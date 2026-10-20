# Systematic per-target function-hint derivation for the futari recomp targets.
#
# ReXGlue's analyzer misses functions that are only reached by indirect calls
# (no PDATA/static edge), which surfaced one at a time as runtime
# "[FATAL] Call to invalid or unregistered function at 0x88xxxxxx" during
# playtesting (see TRACKING.md iterations 3-8). This pass finds all of them
# statically instead:
#
#   1. Runs XenonRecomp on the target XEX to get a reference function map
#      (PDATA + bl-scan + linear gap-fill covers the whole code section).
#   2. Gets ReXGlue's base registered set:
#        - default: a clean codegen run of the target with its TOML includes
#          emptied (so curated hints do not taint the diff), or
#        - -Quick: the committed generated/<target>/futari_init.cpp (assumes
#          the committed tree matches the committed TOMLs).
#   3. diff (XenonRecomp - ReXGlue) = candidate missing functions.
#   4. Bulk-seeds every candidate and codegens; ReXGlue logs
#      "Function 0x.. has no blocks - generating stub" for addresses that are
#      data / misidentified (gap-fill over .long etc.).
#   5. Writes <target>_hints.toml (futari_shell_hints.toml for the entrypoint)
#      keeping only candidates that decoded to real instruction blocks.
#
# The hints file is meant to be listed FIRST in the manifest include list;
# the curated TOML stays authoritative (config merge is last wins), so no
# existing name/switch_tables override can be clobbered.
#
# XenonRecomp is NOT a submodule and NOT needed for normal builds. To run
# this script, clone and build it (console build; VS/cl fails on __builtins):
#
#   git clone --recursive https://github.com/hedge-dev/XenonRecomp thirdparty/XenonRecomp
#   cmake -S thirdparty/XenonRecomp -B thirdparty/XenonRecomp/build \
#     -G Ninja -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
#     -DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl
#   (run from a VS dev prompt so the Windows SDK libs are discoverable)
#
# Usage:
#   .\scripts\build_module_hints.ps1                 # all 8 modules + shell, clean diff
#   .\scripts\build_module_hints.ps1 -Quick          # baseline from committed tree
#   .\scripts\build_module_hints.ps1 -Targets reco_normal
#   .\scripts\build_module_hints.ps1 -Rexglue <path> -Xenon <path>
#
# NOTE: collaborator-visible state — codegen runs here use temp manifests at the
# repo ROOT (".hints_tmp.toml"), because the CLI resolves every path relative to
# the manifest file itself (repo-root anchored paths assume that location).

[CmdletBinding()]
param(
    [string]$Rexglue = "",
    [string]$Xenon = "",
    [string]$CtxHdr = "",
    # 'default' means the entrypoint XEX (0x82 addresses).
    [string[]]$Targets = @(
        'palm_normal', 'palm_abnormal',
        'hirow_normal', 'hirow_abnormal',
        'kiniro_normal', 'kiniro_abnormal',
        'reco_normal', 'reco_abnormal',
        'default'
    ),
    [switch]$Quick
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root
$TMP = '.hints_tmp.toml'

# ---------------------------------------------------------------------------
# Locate the rexglue CLI (same conventions as codegen_all.ps1).
# ---------------------------------------------------------------------------
if (-not $Rexglue) {
    $names = @('rexglue.exe', 'rexglue')
    $searchRoots = @('out', 'thirdparty', 'build') |
        ForEach-Object { Join-Path $root $_ } |
        Where-Object { Test-Path $_ }
    $candidates = @(
        foreach ($sr in $searchRoots) {
            foreach ($name in $names) {
                Get-ChildItem -Path $sr -Recurse -Filter $name -File -ErrorAction SilentlyContinue |
                    Select-Object -ExpandProperty FullName
            }
        }
        (Join-Path $root 'rexglue.exe')
        (Join-Path $root 'rexglue')
    )
    $Rexglue = $candidates | Where-Object { $_ -and (Test-Path $_) } | Select-Object -First 1
}
if (-not $Rexglue) { throw "rexglue CLI not found. Build it or pass -Rexglue <path>." }
Write-Host "Using rexglue: $Rexglue"

# Locate XenonRecomp + the PPC context header (manual dependency, not committed).
if (-not $Xenon) {
    foreach ($p in @(
        'thirdparty\XenonRecomp\build\XenonRecomp\XenonRecomp.exe',
        'thirdparty\XenonRecomp\build\XenonRecomp\Release\XenonRecomp.exe')) {
        if (Test-Path (Join-Path $root $p)) { $Xenon = Join-Path $root $p; break }
    }
}
if (-not $Xenon) {
    throw "XenonRecomp not found. Build it (see the header of this script) or pass -Xenon <path>."
}
if (-not $CtxHdr) { $CtxHdr = Join-Path $root 'thirdparty\XenonRecomp\XenonUtils\ppc_context.h' }
if (-not (Test-Path $CtxHdr)) { throw "PPC context header not found: $CtxHdr" }
Write-Host "Using XenonRecomp: $Xenon"

# ---------------------------------------------------------------------------
# Sanity: generated/ must be clean, since the pass clobbers it transiently and
# every phase depends on the committed-state invariant. Discard any prior
# transient clobber first; uncommitted tooling/doc changes elsewhere are fine.
# ---------------------------------------------------------------------------
git checkout -q -- generated/
if ($LASTEXITCODE -ne 0) { throw "git checkout of generated/ failed" }
$dirty = git status --porcelain -- generated/
if ($dirty) { throw "generated/ is dirty; commit or stash it first (this script regenerates it)." }

function Write-RunProfiler {
    param([string]$Path, [string[]]$EntrypointIncludes, [string]$Module, [string[]]$ModuleIncludes)
    $epIncl = "includes = [" + (($EntrypointIncludes | ForEach-Object { "`"$_`"" }) -join ', ') + "]"
    $modIncl = "includes = [" + (($ModuleIncludes | ForEach-Object { "`"$_`"" }) -join ', ') + "]"
    $head = @"
[project]
name = "futari"
sdk_version = "0.10.0"
game_root = "game_data"

[entrypoint]
file_path = "game_data/default.xex"
out_directory_path = "generated/default"
$epIncl

"@
    if ($Module) {
        $head += @"
[[modules]]
guest_path = "media/Module/$Module.xex"
file_path = "game_data/media/Module/$Module.xex"
out_directory_path = "generated/$Module"
$modIncl

"@
    }
    Set-Content -Path $Path -Value $head -Encoding utf8
}

function Invoke-CodegenProfiler {
    param([string]$Exe, [string]$Log, [string]$ArgString)
    $p = Start-Process -FilePath $Exe -ArgumentList $ArgString -WorkingDirectory $root `
        -RedirectStandardOutput $Log -RedirectStandardError "$Log.err" -NoNewWindow -Wait -PassThru
    if ($p.ExitCode -ne 0) { throw "$(Split-Path $Exe -Leaf) failed (exit $($p.ExitCode)); see $Log[.err]" }
}

$MODULES = @(
    'palm_normal', 'palm_abnormal', 'hirow_normal', 'hirow_abnormal',
    'kiniro_normal', 'kiniro_abnormal', 'reco_normal', 'reco_abnormal'
)

foreach ($t in $Targets) {
    if ($t -eq 'default') {
        $tgt = [pscustomobject]@{
            Name      = 'default'
            XexPath   = 'game_data/default.xex'
            OutDir    = 'generated/default'
            ScopeRe   = '0x82[0-9A-Fa-f]{6}'
            HintsFile = 'futari_shell_hints.toml'
            CurIncl   = 'futari_functions.toml'
            IsModule  = $false
        }
    } elseif ($MODULES -contains $t) {
        $tgt = [pscustomobject]@{
            Name      = $t
            XexPath   = "game_data/media/Module/$t.xex"
            OutDir    = "generated/$t"
            ScopeRe   = '0x88[0-9A-Fa-f]{6}'
            HintsFile = "futari_${t}_hints.toml"
            CurIncl   = "futari_${t}_functions.toml"
            IsModule  = $true
        }
    } else {
        throw "Unknown target '$t' (modules: $($MODULES -join ', '); or 'default' for the shell)."
    }
    if (-not (Test-Path (Join-Path $root $tgt.XexPath))) { throw "Missing $($tgt.XexPath)" }

    Write-Host "==== $($tgt.Name) ===="
    $work = "scripts\module_maps\$($tgt.Name)"
    New-Item -ItemType Directory -Force $work | Out-Null

    # --- 1. XenonRecomp reference map -------------------------------------
    # Paths inside the XenonRecomp config resolve relative to the config file,
    # i.e. to scripts/module_maps/<target>/ — three levels up to the repo.
    $mapToml = Join-Path $work 'xenon.toml'
    @"
[main]
file_path = "../../../$($tgt.XexPath -replace '\\','/')"
out_directory_path = "xenon"
skip_lr = false
skip_msr = false
ctr_as_local = false
xer_as_local = false
reserved_as_local = false
cr_as_local = false
non_argument_as_local = false
non_volatile_as_local = false
"@ | Set-Content -Path $mapToml -Encoding utf8

    $xenonLog = Join-Path $work 'xenon.log'
    # README: "This directory must exist before running the recompiler."
    New-Item -ItemType Directory -Force (Join-Path $work 'xenon') | Out-Null
    Invoke-CodegenProfiler -Exe $Xenon -Log $xenonLog -Args @("`"$mapToml`"", "`"$CtxHdr`"")

    $mapFile = Join-Path $root "scripts\module_maps\$($tgt.Name)\xenon\ppc_func_mapping.cpp"
    if (-not (Test-Path $mapFile)) { throw "XenonRecomp produced no ppc_func_mapping.cpp for $($tgt.Name)" }
    $xenonSet = Select-String -Path $mapFile -Pattern ($tgt.ScopeRe) |
        ForEach-Object { $_.Matches[0].Value.ToUpper() } | Sort-Object -Unique
    Write-Host "  xenon funcs (scope $($tgt.ScopeRe)): $($xenonSet.Count)"

    # --- 2. ReXGlue base registered set ------------------------------------
    $initFile = Join-Path $root "$($tgt.OutDir)/futari_init.cpp"
    if (-not $Quick) {
        # Clean codegen: the target's TOML includes emptied so the diff is
        # against pure analyzer discovery. The entrypoint keeps its curated
        # file in module mode (that output is irrelevant here; leaving it
        # consistent avoids a half-regenerated generated/default).
        $tmpClean = Join-Path $root $TMP
        # NOTE: for the shell, the curated entrypoint TOML can't be emptied —
        # codegen validation requires those dynamic entrypoints (invisible to
        # static analysis). The diff baseline is the registered set either way.
        Write-RunProfiler -Path $tmpClean -EntrypointIncludes @(,$tgt.CurIncl) `
            -Module $(if ($tgt.IsModule) { $tgt.Name } else { $null }) -ModuleIncludes @(,'')
        $cgLog = Join-Path $work 'clean_codegen.log'
        $cgArgs = "codegen `"$tmpClean`""
        if ($tgt.IsModule) { $cgArgs += " --target `"$($tgt.Name)`"" }
        Invoke-CodegenProfiler -Exe $Rexglue -Log $cgLog -ArgString $cgArgs
    }
    $rexSet = Select-String -Path $initFile -Pattern '^\t\{ 0x([0-9A-Fa-f]{8}), \w+ \},$' |
        ForEach-Object { '0x' + $_.Matches[0].Groups[1].Value.ToUpper() } |
        Where-Object { $_ -match $tgt.ScopeRe } | Sort-Object -Unique
    Write-Host "  rex registered: $($rexSet.Count)"

    # --- 3. Candidates -----------------------------------------------------
    # Addresses in the XenonRecomp map ReXGlue has not registered.
    $candidates = Compare-Object -ReferenceObject $rexSet -DifferenceObject $xenonSet |
        Where-Object SideIndicator -eq '=>' | Select-Object -ExpandProperty InputObject | Sort-Object -Unique
    Write-Host "  candidates: $($candidates.Count)"

    if ($candidates.Count -eq 0) {
        Write-Host "  [ok] nothing to seed"
        continue
    }

    # --- 4. Bulk-seed + collect stubs (data / gap-fill misidentifications) --
    $hintsBulk = Join-Path $root $tgt.HintsFile
    @(
        "# $($tgt.HintsFile) - bulk seed (pre-filter); rewritten below."
        "[functions]"
        foreach ($a in $candidates) { "`"$a`" = {}" }
    ) | Set-Content -Path $hintsBulk -Encoding utf8

    $tmpBulk = Join-Path $root $TMP
    Write-RunProfiler -Path $tmpBulk -EntrypointIncludes $(if ($tgt.IsModule) { @(,'futari_functions.toml') } else { @($tgt.HintsFile, $tgt.CurIncl) }) `
        -Module $(if ($tgt.IsModule) { $tgt.Name } else { $null }) -ModuleIncludes $(if ($tgt.IsModule) { @(,$tgt.HintsFile) } else { @(,'') })
    $bulkLog = Join-Path $work 'bulk_codegen.log'
    $cgArgs = "codegen `"$tmpBulk`""
    if ($tgt.IsModule) { $cgArgs += " --target `"$($tgt.Name)`"" }
    Invoke-CodegenProfiler -Exe $Rexglue -Log $bulkLog -ArgString $cgArgs

    $stubs = Get-ChildItem @($bulkLog, "$bulkLog.err") -ErrorAction SilentlyContinue |
        Select-String -Pattern 'has no blocks - generating stub' |
        ForEach-Object { $_.Line } |
        Select-String -Pattern ($tgt.ScopeRe) -AllMatches |
        ForEach-Object { $_.Matches } | ForEach-Object { $_.Value.ToUpper() } |
        Sort-Object -Unique
    Write-Host "  stubs (data): $($stubs.Count)"

    # --- 5. Final hints file ------------------------------------------------
    $real = Compare-Object -ReferenceObject $stubs -DifferenceObject $candidates |
        Where-Object SideIndicator -eq '=>' | Select-Object -ExpandProperty InputObject | Sort-Object -Unique
    $baseNote = if ($tgt.IsModule) { " (base 0x88000000)" } else { "" }
    @(
        "# $($tgt.HintsFile) - function-entry hints for $($tgt.Name)$baseNote."
        "#"
        "# Generated by scripts/build_module_hints.ps1: XenonRecomp reference map"
        "# minus ReXGlue-registered, filtered to addresses that decode to real"
        "# instruction blocks (data/gap-fill stubs dropped). Listed FIRST in the"
        "# manifest include list; the curated *_functions.toml stays authoritative."
        "[functions]"
        foreach ($a in $real) { "`"$a`" = {}" }
    ) | Set-Content -Path (Join-Path $root $tgt.HintsFile) -Encoding utf8
    Write-Host "  REAL seeds written: $($real.Count) -> $($tgt.HintsFile)"

    # --- 6. Validation codegen (real seeds only) ----------------------------
    $valLog = Join-Path $work 'validate_codegen.log'
    $cgArgs = "codegen `"$tmpBulk`""
    if ($tgt.IsModule) { $cgArgs += " --target `"$($tgt.Name)`"" }
    Invoke-CodegenProfiler -Exe $Rexglue -Log $valLog -ArgString $cgArgs

    $valStubs = Get-ChildItem @($valLog, "$valLog.err") -ErrorAction SilentlyContinue |
        Select-String -Pattern 'has no blocks - generating stub' |
        ForEach-Object { $_.Line } |
        Select-String -Pattern ($tgt.ScopeRe) -AllMatches |
        ForEach-Object { $_.Matches } | ForEach-Object { $_.Value.ToUpper() } | Sort-Object -Unique
    $valUnres = Get-ChildItem @($valLog, "$valLog.err") -ErrorAction SilentlyContinue |
        Select-String -Pattern 'Unresolved b target' |
        ForEach-Object { $_.Line } |
        Select-String -Pattern ($tgt.ScopeRe) -AllMatches |
        ForEach-Object { $_.Matches } | ForEach-Object { $_.Value.ToUpper() } | Sort-Object -Unique
    Write-Host "  validate: stubs=$($valStubs.Count) unresolved-b=$($valUnres.Count)"
    if ($valStubs.Count -gt 0) {
        Write-Warning "$($tgt.Name): leftover stubs (these addresses failed to decode even with hints): $($valStubs -join ', ')"
    }
    if ($valUnres.Count -gt 0) {
        Write-Warning "$($tgt.Name): unresolved b targets remain (may resolve as conditional tail calls or need block overrides): $($valUnres -join ', ')"
    }
}

Remove-Item -Path (Join-Path $root $TMP) -ErrorAction SilentlyContinue

Write-Host ""
Write-Host "Next: wire the *_hints.toml files into futari_manifest.toml (includes list, BEFORE the curated TOML),"
Write-Host "then run: .\scripts\codegen_all.ps1"
Write-Host "(generated/ is now in a transient state from the per-target codegen runs; codegen_all.ps1 will restore consistency)"

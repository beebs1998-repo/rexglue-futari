# Regenerates the recompiled C++ for the futari entrypoint and all eight
# character modules, then restores the project-maintained glue files that a
# codegen run would otherwise clobber.
#
# Requires:
#   - the `rexglue` CLI (built from thirdparty/rexglue-sdk), and
#   - the game files in game_data/ (default.xex + media/Module/*.xex).
#
# Usage:
#   .\scripts\codegen_all.ps1                 # incremental
#   .\scripts\codegen_all.ps1 -IgnoreStamp    # force full regeneration
#   .\scripts\codegen_all.ps1 -Rexglue <path> # explicit CLI path

[CmdletBinding()]
param(
    [string]$Rexglue = "",
    [switch]$IgnoreStamp
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root

# Locate the rexglue CLI. It is built as part of the SDK, so it lands in the
# SDK's own output dir (e.g. thirdparty/rexglue-sdk/out/win-amd64/rexglue.exe),
# not the project's out/build.
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

    $onPath = Get-Command rexglue -ErrorAction SilentlyContinue
    if ($onPath) { $candidates += $onPath.Source }

    $Rexglue = $candidates | Where-Object { $_ -and (Test-Path $_) } | Select-Object -First 1
}
if (-not $Rexglue) {
    throw "rexglue CLI not found. Build it (cmake --build --preset win-amd64-release --target rexglue) or pass -Rexglue <path>."
}
Write-Host "Using rexglue: $Rexglue"

$required = @(
    'game_data/default.xex',
    'game_data/media/Module/palm_normal.xex',
    'game_data/media/Module/palm_abnormal.xex',
    'game_data/media/Module/hirow_normal.xex',
    'game_data/media/Module/hirow_abnormal.xex',
    'game_data/media/Module/kiniro_normal.xex',
    'game_data/media/Module/kiniro_abnormal.xex',
    'game_data/media/Module/reco_normal.xex',
    'game_data/media/Module/reco_abnormal.xex'
)
foreach ($item in $required) {
    if (-not (Test-Path (Join-Path $root $item))) {
        throw "Missing $item - codegen needs the game files (see README.md)."
    }
}

$targets = @(
    'palm_normal', 'palm_abnormal',
    'hirow_normal', 'hirow_abnormal',
    'kiniro_normal', 'kiniro_abnormal',
    'reco_normal', 'reco_abnormal'
)

$common = @('codegen', 'futari_manifest.toml')
if ($IgnoreStamp) { $common += '--ignore-stamp' }

# The eight character modules all share guest base 0x88000000, so a combined run
# is rejected by the overlap check. One target per invocation; the entrypoint is
# always regenerated alongside the selected module.
foreach ($target in $targets) {
    Write-Host "=== codegen: $target ==="
    & $Rexglue @common --target $target
    if ($LASTEXITCODE -ne 0) { throw "codegen failed for target '$target' (exit $LASTEXITCODE)" }
}

# codegen rewrites these with only the targets from the last run. Restore the
# project-maintained merged versions (all eight modules together) and the
# auto-codegen-disabled rexglue.cmake.
Write-Host "=== restoring project-maintained glue files ==="
git checkout -- `
    generated/rexglue.cmake `
    generated/default/dll_targets.cmake `
    generated/default/module_registry.cpp
if ($LASTEXITCODE -ne 0) { throw "git checkout failed (exit $LASTEXITCODE)" }

# Static crash gate: fail on embedded recompiler traps that are not in the
# triaged allow-list (scripts/trap_allowlist.txt). This is what used to be
# discovered by playtesting one guest address at a time.
Write-Host "=== validating regenerated code (embedded-trap gate) ==="
& (Join-Path $PSScriptRoot 'validate_codegen.ps1')
if ($LASTEXITCODE -ne 0) { throw "embedded-trap gate failed ($LASTEXITCODE); triage or fix, see output above" }

Write-Host "Done. Rebuild with: cmake --build --preset win-amd64-release --parallel"

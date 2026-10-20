# Static crash gate for the committed (or freshly regenerated) recompiled code.
#
# Scans generated/ for recompiler failure modes that were emitted as embedded
# traps instead of being caught at codegen time:
#
#   - unresolved calls:      REX_FATAL("Unresolved call from 0x.. to 0x..")
#   - unresolved branches:   REX_FATAL("Unresolved branch from 0x.. to 0x..")
#   - unresolved bctr:       REX_FATAL("Jump target 0x.. unresolved at bctr 0x..")
#   - unregistered jump:     REX_FATAL("Jump target 0x.. classified as function but not registered")
#   - stub functions:        "// STUB: Function at 0x.. has no discovered code blocks"
#   - (informational) switch-case out-of-range __builtin_trap() sites; counted
#     but never fatal — the SDK still emits the trap class today.
#
# These are exactly the failures that used to be discovered by playtesting one
# guest address at a time (see TRACKING.md iterations 3-8). Running the gate
# after every codegen turn makes a regression fail loudly, with file:line and
# guest addresses, before the game is ever launched.
#
# Identities in the allow-list (scripts/trap_allowlist.txt) are host-file
# independent: "<target> <class> <guest addresses>" — each entry has been triaged.
# A site whose identity is NOT in the allow-list fails the gate.
#
# Usage:
#   .\scripts\validate_codegen.ps1
#   .\scripts\validate_codegen.ps1 -WriteAllowList     # print current triage entries
#   .\scripts\validate_codegen.ps1 -ListAll            # show every site incl. allowed

[CmdletBinding()]
param(
    [string]$AllowListPath = "",
    [switch]$WriteAllowList,
    [switch]$ListAll
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root
if (-not $AllowListPath) { $AllowListPath = 'scripts\trap_allowlist.txt' }

$TARGETS = @('default') + @(
    'palm_normal', 'palm_abnormal', 'hirow_normal', 'hirow_abnormal',
    'kiniro_normal', 'kiniro_abnormal', 'reco_normal', 'reco_abnormal'
)

# class => regex over the generated sources. Capture groups: 0x addresses
# (site, target...) in emission order; the identity is their joined form.
$ERROR_CLASSES = @(
    @{ Id = 'unresolved_call';    Re = 'REX_FATAL\("Unresolved call from 0x[0-9A-Fa-f]{8} to 0x[0-9A-Fa-f]{8}' },
    @{ Id = 'unresolved_branch';  Re = 'REX_FATAL\("Unresolved branch from 0x[0-9A-Fa-f]{8} to 0x[0-9A-Fa-f]{8}' },
    @{ Id = 'unresolved_bctr';    Re = 'REX_FATAL\("Jump target 0x[0-9A-Fa-f]{8} unresolved at bctr' },
    @{ Id = 'jump_unregistered';  Re = 'REX_FATAL\("Jump target 0x[0-9A-Fa-f]{8} classified as function but not registered' }
)
$INFO_CLASSES = @(
    @{ Id = 'switch_trap';        Re = '__builtin_trap\(\);\s*// Switch case out of range' }
)

$allSites = New-Object System.Collections.Generic.List[object]
foreach ($t in $TARGETS) {
    $dir = Join-Path $root "generated\$t"
    if (-not (Test-Path $dir)) { throw "missing $dir" }
    $files = Get-ChildItem $dir -Recurse -Include *.cpp -File
    foreach ($p in $ERROR_CLASSES + $INFO_CLASSES) {
        $hits = Select-String -Path $files.FullName -Pattern $p.Re
        foreach ($h in $hits) {
            $addrs = ([regex]::Matches($h.Line, '0x[0-9A-Fa-f]{8}') | ForEach-Object { $_.Value.ToUpper() })
            $identity = ($addrs -join '=')
            $rel = $h.Path.Substring($root.Length + 1)
            $allSites.Add([pscustomobject]@{
                Target   = $t
                Class    = $p.Id
                Identity = $identity
                Site     = "$rel`:$($h.LineNumber)"
                Text     = $h.Line.Trim()
            })
        }
    }
}

$switchTrapCount = ($allSites | Where-Object Class -eq 'switch_trap').Count


if ($WriteAllowList) {
    Write-Host "# triage entries (paste into $AllowListPath and review carefully):"
    $allSites | Where-Object Class -ne 'switch_trap' |
        ForEach-Object { "$($_.Target) $($_.Class) $($_.Identity)   # $($_.Site)" }
    Write-Host "# switch_trap (informational, counted only): $switchTrapCount site(s)"
    return
}

$allow = New-Object System.Collections.Generic.List[string]
if (Test-Path $AllowListPath) {
    Get-Content $AllowListPath | ForEach-Object {
        $l = ($_ -split '#')[0].Trim()
        if ($l) { $allow.Add($l) }
    }
}

$newErrors = @($allSites | Where-Object Class -ne 'switch_trap' | Where-Object {
    -not $allow.Contains("$($_.Target) $($_.Class) $($_.Identity)")
})
$staleAllow = @($allow | Where-Object {
    $e = $_
    -not ($allSites | Where-Object { $_.Class -ne 'switch_trap' -and "$($_.Target) $($_.Class) $($_.Identity)" -eq $e })
})

if ($newErrors.Count -gt 0) {
    Write-Host "code validation FAILED: $($newErrors.Count) embedded-trap site(s) not in the allow-list:"
    $newErrors | ForEach-Object { "  $($_.Target) $($_.Class) $($_.Identity): $($_.Site): $($_.Text)" }
    Write-Host ""
    Write-Host "Each address used to be found by playtesting one at a time. Triaged entries go to:"
    Write-Host "  $AllowListPath"
    exit 1
}

if ($ListAll) {
    $errors = @($allSites | Where-Object Class -ne 'switch_trap')
    if ($errors.Count -gt 0) {
        Write-Host "$($errors.Count) allowed embedded-trap site(s):"
        $(foreach ($e in $errors) {
            $id = "$($e.Target) $($e.Class) $($e.Identity)"
            if ($allow.Contains($id)) { "  [allowed] $id : $($e.Site)" }
        })
    } else {
        Write-Host "no embedded-trap sites found"
    }
}
$staleOut = ($staleAllow | Select-Object -First 5)
if ($staleOut) {
    Write-Host "note: $($staleAllow.Count) stale allow-list entr$(if ($staleAllow.Count -eq 1) {'y'} else {'ies'}) (site gone - candidates for removal):"
    $staleOut | ForEach-Object { "  $_" }
}
Write-Host "code validation OK ($($allSites.Count - $switchTrapCount) triaged site(s) allowed, $switchTrapCount switch_trap site(s) informational)"
exit 0

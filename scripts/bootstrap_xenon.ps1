# Downloads/updates the XenonRecomp reference tool (git submodule
# thirdparty/XenonRecomp -> beebs1998-repo/XenonRecomp, a fork of
# hedge-dev/XenonRecomp) and builds it once per machine.
#
# The tool is only needed for scripts/build_module_hints.ps1 (static function
# hint derivation); normal builds and CI never touch it. The build is cached,
# so this is cheap to re-run.
#
# The console build must use clang-cl: an MSVC interpreter build fails on
# __builtin_bswap*-style builtins, and VS/cl is not used.
#
# Usage:
#   .\scripts\bootstrap_xenon.ps1          # init submodule + build if missing
#   .\scripts\bootstrap_xenon.ps1 -Force   # reconfigure/rebuild even if present

[CmdletBinding()]
param([switch]$Force)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
Set-Location $root
$sub = Join-Path $root 'thirdparty\XenonRecomp'

# --- 1. Make sure the submodule is checked out at the recorded SHA ----------
# NOTE: uninitialized nested submodules (fmt, xxHash, ...) still appear as
# existing-but-empty directories, so a plain `Test-Path` probe lies. Trust
# `git submodule status` instead: '-' prefix means "registered, not checked
# out", and a missing CMakeLists.txt means the parent submodule is absent.
$needInit = -not (Test-Path (Join-Path $sub 'CMakeLists.txt'))
if (-not $needInit) {
    $subStatus = @(git -C $sub submodule status 2>$null)
    $needInit = ($subStatus | Where-Object { $_ -match '^-' }).Count -gt 0
    if (-not $subStatus) { $needInit = $true }  # git absent from PATH?
}

if ($needInit) {
    Write-Host 'XenonRecomp submodule (or its nested deps) missing; fetching...'
    & git -C $root submodule update --init --recursive $sub
    if ($LASTEXITCODE -ne 0) { throw "git submodule update failed (exit $LASTEXITCODE)" }
}
else {
    # Refresh if the recorded SHA changed; keep the build dir either way.
    & git -C $root submodule update $sub
    if ($LASTEXITCODE -ne 0) { throw "git submodule update failed (exit $LASTEXITCODE)" }
}
& git -C $sub log --oneline -1

# Keep build/ (and build-asan/) out of the submodule's dirty-state: without a
# local exclude the submodule node shows permanently as '-dirty' in the parent.
# NOTE: in a submodule .git is a file (a gitdir pointer), so resolve the real
# exclude file through git itself.
$exclude = (& git -C $sub rev-parse --path-format=absolute --git-path 'info/exclude') | Select-Object -First 1
Add-Content -Path $exclude -Value "`n# local build output (added by scripts/bootstrap_xenon.ps1)`n/build/`n/build-asan/"

# --- 2. Build once per machine (ninja-free cmake builds are cached) ----------
$exeCandidates = @(
    (Join-Path $sub 'build\XenonRecomp\XenonRecomp.exe'),
    (Join-Path $sub 'build\XenonRecomp\Release\XenonRecomp.exe')
)
$exe = $exeCandidates | Where-Object { Test-Path $_ } | Select-Object -First 1

if ($exe -and -not $Force) {
    Write-Host "XenonRecomp already built: $exe"
    return
}

Write-Host 'Building XenonRecomp (clang-cl + Ninja, requires VS dev tools)...'

# Locate VsDevCmd.bat via the VS installer (works for both VS and Build Tools).
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (-not (Test-Path $vswhere)) { throw 'vswhere.exe not found - Visual Studio/Build Tools is not installed.' }
$vsRoot = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (-not $vsRoot) { throw 'No VS installation with C++ tools found.' }
$vsdevcmd = Join-Path $vsRoot 'Common7\Tools\VsDevCmd.bat'
if (-not (Test-Path $vsdevcmd)) { throw "VsDevCmd.bat not found under $vsRoot." }

$cmakeCmd = @(
    'cmake -S thirdparty/XenonRecomp -B thirdparty/XenonRecomp/build',
    '-G Ninja',
    '-DCMAKE_POLICY_VERSION_MINIMUM=3.5',
    '-DCMAKE_C_COMPILER=clang-cl -DCMAKE_CXX_COMPILER=clang-cl',
    '&& cmake --build thirdparty/XenonRecomp/build --parallel'
) -join ' '

& cmd /c "call `"$vsdevcmd`" -arch=amd64 && $cmakeCmd" | Write-Host
if ($LASTEXITCODE -ne 0) { throw "XenonRecomp build failed (exit $LASTEXITCODE)" }

$exe = $exeCandidates | Where-Object { Test-Path $_ } | Select-Object -First 1
if (-not $exe) { throw 'Build finished but XenonRecomp.exe was not found in build\XenonRecomp.' }
Write-Host "XenonRecomp ready: $exe"

# AGENTS.md — working in this repository

Agent- and developer-facing notes. For the public, human-facing guide, see
[README.md](README.md). All paths are repo-relative.

## What this is

A [ReXGlue](https://github.com/rexglue/rexglue-sdk) recompilation of the Xbox 360
shooter *Mushihimesama Futari*. It builds a native host executable (`futari`) from
statically recompiled PowerPC code, plus eight character-module shared libraries
loaded at runtime.

Two facts dominate everything else:

1. **The recompiled code is committed.** `generated/**` is checked in, so the
   project builds without the game. Do not hand-edit generated files; regenerate
   them (`scripts/codegen_all.ps1`).
2. **The SDK is a pinned submodule.** `thirdparty/rexglue-sdk` points at
   `beebs1998-repo/rexglue-sdk` @ `348c804` (v0.10.0 + module-reload fixes
   (`c0702cd`/`bf06423`), SSSE3 build flag (`51624b5`), D3D12
   `submit_on_primary_buffer_end` default false (`f3b93d5`), cvar TOML
   save-serialization fix (`b773a88`), DFKBL iter-31 save-import fixes
   (`d25ba53`/`9019af7`), the `profile_name` gamertag cvar (`bf63f94`), and the
   branch-classification fix (classify against the emitting function node;
   `348c804`).
   Building against a different SDK can change/crash behaviour. Note: the fork
   force-pushed `origin/main` onto a rewritten history; the previous 5-commit
   line (`8c6b399`, including adaptive VBlank pacing + D3D12
   vsync/guest-present cvars) is preserved but **untracked** on the fork's
   `origin/legacy` branch (`f7d591f`) — see TRACKING.md Iteration 14.

## Module naming & testing coverage

The module/file names (`palm_normal`, `reco_abnormal`, `hirow_…`, `kiniro_…` ×
`normal|abnormal`) are the **game developers'** internal naming (CAVE, for
Mushihimesama Futari — the shipped XEX filenames), **not** the game's player-facing
menu labels (e.g. "Palm - Normal shot") and not a ReXGlue invention. There is no
reliable 1:1 mapping between in-game labels and module names; when diagnosing a
crash, trust the log: the `XexLoadImage('…')` lines are the ground truth for which
module was resident.

Coverage status: **work in progress, the eight modules are not fully
playtested.** Futari is a demanding game (its harder modes punish short
sessions), so reachable content is limited and crashes surface reactively —
as playtesting covers a new character/version/mode/stage combination, expect
to discover further unregistered-function gaps or jump-table truncations, even
after previously "passing" stages (see Iteration 16: a fresh stage-1 gap
appeared in ver 1.5 Ultra long after stages 1-5 had been declared passable in
Arrange ver). The gap table below records what has *actually crashed so far*,
not an exhaustive list of possible gaps.

## Game save data (system config + replays)

Saves live under `user_data/<xuid>/<title_id>/00000001/` (XUID is hardcoded
`B13EBABEBABEBABE`; futari's title id is `435A07D7`). The supported layout is
Xenia Canary's: one directory package per data file
(`replaydata.bin/replaydata.bin`, `systemdata.bin/savegame.bin`) plus a
328-byte raw `XCONTENT_AGGREGATE_DATA` dump at
`Headers/00000001/<package>.header`. Copying Xenia's
`content/B13EBABEBABEBABE/435A07D7/` into `user_data/B13EBABEBABEBABE/` works
as-is (full STFS/CON headers are also accepted — SDK `9019af7`). The guest
flow: replay/config *save* opens the package with `OPEN_EXISTING`
(`replaydata.bin`) or `CREATE_ALWAYS` (`systemdata.bin`, which deletes +
recreates the directory and regenerates a native raw header). Replay list
names: profile gamertag = "User" (set `[Kernel] profile_name` in `futari.toml`
to change); the right-hand 1P pilot name (e.g. `CRN`) is recorded at
score-registration time when the run enters the local top-10 — low-score runs
save without one. See TRACKING.md Iteration 17.

DLC (Black Label + Version 1.01) availability comes entirely from the staged
`00000002` packages + per-package `0xFFFFFFFF` license tails on their
`Headers/00000002/*.header` files (Iteration 20) — the
`XamContentGetLicenseMask` cvar is **not** needed, so there is no
`license_mask` line to maintain in `futari.toml` (and a `[Kernel]` TOML
section would not even load: sections parse as `Section_name` cvars —
Iteration 23). Bundling only `game_data/` is fine; base games are unaffected.

## Config-file staging (backported from the mushi port)

`SetupEnvironment` sets the live config to `exe_dir/futari.toml`, and a
missing file is benign-but-degrading (game silently runs on compiled-in
defaults: no keybinds/mnk, no log rotation, no pinned cvars). Historically
this project's template therefore never took effect on first launch. It is
now staged by construction, three entry points, ALL copy-if-missing — the
live file is never overwritten:

- POST_BUILD stages `futari.toml` next to the exe if missing
  (`scripts/stage_config.cmake`).
- `launch.bat` applies the same rule.
- CI ships `futari.toml` inside the build artifact.

If the template changes after first stage, delete the live copy or re-edit
via F4 to re-sync (documented in README "Settings").

## Layout

| Path | Notes |
| --- | --- |
| `src/main.cpp` | `REX_DEFINE_APP`; includes `generated/default/futari_init.h` |
| `src/futari_app.h` | `FutariApp` — `ReXApp` subclass |
| `src/futari_mod_swap_fix.cpp` | Hooks `sub_82088E10` to unload the previous character module (see below) |
| `generated/default/` | Entrypoint recomp + `dll_targets.cmake`, `module_registry.cpp`, `sources.cmake` |
| `generated/<module>/` | Character-module recomp (8 of them) |
| `generated/rexglue.cmake` | CMake glue; **auto-codegen is disabled here** (see below) |
| `futari_manifest.toml` | Codegen manifest (entrypoint + 8 modules) |
| `futari_functions.toml` | Dynamic entrypoints for the entrypoint XEX (from `ep.txt`) |
| `futari_<module>_functions.toml` | Per-module overrides (names + switch tables) |
| `futari.toml` | Runtime settings (auto-written by the app; also live-editable via F4) |
| `thirdparty/rexglue-sdk/` | Pinned SDK submodule |
| `scripts/codegen_all.ps1` | Regenerate all recompiled code (needs the game) |
| `TRACKING.md` | Iteration log — read before changing runtime/module behaviour |
| `game_data/`, `user_data/`, `logs/`, `out/` | Local only, gitignored |

## Build & run

```
cmake --preset win-amd64-release
cmake --build --preset win-amd64-release --parallel
out\build\win-amd64-release\futari.exe --game_data_root=game_data --user_data_root=user_data
```

Ninja + clang/clang++ are used via `CMakePresets.json`. `game_data/` must contain
your own `default.xex` and `media/Module/*.xex` (see README.md). To reuse an
already-built SDK tree instead of the submodule, pass
`-DREXSDK_DIR=<path>` at configure time.

## Codegen

Auto-codegen is deliberately disabled in `generated/rexglue.cmake`. Reason: all
eight character modules share guest base `0x88000000`, so a single combined
`rexglue codegen futari_manifest.toml` run is rejected by the overlap check. Code
is generated one target per run and committed.

Two generated files are **hand-merged** and must not be clobbered:

- `generated/default/dll_targets.cmake` — CMake targets for all eight module DLLs.
- `generated/default/module_registry.cpp` — registers all eight modules.

`rexglue codegen --target <name>` rewrites both (and `generated/rexglue.cmake`) for
the last target only. `scripts/codegen_all.ps1` runs each target then restores the
committed versions with `git checkout --`. If you regenerate by hand, do the same.

Workflow when the game hits an unregistered function
(`[FATAL] Call to invalid or unregistered function at guest address 0x...`):

1. Add the address to the right `futari*_functions.toml` (entrypoint vs the module
   that logged it). The same address range is usually shared across all eight
   character modules — see the gap table below.
2. `.\scripts\codegen_all.ps1`
3. Rebuild + re-stage (see Conventions).
4. Record the iteration in `TRACKING.md`.

## Static function-hint derivation (`scripts/build_module_hints.ps1`)

The analyzer misses functions that are only reached by indirect calls (no
PDATA/static edge), and each used to be found by playtesting until a
`[FATAL] Call to invalid or unregistered function` fired. The derivation pass
finds them all statically instead, per target:

1. Run XenonRecomp (git submodule `thirdparty/XenonRecomp`, fork
   `beebs1998-repo/XenonRecomp` pinned to upstream `ddd128b`; build once per
   machine with `pwsh .\scripts\bootstrap_xenon.ps1`) on the
   XEX for a full-coverage reference function map (PDATA + bl-scan + gap-fill).
2. Diff that map against ReXGlue's registered set (a clean codegen run with the
   target's TOML includes emptied; the shell keeps its curated TOML because the
   dynamic entrypoints are invisible to static analysis and codegen validation
   requires them). `-Quick` reads the committed `futari_init.cpp` instead.
3. Bulk-seed the diff into `<target>_hints.toml`; codegen; drop candidates that
   log `has no blocks - generating stub` (data / gap-fill misidentifications).
4. Rewrite the hints file with what decoded to real instruction blocks.

Counts from the first full pass (2026-10-21), matching the futari_recomp port
of the same disc byte-for-byte per module: palm 45/44, hirow 42/42,
kiniro 40/40, reco 46/46 (normal/abnormal), entrypoint 132 - 477 hints total.

The manifest lists every hints TOML **before** the curated files (config merge
is last-wins), so names and `[[switch_tables]]` in the curated TOMLs keep
authority. The bulk-seed phase emits ~2800 data/gap-fill candidates per module;
only ~45 survive as real entries — the stub filter does the work, don't hand
trim the files.

Re-run the pass after SDK bumps or codegen changes that alter function
boundaries; it is cheap and catches the missed-entrypoint class without any
launch.

## Embedded-trap gate (`scripts/validate_codegen.ps1`)

Scans the committed `generated/` tree (CI can run it; no game data needed) for
recompiler failures emitted as embedded traps instead of caught at codegen:

- `REX_FATAL("Unresolved call from 0x.. to 0x..")`
- `REX_FATAL("Unresolved branch from 0x.. to 0x..")`
- `REX_FATAL("Jump target 0x.. unresolved at bctr 0x..")`
- `REX_FATAL("Jump target 0x.. classified as function but not registered")`
- `// STUB: Function at 0x.. has no discovered code blocks`

Sites are identified by `<target> <class> <guest addresses>` (host-file
independent) and checked against the triaged allow-list
`scripts/trap_allowlist.txt`; an unknown site fails the run (also wired into
`codegen_all.ps1` and CI). Baseline at introduction: 17 shell unresolved-call
sites, 5 module unresolved-branch sites (hirow×4, kiniro_normal×1), 1 shell
stub, and ~501 informational `__builtin_trap() // Switch case out of range
sites (SDK limitation, see the deferred SDK-fix note below). A new site is
exactly what used to be discovered mid-playtest on stage N - fix it
(hint/override) or triage it into the allow-list deliberately.


## Per-module override TOML (the fix mechanism)

Overrides live in `futari_<module>_functions.toml`, referenced by that module's
`includes` in the manifest. Two kinds are in use:

### Name-only overrides (function boundaries)

Name-only overrides tell the recompiler to treat a guest address as a function
entry point. CONFIG authority => registered before PDATA analysis, so discovery
uses natural boundaries (branch instructions) instead of potentially bogus PDATA
size data.

```toml
[functions."<GUEST_ADDR>"]
name = "sub_<GUEST_ADDR>"
```

**Already-fixed gaps** (present in all eight module TOMLs unless noted):

| Address | Modules | Notes |
|---------|---------|-------|
| `0x881E8F28` | palm_normal | hirow_abnormal calls sub_88150A58 with lr=0x881E8F28 |
| `0x881E7200` | palm_normal + reco_normal | Gap between auto-discovered functions |
| `0x881B2978` | All 8 | Stage 2 crash |
| `0x881B83D0` | All 8 | Stage 2 crash |
| `0x881C5530` | All 8 | Stage 3 crash |
| `0x88180500` | All 8 | Stage 3 crash |
| `0x880B0B48` | All 8 | Stage 4 crash |
| `0x880A49B0` | All 8 | Stage 5 boss crash |
| `0x881E4E88` | All 8 | Stage 1 crash (1.5 Ultra; log evidence from reco_abnormal) |
| `0x881B8368` | All 8 | Loop twin of `0x881B83D0` (reco_abnormal loop trap `0x881B83DC -> 0x881B8368`, mode-select path; see Tracking Iteration 18) |
| `0x881AFB10` | kiniro_abnormal | BL Arrange (360 port) Original mode, stage 2 (360-port modes route to this module — Original + Maniac so far, both pilots; registered only where it trapped — watch for shifted twins in other modules; see Tracking Iteration 21) |
| `0x881B5710` | kiniro_abnormal | BL Arrange (360 port) Original mode, stage 2 #2 — further into the stage (next gap after `0x881AFB10`; see Tracking Iteration 21) |
| `0x881C2940` | kiniro_abnormal | BL Arrange (360 port) Original mode, stage 3 (stage 2 cleared first; below the `0x881C5530` stage-3 pair; see Tracking Iteration 21) |
| `0x8817D368` | kiniro_abnormal | BL Arrange (360 port) Original mode, stage 3 boss (hit on a stale pre-`0x881C2940` DLL run; trap is genuine regardless; see Tracking Iteration 21) |
| `0x880B3CA0` | kiniro_abnormal | BL Arrange (360 port) Original mode, stage 4 boss (next to the all-8 `0x880B0B48`; see Tracking Iteration 21) |
| `0x880A7AA0` | kiniro_abnormal | BL Arrange (360 port) Original mode, stage 5 boss (new address in the `0x880A49B0` stage-5 boss family; see Tracking Iteration 21) |

**Per-module twin addresses** (same loop/boss bodies, byte-shifted per module,
registered only where the variant actually traps — see Tracking Iteration 18):
reco_normal `0x881B8360` (its `-8`-shifted loop twin) and `0x880A494C`
(stage-5 boss loop twin of the `0x880A49B0` mid-entry); entrypoint
`futari_functions.toml` `0x820781F4`/`0x820783E4` (loop twins of the
`0x82078208`/`0x82078408` data-table entries). These lack the all-8 row
because the equivalent block starts at a different guest address in each
variant — grep the generated tree for `REX_FATAL("Unresolved branch ...")`
after a codegen run to check for another twin; there should be none.

**palm_normal specific - bogus PDATA size**: PDATA-derived size for `0x88085F7C`
is bogus (2105724), which crashed codegen; name-only override fixes it.

### Manual switch tables (auto-detection bugs)

Character/mode select uses ten-entry jump tables that auto-detection truncates to
two cases (the bounds-check scan matches an earlier `cmpwi` instead of `cmplwi
r10,9`). Each is fixed with a manual `[[switch_tables]]` entry:

- **palm_normal** (`futari_palm_normal_functions.toml`): switch @ `0x880EBCAC`,
  index r11, table base `0x880EBCB0`, 10 labels `0x880EBCE4 .. 0x880EC254`.
- **palm_abnormal** (`futari_palm_abnormal_functions.toml`): switch @ `0x880DD7B4`,
  index r11, dispatch base `0x880DD7B8`, 10 labels `0x880DD7EC .. 0x880DDC54`.
  NOTE: unlike the others, the static table is NOT at the dispatch base (that
  region is code); read the real table at guest `0x880E41B8` in the decoded image.
- **reco_normal** (`futari_reco_normal_functions.toml`): switch @ `0x880EC87C`,
  index r11, 10 labels `0x880EC8B4 .. 0x880ECD1C`.
- **reco_abnormal** (`futari_reco_abnormal_functions.toml`): switch @ `0x880EC884`,
  index r11, 10 labels (guest base shifted -8 vs reco_normal).
- **kiniro_abnormal** (`futari_kiniro_abnormal_functions.toml`): switch @
  `0x880EF0D0`, index r11, 10 labels `0x880EF108 .. 0x880EF5BC` (table at
  anchor+4, guest `0x880EF0D4`), inside `sub_880EEFA8` — reached only via the
  Black Label DLC path (see Tracking Iteration 20). The other three unchecked
  modules (`kiniro_normal`, `hirow_normal`, `hirow_abnormal`) most likely carry
  the same game-select table shape at a shifted address; register only where a
  real crash or audit shows the `cases != bound+1` inconsistency.
  (Follow-up, Iteration 20: all four were audited and registered —
  kiniro_normal `0x880EF0C8`/table `0x880EF0CC`, hirow_normal
  `0x880EBCAC`/table `0x880EBCB0`, hirow_abnormal `0x880EBCB4`/table
  `0x880EBCB8`; audit criterion = switch whose `case` count differs from its
  bounds-check value+1, counted over `Switch case out of range` traps.)

After adding/editing an override TOML, regenerate ALL affected modules, rebuild all
DLLs, re-stage.

## Crash diagnostics playbook

Crash reporting gives a **host** RVA. Convert to a guest function:

- Build info: faulting module is a `futari_<module>.dll` loaded at image base
  `0x180000000`; **host addr = 0x180000000 + RVA**.
- The function table maps guest->host; use a fnmap TSV produced during analysis
  (`guest_start host_start size ...`) to find the containing function.

Signature `0xC000001D` (Illegal Instruction) at `UD2` is the recompiler's
`__builtin_trap()`, almost always the `default:` case of a switch compiled from a
guest jump table whose auto-detection was truncated — fix with a manual
`[[switch_tables]]` override.

To confirm the real jump table, extract the raw guest image from the shipped XEX
(the XEX is encrypted+compressed): parse the XEX2 header (`headerSize=0x2000`,
security offset `0x78`; AES-128-CBC blank IV + retail key; "basic" decompression
from `fileFormatInfo+8`; image base `0x88000000`), then build a **VA-layout image**
(copy each PE section's raw bytes to its `virtual_address`). A naive
"guest = base + file offset" mapping only works when a section's RawPtr == VA.

Windows Application log, source "Application Error", Event ID 1000, gives the
faulting module + RVA. There is no stack; the offset is the primary clue.

## Character-module swap / unload

The eight character modules all share the same image slot (base `0x88000000`, fixed
by their XEX headers). On real hardware a newly loaded module gets a free base while
the previous one stays resident; recompiled modules are pinned, so a second
`XexLoadImage` while one is resident fails with a base overlap. `src/futari_mod_swap_fix.cpp`
intercepts `sub_82088E10` (the XexLoadImage wrapper used only by the character
module constructors) and unloads the resident character module first, so the
shared slot frees up before the new load.

The SDK fork must also be able to *find* the recompiled module when it unloads. The
kernel hands back the NT device path
(`\Device\Harddisk0\Partition1\media\Module\x.xex`); `NormalizeGuestPath` strips that
device prefix, so it normalizes to the manifest guest path (`media/module/x.xex`) and
`FindRecompiledModule` matches. The earlier filename-only fallback covered
bare-filename manifests (dfkbl) but not subpath guest paths (futari's
`media/Module/...`): the mismatch left the function-table range and module library
leaked, so the next module's `InitializeFunctionTable` hit the overlap. See
`TRACKING.md`, Iteration 13. This is pinned in the SDK submodule; no manual
`rexruntime.dll` patch is needed.

The hook probes candidates through the requested path's directory (e.g.
`game:\media\Module\`) rather than bare filenames — a bare name has no VFS device, so
`GetModule` would log a spurious `ResolvePath failed` warning per candidate.

## Conventions

- Keep `TRACKING.md` current: each change to runtime/module behaviour gets an
  iteration entry (symptom → root cause → fix → status).
- Never commit `game_data/`, `user_data/`, `logs/`, `out/`, or binaries — see
  `.gitignore`.
- Do not add `codegen.build.stamp`/`codegen.d`/`codegen.stamp`/
  `codegen.partition.json` (they embed absolute paths; gitignored).
- Registering extra dynamic entrypoints = edit the `*_functions.toml`, not the
  generated `.cpp`.
- Only regenerate the module(s) you changed (`--target`, via the script) to avoid a
  full 8-module pass, then rebuild and re-stage. The runtime loads DLLs from the
  build output; run from `out/build/win-amd64-release/` (or `launch.bat`).
- Do not kill the game process; let it crash or exit naturally and read the newest
  log in `logs/` (`[error]`/`[critical]` are the actionable lines; `[warning]` is
  noise unless it correlates with a crash). The user drives the game UI.

## Rebuilding the SDK fork

Only if the runtime itself needs changing:

```
cd thirdparty/rexglue-sdk
# make changes, commit, push to the fork
cd ../..
git add thirdparty/rexglue-sdk
git commit -m "Bump SDK to <sha>"
```

Keep `generated/rexglue.cmake` in sync (it is regenerated by codegen, then
re-disabled for auto-codegen). Document SDK-side changes in `TRACKING.md`.

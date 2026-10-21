# Futari Recomp

Recompilation of the Xbox 360 shooter *Mushihimesama Futari* using
[ReXGlue](https://github.com/rexglue/rexglue-sdk).

The project builds a native `futari.exe` (plus eight character-module DLLs) from
statically recompiled PowerPC code. **The recompiled code and a patched ReXGlue SDK
are included in this repository**, so the project builds on a clean machine without
the game. Only *running* it needs your own copy of the game data.

For the engineering history (what was fixed and why), see [TRACKING.md](TRACKING.md).
For agent/developer working notes, see [AGENTS.md](AGENTS.md).

## Requirements

**To build** — no game files needed:

- CMake 3.25 or newer
- Ninja
- LLVM/Clang with C++23 support
- Windows: Visual Studio C++ build tools with a Windows SDK
- Linux: `libgtk-3-dev libx11-xcb-dev libvulkan-dev libasound2-dev libpulse-dev libpipewire-0.3-dev`
  (Debian/Ubuntu names); the `linux-*` presets expect `clang-20`/`clang++-20`

**To run** — your own copy of the Mushihimesama Futari disc, extracted into
`game_data/`:

```
game_data/
├─ default.xex              # entrypoint
├─ media/Module/
│  ├─ palm_normal.xex       # 1.5 arcade, player 1
│  ├─ palm_abnormal.xex     # Arrange novice, player 1
│  ├─ hirow_normal.xex      # Arrange 360, player 2
│  ├─ hirow_abnormal.xex    # Arrange novice, player 2
│  ├─ kiniro_normal.xex     # 1.5 arcade, player 2
│  ├─ kiniro_abnormal.xex   # 1.5 360, player 2
│  ├─ reco_normal.xex       # 1.5 arcade, player 1
│  └─ reco_abnormal.xex     # 1.5 360, player 1
├─ media/...                # fonts, sound, motion, etc.
├─ AvatarAssetPack
└─ nxeart
```

The eight character modules are loaded mutually exclusively from the character
select; all eight share guest base `0x88000000`, so only one is resident at a time.

## Layout

| Path | What |
| --- | --- |
| `src/` | Host application (`main.cpp`, `futari_app.h`, `futari_mod_swap_fix.cpp`) |
| `generated/default/` | Recompiled entrypoint + `dll_targets.cmake` / `module_registry.cpp` |
| `generated/palm_normal|.../` | Recompiled character modules (eight of them) |
| `generated/rexglue.cmake` | SDK/CMake glue (codegen auto-generation disabled — see below) |
| `futari_manifest.toml` | Codegen manifest (entrypoint + 8 modules) |
| `futari*_functions.toml` | Extra dynamic entrypoints and switch tables, per target |
| `futari.toml` | Runtime settings (auto-written; also editable via the F4 overlay) |
| `thirdparty/rexglue-sdk/` | Patched ReXGlue SDK (git submodule, pinned) |
| `scripts/codegen_all.ps1` | Regenerate all recompiled code (needs the game) |
| `TRACKING.md` | Iteration log (bugs found + fixes) |
| `AGENTS.md` | Working notes for agents/developers |

## Building

Clone with the submodule:

```
git clone --recurse-submodules https://github.com/beebs1998-repo/rexglue-futari.git
cd rexglue-futari
```

(Already cloned without it? Run `git submodule update --init --recursive`.)

The SDK submodule itself pulls ~20 upstream dependencies on first init, so this
step can take a few minutes.

### Windows

```
cmake --preset win-amd64-release
cmake --build --preset win-amd64-release --parallel
```

### Linux

```
cmake --preset linux-amd64-release
cmake --build --preset linux-amd64-release --parallel
```

> Linux is supported by the SDK and is exercised by CI, but has been validated
> less than Windows for this title. Report anything that breaks.

The build places the executable and all module/runtime DLLs in
`out/build/<preset>/`.

## First launch

1. Put your extracted game data in `game_data/` (see Requirements).
2. Either run `launch.bat` (Windows), or start the executable directly:

```
out\build\win-amd64-release\futari.exe --game_data_root="game_data" --user_data_root="user_data"
```

The game writes logs to `logs/` and saves to `user_data/`.

## Settings

The game reads and writes `futari.toml` **next to the executable**
(`out\build\win-amd64-release\futari.toml` by default). The copy in this
repository is a *template*: the build (POST_BUILD) and `launch.bat` stage it
next to the exe **only if the live file does not already exist**, so the
curated defaults are in effect from the very first launch. A copy-if-missing
staging rule means:

- your F4 edits and manual tweaks are never clobbered by a rebuild;
- editing the repo template after first stage does NOT propagate - delete
  the live copy (or re-edit via F4) to re-sync.

Settings can be changed live from the in-game overlay (press **F4**). The
debug overlay is **F3**. Defaults here use keyboard input
(`mnk_mode = true`); the key bindings are listed in `futari.toml`.

Saving is **diff-only**: only cvars whose current value differs from the
compiled-in SDK default are written. A cvar sitting at its default therefore
does not appear in the file, and a default-equal line is dropped by the next
save - that is expected, not a desync between the menu and the file.

**Audio buffering** (`audio_maxqframes = 32`): shipped value protects against
occasional crackling on some audio endpoints at the cost of added sound
latency — every buffered unit adds ~5 ms (each is a 256-sample block, so
32 ≈ 171 ms). If the sound delay feels unacceptable to you (e.g. menu sound
effects land late when scrolling), lower it — each step of −8 removes ~43 ms
of delay but increases the chance of brief crackles during busy moments;
`16` is about the floor (~85 ms). Raise it toward `64` if you trade the other
way. Restart the game to apply.

## Regenerating the recompiled code (optional)

Only needed if you change the manifest/function lists, or bump the SDK. It
requires the game files **and** the `rexglue` CLI (built with the SDK).

```
.\scripts\codegen_all.ps1
```

Then rebuild. Two things to know:

- The eight character modules share guest base `0x88000000`, so codegen refuses to
  process them in a single run; the script runs one target per invocation.
- `codegen` rewrites `generated/default/dll_targets.cmake`,
  `generated/default/module_registry.cpp` and `generated/rexglue.cmake` for the
  *last* target only. The committed copies are hand-merged (all eight modules) and
  auto-codegen is disabled in `rexglue.cmake`. The script restores them
  (`git checkout -- ...`) after running; don't let these get clobbered.

## Known issues

- **Character-module swapping** relies on an explicit unload of the resident
  character module before the next is loaded (see `src/futari_mod_swap_fix.cpp` and
  `TRACKING.md`); the hook frees the shared `0x88000000` slot. That unload in turn
  relies on the pinned SDK normalizing the kernel's
  `\Device\Harddisk0\Partition1\...` path back to the manifest guest path.
- **Discovery gaps** — auto-discovery misses functions that are only reached by
  indirect calls. These are now found **statically**, by running
  `scripts/build_module_hints.ps1` (XenonRecomp reference map diffed against
  ReXGlue's registered set; XenonRecomp is the git submodule
  `thirdparty/XenonRecomp`, built once per machine via
  `scripts/bootstrap_xenon.ps1`). The pass wrote the
  `futari_*_hints.toml` files (477 entries: palm 45/44, hirow 42/42, kiniro
  40/40, reco 46/46 normal/abnormal + 132 in the entrypoint) and should not
  need touching unless the SDK or codegen changes. If a new
  `[FATAL] Call to invalid or unregistered function at guest address 0x...`
  shows up anyway, re-run the derivation pass, or add the address to the right
  curated TOML and regenerate (see AGENTS.md).
- **Embedded-trap gate** — `scripts/validate_codegen.ps1` scans the committed
  `generated/` tree for recompiler failures baked into the code (`REX_FATAL`
  traps, stub functions) instead of relying on playtesting to find them. It
  runs in CI and after every `codegen_all.ps1`. Known residue is triaged in
  `scripts/trap_allowlist.txt` (17 entrypoint unresolved-call sites — pending
  the deferred parent/chunk SDK port — plus 5 module unresolved-branch sites
  and 1 stub; ~501 informational switch-case traps that the SDK hard-traps
  instead of falling back).
- **Jump tables** — the ten-entry character/mode switches had to be given manual
  `[[switch_tables]]` overrides; auto-detection truncates them. See `TRACKING.md`.
- **Module naming** — `palm_normal`, `reco_abnormal`, etc. are CAVE's internal
  names for the shipped XEX files; they do **not** correspond to the game's menu
  labels (e.g. "Palm - Normal shot"). The log's `XexLoadImage` lines show which
  module was actually resident.
- **Test coverage is WIP** — the eight modules are not fully playtested. Futari is
  a demanding game, so not every character/version/mode/section path has been
  reached. The static derivation pass closes the *unregistered-call* class for
  the whole code section, but mid-block loop targets and jump-table truncations
  can still surface on new paths (they register as embedded `REX_FATAL`
  branch/trap sites, which the gate flags with guest addresses instead of
  waiting for a runtime crash).

## Credits & legal

- Runtime/toolkit: [ReXGlue](https://github.com/rexglue/rexglue-sdk); this repo pins
  a lightly patched fork (`thirdparty/rexglue-sdk`) with the module-reload fixes
  described in `TRACKING.md`.
- **No game data or ROMs are included.** You must own Mushihimesama Futari and
  extract your own `game_data/`. The recompiled code in `generated/` is derived from
  that game and is provided for interoperability/archival research; use only with
  legally owned data.

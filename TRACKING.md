# Futari Recomp Tracking

Runtime/iteration log for unresolved addresses, missing symbols, and runtime
exceptions. Newest work at the bottom. See [AGENTS.md](AGENTS.md) for the working
notes that these iterations produced.

## Iteration 1 — Project init

- `rexglue init` generated `futari_manifest.toml` from `game_data/default.xex`;
  codegen and build clean.
- Entrypoint XEX has dynamic entrypoints not found by auto-discovery; converted
  `ep.txt` into `futari_functions.toml` and wired it in via
  `[entrypoint] includes`.
- **Status**: RESOLVED.

## Iteration 2 — Character modules added

- The game loads eight character modules (`palm/hirow/kiniro/reco` ×
  `normal/abnormal`) from `media/Module/*.xex`; all share guest base `0x88000000`
  and are loaded mutually exclusively from character select.
- Added all eight to `futari_manifest.toml` with per-module `includes`.
- **Status**: RESOLVED - modules discovered and generated.

## Iterations 3-7 — Stage-gap crashes (name-only overrides)

- Each stage drove the game further and hit `[FATAL] Call to invalid or
  unregistered function at guest address 0x...` in gaps that auto-discovery missed.
- Root cause: systematic discovery gaps in certain guest ranges; adding a name-only
  override registers the address as CONFIG authority (before PDATA), so discovery
  uses natural boundaries.
- Added to **all eight** character TOMLs, one per stage crash:
  - `0x881B2978`, `0x881B83D0` (stage 2)
  - `0x881C5530`, `0x88180500` (stage 3)
  - `0x880B0B48` (stage 4)
  - `0x880A49B0` (stage 5 boss)
- **Status**: RESOLVED - stages 1-5 passable (Arrange ver, palm/reco tested).

## Iteration 8 — palm_normal bogus PDATA size

- PDATA-derived size for `0x88085F7C` is bogus (2105724 bytes), which crashed
  codegen.
- Fix: name-only `[functions."0x88085F7C"]` override so the PDATA loop skips it and
  discovery uses natural boundaries.
- `0x881E8F28` (palm_normal) — hirow_abnormal calls `sub_88150A58` with
  `lr=0x881E8F28`; `0x881E7200` (palm_normal + reco_normal) — gap between
  auto-discovered functions. Both name-only overrides.
- **Status**: RESOLVED.

## Iteration 9 — Jump-table truncation (`0xC000001D`)

- Crash signature: `0xC000001D` (Illegal Instruction) at a `__builtin_trap()`, the
  `default:` case of a switch compiled from a guest jump table.
- Root cause: the ten-entry character/mode switch's bounds check was mis-scanned
  (matched an earlier `cmpwi r11,7` instead of `cmplwi r10,9`), truncating the table
  to 2 of 10 cases. A legal runtime index in [2,9] hit `default:` → UD2.
- Fix: manual `[[switch_tables]]` overrides for the four affected modules:
  - palm_normal @ `0x880EBCAC` (r11, 10 labels `0x880EBCE4..0x880EC254`)
  - palm_abnormal @ `0x880DD7B4` (r11, 10 labels `0x880DD7EC..0x880DDC54`;
    static table read at guest `0x880E41B8`, not the dispatch base)
  - reco_normal @ `0x880EC87C` (r11, 10 labels `0x880EC8B4..0x880ECD1C`)
  - reco_abnormal @ `0x880EC884` (r11, 10 labels, base shifted -8 vs reco_normal)
- Confirmed by extracting the raw guest image from the encrypted+compressed XEX and
  reading the BE u32 target tables at their VAs.
- **Status**: RESOLVED - verified (10 `case N:` labels emitted).

## Iteration 10 — Source availability note (ignored)

- `Unresolved b target ...` warnings during codegen are informational; the
  resulting code still built and ran.

## Iteration 11 — Character-module swap / unload leak

- Symptom chain: every swap **loaded** fine, but the previous module was never
  unregistered, so its guest image range stayed reserved. The next module's
  function-table init reported an image-range overlap, or the path lookup missed
  and `user_modules_` dropped the module (repeated load refusals).
- Root cause: `NormalizeGuestPath` did not strip the
  `\Device\Harddisk0\Partition1` prefix (with a segment-slice off-by-one), so the
  normalized path was empty and `FindRecompiledModule(module->path())` missed during
  `UnloadUserModule`; `UnregisterModule` was skipped and the range leaked. A second
  off-by-one in `utf8_ends_with_case` broke the `.xex` suffix match.
- Fix (SDK): correct the device-prefix strip and the reverse-compare loop; make
  `FindRecompiledModule` match on the extracted filename as well.
- Fix (futari side): `src/futari_mod_swap_fix.cpp` intercepts `sub_82088E10`
  (the XexLoadImage wrapper used by the character-module constructors) and unloads
  the currently-loaded character module first, freeing the shared `0x88000000` slot.
- **Status**: RESOLVED - verified with
  reco_normal → reco_abnormal → palm_normal → palm_abnormal cycling cleanly.

## Iteration 12 — Migrate to the SDK fork (v0.10.0)

- Retargeted the project from the old in-tree SDK (v0.9.0) to the patched fork
  `beebs1998-repo/rexglue-sdk` (`v0.10.0`), vendored as a pinned git submodule at
  `thirdparty/rexglue-sdk` (initially `c5b544d`, then `8c6b399` after Iteration 13).
- The v0.10.0 generated-output layout changed (`futari_pch.h`, split
  `futari_funcs.N.h`, smaller `futari_init.{h,cpp}`), so all `generated/**` was
  regenerated. All preserved `*_functions.toml` overrides were re-applied.
- v0.10.0 enforces a guest-image overlap check at codegen: the eight shared-base
  character modules can no longer be generated in one run. Code is now generated
  one `--target` per invocation; `generated/default/dll_targets.cmake` and
  `generated/default/module_registry.cpp` are hand-merged for all eight modules and
  restored by `scripts/codegen_all.ps1`. Auto-codegen was disabled in
  `generated/rexglue.cmake` for the same reason.
- The fork carried only the *filename-match* half of the Iteration 11 unload fix
  (commit `5690871`); the `NormalizeGuestPath` device-prefix strip lived in the old
  in-tree SDK and was **not** carried over. That omission surfaced as Iteration 13.
  The manual `rexruntime.dll` staging step is still gone.
- **Status**: SDK/submodule + codegen restructure done.

## Iteration 13 — Character-module swap regression after the SDK migration

- Symptom (first post-migration playtest): loading a second character module failed
  and the game crashed with `[FATAL] Call to invalid or unregistered function at
  guest address 0x40A22310`:

  ```
  XexUnloadImage('\Device\Harddisk0\Partition1\media\Module\reco_abnormal.xex', ...)
  XexUnloadImage(...): load_count now 0, last_ref=1
  UnloadUserModule(...): recomp=NOT FOUND module_libraries=1
  ...
  Module image range [88000000, 88CF4AC0) overlaps existing [88000000, 88B8DD70)
  InitializeFunctionTable failed for module 'palm_normal.xex'
  XexLoadImage(...): LoadUserModule failed
  ```

- Root cause: `KernelState::FindRecompiledModule` matches either the normalized path
  or its filename against the registered guest path. The registry key for a character
  module is the subpath `media/module/reco_abnormal.xex` (from the manifest), but on
  unload the kernel hands back the NT device form
  `\Device\Harddisk0\Partition1\media\Module\reco_abnormal.xex`. `NormalizeGuestPath`
  only stripped the drive-colon form (`X:/...`), so it produced
  `device/harddisk0/partition1/media/module/reco_abnormal.xex` — and the filename
  fallback produced `reco_abnormal.xex`. Neither equals the key, so `recomp=NOT FOUND`:
  `UnregisterModule` was skipped and both the function-table range and the
  `module_libraries_` entry leaked. `InitializeFunctionTable` then rejected the next
  module (all eight share base `0x88000000`), `LoadUserModule` failed, and the game
  jumped through a null entry. (dfkbl is unaffected only because its modules sit at
  the game root, so its guest path *is* a bare filename.)
- Fix (SDK fork, `8c6b399`): `NormalizeGuestPath` now drops the mount prefix through
  the first `partitionN` segment when the path begins with `device/`, honouring its
  documented "no device prefix" contract. The NT path now normalizes to
  `media/module/reco_abnormal.xex` and matches the registry key. Extended the
  `guest_path` unit tests; also linked `xxHash` into `unit_tests` so `rex/hash.h`
  (a public header of `rexcore`, linked `PRIVATE`) can be compiled by the suite.
- Fix (futari): dropped the diagnostic `GetModule` probes in
  `src/futari_mod_swap_fix.cpp` that generated the VFS spam, and made the remaining
  probe use the requested path's directory so `ResolvePath` hits the mount instead of
  a bare filename.
- Verified (`futari_006.log`): four consecutive character swaps, each reporting
  `UnloadUserModule(...): recomp=found` and `Unregistering module: ...`, with no
  image-range overlap and no `[FATAL]`, then a clean window close:

  ```
  reco_abnormal (5558) -> palm_normal (5609) -> reco_normal (5555) -> palm_abnormal (5563)
  ```

  In all four transitions the game unloaded the outgoing module itself (the hook
  logged nothing), so `src/futari_mod_swap_fix.cpp` is now a safety net for the case
  where the game would leave a module resident, rather than the primary path.
- **Status**: RESOLVED.

## Iteration 14 — SDK bump to the rewritten fork head (34ea1a0)

- Context: the fork `beebs1998-repo/rexglue-sdk` force-pushed `origin/main`,
  rewriting the history onto v0.10.0 with cherry-picked equivalents of our
  runtime patches. New branches appeared: `origin/pristine` (= `origin/main`,
  upstream-aligned) and `origin/legacy` (the previous 5-commit fork line plus
  one new commit).
- New pin: `34ea1a0` = `v0.10.0` + 4 commits — SSSE3 build flag (`39626a2`,
  Clang-only cherry-pick of `c5b544d`, but the full tree diff shows no
  toolchain/SSSE3 delta between the two pins), module-match-by-filename +
  load/unload logging (`09ef27d`), `NormalizeGuestPath` NT-device-prefix strip
  (`a388c9d`), and a default flip of `d3d12_submit_on_primary_buffer_end` to
  false (`34ea1a0`).
- **Archive: what is dropped from the legacy line (`8c6b399`; preserved
  untracked on `origin/legacy` @ `f7d591f`)** — exactly two commits, both
  graphics/UI and both unused by this project (`src/`, `futari.toml` reference
  none of these cvars; `futari.toml` only sets core `vsync = true`, which
  exists in v0.10.0 already):
  - `d1de8d1` — adaptive VBlank pacing boost + telemetry + rate-limited GPU
    logs: cvars `slowdown_pacing_boost`, `slowdown_pacing_boost_multiplier`,
    `slowdown_debug_log`; `GraphicsSystem::NotifySwapSubmitted`,
    `vblank_count()`, `swap_count()`, and the adaptive VBlank worker in
    `graphics_system.cpp` / `command_processor.cpp` / `util/draw.cpp`.
  - `793728c` — D3D12 VSync and guest-thread presentation cvars:
    `d3d12_present_vsync` and `present_guest_thread_immediate`
    (`src/ui/d3d12/d3d12_presenter.cpp`, `src/ui/presenter.cpp`).
  Diff audit `git diff 8c6b399 34ea1a0` covers exactly those 8 files (+34/-252
  net -218); `src/system/` — where both module-unload fixes from Iteration 13
  live — is **byte-identical** between the two pins, so no archive concerns
  there.
- New behavior to watch: `d3d12_submit_on_primary_buffer_end` now defaults to
  false (batched `ExecuteCommandLists` at swap/sync boundaries instead of
  per-chunk submission). `futari.toml` does not pin this cvar, so the new
  default applies at the next run.
- Fix: submodule `git checkout --detach 34ea1a0`; commit `Bump SDK to 34ea1a0`;
  `AGENTS.md` fact #2 refreshed with the new pin + legacy-branch pointer.
- **Status**: RESOLVED. Reconfigured the build tree off the stale cached
  `REXSDK_DIR=I:/workspace/rexglue-sdk` (old `8c6b399` tree, left untouched)
  onto the pinned submodule (nested `thirdparty/*` submodules initialized);
  full build succeeded (`futari.exe` + all eight `futari_<module>.dll`).
  Playtest (`futari_003.log`): no `[error]`/`[critical]`, normal module
  unload/init traffic, clean shutdown (`Window closing` → `Title terminated`).
  No graphic or pacing anomalies; character and game-mode switching (1.5 /
  Arrange / Novice) all work.

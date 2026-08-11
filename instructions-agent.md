# Agent Harness Instructions - Reproduce the Futari Recomp Project From Scratch

This document tells an agent how to reproduce the **Mushihimesama Futari (Xbox 360)**
recompilation project from a blank workspace, using `rexglue-sdk`. It is a superset
of `instructions.md` (do NOT modify that file) and adds agent-specific workflows,
workarounds, and diagnostic knowledge discovered during development.

## 1. Environment

| Item            | Value                                                    |
|-----------------|----------------------------------------------------------|
| Host OS         | Windows 10/11, PowerShell 5.1                            |
| Project root    | `I:\workspace\futari`                                    |
| SDK root        | `I:\workspace\futari\rexglue-sdk`                        |
| SDK CLI         | `rexglue.exe` (not on PATH; always use the full path)    |
| Reference docs  | `I:\workspace\rexglue-sdk.wiki`, `I:\workspace\360tools` |
| Method reference| `I:\workspace\SDOJ-Recomp` (sister project)              |
| Compiler        | clang/clang++ (Ninja generator via `CMakePresets.json`)  |

Prereqs: the game assets (XEX files) must already be present under `game_data/`.
There are **9** XEX images:
`default.xex` (entrypoint) + 8 character modules
(`palm/hirow/kiniro/reco` x `normal/abnormal`). All modules share guest base
`0x88000000`; only one is loaded at a time (character select).

The project-root `rexruntime.dll` must be the **patched** build carrying the
module-swap/unload fix (Section 7.1). It is already staged at the project root;
if you rebuild it, re-stage it (the game loads the root copy, not the build tree).

## 2. From-Scratch Reproduction Flow

### Step 1 - Initialize the project

```powershell
cd I:\workspace\futari
& "I:\workspace\futari\rexglue-sdk\out\install\win-amd64\bin\rexglue.exe" init `
    --project-name "futari" `
    --game-root game_data `
    --xex-path game_data/default.xex `
    --force
```

Creates `futari_manifest.toml`. Inspect it and ensure every character module has a
`[[modules]]` entry:

```toml
[[modules]]
guest_path = "media/Module/reco_normal.xex"
file_path = "game_data/media/Module/reco_normal.xex"
out_directory_path = "generated/reco_normal"
includes = ["futari_reco_normal_functions.toml"]   # per-module override toml
```

(When starting from scratch, `includes` will be `[]`; add per-module override files
as described in Section 4.)

### Step 2 - Register dynamic entrypoints

`ep.txt` holds entrypoint functions that must be re-registered by name. Convert it
into `futari_functions.toml`:

```toml
[functions."0x8210B038"]
name = "sub_8210B038"
```

and reference it from the entrypoint module:
`includes = ["futari_functions.toml"]` under the `[entrypoint]` table.

### Step 3 - Configure the build

Ensure `CMakePresets.json` exists with at least these presets:
- `win-amd64-debug`
- `win-amd64-release`
- `win-amd64-relwithdebinfo`

Configure (choose release for the shipped artifact):

```powershell
cmake --preset win-amd64-release
```

This writes to `out/build/win-amd64-release` (Ninja generator).

### Step 4 - Generate code

```powershell
& "I:\workspace\futari\rexglue-sdk\out\install\win-amd64\bin\rexglue.exe" codegen futari_manifest.toml
```

Output: `generated/<module>/futari_recomp.N.cpp` (split sources),
`futari_register.cpp`, `futari_init.cpp`, `futari_init.h`, `sources.cmake`,
plus `generated/default/` (`module_registry.cpp`, `dll_targets.cmake`, `rexglue.cmake`).

### Step 5 - Build

```powershell
cmake --build --preset win-amd64-release --target futari -j 8
```

Produces `futari.exe` plus per-module DLLs in `out/build/win-amd64-release/`
(e.g. `futari_reco_normal.dll`, `futari_palm_normal.dll`, ...). A full clean build of
all 8 modules + entrypoint takes several minutes; incremental single-module builds
are fast (see Section 5).

### Step 6 - Stage runtime binaries and run

The runtime loads DLLs from the project root. Copy freshly built DLLs there before
running (and `rexruntime.dll` too, if the SDK changed - Section 7.1):

```powershell
Copy-Item "out\build\win-amd64-release\futari_*.dll" -Destination "I:\workspace\futari\" -Force
cd I:\workspace\futari
.\futari.exe --game_data_root="game_data" --user_data_root="user_data"
```

Do not kill the process prematurely; wait for crash or natural exit. Logs are written
to `logs/futari_###.log` (numbered, newest = highest number). The user drives the
game UI (character select triggers module load).

### Step 7 - Iterate

1. Read the newest log in `logs/`.
2. Filter `[error]`/`[critical]`; ignore `[warning]` unless tied to a crash.
3. Map any crash to a generated function (Section 6) and apply a fix (Sections 4/5/7).
4. Regenerate the affected module, rebuild, re-stage the DLL, re-run.

## 3. Key File Layout

```
I:\workspace\futari\
  futari_manifest.toml              # modules, includes, project settings
  futari_functions.toml             # entrypoint dynamic functions (from ep.txt)
  futari_<module>_functions.toml    # per-module overrides (name, switch tables)
  futari_palm_normal_functions.toml     # palm_normal: name overrides + switch table
  futari_palm_abnormal_functions.toml   # palm_abnormal: name override + switch table
  futari_hirow_normal_functions.toml    # hirow_normal: name-only overrides
  futari_hirow_abnormal_functions.toml  # hirow_abnormal: name-only overrides
  futari_kiniro_normal_functions.toml   # kiniro_normal: name-only overrides
  futari_kiniro_abnormal_functions.toml # kiniro_abnormal: name-only overrides
  futari_reco_normal_functions.toml     # reco_normal: name override + switch table
  futari_reco_abnormal_functions.toml   # reco_abnormal: name override + switch table
  palm_only_manifest.toml           # temp single-module manifest (palm_normal)
  palm_abnormal_only_manifest.toml  # temp single-module manifest (palm_abnormal)
  rexruntime.dll                    # PATCHED runtime (module-swap fix, Sec 7.1)
  futari.exe                        # runtime (staged from out/)
  futari_<module>.dll               # staged module DLLs (runtime loads these)
  game_data/default.xex, media/Module/*.xex
  generated/<module>/futari_recomp.N.cpp
  generated/default/                # module_registry.cpp, dll_targets.cmake
  generated/default/module_registry.cpp.merged  # full 8-module registry (restore target)
  out/build/win-amd64-release/      # cmake+ninja artifacts
  logs/futari_###.log
  src/main.cpp, src/futari_mod_swap_fix.cpp
```

## 4. Per-Module Override TOML (the fix mechanism)

Overrides live in `futari_<module>_functions.toml`, referenced by that module's
`includes` in the manifest. Two kinds are in use:

### Name-only overrides (function boundaries)

Name-only overrides tell the recompiler to treat a guest address as a function entry
point. CONFIG authority => registered before PDATA analysis, so discovery uses natural
boundaries (branch instructions) instead of potentially bogus PDATA size data.

**Systematic gap pattern**: Auto-discovery systematically misses functions in certain
guest address ranges (~0x881BXXXX, ~0x881E7XXX, ~0x881E8XXX, ~0x880AXXXX,
~0x880BXXXX). When the game crashes at an unregistered function, add a name-only
override to ALL 8 character modules (`futari_<module>_functions.toml`) since the same
guest address range is shared across all modules.

```toml
# Pattern: [functions."<GUEST_ADDR>"]
#          name = "sub_<GUEST_ADDR>"
```

**Already-fixed gaps** (add to ALL 8 module TOMLs unless noted):

| Address | Modules | Notes |
|---------|---------|-------|
| `0x881E8F28` | palm_normal only | hirow_abnormal calls sub_88150A58 with lr=0x881E8F28 |
| `0x881E7200` | palm_normal + reco_normal | Gap between auto-discovered functions |
| `0x881B2978` | All 8 modules | Stage 2 crash |
| `0x881B83D0` | All 8 modules | Stage 2 crash |
| `0x881C5530` | All 8 modules | Stage 3 crash |
| `0x88180500` | All 8 modules | Stage 3 crash |
| `0x880B0B48` | All 8 modules | Stage 4 crash |
| `0x880A49B0` | All 8 modules | Stage 5 boss crash |

**palm_normal specific - bogus PDATA size**:
```toml
# PDATA-derived size for 0x88085F7C is bogus (2105724), which crashed codegen.
[functions."0x88085F7C"]
name = "sub_88085F7C"
```

### Manual switch tables (auto-detection bugs)

```toml
# reco_normal: sub_880EC758 (switch @0x880EC87C). Auto-detection mis-scans the
# bounds check (matches the earlier "cmpwi r11,7" instead of "cmplwi r10,9"),
# truncating the table to 2 of 10 entries. Manual override with the full table.
[[switch_tables]]
address = 0x880EC87C     # guest address of the bctr instruction
register = 11            # index register the switch reads
labels = [
    0x880EC8B4,
    0x880EC8D0,
    0x880EC900,
    0x880EC954,
    0x880EC98C,
    0x880EC998,
    0x880ECBA8,
    0x880ECC84,
    0x880ECCC4,
    0x880ECD1C,
]
```

After adding/editing an override TOML, regenerate ALL affected modules (Section 5),
rebuild all DLLs, re-stage.

The same truncation bug hit all three character modules that expose a 10-entry
character-select/mode switch. Fixed with the same mechanism:

- **palm_normal** (`futari_palm_normal_functions.toml`): switch @ `0x880EBCAC`,
  index r11, table base `0x880EBCB0`, 10 labels `0x880EBCE4 .. 0x880EC254`.
- **palm_abnormal** (`futari_palm_abnormal_functions.toml`): switch @ `0x880DD7B4`,
  index r11, dispatch base `0x880DD7B8`, 10 labels `0x880DD7EC .. 0x880DDC54`.
  NOTE: unlike the others, the static table is NOT at the dispatch base (that
  region is code); read the real table at guest `0x880E41B8` in the decoded
  image (Section 6.3). The game patches the dispatch slot at runtime, but the C++
  switch compiled from the static labels is what runs.
- **reco_normal** (`futari_reco_normal_functions.toml`): switch @ `0x880EC87C`,
  index r11, 10 labels `0x880EC8B4 .. 0x880ECD1C`.
- **reco_abnormal** (`futari_reco_abnormal_functions.toml`): switch @ `0x880EC884`,
  index r11, 10 labels (guest base shifted -8 vs reco_normal).

## 5. Single-Module Regeneration (important workaround)

The dev SDK build (`0.9.0.1-dev.gcb58065`) **crashes deterministically**
(0xC0000005) during the `palm_normal` Discover phase when running a full-manifest
codegen. Two workarounds:

**Preferred - `--target`:** regenerate just the modules you changed:

```powershell
& "I:\workspace\futari\rexglue-sdk\out\install\win-amd64\bin\rexglue.exe" codegen futari_manifest.toml --target palm_normal
```

(entrypoint `default.xex` is always processed too; that is fine). Exit code 0 = OK.
The trailing `BaseHeap::Release failed because address is not a region start` line is
harmless.

To regenerate all modules at once:

```powershell
& "I:\workspace\futari\rexglue-sdk\out\install\win-amd64\bin\rexglue.exe" codegen futari_manifest.toml --target palm_normal palm_abnormal hirow_normal hirow_abnormal reco_normal reco_abnormal kiniro_normal kiniro_abnormal
```

**Fallback - temp single-module manifest:** if `--target` misbehaves, write a temp
manifest containing only `[project]`, `[entrypoint]`, and the one `[[modules]]`
entry, run codegen on it, then delete it. Working examples at the project root:
`palm_only_manifest.toml`, `palm_abnormal_only_manifest.toml` (keep the
entrypoint's `includes = ["futari_functions.toml"]` and the module's override
include). The temp-manifest codegen succeeds even when the full-manifest run
crashes.

**IMPORTANT - restore `module_registry.cpp` after ANY temp-manifest codegen:**
codegen rewrites `generated/default/module_registry.cpp` to only the modules in
the manifest it processed. Restore the full 8-module registry from
`generated/default/module_registry.cpp.merged` before building:

```powershell
Copy-Item "generated\default\module_registry.cpp.merged" "generated\default\module_registry.cpp" -Force
```

Then rebuild and re-stage that module only:

```powershell
cmake --build --preset win-amd64-release --target futari_reco_normal
Copy-Item "out\build\win-amd64-release\futari_reco_normal.dll" -Destination "I:\workspace\futari\" -Force
```

## 6. Crash Diagnostics Playbook

### 6.1 Fault containment: guest <-> host mapping

Crash reporting gives a **host** RVA. Convert to guest function:

- Build info: faulting module is a `futari_<module>.dll` loaded at image base
  `0x180000000`; **host addr = 0x180000000 + RVA**.
- The function table maps guest->host. Dump it from the module with a Python script
  (search the image for the known host offset +0x4DC9 style deltas), or use the
  fnmap TSV produced during analysis:
  `reco_normal_fnmap.tsv` columns: `guest_start host_start size ...`, e.g.
  `0x880EC758 0x1802A1810 0x...` -> containing function for host 0x1802A65D9
  (RVA 0x2A65D9) is `sub_880EC758`.

### 6.2 Signature: `0xC000001D` (Illegal Instruction) at UD2

This is the recompiler's `__builtin_trap()`, almost always emitted as the `default:`
case of a switch compiled from a guest jump table:

```cpp
// generated/reco_normal/futari_recomp.4.cpp
switch (ctx.r11.u32) {
case 0: goto loc_880EC8B4;
case 1: goto loc_880EC8D0;
default:
    __builtin_trap(); // Switch case out of range
}
```

Guest `bctr` (compiled to this switch) is a **jump table**: index r11, table at guest
`0x880EC880`, bounded by `cmplwi cr6,r10,9` before the `bctr`. A legal runtime index
in [2,9] hits `default:` -> UD2 -> crash. Root cause: jump-table auto-detection
truncation (Section 4). Fix: manual `[[switch_tables]]` override with the full label
list.

### 6.3 Confirming the real jump table from the guest image

The shipped XEX is encrypted+compressed; extract the raw guest image with a script
like `C:\Users\Lychee\AppData\Local\Temp\opencode\dump_xtable.py`
(XEX2 parse: headerSize=0x2000, security offset 0x78; AES-128-CBC blank IV + retail
key `20B185A5...`; "basic" decompression, blocks from fileFormatInfo+8; image base
0x88000000; output `reco_normal_image.bin`, 0x7B0000 bytes).

- Build a **VA-layout image**: allocate an `imageSize`-byte buffer (from the XEX
  security header) and copy each PE section's raw bytes to its `virtual_address`;
  the runtime maps sections at their VAs (see the `Function table initialized for
  module: code=...` log line, e.g. code=`0x88080000` = base + `.text` VA `0x80000`).
  Then guest addr = `0x88000000 + RVA` = buffer[RVA]. A naive "guest = base +
  file offset" linear mapping only works when a section's RawPtr == VA
  (coincidentally true for reco_normal, whose table is at RVA `0xEC880`).
- Jump tables are 10 big-endian u32 targets. **palm_abnormal gotcha:** the
  dispatch base in the generated code (`0x880DD7B8`) contains code, NOT the
  table; read the static table at guest `0x880E41B8` (RVA `0xE41B8`) instead.
  Validate you found the right table by checking entries[0] and [1] equal the two
  labels codegen already emitted (e.g. `0x880DD7EC`, `0x880DD808`).

### 6.4 Event Log

Windows Application log, source "Application Error", Event ID 1000, gives the
faulting module + RVA (e.g. `futari_reco_normal.DLL`, offset `0x2A65D9`). There is no
stack; the offset is the primary clue.

## 7. Known Issues & How They Were Resolved

| Symptom | Cause | Fix |
|---------|-------|-----|
| Codegen crashes (0xC0000005) during full run on `palm_normal` | Dev SDK bug; palm_normal overrides are name-only so discovery can still hit bad boundaries | `codegen --target <module>` (Section 5) |
| `0xC000001D` at a `__builtin_trap()` in a switch | Auto-detected jump table truncated (bounds mis-scan: earlier `cmpwi r11,7` matched instead of `cmplwi r10,9`) | Manual `[[switch_tables]]` override (Section 4) |
| palm_abnormal hard host crash at character select (no REX FATAL line, process just dies) | Switch @`0x880DD7B4` auto-detection truncated to 2 of 10 cases (same bounds mis-scan); index >= 2 -> `__builtin_trap()` | `[[switch_tables]]` override, labels from static table at guest `0x880E41B8` (Section 4) |
| Function with bogus huge PDATA-derived size | PDATA says e.g. 2105724 bytes | Name-only `[functions."0x..."]` override |
| Game won't load module after rebuild | DLL not re-staged to project root | `Copy-Item` rebuilt DLL to `I:\workspace\futari\` |
| `InitializeFunctionTable failed` in log | Module registration/table mismatch after stale DLL | Rebuild + re-stage + retest |
| Character modules stop swapping; next load fails with an image-range overlap, or `GetModule()` finds nothing after an unload | Module unload never matched its registry entry (Section 7.1) | Patch the 3 SDK source files + re-stage `rexruntime.dll` (Section 7.1) |
| Repeated unregistered function crashes at new addresses | Systematic auto-discovery gaps in certain guest address ranges | Add name-only overrides to ALL affected module TOMLs (Section 4) |

### 7.1 Module swap / unload-leak fix (one-time SDK patch + runtime rebuild)

Symptom chain (runs 023-024): every character-module swap **loaded** fine, but
the *previous* module was never unregistered, so its guest image range stayed
reserved. The next module's function-table init either reported an image-range
overlap or the path lookup silently missed and `user_modules_` dropped the module.

Root cause - three fixes in the rexglue-sdk sources:

- `src/system/guest_path.cpp` `NormalizeGuestPath`: did not strip the
  `\Device\Harddisk0\Partition1` mount prefix; a segment-slice off-by-one
  (`pos+1`) lopped the first char off every segment (`arddisk0`, `artition1`),
  so "Partition" never matched and the whole path was erased to an **empty
  string**. `FindRecompiledModule(module->path())` then missed during
  `UnloadUserModule`, `UnregisterModule` was skipped, and the image range leaked.
  Fix: walk `/Device/<bus>/<index>/<disk>/Partition<N>/...` segments correctly
  (start at `pos = 1`, slice `[pos, next)`, search `find('/', pos)`) and strip the
  prefix so `media/module/<name>.xex` matches the key used at load time.
- `src/core/utf8.cpp` `utf8_ends_with_case`: off-by-one in the reverse-compare
  loop (`for (size_t i = 0; ...)` -> `for (size_t i = 1; ...)`), which broke the
  `.xex` suffix match used by the same lookup path.
- `src/system/kernel_state.cpp` `GetModule`: temporary diagnostics
  (`futari fix diag:`) confirming the path mismatch; harmless to keep.

There is also a futari-side hook `src/futari_mod_swap_fix.cpp`: it intercepts
`sub_82088E10` (the XexLoadImage wrapper used by the character-module
constructors) and unloads any previously loaded character module first, so the
shared `0x88000000` slot frees up before the new load.

Rebuild + stage the runtime (the game loads `rexruntime.dll` from the **project
root**, not the futari build tree):

1. Rebuild the SDK Release runtime so `rexruntime.dll` comes out of
   `I:\workspace\futari\rexglue-sdk\out\win-amd64\Release\rexruntime.dll`.
2. `Copy-Item` that DLL over `I:\workspace\futari\rexruntime.dll` and confirm
   `LastWriteTime` updated before testing.

Verified by run 024: reco_normal -> reco_abnormal -> palm_normal -> palm_abnormal
all unregister and register cleanly with no overlap.

## 8. Rules for the Agent

1. NEVER modify `instructions.md`. Keep rexglue-sdk source edits to the
   documented one-time module-swap fix (Section 7.1); the prebuilt patched
   `rexruntime.dll` is already staged at the project root, so normal workflows do
   not touch the SDK.
2. Always use the full path to `rexglue.exe`; it is not on PATH.
3. Only regenerate the module(s) you changed (`--target`) to avoid the known codegen
   crash; a full-manifest run is acceptable only if it succeeds (it currently does
   NOT with the dev SDK). After any temp-manifest codegen, restore
   `generated/default/module_registry.cpp` from `module_registry.cpp.merged`.
4. Re-stage rebuilt DLLs to the project root and confirm `LastWriteTime` updated
   before asking the user to test. If you rebuild `rexruntime.dll`, re-stage it
   too (Section 7.1).
5. Verify generated fixes in the `.cpp` output (e.g. count `case N:` labels) before
   rebuilding.
6. Do not kill the game process; let it run to crash/exit naturally and read the
   newest numbered log.
7. Preserve the existing override TOMLs (they encode hard-won fixes).
8. The user drives the game UI (menu navigation + character select). Runs that end
   with `Window closing, shutting down...` without a module load mean the fix
   wasn't exercised; ask before relaunching.

## 9. Current Status & Known Gaps

### Gameplay Progress
- **Stage 1**: ✓ Passable (Arrange ver - palm/reco tested)
- **Stage 2**: ✓ Passable (Arrange ver - palm/reco tested)
- **Stage 3**: ✓ Passable (Arrange ver - palm/reco tested)
- **Stage 4**: ✓ Passable (Arrange ver - palm/reco tested)
- **Stage 5**: ✓ Passable (Arrange ver - palm/reco tested)

### All Function Overrides (as of latest build)
Total: 8 name-only overrides across modules + 3 switch table overrides.

**palm_normal_functions.toml:**
- `[functions."0x88085F7C"]` - bogus PDATA size fix
- `[functions."0x881E8F28"]` - hirow_abnormal cross-module return
- `[functions."0x881E7200"]` - gap between sub_881E6E50/sub_881E7208
- `[functions."0x881B2978"]`, `["0x881B83D0"]`, `["0x881C5530"]`, `["0x88180500"]`,
  `["0x880B0B48"]`, `["0x880A49B0"]` - all systematic gaps
- `[[switch_tables]] @ 0x880EBCAC` - 10-entry jump table (r11)

**palm_abnormal_functions.toml:**
- `[functions."0x881B2978"]`, `["0x881B83D0"]`, `["0x881C5530"]`, `["0x88180500"]`,
  `["0x880B0B48"]`, `["0x880A49B0"]` - all systematic gaps
- `[[switch_tables]] @ 0x880DD7B4` - 10-entry jump table (r11)

**hirow_normal_functions.toml / hirow_abnormal_functions.toml:**
- `[functions."0x881B2978"]`, `["0x881B83D0"]`, `["0x881C5530"]`, `["0x88180500"]`,
  `["0x880B0B48"]`, `["0x880A49B0"]` - all systematic gaps

**kiniro_normal_functions.toml / kiniro_abnormal_functions.toml:**
- `[functions."0x881B2978"]`, `["0x881B83D0"]`, `["0x881C5530"]`, `["0x88180500"]`,
  `["0x880B0B48"]`, `["0x880A49B0"]` - all systematic gaps

**reco_normal_functions.toml:**
- `[functions."0x881E7200"]` - gap between sub_881E7100/sub_881E7470
- `[functions."0x881B2978"]`, `["0x881B83D0"]`, `["0x881C5530"]`, `["0x88180500"]`,
  `["0x880B0B48"]`, `["0x880A49B0"]` - all systematic gaps
- `[[switch_tables]] @ 0x880EC87C` - 10-entry jump table (r11)

**reco_abnormal_functions.toml:**
- `[functions."0x881B2978"]`, `["0x881B83D0"]`, `["0x881C5530"]`, `["0x88180500"]`,
  `["0x880B0B48"]`, `["0x880A49B0"]` - all systematic gaps
- `[[switch_tables]] @ 0x880EC884` - 10-entry jump table (r11)

### Debugging Workflow for New Gaps
When a new unregistered function crash appears:
1. Check if the address is in range for ALL modules (it almost always is)
2. Add `[functions."<ADDR>"]` override to ALL affected TOML files
3. Regenerate all modules: `codegen --target palm_normal palm_abnormal ...`
4. Rebuild all DLLs: `cmake --build --preset win-amd64-release -j 8`
5. Re-stage all DLLs to project root
6. Ask user to test the same gameplay segment that previously crashed

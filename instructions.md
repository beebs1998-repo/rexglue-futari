# Project Overview
Recompilation of the Xbox 360 shooter *Mushihimesama Futari* using the `rexglue-sdk`.

# Prerequisites & Environment Configuration
- **Primary SDK Path:** `i:\workspace\futari\rexglue-sdk\`
- **Input Executable:** `game_data/default.xex`
- **Toolchain:** `rexglue` CLI, CMake
- **Reference Documentation:** `i:\workspace\rexglue-sdk.wiki\`, `i:\workspace\360tools\`
- **Example Manifest Overrides:** `360tools/templates/overlay/manifest-overrides.example.toml`
- **Address Reference File:** `ep.txt`

# Step-by-Step Workflow

## 1. Project Initialization
Execute the following command to generate the project structure and manifest file:
```bash
rexglue init --project-name "futari" --game-root game_data --xex-path game_data/default.xex --force
```
**Success Criteria:** `futari_manifest.toml` is created in the project root.  
**Failure Handling:** Verify the integrity of `default.xex`. Check SDK logs for header parsing errors.

## 2. Manifest Configuration & Code Generation
Generate source code from the manifest:
```bash
rexglue codegen futari_manifest.toml
```
**Error Resolution:**
- If compilation or generation fails, edit `futari_manifest.toml`.
- Use `360tools/templates/overlay/manifest-overrides.example.toml` as a reference for valid configuration fields.
- Cross-reference missing addresses in `ep.txt` and add them to the manifest before regenerating.

## 3. Build Execution
Configure and compile the project:
```bash
cmake --preset win-amd64-release
cmake --build --preset win-amd64-release --target futari -j 8
```
**Success Criteria:** Build completes with zero errors. Warnings are acceptable but should be documented.  
**Failure Handling:** Address compiler/linker errors. Verify that all generated symbols match expected XEX exports.

## 4. Runtime Execution & Logging
1. Copy the following binaries to the project root: `futari.exe`, `rexgpu-xenos.dll`, `rexruntime.dll`, `TracyClient.dll`
2. Launch the application:
```bash
futari.exe --game_data_root="game_data" --user_data_root="user_data"
```
**Runtime Behavior:** The executable will continuously write logs to the `logs/` directory. Allow execution to run until log writes stabilize or until manual termination is required. Do not kill the game process, wait until it crashes or exit on its own.

## 5. Log Analysis & Iteration Cycle
1. Navigate to the `logs/` directory and identify the most recently modified log file.
2. Filter entries strictly for `[error]` and `[critical]` tags. Ignore `[warning]` entries unless they directly correlate with a crash or missing functionality.
3. Record unresolved addresses, missing symbols, or runtime exceptions in a tracking document.
4. Return to Step 2 to update `futari_manifest.toml` and regenerate code until critical errors are resolved.

# Critical Paths & References
- **Default SDK:** `i:\workspace\futari\rexglue-sdk\`
- **rexglue wiki:** `i:\workspace\rexglue-sdk.wiki\`
- **Reference Documentation:** `i:\workspace\360tools\docs\`
- **Example Manifest Overrides:** `360tools/templates/overlay/manifest-overrides.example.toml`
- **Address Reference:** `ep.txt`
- **Project method that should be followed:** `i:\workspace\SDOJ-Recomp\`
- **Useful XEX tools:** `i:\workspace\360tools\tools\xex_info.py`

# Module Architecture Notes
- **Primary Executable:** `default.xex`
- **Dynamic Loading:** The game loads additional modules based on in-game menu selections.
- **Character Modules:** 8 character module XEX files (`palm/hirow/kiniro/reco_abnormal/normal.xex`) all share base address `0x88000000`. Only one is loaded at a time (mutually exclusive).
- **Known in-game mapping/layout:** 
  1. 1.5 ver :
     a. Arcade ver -> Game mode (Original, Maniac, Ultra) -> Character selection (Reco, Palm)
     b. 360 ver -> Game mode (Original, Maniac, Ultra) -> Character selection (Reco, Palm)
  2. Arrange :
     a. 360 Arrange ver -> Game mode (Original, Maniac, Ultra) -> Character selection (Reco, Palm)
     b. Novice ver -> Game mode (Original, Maniac, Ultra) -> Character selection (Reco, Palm)
  Info : 
  1.5 - Arcade ver = reco_normal (Player 1 side), kiniro_normal (Player 2 side)
  1.5 - 360 ver = reco_abnormal (Player 1 side), kiniro_abnormal (Player 2 side)
  Arrange - 360 Arrange ver = palm_normal (Player 1 side), hirow_normal (Player 2 side)
  Arrange - Novice ver = palm_abnormal (Player 1 side), hirow_abnormal (Player 2 side)

- According to SDOJ project, we can call/load other module by using [[modules]] in manifest file. Analyze `saidaioujou_recomp_tu1_init.cpp`, `saidaioujou_recomp_tu1_init.h`, `saidaioujou_recomp_tu1_recomp.3.cpp`, `saidaioujou_recomp_tu1_register.cpp`, `saidaioujou_recomp_CA022100_functions.toml` to see how it handles 0x88094460 address.

# Restrictions
1. DO NOT modify this file, `instructions.md`
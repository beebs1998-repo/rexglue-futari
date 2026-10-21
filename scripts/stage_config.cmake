# stage_config.cmake - stage the settings template next to the target
# executable, without ever clobbering a live (user-edited / F4-saved) settings
# file. Used by the futari POST_BUILD command (CMakeLists.txt); launch.bat
# applies the same copy-if-missing rule outside of builds.
#
# Why: the live config is exe_dir/futari.toml (rex_app.cpp SetupEnvironment).
# A missing file is benign for the SDK (defaults are used) but silently drops
# every template pin: keybinds/mnk_mode, the fixed rotating log file, and the
# d3d12_submit_on_primary_buffer_end slowdown pin. Backported from the mushi
# port, which fixed by construction what this project previously left to
# chance (the template never took effect on first launch here). See
# README.md "Settings".
#
# Usage:
#   cmake -DTEMPLATE=<src> -DDIR=<dst dir> -P stage_config.cmake

cmake_minimum_required(VERSION 3.21)

if(NOT DEFINED TEMPLATE OR NOT DEFINED DIR)
    message(FATAL_ERROR "usage: cmake -DTEMPLATE=<src> -DDIR=<dst dir> -P stage_config.cmake")
endif()

get_filename_component(_config_name "${TEMPLATE}" NAME)
if(NOT EXISTS "${DIR}/${_config_name}")
    file(COPY "${TEMPLATE}" DESTINATION "${DIR}")
    message(STATUS "staged ${_config_name} -> ${DIR}")
endif()

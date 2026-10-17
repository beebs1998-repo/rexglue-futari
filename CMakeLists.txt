# futari - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(futari LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use the bundled ReXGlue SDK (git submodule at thirdparty/rexglue-sdk).
# Override with -DREXSDK_DIR=<path> to build against another SDK tree.
set(REXSDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/rexglue-sdk"
    CACHE PATH "Path to the bundled ReXGlue SDK")

include(generated/rexglue.cmake)

# Sources
set(FUTARI_SOURCES
    src/main.cpp
    src/futari_mod_swap_fix.cpp
)

if(WIN32)
    add_executable(futari WIN32 ${FUTARI_SOURCES})
else()
    add_executable(futari ${FUTARI_SOURCES})
endif()

# Recompiled entrypoint is built as an OBJECT library and linked into the host.
# Auto-codegen is intentionally disabled (see generated/rexglue.cmake): the eight
# character modules share guest base 0x88000000, so a single combined codegen run
# is rejected by the overlap check. Code is generated per target and committed.
if(REXGLUE_ENTRYPOINT_GENERATED_SOURCES)
    add_library(futari_recomp OBJECT
        ${REXGLUE_ENTRYPOINT_GENERATED_SOURCES})
    target_include_directories(futari_recomp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${REXGLUE_ENTRYPOINT_INCLUDE_DIR}
    )
    target_link_libraries(futari_recomp PRIVATE rex::runtime)
    rexglue_apply_target_settings(futari_recomp)
    rexglue_apply_recomp_settings(futari_recomp
        "${REXGLUE_ENTRYPOINT_INCLUDE_DIR}/futari_pch.h")
    target_link_libraries(futari PRIVATE
        futari_recomp)
endif()

target_include_directories(futari PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${REXGLUE_ENTRYPOINT_INCLUDE_DIR}
)
target_link_libraries(futari PRIVATE rex::runtime imgui::imgui)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/metadata/icons")
    rexglue_embed_metadata(futari
        DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/metadata/icons"
        PREFIX "icons")
endif()
rexglue_configure_target(futari GPU_PLUGINS xenos)

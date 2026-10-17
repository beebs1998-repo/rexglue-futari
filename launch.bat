@echo off
setlocal
title Futari Recomp

set "ROOT=%~dp0"
set "EXE=%ROOT%out\build\win-amd64-release\futari.exe"

if not exist "%EXE%" (
  echo.
  echo futari.exe was not found at:
  echo   %EXE%
  echo.
  echo Build it first:
  echo   cmake --preset win-amd64-release
  echo   cmake --build --preset win-amd64-release --parallel
  echo.
  pause
  exit /b 1
)

if not exist "%ROOT%game_data\default.xex" (
  echo.
  echo game_data\default.xex was not found.
  echo Put your extracted Mushihimesama Futari data in "%ROOT%game_data\". See README.md.
  echo.
  pause
  exit /b 1
)

start "" /D "%ROOT%" "%EXE%" ^
  --game_data_root="%ROOT%game_data" ^
  --user_data_root="%ROOT%user_data"
exit /b 0

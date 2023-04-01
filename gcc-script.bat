@echo off
cls
set filename=%1
set target=%2
if not exist %filename% (
  echo File not found: %filename%
  exit /b 1
)
if "%target%"=="" (
  set target=%~n1
)
gcc %filename% -o %target%.exe
if not exist %target%.exe (
  echo Compilation failed.
  exit /b 1
)
echo Running %target%.exe...
%target%.exe
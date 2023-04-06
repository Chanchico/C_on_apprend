@echo off
cls
set dirbin=bin
set filename=%1
set targetFile=%2
set target=%dirbin%\%targetFile%
if not exist %filename% (
  echo File not found: %filename%
  exit /b 1
)
if "%target%"=="" (
  set target=%~n1
)
gcc -Wall -Wextra -Werror %filename% -o %target%.exe -I include -L lib -lmingw32 -lSDL2main -lSDL2
if not exist %target%.exe (
  echo Compilation failed.
  exit /b 1
)
echo Running %target%.exe...
%target%.exe
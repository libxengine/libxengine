@echo off
setlocal enabledelayedexpansion

echo Please make sure the 64-bit environment has been entered And the 32-bit and 64-bit directories are inconsistent.
echo Write XEngine x86-32 Library to environment variables (Y/n) [Default: Y]

set /p userInput=Enter Input (Y/n): 

if /i "!userInput!"=="" set userInput=Y

if /i "!userInput!"=="Y" (
    setx XEngine_Lib32 "%cd%\XEngine_Windows"
    echo environment variables was set.
) 

pause

@echo off
echo ============================
echo operator type:
echo   0 set XEngine_LibArm64 to system environment variables(default)
echo   1 copy module to system System32 dir
echo ============================
set /p user_input=input your operator type: 

if "%user_input%"=="" (
    set user_input=0
)
::query 
reg query "HKCU\Environment" /v XEngine_Include >nul 2>&1
if %errorlevel%==0 (
     echo environment variables XEngine_Include is existed,break.
) else (
    echo does not found XEngine_Include in environment variables.setting...
    setx XEngine_Include "%cd%"
)
::operator
if "%user_input%"=="1" (
    echo select 1.copy all dll to System32...
    for /r %%i in (*.dll) do (
        copy "%%i" "%SystemRoot%\System32\"
    )
) else (
    echo select 0
    setx XEngine_LibArm64 "%cd%\XEngine_Windows"
)
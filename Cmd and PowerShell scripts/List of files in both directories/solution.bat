@ECHO OFF
SETLOCAL
if "%1"=="" goto :eof
if "%2"=="" goto :eof

dir /b %2 > temp.txt
for /f %%i in ('dir /b %1 ^| findstr /g:temp.txt') do echo %%i
ENDLOCAL
ECHO ON
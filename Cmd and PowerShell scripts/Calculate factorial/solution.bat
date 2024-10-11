@ECHO OFF
Setlocal EnableDelayedExpansion
SETLOCAL
set /a n=%1
set /a a=0
set /a b=15
if -%n% gtr -%a% goto :Error
if -%n% lss -%b% goto :Error

set /a res=1
for /l %%i in (1,1,%1) do set /a res*=%%i  
echo result is %res%
goto :eof

:Error
echo argument exception
ENDLOCAL
ECHO ON
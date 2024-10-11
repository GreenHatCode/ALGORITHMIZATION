@ECHO OFF
SETLOCAL
for /D %%i in (%1\*.*) do set /A i+=1
echo The total number of subdirectories is %i%
ENDLOCAL
ECHO ON
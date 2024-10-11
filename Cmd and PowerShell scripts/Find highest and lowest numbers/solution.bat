@ECHO OFF 
Setlocal EnableDelayedExpansion
SETLOCAL
SET /A A=%1
SET /A B=%1
:BeginLoop
IF -%1==- GOTO ExitLoop
SHIFT

SET /A T = %1
IF -%A% LSS -%T% (SET /A A=!T!)

IF -%B% GTR -%T% (SET /A B=!T!)

GOTO BeginLoop
:ExitLoop

ECHO min value = %A%
ECHO max value = %B%

ENDLOCAL
ECHO ON
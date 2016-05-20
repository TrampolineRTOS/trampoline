/*
***
*/
- The Trampoline_Kernel directory contains sources files that were originally copied from the os directory of the trampoline project version 1641.

- I have exelude "tpl_os_alarm.c" from the build configurations since WITH_SYSTEM_CALL is set to NO and its existence in the prject generates a 
  preprocessor error.  
 
 - Many others files have been excluded from build configuration and we have kept only needed ones. Including unuseful files generates errors because
   of preprocessor directives testing the integration of only useful files in the project.   
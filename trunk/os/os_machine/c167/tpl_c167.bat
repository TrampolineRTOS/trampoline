
@rem Path to the m4 processor: m4.exe
@set M4PATH=C:\PROGRA~1\GNUWIN32\bin

@rem user application configuration
@set APP_MACRO=App/macro_test_c167


@rem ######## end of configuration.
@path %M4PATH%;%PATH%

@echo generate App/tpl_os_generated_configuration.c and its header file...
m4 -Dheader os/tpl_os_macros.m4 os/os_machine/c167/tpl_c167_macros.m4 %APP_MACRO% > App/tpl_os_generated_configuration.h
m4 os/tpl_os_macros.m4 os/os_machine/c167/tpl_c167_macros.m4 %APP_MACRO% > App/tpl_os_generated_configuration.c
@echo Ok !
@pause
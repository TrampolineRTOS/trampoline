# os directory - kernel and OSEK services

This directory contains kernel functions and OSEK kernel services

* tpl_as_memmap.h: wrapper for memory mapping of assembly source code
* tpl_compiler.h: wrapper for compiler dependant macro and default definition for POSIX
* tpl_config_check.h: macros to check the configuration is ok
* tpl_config_def.h: macros related to the target platform
* tpl_dispatch_table.h: declaration of the dispatch table
* tpl_os_kernel.*: low level kernel functions and scheduler

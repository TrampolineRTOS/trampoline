/*
 * Trampoline OS
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline posix machine dependent stuffs
 *
 */

#ifndef tpl_machine_posix_h
#define tpl_machine_posix_h

#include "tpl_os_internal_types.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
void tpl_osek_func_stub( tpl_proc_id task_id );
void tpl_shutdown(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif

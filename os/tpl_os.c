/**
 * @file tpl_os.c
 *
 * @section Copyright
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 * @section File description
 *
 * Here stands services for :
 * - hardware and application initialization
 * - OS startup
 * - OS shutdown
 */

#include "tpl_os.h"

#ifndef WITH_SYSTEM_CALL

#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * GetActiveApplicationMode return the active application mode
 */
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void)
{
  return tpl_get_active_application_mode_service();
}

/*
 * StartOS can be called by the app to start the OS in
 * an appropriate mode.
 */
FUNC(void, OS_CODE) tpl_start_os(
    CONST(AppModeType, AUTOMATIC) mode)
{
  tpl_start_os_service(mode);
}

/*
 * ShutdownOS can be called by the app to shutdown it
 */
FUNC(void, OS_CODE) ShutdownOS(
    CONST(StatusType, AUTOMATIC) error  /*@unused@*/
)
{
  tpl_shutdown_os_service(error);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_SYSTEM_CALL */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * StartOS can be called by the app to start the OS in
 * an appropriate mode.
 */
FUNC(void, OS_CODE) StartOS(
  CONST(AppModeType, AUTOMATIC) mode)
{
  tpl_init_machine();  
  tpl_start_os(mode);
  /*  tpl_start_os does not return since the idle task will run
      if no other task is AUTOSTART */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os.c */

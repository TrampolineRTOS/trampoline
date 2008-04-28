/**
 * @file tpl_os_it.c
 *
 * @section desc File description
 *
 * This implementation file provides standard OSEK-VDX API
 * for interrupts management.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_error.h"
#include "tpl_os_it.h"
#include "tpl_os_kernel.h"
#include "tpl_os_hooks.h"
#include "tpl_os_definitions.h"
#include "tpl_machine_interface.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * TerminateISR
 *
 * While this function is not part of the OSEK API, it is used
 * to terminate an ISR2 routine
 */
FUNC(StatusType, OS_CODE) TerminateISR2(void)
{
    /*  init the error to no error  */
    VAR(StatusType, AUTOMATIC) result = E_OK;

    /*  lock the task structures    */
    LOCK_WHEN_ISR()

    /*  store information for error hook routine    */
    STORE_SERVICE(OSServiceId_TerminateISR)

    /*  check we are at the ISR2 level  */
    CHECK_ISR2_CALL_LEVEL_ERROR(result)
    /*  check the ISR2 does not own a resource  */
    CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_ISR
    IF_NO_EXTENDED_ERROR(result)

        /*  set the state of the running task to DYING                  */
        tpl_running_obj->state = (tpl_exec_state)DYING;

        /*  and let the scheduler do its job                            */
        tpl_schedule_from_dying();

    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_ERROR(result)

    /*  unlock the task structures  */
    UNLOCK_WHEN_ISR()

    return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_it.h */

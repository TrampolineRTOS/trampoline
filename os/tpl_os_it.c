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
StatusType TerminateISR2(void)
{
    /*  init the error to no error  */
    StatusType result = E_OK;

#ifndef NO_ISR
    tpl_exec_common *exec_obj;
#endif
    
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

        /* Call the post task hook */
        CALL_POST_TASK_HOOK()

        /*  get the running task to terminate it    */
        exec_obj = tpl_running_obj;
        tpl_running_obj = NULL;
        
        /*  dec the activation count    */
        exec_obj->activate_count--;
        
        if (exec_obj->activate_count > 0)
        {
            /*  the task got multiple activations
                so instead of returning it to the SUSPENDED state
                it is inited again and put back in the ready task list  */
            exec_obj->state = READY;
            tpl_init_exec_object(exec_obj);
            tpl_put_exec_object(exec_obj, NEWLY_ACTIVATED_EXEC_OBJ);
        }
        else
        {
            /*  the ISR is SUSPENDED   */
            exec_obj->state = SUSPENDED;
        }

        tpl_schedule(FROM_TASK_LEVEL);
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

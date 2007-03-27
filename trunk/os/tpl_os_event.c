/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Event Management implementation file
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 *
 */

#include "tpl_os.h"
#include "tpl_os_error.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"

#include "tpl_os_event.h"

/*
 * SetEvent
 */

StatusType SetEvent(
    const TaskType      task_id,
    const EventMaskType event)
{
    StatusType result = E_OK;

    LOCK_WHEN_HOOK()

    STORE_SERVICE(OSServiceId_SetEvent)
    STORE_TASK_ID(task_id)
    STORE_EVENT_MASK(event)
    
    CHECK_TASK_ID_ERROR(task_id,result)

    LOCK_WHEN_NO_HOOK()
    
    /*  checks the task is an extended one  */
    CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
    /*  checks the task is not in the SUSPENDED state   */
    CHECK_SUSPENDED_TASK_ERROR(task_id,result)
    
#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
        result = tpl_set_event(tpl_task_table[task_id], event);
        if (result == (tpl_status)E_OK_AND_SCHEDULE)
        {
            tpl_schedule(FROM_TASK_LEVEL);
            result &= OSEK_STATUS_MASK;
        }
    IF_NO_EXTENDED_ERROR_END()
#endif
        
    UNLOCK_WHEN_NO_HOOK()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()
    
    return result;
}


/*
 * ClearEvent
 * see paragraph 13.5.3.2, page 61 of OSEK spec 2.2.2
 */
StatusType ClearEvent(const EventMaskType event)
{
    StatusType result = E_OK;

    LOCK_WHEN_HOOK()

    STORE_SERVICE(OSServiceId_ClearEvent)
    STORE_EVENT_MASK(event)
    
    LOCK_WHEN_NO_HOOK()
    /*  ClearEvent cannot be called from ISR level  */
    CHECK_TASK_CALL_LEVEL_ERROR(result)
    /*  checks the calling task is an extended one  */
    CHECK_NOT_EXTENDED_RUNNING_ERROR(result)

#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
        /*  MISRA RULE 45 VIOLATION: the original pointer points to a struct
            that has the same beginning fields as the struct it is casted to
            This allow object oriented design and polymorphism.
        */
        ((tpl_task *)tpl_running_obj)->evt_set &= (tpl_event_mask)(~event);
    IF_NO_EXTENDED_ERROR_END()
#endif

    UNLOCK_WHEN_NO_HOOK()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()

    return result;
}

/*
 * GetEvent
 * see paragraph 13.5.3.3, page 61 of OSEK spec 2.2.2
 */
StatusType GetEvent(
    const TaskType          task_id,
    const EventMaskRefType  event)
{
    StatusType result = E_OK;

    LOCK_WHEN_HOOK()
    
    STORE_SERVICE(OSServiceId_GetEvent)
    STORE_TASK_ID(task_id)
    STORE_EVENT_MASK_REF(event)
    
    CHECK_TASK_ID_ERROR(task_id,result)

    LOCK_WHEN_NO_HOOK()
    
    /*  checks the task is an extended one  */
    CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
    /*  checks the task is not in the SUSPENDED state   */
    CHECK_SUSPENDED_TASK_ERROR(task_id,result)
    
#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
        *event = tpl_task_table[task_id]->evt_set;
    IF_NO_EXTENDED_ERROR_END()
#endif
    
    UNLOCK_WHEN_NO_HOOK()

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()
    
    return result;
}

/*
 * WaitEvent
 * see $13.5.3.4, page 61-62 of OSEK spec 2.2.2
 */
StatusType WaitEvent(const EventMaskType event)
{
    StatusType result = E_OK;

    LOCK_WHEN_HOOK()

    STORE_SERVICE(OSServiceId_WaitEvent)
    STORE_EVENT_MASK(event)
    
    LOCK_WHEN_NO_HOOK()
    /*  WaitEvent cannot be called from ISR level  */
    CHECK_TASK_CALL_LEVEL_ERROR(result)
    /*  checks the calling task is an extended one  */
    CHECK_NOT_EXTENDED_RUNNING_ERROR(result)
    /*  checks the task does not occupied resource(s)   */
    CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_TASK
    IF_NO_EXTENDED_ERROR(result)
    /*  all the evt_wait is overidden.  */
    
    /*  MISRA RULE 45 VIOLATION: the original pointer points to a struct
        that has the same beginning fields as the struct it is casted to
        This allow object oriented design and polymorphism.
    */
    ((tpl_task *)tpl_running_obj)->evt_wait = event;
    /*  check one of the event to wait is not already set       */

    /*  MISRA RULE 45 VIOLATION: the original pointer points to a struct
        that has the same beginning fields as the struct it is casted to
        This allow object oriented design and polymorphism.
    */
    if ((((tpl_task *)tpl_running_obj)->evt_set & event) == 0)
    {
        /*  no one is set, the task goes in the WAITING state   */
        tpl_running_obj->state = WAITING;
        /*  and a rescheduling occurs                           */
        tpl_schedule(FROM_TASK_LEVEL);
    }
    IF_NO_EXTENDED_ERROR_END()
#endif

    UNLOCK_WHEN_NO_HOOK()

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()
    
    return result;
}

/* End of file tpl_os_event.c */

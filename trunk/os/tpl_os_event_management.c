/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"


#include <stdio.h>
/*
 * Prototypes of external functions
 */
void tpl_put_exec_object(tpl_exec_common *, int);
void tpl_schedule(int);
void tpl_get_task_lock(void);
void tpl_release_task_lock(void);
void tpl_release_internal_resource(tpl_exec_common *);

/*
 * tpl_set_event is called by SetEvent
 * and by tpl_raise_alarm
 * see §13.5.3.1, page 60 of OSEK spec 2.2.2
 */
tpl_status tpl_set_event(tpl_task *task, tpl_event_mask incoming_event)
{
    if (task->exec_desc.state != SUSPENDED) {
        /*  merge the incoming event mask with the old one  */
        task->evt_set = (tpl_event_mask)(task->evt_set | incoming_event);
        /*  cross check the event the task is
            waiting for and the incoming event  */
        if (task->evt_wait & incoming_event) {
            /*  the task was waiting for at least one of the event set
                not sure the wait mask should be clear according to the
                incoming event. did it                                  */
            task->evt_wait &= (tpl_event_mask)(~incoming_event);
            /*  anyway check it is in the WAITING state */
            if (task->exec_desc.state == WAITING) {
                /*  set the state to READY  */
                task->exec_desc.state = READY;
                /*  put the task in the READY list  */
                tpl_put_exec_object(
                    (tpl_exec_common *)task,
                    NEWLY_ACTIVATED_EXEC_OBJ);
                /*  call tpl_schedule   */
                tpl_schedule(FROM_TASK_LEVEL);
            }
        }
        return E_OK;
    }
    else {
        return E_OS_STATE;
    }
}

/*
 * OSEK/VDX services implementation
 */

StatusType SetEvent(TaskType task_id, EventMaskType event)
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
    END_IF_NO_EXTENDED_ERROR()
#endif
        
    UNLOCK_WHEN_NO_HOOK()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()
    
    return result;
}


/*
 * ClearEvent
 * see §13.5.3.2, page 61 of OSEK spec 2.2.2
 */
StatusType ClearEvent(EventMaskType event)
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
        ((tpl_task *)tpl_running_obj)->evt_set &= (tpl_event_mask)(~event);
    END_IF_NO_EXTENDED_ERROR()
#endif

    UNLOCK_WHEN_NO_HOOK()
    
    PROCESS_ERROR(result)
    
    UNLOCK_WHEN_HOOK()

    return result;
}

/*
 * GetEvent
 * see §13.5.3.3, page 61 of OSEK spec 2.2.2
 */
StatusType GetEvent(TaskType task_id, EventMaskRefType event)
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
    END_IF_NO_EXTENDED_ERROR()
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
StatusType WaitEvent(EventMaskType event)
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
    ((tpl_task *)tpl_running_obj)->evt_wait = event;
    /*  check one of the event to wait is not already set       */
    if (!(((tpl_task *)tpl_running_obj)->evt_set & event)) {
        /*  no one is set, the task goes in the WAITING state   */
        tpl_running_obj->state = WAITING;
        /*  and a rescheduling occurs                           */
        tpl_schedule(FROM_TASK_LEVEL);
    }
    END_IF_NO_EXTENDED_ERROR()
#endif

    UNLOCK_WHEN_NO_HOOK()

    PROCESS_ERROR(result)

    UNLOCK_WHEN_HOOK()
    
    return result;
}

/**
 * @file tpl_trace.c
 *
 * @section desc File description
 *
 * Trampoline Trace Calls
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Copyright IRISA - JF Deverge for libpcl port
 * Copyright Geensys for hcs12 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 */

#include "tpl_app_define.h" /* WITH_TRACE */

#if WITH_TRACE == YES
#include <stdio.h>

#include "tpl_trace.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
* trace the execution of a task or ISR
* This function should be implemented in the machine dependant trace backend.
*
*/
FUNC(void, OS_CODE) tpl_trace_proc_change_state(
    CONST(tpl_proc_id,AUTOMATIC) proc_id,
    CONST(tpl_proc_state,AUTOMATIC) target_state)
{
	printf("proc %d change to state %d\n",proc_id,target_state);
}

/**
* trace the lock of a resource by an entity
* @param res_id       identifier of the locked resource
* @param target_state identifier of the locked resource
*/
FUNC(void, OS_CODE) tpl_trace_res_change_state(
    CONST(tpl_resource_id, AUTOMATIC)   res_id,
    CONST(tpl_trace_resource_state,AUTOMATIC) target_state)
{
	printf("res %d change to state %d\n",res_id,target_state);
}

/**
* trace the state of a time object (alarm/schedule tables)
* @param sheduled_alarm    data structure concerning the sheduled alarm
*/
FUNC(void, OS_CODE) tpl_trace_time_obj_change_state(
    CONST(tpl_timeobj_id, AUTOMATIC) timeobj_id,
    CONST(tpl_time_obj_state, AUTOMATIC) target_state)
{
	printf("time obj %d change to state %d\n",timeobj_id ,target_state);
}

/**
* trace the expiration of an alarm
*
* @param expired_alarm    data structure concerning the expired alarm
*/
FUNC(void, OS_CODE) tpl_trace_time_obj_expire(
    CONST(tpl_timeobj_id,AUTOMATIC) timeobj_id)
{
	printf("time obj %d expired!\n",timeobj_id);
}

/**
* trace the events:
* - when an event mask is set to a task (source task is the current running task)
* - when an event mask is reset 
*
*/
FUNC(void, OS_CODE) tpl_trace_event_set(
    CONST(tpl_task_id, AUTOMATIC)       task_target_id,
    CONST(tpl_event_mask, AUTOMATIC)    event)
{
	printf("event set on proc %d, event mask 0x%x\n",task_target_id,event);
}

FUNC(void, OS_CODE) tpl_trace_event_reset(
    CONST(tpl_event_mask, AUTOMATIC)    event)
{
	printf("mask event reset 0x%x\n",event);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_TRACE == YES  */

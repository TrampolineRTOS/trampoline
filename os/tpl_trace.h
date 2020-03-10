
/**
* @file tpl_os_task_kernel.h
*
* @section desc File description
*
* Functions for trace production
*
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
* @section infos File informations
*
* $Date: 2009-04-24 10:10:29 +0000 (ven. 24 avril 2009) $
* $Rev: 735$
* $Author: ljunker$
* $URL: http://trampoline.rts-software.org/svn/trunk/os/tpl_trace.h $
*/
#ifndef TPL_TRACE_H
#define TPL_TRACE_H

#include "tpl_os_types.h"
#include "tpl_os_kernel.h"
#include "tpl_os_timeobj_kernel.h"

#if WITH_TRACE == YES
#include "tpl_target_trace.h"
#endif

/**
* @def IDs of the different traces
*/

#define TASK_RUN 0
#define TASK_PREEMPT 1
#define TASK_TERMINATE 2
#define TASK_ACTIVATE 3
#define TASK_WAIT 4
#define TASK_RELEASED 5
#define TASK_CHANGE_PRIORITY 6
#define RES_GET 7
#define RES_RELEASED 8
#define ISR_RUN 9
#define ISR_PREEMPT 10
#define ISR_TERMINATE 11
#define ISR_ACTIVATE 12
#define ISR_CHANGE_PRIORITY 13
#define ALARM_SCHEDULED 14
#define ALARM_EXPIRE 15
#define ALARM_CANCEL 16
#define USER_EVENT 17
#define TPL_INIT 18
#define TPL_TERMINATE 19
#define COUNTER_INC 20

/* define the alarm actions */

#define TRACE_CALLBACK 0
#define TRACE_ACT_TASK 1
#define TRACE_SET_EVENT 2

/* define the trace output types */

#if WITH_TRACE == YES

/**
*  functions tracing the tasks sheduling
*/
#	if TRACE_TASK == YES

/**
* @def TRACE_TASK_EXECUTE
*/
#		define TRACE_TASK_EXECUTE(new_executed_task_id) \
		tpl_trace_task_execute(new_executed_task_id);

/**
* @def TRACE_TASK_PREEMPT
*/
#		define TRACE_TASK_PREEMPT(preempted_task_id)\
		tpl_trace_task_preempt(preempted_task_id);

/**
* @def TRACE_TASK_TERMINATE
*/
#		define TRACE_TASK_TERMINATE(dying_task_id)\
		tpl_trace_task_terminate(dying_task_id);

/**
* @def TRACE_TASK_ACTIVATE
*/
#		define TRACE_TASK_ACTIVATE(task_id)\
		tpl_trace_task_activate(task_id);
/**
* @def TRACE_TASK_WAIT
*/
#		define TRACE_TASK_WAIT(waiting_task_id)\
		tpl_trace_task_wait(waiting_task_id);

/**
* @def TRACE_TASK_RELEASED
*/
#		define TRACE_TASK_RELEASED(released_task_id, event_id)\
		tpl_trace_task_released(released_task_id, event_id);

/**
* @def TRACE_TASK_CHANGE_PRIORITY
*/
#		define TRACE_TASK_CHANGE_PRIORITY(priority_changing_task_id)\
		tpl_trace_task_change_priority(priority_changing_task_id);


#	else
#		define TRACE_TASK_EXECUTE(new_executed_task_id)
#		define TRACE_TASK_PREEMPT(prempted_task_id)
#		define TRACE_TASK_TERMINATE(dying_task_id)
#		define TRACE_TASK_ACTIVATE(task_id)
#		define TRACE_TASK_WAIT(waiting_task_id)
#		define TRACE_TASK_RELEASED(released_task_id,event_id)
#		define TRACE_TASK_CHANGE_PRIORITY(priority_changing_task_id)
#	endif

/**
*  functions tracing the resources use
*/
#	if TRACE_RES == YES

/**
* @def TRACE_RES_GET
*/
#		define TRACE_RES_GET(res_id, locking_entity_id)\
		tpl_trace_res_get(res_id, locking_entity_id);

/**
* @def TRACE_RES_RELEASE
*/
#		define TRACE_RES_RELEASED(res_id)\
		tpl_trace_res_released(res_id);

#	else
#		define TRACE_RES_GET(res_id, locking_entity_id)
#		define TRACE_RES_RELEASED(res_id);
#	endif

/**
*  functions tracing the ISRs sheduling
*/
 #	if TRACE_ISR == YES

/**
* @def TRACE_ISR_RUN
*/
#		define TRACE_ISR_RUN(running_isr_id)\
		tpl_trace_isr_run(running_isr_id);

/**
* @def TRACE_ISR_PREEMPT
*/
#		define TRACE_ISR_PREEMPT(prempted_isr_id)\
		tpl_trace_isr_preempt(prempted_isr_id);

/**
* @def TRACE_ISR_TERMINATE
*/
#		define TRACE_ISR_TERMINATE(dying_isr_id)\
		tpl_trace_isr_terminate(dying_isr_id);

/**
* @def TRACE_ISR_ACTIVATE
*/
#		define TRACE_ISR_ACTIVATE(isr_id)\
		tpl_trace_isr_activate(isr_id);

/**
* @def TRACE_ISR_CHANGE_PRIORITY
*/
#		define TRACE_ISR_CHANGE_PRIORITY(priority_changing_isr_id)\
		tpl_trace_isr_change_priority(priority_changing_isr_id);

 #	else
#		define TRACE_ISR_RUN(running_isr_id)
#		define TRACE_ISR_PREEMPT(prempted_isr_id)
#		define TRACE_ISR_TERMINATE(dying_isr_id)
#		define TRACE_ISR_ACTIVATE(isr_id)
#		define TRACE_ISR_CHANGE_PRIORITY(priority_changing_isr_id)


#	endif

/**
*  functions tracing the alarms sheduling
*/
#	if TRACE_ALARM == YES

/**
* @def TRACE_ALARM_SCHEDULED
*/
#		define TRACE_ALARM_SCHEDULED(scheduled_alarm)\
		tpl_trace_alarm_scheduled(scheduled_alarm);

/**
* @def TRACE_ALARM_EXPIRE
*/
#		define TRACE_ALARM_EXPIRE(expired_alarm)\
		tpl_trace_alarm_expire(expired_alarm);

/**
* @def TRACE_ALARM_CANCEL
*/
#		define TRACE_ALARM_CANCEL(cancelled_alarm_id)\
		tpl_trace_alarm_cancel(cancelled_alarm_id);

#	  if (ALARM_COUNT > 0)
/**
 * @def TRACE_COUNTER
 */
#       define TRACE_COUNTER(counter_desc)\
        tpl_trace_counter(counter_desc);
#	  else
#       define TRACE_COUNTER(counter_desc)
#	  endif

#	else
#		define TRACE_ALARM_SCHEDULED(scheduled_alarm)
#		define TRACE_ALARM_EXPIRE(expired_alarm)
#		define TRACE_ALARM_CANCEL(cancelled_alarm_id)
#       define TRACE_COUNTER(counter_desc)
#	endif

/**
*  function tracing other events
*/
#	if TRACE_U_EVENT == YES

/**
* @def TRACE_USER_EVENT
*/
#		define TRACE_USER_EVENT(event_id)\
		tpl_trace_user_event(event_id);
#	else
#		define TRACE_USER_EVENT(event_id)
#	endif

/**
* @def TRACE_TPL_INIT
*/
#	define TRACE_TPL_INIT()\
	tpl_trace_tpl_init();

/**
* @def TRACE_TPL_TERMINATE
*/
#	define TRACE_TPL_TERMINATE()\
	tpl_trace_tpl_terminate();

#else
#	define TRACE_TPL_INIT()
#	define TRACE_TPL_TERMINATE()
#	define TRACE_TASK_EXECUTE(new_executed_task_id)
#	define TRACE_TASK_PREEMPT(prempted_task_id)
#	define TRACE_TASK_TERMINATE(dying_task_id)
#	define TRACE_TASK_ACTIVATE(task_id)
#	define TRACE_TASK_WAIT(waiting_task_id)
#	define TRACE_TASK_RELEASED(released_task_id,event_id)
#	define TRACE_TASK_CHANGE_PRIORITY(priority_changing_task_id)
#	define TRACE_ISR_RUN(running_isr_id)
#	define TRACE_ISR_PREEMPT(prempted_isr_id)
#	define TRACE_ISR_TERMINATE(dying_isr_id)
#	define TRACE_ISR_ACTIVATE(isr_id)
#	define TRACE_ISR_CHANGE_PRIORITY(priority_changing_isr_id)
#	define TRACE_RES_GET(res_id, locking_entity_id)
#	define TRACE_RES_RELEASED(res_id)
#	define TRACE_ALARM_SCHEDULED(scheduled_alarm)
#	define TRACE_ALARM_EXPIRE(expired_alarm)
#	define TRACE_ALARM_CANCEL(cancelled_alarm_id)
#   define TRACE_COUNTER(counter_desc)
#	define TRACE_U_EVENT(event_id)
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
* trace the execution of a task
*
* @param new_executed_task_id	identifier of the task to be traced
*
*/

FUNC(void, OS_CODE) tpl_trace_task_execute(
  CONST(TaskType, AUTOMATIC) new_executed_task_id);

/**
* trace the preemption of a task
*
* @param prempted_task_id	id of the preempted task
*/

FUNC(void, OS_CODE) tpl_trace_task_preempt(
  CONST(TaskType, AUTOMATIC) prempted_task_id);

/**
* trace the termination of a task
*
* @param dying_task_id	identifier of the task which terminates
*
*/

FUNC(void, OS_CODE) tpl_trace_task_terminate(
  CONST(TaskType, AUTOMATIC) dying_task_id);

/**
* trace the activation of a task
*
* @param task_id		identifier ot the task which is activated
*/

FUNC(void, OS_CODE) tpl_trace_task_activate(
  CONST(TaskType, AUTOMATIC) task_id);

/**
* trace the switch to wait state of a task
*
* @param waiting_task_id 	identifier of the task which switch to wait state
*/

FUNC(void, OS_CODE) tpl_trace_task_wait(
  CONST(TaskType, AUTOMATIC) waiting_task_id);

/**
* trace the release of a waiting task
*
* @param released_task_id	 identifier of the released task
*
* @param event_id identifier of the event recieved
*/

FUNC(void, OS_CODE) tpl_trace_task_released(
  CONST(TaskType, AUTOMATIC) released_task_id,
  CONST(tpl_event_mask, AUTOMATIC) event_id);

/**
* trace the priority change of a task
*
* @param changing_priority_task_id	 identifier of the task whose priority change
*/

FUNC(void, OS_CODE) tpl_trace_task_change_priority(
  CONST(TaskType, AUTOMATIC) priority_changing_task_id);

/**
* trace the lock of a resource by an entity
*
* @param res_id 		identifier of the locked resource
*
* @param locking_entity_id		identifier of the locking entity
*/

FUNC(void, OS_CODE) tpl_trace_res_get(
  CONST(tpl_resource_id, AUTOMATIC) res_id, CONST(TaskType, AUTOMATIC) task_id);

/**
* trace the release of a resource
*
* @param res_id		identifier of the resource
*/

FUNC(void, OS_CODE) tpl_trace_res_released(
  CONST(tpl_resource_id, AUTOMATIC) res_id);

/**
* trace the execution of an ISR
*
* @param running_isr_id	identifier of the ISR executed
*/

FUNC(void, OS_CODE) tpl_trace_isr_run(
  CONST(tpl_isr_id, AUTOMATIC) running_isr_id);

/**
* trace the preemption of an ISR
*
* @param prempted_isr_id	id of the preempted ISR
*/

FUNC(void, OS_CODE) tpl_trace_isr_preempt(
  CONST(tpl_isr_id, OS_VAR) prempted_isr_id);

/**
* trace the termination of an ISR
*
* @param dying_isr_id		identifier of the ISR terminated
*/

FUNC(void, OS_CODE) tpl_trace_isr_terminate(
  CONST(tpl_isr_id, AUTOMATIC) dying_isr_id);

/**
* trace the activation of an ISR
*
* @param isr_id		identifier of the activated ISR
*/

FUNC(void, OS_CODE) tpl_trace_isr_activate(
  CONST(tpl_isr_id, AUTOMATIC) isr_id);

/**
* trace the change of priority of an ISR
*
* @param priority_changing_isr_id	identifier of the isr whose priority changes
*/

FUNC(void, OS_CODE) tpl_trace_isr_change_priority(
  CONST(tpl_isr_id, AUTOMATIC) priority_changing_isr_id);

/**
* trace the programmation of an alarm
*
* @param sheduled_alarm		data structure concerning the sheduled alarm
*/

FUNC(void, OS_CODE) tpl_trace_alarm_scheduled(
  CONSTP2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)scheduled_alarm);

/**
* trace the expiration of an alarm
*
* @param expired_alarm		data structure concerning the expired alarm
*/

FUNC(void, OS_CODE) tpl_trace_alarm_expire(
  CONSTP2VAR(tpl_time_obj,AUTOMATIC,OS_APPL_DATA) expired_alarm);

/**
* trace the cancellation of an alarm
*
* @param cancelled_alarm 	data structure concerning the cancelled alarm
*/

FUNC(void, OS_CODE) tpl_trace_alarm_cancel(
  CONST(tpl_alarm_id, AUTOMATIC) cancelled_alarm_id);

FUNC(void, OS_CODE) tpl_trace_counter(
  CONSTP2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter_desc);

/**
* trace an user's event
*
* @param event_id	id of the event to trace
*
* FUNC(void, OS_CODE) trace_user_event(
*  CONST(tpl_user_event, AUTOMATIC) event_id);
*/

/**
* trace the initialization of Trampoline
*/

FUNC(void, OS_CODE) tpl_trace_tpl_init();

/**
* trace the termination of Trampoline
*/

FUNC(void, OS_CODE) tpl_trace_tpl_terminate();

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_TRACE_H */
/* End of file tpl_trace.h */


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
*/
#ifndef TPL_TRACE_H
#define TPL_TRACE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tpl_app_define.h" /* WITH_TRACE */
#include "tpl_os_types.h"
#include "tpl_os_kernel.h"
#include "tpl_os_timeobj_kernel.h"


#define RESOURCE_FREE  0
#define RESOURCE_TAKEN 1
typedef uint8 tpl_trace_resource_state;



/**
* @def IDs of the different traces
* value used in the binary export implementation. do not modify.
*/

/* special case sent by target when there is no more place*/
#define OVERFLOW     0
#define PROC_TYPE    1
#define RES_TYPE     2
#define EVENT_TYPE   3
#define TIMEOBJ_TYPE 4 // ALARM_SLEEP, ALARM_ACTIVE, ALARM EXPIRE
#define MESSAGE_TYPE 5 // SEND_ZERO_MESSAGE, SEND or RECEIVE
#define IOC_TYPE     6

/* sub types */
#define SEND_NONZERO_MESSAGE_KIND 0
#define SEND_ZERO_MESSAGE_KIND    1
#define MESSAGE_RECEIVE_KIND      2

#define TIMEOBJ_CHANGE_STATE_KIND 0
#define TIMEOBJ_EXPIRE_KIND       1

#define EVENT_SET_KIND            0
#define EVENT_RESET_KIND          1

/* define the trace output types */
#if WITH_TRACE == YES
     /**
      * Trace ends (close the file for instance). This event is sent by
	  * ShutdownOS() system call
      * This function should be implemented in the machine dependant trace backend.
      */
#  define TRACE_CLOSE()\
       tpl_trace_close();

   /**
   *  function tracing the tasks or ISR sheduling
   */
#  if TRACE_PROC == YES
     /**
     * Trace that a proc (isr or task) changes its internal state 
     * (RUNNING, WAITING, ..). See tpl_os_definitions.h and tpl_os_kernel.h
     * This function should be implemented in the machine dependant trace backend.
     */
#    define TRACE_PROC_CHANGE_STATE(proc_id, target_state) \
       tpl_trace_proc_change_state(proc_id, target_state);
#  else
#    define TRACE_PROC_CHANGE_STATE(proc_id, target_state) 
#  endif

   /**
   *  function tracing the resources use
   */
#  if TRACE_RES == YES
     /**
     * Trace the resources. The target state is the new state of the resource.
     */
#    define TRACE_RES_CHANGE_STATE(res_id, target_state)\
       tpl_trace_res_change_state(res_id, target_state);
#  else
#    define TRACE_RES_CHANGE_STATE(res_id, target_state)
#  endif

#  if TRACE_EVENT == YES
     /**
     * Trace the events
     */
#    define TRACE_EVENT_SET(task_target_id, event)\
       tpl_trace_event_set(task_target_id, event);
#    define TRACE_EVENT_RESET(event)\
       tpl_trace_event_reset(event);
#  else
#    define TRACE_EVENT_SET(task_target_id, event)
#    define TRACE_EVENT_RESET(event)
#  endif

   /**
   *  functions tracing the time objects sheduling (alarms and schedule tables)
   */
#  if TRACE_ALARM == YES
     /**
      * Trace that a time object (alarm or schedule table) changes its internal state 
      * (ALARM_SLEEP, ALARM_ACTIVE or ALARM_AUTOSTART). See tpl_os_timeobj_kernel.h
      * This function should be implemented in the machine dependant trace backend.
      */
#    define TRACE_TIMEOBJ_CHANGE_STATE(timeobj_id,target_state)\
       tpl_trace_time_obj_change_state(timeobj_id,target_state);
     /**
      * Trace that a time object (alarm or schedule table) expires
      * and performs its action.
      * This function should be implemented in the machine dependant trace backend.
      */
#    define TRACE_TIMEOBJ_EXPIRE(timeobj_id)\
       tpl_trace_time_obj_expire(timeobj_id);
#  else
#    define TRACE_TIMEOBJ_CHANGE_STATE(timeobj_id,target_state)
#    define TRACE_TIMEOBJ_EXPIRE(timeobj_id)
#  endif

   /**
   *  functions tracing the ioc
   */
#  if TRACE_IOC == YES
     /**
     * Trace the ioc
     */
#    define TRACE_IOC_SEND(ioc_id)\
       tpl_trace_ioc_send(ioc_id);
#    define TRACE_IOC_RECEIVE(ioc_id)\
       tpl_trace_ioc_receive(ioc_id);
#  else
#    define TRACE_IOC_SEND(ioc_id)
#    define TRACE_IOC_RECEIVE(ioc_id)
#  endif

   /**
   *  functions tracing the message
   */
#  if TRACE_MESSAGE == YES
     /**
     * Trace the message
     */
#    define TRACE_MSG_SEND(mess_id,is_zero_message)\
       tpl_trace_msg_send(mess_id,is_zero_message);
#    define TRACE_MSG_RECEIVE(mess_id)\
       tpl_trace_msg_receive(mess_id);
#  else
#    define TRACE_MSG_SEND(mess_id,is_zero_message)
#    define TRACE_MSG_RECEIVE(mess_id)
#  endif


#else /* no trace at all */
#    define TRACE_CLOSE()
#    define TRACE_PROC_CHANGE_STATE(proc_id, target_state) 
#    define TRACE_RES_CHANGE_STATE(res_id,target_state)
#    define TRACE_TIMEOBJ_CHANGE_STATE(timeobj_id,target_state)
#    define TRACE_TIMEOBJ_EXPIRE(timeobj_id)
#    define TRACE_EVENT_SET(task_target_id, event)
#    define TRACE_EVENT_RESET(event)
#    define TRACE_IOC_SEND(ioc_id)
#    define TRACE_IOC_RECEIVE(ioc_id)
#    define TRACE_MSG_SEND(ioc_id,is_zero_message)
#    define TRACE_MSG_RECEIVE(ioc_id)
#endif

#if WITH_TRACE == YES

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
* trace ends
* This function should be implemented in the machine dependant trace backend.
*
*/
FUNC(void, OS_CODE) tpl_trace_close();

/**
* trace the execution of a task or ISR
* This function should be implemented in the machine dependant trace backend.
*
*/
FUNC(void, OS_CODE) tpl_trace_proc_change_state(
    CONST(tpl_proc_id,AUTOMATIC) proc_id,
    CONST(tpl_proc_state,AUTOMATIC) target_state);

/**
* trace the lock of a resource by an entity
* @param res_id       identifier of the locked resource
* @param target_state identifier of the locked resource
*/
FUNC(void, OS_CODE) tpl_trace_res_change_state(
    CONST(tpl_resource_id, AUTOMATIC)   res_id,
    CONST(tpl_trace_resource_state,AUTOMATIC) target_state);

/**
* trace the state of a time object (alarm/schedule tables)
* @param sheduled_alarm    data structure concerning the sheduled alarm
*/
FUNC(void, OS_CODE) tpl_trace_time_obj_change_state(
    CONST(tpl_timeobj_id, AUTOMATIC) timeobj_id,
    CONST(tpl_time_obj_state, AUTOMATIC) target_state);

/**
* trace the expiration of an alarm
*
* @param expired_alarm    data structure concerning the expired alarm
*/
FUNC(void, OS_CODE) tpl_trace_time_obj_expire(
    CONST(tpl_timeobj_id,AUTOMATIC) timeobj_id);

/**
* trace the events:
* - when an event mask is set to a task (source task is the current running task)
* - when an event mask is reset 
*
*/
FUNC(void, OS_CODE) tpl_trace_event_set(
    CONST(tpl_task_id, AUTOMATIC)       task_target_id,
    CONST(tpl_event_mask, AUTOMATIC)    event);

FUNC(void, OS_CODE) tpl_trace_event_reset(
    CONST(tpl_event_mask, AUTOMATIC)    event);
       

/**
* trace the ioc:
* - when an ioc message is sent
* - when an ioc message is received 
*
*/
# if (WITH_IOC == YES)
FUNC(void, OS_CODE) tpl_trace_ioc_send(
    VAR(tpl_ioc_id, AUTOMATIC) ioc_id);

FUNC(void, OS_CODE) tpl_trace_ioc_receive(
    VAR(tpl_ioc_id, AUTOMATIC) ioc_id);

# endif /* WITH_IOC == YES */

#if WITH_COM == YES
# include "tpl_com_internal.h"

/**
* trace the message:
* - when a message is sent
* - when a message is received 
*
*/

FUNC(void, OS_CODE) tpl_trace_msg_send(
    CONST(tpl_message_id, AUTOMATIC)   mess_id,
    CONST(tpl_bool,AUTOMATIC)          is_zero_message);

FUNC(void, OS_CODE) tpl_trace_msg_receive(
    VAR(tpl_message_id, AUTOMATIC) mess_id);
#endif  /* WITH_COM == YES */
                

# define OS_STOP_SEC_CODE
# include "tpl_memmap.h"

#endif /* WITH_TRACE == YES */

#ifdef __cplusplus
}
#endif

#endif /* TPL_TRACE_H */
/* End of file tpl_trace.h */

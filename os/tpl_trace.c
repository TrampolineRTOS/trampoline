/**
 * @file tpl_trace.c
 *
 * @section desc File description
 *
 * Trampoline Trace Calls
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
 * $Date: 2009-04-24 10:26:01 +0000 (ven. 24 avril 2009) $
 * $Rev: 735 $
 * $Author: ljunker $
 * $URL: http://trampoline.rts-software.org/svn/trunk/os/tpl_trace.c $
 */

#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_types.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_timeobj_kernel.h"
#include "tpl_trace.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
* TASKS FUNCTIONS
*/

FUNC(void, OS_CODE) tpl_trace_task_execute(
  CONST(TaskType, AUTOMATIC) new_executed_task_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_status, AUTOMATIC) new_executed_task_old_status;
  VAR(tpl_priority, AUTOMATIC) new_executed_task_prio;

  if(TPL_KERN_REF(kern).s_running->type != 0x2)
    {
/* This function is called just before the scheduling process,
    so we can get the status of the task before it changes.*/

    tpl_trace_get_date();
    new_executed_task_old_status = tpl_dyn_proc_table[new_executed_task_id]->state;
    new_executed_task_prio = tpl_dyn_proc_table[new_executed_task_id]->priority;

/* record part*/

    EVENT_BEGIN(TASK_RUN)
    EVENT_VALUE(new_executed_task_id)
    EVENT_VALUE(new_executed_task_prio)
    EVENT_VALUE(new_executed_task_old_status)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_task_preempt(
  CONST(TaskType, OS_VAR) preempted_task_id)
{
  VAR(tpl_priority, AUTOMATIC) preempted_task_prio;

  if (tpl_stat_proc_table[preempted_task_id]->type != IS_ROUTINE)
  {
    /*
     * we retrieve the preempted task's data by requesting
     * from the currently running task, the scheduling process having
     * not already been applied
     */
    tpl_trace_get_date();
    preempted_task_prio = tpl_dyn_proc_table[preempted_task_id]->priority;

    EVENT_BEGIN(TASK_PREEMPT)
    EVENT_VALUE(preempted_task_id)
    EVENT_VALUE(preempted_task_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_task_terminate(
  CONST(TaskType, AUTOMATIC) dying_task_id)
{
  VAR(tpl_priority, AUTOMATIC) dying_task_prio;

  if (tpl_stat_proc_table[dying_task_id]->type != IS_ROUTINE)
  {

    tpl_trace_get_date();
    dying_task_prio = tpl_dyn_proc_table[dying_task_id]->priority;

    EVENT_BEGIN(TASK_TERMINATE)
    EVENT_VALUE(dying_task_id)
    EVENT_VALUE(dying_task_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_task_activate(
  CONST(TaskType, AUTOMATIC) task_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_status, AUTOMATIC) task_old_status;
  VAR(tpl_priority, AUTOMATIC) task_prio;

  if(TPL_KERN_REF(kern).s_running->type != 0x2)
  {
    tpl_trace_get_date();

    task_old_status = tpl_dyn_proc_table[task_id]->state;
    task_prio = tpl_dyn_proc_table[task_id]->priority;

    EVENT_BEGIN(TASK_ACTIVATE)
    EVENT_VALUE(task_id)
    EVENT_VALUE(task_prio)
    EVENT_VALUE(task_old_status)
    EVENT_END()
    FORMAT_TRACE()
  }
}


FUNC(void, OS_CODE) tpl_trace_task_wait(
  CONST(TaskType, AUTOMATIC) waiting_task_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_status, AUTOMATIC) waiting_task_status;
  VAR(tpl_priority, AUTOMATIC) waiting_task_prio;

  if(TPL_KERN_REF(kern).s_running->type != 0x2)
  {
    tpl_trace_get_date();

    waiting_task_status = tpl_dyn_proc_table[waiting_task_id]->state;
    waiting_task_prio = tpl_dyn_proc_table[waiting_task_id]->priority;

    EVENT_BEGIN(TASK_WAIT)
    EVENT_VALUE(waiting_task_id)
    EVENT_VALUE(waiting_task_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_task_released(
  CONST(TaskType, AUTOMATIC) released_task_id, CONST(tpl_event_mask, AUTOMATIC)
event_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_status, AUTOMATIC) released_task_status;
  VAR(tpl_priority, AUTOMATIC) released_task_prio;

  if(TPL_KERN_REF(kern).s_running->type != 0x2)
  {
    tpl_trace_get_date();

    released_task_status = tpl_dyn_proc_table[released_task_id]->state;
    released_task_prio = tpl_dyn_proc_table[released_task_id]->priority;

    EVENT_BEGIN(TASK_RELEASED)
    EVENT_VALUE(released_task_id)
    EVENT_VALUE(released_task_status)
    EVENT_VALUE(released_task_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_task_change_priority(
  CONST(TaskType, AUTOMATIC) priority_changing_task_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_priority, AUTOMATIC) priority_changing_task_new_prio;

  if(TPL_KERN_REF(kern).s_running->type != 0x2)
  {
    tpl_trace_get_date();
    priority_changing_task_new_prio = tpl_dyn_proc_table[TPL_KERN_REF(kern).running_id]->priority;

    EVENT_BEGIN(TASK_CHANGE_PRIORITY)
    EVENT_VALUE(priority_changing_task_id)
    EVENT_VALUE(priority_changing_task_new_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

/**
* RESOURCE FUNCTIONS
*/

FUNC(void, OS_CODE) tpl_trace_res_get(
  CONST(tpl_resource_id, AUTOMATIC) res_id, CONST(TaskType, AUTOMATIC) locking_entity_id)
{
  VAR(tpl_priority, AUTOMATIC) locking_entity_prio;
  tpl_trace_get_date();

  locking_entity_prio = tpl_dyn_proc_table[locking_entity_id]->priority;

  EVENT_BEGIN(RES_GET)
  EVENT_VALUE(res_id)
  EVENT_VALUE(locking_entity_id)
  EVENT_VALUE(locking_entity_prio)
  EVENT_END()
    FORMAT_TRACE()
}

FUNC(void, OS_CODE) tpl_trace_res_released(
  CONST(tpl_resource_id, AUTOMATIC) res_id)
{
  tpl_trace_get_date();

  EVENT_BEGIN(RES_RELEASED)
  EVENT_VALUE(res_id)
  EVENT_END()
  FORMAT_TRACE()
}

/**
* ISR FUNCTIONS
*/

FUNC(void, OS_CODE) tpl_trace_isr_run(
  CONST(tpl_isr_id, AUTOMATIC) running_isr_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_priority, AUTOMATIC) running_isr_prio;

  if (TPL_KERN_REF(kern).s_running->type == 0x2)
  {
    tpl_trace_get_date();
    running_isr_prio = tpl_dyn_proc_table[running_isr_id]->priority;

    EVENT_BEGIN(ISR_RUN)
    EVENT_VALUE(running_isr_id)
    EVENT_VALUE(running_isr_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}


FUNC(void, OS_CODE) tpl_trace_isr_preempt(
  CONST(tpl_isr_id, OS_VAR) preempted_isr_id)
{
  VAR(tpl_priority, AUTOMATIC) preempted_isr_prio;

  if (tpl_stat_proc_table[preempted_isr_id]->type == IS_ROUTINE)
  {
    tpl_trace_get_date();
    preempted_isr_prio = tpl_dyn_proc_table[preempted_isr_id]->priority;

    EVENT_BEGIN(ISR_PREEMPT)
    EVENT_VALUE(preempted_isr_id)
    EVENT_VALUE(preempted_isr_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_isr_terminate(
  CONST(tpl_isr_id, AUTOMATIC) dying_isr_id)
{
  VAR(tpl_priority, AUTOMATIC) dying_isr_prio;

  if (tpl_stat_proc_table[dying_isr_id]->type == IS_ROUTINE)
  {
    dying_isr_prio = tpl_dyn_proc_table[dying_isr_id]->priority;
    tpl_trace_get_date();

    EVENT_BEGIN(ISR_TERMINATE)
    EVENT_VALUE(dying_isr_id)
    EVENT_VALUE(dying_isr_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_isr_activate(
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
  VAR(tpl_status, AUTOMATIC) isr_old_status;
  VAR(tpl_priority, AUTOMATIC) isr_prio;

  if (tpl_stat_proc_table[isr_id]->type == 0x2)
  {
    tpl_trace_get_date();
    isr_old_status = tpl_dyn_proc_table[isr_id]->state;
    isr_prio = tpl_dyn_proc_table[isr_id]->priority;

    EVENT_BEGIN(ISR_ACTIVATE)
    EVENT_VALUE(isr_id)
    EVENT_VALUE(isr_prio)
    EVENT_VALUE(isr_old_status)
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_isr_change_priority(
  CONST(tpl_isr_id, AUTOMATIC) priority_changing_isr_id)
{
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)
  VAR(tpl_priority, AUTOMATIC) priority_changing_isr_new_prio;

  if(TPL_KERN_REF(kern).s_running->type == 0x2)
  {

    tpl_trace_get_date();
    priority_changing_isr_new_prio = tpl_dyn_proc_table[TPL_KERN_REF(kern).running_id]->priority;

    EVENT_BEGIN(TASK_CHANGE_PRIORITY)
    EVENT_VALUE(priority_changing_isr_id)
    EVENT_VALUE(priority_changing_isr_new_prio)
    EVENT_END()
    FORMAT_TRACE()
  }
}

#if (WITH_TRACE == YES)
FUNC(void, OS_CODE) tpl_trace_alarm_scheduled(
  CONSTP2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) scheduled_alarm)
{

  VAR(tpl_tick, AUTOMATIC) scheduled_alarm_expir_date;
  VAR(tpl_timeobj_id, TYPEDEF) scheduled_alarm_id;

  tpl_trace_get_date();
  scheduled_alarm_expir_date = scheduled_alarm->date;
  scheduled_alarm_id = scheduled_alarm->stat_part->timeobj_id;

  EVENT_BEGIN(ALARM_SCHEDULED)
  EVENT_VALUE(scheduled_alarm_id)
  EVENT_VALUE(scheduled_alarm_expir_date)
  EVENT_END()
  FORMAT_TRACE()
}

FUNC(void, OS_CODE) tpl_trace_alarm_expire(
  CONSTP2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA) expired_alarm)
{

  P2VAR(tpl_alarm_static, AUTOMATIC, OS_APPL_DATA) expired_alarm_stat;
  VAR(tpl_action_func, TYPEDEF) expired_alarm_action;

  if(expired_alarm->stat_part->expire == tpl_raise_alarm){

    tpl_trace_get_date();
    expired_alarm_stat = (tpl_alarm_static *)expired_alarm->stat_part;
    expired_alarm_action = expired_alarm_stat->action->action;

    EVENT_BEGIN(ALARM_EXPIRE)

    /* TODO: missing Alarm id here */

    if(expired_alarm_action == tpl_action_callback){
    EVENT_VALUE(TRACE_CALLBACK)
    }
    if(expired_alarm_action == tpl_action_activate_task){
    EVENT_VALUE(TRACE_ACT_TASK)
    }
    if(expired_alarm_action == tpl_action_setevent){
    EVENT_VALUE(TRACE_SET_EVENT)
    }
    EVENT_END()
    FORMAT_TRACE()
  }
}

FUNC(void, OS_CODE) tpl_trace_alarm_cancel(
  CONST(tpl_alarm_id, AUTOMATIC)cancelled_alarm_id)
{

  tpl_trace_get_date();

  EVENT_BEGIN(ALARM_CANCEL)
  EVENT_VALUE(cancelled_alarm_id)
  EVENT_END()
    FORMAT_TRACE()
}

#if ALARM_COUNT > 0
FUNC(void, OS_CODE) tpl_trace_counter(
    CONSTP2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter_desc)
{
  VAR(tpl_counter_id, AUTOMATIC) counter_id;
  extern CONSTP2VAR(tpl_counter, OS_VAR, OS_APPL_DATA)
  tpl_counter_table[COUNTER_COUNT];
  VAR(tpl_task_id, AUTOMATIC) i;

  for (i = 0 ; i<COUNTER_COUNT ; i++)
  {
    if ( tpl_counter_table[i] == counter_desc)
    {
      counter_id = i;
    }
  }

  EVENT_BEGIN(COUNTER_INC)
	EVENT_VALUE(counter_id)
	EVENT_END()
	FORMAT_TRACE()
}
#endif /* ALARM_COUNT */

#endif /* WITH_TRACE*/

FUNC(void, OS_CODE) tpl_trace_tpl_init()
{
  tpl_trace_get_date();
  EVENT_BEGIN(TPL_INIT)
  EVENT_END()
  FORMAT_TRACE()
}

FUNC(void, OS_CODE) tpl_trace_tpl_terminate()
{
  tpl_trace_get_date();

  EVENT_BEGIN(TPL_TERMINATE)
  EVENT_END()
  FORMAT_TRACE()
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

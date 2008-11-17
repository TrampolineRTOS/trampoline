/**
 * @file tpl_os_task.c
 *
 * @section desc File description
 *
 * Trampoline Task Management Calls
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Copyright IRISA - JF Deverge for libpcl port
 * Copyright AYRTON TECHNOLOGY for hcs12 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: 2008-09-05 15:24:48 +0200 (Fri, 05 Sep 2008) $
 * $Rev: 509 $
 * $Author: jlb $
 * $URL: https://trampoline.rts-software.org/svn/trunk/os/tpl_os_task.c $
 */

#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_hooks.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_task_kernel.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Kernel service for task activation
 */
FUNC(StatusType, OS_CODE) tpl_activate_task_service(
  CONST(TaskType, AUTOMATIC) task_id)
{
  /*  init the error to no error  */
  VAR(StatusType, AUTOMATIC) result = E_OK;
  VAR(tpl_proc_id, AUTOMATIC) old_running_id;

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  lock the task structures    */
  LOCK_WHEN_TASK()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_ActivateTask)
  STORE_TASK_ID(task_id)

  /*  Check a task_id error   */
  CHECK_TASK_ID_ERROR(task_id,result)

#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
    result = tpl_activate_task(task_id);
    if (result == (tpl_status)E_OK_AND_SCHEDULE)
    {
      old_running_id = tpl_running_id;
      result |= tpl_schedule_from_running(FROM_TASK_LEVEL);
    }
  IF_NO_EXTENDED_ERROR_END()
#endif

#ifndef WITH_SYSTEM_CALL
  if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH)
  {
    tpl_switch_context(
      &(tpl_stat_proc_table[old_running_id]->context),
      &(tpl_stat_proc_table[tpl_running_id]->context)
    );
  }
#endif
  
  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_WHEN_TASK()

  return result;
}


FUNC(StatusType, OS_CODE) tpl_terminate_task_service(void)
{
  /*  init the error to no error  */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  lock the task structures    */
  LOCK_WHEN_TASK()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_TerminateTask)

  /*  check we are at the task level  */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  check the task does not own a resource  */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)

    /*  set the state of the running task to DYING                  */
    tpl_dyn_proc_table[tpl_running_id]->state = (tpl_proc_state)DYING;

    /*  and let the scheduler do its job                            */
    result |= tpl_schedule_from_dying();

  IF_NO_EXTENDED_ERROR_END()
#endif

#ifndef WITH_SYSTEM_CALL
  if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH)
  {
    tpl_switch_context(
      NULL,
      &(tpl_stat_proc_table[tpl_running_id]->context)
    );
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_WHEN_TASK()

  return result;
}


FUNC(StatusType, OS_CODE) tpl_chain_task_service(
  CONST(TaskType, AUTOMATIC) task_id)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;
  
#ifndef NO_TASK
  P2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA) dyn_proc;
  P2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) stat_proc;
  VAR(tpl_activate_counter, AUTOMATIC)            count;
#endif
  
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
  /*  lock the task system    */
  LOCK_WHEN_TASK()
  
  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_ChainTask)
  STORE_TASK_ID(task_id)
  
  /*  Check a call level error    */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  Check a task_id error       */
  CHECK_TASK_ID_ERROR(task_id,result)
  /*  Check no resource is held by the terminating task   */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)
  
#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
  
    dyn_proc = tpl_dyn_proc_table[task_id];
    stat_proc = tpl_stat_proc_table[task_id];
    
    if (task_id == tpl_running_id)
    {
      /*  The activated task and the currently running object
          are the same. So the task is put in the RESURRECT state.    */
      tpl_dyn_proc_table[tpl_running_id]->state = RESURRECT;
      
    }
    else
    {
      count = dyn_proc->activate_count;
      
      if (count < stat_proc->max_activate_count)
      {
        if (count == 0)
        {
          if (stat_proc->type == TASK_EXTENDED)
          {
            /*  if the task is an extended one, it is initialized now */
            dyn_proc->state = (tpl_proc_state)READY;
            tpl_init_proc(task_id);
          }
          else
          {
            /*  if it is a basic task, its initialization is
                postponed to the time it will get the CPU             */
            dyn_proc->state = (tpl_proc_state)READY_AND_NEW;
          }
        }
        /*  put it in the list  */
        tpl_put_new_proc(task_id);
        
        /*  inc the task activation count. When the task
            will terminate it will dec this count and if
            not zero it will be reactivated                           */
        dyn_proc->activate_count++;
        
        /*  the object that is currently running is put in
            the DYING state                                           */
        tpl_dyn_proc_table[tpl_running_id]->state = DYING;
      }
      else
      {
        /*  The max activation count is reached. So an error occurs   */
        result = E_OS_LIMIT;
      }
    }
    
    if (result == E_OK)
    {
      /*  and let the scheduler do its job                            */
      result |= tpl_schedule_from_dying();
    }
    
#ifndef WITH_SYSTEM_CALL
    if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH)
    {
      stat_proc = tpl_stat_proc_table[tpl_running_id];
      tpl_switch_context(
        NULL,
        &(stat_proc->context)
      );
    }
#endif
    
    
  IF_NO_EXTENDED_ERROR_END()
#endif
  
  PROCESS_ERROR(result)
  
  /*  unlock the task structures  */
  UNLOCK_WHEN_TASK()
  
  return result;
}


FUNC(StatusType, OS_CODE) tpl_schedule_service(void)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;
  VAR(tpl_proc_id, AUTOMATIC) old_running_id;
  
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
  /*  lock the task system    */
  LOCK_WHEN_TASK()
  
  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_Schedule)
  
  /*  Check a call level error    */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  Check no resource is held by the calling task   */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)
  
#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
    /*  release the internal resource   */
    tpl_release_internal_resource(tpl_running_id);
    /*  does the rescheduling           */
    old_running_id = tpl_running_id;
    result |= tpl_schedule_from_running(FROM_TASK_LEVEL);
    /*  get the internal resource       */
    tpl_get_internal_resource(tpl_running_id);
  IF_NO_EXTENDED_ERROR_END()
#endif
  
#ifndef WITH_SYSTEM_CALL
  if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH)
  {
    tpl_switch_context(
      &(tpl_stat_proc_table[old_running_id]->context),
      &(tpl_stat_proc_table[tpl_running_id]->context)
    );
  }
#endif
  
  PROCESS_ERROR(result)
  
  /*  unlock the task structures  */
  UNLOCK_WHEN_TASK()
  
  return result;
}


FUNC(StatusType, OS_CODE) tpl_get_task_id_service(
  VAR(TaskRefType, AUTOMATIC) task_id)
{
  /*  get the task id from the task descriptor. If the id is not
      within 0 and TASK_COUNT-1, INVALID_TASK is returned         */
  if (tpl_running_id >= 0 && tpl_running_id < TASK_COUNT)
  {
    *task_id = tpl_running_id;
  }
  else
  {
    *task_id = INVALID_TASK;
  }
  return E_OK;
}


FUNC(StatusType, OS_CODE) tpl_get_task_state_service(
  CONST(TaskType, AUTOMATIC)        task_id,
  VAR(TaskStateRefType, AUTOMATIC)  state)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  LOCK_WHEN_HOOK()

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetTaskState)
  STORE_TASK_STATE_REF(state)

  /*  Check a task_id error       */
  CHECK_TASK_ID_ERROR(task_id,result)

#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
    *state = (tpl_dyn_proc_table[task_id]->state) & 0x3;
  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  UNLOCK_WHEN_HOOK()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_task.c */

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
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_hooks.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_task_kernel.h"
#include "tpl_trace.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#endif

extern CONST(tpl_proc_id, AUTOMATIC) INVALID_TASK;

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

  /*  lock the kernel    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

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
      tpl_schedule_from_running();
# ifndef WITH_SYSTEM_CALL
      if (tpl_kern.need_switch != NO_NEED_SWITCH)
      {
        tpl_switch_context(
          &(tpl_kern.s_old->context),
          &(tpl_kern.s_running->context)
        );
      }
# endif
    }
  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)
	
  /*  unlock the kernel  */
  UNLOCK_KERNEL()
	

  return result;
}


FUNC(StatusType, OS_CODE) tpl_terminate_task_service(void)
{
  /*  init the error to no error  */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /*  lock the kernel    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_TerminateTask)

  /*  check we are at the task level  */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  check the task does not own a resource  */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
    /*  the activate count is decreased
     */
    tpl_kern.running->activate_count--;

    /*  and let the scheduler do its job
     */
    tpl_schedule_from_dying();
    TRACE_TASK_TERMINATE(tpl_kern.s_old->id,tpl_kern.s_old->id)
# ifndef WITH_SYSTEM_CALL
    if (tpl_kern.need_switch != NO_NEED_SWITCH)
    {
      tpl_switch_context(
        NULL,
        &(tpl_kern.s_running->context)
      );
    }
# endif

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  return result;
}


FUNC(StatusType, OS_CODE) tpl_chain_task_service(
  CONST(TaskType, AUTOMATIC) task_id)
{
  VAR(StatusType, AUTOMATIC)  result = E_OK;

  /*  lock the kernel    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

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
    /* the activate count is decreased
     */
    tpl_kern.running->activate_count--;

    /* activate the chained task
     */
    result = tpl_activate_task(task_id);

    if (result == E_OK_AND_SCHEDULE)
    {
      /*  and let the scheduler do its job                            */
      TRACE_TASK_TERMINATE(tpl_kern.running_id,tpl_kern.running_id)
      tpl_schedule_from_dying();
# ifndef WITH_SYSTEM_CALL
      if (tpl_kern.need_switch != NO_NEED_SWITCH)
      {
        tpl_switch_context(NULL, &(tpl_kern.s_running->context));
      }
# endif
    }
    else
    {
      /* the activate count is restored since the caller does not terminate */
      tpl_kern.running->activate_count++;
    }

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  return result;
}


FUNC(StatusType, OS_CODE) tpl_schedule_service(void)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /*  lock the task system    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_Schedule)

  /*  Check a call level error    */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  Check no resource is held by the calling task   */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)

#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
    /*  release the internal resource   */
    tpl_release_internal_resource(tpl_kern.running_id);
    /*  does the rescheduling           */
    tpl_schedule_from_running();
    /*  get the internal resource       */
    tpl_get_internal_resource(tpl_kern.running_id);
# ifndef WITH_SYSTEM_CALL
    if (tpl_kern.need_switch != NO_NEED_SWITCH)
    {
      tpl_switch_context(
        &(tpl_kern.s_old->context),
        &(tpl_kern.s_running->context)
      );
    }
# endif
  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  return result;
}


FUNC(StatusType, OS_CODE) tpl_get_task_id_service(
  VAR(TaskRefType, AUTOMATIC) task_id)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;
	
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetTaskID)
  STORE_TASK_ID_REF(task_id)
  
  /*  get the task id from the task descriptor. If the id is not
      within 0 and TASK_COUNT-1, INVALID_TASK is returned         */
  IF_NO_EXTENDED_ERROR(result)
	if (tpl_kern.running_id >= 0 && tpl_kern.running_id < TASK_COUNT)
	{
		*task_id = tpl_kern.running_id;
	}
	else
	{
		*task_id = INVALID_TASK;
	}
  IF_NO_EXTENDED_ERROR_END()
  
  UNLOCK_KERNEL()

  return result;
}


FUNC(StatusType, OS_CODE) tpl_get_task_state_service(
  CONST(TaskType, AUTOMATIC)        task_id,
  VAR(TaskStateRefType, AUTOMATIC)  state)
{
  VAR(StatusType, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetTaskState)
  STORE_TASK_ID(task_id)
  STORE_TASK_STATE_REF(state)

  /*  Check a task_id error       */
  CHECK_TASK_ID_ERROR(task_id,result)

#ifndef NO_TASK
  IF_NO_EXTENDED_ERROR(result)
    *state = (tpl_dyn_proc_table[task_id]->state) & 0x3;
  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_task.c */

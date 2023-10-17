/**
 * @file tpl_os_task_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Task Management Calls
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de
 * Nantes Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_task_kernel.h"
#include "tpl_dow.h"
#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_hooks.h"
#include "tpl_trace.h"

#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#if SPINLOCK_COUNT > 0
#include "tpl_as_spinlock_kernel.h"
#endif
#endif

#if WITH_MEMORY_PROTECTION == YES
#include "tpl_os_mem_prot.h"
#endif

extern CONST(tpl_proc_id, AUTOMATIC) INVALID_TASK;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Kernel service for task activation
 */
FUNC(StatusType, OS_CODE)
tpl_activate_task_service(CONST(tpl_task_id, AUTOMATIC) task_id)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_PROC_CORE_ID(task_id, proc_core_id)

  /*  init the error to no error  */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /*  lock the kernel    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_ActivateTask)
  STORE_TASK_ID(task_id)

  /* Check call level error */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  /* Check a task_id error   */
  CHECK_TASK_ID_ERROR(task_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id, result)

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {

    DOW_DO(printf("*S* ActivateTask\n"));

    result = tpl_activate_task(task_id);
    if (TPL_KERN(proc_core_id).need_schedule)
    {
      tpl_schedule_from_running(CORE_ID_OR_NOTHING(proc_core_id));
      DOW_DO(printf("*S* ActivateTask - rescheduling done\n"));
      SWITCH_CONTEXT(CORE_ID_OR_NOTHING(proc_core_id))
    }
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  return result;
}

FUNC(StatusType, OS_CODE) tpl_terminate_task_service(void)
{
  GET_CURRENT_CORE_ID(core_id)

  /* init the error to no error */
  VAR(StatusType, AUTOMATIC) result = E_OK;

  /* lock the kernel */
  LOCK_KERNEL()
  /* store information for error hook routine */
  STORE_SERVICE(OSServiceId_TerminateTask)
  /* check interrupts are not disabled by user */
  CHECK_INTERRUPT_LOCK(result)
  /* check we are at the task level */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id, result)
  /* check the task does not own a resource */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  /*  checks the task does not occupy spinlock(s)   */
  CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(core_id, result)

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /* the activate count is decreased */
    TPL_KERN(core_id).running->activate_count--;

    /* terminate the running task */
    tpl_terminate();
    /* task switching should occur */
    TPL_KERN(core_id).need_switch = NEED_SWITCH;
    /* start the highest priority process */
    tpl_start(CORE_ID_OR_NOTHING(core_id));

    SWITCH_CONTEXT_NOSAVE(CORE_ID_OR_NOTHING(core_id))
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the kernel  */
  UNLOCK_KERNEL()

  return result;
}

FUNC(StatusType, OS_CODE)
tpl_chain_task_service(CONST(tpl_task_id, AUTOMATIC) task_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(StatusType, AUTOMATIC) result = E_OK;

  /*  lock the kernel    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_ChainTask)
  STORE_TASK_ID(task_id)

  /*  Check a call level error    */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id, result)
  /*  Check a task_id error       */
  CHECK_TASK_ID_ERROR(task_id, result)
  /*  Check no resource is held by the terminating task   */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  /*  checks the task does not occupy spinlock(s)   */
  CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(core_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id, result)

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /* the activate count is decreased */
    TPL_KERN(core_id).running->activate_count--;

    DOW_DO(printf("*S* ChainTask\n"));

    /* activate the chained task */
    result = tpl_activate_task(task_id);

    if (result == E_OK)
    {
      /*
       * This first part deals with the case of an activated task
       * on a remote core
       */

      /* get the core id of the newly activated task */
      GET_PROC_CORE_ID(task_id, activated_task_core_id)
#if NUMBER_OF_CORES > 1
      if (activated_task_core_id != core_id)
      {
        REMOTE_SWITCH_CONTEXT(activated_task_core_id);
      }
#endif

      /*
       * This second part deals with the local rescheduling due to
       * the termination of the task
       */

      /* terminate the running task */
      tpl_terminate();
      /* task switching should occur */
      TPL_KERN(core_id).need_switch = NEED_SWITCH;
      /* start the highest priority task */
      tpl_start(CORE_ID_OR_NOTHING(core_id));
      /* local switch context because the task terminates */
      SWITCH_CONTEXT_NOSAVE(CORE_ID_OR_NOTHING(core_id))
    }
    else
    {
      /* the activate count is restored since the caller does not terminate */
      TPL_KERN(core_id).running->activate_count++;
    }
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  return result;
}

FUNC(StatusType, OS_CODE) tpl_schedule_service(void)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(StatusType, AUTOMATIC) result = E_OK;

  /*  lock the task system    */
  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_Schedule)

  /*  Check a call level error    */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id, result)
  /*  Check no resource is held by the calling task   */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  /*  checks the task does not occupy spinlock(s)   */
  CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(core_id, result)

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    DOW_DO(printf("*S* Schedule\n"));
    /*  release the internal resource   */
    tpl_release_internal_resource((tpl_proc_id)TPL_KERN(core_id).running_id);
    /*  does the rescheduling           */
    tpl_schedule_from_running(CORE_ID_OR_NOTHING(core_id));
    /*  get the internal resource       */

    if (TPL_KERN(core_id).running_id == TPL_KERN(core_id).elected_id)
    {
      tpl_get_internal_resource((tpl_proc_id)TPL_KERN(core_id).running_id);
    }

    LOCAL_SWITCH_CONTEXT(core_id)
  }
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  return result;
}

FUNC(StatusType, OS_CODE)
tpl_get_task_id_service(CONSTP2VAR(tpl_task_id, AUTOMATIC, OS_APPL_DATA)
                            task_id)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(StatusType, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetTaskID)
  STORE_TASK_ID_REF(task_id)

  /* Check call level error */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  /* check state is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, task_id, result);

  /*  get the task id from the task descriptor. If the id is less
   *  than TASK_COUNT-1.
   *  TPL_KERN(core_id).running_id is uint32 (tpl_os_kernel.h) (always >= 0)
   *  INVALID_TASK is returned         */
  IF_NO_EXTENDED_ERROR(result)
  {
    if (TPL_KERN(core_id).running_id < TASK_COUNT)
    {
      *task_id = (tpl_proc_id)TPL_KERN(core_id).running_id;
    }
    else
    {
      *task_id = INVALID_TASK;
    }
  }

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

FUNC(StatusType, OS_CODE)
tpl_get_task_state_service(CONST(tpl_task_id, AUTOMATIC) task_id,
                           CONSTP2VAR(tpl_proc_state, AUTOMATIC, OS_APPL_DATA)
                               state)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(StatusType, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetTaskState)
  STORE_TASK_ID(task_id)
  STORE_TASK_STATE_REF(state)

  /* Check call level error */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  /*  Check a task_id error       */
  CHECK_TASK_ID_ERROR(task_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id, result)

  /* check state is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, state, result);

#if TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    *state = (tpl_dyn_proc_table[task_id]->state) & 0x3;
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_task.c */

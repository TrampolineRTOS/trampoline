/**
 * @file tpl_os_event_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Event Management implementation file
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

#include "tpl_machine_interface.h"
#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_kernel.h"
#include "tpl_os_task_kernel.h"
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

#include "tpl_os_event_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_set_event_service.
 */
FUNC(tpl_status, OS_CODE)
tpl_set_event_service(CONST(tpl_task_id, AUTOMATIC) task_id,
                      CONST(tpl_event_mask, AUTOMATIC) event)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_PROC_CORE_ID(task_id, proc_core_id)

  VAR(tpl_status, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_SetEvent)
  STORE_TASK_ID(task_id)
  STORE_EVENT_MASK(event)

  /* Check call level error: forbidden from an alarm callback */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  CHECK_TASK_ID_ERROR(task_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id, result)

  /*  checks the task is an extended one  */
  CHECK_NOT_EXTENDED_TASK_ERROR(task_id, result)
  /*  checks the task is not in the SUSPENDED state   */
  CHECK_SUSPENDED_TASK_ERROR(task_id, result)

#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    result = tpl_set_event(task_id, event);
    if (result == E_OK && TPL_KERN(proc_core_id).need_schedule)
    {
      tpl_schedule_from_running(CORE_ID_OR_NOTHING(proc_core_id));
      SWITCH_CONTEXT(CORE_ID_OR_NOTHING(proc_core_id))
    }
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/*
 * tpl_clear_event_service
 */
FUNC(tpl_status, OS_CODE)
tpl_clear_event_service(CONST(tpl_event_mask, AUTOMATIC) event)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_ClearEvent)
  STORE_EVENT_MASK(event)

  /*  ClearEvent cannot be called from ISR level  */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id, result)
  /*  checks the calling task is an extended one  */
  CHECK_NOT_EXTENDED_RUNNING_ERROR(core_id, result)

#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    tpl_task_events_table[(tpl_proc_id)TPL_KERN(core_id).running_id]->evt_set &=
        (tpl_event_mask)(~event);
    TRACE_EVENT_RESET(event)
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/*
 * tpl_get_event_service
 */
FUNC(tpl_status, OS_CODE)
tpl_get_event_service(CONST(tpl_task_id, AUTOMATIC) task_id,
                      CONSTP2VAR(tpl_event_mask, AUTOMATIC, OS_APPL_DATA) event)
{
  GET_CURRENT_CORE_ID(core_id)

  VAR(tpl_status, AUTOMATIC) result = E_OK;

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_GetEvent)
  STORE_TASK_ID(task_id)
  STORE_EVENT_MASK_REF(event)

  /* Check call level error: forbidden from an alarm callback */
  CHECK_CALLBACK_CALL_LEVEL_ERROR(result, core_id)

  CHECK_TASK_ID_ERROR(task_id, result)

  /* check access right */
  CHECK_ACCESS_RIGHTS_TASK_ID(core_id, task_id, result)

  /*  checks the task is an extended one  */
  CHECK_NOT_EXTENDED_TASK_ERROR(task_id, result)
  /*  checks the task is not in the SUSPENDED state   */
  CHECK_SUSPENDED_TASK_ERROR(task_id, result)

  /* check event is in an authorized memory region */
  CHECK_DATA_LOCATION(core_id, event, result);

#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    *event = tpl_task_events_table[task_id]->evt_set;
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

/*
 * tpl_wait_event_service
 */
FUNC(tpl_status, OS_CODE)
tpl_wait_event_service(CONST(tpl_event_mask, AUTOMATIC) event)
{
  GET_CURRENT_CORE_ID(core_id)
  GET_TPL_KERN_FOR_CORE_ID(core_id, kern)

  VAR(tpl_status, AUTOMATIC) result = E_OK;

  /* event mask of the caller */
  CONSTP2VAR(tpl_task_events, AUTOMATIC, OS_VAR)
  task_events = tpl_task_events_table[TPL_KERN_REF(kern).running_id];

  LOCK_KERNEL()

  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)

  STORE_SERVICE(OSServiceId_WaitEvent)
  STORE_EVENT_MASK(event)

  /*  WaitEvent cannot be called from ISR level  */
  CHECK_TASK_CALL_LEVEL_ERROR(core_id, result)
  /*  checks the calling task is an extended one  */
  CHECK_NOT_EXTENDED_RUNNING_ERROR(core_id, result)
  /*  checks the task does not occupy resource(s)   */
  CHECK_RUNNING_OWNS_REZ_ERROR(core_id, result)
  /*  checks the task does not occupy spinlock(s)   */
  CHECK_SCHEDULE_WHILE_OCCUPED_SPINLOCK(core_id, result)

#if EXTENDED_TASK_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    /* all the evt_wait is overidden. */
    task_events->evt_wait = event;

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
    /* reset the execution budget */
    tpl_tp_on_terminate_or_wait(TPL_KERN_REF(kern).running_id);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION  == YES */

    /* check one of the event to wait is not already set */
    if ((task_events->evt_set & task_events->evt_wait) == 0)
    {
      /* No event is set, the task blocks */
      tpl_block();
    }
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
    else
    {
      if (FALSE == tpl_tp_on_activate_or_release(TPL_KERN_REF(kern).running_id))
      {
        tpl_call_protection_hook(E_OS_PROTECTION_ARRIVAL);
      }
      else
      {
        tpl_tp_on_start(TPL_KERN_REF(kern).running_id);
      }
    }
#endif /* WITH_AUTOSAR_TIMING_PROTECTION == YES */
  }
#endif

  PROCESS_ERROR(result)

  UNLOCK_KERNEL()

  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_event_kernel.c */

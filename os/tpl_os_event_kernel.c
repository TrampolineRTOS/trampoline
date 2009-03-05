/**
 * @file tpl_os_event_kernel.c
 *
 * @section desc File description
 *
 * Trampoline Event Management implementation file
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Copyright ESEO for function and data structures documentation
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

#include "tpl_os_definitions.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_os_kernel.h"
#include "tpl_os_task_kernel.h"
#include "tpl_machine_interface.h"

#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_as_protec_hook.h"
#endif

#include "tpl_os_event_kernel.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_set_event_service.
 */
FUNC(tpl_status, OS_CODE) tpl_set_event_service(
  CONST(tpl_task_id, AUTOMATIC)       task_id,
  CONST(tpl_event_mask, AUTOMATIC)    event)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  VAR(tpl_proc_id, AUTOMATIC) old_running_id = tpl_running_id;
  
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
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
  
#ifndef NO_EXTENDED_TASK
  IF_NO_EXTENDED_ERROR(result)
  result = tpl_set_event(task_id, event);
  if (result == (tpl_status)E_OK_AND_SCHEDULE)
  {
    result |= tpl_schedule_from_running(FROM_TASK_LEVEL);
# ifndef WITH_SYSTEM_CALL
    if (tpl_need_switch != NO_NEED_SWITCH)
    {
      tpl_switch_context(
        (P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA))
          &(tpl_stat_proc_table[old_running_id]->context),
        (P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA))
          &(tpl_stat_proc_table[tpl_running_id]->context)
      );
    }
# endif
  }
  IF_NO_EXTENDED_ERROR_END()
#endif

  UNLOCK_WHEN_NO_HOOK()
  
  PROCESS_ERROR(result)
  
  UNLOCK_WHEN_HOOK()
  
  return result;
}


/*
 * tpl_clear_event_service
 */
FUNC(tpl_status, OS_CODE) tpl_clear_event_service(
  CONST(tpl_event_mask, AUTOMATIC) event)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
  LOCK_WHEN_HOOK()
  
  STORE_SERVICE(OSServiceId_ClearEvent)
  STORE_EVENT_MASK(event)
  
  LOCK_WHEN_NO_HOOK()
  /*  ClearEvent cannot be called from ISR level  */
  CHECK_TASK_CALL_LEVEL_ERROR(result)
  /*  checks the calling task is an extended one  */
  CHECK_NOT_EXTENDED_RUNNING_ERROR(result)
  
#ifndef NO_EXTENDED_TASK
  IF_NO_EXTENDED_ERROR(result)
    tpl_task_events_table[tpl_running_id]->evt_set &= (tpl_event_mask)(~event);
  IF_NO_EXTENDED_ERROR_END()
#endif
  
  UNLOCK_WHEN_NO_HOOK()
  
  PROCESS_ERROR(result)
  
  UNLOCK_WHEN_HOOK()
  
  return result;
}

/*
 * tpl_get_event_service
 */
FUNC(tpl_status, OS_CODE) tpl_get_event_service(
  CONST(tpl_task_id, AUTOMATIC)                       task_id,
  CONSTP2VAR(tpl_event_mask, AUTOMATIC, OS_APPL_DATA) event)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
  LOCK_WHEN_HOOK()
  
  STORE_SERVICE(OSServiceId_GetEvent)
  STORE_TASK_ID(task_id)
  STORE_EVENT_MASK_REF(event)
  
  CHECK_TASK_ID_ERROR(task_id,result)
  
  /*  checks the task is an extended one  */
  CHECK_NOT_EXTENDED_TASK_ERROR(task_id,result)
  /*  checks the task is not in the SUSPENDED state   */
  CHECK_SUSPENDED_TASK_ERROR(task_id,result)
  
#ifndef NO_EXTENDED_TASK
  IF_NO_EXTENDED_ERROR(result)
  *event = tpl_task_events_table[task_id]->evt_set;
  IF_NO_EXTENDED_ERROR_END()
#endif
  
  PROCESS_ERROR(result)
  
  UNLOCK_WHEN_HOOK()
  
  return result;
}

/*
 * tpl_wait_event_service
 */
FUNC(tpl_status, OS_CODE) tpl_wait_event_service(
  CONST(tpl_event_mask, AUTOMATIC) event)
{
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  VAR(tpl_task_id, AUTOMATIC) old_running_id;
  
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result)
  
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
  
#ifndef NO_EXTENDED_TASK
  IF_NO_EXTENDED_ERROR(result)
  /*  all the evt_wait is overidden.  */
  tpl_task_events_table[tpl_running_id]->evt_wait = event;
  /*  check one of the event to wait is not already set       */
  if ((tpl_task_events_table[tpl_running_id]->evt_set & event) == 0)
  {
    /*  no one is set, the task goes in the WAITING state   */
    tpl_dyn_proc_table[tpl_running_id]->state = WAITING;
    /*  save the current running process                    */
    old_running_id = tpl_running_id;
    /*  and a rescheduling occurs                           */
    result |= tpl_schedule_from_waiting();
# ifndef WITH_SYSTEM_CALL
    if (tpl_need_switch != NO_NEED_SWITCH)
    {
      tpl_switch_context(
        &(tpl_stat_proc_table[old_running_id]->context),
        &(tpl_stat_proc_table[tpl_running_id]->context)
      );
    }
# endif  
  }
  IF_NO_EXTENDED_ERROR_END()
#endif
  
  UNLOCK_WHEN_NO_HOOK()
  
  PROCESS_ERROR(result)
  
  UNLOCK_WHEN_HOOK()
  
  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_os_event_kernel.c */

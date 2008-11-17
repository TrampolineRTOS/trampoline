/**
 * @file tpl_os_it_kernel.c
 *
 * @section desc File description
 *
 * Trampoline interrupt service routines management
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
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
#include "tpl_os_kernel.h"
#include "tpl_os_error.h"
#include "tpl_os_errorhook.h"
#include "tpl_machine_interface.h"

#include "tpl_os_it_kernel.h"

#ifdef WITH_AUTOSAR_STACK_MONITORING
#include "tpl_as_stack_monitor.h"
#endif /* WITH_AUTOSAR_STACK_MONITORING */

#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#endif

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_terminate_isr2_service
 *
 * While this function is not part of the OSEK API, it is used
 * to terminate an ISR2 routine
 */
FUNC(tpl_status, OS_CODE) tpl_terminate_isr2_service(void)
{
  /*  init the error to no error  */
  VAR(tpl_status, AUTOMATIC) result = E_OK;
  
  CHECK_INTERRUPT_LOCK(result)
  
  /*  lock the task structures    */
  LOCK_WHEN_ISR()
  
  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_TerminateISR)
  
  /*  check we are at the ISR2 level  */
  CHECK_ISR2_CALL_LEVEL_ERROR(result)
  /*  check the ISR2 does not own a resource  */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)
  
#ifndef NO_ISR
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
  UNLOCK_WHEN_ISR()
  
  return result;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#ifndef NO_ISR

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 */
STATIC FUNC(void, OS_CODE) tpl_activate_isr(
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
  CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA) isr =
    tpl_dyn_proc_table[isr_id];
  /*  MISRA RULE 33 VIOLATION: the right statement does
      not need to be executed if the first test fails
  */
  if ((isr->activate_count < tpl_stat_proc_table[isr_id]->max_activate_count)
#ifdef WITH_AUTOSAR
      && (tpl_is_isr2_enabled(isr_id))
#endif
      )
  {
    if (isr->activate_count == 0)
    {
      /*  check the isr is in the SUSPENDED state before moving it        */
      if (isr->state == (tpl_proc_state)SUSPENDED)
      {
        isr->state = (tpl_proc_state)READY_AND_NEW;
      }
    }
    /*  put it in the list  */
    tpl_put_new_proc(isr_id);
    /*  inc the isr activation count. When the isr will terminate
        it will dec this count and if not zero it will be reactivated   */
    isr->activate_count++;
  }
}

/*
 * The central interrupt handler is called by the interrupt handler
 * with the id of the interrupt (usually its priority) as parameter
 * tpl_central_interrupt_handler saves the context of the interrupted
 * task / interrupt handler, switches to the context of the handler
 * and calls the handler
 */
FUNC(void, OS_CODE) tpl_central_interrupt_handler(CONST(u16, AUTOMATIC) isr_id)
{
  STATIC VAR(s32, AUTOMATIC) tpl_it_nesting =  0;
  P2CONST(tpl_isr_static, AUTOMATIC, OS_APPL_DATA) isr;
  VAR(tpl_status, AUTOMATIC) result = E_OK;

#ifdef WITH_AUTOSAR_STACK_MONITORING
    tpl_check_stack(tpl_running_id);
#endif /* WITH_AUTOSAR_STACK_MONITORING */

  /*  Is there a handler for this id ?
      ie the id has been counted in the table and there
      is a tpl_isr available
   */
#ifdef OS_EXTENDED
  if (isr_id < ISR_COUNT)
  {
#endif
    tpl_it_nesting++;
    
    isr = tpl_isr_stat_table[isr_id];
    
    if (isr != NULL)
    {
      if ((isr->next) == NULL)
      {
        /*  Only one handler for this id. run the handler   */
        tpl_activate_isr(isr->isr_id);
      }
      else
      {
        /*  look for the handler    */
        while (isr != NULL)
        {
          if (isr->helper() == TRUE)
          {
            /* activate the handler */
            tpl_activate_isr(isr->isr_id);
          }
          isr = isr->next;
        }
      }
    }
    
    tpl_it_nesting--;
    
    if (tpl_it_nesting == 0)
    {
      tpl_proc_id old_running_id = tpl_running_id;
      
      if(tpl_current_os_state() == OS_IDLE)
      {
        result |= tpl_schedule_from_idle();
      }
      else
      {
        result |= tpl_schedule(FROM_IT_LEVEL);
      }
      
#ifndef WITH_SYSTEM_CALL
      if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH)
      {
        tpl_switch_context_from_it(
          &(tpl_stat_proc_table[old_running_id]->context),
          &(tpl_stat_proc_table[tpl_running_id]->context)
        );
      }
#endif
    }
#ifdef OS_EXTENDED
  }
#endif
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* NO_ISR */

/* End of file tpl_os_it_kernel.c */

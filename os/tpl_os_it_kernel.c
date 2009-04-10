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

volatile VAR(u16, OS_VAR) tpl_locking_depth = 0;
extern VAR(u32, OS_VAR) tpl_cpt_user_task_lock;
extern VAR(tpl_bool, OS_VAR) tpl_user_task_lock;

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_suspend_all_interrupts_service(void)
{
  tpl_disable_interrupts();
  
  tpl_locking_depth++;

#ifdef WITH_AUTOSAR
  tpl_cpt_user_task_lock++;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  if( tpl_locking_depth == 1)
  {
    tpl_start_all_isr_lock_monitor(tpl_kern.running_id);
  }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_resume_all_interrupts_service(void)
{
  if (tpl_locking_depth > 0)
  {
    tpl_locking_depth--;
#ifdef WITH_AUTOSAR
    tpl_cpt_user_task_lock--;
#endif
  }
  if( tpl_locking_depth == 0)
  {
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_stop_all_isr_lock_monitor(tpl_kern.running_id);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    tpl_enable_interrupts();
  }
  
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_disable_all_interrupts_service(void)
{
  tpl_disable_interrupts();

#ifdef WITH_AUTOSAR
  tpl_user_task_lock = TRUE;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_start_all_isr_lock_monitor(tpl_kern.running_id);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_enable_all_interrupts_service(void)
{
#ifdef WITH_AUTOSAR
  tpl_user_task_lock = FALSE;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  tpl_stop_all_isr_lock_monitor(tpl_kern.running_id);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */

  tpl_enable_interrupts();
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_suspend_os_interrupts_service(void)
{
  tpl_disable_interrupts();
  
  tpl_locking_depth++;

#ifdef WITH_AUTOSAR
  tpl_cpt_user_task_lock++;
#endif

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
  if( tpl_locking_depth == 1)
  {
    tpl_start_all_isr_lock_monitor(tpl_kern.running_id);
  }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

/**
 * TODO: document this
 */
FUNC(void, OS_CODE) tpl_resume_os_interrupts_service(void)
{
  if (tpl_locking_depth > 0)
  {
    tpl_locking_depth--;
#ifdef WITH_AUTOSAR
    tpl_cpt_user_task_lock--;
#endif
  }
  if( tpl_locking_depth == 0)
  {
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_stop_all_isr_lock_monitor(tpl_kern.running_id);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    tpl_enable_interrupts();
  }
}

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
  LOCK_KERNEL()
  
  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_TerminateISR2)
  
  /*  check we are at the ISR2 level  */
  CHECK_ISR2_CALL_LEVEL_ERROR(result)
  /*  check the ISR2 does not own a resource  */
  CHECK_RUNNING_OWNS_REZ_ERROR(result)
  
#ifndef NO_ISR
  IF_NO_EXTENDED_ERROR(result)
  
  /* the activate count is decreased
   */
  tpl_kern.running->activate_count--;
    
  /*  and let the scheduler do its job  */
  tpl_schedule_from_dying();
  
  IF_NO_EXTENDED_ERROR_END()
#endif
  
#ifndef WITH_SYSTEM_CALL
  if (tpl_kern.need_switch != NO_NEED_SWITCH)
  {
    tpl_switch_context(
      NULL,
      &(tpl_kern.s_running->context)
    );
  }
#endif
  
  PROCESS_ERROR(result)
  
  /*  unlock the task structures  */
  UNLOCK_KERNEL()
  
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

#ifdef WITH_AUTOSAR_STACK_MONITORING
    tpl_check_stack(tpl_kern.running_id);
#endif /* WITH_AUTOSAR_STACK_MONITORING */

  /*  Is there a handler for this id ?
      ie the id has been counted in the table and there
      is a tpl_isr available
   */
#ifdef OS_EXTENDED
  if ((isr_id >= TASK_COUNT) && (isr_id < (TASK_COUNT + ISR_COUNT)))
  {
#endif
    tpl_it_nesting++;
    
    isr = tpl_isr_stat_table[isr_id - TASK_COUNT];
    
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
      tpl_schedule_from_running();
      
#ifndef WITH_SYSTEM_CALL
      if (tpl_kern.need_switch != NO_NEED_SWITCH)
      {
        tpl_switch_context_from_it(
          &(tpl_kern.s_old->context),
          &(tpl_kern.s_running->context)
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

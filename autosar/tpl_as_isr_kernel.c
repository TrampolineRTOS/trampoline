/**
 * @file tpl_as_isr_kernel.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software ISR internals implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#include "tpl_as_isr_kernel.h"
#include "tpl_as_isr_definitions.h"
#include "tpl_as_error.h"

/* for LOCK_KERNEL() UNLOCK_KERNEL()  */
extern FUNC(void, OS_CODE) tpl_get_task_lock(void);
extern FUNC(void, OS_CODE) tpl_release_task_lock(void);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_disable_isr2_by_user (
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
#if ISR_COUNT > 0
  VAR(tpl_isr_id, AUTOMATIC) actual_id = isr_id - TASK_COUNT;
  
  if (tpl_isr2_enable_table[actual_id] == DISABLED_BY_TIMING_PROTECTION)
  {
    tpl_isr2_enable_table[actual_id] = DISABLED_BY_BOTH;
  }
  else
  {
    tpl_isr2_enable_table[actual_id] = DISABLED_BY_USER;
  }
#endif
}

FUNC(void, OS_CODE) tpl_disable_isr2_by_timing_protection (
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
#if ISR_COUNT > 0
  VAR(tpl_isr_id, AUTOMATIC) actual_id = isr_id - TASK_COUNT;
  
  if (tpl_isr2_enable_table[actual_id] == DISABLED_BY_USER)
  {
    /* this case cannot happen but it is logically valid */
    tpl_isr2_enable_table[actual_id] = DISABLED_BY_BOTH;
  }
  else
  {
    tpl_isr2_enable_table[actual_id] = DISABLED_BY_TIMING_PROTECTION;
  }
#endif
}

FUNC(void, OS_CODE) tpl_enable_isr2_by_user (
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
#if ISR_COUNT > 0
  VAR(tpl_isr_id, AUTOMATIC) actual_id = isr_id - TASK_COUNT;
  
  if (tpl_isr2_enable_table[actual_id] == DISABLED_BY_USER)
  {
    tpl_isr2_enable_table[actual_id] = ENABLED;
  }
  if (tpl_isr2_enable_table[actual_id] == DISABLED_BY_BOTH)
  {
    tpl_isr2_enable_table[actual_id] = DISABLED_BY_TIMING_PROTECTION;
  }
#endif
}

FUNC(void, OS_CODE) tpl_enable_isr2_by_timing_protection (
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
#if ISR_COUNT > 0
  VAR(tpl_isr_id, AUTOMATIC) actual_id = isr_id - TASK_COUNT;

  if (tpl_isr2_enable_table[actual_id] == DISABLED_BY_BOTH)
  {
    tpl_isr2_enable_table[actual_id] = DISABLED_BY_USER;
  }
  if (tpl_isr2_enable_table[actual_id] == DISABLED_BY_TIMING_PROTECTION)
  {
    tpl_isr2_enable_table[actual_id] = ENABLED;
  }
#endif
}

FUNC(tpl_bool, OS_CODE) tpl_is_isr2_enabled (
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
  VAR(tpl_bool, AUTOMATIC) result = FALSE;

#if ISR_COUNT > 0
  if (tpl_isr2_enable_table[isr_id - TASK_COUNT] == ENABLED)
  {
    result = TRUE;
  }
  else
  {
    result = FALSE;
  }
#endif
  
  return result;
}

/*
 * Get the ID of the currently running ISR.
 *
 * It returns the identifier of the currently running ISR
 * or INVALID_ISR when called from outside a running ISR.
 *
 * see paragraph 8.4.2 page 51 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(tpl_isr_id, OS_CODE) tpl_get_isr_id_service(void)
{
  GET_CURRENT_CORE_ID(core_id)
  
  VAR(StatusType, AUTOMATIC) result_status = E_OK;
  VAR(tpl_isr_id, AUTOMATIC) result = INVALID_ISR;

  /*  lock the kernel    */
  LOCK_KERNEL()
	
  /* check interrupts are not disabled by user    */
  CHECK_INTERRUPT_LOCK(result_status)
	
  /*  store information for error hook routine    */
  STORE_SERVICE(OSServiceId_GetISRID)

  if ((TPL_KERN(core_id).running_id >= TASK_COUNT) &&
      TPL_KERN(core_id).running_id < (ISR_COUNT+TASK_COUNT))
  {
    result = (tpl_proc_id)TPL_KERN(core_id).running_id;
  }
	
  PROCESS_ERROR(result_status)
	
  /*  unlock the kernel  */
  UNLOCK_KERNEL()
	
  return result;	
}

/**
 * Disables the specified ISR
 *
 * see ß8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_disable_interrupt_source_service(
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  CHECK_ISR_ID_ERROR(isr_id,result)

#if ISR_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    tpl_disable_isr2_by_user(isr_id);
  }
#endif

  return result;
}

/**
 * Enables the specified ISR
 *
 * see ß8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_enable_interrupt_source_service(
    VAR(tpl_isr_id, AUTOMATIC) isr_id)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  CHECK_ISR_ID_ERROR(isr_id,result)

#if ISR_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)
  {
    tpl_enable_isr2_by_user(isr_id);
  }
#endif

  return result;
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_isr_kernel.c  */

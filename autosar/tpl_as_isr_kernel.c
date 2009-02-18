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

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_disable_isr2_by_user (
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
#ifndef NO_ISR
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
#ifndef NO_ISR
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
#ifndef NO_ISR
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
#ifndef NO_ISR
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

#ifndef NO_ISR
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
  if ((tpl_running_id >= TASK_COUNT) && tpl_running_id < (ISR_COUNT+TASK_COUNT))
  {
    return tpl_running_id;
  }
  else
  {
    return INVALID_ISR;
  }
}

/**
 * Disables the specified ISR
 *
 * see §8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_disable_interrupt_source_service(
  CONST(tpl_isr_id, AUTOMATIC) isr_id)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  CHECK_ISR_ID_ERROR(isr_id,result)

#ifndef NO_ISR
  IF_NO_EXTENDED_ERROR(result)
    tpl_disable_isr2_by_user(isr_id);
  IF_NO_EXTENDED_ERROR_END()
#endif

  return result;
}

/**
 * Enables the specified ISR
 *
 * see §8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_enable_interrupt_source_service(
    VAR(tpl_isr_id, AUTOMATIC) isr_id)
{
  VAR(tpl_status, AUTOMATIC)  result = E_OK;

  CHECK_ISR_ID_ERROR(isr_id,result)

#ifndef NO_ISR
  IF_NO_EXTENDED_ERROR(result)
    tpl_enable_isr2_by_user(isr_id);
  IF_NO_EXTENDED_ERROR_END()
#endif

  return result;
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_isr_kernel.c  */

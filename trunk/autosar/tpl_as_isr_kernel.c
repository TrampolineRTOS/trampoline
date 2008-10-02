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
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) isr2)
{
  if (isr2->enabled == DISABLED_BY_TIMING_PROTECTION)
  {
    isr2->enabled = DISABLED_BY_BOTH;
  }
  else
  {
    isr2->enabled = DISABLED_BY_USER;
  }
}

FUNC(void, OS_CODE) tpl_disable_isr2_by_timing_protection (
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) isr2)
{
  if (isr2->enabled == DISABLED_BY_USER)
  {
    /* this case cannot happen but it is logically valid */
    isr2->enabled = DISABLED_BY_BOTH;
  }
  else
  {
    isr2->enabled = DISABLED_BY_TIMING_PROTECTION;
  }
}

FUNC(void, OS_CODE) tpl_enable_isr2_by_user (
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) isr2)
{
  if (isr2->enabled == DISABLED_BY_USER)
  {
    isr2->enabled = ENABLED;
  }
  if (isr2->enabled == DISABLED_BY_BOTH)
  {
    isr2->enabled = DISABLED_BY_TIMING_PROTECTION;
  }
}

FUNC(void, OS_CODE) tpl_enable_isr2_by_timing_protection (
    P2VAR(tpl_isr, AUTOMATIC, OS_APPL_DATA) isr2)
{
  if (isr2->enabled == DISABLED_BY_BOTH)
  {
    isr2->enabled = DISABLED_BY_USER;
  }
  if (isr2->enabled == DISABLED_BY_TIMING_PROTECTION)
  {
    isr2->enabled = ENABLED;
  }
}

FUNC(u8, OS_CODE) tpl_is_isr2_enabled (
    P2CONST(tpl_isr, AUTOMATIC, OS_APPL_DATA) isr2)
{
  VAR(u8, AUTOMATIC) result;

  if (isr2->enabled == ENABLED)
  {
    result = TRUE;
  }
  else
  {
    result = FALSE;
  }

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
    P2VAR(tpl_exec_common, AUTOMATIC, OS_APPL_DATA) ro = tpl_running_obj;
    VAR(tpl_isr_id, AUTOMATIC)  isr_id = (tpl_isr_id)INVALID_ISR;

    if (tpl_running_obj->static_desc->type != IS_ROUTINE)
    {
        isr_id = (tpl_isr_id)(ro->static_desc->id);
    }

    return isr_id;
}

/**
 * Disables the specified ISR
 *
 * see §8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE) tpl_disable_interrupt_source_service(
    VAR(tpl_isr_id, AUTOMATIC) isr_id)
{
    VAR(tpl_status, AUTOMATIC)  result = E_OK;

#ifndef NO_ISR
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr;
#endif

    CHECK_ISR_ID_ERROR(isr_id,result)

#ifndef NO_ISR
    IF_NO_EXTENDED_ERROR(result)
        /* get the isr */
        isr = tpl_isr_table[isr_id];
        tpl_disable_isr2_by_user(isr);
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

#ifndef NO_ISR
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr;
#endif

    CHECK_ISR_ID_ERROR(isr_id,result)

#ifndef NO_ISR
    IF_NO_EXTENDED_ERROR(result)
        /* get the isr */
        isr = tpl_isr_table[isr_id];
        tpl_enable_isr2_by_user(isr);
    IF_NO_EXTENDED_ERROR_END()
#endif

    return result;
}


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_isr_kernel.c  */

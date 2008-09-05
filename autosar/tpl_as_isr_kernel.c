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

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_as_isr_kernel.c  */

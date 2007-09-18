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

void tpl_disable_isr2_by_user (tpl_isr *isr2)
{
  if (isr2->enabled == DISABLED_BY_TIMING_PROTECTION)
    isr2->enabled = DISABLED_BY_BOTH;
  else
    isr2->enabled = DISABLED_BY_USER;
}

void tpl_disable_isr2_by_timing_protection (tpl_isr *isr2)
{
  if (isr2->enabled == DISABLED_BY_USER)
  {
    /* this case cannot happen but it is logically valid */
    isr2->enabled = DISABLED_BY_BOTH;
  }
  else
    isr2->enabled = DISABLED_BY_TIMING_PROTECTION;
}

void tpl_enable_isr2_by_user (tpl_isr *isr2)
{
  if (isr2->enabled == DISABLED_BY_USER)
    isr2->enabled = ENABLED;
  if (isr2->enabled == DISABLED_BY_BOTH)
    isr2->enabled = DISABLED_BY_TIMING_PROTECTION;
}

void tpl_enable_isr2_by_timing_protection (tpl_isr *isr2)
{
  if (isr2->enabled == DISABLED_BY_BOTH)
    isr2->enabled = DISABLED_BY_USER;
  if (isr2->enabled == DISABLED_BY_TIMING_PROTECTION)
    isr2->enabled = ENABLED;
}

u8 tpl_is_isr2_enabled (tpl_isr *isr2)
{
  u8 result;

  if (isr2->enabled == ENABLED)
    result = TRUE;
  else
    result = FALSE;

  return result;
}

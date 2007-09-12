/**
 * @file tpl_as_isr_kernel.c
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

void tpl_disable_isr2 (tpl_isr *isr2)
{
	isr2->enabled = FALSE;
}

void tpl_enable_isr2 (tpl_isr *isr2)
{
  isr2->enabled = TRUE;
}

u8 tpl_is_isr2_enabled (tpl_isr *isr2)
{
  return isr2->enabled; 
}

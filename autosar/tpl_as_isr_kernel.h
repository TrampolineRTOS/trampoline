/**
 * @file tpl_as_isr_kernel.h
 *
 * @section desc File description
 *
 * Trampoline autosar extension software ISR internals
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
 
#ifndef TPL_AS_ISR__KERNEL_H
#define TPL_AS_ISR__KERNEL_H

#include "tpl_os_definitions.h"
#include "tpl_os_it_kernel.h"

/**
 * @internal 
 *
 * @todo : document this
 *
 * @see #DisableInterruptSource
 */
extern void tpl_disable_isr2 (tpl_isr *isr2);

/**
 * @internal
 *
 * @todo : document this 
 *
 * @see #EnableInterruptSource
 */
extern void tpl_enable_isr2 (tpl_isr *isr2);

/**
 * @internal
 * 
 * @todo document this
 *
 * @retval FALSE this ISR2 is disabled
 * @retval TRUE this ISR2 is enabled 
 */
u8 tpl_is_isr2_enabled (tpl_isr *isr2);

#endif /* TPL_AS_ISR__KERNEL_H */


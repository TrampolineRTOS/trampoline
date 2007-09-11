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

#include "tpl_os_internal_types.h"

/**
 * @internal 
 *
 * @TODO : document this
 *
 * @see #DisableInterruptSource
 */
extern void tpl_disable_isr2 (tpl_exec_common *isr2);

/**
 * @internal
 *
 * @TODO : document this 
 *
 * @see #EnableInterruptSource
 */
extern void tpl_enable_isr2 (tpl_exec_common *isr2);

#endif /* TPL_AS_ISR__KERNEL_H */


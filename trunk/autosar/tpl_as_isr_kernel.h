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
 * ISR2 enabled state.
 *
 * @see #tpl_isr
 */
typedef enum
{
  DISABLED_BY_TIMING_PROTECTION, /**< disabled only by timing protection */
  DISABLED_BY_USER,              /**< disabled from API */
  DISABLED_BY_BOTH,              /**< disabled by timing protection then
                                      by user */
  ENABLED                        /**< ISR is enabled */
} tpl_isr2_enable_state;

/**
 * @internal 
 *
 * called directly by DisableInterruptSource
 *
 * @param isr2 the isr to disable
 *
 * @see #DisableInterruptSource
 */
extern void tpl_disable_isr2_by_user (tpl_isr *isr2);

/**
 * @internal 
 *
 * called by timing protection when an ISR2 reaches its
 * count limit
 *
 * @param isr2 the isr to disable
 */
extern void tpl_disable_isr2_by_timing_protection (tpl_isr *isr2);

/**
 * @internal
 *
 * called directly by EnableInterruptSource
 *
 * @see #EnableInterruptSource
 */
extern void tpl_enable_isr2_by_user (tpl_isr *isr2);

/**
 * @internal 
 *
 * called when a timeframe is reached
 */
extern void tpl_enable_isr2_by_timing_protection (tpl_isr *isr2);

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


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

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/**
 * @internal
 *
 * called directly by DisableInterruptSource
 *
 * @param isr2 the isr to disable
 *
 * @see #DisableInterruptSource
 */
extern FUNC(void, OS_CODE) tpl_disable_isr2_by_user (
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr2);

/**
 * @internal
 *
 * called by timing protection when an ISR2 reaches its
 * count limit
 *
 * @param isr2 the isr to disable
 */
extern FUNC(void, OS_CODE) tpl_disable_isr2_by_timing_protection (
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr2);

/**
 * @internal
 *
 * called directly by EnableInterruptSource
 *
 * @see #EnableInterruptSource
 */
extern FUNC(void, OS_CODE) tpl_enable_isr2_by_user (
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr2);

/**
 * @internal
 *
 * called when a timeframe is reached
 */
extern FUNC(void, OS_CODE) tpl_enable_isr2_by_timing_protection (
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr2);

/**
 * @internal
 *
 * @todo document this
 *
 * @retval FALSE this ISR2 is disabled
 * @retval TRUE this ISR2 is enabled
 */
FUNC(u8, OS_CODE) tpl_is_isr2_enabled (
    P2VAR(tpl_isr, OS_APPL_DATA, AUTOMATIC) isr2);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_ISR__KERNEL_H */


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

#ifndef TPL_AS_ISR_KERNEL_H
#define TPL_AS_ISR_KERNEL_H

#include "tpl_os_definitions.h"
#include "tpl_os_interrupt_kernel.h"

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

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * @internal
 *
 * Table of state of ISR2
 *
 * @see #tpl_isr2_enable_state
 */

#if ISR_COUNT > 0
extern VAR(tpl_isr2_enable_state, OS_VAR) tpl_isr2_enable_table[ISR_COUNT];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

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
extern FUNC(void, OS_CODE)
    tpl_disable_isr2_by_user(CONST(tpl_isr_id, AUTOMATIC) isr_id);

/**
 * @internal
 *
 * called by timing protection when an ISR2 reaches its
 * count limit
 *
 * @param isr2 the isr to disable
 */
extern FUNC(void, OS_CODE)
    tpl_disable_isr2_by_timing_protection(CONST(tpl_isr_id, AUTOMATIC) isr_id);

/**
 * @internal
 *
 * called directly by EnableInterruptSource
 *
 * @see #EnableInterruptSource
 */
extern FUNC(void, OS_CODE)
    tpl_enable_isr2_by_user(CONST(tpl_isr_id, AUTOMATIC) isr_id);

/**
 * @internal
 *
 * called when a timeframe is reached
 */
extern FUNC(void, OS_CODE)
    tpl_enable_isr2_by_timing_protection(CONST(tpl_isr_id, AUTOMATIC) isr_id);

/**
 * @internal
 *
 * @todo document this
 *
 * @retval FALSE this ISR2 is disabled
 * @retval TRUE this ISR2 is enabled
 */
FUNC(tpl_bool, OS_CODE)
tpl_is_isr2_enabled(CONST(tpl_isr_id, AUTOMATIC) isr_id);

/*
 * Get the ID of the currently running ISR.
 *
 * It returns the identifier of the currently running ISR
 * or INVALID_ISR when called from outside a running ISR.
 *
 * see §8.4.2 page 51 of
 * AUTOSAR/Specification of the Operating System v2.0.1
 */
FUNC(tpl_isr_id, OS_CODE) tpl_get_isr_id_service(void);

/**
 * Disables the specified ISR
 *
 * see §8.4.20 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE)
tpl_disable_interrupt_source_service(VAR(tpl_isr_id, AUTOMATIC) isr_id);

/**
 * Enables the specified ISR
 *
 * see §8.4.21 of AUTOSAR/Specification of the Operating System v2.1.0
 */
FUNC(tpl_status, OS_CODE)
tpl_enable_interrupt_source_service(VAR(tpl_isr_id, AUTOMATIC) isr_id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_AS_ISR_KERNEL_H */

/**
 * @file tpl_os_interrupts.h
 *
 * @section desc File description
 *
 * Trampoline interrupt service routines management
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation
 * Trampoline is protected by the French intellectual property law.
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

#ifndef TPL_OS_IT_KERNEL_H
#define TPL_OS_IT_KERNEL_H

#include "tpl_os_application_def.h"
#include "tpl_os_internal_types.h"

/**
 * An ISR helper is a function which should return true
 * if the related ISR decides to handle the interrupt
 *
 * This type is not intended to be used alone.
 *
 * @see #TPL_ISR_STATIC
 */
typedef P2FUNC(tpl_bool, OS_APPL_CODE, tpl_isr_helper)(void);

struct TPL_ISR;

/**
 * @struct TPL_ISR_STATIC
 *
 * Static descriptor of a category 2 interrupt service routine
 */
struct TPL_ISR_STATIC {
    CONST(tpl_isr_helper, AUTOMATIC)  helper;             /**<  pointer to a helper function used
                                                                to search for hardware that
                                                                launched the interrupt              */
    struct P2VAR(TPL_ISR, OS_APPL_DATA, AUTOMATIC) next;  /**<  when there is several handler for
                                                                the same interrupt priority, the
                                                                tpl_isr are chained. In this case.
                                                                Trampoline uses the helper to check
                                                                what handler will be called for the
                                                                interrupt.                          */
};

/**
 * @typedef tpl_isr_static
 *
 * This is an alias for #TPL_ISR_STATIC structure
 *
 * @see #TPL_ISR_STATIC
 */
typedef struct TPL_ISR_STATIC tpl_isr_static;

/**
 * @struct TPL_ISR
 *
 * This structure glues together a common executable
 * descriptor (#tpl_exec_common) and a pointer to a tpl_isr_static
 */
struct TPL_ISR {
    VAR(tpl_exec_common, AUTOMATIC)                 exec_desc;    /**<  common descriptor                 */
    P2CONST(tpl_isr_static, OS_CONST, AUTOMATIC)    static_desc;  /**<  pointer to the static desc of the
                                                                        isr                               */
#ifdef WITH_AUTOSAR
    VAR(tpl_bool, AUTOMATIC)                        enabled;      /**< FALSE if disabled, TRUE if enabled
                                                                       (see #tpl_isr2_enable_state) */
#endif
};

/**
 * @typedef tpl_isr
 *
 * This is an alias for #TPL_ISR structure
 *
 * @see #TPL_ISR
 */
typedef struct TPL_ISR tpl_isr;


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * This is the dispatcher of interrupts. It should be called by
 * the root interrupt handler with an ISR identifier
 *
 * @param interrupt service routine identifier
 */
FUNC(void, OS_CODE) tpl_central_interrupt_handler(CONST(u16, AUTOMATIC) id);

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* TPL_OS_IT_KERNEL_H */

/* End of file tpl_os_it_kernel.h */

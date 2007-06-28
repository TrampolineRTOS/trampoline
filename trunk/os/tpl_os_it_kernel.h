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

#include "tpl_os_internal_types.h"

/**
 * An ISR helper is a function which should return true
 * if the related ISR decides to handle the interrupt
 *
 * This type is not intended to be used alone.
 *
 * @see #TPL_ISR_STATIC
 */
typedef tpl_bool (*tpl_isr_helper)(void);

struct TPL_ISR;

/**
 * @struct TPL_ISR_STATIC
 *
 * Static descriptor of a category 2 interrupt service routine 
 */
struct TPL_ISR_STATIC {
    const tpl_isr_helper  helper; /**<  pointer to a helper function used
                                        to search for hardware that
                                        launched the interrupt              */
    struct TPL_ISR  *next;        /**<  when there is several handler for
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
    tpl_exec_common exec_desc;      /**<  common descriptor                 */
    tpl_isr_static  *static_desc;   /**<  pointer to the static desc of the
                                          isr                               */
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
#include "Memmap.h"
/**
 * This is the dispatcher of interrupts. It should be called by
 * the root interrupt handler with an ISR identifier (usually the ISR priority)
 *
 * @param interrupt service routine identifier
 */
void tpl_central_interrupt_handler(const u16 id);

#define OS_STOP_SEC_CODE
#include "Memmap.h"

#endif /* TPL_OS_IT_KERNEL_H */

/* End of file tpl_os_it_kernel.h */

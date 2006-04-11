/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline interrupt service routines management
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_OS_INTERRUPTS_H__
#define __TPL_OS_INTERRUPTS_H__

#include "tpl_os_internal_types.h"

typedef bool (*tpl_isr_helper)(void);

struct TPL_ISR;

struct TPL_ISR_STATIC {
    tpl_isr_helper  helper; /*  pointer to a helper function used to search
                                for hardware that launched the interrupt        */
    struct TPL_ISR  *next;  /*  when there is several handler for the same
                                interrupt priority, the tpl_isr are chained.
                                In this case. Trampoline uses the helper to
                                check what handler will be called for the
                                interrupt                                       */
};

typedef struct TPL_ISR_STATIC tpl_isr_static;

/*
 * tpl_isr glues together a common executable
 * descriptor and a pointer to a tpl_isr_static
 */
struct TPL_ISR {
    tpl_exec_common exec_desc;      /*  common descriptor                       */
    tpl_isr_static  *static_desc;   /*  pointer to the static desc of the isr   */
};

typedef struct TPL_ISR tpl_isr;

void tpl_central_interrupt_handler(unsigned int id);

#endif

/**
 * @file tpl_interrupts.S
 *
 * @section descr File description
 *
 * Low level functions to enable and disable interrupts.
 * These functions are called by 6 services :
 * - tpl_disable_all_interrupts_service
 * - tpl_enable_all_interrupts_service
 * - tpl_suspend_all_interrupts_service
 * - tpl_resume_all_interrupts_service
 * - tpl_suspend_os_interrupts_service
 * - tpl_resume_os_interrupts_service
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c)
 * CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

.syntax unified
.thumb

#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
#include "tpl_cortex_definitions.h"

/*-----------------------------------------------------------------------------
 * the code starts here
 */

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/*-----------------------------------------------------------------------------
 * A WORD ABOUT INTERRUPT PRIORITY for Cortex M0
 * 4 levels of priority are available
 *-----------------------------------------------------------------------------
 * Prioritities are set in the following order (from lower urgency to higher
 * urgency):
 *
 *   +-----------------------------------+
 *   |            Tasks, ISR2            | Thread mode
 *   +-----------------------------------+
 *   |      COUNTERS, ISR2 Handlers      | <- OS_ISR_PRIO (3)
 *   +-----------------------------------+
 *   |              ISR1 1               | (2)
 *   +-----------------------------------+
 *   |              ISR1 n               | <- ISR1_IT_PRIO (1)
 *   +-----------------------------------+
 *   |               SVC                 | <- KERNEL_PRIO (0)
 *   +-----------------------------------+
 *
 * DISCUSSION.
 *
 * With priority of SVC set at 0, the kernel cannot be interrupted by ISR1.
 * The SVC handler is only called by Tasks and ISR2 that execute in thread
 * mode.
 *
 * When disabling all interrupts, the BASEPRI register is set to 1.
 * This prevents interruptions by ISR1 and, since the SVC priority is 0, OS
 * services can be called from thread mode.
 */

/*=============================================================================
 * tpl_disable_interrupts disables all the interrupts by setting the BASEPRI
 * register to ISR1_IT_PRIO.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_disable_interrupts
 .type   tpl_disable_interrupts, %function

tpl_disable_interrupts:
    /*-------------------------------------------------------------------------
     * Set BASEPRI to ISR1_IT_PRIO.
     */
    movs r0,#ISR1_IT_PRIO
    msr  basepri,r0

    bx   lr

/*=============================================================================
 * tpl_enable_interrupts enables all the interrupts by setting BASEPRI to
 * OS_ISR_PRIO.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_enable_interrupts
 .type   tpl_enable_interrupts, %function

tpl_enable_interrupts:
    /*-------------------------------------------------------------------------
     * set BASEPRI to OS_ISR_PRIO
     */
    movs r0,#OS_ISR_PRIO
    msr  basepri,r0

    bx   lr

/*-----------------------------------------------------------------------------
 * the code ends here
 */

 #define OS_STOP_SEC_CODE
 #include "tpl_as_memmap.h"

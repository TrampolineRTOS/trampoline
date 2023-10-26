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
 * A WORD ABOUT INTERRUPT PRIORITY
 *-----------------------------------------------------------------------------
 * Prioritities are set in the following order (from lower urgency to higher
 * urgency):
 *
 *   +-----------------------------------+
 *   |            Tasks, ISR2            | Thread mode
 *   +-----------------------------------+
 *   |   SVCe, COUNTERS, ISR2 Handlers   | <- KERNEL_PRIO
 *   +-----------------------------------+
 *   |              ISR1 1               |
 *   +-----------------------------------+
 *   |               ...                 |
 *   +-----------------------------------+
 *   |              ISR1 n               | <- ISR1_IT_PRIO
 *   +-----------------------------------+
 *   |              SVCd                 | <- 0
 *   +-----------------------------------+
 *
 * At SVCe, the priority used for SVC when all interrupts are not disabled is
 * KERNEL_PRIO
 * At SVCd, the priority used for SVC when all interrupts are disabled is 0
 *
 * DISCUSSION.
 *
 * When a task or an ISR2 Calls DisableAllInterrupts, it does so with SVCe
 * having the KERNEL_PRIO priority. The service set the BASEPRI register to 1.
 * As a result a SVC having the KERNEL_PRIO priority cannot be called anymore
 * (a Hardfault would occur). So, to be able to call EnableAllInterrupt,
 * the SVC need to have a priority greater (value lower) than 1.
 * So the SVCd priority is set to 0.
 * tpl_disable_interrupt set the SVC priority to 0 and tpl_enable_interrupts
 * reset it to KERNEL_PRIO.
 *
 * 3 modes are supported in interrupt enabling/desabling.
 *
 * 1 - nothing is disabled at all. OS ISR (ISR2) and ISR (ISR1) are handled
 *     The case correspond to BASEPRI set to 0 (BASEPRI disabled)
 * 2 - OS ISR (ISR2) are disabled. ISR (ISR1) are handled. BASEPRI is not
 *     not changed but the ISR2 are disabled.
 * 3 - ISR (ISR1) are disabled. This case corresponds to BASEPRI set to
 *     ISR1_IT_PRIO. In this last mode OS ISR may be enable of not.
 */

/*-----------------------------------------------------------------------------
 * SHPR2 contains the priority of the SVC. This is in the leftmost byte
 */
.equ SHPR2, 0xE000ED1C

/*=============================================================================
 * tpl_disable_interrupts disables all the interrupts by setting the BASEPRI
 * register to the ISR1_IT_PRIO.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_disable_interrupts
 .type   tpl_disable_interrupts, %function

tpl_disable_interrupts:
    /*-------------------------------------------------------------------------
     * Whatever state we are in and whatever the tpl_isr2_disabled value is,
     * the new state is ISR1_IT_PRIO and tpl_isr2_disabled is not set, so
     * no test is done
     */
    movs r0,#ISR1_IT_PRIO
    msr  basepri,r0

    /*-------------------------------------------------------------------------
     * Set the priority of the SVC to 0
     */
    ldr  r0,=SHPR2
    ldr  r1,[r0]
    ldr  r2,=0x00FFFFFF
    ands r1,r2
    str  r1,[r0]

    bx   lr

/*=============================================================================
 * tpl_enable_interrupts enables all the interrupts by setting the BASEPRI
 * register to the 0.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_enable_interrupts
 .type   tpl_enable_interrupts, %function

tpl_enable_interrupts:
    /*-------------------------------------------------------------------------
     * 1 - Reset the priority of SVC to KERNEL_PRIO
     */
    ldr  r0,=SHPR2
    ldr  r1,[r0]
    ldr  r2,=KERNEL_PRIO_SHPR2
    orrs r1,r2
    str  r1,[r0]

    /*-------------------------------------------------------------------------
     * 2 - reset BASEPRI to 0
     */
    movs  r0,#0
    msr   basepri,r0

    bx    lr

/*-----------------------------------------------------------------------------
 * the code ends here
 */

 #define OS_STOP_SEC_CODE
 #include "tpl_as_memmap.h"

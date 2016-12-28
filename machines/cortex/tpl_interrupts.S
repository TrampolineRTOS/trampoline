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
 *   +----------------------------------+
 *   |            Tasks, ISR2           |
 *   +----------------------------------+
 *   |           ISR2 handlers          | <- ISR2_IT_PRIO
 *   +----------------------------------+
 *   | SVC, COUNTERS (Systick included) | <- SVC_PRIO
 *   +----------------------------------+
 *   |              ISR1 1              |
 *   +----------------------------------+
 *   |               ...                |
 *   +----------------------------------+
 *   |              ISR1 n              | <- ISR1_IT_PRIO
 *   +----------------------------------+
 *
 * 3 modes are supported in interrupt enabling/desabling.
 *
 * 1 - nothing is disabled at all. OS ISR (ISR2) and ISR (ISR1) are handled
 *     The case correspond to BASEPRI set to 0 (BASEPRI disabled)
 * 2 - OS ISR (ISR2) are disabled. ISR (ISR1) are handled. This case
 *     corresponds to BASEPRI set to ISR2_IT_PRIO
 * 3 - ISR (ISR1) are disabled. This case corresponds to BASEPRI set to
 *     ISR1_IT_PRIO
 *
 * The state is determined by the value stored in BASEPRI (0, ISR2_IT_PRIO and
 * ISR1_IT_PRIO, and a boolean to remember if ISR2 was disabled or not.
 * The state machine works as follow:
 *
 *                                |
 *                                | isr2_dis:=false
 *                                |
 *                                v
 *                         +------+------+
 *                 +-------+             +-------+
 *       Enable_OS |       | Enabled (0) |       | Enable
 *                 +------>+             +<------+
 *                         ++-+------+-+-+
 *                          | ^      | |
 *           Disable_OS/    | |      | +------------+
 *           isr2_dis:=true | |      |              |
 *          +---------------+ |      +-----------+  |
 *          |                 | isr2_dis==false/ |  | Disable
 *          |  +---------------           Enable |  |
 *          |  | Enable_OS/                      |  |
 *          |  | isr2_dis:=false                 |  | +-------+ Enable_OS/
 *          v  |                                 |  v |       | isr2_dis:=false
 *       +--+--+--------+    Disable     +-------+--+-+-+     |
 *       |              +--------------->+              +<----+
 *       | ISR2_IT_PRIO |                | ISR1_IT_PRIO |
 *    +->|              +<---------------+              +<----+
 *    |  +----+-----+---+ isr_dis==true/ +---+-----+--+-+     | Disable_OS/
 *    |    |  ^     |     Enable             ^     |  |       | isr2_dis:=true
 *    +----+  |     |                        |     |  +-------+
 *  Enable    +-----+                        +-----+
 *           Disable_OS                      Disable
 *
 */

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
     * Whatever state we are in and whatever the is2_dis value is,
     * the new state is ISR1_IT_PRIO and is2_dis is not set, so
     * no test is done
     */
    movs r0,#ISR1_IT_PRIO
    msr  basepri,r0
    bx   lr

/*=============================================================================
 * tpl_enable_interrupts enables all the interrupts by setting the BASEPRI
 * register to the 0 or to ISR2_IT_PRIO according to the initial state.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_enable_interrupts
 .type   tpl_enable_interrupts, %function

tpl_enable_interrupts:
    /*-------------------------------------------------------------------------
     * 1 - Does something only if we are in ISR1_IT_PRIO. So we get the BASEPRI
     *     to check the state.
     */
    mrs  r0,basepri
    cmp  r0,#ISR1_IT_PRIO
    bne  tpl_enable_interrupts_do_nothing

    /*-------------------------------------------------------------------------
     * 2 - Check the tpl_isr2_disabled variable
     */
    ldr  r0,=tpl_isr2_disabled
    cmp  r0,#0
    beq  tpl_enable_interrupts_isr2_not_disabled

    /*-------------------------------------------------------------------------
     * 3 - ISR2 are disabled so we go in the ISR2_IT_PRIO state
     */
    movs r0,#ISR2_IT_PRIO
    msr  basepri,r0
    bx   lr

tpl_enable_interrupts_isr2_not_disabled:
    /*-------------------------------------------------------------------------
     * 3 - ISR2 are NOT disabled so we go in the 0 state
     */
    movs r0,#0
    msr  basepri,r0

tpl_enable_interrupts_do_nothing:
    bx   lr

/*=============================================================================
 * tpl_disable_os_interrupts disables the OS interrupts by setting the BASEPRI
 * register to the ISR2_IT_PRIO or staying in ISR1_IT_PRIO.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_disable_os_interrupts
 .type   tpl_disable_os_interrupts, %function

tpl_disable_os_interrupts:
    /*-------------------------------------------------------------------------
     * 1 - Whatever state we are in, is2_dis is set to true.
     */
    movs r0,#1
    ldr  r1,=tpl_isr2_disabled
    str  r0,[r1]

    /*-------------------------------------------------------------------------
     * 2 - Check the state, if it is 0, it is changed to ISR2_IT_PRIO
     */
    mrs  r0,basepri
    cmp  r0,#0
    bne  tpl_disable_os_interrupts_no_change
    movs r0,#ISR2_IT_PRIO
    msr  basepri,r0

tpl_disable_os_interrupts_no_change:
    bx   lr

/*=============================================================================
 * tpl_enable_os_interrupts enables the OS interrupts by setting the BASEPRI
 * register to the ISR2_IT_PRIO or staying in ISR1_IT_PRIO.
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_enable_os_interrupts
 .type   tpl_enable_os_interrupts, %function

tpl_enable_os_interrupts:
    /*-------------------------------------------------------------------------
     * 1 - Whatever state we are in, is2_dis is set to false.
     */
    movs r0,#0
    ldr  r1,=tpl_isr2_disabled
    str  r0,[r1]

    /*-------------------------------------------------------------------------
     * 2 - Check the state, if it is ISR2_IT_PRIO, it is changed to 0
     */
    mrs  r0,basepri
    cmp  r0,#ISR2_IT_PRIO
    bne  tpl_enable_os_interrupts_no_change
    movs r0,#0
    msr  basepri,r0

tpl_enable_os_interrupts_no_change:
    bx   lr


/*-----------------------------------------------------------------------------
 * the code ends here
 */

 #define OS_STOP_SEC_CODE
 #include "tpl_as_memmap.h"

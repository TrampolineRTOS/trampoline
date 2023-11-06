/**
 * @file tpl_startup.S
 *
 * @section desc File description
 *
 * Startup code called just after reset of cpu. This code then jumb to the
 * tpl_continue_reset_handler
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
 * $Author: DavidGarriou $
 * $URL: https://github.com/TrampolineRTOS/trampoline $
 */


.syntax unified
.thumb

/**
 * @internal
 *
 * tpl_reset_handler
 *
 * tpl_reset_handler is the first function called after a cpu reset.
 * This function must be referenced at the index 1 of the vector table.
 *
 * We will use PSP (Process Stack Pointer) and MSP (Main Stack Pointer).
 * The cpu starts in privileged thread mode using MSP.
 * 1 - Copy MSP into PSP
 * 2 - Switch to use PSP
 * Just after the modification of CONTROL register (set to use both PSP and MSP)
 * the cpu will use PSP. So we MUST initialize PSP with a temporary value otherwise
 * the startup will crash.
 * We can initialize PSP with the current value of MSP because PSP will be updated
 * with the stack of running processes. The first process to run is the idle task.
 *
 * @param
 */

 #define OS_START_SEC_CODE
 #include "tpl_as_memmap.h"

	.global tpl_reset_handler
	.type tpl_reset_handler, %function

tpl_reset_handler:
    /* Copy MSP into PSP */
    mrs  r0, msp
    msr  psp, r0
    /* Switch to use PSP, privileged state */
    movs r0, #2
    msr  control, r0
    /* Instruction Synchronization Barrier */
    isb
    /* Branch to the subsequent reset handler code */
    ldr  r0, =tpl_continue_reset_handler
    bx   r0

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

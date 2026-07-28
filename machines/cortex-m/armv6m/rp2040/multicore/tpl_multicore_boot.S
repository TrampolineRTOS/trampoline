/**
 * @file tpl_startup.S
 *
 * @section desc File description
 *
 * Startup code called just after the core0 wake up others core. This code then jumb to the
 * main
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
 * $Author: Perret Florian
 * $URL: https://github.com/TrampolineRTOS/trampoline $
 */


.syntax unified
.thumb

/**
 * @internal
 *
 * tpl_multicore_boot_handler
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
 * We create space for PSP since in multicore there is system call before StartOS 
 * and we need to be able to return to main so MSP and PSP can't corrup each others.
 *
 * @param
 */
#include "tpl_os_definitions.h"
#include "tpl_app_define.h"
#if NUMBER_OF_CORES > 1

 #define OS_START_SEC_CODE
 #include "tpl_as_memmap.h"

	.global tpl_multicore_boot_handler
	.type tpl_multicore_boot_handler, %function

tpl_multicore_boot_handler:
    /* Copy MSP - 248 into PSP */
    mrs  r0, msp
    subs r0,#248
    msr  psp, r0
    /* Switch to use PSP, privileged state */
    movs r0, #2
    msr  control, r0
    /* Instruction Synchronization Barrier */
    isb
    /* Branch to the subsequent reset handler code */
    ldr  r0, =main
    bx   r0

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#endif

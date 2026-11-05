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
 * A WORD ABOUT INTERRUPT MASKING for Cortex M0/M0+ (ARMv6-M)
 *-----------------------------------------------------------------------------
 * Unlike ARMv7-M architectures, the Cortex-M0+ does NOT implement the 
 * BASEPRI register. Therefore, priority-based interrupt masking is not 
 * possible at the hardware level.
 *
 * The only available mechanism to protect critical sections is the PRIMASK 
 * register, which is manipulated using the 'cpsid i' and 'cpsie i' instructions.
 * 
 * When 'tpl_disable_interrupts' is called, it sets PRIMASK to 1. 
 * This disables ALL configurable exceptions and interrupts globally, 
 * regardless of their priority level. Only the Non-Maskable Interrupt (NMI) 
 * and HardFault exceptions can bypass this mask.
 *
 * Consequence for the OS:
 * We operate on an "all-or-nothing" basis. It is no longer possible to let 
 * high-priority interrupts (ISR1) preempt the kernel during its critical 
 * sections. All ISRs and Counters are delayed until PRIMASK is cleared.
 *-----------------------------------------------------------------------------*/

/*=============================================================================
 * tpl_disable_interrupts disables all the interrupts by setting primask to 1
 * 
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_disable_interrupts
 .type   tpl_disable_interrupts, %function

tpl_disable_interrupts:


    cpsid i

    bx   lr

/*=============================================================================
 * tpl_enable_interrupts enables all the interrupts by setting primask to 0
 * 
 *
 * Scratch registers are usable : r0-r3 and r12. r12 is not used to be
 * compatible with armv6m general purpose registers access restrictions.
 */
 .global tpl_enable_interrupts
 .type   tpl_enable_interrupts, %function

tpl_enable_interrupts:

    cpsie i
    
    bx lr

/*-----------------------------------------------------------------------------
 * the code ends here
 */

 #define OS_STOP_SEC_CODE
 #include "tpl_as_memmap.h"

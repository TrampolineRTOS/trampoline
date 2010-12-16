/**
 * @file tpl_system_call.S
 *
 * @section descr File description
 *
 * System calls handling.
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
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

.equ  NO_NEED_SWITCH , 0
.equ  NEED_SWITCH , 1
.equ  NEED_SAVE , 2

.include "syscallcount.inc"

.syntax unified
.include "tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/* Main system call handler
 *
 * We take care to not alter callee saved registers
 * which are all except r0-r3 (EABI convention).
 *
 * We do not use r3 because it is used to give the service number
 * in a system call. After dispatching, r3 can be altered.
 *
 * This exception to EABI conventions is specific to system call
 * mechanism.
 */
/*.global tpl_primary_syscall_handler
tpl_primary_syscall_handler:
*/
	.global SVC_Handler
    .type   SVC_Handler, %function
SVC_Handler:    
   /**********************
    * KERNEL ENTER STAGE *
    **********************
    * The stack generated after this stage looks like this :
    *
    *         |---------------------------|
    *         | task's return address     |
    * SP+16-> |---------------------------|
    *         | r2 saved value            |
    * SP+12-> |---------------------------|
    *         | r1 saved value            |
    * SP+8 -> |---------------------------|
    *         | r0 saved value            |
    * SP+4 -> |---------------------------|
    *         | spsr #0                   |
    * SP   -> |---------------------------|
    *
    * The SPSR is pushed to make possible to nest system calls
    */

    /* first we disable all IRQ (IRQ are ISR cat. 2, FIQ are
     * ISR cat. 1) to prevent any preemption while in kernel
     * mode.
     */
    /*msr cpsr_c, #(CPSR_IRQ_LOCKED | CPSR_SVC_MODE)*/

    /* We save R0 to R2 here as they may contain system call
     * parameter. We save LR as the task's return address.
     * R3 is not saved as it is known to never being used as
     * system call parameter (and contains system call number).
     */
    /*stmfd sp!, {r0-r2,lr}*/

    /* System calls should be reentrant, so we have to
     * save the SPSR on the stack. */
    /*mrs r1, spsr
    stmfd sp!, {r1}*/
    
    /* manage reentrance of kernel */
    ldr r1, =nested_kernel_entrance_counter
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]

    /* reset tpl_kern variables */
    ldr r1, =tpl_kern
    mov r2, #NO_NEED_SWITCH
    strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]

   /*********************************
    * SYSTEM CALL DISPATCHING STAGE *
    *********************************/
    /* WARNING : r3 should not be altered until here
     * as it is used to give the service identifier while calling swi
     */
    cmp r3, #SYSCALL_COUNT
    bhs invalid_service_id

    /* get the appropriate system call address into R3 */
    ldr r1, =tpl_dispatch_table
    /*ldr r3, [r1, r3, LSL #2] TODO */
	lsl r3,#2
	ldr r3,[R1,R3]

    /* pop registers values from the stack without altering
     * the stack pointer */
	mrs r2,psp
    ldmia r2, {r0-r2}
	push {lr}

    /* call the service  */
    blx r3

	pop {lr}
  /* we save back returned value (r0-r1) into r0-r1 saved values on the stack */
	mrs r2,psp
    stmia r2, {r0-r1}
 
    /* check if context switch is needed (requested by system service) */
    ldr r2, =tpl_kern
    ldrb r2, [r2, #TPL_KERN_OFFSET_NEED_SWITCH]
    cmp r2, #NO_NEED_SWITCH
    beq swi_no_context_switch_exit

    /* do not switch context if nested kernel entrance */
    ldr r2, =nested_kernel_entrance_counter
    ldr r2, [r2]
    cmp r2, #1
    bhi swi_no_context_switch_exit

   /***************************
    * CONTEXT SWITCHING STAGE *
    ***************************/
context_switch_swi:
  /* load the tpl_kern base address */
    ldr r0, =tpl_kern

    /* do we need to save the context ? if not, jump to load */
    ldrb r2, [r0, #TPL_KERN_OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_swi

    /*
     * SAVES OLD CONTEXT
     */
save_context_swi:

    /* get the context block address */
    ldr r2, [r0, #TPL_KERN_OFFSET_S_OLD] /* get the address of the context bloc */
    ldr r2, [r2]                /* jump to context bloc (from static descriptor) */
    stmia r2, {r4-r11}
	mrs r0,psp
	str r0 ,[r2,#4*8]
  
    b load_context_swi       /* jump to suite */

    /* only executed if context saving step has not been done */
skip_save_context_swi:
 
    /*
     * LOADS NEW CONTEXT
     */
load_context_swi:

  /* We updates kernel reentrance counter while registers are freely
   * usable and as we know we won't enter in kernel again (IRQ locked and
   * no SWI can occur) */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]

    /* Get the context block address.
     *
     * We use r14 as it will be restored separatly and later, it
     * is useful for the following ldmia instruction
     */
    ldr r0, [r0, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr r0, [r0]                   /* jump to context bloc (from static descriptor) */

	ldmia r0 , {r4-r11}
  	ldr r0 , [r0,#(4*8)]
	msr psp,r0


    /********************************************
     * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
     ********************************************/
invalid_service_id:  /* currently, if invalid service id is specified, we do nothing */
swi_no_context_switch_exit:

  /* manage reentrance of kernel */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]


	bx lr
#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_system_call.S */

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

	.syntax unified
	.thumb

	.equ  NO_NEED_SWITCH_NOR_SCHEDULE , 0
	.equ  NO_NEED_SWITCH , 0
	.equ  NEED_SWITCH , 1
	.equ  NEED_SAVE , 2
	.equ  ARM_INITIAL_EXC_RETURN, 0xFFFFFFF9

/*.include "syscallcount.inc"*/
	.equ SYSCALL_COUNT , 28

#include "tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

	.extern nested_kernel_entrance_counter
	.extern tpl_kern
	.extern tpl_dispatch_table

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

/*
	---------------
	| WITHOUT FPU |
        ---------------
	STACK BEFORE SYSTEM CALL, BEFORE PUSHING CONTEXT

*          |---------------------------|
*          |                           |
* SP    -> |---------------------------|

 	STACK AFTER PUSHING CONTEXT

*          |---------------------------|
*          |                           | |
*          |---------------------------| |<- Pre-IRQ Top of Stack
*          | {aligner}                 | |
* SP+32 -> |---------------------------|
*          | xPSR                      |
* SP+28 -> |---------------------------|
*          | PC                        |
* SP+24 -> |---------------------------|
*          | LR return address         |
* SP+20 -> |---------------------------|
*          | R12                       |
* SP+16 -> |---------------------------|
*          | R3 service number         |
* SP+12 -> |---------------------------|
*          | R2                        |
* SP+8  -> |---------------------------|
*          | R1                        |
* SP+4  -> |---------------------------|
*          | R0                        |
* SP    -> |---------------------------| <- IRQ Top of stack

        ---------------
	| WITH FPU    |
        ---------------
	STACK BEFORE SYSTEM CALL, BEFORE PUSHING CONTEXT

*          |---------------------------|
*          |                           |
* SP    -> |---------------------------|

 	STACK AFTER PUSHING CONTEXT

*          |---------------------------|
*          |                           | |
*          |---------------------------| |<- Pre-IRQ Top of Stack
*          | {aligner}                 | |
*          |---------------------------|
*          | FPSCR                     |
*          |---------------------------|
*          | S15                       |
*          |---------------------------|
*          | S14                       |
*          |---------------------------|
*          | S13                       |
*          |---------------------------|
*          | S12                       |
*          |---------------------------|
*          | S11                       |
*          |---------------------------|
*          | S10                       |
*          |---------------------------|
*          | S9                        |
*          |---------------------------|
*          | S8                        |
*          |---------------------------|
*          | S7                        |
*          |---------------------------|
*          | S6                        |
*          |---------------------------|
*          | S5                        |
*          |---------------------------|
*          | S4                        |
*          |---------------------------|
*          | S3                        |
*          |---------------------------|
*          | S2                        |
*          |---------------------------|
*          | S1                        |
*          |---------------------------|
*          | S0                        |
* SP+32 -> |---------------------------|
*          | xPSR                      |
* SP+28 -> |---------------------------|
*          | PC                        |
* SP+24 -> |---------------------------|
*          | LR return address         |
* SP+20 -> |---------------------------|
*          | R12                       |
* SP+16 -> |---------------------------|
*          | R3 service number         |
* SP+12 -> |---------------------------|
*          | R2                        |
* SP+8  -> |---------------------------|
*          | R1                        |
* SP+4  -> |---------------------------|
*          | R0                        |
* SP    -> |---------------------------| <- IRQ Top of stack

*/
	.global tpl_primary_syscall_handler
	.type   tpl_primary_syscall_handler, %function
tpl_primary_syscall_handler:
    
	/* manage reentrance of kernel */
	ldr r1, =nested_kernel_entrance_counter
	ldr r2, [r1]
	add r2, r2, #1
	str r2, [r1]

	/* reset tpl_kern variables */ /* <! DGAR POURQUOI ? !> */
	ldr r1, =tpl_kern
	mov r2, #NO_NEED_SWITCH_NOR_SCHEDULE
	strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
	strb r2, [r1, #TPL_KERN_OFFSET_NEED_SCHEDULE]

	/*********************************
	* SYSTEM CALL DISPATCHING STAGE *
	*********************************/
	/* WARNING : r3 should not be altered until here
	* as it is used to give the service identifier while calling the system call ( PendSV on Cortex-M4 )
	*/
	cmp r3, #SYSCALL_COUNT
	bhs invalid_service_id

	/* get the appropriate system call address into R3 */
	ldr r1, =tpl_dispatch_table
	ldr r3, [r1, r3, LSL #2]

	/* pop registers values from the stack without altering the stack pointer */ /* <! DGAR POURQUOI ? > */
	mrs r2,PSP
	ldmia r2, {r0-r2}

	push {lr} /* save lr onto stack */
	/* call the service  */
	blx r3
	
	pop {lr} /* get lr back from stack */
	
	/* we save back returned value (r0-r1) into r0-r1 saved values on the stack */ /* <! DGAR POURQUOI ? ET POURQUOI r0-r1 au lieu de r0-r2 > */
	//mrs r2,PSP
	//stmia r2, {r0-r1}
 
    /* Do we need to switch context ? */
	/* (requested by system service) */

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
    /* Context is saved, so the value of r3 will be 1 */
    mov r3, #1
    /* get the context block address */
    ldr r2, [r0, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr r2, [r2]             /* jump to context bloc (from static descriptor) */
    mov lr, sp
    stmia r2, {r4-r11, lr}       /* Save r4-r11 and sp into context bloc */

	b load_context_swi       /* jump to suite */

	/* only executed if context saving step has not been done */
skip_save_context_swi:
    /* Context is not saved, so the value of r3 will be 0 */
    mov r3, #0
 
	/*
	* LOADS NEW CONTEXT
	*/
load_context_swi:

	/* First call tpl_run_elected with the value of tpl_kern.need_switch
	 * and get the value of the elected task.
	 * tpl_kern.need_switch (stored into r3) is copied into r0
	 */
	mov r0, r3
	push {lr} /* save lr onto stack */

	bl tpl_run_elected
    
	pop {lr} /* get lr back from stack */
	/* Keep the returned value into r3 */
	mov r3, r0
	
	/* We update kernel reentrance counter while registers are freely
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
    ldr r0, =tpl_kern
    ldr lr, [r0, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr lr, [lr]                   /* jump to context bloc (from static descriptor) */

    ldmia lr, {r4-r11}      /* loads from lr base register into r0 to r12 */
//	ldr lr, [lr, #(14 * 4)] /* loads from lr+14*4 (lr) to r5 */
//	ldr lr, [lr, #(15 * 4)] /* loads from lr+15*4 (pc) to r6 */

    /* Switch to new task's SP */
    /* loads SP value into r0 */
    ldr r0, [lr, #(8 * 4)]

    /*
    * Dans le cas où on utilise une seule pile : MSP
    * Si on utilise les 2 piles alors modifier ce code
    */
    /*
     * Get the pushed value of lr when entering the exception handler
	 * 0xFFFFFFF1 - Return to Handler mode, exception return uses non-floating-point state from the MSP and execution uses MSP after return.
	 * 0xFFFFFFF9 - Return to Thread mode, exception return uses non-floating-point state from MSP and execution uses MSP after return.
	 * 0xFFFFFFFD - Return to Thread mode, exception return uses non-floating-point state from the PSP and execution uses PSP after return.
	 * 0xFFFFFFE1 - Return to Handler mode, exception return uses floating-point-state from MSP and execution uses MSP after return.
	 * 0xFFFFFFE9 - Return to Thread mode, exception return uses floating-point state from MSP and execution uses MSP after return.
	 * 0xFFFFFFED - Return to Thread mode, exception return uses floating-point state from PSP and execution uses PSP after return.
	 */
//	pop {lr}
	mov lr, #ARM_INITIAL_EXC_RETURN
	/* Changes the SP now */
    /* Writes MSP with value of r0 */
    msr msp, r0

	b tpl_primary_syscall_handler_exit

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

tpl_primary_syscall_handler_exit:
	cpsie i

	bx lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_system_call.S */

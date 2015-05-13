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

/*.include "syscallcount.inc"*/
	.equ SYSCALL_COUNT , 28

#include "tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

	.extern nested_kernel_entrance_counter
	.extern tpl_kern
	.extern tpl_dispatch_table

/* Main system call handler
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * We take care to not alter callee saved registers
 * which are all except r0-r3 (EABI convention).
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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

/*******************************************************************************
 *
 *******************************************************************************/
tpl_enter_kernel:
	#if WITH_MEMORY_PROTECTION == YES
	/*
	* Switch to kernel memory protection scheme
	*/
	push {lr}
	bl tpl_kernel_mp
	pop {lr}
	#endif
	/* 
	* Manage reentrance of kernel
	* Increment nested_kernel_entrance_counter
	*/
	ldr r1, =nested_kernel_entrance_counter
	ldr r2, [r1]
	add r2, r2, #1
	str r2, [r1]
	/* 
	* Switch to the kernel stack
	* Automatic (configuration) for the Cortex-M4
	*/	
tpl_enter_kernel_exit:	
	bx lr

/*******************************************************************************
 *
 *******************************************************************************/
tpl_leave_kernel:
	/* 
	* Manage reentrance of kernel
	* Decrement nested_kernel_entrance_counter
	*
	* We update kernel reentrance counter while registers are freely
	* usable and as we know we won't enter in kernel again (IRQ locked and
	* no SWI can occur)
	*/
	ldr r1, =nested_kernel_entrance_counter
	ldr r2, [r1]
	sub r2, r2, #1
	str r2, [r1]
	#if WITH_MEMORY_PROTECTION == YES
	/*
	* Switch to user memory protection scheme
	*/
	push {lr}
	bl tpl_user_mp
	pop {lr}
	#endif
tpl_leave_kernel_exit:
	bx lr

/*******************************************************************************
 *
 *******************************************************************************/
	.global tpl_primary_syscall_handler
	.type   tpl_primary_syscall_handler, %function
tpl_primary_syscall_handler:
	/* <!DGAR> fait par la suite ? à modifier => tester nested_kernel_entrance_counter == 0
	*/
	/* <!DGAR> Shall we disable all interrupts ?
	*/

	/* __1__
	* The first thing to do is to check if the service id is a valid one
	* Shall be less than SYSCALL_COUNT
	*/
	cmp r3, #SYSCALL_COUNT       /* Shall use [r12] */
	bhs invalid_service_id
	
	/* __2__
	* Save registers [r0], [r1], [r2], [lr] on top of stack.
	* [lr] register holds EXC_RETURN value, giving information about the caller context
	* We save [lr], then [r2], then [r1], then [r0].
	*/
	stmdb sp!, {r0-r2,lr}
	
	/* __X__
	* Enter into kernel
	*/
	bl tpl_enter_kernel
	
	/* reset tpl_kern variables */
	ldr r1, =tpl_kern
	mov r2, #NO_NEED_SWITCH_NOR_SCHEDULE
	strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
	strb r2, [r1, #TPL_KERN_OFFSET_NEED_SCHEDULE]

	/* save volatile registers
	 * get the context block address
	 * r1 is already the address of tpl_kern */
	ldr r2, [r1, #TPL_KERN_OFFSET_S_ELECTED]
	ldr r2, [r2]
	stmia r2, {r4-r11}           /* Save r4-r11 into context bloc reg */
	mrs r1, psp                  /* Get current process stack pointer (psp) value */
	str r1, [r2, #32]            /* and save it into context bloc sp */

	/* pop registers values from the stack
	 * The sp is altered */
	ldmia sp!, {r0-r2}

	/*********************************
	* SYSTEM CALL DISPATCHING STAGE *
	*********************************/
	/* WARNING : r0 and r3 should not be altered until here
	* as they are used to :
	* r3 : give the service identifier while calling the system call
	* r0 : give some arg to the service
	*/

	/* get the appropriate system call address into R3 */
	ldr r1, =tpl_dispatch_table
	ldr r3, [r1, r3, LSL #2]

	/* call the service
	 * r0-r3 shall be altered by callee.
	 * r4-r8, r10, r11 are callee saved.
	 * We just save lr.
	 */
	push {lr}
	blx r3
	pop {lr}
	
	/* Do we need to switch context ?
	 * (requested by system service)
	 */
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
	/* Context is saved, so the value of r3 will be 1
	 * [r3] is used for the future call of tpl_run_elected
	 */
	mov r3, #1
	/* already done at the beginning of the subroutine */
	b load_context_swi

	/* only executed if context saving step has not been done */
skip_save_context_swi:
	/* Context is not saved, so the value of r3 will be 0
	 * [r3] is used for the future call of tpl_run_elected
	 */
	mov r3, #0
	/* get back volatile registers
	 * get the context block address */
	ldr r1, =tpl_kern
	ldr r2, [r1, #TPL_KERN_OFFSET_S_ELECTED]
	ldr r2, [r2]
	ldmia r2, {r4-r11} /* Load r4-r11 from context bloc reg */
 
	/*
	 * LOADS NEW CONTEXT
	 */
load_context_swi:
	/* First call tpl_run_elected with the value of tpl_kern.need_switch
	 * and get the value of the elected task.
	 * tpl_kern.need_switch (stored into r3) is copied into r0
	 */
	mov r0, r3
	push {lr}
	bl tpl_run_elected
	pop {lr}
	mov r3, r0 	/* Keep the returned value into r3 */
	
	/* Get the context block address */
	ldr r0, =tpl_kern
	ldr lr, [r0, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
	ldr lr, [lr]                             /* jump to context bloc (from static descriptor) */

	ldmia lr, {r4-r11}      /* loads from lr base register into r4 to r11 */
	ldr r0, [lr, #32]
	msr psp, r0

    /********************************************
     * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
     ********************************************/
invalid_service_id:  /* currently, if invalid service id is specified, we do nothing */
swi_no_context_switch_exit:
	/* __X__
 	* Leave kernel
 	*/
	bl tpl_leave_kernel
	
tpl_primary_syscall_handler_exit:
	/* Moves back EXC_RETURN into lr.
	 * lr was pushed on stack with statement << stmdb sp!, {r0-r2,lr} >> at beginning of handler call.
	 */
	pop {lr}
	cpsie i

	bx lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_system_call.S */

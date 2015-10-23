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

#include "tpl_assembler.h"
#include "tpl_asm_definitions.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"
#include "tpl_service_ids.h"

.section .osVar ,"aw"

.equ  NO_NEED_SWITCH_NOR_SCHEDULE , 0
.equ  NO_NEED_SWITCH , 0
.equ  NEED_SWITCH , 1
.equ  NEED_SAVE , 2

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

*/

.section .osCode CODE_ACCESS_RIGHT

/*******************************************************************************
 * DEBUG FUNCTION
 *******************************************************************************/
	.global info_stack_pointer
	.type info_stack_pointer, %function
info_stack_pointer:
  mov r0, sp
  bx lr

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
	ldr r12, =nested_kernel_entrance_counter
	ldr r4, [r12]
	add r4, r4, #1
	str r4, [r12]
	/*
	 * NA: Switch to the kernel stack
	 * Automatic (configuration) for the Cortex-M4
	 */

	/*
	 * NA: Make space on the stack to call C functions
	 * Automatic for the Cortex-M4
	 */
tpl_enter_kernel_exit:
	bx lr

/*******************************************************************************
 *
 *******************************************************************************/
tpl_leave_kernel:
	/*
	 * NA: Restore saved registers in the system stack
	 * Automatic for the Cortex-M4
	 */

	/*
	 * Manage reentrance of kernel
	 * Decrement nested_kernel_entrance_counter
	 *
	 * We update kernel reentrance counter while registers are freely
	 * usable and as we know we won t enter in kernel again (IRQ locked and
	 * no SWI can occur)
	 *
	 * NA: If it reaches 0, the process stack is restored
	 * Automatic for the Cortex-M4
	 */
	ldr r12, =nested_kernel_entrance_counter
	ldr r4, [r12]
	sub r4, r4, #1
	str r4, [r12]

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
	b tpl_sc_handler

tpl_sc_handler:
	/*
	 * Stack is MSP now
	 */

	/* __1__HANDLER_PROLOG
	 * The first thing to do is to check if the service id is a valid one
	 * Shall be less than SYSCALL_COUNT
	 */
	cmp r3, #SYSCALL_COUNT
	bhs invalid_service_id

	sub sp, sp, #KS_FOOTPRINT		/* Make space on top of kernel stack. */
	mrs r12, psp					/* Copy process stack pointer psp into r12 */
	str r12, [sp, #KS_PROCESS_SP]	/* and save it into kernel stack. */
	str r4, [sp, #KS_R4]			/* Save working register r4 on kernel stack. */
	str r5, [sp, #KS_R5]			/* Save working register r5 on kernel stack. */
	ldr r12, =tpl_kern
	str r12, [sp, #KS_KERN_PTR] 	/* Store tpl_kern into kernel stack. */
	str lr, [sp, #KS_LR]			/* Store lr register into kernel stack. */
	/* Now use r5 instead of sp */
	mov r5, sp

	/* __2__ENTER_KERNEL
	* Enter into kernel
	*/
	push {lr}
	bl tpl_enter_kernel
	pop {lr}

	/*
	 * Get the appropriate system call address into R3
	 */
	ldr r12, =tpl_dispatch_table
	ldr r3, [r12, r3, LSL #2]

	/*
	 * Reset tpl_kern variables
	 */
	ldr r12, [r5, #KS_KERN_PTR]						/* load the tpl_kern base address */
	mov r4, #NO_NEED_SWITCH_NOR_SCHEDULE
	strb r4, [r12, #TPL_KERN_OFFSET_NEED_SWITCH]
	strb r4, [r12, #TPL_KERN_OFFSET_NEED_SCHEDULE]

	/* __3__SYSTEM_CALL
	 * System call
	 * WARNING : r0 and r3 should not be altered until here
	 * as they are used to :
	 * r3 : give the service identifier while calling the system call
	 * r0 : give some arg to the service
	 */
	blx r3
	/*
	 * r0 holds the return code of the service.
	 * r0 will be destroyed by the call to tpl_save_context.
	 * It is saved into kernel stack.
	 */
	str r0, [r5, #KS_RETURN_CODE]

	/*
	 * Do we need to switch context ?
	 * (requested by system service)
	 */
	ldr r12, [r5, #KS_KERN_PTR]						/* load the tpl_kern base address */
	ldrb r12, [r12, #TPL_KERN_OFFSET_NEED_SWITCH]
	cmp r12, #NO_NEED_SWITCH
	beq no_context_switch

	/* do not switch context if nested kernel entrance */
	ldr r12, =nested_kernel_entrance_counter
	ldr r4, [r12]
	cmp r4, #1
	bhi no_context_switch

	/* __4__SWITCH_CONTEXT
	 * We are going to switch context.
	 * Do we need to save old context ?
	 */
	mov r0, #0	/* set save parameter to 0 */
	ldr r12, [r5, #KS_KERN_PTR]						/* load the tpl_kern base address */
	ldrb r12, [r12, #TPL_KERN_OFFSET_NEED_SWITCH]
	tst r12, #NEED_SAVE
	beq no_save_old_context
	mov r0, #1	/* set save parameter to 1 */

	/*
	 * Save context
	 */
	ldr r12, [r5, #KS_KERN_PTR]						/* load the tpl_kern base address */
	ldr r12, [r12, #TPL_KERN_OFFSET_S_RUNNING]
	push {lr}
	bl tpl_save_context
	pop {lr}

no_save_old_context:
#if WITH_MEMORY_PROTECTION == YES
  /*
   * set up the memory protection for the process that just got the CPU
   */
#endif

call_tpl_run_elected:
	/* First call tpl_run_elected with the value of tpl_kern.need_switch
	 * and get the value of the elected task.
	 * tpl_kern.need_switch (stored into r3) is copied into r0
	 */
	bl tpl_run_elected

	/*
	 * Load context:
	 * get s_running (it has been changed by tpl_run_elected)
	 */
	ldr r12, [r5, #KS_KERN_PTR]						/* load the tpl_kern base address */
	ldr r12, [r12, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
	push {lr}
	bl tpl_load_context
	pop {lr}

    /********************************************
     * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
     ********************************************/
invalid_service_id:  /* currently, if invalid service id is specified, we do nothing */
no_context_switch:
	/*
 	 * Reset the tpl_need_switch variable to NO_NEED_SWITCH
 	 */
	ldr r12, [r5, #KS_KERN_PTR]						/* load the tpl_kern base address */
	mov r4, #NO_NEED_SWITCH_NOR_SCHEDULE
	strb r4, [r12, #TPL_KERN_OFFSET_NEED_SWITCH]

	/*
	 * The return value of service has been saved into KS(KS_RETURN_CODE).
	 * Copy back this return value into r0
	 */
	ldr r0, [r5, #KS_RETURN_CODE]

	/* __5__LEAVE_KERNEL
 	 * Leave kernel
 	 */
	push {lr}
	bl tpl_leave_kernel
	pop {lr}

	/* __6__HANDLER_EPILOG
 	 * Leave kernel
 	 */
	/*
	 * Restore registers from kernel stack before leaving.
	 * sp MUST be the same as at the beginning of routine.
	 * Not necessary to use r5 now.
	 */
	ldr r4, [sp, #KS_R4]
	ldr r5, [sp, #KS_R5]
	ldr lr, [sp, #KS_LR]

	ldr r12, [sp, #KS_PROCESS_SP]
	msr psp, r12
	add sp, sp, #KS_FOOTPRINT

tpl_sc_handler_exit:
	bx lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

.end

/* End of file tpl_system_call.S */

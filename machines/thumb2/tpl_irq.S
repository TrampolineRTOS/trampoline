/**
 * @file tpl_irq.S
 *
 * @section descr File description
 *
 * IRQ handling.
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

#include "tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

	.extern nested_kernel_entrance_counter
	.extern tpl_kern
	.extern tpl_dispatch_table
	.extern decPeriode

/*
 * First stage category 2 interrupt handler (which means only IRQ on
 * this architecture, FIQ are category 1 interrupts)
 */

    /**********************
     * KERNEL ENTER STAGE *
     **********************
     * After this stage, stack looks like this :
     *
     *         |---------------------------|
     *         | task's return address     |
     * SP+24-> |---------------------------|
     *         | ip (r12)                  |
     * SP+18-> |---------------------------|
     *         | r11                       |
     * SP+14-> |---------------------------|
     *         | r9                        |
     * SP+10-> |---------------------------|
     *         | r3                        |
     * SP+C -> |---------------------------|
     *         | r2                        |
     * SP+8 -> |---------------------------|
     *         | r1                        |
     * SP+4 -> |---------------------------|
     *         | r0                        |
     * SP   -> |---------------------------|
     *
     * Every caller-saved register is saved here, as the
     * other ones shall be saved by callee. We don't want
     * to save every register here as we don't know if
     * a context switch is actually needed.
     */

	.global tpl_primary_irq_handler
	.type   tpl_primary_irq_handler, %function
tpl_primary_irq_handler:

    /* manage reentrance of kernel */
    ldr r1, =nested_kernel_entrance_counter
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_enter
#endif /* WITH_MEMORY_PROTECTION == YES */

	/* reset tpl_kern variables */ /* <! DGAR POURQUOI ? !> */
    ldr r1, =tpl_kern
    mov r2, #NO_NEED_SWITCH_NOR_SCHEDULE
    strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
    strb r2, [r1, #TPL_KERN_OFFSET_NEED_SCHEDULE]

    /************************
     * IRQ processing stage *
     ************************/

//    mov r0,#15 /* <! DGAR TEMPORAIRE POUR APPELER LE BON SERVICE > */

    push {lr} /* save lr onto stack */

    bl tpl_arm_subarch_irq_handler
    
    pop {lr} /* get lr back from stack */

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_exit
#endif

//	b tpl_primary_irq_handler_exit
    /***************************************************
     * on the way to exit IRQ routine (with or without *
     * context switch)                                 *
     ***************************************************/
    /* Do we need to switch context ? */

    ldr r2, =tpl_kern
    ldrb r2, [r2, #TPL_KERN_OFFSET_NEED_SWITCH]
    cmp r2, #NO_NEED_SWITCH
    beq irq_no_context_switch
	
	/***************************
	* CONTEXT SWITCHING STAGE *
	***************************/

context_switch_irq:
    /* load the tpl_kern base address */
    ldr r0, =tpl_kern

    /* do we need to save the context ? if not, jump to load */
    ldrb r2, [r0, #TPL_KERN_OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_irq

    /*
     * SAVES OLD CONTEXT
     */
save_context_irq:
    /* Context is saved, so the value of r3 will be 1 */
    mov r3, #1
    /* get the context block address */
    ldr r2, [r0, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr r2, [r2]                /* jump to context bloc (from static descriptor) */
    mov lr, sp
    stmia r2, {r4-r11, lr}       /* Save r4-r11 and sp into context bloc */

    b load_context_irq

    /* only executed if context saving step has not been done */
skip_save_context_irq: /* <! DGAR POURQUOI > */
    /* Context is not saved, so the value of r3 will be 0 */
    mov r3, #0
//    add sp, sp, #(8 * 4) /* skip saved register frame (8 = r0-r3 + r9 + r11 + r12 + r14) */

	/*
	* LOADS NEW CONTEXT
	*/
load_context_irq:

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

    ldmia lr, {r4-r11}      /* loads from lr base register into r4 to r11 */
//	ldr lr, [lr, #(14 * 4)] /* loads from lr+14*4 (lr) to r5 */
//	ldr lr, [lr, #(15 * 4)] /* loads from lr+15*4 (pc) to r6 */

    /* Switch to new task's SP */
    /* loads SP value into r0 */
    ldr r0, [lr, #(8 * 4)]

    /*
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
	mov lr, #ARM_INITIAL_EXC_RETURN
	//pop {lr}
	/* Changes the SP now */
    /* Writes MSP with value of r0 */
    msr msp, r0

	b tpl_primary_irq_handler_exit

    /********************************************
     * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
     ********************************************/
irq_no_context_switch:
    /* manage reentrance of kernel */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]

    /* return to interrupted task */
tpl_primary_irq_handler_exit:
    bx lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_irq.S */

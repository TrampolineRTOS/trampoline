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

#include "tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/*
 * First stage category 2 interrupt handler (which means only IRQ on
 * this architecture, FIQ are category 1 interrupts)
 */
.global tpl_primary_irq_handler
tpl_primary_irq_handler:
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

    /* fix LR to make it point on task's return address */
    sub lr, lr, #4
    /* store caller-saved registers */
    stmfd sp!, {r0-r3,r9,r11,ip,lr}
    /* manage reentrance of kernel */
    ldr r1, =nested_kernel_entrance_counter
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_enter
#endif /* WITH_MEMORY_PROTECTION == YES */

    /* reset tpl_kern variables */
    ldr r1, =tpl_kern
    mov r2, #NO_NEED_SWITCH
    strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]

    /************************
     * IRQ processing stage *
     ************************/
    bl tpl_arm_subarch_irq_handler

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_exit
#endif

    /***************************************************
     * on the way to exit IRQ routine (with or without *
     * context switch)                                 *
     ***************************************************/
context_switch_swi:
    /* load the tpl_kern base address */
    ldr r1, =tpl_kern

    /* then, do we need to switch context ? */
    ldr r2, =tpl_kern
    mov r0, #0	/* set save parameter to 0 */
    ldrb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
    cmp r2, #NO_NEED_SWITCH
    beq irq_no_context_switch
    mov r0, #1	/* set save parameter to 1 */

    /*
     * SAVES OLD CONTEXT
     */

    /* do we need to save the context ? if not, jump to load */
    ldrb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_irq

    /* get the context block address */
    ldr r2, [r1, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr r2, [r2]                /* jump to context bloc (from static descriptor) */
    add r2, r2, #(4 * 4)        /* jump over r0-r3 saving zone */
    stmia r2, {r4-r14}^         /* save callee saved registers (r9 and r12 will be overwritten) */
    sub r2, r2, #(4 * 4)        /* get back to begining of task's saving zone... */
    mrs r4, spsr
    str r4, [r2, #(16 * 4)]

    /* save ABI's caller-saved registers, those which are saved into
     * kernel_enter macro
     */
    ldmfd sp!, {r4-r7,r9,r11,ip,lr} /* /!\ r0-r3 <=> r4-r7 */
    stmia r2, {r4-r7}
    str r9, [r2, #(9*4)]
    str r11, [r2, #(11*4)]
    str ip, [r2, #(12*4)]
    str lr, [r2, #(15*4)]

    b load_context_irq

    /* only executed if context saving step has not been done */
skip_save_context_irq:
    add sp, sp, #(8 * 4) /* skip saved register frame (8 = r0-r3 + r9 + r11 + r12 + r14) */

load_context_irq:

call_tpl_run_elected:
	/* First call tpl_run_elected with the value of tpl_kern.need_switch
	 * and get the value of the elected task.
	 * tpl_kern.need_switch (stored into r3) is copied into r0
	 */
	bl tpl_run_elected

  /* We updates kernel reentrance counter while registers are freely
   * usable and as we know we won't enter in kernel again (IRQ locked and
   * no SWI can occur) */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]

    /*
     * LOADS NEW CONTEXT
     */

    /* Get the context block address.
     *
     * We use r14 as it will be restored separatly and later, it
     * is useful for the following ldmia instruction
     */
    ldr r1, =tpl_kern
    ldr r14, [r1, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context block */
    ldr r14, [r14]                   /* jump to context bloc (from static descriptor) */

    ldr r0, [r14, #(16 * 4)]        /* restore SPSR register from context block */
    msr spsr, r0

    /* finish load and get back to running task */
#if !defined NO_OKI_PIPELINE_BUG
    ldmia lr, {r0-r14}^
    b flush_pipeline
flush_pipeline:
    ldr lr, [lr, #(15 * 4)]

    movs pc, lr
#else
    ldmia lr, {r0-r15}^
#endif /* defined NO_OKI_PIPELINE_BUG */

    /********************************************
     * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
     ********************************************/
irq_no_context_switch:
    /* manage reentrance of kernel */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]

    /* restore caller-saved registers */
    ldmfd sp!, {r0-r3,r9,r11,ip,lr}

    /* return to interrupted task */
    movs pc,lr


#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_irq.S */

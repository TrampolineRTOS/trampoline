/**
 * @file arm926_exception_catch.S
 *
 * @section descr File description
 *
 * Catch of CPU exceptions (abort, undefined, ...)
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
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#include "../tpl_asm_definitions.h"
#include "tpl_os_application_def.h"

.global primary_undefined_instruction_handler
.global primary_prefetch_abort_handler
.global primary_data_abort_handler

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

primary_undefined_instruction_handler:
    msr cpsr_c, #(CPSR_IRQ_LOCKED | CPSR_UND_MODE)
    b any_exception_enter

primary_data_abort_handler:
    msr cpsr_c, #(CPSR_IRQ_LOCKED | CPSR_ABT_MODE)
    sub lr, lr, #8
    b any_exception_enter

primary_prefetch_abort_handler:
    msr cpsr_c, #(CPSR_IRQ_LOCKED | CPSR_ABT_MODE)
    sub lr, lr, #4
    b any_exception_enter

any_exception_enter:
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

    /* store caller-saved registers */
    stmfd sp!, {r0-r3,r9,r11,ip,lr}
    /* manage reentrance of kernel */
    ldr r1, =nested_kernel_entrance_counter
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]
    cmp r2, #1
    bhi skip_kernel_enter

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_enter
#endif /* WITH_MEMORY_PROTECTION == YES */

    /* reset tpl_kern variables */
    ldr r1, =tpl_kern
    mov r2, #NO_NEED_SWITCH
    strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]

skip_kernel_enter:

    /******************************
     * exception processing stage *
     ******************************/

    mrs r0, cpsr
    and r0, r0, #0x1F
    cmp r0, #CPSR_UND_MODE
    moveq r0, #E_OS_PROTECTION_EXCEPTION
    movne r0, #E_OS_PROTECTION_MEMORY 
    bl tpl_call_protection_hook

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_exit
#endif /* WITH_MEMORY_PROTECTION == YES */

    /*************************************************
     * on the way to exit exception (with or without *
     * context switch)                               *
     *************************************************/
    /* then, do we need to switch context ? */
    ldr r2, =tpl_kern
    ldrb r2, [r2, #TPL_KERN_OFFSET_NEED_SWITCH]
    cmp r2, #NO_NEED_SWITCH
    beq except_no_context_switch
    ldr r2, =nested_kernel_entrance_counter
    ldr r2, [r2]
    cmp r2, #1
    bhi except_no_context_switch

context_switch_exception:
    /* load the tpl_kern base address */
    ldr r0, =tpl_kern

    /*
     * SAVES OLD CONTEXT
     */

    /* do we need to save the context ? if not, jump to load */
    ldrb r2, [r0, #TPL_KERN_OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_except

    /* get the context block address */
    ldr r2, [r0, #TPL_KERN_OFFSET_S_OLD] /* get the address of the context bloc */
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

    b load_context_except

    /* only executed if context saving step has not been done */
skip_save_context_except:
    add sp, sp, #(8 * 4) /* skip saved register frame (8 = r0-r3 + r9 + r11 + r12 + r14) */

load_context_except:

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
    ldr r0, =tpl_kern
    ldr r14, [r0, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context block */

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
except_no_context_switch:
    /* manage reentrance of kernel */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]

    /* restore caller-saved registers */
    ldmfd sp!, {r0-r3,r9,r11,ip,lr}

    /* return to interrupted task */
    movs pc,lr

/* FIQ not defined in this port version */
.global primary_fiq_handler
.global tpl_primary_fiq_handler
primary_fiq_handler:
tpl_primary_fiq_handler:
  subs pc, lr, #4

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"


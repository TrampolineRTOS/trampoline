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

#include "tpl_asm_definitions.h"

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
.global tpl_primary_syscall_handler
tpl_primary_syscall_handler:
    
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
    msr cpsr_c, #(CPSR_IRQ_LOCKED | CPSR_SVC_MODE)

    /* We save R0 to R2 here as they may contain system call
     * parameter. We save LR as the task's return address.
     * R3 is not saved as it is known to never being used as
     * system call parameter (and contains system call number).
     */
    stmfd sp!, {r0-r2,lr}

    /* System calls should be reentrant, so we have to
     * save the SPSR on the stack. */
    mrs r1, spsr
    stmfd sp!, {r1}
    
    /* manage reentrance of kernel */
    ldr r1, =nested_kernel_entrance_counter
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]
    cmp r2, #1
    bhi skip_kernel_enter

#if WITH_MEMORY_PROTECTION == YES
    stmfd sp!, {r3}    /* r3 must not be altered : it contains service s identifier */
    bl tpl_mp_kernel_enter
    ldmfd sp!, {r3}
#endif /* WITH_MEMORY_PROTECTION == YES */

    /* reset tpl_kern variables */
    ldr r1, =tpl_kern
    mov r2, #NO_NEED_SWITCH
    strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]

skip_kernel_enter:

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
    ldr r3, [r1, r3, LSL #2]

    /* pop registers values from the stack without altering
     * the stack pointer */
    add sp, sp, #4     /* just jump over SPSR saved value */
    ldmia sp, {r0-r2}
    sub sp, sp, #4     /* restore current value of SP */

    /* call the service (blx does not exist on ARM7TDMI, so we split it in
     * two instructions) */
    mov lr, pc
    bx r3

  /* we save back returned value (r0-r1) into r0-r1 saved values on the stack */
    add sp, sp, #4
    stmia sp, {r0-r1}
    sub sp, sp, #4

    /* check if context switch is needed (requested by system service) */
    ldr r2, =tpl_kern
    ldrb r2, [r2, #TPL_KERN_OFFSET_NEED_SWITCH]
    cmp r2, #NO_NEED_SWITCH
    beq swi_no_context_switch_exit

    /* do not switch context nor do kernel exit if nested kernel entrance */
    ldr r2, =nested_kernel_entrance_counter
    ldr r2, [r2]
    cmp r2, #1
    bhi swi_skip_kernel_exit

   /***************************
    * CONTEXT SWITCHING STAGE *
    ***************************/
context_switch_swi:
    /* load the tpl_kern base address */
    ldr r1, =tpl_kern
    
    /* do we need to save the context ? if not, jump to load */
   	mov r0, #0	/* set save parameter to 0 */
    ldrb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_swi
    mov r0, #1	/* set save parameter to 1 */

    /*
     * SAVES OLD CONTEXT
     */
save_context_swi:

    /* get the context block address */
    ldr r2, [r1, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr r2, [r2]                /* jump to context bloc (from static descriptor) */
    add r2, r2, #(4 * 4)        /* jump over r0-r3 saving zone */
    stmia r2, {r4-r14}^
    sub r2, r2, #(4 * 4)        /* get back to begining of task's saving zone... */

    ldmfd sp!, {r4}          /* as SWI is reentrant, true SPSR is found in the stack */
    str r4, [r2, #(16 * 4)]

   /* save ABI's caller-saved registers, those which are saved into
    * kernel_enter macro
    */
    ldmfd sp!, {r4-r6} /* r0-r2 <=> r4-r6 */
    stmia r2, {r4-r6}

    ldmfd sp!, {r4}          /* pop task's return address */
    str r4, [r2, #(15 * 4)]  /* and store it into task's saving zone */

    /* NB: R3 is not saved as we know its value won't be significant */
    b load_context_swi       /* jump to suite */

    /* only executed if context saving step has not been done */
skip_save_context_swi:
    add sp, sp, #(5 * 4) /* discards kernel enter stack frame */

    /*
     * LOADS NEW CONTEXT
     */
load_context_swi:

call_tpl_run_elected:
	/* First call tpl_run_elected with the value of tpl_kern.need_switch
	 * and get the value of the elected task.
	 * tpl_kern.need_switch (stored into r3) is copied into r0
	 */
	bl tpl_run_elected

#if WITH_MEMORY_PROTECTION == YES
    bl tpl_mp_kernel_exit
#endif

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
    ldr r1, =tpl_kern
    ldr lr, [r1, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr lr, [lr]                   /* jump to context bloc (from static descriptor) */

    /* loads SPSR*/
    ldr r0, [lr, #(16 * 4)]
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
invalid_service_id:  /* currently, if invalid service id is specified, we do nothing */
swi_no_context_switch_exit:

  /* manage reentrance of kernel */
    ldr r3, =nested_kernel_entrance_counter
    ldr r2, [r3]
    sub r2, r2, #1
    str r2, [r3]

#if WITH_MEMORY_PROTECTION == YES
    /* in case we enter in trusted function, we must prepare
     * the memory protection to give all rights to a process
     * which is initially non-trusted
     */
    cmp r2, #0
    bleq tpl_mp_kernel_exit
#endif /* WITH_MEMORY_PROTECTION == YES */

swi_skip_kernel_exit:

    /* pops the kernel enter stack frame */
    ldmfd sp!, {r3}
    msr spsr, r3
    ldmfd sp!, {r0-r2,lr}

    movs pc, lr

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_system_call.S */

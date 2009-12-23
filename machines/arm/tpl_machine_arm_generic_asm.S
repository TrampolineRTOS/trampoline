/**
 * @file tpl_machine_arm_generic_asm.S
 *
 * @section descr File description
 *
 * Low level part of generic ARM platform
 *
 * This includes system call mechanism and IRQ (category 2 interrupts)
 * handling (at low level).
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

#include "tpl_asm_macros.h" /* this file should be defined in end platform (eg SIMTEC) */

#include "../tpl_asm_definitions.h"

/* Give the necessary offsets for acces to the different elements of 
 * an tpl_kern_state type structure 
 */
 
.set OFFSET_S_OLD,0
.set OFFSET_S_RUNNING, 4
.set OFFSET_OLD, 8
.set OFFSET_RUNNING, 12
.set OFFSET_RUNNING_ID, 16
.set OFFSET_NEED_SWITCH, 20

/* stacks are placed just after BSS segment as we don't need to initialize
 * them */
.section stacks
.align 2

.global irq_stack_top
irq_stack_top:
.space 4096 * 4
.global irq_stack_bottom
irq_stack_bottom:

.global fiq_stack_top
fiq_stack_top:
.space 1024 * 4
.global fiq_stack_bottom
fiq_stack_bottom:

.global svc_stack_top
svc_stack_top:
.space 4096 * 4
.global svc_stack_bottom
svc_stack_bottom:

.global abt_stack_top
abt_stack_top:
.space 256 * 4
.global abt_stack_bottom
abt_stack_bottom:

.global und_stack_top
und_stack_top:
.space 256 * 4
.global und_stack_bottom
und_stack_bottom:

.global usr_stack_top
usr_stack_top:
.space 4096 * 4
.global usr_stack_bottom
usr_stack_bottom:

.bss
.align 2

nested_kernel_entrance_counter:
	.word 0

.text
.align 2

/*
 * Module's initializer
 */
.global tpl_init_machine_low_level
tpl_init_machine_low_level:
	stmfd sp!, {r0-r1}

	ldr r0, =nested_kernel_entrance_counter
	mov r1, #0
	str r1, [r0]

	ldmfd sp!, {r0-r1}
	mov pc, lr

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
     * R3 is not saved as it is know to never being used as
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

    /* reset tpl_kern variables */
    ldr r1, =tpl_kern
    mov r2, #NO_NEED_SWITCH
    strb r2, [r1, #OFFSET_NEED_SWITCH]

   /*********************************
    * SYSTEM CALL DISPATCHING STAGE *
    *********************************/
	/* WARNING : r3 should not be altered until here
	 * as it is used to give the service identifier while calling swi
	 */
	cmp r3, #OS_SYSCALL_COUNT
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
    ldrb r2, [r2, #OFFSET_NEED_SWITCH]
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
    ldrb r2, [r0, #OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_swi

    /*
     * SAVES OLD CONTEXT
     */
save_context_swi:

    /* get the context block address */
    ldr r2, [r0, #OFFSET_S_OLD] /* get the address of the context bloc */
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
    add sp, sp, #(5 * 4)

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
    ldr lr, [r0, #OFFSET_S_RUNNING] /* get the address of the context bloc */
    ldr lr, [lr]                   /* jump to context bloc (from static descriptor) */

    /* loads SPSR*/
    ldr r0, [lr, #(16 * 4)]
    msr spsr, r0

    /* finish load and get back to running task */
    ldmia lr, {r0-r14}^
    b flush_pipeline
flush_pipeline:
    ldr lr, [lr, #(15 * 4)]

    movs pc, lr


    ldmia lr, {r0-r15}^
	
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

    /* pops the stack frame (see kernel enter phase) */
    ldmfd sp!, {r3}
    msr spsr, r3
    ldmfd sp!, {r0-r2,lr}

    movs pc, lr


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
     * SP+18-> |---------------------------|
     *         | ip (r12)                  |
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
	stmfd sp!, {r0-r3,r9,ip,lr}
	/* manage reentrance of kernel */
    ldr r1, =nested_kernel_entrance_counter
    ldr r2, [r1]
    add r2, r2, #1
    str r2, [r1]
	
	bl tpl_arm_subarch_irq_handler

    ldr r2, =tpl_kern
    ldrb r2, [r2, #OFFSET_NEED_SWITCH]
    cmp r2, #NO_NEED_SWITCH
	beq irq_no_context_switch
	
context_switch_irq:
  /* load the tpl_kern base address */
    ldr r0, =tpl_kern

    /*
     * SAVES OLD CONTEXT
     */

  /* do we need to save the context ? if not, jump to load */
    ldrb r2, [r0, #OFFSET_NEED_SWITCH]
    tst r2, #NEED_SAVE
    beq skip_save_context_irq

    /* get the context block address */
    ldr r2, [r0, #OFFSET_S_OLD] /* get the address of the context bloc */
    ldr r2, [r2]                /* jump to context bloc (from static descriptor) */
    add r2, r2, #(4 * 4)        /* jump over r0-r3 saving zone */
    stmia r2, {r4-r14}^         /* save callee saved registers (r9 and r12 will be overwritten) */
    sub r2, r2, #(4 * 4)        /* get back to begining of task's saving zone... */
    mrs r4, spsr
    str r4, [r2, #(16 * 4)]

    /* save ABI's caller-saved registers, those which are saved into
     * kernel_enter macro
     */
    ldmfd sp!, {r4-r7,r9,ip,lr} /* /!\ r0-r3 <=> r4-r7 */
    stmia r2, {r4-r7}
    str r9, [r2, #(9*4)]
    str ip, [r2, #(12*4)]
    str lr, [r2, #(15*4)]

    b load_context_irq

    /* only executed if context saving step has not been done */
skip_save_context_irq:
    add sp, sp, #(7 * 4)

load_context_irq:

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

    ldr r14, [r0, #OFFSET_S_RUNNING] /* get the address of the context bloc */

    ldr r14, [r14]                   /* jump to context bloc (from static descriptor) */

    ldr r0, [r14, #(16 * 4)]
    msr spsr, r0

    ldmia r14, {r0-r15}^
	
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
    ldmfd sp!, {r0-r3,r9,ip,lr}

    /* return to interrupted task */
    movs pc,lr

/**
 * Copyright (c) 2012 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file arm_entry_v7.S
 * @author Anup Patel (anup@brainfault.org)
 * @author Sukanto Ghosh (sukantoghosh@gmail.com)
 * @brief Entry point code for basic firmware
 */

#include "arm_asm_macro.h"
#include "gic_config.h"
#include "arm_plat.h"

#include "tpl_asm_definitions.h"

	/*
	 * Basic firmware could be loaded any where in memory by
	 * boot loaders.
	 * The _start function ensures that it exectues from intended
	 * base address provided at compile time.
	 */
	.section .expvect, "ax", %progbits
	.globl _start
_start:
	add	r0, pc, #-0x8
	cpsid	if

#ifdef BOARD_SMP
	/* Core-1 should spin and core-0 should go ahead */
	mrc	p15, 0, r5, c0, c0, 5
	ands	r5, r5, #0x3
	bne	_secondary_loop
#endif

	ldr	r1, __code_start
	sub	r6, r0, r1		/* r1 -> Load Start - Exec Start */
	/*
	 * r6 -> offset between binary execution and load addresses
	 * We need to ensure that when we jump to reset code, we are executing
	 * from intended execution address. If necessary do relocation from
	 * load memory to execution memory.
	 */
	ldr	r1, __reloc_region_start	/* r1 -> execution address of reloc_region_start */
	ldr	r2, __reloc_region_end
	sub	r2, r2, r1		/* r2 -> reloc_region size */
	add	r0, r1, r6		/* r0 -> load address of reloc_region start */
	bl	_reloc_region

	/*
	 * Manually zero out the zero region (bss + heap)
	 */
	ldr	r1, __zero_region_start
	ldr	r2, __zero_region_end
	mov	r7, #0x0
	mov	r8, #0x0
	mov	r9, #0x0
	mov	r10, #0x0
_zeroing_loop:
	cmp	r1, r2
	bge	_zeroing_done
	stmia	r1!, {r7 - r10}
	b	_zeroing_loop
_zeroing_done:

	/*
	 * Enable I-Cache
	 */
	mrc	p15, 0, r0, c1, c0, 0
	ldr	r1, __sctlr_mmu_clear
	ldr	r2, __sctlr_mmu_set
	and	r0, r0, r1
	orr	r0, r0, r2
	mcr	p15, 0, r0, c1, c0, 0

_jump_to_exec:
	ldr	pc, __reset

__code_start:
	.word _code_start
__reloc_region_start:
	.word _reloc_region_start
__reloc_region_end:
	.word _reloc_region_end
__zero_region_start:
	.word _zero_region_start
__zero_region_end:
	.word _zero_region_end
__heap_start:
	.word _heap_start
__heap_end:
	.word _heap_end
__sctlr_mmu_clear:
	.word ~(SCTLR_A_MASK)
__sctlr_mmu_set:
	.word (SCTLR_I_MASK)

	/*
	 * Copies data from source to destination taking care of even
	 * overlapping regions
	 * Arguments:
	 *  r0 -> source address
	 *  r1 -> destination address
	 *  r2 -> byte count
	 * Unmodified gprs: r4, r5, r6, r11, r12
	 */
_reloc_region:
	mov	r3, #0
	cmp	r0, r1
	beq	_reloc_done
	blt	_rev_copy
_fwd_loop:
	cmp	r3, r2
	bge	_reloc_done
	ldmia	r0!, {r7 - r10}
	stmia	r1!, {r7 - r10}
	add	r3, r3, #16
	b	_fwd_loop
_rev_copy:
	add	r0, r0, r2
	add	r1, r1, r2
_rev_loop:
	cmp	r3, r2
	bge	_reloc_done
	ldmdb	r0!, {r7 - r10}
	stmdb	r1!, {r7 - r10}
	add	r3, r3, #16
	b	_rev_loop
_reloc_done:
	bx	lr


#ifdef BOARD_SMP
_secondary_loop:
	/* Enable the GIC CPU interface for this core */
	ldr	r0, _gic_cpu_addr
	mov	r1, #1
	str	r1, [r0]
	mov	r1, #0xFF
	str	r1, [r0, #4]
	ldr	r0, _sys_flags_addr
1:
	/* Wait for interrupt before checking SPIN_ADDR */
	wfi
	ldr	r1, [r0]
	teq	r1, #0
	/* Repeat if SPIN_ADDR == 0 */
	beq	1b
	/* Jump to the address stored the the SPIN_ADDR register */
	bx	r1

_gic_cpu_addr:
	.word	GIC_CPU_BASE
_sys_flags_addr:
	.word 	ARM_PLAT_SPIN_ADDR
#endif

	.section .expvect, "ax", %progbits
	.align 5		/* Required for VBAR */
	.globl _start_vect
_start_vect:
	ldr	pc, __reset
	ldr	pc, __undefined_instruction
	ldr	pc, __software_interrupt
	ldr	pc, __prefetch_abort
	ldr	pc, __data_abort
	ldr	pc, __not_used
	ldr	pc, __irq
	ldr	pc, __fiq
__reset:
	.word _reset
__undefined_instruction:
	.word _undefined_instruction
__software_interrupt:
	.word _software_interrupt
__prefetch_abort:
	.word _prefetch_abort
__data_abort:
	.word _data_abort
__not_used:
	.word _not_used
__irq:
	.word _irq
__fiq:
	.word _fiq
	.global _end_vect
_end_vect:

__svc_stack_end:
	.word _svc_stack_end
__und_stack_end:
	.word _und_stack_end
__abt_stack_end:
	.word _abt_stack_end
__irq_stack_end:
	.word _irq_stack_end
__fiq_stack_end:
	.word _fiq_stack_end
__usr_stack_end:
	.word _usr_stack_end

	.globl _reset
_reset:
	/* Clear a register for temporary usage */
	mov	r8, #0
	/* Disable IRQ & FIQ */
	cpsid if
	/* Set Supervisor Mode Stack */
	SET_CURRENT_MODE CPSR_MODE_SUPERVISOR
	SET_CURRENT_STACK __svc_stack_end
	/* Set Undefined Mode Stack */
	SET_CURRENT_MODE CPSR_MODE_UNDEFINED
	SET_CURRENT_STACK __und_stack_end
	/* Set Abort Mode Stack */
	SET_CURRENT_MODE CPSR_MODE_ABORT
	SET_CURRENT_STACK __abt_stack_end
	/* Set IRQ Mode Stack */
	SET_CURRENT_MODE CPSR_MODE_IRQ
	SET_CURRENT_STACK __irq_stack_end
	/* Set FIQ Mode Stack */
	SET_CURRENT_MODE CPSR_MODE_FIQ
	SET_CURRENT_STACK __fiq_stack_end
	/* Set System Mode Stack */
	SET_CURRENT_MODE CPSR_MODE_SYSTEM
	SET_CURRENT_STACK __usr_stack_end
	/* Set to Supervisor Mode */
	SET_CURRENT_MODE CPSR_MODE_SUPERVISOR
	/* Call init function */
	bl	arm_init
	/* Call main function */
	bl	arm_main
	/* We should never reach here */
	b	.

	.globl _switch_to_user_mode
_switch_to_user_mode:
	sub	r0, sp
	mov	r1, lr
	SET_CURRENT_MODE CPSR_MODE_USER
	mov	sp, r0
	mov	lr, r1
	bx	lr

START_EXCEPTION_HANDLER _undefined_instruction, 4
	PUSH_USER_REGS
	CALL_EXCEPTION_CFUNC do_undefined_instruction
	PULL_USER_REGS
END_EXCEPTION_HANDLER

/**********************************************************************
 *
 **********************************************************************/
_software_interrupt:
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
  bhi _software_interrupt_skip_kernel_enter

#if WITH_MEMORY_PROTECTION == YES
  stmfd sp!, {r3}    /* r3 must not be altered : it contains service s identifier */
  bl tpl_mp_kernel_enter
  ldmfd sp!, {r3}
#endif /* WITH_MEMORY_PROTECTION == YES */

  /* reset tpl_kern variables */
  ldr r1, =tpl_kern
  mov r2, #NO_NEED_SWITCH
  strb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]

_software_interrupt_skip_kernel_enter:
  /*********************************
   * SYSTEM CALL DISPATCHING STAGE *
   *********************************/
  /* WARNING : r3 should not be altered until here
   * as it is used to give the service identifier while calling swi
   */
  cmp r3, #SYSCALL_COUNT
  bhs _software_interrupt_invalid_service_id

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
	@TRACEKERN
  ldr r2, =tpl_kern
  ldrb r2, [r2, #TPL_KERN_OFFSET_NEED_SWITCH]
  cmp r2, #NO_NEED_SWITCH
  beq _software_interrupt_no_context_switch_exit

  /* do not switch context nor do kernel exit if nested kernel entrance */
  ldr r2, =nested_kernel_entrance_counter
  ldr r2, [r2]
  cmp r2, #1
  bhi _software_interrupt_skip_kernel_exit

  /***************************
   * CONTEXT SWITCHING STAGE *
   ***************************/
_software_interrupt_context_switch_swi:
	@TRACE trace_0_
  /* load the tpl_kern base address */
  ldr r1, =tpl_kern

  /* do we need to save the context ? if not, jump to load */
  mov r0, #0	/* set save parameter to 0 */
	@TRACEREG r0
  ldrb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
	@TRACEREG r0
  tst r2, #NEED_SAVE
	@TRACEREG r0
  beq _software_interrupt_skip_save_context_swi
  mov r0, #1	/* set save parameter to 1 */
	@TRACE trace_0__

  /*
   * SAVES OLD CONTEXT
   */
_software_interrupt_save_context_swi:
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
  b _software_interrupt_load_context_swi       /* jump to suite */

  /* only executed if context saving step has not been done */
_software_interrupt_skip_save_context_swi:
	@TRACEREG r0
	@TRACE trace_0___
	@TRACEREG r0

  add sp, sp, #(5 * 4) /* discards kernel enter stack frame */

  /*
   * LOADS NEW CONTEXT
   */
_software_interrupt_load_context_swi:
	@TRACE trace_0_
_software_interrupt_call_tpl_run_elected_swi:
  /* First call tpl_run_elected with the value of tpl_kern.need_switch
   * and get the value of the elected task.
   * tpl_kern.need_switch (stored into r3) is copied into r0
   */
	@TRACEREG r0
  bl tpl_run_elected
	@TRACE trace_1

#if WITH_MEMORY_PROTECTION == YES
	bl tpl_mp_kernel_exit
#endif

	@TRACE trace_2

  /* We updates kernel reentrance counter while registers are freely
   * usable and as we know we won't enter in kernel again (IRQ locked and
   * no SWI can occur) */
  ldr r3, =nested_kernel_entrance_counter
  ldr r2, [r3]
  sub r2, r2, #1
  str r2, [r3]

	@TRACE trace_3

  /* Get the context block address.
   *
   * We use r14 as it will be restored separatly and later, it
   * is useful for the following ldmia instruction
   */
  ldr r1, =tpl_kern
	@TRACEREG r1
  ldr lr, [r1, #TPL_KERN_OFFSET_S_RUNNING] /* get the address of the context bloc */
	@TRACEREG lr
  ldr lr, [lr]                   /* jump to context bloc (from static descriptor) */
	@TRACE trace_4
	@TRACEREG lr


  /* loads SPSR*/
  ldr r0, [lr, #(16 * 4)]
  msr spsr, r0
	@TRACE trace_5
	@TRACEREG r0

  /* finish load and get back to running task */
#if !defined NO_OKI_PIPELINE_BUG
	@TRACE trace_6
  ldmia lr, {r0-r14}^
	@TRACE trace_7
  b _software_interrupt_flush_pipeline_swi
_software_interrupt_flush_pipeline_swi:
	@TRACE trace_8
  ldr lr, [lr, #(15 * 4)]
	@TRACE trace_9
	@TRACEREG lr
  movs pc, lr
#else
	@TRACE trace_10
  ldmia lr, {r0-r15}^
#endif /* defined NO_OKI_PIPELINE_BUG */

  /********************************************
   * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
   ********************************************/
_software_interrupt_invalid_service_id:  /* currently, if invalid service id is specified, we do nothing */
_software_interrupt_no_context_switch_exit:
	@TRACE trace_11
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

_software_interrupt_skip_kernel_exit:
	@TRACE trace_12
  /* pops the kernel enter stack frame */
  ldmfd sp!, {r3}
  msr spsr, r3
  ldmfd sp!, {r0-r2,lr}

  movs pc, lr
_software_interrupt_end:
@START_EXCEPTION_HANDLER _software_interrupt, 4
@	PUSH_USER_REGS
@	CALL_EXCEPTION_CFUNC do_software_interrupt
@	PULL_USER_REGS
@END_EXCEPTION_HANDLER

/**********************************************************************
 *
 **********************************************************************/
START_EXCEPTION_HANDLER _prefetch_abort, 4
	PUSH_USER_REGS
	CALL_EXCEPTION_CFUNC do_prefetch_abort
	PULL_USER_REGS
END_EXCEPTION_HANDLER

START_EXCEPTION_HANDLER _data_abort, 8
	PUSH_USER_REGS
	CALL_EXCEPTION_CFUNC do_data_abort
	PULL_USER_REGS
END_EXCEPTION_HANDLER

START_EXCEPTION_HANDLER _not_used, 4
	PUSH_USER_REGS
	CALL_EXCEPTION_CFUNC do_not_used
	PULL_USER_REGS
END_EXCEPTION_HANDLER

@START_EXCEPTION_HANDLER _irq, 4
@	PUSH_USER_REGS
@	CALL_EXCEPTION_CFUNC do_irq
@	PULL_USER_REGS
@END_EXCEPTION_HANDLER

_irq:
	@TRACE trace_0
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
	@TRACE trace_1
	CALL_EXCEPTION_CFUNC do_irq
	@TRACE trace_2

#if WITH_MEMORY_PROTECTION == YES
  bl tpl_mp_kernel_exit
#endif

  /***************************************************
   * on the way to exit IRQ routine (with or without *
   * context switch)                                 *
   ***************************************************/
_irq_context_switch_irq:
  /* load the tpl_kern base address */
  ldr r1, =tpl_kern

  /* then, do we need to switch context ? */
  ldr r2, =tpl_kern
  mov r0, #0	/* set save parameter to 0 */
  ldrb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
  cmp r2, #NO_NEED_SWITCH
  beq _irq_no_context_switch
  mov r0, #1	/* set save parameter to 1 */

  /*
   * SAVES OLD CONTEXT
   */

  /* do we need to save the context ? if not, jump to load */
  ldrb r2, [r1, #TPL_KERN_OFFSET_NEED_SWITCH]
  tst r2, #NEED_SAVE
  beq _irq_skip_save_context_irq

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

  b _irq_load_context_irq

  /* only executed if context saving step has not been done */
_irq_skip_save_context_irq:
  add sp, sp, #(8 * 4) /* skip saved register frame (8 = r0-r3 + r9 + r11 + r12 + r14) */

_irq_load_context_irq:

_irq_call_tpl_run_elected_irq:
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
  b _irq_flush_pipeline_irq
_irq_flush_pipeline_irq:
  ldr lr, [lr, #(15 * 4)]

  movs pc, lr
#else
  ldmia lr, {r0-r15}^
#endif /* defined NO_OKI_PIPELINE_BUG */

  /********************************************
   * KERNEL EXIT WITHOUT CONTEXT SWITCH STAGE *
   ********************************************/
_irq_no_context_switch:
  /* manage reentrance of kernel */
  ldr r3, =nested_kernel_entrance_counter
  ldr r2, [r3]
  sub r2, r2, #1
  str r2, [r3]
	/* restore caller-saved registers */
	ldmfd sp!, {r0-r3,r9,r11,ip,lr}
	/* LR is 4 bytes far after return address */
	add lr, lr, #4
	/* return to interrupted task */
	subs pc,lr,#4
	@movs pc,lr
_irq_end:

START_EXCEPTION_HANDLER _fiq, 4
	PUSH_FIQUSER_REGS
	CALL_EXCEPTION_CFUNC do_fiq
	PULL_USER_REGS
END_EXCEPTION_HANDLER

/**
 * @file tpl_machine_armadeus_apf27_asm.s
 *
 * @section descr File description
 *
 * Low level part of ARMADEUS-APF27 platform
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
#include "tpl_app_objects.h"

/* TODO for prefect and data abort handler with
 * memory protection
#ifdef WITH_AUTOSAR
#include "../autosar/tpl_as_definitions.h"
#include "../autosar/tpl_as_protec_hook.h"
#endif
*/


.set prefetch_abort, 1
.set data_abort, 2
.set undefined_instruction, 3
.set unused, 4


.set OFFSET_PROC_VAR, 0
.set OFFSET_PROC_STACK, 4
.set OFFSET_OSAP_VAR, 8
.set OFFSET_RUNNING_ID, 16

/* The bootstrap stack needs to be located in internal SRAM because
 * we don't need to configure it to use it */
.section bootstrap_stack
.align 2
bootstrap_stack_top:
.space 1024 * 4
bootstrap_stack_bottom:

.section .osVar
.align 2

/* containts the address of the instruction which caused exception (abort,
 * pfabord, undef) */
.global faulty_instruction
faulty_instruction:
	.word 0

/* contains the CPSR value at the time of the fault (abord, pfabord, undef) */
.global saved_psr
saved_psr:
	.word 0

/* contains the stack pointer at the time of the fault */
.global interrupted_stack_pointer
interrupted_stack_pointer:
	.word 0

/* TODO This code is here just for demo of the
 * memory protection work*/
/**********************************/
/* This table receive abort information */ 
.global mp_abort_table
mp_abort_table:
.space 256 * 4

.global mp_abort_table_entry
mp_abort_table_entry:
	.word mp_abort_table
 /*********************************/
 
.section .osCode
.align 2

/* this macro locks interrupts before hanging down in a loop */
.macro lock_interrupts
	stmfd sp!, {r0}
	mrs r0, cpsr
	orr r0, r0, #(CPSR_FIQ_LOCKED | CPSR_IRQ_LOCKED)
	msr cpsr_c, r0
	ldmfd sp!, {r0}
.endm

/* this macro decodes some informations about an exception (abort, undef) */
.macro decode_exception exception_type
	stmfd sp!, {r0, r1, r2}

	/* get the faulty PC */
.if (\exception_type == data_abort)
	sub r0, lr, #8
.else
  sub r0, lr, #4
.endif
	ldr r1, =faulty_instruction
	str r0, [r1]

	/* get the faulty CPSR */
	mrs r0, spsr
	ldr r1, =saved_psr
	str r0, [r1]

  /* get stack pointer from faulty mode */
	mrs r0, cpsr /* save current mode */
	mrs r1, spsr
	and r1, r1, #PSR_MODE_MASK
	bic r2, r0, #PSR_MODE_MASK
	orr r2, r2, r1
	msr cpsr, r2
	ldr r1, =interrupted_stack_pointer
	str sp, [r1]
	msr cpsr, r0

	ldmfd sp!, {r0, r1, r2}
.endm

.global primary_undefined_instruction_handler
primary_undefined_instruction_handler:
  lock_interrupts
  decode_exception undefined_instruction
  b .

.global tpl_arm_subarch_prefetch_abort_handler
tpl_arm_subarch_prefetch_abort_handler:
  /*decode_exception prefetch_abort*/  
  /*b .*/ 
 
  /* TODO This code is here just for demo of the
   * memory protection work */
  /* Save registers used by the data abort */
	stmfd sp!, {r0-r2, lr}

	/* Get status code fault from the "Instruction Fault Status Register */
	mrc p15, 0, r0, c5, c0, 1
	and r0, r0, #0xF

	/* Set id_bits with the value of current id process*/
	orr r0, r1, LSL #8

	/* Set flag of prefetch abort */
	mov r1, #prefetch_abort
	orr r0, r1, LSL #4
	bl store_into_mp_abort_table
	
	/*  Get the fault address from the Fault Address Register */
	mrc p15, 0, r0, c6, c0, 0
	
	bl store_into_mp_abort_table
	
	/*  Restore saved registers */
	ldmfd sp!, {r0-r2, lr}
	
	mov pc,lr
  

.global tpl_arm_subarch_data_abort_handler
tpl_arm_subarch_data_abort_handler:
  
  /*decode_exception data_abort*/
  /*b .*/
    /* TODO This code is here just for demo of the
   * memory protection work */
  /* Save registers used by the data abort */
	stmfd sp!, {r0-r2, lr}
	
	/* Get the id of the running porcess wich generate prefetch abort */	
	ldr r2, =tpl_kern
	ldr r1, [r2, #OFFSET_RUNNING_ID] 
									  								  
	/* Get status code fault from the "Instruction Fault Status Register */
	mrc p15, 0, r0, c5, c0, 0
	and r0, r0, #0xF
	
	/* Set id_bits with the value of current id process*/
	orr r0, r1, LSL #8
	
	/* Set flag of data abort */
	mov r1, #data_abort
	orr r0, r1, LSL #4

	bl store_into_mp_abort_table
	
	/*  Get the fault address from the Fault Address Register */
	mrc p15, 0, r0, c6, c0, 0
	
	bl store_into_mp_abort_table
	
	/*  Restore saved registers */
	ldmfd sp!, {r0-r2, lr}
	mov pc,lr

.global store_into_mp_abort_table
store_into_mp_abort_table:
  /* Load the current mp_abort_table entry address */
  ldr r2, =mp_abort_table_entry
  ldr r1, [r2]
 
  /* Get the address just after the mp_abort_table */
  ldr r2, =mp_abort_table
  add r2, r2, #(256 * 4)
  cmp r1, r2
 
  /* If mp_abort_table is full execution is block in infinity loop */ 
  beq .
  /* Store information inside the mp_abort_table */
  str r0, [r1]
  
  ldr r2, =mp_abort_table_entry
  add r1, r1, #0x4
  str r1, [r2]
  
  mov pc,lr

.global primary_unused_handler
primary_unused_handler:
  lock_interrupts
  decode_exception unused
  b .

/* FIQ not defined in this port version */
.global tpl_primary_fiq_handler
tpl_primary_fiq_handler:
	subs pc, lr, #4

.global tpl_arm_bootstrap_entry
tpl_arm_bootstrap_entry:

	/* jump to the generic arm bootstrap*/
	bl tpl_arm_bootstrap_generic
    
	/* jump to high level bootstrap part */
	b tpl_arm_bootstrap_stage2

/* Control register c1
 * Enable align address condrol, 'A' bit
 * Enable MMU, 'M' bit
 */
.global tpl_enable_memory_protection
tpl_enable_memory_protection:
	/* TODO this could be done at initialization */
	/* Set domain 0 as client - it's only the one used here - */
	mrc p15, 0, r2, c3, c0, 0
	mov r2, #0x1					
	mcr p15, 0, r2, c3, c0, 0
	
	/* Flush TLB */
	mcr p15, 0, r2, c8, c7, 0

	/* Set the A and M bits */
	mrc p15, 0, r2, c1, c0, 0	
	orr r2, r2, #0b11
	mcr p15, 0, r2, c1, c0, 0
	b pipeline_flush

.global tpl_disable_memory_protection
tpl_disable_memory_protection:
	/* Unset the A and M bits */
	mrc p15, 0, r2, c1, c0, 0
	bic r2, r2, #0b11
	mcr p15, 0, r2, c1, c0, 0
	b pipeline_flush

.global tpl_switch_memory_protection_context
tpl_switch_memory_protection_context:
	/* Set the translation table base address */
	ldr r1, [r0, #OFFSET_RUNNING_ID]	/* get the ID of the running process */
	
		/* get the address of the table of all translation table base address*/
	ldr r2, =ttb_table
	add r2, r2, r1, LSL #2			/* get the good translation table base address */
	ldr r2, [r2]
	mcr p15, 0, r2, c2, c0, 0		/* set the system with this new base address */
	b pipeline_flush


/* Flush pipeline for the next instruction use 
 * the good memory translation path */		
pipeline_flush:
	mov pc, lr	
	

/* We want tpl_sleep not to use stack. Writing in assembler make us able to
 * prevent this. */
.global tpl_sleep
tpl_sleep:
  /* halts CPU */
#ifdef DISABLED_FOR_DEBUG_FACILITY 
 /* TODO */
#endif
  /* falls into infinite loop */
	b .

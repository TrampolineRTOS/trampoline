/**
 * @file olimex_exception_catch.S
 *
 * @section descr File description
 *
 * ARM exceptions catching. Default behavior has been choosen to
 * help debugging.
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

#include "../../../tpl_asm_definitions.h"

.set prefetch_abort, 1
.set data_abort, 2
.set undefined_instruction, 3
.set unused, 4

#define OS_START_SEC_VAR
#include "tpl_as_memmap.h"

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

#define OS_STOP_SEC_VAR
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

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
    and r1, r1, #0x1f
  bic r2, r0, #0x1f
    orr r2, r2, r1
    msr cpsr, r2
    ldr r1, =interrupted_stack_pointer
    str sp, [r1]
    msr cpsr, r0

    ldmfd sp!, {r0, r1, r2}
.endm

.global primary_undefined_instruction_handler_etiq
primary_undefined_instruction_handler_etiq:
  lock_interrupts
  decode_exception undefined_instruction
  b .

.global primary_prefetch_abort_handler
primary_prefetch_abort_handler:
  lock_interrupts
  decode_exception prefetch_abort
  b .

.global primary_data_abort_handler
primary_data_abort_handler:
  lock_interrupts
  decode_exception data_abort
  b .

.global primary_unused_handler
primary_unused_handler:
  lock_interrupts
  decode_exception unused
  b .

/* FIQ not defined in this port version */
.global tpl_primary_fiq_handler
tpl_primary_fiq_handler:
  subs pc, lr, #4

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file olimx_exception_catch.S */

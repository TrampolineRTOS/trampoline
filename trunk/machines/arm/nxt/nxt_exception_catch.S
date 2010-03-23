/**
 * @file nxt_exception_catch.S
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

#include "../tpl_asm_definitions.h"

.set prefetch_abort, 1
.set data_abort, 2
.set undefined_instruction, 3
.set unused, 4

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/* this macro locks interrupts before hanging down in a loop */
.macro lock_interrupts_and_display_info exception_type
    stmfd sp!, {r0}
    mrs r0, cpsr
    orr r0,r0, #(CPSR_FIQ_LOCKED | CPSR_IRQ_LOCKED)
    msr cpsr_c, r0
    ldmfd sp!, {r0}
    
    /* get the faulty CPSR */
    mrs r0, spsr
    ldr r1, =saved_psr
    str r0, [r1]
    
    /* get the faulty pc */
    ldr r0,=exception_catch_pc
    str lr,[r0]
    
    /* saved the exception catch id */
    ldr r0,=exception_catch_id
    mov r1, #\exception_type
    str r1,[r0]    

    /* display pc and msr on th display */
    bl exception_catch_display
.endm

/* TODO : dislpay exception (not just pc) : undef, prefetch abort, data abort, unused*/

.global primary_undefined_instruction_handler
primary_undefined_instruction_handler:
  lock_interrupts_and_display_info undefined_instruction

.global primary_prefetch_abort_handler
primary_prefetch_abort_handler:
  lock_interrupts_and_display_info prefetch_abort

.global primary_data_abort_handler
primary_data_abort_handler:
  lock_interrupts_and_display_info data_abort

.global primary_unused_handler
primary_unused_handler:
  lock_interrupts_and_display_info unused

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

/* End of file nxt_exception_catch.c */

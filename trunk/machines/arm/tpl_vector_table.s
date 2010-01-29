/**
 * @file tpl_vector_table.s
 *
 * @section descr File description
 *
 * Vector table for ARM platform
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
 
.section .vectbl, "ax"
.code 32
.align 2

/* Useful for olimex_lpc_e2294 */
.global Vec_reset

Vec_reset:                 ldr pc, =tpl_arm_bootstrap_entry
Vec_undefinedInstruction:  ldr pc, =primary_undefined_instruction_handler
Vec_softwareInterrupt:     ldr pc, =tpl_primary_syscall_handler
Vec_prefetchAbort:         ldr pc, =primary_prefetch_abort_handler
Vec_dataAbort:             ldr pc, =primary_data_abort_handler
Vec_unused:                .word   0xB8A06F60   /* Magic number */
Vec_interruptRequest:      ldr pc, =tpl_primary_irq_handler
Vec_fastInterruptRequest:  ldr pc, =tpl_primary_fiq_handler

.ltorg

/* End of file tpl_vector_table.s */

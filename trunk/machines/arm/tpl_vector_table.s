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

/* this section is used in linker configuration to
 * place the vector table at the right place */
.section .vectbl
 
.align 2

/* TODO: remove this */
.global Vec_reset
  
Vec_reset:                 b tpl_arm_bootstrap_entry
Vec_undefinedInstruction:  b primary_undefined_instruction_handler
Vec_softwareInterrupt:     b tpl_primary_syscall_handler
Vec_prefetchAbort:         b primary_prefetch_abort_handler
Vec_dataAbort:             b primary_data_abort_handler
Vec_unused:                b primary_unused_handler
Vec_interruptRequest:      b tpl_primary_irq_handler
Vec_fastInterruptRequest:  b tpl_primary_fiq_handler

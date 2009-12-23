/**
 * @file tpl_system_stacks.s
 *
 * @section descr File description
 *
 * Provides system stacks for generic ARM port
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

/*
 * Stacks are placed just after BSS segment as we don't need to initialize
 * them. See into ldscript file.
 */
.section stacks

.align 2

/*
 * IRQ mode stack
 */
.global irq_stack_top
irq_stack_top:
.space 4096 * 4
.global irq_stack_bottom
irq_stack_bottom:

/*
 * FIQ mode stack
 */
.global fiq_stack_top
fiq_stack_top:
.space 1024 * 4
.global fiq_stack_bottom
fiq_stack_bottom:

/*
 * Service mode stack
 */
.global svc_stack_top
svc_stack_top:
.space 4096 * 4
.global svc_stack_bottom
svc_stack_bottom:

/*
 * Abort mode stack
 */
.global abt_stack_top
abt_stack_top:
.space 256 * 4
.global abt_stack_bottom
abt_stack_bottom:

/*
 * undefined mode stack
 */
.global und_stack_top
und_stack_top:
.space 256 * 4
.global und_stack_bottom
und_stack_bottom:

/*
 * default user mode stack (used at startup and by IDLE task)
 */
.global usr_stack_top
usr_stack_top:
.space 4096 * 4
.global usr_stack_bottom
usr_stack_bottom:

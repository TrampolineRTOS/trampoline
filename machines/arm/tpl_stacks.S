/**
 * @file tpl_stacks.s
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
#include "tpl_stacks_size.h"

#define OS_START_SEC_STACKS
#include "tpl_as_memmap.h"

/*
 * IRQ mode stack
 */
.global irq_stack_top
irq_stack_top:
.space IRQ_STACK_SIZE
.global irq_stack_bottom
irq_stack_bottom:

/*
 * FIQ mode stack
 */
.global fiq_stack_top
fiq_stack_top:
.space FIQ_STACK_SIZE
.global fiq_stack_bottom
fiq_stack_bottom:

/*
 * Service mode stack
 */
.global svc_stack_top
svc_stack_top:
.space SVC_STACK_SIZE
.global svc_stack_bottom
svc_stack_bottom:

/*
 * Abort mode stack
 */
.global abt_stack_top
abt_stack_top:
.space ABT_STACK_SIZE
.global abt_stack_bottom
abt_stack_bottom:

/*
 * undefined mode stack
 */
.global und_stack_top
und_stack_top:
.space UND_STACK_SIZE
.global und_stack_bottom
und_stack_bottom:

/*
 * default user mode stack (used at startup and by IDLE task)
 */
.global usr_stack_top
usr_stack_top:
.space USR_STACK_SIZE
.global usr_stack_bottom
usr_stack_bottom:

#define OS_STOP_SEC_STACKS
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file tpl_stacks.h */

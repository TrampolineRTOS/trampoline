/**
 * @file olimex_bootstrap_stage1.S
 *
 * @section descr File description
 *
 * First part of the bootstrap for OLIMEX
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

#include "../tpl_asm_definitions.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global tpl_arm_bootstrap_entry
tpl_arm_bootstrap_entry:
  /* setup IRQ mode initial stack pointer */
  msr cpsr_c, #(CPSR_IRQ_MODE | CPSR_IRQ_LOCKED | CPSR_FIQ_LOCKED)
    ldr sp, =irq_stack_bottom

    /* setup FIQ mode initial stack pointer */
  msr cpsr_c, #(CPSR_FIQ_MODE | CPSR_IRQ_LOCKED | CPSR_FIQ_LOCKED)
    ldr sp, =fiq_stack_bottom

    /* setup service (syscall) mode initial stack pointer */
  msr cpsr_c, #(CPSR_SVC_MODE | CPSR_IRQ_LOCKED | CPSR_FIQ_LOCKED)
    ldr sp, =svc_stack_bottom

  msr cpsr_c, #(CPSR_ABT_MODE | CPSR_IRQ_LOCKED | CPSR_FIQ_LOCKED)
    ldr sp, =abt_stack_bottom

  msr cpsr_c, #(CPSR_UND_MODE | CPSR_IRQ_LOCKED | CPSR_FIQ_LOCKED)
    ldr sp, =und_stack_bottom

  /* setup user mode initial stack pointer */
  msr cpsr_c, #(CPSR_SYS_MODE | CPSR_IRQ_LOCKED | CPSR_FIQ_LOCKED)
    ldr sp, =usr_stack_bottom

  /* jump to high level bootstrap part */
  b tpl_arm_bootstrap_stage2

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file olimex_bootstrap_stage1.S */

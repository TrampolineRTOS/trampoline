/**
 * @file apf27_bootstrap_stage1.S
 *
 * @section descr File description
 *
 * First steps of bootstrap for APF27 board
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

/* to be able to boot easily with u-boot, according to the linker
 * script, we place this first instruction at a fixed address
 * (which will be the load address)
 */
.section .ubootsupport

.global tpl_arm_bootstrap_entry
tpl_arm_bootstrap_entry:
tpl_arm_bootstrap_stage1:

/* first, we copy exception table the right location */
  ldr r0, =vec_excpt_copy_begin
  ldr r1, =0xFFFFFEF0
  ldr r2, =vec_excpt_copy_end
1:
  cmp r0, r2
  beq 2f
  ldr r3, [r0], #4
  str r3, [r1], #4
  b 1b
2:

/* secondly, we copy interrupt table at the right location */
  ldr r0, =vec_int_copy_begin
  ldr r1, =0xFFFFFF00
  ldr r2, =vec_int_copy_end
3:
  cmp r0, r2
  beq 4f
  ldr r3, [r0], #4
  str r3, [r1], #4
  b 3b
4:

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


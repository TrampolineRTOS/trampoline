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

   VICIntEnClear  = 0xFFFFF014
   VICVectCntl0   = 0xFFFFF200


#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

.global tpl_arm_bootstrap_entry
tpl_arm_bootstrap_entry:

  /* wait for oscillator stability */ 
  nop
  nop
  nop
  nop
  nop
  nop
  nop
  nop
   

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

  /* do the PLL init to run at 60MHz */
  bl initialize_lpc2200_pll

/* Clear .bss section */
   ldr   r1, =common_zeroed_vars_begin
   ldr   r2, =common_zeroed_vars_end
   ldr   r3, =0
bss_clear_loop:
   cmp   r1, r2
   strne r3, [r1], #+4
   bne   bss_clear_loop

/*--- Clear interrupt control registers */
   mov   r0, #0 /* the value to write for clearing register */
   ldr   r1, =VICVectCntl0 /* Control register address */
   mov   r2, #16 /* register count */
ctrl_reg_clear_loop:
   str   r0, [r1], #4
   subs  r2, r2, #1
   bne   ctrl_reg_clear_loop

/*--- Clear all remaining interrupt enables */
/*    (they can be still enabled after a soft reset) */
   mvn   r0, #0
   ldr   r1, =VICIntEnClear
   str   r0, [r1]
  
  /* jump to high level bootstrap part */
  b tpl_arm_bootstrap_stage2

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file olimex_bootstrap_stage1.S */

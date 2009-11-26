/*
 * @file tpl_init.s
 *
 * @section desc File description
 *
 * Machine initialization functions for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OpenSource project
 * http://trampoline.rts-software.org
 *
 * Trampoline is copyright (c) IRCCyN 2005+ except for the following parts
 * Copyright ESEO for ARM7 port, function and data structures documentation
 * Copyright Geensys for hcs12 port and v8500 port
 * Trampoline is protected by the French intellectual property law.
 *
 * Trampoline/OS and Trampoline/COM are distributed under one of the
 * following license:
 * - the BSD license
 * - the LGPL V2 license.
 *
 * Goil and Viper are distributed under the GPL v2 license.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_assembler.h"

TPL_EXTERN tpl_register_r2
TPL_EXTERN tpl_register_r13
TPL_EXTERN tpl_msr_start_value

  .text
  .global tpl_init_regs
  .global tpl_shutdown
  
  .section .osCode CODE_ACCESS_RIGHT
  
tpl_init_regs:
  subi  r1,r1,4   /* space on the stack */
  stw   r3,0(r1)  /* save the working register  */
  lis   r3,TPL_HIG(tpl_register_r2)       /*  save the start value of RTOC  */
  ori   r3,r3,TPL_LOW(tpl_register_r2)
  stw   r2,0(r3)
  lis   r3,TPL_HIG(tpl_register_r13)      /*  save the start value of r13   */
  ori   r3,r3,TPL_LOW(tpl_register_r13)
  stw   r13,0(r3)
  mfmsr r0
  lis   r3,TPL_HIG(tpl_msr_start_value)   /*  save the start value of msr   */
  ori   r3,r3,TPL_LOW(tpl_msr_start_value)
  stw   r0,0(r3)
  lwz   r3,0(r1)  /*  get back the working register */
  addi  r1,r1,4   /*  release space on the stack    */
  blr

  .type tpl_init_regs,@function
  .size tpl_init_regs,$-tpl_init_regs
  
tpl_shutdown:
  mfmsr r5  /* disable the external interrupts */
  li    r6,0
  ori   r6,r6,0x8000
  neg   r6,r6
  and   r5,r5,r6
  mtmsr r5
infinite_loop:
  b     infinite_loop
    

  .type tpl_shutdown,@function
  .size tpl_shutdown,$-tpl_shutdown

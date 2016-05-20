/*
 * @file tpl_dispatch.s
 *
 * @section desc File description
 *
 * Trampoline low level function tu enable and disable interrupts
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#include "tpl_assembler.h"
#include "tpl_app_define.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"

TPL_EXTERN  tpl_current_date
TPL_EXTERN  tpl_tick_init_value
TPL_EXTERN  tpl_call_counter_tick
TPL_EXTERN  tpl_enter_kernel
TPL_EXTERN  tpl_leave_kernel
TPL_EXTERN  tpl_kern
/* TPL_EXTERN  tpl_need_switch */   /* MPC5674F_Porting_Modif : This variable or function is no longer used in this file */ 
TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN  tpl_kernel_mp
TPL_EXTERN  tpl_user_mp
TPL_EXTERN  tpl_set_process_mp



 #if (TPL_TICK_TIMER == TPL_DECREMENTER)

  .global tpl_init_dec
  .text
  .section .osCode CODE_ACCESS_RIGHT

/**
 *
 */
tpl_init_dec:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_li      r11,0
  mttbu     r11
  mttbl     r11

  /* load dec and decar register with value correcponding to tick period */
  e_lis     r11,TPL_HIG(tpl_tick_init_value)
  e_or2i    r11,TPL_LOW(tpl_tick_init_value)
  e_lwz     r11,0(r11)
  mtdec     r11
  mtdecar   r11

  /* tcr register : set DIE and ARE bits, enable dec and auto reload */
  e_lis     r11,0x0440
  mttcr     r11

  /* hid0 register : set TBEN register */
  e_li      r11,0x4000
  mthid0    r11

  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  li        r11,0
  mttbu     r11
  mttbl     r11

  /* load dec and decar register with value correcponding to tick period */
  lis       r11,TPL_HIG(tpl_tick_init_value)
  ori       r11,r11,TPL_LOW(tpl_tick_init_value)
  lwz       r11,0(r11)
  mtdec     r11
  mtdecar   r11

  /* tcr register : set DIE and ARE bits, enable dec and auto reload */
  lis       r11,0x0440
  mttcr     r11

  /* hid0 register : set TBEN register */
  li        r11,0x4000
  mthid0    r11

  blr
#endif
  .type tpl_init_dec,@function
  .size tpl_init_dec,$-tpl_init_dec


  .section  .dec_vector  CODE_ACCESS_RIGHT
tpl_dec_vector:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b         tpl_dec_handler
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b           tpl_dec_handler
#endif
  .type tpl_dec_vector,@function
  .size tpl_dec_vector,$-tpl_dec_vector


  .section  .dec_handler CODE_ACCESS_RIGHT

tpl_dec_handler:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  se_subi     r1,PS_FOOTPRINT

  e_stw       r11,PS_R11(r1)
  e_stw       r12,PS_R12(r1)
  mflr        r11
  e_stw       r11,PS_LR(r1)
  mfcr        r11
  e_stw       r11,PS_CR(r1)
  e_stw       r0,PS_R0(r1)

  e_bl        tpl_enter_kernel

  e_lis       r11,TPL_HIG(tpl_current_date)
  e_or2i      r11,TPL_LOW(tpl_current_date)
  e_lwz       r12,0(r11)
  e_addi      r12,r12,1
  e_stw       r12,0(r11)


  e_lis       r11,TPL_HIG(tpl_kern)
  e_or2i      r11,TPL_LOW(tpl_kern)
  e_stw       r11,KS_KERN_PTR(r1)            /* save the ptr for future use  */
  e_li        r0,NO_NEED_SWITCH
  e_stb       r0,20(r11)


  /*
   * as we are coming from an exception and calling a C function,
   * we have to save all volatile registers,
   * which could be altered by this call
   */

  e_subi      r1,r1,44
  e_stw       r0,0(r1)
  e_stw       r3,4(r1)
  e_stw       r4,8(r1)
  e_stw       r5,12(r1)
  e_stw       r6,16(r1)
  e_stw       r7,20(r1)
  e_stw       r8,24(r1)
  e_stw       r9,28(r1)
  e_stw       r10,32(r1)
  e_stw       r11,36(r1)
  e_stw       r12,40(r1)

  se_subi     r1,8

  /* call the counter_tick function */
  e_bl        tpl_call_counter_tick

  /*
   * restore all volatile registers
   */

  se_addi     r1,8

  e_lwz       r12,40(r1)
  e_lwz       r11,36(r1)
  e_lwz       r10,32(r1)
  e_lwz       r9,28(r1)
  e_lwz       r8,24(r1)
  e_lwz       r7,20(r1)
  e_lwz       r6,16(r1)
  e_lwz       r5,12(r1)
  e_lwz       r4,8(r1)
  e_lwz       r3,4(r1)
  e_lwz       r0,0(r1)
  e_addi      r1,r1,44

  /*
   * Check the tpl_need_switch variable
   * to see if a switch should occur
   */
  e_lwz       r11,KS_KERN_PTR(r1)
  e_lbz       r12,20(r11)
  e_andi.     r0,r12,NEED_SWITCH
  se_beq      no_context_switch

  /*
   * r3 will be destroyed by the call to tpl_save_context. It is save
   * in the ad hoc area since it is the return code of the service
   */
  e_stw       r3,KS_RETURN_CODE(r1)

  /*
   * Check if context of the task/isr that just lost the CPU needs
   * to be saved. No save is needed for a TerminateTask or ChainTask
   */
  e_andi.     r0,r12,NEED_SAVE
  se_beq      no_save

  /*
   * get the context pointer of the task that just lost the CPU
   */
  e_lwz       r3,0(r11)                     /* get s_old                    */
  e_bl        tpl_save_context

  /*
   * get the context pointer of the task that just got the CPU
   */
  e_lwz       r11,KS_KERN_PTR(r1)

no_save:

#if WITH_MEMORY_PROTECTION == YES
  /*
   * set up the memory protection for the process that just got the CPU
   */
  e_lwz       r3,16(r11)    /* get the id of the process which get the cpu  */
  e_bl        tpl_set_process_mp        /* set the memory protection scheme */
#endif

  e_lwz       r11,KS_KERN_PTR(r1)
  e_lwz       r3,4(r11)                     /* get s_running                */
  e_bl        tpl_load_context

  /*
   * r3 is restored (ie get back the return code)
   */
  e_lwz       r3,KS_RETURN_CODE(r1)

  /* TODO */
no_context_switch:
  /*
   * does the stuff to leave the kernel
   */

    /* clear DIS bit in TSR SPR */
  e_lis       r11,0x0800
  mtspr       336,r11

  e_bl        tpl_leave_kernel

  e_lwz       r0,PS_R0(r1)
  e_lwz       r11,PS_CR(r1)
  mtcr        r11
  e_lwz       r11,PS_LR(r1)
  mtlr        r11
  e_lwz       r12,PS_R12(r1)
  e_lwz       r11,PS_R11(r1)

  se_addi     r1,PS_FOOTPRINT

  se_rfi
/* ------------ NO VLE ------------------------------------------------------*/
#else
  subi      r1,r1,PS_FOOTPRINT

  stw       r11,PS_R11(r1)
  stw       r12,PS_R12(r1)
  mflr      r11
  stw       r11,PS_LR(r1)
  mfcr      r11
  stw       r11,PS_CR(r1)

  bl        tpl_enter_kernel

  lis       r11,TPL_HIG(tpl_current_date)
  ori       r11,r11,TPL_LOW(tpl_current_date)
  lwz       r12,0(r11)
  addi      r12,r12,1
  stw       r12,0(r11)


  lis       r11,TPL_HIG(tpl_kern)
  ori       r11,r11,TPL_LOW(tpl_kern)
  stw       r11,KS_KERN_PTR(r1)            /* save the ptr for future use  */
  li        r0,NO_NEED_SWITCH
  stb       r0,20(r11)


  /*
   * as we are coming from an exception and calling a C function,
   * we have to save all volatile registers,
   * which could be altered by this call
   */

  subi      r1,r1,44
  stw       r0,0(r1)
  stw       r3,4(r1)
  stw       r4,8(r1)
  stw       r5,12(r1)
  stw       r6,16(r1)
  stw       r7,20(r1)
  stw       r8,24(r1)
  stw       r9,28(r1)
  stw       r10,32(r1)
  stw       r11,36(r1)
  stw       r12,40(r1)

  subi      r1,r1,8

  /* call the counter_tick function */
  bl        tpl_call_counter_tick

  /*
   * restore all volatile registers
   */

  addi      r1,r1,8

  lwz       r12,40(r1)
  lwz       r11,36(r1)
  lwz       r10,32(r1)
  lwz       r9,28(r1)
  lwz       r8,24(r1)
  lwz       r7,20(r1)
  lwz       r6,16(r1)
  lwz       r5,12(r1)
  lwz       r4,8(r1)
  lwz       r3,4(r1)
  lwz       r0,0(r1)
  addi      r1,r1,44

  /*
   * Check the tpl_need_switch variable
   * to see if a switch should occur
   */
  lwz       r11,KS_KERN_PTR(r1)
  lbz       r12,20(r11)
  andi.     r0,r12,NEED_SWITCH
  beq       no_context_switch

  /*
   * r3 will be destroyed by the call to tpl_save_context. It is save
   * in the ad hoc area since it is the return code of the service
   */
  stw       r3,KS_RETURN_CODE(r1)

  /*
   * Check if context of the task/isr that just lost the CPU needs
   * to be saved. No save is needed for a TerminateTask or ChainTask
   */
  andi.     r0,r12,NEED_SAVE
  beq       no_save

  /*
   * get the context pointer of the task that just lost the CPU
   */
  lwz       r3,0(r11)                     /* get s_old                    */
  bl        tpl_save_context

  /*
   * get the context pointer of the task that just got the CPU
   */
  lwz       r11,KS_KERN_PTR(r1)

no_save:

#if WITH_MEMORY_PROTECTION == YES
  /*
   * set up the memory protection for the process that just got the CPU
   */
  lwz       r3,16(r11)    /* get the id of the process which get the cpu  */
  bl        tpl_set_process_mp        /* set the memory protection scheme */
#endif

  lwz       r11,KS_KERN_PTR(r1)
  lwz       r3,4(r11)                     /* get s_running                */
  bl        tpl_load_context

  /*
   * r3 is restored (ie get back the return code)
   */
  lwz       r3,KS_RETURN_CODE(r1)

  /* TODO */
no_context_switch:
  /*
   * does the stuff to leave the kernel
   */

    /* clear DIS bit in TSR SPR */
  lis       r11,0x0800
  mtspr     336,r11

  bl        tpl_leave_kernel

  lwz       r11,PS_CR(r1)
  mtcr      r11
  lwz       r11,PS_LR(r1)
  mtlr      r11
  lwz       r12,PS_R12(r1)
  lwz       r11,PS_R11(r1)

  addi      r1,r1,PS_FOOTPRINT

  rfi
#endif

  .type tpl_dec_handler,@function
  .size tpl_dec_handler,$-tpl_dec_handler


#else


  .section  .dec_vector  CODE_ACCESS_RIGHT
tpl_dec_vector:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b         tpl_dec_vector
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b           tpl_dec_vector
#endif
  .type tpl_dec_vector,@function
  .size tpl_dec_vector,$-tpl_dec_vector


#endif


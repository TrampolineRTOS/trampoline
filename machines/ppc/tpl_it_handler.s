/*
 * @file tpl_it_handler.s
 *
 * @section desc File description
 *
 * Trampoline external interrupt handler for PowerPC port
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

#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_assembler.h"

TPL_EXTERN  tpl_stat_proc_table
TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN  tpl_unset_mp
TPL_EXTERN  tpl_kern
TPL_EXTERN  tpl_kernel_stack_bottom

  .text
  .section  ".EI_handler","ax"
  .global tpl_it_handler
  
/*
 * tpl_it_handler should be called directly from the external interrupt
 * vector by an unconditional branch (relative or absolute)
 *
 * tpl_it_handler switches on the system stack and saves the registers
 * in the context of the process that was running when the interrupt was got
 * then it calls tpl_central_interrupt_handler
 * at last it restores the registers from the context of the current running
 * process (which might be different since tpl_central_interrupt_handler may
 * do a rescheduling).
 */
tpl_it_handler:

  /*
   * When entering tpl_it_handler, we are on a process stack. Since
   * some registers are needed to work, they are saved on the process stack
   * using the same scheme as in a system call function
   *  
   *          |              |
   *          +--------------+
   *  SP-> +0 |      r11     |
   *          +--------------+
   *       +4 |      r12     |
   *          +--------------+
   *       +8 |      lr      |
   *          +--------------+
   *      +12 |      cr      |
   *          +--------------+
   *      +16 |      r0      |
   *          +--------------+
   */
  subi  r1,r1,20
  stw   r11,0(r1)
  stw   r12,4(r1)
  mflr  r11
  stw   r11,8(r1)
  mfcr  r11
  stw   r11,12(r1)
  stw   r0,16(r1)
  
  /*        bl   tpl_unset_mp */ /* disable memory protection    */

  /*
   * Switch to the kernel stack
   */  
  lis   r11,TPL_HIG(tpl_kernel_stack_bottom)      /* get the kernel           */
  ori   r11,r11,TPL_LOW(tpl_kernel_stack_bottom)  /* stack bottom ptr         */
  subi  r11,r11,KS_FOOTPRINT  /* make space on the stack to call C functions  */
  stw   r1,KS_SP(r11)         /*  save the sp of the caller                   */
  mr    r1,r11                /*  set the kernel stack                        */
  stw   r3,KS_RETURN_CODE(r1) /* save r3                                      */
  /*
   * Save SRR0 and SRR1 filled by the sc done by the caller
   * in the kernel stack. Needed to allow sc in hooks
   */
  mfspr r11,spr_SRR0
  stw   r11,KS_SRR0(r1)
  mfspr r11,spr_SRR1
  stw   r11,KS_SRR1(r1)
  
  /*
   * Save the context of the running process.
   */
  lis   r11,TPL_HIG(tpl_kern)
  ori   r11,r11,TPL_LOW(tpl_kern)
  stw   r11,KS_KERN_PTR(r1) /* save the ptr for future use  */
  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the handler This is needed because, beside tpl_schedule,
   * no service modify this variable. So an old value is retained
   */
  li    r12,NO_NEED_SWITCH
  stb   r12,20(r11)
  
  /*
   * Save the context of the interrupted process
   * The pointer to the context is in r3
   */  
  lwz   r3,0(r11)           /* get the context pointer      */
  bl    tpl_save_context

  /*
   * Get a pointer to the it vector
   */
  lis   r11,TPL_HIG(tpl_it_vector)
  ori   r11,r11,TPL_LOW(tpl_it_vector)
  /*
   * Here we need a way to get the id of the it. It depends on the
   * interrupt controller. For testing we put a constant
   */
  li    r12,5
  slwi  r12,r12,2
  lwz   r0,r11,r12
  /*  Call the IT routine */
  mtlr  r0
  blrl
  
  /*  test tpl_need_switch to see if a rescheduling occured                 */
  lis   r11,TPL_HIG(tpl_kern)
  ori   r11,r11,TPL_LOW(tpl_kern)
  lbz   r12,0(r11)
  andi. r12,r12,NEED_SWITCH
  beq   no_context_switch

  /* HERE WE SHOULD HAVE THE CONTEXT SWITCH FOR FP REGISTERS                */

no_context_switch:

  lwz   r11,KS_KERN_PTR(r1)
  /*
   * load the context of the running process. The pointer to the context
   * is in r3
   */
  lwz   r3,4(r11)                         /* get the context pointer        */
  bl    tpl_load_context
  /*
   * Restore the SRR0 and SRR1 saved in the system stack
   */
  lwz   r11,KS_SRR0(r1)
  mtspr spr_SRR0,r11
  lwz   r11,KS_SRR1(r1)
  mtspr spr_SRR1,r11

  /*  Get back registers that was saved in the system stack                 */
  lwz   r3,KS_RETURN_CODE(r1)             /* get r3                         */
  lwz   r1,KS_SP(r1)                      /* Restore the SP                 */

  /*  restore the registers befor returning                           */
  lwz   r0,16(r1)
  lwz   r11,12(r1)
  mtcr  r11
  lwz   r11,8(r1)
  mtlr  r11
  lwz   r12,4(r1)
  lwz   r11,0(r1)
  
  addi  r1,r1,20
  
  rfi

  .type tpl_it_handler,@function
  .size tpl_it_handler,$-tpl_it_handler
  
/*
 * @file tpl_protection.S
 *
 * @section desc File description
 *
 * Trampoline protection hook wrapper
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

#include "tpl_os_kernel_stack.h"
#include "tpl_assembler.h"
#include "tpl_os_definitions.h"
#include "tpl_as_definitions.h"

TPL_EXTERN 	tpl_enter_kernel
TPL_EXTERN 	tpl_leave_kernel
TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN	tpl_call_protection_hook
TPL_EXTERN	tpl_set_process_mp
TPL_EXTERN 	tpl_kern

  .text
  .section .osCode CODE_ACCESS_RIGHT
  
/**
 * tpl_protection_hook_wrapper is called when an exception
 * related to protection (like memory protection for instance)
 * is encountered
 */
  .global tpl_protection_hook_wrapper
tpl_protection_hook_wrapper:
  /*
   * When entering tpl_protection_hook_wrapper, we are on a process stack.
   * Since some registers are needed to work, they are saved on the process
   * stack using the same scheme as in a system call function. We must be able
   * to return back to the process that triggered the exception because the
   * the ProtectionHook may return PRO_IGNORE.
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
  
  /*
   * Does the stuff to enter in kernel
   */
  bl    tpl_enter_kernel

  /*
   * Save r3 in the kernel stack. It is from here it will be get to be saved
   * in the context of the interrupted process
   */
  stw   r3,KS_RETURN_CODE(r1)
  
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
  lwz   r3,4(r11)           /* get the context pointer      */
  bl    tpl_save_context

  /*
   * call tpl_call_protection_hook with E_OS_PROTECTION_MEMORY as parameter
   */
  li    r3,E_OS_PROTECTION_MEMORY
  bl    tpl_call_protection_hook

  /*
   * test tpl_need_switch to see if a rescheduling occured
   */
  lwz   r11,KS_KERN_PTR(r1)
  lbz   r12,0(r11)
  andi. r12,r12,NEED_SWITCH
  
  beq   no_context_switch

#if WITH_FLOAT == YES
  /*
   * TODO: HERE WE SHOULD HAVE THE CONTEXT SWITCH FOR FP REGISTERS
   */
#endif

#if WITH_MEMORY_PROTECTION == YES
  lwz   r11,KS_KERN_PTR(r1)
  lwz   r3,16(r11)    /* get the id of the process which get the cpu  */
  bl    tpl_set_process_mp        /* set the memory protection scheme */
#endif

no_context_switch:

  /*
   * load the context of the running process. The pointer to the context
   * is in r3
   */
  lwz   r11,KS_KERN_PTR(r1)
  lwz   r3,4(r11)                         /* get s_running            */
  bl    tpl_load_context

  /*
   * Get back registers that was saved in the system stack
   */
  lwz   r3,KS_RETURN_CODE(r1)             /* get r3                   */

  /*
   * does the stuff to leave the kernel
   */
  bl    tpl_leave_kernel

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

  .type tpl_protection_hook_wrapper,@function
  .size tpl_protection_hook_wrapper,$-tpl_protection_hook_wrapper

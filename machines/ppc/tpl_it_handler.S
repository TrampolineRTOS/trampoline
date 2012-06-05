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
#include "tpl_os_process_stack.h"
#include "tpl_assembler.h"

TPL_EXTERN  tpl_kern
TPL_EXTERN  tpl_it_table

TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN  tpl_kernel_mp
TPL_EXTERN  tpl_user_mp
TPL_EXTERN  tpl_set_process_mp
TPL_EXTERN  tpl_enter_kernel
TPL_EXTERN  tpl_leave_kernel
TPL_EXTERN  tpl_it_id

  .text
  .section  .EI_vector CODE_ACCESS_RIGHT
tpl_it_vector:
  b     tpl_it_handler
  
  .section  .EI_handler CODE_ACCESS_RIGHT
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
  subi  r1,r1,PS_FOOTPRINT
  stw   r11,PS_R11(r1)
  stw   r12,PS_R12(r1)
  mflr  r11
  stw   r11,PS_LR(r1)
  mfcr  r11
  stw   r11,PS_CR(r1)
  stw   r0,PS_R0(r1)
  
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
   * Get the id of the interrupt
   * (it is returned in r3)
   */
  bl    tpl_it_id

  /*
   * Get a pointer to the it table
   * This table is generated an can be found in tpl_app_config.c file
   */
  lis   r11,TPL_HIG(tpl_it_table)
  ori   r11,r11,TPL_LOW(tpl_it_table)
  /*
   * convert the it id to an offset. Each entry of the tpl_it_vector
   * uses 2 x 4 bytes words on a 32 bits PowerPC. The first word
   * id the function pointer of the it handler. The second word is
   * its parameter (so it is loaded in r3)
   */
  slwi  r12,r3,3
  lwzx  r0,r11,r12
  addi  r12,r12,4
  mtlr  r0
  lwzx  r3,r11,r12
  /*
   * Call the IT routine
   */
  blrl
  
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
  lwz   r0,PS_R0(r1)
  lwz   r11,PS_CR(r1)
  mtcr  r11
  lwz   r11,PS_LR(r1)
  mtlr  r11
  lwz   r12,PS_R12(r1)
  lwz   r11,PS_R11(r1)
  
  addi  r1,r1,PS_FOOTPRINT
  
  rfi

  .type tpl_it_handler,@function
  .size tpl_it_handler,$-tpl_it_handler
  
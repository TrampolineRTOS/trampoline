/*
 * @file tpl_dispatch.s
 *
 * @section desc File description
 *
 * Trampoline dispatch level for PowerPC port
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

#include "tpl_service_ids.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"
#include "tpl_assembler.h"

TPL_EXTERN  tpl_dispatch_table
TPL_EXTERN  tpl_kern
TPL_EXTERN  tpl_need_switch

TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN  tpl_kernel_mp
TPL_EXTERN  tpl_user_mp
TPL_EXTERN  tpl_set_process_mp

  .global tpl_kernel_stack
  .global tpl_kernel_stack_bottom
  .global tpl_sc_handler
  .global tpl_enter_kernel
  .global tpl_leave_kernel
  .global tpl_reentrancy_counter
  
  .data
  .align  4
/*
 * The kernel stack. When a system call is done, the sc handler switches
 * to the kernel stack.
 */
  .section .osVar VAR_ACCESS_RIGHT
tpl_kernel_stack:
  .space  KERNEL_STACK_SIZE
tpl_kernel_stack_bottom:
/*
 * A reentrency counter to track system calls made from
 * hook routines
 */
  .align  4
tpl_reentrancy_counter:
  .long   0

  .text
  .section .osCode CODE_ACCESS_RIGHT
  
/**
 * tpl_enter_kernel does all the stuff to switch from
 * the context of the running process to the context
 * of the kernel
 * - it switches to the kernel stack if needed
 * - it saves registers on the kernel stack
 */
tpl_enter_kernel:

#if WITH_MEMORY_PROTECTION == YES
  /*
   * Switch to kernel mem protection scheme
   */
  subi  r1,r1,4
  mflr  r11
  stw   r11,0(r1)       /* save lr on the current stack */
  bl    tpl_kernel_mp   /* disable memory protection    */
  lwz   r11,0(r1)       /* restore lr                   */
  mtlr  r11
  addi  r1,r1,4
#endif
  
   /* Check the reentrency counter value and inc it
   * if the value is 0 before the inc, then we switch to
   * the system stack.
   */
  lis   r11,TPL_HIG(tpl_reentrancy_counter)
  ori   r11,r11,TPL_LOW(tpl_reentrancy_counter)
  lwz   r12,0(r11)    /*  get the value of the counter */
  cmpwi r12,0
  addi  r12,r12,1
  stw   r12,0(r11)
  bne   no_stack_change
  
  /*
   * Switch to the kernel stack
   */  
  lis   r11,TPL_HIG(tpl_kernel_stack_bottom)      /* get the kernel   */
  ori   r11,r11,TPL_LOW(tpl_kernel_stack_bottom)  /* stack bottom ptr */
  stw   r1,KS_SP-KS_FOOTPRINT(r11)  /*  save the sp of the caller     */
  mr    r1,r11                      /*  set the kernel stack          */
  
no_stack_change:

  subi  r1,r1,KS_FOOTPRINT  /* make space on the stack to call C functions  */

  /*
   * Save SRR0 and SRR1 filled by the sc done by the caller
   * in the kernel stack. Needed to allow sc in hooks
   */
  mfspr r11,spr_SRR0
  stw   r11,KS_SRR0(r1)
  mfspr r11,spr_SRR1
  stw   r11,KS_SRR1(r1)
  
  blr

  .type tpl_enter_kernel,@function
  .size tpl_enter_kernel,$-tpl_enter_kernel

/****************************************************************************/

/**
 * tpl_leave_kernel does all the stuff to switch from
 * the context of the kernel to the context
 * of the running process
 * - it switches to the running process stack
 * - it restores registers from the kernel stack
 */
tpl_leave_kernel:
  /*
   * Restore the SRR0 and SRR1 saved in the system stack
   */
  lwz   r11,KS_SRR0(r1)
  mtspr spr_SRR0,r11
  lwz   r11,KS_SRR1(r1)
  mtspr spr_SRR1,r11

  addi  r1,r1,KS_FOOTPRINT        /*  free back space on the stack    */
  
  /*
   * The reentrency counter is decremented. If it reaches
   * 0, the process stack is restored
   */
  lis   r11,TPL_HIG(tpl_reentrancy_counter)
  ori   r11,r11,TPL_LOW(tpl_reentrancy_counter)
  lwz   r12,0(r11)    /*  get the value of the counter */
  subi  r12,r12,1
  stw   r12,0(r11)
  cmpwi r12,0
  bne   no_stack_restore

  /*  Restore the execution context of the caller
      (or the context of the task/isr which just got the CPU)         */
  lwz   r1,KS_SP-KS_FOOTPRINT(r1)   /*  Restore the SP and switch
                                        back to the process stack     */

#if WITH_MEMORY_PROTECTION == YES
  /*
   * Switch to user mem protection scheme
   */
  subi  r1,r1,4
  mflr  r11
  stw   r11,0(r1)   /* save lr on the current stack  */
  bl    tpl_user_mp /* Enable the memory protection  */
  lwz   r11,0(r1)   /* restore lr                    */
  mtlr  r11
  addi  r1,r1,4
#endif
  
no_stack_restore:
  blr

  .type tpl_leave_kernel,@function
  .size tpl_leave_kernel,$-tpl_leave_kernel
 
/****************************************************************************/

  .section  .SC_vector  CODE_ACCESS_RIGHT
tpl_sc_vector:
  b   tpl_sc_handler

  .section  .SC_handler CODE_ACCESS_RIGHT

/**
 * System call handler
 *
 * This is the second part of the handler. The first part is in the system
 * call interrupt vector. This first part branches to this function.
 */
    
tpl_sc_handler:

  /* The first thing to do is to check the service id is a valid one  */
  
  cmpwi r0,SYSCALL_COUNT              /* check the service id is in   */
  bge   invalid_service_id            /* the allowed range            */
  
  /*
   * The second thing is to save some working registers on the
   * process stack. r0 has already been saved by the function that
   * did the system call and used to pass the service id.
   * Here, we save lr, cr, r11 and r12. This is not needed
   * in fact since these registers are volatile but we want to start
   * with a symetrical scheme compared to the interrupt handler.
   * In addition, a 16 bytes space may be allocated on the top of the
   * process stack to save the SRR0 and SRR1 and to put the linkage area
   * if the CallTrustedFunction service is called.
   *
   * See the tpl_os_process_stack.h file for stack mapping
   * 
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
   * Then get the pointer to the service which is called
   */  
  slwi  r0,r0,2                              /* compute the offset     */
  lis   r11,TPL_HIG(tpl_dispatch_table)      /* load the ptr to the    */
  ori   r11,r11,TPL_LOW(tpl_dispatch_table)  /* dispatch table         */
  lwzx  r11,r11,r0                     /* get the ptr to the service   */
  mtlr  r11                            /* put it in lr for future use  */
  
  /* 
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the service. This is needed because, beside
   * tpl_schedule, no service modify this variable. So an old value
   * is retained
   */
  lis   r11,TPL_HIG(tpl_kern)
  ori   r11,r11,TPL_LOW(tpl_kern)
  stw   r11,KS_KERN_PTR(r1)            /* save the ptr for future use  */
  li    r0,NO_NEED_SWITCH
  stb   r0,20(r11)
  
  /*
   * Set the RI bit of the MSR to allow sc in hooks
   */
  mfmsr r11
  ori   r11,r11,RI_BIT_1
  mtmsr r11
  
  /*
   * Call the service
   */
  blrl
  
  /*
   * Check the tpl_need_switch variable
   * to see if a switch should occur
   */
  lwz   r11,KS_KERN_PTR(r1)
  lbz   r12,20(r11)
  andi. r0,r12,NEED_SWITCH
  beq   no_context_switch
  
  /*
   * r3 will be destroyed by the call to tpl_save_context. It is save
   * in the ad hoc area since it is the return code of the service
   */
  stw   r3,KS_RETURN_CODE(r1)
  
  /*
   * Check if context of the task/isr that just lost the CPU needs
   * to be saved. No save is needed for a TerminateTask or ChainTask
   */
  andi. r0,r12,NEED_SAVE
  beq   no_save
  
  /*
   * get the context pointer of the task that just lost the CPU
   */
  lwz   r3,0(r11)                     /* get s_running                    */
  bl    tpl_save_context
  
  /*
   * get the context pointer of the task that just got the CPU
   */
  lwz   r11,KS_KERN_PTR(r1)
  
no_save:

#if WITH_MEMORY_PROTECTION == YES
  /*
   * set up the memory protection for the process that just got the CPU
   */
  lwz   r3,16(r11)    /* get the id of the process which get the cpu  */
  bl    tpl_set_process_mp        /* set the memory protection scheme */
#endif

  lwz   r11,KS_KERN_PTR(r1)
  lwz   r3,4(r11)                     /* get s_elected                */
  bl    tpl_load_context
  
  /*
   * r3 is restored (ie get back the return code)
   */
  lwz   r3,KS_RETURN_CODE(r1)
  
  /* TODO */    
no_context_switch:
  /*
   * does the stuff to leave the kernel
   */
  bl    tpl_leave_kernel

  /*  restore the registers before returning                          */
  lwz   r0,PS_R0(r1)
  lwz   r11,PS_CR(r1)
  mtcr  r11
  lwz   r11,PS_LR(r1)
  mtlr  r11
  lwz   r12,PS_R12(r1)
  lwz   r11,PS_R11(r1)

  addi  r1,r1,PS_FOOTPRINT
  
invalid_service_id:
  rfi                                 /* return from interrupt        */

  .type tpl_sc_handler,@function
  .size tpl_sc_handler,$-tpl_sc_handler

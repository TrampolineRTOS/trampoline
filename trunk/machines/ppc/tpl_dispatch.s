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

#include "tpl_os_service_ids.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_assembler.h"

#define SYSCALL_COUNT   OS_SYSCALL_COUNT

TPL_EXTERN  tpl_dispatch_table
TPL_EXTERN  tpl_stat_proc_table
TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN  tpl_unset_mp
TPL_EXTERN  tpl_kern
TPL_EXTERN  tpl_need_switch

  .global tpl_kernel_stack
  .global tpl_sc_handler
  
  .data
  .align 4
tpl_kernel_stack:
  .space  KERNEL_STACK_SIZE

  .text
  .section  ".IVORhandlers","ax"
/**
 * System call handler
 *
 * This is the second part of the handler. The first part is in the system
 * call interrupt vector. This first part saves the registers it uses on the
 * task/ISR2 stack and branches to this function.
 */
    
tpl_sc_handler:

    /* The first thing to do is to check the service id is a valid one  */
    
    cmpwi r0,SYSCALL_COUNT              /* check the service id is in   */
    bge   ISID                          /* the allowed range            */
    
    /*  The second thing is to switch to kernel mem protection scheme   */
    
    mflr r12                            /* save lr to call tpl_unset_mp */
    ;        bl   tpl_unset_mp                   /* disable memory protection    */
    
    /*  The third thing is to switch to the kernel stack                */
    
    lis  r11,TPL_HIG(tpl_kernel_stack)  /* get the kernel stack ptr     */
    ori  r11,r11,TPL_LOW(tpl_kernel_stack)
    addi r11,r11,KERNEL_STACK_SIZE-KS_FOOTPRINT /* point to the bottom  */
    stw  r1,KS_SP(r11)                  /* save the sp of the caller    */
    mr   r1,r11                         /* set the kernel stack         */
    stw  r12,KS_LR(r1)                  /* save the LR                  */
    mfcr r11                            /* save the CR                  */
    stw  r11,KS_CR(r1)
    
    /*  Then get the pointer to the service that is called              */
    
    slwi r0,r0,2                              /* compute the offset     */
    lis  r11,TPL_HIG(tpl_dispatch_table)      /* load the ptr to the    */
    ori  r11,r11,TPL_LOW(tpl_dispatch_table)  /* dispatch table         */
    lwzx r11,r11,r0                     /* get the ptr to the service   */
    mtlr r11
    
    /*  Reset the tpl_need_switch variable to NO_NEED_SWITCH before
        calling the service. This is needed because, beside
        tpl_schedule, no service modify this variable. So an old value
        is retained                                                     */
    lis  r11,TPL_HIG(tpl_kern)
    ori  r11,r11,TPL_LOW(tpl_kern)
    li   r0,NO_NEED_SWITCH
    stb  r0,20(r11)
    
    /*  Call the service                                                */
    
    blrl
    
    /*  Check the tpl_need_switch variable
        to see if a switch should occur                                 */
    
    lis   r11,TPL_HIG(tpl_kern)
    ori   r11,r11,TPL_LOW(tpl_kern)
    lbz   r12,20(r11)
    andi. r0,r12,NEED_SWITCH
    beq   no_context_switch
    
    /* r3 will be destroyed by the call to tpl_save_context
       It is save in the ad hoc area since it is the return code
       of the service                                                   */
       
    stw   r3,KS_RETURN_CODE(r1)
    
    /* Check if context of the task/isr that just lost the CPU needs
       to be saved. This occurs on a TerminateTask or ChainTask         */
    
    andi. r0,r12,NEED_SAVE
    beq   no_save
    
    /* get the context pointer of the task that just lost the CPU       */
    
    lwz   r3,0(r11)                     /* get s_old                    */
    
    bl    tpl_save_context
    
    /* get the context pointer of the task that just got the CPU        */

    lis   r11,TPL_HIG(tpl_kern)
    ori   r11,r11,TPL_LOW(tpl_kern)
    
no_save:
 
    lwz   r3,4(r11)                     /* get s_running                */
    
    bl    tpl_load_context
    
    /*  r3 is restored (ie get back the return code                     */
    
    lwz   r3,KS_RETURN_CODE(r1)
    
    /*  set up the memory protection for the process that just
        got the CPU                                                     */

    /* TODO */    
no_context_switch:
    
    /*  Restore the execution context of the caller
        (or the context of the task/isr which just got the CPU)         */

    lwz   r11,KS_CR(r1)                 /* Get the CR                   */
    mtcr  r11
    lwz   r12,KS_LR(r1)                 /* Get the LR                   */
    lwz   r1,KS_SP(r1)                  /* Restore the SP               */
    
    /*  Enable the memory protection                                    */
//        bl    tpl_user_mp
    
    /*  restore the LR before returning                                 */
    mtlr  r12

ISID:
    rfi                                 /* return from interrupt        */

  .type tpl_sc_handler,@function
  .size tpl_sc_handler,$-tpl_sc_handler

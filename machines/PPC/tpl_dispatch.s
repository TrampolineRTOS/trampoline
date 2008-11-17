/*
 *  @file tpl_dispatch.s
 *
 * @section desc File description
 *
 * Trampoline dispatch level
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

#define SYSCALL_COUNT   OS_SYSCALL_COUNT

.reference tpl_dispatch_table
.reference tpl_sc_switch_context
.reference tpl_unset_mp

kernel_stack_size = 80

.data
.align 4
tpl_kernel_stack:   .space      kernel_stack_size

.text
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
        bl   tpl_kernel_mp                  /* disable memory protection    */
        
        /*  The third thing is to switch to the kernel stack               */
        
        lis  r11,hi16(tpl_kernel_stack)     /* get the system stack ptr     */
        ori  r11,r11,lo16(tpl_kernel_stack)
        addi r11,r11,kernel_stack_size-24   /* point to the bottom          */
        stw  r1,12(r11)                     /* save the sp of the caller    */
        mr   r1,r11                         /* set the kernel stack         */
        stw  r12,8(r1)                      /* save the LR                  */
        lis  r11,hi16(tpl_running_obj)      /* save the descriptor pointer  */
        ori  r11,r11,lo16(tpl_running_obj)  /* of the caller                */
        stw  r11,16(r1)
        
        /*  The kernel stack is like that:
        
            |                            |
            +----------------------------+
    SP->    |        linkage area        |  The linkage area is a zone
            +----------------------------+  reserved for the callee when
         +4 |        linkage area        |  calling a C function
            +----------------------------+
         +8 |      LR of the caller      |
            +----------------------------+
        +12 |      SP of the caller      |
            +----------------------------+
        +16 |    task descriptor ptr     |
            +----------------------------+
        +20 | return code of the service |
            +----------------------------+
        */

        /*  Then get the pointer to the service that is called              */
        
        slwi r0,r0,2                        /* change the id to an offset   */
        lis  r11,hi16(tpl_dispatch_table)   /* load the ptr to the          */
        ori  r11,r11,lo16(tpl_dispatch_table)   /* dispatch table           */
        lwz  r11,0(r11)                     /* get the ptr to the service   */
        lwzx r11,r11,r0
        
        /*  Call the service                                                */
        
        mtlr r11
        blrl
        
        /*  Check the return code (in r3) to see if a switch occured        */
        
        andi. r11,r3,NEED_CONTEXT_SWITCH
        bne   no_context_switch

        /* r3 will be destroyed by the call to tpl_sc_context_switch
           It is save in the ad hoc area                                    */
           
        stw   r3,20(r1)

        /* get the context pointer of the task that just lost the CPU       */
        
        lwz   r11,16(r1)                    /* get the task descriptor      */
        lwz   r3,0(r11)                     /* get the context pointer      */
        
        /* get the context pointer of the task that just got the CPU        */
        
        lis   r11,hi16(tpl_running_obj)     /* get the task descriptor      */
        ori   r11,r11,lo16(tpl_running_obj)
        lwz   r4,0(r11)                     /* get the context pointer      */
        
        bl    tpl_sc_switch_context
        
        /*  r3 is restored (ie get back the return code                     */
        
        lwz   r3,20(r1)
        
        /*  set up the memory protection for the process that just
            got the CPU                                                     */
        lis   r11,hi16(tpl_running_obj)     /* get the task descriptor      */
        ori   r11,r11,lo16(tpl_running_obj)
        lwz   r11,ID(r11)                   /* 
        
no_context_switch:
        
        /*  Restore the execution context of the caller
            (or the context of the task/isr which just got the CPU)         */
            
        lwz   r12,8(r1)                     /* Get the LR                   */
        lwz   r1,12(r1)                     /* Restore the SP               */
        
        /*  Enable the memory protection                                    */
        bl    tpl_user_mp
        
        /*  restore the LR before returning                                 */
        mtlr  r12

ISID:   rfi                                 /* return from interrupt        */

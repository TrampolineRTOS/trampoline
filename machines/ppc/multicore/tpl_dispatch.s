/*
 * @file tpl_dispatch.s
 * @section desc File description
 *
 * Trampoline dispatch level for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
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
#include "tpl_registers_asm.h"

TPL_EXTERN(tpl_kern)
TPL_EXTERN(tpl_need_switch)

TPL_EXTERN(tpl_save_context)
TPL_EXTERN(tpl_load_context)
TPL_EXTERN(tpl_kernel_mp)
TPL_EXTERN(tpl_user_mp)
TPL_EXTERN(tpl_set_process_mp)
TPL_EXTERN(tpl_run_elected)
TPL_EXTERN(tpl_get_kernel_lock)
TPL_EXTERN(tpl_release_kernel_lock)
TPL_EXTERN(tpl_service_lock_kernel)
TPL_EXTERN(tpl_kernel_stack_bottom)

#if WITH_ORTI
TPL_EXTERN(tpl_servicetrace)
#endif

TPL_GLOBAL(tpl_kernel_stack)
TPL_GLOBAL(tpl_sc_handler)
TPL_GLOBAL(tpl_enter_kernel)
TPL_GLOBAL(tpl_leave_kernel)
TPL_GLOBAL(tpl_reentrancy_counter)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

/****************************************************************************/
/*
 * A reentrency counter to track system calls made from
 * hook routines
 */
#define OS_START_SEC_VAR
#include "tpl_as_memmap.h"

TPL_ALIGN(4)
TPL_GLOBAL_REF(tpl_reentrancy_counter): TPL_FILL((NUMBER_OF_CORES*4))
TPL_TYPE(TPL_GLOBAL_REF(tpl_reentrancy_counter),@object)
TPL_SIZE(TPL_GLOBAL_REF(tpl_reentrancy_counter),(NUMBER_OF_CORES*4))

#define OS_STOP_SEC_VAR
#include "tpl_as_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/****************************************************************************/
/**
 * tpl_enter_kernel does all the stuff to switch from
 * the context of the running process to the context
 * of the kernel
 * - it switches to the kernel stack if needed
 * - it saves registers on the kernel stack
 * - in multicore, it locks the kernel if the syscall's KERNEL_LOCK byte is set
 */
TPL_GLOBAL_REF(tpl_enter_kernel_sc):

  se_mtar   r11,r5
  se_mtar   r12,r6
#if WITH_MEMORY_PROTECTION == YES
  /*
   * Switch to kernel mem protection scheme
   */
  se_subi   r1,4
  mflr      r5
  se_stw    r5,0(r1)      /* save lr on the current stack */
  e_bl      TPL_EXTERN_REF(tpl_kernel_mp)  /* disable memory protection    */
  se_lwz    r5,0(r1)      /* restore lr                   */
  mtlr      r5
  se_addi   r1,4
#endif

   /* Check the reentrency counter value and inc it
   * if the value is 0 before the inc, then we switch to
   * the system stack.
   */
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  e_add16i  r5,TPL_LOW(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  se_add    r5,r6
  se_lwz    r6,0(r5)   /*  get the value of the counter */
  se_cmpi   r6,0
  se_addi   r6,1
  se_stw    r6,0(r5)

  e_bne     no_stack_change_sc

  /*
   * Switch to the kernel stack
   */
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_kernel_stack_bottom))      /* get the kernel   */
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_kernel_stack_bottom))      /* stack bottom ptr */
  se_add    r5,r6
  se_lwz    r5,0(r5)
  e_stw     r1,KS_SP-KS_FOOTPRINT(r5)  /*  save the sp of the caller     */
  se_mr     r1,r5                      /*  set the kernel stack          */

no_stack_change_sc:

  se_subi   r1,KS_FOOTPRINT  /* make space on the stack to call C functions  */

  /*
   * Save SRR0 and SRR1 filled by the sc done by the caller
   * in the kernel stack. Needed to allow sc in hooks
   */
  mfsrr0    r5
  e_stw     r5,KS_SRR0(r1)
  mfsrr1    r5
  e_stw     r5,KS_SRR1(r1)

#if WITH_MULTICORE == YES
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_service_lock_kernel))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_service_lock_kernel))
  se_add    r5,r0
  se_lbz    r5,0(r5)
  se_cmpi   r5,1
  se_bne    dontlock

  /*
   * Last we have to lock the kernel, we must save LR in the stack before
   * the call. If the kernel is already locked by this core, the call does
   * nothing.
   */
  mflr      r5
  e_stw     r5,KS_LR(r1)

  /* Lock the kernel, this call is blocking */
  e_bl      TPL_EXTERN_REF(tpl_get_kernel_lock)

  /* Restore LR */
  e_lwz     r5,KS_LR(r1)
  mtlr      r5
dontlock :
#endif

  se_mfar   r5,r11
  se_mfar   r6,r12
  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_enter_kernel_sc))
TPL_TYPE(TPL_GLOBAL_REF(tpl_enter_kernel_sc),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_enter_kernel_sc),$-TPL_GLOBAL_REF(tpl_enter_kernel_sc))

/****************************************************************************/
/**
 * tpl_enter_kernel does all the stuff to switch from
 * the context of the running process to the context
 * of the kernel
 * - it switches to the kernel stack if needed
 * - it saves registers on the kernel stack
 * - in multicore, it always locks the kernel
 */
TPL_GLOBAL_REF(tpl_enter_kernel):

  se_mtar   r11,r5
  se_mtar   r12,r6
#if WITH_MEMORY_PROTECTION == YES
  /*
   * Switch to kernel mem protection scheme
   */
  se_subi   r1,4
  mflr      r5
  se_stw    r5,0(r1)      /* save lr on the current stack */
  e_bl      TPL_EXTERN_REF(tpl_kernel_mp)  /* disable memory protection    */
  se_lwz    r5,0(r1)      /* restore lr                   */
  mtlr      r5
  se_addi   r1,4
#endif

   /* Check the reentrency counter value and inc it
   * if the value is 0 before the inc, then we switch to
   * the system stack.
   */
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  e_add16i  r5,TPL_LOW(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  se_add    r5,r6
  se_lwz    r6,0(r5)  /*  get the value of the counter */
  se_cmpi   r6,0
  se_addi   r6,1
  se_stw    r6,0(r5)

  e_bne     no_stack_change

  /*
   * Switch to the kernel stack
   */
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_kernel_stack_bottom))      /* get the kernel   */
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_kernel_stack_bottom))      /* stack bottom ptr */
  se_add    r5,r6
  se_lwz    r5,0(r5)
  e_stw     r1,KS_SP-KS_FOOTPRINT(r5)  /*  save the sp of the caller     */
  se_mr     r1,r5                      /*  set the kernel stack          */

no_stack_change:

  se_subi   r1,KS_FOOTPRINT  /* make space on the stack to call C functions  */

  /*
   * Save SRR0 and SRR1 filled by the sc done by the caller
   * in the kernel stack. Needed to allow sc in hooks
   */
  mfsrr0    r5
  e_stw     r5,KS_SRR0(r1)
  mfsrr1    r5
  e_stw     r5,KS_SRR1(r1)

  se_mfar   r5,r11
  se_mfar   r6,r12

#if WITH_MULTICORE == YES
  /*
   * Last we have to lock the kernel, we must save LR in the stack before
   * the call. If the kernel is already locked by this core, the call does
   * nothing.
   */
  mflr      r11
  e_stw     r11,KS_LR(r1)

  /* Lock the kernel, this call is blocking */
  e_bl      TPL_EXTERN_REF(tpl_get_kernel_lock)

  /* Restore LR */
  e_lwz     r11,KS_LR(r1)
  mtlr      r11
#endif

  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_enter_kernel))
TPL_TYPE(TPL_GLOBAL_REF(tpl_enter_kernel),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_enter_kernel),$-TPL_GLOBAL_REF(tpl_enter_kernel))



/****************************************************************************/
/**
 * tpl_leave_kernel does all the stuff to switch from
 * the context of the kernel to the context
 * of the running process
 * - it switches to the running process stack
 * - it restores registers from the kernel stack
 */
TPL_GLOBAL_REF(tpl_leave_kernel):

  /*
   * Restore the SRR0 and SRR1 saved in the system stack
   */
  e_lwz     r11,KS_SRR0(r1)
  mtsrr0    r11
  e_lwz     r11,KS_SRR1(r1)
  mtsrr1    r11

  se_addi   r1,KS_FOOTPRINT         /*  free back space on the stack    */

  /*
   * The reentrency counter is decremented. If it reaches
   * 0, the process stack is restored
   */
  se_mtar   r11,r5
  se_mtar   r12,r6
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  e_add16i  r5,TPL_LOW(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  se_add    r5,r6
  se_lwz    r6,0(r5)     /*  get the value of the counter */
  se_subi   r6,1
  se_stw    r6,0(r5)
  se_cmpi   r6,0
  e_bne     no_stack_restore

  /*  Restore the execution context of the caller
      (or the context of the task/isr which just got the CPU)         */
  e_lwz     r1,KS_SP-KS_FOOTPRINT(r1)  /*  Restore the SP and switch
                                            back to the process stack     */

#if WITH_MEMORY_PROTECTION == YES
  /*
   * Switch to user mem protection scheme
   */
  se_subi   r1,4
  mflr      r5
  se_stw    r5,0(r1)
  e_bl      TPL_EXTERN_REF(tpl_user_mp)
  se_lwz    r5,0(r1)
  mtlr      r5
  se_addi   r1,4
#endif

#if WITH_MULTICORE == YES
  /* Unlock the kernel, we must save LR in the stack before the call */
  se_subi   r1,4
  mflr      r5
  se_stw    r5,0(r1)
  e_bl      TPL_EXTERN_REF(tpl_release_kernel_lock)
  se_lwz    r5,0(r1)
  mtlr      r5
  se_addi   r1,4
#endif

no_stack_restore:
  se_mfar   r5,r11
  se_mfar   r6,r12

  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_leave_kernel))
TPL_TYPE(TPL_GLOBAL_REF(tpl_leave_kernel),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_leave_kernel),$-TPL_GLOBAL_REF(tpl_leave_kernel))

#if WITH_SYSTEM_CALL == YES

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

/****************************************************************************/
TPL_TEXT_SECTION
TPL_SECTION(SC_vector, CODE_ACCESS_RIGHT)
TPL_GLOBAL(tpl_sc_vector)
TPL_GLOBAL_REF(tpl_sc_vector):
  e_b   TPL_GLOBAL_REF(tpl_sc_handler)

  FUNCTION(TPL_GLOBAL_REF(tpl_sc_vector))
TPL_TYPE(TPL_GLOBAL_REF(tpl_sc_vector),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_sc_vector),$-TPL_GLOBAL_REF(tpl_sc_vector))

TPL_TEXT_SECTION
TPL_SECTION(SC_handler, CODE_ACCESS_RIGHT)

/****************************************************************************/
/**
 * System call handler
 *
 * This is the second part of the handler. The first part is in the system
 * call interrupt vector. This first part branches to this function.
 */

TPL_EXTERN(tpl_dispatch_table)
TPL_GLOBAL_REF(tpl_sc_handler):


  /* The first thing to do is to check the service id is a valid one  */

  e_cmp16i  r0,SYSCALL_COUNT              /* check the service id is in   */
  e_bge     invalid_service_id            /* the allowed range            */

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
  se_subi   r1,PS_FOOTPRINT

  e_stw     r11,PS_R11(r1)
  e_stw     r12,PS_R12(r1)
  mflr      r11
  e_stw     r11,PS_LR(r1)
  mfcr      r11
  e_stw     r11,PS_CR(r1)
  e_stw     r0,PS_R0(r1)

#if WITH_ORTI
  /* Set the service trace before entering the kernel */
  se_mtar   r11,r5
  se_mtar   r12,r6
  /* Get the tpl_servicetrace addresse in r5 */
# if WITH_MULTICORE == YES
  mfspr     r6,spr_PIR
  se_slwi   r6,2
# endif
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_servicetrace))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_servicetrace))
# if WITH_MULTICORE == YES
  se_add    r5,r6
  se_lwz    r5,0(r5)
# endif
  /* Bit0 = 1 = Inside syscall. Other bits = syscall id. */
  e_slwi    r6,r0,1
  se_addi   r6,0x1
  se_stw    r6,0(r5)

  se_mfar   r5,r11
  se_mfar   r6,r12
#endif

  /*
   * Does the stuff to enter in kernel
   */
  e_bl      TPL_GLOBAL_REF(tpl_enter_kernel_sc)

  /*
   * Then get the pointer to the service that is called
   */
  se_slwi   r0,2                                /* compute the offset     */
  e_lis     r11,TPL_HIG(TPL_EXTERN_REF(tpl_dispatch_table))     /* load the ptr to the    */
  e_add16i  r11,TPL_LOW(TPL_EXTERN_REF(tpl_dispatch_table))     /* dispatch table         */
  lwzx      r11,r11,r0                    /* get the ptr to the service   */
  mtlr      r11                           /* put it in lr for future use  */

  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the service. This is needed because, beside
   * tpl_schedule, no service modify this variable. So an old value
   * is retained
   */
  se_mtar   r11,r5
  se_mtar   r12,r6

#if WITH_MULTICORE == YES
  mfspr     r6,spr_PIR
  se_slwi   r6,2                          /* get core number, and multiply by 4, to get the index of table tpl_kern[] */
#endif
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_kern))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_kern))
#if WITH_MULTICORE == YES
  se_add    r5,r6
  se_lwz    r5,0(r5)
#endif
  e_stw     r5,KS_KERN_PTR(r1)            /* save the ptr for future use  */

  se_mfar   r5,r11
  se_mfar   r6,r12

  /*
   * Set the RI bit of the MSR to allow sc in hooks
   */
  mfmsr     r11
  e_or2i    r11,RI_BIT_1
  mtmsr     r11

  /*
   * Call the service
   */
  se_blrl

  /*
   * r3 will be destroyed by the call to tpl_save_context. It is save
   * in the ad hoc area since it is the return code of the service
   */
  e_stw     r3,KS_RETURN_CODE(r1)

 /*
  * Check if the reentrancy counter is not greater than 1
  * No context switch shall occur if we're not leaving the kernel after
  * this call.
  */
  se_mtar   r11,r5
  se_mtar   r12,r6
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  e_add16i  r5,TPL_LOW(TPL_GLOBAL_REF(tpl_reentrancy_counter))
  se_add    r5,r6
  se_lwz    r6,0(r5)     /*  get the value of the counter */
  se_cmpi   r6,1
  se_mfar   r5,r11
  se_mfar   r6,r12
  e_bne     no_context_switch
  /*
   * Check the tpl_need_switch variable
   * to see if a switch should occur
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lbz     r12,24(r11)
  e_andi.   r12,r12,NEED_SWITCH
  e_beq     no_context_switch

  /*
   * Check if context of the task/isr that just lost the CPU needs
   * to be saved. No save is needed for a TerminateTask or ChainTask
   */
  e_lbz     r12,24(r11)
  e_andi.   r12,r12,NEED_SAVE
  e_beq     no_save

  /*
   * get the context pointer of the task that just lost the CPU
   */
  e_lwz     r3,0(r11)                     /* get s_running */
  e_bl      TPL_EXTERN_REF(tpl_save_context)



no_save:

#if WITH_MEMORY_PROTECTION == YES
  /*
   * set up the memory protection for the process that just got the CPU
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lwz     r3,16(r11)    /* get the id of the process which get the cpu  */
  e_bl      TPL_EXTERN_REF(tpl_set_process_mp)        /* set the memory protection scheme */
#endif


  se_li     r3,0          /* set save parameter to 0 */
  /* get tpl_kern[].need_switch, and pass it as parameter of tpl_run_elected */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lbz     r12,24(r11)
  e_andi.   r12,r12,NEED_SAVE
  e_beq     call_tpl_run_elected
  se_li     r3,1          /* set save parameter to 1 */
call_tpl_run_elected:
  e_bl      TPL_EXTERN_REF(tpl_run_elected)

  e_lwz     r11,KS_KERN_PTR(r1)
  e_lwz     r3,0(r11)                     /* get s_running (it has been changed by tpl_run_elected) */
  e_bl      TPL_EXTERN_REF(tpl_load_context)

  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_li      r12,NO_NEED_SWITCH
  e_stb     r12,24(r11)

no_context_switch:

  /*
   * r3 is restored (ie get back the return code)
   */
  e_lwz     r3,KS_RETURN_CODE(r1)

  /*
   * does the stuff to leave the kernel
   */
  e_bl      TPL_GLOBAL_REF(tpl_leave_kernel)

  /*  restore the registers before returning                          */

  e_lwz     r0,PS_R0(r1)

#if WITH_ORTI
  /* Set the service trace after leaving the kernel */
  se_mtar   r11,r5
  se_mtar   r12,r6
  /* Get the tpl_servicetrace addresse in r5 */
# if WITH_MULTICORE == YES
  mfspr     r6,spr_PIR
  se_slwi   r6,2
# endif
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_servicetrace))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_servicetrace))
# if WITH_MULTICORE == YES
  se_add    r5,r6
  se_lwz    r5,0(r5)
# endif
  /* Bit0 = 0 = Left syscall. Other bits = syscall id. */
  e_slwi    r6,r0,1
  se_stw    r6,0(r5)

  se_mfar   r5,r11
  se_mfar   r6,r12
#endif

  e_lwz     r11,PS_CR(r1)
  mtcr      r11
  e_lwz     r11,PS_LR(r1)
  mtlr      r11
  e_lwz     r12,PS_R12(r1)
  e_lwz     r11,PS_R11(r1)

  se_addi   r1,PS_FOOTPRINT

invalid_service_id:
  se_isync
  se_rfi                              /* return from interrupt        */

  FUNCTION(TPL_GLOBAL_REF(tpl_sc_handler))
TPL_TYPE(TPL_GLOBAL_REF(tpl_sc_handler),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_sc_handler),$-TPL_GLOBAL_REF(tpl_sc_handler))

#endif /* WITH_SYSTEM_CALL == YES */


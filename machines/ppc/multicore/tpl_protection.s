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

#include "tpl_os_kernel_stack.h"
#include "tpl_assembler.h"
#include "tpl_os_definitions.h"
#include "tpl_app_define.h"
#include "tpl_registers_asm.h"

TPL_EXTERN(tpl_enter_kernel)
TPL_EXTERN(tpl_leave_kernel)
TPL_EXTERN(tpl_save_context)
TPL_EXTERN(tpl_load_context)
TPL_EXTERN(tpl_call_protection_hook)
TPL_EXTERN(tpl_set_process_mp)
TPL_EXTERN(tpl_kern)
TPL_EXTERN(tpl_mpu)
TPL_EXTERN(tpl_reentrancy_counter)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/**
 * tpl_protection_hook_wrapper is called when an exception
 * related to protection (like memory protection for instance)
 * is encountered
 */
TPL_GLOBAL(tpl_protection_hook_wrapper)
TPL_GLOBAL_REF(tpl_protection_hook_wrapper):
/* Without Memory Protection, the wrapper falls directly in infinite loop*/
#if (WITH_MEMORY_PROTECTION == NO)
machine_check_error:
  /*e_bl machine_check_error*/
  se_blr
#else
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
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  se_subi   r1,20
  e_stw     r11,0(r1)
  e_stw     r12,4(r1)
  mflr      r11
  e_stw     r11,8(r1)
  mfcr      r11
  e_stw     r11,12(r1)
  e_stw     r0,16(r1)

  /* To use VLE instructions */
  se_mtar   r11,r5
  se_mtar   r12,r6

  /*  Load the address of the MPU base register */
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_mpu))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_mpu))
  se_add    r5,r6
  se_lwz    r6,0(r5)

  /* and MPU_CESR with SPERR field mask*/
  se_lwz    r5,MPU_CESR(r6)
  e_andi.   r5,r5,MPU_CESR_SPERR_MASK

  /* To use VLE instructions */
  se_mfar   r5,r11
  se_mfar   r6,r12

  /* if result is 0, then we are not in a real machine check exception*/
  e_beq     machine_check_error

  /*
   * Does the stuff to enter in kernel
   */
  e_bl      TPL_EXTERN_REF(tpl_enter_kernel)

  /* To use VLE instructions */
  se_mtar   r11,r5
  se_mtar   r12,r6

  /*
   * Save r3 in the kernel stack. It is from here it will be get to be saved
   * in the context of the interrupted process
   */
  se_stw     r3,KS_RETURN_CODE(r1)

  /*
   * Save the context of the running process.
   */
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
  se_stw     r5,KS_KERN_PTR(r1) /* save the ptr for future use  */
  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the handler This is needed because, beside tpl_schedule,
   * no service modify this variable. So an old value is retained
   */
  se_li     r6,NO_NEED_SWITCH
  e_stb     r6,24(r5)

  /*
   * Save the context of the interrupted process
   * The pointer to the context is in r3
   */
  se_lwz     r3,4(r5)          /* get the context pointer      */

  /* To use VLE instructions */
  se_mtar   r11,r5
  se_mtar   r12,r6

  e_bl      TPL_EXTERN_REF(tpl_save_context)

  /*
   * call tpl_call_protection_hook with E_OS_PROTECTION_MEMORY as parameter
   */
  e_li      r3,E_OS_PROTECTION_MEMORY
  e_bl      TPL_EXTERN_REF(tpl_call_protection_hook)

 /*
  * Check if the reentrancy counter is not greater than 1
  * No context switch shall occur if we're not leaving the kernel after
  * this call.
  */
  se_mtar   r11,r5
  se_mtar   r12,r6
  mfspr     r6,spr_PIR
  se_slwi   r6,2
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_reentrancy_counter))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_reentrancy_counter))
  se_add    r5,r6
  se_lwz    r6,0(r5)     /*  get the value of the counter */
  se_cmpi   r6,1
  se_mfar   r5,r11
  se_mfar   r6,r12
  e_bne     no_context_switch
  /*
   * test tpl_need_switch to see if a rescheduling occured
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lbz     r12,24(r11)
  e_andi.   r12,r12,NEED_SWITCH

  se_beq    no_context_switch

#if WITH_FLOAT == YES
  /*
   * TODO: HERE WE SHOULD HAVE THE CONTEXT SWITCH FOR FP REGISTERS
   */
#endif

#if WITH_MEMORY_PROTECTION == YES
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lwz     r3,16(r11)    /* get the id of the process which get the cpu  */
  e_bl      TPL_EXTERN_REF(tpl_set_process_mp)        /* set the memory protection scheme */
#endif

no_context_switch:

  /*
   * load the context of the running process. The pointer to the context
   * is in r3
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lwz     r3,4(r11)                         /* get s_running            */
  e_bl      TPL_EXTERN_REF(tpl_load_context)

  /*
   * Get back registers that was saved in the system stack
   */
  e_lwz     r3,KS_RETURN_CODE(r1)             /* get r3                   */

  /*
   * does the stuff to leave the kernel
   */
  e_bl      TPL_EXTERN_REF(tpl_leave_kernel)

  /*  restore the registers befor returning                           */
  e_lwz     r0,16(r1)
  e_lwz     r11,12(r1)
  mtcr      r11
  e_lwz     r11,8(r1)
  mtlr      r11
  e_lwz     r12,4(r1)
  e_lwz     r11,0(r1)

  e_addi    r1,r1,20

  se_rfi

/* infinited loop due to machine check exception */
machine_check_error:
  /*e_bl machine_check_error*/
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else

  subi  r1,r1,20
  stw   r11,0(r1)
  stw   r12,4(r1)
  mflr  r11
  stw   r11,8(r1)
  mfcr  r11
  stw   r11,12(r1)
  stw   r0,16(r1)

  /*  Load the address of the MPU base register */
  mfspr   r11,spr_PIR
  slwi    r11,2
  lis     r12,TPL_HIG(TPL_EXTERN_REF(tpl_mpu))
  add16i  r12,TPL_LOW(TPL_EXTERN_REF(tpl_mpu))
  add     r12,r11
  lwz     r12,0(r12)

  /* and MPU_CESR with SPERR field mask*/
  lwz     r11,MPU_CESR(r12)
  andi.   r11,r11,MPU_CESR_SPERR_MASK

  /* if result is 0, then we are not in a real machine check exception*/
  beq     machine_check_error

  /*
   * Does the stuff to enter in kernel
   */
  bl    TPL_EXTERN_REF(tpl_enter_kernel)

  /*
   * Save r3 in the kernel stack. It is from here it will be get to be saved
   * in the context of the interrupted process
   */
  stw   r3,KS_RETURN_CODE(r1)

  /*
   * Save the context of the running process.
   */
  lis   r11,TPL_HIG(TPL_EXTERN_REF(tpl_kern))
  ori   r11,r11,TPL_LOW(TPL_EXTERN_REF(tpl_kern))
  stw   r11,KS_KERN_PTR(r1) /* save the ptr for future use  */
  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the handler This is needed because, beside tpl_schedule,
   * no service modify this variable. So an old value is retained
   */
  li    r12,NO_NEED_SWITCH
  stb   r12,24(r11)

  /*
   * Save the context of the interrupted process
   * The pointer to the context is in r3
   */
  lwz   r3,4(r11)           /* get the context pointer      */
  bl    TPL_EXTERN_REF(tpl_save_context)

  /*
   * call tpl_call_protection_hook with E_OS_PROTECTION_MEMORY as parameter
   */
  li    r3,E_OS_PROTECTION_MEMORY
  bl    TPL_EXTERN_REF(tpl_call_protection_hook)

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
  bl    TPL_EXTERN_REF(tpl_set_process_mp)        /* set the memory protection scheme */
#endif

no_context_switch:

  /*
   * load the context of the running process. The pointer to the context
   * is in r3
   */
  lwz   r11,KS_KERN_PTR(r1)
  lwz   r3,4(r11)                         /* get s_running            */
  bl    TPL_EXTERN_REF(tpl_load_context)

  /*
   * Get back registers that was saved in the system stack
   */
  lwz   r3,KS_RETURN_CODE(r1)             /* get r3                   */

  /*
   * does the stuff to leave the kernel
   */
  bl    TPL_EXTERN_REF(tpl_leave_kernel)

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

  /* infinited loop due to machine check exception */
machine_check_error:
  /*bl machine_check_error*/
  blr
#endif
#endif /* WITH_MEMORY_PROTECTION */
  FUNCTION(TPL_GLOBAL_REF(tpl_protection_hook_wrapper))
TPL_TYPE(TPL_GLOBAL_REF(tpl_protection_hook_wrapper),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_protection_hook_wrapper),$-TPL_GLOBAL_REF(tpl_protection_hook_wrapper))

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"


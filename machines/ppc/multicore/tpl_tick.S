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

#include "tpl_assembler.h"
#include "tpl_registers_asm.h"
#include "tpl_app_define.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"

TPL_EXTERN(tpl_current_date)
TPL_EXTERN(tpl_dec_init_value)
TPL_EXTERN(tpl_enter_kernel)
TPL_EXTERN(tpl_leave_kernel)
TPL_EXTERN(tpl_kern)
TPL_EXTERN(tpl_need_switch)
TPL_EXTERN(tpl_save_context)
TPL_EXTERN(tpl_load_context)
TPL_EXTERN(tpl_kernel_mp)
TPL_EXTERN(tpl_user_mp)
TPL_EXTERN(tpl_set_process_mp)
TPL_EXTERN(tpl_run_elected)
TPL_EXTERN(tpl_reentrancy_counter)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#if (TPL_USE_DECREMENTER == YES)
TPL_EXTERN(tpl_dec_table)

/****************************************************************************/
TPL_GLOBAL(tpl_init_dec)
#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/**
 *
 */
TPL_GLOBAL_REF(tpl_init_dec):

  e_li      r11,0
  mtspr     spr_TBU, r11
  mtspr     spr_TBL, r11

  /* load dec and decar register with value correcponding to tick period */
  e_lis     r11,TPL_HIG(TPL_EXTERN_REF(tpl_dec_init_value))
  e_add16i  r11,TPL_LOW(TPL_EXTERN_REF(tpl_dec_init_value))
  e_lwz     r11,0(r11)
  mtspr     spr_DEC, r11
  mtspr     spr_DECAR, r11

  /* tcr register : set DIE and ARE bits, enable dec and auto reload */
  e_lis     r11,0x0440
  mtspr     spr_TCR, r11

  /* hid0 register : set TBEN register */
  e_li      r11,0x4000
  mtspr     spr_HID0, r11

  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_init_dec))
TPL_TYPE(TPL_GLOBAL_REF(tpl_init_dec),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_init_dec),$-TPL_GLOBAL_REF(tpl_init_dec))

/****************************************************************************/
#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
TPL_SECTION(dec_vector, CODE_ACCESS_RIGHT)
tpl_dec_vector:

  e_b         tpl_dec_handler

  FUNCTION(tpl_dec_vector)
TPL_TYPE(tpl_dec_vector,@function)
TPL_SIZE(tpl_dec_vector,$-tpl_dec_vector)


/****************************************************************************/
TPL_SECTION(dec_handler, CODE_ACCESS_RIGHT)

tpl_dec_handler:

  se_subi     r1,PS_FOOTPRINT

  e_stw       r11,PS_R11(r1)
  e_stw       r12,PS_R12(r1)
  mflr        r11
  e_stw       r11,PS_LR(r1)
  mfcr        r11
  e_stw       r11,PS_CR(r1)
  e_stw       r0,PS_R0(r1)

  e_bl        TPL_EXTERN_REF(tpl_enter_kernel)

  /*
   * Save r3 in the kernel stack. It is from here it will be get to be saved
   * in the context of the interrupted process
   */
  e_stw     r3,KS_RETURN_CODE(r1)


  se_mtar     r11,r5
  se_mtar     r12,r6
  mfspr       r6,spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  se_slwi     r6,2
  e_lis       r5,TPL_HIG(TPL_EXTERN_REF(tpl_current_date))
  e_add16i    r5,TPL_LOW(TPL_EXTERN_REF(tpl_current_date))
  se_add      r5,r6
  e_lwz       r6,0(r5)
  e_addi      r6,r6,1
  e_stw       r6,0(r5)

#if WITH_MULTICORE == YES
  mfspr       r6,spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  se_slwi     r6,2
#endif
  e_lis       r5,TPL_HIG(TPL_EXTERN_REF(tpl_kern))
  e_add16i    r5,TPL_LOW(TPL_EXTERN_REF(tpl_kern))
#if WITH_MULTICORE == YES
  se_add      r5,r6
  e_lwz       r5,0(r5)
#endif
  e_stw       r5,KS_KERN_PTR(r1)            /* save the ptr for future use  */

  se_mfar   r5,r11
  se_mfar   r6,r12

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
  mfspr       r6,spr_PIR
  se_slwi     r6,2
  e_lis       r5,TPL_HIG(TPL_EXTERN_REF(tpl_dec_table))
  e_add16i    r5,TPL_LOW(TPL_EXTERN_REF(tpl_dec_table))
  lwzx        r5,r5,r6
  mtlr        r5
  se_blrl

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
   * Check the tpl_need_switch variable
   * to see if a switch should occur
   */
  e_lwz       r11,KS_KERN_PTR(r1)
  e_lbz       r12,24(r11)
  e_andi.     r12,r12,NEED_SWITCH
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
  e_lbz       r12,24(r11)
  e_andi.     r12,r12,NEED_SAVE
  se_beq      no_save

  /*
   * get the context pointer of the task that just lost the CPU
   */
  e_lwz       r3,0(r11)                     /* get s_running                    */
  e_bl        TPL_EXTERN_REF(tpl_save_context)


no_save:

#if WITH_MEMORY_PROTECTION == YES
  /*
   * set up the memory protection for the process that just got the CPU
   */
  e_lwz       r11,KS_KERN_PTR(r1)
  e_lwz       r3,16(r11)    /* get the id of the process which get the cpu  */
  e_bl        TPL_EXTERN_REF(tpl_set_process_mp)        /* set the memory protection scheme */
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


  e_lwz       r11,KS_KERN_PTR(r1)
  e_lwz       r3,0(r11)                     /* get s_running                */
  e_bl        TPL_EXTERN_REF(tpl_load_context)



  /*
   * r3 is restored (ie get back the return code)
   */
  e_lwz       r3,KS_RETURN_CODE(r1)

  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_li      r12,NO_NEED_SWITCH
  e_stb     r12,24(r11)

  /* TODO */
no_context_switch:

  /*
   * does the stuff to leave the kernel
   */

    /* clear DIS bit in TSR SPR */
  e_lis       r11,0x0800
  mtspr       spr_TSR,r11

  e_bl        TPL_EXTERN_REF(tpl_leave_kernel)

  e_lwz       r0,PS_R0(r1)
  e_lwz       r11,PS_CR(r1)
  mtcr        r11
  e_lwz       r11,PS_LR(r1)
  mtlr        r11
  e_lwz       r12,PS_R12(r1)
  e_lwz       r11,PS_R11(r1)

  se_addi     r1,PS_FOOTPRINT

  se_isync
  se_rfi

  FUNCTION(tpl_dec_handler)
TPL_TYPE(tpl_dec_handler,@function)
TPL_SIZE(tpl_dec_handler,$-tpl_dec_handler)


#else


TPL_SECTION(dec_vector, CODE_ACCESS_RIGHT)
tpl_dec_vector:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_b         tpl_dec_vector
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b           tpl_dec_vector
#endif
  FUNCTION(tpl_dec_vector)
TPL_TYPE(tpl_dec_vector,@function)
TPL_SIZE(tpl_dec_vector,$-tpl_dec_vector)


#endif


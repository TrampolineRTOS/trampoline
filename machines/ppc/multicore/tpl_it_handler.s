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

#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"
#include "tpl_assembler.h"
#include "tpl_registers_asm.h"
#include "tpl_app_define.h"

TPL_EXTERN(tpl_kern)
TPL_EXTERN(tpl_it_table)

TPL_EXTERN(tpl_save_context)
TPL_EXTERN(tpl_load_context)
TPL_EXTERN(tpl_kernel_mp)
TPL_EXTERN(tpl_user_mp)
TPL_EXTERN(tpl_set_process_mp)
TPL_EXTERN(tpl_enter_kernel)
TPL_EXTERN(tpl_leave_kernel)
TPL_EXTERN(tpl_it_id)
TPL_EXTERN(tpl_ack_irq)
TPL_EXTERN(tpl_run_elected)
TPL_EXTERN(tpl_reentrancy_counter)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

/****************************************************************************/
TPL_TEXT_SECTION
TPL_SECTION(EI_vector, CODE_ACCESS_RIGHT)
TPL_GLOBAL(tpl_it_vector)
TPL_GLOBAL_REF(tpl_it_vector):
  e_b   TPL_GLOBAL_REF(tpl_it_handler)

  FUNCTION(TPL_GLOBAL_REF(tpl_it_vector))
TPL_TYPE(TPL_GLOBAL_REF(tpl_it_vector),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_it_vector),$-TPL_GLOBAL_REF(tpl_it_vector))


/****************************************************************************/
TPL_SECTION(EI_handler, CODE_ACCESS_RIGHT)
TPL_GLOBAL(tpl_it_handler)

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
TPL_GLOBAL_REF(tpl_it_handler):

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
  se_subi   r1,PS_FOOTPRINT
  e_stw     r11,PS_R11(r1)
  e_stw     r12,PS_R12(r1)
  mflr      r11
  e_stw     r11,PS_LR(r1)
  mfcr      r11
  e_stw     r11,PS_CR(r1)
  e_stw     r0,PS_R0(r1)

  /*
   * Does the stuff to enter in kernel
   */
  e_bl      TPL_EXTERN_REF(tpl_enter_kernel)


  /*
   * Save the context of the running process.
   */
  se_mtar   r11,r5
  se_mtar   r12,r6
#if WITH_MULTICORE == YES
  mfspr     r6,spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r6,r6,2
#endif
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_kern))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_kern))
#if WITH_MULTICORE == YES
  se_add    r5,r6
  e_lwz     r5,0(r5)
#endif
  e_stw     r5,KS_KERN_PTR(r1) /* save the ptr for future use  */

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


  /*
   * Get the id of the interrupt
   * (it is returned in r3)
   */
  e_bl      TPL_EXTERN_REF(tpl_it_id)

  /*
   * Get a pointer to the it table
   * This table is generated an can be found in tpl_app_config.c file
   */
  se_mtar   r11,r5
  se_mtar   r12,r6
#if WITH_MULTICORE == YES
  /* In multicore, tpl_it_table is indexed by the core_id */
  mfspr     r6,spr_PIR
  e_slwi    r6,r6,2
#endif
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_it_table))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_it_table))
#if WITH_MULTICORE == YES
  se_add    r6,r5
  e_lwz     r5,0(r6)
#endif
  /*
   * convert the it id to an offset. Each entry of the tpl_it_vector
   * uses 2 x 4 bytes words on a 32 bits PowerPC. The first word
   * id the function pointer of the it handler. The second word is
   * its parameter (so it is loaded in r3)
   */
  e_slwi    r6,r3,3
  lwzx      r0,r5,r6
  e_addi    r6,r6,4
  mtlr      r0
  lwzx      r3,r5,r6

  se_mfar   r5,r11
  se_mfar   r6,r12

  se_subi     r1,8

  /*
   * Call the IT routine
   */
  se_blrl

  se_addi     r1,8

  /*
   * get the return value to check if we have to restore cpu priority
   */
  e_cmp16i  r3,0
  e_beq     no_prio_restore

  e_bl      TPL_EXTERN_REF(tpl_ack_irq)

no_prio_restore:

  /*
   * restore all volatile registers
   */
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
   * test tpl_need_switch to see if a rescheduling occured
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
  se_beq    no_save

  /*
   * get the context pointer of the task that just lost the CPU
   */
  e_lwz       r3,0(r11)                     /* get s_running                    */
  e_bl        TPL_EXTERN_REF(tpl_save_context)



no_save:

#if WITH_MEMORY_PROTECTION == YES
  e_lwz       r11,KS_KERN_PTR(r1)
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

no_context_switch:

  /*
   * does the stuff to leave the kernel
   */
  e_bl      TPL_EXTERN_REF(tpl_leave_kernel)

  /*  restore the registers befor returning                           */

  e_lwz     r0,PS_R0(r1)
  e_lwz     r11,PS_CR(r1)
  mtcr      r11
  e_lwz     r11,PS_LR(r1)
  mtlr      r11
  e_lwz     r12,PS_R12(r1)
  e_lwz     r11,PS_R11(r1)

  se_addi   r1,PS_FOOTPRINT

  se_isync
  se_rfi

  FUNCTION(TPL_GLOBAL_REF(tpl_it_handler))
TPL_TYPE(TPL_GLOBAL_REF(tpl_it_handler),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_it_handler),$-TPL_GLOBAL_REF(tpl_it_handler))

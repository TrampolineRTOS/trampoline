/*
 * @file tpl_init.s
 *
 * @section desc File description
 *
 * Machine initialization functions for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OpenSource project
 * http://trampoline.rts-software.org
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
#include "tpl_app_define.h"

TPL_EXTERN(tpl_register_r2)
TPL_EXTERN(tpl_register_r13)
TPL_EXTERN(tpl_msr_start_value)
TPL_EXTERN(tpl_release_kernel_lock)

TPL_GLOBAL(tpl_init_regs)
TPL_GLOBAL(tpl_shutdown)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

TPL_GLOBAL_REF(tpl_init_regs):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  se_subi   r1,4   /* space on the stack */
  e_stw     r3,0(r1)  /* save the working register  */
  e_lis     r3,TPL_HIG(TPL_EXTERN_REF(tpl_register_r2))       /*  save the start value of RTOC  */
  e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(tpl_register_r2))
  e_stw     r2,0(r3)
  e_lis     r3,TPL_HIG(TPL_EXTERN_REF(tpl_register_r13))      /*  save the start value of r13   */
  e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(tpl_register_r13))
  e_stw     r13,0(r3)
  mfmsr     r0
  e_lis     r3,TPL_HIG(TPL_EXTERN_REF(tpl_msr_start_value))   /*  save the start value of msr   */
  e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(tpl_msr_start_value))
  e_stw     r0,0(r3)
  e_lwz     r3,0(r1)  /*  get back the working register */
  se_addi   r1,4   /*  release space on the stack    */
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  subi  r1,r1,4   /* space on the stack */
  stw   r3,0(r1)  /* save the working register  */
  lis   r3,TPL_HIG(TPL_EXTERN_REF(tpl_register_r2))       /*  save the start value of RTOC  */
  ori   r3,TPL_LOW(TPL_EXTERN_REF(tpl_register_r2))
  stw   r2,0(r3)
  lis   r3,TPL_HIG(TPL_EXTERN_REF(tpl_register_r13))      /*  save the start value of r13   */
  ori   r3,TPL_LOW(TPL_EXTERN_REF(tpl_register_r13))
  stw   r13,0(r3)
  mfmsr r0
  lis   r3,TPL_HIG(TPL_EXTERN_REF(tpl_msr_start_value))   /*  save the start value of msr   */
  ori   r3,TPL_LOW(TPL_EXTERN_REF(tpl_msr_start_value))
  stw   r0,0(r3)
  lwz   r3,0(r1)  /*  get back the working register */
  addi  r1,r1,4   /*  release space on the stack    */
  blr
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_init_regs))
TPL_TYPE(TPL_GLOBAL_REF(tpl_init_regs),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_init_regs),$-TPL_GLOBAL_REF(tpl_init_regs))

TPL_GLOBAL_REF(tpl_shutdown):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  mfmsr     r5  /* disable the external interrupts */
  e_li      r6,0
  e_or2i    r6,0x8000
  se_not    r6
  se_and    r5,r6
  mtmsr     r5
#if WITH_MULTICORE == YES
  /* Unlock the kernel */
  e_bl      TPL_EXTERN_REF(tpl_release_kernel_lock)
#endif
infinite_loop:
  se_b     infinite_loop
/* ------------ NO VLE ------------------------------------------------------*/
#else
  mfmsr r5  /* disable the external interrupts */
  li    r6,0
  ori   r6,r6,0x8000
  not   r6,r6
  and   r5,r5,r6
  mtmsr r5
#if WITH_MULTICORE == YES
  /* Unlock the kernel */
  bl        TPL_EXTERN_REF(tpl_release_kernel_lock)
#endif
infinite_loop:
  b     infinite_loop
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_shutdown))
TPL_TYPE(TPL_GLOBAL_REF(tpl_shutdown),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_shutdown),$-TPL_GLOBAL_REF(tpl_shutdown))
#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"


/*
 * @file tpl_multicore.s
 *
 * @section desc File description
 *
 * Trampoline multicore assembly functions for PPC
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
 * This software is distributed under the Lesser GNU Public Licence
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

TPL_EXTERN(tpl_sem)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif

#if WITH_MULTICORE == YES

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/** ===========================================================================
 * tpl_get_core_id
 * @ret r3 = core_id
 */
TPL_GLOBAL(tpl_get_core_id)
TPL_GLOBAL_REF(tpl_get_core_id):
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  mfspr r3,spr_PIR
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  mfspr r3,spr_PIR
  blr
#endif
  FUNCTION(TPL_GLOBAL_REF(tpl_get_core_id))
TPL_TYPE(TPL_GLOBAL_REF(tpl_get_core_id),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_get_core_id),$-TPL_GLOBAL_REF(tpl_get_core_id))


/** ===========================================================================
 * tpl_get_kernel_lock
 * \brief   get the kernel lock
 */
TPL_GLOBAL(tpl_get_kernel_lock)
TPL_GLOBAL_REF(tpl_get_kernel_lock):
#if (WITH_VLE == YES)
/* ------------ VLE ---------------------------------------------------------*/
  /* Save r2,r5,r6 */
  se_subi   r1,12
  se_stw    r6,8(r1)
  se_stw    r5,4(r1)
  se_stw    r2,0(r1)

  /* r6 : Get the Gates base address */
  e_lis     r6,TPL_HIG(TPL_SEMA4_BASE)
  e_add16i  r6,TPL_LOW(TPL_SEMA4_BASE)

  /* r5 : Core0 must write 0x1 ; Core1 must write 0x2 => just add 1 to the cpu_id */
  mfspr     r5,spr_PIR
  se_addi   r5,1

  /* Try to get the lock */
tpl_get_kernel_lock_retry :
  se_stb    r5,TPL_GATE_KERNEL(r6)
  se_isync
  se_lbz    r2,TPL_GATE_KERNEL(r6)
  se_cmp    r2,r5
  se_bne    tpl_get_kernel_lock_retry

  /* Restore r2,r5,r6 */
  se_lwz    r2,0(r1)
  se_lwz    r5,4(r1)
  se_lwz    r6,8(r1)
  se_addi   r1,12
  blr
#endif
TPL_TYPE(TPL_GLOBAL_REF(tpl_get_kernel_lock),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_get_kernel_lock),$-TPL_GLOBAL_REF(tpl_get_kernel_lock))


/** ===========================================================================
 * tpl_release_kernel_lock
 * \brief   release the kernel lock
 */
TPL_GLOBAL(tpl_release_kernel_lock)
TPL_GLOBAL_REF(tpl_release_kernel_lock):
#if (WITH_VLE == YES)
/* ------------ VLE ---------------------------------------------------------*/
  /* Save r5,r6 */
  se_subi   r1,8
  se_stw    r6,4(r1)
  se_stw    r5,0(r1)

  /* r6 : Get the Gates base address */
  e_lis     r6,TPL_HIG(TPL_SEMA4_BASE)
  e_add16i  r6,TPL_LOW(TPL_SEMA4_BASE)

  /* r5 : Write 0 to unlock the gate */
  se_li     r5,0
  se_stb    r5,TPL_GATE_KERNEL(r6)

  /* Restore r5,r6 */
  se_lwz    r5,0(r1)
  se_lwz    r6,4(r1)
  se_addi   r1,8
  blr

#endif
TPL_TYPE(TPL_GLOBAL_REF(tpl_release_kernel_lock),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_release_kernel_lock),$-TPL_GLOBAL_REF(tpl_release_kernel_lock))



#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
#endif /* if WITH_MULTICORE == YES */


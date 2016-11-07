/*
 * @file tpl_it_management.S
 *
 * @section desc File description
 *
 * Trampoline interrupt id fonction for MPC551x
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

TPL_EXTERN(_IVPR_VECBASE)
TPL_EXTERN(_IVOR0_OFFSET)
TPL_EXTERN(_IVOR1_OFFSET)
TPL_EXTERN(_IVOR2_OFFSET)
TPL_EXTERN(_IVOR3_OFFSET)
TPL_EXTERN(_IVOR4_OFFSET)
TPL_EXTERN(_IVOR5_OFFSET)
TPL_EXTERN(_IVOR6_OFFSET)
TPL_EXTERN(_IVOR7_OFFSET)
TPL_EXTERN(_IVOR8_OFFSET)
TPL_EXTERN(_IVOR10_OFFSET)
TPL_EXTERN(_IVOR11_OFFSET)
TPL_EXTERN(_IVOR12_OFFSET)
TPL_EXTERN(_IVOR13_OFFSET)
TPL_EXTERN(_IVOR14_OFFSET)
TPL_EXTERN(_IVOR15_OFFSET)
TPL_EXTERN(_IVOR32_OFFSET)
TPL_EXTERN(_IVOR33_OFFSET)
TPL_EXTERN(_IVOR34_OFFSET)

TPL_EXTERN(tpl_intc)

#if (WITH_VLE == YES)
TPL_VLE_ON
#else
TPL_VLE_OFF
#endif


/****************************************************************************/
#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"
TPL_GLOBAL(tpl_it_id)
TPL_GLOBAL_REF(tpl_it_id):

  se_subi   r1,4
  se_stw    r4,0(r1)

  mfspr     r4, spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2
  e_lis     r3,TPL_HIG(TPL_EXTERN_REF(tpl_intc))
  e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(tpl_intc))
  se_add    r3,r4             /* load the correct pointer to INTC depending on the core */
  e_lwz     r3,0(r3)
  e_lwz     r3,TPL_INTC_IACKR_PRC0(r3) /* get value of field IACKR_PRC0 in INTC */
  e_srwi    r3,r3,2

  se_lwz    r4,0(r1)
  se_addi   r1,4
  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_it_id))
TPL_TYPE(TPL_GLOBAL_REF(tpl_it_id),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_it_id),$-TPL_GLOBAL_REF(tpl_it_id))


/****************************************************************************/
TPL_GLOBAL(tpl_init_ivpr)
TPL_GLOBAL_REF(tpl_init_ivpr):

  se_subi   r1,8
  se_stw    r4,0(r1)
  se_stw    r5,4(r1)

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVPR_VECBASE))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVPR_VECBASE))
  mtspr   spr_IVPR,r4

/* #if TARGET_CHIP == "MPC5643" || TARGET_CHIP == "MPC5646" || TARGET_CHIP == "MPC5668" || TARGET_CHIP == "MPC5646C" */
  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR0_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR0_OFFSET))
  mtspr     spr_IVOR0,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR1_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR1_OFFSET))
  mtspr     spr_IVOR1,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR2_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR2_OFFSET))
  mtspr     spr_IVOR2,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR3_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR3_OFFSET))
  mtspr     spr_IVOR3,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR4_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR4_OFFSET))
  mtspr     spr_IVOR4,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR5_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR5_OFFSET))
  mtspr     spr_IVOR5,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR6_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR6_OFFSET))
  mtspr     spr_IVOR6,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR7_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR7_OFFSET))
  mtspr     spr_IVOR7,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR8_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR8_OFFSET))
  mtspr     spr_IVOR8,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR10_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR10_OFFSET))
  mtspr     spr_IVOR10,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR11_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR11_OFFSET))
  mtspr     spr_IVOR11,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR12_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR12_OFFSET))
  mtspr     spr_IVOR12,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR13_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR13_OFFSET))
  mtspr     spr_IVOR13,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR14_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR14_OFFSET))
  mtspr     spr_IVOR14,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR15_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR15_OFFSET))
  mtspr     spr_IVOR15,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR32_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR32_OFFSET))
  mtspr     spr_IVOR32,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR33_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR33_OFFSET))
  mtspr     spr_IVOR33,r4

  e_lis     r4,TPL_HIG(TPL_EXTERN_REF(_IVOR34_OFFSET))
  e_add16i  r4,TPL_LOW(TPL_EXTERN_REF(_IVOR34_OFFSET))
  mtspr     spr_IVOR34,r4

/* #endif */

  se_lwz    r5,4(r1)
  se_lwz    r4,0(r1)
  se_addi   r1,8
  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_init_ivpr))
TPL_TYPE(TPL_GLOBAL_REF(tpl_init_ivpr),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_init_ivpr),$-TPL_GLOBAL_REF(tpl_init_ivpr))


/****************************************************************************/
TPL_GLOBAL(tpl_ack_irq)
TPL_GLOBAL_REF(tpl_ack_irq):

  se_subi   r1,8
  se_stw    r3,0(r1)
  se_stw    r4,4(r1)

  mfspr     r4, spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2
  e_lis     r3,TPL_HIG(TPL_EXTERN_REF(tpl_intc))
  e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(tpl_intc))
  se_add    r3,r4
  e_lwz     r3,0(r3)

  e_li      r4,0
  e_stw     r4,TPL_INTC_EOIR_PRC0(r3)  /* set field IACKR_PRC0 in INTC */

  se_lwz    r4,4(r1)
  se_lwz    r3,0(r1)
  se_addi   r1,8

  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_ack_irq))
TPL_TYPE(TPL_GLOBAL_REF(tpl_ack_irq),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_ack_irq),$-TPL_GLOBAL_REF(tpl_ack_irq))


/****************************************************************************/
TPL_GLOBAL(tpl_get_cpu_prio)
TPL_GLOBAL_REF(tpl_get_cpu_prio):

  se_subi   r1,4
  se_stw    r4,0(r1)

  mfspr     r4, spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2
  e_lis     r3,TPL_HIG(TPL_EXTERN_REF(tpl_intc))
  e_add16i  r3,TPL_LOW(TPL_EXTERN_REF(tpl_intc))
  se_add    r3,r4
  e_lwz     r3,0(r3)

  e_lwz     r3,TPL_INTC_CPR_PRC0(r3)

  se_lwz    r4,0(r1)
  se_addi   r1,4

  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_get_cpu_prio))
TPL_TYPE(TPL_GLOBAL_REF(tpl_get_cpu_prio),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_get_cpu_prio),$-TPL_GLOBAL_REF(tpl_get_cpu_prio))


/****************************************************************************/
TPL_GLOBAL(tpl_set_cpu_prio)
TPL_GLOBAL_REF(tpl_set_cpu_prio):

  se_subi   r1,8
  se_stw    r4,0(r1)
  se_stw    r5,4(r1)

  mfspr     r4, spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2
  e_lis     r5,TPL_HIG(TPL_EXTERN_REF(tpl_intc))
  e_add16i  r5,TPL_LOW(TPL_EXTERN_REF(tpl_intc))
  se_add    r5,r4
  e_lwz     r5,0(r5)

  e_stw     r3,TPL_INTC_CPR_PRC0(r5)

  se_lwz    r5,4(r1)
  se_lwz    r4,0(r1)
  se_addi   r1,8

  se_blr

  FUNCTION(TPL_GLOBAL_REF(tpl_set_cpu_prio))
TPL_TYPE(TPL_GLOBAL_REF(tpl_set_cpu_prio),@function)
TPL_SIZE(TPL_GLOBAL_REF(tpl_set_cpu_prio),$-TPL_GLOBAL_REF(tpl_set_cpu_prio))


#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"


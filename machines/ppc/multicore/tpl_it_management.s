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
#include "tpl_app_define.h"
#include "tpl_registers.h"

  .extern __IVPR_VECBASE
  .extern __IVOR0_OFFSET
  .extern __IVOR1_OFFSET
  .extern __IVOR2_OFFSET
  .extern __IVOR3_OFFSET
  .extern __IVOR4_OFFSET
  .extern __IVOR5_OFFSET
  .extern __IVOR6_OFFSET
  .extern __IVOR7_OFFSET
  .extern __IVOR8_OFFSET
  .extern __IVOR10_OFFSET
  .extern __IVOR11_OFFSET
  .extern __IVOR12_OFFSET
  .extern __IVOR13_OFFSET
  .extern __IVOR14_OFFSET
  .extern __IVOR15_OFFSET
  .extern __IVOR32_OFFSET
  .extern __IVOR33_OFFSET
  .extern __IVOR34_OFFSET

  .extern tpl_intc


  .equ spr_IVPR, 63

/****************************************************************************/
  .text
  .section .osCode CODE_ACCESS_RIGHT
  .global tpl_it_id
tpl_it_id:

  se_subi   r1,4
  se_stw    r4,0(r1)
  
  mfspr     r4,spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2 
  e_lis     r3,TPL_HIG(tpl_intc)
  e_or2i    r3,TPL_LOW(tpl_intc)  
  se_add    r3,r4             /* load the correct pointer to INTC depending on the core */
  e_lwz     r3,0(r3)
  e_lwz     r3,TPL_INTC_IACKR_PRC0(r3) /* get value of field IACKR_PRC0 in INTC */
  e_srwi    r3,r3,2
  
  se_lwz    r4,0(r1)
  se_addi   r1,4
  se_blr

  FUNCTION(tpl_it_id)
  .type tpl_it_id,@function
  .size tpl_it_id,$-tpl_it_id

  
/****************************************************************************/  
  .global tpl_init_interrupts
tpl_init_interrupts:

  se_subi   r1,8
  se_stw    r4,0(r1)
  se_stw    r5,4(r1)
  
  e_lis   r4,TPL_HIG(__IVPR_VECBASE)
  e_or2i  r4,TPL_LOW(__IVPR_VECBASE)
  mtspr   spr_IVPR,r4
#if (TARGET_CHIP == MPC5643 || TARGET_CHIP == MPC5646 || TARGET_CHIP == MPC5668 || TARGET_CHIP == MPC5646C)
  e_lis   r4,TPL_HIG(__IVOR0_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR0_OFFSET)
  mtspr   IVOR0,r4

  e_lis   r4,TPL_HIG(__IVOR1_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR1_OFFSET)
  mtspr   IVOR1,r4

  e_lis   r4,TPL_HIG(__IVOR2_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR2_OFFSET)
  mtspr   IVOR2,r4

  e_lis   r4,TPL_HIG(__IVOR3_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR3_OFFSET)
  mtspr   IVOR3,r4

  e_lis   r4,TPL_HIG(__IVOR4_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR4_OFFSET)
  mtspr   IVOR4,r4

  e_lis   r4,TPL_HIG(__IVOR5_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR5_OFFSET)
  mtspr   IVOR5,r4

  e_lis   r4,TPL_HIG(__IVOR6_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR6_OFFSET)
  mtspr   IVOR6,r4

  e_lis   r4,TPL_HIG(__IVOR7_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR7_OFFSET)
  mtspr   IVOR7,r4

  e_lis   r4,TPL_HIG(__IVOR8_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR8_OFFSET)
  mtspr   IVOR8,r4

  e_lis   r4,TPL_HIG(__IVOR10_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR10_OFFSET)
  mtspr   IVOR10,r4

  e_lis   r4,TPL_HIG(__IVOR11_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR11_OFFSET)
  mtspr   IVOR11,r4

  e_lis   r4,TPL_HIG(__IVOR12_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR12_OFFSET)
  mtspr   IVOR12,r4

  e_lis   r4,TPL_HIG(__IVOR13_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR13_OFFSET)
  mtspr   IVOR13,r4

  e_lis   r4,TPL_HIG(__IVOR14_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR14_OFFSET)
  mtspr   IVOR14,r4

  e_lis   r4,TPL_HIG(__IVOR15_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR15_OFFSET)
  mtspr   IVOR15,r4

  e_lis   r4,TPL_HIG(__IVOR32_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR32_OFFSET)
  mtspr   IVOR32,r4

  e_lis   r4,TPL_HIG(__IVOR33_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR33_OFFSET)
  mtspr   IVOR33,r4

  e_lis   r4,TPL_HIG(__IVOR34_OFFSET)
  e_or2i  r4,TPL_LOW(__IVOR34_OFFSET)
  mtspr   IVOR34,r4

#endif

  /* set the current priority of the core 0 to 0 */   
  e_lis     r5,TPL_HIG(tpl_intc)
  e_or2i    r5,TPL_LOW(tpl_intc)  
  e_lwz     r5,0(r5)          
  e_li      r4,0
  e_stw     r4,TPL_INTC_CPR_PRC0(r5) /* store in field INTC_CPR_PRC0 in INTC */
#if (WITH_MULTICORE==YES)
  /* set the current priority of the core 1 to 0 */ 
  e_lis     r5,TPL_HIG(tpl_intc)
  e_or2i    r5,TPL_LOW(tpl_intc) 
  e_lwz     r5,4(r5)
  e_li      r4,0
  e_stw     r4,TPL_INTC_CPR_PRC0(r5)  /* store in field INTC_CPR_PRC0 in INTC */
#endif

  se_lwz    r5,4(r1)
  se_lwz    r4,0(r1)
  se_addi   r1,8
  se_blr

  FUNCTION(tpl_init_interrupts)
  .type tpl_init_interrupts,@function
  .size tpl_init_interrupts,$-tpl_init_interrupts


/****************************************************************************/
  .global tpl_ack_irq
tpl_ack_irq:

  se_subi   r1,8
  se_stw    r3,0(r1)
  se_stw    r4,4(r1)
  
  mfspr     r4,spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2 
  e_lis     r3,TPL_HIG(tpl_intc)
  e_or2i    r3,TPL_LOW(tpl_intc) 
  se_add    r3,r4
  e_lwz     r3,0(r3)  
  
  e_li      r4,0
  e_stw     r4,TPL_INTC_EOIR_PRC0(r3)  /* set field IACKR_PRC0 in INTC */
  
  se_lwz    r4,4(r1)
  se_lwz    r3,0(r1)
  se_addi   r1,8
  
  se_blr

  FUNCTION(tpl_ack_irq)
  .type tpl_ack_irq,@function
  .size tpl_ack_irq,$-tpl_ack_irq


/****************************************************************************/
  .global tpl_get_cpu_prio
tpl_get_cpu_prio:

  se_subi   r1,4
  se_stw    r4,0(r1)
  
  mfspr     r4,spr_PIR        /* get the core number, *4 to have the index in table of uint32 */
  e_slwi    r4,r4,2 
  e_lis     r3,TPL_HIG(tpl_intc)
  e_or2i    r3,TPL_LOW(tpl_intc) 
  se_add    r3,r4
  e_lwz     r3,0(r3)
  
  e_lwz     r3,TPL_INTC_CPR_PRC0(r3)
  
  se_lwz    r4,0(r1)
  se_addi   r1,4
  
  se_blr

  FUNCTION(tpl_get_cpu_prio)
  .type tpl_get_cpu_prio,@function
  .size tpl_get_cpu_prio,$-tpl_get_cpu_prio


/****************************************************************************/  
  .global tpl_set_cpu_prio
tpl_set_cpu_prio:

  se_subi   r1,8
  se_stw    r4,0(r1)
  se_stw    r5,4(r1)
  
  mfspr     r4,spr_PIR
  e_slwi    r4,r4,2 
  e_lis     r5,TPL_HIG(tpl_intc)
  e_or2i    r5,TPL_LOW(tpl_intc) 
  se_add    r5,r4
  e_lwz     r5,0(r5)

  e_stw     r3,TPL_INTC_CPR_PRC0(r5)
  
  se_lwz    r5,4(r1)
  se_lwz    r4,0(r1)
  se_addi   r1,8
  
  se_blr

  FUNCTION(tpl_set_cpu_prio)
  .type tpl_set_cpu_prio,@function
  .size tpl_set_cpu_prio,$-tpl_set_cpu_prio




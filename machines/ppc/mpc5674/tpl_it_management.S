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
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
 *
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

#include "tpl_assembler.h"
#include "tpl_app_define.h"
#include "tpl_registers.h"


TPL_EXTERN EXCEPTION_HANDLERS;
  
.equ spr_IVPR, 63

  .text
  .section .osCode CODE_ACCESS_RIGHT
  .global tpl_it_id
tpl_it_id:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_lis   r3,TPL_HIG(INTC_IACKR)
  /* MPC5674F_Porting_Modif :  Delete the second parameter in the instruction below to respect VLE syntax */
  /* e_or2i  r3,r3,TPL_LOW(INTC_IACKR) */ 
  e_or2i  r3,TPL_LOW(INTC_IACKR) 
  e_lwz   r3,0(r3)
  e_srwi  r3,r3,2
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  lis   r3,TPL_HIG(INTC_IACKR)
  ori   r3,r3,TPL_LOW(INTC_IACKR)
  lwz   r3,0(r3)
  srwi  r3,r3,2
  blr
#endif

  .type tpl_it_id,@function
  .size tpl_it_id,$-tpl_it_id

  .global tpl_init_interrupts
tpl_init_interrupts:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_lis   r11,TPL_HIG(IVPR_VECBASE) /* base address of INTC_hw_table in the link file when using hw mode */  
  e_or2i  r11,TPL_LOW(IVPR_VECBASE)      
  mtspr   spr_IVPR,r11

/* MPC5674F_Porting_Modif : Configure the IVOR for mpc5674 and set it in function of the EXCEPTION_HANDLERS which has been defined in the link file 
   and point to exceptions handlers section */
#if (TARGET_CHIP == "MPC5643" || TARGET_CHIP == "MPC5646" || TARGET_CHIP == "MPC5668" || TARGET_CHIP == "MPC5674")
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS)
  mtspr   IVOR0,r11
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x10)
  mtspr   IVOR1,r11
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x20)
  mtspr   IVOR2,r11
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x30)
  mtspr   IVOR3,r11         
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x40)
  mtspr   IVOR4,r11    
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x50)
  mtspr   IVOR5,r11   
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x60)
  mtspr   IVOR6,r11  
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x70)
  mtspr   IVOR7,r11 
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x80)
  mtspr   IVOR8,r11 
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x90)
  mtspr   IVOR9,r11  
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0xA0)
  mtspr   IVOR10,r11 
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0xB0)
  mtspr   IVOR11,r11  
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0xC0)
  mtspr   IVOR12,r11 
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0xD0)
  mtspr   IVOR13,r11          
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0xE0)
  mtspr   IVOR14,r11    
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0xF0)
  mtspr   IVOR15,r11
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x100)
  mtspr   IVOR32,r11
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x110)
  mtspr   IVOR33,r11
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x120)
  mtspr   IVOR34,r11
#if (TARGET_CHIP == "MPC5674")
  e_li    r11,TPL_LOW(EXCEPTION_HANDLERS + 0x130)
  mtspr   IVOR35,r11
#endif
  
#endif
  /* MPC5674F_Porting_Modif : select the software interrupt mode & 4 byte for the vector table offset */
#if (INTC_HW_MODE == YES)  
  e_lis   r12,0x0
  e_or2i  r12,0x1
#else
  e_lis   r12,0x0
#endif  
  e_lis   r11,TPL_HIG(INTC_MCR)
  e_or2i  r11,TPL_LOW(INTC_MCR)
  e_stw   r12,0(r11)
  /* set the current priority of the core to 0 */
  e_lis   r11,TPL_HIG(INTC_CPR)
  e_or2i  r11,TPL_LOW(INTC_CPR)
  e_li    r12,0x0
  e_stw   r12,0(r11)
  /* MPC5674F_Porting_Modif : enable external interrupts by setting MSR[EE] = 1 */
  wrteei 1
  
  se_blr

/* ------------ NO VLE ------------------------------------------------------*/
#else
  li    r11,0x1000
  mtspr spr_IVPR,r11

  /* set the current priority of the core to 0 */
  lis   r11,TPL_HIG(INTC_CPR)
  ori   r11,r11,TPL_LOW(INTC_CPR)
  li    r12,0x0
  stw   r12,0(r11)
  blr

#endif

  .type tpl_init_interrupts,@function
  .size tpl_init_interrupts,$-tpl_init_interrupts

  .global tpl_ack_irq
tpl_ack_irq:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_lis   r11,TPL_HIG(INTC_EOIR)
  e_or2i  r11,TPL_LOW(INTC_EOIR)
  e_li    r12,0
  e_stw   r12,0(r11)
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  lis r11,TPL_HIG(INTC_EOIR)
  ori r11,r11,TPL_LOW(INTC_EOIR)
  li  r12,0
  stw r12,0(r11)
  blr
#endif

/* 
 * MPC5674F_Porting_Modif: add this function to be called when EOIR is performed
 * by TeminateISR2 service. This service is called by tpl_sc_handler, so we must restore 
 * the CPR value after EOIR clear flag
 */
  .type tpl_isr2_ack_irq,@function
  .size tpl_isr2_ack_irq,$-tpl_isr2_ack_irq

  .global tpl_isr2_ack_irq
tpl_isr2_ack_irq:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  wrteei 0 						 /* Disable interrupt recognition to block interrupts just after EOIR clear */
 
  e_lis   r12,TPL_HIG(INTC_EOIR)
  e_or2i  r12,TPL_LOW(INTC_EOIR)
  e_li    r0,0
  e_stw   r0,0(r12)
   
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  lis r11,TPL_HIG(INTC_EOIR)
  ori r11,r11,TPL_LOW(INTC_EOIR)
  li  r12,0
  stw r12,0(r11)
  blr
#endif

  .type tpl_isr2_ack_irq,@function
  .size tpl_isr2_ack_irq,$-tpl_isr2_ack_irq


  .global tpl_get_cpu_prio
tpl_get_cpu_prio:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_lis   r11,TPL_HIG(INTC_CPR)
  e_or2i  r11,TPL_LOW(INTC_CPR)
  e_lwz   r3,0(r11)
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  lis r11,TPL_HIG(INTC_CPR)
  ori r11,r11,TPL_LOW(INTC_CPR)
  lwz r3,0(r11)
  blr
#endif
  .type tpl_get_cpu_prio,@function
  .size tpl_get_cpu_prio,$-tpl_get_cpu_prio


  .global tpl_set_cpu_prio
tpl_set_cpu_prio:
/* ------------ VLE ---------------------------------------------------------*/
#if (WITH_VLE == YES)
  e_lis   r11,TPL_HIG(INTC_CPR)
  e_or2i  r11,TPL_LOW(INTC_CPR)
  e_stw   r3,0(r11)
  se_blr
/* ------------ NO VLE ------------------------------------------------------*/
#else
  lis r11,TPL_HIG(INTC_CPR)
  ori r11,r11,TPL_LOW(INTC_CPR)
  stw r3,0(r11)
  blr
#endif
  .type tpl_set_cpu_prio,@function
  .size tpl_set_cpu_prio,$-tpl_set_cpu_prio
  

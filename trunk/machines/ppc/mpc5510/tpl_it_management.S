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

  .equ INTC_addr, 0xfff48000
  .equ INTC_CPR_PRC0,   INTC_addr +  0x8
  .equ INTC_IACKR_PRC0, INTC_addr + 0x10  /* MPC551x: P0 Interrupt Acknowledge @  */
  .equ INTC_EOIR_PRC0,  INTC_addr + 0x18
  .equ INTC_SSCIR,      INTC_addr + 0x20
  .equ INTC_PSR,        INTC_addr + 0x40
  .equ spr_IVPR, 63
  
  .text
  .section .osCode CODE_ACCESS_RIGHT
  .global tpl_it_id
tpl_it_id:
  lis   r3,TPL_HIG(INTC_IACKR_PRC0)
  ori   r3,r3,TPL_LOW(INTC_IACKR_PRC0)
  lwz   r3,0(r3)
  srwi  r3,r3,2
  blr
  
  .type tpl_it_id,@function
  .size tpl_it_id,$-tpl_it_id

  .global tpl_init_interrupts
tpl_init_interrupts:
  li    r11,0x1000
  mtspr spr_IVPR,r11
  
  /*
   * setup the software interrupt for testing
   */
  /* first the priority */
  lis	 r11,TPL_HIG(INTC_PSR)
  ori  r11,r11,TPL_LOW(INTC_PSR)
  li	 r12,0x1
  slwi r12,r12,24
  stw  r12,0(r11)

  /*
   * setup the IRQ3 interrupt of the GPIO
   */
  lis	 r11,TPL_HIG(INTC_PSR)
  ori  r11,r11,TPL_LOW(INTC_PSR)
  li	 r12,0x1
  slwi r12,r12,24
  stw  r12,56(r11)

  /* set the current priority of the core to 0 */
  lis	r11,TPL_HIG(INTC_CPR_PRC0)
  ori   r11,r11,TPL_LOW(INTC_CPR_PRC0)
  li	r12,0x0
  stw   r12,0(r11)
  blr
  .type tpl_init_interrupts,@function
  .size tpl_init_interrupts,$-tpl_init_interrupts




  .global tpl_trigger_sw_it  
tpl_trigger_sw_it:
  lis	r11,TPL_HIG(INTC_SSCIR)
  ori	r11,r11,TPL_LOW(INTC_SSCIR)
  li	r12,0x2
  slwi  r12,r12,24
  stw   r12,0(r11)
  blr
  .type tpl_trigger_sw_it,@function
  .size tpl_trigger_sw_it,$-tpl_trigger_sw_it

 
  .global tpl_ack_sw_it
tpl_ack_sw_it:
  lis	r11,TPL_HIG(INTC_SSCIR)
  ori	r11,r11,TPL_LOW(INTC_SSCIR)
  li	r12,0x1
  slwi  r12,r12,24
  stw   r12,0(r11)
  blr
  .type tpl_ack_sw_it,@function
  .size tpl_ack_sw_it,$-tpl_ack_sw_it
  
  .global tpl_ack_irq
tpl_ack_irq:
  lis r11,TPL_HIG(INTC_EOIR_PRC0)
  ori	r11,r11,TPL_LOW(INTC_EOIR_PRC0)
  li  r12,0
  stw r12,0(r11)
  blr
  .type tpl_ack_irq,@function
  .size tpl_ack_irq,$-tpl_ack_irq


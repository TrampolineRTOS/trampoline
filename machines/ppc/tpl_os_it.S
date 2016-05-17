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

#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_assembler.h"

#ifndef WITH_SYSTEM_CALL
#error "This file should not be part of your project since WITH_SYSTEM_CALL is not defined"
#endif

  .global tpl_enable_interrupts
  .global tpl_disable_interrupts

  .text
  
  .section .osCode CODE_ACCESS_RIGHT

/**
 * Enable interrupts. On the PowerPC, the interrupt bit is located
 * in the MSR (Machine state register). But since this function is
 * called from an OS service, whe already are in an interrupt handler.
 * So the interrupt bit is not in the MSR but has been saved in the SRR1
 * register.
 * Since MSR will be restored with the content od the SRR1 register when
 * we will return from interrupt, we change set the interrupt bit in
 * this register.
 */
tpl_enable_interrupts:
  mfspr r11,spr_SRR1    /* get the register where the MSR has been saved  */
  li    r12,0           /* set r11 to EE_BIT constant                     */
  ori   r12,r12,EE_BIT_1
  or    r11,r11,r12     /* clear the EE_BIT in SRR1 copy                  */ 
  mtspr spr_SRR1,r11   /* put back in SRR1                               */
  blr 

/**
 * Disable interrupts. On the PowerPC, the interrupt bit is located
 * in the MSR (Machine state register). But since this function is
 * called from an OS service, whe already are in an interrupt handler.
 * So the interrupt bit is not in the MSR but has been saved in the SRR1
 * register.
 * Since MSR will be restored with the content od the SRR1 register when
 * we will return from interrupt, we change set the interrupt bit in
 * this register.
 */
tpl_disable_interrupts:
  mfspr r11,spr_SRR1    /* get the register where the MSR has been saved  */
  li    r12,0           /* set r11 to EE_BIT constant                     */
  ori   r12,r12,EE_BIT_1
  andc  r11,r11,r12     /* clear the EE_BIT in SRR1 copy                  */ 
  mtspr spr_SRR1,r11   /* put back in SRR1                               */
  blr 
 

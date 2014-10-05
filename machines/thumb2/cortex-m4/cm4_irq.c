/**
 * @file cm4_irq.c
 *
 * @section descr File description
 *
 * STM32F4 platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
 * Trampoline is protected by the French intellectual property law.
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

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[82];

void tpl_arm_subarch_irq_handler ()
{
  VAR(uint32, AUTOMATIC) isr_id_dec;
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;
  
  /* get interrupt id */
//  isr_id_dec = NVIC_GetPendingIRQ();
  /* <! ATTENTION
   * Attribution du vecteur 15 temporairement; on ne sert que l'it SysTick
   */
  isr_id_dec = (uint32)15;
  /* !> */

  /* clear interrupt */
  /* Automatically done when the interrupt is serviced */

  /* launch interrupt fonction (ISR2, timer...) */
  isr_vector = tpl_it_vector[isr_id_dec].func;
  isr_vector(tpl_it_vector[isr_id_dec].args);
}

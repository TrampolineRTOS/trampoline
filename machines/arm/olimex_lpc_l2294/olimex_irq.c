/**
 * @file olimex_irq.c
 *
 * @section descr File description
 *
 * OLIMEX platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
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
#include "tpl_os_interrupt_kernel.h" //tpl_it_handler
#include "lpc22xx.h" //VICIRQStatus...

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[31];

void tpl_arm_subarch_irq_handler ()
{
  VAR(uint32, AUTOMATIC) isr_id_dec = 0;
  volatile VAR(uint32, AUTOMATIC) leading_zeros = 0;
  
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;
  
  /* get interrupt id
   *
   * __builtin_clz counts the leading zero's in register VICIRQStatus
   */
  leading_zeros = (uint32)__builtin_clz(VICIRQStatus);
  isr_id_dec = (uint32)31 - leading_zeros;
  
  /* clear interrupt */
  void (* routine) (void) = (void (*) (void)) VICVectAddr ;
  routine () ;    
  
  /* launch interrupt fonction (ISR2, timer...) */
  isr_vector = tpl_it_vector[isr_id_dec].func;
  isr_vector(tpl_it_vector[isr_id_dec].args);
 
  /* acknowlege interrupts */
  VICVectAddr = 0 ;
}

/* End of file olimex_irq.c */

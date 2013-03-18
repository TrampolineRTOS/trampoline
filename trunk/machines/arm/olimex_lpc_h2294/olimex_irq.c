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
  VAR(u32, AUTOMATIC) isr_id_hex;
  VAR(u32, AUTOMATIC) isr_id_dec = 0;
  VAR(u32, AUTOMATIC) i;
  VAR(tpl_it_handler, AUTOMATIC) isr_vector;
  
  /* get interrupt id */
  isr_id_hex = VICIRQStatus;
   
  /* clear interrupt */
  void (* routine) (void) = (void (*) (void)) VICVectAddr ;
  routine () ;    
  
  /* Convert the interrupt id which is in hexadecimal in decimal */
  for(i=0; i<31; i++)
  {
    if ((isr_id_hex >> i) == 1)
    {
      isr_id_dec = i;
    }
  }  
    
  /* launch interrupt fonction (ISR2, timer...) */
  isr_vector = tpl_it_vector[isr_id_dec].func;
  isr_vector(tpl_it_vector[isr_id_dec].args);
 
  /* acknowlege interrupts */
  VICVectAddr = 0 ;
    
}

/* End of file olimex_irq.c */

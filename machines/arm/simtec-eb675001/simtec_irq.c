/**
 * @file simtec_irq.c
 *
 * @section descr File description
 *
 * SIMTEC platform specific routines and variables
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

#include "simtec_driver_adapter.h"
#include "tpl_os_kernel.h"
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#endif /* WITH_AUTOSAR */

extern CONST(tpl_it_vector_entry, OS_CONST) tpl_it_vector[32];

void tpl_arm_subarch_irq_handler ()
{
  u32 interrupt_source;

  interrupt_source = simtec_get_interrupt_source ();
  tpl_it_vector[interrupt_source].func (tpl_it_vector[interrupt_source].args);

  /* acknoledge interrupt */
  simtec_acknoledge_current_irq_level ();
}

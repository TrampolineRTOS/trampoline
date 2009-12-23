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
#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#endif /* WITH_AUTOSAR */

extern CONSTP2CONST(u16, AUTOMATIC, OS_APPL_DATA)
  simtec_isr_by_src[32];

void tpl_arm_subarch_irq_handler ()
{
  u32 interrupt_source;
  u16 isr_id;

  interrupt_source = simtec_get_interrupt_source ();
  switch (interrupt_source)
  {
    case SYSTEM_TIMER_INT_SOURCE:
      simtec_heartbeat_timer_ack ();
      /* TODO: call counter heartbeat */
      /* TODO: increment local time (watchdogs) */
      break;
#ifndef NO_ISR
    default:
      isr_id = simtec_isr_by_src[interrupt_source];
      tpl_central_interrupt_handler(isr_id);
#endif /* !defined NO_ISR */
  }

  /* acknoledge interrupt */
  simtec_acknoledge_current_irq_level ();
}

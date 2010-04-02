/**
 * @file simtec_tpl_stubs.c
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
#include "tpl_machine.h"
#include "simtec_driver_adapter.h"
#include "tpl_machine_interface.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_kernel.h"
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#endif /* WITH_AUTOSAR */

/* TODO: use MemMap.h */

void tpl_init_machine()
{
  simtec_int_ctrl_setup_defaults ();

  simtec_disable_all_devices ();

  simtec_setup_heartbeat_timer_1ms ();

  tpl_init_machine_generic ();

  simtec_heartbeat_timer_start ();
}

void tpl_shutdown ()
{
  /* FIXME: this is does not conform to AUTOSAR OS specifications, 
   * should return to main with initial context */
  DISABLE_FIQ ();
  DISABLE_IRQ ();
  
  /* fall into very low consumption mode : all
   * internal CPU clocks are disabled.
   */
  simtec_system_standby ();

  while (1);
}

#if WITH_AUTOSAR_TIMING_PROTECTION == YES

void tpl_set_watchdog (tpl_time delay, tpl_watchdog_expire_function function)
{
  /* TODO: use simtec driver adapter abstraction */
  /*timer 's parameter initialisation*/
  Timer_set_valeur_initiale (TIMER_0, 0);
  Timer_set_valeur_finale (TIMER_0, (UInt16) delay);
  Timer_set_periode (TIMER_0, (UInt32) delay);
  
  /*indicate to the IT handler the IRQ of timer0*/
  Interruption_set_gestionnaire_irq (INTERRUPTION_TIMER_0,function,NULL);
  Timer_activer_interruptions (TIMER_0);
  
  /*start the timer*/
  Timer_demarrer (TIMER_0);
  /*remember to acknoledge somewhere : Timer_acquitter_evenement(TIMER_0);*/
}
  
void tpl_cancel_watchdog ()
{
  /* TODO: use simtec driver adapter abstraction */
  Timer_desactiver_interruptions (TIMER_0);
  Timer_arreter (TIMER_0);
}

tpl_time tpl_get_local_current_date ()
{
  /* TODO: use simtec driver adapter abstraction */
  tpl_time tmp;
  return tmp;
}
#endif /* defined WITH_AUTOSAR_TIMING_PROTECTION */ 

#if WITH_AUTOSAR_STACK_MONITORING == YES

/* FIXME : needs update (tpl_proc_static) */
u8 tpl_check_stack_pointer (tpl_exec_common *this_exec_obj)
{
  u8 tmp;
  if(this_exec_obj->static_desc->context.core_context->r[sp]<
     &(this_exec_obj->static_desc->stack))
  tmp=1; /*no overflow detected*/
  else tmp=0; /*there is an overflow*/
  return tmp;
}

#endif /* WITH_AUTOSAR_STACK_MONITORING */

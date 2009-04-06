/**
 * @file tpl_machine_simtec_eb675001.c
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
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifdef WITH_AUTOSAR
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

/* TODO: use MemMap.h */

struct ARM_CONTEXT idle_task_context;

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

/* These external variables represent symbols defined in
 * ldscript file. They are used to know where each section
 * has been located */
extern u16 debut_bss;
extern u16 fin_bss;
extern u16 debut_rom;
extern u16 fin_rom;
extern u16 debut_data;
extern u16 fin_data;
extern int main (void);

/* this function should not return as
 * it is called straight after reset
 */
void tpl_arm_bootstrap_stage2 ()
{
  simtec_memory_setup_defaults ();

  /*
   * initialіze memory segments
   */
  /* BSS should be zeroed */
  u16 *ptr_bss = &debut_bss;
  while((int)ptr_bss < (int)&fin_bss)
    *ptr_bss ++ = 0;

  /* DATA initial values copied from ROM */
  u16 *data_src, *data_dst;
  data_src = &fin_rom;
  data_dst = &debut_data;
  while (data_dst != &fin_data)
    *data_dst++ = *data_src++;  

  /*
   * start application (which may start Trampoline via StartOS)
   */
  main ();
  
  /* ends in a loop, as we should not return from reset */
  while (1);
}

void tpl_init_machine()
{
  simtec_int_ctrl_setup_defaults ();

  simtec_disable_all_devices ();
   
  simtec_setup_heartbeat_timer_1ms ();

  tpl_init_machine_generic ();

  simtec_heartbeat_timer_start ();
}

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

#ifdef WITH_AUTOSAR_TIMING_PROTECTION

void tpl_set_watchdog (tpl_time delay, tpl_watchdog_expire_function function)
{
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
  Timer_desactiver_interruptions (TIMER_0);
  Timer_arreter (TIMER_0);
}

tpl_time tpl_get_local_current_date ()
{
  tpl_time tmp;
  return tmp;
}
#endif /* defined WITH_AUTOSAR_TIMING_PROTECTION */ 

#ifdef WITH_AUTOSAR_STACK_MONITORING

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

/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot��par la loi sur la propri��intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline ARM7 specifics
 *
 * $Date: 2008/05/20 12:09:34 $
 * $Rev$
 * $Author: GuillaumeNuth $
 * $URL$
 */

#include "tpl_machine.h"
#include "interruption.h"
#include "horloge.h"
#include "timer.h"
#include "../os/tpl_machine_interface.h"
#include "../os/tpl_os_custom_types.h"
#include "../os/tpl_os_definitions.h"
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
#include "../autosar/tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#ifdef WITH_AUTOSAR
#include "../autosar/tpl_as_isr_kernel.h"
#include "../os/tpl_os_kernel.h" /* for tpl_running_obj */
#endif /* WITH_AUTOSAR */


arm7_context idle_task_context;
volatile static u32 tpl_locking_depth = 0;

#define TIMER_0 0

#ifndef NO_ISR
	extern int signal_for_isr_id[ISR_COUNT];
	int id;
#endif


/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1) ;
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and lr and init the other registers to 0
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
	int i;
	arm7_context *ic = tpl_stat_proc_table[proc_id]->context.ic;
	
	for (i = 0; i < 17; i++ ) {
        ic->R[i] = 0; /*put all the register of the context to 0*/
	}
	
	
	ic->R[14] = (unsigned long)(tpl_stat_proc_table[proc_id]->entry);
	ic->R[13] = (unsigned long)(tpl_stat_proc_table[proc_id]->stack.stack_zone
	               + tpl_stat_proc_table[proc_id]->stack.stack_size); 
	/*  Size of the linkage area used to store (among others)
        the link register if the task calls a function          */
}


void tpl_enable_all_interrupts_service()
{
	Interruption_activer_irq();
	Interruption_activer_fiq ();
	
	#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_disable_all_isr_lock_monitor (tpl_running_obj);
	#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
	
}

void tpl_disable_all_interrupts_service()
{
	Interruption_desactiver_irq ();
	Interruption_desactiver_fiq ();
	
	#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    tpl_start_all_isr_lock_monitor (tpl_running_obj);
	#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
	
}

void quit(int n)
{
    ShutdownOS(E_OK);  
}

void tpl_init_machine()
{
   /*init of all the peripherals*/
   /*the order of the init is important*/
   Horloge_initialiser();
   Memoire_initialiser();
   GPIO_initialiser();
   UART_initialiser();
   I2C_initialiser();
   Interruption_initialiser();
   InterruptionSysteme_initialiser ();
   Timer_initialiser();
   Horloge_activer (HORLOGE_TIMER0);

   UART_envoyer_chaine("\ndriver init OK \n");
   
}


void tpl_signal_handler (int sig)
{
	#ifndef NO_ISR
/*    for (id = 0; id < ISR_COUNT; id++)
    {
        if (signal_for_isr_id[id] == sig)
        {*/
                tpl_central_interrupt_handler(id);
/*        }
    }*/
	#endif /* NO_ISR */
}

void tpl_resume_all_interrupts_service(void)
{
    tpl_locking_depth--;
    
    if (tpl_locking_depth == 0)
    {
    	
	Interruption_activer_irq ();
	Interruption_activer_fiq ();
	
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_all_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    }
}

void tpl_suspend_all_interrupts_service(void)
{

    Interruption_desactiver_irq ();
	Interruption_desactiver_fiq ();
   
    tpl_locking_depth++;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (tpl_locking_depth == 1)
    {
      tpl_start_all_isr_lock_monitor (tpl_running_obj);
    }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
}

void tpl_resume_os_interrupts_service(void)
{
    tpl_locking_depth--;
    
    if (tpl_locking_depth == 0)
    {

	Interruption_activer_irq ();
	Interruption_activer_fiq ();

#ifdef WITH_AUTOSAR_TIMING_PROTECTION
        tpl_disable_os_isr_lock_monitor (tpl_running_obj);
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
    }
}

void tpl_suspend_os_interrupts_service(void)
{

	Interruption_desactiver_irq ();
	Interruption_desactiver_fiq ();
    
    tpl_locking_depth++;
#ifdef WITH_AUTOSAR_TIMING_PROTECTION
    if (tpl_locking_depth == 1)
    {
      tpl_start_os_isr_lock_monitor (tpl_running_obj); 
    }
#endif /*WITH_AUTOSAR_TIMING_PROTECTION */
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
	/*think to acquit somewhere : Timer_acquitter_evenement(TIMER_0);*/
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


#endif /* WITH_AUTOSAR_TIMING_PROTECTION */

#ifdef WITH_AUTOSAR_STACK_MONITORING

u8 tpl_check_stack_pointer (tpl_exec_common *this_exec_obj)
{
	u8 tmp;
	if(this_exec_obj->static_desc->context.ic->R[13]<
	&(this_exec_obj->static_desc->stack))
	tmp=1; /*no overflow detected*/
	else tmp=0; /*there is an overflow*/
	return tmp;
}

u8 tpl_check_stack_footprint (tpl_exec_common *this_exec_obj)
{
	u8 tmp;
	/*to do*/
	tmp=0;
	return tmp;
}

#endif /* WITH_AUTOSAR_STACK_MONITORING */


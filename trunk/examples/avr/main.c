#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include <avr/io.h>

//ISR(boutonISR)
//{
//	PORTA ^= 0x20;
//}

//remove trampoline def of ISR..
#undef ISR
#include <avr/interrupt.h>
//and add GCC def of ISR :-/
//
int main(void)
{
	//portA => LEDs
	PORTA = 0;
	DDRA  = 0xFF;
	//timer2 => base pour generalCounter.
	TCCR2A = 7; //timer lance, prediviseur 1024
	TIMSK2 = 1; //interruption locale #includeen overflow
	//init bouton S
	DDRE  &= 0x7F;	// bit 7 du port E en entree
	PORTE |= 0x80;	// active la resistance de pullup port E.7
	EICRB =  0x80;  // detection de front descendant sur E.7 (INT7)
	EIMSK |= 0x80;  //port E.7 => int7

	sei();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
TASK(secondTask)
{
	PORTA |=2;
	TerminateTask();
}

TASK(startTask)
{
	PORTA |= 1;
	ChainTask(secondTask);
}

TASK(periodicTask)
{
	PORTA ^= 0x80;
	TerminateTask();
}

#include "tpl_os_timeobj_kernel.h"
#include "tpl_os_kernel.h"
#include "tpl_machine_interface.h"

//interruption du timer 2 => association au generalCounter (defini dans l'OIL)
//extern tpl_counter generalCounter_counter_desc;
//ISR (TIMER2_OVF_vect)
//{
//	PORTA ^= 0x40;
//	tpl_status  need_rescheduling;
//    need_rescheduling = tpl_counter_tick(&generalCounter_counter_desc);
//	if (need_rescheduling == NEED_RESCHEDULING)
//  	{
//    	tpl_proc_id old_running_id = tpl_running_id;
//    	tpl_status result = tpl_schedule(FROM_IT_LEVEL);
//    	if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH) {
//      		tpl_switch_context_from_it(
//        		&(tpl_stat_proc_table[old_running_id]->context),
//        		&(tpl_stat_proc_table[tpl_running_id]->context));
//    	}
//	}
//}

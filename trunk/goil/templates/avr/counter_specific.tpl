#include <avr/io.h>
#include <avr/interrupt.h>  

/*
 * tpl_init_machine 
 */
void tpl_init_tick_timer()
{
TCCR2A = 1;
TIMSK2 = 1;
}


void tpl_schedule(u8 from);
tpl_status tpl_counter_tick(tpl_counter *counter);
void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$
	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}




ISR (TIMER2_OVF_vect)
{
tpl_call_counter_tick();
}
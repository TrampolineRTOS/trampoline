#include <tpl_os_kernel.h>        //tpl_schedule
#include <tpl_os_alarm_kernel.h> //tpl_counter_tick

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$
	if (need_rescheduling == NEED_RESCHEDULING) {
		tpl_schedule(FROM_IT_LEVEL);
    }
}


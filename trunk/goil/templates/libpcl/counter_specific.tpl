#include "tpl_os_kernel.h"        //tpl_schedule
#include "tpl_os_timeobj_kernel.h"  //tpl_counter_tick
#include "tpl_machine_interface.h"

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$
	if (need_rescheduling == NEED_RESCHEDULING) {
        tpl_status result = tpl_schedule(FROM_IT_LEVEL);
        if ((result & NEED_CONTEXT_SWITCH) == NEED_CONTEXT_SWITCH) {
            tpl_switch_context_from_it(
                (P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA))
                    &(tpl_old_running_obj->static_desc->context),
                (P2VAR(tpl_context, AUTOMATIC, OS_APPL_DATA))
                    &(tpl_running_obj->static_desc->context)
            );
        }
    }
}


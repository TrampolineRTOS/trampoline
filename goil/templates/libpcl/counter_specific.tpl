#include "tpl_os_kernel.h"          /* tpl_schedule */
#include "tpl_os_timeobj_kernel.h"  /* tpl_counter_tick */
#include "tpl_machine_interface.h"  /* tpl_switch_context_from_it */

void tpl_call_counter_tick()
{
	tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$

  need_rescheduling |= tpl_counter_tick(&SystemCounter_counter_desc);

  
  if (need_rescheduling == NEED_RESCHEDULING)
  {
    tpl_proc_id old_running_id = tpl_running_id;
    tpl_schedule_from_running();
    if (tpl_need_switch != NO_NEED_SWITCH) {
      tpl_switch_context_from_it(
        &(tpl_stat_proc_table[old_running_id]->context),
        &(tpl_stat_proc_table[tpl_running_id]->context)
      );
    }
  }
}


#define OS_START_SEC_CODE
#include "Memmap.h"

#ifdef WITH_AUTOSAR
extern FUNC(void, OS_CODE) tpl_s12x_inc_time(void);
#endif
extern FUNC(tpl_status, OS_CODE) tpl_counter_tick(
    P2VAR(tpl_counter, OS_APPL_DATA, AUTOMATIC) counter);

FUNC(void, OS_CODE) tpl_call_counter_tick()
{
  VAR(tpl_status, AUTOMATIC)  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$
  
#ifdef WITH_AUTOSAR
  tpl_s12x_inc_time();
#endif
  if (need_rescheduling == NEED_RESCHEDULING)
  {
    tpl_proc_id old_running_id = tpl_running_id;
    tpl_status result = tpl_schedule(FROM_IT_LEVEL);
    if (tpl_need_switch != NO_NEED_SWITCH) {
      tpl_switch_context_from_it(
        &(tpl_stat_proc_table[old_running_id]->context),
        &(tpl_stat_proc_table[tpl_running_id]->context)
      );
    }
  }
}

#define OS_STOP_SEC_CODE
#include "Memmap.h"


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
    tpl_schedule_from_running();
    if (tpl_kern.need_switch != NO_NEED_SWITCH) {
      tpl_switch_context_from_it(
        &(tpl_kern.s_old->context),
        &(tpl_kern.s_running->context)
      );
    }
  }
}

#define OS_STOP_SEC_CODE
#include "Memmap.h"


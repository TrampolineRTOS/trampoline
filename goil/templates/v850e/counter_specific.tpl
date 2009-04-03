#define OS_START_SEC_CODE
#include "Memmap.h"

FUNC(void, OS_CODE) Os_IncTime(void);
FUNC(void, OS_CODE) tpl_schedule_from_running(void);
FUNC(tpl_status, OS_CODE) tpl_counter_tick(tpl_counter *counter);

#define OS_STOP_SEC_CODE
#include "Memmap.h"



#define GPT_START_SEC_PUBLIC_CODE
#include "Memmap.h"

FUNC(void, GPT_PUBLIC_CODE) tpl_call_counter_tick(void)
{
  tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$
  
  Os_IncTime();
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

#define GPT_STOP_SEC_PUBLIC_CODE
#include "Memmap.h"

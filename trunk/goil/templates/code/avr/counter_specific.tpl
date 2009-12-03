#include "tpl_os_kernel.h"          /* tpl_schedule */
#include "tpl_os_timeobj_kernel.h"  /* tpl_counter_tick */
#include "tpl_machine_interface.h"  /* tpl_switch_context_from_it */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

//gcc uses ISR as a keyword to define an interrupt handler.
//Osek uses ISR to define an ISR2 :-/
#ifdef ISR
	#undef ISR
#endif
#include <avr/interrupt.h>

ISR($IT_SOURCE$)
{
  tpl_status  need_rescheduling = NO_SPECIAL_CODE;
$COUNTER_LIST$

  if (need_rescheduling == NEED_RESCHEDULING)
  {
    tpl_schedule_from_running();
#ifndef WITH_SYSTEM_CALL
    if (tpl_kern.need_switch != NO_NEED_SWITCH) {
      tpl_switch_context_from_it(
        &(tpl_kern.s_old->context),
        &(tpl_kern.s_running->context)
      );
    }
#endif
  }
}
#ifdef WITH_IT_TABLE  
	#undef WITH_IT_TABLE
#endif
#define WITH_IT_TABLE  NO
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

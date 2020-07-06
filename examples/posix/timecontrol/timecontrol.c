#include "tpl_os.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "tpl_os_alarm_kernel.h"
#include "tpl_os_task_kernel.h"
#include "tpl_os_timeobj_kernel.h"

int main(void) {
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
extern VAR(tpl_counter, OS_VAR) SystemCounter_counter_desc;

FUNC(StatusType, OS_CODE)
tpl_apply_strategy(CONST(tpl_task_id, AUTOMATIC) task_id,
                   CONST(tpl_alarm_id, AUTOMATIC) alarm_id) {
  VAR(StatusType, AUTOMATIC) result;

  if (task_id == task2 && alarm_id == task2_alarm) {

    VAR(tpl_tick, AUTOMATIC) current_date;
    current_date = SystemCounter_counter_desc.current_date;

    // check if we have to delay this request
    if (current_date < 14) {
      result = tpl_activate_task(task_id);
    } else {
      // push activation 4 t.u. in the future
      tpl_set_rel_alarm_service(task2_stratalarm, 4, 0);
      result = E_OK;
    }
  } else {
    result = tpl_activate_task(task_id);
  }
  return result;
};

static volatile bool elapsed = false;

void empty_func_callback(void) { return; }

TASK(task1) {
  VAR(TickType, AUTOMATIC) consumed = 0;
  do {
    GetAlarm(task1_alarm, &consumed);
  } while (consumed > 10 - 4);
  TerminateTask();
}

TASK(task2) {
  VAR(TickType, AUTOMATIC) consumed = 0;
  do {
    GetAlarm(task2_alarm, &consumed);
  } while (consumed > 15 - (7 + 4));
  TerminateTask();
}

void primary(void) { printf("primary\r\n"); }

void secondary(void) { printf("secondary\r\n"); }

TASK(task3) {

  TickType count_to_20;
  if (GetAlarm(p2s_alarm, &count_to_20) == E_OK) {
    if (count_to_20 > 20 - 14) {
      primary();
    } else {
      secondary();
    }
  } else {
    secondary();
  }
  TerminateTask();
}

#include "tpl_os.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

static volatile bool elapsed = false;

void empty_func_callback(void) { return; }

TASK(task1) {

  for (volatile uint32_t i = 0; i < 100000; i++)
    ;
  TerminateTask();
}

TASK(task2) {
  /* for (volatile uint32_t i = 0; i < 100000; i++) */
  /*   ; */
  getchar();
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

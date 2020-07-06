#include "tpl_os.h"
#include <stdio.h>

int main(void) {
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

static volatile bool elapsed = false;

void alarm_callback_set_elapsed(void) { elapsed = true; }

TASK(task1) {
  static int occurence = 0;

  occurence++;
  printf("Activation #%d\n", occurence);

  TerminateTask();
}

TASK(task2) {}

void primary(void) { printf("primary\r\n"); }

void secondary(void) { printf("secondary\r\n"); }

TASK(task 3) {
  if (!elapsed) {
    primary();
  } else {
    secondary();
  }
}

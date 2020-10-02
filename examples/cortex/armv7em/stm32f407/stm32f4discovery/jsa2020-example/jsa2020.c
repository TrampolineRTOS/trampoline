#include "tp.h"
#include "tpl_os.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
extern volatile VAR(uint32, OS_VAR) tpl_time_counter;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task1_START_SEC_CODE

#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void) {
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/**
 * Must not be called from a preemptive task.  When called from a non preemptive
 * task, loops until tpl_time_counter has ticked ticks time.
 */

FUNC(void, OS_APPL_CODE) take_time(CONST(uint32, AUTOMATIC) ticks) {
  CONST(uint32, AUTOMATIC) deadline = tpl_time_counter + ticks;
  if (ticks > 0) {
    while (tpl_time_counter != deadline)
      ;
  }
}

/**
 * PseudoRNG based on xorshift32.
 * Code adapted from https://en.wikipedia.org/wiki/Xorshift
 */

VAR(uint32, OS_APPL_DATA) rgen_task1 = 42;

FUNC(uint32, OS_APPL_CODE) xorshift32(uint32 *state) {
  /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
  uint32 x = *state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  *state = x;
  return x;
}

TASK(task1) {
  /*  exectime is 4, 5 or 6 */
  uint32 exectime = 4 + (xorshift32(&rgen_task1) % 3);
  take_time(exectime);
  TerminateTask();
}

#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task2) {
  take_time(7);
  TerminateTask();
}

#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"

static volatile VAR(tpl_bool, OS_APPL_DATA) switch_to_secondary = FALSE;
/* static volatile tpl_bool switch_to_secondary = FALSE;    */

ALARMCALLBACK(execute_secondary) { switch_to_secondary = TRUE; }

TASK(task3) {
  if (switch_to_secondary) {
    ledOn(ORANGE);
    take_time(10);
  } else {
    ledOn(GREEN);
    take_time(16);
    // execute primary
  }
  TerminateTask();
}

#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t *file, uint32_t line) {}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

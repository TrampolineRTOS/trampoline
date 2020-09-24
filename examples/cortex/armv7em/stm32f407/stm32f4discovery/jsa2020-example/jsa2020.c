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

FUNC(void, OS_APPL_CODE) take_time(CONST(uint32, AUTOMATIC) ticks) {
  CONST(uint32, AUTOMATIC) deadline = tpl_time_counter + ticks;
  if (ticks > 0) {
    while (tpl_time_counter != deadline)
      ;
  }
}

TASK(task1) {
  take_time(4);
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

#include "tp.h"
#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  tpl_start_enforcement_timer();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  STATIC VAR(uint32, AUTOMATIC) lastTimeValue = 0;

  VAR(uint32, AUTOMATIC) timer = tpl_get_enforcement_timer();

  if (timer - lastTimeValue > 200000) {
    lastTimeValue = timer;
    ledToggle(BLUE);
  }
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_back_START_SEC_CODE
#include "tpl_memmap.h"

TASK(back)
{
  while(1)
  {
    VAR(uint32, AUTOMATIC) date = tpl_get_enforcement_timer();
    tpl_wait_enforcement_timer(date, date+5);
    ledToggle(RED);
    TaskType myId;
    GetTaskID(&myId);
  }
}

#define APP_Task_back_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreUserServiceHook(uint32 serviceID) {
    ledToggle(GREEN);
}

FUNC(void, OS_CODE) PostUserServiceHook(uint32 serviceID) {
    ledToggle(GREEN);
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledOn(ORANGE);
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledOff(ORANGE);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

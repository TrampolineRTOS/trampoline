#include "tp.h"
#include "tpl_os.h"

#define APP_Task_a_task_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

DeclareTask(task_0);
DeclareEvent(ev_0);

TASK(a_task)
{
  ActivateTask(task_0);

  while(1)
  {
    delay(500);

    ledOn(RED);

    WaitEvent(ev_0);
    ClearEvent(ev_0);

    ledOff(RED);

    delay(500);

    ActivateTask(task_0);

    delay(500);
  }

	TerminateTask();
}
#define APP_Task_a_task_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_0_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_0)
{
  delay(500);
  SetEvent(a_task, ev_0);
  delay(500);
  TerminateTask();
}
#define APP_Task_task_0_STOP_SEC_CODE
#include "tpl_memmap.h"

/*
 * This is necessary for ST libraries
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == a_task) {
    ledOn(ORANGE);
  }
  else if (task_id == task_0) {
    ledOn(GREEN);
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == a_task) {
    ledOff(ORANGE);
  }
  else if (task_id == task_0) {
    ledOff(GREEN);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


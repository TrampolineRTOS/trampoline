#include "tp.h"
#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{

  ledinit();
  ledBootInit();

  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
    ledon();
    for(long long i = 0; i < 2000000; i++);
    ledoff();
    for(long long i = 0; i < 2000000; i++);
    TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_life_START_SEC_CODE
#include "tpl_memmap.h"

TASK(life)
{
    // ledBootOn();
    // for(long long i = 0; i < 2000000; i++);
    // ledBootOff();
    // for(long long i = 0; i < 2000000; i++);
    TerminateTask();
}
#define APP_Task_life_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledBootOn();
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledBootOff();
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


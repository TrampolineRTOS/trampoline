#include "tp.h"
#include "tpl_os.h"

DeclareResource(resVal);

#define APP_Task_bgTask_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
volatile VAR(int, AUTOMATIC) val = 0;
#define APP_Task_bgTask_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

#define APP_Task_bgTask_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(bgTask)
{
  while (1)
  {
    GetResource(resVal);
    val++;
    ReleaseResource(resVal);
    GetResource(resVal);
    val--;
    ReleaseResource(resVal);
  }
	TerminateTask();
}
#define APP_Task_bgTask_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_periodicTask_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
volatile VAR(int, AUTOMATIC) activationCount = 0;
#define APP_Task_periodicTask_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

#define APP_Task_periodicTask_START_SEC_CODE
#include "tpl_memmap.h"
TASK(periodicTask)
{
  activationCount++;

  ledToggle(BLUE);

  if (activationCount % 2)
  {
    GetResource(resVal);
    val++;
    ReleaseResource(resVal);
  }
  else
  {
    GetResource(resVal);
    val--;
    ReleaseResource(resVal);
  }
	TerminateTask();
}
#define APP_Task_periodicTask_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_displayTask_START_SEC_CODE
#include "tpl_memmap.h"
TASK(displayTask)
{
  ledToggle(ORANGE);

  if (val < -1 || val > 2)
  {
    ledOff(GREEN);
    ledOn(RED);
  }
  else
  {
    ledOff(RED);
    ledOn(GREEN);
  }
	TerminateTask();
}
#define APP_Task_displayTask_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


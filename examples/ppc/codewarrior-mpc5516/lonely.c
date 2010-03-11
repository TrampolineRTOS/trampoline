#include "tpl_os.h"
#include "GPIO_driver.h"

#define APP_Task_iamsolonely_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
    SetOutputLine(PORT_C,11);
    SetInputLine(PORT_A,3);
    EnableIRQ3();

/*    while (1)
    {
      char button = ReadLine(PORT_A,3);
      WriteLine(PORT_C,11,button);
    } */
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
#define APP_Task_iamsolonely_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) ErrorHook(VAR(StatusType, AUTOMATIC) error)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, OS_VAR) switch_count = 0;
VAR(TaskType, OS_VAR) new_task;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_iamsolonely_START_SEC_CONST_32BIT
#include "tpl_memmap.h"
CONST(int, AUTOMATIC) tata = 0;
#define APP_Task_iamsolonely_STOP_SEC_CONST_32BIT
#include "tpl_memmap.h"

#define APP_Task_iamsolonely_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) titi = 0;
#define APP_Task_iamsolonely_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_gogo_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) toto = 0;
#define APP_Task_gogo_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) PreTaskHook(void)
{
  switch_count++;
  GetTaskID(&new_task);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

DeclareTask(iamsolonely);

#define APP_Task_iamsolonely_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void,AUTOMATIC) tpl_trigger_sw_it(void);

TASK(iamsolonely)
{
  titi = 1;
  titi = toto;
  toto = 4;
	while(1);
	TerminateTask();
}
#define APP_Task_iamsolonely_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_gogo_START_SEC_CODE
#include "tpl_memmap.h"
TASK(gogo)
{
  static char led_state = 0;
  WriteLine(PORT_C,11,led_state);
  led_state = ! led_state;
	TerminateTask();
}
#define APP_Task_gogo_STOP_SEC_CODE
#include "tpl_memmap.h"

#include "tpl_os.h"

#define APP_Task_iamsolonely_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
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
CONST(int, AUTOMATIC) toto = 0;
#define APP_Task_iamsolonely_STOP_SEC_CONST_32BIT
#include "tpl_memmap.h"

#define APP_Task_iamsolonely_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) titi = 0;
#define APP_Task_iamsolonely_STOP_SEC_VAR_32BIT
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
	//tpl_trigger_sw_it();
	TerminateTask();
}
#define APP_Task_iamsolonely_STOP_SEC_CODE
#include "tpl_memmap.h"

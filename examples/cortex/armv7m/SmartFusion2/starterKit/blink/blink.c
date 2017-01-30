#include "tpl_os.h"
#include "m2sxxx.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
	GPIO->GPIO_1_CFG = 5; //output mode.
	GPIO->GPIO_2_CFG = 5; //output mode.
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

DeclareTask (T1);

TASK(blink)
{
	ActivateTask(T1);
	TerminateTask();
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_T1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(T1)
{
	GPIO->GPIO_OUT ^= 0x6; //toggle LED3 and 4.
	TerminateTask();
}
#define APP_Task_T1_STOP_SEC_CODE
#include "tpl_memmap.h"
#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"


DeclareCounter(Software_Counter);

FUNC(int, OS_APPL_CODE) main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}



TASK(blink)
{
	TickType XXXXX;
	GetCounterValue(Software_Counter, &XXXXX);
	TerminateTask();
}

ISR(isr_button2)
{

}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

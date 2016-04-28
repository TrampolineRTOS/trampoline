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

TASK(blink)
{
	GPIO->GPIO_OUT ^= 0x2; //toggle LED3
	TerminateTask();
}

ISR(isr_fpga)
{
	GPIO->GPIO_OUT ^= 0x4; //toggle LED4
	TerminateTask();
}

//TODO: automatic implementation...
void FabricIrq0_IRQ_ClearFlag()
{
		NVIC_ClearPendingIRQ(FabricIrq0_IRQn);	
}

#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"


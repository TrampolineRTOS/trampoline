#include "tpl_os.h"
#include "pinAccess.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	initCoroBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	digitalToggle(GPIOB,0);		//toggle user led.
	TerminateTask();
}


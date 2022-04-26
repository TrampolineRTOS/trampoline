#include "tpl_os.h"
#include "pinAccess.h"
#include "tft.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	initCoroBoard();
    Tft.print("Master CORO board");
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	static uint32_t i=0;
	digitalToggle(GPIOB,0);	 //toggle user led.
	Tft.setTextCursor(0,1);  //col, line
	Tft.eraseText(7);        //up to 7 characters to print i
	Tft.print(i);
	i++;
	TerminateTask();
}

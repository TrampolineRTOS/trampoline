#include "tpl_os.h"

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
#include "buttonTasks.h"
#include "display.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	pinMode(GPIOB,0,OUTPUT);	//user led is PB0
	setupIOExtender();
	setupDisplay();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(blink)
{
	digitalToggle(GPIOB,0);		//toggle user led.
	TerminateTask();
}

/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

extern "C" void __cxa_pure_virtual() { while (1); }

#ifdef __cplusplus
}
#endif /* __cplusplus */

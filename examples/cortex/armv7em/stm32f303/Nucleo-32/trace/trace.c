#include "tpl_os.h"
#include "pinAccess.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"


FUNC(int, OS_APPL_CODE) main(void)
{
  pinMode(GPIOB,3,OUTPUT); //led 1 is PB3
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  digitalToggle(GPIOB,3);
  TerminateTask();
}

//tmp TODO: add ISR into library.
void itUsart();
ISR(usart)
{
	itUsart();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"


#include "pinAccess.h"
#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

// init PB.3 as output (LED 1 on pin 13).
void initUserLed() {
	pinMode(GPIOB,3,OUTPUT);
}

FUNC(int, OS_APPL_CODE) main(void) {
  initUserLed();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink) {
  digitalToggle(GPIOB, 3);
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#include "pinAccess.h"
#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"

#define LED_GREEN_PORT  GPIOB
#define LED_GREEN_PIN   0
#define LED_YELLOW_PORT GPIOE
#define LED_YELLOW_PIN  1
#define LED_RED_PORT    GPIOB
#define LED_RED_PIN     14

void initUserLed() {
  pinMode(LED_GREEN_PORT,LED_GREEN_PIN,OUTPUT);
  pinMode(LED_YELLOW_PORT,LED_YELLOW_PIN,OUTPUT);
  pinMode(LED_RED_PORT,LED_RED_PIN,OUTPUT);
}

FUNC(int, OS_APPL_CODE) main(void) {
  initUserLed();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink) {
  digitalToggle(LED_GREEN_PORT,LED_GREEN_PIN);
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

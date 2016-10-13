#include "tp.h"
#include "tpl_os.h"

#define APP_Task_read_button_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

DeclareAlarm(blink_alarm);

TASK(read_button)
{
  ledToggle(BLUE);
  if (SetRelAlarm(blink_alarm, 100, 100) != E_OK) {
    CancelAlarm(blink_alarm);
  } else {
    /* Nothing, the alarm is now launched */
  }
  TerminateTask();
}
#define APP_Task_read_button_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
TASK(blink)
{
  uint32 volatile time;

  ledToggle(GREEN);

  time = millis();
  if (time > 10000) {
    ledOn(ORANGE);
  }

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button_START_SEC_CODE
#include "tpl_memmap.h"
DeclareTask(read_button);

ISR(isr_button)
{
  ledToggle(RED);
  ActivateTask(read_button);
  /* If button is an ISR2 then call CallTerminateISR2 at the end of the handler otherwise do nothing more. */
  CallTerminateISR2();
}
#define APP_ISR_isr_button_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * This is necessary for ST libraries
 */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

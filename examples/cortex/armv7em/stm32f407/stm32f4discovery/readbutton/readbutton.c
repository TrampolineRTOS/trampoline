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
  static int a = 0;
  if (readButton() == BUTTON_PRESSED) {
    ledToggle(BLUE);
    if (a == 0) {
      SetRelAlarm(blink_alarm, 100, 100);
      a = 1;
    }
    else {
      CancelAlarm(blink_alarm);
      a = 0;
    }
  }
  TerminateTask();
}
#define APP_Task_read_button_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
TASK(blink)
{
  ledToggle(GREEN);
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
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


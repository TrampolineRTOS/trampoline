/* Libraries */

#include "tpl_os.h"
#include "tp_ecn.h"

/* Main */

#define APP_Task_blinker_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{            
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/* Application */

TASK(blinker)
{
    static int state = 0;
    if (state == 0) {
      state = 1;
      led_on(S0);
    }
    else {
      state = 0;
      led_off(S0);
    }
    TerminateTask();
}
#define APP_Task_blinker_STOP_SEC_CODE
#include "tpl_memmap.h"

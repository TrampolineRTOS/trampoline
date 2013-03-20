/* Libraries */

#include "tpl_os.h"
#include "tp_ecn.h"
#include "lpc22xx.h"

/* Main */

#define APP_Task_push_observer_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{            
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/* Application */

TASK(push_observer)
{
  static int pushed = 0;
  /* anti rebond */ 
  uint32 state = push_button();
  
  if (pushed == 0) {
    if (state) {
      pushed = 1;
      lcd_init();
      lcd_print_string("Pressed ");
      lcd_print_unsigned(state);
    }
  }
  else {
    if (state == 0) {
      pushed = 0;
      lcd_init();
      lcd_print_string("Released");
    }
  }
  TerminateTask();
}
#define APP_Task_push_observer_STOP_SEC_CODE
#include "tpl_memmap.h"


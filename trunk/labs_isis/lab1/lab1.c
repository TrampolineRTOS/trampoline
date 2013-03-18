/* Libraries */

#include "tpl_os.h"
#include "tp_ecn.h"

/* Main */

#define APP_Task_a_task_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{            
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

/* Application */

TASK(a_task)
{
    lcd_init();
    lcd_goto_line_column(0,0);
    lcd_print_string("I am a task");
    
    TerminateTask();
}
#define APP_Task_a_task_STOP_SEC_CODE
#include "tpl_memmap.h"

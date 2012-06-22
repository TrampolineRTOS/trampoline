/* Libraries */

#include "tpl_os.h"
#include "LPC22xx.h"
//#include "timer.h"
#include "lcd.h"

/* Main */

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{            
    // set io pins for led P1.23
    IO1DIR |= (1 << 23) ;  // pin P1.23 is an output, everything else is input after reset
    IO1CLR = 1 << 23;
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"

/* Vars */
#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, OS_VAR) switch_count = 0;
VAR(TaskType, OS_VAR) new_task;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task1_START_SEC_CONST_32BIT
#include "tpl_memmap.h"
CONST(int, AUTOMATIC) toto = 0;
#define APP_Task_task1_STOP_SEC_CONST_32BIT
#include "tpl_memmap.h"

#define APP_Task_task1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) titi = 0;
#define APP_Task_task1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task2_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) lcdstate = 0;
#define APP_Task_task2_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

/* Application */

DeclareTask(task1);
DeclareTask(task2);
DeclareTask(task3);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
void PreTaskHook()
{
  TaskType tid;
  GetTaskID(&tid);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task1)
{
/*    LCDSendTxt("1");
    
    ActivateTask(task3);
    
    LCDSendTxt("3");
 */       
    TerminateTask();
    
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task2)
{
    static int state = 0;
    if (state == 0) {
      state = 1;
      IO1CLR = 1 << 23;
    }
    else {
      state = 0;
      IO1SET = 1 << 23 ;
    }
    TerminateTask();
}
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task3)
{
/*  LCDSendTxt("2");*/
  TerminateTask();    
    
}
#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_ISR_isr_button1_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button1)
{
  LCDSendCommand(CLR_DISP);
  LCDSendTxt("B1 pressed");
}
#define APP_ISR_isr_button1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button2_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button2)
{
  LCDSendCommand(CLR_DISP);
  LCDSendTxt("B2 pressed");
}
#define APP_ISR_isr_button2_STOP_SEC_CODE
#include "tpl_memmap.h"

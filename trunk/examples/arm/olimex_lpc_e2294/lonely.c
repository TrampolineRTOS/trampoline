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

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task1)
{
    LCDSendTxt("1");
    
    ActivateTask(task3);
    
    LCDSendTxt("3");
        
    TerminateTask();
    
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task2)
{
    if (lcdstate == 0)
    {
        IO0SET = 0x00000400 ; //led on
        lcdstate = 1;
    }
    else if (lcdstate == 1)
    {
        IO0CLR = 0x00000400 ; //led off
        lcdstate = 0;
    }
    TerminateTask();
 
}
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task3)
{
  LCDSendTxt("2");
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

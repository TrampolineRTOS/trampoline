#include "tpl_os.h"
#include "LPC22xx.h"
#include "timer.h"
#include "lcd.h"

//u32 * IO0SET_var = 0xE0028004;
//IO0SET = 0xE0028004;
//u32 * IO0CLR_var = 0xE002800C;
//IO0CLR_var = 0xE002800C;

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{            
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


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

DeclareTask(task1);
DeclareTask(task2);
DeclareTask(task3);
DeclareTask(task4);

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task1)
{
    LCDSendTxt("1");
    
    ActivateTask(task3);
    
    LCDSendTxt("3");
        
    ChainTask(task2);
    
}

#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task2)
{
    //LCDSendTxt("4");
    
    IO0SET = 0x00000400 ; //led on
    WaitTimer_100us(5000); //wait
    
    ChainTask(task4);
 
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

#define APP_Task_task4_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task4)
{
    //LCDSendTxt("5");
    
    IO0CLR = 0x00000400 ; //led off
    WaitTimer_100us(5000);  //wait
    ChainTask(task2);
}

#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"

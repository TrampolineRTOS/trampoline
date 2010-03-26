/**
 *
 * This application test the timers (timer0 to initialize lcd and timer1 with IRQ for systemcounter)
 * and the lcd in the same time.
 *
 *
 */


#include "tpl_os.h"

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

#define APP_Task_task2_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) lcdstate = 0;
#define APP_Task_task2_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

DeclareTask(task1);
DeclareTask(task2);
DeclareTask(task3);

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task1)
{
    
    ActivateTask(task3);
          
    TerminateTask();
    
}

#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task2)
{
  ChainTask(task2);
 
}

#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task3)
{
    TerminateTask();    
    
}

#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"

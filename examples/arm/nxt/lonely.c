#include "tpl_os.h"
#include "nxt_motors.h" // for nxt_motor_set_speed()
#include "ecrobot_interface.h" // for NXT_PORT_A

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

#define APP_Task_task1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, AUTOMATIC) motor2speed = 0;
#define APP_Task_task1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

DeclareTask(task1);
DeclareTask(task5);

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task1)
{
    ecrobot_status_monitor("NXT task1!");
    
    nxt_motor_set_speed(NXT_PORT_A, 50, 1);
    
    while(1){
    };
    
    ChainTask(task1);
}

#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task5_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task5)
{   
    ecrobot_status_monitor("NXT task5!");
    
    motor2speed += 5;
    nxt_motor_set_speed(NXT_PORT_B, motor2speed, 1);
    
    TerminateTask();
    
}

#define APP_Task_task5_STOP_SEC_CODE
#include "tpl_memmap.h"

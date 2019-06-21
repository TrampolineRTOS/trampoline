/**
 * @file nxt_simple.c
 *
 * @section desc File description
 *
 * This application is made of two tasks. The lower priority task1 is autostart.
 * It prints its name to the display, initialize the motorA to 50% of its speed
 * and do an infinit loop. task5 is connected to an alarm which is launched every
 * second. It increases motorB speed by 5% (as the type of the speed parameter 
 * is an 8 bits, once arrived to 256, it will change its sens) and prints its 
 * name to the display. The NXT buttons are connected to ISR2s thus if you press
 * the left, right or "orange" button, each ISR2s will print to the display the 
 * ISR2 name. The stop button shutdowns the Trampoline application.
 *
 * @section copyright Copyright
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "nxt_motors.h" // for nxt_motor_set_speed()
#include "ecrobot_interface.h" // for NXT_PORT_A
#include "ecrobot_private.h"

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
VAR(unsigned, AUTOMATIC) motor2speed = 0;
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


#define APP_ISR_isr_button_start_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_button_start)
{
    ecrobot_status_monitor("isr_button_start");
    
}

#define APP_ISR_isr_button_start_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_ISR_isr_button_stop_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_button_stop)
{
    ShutdownOS(E_OK);
}

#define APP_ISR_isr_button_stop_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_ISR_isr_button_left_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_button_left)
{
    ecrobot_status_monitor("isr_button_left"); 

}

#define APP_ISR_isr_button_left_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_ISR_isr_button_right_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_button_right)
{
    ecrobot_status_monitor("isr_button_right");   

}

#define APP_ISR_isr_button_right_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file nxt_simple.c */

/**
 * @file bluetooth2.c
 *
 * @section desc File description
 *
 * This example is for a robot-car, made of 4 wheels (the 2 rear wheels are commanded by 2 motors).
 * Another motor (motorC) set the direction.
 * To turn left, set a motorC speed positive. To turn right, set a motorC speed negative.
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

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) speed = 0;
VAR(s32, AUTOMATIC) direction = 0;
VAR(s8, AUTOMATIC) buf0 = 0;
VAR(s8, AUTOMATIC) buf1 = 0;
#define DEAD_STOP 360*3
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

/* debug code */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

char dectohex(char bit)
{
    char ret = 48;
    switch(bit)
    {
        case 0:
            ret = 0x30;
            break;
        case 1:
            ret = 0x31;
            break;
        case 2:
            ret = 0x32;
            break;
        case 3:
            ret = 0x33;
            break;
        case 4:
            ret = 0x34;
            break;
        case 5:
            ret = 0x35;
            break;
        case 6:
            ret = 0x36;
            break;
        case 7:
            ret = 0x37;
            break;
        case 8:
            ret = 0x38;
            break;
        case 9:
            ret = 0x39;
            break;
        case 10:
            ret = 0x41;
            break;
        case 11:
            ret = 0x42;
            break;
        case 12:
            ret = 0x43;
            break;
        case 13:
            ret = 0x44;
            break;
        case 14:
            ret = 0x45;
            break;
        case 15:
            ret = 0x46;
            break;
    }
    return ret;
    
}

void displayHex(u32 addr, int posx, int posy)
{
    char byte = 0;
    char display [9];
    //ipc has the form : 0x2XXXYYYY
    //test : force ipc to ipc = 0xFAE0D6CB;
    
    //u32 * p;
    //p = 0x00207634;
    // *p = 0x10;
    
    
    byte = ((addr & 0xF0000000) >> 28);
    display[0] = dectohex(byte);
    
    byte = ((addr & 0x0F000000) >> 24);
    display[1] = dectohex(byte);
    
    byte = ((addr & 0x00F00000) >> 20);
    display[2] = dectohex(byte);
    
    byte = ((addr & 0x000F0000) >> 16);
    display[3] = dectohex(byte);
    
    byte = ((addr & 0x0000F000) >> 12);
    display[4] = dectohex(byte);
    
    byte = ((addr & 0x00000F00) >> 8);
    display[5] = dectohex(byte);
    
    byte = ((addr & 0x000000F0) >> 4);
    display[6] = dectohex(byte);
    
    byte = (addr & 0x0000000F);
    display[7] = dectohex(byte);
    
    display[8] = 0;
    
    display_goto_xy(posx, posy);
    display_string(display);
    
}


void displayValue(char * name, s32 value, int posx, int posy)
{
    
    display_goto_xy(posx, posy);
    display_string(name);
    display_int(value, 8);
    
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

#define APP_Task_task_idle_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_idle_START_SEC_CONST_32BIT
#include "tpl_memmap.h"
CONST(int, AUTOMATIC) toto = 0;
#define APP_Task_task_idle_STOP_SEC_CONST_32BIT
#include "tpl_memmap.h"

#define APP_Task_task_idle_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) bt_status = BT_NO_INIT;
#define APP_Task_task_idle_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

DeclareTask(task_idle);
DeclareTask(task_check_bt);
DeclareTask(task_command_motors);

#define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_idle)
{    
    ecrobot_status_monitor("TPL btslave!");
    
    while(1)
    {  
        ecrobot_init_bt_slave("LEJOS-OSEK");
       
        if (ecrobot_get_bt_status() == BT_STREAM && bt_status != BT_STREAM)
        {
            display_clear(0);
            display_goto_xy(0, 0);
            display_string("[BT]");
            display_update();
        }
        bt_status = ecrobot_get_bt_status();
        
    }	
    
}

#define APP_Task_task_idle_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_check_bt_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
VAR(u32, AUTOMATIC) command_nbr = 0;
#define APP_Task_task_check_bt_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define APP_Task_task_check_bt_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_check_bt)
{   
    static u8 bt_receive_buf[32]; 
    
    /* read packet data from the master device */  
    ecrobot_read_bt_packet(bt_receive_buf, 32);
    
    
    if((bt_receive_buf[0] != 0) || (bt_receive_buf[1] != 0))
    {
        
        displayValue("buf0:", bt_receive_buf[0], 0, 1);
        displayValue("buf1:", bt_receive_buf[1], 0, 2);
        display_update();
        
        /* save variables */
        /* TODO : No needs to GetResource because they (speed and direction)
         * are written by task_check_bt ad read by task_command_motors ?
         */
        speed = (s32)((s8)bt_receive_buf[0]);
        direction = (s32)((s8)bt_receive_buf[1]);
        
    }
        
    bt_receive_buf[0] = 0;
    bt_receive_buf[1] = 0;
        
    TerminateTask();
    
    
}

#define APP_Task_task_check_bt_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task_command_motors_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) motorCgetcount = 0;
VAR(s32, AUTOMATIC) motorCcommand = 0;
VAR(s8, AUTOMATIC) motorCcommands8 = 0;
#define APP_Task_task_command_motors_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task_command_motors_START_SEC_CONST_8BIT
#include "tpl_memmap.h"
CONST(u8, AUTOMATIC) K = 1;
#define APP_Task_task_command_motors_STOP_SEC_CONST_8BIT
#include "tpl_memmap.h"

#define APP_Task_task_command_motors_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_command_motors)
{
    /* TODO : translate asservissement in english */
    /* Asservissment K (PID in the futur ?) of motorCposition according to direction */
    
    /* direction motor (motorC) */
    motorCgetcount = ecrobot_get_motor_rev(NXT_PORT_C);
    
    /* command motor according to position */
    motorCcommand = K*(direction - motorCgetcount);
    
    if (motorCcommand > 100)
    {
        motorCcommands8 = 100; 
    }
    else if (motorCcommand < 100)
    {
        motorCcommands8 = -100; 
    }
    else
    {
        motorCcommands8 = motorCcommand;
    }
    
    ecrobot_set_motor_speed(NXT_PORT_C, motorCcommand);
    
    
    displayValue("speed:", speed, 0, 4);
    displayValue("dir:", direction, 0, 5);
    displayValue("getC:", motorCgetcount, 0, 6);
    displayValue("cmdC:", motorCcommand, 0, 7);
    display_update();

    /* rear motors */
    ecrobot_set_motor_speed(NXT_PORT_B, speed);
    ecrobot_set_motor_speed(NXT_PORT_A, speed);
    
    TerminateTask();
}

#define APP_Task_task_command_motors_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button_stop_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_button_stop)
{
    ShutdownOS(E_OK);
}

#define APP_ISR_isr_button_stop_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file bluetooth2.c */

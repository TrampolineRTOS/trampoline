/**
 * @file littleTrain1.c
 *
 * @section desc File description
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
#include "nxt_motors.h" /* for nxt_motor_set_speed() */
#include "ecrobot_interface.h" /* for NXT_PORT_A */

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) speed = 0;
VAR(s32, AUTOMATIC) direction = 0;
#define ULTRASONICMOTORSPEED 30
#define ULTRASONICMOTORDEADSTOP 120
#define IMPOSSIBLEDATA 128
VAR(u8, AUTOMATIC) bt_cmd[2];
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

/* debug code */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void displayValue(char * name, s32 value, int posx, int posy)
{
    
    display_goto_xy(posx, posy);
    display_string(name);
    display_int(value, 3);
    
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* end debug code */

#define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void ShutdownHook(StatusType error)
{ 
	ecrobot_term_sonar_sensor(NXT_PORT_S1);
}

#define APP_Task_task_idle_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_idle_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) bt_status = BT_NO_INIT;
VAR(boolean, AUTOMATIC) bt_connected = FALSE;
#define APP_Task_task_idle_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

DeclareTask(task_idle);
DeclareTask(task_send_bt);
DeclareTask(task_command_motors);
DeclareResource(DisplayResource);

#define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_idle)
{    
  display_goto_xy(0, 4);
  display_string("Waiting for");
  display_goto_xy(0, 5);
  display_string("bluetooth (<15s)");
  
  ecrobot_init_sonar_sensor(NXT_PORT_S1);
  
  while(bt_connected == FALSE)
  {
    ecrobot_init_bt_slave("LEJOS-OSEK");
   
    if (ecrobot_get_bt_status() == BT_STREAM && bt_status != BT_STREAM)
    {
        display_clear(0);
        display_goto_xy(0, 0);
        display_string("[BT]");
        display_update();
        bt_connected = TRUE;
    }
    bt_status = ecrobot_get_bt_status();
  } 
  
  display_string("connected !");
  
  TerminateTask();
  
}

#define APP_Task_task_idle_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_command_motors_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) motorCgetcount = 0;
VAR(s32, AUTOMATIC) motorCcommand = 0;
VAR(s8, AUTOMATIC) motorCcommands8 = 0;
VAR(u8, AUTOMATIC) var = 0;
#define K 1
#define APP_Task_task_command_motors_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task_command_motors_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_command_motors)
{
  
  /* Send datas just to check pc does the right direction */
  bt_cmd[0] = (u8)speed;
  bt_cmd[1] = (u8)direction;
  ecrobot_send_bt_packet(bt_cmd, (u32)2);
  
  displayValue("motorC:", motorCgetcount, 0, 4);
  display_update();
  
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

extern u8 bt_frame[128];
extern boolean bt_frame_received;

#define APP_ISR_isr_bluetooth_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_bluetooth)
{
  if(bt_frame_received == TRUE)
  {
    speed = (s32)((s8)bt_frame[0]);
    direction = (s32)((s8)bt_frame[1]);
    
    ecrobot_set_motor_speed(NXT_PORT_A, speed);
    displayValue("speed:", speed, 0, 2);
    displayValue("direction:", direction, 0, 3);
    
  }
  
}

#define APP_ISR_isr_bluetooth_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file littleTrain1.c */

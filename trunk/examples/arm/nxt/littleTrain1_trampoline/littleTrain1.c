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
#include "nxt_motors.h" // for nxt_motor_set_speed()
#include "ecrobot_interface.h" // for NXT_PORT_A
#include <math.h>

#define BETA_INIT 0.000000001
#define TICK_PER_ROTATION 360 // TODO : Find a way to synchronize viper2 and trampoline about TICK_PER_ROTATION
#define PI 3.141592
#define RADIUS 2.1 //2.17
#define ZERO 0.0
#define VALUESMAX 6

#define APP_Task_Odometry_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(u8, AUTOMATIC) gap = 15.2; //15.3
VAR(s8, AUTOMATIC) motorright =0, motorleft=0;
VAR(double, AUTOMATIC) theta = 1.570796;
VAR(double, AUTOMATIC) position[2] = {0,30};
VAR(double, AUTOMATIC) position_old[2] = {0,20};
VAR(double, AUTOMATIC) tickincm = 2*PI*RADIUS/TICK_PER_ROTATION; 
VAR(double, AUTOMATIC) beta = 0.000000000;
VAR(double, AUTOMATIC) r;
VAR(double, AUTOMATIC) m1=0, m2=0;
VAR(double, AUTOMATIC) dx=0, dy=1.0;
VAR(double, AUTOMATIC) dx_done=0, dy_done=0;
VAR(double, AUTOMATIC) dx_old=0, dy_old=0;
VAR(tpl_bool, AUTOMATIC) motorstopped = FALSE;

VAR(double, AUTOMATIC) values[VALUESMAX]={0,0,0,0,0,0};
VAR(u8, AUTOMATIC) valuesindex = 0;
VAR(u8, AUTOMATIC) valuesindexsent = 0;
VAR(tpl_bool, AUTOMATIC) valuesmodified = FALSE;

VAR(double, AUTOMATIC) hyp=0;
VAR(s32, AUTOMATIC) temp1=0, temp2=0;
VAR(s32, AUTOMATIC) sensor1=0, sensor2=0;

VAR(u8, AUTOMATIC) ifor;
VAR(u8, AUTOMATIC) valuesmissing = 0;
VAR(u8, AUTOMATIC) bt_send_buf[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
VAR(u16, AUTOMATIC) tempu16;

#define APP_Task_Odometry_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

/* debuf code 
//		conversion decimal to hexa
char dectohex(char bit)
{
	char ret;
	ret = bit + 0x30;
	if (bit >= 10) 
	{
		ret += 7;
	}
	return ret;
}

//		aficher en hexa sur le robot
void displayHex(u32 addr, int posx, int posy)
{
	char byte = 0;
	char display [9];
	
	// TODO : change this
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
*/

#define APP_Task_task_idle_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_idle_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) bt_status = BT_NO_INIT;
VAR(boolean, AUTOMATIC) bt_connected = FALSE;
#define APP_Task_task_idle_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

DeclareTask(task_idle);
DeclareTask(Odometry);
DeclareTask(Send);

#define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_idle)
{    
  display_goto_xy(0, 4);
  display_string("Waiting for");
  display_goto_xy(0, 5);
  display_string("bluetooth (<15s)");
  
  
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


#define APP_Task_Odometry_START_SEC_CODE
#include "tpl_memmap.h"

TASK(Odometry)
{
	temp1 = ecrobot_get_motor_rev (NXT_PORT_A);
	temp2 = ecrobot_get_motor_rev (NXT_PORT_B);
	
	//Converts ticks in centimeters 
	m1=(double)((temp1-sensor1)*tickincm);
	m2=(double)((temp2-sensor2)*tickincm);
	
	sensor1=temp1;
	sensor2=temp2;
	
	if (m1 == m2)
    {
		if (m1 != ZERO)
		{
			hyp = sqrt(dx*dx+dy*dy);
			
			// Store actual position in old position  
			position_old[0] = position[0];
			position_old[1] = position[1];
			
			// Move the robot lower or faster according to the sensors  
			position[0] += m1*dx/hyp;
			position[1] += m2*dy/hyp;  
			
			// Find last movement (dx and dy)  
			dx = position[0] - position_old[0];
			dy = position[1] - position_old[1];
		
			values[valuesindex] = dx;
			valuesindex = (valuesindex+1)%6;
			values[valuesindex] = dy;
			valuesindex = (valuesindex+1)%6;
			valuesmodified = TRUE;
					
			dx_done += dx;
			dy_done += dy;
			
		}
		
	}
	else 
	{
		//Find beta : delta angle due to new sensor values 
		beta = (m1 - m2)/gap;
		
        // Store actual position in old position  
        position_old[0] = position[0];
        position_old[1] = position[1];
        
        // Find radius to the circle the robot is moving on  
        r = (m1 + m2)/(2*beta);
        
        // Find coordinates of the circle's center (the robot is moving on)  
        double x0 = position[0] - r*sin(theta);
        double y0 = position[1] + r*cos(theta);
		
        // Increment angle adding delta angle  
        theta += beta;
		
        // Find next position  
        position[0] = x0 + r*sin(theta);
        position[1] = y0 - r*cos(theta);
		
		// Find last movement (dx and dy)  
		dx = position[0] - position_old[0];
		dy = position[1] - position_old[1];
		
		values[valuesindex] = dx;
		valuesindex = (valuesindex+1)%6;
		values[valuesindex] = dy;
		valuesindex = (valuesindex+1)%6;
		valuesmodified = TRUE;
		
		dx_done += dx;
		dy_done += dy;
		
		
	}
	
	display_goto_xy(0, 2);
	display_string("tourne");
	display_int(dx*100,2);
	display_int(dy*100,2);
	
	display_goto_xy(0, 3);
	display_string("dx_do");
	display_int(dx_done,2);
	display_int(dy_done,2);
	
	display_goto_xy(0, 4);
	display_string("pos:");
	display_int(position[0],2);
	display_int(position[1],2);
	
	display_update();
	
	
	TerminateTask();
}

#define APP_Task_Odometry_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_Send_START_SEC_CODE
#include "tpl_memmap.h"

TASK(Send)
{    
	if (valuesmodified == TRUE)
	{
		if (valuesindex <= valuesindexsent)
		{
			valuesmissing = valuesindex + VALUESMAX - valuesindexsent;
		}
		else
		{
			valuesmissing = valuesindex - valuesindexsent;
		}
		
		display_goto_xy(0, 6);
		display_string("buf:");
		
		for(ifor=0;ifor<valuesmissing;ifor++)
		{
			tempu16 = (u16)(values[valuesindexsent]*100);
			bt_send_buf[2*ifor] = (u8)(tempu16>>8);
			bt_send_buf[2*ifor+1] = (u8)(tempu16);
			valuesindexsent = (valuesindexsent+1)%6;
			display_int(bt_send_buf[2*ifor],2);
			display_int(bt_send_buf[2*ifor+1],2);
		}
		
		display_goto_xy(0, 5);
		display_string("valmiss:");
		display_int(valuesmissing,2);
		
		ecrobot_send_bt_packet(bt_send_buf,valuesmissing*2);
		valuesmodified = FALSE;
	}
	
	TerminateTask();    
}

#define APP_Task_Send_STOP_SEC_CODE
#include "tpl_memmap.h"



extern u8 bt_frame[128];
extern boolean bt_frame_received;

#define APP_ISR_isr_bluetooth_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_bluetooth)
{
	if(bt_frame_received == TRUE)
	{
		switch (bt_frame[0])
		{
			case 1: // forward
				
				if ((motorright==0)&&(motorleft==0))
				{
					motorright += 20;
					motorleft += 20;
				}
				else
				{
					if (motorright ==100)
						motorright=100;
					else
						motorright += 10;
					if (motorleft==100)
						motorleft=100;
					else
						motorleft += 10;
				}
				break;
				
			case 2: //slow down. Going backward is impossible
				
				if (motorright == 20)
					motorright=0;
				else if (motorright ==0)
					motorright = 0;
				else 
					motorright -=10;
				
				if (motorleft ==20)
					motorleft =0;
				else if (motorleft == 0)
					motorleft = 0;
				else 
					motorleft -=10;
				break;
				
			case 3: //turn left
				if (motorright==0)
					motorright +=20;
				else
					motorright += 10;
				break;
				
			case 4: //turn right
				if (motorleft==0)
					motorleft +=20;
				else motorleft +=10;
				break;
				
			default:
				break;            
		}
		
		ecrobot_set_motor_speed(NXT_PORT_A, motorleft);
		ecrobot_set_motor_speed(NXT_PORT_B, motorright);
	}
}

#define APP_ISR_isr_bluetooth_STOP_SEC_CODE
#include "tpl_memmap.h"



#define APP_ISR_isr_button_stop_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button_stop)
{
    ShutdownOS(E_OK);
}
#define APP_ISR_isr_button_stop_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file littleTrain1.c */

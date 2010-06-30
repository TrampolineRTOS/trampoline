/**
 * @file littleTrain2.c
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
#include <math.h>


#define BETA_INIT 0.000000001
#define TICK_PER_ROTATION 360 // TODO : Find a way to synchronize viper2 and trampoline about TICK_PER_ROTATION
#define PI 3.141592
#define RADIUS 2.1
#define PREC 5.000

#define SPEED 25.0

u8 gap = 15.2;
double theta = 1.570796;
double tickincm = 2*PI*RADIUS/TICK_PER_ROTATION;

double beta_odometry = 0.001;
double beta_odometry_moins=0.001;
double position[2] = {0,10};
double position_old[2] = {0,0};
double r=0, r_odometry=0;
double m1=0, m2=0;
double m1_odometry =0,m2_odometry =0;
double dx_over_dy=0;
double hyp =0;
s32 sensor1 =0, sensor2=0;
s32 temp1=0, temp2=0; 
double speed_L=0, speed_R=0;
double dx=0, dy=0, dx_temp=0;

//double dx_final_tbl[7] = {50,50 ,0  ,0 ,50,50,0};
//double dy_final_tbl[7] = {50,100,100,50,50,0 ,0};
//u8 i_tbl = 0;
u8 commandmotors = TRUE;

double dx_final =0, dy_final=0;
double dx_done =0, dy_done=0;
double dx_odometry=0, dy_odometry=1, dx_odometry_temp=0;
double dy_by_dx = 0;
s16 dx0=0, dx1=0, dx2=0;
s16 dy0=0, dy1=0, dy2=0;

double speed = SPEED;
double rtd = 360/(2*PI);
double turnmore = 0.5;
double anglediff = 0;
double angletofollow = 0;
double actualangle = PI/2;
double addangletoactualangle = 0;
double deltaspeed = 0;

/* debug code */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

/*
//		conversion decimal vers hexa
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

//  aficher en hexa sur le robot
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


void displayValue(char * name, s32 value, int posx, int posy)
{
    
    display_goto_xy(posx, posy);
    display_string(name);
    display_int(value, 3);
    
}
*/

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* end debug code */




#define APP_Task_task_idle_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(s32, AUTOMATIC) bt_status = BT_NO_INIT;
VAR(boolean, AUTOMATIC) bt_connected = FALSE;
#define APP_Task_task_idle_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


DeclareTask(task_idle);
DeclareTask(MotorControl);
DeclareTask(Odometry);


 #define APP_Task_task_idle_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_idle)
{    
	display_goto_xy(0, 7);
	display_string("Waiting for");
	display_update();
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
	temp1 = ecrobot_get_motor_rev (NXT_PORT_B);
	temp2 = ecrobot_get_motor_rev (NXT_PORT_A);
	
	//Converts ticks in centimeters 
	m1_odometry=(double)((temp1-sensor1)*tickincm);
	m2_odometry=(double)((temp2-sensor2)*tickincm);
	
	sensor1=temp1;
	sensor2=temp2;
	
	
	//Find beta_odometry : delta angle due to new sensor values 
	beta_odometry = (m1_odometry - m2_odometry)/gap; 
	
	beta_odometry_moins = beta_odometry*(-1);
	
	if ((beta_odometry < BETA_INIT) && (beta_odometry_moins) < BETA_INIT)
    {
        if ( (m1_odometry != 0) && (m2_odometry != 0) )
        {
			hyp = sqrt((dx_odometry*dx_odometry)+(dy_odometry*dy_odometry));
			
			// Store actual position in old position  
            position_old[0] = position[0];
            position_old[1] = position[1];
            
			// Move the robot lower or faster according to the sensors  
            position[0] += m2_odometry*dx_odometry/hyp;
            position[1] += m1_odometry*dy_odometry/hyp;  
			
			// Find last movement (dx and dy)  
			dx_odometry = position[0] - position_old[0];
			dy_odometry = position[1] - position_old[1];
			
			dx_done += dx_odometry;
			dy_done += dy_odometry;
			
		}
	}
	else 
	{
        // Store actual position in old position  
        position_old[0] = position[0];
        position_old[1] = position[1];
        
        // Find radius to the circle the robot is moving on  
        r_odometry = (m1_odometry + m2_odometry)/(2*beta_odometry);
        
        // Find coordinates of the circle's center (the robot is moving on)  
        double x0 = position[0] - r_odometry*sin(theta);
        double y0 = position[1] + r_odometry*cos(theta);
		
		
		// Increment angle adding delta angle  
        theta += beta_odometry;
		
        // Find next position  
        position[0] = x0 + r_odometry*sin(theta);
        position[1] = y0 - r_odometry*cos(theta);
		
		// Find last movement (dx_odometry and dy_odometry)  
		dx_odometry = position[0] - position_old[0];
		dy_odometry = position[1] - position_old[1];
		
		dx_done += dx_odometry;
		dy_done += dy_odometry;
		
	}
	
	//find the actual angle
	// if dx==0
	if ((dx_odometry == 0) && (dy_odometry != 0))
	{
		dx_odometry_temp = BETA_INIT;
	}
	else
	{
		dx_odometry_temp = dx_odometry;
	}
	
	/*
	// if dx/dy<0
	if ( (dx_odometry_temp < 0) && (dy_odometry > 0) )
	{
		actualangle = PI + atan(dy_odometry/dx_odometry_temp);
		
//		display_goto_xy(0,5);
//		display_string ("dy_by_dx<0!?");
//		display_goto_xy(0,6);
//		display_string ("dy/dx_o:");
//		display_int(dx_odometry_temp*10000,2);
//		display_int((dy_odometry/dx_odometry_temp),2);
//		while(1);
		
	}
	else if ( (dx_odometry_temp < 0) && (dy_odometry < 0) )
	{
		actualangle = PI + atan(dy_odometry/dx_odometry_temp);
	}
	else if ((dx_odometry_temp > 0))
	{
		actualangle = atan(dy_odometry/dx_odometry_temp);
	}
	*/
	actualangle = atan2(dy_odometry,dx_odometry_temp);
	
	/*
	display_goto_xy(0,0);
	display_string("dx_o:");
	display_int(dx_odometry*100,5);
	display_goto_xy(0,1);
	display_string("dy_o:");
	display_int(dy_odometry*100,5);
	display_goto_xy(0,2);
	display_string("dx_do:");
	display_int(dx_done,5);
	display_goto_xy(0,3);
	display_string("dy_do:");
	display_int(dy_done,5);
	display_goto_xy(0,6);
	display_string("beta_o:");
	display_int(beta_odometry*100,6);
	
	display_update();
	 */
	
	
	TerminateTask();
}

#define APP_Task_Odometry_STOP_SEC_CODE
#include "tpl_memmap.h"



#define APP_Task_MotorControl_START_SEC_VAR_32BIT
#include "tpl_memmap.h"

VAR(s8, AUTOMATIC) speed_left = 0;
VAR(s8, AUTOMATIC) speed_right = 0;

#define APP_Task_MotorControl_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_MotorControl_START_SEC_CODE
#include "tpl_memmap.h"

TASK(MotorControl)
{   
	dx = dx_final - dx_done;
	dy = dy_final - dy_done;
	
	if ( (((dx > 0) && (dx < PREC)) || ((dx < 0) && (dx > -PREC))) && (((dy > 0) && (dy < PREC)) || ((dy < 0) && (dy > -PREC))) )
	{
		display_goto_xy(0,5);
		display_string ("finish!");
		ecrobot_set_motor_speed(NXT_PORT_A, 0);
		ecrobot_set_motor_speed(NXT_PORT_B, 0);
		//go to another point
		/*i_tbl++;
		if (i_tbl == 7)
		{
			while(1);
		}
		dx_final = dx_final_tbl[i_tbl];
		dy_final = dy_final_tbl[i_tbl];
		*/
		//commandmotors = FALSE;
	}
	else 
	{
		// careful too small value
		if (dx == 0)
		{
			dx_temp = BETA_INIT;
		}
		else
		{
			dx_temp = dx;
		}
		// careful dy_by_dx negative
		dy_by_dx = dy/dx_temp;
		
		/*
		if ( (dx < 0) && (dy > 0) )
		{
			display_goto_xy(0,6);
			display_string ("< >");
			angletofollow = PI + atan(dy_by_dx);
		}
		else if ( (dx < 0) && (dy < 0) )
		{
			display_goto_xy(0,6);
			display_string ("< <");
			angletofollow = PI + atan(dy_by_dx);
		}
		else if ((dx > 0))
		{
			display_goto_xy(0,6);
			display_string (">");
			angletofollow = atan(dy_by_dx);
		}
		*/
		angletofollow = atan2(dy,dx_temp);
		anglediff = angletofollow - actualangle;
		
		if (anglediff > PI)
		{
			anglediff -= 2*PI;
		}
		else if (anglediff < -PI)
		{
			anglediff += 2*PI;
		}
		
		//deltaspeed = (anglediff * SPEED)/PI;
		
		speed_L = speed - anglediff*rtd*turnmore;
		speed_R = speed + anglediff*rtd*turnmore;
		//careful too big speed
		if (speed_L > 70.0)
		{
			speed_L = 70.0;
		}
		else if (speed_L < 0)
		{
			speed_L = 0;
		}
		if (speed_R > 70.0)
		{
			speed_R = 70.0;
		}
		else if (speed_R < 0)
		{
			speed_R = 0;	
		}
		
		//convert in u8 to respect function's prototype
		speed_left = (s8)speed_L;
		speed_right = (s8)speed_R;
	
		if (commandmotors == TRUE)
		{
			// Apply values to motors
			ecrobot_set_motor_speed(NXT_PORT_A, speed_left);
			ecrobot_set_motor_speed(NXT_PORT_B, speed_right);
		}
		
		
		
		display_goto_xy(0,0);
		display_string ("dxy_f:");
		display_int(dx_final,4);
		display_int(dy_final,4);
		
		display_goto_xy(0,1);
		display_string ("dxy_o:");
		display_int(dx_odometry*100,4);
		display_int(dy_odometry*100,4);
		
		display_goto_xy(0,2);
		display_string ("dxy_do:");
		display_int(dx_done,4);
		display_int(dy_done,4);
		
		display_goto_xy(0,3);
		display_string("dxy:");
		display_int(dx,4);
		display_int(dy,4);
		
		display_goto_xy(0,4);
		display_string ("ang_fa:");
		display_int(angletofollow*rtd,2);
		display_int(actualangle*rtd,4);
		
		display_goto_xy(0,6);
		display_string ("ang_dif:");
		display_int(anglediff*rtd,2);
		
		
		
		display_update();
		
		/*u8 bt_send_buf[18];
		 
		 bt_send_buf[0]=(u8)((u32)(dx_odometry*100)>>8);
		 bt_send_buf[1]=(u8)dx_odometry*100;
		 bt_send_buf[2]=(u8)((u32)(dy_odometry*100)>>8);
		 bt_send_buf[3]=(u8)dy_odometry*100;
		 bt_send_buf[4]=(u8)((u32)(dx_done)>>8);
		 bt_send_buf[5]=(u8)dx_done;
		 bt_send_buf[6]=(u8)((u32)(dy_done)>>8);
		 bt_send_buf[7]=(u8)dy_done; 
		 bt_send_buf[8]=(u8)((u32)(dx)>>8);
		 bt_send_buf[9]=(u8)dx;
		 bt_send_buf[10]=(u8)((u32)(dy)>>8);
		 bt_send_buf[11]=(u8)dy; 
		 bt_send_buf[12]=(u8)((u32)(dy_by_dx*100)>>8);
		 bt_send_buf[13]=(u8)dy_by_dx*100;
		 bt_send_buf[14]=(u8)((u32)(angletofollow*rtd)>>8);
		 bt_send_buf[15]=(u8)angletofollow*rtd; 	
		 bt_send_buf[16]=(u8)((u32)(actualangle*rtd)>>8);
		 bt_send_buf[17]=(u8)actualangle*rtd; 	
		 
		 ecrobot_send_bt_packet(bt_send_buf,18);
		 */
		/*
		if (i_tbl == 3)
		{
			while(1);
		}
		*/
	}
	
		
	TerminateTask();
}


#define APP_Task_MotorControl_STOP_SEC_CODE
#include "tpl_memmap.h"



extern u8 bt_frame[128];
extern boolean bt_frame_received;
extern u8 bt_length;
u8 i;
u16 tempu16 = 0;

#define APP_ISR_isr_bluetooth_START_SEC_CODE
#include "tpl_memmap.h"

ISR(isr_bluetooth)
{
	display_goto_xy(0,7);
	display_string("isr!!!!!!!!!");
	
	if(bt_frame_received == TRUE)
	{
		if (bt_length%2)
		{
			display_goto_xy(0,7);
			display_string("bt_length:");
		}
		else
		{
			display_goto_xy(0,7);
			display_string("bt_length:");
		}
		display_int(bt_length,2);
		
		for(i=0; i<(bt_length/2) ; i++)
		{
			tempu16 =((bt_frame[2*i])<<8);
			tempu16 |= bt_frame[(2*i)+1];
			if ( (i%2) == 1)
			{
				dy_final += tempu16/100;
			}
			else
			{
				dx_final += tempu16/100;
			}
		}
		
		/*
		dy0 =((bt_frame[2])<<8);
		dy0 |= bt_frame[3];
		
		dx1 =((bt_frame[4])<<8);
		dx1 |= bt_frame[5];
		dy1 =((bt_frame[6])<<8);
		dy1 |= bt_frame[7];
		
		dx2 =((bt_frame[8])<<8);
		dx2 |= bt_frame[9];
		dy2 =((bt_frame[10])<<8);
		dy2 |= bt_frame[11];
		 */
		
 /*		display_goto_xy(0,2);
 		display_string("dx0:");
 		displayHex(dx0,4,2);
 		display_goto_xy(0,3);
 		display_string("dy0:");
 		displayHex(dy0,4,3);
 		display_goto_xy(0,4);
 		display_string("dx1:");
 		displayHex(dx1,4,4);
 		display_goto_xy(0,5);
 		display_string("dy1:");
 		displayHex(dy1,4,5);
 		display_goto_xy(0,6);
 		display_string("dx2:");
 		displayHex(dx2,4,6);
 		display_goto_xy(0,7);
 		display_string("dy2:");
		displayHex(dy2,4,7);
		display_update();
*/		
		/*dx_final += (dx0+dx1+dx2)/100;
		dy_final += (dy0+dy1+dy2)/100;
		 */
		
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

 

/* End of file littleTrain2.c */

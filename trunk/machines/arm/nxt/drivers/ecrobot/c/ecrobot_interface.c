/*****************************************************************************
 * FILE: ecrobot_interface.c
 *
 * COPYRIGHT 2008 Takashi Chikamasa <takashic@cybernet.co.jp>
 *
 * <About leJOS NXJ>
 *  leJOS NXJ is a full firmware replacement of LEGO Mindstorms NXT and 
 *  designed for Java programming environment for the NXT 
 *  ( For more detailed information, please see: http://lejos.sourceforge.net/ )
 *  In the leJOS NXJ distribution, C source files for NXT platform layer is also
 *  included besides with the Java VM. The platform C source code is well
 *  structured, comprehensive, and achieved higher performance than the LEGO's
 *  one. Therefore, leJOS NXJ (platform) is also the best GCC based C/C++  
 *  development platform for NXT.
 *
 *  The contents of this file are subject to the Mozilla Public License
 *  Version 1.0 (the "License"); you may not use this file except in
 *  compliance with the License. You may obtain a copy of the License at
 *  http://www.mozilla.org/MPL/
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 *
 *  The Original Code is TinyVM code, first released March 6, 2000,
 *  later released as leJOS on September 23, 2000.
 *
 *  The Initial Developer of the Original Code is Jose H. Solorzano.
 *
 *  Contributor(s): see leJOS NXJ ACKNOWLEDGEMENTS .
 *
 *
 * <About TOPPERS OSEK>
 *  TOPPERS OSEK is an open source OSEK kernel and developed by TOPPERS project.
 *  TOPPERS(Toyohashi OPen Platform for Embedded Real-time Systems) has been managed 
 *  by a Non Profit Organization founded in Sep. 2003 and has been led by Professor
 *  Hiroaki Takada of Nagoya University in Japan. 
 *
 *  TOPPERS OSEK program is covered by the TOPPERS License as published
 *  by the TOPPERS PROJECT (http://www.toppers.jp/en/index.html).
 *
 *****************************************************************************/

#include <stddef.h>
#include <string.h>

#include "ecrobot_base.h"
#include "ecrobot_private.h"
#include "ecrobot_interface.h"

static U8 deviceStatus = DEVICE_NO_INIT;


/*==============================================================================
 * NXT Servo Motor API
 *=============================================================================*/

/**
 * set Servo Motor PWM duty ratio
 *
 * @param port_id: NXT_PORT_A/NXT_PORT_B/NXT_PORT_C
 * @param speed: PWM duty ration (-100 to 100)
 */
void ecrobot_set_motor_speed(U8 port_id, S8 speed)
{
	/* 1st arg:port id (0/1/2)        */
	/* 2nd arg:speed (-100 to 100)    */
	/* 3rd arg:mode (1:brake/0:float) */

	/* As far as we tested the controllability of motor position for 
	 * precise real-time control applications (e.g. NXTway-GS, NXT GT)
	 * brake mode seems to be better.
	 */
	nxt_motor_set_speed(port_id, speed, 1);
}

/**
 * set Servo Motor brake mode and PWM duty ratio
 *
 * @param port_id: NXT_PORT_A/NXT_PORT_B/NXT_PORT_C
 * @param mode: 0(float)/1(brake)
 * @param speed: PWM duty ratio (-100 to 100)
 */
void ecrobot_set_motor_mode_speed(U8 port_id, S32 mode, S8 speed)
{
	/* 1st arg:port id (0/1/2)        */
	/* 2nd arg:speed (-100 to 100)    */
	/* 3rd arg:mode (1:brake/0:float) */
	nxt_motor_set_speed(port_id, speed, mode);
}

/**
 * get Servo Motor revolution in degree
 *
 * @param port_id: NXT_PORT_A/NXT_PORT_B/NXT_PORT_C
 * @return: motor revolution in degree
 */
S32 ecrobot_get_motor_rev(U8 port_id)
{
	return nxt_motor_get_count(port_id);
}

/**
 * set Servo Motor revolution in degree
 *
 * @param port_id: NXT_PORT_A/NXT_PORT_B/NXT_PORT_C
 * @param rev: motor revolution in degree
 */
void ecrobot_set_motor_rev(U8 port_id, S32 rev)
{
	nxt_motor_set_count(port_id, rev);
}


/*==============================================================================
 * NXT A/D Sensors API
 *=============================================================================*/

/**
 * turn infra-red light on
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_set_light_sensor_active(U8 port_id)
{
	set_digi0(port_id);
}

/**
 * turn infra-red light off
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_set_light_sensor_inactive(U8 port_id)
{
	unset_digi0(port_id);
}

/**
 * get Light Sensor raw A/D data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: A/D raw data(0 to 1023)
 */
U16 ecrobot_get_light_sensor(U8 port_id)
{
	return (U16)sensor_adc(port_id);
}

/**
 * get Touch Sensor on/off status
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: 1(touched)/0(not touched)
 */
U8 ecrobot_get_touch_sensor(U8 port_id)
{
	return (sensor_adc(port_id) < 512);
}

/**
 * get Sound Sensor raw A/D data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: A/D raw data(0 to 1023)
 */
U16 ecrobot_get_sound_sensor(U8 port_id)
{
	return (U16)sensor_adc(port_id);
}


/*==============================================================================
 * NXT I2C API
 *=============================================================================*/
/**
 * init a NXT sensor port for I2C communication
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param type: LOWSPEED_9V/LOWSPEED
 */
void ecrobot_init_i2c(U8 port_id, U8 type)
{
	if (deviceStatus == DEVICE_NO_INIT)
	{
		nxt_avr_set_input_power(port_id, type);
		i2c_enable(port_id);
	}
}

/**
 * wait until I2C communication is ready
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param wait: wait time out in msec
 * @return: 1(I2C is ready)/0(time out)
 */
U8 ecrobot_wait_i2c_ready(U8 port_id, U32 wait)
{
	volatile U32 time_out;

	time_out = systick_get_ms() + wait;
	while(systick_get_ms() <= time_out)
	{
		if (i2c_busy(port_id) == 0) return 1;
	}
	return 0; /* time out */
}

/**
 * send I2C data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param address: 0x01 to 0x7F
 *  Note that addresses are from 0x01 to 0x7F not
 *  even numbers from 0x02 to 0xFE as given in some I2C device specifications.
 *  They are 7-bit addresses not 8-bit addresses.
 * @param i2c_reg: I2C register e.g. 0x42
 * @param buf: buffer containing data to send
 * @param len: length of the data to send
 * @return: 1(success)/0(failure)
 */
SINT ecrobot_send_i2c(U8 port_id, U32 address, SINT i2c_reg, U8 *buf, U32 len)
{
	SINT ret;
	
	ecrobot_wait_i2c_ready(port_id, 50);
	ret = i2c_start_transaction(port_id, address, i2c_reg, 1, buf, len, 1);
	return !ret;
}

/**
 * read I2C data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param address: 0x01 to 0x7F
 *  Note that addresses are from 0x01 to 0x7F not
 *  even numbers from 0x02 to 0xFE as given in some I2C device specifications.
 *  They are 7-bit addresses not 8-bit addresses.
 * @param i2c_reg: I2C register e.g. 0x42
 * @param buf: buffer to return data
 * @param len: length of the return data
 * @return: 1(success)/0(failure)
 */
SINT ecrobot_read_i2c(U8 port_id, U32 address, SINT i2c_reg, U8 *buf, U32 len)
{
	SINT ret;

	ecrobot_wait_i2c_ready(port_id, 50);
	ret = i2c_start_transaction(port_id, address, i2c_reg, 1, buf, len, 0);
	return !ret;
}

/**
 * terminate a NXT sensor port used for I2C communication
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_i2c(U8 port_id)
{
	i2c_disable(port_id);
}


/*==============================================================================
 * NXT Ultrasonic Sensor API
 *=============================================================================*/
static S32 distance_state[4] = {-1,-1,-1,-1}; /* -1: sensor is not connected */

static S32 getDistance(void)
{
	SINT i;
	
	/*
 	 * if multiple Ultrasonic Sensors are connected to a NXT,
 	 * only the senosr measurement data which is connected to the smallest port id
 	 * can be monitored in LCD and logging data.
 	 */
	for (i = 0; i < 4; i++)
	{
		if (distance_state[i] != -1)
		{
			return distance_state[i];
		}
	}
	return -1;
}

/**
 * init a NXT sensor port for Ultrasonic Sensor
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_init_sonar_sensor(U8 port_id)
{
	ecrobot_init_i2c(port_id, LOWSPEED);
}

/**
 * get Ultrasonic Sensor measurement data in cm
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: distance in cm (0 to 255), -1 (failure)
 *  NOTE that this API has one cycle delay between data acquisition request
 *  and actual data acquisition. 
 */
S32 ecrobot_get_sonar_sensor(U8 port_id)
{
	static U8 data[4] = {0};

	if (i2c_busy(port_id) == 0)
	{
		distance_state[port_id] = (S32)data[port_id];
	   /* i2c_start_transaction just triggers an I2C transaction,
		* actual data transaction between ARM7 and a Ultrasonic
		* Sensor is done by an ISR after this, so there is one cycle
		* delay for consistent data acquistion
		*/
		i2c_start_transaction(port_id,1,0x42,1,&data[port_id],1,0);
	}

	return distance_state[port_id];
}

/**
 * terminate I2C used for for Ultrasonic Sensor
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_sonar_sensor(U8 port_id)
{
	distance_state[0] = -1;
	distance_state[1] = -1;
	distance_state[2] = -1;
	distance_state[3] = -1;
	i2c_disable(port_id);
}


/*==============================================================================
 * RCX Sensors API
 * 
 * According to LEGO Hardware Developer Kit, RCX sensors are categorized as
 * two types
 *   ACTIVE SENSOR:  RCX Light Sensor, RCX Rotation Sensor
 *   PASSIVE SENSOR: RCX Touch Sensor
 * ACTIVE SENSOR requires additional power source to drive the sensor
 * PASSIVE SENSOR is compatible with NXT A/D sensors
 *
 * Concept of these RCX Sensors API is contributed by Maurits Kooiman(Mansk).
 * see http://forums.nxtasy.org/index.php?showtopic=1540
 *=============================================================================*/

/**
 * supply power source for ACTIVE SENSORS
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_set_RCX_power_source(U8 port_id)
{
	if (deviceStatus == DEVICE_NO_INIT)
	{
		nxt_avr_set_input_power(port_id, LOWSPEED_9V);
	}
}

/**
 * stop power source for ACTIVE SENSORS
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_RCX_power_source(U8 port_id)
{
	nxt_avr_set_input_power(port_id, 0);
}

/**
 * get RCX Sensor raw A/D data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: raw A/D data (0 to 1023)
 */
S16 ecrobot_get_RCX_sensor(U8 port_id)
{
	return (S16)sensor_adc(port_id);
}

/**
 * get RCX Touch Sensor on/off status
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: 1(touched)/0(not touched)
 */
U8 ecrobot_get_RCX_touch_sensor(U8 port_id)
{
	return (sensor_adc(port_id) < 512);
}


/*==============================================================================
 * NXT internal status API
 *=============================================================================*/
#define N_BTN_STATE 20

static nxt_inputs ecrobot_inputs;
static U8 buttons_states[N_BTN_STATE];
static SINT buttons_i;

/**
 * get battery voltage in mille volt
 *
 * @return: battery voltage in mV (e.g. 9000 = 9.000V)
 */
U16 ecrobot_get_battery_voltage(void)
{
	return (U16)ecrobot_inputs.battery_state;
}

/**
 * get System tick in mille second
 *
 * @return: time in msec.
 *  NOTE that system tick is started when the NXT was turned on.
 *  not when application was started.
 */
U32 ecrobot_get_systick_ms(void)
{
	return systick_get_ms();
}

/**
 * get ENTER buttons status 
 *  NOTE that STOP and EXIT buttons are preserved by the system,
 *  so should not be disclosed to application.
 *
 * @return: 1(pressed)/0(not pressed)
 */
U8 ecrobot_is_ENTER_button_pressed(void)
{
	return ((ecrobot_get_button_state() & ENTER_PRESSED) == ENTER_PRESSED);
}

/**
 * get RUN buttons status 
 *  NOTE that STOP and EXIT buttons are preserved by the system,
 *  so should not be disclosed to application.
 *
 * @return: 1(pressed)/0(not pressed)
 */
U8 ecrobot_is_RUN_button_pressed(void)
{
	return ((ecrobot_get_button_state() & RUN_PRESSED) == RUN_PRESSED);
}

void ecrobot_init_nxtstate(void)
{
//	ecrobot_inputs.battery_state = 0;
	ecrobot_inputs.buttons_state = 0;
	memset(buttons_states, 0, sizeof(buttons_states));
	buttons_i = 0;
}

U8 ecrobot_get_button_state(void)
{
	return ecrobot_inputs.buttons_state;
}

void ecrobot_poll_nxtstate(void)
{
	SINT i;

	ecrobot_inputs.battery_state = battery_voltage();

	/* button debouncer */
	buttons_states[buttons_i++] = (U8)buttons_get() & 0x0F;
	if (buttons_i == N_BTN_STATE) buttons_i = 0;
	for (i = 1; i < N_BTN_STATE; i++)
	{
		if (buttons_states[i-1] != buttons_states[i])
		{
	  		return;
		}
		
		if (i == N_BTN_STATE-1)
    	{
	  		ecrobot_inputs.buttons_state = buttons_states[i];
    	}
  	}
}

void ecrobot_setDeviceInitialized(void)
{
	if (deviceStatus == DEVICE_NO_INIT)
	{
		deviceStatus = DEVICE_INITIALIZED;
	}
}

U8 get_device_status()
{
	return deviceStatus;
}

/*==============================================================================
 * NXT Data Logging API for NXT GamePad
 *=============================================================================*/
static S16 adc[4]; /* used for ecrobot_adc_data_monitor */

/**
 * data logging API used with NXT GamePad
 *
 * @param data1: user configurable data to be logged
 * @param data2: user configurable data to be logged
 */
void ecrobot_bt_data_logger(S8 data1, S8 data2)
{
	U8 data_log_buffer[32];

	*((U32 *)(&data_log_buffer[0]))  = (U32)systick_get_ms();
	*(( S8 *)(&data_log_buffer[4]))  =  (S8)data1;
	*(( S8 *)(&data_log_buffer[5]))  =  (S8)data2;
	*((U16 *)(&data_log_buffer[6]))  = (U16)ecrobot_inputs.battery_state;
	*((S32 *)(&data_log_buffer[8]))  = (S32)nxt_motor_get_count(0);
	*((S32 *)(&data_log_buffer[12])) = (S32)nxt_motor_get_count(1);
	*((S32 *)(&data_log_buffer[16])) = (S32)nxt_motor_get_count(2);
	*((S16 *)(&data_log_buffer[20])) = (S16)sensor_adc(0);
	*((S16 *)(&data_log_buffer[22])) = (S16)sensor_adc(1);
	*((S16 *)(&data_log_buffer[24])) = (S16)sensor_adc(2);
	*((S16 *)(&data_log_buffer[26])) = (S16)sensor_adc(3);
	*((S32 *)(&data_log_buffer[28])) = (S32)getDistance();
	
	ecrobot_send_bt_packet(data_log_buffer, 32);
}

/**
 * data logging API used with NXT GamePad
 *
 * @param data1: user configurable data to be logged
 * @param data2: user configurable data to be logged
 * @param adc1:  user configurable data to be logged
 * @param adc2:  user configurable data to be logged
 * @param adc3:  user configurable data to be logged
 * @param adc4:  user configurable data to be logged
 */
void ecrobot_bt_adc_data_logger(S8 data1, S8 data2, S16 adc1, S16 adc2, S16 adc3, S16 adc4)
{
	U8 data_log_buffer[32];

	*((U32 *)(&data_log_buffer[0]))  = (U32)systick_get_ms();
	*(( S8 *)(&data_log_buffer[4]))  =  (S8)data1;
	*(( S8 *)(&data_log_buffer[5]))  =  (S8)data2;
	*((U16 *)(&data_log_buffer[6]))  = (U16)ecrobot_inputs.battery_state;
	*((S32 *)(&data_log_buffer[8]))  = (S32)nxt_motor_get_count(0);
	*((S32 *)(&data_log_buffer[12])) = (S32)nxt_motor_get_count(1);
	*((S32 *)(&data_log_buffer[16])) = (S32)nxt_motor_get_count(2);
	*((S16 *)(&data_log_buffer[20])) = (S16)adc1;
	*((S16 *)(&data_log_buffer[22])) = (S16)adc2;
	*((S16 *)(&data_log_buffer[24])) = (S16)adc3;
	*((S16 *)(&data_log_buffer[26])) = (S16)adc4;
	*((S32 *)(&data_log_buffer[28])) = (S32)getDistance();
	adc[0] = adc1;
	adc[1] = adc2;
	adc[2] = adc3;
	adc[3] = adc4;
	
	ecrobot_send_bt_packet(data_log_buffer, 32);
}


/*==============================================================================
 * NXT LCD display API
 *=============================================================================*/

/**
 * convert a BMP file to an array data for LCD display
 *
 * @param file: monochrome BMP file data
 * @param lcd: data array to be drawn in LCD
 * @param width: pixel width of the BMP file (max. 100)
 * @param height: pixel height of the BMP file (max. 64)
 * @return: 1(success)/-1(failure)
 */
SINT ecrobot_bmp2lcd(const CHAR *file, U8 *lcd, S32 width, S32 height)
{
	SINT bmp_line, bmp_line_alignment;
	SINT bmp_row, bmp_col;
	SINT lcd_row;
	SINT lcd_pos;
	SINT bmp_bit_pos;
	SINT lcd_bit_pos;
	SINT bits;
	U8 bmp_data;
	BMP *bmp = (BMP *)file;
	
	/* check a BMP file header information */
	if (bmp->fileHeader.type != BM_TYPE)  /* Windows */
		return -1;
	if ((bmp->infoHeader.width > NXT_LCD_WIDTH) ||
		(bmp->infoHeader.width < 1) ||
		(bmp->infoHeader.width != width))
		return -1;
	if ((bmp->infoHeader.height > NXT_LCD_DEPTH * 8) ||
		(bmp->infoHeader.height < 1) ||
		(bmp->infoHeader.height != height))
		return -1;
	if (bmp->infoHeader.bits != 1)        /* monochrome bmp */
		return -1;
	if (bmp->infoHeader.compression != 0) /* no compression */
		return -1;
	
	/* 
	 * Specifications of a monochrome bmp file
	 *
	 * - each bit represents a pixel.
	 * - each line has 4 bytes alignment.
	 *   (100 pixels data is saved in 100/8 = 12 + 1 + 3 = 16 byte)
	 * - data order in a BMP file:
     *   (0,n)---------------->(m,n)
     *        ---------------->
     *        ---------------->
     *        ---------------->
     *   (0,0)---------------->(m,0)
	 */
	 
	/* calculate line alignment */
	bmp_line = bmp->infoHeader.width / 8;
	if (bmp->infoHeader.width % 8)
	{
		bmp_line++;
	}
	
	if ((bmp_line % 4) != 0)
	{
		bmp_line_alignment = ((bmp_line / 4) + 1) * 4;
	}
	else
	{
		bmp_line_alignment = bmp_line;
	}
	
	/* convert BMP data to LCD array data */
	for (bmp_row = 0; bmp_row < bmp->infoHeader.height; bmp_row++)
	{
		lcd_row = NXT_LCD_DEPTH - ((bmp_row / 8) + 1);
		lcd_bit_pos = bmp_row % 8;
		bits = 0;
		for(bmp_col = 0; bmp_col < bmp_line; bmp_col++)
		{
			bmp_data = file[(bmp_row * bmp_line_alignment) + bmp_col + bmp->fileHeader.offset];
			lcd_pos = (lcd_row * NXT_LCD_WIDTH) + (bmp_col * 8);
			for (bmp_bit_pos = 0; ((bmp_bit_pos < 8) && (bits < bmp->infoHeader.width)); bmp_bit_pos++, bits++)
			{
				int lcd_index = lcd_pos + bmp_bit_pos;
				/* checks render data can be stored into LCD */
				if (lcd_index < NXT_LCD_WIDTH*NXT_LCD_DEPTH)
				{
					if (!(bmp_data & (0x01 << (7 - bmp_bit_pos))))
					{
						lcd[lcd_index] |= (0x80 >> lcd_bit_pos);
					}
					else
					{
						lcd[lcd_index] &= (~0x80 >> lcd_bit_pos);
					}
				}
			}
		}
	}
	return 1;
}

void ecrobot_show_int(S32 var)
{
	display_clear(0);

	display_goto_xy(0, 7);
	display_string("VAR: ");
	display_int(var, 0);

	display_update();
}

void ecrobot_debug(UINT var)
{
	display_clear(0);

	display_goto_xy(0, 7);
	display_string("DBG: ");
	display_int(var, 0);

	display_update();
}

void ecrobot_debug1(UINT var1, UINT var2, UINT var3)
{
	display_clear(0);

	display_goto_xy(0, 1);
	display_string("VAR1: ");
	display_int(var1, 0);

	display_goto_xy(0, 2);
	display_string("VAR2: ");
	display_int(var2, 0);

	display_goto_xy(0, 3);
	display_string("VAR3: ");
	display_int(var3, 0);

	display_update();
}

void ecrobot_debug2(UINT var1, UINT var2, UINT var3)
{
	display_clear(0);

	display_goto_xy(0, 4);
	display_string("VAR4: ");
	display_int(var1, 0);

	display_goto_xy(0, 5);
	display_string("VAR5: ");
	display_int(var2, 0);

	display_goto_xy(0, 6);
	display_string("VAR6: ");
	display_int(var3, 0);

	display_update();
}

void ecrobot_status_monitor(const CHAR *target_name)
{
    display_clear(0);

	display_goto_xy(0, 0);
    display_string(target_name);

   	display_goto_xy(0, 1);
   	display_string("TIME:");
   	display_unsigned(systick_get_ms()/1000, 0);

   	display_goto_xy(0, 2);
   	display_string("BATT:");
   	display_unsigned(ecrobot_inputs.battery_state/100, 0);
    
   	display_goto_xy(0, 3);
   	display_string("REV: ");
   	display_int(nxt_motor_get_count(0), 0);
   	display_int(nxt_motor_get_count(1), 6);
    
   	display_goto_xy(0, 4);
   	display_string("     ");
   	display_int(nxt_motor_get_count(2), 0);

   	display_goto_xy(0, 5);
   	display_string("ADC: ");
   	display_unsigned(sensor_adc(0), 0);
   	display_unsigned(sensor_adc(1), 5);

   	display_goto_xy(0, 6);
   	display_string("     ");
   	display_unsigned(sensor_adc(2), 0);
   	display_unsigned(sensor_adc(3), 5);

   	display_goto_xy(0, 7);
   	display_string("BT/DST: ");
	if (ecrobot_get_bt_status() == BT_STREAM)
	{
		display_unsigned(1, 0);
   	}
   	else
   	{
		display_unsigned(0, 0);
   	}
   	display_int(getDistance(), 5);

	display_update();
}

/* This function is used to display user selected sensor values */
void ecrobot_adc_data_monitor(const CHAR *target_name)
{
	display_clear(0);

	display_goto_xy(0, 0);
   	display_string(target_name);

   	display_goto_xy(0, 1);
   	display_string("TIME:");
   	display_unsigned(systick_get_ms()/1000, 0);

   	display_goto_xy(0, 2);
   	display_string("BATT:");
   	display_unsigned(ecrobot_inputs.battery_state/100, 0);
    
   	display_goto_xy(0, 3);
   	display_string("REV: ");
   	display_int(nxt_motor_get_count(0), 0);
   	display_int(nxt_motor_get_count(1), 6);

   	display_goto_xy(0, 4);
   	display_string("     ");
   	display_int(nxt_motor_get_count(2), 0);

   	display_goto_xy(0, 5);
   	display_string("ADC1/2:");
   	display_int(adc[0], 0);
   	display_int(adc[1], 5);

   	display_goto_xy(0, 6);
   	display_string("ADC3/4:");
   	display_int(adc[2], 0);
   	display_int(adc[3], 5);

   	display_goto_xy(0, 7);
   	display_string("BT/DST: ");
	if (ecrobot_get_bt_status() == BT_STREAM)
	{
		display_unsigned(1, 0);
   	}
   	else
   	{
		display_unsigned(0, 0);
   	}
   	display_int(getDistance(), 5);

	display_update();
}


/*==============================================================================
 * NXT Sound API
 *=============================================================================*/

/**
 * play a tone(wrapper of leJOS sound tone api)
 *
 * @param freq: soundfrequency in Hz (31 to 2100)
 * @param ms: sound duration in centisecond (10 - 256)
 * @vol: sound volume (0 to 100)
 * @return 1 (always)
 */
SINT ecrobot_sound_tone(U32 freq, U32 ms, U32 vol)
{
	sound_freq_vol(freq, ms, vol);
	return 1;
}

/**
 * play a WAV file (support for only 8bit monoral PCM)
 *
 * @param file: WAV file data
 *  NOTE that supports only 8bit monoral PCM
 * @param length: length of WAV file
 * @param freq: sampling frequency -1(inherit the WAV file original)/2000 to 22050Hz
 * @param vol: sound volume(0 to 100)
 * @return: 1(success)/0(sound resource is busy)/-1(failure)
 */
SINT ecrobot_sound_wav(const CHAR *file, U32 length, S32 freq, U32 vol)
{
	WAV *wav = (WAV *)file;

	/* check sound resource is free */
	if (sound_get_time() > 0)
		return 0;
		
	/* check length of a file */
	if (length < WAV_HDR_SIZE)
		return -1;
	
	/* check a WAV file header information */
	if (wav->riff.chunkID != RIFF_CHUNK_ID)
		return -1;
	if (wav->riff.format != RIFF_FORMAT)
		return -1;
	if (wav->fmt.chunkID != FMT_CHUNK_ID)
		return -1;
	if (wav->fmt.audioFormat != 0x0001) /* PCM */
		return -1;
	if (wav->fmt.numChannels != 0x0001) /* mono channel */
		return -1;
	if (wav->fmt.bitsPerSample != 0x0008) /* 8bit */
		return -1;

	/* in case of freq < 0, freq(sample rate) is inherited from a WAV file */
	if (freq < 0)
	{
		freq = wav->fmt.sampleRate;
	}
	
	/* read wav data. Currently, supported PCM file types are 
	 * linear PCM(data chunkID is "data" and "fact") and non-linear PCM.
	 */
	if (wav->data.chunkID == DATA_CHUNK_ID)
	{
		/* linear PCM */
		sound_play_sample(wav->data.data, wav->data.chunkSize, (U32)freq, vol);
	}
	else
	{
		WAV_FACT *wav_fact = (WAV_FACT *)file;
		if (wav_fact->data.chunkID == FACT_CHUNK_ID && wav_fact->data.data_chunkID == DATA_CHUNK_ID)
		{
 			/* linear PCM with "fact" chunk ID */
			sound_play_sample(wav_fact->data.data, wav_fact->data.data_chunkSize, (U32)freq, vol);
		}
		else
		{
			WAV_NL *wav_nl = (WAV_NL *)file;
			if (wav_nl->data.chunkID == DATA_CHUNK_ID)
			{
 				/* non linear PCM */
				sound_play_sample(wav_nl->data.data, wav_nl->data.chunkSize, (U32)freq, vol);
			}
			else
			{
				return -1;
			}
		}
	}
	return 1;
}


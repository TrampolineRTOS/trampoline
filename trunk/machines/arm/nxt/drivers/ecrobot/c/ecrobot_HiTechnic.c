/*****************************************************************************
 * FILE: ecrobot_HiTechnic.c
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
#include "ecrobot_interface.h"


/*==============================================================================
 * NXT HiTechnic Gyro Sensor API
 *=============================================================================*/

/**
 * get HiTechnic Gyro Sensor raw A/D data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: A/D raw data(0 to 1023)
 */
U16 ecrobot_get_gyro_sensor(U8 port_id)
{
	return (U16)sensor_adc(port_id);
}

/*==============================================================================
 * NXT HiTechnic Acceleration Sensor API
 *=============================================================================*/

/**
 * init a NXT port for I2C device(Acceleration Sensor)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_init_accel_sensor(U8 port_id)
{
	ecrobot_init_i2c(port_id, LOWSPEED);
}

/**
 * get HiTechnic Acceleration Sensor data ([x,y,z] axes acceleration)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param buf: buffer to return the x/y/z axes accel data
 */
void ecrobot_get_accel_sensor(U8 port_id, S16 buf[3])
{
	 SINT i;
	  /* support for multiple accel sensors in a NXT */
	 static S16 accel[4][3];
	 static U8 data[4][6] = {{0}};

	// Data representation from the sensor, per Hi-Technic's documentation:
	//
	// data[0]: X axis upper 8 bits
	// data[1]: Y axis upper 8 bits
	// data[2]: Z axis upper 8 bits
	// data[3]: X axis lower 2 bits
	// data[4]: Y axis lower 2 bits
	// data[5]: Z axis lower 2 bits

	if (i2c_busy(port_id) == 0)
	{
		for (i=0; i<3; i++)
		{
			accel[port_id][i] = (S16)data[port_id][i];
			if (accel[port_id][i] > 127) accel[port_id][i] -= 256;
			/* convert to 10 bit value */
			accel[port_id][i] = (accel[port_id][i] << 2) | ((S16)data[port_id][i+3] & 0x0003);
   		}
	   /* i2c_start_transaction just triggers an I2C transaction,
		* actual data transaction between ARM7 and an Acceleration
		* Sensor is done by an ISR after this, so there is one execution cycle
		* delay for consistent data acquistion
		*/
		i2c_start_transaction(port_id,1,0x42,1,&data[port_id][0],6,0);
	}
	
	for (i=0; i<3; i++)
	{
		buf[i] = accel[port_id][i];
   	}
}

/**
 * terminate a NXT port for I2C device(Acceleration Sensor)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_accel_sensor(U8 port_id)
{
	i2c_disable(port_id);
}

/*==============================================================================
 * NXT HiTechnic IR Seeker API
 *
 * Note that IR Seeker API is developed by 
 * Nathan Bahr Sr. Electrical Engineer, Milwaukee School of Engineering (bahrn@msoe.edu)
 *=============================================================================*/

/**
 * init a NXT port for I2C device(IR Seeker)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_init_ir_seeker(U8 port_id)
{
	ecrobot_init_i2c(port_id, LOWSPEED);
}

/**
 * get HiTechnic IR Seeker data (Direction and Five Intensity Vectors)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param buf: buffer to return the direction and five intesity vector data
 */
void ecrobot_get_ir_seeker(U8 port_id, S8 buf[6])
{
	 SINT i;
	  /* support for multiple IR Seeker in a NXT */
	 static S8 infrared[4][6];
	 static U8 data[4][6] = {{0}};

	// Data representation from the sensor, per Hi-Technic's documentation:
	//
	// data[0]: Direction 8 bits
	// data[1]: Intensity1 8 bits
	// data[2]: Intensity2 8 bits
	// data[3]: Intensity3 8 bits
	// data[4]: Intensity4 8 bits
	// data[5]: Intensity5 8 bits

	if (i2c_busy(port_id) == 0)
	{
		for (i=0; i<6; i++)
		{
			infrared[port_id][i] = (S8)data[port_id][i];
   		}
	   /* i2c_start_transaction just triggers an I2C transaction,
		* actual data transaction between ARM7 and an Infrared
		* Sensor is done by an ISR after this, so there is one execution cycle
		* delay for consistent data acquistion
		*/
		i2c_start_transaction(port_id,1,0x42,1,&data[port_id][0],6,0);
	}
	
	for (i=0; i<6; i++)
	{
		buf[i] = infrared[port_id][i];
   	}
}

/**
 * terminate a NXT port for I2C device(IR Seeker)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_ir_seeker(U8 port_id)
{
	i2c_disable(port_id);
}

/*==============================================================================
 * NXT HiTechnic Color Sensor API
 *=============================================================================*/

/**
 * init a NXT port for I2C device(Color Sensor)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_init_color_sensor(U8 port_id)
{
	ecrobot_init_i2c(port_id, LOWSPEED);
}

/**
 * get HiTechnic Color Sensor data ([r,g,b] raw color data)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @param buf: buffer to return the r/g/b raw color data
 */
void ecrobot_get_color_sensor(U8 port_id, S16 buf[3])
{
	SINT i;
	/* support for multiple color sensors in a NXT */
	static S16 color[4][3];
	static U8 data[4][14] = {{0}};

	// Data representation from the sensor, per Hi-Technic's documentation:
	//
	// data[0]: color number
	// data[1]: red saturation
	// data[2]: green saturation
	// data[3]: blue saturation
	// data[4]: raw red upper 2 bits
	// data[5]: raw red lower 8 bits
	// data[6]: raw green upper 2 bits
	// data[7]: raw green lower 8 bits
	// data[8]: raw blue upper 2 bits
	// data[9]: raw blue lower 8 bits
	// data[10]: color index (2 bits per r/g/b)
	// data[11]: normalized red
	// data[12]: normalized green
	// data[13]: normalized blue

	if (i2c_busy(port_id) == 0)
	{
		/* convert to 10 bit value */
		color[port_id][0] = ((S16)data[port_id][4] << 8) | ((S16)data[port_id][5]);
		color[port_id][1] = ((S16)data[port_id][6] << 8) | ((S16)data[port_id][7]);
		color[port_id][2] = ((S16)data[port_id][8] << 8) | ((S16)data[port_id][9]);

	   /* i2c_start_transaction just triggers an I2C transaction,
		* actual data transaction between ARM7 and a Color
		* Sensor is done by an ISR after this, so there is one execution cycle
		* delay for consistent data acquistion
		*/
		i2c_start_transaction(port_id,1,0x42,1,&data[port_id][0],14,0);
	}
	
	for (i=0; i<3; i++)
	{
		buf[i] = color[port_id][i];
   	}
}

/**
 * terminate a NXT port for I2C device(Color Sensor)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_color_sensor(U8 port_id)
{
	i2c_disable(port_id);
}

/*==============================================================================
 * NXT HiTechnic Compass Sensor API
 *=============================================================================*/

/**
 * init a NXT port for I2C device(Compass Sensor)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_init_compass_sensor(U8 port_id)
{
	ecrobot_init_i2c(port_id, LOWSPEED);
}

/**
 * calibrate a Compass Sensor
 * Note that this implementation is not smart as C++ version and
 * it has some waits in the function.
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: 1(succeeded)/0(failed)
 */
U8 ecrobot_cal_compass_sensor(U8 port_id)
{
	U8 cmd;

	if (ecrobot_wait_i2c_ready(port_id, 50) == 0) return 0;

	cmd = 0x43; /* start calibration command */
	i2c_start_transaction(port_id,1,0x41,1,&cmd,1,1);
	if (ecrobot_wait_i2c_ready(port_id, 50) == 0) return 0;

	cmd = 0x00; /* end calibration command */
	i2c_start_transaction(port_id,1,0x41,1,&cmd,1,1);
	if (ecrobot_wait_i2c_ready(port_id, 50) == 0) return 0;

	// now read back the byte, if it's 0 then calibration succeeded,
	// otherwise it'll be a 2 and it failed.
	i2c_start_transaction(port_id,1,0x41,1,&cmd,1,0);
	if (ecrobot_wait_i2c_ready(port_id, 50) == 0) return 0;

	return !cmd;
}

/**
 * get HiTechnic Compass Sensor data
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 * @return: heading data
 */
S16 ecrobot_get_compass_sensor(U8 port_id)
{
	/* support for multiple compass sensors in a NXT */
	static S16 heading[4];
	static U8 data[4][5] = {{0}};

	// Data representation from the sensor, per Hi-Technic's documentation:
	//
	// data[0]: mode control
	// data[1]: heading upper 8 bits
	// data[2]: heading lower 1 bit
	// data[3]: heading lower 8 bits
	// data[4]: heading upper 1 bit

	if (i2c_busy(port_id) == 0)
	{
		heading[port_id] = (S16)data[port_id][3] | ((S16)data[port_id][4] << 8);
	   /* i2c_start_transaction just triggers an I2C transaction,
		* actual data transaction between ARM7 and an Acceleration
		* Sensor is done by an ISR after this, so there is one execution cycle
		* delay for consistent data acquistion
		*/
		i2c_start_transaction(port_id,1,0x41,1,&data[port_id][0],5,0);
	}

	return heading[port_id];
}

/**
 * terminate a NXT port for I2C device(Compass Sensor)
 *
 * @param port_id: NXT_PORT_S1/NXT_PORT_S2/NXT_PORT_S3/NXT_PORT_S4
 */
void ecrobot_term_compass_sensor(U8 port_id)
{
	i2c_disable(port_id);
}


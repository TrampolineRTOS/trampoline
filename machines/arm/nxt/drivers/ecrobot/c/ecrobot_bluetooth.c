/*****************************************************************************
 * FILE: ecrobot_bluetooth.c
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

static volatile U8 bt_status = BT_NO_INIT;
static volatile U8 handle;
static U8 sendBuf[BT_BUF_SIZE];
static U8 receiveBuf[BT_BUF_SIZE];
extern U8 in_buf[2][128];

/*
 * nxtOSEK Bluetooth API supports only minimum part of LEGO Communication Protocol(LCP).
 * Therefore, it is not possible to communicate nxtOSEK application and a LCP tool on PC
 * or NXT standard firmware. However, communication throughput is much higher than LCP.
 * We have proviced an original Bluetooth PC utility which is called NXT GamePad.
 * You can use NXT GamePad for R/C control using a PC GamePad and also data logging.
 */
 
/**
 * send Bluetooth command
 *
 * @param cmd: Bluetooth command
 * @param buflen: length of the command to send
 */
static void send_bt_command(U8 *cmd, U32 bufLen)
{
	S32 checkSum = 0;
	S32 i;

	sendBuf[0] = (U8) (bufLen + 2);

	for(i = 0; i < bufLen; i++)
	{
		sendBuf[i+1] = cmd[i];
		checkSum += cmd[i];
	}

    checkSum = -checkSum;
    sendBuf[bufLen+2] = (U8)((checkSum >> 8) & 0xff);
    sendBuf[bufLen+3] = (U8)(checkSum & 0xff);

	bt_send(sendBuf, bufLen+3);
}

/**
 * read Bluetooth command
 *
 * @param cmd: Bluetooth command
 * @param buflen: length of the command buffer
 * @return length of the return command
 */
static U32 read_bt_command(U8 *cmd, U32 bufLen)
{
	S32 checkSum, negSum, i;
	U32 len;

	memset(&receiveBuf[0],0,sizeof(receiveBuf));
	bt_receive(&receiveBuf[0]);
	len = receiveBuf[0];
	cmd[0] = (U8) len;

	if (len == 0)
		return 0;

	checkSum = len;

	if (len-1 <= bufLen)
	{
		for(i = 1; i < len-1; i++) 
		{
			cmd[i] = receiveBuf[i];
			checkSum += (cmd[i] & 0xff);
		}
		negSum = (receiveBuf[len-1] & 0xff) << 8;
		negSum += (receiveBuf[len] & 0xff);
		if (checkSum + negSum == 65536)
		{
			 return len-1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

/**
 * get Bluetooth local device address
 *
 * @param bd_addr: buffer for getting Bluetooth Device Address
 *                 (7bytes hex array data)
 * @return: 1(succeeded)/0(failed)
 */
static U8 getLocalAddress(U8* bd_addr)
{
	SINT timeout;
	U8 msg[1];
	U8 reply[32];
	
	msg[0] = MSG_GET_LOCAL_ADDR;
	send_bt_command(msg,1);

	timeout = systick_get_ms() + 3000; /* wait for 3 sec */
	while(systick_get_ms() < timeout)
	{
		read_bt_command(reply,32);

		if (reply[0] != 0 && reply[1] == MSG_GET_LOCAL_ADDR_RESULT)
		{
			for(SINT i=0;i<7;i++)
			{
				bd_addr[i] = reply[i+2];
			}
			return 1;
		}
	}
	return 0;
}

/**
 * wrapper function for ECRobot++ API
 */
U8 ecrobot_get_bt_device_address(U8* bd_addr)
{
	return getLocalAddress(bd_addr);
}

/**
 * get Bluetooth device name
 *
 * @param bd_name: buffer for getting Bluetooth Device Name (max. 16 characters string)
 * @return: 1(succeeded)/0(failed)
 */
U8 ecrobot_get_bt_device_name(CHAR* bd_name)
{
	SINT timeout;
	U8 msg[1];
	U8 reply[32];
	SINT i;
	
	msg[0] = MSG_GET_FRIENDLY_NAME;
	send_bt_command(msg,1);

	timeout = systick_get_ms() + 3000; /* wait for 3 sec */
	while(systick_get_ms() < timeout)
	{
		read_bt_command(reply,32);

		if (reply[0] != 0 && reply[1] == MSG_GET_FRIENDLY_NAME_RESULT)
		{
			for(i=0;i<16;i++)
			{
				bd_name[i] = (CHAR)reply[i+2];
				if (bd_name[i] == '\0') return 1; /* shorter than 16 characters because null terminated */
			}
			
			if (i == 16)
			{
				/* Add null terminator to easy to handle the name as a string */
				reply[16] = '\0';
			}
			return 1;
		}
	}
	return 0;
}

/**
 * set Bluetooth device name
 *
 * @param bd_name: buffer for setting Bluetooth Device Name (max. 16 characters string)
 * @return: 1(succeeded)/0(failed)
 */
U8 ecrobot_set_bt_device_name(const CHAR* bd_name)
{
	U8 msg[17];

	/* Bluetooth should not be connected */
	if (bt_status != BT_CONNECTED && bt_status != BT_STREAM)
	{
		msg[0] = MSG_SET_FRIENDLY_NAME;
		strncpy((CHAR*)&msg[1], bd_name, 16); /* fill null the rest of 16 byts spaces */
		send_bt_command(msg, 17);
		systick_wait_ms(100);
		return 1;
	}
	return 0;
}

/**
 * set Bluetooth factory setting
 *
 * @param -
 * @return: 1(succeeded)/0(failed)
 */
U8 ecrobot_set_bt_factory_settings(void)
{
	U8 msg[1];

	/* Bluetooth should not be connected */
	if (bt_status != BT_CONNECTED && bt_status != BT_STREAM)
	{
		msg[0] = MSG_SET_FACTORY_SETTINGS;
		send_bt_command(msg, 1);
		systick_wait_ms(100);
		return 1;
	}
	return 0;
}

/**
 * open a Bluetooth stream with the paired device
 */
static void ecrobot_open_bt_stream(void)
{
	U8 msg[2];

	if (bt_status == BT_CONNECTED)
	{
		msg[0] = MSG_OPEN_STREAM;
		msg[1] = handle;
		send_bt_command(msg, 2);
		systick_wait_ms(100);
		
		bt_set_arm7_cmd(); /* set stream mode */
		bt_status = BT_STREAM;
    
    /* after NXT initialized, ready for caracter (first length) */
    *AT91C_US1_RPR  = (unsigned int)&(in_buf[0][0]);
    *AT91C_US1_RCR = 2;    
    
	}
}

/**
 * close a Bluetooth opened stream
 */
//static void ecrobot_close_bt_stream(void)
//{
//	if (bt_status == BT_STREAM)
//	{
//		bt_clear_arm7_cmd(); /* set command mode */
//		systick_wait_ms(100);
//		bt_status == BT_CONNECTED;
//	}
//}

/**
 * connect the master device to a slave device
 * NOTE that this API is assumed to be invoked in a loop to establish a connection
 *
 * @param bd_addr: Slave device's Bluetooth Device Address (7bytes hex array data)
 * @param pin: pin code (8 to 16 characters)
 * @return: Bluetooth device status (BT_NO_INIT/BT_INITIALIZED/BT_CONNECTED/BT_STREAM)
 */
static SINT ecrobot_connect_bt_master(const U8 *bd_addr, const CHAR *pin)
{
	SINT i;
	U8    msg[32];
	U8  reply[32];
	U8  dummy[32];
	U8  device[7];

	if (bt_status == BT_NO_INIT)
	{
		bt_reset(); /* reset BC4 chip */
		bt_status = BT_INITIALIZED;
		
		msg[0] = MSG_CONNECT;
		for (SINT i = 0; i < 7; i++)
		{
			msg[i + 1] = bd_addr[i];
		}
		send_bt_command(msg, 8);
		systick_wait_ms(100);
	}
	else if (bt_status == BT_INITIALIZED)
	{
		/* search for the slave device
	 	 * (based on LEJOS Bluetooth.connection)
   	 	 */
		read_bt_command(reply,32);
		
		if (reply[0] != 0)
		{
			if (reply[1] == MSG_REQUEST_PIN_CODE)
			{
				/* get bd_addr from slave */
				for(i = 0; i < 7; i++)
				{
					device[i] = reply[i+2];
				}

				memset(msg,0,sizeof(msg));
				msg[0] = MSG_PIN_CODE;
				/* fill in slave bd_addr */
				for(i = 0; i < 7; i++)
				{
					msg[i+1] = device[i];
				}
				/* fill in pin code */
				for(i = 0; i<16 && pin[i] != '\0'; i++)
				{
					msg[i+8] = (U8)pin[i];
				}
				send_bt_command(msg, 24);
			}
			else if (reply[1] == MSG_CONNECT_RESULT)
			{
				systick_wait_ms(300);
				read_bt_command(dummy,32);

				if (dummy[0] == 0)
				{
					handle = reply[3];
					bt_status = BT_CONNECTED;
					add_status_info(BT_CONNECTED);
				}
			}
		}
	}
	return bt_status;
}

/**
 * connect the slave device to a master device
 * NOTE that this API is assumed to be invoked in a loop to establish a connection
 *
 * @param pin: pin code (8 to 16 characters)
 * @return: Bluetooth device status (BT_NO_INIT/BT_INITIALIZED/BT_CONNECTED/BT_STREAM)
 */
static SINT ecrobot_connect_bt_slave(const CHAR *pin)
{
	SINT i;
	U8    msg[32];
	U8  reply[32];
	U8  dummy[32];
	U8  bd_addr[7];

	if (bt_status == BT_NO_INIT)
	{
		bt_reset(); /* reset BC4 chip */
		bt_status = BT_INITIALIZED;

		if (getLocalAddress(bd_addr))
		{
			show_bd_addr(bd_addr);
		}
		else
		{
			show_bd_addr_err();
		}
	}
	else if (bt_status == BT_INITIALIZED)
	{
		/* wait for a master device
		 * (based on LEJOS Bluetooth.waitForConnection)
    	 */
		read_bt_command(reply, 32);

		if (reply[0] != 0)
		{
			if (reply[1] == MSG_REQUEST_PIN_CODE)
			{
				for(i = 0; i < 7; i++)
				{
					bd_addr[i] = reply[i+2];
				}

				memset(msg,0,sizeof(msg));
				msg[0] = MSG_PIN_CODE;
				/* fill in slave bd_addr */
				for(i = 0; i < 7; i++)
				{
					msg[i+1] = bd_addr[i];
				}
				/* fill in pin code */
				for(i = 0; i<16 && pin[i] != '\0'; i++)
				{
					msg[i+8] = (U8)pin[i];
				}
				send_bt_command(msg, 24);
			}
			else if (reply[1] == MSG_REQUEST_CONNECTION)
			{
				for(i = 0; i < 7; i++)
				{
					bd_addr[i] = reply[i+2];
				}
				msg[0] = MSG_ACCEPT_CONNECTION;
				msg[1] = 1;
				send_bt_command(msg, 2);
			}
			else if (reply[1] == MSG_CONNECT_RESULT)
			{
				systick_wait_ms(300);
				read_bt_command(dummy,32);

				if (dummy[0] == 0)
				{
					handle = reply[3];
					bt_status = BT_CONNECTED;
					add_status_info(BT_CONNECTED);
				} 
			}
		}
	}
	return bt_status;
}

/**
 * return Bluetooth status
 *
 * @return: Bluetooth device status (BT_NO_INIT/BT_INITIALIZED/BT_CONNECTED/BT_STREAM)
 */
SINT ecrobot_get_bt_status(void)
{
	return bt_status;
}

/**
 * initialize NXT as a Bluetooth master device
 * NOTE that this API is assumed to be invoked in a loop to establish a connection
 *
 * @param bd_addr: Slave device's Bluetooth Device Address (7bytes hex array data)
 * @param pin: pin code (8 to 16 characters)
 */
void ecrobot_init_bt_master(const U8 *bd_addr, const CHAR *pin)
{
	ecrobot_connect_bt_master(bd_addr, pin);
	ecrobot_open_bt_stream();
}

/**
 * initialize NXT as a Bluetooth slave device
 * NOTE that this API is assumed to be invoked in a loop to establish a connection
 *
 * @param pin: pin code (8 to 16 characters)
 */
void ecrobot_init_bt_slave(const CHAR *pin)
{
	ecrobot_connect_bt_slave(pin);
	ecrobot_open_bt_stream();
}

/**
 * this API is kept for backward compatibility (not recommend to use)
 */
void ecrobot_init_bt_connection(void)
{
	ecrobot_init_bt_slave("MATLAB");
}

/**
 * terminate Bluetooth connection (used for master and slave)
 */
void ecrobot_term_bt_connection(void)
{
	U8 msg[2];

	if (bt_status > BT_CONNECTED)
	{
		bt_clear_arm7_cmd(); /* set Bluetooth command mode */
		systick_wait_ms(100);

		msg[0] = MSG_CLOSE_CONNECTION;
		msg[1] = handle;
		send_bt_command(msg, 2);
		systick_wait_ms(100);
	}
	bt_status = BT_NO_INIT;
}

/**
 * send Bluetooth data packet
 *
 * @param buf: data buffer to send
 * @param bufLen: length of data to send
 * @return: length of data to be able to send
 */
U32 ecrobot_send_bt_packet(U8 *buf, U32 bufLen)
{
#ifndef XCP_ON_BLUETOOTH
	SINT i;

	if (bt_status == BT_STREAM && bufLen <= BT_BUF_SIZE)
    {
		sendBuf[0] = (U8) (bufLen & 0xFF);
		sendBuf[1] = (U8) ((bufLen >> 8) & 0xFF);
		for(i = 0; i < bufLen; i++)
		{
			sendBuf[i+2] = buf[i];
		}
		if (bt_pending() & 2)
		{
			return 0;
		}
		bt_write(&sendBuf[0], 0, bufLen+2);
		return bufLen;
    }
#endif
    return 0;
}

/**
 * read Bluetooth data packet
 *
 * @param buf: data buffer to send
 * @param bufLen: length of return data buffer
 * @return: length of return data
 */
U32 ecrobot_read_bt_packet(U8 *buf, U32 bufLen)
{
#ifndef XCP_ON_BLUETOOTH
	SINT i;
	U32 len;

	if (bt_status == BT_STREAM && bufLen <= BT_BUF_SIZE)
	{
		bt_receive(&receiveBuf[0]);
		len = receiveBuf[0];
		
		if (len > 0 && len <= bufLen+2)
		{
			for(i = 0; i < len; i++)
			{
				buf[i] = receiveBuf[i+2];
			}
			return len; // not len-2
			// len has actual data length of the packet data, so not len-2. 
			// Thanks EunJin Jeong for fixing the bug.
			// April 9th, 2009 by takashic
		}
		return 0;
	}
#endif
	return 0;
}


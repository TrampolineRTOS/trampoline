/*****************************************************************************
 * FILE: ecrobot_usb.c
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

#include "ecrobot_usb.h"

/*==============================================================================
 * NXT USB API for LEGO fantom driver
 *=============================================================================*/
#define SERIAL_NO 				"123456780090"
#define NAME 					"nxt" /* default device name */

#define RESET 					0x40000000
#define USB_STREAM 				1
#define USB_STATE_MASK 			0xf0000000
#define USB_STATE_CONNECTED 	0x10000000
#define USB_CONFIG_MASK 		0xf000000
#define USB_WRITABLE 			0x100000
#define USB_READABLE 			0x200000
#define SYSTEM_COMMAND_REPLY 	0x01
#define REPLY_COMMAND 			0x02
#define GET_FIRMWARE_VERSION 	0x88
#define GET_DEVICE_INFO 		0x9B

#define USB_ECROBOT_MODE 		0xFF

static U8 dev_name[MAX_DEV_NAME_LEN] = NAME;
/* unique signature to connect with only NXTCommFantom API */
static const U8 ecrobot_sig[] = {'E', 'C', 'R', 'O', 'B', 'O', 'T'};

static volatile SINT read_data_len;
static volatile U8 usb_status = USB_NO_INIT;
static U8 usb_buf[MAX_USB_DATA_LEN];

/**
 * initialize USB
 */
void ecrobot_init_usb(void)
{
	if (usb_status == USB_NO_INIT)
	{
		udp_init();
		udp_disable();
		/*
	 	 * Note that udp_set_name and udp_set_serialno eliminate
	 	 * "\0", so sizeof must be used (do not use strlen)
	 	 */
		udp_set_name((U8 *)NAME, sizeof(NAME));
		udp_set_serialno((U8 *)SERIAL_NO, sizeof(SERIAL_NO));
		udp_enable(0); /* no reset */
		memset(usb_buf,0,sizeof(usb_buf)); /* flush buffer */
		usb_status = USB_INIT;
	}
}

/**
 * set USB device name
 * This name can be used to identify the NXT to be connected
 * under multiple NXTs connection to host.
 * By default, NAME is set as device name in ecrobot_init_usb,
 * so ecrobot_set_name_usb should be called after the init and
 * ecrobot_disconnect_usb calls the init inside of the disconnect
 * function, it needs to call ecrobot_set_name_usb to set desired
 * device name.
 *
 * @param name: device name (max. character length is 16)
 * @return: 1(success)/0(failure)
 */
SINT ecrobot_set_name_usb(U8* name)
{
	if(usb_status == USB_INIT && strcmp((const char *)dev_name, (char *)name))
	{
		if (sizeof(name) > MAX_DEV_NAME_LEN) return 0;
		
		strcpy((char *)dev_name, (char *)name);
		udp_set_name((U8 *)dev_name, sizeof(name));
		return 1;
	}
	return 0;
}

/**
 * USB process handler to establish a connection with PC.
 * This function must be invoked every 1msec
 * (i.e. in a loop with 1msec wait, OSEK/JSP 1msec peiodical Task)
 *
 * @return: usb_status(USB_NO_INIT/USB_INIT/USB_CONNECTED)
 */ 
U8 ecrobot_process1ms_usb(void)
{
	SINT len;
	SINT conn; /* connection status (not USB status) */
	SINT i;
	
	if (usb_status == USB_INIT)
	{
		conn = udp_status();
		if ((conn & USB_STATE_MASK) == USB_STATE_CONNECTED && (conn & USB_CONFIG_MASK) != 0)
		{
			if ((udp_read(usb_buf, 0, MAX_USB_DATA_LEN) == 2) && usb_buf[0] == SYSTEM_COMMAND_REPLY)
			{
				len = 3;
				usb_buf[2] = (U8)0xff;
				if (usb_buf[1] == GET_FIRMWARE_VERSION)
				{
					usb_buf[2] = 0;
					usb_buf[3] = 2;
					usb_buf[4] = 1;
					usb_buf[5] = 3;
					usb_buf[6] = 1;
					len = 7;
				}
				else if (usb_buf[1] == GET_DEVICE_INFO)
				{
					memset(usb_buf,0,sizeof(usb_buf)); /* flush buffer */
					usb_buf[1] = GET_DEVICE_INFO;
					strcpy((char *)&usb_buf[3], (char *)dev_name); /* only send back the device name */
					len = 33;
				}
				else if (usb_buf[1] == USB_ECROBOT_MODE)
				{
					/* Send back special signature to indicate we have accepted ECRobot mode */
					for (i = 0; i < sizeof(ecrobot_sig); i++)
					{
						usb_buf[i+1] = ecrobot_sig[i];
					}
					len = sizeof(ecrobot_sig) + 1;
					read_data_len = 0;
					usb_status = USB_CONNECTED; /* a connection is established */
				}
				usb_buf[0] = REPLY_COMMAND;
				udp_write(usb_buf, 0, len);
			}
		}
	}
	else if (usb_status == USB_CONNECTED)
	{
		/* keep un-read data until ecrobot_read_usb is called */
		if (read_data_len == 0)
		{
			read_data_len = udp_read(usb_buf, 0, MAX_USB_DATA_LEN);
		}
	}
	return usb_status;
}

/**
 * returns connection status of USB
 *
 * @return: 1(connected)/0(not connected)
 */
U8 ecrobot_is_usb_connected(void)
{
	if (usb_status == USB_CONNECTED)
	{
		return 1;
	}
	return 0;
}

/**
 * disconnect a USB connection
 *
 * @return: 1(success)/0(failure)
 */
SINT ecrobot_disconnect_usb(void)
{
	if (usb_status == USB_CONNECTED)
	{
		ecrobot_term_usb();
		ecrobot_init_usb(); /* default device name is set */
		return 1;
	}
	return 0;
}

/**
 * read USB data from host
 *
 * @param buf: buffer for read data
 * @param off: buffer offset
 * @param len: length of data to be read
 * @return: length of read data
 */
SINT ecrobot_read_usb(U8* buf, U32 off, U32 len)
{
	if (usb_status != USB_CONNECTED) return 0;
	if (len > MAX_USB_DATA_LEN) len = MAX_USB_DATA_LEN;
	
	if (read_data_len > 0)
	{
		if (read_data_len > len) read_data_len = len;
		memcpy(&buf[off], usb_buf, read_data_len);
		len = read_data_len;
		read_data_len = 0; /* data is read by application */
	}
	else
	{
		len = 0;
	}
	return len;
}

/**
 * send USB data to host
 *
 * @param buf: buffer for data to be sent
 * @param off: buffer offset
 * @param len: length of the data to be sent
 * @return: length of sent data
 */
SINT ecrobot_send_usb(U8* buf, U32 off, U32 len)
{
	if (usb_status != USB_CONNECTED) return 0;
	if (len > MAX_USB_DATA_LEN) return 0;

	return udp_write(buf, off, len);
}

/**
 * close a USB connection.
 */
void ecrobot_term_usb(void)
{
	udp_disable();
	usb_status = USB_NO_INIT;
}


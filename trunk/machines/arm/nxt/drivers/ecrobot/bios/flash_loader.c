/*****************************************************************************
 * FILE: flash_loader.c
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

#include <string.h>

/* leJOS NXJ I/O driver */
#include "mytypes.h"
#include "interrupts.h"
#include "aic.h"
#include "AT91SAM7.h"
#include "uart.h"
#include "systick.h"
#include "nxt_avr.h"
#include "twi.h"
#include "platform_hooks.h"
#include "nxt_avr.h"
#include "nxt_lcd.h"
#include "nxt_motors.h"
#include "sensors.h"
#include "display.h"
#include "i2c.h"
#include "bt.h"
#include "sound.h"
#include "udp.h"

#include "flash_loader.h"
#include "bios_display.h"
#include "bios.h"

#include "ecrobot_usb.h"

/*
 * verify flash pages
 *
 * return:
 *	1: data is flashed correctly
 *	0: data mismatch occurred
 */
static int verify_flash_page(int start_page, U8 *data, int page_num)
{
	int i;
	volatile U8 *page_addr;

	page_addr = (volatile U8 *)(FLASH_START_ADDR + 
		(start_page + page_num) * FLASH_PAGE_SIZE);

	for (i = 0; i < FLASH_PAGE_SIZE; i++)
	{
		if (data[i] != page_addr[i])
		{
			return 0;
		}
	}
	return 1;
}

/*
 * set BIOS version to record
 *
 * return:
 *  1: succeed to set BIOS version
 *  0: failed to set BIOS version
 */
static int set_bios_version(void)
{
	U8 data[FLASH_PAGE_SIZE];

	memset(data, 0, FLASH_PAGE_SIZE);
	strcpy((char *)data, VERSION);
	flash_write_page(FLASH_RECORD_START_PAGE, (U32 *)data, 0);
	return (verify_flash_page(FLASH_RECORD_START_PAGE, data, 0));
}

/*
 * check BIOS version record to judge the new version is
 * same as remaining version record.
 *
 * return:
 *	1: version is same
 *	0: version is different
 */
int is_bios_version_equal(void)
{
	char *version;

	version = (char *)(FLASH_START_ADDR + FLASH_RECORD_START_PAGE * FLASH_PAGE_SIZE);
	return ((int)!strcmp((const char *)version, VERSION));
}

/*
 * check whether a flash request was set or not.
 *
 * return:
 *  1: flash is requested
 *  0: flash is not requested
 */
int has_flash_request(void)
{
	char *request;

	request = (char *)(FLASH_START_ADDR + FLASH_REQUEST_START_PAGE * FLASH_PAGE_SIZE);
	return ((int)!strcmp((const char *)request, FLASH_REQUEST));
}

/*
 * set a flash request to record
 *
 * return:
 *  1: succeeded to set a flash request
 *  0: failed to set a flash request
 */
int set_flash_request(void)
{
	U8 data[FLASH_PAGE_SIZE];

	memset(data, 0, FLASH_PAGE_SIZE);
	strcpy((char *)data, FLASH_REQUEST);
	flash_write_page(FLASH_REQUEST_START_PAGE, (U32 *)data, 0);
	return (verify_flash_page(FLASH_REQUEST_START_PAGE, data, 0));
}

/*
 * zero clear a flash request in record
 *
 * return:
 *  1: succeeded to clear a flash request
 *  0: failed to clear a flash request
 */
int clear_flash_request(void)
{
	U8 data[FLASH_PAGE_SIZE];

	memset(data, 0, FLASH_PAGE_SIZE);
	flash_write_page(FLASH_REQUEST_START_PAGE, (U32 *)data, 0);
	return (verify_flash_page(FLASH_REQUEST_START_PAGE, data, 0));
}

/*
 * flash loader to upload an application
 */
void flash_loader(void)
{
	#define EXIT_BUTTON 0x08

	U8 data[FLASH_PAGE_SIZE];
	int len;
	int i;
	int current_data;
	int data_end;
	int page;

	ecrobot_init_usb();
	ecrobot_set_name_usb((U8 *)VERSION); /* this will be checked in appflash */

	i = 0;
	page = 0;
	current_data = 0;
	data_end = -1;
	while(1)
	{
		ecrobot_process1ms_usb();
		systick_wait_ms(1);

		len = ecrobot_read_usb(&data[i], 0, DATA_LENGTH);
		if (len == 2 && data_end == -1)
		{
			/* initialize flash loader */
			i = 0;
			page = 0;
			current_data = 0;
			data_end = *((unsigned short *)&data[i]);
			memset(data, 0, FLASH_PAGE_SIZE);
			display_bios_status(0, data_end*DATA_LENGTH);
		}
		else if (len == DATA_LENGTH && data_end != -1)
		{
			/* echo back to PC to check data corruption */
			ecrobot_send_usb(&data[i], 0, DATA_LENGTH);
			i += DATA_LENGTH;
			current_data++;
			display_bios_status(current_data, data_end);

			/* flash one page */
			if (i >= FLASH_PAGE_SIZE)
			{
				flash_write_page(FLASH_START_PAGE, (U32 *)data, page);
				if (!verify_flash_page(FLASH_START_PAGE, data, page))
				{
					display_bios_status(UPLOAD_FAILED, 0);
					i = 0;
					data_end = -1;
					continue;
				}
				memset(data, 0, FLASH_PAGE_SIZE);
				i = 0;
				page++;
			}

			/* final procedure for flash */
			if (current_data == data_end)
			{
				if (data_end % (FLASH_PAGE_SIZE/DATA_LENGTH))
				{
					/* requires an additional page to flash the last data */
					flash_write_page(FLASH_START_PAGE, (U32 *)data, page);
					if (!verify_flash_page(FLASH_START_PAGE, data, page))
					{
						display_bios_status(UPLOAD_FAILED, 0);
						i = 0;
						data_end = -1;
						continue;
					}
				}
				
				if (!set_bios_version())
				{
					display_bios_status(UPLOAD_FAILED, 0);
				}
				else
				{
					/* flash was succeeded */
					display_bios_status(UPLOAD_FINISHED, 0);
				}
				i = 0;
				data_end = -1;
			}
		}
		else
		{
			display_bios_status(UPLOAD_IDLE, 0);
		}

		if (buttons_get() == EXIT_BUTTON && data_end == -1)
		{
			/* shut down the NXT */
			ecrobot_term_usb();
			display_clear(1);
			systick_wait_ms(10);
			nxt_lcd_power_down(); /* reset LCD hardware */
			systick_wait_ms(20);
			while(1)
			{
				nxt_avr_power_down();
			}
		}
	}
}

void nxt_device_init(void)
{
	aic_initialise();
  interrupts_enable();
  nxt_avr_init();
	systick_init();
  i2c_init();
	nxt_motor_init();
	//sound_init();
	bt_init();
	systick_wait_ms(1000); /* wait for LCD to stabilize */
	display_init(); //need systick_wait_ms()
	init_sensors();
    
    
}



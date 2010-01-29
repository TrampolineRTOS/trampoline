/*****************************************************************************
 * FILE: ecrobot_base.c
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

#include "ecrobot_base.h"
#include "ecrobot_private.h"
#include "ecrobot_interface.h"

#ifdef NXT_JSP
extern void lejos_osek_stop(void);
#endif

/* C++ constructor/destructor table */
extern void (*__ctor_begin[])(void);
extern void (*__ctor_end)(void);
extern void (*__dtor_begin[])(void);
extern void (*__dtor_end)(void);

/* declarations for splash screen BMP file */
#ifdef NXT_JSP
EXTERNAL_BMP_DATA(nxtjsp_splash);
#else
EXTERNAL_BMP_DATA(nxtosek_splash);
#endif

/* used for getting the address of a constant data */
const UINT exec_addr[1] = {0};

static CHAR status_bar[MAX_STATUS_BAR_LENGTH];
static SINT status_bar_position = 0;

/* flag to notify RTOS is started */
static volatile SINT OS_flag;

void init_OS_flag(void)
{
	OS_flag = 0;
}

void set_OS_flag(void)
{
	OS_flag = 1;
}

SINT get_OS_flag(void)
{
	return OS_flag;
}

/*
 * execute C++ constructors
 */
void cpp_constructor(void)
{
    SINT i;

    /* call all global object constructors */
    for (i=0;__ctor_begin[i] != __ctor_end;i++)
      (*__ctor_begin[i])();
}

/*
 * execute C++ destructors
 */
void cpp_destructor(void)
{
    SINT i;

    /* call all global object destructors */
    for (i=0;__dtor_begin[i] != __dtor_end;i++)
      (*__dtor_begin[i])();
}

/*
 * return where the program is executed
 */
SINT execution_mode(void)
{
	if (exec_addr < (volatile UINT *)0x200000)
	{
		return EXECUTED_FROM_FLASH;
	}
	return EXECUTED_FROM_SRAM;
}

/*
 * display application splash screen which is designed in
 * ecrobot_splash.bmp file
 */
/*
void show_splash_screen(void)
{
	S32 row, column;
	S32 index;
	static U8 lcd[NXT_LCD_DEPTH*NXT_LCD_WIDTH];
	
	// convert bmp file data to an array data for LCD
#ifdef NXT_JSP
	ecrobot_bmp2lcd(BMP_DATA_START(nxtjsp_splash), lcd, 100, 64);
#else
	ecrobot_bmp2lcd(BMP_DATA_START(nxtosek_splash), lcd, 100, 64);
#endif
	
	for (column = 0; column < NXT_LCD_WIDTH; column++)
	{
		for (row = 0; row < NXT_LCD_DEPTH; row++)
		{
			index = row * NXT_LCD_WIDTH + column;
			lcd[index] = ~lcd[index];
		}
		display_clear(0);
		display_bitmap_copy(lcd, 100, 8, 0, 0);
		display_update();
		systick_wait_ms(800/100);
	}
	
	if (execution_mode() == EXECUTED_FROM_SRAM)
	{
		// flip back to the original data for re-start 
		for (column = 0; column < NXT_LCD_WIDTH; column++)
		{
			for (row = 0; row < NXT_LCD_DEPTH; row++)
			{
				index = row * NXT_LCD_WIDTH + column;
				lcd[index] = ~lcd[index];
			}
		}
	}
	systick_wait_ms(200);
}
*/

/*
 * display application main screen
 */
/*void show_main_screen(void)
{
	display_clear(0);
	display_goto_xy(0, 5);
	display_string("================");
	display_goto_xy(0, 6);
	display_string("<STP  ENTR  RUN>");
	display_goto_xy(0, 7);
	display_string("      EXIT      ");
	display_update();
}
*/
/*
 * display status bar in the main screen
 * 
 * clear: 1(clear status bar), 0(not clear status bar)
 */
/*void display_status_bar(SINT clear)
{
	if (clear)
	{
		memset(status_bar, ' ', MAX_STATUS_BAR_LENGTH);
		status_bar_position = 0;
	}

	display_goto_xy(0, 3);
   	display_string("BATT:");
   	display_unsigned(ecrobot_get_battery_voltage()/100, 0);
	display_goto_xy(0, 4);
	display_string(status_bar);
	display_update();
}
*/
void show_bd_addr(U8 *bd_addr)
{
	SINT i;

	if (!get_OS_flag())
	{
		display_goto_xy(0, 0);
		display_string("BD_ADDR:");
		display_goto_xy(0, 1);
		for (i = 0; i < 7; i++)
		{
			display_hex(bd_addr[i], 2);
		}
		display_update();
	}
}

void show_bd_addr_err(void)
{
	if (!get_OS_flag())
	{
		display_goto_xy(0, 0);
		display_string("BD_ADDR: FAILED");
		display_goto_xy(0, 1);
		display_string("RESTART NXT.");
		display_update();
	}
}

/*
 * add information to the status bar
 */
void add_status_info(SINT status)
{
	CHAR *str;
	
	if (!get_OS_flag())
	{
		switch(status)
		{
			case EXECUTED_FROM_FLASH:
				str = "[F]";
				break;
			case EXECUTED_FROM_SRAM:
				str = "[R]";
				break;
			case BT_CONNECTED:
				str = "[BT]";
				break;
			default:
				return;
		}

		if ((status_bar_position + strlen(str)) <= MAX_STATUS_BAR_LENGTH)
		{
			strcpy(&status_bar[status_bar_position], (const CHAR *)str);
			status_bar_position += strlen(str);
		}
	}
}

/*
 * read buttons status on the NXT. This function is assumed to be executed
 * every 1msec
 */
void check_NXT_buttons(void)
{
	U32 st;
	static U32 last_act_time = 0;

	/* check the buttons every 10msec */
	st = systick_get_ms();
	if (st >= last_act_time + 10) 
	{
		last_act_time = st;
		ecrobot_poll_nxtstate();
		if (ecrobot_get_button_state() == STOP_PRESSED)
		{
			cpp_destructor();
			ecrobot_device_terminate();
			display_clear(0);
			display_force_update();
			systick_wait_ms(10);
			nxt_lcd_power_down(); /* reset LCD hardware */
			systick_wait_ms(10);

			/* jump to the entry of application */
#ifdef NXT_JSP
			lejos_osek_stop();
#else
			start();
#endif
		}
		else if (ecrobot_get_button_state() == EXIT_PRESSED)
		{
			cpp_destructor();
			ecrobot_device_terminate();
			display_clear(0);
			display_force_update();
			systick_wait_ms(10);
			nxt_lcd_power_down(); /* reset LCD hardware */
			systick_wait_ms(10);
			nxt_avr_power_down(); /* send command to AVR to sleep ARM */
		}
	}
}


/*****************************************************************************
 * FILE: bios_display.c
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

#include "mytypes.h"
#include "display.h"
#include "nxt_avr.h"
#include "nxt_lcd.h"

#include "flash_loader.h"
#include "bios.h"

void display_progress_bar(int row, int progress, int max_progress)
{
	U8 *buf;
	int column;
	int index;
	int current_progress;
	
	if ( (progress < 0) || (max_progress <= 0) || (progress > max_progress) ||
	     (row < 0) || (row >= NXT_LCD_DEPTH) )
	{
		return;
	}
	
	current_progress = (progress * 100) / max_progress;
	buf = display_get_buffer();
	for (column = 0; column < NXT_LCD_WIDTH; column++)
	{
		index = (row * NXT_LCD_WIDTH) + column;
		if (column < current_progress)
		{
			buf[index] = 0xff;
		}
		else
		{
			buf[index] = 0x00;
		}	
	}
}

void display_bios_status(int data, int max_data)
{
	static U8 first_flag = 1;
	
	if (first_flag)
	{
		display_clear(0);
		display_goto_xy(0, 0);
		display_string(VERSION);
		display_goto_xy(0, 1);
		display_string("================");
	}

	display_goto_xy(0, 2);
   	display_string("BATT:");
	display_unsigned(battery_voltage()/100, 0);

	if (first_flag)
	{
		display_goto_xy(0, 3);
		display_string("UPLOAD: READY   ");
		first_flag = 0;
	}
	else
	{
		if (data >= UPLOAD_IN_PROGRESS)
		{
			display_goto_xy(0, 3);
			display_string("UPLOAD: PROGRESS");
			display_progress_bar(4, data, max_data);
		}
		else if (data == UPLOAD_FAILED)
		{
			display_goto_xy(0, 3);
			display_string("UPLOAD: FAILED  ");
		}
		else if (data == UPLOAD_FINISHED)
		{
			display_goto_xy(0, 3);
			display_string("UPLOAD: FINISHED");
			/* clear progress bar */
			display_progress_bar(4, 0, 100);
		}
	}
	display_update();
}


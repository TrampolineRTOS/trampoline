/* configuration for HC11 : */

#include <stdio.h>
#include <unistd.h>
#include "tpl_default_tasks_workstation.h"


void dac(int value_to_convert)
{
	P8 = value_to_convert;
}

void start_dialoguing_dac(void)
{
	COMP0 = 1;
}

void stop_dialoguing_dac(void)
{
	COMP0 = 0;
}

void start_dialoguing_lcd(void)
{
	COMP1 = 1;
}

void stop_dialoguing_lcd(void)
{
	COMP1 = 0;
}

void lcd1(char *string)
{
	lcd_Home1(); 
 	lcd_PutString(string); 
}

void lcd2(char *string)
{
	lcd_Home2(); 
 	lcd_PutString(string); 
}
/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Portability Section
 *                   -------------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_port.c (for portability)
 *
 *  Date:       Aug 15, 2011
 *
 *  Author:     Anup Patel (anup@brainfault.org)
 *
 ****************************************************************************
 */

#include <arm_heap.h>
#include <arm_stdio.h>
#include <arm_string.h>
#include <arm_timer.h>
#include "dhry_port.h"

extern u8 _heap_start;

void * dhry_malloc(unsigned int size)
{
	return arm_malloc(size);
}

TimeStamp dhry_timestamp(void)
{
	return arm_udiv64(arm_timer_timestamp(), 1000);
}

long dhry_to_microsecs(TimeStamp UserTime)
{
	return UserTime;
}

long dhry_iter_per_sec(TimeStamp UserTime, int Number_Of_Runs)
{
	return arm_udiv64(((TimeStamp)Number_Of_Runs * (TimeStamp)1000000),
								 UserTime);
}

int dhry_strcmp(char *dst, char *src)
{
	return arm_strcmp(dst, src);
}

void dhry_strcpy(char *dst, char *src)
{
	arm_strcpy(dst, src);
}

void dhry_printc(char ch)
{
	char tmp[2];
	tmp[0] = ch;
	tmp[1] = '\0';
	arm_puts(tmp);
}

void dhry_prints(char *str)
{
	arm_puts(str);
}

void dhry_printi(int val)
{
	char tmp[128];
	arm_int2str(tmp, val);
	arm_puts(tmp);
}


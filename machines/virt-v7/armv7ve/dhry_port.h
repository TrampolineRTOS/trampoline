/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Portability Section
 *                   -------------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_port.h (for portability)
 *
 *  Date:       Aug 15, 2011
 *
 *  Author:     Anup Patel (anup@brainfault.org)
 *
 ****************************************************************************
 */

#ifndef __DHRY_PORT_H_
#define __DHRY_PORT_H_

#include <arm_math.h>

#define REG register

typedef unsigned long long TimeStamp;

#define Too_Small_Time  (TimeStamp)1000000

#define dhry_sdiv32(v, d)	arm_sdiv32((v), (d))

void * dhry_malloc(unsigned int size);
TimeStamp dhry_timestamp(void);
long dhry_to_microsecs(TimeStamp UserTime);
long dhry_iter_per_sec(TimeStamp UserTime, int Number_Of_Runs);
int dhry_strcmp(char *dst, char *src);
void dhry_strcpy(char *dst, char *src);
void dhry_printc(char ch);
void dhry_prints(char *str);
void dhry_printi(int val);

#endif /* __DHRY_PORT_H_ */

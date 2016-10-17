/**
 * Copyright (c) 2011 Anup Patel.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file arm_stdio.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief Header file for common input/output functions
 */

#ifndef __ARM_STDIO_H_
#define __ARM_STDIO_H_

#include <arm_types.h>

bool arm_isprintable(char ch);
void arm_putc(char ch);
char arm_getc(void);
void arm_stdio_init(void);
void arm_puts(const char * str);
void arm_gets(char *s, int maxwidth, char endchar);
int arm_sprintf(char *out, const char *format, ...);
int arm_snprintf(char *out, u32 out_sz, const char *format, ...);
int arm_printf(const char *format, ...);

#endif /* __ARM_STDIO_H_ */

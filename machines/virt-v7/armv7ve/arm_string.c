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
 * @file arm_string.c
 * @author Anup Patel (anup@brainfault.org)
 * @brief source file for common string functions
 */

#include <arm_string.h>
#include <arm_math.h>

void *arm_memcpy(void *dest, const void *src, unsigned int count)
{
	u8 *dst8 = (u8 *) dest;
	u8 *src8 = (u8 *) src;

	if (count & 1) {
		dst8[0] = src8[0];
		dst8 += 1;
		src8 += 1;
	}

	count /= 2;
	while (count--) {
		dst8[0] = src8[0];
		dst8[1] = src8[1];

		dst8 += 2;
		src8 += 2;
	}

	return dest;
}

void *arm_memmove(void *dest, const void *src, unsigned int count)
{
	u8 *dst8 = (u8 *) dest;
	const u8 *src8 = (u8 *) src;

	if(dest == src)
		return dest;

	if (src8 > dst8) {
		if (count & 1) {
			dst8[0] = src8[0];
			dst8 += 1;
			src8 += 1;
		}

		count /= 2;
		while (count--) {
			dst8[0] = src8[0];
			dst8[1] = src8[1];

			dst8 += 2;
			src8 += 2;
		}
	} else {
		dst8 += count;
		src8 += count;

		if (count & 1) {
			dst8 -= 1;
			src8 -= 1;
			dst8[0] = src8[0];
		}

		count /= 2;
		while (count--) {
			dst8 -= 2;
			src8 -= 2;

			dst8[0] = src8[0];
			dst8[1] = src8[1];
		}
	}

	return dest;
}

void *arm_memset(void *dest, int c, unsigned int count)
{
	u8 *dst8 = (u8 *) dest;
	u8 ch = (u8) c;

	if (count & 1) {
		dst8[0] = ch;
		dst8 += 1;
	}

	count /= 2;
	while (count--) {
		dst8[0] = ch;
		dst8[1] = ch;
		dst8 += 2;
	}

	return dest;
}

int arm_memcmp(const void *s1, const void *s2, unsigned int count)
{
	u8 *p1 = (u8 *) s1;
	u8 *p2 = (u8 *) s2;
	if (count != 0) {
		do {
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
		} while (--count != 0);
	}
	return (0);
}

char *arm_memchr(const char *p, int ch, int count)
{
	int i;
	for(i=0; i<count; i++) {
		if ((*p)==ch) {
			return((char *)p);
		}
		p++;
	} 
	return((char *)NULL);
}

char *arm_strchr(const char *p, int ch)
{
	do {
		if ((*p)==ch) {
			return((char *)p);
		}
	} while((*p++)!='\0'); 
	return((char *)NULL);
}

size_t arm_strlen(const char *s)
{
	size_t ret = 0;
	while (s[ret]) {
		ret++;
	}
	return ret;
}

char *arm_strcpy(char *dest, const char *src)
{
	u32 i;
	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}

char *arm_strcat(char *dest, const char *src)
{
	arm_strcpy(&dest[arm_strlen(dest)], src);

	return dest;
}

int arm_strcmp(const char *a, const char *b)
{
	while (*a == *b) {
		if (*a == '\0' || *b == '\0') {
			return (unsigned char)*a - (unsigned char)*b;
		}
		++a;
		++b;
	}
	return (unsigned char)*a - (unsigned char)*b;
}

int arm_str2int(char * src)
{
	int val = 0, pos = 0, minus = 0;

	if (src[pos] == '-') {
		minus = 1;
		pos++;
	}

	while (src[pos]) {
		val = 10 * val + (src[pos] - '0');
		pos++;
	}

	return (minus) ? -val : val;
}

void arm_int2str(char * dst, int src)
{
	int val, count = 0, pos = 0;
	static const char intchars[] = "0123456789";

	val = src;
	while (val) {
		count++;
		val = val / 10;
	}
	if (src < 0) {
		count++;
	}

	val = (src < 0) ? -src : src;
	while (val) {
		dst[count - pos - 1] = intchars[val % 10];
		pos++;
		val = val / 10;
	}
	if (src < 0) {
		dst[0] = '-';
	}

	if (count == 0) {
		dst[count] = '0';
		count++;
	}

	dst[count] = '\0';
}

void arm_ulonglong2str(char *dst, unsigned long long src)
{
	unsigned long long val, remainder;
        int count = 0, pos = 0;
        static const char intchars[] = "0123456789";

        val = src;
        while (val) {
                count++;
                val = do_udiv64(val, 10, &remainder);
        }
        if (src < 0) {
                count++;
        }

        val = (src < 0) ? -src : src;
        while (val) {
                val = do_udiv64(val, 10, &remainder);
                dst[count - pos - 1] = intchars[remainder];
                pos++;
        }
        if (src < 0) {
                dst[0] = '-';
        }

        if (count == 0) {
                dst[count] = '0';
                count++;
        }

        dst[count] = '\0';
}

unsigned int arm_hexstr2uint(char * src)
{
	unsigned int val = 0x0;
	int pos = 0;

	if ((src[0] == '0') && (src[1] == 'x')) {
		pos = 2;
	}

	while (src[pos]) {
		if (('0' <= src[pos]) && (src[pos] <= '9')) {
			val = val * 16 + (src[pos] - '0');
		} else if (('A' <= src[pos]) && (src[pos] <= 'F')) {
			val = val * 16 + (src[pos] - 'A' + 10);
		} else if (('a' <= src[pos]) && (src[pos] <= 'f')) {
			val = val * 16 + (src[pos] - 'a' + 10);
		}
		pos++;
	}

	return val;
}

void arm_uint2hexstr(char * dst, unsigned int src)
{
	int ite, pos = 0;
	static const char hexchars[] = "0123456789ABCDEF";

	for (ite = 0; ite < 8; ite++) {
		if ((pos == 0) && !((src >> (4 * (8 - ite - 1))) & 0xF)) {
			continue;
		}
		dst[pos] = hexchars[(src >> (4 * (8 - ite - 1))) & 0xF];
		pos++;
	}

	if (pos == 0) {
		dst[pos] = '0';
		pos++;
	}

	dst[pos] = '\0';
}

void arm_ulonglong2hexstr(char *dst, unsigned long long src)
{
	int ite, pos = 0;
	static const char hexchars[] = "0123456789ABCDEF";

	for (ite = 0; ite < 16; ite++) {
		if ((pos == 0) && !((src >> (4 * (16 - ite - 1))) & 0xF)) {
			continue;
		}
		dst[pos] = hexchars[(src >> (4 * (16 - ite - 1))) & 0xF];
		pos++;
	}

	if (pos == 0) {
		dst[pos] = '0';
		pos++;
	}

	dst[pos] = '\0';
}


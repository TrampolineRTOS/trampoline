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
 * @file arm_math.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief commonly required math operations
 */

#ifndef __ARM_MATH_H_
#define __ARM_MATH_H_

#include "tpl_os_internal_types.h"
#include <arm_types.h>

#define do_abs(x)  ((x) < 0 ? -(x) : (x))

u64 do_udiv64(u64 dividend, u64 divisor, u64 * remainder);

static inline u64 arm_udiv64(u64 value, u64 divisor)
{
	return do_udiv64(value, divisor, NULL);
}

static inline u64 arm_umod64(u64 value, u64 divisor)
{
	u64 remainder;
	do_udiv64(value, divisor, &remainder);
	return remainder;
}

u32 do_udiv32(u32 dividend, u32 divisor, u32 * remainder);

static inline u32 arm_udiv32(u32 value, u32 divisor)
{
	u32 remainder;
	return do_udiv32(value, divisor, &remainder);
}

static inline u32 arm_umod32(u32 value, u32 divisor)
{
	u32 remainder;
	do_udiv32(value, divisor, &remainder);
	return remainder;
}

static inline s32 arm_sdiv32(s32 value, s32 divisor)
{
	u32 remainder;
	if ((value * divisor) < 0) {
		return -do_udiv32( do_abs(value), do_abs(divisor), &remainder );
	} else { /* positive value */
		return do_udiv32( do_abs(value), do_abs(divisor), &remainder );
	}
}

#endif /* __ARM_MATH_H_ */

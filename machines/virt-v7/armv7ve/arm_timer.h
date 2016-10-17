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
 * @file arm_timer.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief ARM Timer header
 */
#ifndef _ARM_TIMER_H__
#define _ARM_TIMER_H__

#include <arm_types.h>
#include <arm_board.h>

static inline void arm_timer_enable(void)
{
	arm_board_timer_enable();
}

static inline void arm_timer_disable(void)
{
	arm_board_timer_disable();
}

static inline u64 arm_timer_irqcount(void)
{
	return arm_board_timer_irqcount();
}

static inline u64 arm_timer_irqdelay(void)
{
	return arm_board_timer_irqdelay();
}

static inline u64 arm_timer_timestamp(void)
{
	return arm_board_timer_timestamp();
}

static inline int arm_timer_init(u32 usecs)
{
	return arm_board_timer_init(usecs);
}

static inline void arm_timer_change_period(u32 usecs)
{
	return arm_board_timer_change_period(usecs);
}

#endif

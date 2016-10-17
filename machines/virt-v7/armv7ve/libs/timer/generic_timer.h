/**
 * Copyright (c) 2013 Sukanto Ghosh.
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
 * @file generic_timer.h
 * @author Sukanto Ghosh (sukantoghosh@gmail.com)
 * @brief ARMv7 Generic Timer Header
 */
#ifndef _ARM_GENERIC_TIMER_H__
#define _ARM_GENERIC_TIMER_H__

#include <arm_types.h>

void generic_timer_enable(void);
void generic_timer_disable(void);
u64 generic_timer_irqcount(void);
u64 generic_timer_irqdelay(void);
u64 generic_timer_timestamp(void);
void generic_timer_change_period(u32 usecs);
int generic_timer_init(u32 usecs, u32 irq);

#endif

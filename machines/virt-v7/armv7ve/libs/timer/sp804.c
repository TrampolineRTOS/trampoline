/**
 * Copyright (c) 2013 Anup Patel.
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
 * @file sp804.c
 * @author Anup Patel (anup@brainfault.org)
 * @brief ARM SP804 Dual-Mode Timer source
 */

#include <arm_io.h>
#include <arm_irq.h>
#include <arm_math.h>

#include <timer/sp804.h>

#define TIMER_LOAD              0x00
#define TIMER_VALUE             0x04
#define TIMER_CTRL              0x08
#define TIMER_CTRL_ONESHOT      (1 << 0)
#define TIMER_CTRL_32BIT        (1 << 1)
#define TIMER_CTRL_DIV1         (0 << 2)
#define TIMER_CTRL_DIV16        (1 << 2)
#define TIMER_CTRL_DIV256       (2 << 2)
#define TIMER_CTRL_IE           (1 << 5)        /* Interrupt Enable (versatile only) */
#define TIMER_CTRL_PERIODIC     (1 << 6)
#define TIMER_CTRL_ENABLE       (1 << 7)

#define TIMER_INTCLR            0x0c
#define TIMER_RIS               0x10
#define TIMER_MIS               0x14
#define TIMER_BGLOAD            0x18

static u32 sp804_base;
static u32 sp804_irq;
static u64 sp804_irq_count;
static u64 sp804_irq_tcount;
static u64 sp804_irq_tstamp;
static u64 sp804_irq_delay;
static u64 sp804_counter_mask;
static u64 sp804_counter_shift;
static u64 sp804_counter_mult;
static u64 sp804_counter_last;
static u64 sp804_time_stamp;

void sp804_enable(void)
{
	u32 ctrl;

	ctrl = arm_readl((void *)(sp804_base + TIMER_CTRL));
	ctrl |= TIMER_CTRL_ENABLE;
	arm_writel(ctrl, (void *)(sp804_base + TIMER_CTRL));
}

void sp804_disable(void)
{
	u32 ctrl;

	ctrl = arm_readl((void *)(sp804_base + TIMER_CTRL));
	ctrl &= ~TIMER_CTRL_ENABLE;
	arm_writel(ctrl, (void *)(sp804_base + TIMER_CTRL));
}

void sp804_change_period(u32 usec)
{
        arm_writel(usec, (void *)(sp804_base + TIMER_LOAD));
}

u64 sp804_irqcount(void)
{
	return sp804_irq_count;
}

u64 sp804_irqdelay(void)
{
	return sp804_irq_delay;
}

u64 sp804_timestamp(void)
{
	u64 sp804_counter_now, sp804_counter_delta, offset;
	sp804_counter_now = ~arm_readl((void *)(sp804_base + 0x20 + TIMER_VALUE));
	sp804_counter_delta = (sp804_counter_now - sp804_counter_last) & sp804_counter_mask;
	sp804_counter_last = sp804_counter_now;
	offset = (sp804_counter_delta * sp804_counter_mult) >> sp804_counter_shift;
	sp804_time_stamp += offset;
	return sp804_time_stamp;
}

int sp804_irqhndl(u32 irq_no, struct pt_regs * regs)
{
	u64 tstamp = sp804_timestamp();

	if (!sp804_irq_tstamp) {
		sp804_irq_tstamp = tstamp;
	}
	if (sp804_irq_tcount == 256) {
		sp804_irq_delay = (tstamp - sp804_irq_tstamp) >> 8;
		sp804_irq_tcount = 0;
		sp804_irq_tstamp = tstamp;
	}
	sp804_irq_tcount++;
	sp804_irq_count++;

	arm_writel(1, (void *)(sp804_base + TIMER_INTCLR));

	return 0;
}

int sp804_init(u32 usecs, u32 base, u32 irq,
		u64 counter_mask, u64 counter_mult, u64 counter_shift)
{
	u32 val;

	sp804_base = base;

	sp804_counter_mask = counter_mask;
	sp804_counter_shift = counter_shift;
	sp804_counter_mult = counter_mult;
	sp804_counter_last = 0; 
	sp804_time_stamp = 0;

	sp804_irq = irq;
	sp804_irq_count = 0;
	sp804_irq_tcount = 0;
	sp804_irq_tstamp = 0;
	sp804_irq_delay = 0;

	/* Register interrupt handler */
	arm_irq_register(sp804_irq, &sp804_irqhndl);

	/* Setup Timer0 for generating irq */
	val = arm_readl((void *)(sp804_base + TIMER_CTRL));
	val &= ~TIMER_CTRL_ENABLE;
	val |= (TIMER_CTRL_32BIT | TIMER_CTRL_PERIODIC | TIMER_CTRL_IE);
	arm_writel(val, (void *)(sp804_base + TIMER_CTRL));
	sp804_change_period(usecs);

	/* Setup Timer1 for free running counter */
	arm_writel(0x0, (void *)(sp804_base + 0x20 + TIMER_CTRL));
	arm_writel(0xFFFFFFFF, (void *)(sp804_base + 0x20 + TIMER_LOAD));
	val = (TIMER_CTRL_32BIT | TIMER_CTRL_PERIODIC | TIMER_CTRL_ENABLE);
	arm_writel(val, (void *)(sp804_base + 0x20 + TIMER_CTRL));

	return 0;
}

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
 * @file generic_timer.c
 * @author Sukanto Ghosh (sukantoghosh@gmail.com)
 * @brief ARMv7 Generic Timer driver source
 *
 */

#include <arm_irq.h>
#include <arm_math.h>
#include <arm_stdio.h>
#include <arm_inline_asm.h>
#include <generic_timer.h>

#define read_cntfrq()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c14, c0, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define read_cntv_ctl()		({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c14, c3, 1\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_cntv_ctl(val)	__asm__ volatile(\
				" mcr     p15, 0, %0, c14, c3, 1\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_cntv_cval()	({ u32 v1, v2; __asm__ volatile(\
				" mrrc     p15, 3, %0, %1, c14\n\t" \
				: "=r" (v1), "=r" (v2) : : "memory", "cc"); \
				(((u64)v2 << 32) + (u64)v1);})

#define write_cntv_cval(val)	__asm__ volatile(\
				" mcrr     p15, 3, %0, %1, c14\n\t" \
				:: "r" ((val) & 0xFFFFFFFF), "r" ((val) >> 32) \
				: "memory", "cc")

#define read_cntv_tval()	({ u32 rval; __asm__ volatile(\
				" mrc     p15, 0, %0, c14, c3, 0\n\t" \
				: "=r" (rval) : : "memory", "cc"); rval;})

#define write_cntv_tval(val)	__asm__ volatile(\
				" mcr     p15, 0, %0, c14, c3, 0\n\t" \
				:: "r" ((val)) : "memory", "cc")

#define read_cntvct()		({ u32 v1, v2; __asm__ volatile(\
				" mrrc     p15, 1, %0, %1, c14\n\t" \
				: "=r" (v1), "=r" (v2) : : "memory", "cc"); \
				(((u64)v2 << 32) + (u64)v1);})

#define GENERIC_TIMER_CTRL_ENABLE		(1 << 0)
#define GENERIC_TIMER_CTRL_IT_MASK		(1 << 1)
#define GENERIC_TIMER_CTRL_IT_STAT		(1 << 2)

static u64 timer_irq_count;
static u64 timer_irq_tcount;
static u64 timer_irq_delay;
static u64 timer_irq_tstamp;
static u64 timer_freq;
static u64 timer_period_ticks;
static u64 timer_mult;
static u32 timer_shift;

void generic_timer_enable(void)
{
	unsigned long ctrl;

	ctrl = read_cntv_ctl();
	ctrl |= GENERIC_TIMER_CTRL_ENABLE;
	ctrl &= ~GENERIC_TIMER_CTRL_IT_MASK;
	write_cntv_ctl(ctrl);
}

void generic_timer_disable(void)
{
	unsigned long ctrl;

	ctrl = read_cntv_ctl();
	ctrl &= ~GENERIC_TIMER_CTRL_ENABLE;
	write_cntv_ctl(ctrl);
}

void generic_timer_change_period(u32 usec)
{
	timer_period_ticks = (arm_udiv64(timer_freq, 1000000) * usec);

	write_cntv_tval(timer_period_ticks);
}

u64 generic_timer_irqcount(void)
{
	return timer_irq_count;
}

u64 generic_timer_irqdelay(void)
{
	return timer_irq_delay;
}

u64 generic_timer_timestamp(void)
{
	return (read_cntvct() * timer_mult) >> timer_shift;
}

int generic_timer_irqhndl(u32 irq_no, struct pt_regs *regs)
{
	unsigned long ctrl;
	u64 tstamp;

	// arm_puts("generic_timer_irqhndl\n");

	ctrl = read_cntv_ctl();
	if (ctrl & GENERIC_TIMER_CTRL_IT_STAT) {
		ctrl |= GENERIC_TIMER_CTRL_IT_MASK;
		write_cntv_ctl(ctrl);
	}

	timer_irq_count++;
	timer_irq_tcount++;

	tstamp = generic_timer_timestamp();
	if (!timer_irq_tstamp) {
		timer_irq_tstamp = tstamp;
	}
	if (timer_irq_tcount == 128) {
		timer_irq_delay = (tstamp - timer_irq_tstamp) >> 7;
		timer_irq_tcount = 0;
		timer_irq_tstamp = tstamp;
	}

	ctrl = read_cntv_ctl();
	ctrl |= GENERIC_TIMER_CTRL_ENABLE;
	ctrl &= ~GENERIC_TIMER_CTRL_IT_MASK;

	write_cntv_tval(timer_period_ticks);
	write_cntv_ctl(GENERIC_TIMER_CTRL_ENABLE);

	return 0;
}

static void calc_mult_shift(u64 *mult, u32 *shift,
		            u32 from, u32 to, u32 maxsec)
{
        u64 tmp;
        u32 sft, sftacc= 32;

	/* Calculate the shift factor which is limiting
	 * the conversion range:
	 */
        tmp = ((u64)maxsec * from) >> 32;
        while (tmp) {
                tmp >>=1;
                sftacc--;
        }

        /* Find the conversion shift/mult pair which has the best
	 * accuracy and fits the maxsec conversion range:
	 */
        for (sft = 32; sft > 0; sft--) {
                tmp = (u64) to << sft;
                tmp += from / 2;
                tmp = arm_udiv64(tmp, from);
                if ((tmp >> sftacc) == 0)
                        break;
        }
        *mult = tmp;
        *shift = sft;
}

long testi_nbcall = 0;

int testi(void) {
	arm_puts("testi_nbcall\n");

  return 0;
}

extern FUNC(void, OS_CODE) ARM_TIMER_Handler(void);

int generic_timer_irqandtickhndl(u32 irq_no, struct pt_regs *regs) {
	int res = 1;

	// arm_puts("generic_timer_irqandtickhndl 1\n");

	res = generic_timer_irqhndl(irq_no, regs);
	if (res == 0) {
		ARM_TIMER_Handler();
	}
	// res = 1;
	// res = testi();
	// arm_puts("generic_timer_irqandtickhndl 2\n");
	// if (res == 0) {
	// 	testi_nbcall++;
	// }
	// res = 1;
	// arm_puts("generic_timer_irqandtickhndl 3\n");

	return 0;
}

int generic_timer_init(u32 usecs, u32 irq)
{
	timer_freq = read_cntfrq();
	if (timer_freq == 0) {
		/* Assume 100 Mhz clock if cntfrq_el0 not programmed */
		timer_freq = 100000000;
	}

	calc_mult_shift(&timer_mult, &timer_shift, timer_freq, 1000000000, 1);

	timer_period_ticks = (arm_udiv64(timer_freq, 1000000) * usecs);

//	arm_irq_register(irq, &generic_timer_irqhndl);
	arm_irq_register(irq, &generic_timer_irqandtickhndl);
	write_cntv_tval(timer_period_ticks);
	write_cntv_ctl(GENERIC_TIMER_CTRL_IT_MASK);

	return 0;
}

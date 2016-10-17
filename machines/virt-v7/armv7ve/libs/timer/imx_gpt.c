/**
 * Copyright (C) 2014 Institut de Recherche Technologique SystemX and OpenWide.
 * Inspired by sp804.c, Copyright (c) 2013 Anup Patel.
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
 * @file imx_gpt.c
 * @author Jimmy Durand Wesolowski (jimmy.durand-wesolowski@openwide.fr)
 * @brief i.MX6 GPT timer
 */

#include <arm_io.h>
#include <arm_irq.h>
#include <arm_math.h>

#include <timer/imx_gpt.h>

#define GPT_CR			0
#define GPT_CR_SW		(1 << 15)
#define GPT_CR_FRR		(1 << 9)
#define GPT_CR_ENMOD		(1 << 1)
#define GPT_CR_EN		(1 << 0)
#define GPT_PR			0x4
#define GPT_PR_MASK		0xFFF
#define GPT_SR			0x8
#define GPT_SR_MASK		0x3F
#define GPT_IR			0xC
#define GPT_IR_MASK		0x3F
#define GPT_OC1			0x10
#define GPT_OC2			0x14
#define GPT_OC3			0x18
#define GPT_CNT			0x24
#define GPT_FREQ		32000

static u32 imx_gpt_base;
static u32 imx_gpt_irq;
static u64 imx_gpt_period = 0;
static u64 imx_gpt_irq_count = 0;
static u64 imx_gpt_irq_tstamp = 0;
static u64 imx_gpt_irq_delay = 0;
static u64 imx_gpt_freerun = 0;
static u64 imx_gpt_timestamp_sum = 0;

void imx_gpt_enable(void)
{
	u32 ctrl;

	ctrl = arm_readl((void *)(imx_gpt_base + GPT_CR));
	ctrl |= GPT_CR_EN;
	arm_writel(ctrl, (void *)(imx_gpt_base + GPT_CR));
}

void imx_gpt_disable(void)
{
	u32 ctrl;

	ctrl = arm_readl((void *)(imx_gpt_base + GPT_CR));
	ctrl &= ~GPT_CR_EN;
	arm_writel(ctrl, (void *)(imx_gpt_base + GPT_CR));
}

static void imx_gpt_next_event(void)
{
	u32 cnt = 0;

	if (imx_gpt_freerun) {
		cnt = arm_readl((void *)(imx_gpt_base + GPT_CNT));
	}
	arm_writel(cnt + imx_gpt_period, (void *)(imx_gpt_base + GPT_OC1));
}

void imx_gpt_change_period(u32 usec)
{
	u32 rem;

	if (!imx_gpt_freerun) {
		imx_gpt_timestamp_sum += arm_readl((void *)(imx_gpt_base +
							    GPT_CNT));
	}
	imx_gpt_period = do_udiv32(usec, (GPT_FREQ / 1000), &rem);
	imx_gpt_next_event();
}

u64 imx_gpt_irqcount(void)
{
	return imx_gpt_irq_count;
}

u64 imx_gpt_irqdelay(void)
{
	return imx_gpt_irq_delay;
}

u64 imx_gpt_timestamp(void)
{
	static u32 imx_gpt_counter_last = 0;
	static u32 imx_gpt_up = 0;
	u32 counter = 0;
	u64 timestamp;

	counter = arm_readl((void *)(imx_gpt_base + GPT_CNT));
	if (imx_gpt_freerun) {
		/*
		 * In freerun mode, we only have to make a 64 bit counter
		 * from a 32 bit one.
		 */
		if (counter < imx_gpt_counter_last) {
			++imx_gpt_up;
		};
		imx_gpt_counter_last = counter;
		timestamp = imx_gpt_up;
		timestamp = (timestamp << 32) | counter;
	} else {
		/*
		 * In restart mode, we retrieve the period sum and the
		 * current value
		 */
		timestamp = imx_gpt_timestamp_sum + counter;
	}
	return timestamp * GPT_FREQ;
}

int imx_gpt_irqhndl(u32 irq_no, struct pt_regs * regs)
{
	u64 tstamp = 0;

	imx_gpt_disable();

	tstamp = imx_gpt_timestamp();
	imx_gpt_irq_delay = tstamp - imx_gpt_irq_tstamp;
	imx_gpt_irq_tstamp = tstamp;
	imx_gpt_irq_count++;

	if (!imx_gpt_freerun) {
		imx_gpt_timestamp_sum += imx_gpt_period;
	}

	imx_gpt_next_event();
	arm_writel(1, (void *)(imx_gpt_base + GPT_SR));
	imx_gpt_enable();

	return 0;
}

int imx_gpt_init(u32 usecs, u32 base, u32 irq, u32 freerun)
{
	u32 val;

	imx_gpt_base = base;
	imx_gpt_irq = irq;
	imx_gpt_irq_count = 0;

	/* Register interrupt handler */
	arm_irq_register(imx_gpt_irq, &imx_gpt_irqhndl);

	val = arm_readl((void *)(imx_gpt_base + GPT_CR));
	if (freerun) {
		imx_gpt_freerun = 1;
		val |= GPT_CR_FRR;
	}
	val |= GPT_CR_ENMOD;
	arm_writel(val, (void *)(imx_gpt_base + GPT_CR));

	imx_gpt_disable();
	imx_gpt_change_period(usecs);
	imx_gpt_enable();

	/* Setup Timer0 for generating irq */
	arm_writel(1, (void *)(imx_gpt_base + GPT_IR));

	return 0;
}

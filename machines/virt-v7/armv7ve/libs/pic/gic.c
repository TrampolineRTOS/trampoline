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
 * @file gic.c
 * @author Anup Patel (anup@brainfault.org)
 * @brief ARM Generic Interrupt Controller
 */

#include <arm_io.h>
#include <gic_config.h>
#include <gic.h>

#define max(a,b)	((a) < (b) ? (b) : (a))

struct gic_chip_data {
	u32 irq_offset;
	virtual_addr_t dist_base;
	virtual_addr_t cpu_base;
};

static struct gic_chip_data gic_data[GIC_MAX_NR];

static inline void gic_write(u32 val, virtual_addr_t addr)
{
	arm_writel(val, (void *)(addr));
}

static inline u32 gic_read(virtual_addr_t addr)
{
	return arm_readl((void *)(addr));
}

int gic_active_irq(u32 gic_nr)
{
	int ret = -1;

	if (GIC_MAX_NR <= gic_nr) {
		return -1;
	}

	ret = gic_read(gic_data[gic_nr].cpu_base +
				GIC_CPU_INTACK) & 0x3FF;
	ret += gic_data[gic_nr].irq_offset;

	return ret;
}

int gic_eoi_irq(u32 gic_nr, u32 irq)
{
	u32 gic_irq;

	if (GIC_MAX_NR <= gic_nr) {
		return -1;
	}

	if (irq < gic_data[gic_nr].irq_offset) {
		return -1;
	}

	gic_irq = irq - gic_data[gic_nr].irq_offset;
	gic_write(gic_irq, gic_data[gic_nr].cpu_base + GIC_CPU_EOI);

	return 0;
}

int gic_mask(u32 gic_nr, u32 irq)
{
	u32 mask = 1 << (irq % 32);
	u32 gic_irq;

	if (GIC_MAX_NR <= gic_nr) {
		return -1;
	}

	if (irq < gic_data[gic_nr].irq_offset) {
		return -1;
	}

	gic_irq = irq - gic_data[gic_nr].irq_offset;

	gic_write(mask, gic_data[gic_nr].dist_base +
			   GIC_DIST_ENABLE_CLEAR + (gic_irq / 32) * 4);

	return 0;
}

int gic_unmask(u32 gic_nr, u32 irq)
{
	u32 mask = 1 << (irq % 32);
	u32 gic_irq;

	if (GIC_MAX_NR <= gic_nr) {
		return -1;
	}

	if (irq < gic_data[gic_nr].irq_offset) {
		return -1;
	}

	gic_irq = irq - gic_data[gic_nr].irq_offset;

	gic_write(mask, gic_data[gic_nr].dist_base +
			   GIC_DIST_ENABLE_SET + (gic_irq / 32) * 4);

	return 0;
}

int gic_dist_init(u32 gic_nr, virtual_addr_t base, u32 irq_start)
{
	unsigned int max_irq, i;
	u32 cpumask = 1 << 0;	/*smp_processor_id(); */

	if (GIC_MAX_NR <= gic_nr) {
		return -1;
	}

	cpumask |= cpumask << 8;
	cpumask |= cpumask << 16;

	gic_data[gic_nr].dist_base = base;
	gic_data[gic_nr].irq_offset = (irq_start - 1) & ~31;

	gic_write(0, base + GIC_DIST_CTRL);

	/*
	 * Find out how many interrupts are supported.
	 */
	max_irq = gic_read(base + GIC_DIST_CTR) & 0x1f;
	max_irq = (max_irq + 1) * 32;

	/*
	 * The GIC only supports up to 1020 interrupt sources.
	 * Limit this to either the architected maximum, or the
	 * platform maximum.
	 */
	if (max_irq > max(1020, GIC_NR_IRQS))
		max_irq = max(1020, GIC_NR_IRQS);

	/*
	 * Set all global interrupts to be level triggered, active low.
	 */
	for (i = 32; i < max_irq; i += 16)
		gic_write(0, base + GIC_DIST_CONFIG + i * 4 / 16);

	/*
	 * Set all global interrupts to this CPU only.
	 */
	for (i = 32; i < max_irq; i += 4)
		gic_write(cpumask, base + GIC_DIST_TARGET + i * 4 / 4);

	/*
	 * Set priority on all interrupts.
	 */
	for (i = 0; i < max_irq; i += 4)
		gic_write(0xa0a0a0a0, base + GIC_DIST_PRI + i * 4 / 4);

	/*
	 * Disable all interrupts.
	 */
	for (i = 0; i < max_irq; i += 32)
		gic_write(0xffffffff,
				   base + GIC_DIST_ENABLE_CLEAR + i * 4 / 32);

	gic_write(1, base + GIC_DIST_CTRL);

	return 0;
}

int gic_cpu_init(u32 gic_nr, virtual_addr_t base)
{
	if (GIC_MAX_NR <= gic_nr) {
		return -1;
	}

	gic_data[gic_nr].cpu_base = base;

	gic_write(0xf0, base + GIC_CPU_PRIMASK);
	gic_write(1, base + GIC_CPU_CTRL);

	return 0;
}

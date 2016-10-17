/**
 * Copyright (c) 2014 Anup Patel.
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
 * @file arm_board.c
 * @author Anup Patel (anup@brainfault.org)
 * @brief various platform specific functions
 */

#include <arm_types.h>
#include <arm_string.h>
#include <arm_board.h>
#include <arm_plat.h>
#include <arm_stdio.h>
#include <gic.h>
#include <generic_timer.h>
#include <pl01x.h>

long arm_irq;

void arm_board_reset(void)
{
	long ret;
	unsigned long func, arg0, arg1, arg2;

	/* HVC-based PSCI v0.2 SYSTEM_RESET call */
	func = 0x84000009;
	arg0 = 0;
	arg1 = 0;
	arg2 = 0;
	__asm__ volatile(
		".arch_extension sec\n\t"
		"mov	r0, %1\n\t"
		"mov	r1, %2\n\t"
		"mov	r2, %3\n\t"
		"mov	r3, %4\n\t"
		"smc	#0    \n\t"
		"mov	%0, r0\n\t"
	: "=r" (ret)
	: "r" (func), "r" (arg0), "r" (arg1), "r" (arg2)
	: "r0", "r1", "r2", "r3", "cc", "memory");

	if (ret) {
		arm_printf("%s: PSCI SYSTEM_RESET returned %d",
			   __func__, ret);
	}
}

void arm_board_init(void)
{
	/* Nothing to do */
}

char *arm_board_name(void)
{
	return "Virt-v7";
}

physical_addr_t arm_board_ram_start(void)
{
	return VIRT_V7_RAM0;
}

physical_size_t arm_board_ram_size(void)
{
	return VIRT_V7_RAM0_SIZE;
}

u32 arm_board_linux_machine_type(void)
{
	return 0x000; /* Dummy machine type */
}

void arm_board_linux_default_cmdline(char *cmdline, u32 cmdline_sz)
{
	arm_strcpy(cmdline, "root=/dev/ram rw earlyprintk "
			    "console=ttyAMA0");
}

physical_addr_t arm_board_flash_addr(void)
{
	return VIRT_V7_NOR_FLASH;
}

u32 arm_board_iosection_count(void)
{
	return 6;
}

physical_addr_t arm_board_iosection_addr(int num)
{
	physical_addr_t ret = 0;

	switch (num) {
	case 0:
		/* nor-flash */
		ret = VIRT_V7_NOR_FLASH;
		break;
	case 1:
		/* gic */
		ret = VIRT_V7_GIC;
		break;
	case 2:
		/* uart0 */
		ret = VIRT_V7_UART0;
		break;
	case 3:
		/* virtio-net */
		ret = VIRT_V7_VIRTIO_NET;
		break;
	case 4:
		/* virtio-blk */
		ret = VIRT_V7_VIRTIO_BLK;
		break;
	case 5:
		/* virtio-con */
		ret = VIRT_V7_VIRTIO_CON;
		break;
	default:
		while (1);
		break;
	}

	return ret;
}

u32 arm_board_pic_nr_irqs(void)
{
	return NR_IRQS_VIRT_V7;
}

int arm_board_pic_init(void)
{
	int rc;

	/*
	 * Initialize Generic Interrupt Controller
	 */
	rc = gic_dist_init(0, VIRT_V7_GIC_DIST, IRQ_VIRT_V7_GIC_START);
	if (rc) {
		return rc;
	}
	rc = gic_cpu_init(0, VIRT_V7_GIC_CPU);
	if (rc) {
		return rc;
	}

	return 0;
}

u32 arm_board_pic_active_irq(void)
{
	return gic_active_irq(0);
}

int arm_board_pic_ack_irq(u32 irq)
{
	return 0;
}

int arm_board_pic_eoi_irq(u32 irq)
{
	return gic_eoi_irq(0, irq);
}

int arm_board_pic_mask(u32 irq)
{
	return gic_mask(0, irq);
}

int arm_board_pic_unmask(u32 irq)
{
	return gic_unmask(0, irq);
}

void arm_board_timer_enable(void)
{
	return generic_timer_enable();
}

void arm_board_timer_disable(void)
{
	return generic_timer_disable();
}

u64 arm_board_timer_irqcount(void)
{
	return generic_timer_irqcount();
}

u64 arm_board_timer_irqdelay(void)
{
	return generic_timer_irqdelay();
}

u64 arm_board_timer_timestamp(void)
{
	return generic_timer_timestamp();
}

void arm_board_timer_change_period(u32 usecs)
{
	return generic_timer_change_period(usecs);
}

int arm_board_timer_init(u32 usecs)
{
	return generic_timer_init(usecs, IRQ_VIRT_V7_VIRT_TIMER);
}

int arm_board_serial_init(void)
{
	pl01x_init(VIRT_V7_UART0, PL01X_TYPE_1, 115200, 24000000);

	return 0;
}

void arm_board_serial_putc(char ch)
{
	if (ch == '\n') {
		pl01x_putc(VIRT_V7_UART0, PL01X_TYPE_1, '\r');
	}
	pl01x_putc(VIRT_V7_UART0, PL01X_TYPE_1, ch);
}

char arm_board_serial_getc(void)
{
	char ch = pl01x_getc(VIRT_V7_UART0, PL01X_TYPE_1);
	if (ch == '\r') {
		ch = '\n';
	}
	arm_board_serial_putc(ch);
	return ch;
}

char arm_board_serial_mute_getc(void)
{
	char ch = pl01x_getc(VIRT_V7_UART0, PL01X_TYPE_1);
	if (ch == '\r') {
		ch = '\n';
	}
	return ch;
}

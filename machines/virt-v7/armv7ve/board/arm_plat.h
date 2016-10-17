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
 * @file arm_plat.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief Platform Configuration for virt-v7 board
 */
#ifndef __ARM_PLAT_H__
#define __ARM_PLAT_H__

#define VIRT_V7_NOR_FLASH		(0x00000000)
#define VIRT_V7_NOR_FLASH_SIZE		(0x01000000)
#define VIRT_V7_GIC			(0x08000000)
#define VIRT_V7_GIC_SIZE		(0x00020000)
#define VIRT_V7_UART0			(0x09000000)
#define VIRT_V7_VIRTIO_NET		(0x0A000000)
#define VIRT_V7_VIRTIO_NET_SIZE		(0x00001000)
#define VIRT_V7_VIRTIO_BLK		(0x0A001000)
#define VIRT_V7_VIRTIO_BLK_SIZE		(0x00001000)
#define VIRT_V7_VIRTIO_CON		(0x0A002000)
#define VIRT_V7_VIRTIO_CON_SIZE		(0x00001000)
#define VIRT_V7_PCI			(0x10000000)
#define VIRT_V7_PCI_SIZE		(0x30000000)
#define VIRT_V7_RAM0			(0x40000000)
#define VIRT_V7_RAM0_SIZE		(0x06000000)

#define VIRT_V7_GIC_DIST		(VIRT_V7_GIC + 0x00000)
#define	VIRT_V7_GIC_CPU			(VIRT_V7_GIC + 0x10000)

/*
 * Interrupts.
 */
#define IRQ_VIRT_V7_VIRT_TIMER		27
#define IRQ_VIRT_V7_PHYS_TIMER		30

#define IRQ_VIRT_V7_UART0		33
#define IRQ_VIRT_V7_VIRTIO_NET		48
#define IRQ_VIRT_V7_VIRTIO_BLK		49
#define IRQ_VIRT_V7_VIRTIO_CON		50

#define IRQ_VIRT_V7_GIC_START		16
#define NR_IRQS_VIRT_V7			128
#define NR_GIC_VIRT_V7			1

#define IRQ_VIRT_TIMER			IRQ_VIRT_V7_VIRT_TIMER

/*
 * Defines required by common code
 */
#define ARM_PLAT_SPIN_ADDR		(VIRT_V7_RAM0)

#endif

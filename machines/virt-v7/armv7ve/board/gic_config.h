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
 * @file gic_config.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief ARM Generic Interrupt Controller configuration header
 */
#ifndef _GIC_CONFIG_H__
#define _GIC_CONFIG_H__

#include <arm_plat.h>

#define GIC_CPU_BASE		VIRT_V7_GIC_CPU
#define GIC_DIST_BASE		VIRT_V7_GIC_DIST

#define GIC_NR_IRQS		NR_IRQS_VIRT_V7
#define GIC_MAX_NR		NR_GIC_VIRT_V7

#endif

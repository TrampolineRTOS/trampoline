/**
 * Copyright (c) 2010 Anup Patel.
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
 * @file arm_irq.h
 * @author Anup Patel (anup@brainfault.org)
 * @brief header file for ARM interrupts
 */
#ifndef _ARM_IRQ_H__
#define _ARM_IRQ_H__

#include <arm_types.h>

typedef int (*arm_irq_handler_t) (u32 irq_no, struct pt_regs * regs);

#define CPU_IRQ_NR					8

/** IRQ Numbers */
#define ARM_RESET_IRQ					0
#define ARM_UNDEF_INST_IRQ				1
#define ARM_SOFT_IRQ					2
#define ARM_PREFETCH_ABORT_IRQ				3
#define ARM_DATA_ABORT_IRQ				4
#define ARM_NOT_USED_IRQ				5
#define ARM_EXTERNAL_IRQ				6
#define ARM_EXTERNAL_FIQ				7

void arm_irq_setup(void);
void arm_irq_register(u32 irq_no, arm_irq_handler_t hndl);
void arm_irq_enable(void);
void arm_irq_disable(void);
void arm_irq_wfi(void);

#endif

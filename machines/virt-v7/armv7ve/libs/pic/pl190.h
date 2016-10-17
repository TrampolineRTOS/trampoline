/**
 * Copyright (c) 2012 Jean-Christophe Dubois.
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
 * @file pl190.h
 * @author Jean-Christophe Dubois (jcd@tribudubois.net)
 * @brief Versatile Generic Interrupt Controller header
 */
#ifndef __PL190_H__
#define __PL190_H__

#include <arm_types.h>

#define PL190_IRQ_STATUS                  0x00
#define PL190_FIQ_STATUS                  0x04
#define PL190_RAW_STATUS                  0x08
#define PL190_INT_SELECT                  0x0c    /* 1 = FIQ, 0 = IRQ */
#define PL190_INT_ENABLE                  0x10    /* 1 = enable, 0 = disable */
#define PL190_INT_ENABLE_CLEAR            0x14
#define PL190_INT_SOFT                    0x18
#define PL190_INT_SOFT_CLEAR              0x1c
#define PL190_PROTECT                     0x20
#define PL190_VECT_ADDR                   0x30    /* PL190 only */
#define PL190_DEF_VECT_ADDR               0x34    /* PL190 only */

#define PL190_VECT_ADDR0                  0x100   /* 0 to 15 (0..31 PL192) */
#define PL190_VECT_CNTL0                  0x200   /* 0 to 15 (0..31 PL192) */
#define PL190_ITCR                        0x300   /* VIC test control register */

#define PL190_VECT_CNTL_ENABLE            (1 << 5)

#define PL190_PL192_VECT_ADDR             0xF00

int pl190_active_irq(u32 vic_nr);
int pl190_eoi_irq(u32 vic_nr, u32 irq);
int pl190_mask(u32 vic_nr, u32 irq);
int pl190_unmask(u32 vic_nr, u32 irq);
int pl190_cpu_init(u32 vic_nr, virtual_addr_t base);

#endif

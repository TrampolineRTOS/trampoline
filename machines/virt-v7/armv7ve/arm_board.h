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
 * @file arm_board.h
 * @author Jean-Christophe Dubois (jcd@tribudubois.net)
 * @brief ARM Platform misc functions Header
 */
#ifndef _ARM_BOARD_H__
#define _ARM_BOARD_H__

#include <arm_types.h>

void arm_board_reset(void);
void arm_board_init(void);
char *arm_board_name(void);
u32 arm_board_ram_start(void);
u32 arm_board_ram_size(void);
u32 arm_board_flash_addr(void);
u32 arm_board_linux_machine_type(void);
void arm_board_linux_default_cmdline(char *cmdline, u32 cmdline_sz);

u32 arm_board_iosection_count(void);
physical_addr_t arm_board_iosection_addr(int num);

u32 arm_board_pic_nr_irqs(void);
int arm_board_pic_init(void);
u32 arm_board_pic_active_irq(void);
int arm_board_pic_ack_irq(u32 irq);
int arm_board_pic_eoi_irq(u32 irq);
int arm_board_pic_mask(u32 irq);
int arm_board_pic_unmask(u32 irq);

void arm_board_timer_enable(void);
void arm_board_timer_disable(void);
u64 arm_board_timer_irqcount(void);
u64 arm_board_timer_irqdelay(void);
u64 arm_board_timer_timestamp(void);
void arm_board_timer_change_period(u32 usecs);
int arm_board_timer_init(u32 usecs);

int arm_board_serial_init(void);
void arm_board_serial_putc(char ch);
char arm_board_serial_getc(void);
char arm_board_serial_mute_getc(void);

#endif

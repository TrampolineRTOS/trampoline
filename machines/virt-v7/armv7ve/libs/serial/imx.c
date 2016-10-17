/**
 * Copyright (C) 2014 Institut de Recherche Technologique SystemX and OpenWide.
 * Jimmy Durand Wesolowski (jimmy.durand-wesolowski@openwide.fr)
 * All rights reserved.
 * Inspired from pl01x.c, written by Anup Patel.
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
 * @file imx.c
 * @author Jimmy Durand Wesolowski (jimmy.durand-wesolowski@openwide.fr)
 * @brief source file for i.MX serial port driver.
 */

#include <arm_io.h>
#include <arm_math.h>
#include <serial/imx.h>

void imx_putc(u32 base, char ch)
{
	/* Wait until there is space in the FIFO */
	while (!(arm_readw((void*)(base + USR1)) & USR1_TRDY)) {
		;
	}

	/* Send the character */
	arm_writeb(ch, (void*)(base + URTX0));
}

char imx_getc(u32 base)
{
	u16 data;

	/* Wait until there is data in the FIFO */
	while (!(arm_readw((void*)(base + USR2)) & USR2_RDR)) {
		;
	}

	data = arm_readb((void*)(base + URXD0));

	/* Check for an error flag */
	if (data & 0xFF00) {
		/* Clear the error */
		arm_writew(0x8400, (void*)(base + USR1));
		return -1;
	}

	return data;
}

void imx_init(u32 base, u32 baudrate, u32 input_clock)
{
	unsigned int temp;

	/* First, disable everything */
	arm_writew(0x0, (void*)(base + UCR1));
	arm_writew(0x0, (void*)(base + UCR2));

	/*
	 * Set baud rate
	 *
	 * (UBMR + 1) / (UBIR + 1) = input_clock / (16 * BAUD_RATE)
	 * Set UBIR = 0xF:
	 * UBMR + 1 = input_clock / BAUD_RATE
	 */
	temp = arm_udiv32(input_clock, baudrate);
	arm_writew(0xF, (void*)(base + UBIR));
	arm_writew(temp - 1, (void*)(base + UBMR));

	/* Set the UART to be 8 bits, 1 stop bit,
	 * no parity, fifo enabled */
	arm_writel(UCR2_WS | UCR2_TXEN | UCR2_RXEN, (void*)(base + UCR2));

	/* Finally, enable the UART */
	arm_writew(UCR1_UARTEN, (void*)(base + UCR1));
}


/*
 * (c) 2010 Jonathan ILIAS-PILLET <jonathan.ilias@eseo.fr> adapted to Trampoline
 * (c) 2004 Sascha Hauer <sascha@saschahauer.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "imx-regs.h"
#include "clock.h"

#define CONFIG_IMX27
#define UART_PHYS IMX_UART1_BASE

#define URXD0(base) __REG( 0x0 +(base))  /* Receiver Register */
#define URTX0(base) __REG( 0x40 +(base)) /* Transmitter Register */
#define UCR1(base)  __REG( 0x80 +(base)) /* Control Register 1 */
#define UCR2(base)  __REG( 0x84 +(base)) /* Control Register 2 */
#define UCR3(base)  __REG( 0x88 +(base)) /* Control Register 3 */
#define UCR4(base)  __REG( 0x8c +(base)) /* Control Register 4 */
#define UFCR(base)  __REG( 0x90 +(base)) /* FIFO Control Register */
#define USR1(base)  __REG( 0x94 +(base)) /* Status Register 1 */
#define USR2(base)  __REG( 0x98 +(base)) /* Status Register 2 */
#define UESC(base)  __REG( 0x9c +(base)) /* Escape Character Register */
#define UTIM(base)  __REG( 0xa0 +(base)) /* Escape Timer Register */
#define UBIR(base)  __REG( 0xa4 +(base)) /* BRM Incremental Register */
#define UBMR(base)  __REG( 0xa8 +(base)) /* BRM Modulator Register */
#define UBRC(base)  __REG( 0xac +(base)) /* Baud Rate Count Register */
#ifdef CONFIG_IMX27
#define ONEMS(base) __REG( 0xb0 +(base)) /* One Millisecond register (i.MX27) */
#define UTS(base)   __REG( 0xb4 +(base)) /* UART Test Register */
#endif
#ifdef CONFIG_IMX1
#define BIPR1(base) __REG( 0xb0 +(base)) /* Incremental Preset Register 1 */
#define BIPR2(base) __REG( 0xb4 +(base)) /* Incremental Preset Register 2 */
#define BIPR3(base) __REG( 0xb8 +(base)) /* Incremental Preset Register 3 */
#define BIPR4(base) __REG( 0xbc +(base)) /* Incremental Preset Register 4 */
#define BMPR1(base) __REG( 0xc0 +(base)) /* BRM Modulator Register 1 */
#define BMPR2(base) __REG( 0xc4 +(base)) /* BRM Modulator Register 2 */
#define BMPR3(base) __REG( 0xc8 +(base)) /* BRM Modulator Register 3 */
#define BMPR4(base) __REG( 0xcc +(base)) /* BRM Modulator Register 4 */
#define UTS(base)   __REG( 0xd0 +(base)) /* UART Test Register */
#endif
#ifdef CONFIG_IMX31
# define ONEMS(base)	__REG( 0xb0 +(base)) /* One Millisecond register (i.MX27) */
# define UTS(base)	__REG( 0xb4 +(base)) /* UART Test Register */
#endif

/* UART Control Register Bit Fields.*/
#define  URXD_CHARRDY    (1<<15)
#define  URXD_ERR        (1<<14)
#define  URXD_OVRRUN     (1<<13)
#define  URXD_FRMERR     (1<<12)
#define  URXD_BRK        (1<<11)
#define  URXD_PRERR      (1<<10)
#define  UCR1_ADEN       (1<<15) /* Auto dectect interrupt */
#define  UCR1_ADBR       (1<<14) /* Auto detect baud rate */
#define  UCR1_TRDYEN     (1<<13) /* Transmitter ready interrupt enable */
#define  UCR1_IDEN       (1<<12) /* Idle condition interrupt */
#define  UCR1_RRDYEN     (1<<9)	 /* Recv ready interrupt enable */
#define  UCR1_RDMAEN     (1<<8)	 /* Recv ready DMA enable */
#define  UCR1_IREN       (1<<7)	 /* Infrared interface enable */
#define  UCR1_TXMPTYEN   (1<<6)	 /* Transimitter empty interrupt enable */
#define  UCR1_RTSDEN     (1<<5)	 /* RTS delta interrupt enable */
#define  UCR1_SNDBRK     (1<<4)	 /* Send break */
#define  UCR1_TDMAEN     (1<<3)	 /* Transmitter ready DMA enable */
#define  UCR1_UARTCLKEN  (1<<2)	 /* UART clock enabled */
#define  UCR1_DOZE       (1<<1)	 /* Doze */
#define  UCR1_UARTEN     (1<<0)	 /* UART enabled */
#define  UCR2_ESCI     	 (1<<15) /* Escape seq interrupt enable */
#define  UCR2_IRTS  	 (1<<14) /* Ignore RTS pin */
#define  UCR2_CTSC  	 (1<<13) /* CTS pin control */
#define  UCR2_CTS        (1<<12) /* Clear to send */
#define  UCR2_ESCEN      (1<<11) /* Escape enable */
#define  UCR2_PREN       (1<<8)  /* Parity enable */
#define  UCR2_PROE       (1<<7)  /* Parity odd/even */
#define  UCR2_STPB       (1<<6)	 /* Stop */
#define  UCR2_WS         (1<<5)	 /* Word size */
#define  UCR2_RTSEN      (1<<4)	 /* Request to send interrupt enable */
#define  UCR2_TXEN       (1<<2)	 /* Transmitter enabled */
#define  UCR2_RXEN       (1<<1)	 /* Receiver enabled */
#define  UCR2_SRST 	 (1<<0)	 /* SW reset */
#define  UCR3_DTREN 	 (1<<13) /* DTR interrupt enable */
#define  UCR3_PARERREN   (1<<12) /* Parity enable */
#define  UCR3_FRAERREN   (1<<11) /* Frame error interrupt enable */
#define  UCR3_DSR        (1<<10) /* Data set ready */
#define  UCR3_DCD        (1<<9)  /* Data carrier detect */
#define  UCR3_RI         (1<<8)  /* Ring indicator */
#define  UCR3_TIMEOUTEN  (1<<7)  /* Timeout interrupt enable */
#define  UCR3_RXDSEN	 (1<<6)  /* Receive status interrupt enable */
#define  UCR3_AIRINTEN   (1<<5)  /* Async IR wake interrupt enable */
#define  UCR3_AWAKEN	 (1<<4)  /* Async wake interrupt enable */
#define  UCR3_REF25 	 (1<<3)  /* Ref freq 25 MHz (i.MXL / i.MX1) */
#define  UCR3_REF30 	 (1<<2)  /* Ref Freq 30 MHz (i.MXL / i.MX1) */
#define  UCR3_RXDMUXSEL  (1<<2)  /* RXD Muxed input select (i.MX27) */
#define  UCR3_INVT  	 (1<<1)  /* Inverted Infrared transmission */
#define  UCR3_BPEN  	 (1<<0)  /* Preset registers enable */
#define  UCR4_CTSTL_32   (32<<10) /* CTS trigger level (32 chars) */
#define  UCR4_INVR  	 (1<<9)  /* Inverted infrared reception */
#define  UCR4_ENIRI 	 (1<<8)  /* Serial infrared interrupt enable */
#define  UCR4_WKEN  	 (1<<7)  /* Wake interrupt enable */
#define  UCR4_REF16 	 (1<<6)  /* Ref freq 16 MHz */
#define  UCR4_IRSC  	 (1<<5)  /* IR special case */
#define  UCR4_TCEN  	 (1<<3)  /* Transmit complete interrupt enable */
#define  UCR4_BKEN  	 (1<<2)  /* Break condition interrupt enable */
#define  UCR4_OREN  	 (1<<1)  /* Receiver overrun interrupt enable */
#define  UCR4_DREN  	 (1<<0)  /* Recv data ready interrupt enable */
#define  UFCR_RXTL_SHF   0       /* Receiver trigger level shift */
#define  UFCR_RFDIV      (7<<7)  /* Reference freq divider mask */
#define  UFCR_TXTL_SHF   10      /* Transmitter trigger level shift */
#define  USR1_PARITYERR  (1<<15) /* PCONFIG_IMX_SERIAL1arity error interrupt flag */
#define  USR1_RTSS  	 (1<<14) /* RTS pin status */
#define  USR1_TRDY  	 (1<<13) /* Transmitter ready interrupt/dma flag */
#define  USR1_RTSD  	 (1<<12) /* RTS delta */
#define  USR1_ESCF  	 (1<<11) /* Escape seq interrupt flag */
#define  USR1_FRAMERR    (1<<10) /* Frame error interrupt flag */
#define  USR1_RRDY       (1<<9)	 /* Receiver ready interrupt/dma flag */
#define  USR1_TIMEOUT    (1<<7)	 /* Receive timeout interrupt status */
#define  USR1_RXDS  	 (1<<6)	 /* Receiver idle interrupt flag */
#define  USR1_AIRINT	 (1<<5)	 /* Async IR wake interrupt flag */
#define  USR1_AWAKE 	 (1<<4)	 /* Aysnc wake interrupt flag */
#define  USR2_ADET  	 (1<<15) /* Auto baud rate detect complete */
#define  USR2_TXFE  	 (1<<14) /* Transmit buffer FIFO empty */
#define  USR2_DTRF  	 (1<<13) /* DTR edge interrupt flag */
#define  USR2_IDLE  	 (1<<12) /* Idle condition */
#define  USR2_IRINT 	 (1<<8)	 /* Serial infrared interrupt flag */
#define  USR2_WAKE  	 (1<<7)	 /* Wake */
#define  USR2_RTSF  	 (1<<4)	 /* RTS edge interrupt flag */
#define  USR2_TXDC  	 (1<<3)	 /* Transmitter complete */
#define  USR2_BRCD  	 (1<<2)	 /* Break condition */
#define  USR2_ORE        (1<<1)	 /* Overrun error */
#define  USR2_RDR        (1<<0)	 /* Recv data ready */
#define  UTS_FRCPERR	 (1<<13) /* Force parity error */
#define  UTS_LOOP        (1<<12) /* Loop tx and rx */
#define  UTS_TXEMPTY	 (1<<6)	 /* TxFIFO empty */
#define  UTS_RXEMPTY	 (1<<5)	 /* RxFIFO empty */
#define  UTS_TXFULL 	 (1<<4)	 /* TxFIFO full */
#define  UTS_RXFULL 	 (1<<3)	 /* RxFIFO full */
#define  UTS_SOFTRST	 (1<<0)	 /* Software reset */

/*
 * create default values for different platforms
 */
#ifdef CONFIG_IMX1
# define	UCR1_VAL (UCR1_UARTCLKEN)
# define	UCR3_VAL 0
# define	UCR4_VAL (UCR4_CTSTL_32 | UCR4_REF16)
#endif
#ifdef CONFIG_IMX27
# define	UCR1_VAL (UCR1_UARTCLKEN)
# define	UCR3_VAL (0x700 | UCR3_RXDMUXSEL)
# define	UCR4_VAL UCR4_CTSTL_32
#endif
#ifdef CONFIG_IMX31
# define	UCR1_VAL (0)
# define	UCR3_VAL (0x700 | UCR3_RXDMUXSEL)
# define	UCR4_VAL UCR4_CTSTL_32
#endif

static int imx_serial_reffreq(ulong base)
{
	ulong rfdiv;

	rfdiv = (UFCR(base) >> 7) & 7;
	rfdiv = rfdiv < 6 ? 6 - rfdiv : 7;

	return imx_get_perclk1() / rfdiv;
}

/*
 * Initialise the serial port with the given baudrate. The settings
 * are always 8 data bits, no parity, 1 stop bit, no start bits.
 *
 */
int serial_init(void)
{
/*	struct device_d *dev = cdev->dev;
	ulong base = dev->map_base;
*/

	UCR1(UART_PHYS) = UCR1_VAL;
	UCR2(UART_PHYS) = UCR2_WS | UCR2_IRTS;
	UCR3(UART_PHYS) = UCR3_VAL;
	UCR4(UART_PHYS) = UCR4_VAL;
	UESC(UART_PHYS) = 0x0000002B;
	UTIM(UART_PHYS) = 0;
	UBIR(UART_PHYS) = 0;
	UBMR(UART_PHYS) = 0;
	UTS(UART_PHYS)  = 0;

	/* Configure FIFOs */
	UFCR(UART_PHYS) = 0xa81;

#if defined(CONFIG_IMX27) || defined(CONFIG_IMX31)
	ONEMS(UART_PHYS) = imx_serial_reffreq(UART_PHYS) / 1000;
#endif

	/* Set the numerator value minus one of the BRM ratio */
	UBIR(UART_PHYS) = (DEFAULT_BAUDRATE / 100) - 1;
	/* Set the denominator value minus one of the BRM ratio    */
	UBMR(UART_PHYS) = ((imx_serial_reffreq(UART_PHYS) / 1600) - 1);

	/* Enable FIFOs */
	UCR2(UART_PHYS) |= UCR2_SRST | UCR2_RXEN | UCR2_TXEN;

  	/* Clear status flags */
	USR2(UART_PHYS) |= USR2_ADET  |
	          USR2_DTRF  |
	          USR2_IDLE  |
	          USR2_IRINT |
	          USR2_WAKE  |
	          USR2_RTSF  |
	          USR2_BRCD  |
	          USR2_ORE   |
	          USR2_RDR;

  	/* Clear status flags */
	USR1(UART_PHYS) |= USR1_PARITYERR |
	          USR1_RTSD      |
	          USR1_ESCF      |
	          USR1_FRAMERR   |
	          USR1_AIRINT    |
	          USR1_AWAKE;

	UCR1(UART_PHYS) |= UCR1_UARTEN;

	return 0;
}

void serial_putc(const char c)
{
	/* Wait for Tx FIFO not full */
(*((volatile u32 *)(0x10008004))) = 0x0ffff;
	while (UTS(UART_PHYS) & UTS_TXFULL);

        URTX0(UART_PHYS) = c;
(*((volatile u32 *)(0x10008004))) = 0xffffffff;
	/* If \n, also do \r */
	if (c == '\n')
		serial_putc ('\r');
}

int serial_tstc(void)
{
	/* If receive fifo is empty, return false */
	if (UTS(UART_PHYS) & UTS_RXEMPTY)
		return 0;
	return 1;
}

int serial_getc(void)
{
	unsigned char ch;

	while (UTS(UART_PHYS) & UTS_RXEMPTY);

	ch = URXD0(UART_PHYS);

	return ch;
}

void serial_puts (const char *s)
{
       while (*s) {
               serial_putc (*s++);
       }
}

void serial_setbrg(void)
{
	ulong ucr1 = UCR1(UART_PHYS);

	/* disable UART */
	UCR1(UART_PHYS) &= ~UCR1_UARTEN;

	/* Set the numerator value minus one of the BRM ratio */
	UBIR(UART_PHYS) = (DEFAULT_BAUDRATE / 100) - 1;
	/* Set the denominator value minus one of the BRM ratio    */
	UBMR(UART_PHYS) = ((imx_serial_reffreq(UART_PHYS) / 1600) - 1);

	UCR1(UART_PHYS) = ucr1;

	return;
}


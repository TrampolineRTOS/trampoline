/*
 *
 * (c) 2007 Pengutronix, Sascha Hauer <s.hauer@pengutronix.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _IMX_REGS_H
#define _IMX_REGS_H

/* ------------------------------------------------------------------------
 *  Motorola IMX system registers
 * ------------------------------------------------------------------------
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
__extension__ typedef unsigned long long u64;

# ifndef __ASSEMBLY__
# define __REG(x)	(*((volatile u32 *)(x)))
# define __REG16(x)     (*(volatile u16 *)(x))
# define __REG2(x,y)    (*(volatile u32 *)((u32)&__REG(x) + (y)))

extern void imx_gpio_mode (int gpio_mode);

# else
#  define __REG(x) (x)
#  define __REG16(x) (x)
#  define __REG2(x,y) ((x)+(y))
#endif

#define IMX_IO_BASE		0x10000000

#define IMX_AIPI1_BASE             (0x00000 + IMX_IO_BASE)
#define IMX_WDT_BASE               (0x02000 + IMX_IO_BASE)
#define IMX_TIM1_BASE              (0x03000 + IMX_IO_BASE)
#define IMX_TIM2_BASE              (0x04000 + IMX_IO_BASE)
#define IMX_TIM3_BASE              (0x05000 + IMX_IO_BASE)
#define IMX_UART1_BASE             (0x0a000 + IMX_IO_BASE)
#define IMX_UART2_BASE             (0x0b000 + IMX_IO_BASE)
#define IMX_UART3_BASE             (0x0c000 + IMX_IO_BASE)
#define IMX_UART4_BASE             (0x0d000 + IMX_IO_BASE)
#define IMX_I2C1_BASE              (0x12000 + IMX_IO_BASE)
#define IMX_GPIO_BASE              (0x15000 + IMX_IO_BASE)
#define IMX_TIM4_BASE              (0x19000 + IMX_IO_BASE)
#define IMX_TIM5_BASE              (0x1a000 + IMX_IO_BASE)
#define IMX_UART5_BASE             (0x1b000 + IMX_IO_BASE)
#define IMX_UART6_BASE             (0x1c000 + IMX_IO_BASE)
#define IMX_I2C2_BASE              (0x1D000 + IMX_IO_BASE)
#define IMX_TIM6_BASE              (0x1f000 + IMX_IO_BASE)
#define IMX_AIPI2_BASE             (0x20000 + IMX_IO_BASE)
#define IMX_PLL_BASE               (0x27000 + IMX_IO_BASE)
#define IMX_SYSTEM_CTL_BASE        (0x27800 + IMX_IO_BASE)
#define IMX_IIM_BASE               (0x28000 + IMX_IO_BASE)
#define IMX_FEC_BASE               (0x2b000 + IMX_IO_BASE)

#define IMX_ESD_BASE               (0xD8001000)
#define IMX_WEIM_BASE              (0xD8002000)


/* AIPI */
#define AIPI1_PSR0	__REG(IMX_AIPI1_BASE + 0x00)
#define AIPI1_PSR1	__REG(IMX_AIPI1_BASE + 0x04)
#define AIPI2_PSR0	__REG(IMX_AIPI2_BASE + 0x00)
#define AIPI2_PSR1	__REG(IMX_AIPI2_BASE + 0x04)

/* System Control */
#define FMCR	__REG(IMX_SYSTEM_CTL_BASE + 0x14)
#define GPCR	__REG(IMX_SYSTEM_CTL_BASE + 0x18)
#define WBCR	__REG(IMX_SYSTEM_CTL_BASE + 0x1C)
#define DSCR1	__REG(IMX_SYSTEM_CTL_BASE + 0x20)
#define DSCR2	__REG(IMX_SYSTEM_CTL_BASE + 0x24)
#define DSCR3	__REG(IMX_SYSTEM_CTL_BASE + 0x28)
#define DSCR4	__REG(IMX_SYSTEM_CTL_BASE + 0x2C)
#define DSCR5	__REG(IMX_SYSTEM_CTL_BASE + 0x30)
#define DSCR6	__REG(IMX_SYSTEM_CTL_BASE + 0x34)
#define DSCR7	__REG(IMX_SYSTEM_CTL_BASE + 0x38)
#define DSCR8	__REG(IMX_SYSTEM_CTL_BASE + 0x3C)
#define DSCR9	__REG(IMX_SYSTEM_CTL_BASE + 0x40)
#define DSCR10	__REG(IMX_SYSTEM_CTL_BASE + 0x44)
#define DSCR11	__REG(IMX_SYSTEM_CTL_BASE + 0x48)
#define DSCR12	__REG(IMX_SYSTEM_CTL_BASE + 0x4C)
#define DSCR13	__REG(IMX_SYSTEM_CTL_BASE + 0x50)
#define PSCR	__REG(IMX_SYSTEM_CTL_BASE + 0x54)
#define PMCR	__REG(IMX_SYSTEM_CTL_BASE + 0x58)
#define DCVR0	__REG(IMX_SYSTEM_CTL_BASE + 0x60)
#define DCVR1	__REG(IMX_SYSTEM_CTL_BASE + 0x64)
#define DCVR2	__REG(IMX_SYSTEM_CTL_BASE + 0x68)
#define DCVR3	__REG(IMX_SYSTEM_CTL_BASE + 0x6C)

/* FMCR System Control bit definition*/
#define UART4_RXD_CTL 	(1<<25)		
#define UART4_RTS_CTL 	(1<<24)		
#define KP_COL6_CTL 	(1<<18)		
#define KP_ROW7_CTL 	(1<<17)		
#define KP_ROW6_CTL 	(1<<16)		
#define PC_WAIT_B_CTL 	(1<<14)		 
#define PC_READY_CTL 	(1<<13)		
#define PC_VS1_CTL 	    (1<<12)		
#define PC_VS2_CTL 	    (1<<11)		
#define PC_BVD1_CTL 	(1<<10)		
#define PC_BVD2_CTL 	(1<<9)		
#define IOS16_CTL 	    (1<<8)		
#define NF_FMS 	        (1<<5)		
#define NF_16BIT_SEL 	(1<<4)		
#define SLCDC_SEL 	    (1<<2)		
#define SDCS1_SEL 	    (1<<1)		
#define SDCS0_SEL 	    (1<<0)	


/* Chip Select Registers */
#define CS0U __REG(IMX_WEIM_BASE + 0x00) /* Chip Select 0 Upper Register    */
#define CS0L __REG(IMX_WEIM_BASE + 0x04) /* Chip Select 0 Lower Register    */
#define CS0A __REG(IMX_WEIM_BASE + 0x08) /* Chip Select 0 Addition Register */
#define CS1U __REG(IMX_WEIM_BASE + 0x10) /* Chip Select 1 Upper Register    */
#define CS1L __REG(IMX_WEIM_BASE + 0x14) /* Chip Select 1 Lower Register    */
#define CS1A __REG(IMX_WEIM_BASE + 0x18) /* Chip Select 1 Addition Register */
#define CS2U __REG(IMX_WEIM_BASE + 0x20) /* Chip Select 2 Upper Register    */
#define CS2L __REG(IMX_WEIM_BASE + 0x24) /* Chip Select 2 Lower Register    */
#define CS2A __REG(IMX_WEIM_BASE + 0x28) /* Chip Select 2 Addition Register */
#define CS3U __REG(IMX_WEIM_BASE + 0x30) /* Chip Select 3 Upper Register    */
#define CS3L __REG(IMX_WEIM_BASE + 0x34) /* Chip Select 3 Lower Register    */
#define CS3A __REG(IMX_WEIM_BASE + 0x38) /* Chip Select 3 Addition Register */
#define CS4U __REG(IMX_WEIM_BASE + 0x40) /* Chip Select 4 Upper Register    */
#define CS4L __REG(IMX_WEIM_BASE + 0x44) /* Chip Select 4 Lower Register    */
#define CS4A __REG(IMX_WEIM_BASE + 0x48) /* Chip Select 4 Addition Register */
#define CS5U __REG(IMX_WEIM_BASE + 0x50) /* Chip Select 5 Upper Register    */
#define CS5L __REG(IMX_WEIM_BASE + 0x54) /* Chip Select 5 Lower Register    */
#define CS5A __REG(IMX_WEIM_BASE + 0x58) /* Chip Select 5 Addition Register */
#define EIM  __REG(IMX_WEIM_BASE + 0x60) /* WEIM Configuration Register     */

/* SDRAM Controller registers */
#define ESDCTL0 __REG(IMX_ESD_BASE + 0x00) /* Enhanced SDRAM Control Register 0       */
#define ESDCFG0 __REG(IMX_ESD_BASE + 0x04) /* Enhanced SDRAM Configuration Register 0 */
#define ESDCTL1 __REG(IMX_ESD_BASE + 0x08) /* Enhanced SDRAM Control Register 1       */
#define ESDCFG1 __REG(IMX_ESD_BASE + 0x0C) /* Enhanced SDRAM Configuration Register 1 */
#define ESDMISC __REG(IMX_ESD_BASE + 0x10) /* Enhanced SDRAM Miscellanious Register   */

/* Watchdog Registers*/
#define WCR  __REG16(IMX_WDT_BASE + 0x00) /* Watchdog Control Register */
#define WSR  __REG16(IMX_WDT_BASE + 0x04) /* Watchdog Service Register */
#define WSTR __REG16(IMX_WDT_BASE + 0x08) /* Watchdog Status Register  */

/* important definition of some bits of WCR */
#define WCR_WDE 0x04

/* PLL registers */
#define CSCR		__REG(IMX_PLL_BASE + 0x00) /* Clock Source Control Register       */
#define MPCTL0		__REG(IMX_PLL_BASE + 0x04) /* MCU PLL Control Register 0          */
#define MPCTL1		__REG(IMX_PLL_BASE + 0x08) /* MCU PLL Control Register 1          */
#define SPCTL0		__REG(IMX_PLL_BASE + 0x0c) /* System PLL Control Register 0       */
#define SPCTL1		__REG(IMX_PLL_BASE + 0x10) /* System PLL Control Register 1       */
#define OSC26MCTL	__REG(IMX_PLL_BASE + 0x14) /* Oscillator 26M Register             */
#define PCDR0		__REG(IMX_PLL_BASE + 0x18) /* Peripheral Clock Divider Register 0 */
#define PCDR1		__REG(IMX_PLL_BASE + 0x1c) /* Peripheral Clock Divider Register 1 */
#define PCCR0		__REG(IMX_PLL_BASE + 0x20) /* Peripheral Clock Control Register 0 */
#define PCCR1		__REG(IMX_PLL_BASE + 0x24) /* Peripheral Clock Control Register 1 */
#define CCSR		__REG(IMX_PLL_BASE + 0x28) /* Clock Control Status Register       */

#define CSCR_MPEN		(1 << 0)
#define CSCR_SPEN		(1 << 1)
#define CSCR_FPM_EN		(1 << 2)
#define CSCR_OSC26M_DIS		(1 << 3)
#define CSCR_OSC26M_DIV1P5	(1 << 4)
#define CSCR_AHB_DIV
#define CSCR_ARM_DIV
#define CSCR_ARM_SRC_MPLL	(1 << 15)
#define CSCR_MCU_SEL		(1 << 16)
#define CSCR_SP_SEL		(1 << 17)
#define CSCR_MPLL_RESTART	(1 << 18)
#define CSCR_SPLL_RESTART	(1 << 19)
#define CSCR_MSHC_SEL		(1 << 20)
#define CSCR_H264_SEL		(1 << 21)
#define CSCR_SSI1_SEL		(1 << 22)
#define CSCR_SSI2_SEL		(1 << 23)
#define CSCR_SD_CNT
#define CSCR_USB_DIV
#define CSCR_UPDATE_DIS		(1 << 31)

#define MPCTL1_BRMO		(1 << 6)
#define MPCTL1_LF		(1 << 15)

#define PCCR0_SSI2_EN	(1 << 0)
#define PCCR0_SSI1_EN	(1 << 1)
#define PCCR0_SLCDC_EN	(1 << 2)
#define PCCR0_SDHC3_EN	(1 << 3)
#define PCCR0_SDHC2_EN	(1 << 4)
#define PCCR0_SDHC1_EN	(1 << 5)
#define PCCR0_SDC_EN	(1 << 6)
#define PCCR0_SAHARA_EN	(1 << 7)
#define PCCR0_RTIC_EN	(1 << 8)
#define PCCR0_RTC_EN	(1 << 9)
#define PCCR0_PWM_EN	(1 << 11)
#define PCCR0_OWIRE_EN	(1 << 12)
#define PCCR0_MSHC_EN	(1 << 13)
#define PCCR0_LCDC_EN	(1 << 14)
#define PCCR0_KPP_EN	(1 << 15)
#define PCCR0_IIM_EN	(1 << 16)
#define PCCR0_I2C2_EN	(1 << 17)
#define PCCR0_I2C1_EN	(1 << 18)
#define PCCR0_GPT6_EN	(1 << 19)
#define PCCR0_GPT5_EN	(1 << 20)
#define PCCR0_GPT4_EN	(1 << 21)
#define PCCR0_GPT3_EN	(1 << 22)
#define PCCR0_GPT2_EN	(1 << 23)
#define PCCR0_GPT1_EN	(1 << 24)
#define PCCR0_GPIO_EN	(1 << 25)
#define PCCR0_FEC_EN	(1 << 26)
#define PCCR0_EMMA_EN	(1 << 27)
#define PCCR0_DMA_EN	(1 << 28)
#define PCCR0_CSPI3_EN	(1 << 29)
#define PCCR0_CSPI2_EN	(1 << 30)
#define PCCR0_CSPI1_EN	(1 << 31)

#define PCCR1_MSHC_BAUDEN	(1 << 2)
#define PCCR1_NFC_BAUDEN	(1 << 3)
#define PCCR1_SSI2_BAUDEN	(1 << 4)
#define PCCR1_SSI1_BAUDEN	(1 << 5)
#define PCCR1_H264_BAUDEN	(1 << 6)
#define PCCR1_PERCLK4_EN	(1 << 7)
#define PCCR1_PERCLK3_EN	(1 << 8)
#define PCCR1_PERCLK2_EN	(1 << 9)
#define PCCR1_PERCLK1_EN	(1 << 10)
#define PCCR1_HCLK_USB		(1 << 11)
#define PCCR1_HCLK_SLCDC	(1 << 12)
#define PCCR1_HCLK_SAHARA	(1 << 13)
#define PCCR1_HCLK_RTIC		(1 << 14)
#define PCCR1_HCLK_LCDC		(1 << 15)
#define PCCR1_HCLK_H264		(1 << 16)
#define PCCR1_HCLK_FEC		(1 << 17)
#define PCCR1_HCLK_EMMA		(1 << 18)
#define PCCR1_HCLK_EMI		(1 << 19)
#define PCCR1_HCLK_DMA		(1 << 20)
#define PCCR1_HCLK_CSI		(1 << 21)
#define PCCR1_HCLK_BROM		(1 << 22)
#define PCCR1_HCLK_ATA		(1 << 23)
#define PCCR1_WDT_EN		(1 << 24)
#define PCCR1_USB_EN		(1 << 25)
#define PCCR1_UART6_EN		(1 << 26)
#define PCCR1_UART5_EN		(1 << 27)
#define PCCR1_UART4_EN		(1 << 28)
#define PCCR1_UART3_EN		(1 << 29)
#define PCCR1_UART2_EN		(1 << 30)
#define PCCR1_UART1_EN		(1 << 31)

/* SDRAM Controller registers bitfields */
#define ESDCTL_PRCT(x)		(((x) & 3f) << 0)
#define ESDCTL_BL		(1 << 7)
#define ESDCTL_FP		(1 << 8)
#define ESDCTL_PWDT(x)		(((x) & 3) << 10)
#define ESDCTL_SREFR(x)		(((x) & 7) << 13)
#define ESDCTL_DSIZ_16_UPPER	(0 << 16)
#define ESDCTL_DSIZ_16_LOWER	(0 << 16)
#define ESDCTL_DSIZ_32		(0 << 16)
#define ESDCTL_COL8		(0 << 20)
#define ESDCTL_COL9		(1 << 20)
#define ESDCTL_COL10		(2 << 20)
#define ESDCTL_ROW11		(0 << 24)
#define ESDCTL_ROW12		(1 << 24)
#define ESDCTL_ROW13		(2 << 24)
#define ESDCTL_ROW14		(3 << 24)
#define ESDCTL_ROW15		(4 << 24)
#define ESDCTL_SP		(1 << 27)
#define ESDCTL_SMODE_NORMAL	(0 << 28)
#define ESDCTL_SMODE_PRECHAGRE	(1 << 28)
#define ESDCTL_SMODE_AUTO_REF	(2 << 28)
#define ESDCTL_SMODE_LOAD_MODE	(3 << 28)
#define ESDCTL_SMODE_MAN_REF	(4 << 28)
#define ESDCTL_SDE		(1 << 31)

#define ESDCFG_TRC(x)		(((x) & 0xf) << 0)
#define ESDCFG_TRCD(x)		(((x) & 0x7) << 4)
#define ESDCFG_TCAS(x)		(((x) & 0x3) << 8)
#define ESDCFG_TRRD(x)		(((x) & 0x3) << 10)
#define ESDCFG_TRAS(x)		(((x) & 0x7) << 12)
#define ESDCFG_TWR		(1 << 15)
#define ESDCFG_TMRD(x)		(((x) & 0x3) << 16)
#define ESDCFG_TRP(x)		(((x) & 0x3) << 18)
#define ESDCFG_TWTR		(1 << 20)
#define ESDCFG_TXP(x)		(((x) & 0x3) << 21)

#define ESDMISC_RST		(1 << 1)
#define ESDMISC_MDDREN		(1 << 2)
#define ESDMISC_MDDR_DL_RST	(1 << 3)
#define ESDMISC_MDDR_MDIS	(1 << 4)
#define ESDMISC_LHD		(1 << 5)
#define ESDMISC_MA10_SHARE	(1 << 6)
#define ESDMISC_SDRAM_RDY	(1 << 31)

#define PC5_PF_I2C2_DATA	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 5)
#define PC6_PF_I2C2_CLK		(GPIO_PORTC | GPIO_OUT | GPIO_PF | 6)
#define PC7_PF_USBOTG_DATA5	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 7)
#define PC8_PF_USBOTG_DATA6	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 8)
#define PC9_PF_USBOTG_DATA0	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 9)
#define PC10_PF_USBOTG_DATA2	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 10)
#define PC11_PF_USBOTG_DATA1	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 11)
#define PC12_PF_USBOTG_DATA4	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 12)
#define PC13_PF_USBOTG_DATA3	(GPIO_PORTC | GPIO_OUT | GPIO_PF | 13)

#define PD0_AIN_FEC_TXD0	(GPIO_PORTD | GPIO_OUT | GPIO_AIN | 0)
#define PD1_AIN_FEC_TXD1	(GPIO_PORTD | GPIO_OUT | GPIO_AIN | 1)
#define PD2_AIN_FEC_TXD2	(GPIO_PORTD | GPIO_OUT | GPIO_AIN | 2)
#define PD3_AIN_FEC_TXD3	(GPIO_PORTD | GPIO_OUT | GPIO_AIN | 3)
#define PD4_AOUT_FEC_RX_ER	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 4)
#define PD5_AOUT_FEC_RXD1	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 5)
#define PD6_AOUT_FEC_RXD2	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 6)
#define PD7_AOUT_FEC_RXD3	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 7)
#define PD8_AF_FEC_MDIO		(GPIO_PORTD | GPIO_IN | GPIO_AF | 8)
#define PD9_AIN_FEC_MDC		(GPIO_PORTD | GPIO_OUT | GPIO_AIN | 9)
#define PD10_AOUT_FEC_CRS	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 10)
#define PD11_AOUT_FEC_TX_CLK	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 11)
#define PD12_AOUT_FEC_RXD0	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 12)
#define PD13_AOUT_FEC_RX_DV	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 13)
#define PD14_AOUT_FEC_CLR	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 14)
#define PD15_AOUT_FEC_COL	(GPIO_PORTD | GPIO_IN | GPIO_AOUT | 15)
#define PD16_AIN_FEC_TX_ER	(GPIO_PORTD | GPIO_OUT | GPIO_AIN | 16)
#define PF23_AIN_FEC_TX_EN	(GPIO_PORTF | GPIO_OUT | GPIO_AIN | 23)

#define PE0_PF_USBOTG_NXT	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 0)
#define PE1_PF_USBOTG_STP	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 1)
#define PE2_PF_USBOTG_DIR	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 2)
#define PE3_PF_UART2_CTS	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 3)
#define PE4_PF_UART2_RTS	(GPIO_PORTE | GPIO_IN  | GPIO_PF | 4)
#define PE6_PF_UART2_TXD	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 6)
#define PE7_PF_UART2_RXD	(GPIO_PORTE | GPIO_IN  | GPIO_PF | 7)
#define PE8_PF_UART3_TXD	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 8)
#define PE9_PF_UART3_RXD	(GPIO_PORTE | GPIO_IN  | GPIO_PF | 9)
#define PE10_PF_UART3_CTS	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 10)
#define PE11_PF_UART3_RTS	(GPIO_PORTE | GPIO_IN  | GPIO_PF | 11)
#define PE12_PF_UART1_TXD	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 12)
#define PE13_PF_UART1_RXD	(GPIO_PORTE | GPIO_IN  | GPIO_PF | 13)
#define PE14_PF_UART1_CTS	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 14)
#define PE15_PF_UART1_RTS	(GPIO_PORTE | GPIO_IN  | GPIO_PF | 15)
#define PD17_PF_I2C_DATA	(GPIO_PORTD | GPIO_OUT | GPIO_PF | 17)
#define PD18_PF_I2C_CLK		(GPIO_PORTD | GPIO_OUT | GPIO_PF | 18)
#define PE24_PF_USBOTG_CLK	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 24)
#define PE25_PF_USBOTG_DATA7	(GPIO_PORTE | GPIO_OUT | GPIO_PF | 25)

/*
 * Definitions for the clocksource driver
 */
/* Part 1: Registers */
# define GPT_TCTL   0x00
# define GPT_TPRER  0x04
# define GPT_TCMP   0x08
# define GPT_TCR    0x0c
# define GPT_TCN    0x10
# define GPT_TSTAT  0x14

/* Part 2: Bitfields */
#define TCTL_SWR       (1<<15) /* Software reset */
#define TCTL_FRR       (1<<8)  /* Freerun / restart */
#define TCTL_CAP       (3<<6)  /* Capture Edge */
#define TCTL_OM        (1<<5)  /* output mode */
#define TCTL_IRQEN     (1<<4)  /* interrupt enable */
#define TCTL_CLKSOURCE (1)     /* Clock source bit position */
#define TCTL_TEN       (1)     /* Timer enable */
#define TPRER_PRES     (0xff)  /* Prescale */
#define TSTAT_CAPT     (1<<1)  /* Capture event */
#define TSTAT_COMP     (1)     /* Compare event */

/*
 *  GPIO Module and I/O Multiplexer
 *  x = 0..3 for reg_A, reg_B, reg_C, reg_D
 *
 *  i.MX1 and i.MXL: 0 <= x <= 3
 *  i.MX27         : 0 <= x <= 5
 */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define DDIR(x)    __REG2(IMX_GPIO_BASE + 0x00, ((x) & 7) << 8)
#define OCR1(x)    __REG2(IMX_GPIO_BASE + 0x04, ((x) & 7) << 8)
#define OCR2(x)    __REG2(IMX_GPIO_BASE + 0x08, ((x) & 7) << 8)
#define ICONFA1(x) __REG2(IMX_GPIO_BASE + 0x0c, ((x) & 7) << 8)
#define ICONFA2(x) __REG2(IMX_GPIO_BASE + 0x10, ((x) & 7) << 8)
#define ICONFB1(x) __REG2(IMX_GPIO_BASE + 0x14, ((x) & 7) << 8)
#define ICONFB2(x) __REG2(IMX_GPIO_BASE + 0x18, ((x) & 7) << 8)
#define DR(x)      __REG2(IMX_GPIO_BASE + 0x1c, ((x) & 7) << 8)
#define GIUS(x)    __REG2(IMX_GPIO_BASE + 0x20, ((x) & 7) << 8)
#define SSR(x)     __REG2(IMX_GPIO_BASE + 0x24, ((x) & 7) << 8)
#define ICR1(x)    __REG2(IMX_GPIO_BASE + 0x28, ((x) & 7) << 8)
#define ICR2(x)    __REG2(IMX_GPIO_BASE + 0x2c, ((x) & 7) << 8)
#define IMR(x)     __REG2(IMX_GPIO_BASE + 0x30, ((x) & 7) << 8)
#define ISR(x)     __REG2(IMX_GPIO_BASE + 0x34, ((x) & 7) << 8)
#define GPR(x)     __REG2(IMX_GPIO_BASE + 0x38, ((x) & 7) << 8)
#define SWR(x)     __REG2(IMX_GPIO_BASE + 0x3c, ((x) & 7) << 8)
#define PUEN(x)    __REG2(IMX_GPIO_BASE + 0x40, ((x) & 7) << 8)

#define GPIO_PIN_MASK 0x1f

#define GPIO_PORT_SHIFT 5
#define GPIO_PORT_MASK (0x7 << GPIO_PORT_SHIFT)

#define GPIO_PORTA (PORTA << GPIO_PORT_SHIFT)
#define GPIO_PORTB (PORTB << GPIO_PORT_SHIFT)
#define GPIO_PORTC (PORTC << GPIO_PORT_SHIFT)
#define GPIO_PORTD (PORTD << GPIO_PORT_SHIFT)
#define GPIO_PORTE (PORTE << GPIO_PORT_SHIFT)
#define GPIO_PORTF (PORTF << GPIO_PORT_SHIFT)

#define GPIO_OUT   (1 << 8)
#define GPIO_IN    (0 << 8)
#define GPIO_PUEN  (1 << 9)

#define GPIO_PF    (1 << 10)
#define GPIO_AF    (1 << 11)

#define GPIO_OCR_SHIFT 12
#define GPIO_OCR_MASK (3 << GPIO_OCR_SHIFT)
#define GPIO_AIN   (0 << GPIO_OCR_SHIFT)
#define GPIO_BIN   (1 << GPIO_OCR_SHIFT)
#define GPIO_CIN   (2 << GPIO_OCR_SHIFT)
#define GPIO_GPIO  (3 << GPIO_OCR_SHIFT)

#define GPIO_AOUT_SHIFT 14
#define GPIO_AOUT_MASK (3 << GPIO_AOUT_SHIFT)
#define GPIO_AOUT     (0 << GPIO_AOUT_SHIFT)
#define GPIO_AOUT_ISR (1 << GPIO_AOUT_SHIFT)
#define GPIO_AOUT_0   (2 << GPIO_AOUT_SHIFT)
#define GPIO_AOUT_1   (3 << GPIO_AOUT_SHIFT)

#define GPIO_BOUT_SHIFT 16
#define GPIO_BOUT_MASK (3 << GPIO_BOUT_SHIFT)
#define GPIO_BOUT      (0 << GPIO_BOUT_SHIFT)
#define GPIO_BOUT_ISR  (1 << GPIO_BOUT_SHIFT)
#define GPIO_BOUT_0    (2 << GPIO_BOUT_SHIFT)
#define GPIO_BOUT_1    (3 << GPIO_BOUT_SHIFT)

/* IIM Control Registers */
#define IIM_STAT	__REG(IMX_IIM_BASE + 0x00)
#define IIM_STAT_BUSY	(1 << 7)
#define IIM_STAT_PRGD	(1 << 1)
#define IIM_STAT_SNSD	(1 << 0)
#define IIM_STATM	__REG(IMX_IIM_BASE + 0x04)
#define IIM_ERR		__REG(IMX_IIM_BASE + 0x08)
#define IIM_ERR_PRGE	(1 << 7)
#define IIM_ERR_WPE	(1 << 6)
#define IIM_ERR_OPE	(1 << 5)
#define IIM_ERR_RPE	(1 << 4)
#define IIM_ERR_WLRE	(1 << 3)
#define IIM_ERR_SNSE	(1 << 2)
#define IIM_ERR_PARITYE	(1 << 1)
#define IIM_EMASK	__REG(IMX_IIM_BASE + 0x0C)
#define IIM_FCTL	__REG(IMX_IIM_BASE + 0x10)
#define IIM_UA		__REG(IMX_IIM_BASE + 0x14)
#define IIM_LA		__REG(IMX_IIM_BASE + 0x18)
#define IIM_SDAT	__REG(IMX_IIM_BASE + 0x1C)
#define IIM_PREV	__REG(IMX_IIM_BASE + 0x20)
#define IIM_SREV	__REG(IMX_IIM_BASE + 0x24)
#define IIM_PROG_P	__REG(IMX_IIM_BASE + 0x28)
#define IIM_SCS0	__REG(IMX_IIM_BASE + 0x2C)
#define IIM_SCS1	__REG(IMX_IIM_BASE + 0x30)
#define IIM_SCS2	__REG(IMX_IIM_BASE + 0x34)
#define IIM_SCS3	__REG(IMX_IIM_BASE + 0x38)
#define IIM_BANK_AREA	IMX_IIM_BASE + 0x800
#define IIM_BANK_REG(x,y) __REG2(IIM_BANK_AREA + 0x400 * x, y<<2)
/* Definitions for i.MX27 TO2 */
#define IIM0_MAC		5
#define IIM0_SCC_KEY		11
#define IIM1_SUID		1


#endif				/* _IMX_REGS_H */


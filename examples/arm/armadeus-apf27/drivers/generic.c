/*
 *  Copyright (c) 2008 Eric Jarrige <eric.jarrige@armadeus.org>
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

//#include <common.h>
#include "config_apf27.h"
#include "imx-regs.h"
#include "clock.h"

/*
#include <asm-generic/div64.h>
#include <init.h>
*/
/*
 *  get the system pll clock in Hz
 *
 *                  mfi + mfn / (mfd +1)
 *  f = 2 * f_ref * --------------------
 *                        pd + 1
 */
unsigned int imx_decode_pll(unsigned int pll, unsigned int f_ref)
{
/*	unsigned long long ll;
	unsigned int quot;
*/
	unsigned int mfi = (pll >> 10) & 0xf;
	unsigned int mfn = pll & 0x3ff;
	unsigned int mfd = (pll >> 16) & 0x3ff;
	unsigned int pd =  (pll >> 26) & 0xf;

	mfi = mfi <= 5 ? 5 : mfi;

/*	ll = 2 * (unsigned long long)f_ref * ( (mfi << 16) + (mfn << 16) / (mfd + 1));
	quot = (pd + 1) * (1 << 16);
	ll += quot / 2;
	do_div(ll, quot);
	return (unsigned int) ll;*/
	return (2*(u64)f_ref* (mfi*(mfd+1) + mfn))/((mfd+1)*(pd+1));
}

static ulong clk_in_32k(void)
{
	return 1024 * CFG_OSC32;
}

static ulong clk_in_26m(void)
{
	if (CSCR & CSCR_OSC26M_DIV1P5) {
		/* divide by 1.5 */
		return 26000000 / 1.5;
	} else {
		/* divide by 1 */
		return 26000000;
	}
}

ulong imx_get_mpllclk(void)
{
	ulong cscr = CSCR;
	ulong fref;

	if (cscr & CSCR_MCU_SEL)
		fref = clk_in_26m();
	else
		fref = clk_in_32k();

	return imx_decode_pll(MPCTL0, fref);
}

ulong imx_get_armclk(void)
{
	ulong cscr = CSCR;
	ulong fref = imx_get_mpllclk();
	ulong div;

	if (!(cscr & CSCR_ARM_SRC_MPLL))
		fref = (fref * 2) / 3;

	div = ((cscr >> 12) & 0x3) + 1;

	return fref / div;
}

ulong imx_get_ahbclk(void)
{
	ulong cscr = CSCR;
	ulong fref = imx_get_mpllclk();
	ulong div;

	div = ((cscr >> 8) & 0x3) + 1;

	return fref * 2 / 3 / div;

}

ulong imx_get_spllclk(void)
{
	ulong cscr = CSCR;
	ulong fref;

	if (cscr & CSCR_SP_SEL)
		fref = clk_in_26m();
	else
		fref = clk_in_32k();

	return imx_decode_pll(SPCTL0, fref);
}

static ulong imx_get_usbclk(void)
{
        return (imx_get_spllclk() / (((CSCR >> 28) & 0x07) + 1));
}

static ulong imx_get_nfcclk(void)
{
        return (imx_get_ahbclk() / (((PCDR0 >> 6) & 0x0f) + 1));
}

static ulong imx_get_mshcclk(void)
{
        return (imx_get_mpllclk() * 2 / (((PCDR0 >> 0) & 0x3f) + 1) / 3);
}

static ulong imx_get_h264clk(void)
{
        return ((imx_get_mpllclk() * 4 ) / (((PCDR0 >> 10) & 0x3f) + 4) / 3);
}

static ulong imx_get_ssi1clk(void)
{
        return ((imx_get_mpllclk() * 4 ) / (((PCDR0 >> 16) & 0x3f) + 4) / 3);
}

static ulong imx_get_ssi2clk(void)
{
        return ((imx_get_mpllclk() * 4) / (((PCDR0 >> 26) & 0x3f) + 4) / 3);
}

static ulong imx_decode_perclk(ulong div)
{
        return (imx_get_mpllclk() * 2) / (div * 3);
}

ulong imx_get_perclk1(void)
{
	return imx_decode_perclk((PCDR1 & 0x3f) + 1);
}

ulong imx_get_perclk2(void)
{
	return imx_decode_perclk(((PCDR1 >> 8) & 0x3f) + 1);
}

ulong imx_get_perclk3(void)
{
	return imx_decode_perclk(((PCDR1 >> 16) & 0x3f) + 1);
}

ulong imx_get_perclk4(void)
{
	return imx_decode_perclk(((PCDR1 >> 24) & 0x3f) + 1);
}

int imx_dump_clocks(void)
{
#if defined CONFIG_HAVE_STDIO
	printf("mpll   : %10ld Hz\n", imx_get_mpllclk());
	printf("spll   : %10ld Hz\n", imx_get_spllclk());
	printf("arm    : %10ld Hz\n", imx_get_armclk());
	printf("hclk   : %10ld Hz\n", imx_get_ahbclk());
	printf("perclk1: %10ld Hz\n", imx_get_perclk1());
	printf("perclk2: %10ld Hz\n", imx_get_perclk2());
	printf("perclk3: %10ld Hz\n", imx_get_perclk3());
	printf("perclk4: %10ld Hz\n", imx_get_perclk4());
	printf("usbclk : %10ld Hz\n", imx_get_usbclk());
	printf("nfcclk : %10ld Hz\n", imx_get_nfcclk());
	printf("mshcclk: %10ld Hz\n", imx_get_mshcclk());
	printf("h264clk: %10ld Hz\n", imx_get_h264clk());
	printf("ssi1clk: %10ld Hz\n", imx_get_ssi1clk());
	printf("ssi2clk: %10ld Hz\n", imx_get_ssi2clk());
	printf("clkin26: %10ld Hz\n", clk_in_26m());
	printf("clkin32: %10d Hz\n", CFG_OSC32);
	printf("ESDCTL0: %#x ESDCTL1: %#x\n", ESDCTL0, ESDCTL1);
	printf("ESDCFG0: %#x ESDCFG1: %#x\n", ESDCFG0,ESDCFG1);
	printf("SDmdreg: %#x\n", CFG_SDRAM_1_BASE+CFG_SDRAM_MODE_REGISTER_VAL);
	printf("SDemdreg: %#x\n", CFG_SDRAM_1_BASE+CFG_SDRAM_EXT_MODE_REGISTER_VAL);
	printf("SDprech: %#x\n", CFG_SDRAM_PRECHARGE_ALL_VAL);
	printf("SPL Saved boot: %#lx\n", *((long*)(0xa0200004)));
	printf("uboot Saved boot: %#lx\n", *((long*)(0xa0200008)));
#endif /* defined CONFIG_HAVE_STDIO */

	return 0;
}


/*void imx_gpio_mux(unsigned long mode)
{
       unsigned long reg, shift, tmp;

       reg = IOMUXC_BASE + (mode & 0xfc);
       shift = (~mode & 0x3) * 8;

       tmp = __REG(reg);
       tmp &= ~(0xff << shift);
       tmp |= ((mode >> 8) & 0xff) << shift;
       __REG(reg) = tmp;
}
*/
#if defined(CONFIG_DISPLAY_CPUINFO)
int print_cpuinfo (void)
{
       printf("CPU:   Freescale i.MX27 at %ld MHz\n",
               imx_get_mpllclk() / 1000000);
       imx_dump_clocks();
       printf("\n");
       return 0;
}
#endif

void imx_gpio_mode(int gpio_mode)
{
	unsigned int pin = gpio_mode & GPIO_PIN_MASK;
	unsigned int port = (gpio_mode & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
	unsigned int ocr = (gpio_mode & GPIO_OCR_MASK) >> GPIO_OCR_SHIFT;
	unsigned int aout = (gpio_mode & GPIO_AOUT_MASK) >> GPIO_AOUT_SHIFT;
	unsigned int bout = (gpio_mode & GPIO_BOUT_MASK) >> GPIO_BOUT_SHIFT;
	unsigned int tmp;

	/* Pullup enable */
	if(gpio_mode & GPIO_PUEN)
		PUEN(port) |= (1 << pin);
	else
		PUEN(port) &= ~(1 << pin);

	/* Data direction */
	if(gpio_mode & GPIO_OUT)
		DDIR(port) |= 1 << pin;
	else
		DDIR(port) &= ~(1 << pin);

	/* Primary / alternate function */
	if(gpio_mode & GPIO_AF)
		GPR(port) |= (1 << pin);
	else
		GPR(port) &= ~(1 << pin);

	/* use as gpio? */
	if(!(gpio_mode & (GPIO_PF | GPIO_AF)))
		GIUS(port) |= (1 << pin);
	else
		GIUS(port) &= ~(1 << pin);

	/* Output / input configuration */
	if (pin < 16) {
		tmp = OCR1(port);
		tmp &= ~(3 << (pin * 2));
		tmp |= (ocr << (pin * 2));
		OCR1(port) = tmp;

		ICONFA1(port) &= ~(3 << (pin * 2));
		ICONFA1(port) |= aout << (pin * 2);
		ICONFB1(port) &= ~(3 << (pin * 2));
		ICONFB1(port) |= bout << (pin * 2);
	} else {
		pin -= 16;

		tmp = OCR2(port);
		tmp &= ~(3 << (pin * 2));
		tmp |= (ocr << (pin * 2));
		OCR2(port) = tmp;

		ICONFA2(port) &= ~(3 << (pin * 2));
		ICONFA2(port) |= aout << (pin * 2);
		ICONFB2(port) &= ~(3 << (pin * 2));
		ICONFB2(port) |= bout << (pin * 2);
	}

}


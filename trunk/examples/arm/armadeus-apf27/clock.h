
#ifndef __ASM_ARCH_CLOCK_H
#define __ASM_ARCH_CLOCK_H

#define DEFAULT_BAUDRATE 115200

unsigned int imx_decode_pll(unsigned int pll, unsigned int f_ref);

typedef unsigned long ulong;

ulong imx_get_mpllclk(void);

#ifdef CONFIG_IMX27
ulong imx_get_armclk(void);
#endif
#ifdef CONFIG_IMX1
static inline ulong imx_get_armclk(void)
{
	return imx_get_mpllclk();
}
#endif

ulong imx_get_spllclk(void);
ulong imx_get_fclk(void);
ulong imx_get_hclk(void);
ulong imx_get_bclk(void);
ulong imx_get_perclk1(void);
ulong imx_get_perclk2(void);
ulong imx_get_perclk3(void);
ulong imx_get_ahbclk(void);

#endif /* __ASM_ARCH_CLOCK_H */

/*
 * clock configuration for RP2040
 * Trampoline RTOS
 *
 * Some parts are extracted from pico-sdk.
 *  * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *  * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico.h"
#include "hardware/structs/xosc.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"
#include "hardware/structs/resets.h"

static const uint32_t MHZ = 1000 * 1000 ;
/* useful for systick config */
const uint32_t SystemCoreClockTMP = 125*MHZ;

/* from pico-sdk/src/rp2_common/hardware_xosc/xosc.c */
void tpl_xosc_init(void) {
    // Assumes 1-15 MHz input
    //assert(XOSC_MHZ <= 15);
    xosc_hw->ctrl = XOSC_CTRL_FREQ_RANGE_VALUE_1_15MHZ;

    // Set xosc startup delay
    uint32_t startup_delay = (((12 * MHZ) / 1000) + 128) / 256;
    xosc_hw->startup = startup_delay;

    // Set the enable bit now that we have set freq range and startup delay
    xosc_hw->ctrl |= XOSC_CTRL_ENABLE_VALUE_ENABLE << XOSC_CTRL_ENABLE_LSB; 

    // Wait for XOSC to be stable
    while(!(xosc_hw->status & XOSC_STATUS_STABLE_BITS));
}


/* largely inspired by
 * from pico-sdk/src/rp2_common/hardware_pll/pll.c */
void tpl_pll_init(pll_hw_t * pll, 
		      const uint32_t refdiv,
			  const uint32_t vco_freq,
			  const uint32_t post_div1,
			  const uint32_t post_div2)
{
    // Turn off PLL in case it is already running
    pll->pwr = 0xffffffff; //p.256
    pll->fbdiv_int = 0;    //p.257

    const uint32_t ref_mhz = XOSC_MHZ / refdiv;
    pll->cs = refdiv; //p.256

    // What are we multiplying the reference clock by to get the vco freq
    // (The regs are called div, because you divide the vco output and compare it to the refclk)
    const uint32_t fbdiv = vco_freq / (ref_mhz * MHZ);

//    // fbdiv
//    assert(fbdiv >= 16 && fbdiv <= 320);
//
//    // Check divider ranges
//    assert((post_div1 >= 1 && post_div1 <= 7) && (post_div2 >= 1 && post_div2 <= 7));
//
//    // post_div1 should be >= post_div2
//    // from appnote page 11
//    // postdiv1 is designed to operate with a higher input frequency
//    // than postdiv2
//    assert(post_div2 <= post_div1);
//
//    // Check that reference frequency is no greater than vco / 16
//    assert(ref_mhz <= (vco_freq / 16));

    // Put calculated value into feedback divider
    pll->fbdiv_int = fbdiv;

    // Turn on PLL
    const uint32_t power = PLL_PWR_PD_BITS | // Main power
                           PLL_PWR_VCOPD_BITS; // VCO Power

    pll->pwr &= ~power;

    // Wait for PLL to lock
    while (!(pll->cs & PLL_CS_LOCK_BITS)) {};

    // Set up post dividers - div1 feeds into div2 so if div1 is 5 and div2 is 2 then you get a divide by 10
    const uint32_t pdiv = (post_div1 << PLL_PRIM_POSTDIV1_LSB) |
                          (post_div2 << PLL_PRIM_POSTDIV2_LSB);
    pll->prim = pdiv;

    // Turn on post divider
    pll->pwr &= ~PLL_PWR_POSTDIVPD_BITS;
}

int tpl_clock_configure(enum clock_index clk_index, 
		            uint32_t src,
					uint32_t auxsrc, 
					uint32_t src_freq, 
					uint32_t freq) 
{
    uint32_t div;

    //assert(src_freq >= freq);

    if (freq > src_freq)
        return 0;

    // Div register is 24.8 int.frac divider so multiply by 2^8 (left shift by 8)
    div = (uint32_t) (((uint64_t) src_freq << 8) / freq);

    clock_hw_t *clock = &clocks_hw->clk[clk_index];

    // If increasing divisor, set divisor before source. Otherwise set source
    // before divisor. This avoids a momentary overspeed when e.g. switching
    // to a faster source and increasing divisor to compensate.
    if (div > clock->div) {
        clock->div = div;
    }
    // If switching a glitchless slice (ref or sys) to an aux source, switch
    // away from aux *first* to avoid passing glitches when changing aux mux.
    // Assume (!!!) glitchless source 0 is no faster than the aux source.
	
    const int has_glitchless_mux = (clk_index == clk_sys) || (clk_index == clk_ref) ;

    if (has_glitchless_mux && src == CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX) {
        clock->ctrl &= ~CLOCKS_CLK_REF_CTRL_SRC_BITS;
        while (!(clock->selected & 1u)) {}
    }
    // If no glitchless mux, cleanly stop the clock to avoid glitches
    // propagating when changing aux mux. Note it would be a really bad idea
    // to do this on one of the glitchless clocks (clk_sys, clk_ref).
    else {

        clock->ctrl &= ~CLOCKS_CLK_GPOUT0_CTRL_ENABLE_BITS;
        //if (configured_freq[clk_index] > 0) {
        //    // Delay for 3 cycles of the target clock, for ENABLE propagation.
        //    // Note XOSC_COUNT is not helpful here because XOSC is not
        //    // necessarily running, nor is timer... so, 3 cycles per loop:
        //    uint delay_cyc = configured_freq[clk_sys] / configured_freq[clk_index] + 1;
        //    asm volatile (
        //        ".syntax unified \n\t"
        //        "1: \n\t"
        //        "subs %0, #1 \n\t"
        //        "bne 1b"
        //        : "+r" (delay_cyc)
        //    );
        //}
    }

    // Set aux mux first, and then glitchless mux if this clock has one
	uint32_t tmp = clock->ctrl & ~CLOCKS_CLK_SYS_CTRL_AUXSRC_BITS;
	tmp |= auxsrc << CLOCKS_CLK_SYS_CTRL_AUXSRC_LSB;
    clock->ctrl = tmp;

    if (has_glitchless_mux) {
		tmp = clock->ctrl & ~CLOCKS_CLK_REF_CTRL_SRC_BITS;
		tmp |= src << CLOCKS_CLK_REF_CTRL_SRC_LSB;
        clock->ctrl = tmp;
        while (!(clock->selected & (1u << src))) {}
    }

    clock->ctrl |= CLOCKS_CLK_GPOUT0_CTRL_ENABLE_BITS;

    // Now that the source is configured, we can trust that the user-supplied
    // divisor is a safe value.
    clock->div = div;

    // Store the configured frequency
    //configured_freq[clk_index] = freq;

    return 1; 
}

/*
 * largely inspired by
 * from pico-sdk/src/rp2_common/hardware_clocks/clocks.c */
void tpl_clocks_init(void) {
    // Start tick in watchdog
    //watchdog_start_tick(XOSC_MHZ);

    // Disable resus that may be enabled from previous software
    clocks_hw->resus.ctrl = 0;

    // Enable the xosc
    tpl_xosc_init();

    // Before we touch PLLs, switch sys and ref cleanly away from their aux sources.
	clocks_hw->clk[clk_sys].ctrl &= ~ CLOCKS_CLK_SYS_CTRL_SRC_BITS ;
    while (clocks_hw->clk[clk_sys].selected != 0x1) {}
    clocks_hw->clk[clk_ref].ctrl &= ~ CLOCKS_CLK_REF_CTRL_SRC_BITS;
    while (clocks_hw->clk[clk_ref].selected != 0x1) {}

    /// \tag::pll_settings[]
    // Configure PLLs
    //                   REF     FBDIV VCO            POSTDIV
    // PLL SYS: 12 / 1 = 12MHz * 125 = 1500MHZ / 6 / 2 = 125MHz
    // PLL USB: 12 / 1 = 12MHz * 40  = 480 MHz / 5 / 2 =  48MHz
    /// \end::pll_settings[]

	//first reset PLL
    const uint32_t resettedPheripheral = RESETS_RESET_PLL_SYS_BITS | RESETS_RESET_PLL_USB_BITS ;
    resets_hw->reset |= resettedPheripheral ; //got to reset state
    resets_hw->reset &= ~resettedPheripheral; //get out of reset state
    //--- Wait until reset is done
    while ((resettedPheripheral & ~resets_hw->reset_done) != 0) {}

    tpl_pll_init(pll_sys_hw, 1, 1500 * MHZ, 6, 2);
    tpl_pll_init(pll_usb_hw, 1, 480 * MHZ, 5, 2);

    // Configure clocks
    // CLK_REF = XOSC (12MHz) / 1 = 12MHz
    tpl_clock_configure(clk_ref,
                    CLOCKS_CLK_REF_CTRL_SRC_VALUE_XOSC_CLKSRC,
                    0, // No aux mux
                    12 * MHZ,
                    12 * MHZ);

    /// \tag::configure_clk_sys[]
    // CLK SYS = PLL SYS (125MHz) / 1 = 125MHz
    tpl_clock_configure(clk_sys,
                    CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
                    CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS,
                    125 * MHZ,
                    125 * MHZ);
    /// \end::configure_clk_sys[]

    // CLK USB = PLL USB (48MHz) / 1 = 48MHz
    tpl_clock_configure(clk_usb,
                    0, // No GLMUX
                    CLOCKS_CLK_USB_CTRL_AUXSRC_VALUE_CLKSRC_PLL_USB,
                    48 * MHZ,
                    48 * MHZ);

    // CLK ADC = PLL USB (48MHZ) / 1 = 48MHz
    tpl_clock_configure(clk_adc,
                    0, // No GLMUX
                    CLOCKS_CLK_ADC_CTRL_AUXSRC_VALUE_CLKSRC_PLL_USB,
                    48 * MHZ,
                    48 * MHZ);

    // CLK RTC = PLL USB (48MHz) / 1024 = 46875Hz
    tpl_clock_configure(clk_rtc,
                    0, // No GLMUX
                    CLOCKS_CLK_RTC_CTRL_AUXSRC_VALUE_CLKSRC_PLL_USB,
                    48 * MHZ,
                    46875);

    // CLK PERI = clk_sys. Used as reference clock for Peripherals. No dividers so just select and enable
    // Normally choose clk_sys or clk_usb
    tpl_clock_configure(clk_peri,
                    0,
                    CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLK_SYS,
                    125 * MHZ,
                    125 * MHZ);
}

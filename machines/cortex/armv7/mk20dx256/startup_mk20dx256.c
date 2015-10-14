/**
 * @file handlers_mk20dx256.c
 *
 * @section descr File description
 *
 * mk20dx256 specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "tpl_compiler.h"
#include "cmsis_wrapper.h"
#include "tpl_os_interrupt_kernel.h"

extern unsigned long _stext;
extern unsigned long _etext;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;
extern unsigned long _estack;

extern int main (void);
void __libc_init_array(void);

VAR(tpl_it_handler, AUTOMATIC) _VectorsRam[NVIC_NUM_INTERRUPTS+16];
extern CONST(tpl_it_handler, AUTOMATIC) tpl_it_vectors[NVIC_NUM_INTERRUPTS+16];

__attribute__ ((section(".flashconfig"), used))
const uint8_t flashconfigbytes[16] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF
};

static void startup_default_early_hook(void) {
#if defined(KINETISK)
	WDOG_STCTRLH = WDOG_STCTRLH_ALLOWUPDATE;
#elif defined(KINETISL)
	SIM_COPC = 0;  // disable the watchdog
#endif
}
static void startup_default_late_hook(void) {}
void startup_early_hook(void)		__attribute__ ((weak, alias("startup_default_early_hook")));
void startup_late_hook(void)		__attribute__ ((weak, alias("startup_default_late_hook")));

void Reset_Handler(void)
{
	uint32_t *src = &_etext;
	uint32_t *dest = &_sdata;
	unsigned int i;
#if F_CPU <= 2000000
	volatile int n;
#endif
	//volatile int count;

#ifdef KINETISK
	WDOG_UNLOCK = WDOG_UNLOCK_SEQ1;
	WDOG_UNLOCK = WDOG_UNLOCK_SEQ2;
	__asm__ volatile ("nop");
	__asm__ volatile ("nop");
#endif
	// programs using the watchdog timer or needing to initialize hardware as
	// early as possible can implement startup_early_hook()
  startup_early_hook();

	// enable clocks to always-used peripherals
#if defined(__MK20DX128__)
	SIM_SCGC5 = 0x00043F82;		// clocks active to all GPIO
	SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTFL;
#elif defined(__MK20DX256__)
	SIM_SCGC3 = SIM_SCGC3_ADC1 | SIM_SCGC3_FTM2;
	SIM_SCGC5 = 0x00043F82;		// clocks active to all GPIO
	SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTFL;
#elif defined(__MK66FX1M0__)
	SIM_SCGC3 = SIM_SCGC3_ADC1 | SIM_SCGC3_FTM2 | SIM_SCGC3_FTM3;
	SIM_SCGC5 = 0x00043F82;		// clocks active to all GPIO
	SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTFL;
	PORTC_PCR5 = PORT_PCR_MUX(1) | PORT_PCR_DSE | PORT_PCR_SRE;
	GPIOC_PDDR |= (1<<5);
	GPIOC_PSOR = (1<<5);
	//while (1);
#elif defined(__MKL26Z64__)
	SIM_SCGC4 = SIM_SCGC4_USBOTG | 0xF0000030;
	SIM_SCGC5 = 0x00003F82;		// clocks active to all GPIO
	SIM_SCGC6 = SIM_SCGC6_ADC0 | SIM_SCGC6_TPM0 | SIM_SCGC6_TPM1 | SIM_SCGC6_TPM2 | SIM_SCGC6_FTFL;
#endif
#if 0
	// testing only, enable ser_print
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV4(1);
	MCG_C4 |= MCG_C4_DMX32 | MCG_C4_DRST_DRS(1);
	SIM_SOPT2 = SIM_SOPT2_UART0SRC(1) | SIM_SOPT2_TPMSRC(1);
	SIM_SCGC4 |= 0x00000400;
	UART0_BDH = 0;
	UART0_BDL = 26; // 115200 at 48 MHz
	UART0_C2 = UART_C2_TE;
	PORTB_PCR17 = PORT_PCR_MUX(3);
#endif
#ifdef KINETISK
	// if the RTC oscillator isn't enabled, get it started early
	if (!(RTC_CR & RTC_CR_OSCE)) {
		RTC_SR = 0;
		RTC_CR = RTC_CR_SC16P | RTC_CR_SC4P | RTC_CR_OSCE;
	}
#endif
	// release I/O pins hold, if we woke up from VLLS mode
	if (PMC_REGSC & PMC_REGSC_ACKISO) PMC_REGSC |= PMC_REGSC_ACKISO;

    // since this is a write once register, make it visible to all F_CPU's
    // so we can into other sleep modes in the future at any speed
	SMC_PMPROT = SMC_PMPROT_AVLP | SMC_PMPROT_ALLS | SMC_PMPROT_AVLLS;

	// TODO: do this while the PLL is waiting to lock....
	while (dest < &_edata) *dest++ = *src++;
	dest = &_sbss;
	while (dest < &_ebss) *dest++ = 0;

	// default all interrupts to medium priority level
	for (i=0; i < NVIC_NUM_INTERRUPTS + 16; i++) _VectorsRam[i] = tpl_it_vectors[i];
	for (i=0; i < NVIC_NUM_INTERRUPTS; i++) NVIC_SET_PRIORITY(i, 128);
	SCB_VTOR = (uint32_t)_VectorsRam;	// use vector table in RAM

	// hardware always starts in FEI mode
	//  C1[CLKS] bits are written to 00
	//  C1[IREFS] bit is written to 1
	//  C6[PLLS] bit is written to 0
// MCG_SC[FCDIV] defaults to divide by two for internal ref clock
// I tried changing MSG_SC to divide by 1, it didn't work for me
#if F_CPU <= 2000000
    #if defined(KINETISK)
    MCG_C1 = MCG_C1_CLKS(1) | MCG_C1_IREFS;
    #elif defined(KINETISL)
	// use the internal oscillator
	MCG_C1 = MCG_C1_CLKS(1) | MCG_C1_IREFS | MCG_C1_IRCLKEN;
    #endif
	// wait for MCGOUT to use oscillator
	while ((MCG_S & MCG_S_CLKST_MASK) != MCG_S_CLKST(1)) ;
	for (n=0; n<10; n++) ; // TODO: why do we get 2 mA extra without this delay?
	MCG_C2 = MCG_C2_IRCS;
	while (!(MCG_S & MCG_S_IRCST)) ;
	// now in FBI mode:
	//  C1[CLKS] bits are written to 01
	//  C1[IREFS] bit is written to 1
	//  C6[PLLS] is written to 0
	//  C2[LP] is written to 0
	MCG_C2 = MCG_C2_IRCS | MCG_C2_LP;
	// now in BLPI mode:
	//  C1[CLKS] bits are written to 01
	//  C1[IREFS] bit is written to 1
	//  C6[PLLS] bit is written to 0
	//  C2[LP] bit is written to 1
#else
    #if defined(KINETISK)
    // enable capacitors for crystal
    OSC0_CR = OSC_SC8P | OSC_SC2P;
    #elif defined(KINETISL)
    // enable capacitors for crystal
    OSC0_CR = OSC_SC8P | OSC_SC2P | OSC_ERCLKEN;
    #endif
	// enable osc, 8-32 MHz range, low power mode
	MCG_C2 = MCG_C2_RANGE0(2) | MCG_C2_EREFS;
	// switch to crystal as clock source, FLL input = 16 MHz / 512
	MCG_C1 =  MCG_C1_CLKS(2) | MCG_C1_FRDIV(4);
	// wait for crystal oscillator to begin
	while ((MCG_S & MCG_S_OSCINIT0) == 0) ;
	// wait for FLL to use oscillator
	while ((MCG_S & MCG_S_IREFST) != 0) ;
	// wait for MCGOUT to use oscillator
	while ((MCG_S & MCG_S_CLKST_MASK) != MCG_S_CLKST(2)) ;

	// now in FBE mode
	//  C1[CLKS] bits are written to 10
	//  C1[IREFS] bit is written to 0
	//  C1[FRDIV] must be written to divide xtal to 31.25-39 kHz
	//  C6[PLLS] bit is written to 0
	//  C2[LP] is written to 0
  #if F_CPU <= 16000000
	// if the crystal is fast enough, use it directly (no FLL or PLL)
	MCG_C2 = MCG_C2_RANGE0(2) | MCG_C2_EREFS | MCG_C2_LP;
	// BLPE mode:
	//   C1[CLKS] bits are written to 10
	//   C1[IREFS] bit is written to 0
	//   C2[LP] bit is written to 1
  #else
	// if we need faster than the crystal, turn on the PLL
   #if defined(__MK66FX1M0__)
    #if F_CPU == 96000000
	MCG_C5 = MCG_C5_PRDIV0(1);
	MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(8);
    #else
    #error "MK66FX1M0 only supports 96 MHz so far...."
    #endif
   #else
    #if F_CPU == 72000000
	MCG_C5 = MCG_C5_PRDIV0(5);		 // config PLL input for 16 MHz Crystal / 6 = 2.667 Hz
    #else
	MCG_C5 = MCG_C5_PRDIV0(3);		 // config PLL input for 16 MHz Crystal / 4 = 4 MHz
    #endif
    #if F_CPU == 168000000
	MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(18); // config PLL for 168 MHz output
    #elif F_CPU == 144000000
	MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(12); // config PLL for 144 MHz output
    #elif F_CPU == 120000000
	MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(6); // config PLL for 120 MHz output
    #elif F_CPU == 72000000
	MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(3); // config PLL for 72 MHz output
    #else
	MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(0); // config PLL for 96 MHz output
    #endif
   #endif


	// wait for PLL to start using xtal as its input
	while (!(MCG_S & MCG_S_PLLST)) ;
	// wait for PLL to lock
	while (!(MCG_S & MCG_S_LOCK0)) ;
	// now we're in PBE mode
  #endif
#endif
	// now program the clock dividers
#if F_CPU == 168000000
	// config divisors: 168 MHz core, 56 MHz bus, 28 MHz flash, USB = 168 * 2 / 7
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(2) |	 SIM_CLKDIV1_OUTDIV4(5);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(6) | SIM_CLKDIV2_USBFRAC;
#elif F_CPU == 144000000
	// config divisors: 144 MHz core, 48 MHz bus, 28.8 MHz flash, USB = 144 / 3
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(2) |	 SIM_CLKDIV1_OUTDIV4(4);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(2);
#elif F_CPU == 120000000
	// config divisors: 120 MHz core, 60 MHz bus, 24 MHz flash, USB = 128 * 2 / 5
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(1) |	 SIM_CLKDIV1_OUTDIV4(4);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(4) | SIM_CLKDIV2_USBFRAC;
#elif F_CPU == 96000000
	// config divisors: 96 MHz core, 48 MHz bus, 24 MHz flash, USB = 96 / 2
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(1) |	 SIM_CLKDIV1_OUTDIV4(3);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(1);
#elif F_CPU == 72000000
	// config divisors: 72 MHz core, 36 MHz bus, 24 MHz flash, USB = 72 * 2 / 3
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(1) |	 SIM_CLKDIV1_OUTDIV4(2);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(2) | SIM_CLKDIV2_USBFRAC;
#elif F_CPU == 48000000
	// config divisors: 48 MHz core, 48 MHz bus, 24 MHz flash, USB = 96 / 2
	#if defined(KINETISK)
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV2(1) |	 SIM_CLKDIV1_OUTDIV4(3);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(1);
	#elif defined(KINETISL)
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV4(1);
	#endif
#elif F_CPU == 24000000
	// config divisors: 24 MHz core, 24 MHz bus, 24 MHz flash, USB = 96 / 2
	#if defined(KINETISK)
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV2(3) |	 SIM_CLKDIV1_OUTDIV4(3);
	SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(1);
	#elif defined(KINETISL)
	SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV4(0);
	#endif
#elif F_CPU == 16000000
	// config divisors: 16 MHz core, 16 MHz bus, 16 MHz flash
#if defined(KINETISK)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(0) |	 SIM_CLKDIV1_OUTDIV4(0);
#elif defined(KINETISL)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV4(0);
#endif
#elif F_CPU == 8000000
	// config divisors: 8 MHz core, 8 MHz bus, 8 MHz flash
#if defined(KINETISK)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV2(1) |	 SIM_CLKDIV1_OUTDIV4(1);
#elif defined(KINETISL)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV4(0);
#endif
#elif F_CPU == 4000000
    // config divisors: 4 MHz core, 4 MHz bus, 2 MHz flash
    // since we are running from external clock 16MHz
    // fix outdiv too -> cpu 16/4, bus 16/4, flash 16/4
    // here we can go into vlpr?
	// config divisors: 4 MHz core, 4 MHz bus, 4 MHz flash
#if defined(KINETISK)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV2(3) |	 SIM_CLKDIV1_OUTDIV4(3);
#elif defined(KINETISL)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV4(0);
#endif
#elif F_CPU == 2000000
    // since we are running from the fast internal reference clock 4MHz
    // but is divided down by 2 so we actually have a 2MHz, MCG_SC[FCDIV] default is 2
    // fix outdiv -> cpu 2/1, bus 2/1, flash 2/2
	// config divisors: 2 MHz core, 2 MHz bus, 1 MHz flash
#if defined(KINETISK)
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(0) |	 SIM_CLKDIV1_OUTDIV4(1);
#elif defined(KINETISL)
    // config divisors: 2 MHz core, 1 MHz bus, 1 MHz flash
    SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV4(1);
#endif
#else
#error "Error, F_CPU must be 168, 144, 120, 96, 72, 48, 24, 16, 8, 4, or 2 MHz"
#endif

#if F_CPU > 16000000
	// switch to PLL as clock source, FLL input = 16 MHz / 512
	MCG_C1 = MCG_C1_CLKS(0) | MCG_C1_FRDIV(4);
	// wait for PLL clock to be used
	while ((MCG_S & MCG_S_CLKST_MASK) != MCG_S_CLKST(3)) ;
	// now we're in PEE mode
	// USB uses PLL clock, trace is CPU clock, CLKOUT=OSCERCLK0
	#if defined(KINETISK)
	SIM_SOPT2 = SIM_SOPT2_USBSRC | SIM_SOPT2_PLLFLLSEL | SIM_SOPT2_TRACECLKSEL
		| SIM_SOPT2_CLKOUTSEL(6);
	#elif defined(KINETISL)
	SIM_SOPT2 = SIM_SOPT2_USBSRC | SIM_SOPT2_PLLFLLSEL | SIM_SOPT2_CLKOUTSEL(6)
		| SIM_SOPT2_UART0SRC(1) | SIM_SOPT2_TPMSRC(1);
	#endif
#else

#if F_CPU == 2000000
	SIM_SOPT2 = SIM_SOPT2_TRACECLKSEL | SIM_SOPT2_CLKOUTSEL(4) | SIM_SOPT2_UART0SRC(3);
#else
    SIM_SOPT2 = SIM_SOPT2_TRACECLKSEL | SIM_SOPT2_CLKOUTSEL(6) | SIM_SOPT2_UART0SRC(2);
#endif

#endif

#if F_CPU <= 2000000
    // since we are not going into "stop mode" i removed it
	SMC_PMCTRL = SMC_PMCTRL_RUNM(2); // VLPR mode :-)
#endif


	//init_pins();
	__enable_irq();

	// _init_Teensyduino_internal_();

#if 0
#if defined(KINETISK)
	// RTC initialization
	if (RTC_SR & RTC_SR_TIF) {
		// this code will normally run on a power-up reset
		// when VBAT has detected a power-up.  Normally our
		// compiled-in time will be stale.  Write a special
		// flag into the VBAT register file indicating the
		// RTC is set with known-stale time and should be
		// updated when fresh time is known.
		#if ARDUINO >= 10600
		rtc_set((uint32_t)&__rtc_localtime);
		#else
		rtc_set(TIME_T);
		#endif
		*(uint32_t *)0x4003E01C = 0x5A94C3A5;
	}
	if ((RCM_SRS0 & RCM_SRS0_PIN) && (*(uint32_t *)0x4003E01C == 0x5A94C3A5)) {
		// this code should run immediately after an upload
		// where the Teensy Loader causes the Mini54 to reset.
		// Our compiled-in time will be very fresh, so set
		// the RTC with this, and clear the VBAT resister file
		// data so we don't mess with the time after it's been
		// set well.
		#if ARDUINO >= 10600
		rtc_set((uint32_t)&__rtc_localtime);
		#else
		rtc_set(TIME_T);
		#endif
		*(uint32_t *)0x4003E01C = 0;
	}
#endif
#endif

	__libc_init_array();

  startup_late_hook();
	main();
	while (1) ;
}

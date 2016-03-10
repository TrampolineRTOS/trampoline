/**
 * @file startup_mk20dx256.c
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

// static void startup_default_early_hook(void) {
// #if defined(KINETISK)
// 	WDOG_STCTRLH = WDOG_STCTRLH_ALLOWUPDATE;
// #elif defined(KINETISL)
// 	SIM_COPC = 0;  // disable the watchdog
// #endif
// }
// static void startup_default_late_hook(void) {}
// void startup_early_hook(void)		__attribute__ ((weak, alias("startup_default_early_hook")));
// void startup_late_hook(void)		__attribute__ ((weak, alias("startup_default_late_hook")));

void tpl_continue_reset_handler(void)
{
//---------1- Inhiber le chien de garde
  WDOG_UNLOCK = 0xC520 ;
  WDOG_UNLOCK = 0xD928 ;
  WDOG_STCTRLH = 0x0010 ;
  // enable clocks to always-used peripherals
  SIM_SCGC3 = SIM_SCGC3_ADC1 | SIM_SCGC3_FTM2;
  SIM_SCGC5 = 0x00043F82;    // clocks active to all GPIO
  SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTFL;

  // if the RTC oscillator isn't enabled, get it started early
  if (!(RTC_CR & RTC_CR_OSCE)) {
    RTC_SR = 0;
    RTC_CR = RTC_CR_SC16P | RTC_CR_SC4P | RTC_CR_OSCE;
  }

  // release I/O pins hold, if we woke up from VLLS mode
  if (PMC_REGSC & PMC_REGSC_ACKISO) PMC_REGSC |= PMC_REGSC_ACKISO;

  // TODO: do this while the PLL is waiting to lock....
//  SCB_VTOR = 0;  // use vector table in flash

  // default all interrupts to medium priority level
//  for (int32_t i=0; i < NVIC_NUM_INTERRUPTS; i++) NVIC_SET_PRIORITY(i, 128);
//---------2- Initialisation de la PLL
  // start in FEI mode
  // enable capacitors for crystal
  OSC0_CR = OSC_SC8P | OSC_SC2P;
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
  // now we're in FBE mode
  // config PLL input for 16 MHz Crystal / 4 = 4 MHz
  MCG_C5 = MCG_C5_PRDIV0(3);
  // config PLL for 96 MHz output
  MCG_C6 = MCG_C6_PLLS | MCG_C6_VDIV0(0);
  // wait for PLL to start using xtal as its input
  while (!(MCG_S & MCG_S_PLLST)) ;
  // wait for PLL to lock
  while (!(MCG_S & MCG_S_LOCK0)) ;
  // now we're in PBE mode
#if F_CPU == 96000000
  // config divisors: 96 MHz core, 48 MHz bus, 24 MHz flash
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(1) |   SIM_CLKDIV1_OUTDIV4(3);
#elif F_CPU == 48000000
  // config divisors: 48 MHz core, 48 MHz bus, 24 MHz flash
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV2(1) |   SIM_CLKDIV1_OUTDIV4(3);
#elif F_CPU == 24000000
  // config divisors: 24 MHz core, 24 MHz bus, 24 MHz flash
  SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(3) | SIM_CLKDIV1_OUTDIV2(3) |   SIM_CLKDIV1_OUTDIV4(3);
#else
#error "Error, F_CPU must be 96000000, 48000000, or 24000000"
#endif
  // switch to PLL as clock source, FLL input = 16 MHz / 512
  MCG_C1 = MCG_C1_CLKS(0) | MCG_C1_FRDIV(4);
  // wait for PLL clock to be used
  while ((MCG_S & MCG_S_CLKST_MASK) != MCG_S_CLKST(3)) ;
  // now we're in PEE mode
  // configure USB for 48 MHz clock
//  SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(1); // USB = 96 MHz PLL / 2
  // USB uses PLL clock, trace is CPU clock, CLKOUT=OSCERCLK0
//  SIM_SOPT2 = SIM_SOPT2_USBSRC | SIM_SOPT2_PLLFLLSEL | SIM_SOPT2_TRACECLKSEL | SIM_SOPT2_CLKOUTSEL(6);

//---------3- Initialisation de la section .bss
  extern unsigned __bss_start ;
  extern unsigned __bss_end ;
  unsigned * p = & __bss_start ;
  while (p != & __bss_end) {
    * p = 0 ;
    p ++ ;
  }
//---------4- Copy de la section .data
  extern unsigned __data_start ;
  extern unsigned __data_end ;
  extern unsigned __data_load_start ;
  unsigned * pSrc = & __data_load_start ;
  unsigned * pDest = & __data_start ;
  while (pDest != & __data_end) {
    * pDest = * pSrc ;
    pDest ++ ;
    pSrc ++ ;
  }

// Systick configuration is done in tpl_set_systick which is called
// when StartOS is called

//---------5- Exécuter les constructeurs des variables globales
  extern void (* __constructor_array_start) (void) ;
  extern void (* __constructor_array_end) (void) ;
  void (** ptr) (void) = & __constructor_array_start ;
  while (ptr != & __constructor_array_end) {
    (* ptr) () ;
    ptr ++ ;
  }
//---------6- Exécuter les routines d'initialisation de la section init_routine_array
//   extern void (* __init_routine_array_start) (void) ;
//   extern void (* __init_routine_array_end) (void) ;
//   ptr = & __init_routine_array_start ;
//   while (ptr != & __init_routine_array_end) {
//     (* ptr) () ;
//     ptr ++ ;
//   }
//---------7- Exécuter le programme utilisateur
  main();
  while (1) ;
}

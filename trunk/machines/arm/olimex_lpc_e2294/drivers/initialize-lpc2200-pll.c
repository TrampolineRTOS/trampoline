/*--------------------------------------------------------------------------*/
/*                                                                          */
/* Copyright (C) 2009, ..., 2012 Pierre Molinaro.                           */
/*                                                                          */
/* e-mail : molinaro@irccyn.ec-nantes.fr                                    */
/*                                                                          */
/* IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes*/
/* ECN, Ecole Centrale de Nantes (France)                                   */
/*                                                                          */
/* This program is free software; you can redistribute it and/or modify it  */
/* under the terms of the GNU General Public License as published by the    */
/* Free Software Foundation.                                                */
/*                                                                          */
/* This program is distributed in the hope it will be useful, but WITHOUT   */
/* ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    */
/* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for */
/* more details.                                                            */
/*                                                                          */
//---------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------*

#include "check-lpc2200-timing-settings.h"
#include "lpc22xx.h"

//---------------------------------------------------------------------------*
//   Setting the Phased Lock Loop: computations for a 14.7456 MHz crystal     *
//---------------------------------------------------------------------------*
//                                                                           *
// NPX LPC2294 is connected to a 14.7456 MHz crystal:                        *
//  LPC22XX_CRYSTAL_FREQUENCY = 14745600                                     *
//  LPC22XX_PLL_FREQUENCY_MULTIPLIER = 4 # So CCLK is 58.9824 MHz            *
//  LPC22XX_APB_DIVIDER := 1 # So PCLK is 58.9824 MHz                        *
//                                                                           *
// The processor clock CCLK is a multiple of crystal:                        *
//      CCLK = LPC22XX_CRYSTAL_FREQUENCY * LPC22XX_PLL_FREQUENCY_MULTIPLIER  *
//   LPC22XX_PLL_FREQUENCY_MULTIPLIER = 1 -> CCLK = 14.7456 MHz              *
//   LPC22XX_PLL_FREQUENCY_MULTIPLIER = 2 -> CCLK = 29.4912 MHz              *
//   LPC22XX_PLL_FREQUENCY_MULTIPLIER = 3 -> CCLK = 44.2368 MHz              *
//   LPC22XX_PLL_FREQUENCY_MULTIPLIER = 4 -> CCLK = 58.9834 MHz              *
//   LPC22XX_PLL_FREQUENCY_MULTIPLIER = 5 -> CCLK = 73.7280 MHz NO! >60 MHz  *
//                                                                           *
// LPC22XX_PLL_FREQUENCY_MULTIPLIER - 1 must be entered into bits 0-4 of     *
// PLLCFG.                                                                   *
//                                                                           *
//---------------------------------------------------------------------------*
//                                                                           *
// The Current Controlled Oscilator (CCO) must operate at Fcco in the range  *
// 156 MHz to 320 MHz.                                                       *
//                                                                           *
// According to the Philips LPC2294 manual:  Fcco = CCLK * 2 * PSEL, and     *
// PSEL can only be 1, 2, 4 or 8.                                            *
//                                                                           *
// So, for CCLK = 58.9834 MHz:                                               *
//   P = 1 -> Fcco = 117.9648 MHz NO!! Lower than 156 MHz                    *
//   P = 2 -> Fcco = 235.9296 MHz Ok                                         *
//   P = 4 -> Fcco = 471.8592 MHz NO!! Greater than 320 MHz                  *
//                                                                           *
//---------------------------------------------------------------------------*

#if ((CCLK * 2) >= 156000000) && ((CCLK * 2) <= 320000000)
  #define PSEL (0 << 5)
#elif ((CCLK * 2 * 2) >= 156000000) && ((CCLK * 2 * 2) <= 320000000)
  #define PSEL (1 << 5)
#elif ((CCLK * 2 * 4) >= 156000000) && ((CCLK * 2 * 4) <= 320000000)
  #define PSEL (2 << 5)
#elif ((CCLK * 2 * 8) >= 156000000) && ((CCLK * 2 * 8) <= 320000000)
  #define PSEL (3 << 5)
#else
  #error "Unable to compute a valid value for PSEL"
  #define PSEL (0) // Any value, for not raising an other error
#endif
  
//---------------------------------------------------------------------------*
//                                                                           *
// Setting the PLLCFG register:                                              *
//   - bits 0-4 handle M - 1;                                                *
//   - bits 5-6 is 0 if P=1, 1 if P=2, 2 if P=4, and 3 if P=8.               *
//   - bit 7 should be 0.                                                    *
//                                                                           *
// So, for CCLK = 58.9834 MHz: PLLCFG = 0 01 00011 = 0x23                    *
//                                                                           *
// Final note: to load PLLCFG register, we must use the 0xAA - 0x55 write    *
// sequence to the PLLFEED register; this is done in the short function      *
// feed() below.                                                             *
//                                                                           *
//---------------------------------------------------------------------------*

static void feed (void) {
  PLLFEED = 0xAA ;
  PLLFEED = 0x55 ;
}

//---------------------------------------------------------------------------*

void initialize_lpc2200_pll (void) ; // This routine is called from assembly

void initialize_lpc2200_pll (void)  {
  #define PLOCK (0x400)

//--- Setting Multiplier and Divider values
  PLLCFG = (PSEL) | (LPC22XX_PLL_FREQUENCY_MULTIPLIER - 1) ;
  feed () ;
  
//--- Enabling the PLL 
  PLLCON = 0x1 ;
  feed () ;
  
 //--- Wait for the PLL to lock to set frequency
  while (!(PLLSTAT & PLOCK)) {}
  
//--- Connect the PLL as the clock source
  PLLCON = 0x3 ;
  feed () ;
  
//--- Enabling MAM and setting number of clocks used for Flash memory fetch
  MAMCR = 0 ; // Disable MAM
  MAMTIM = 3 ; // 3 CCLK are correct for CCLK until 60 MHz
  MAMCR = 0x2 ; // Enable MAM
  
//--- Setting peripheral Clock (PCLK) according to LPC22XX_APB_DIVIDER
  #if LPC22XX_APB_DIVIDER == 1
    VPBDIV = 0x1 ;
  #elif LPC22XX_APB_DIVIDER == 2
    VPBDIV = 0x2 ;
  #elif LPC22XX_APB_DIVIDER == 4
    VPBDIV = 0x0 ;
  #else
    #error "Invalid LPC22XX_APB_DIVIDER value: should be 1, 2, or 4"
  #endif
}

//---------------------------------------------------------------------------*

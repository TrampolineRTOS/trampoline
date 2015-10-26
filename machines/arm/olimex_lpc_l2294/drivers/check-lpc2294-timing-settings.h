//---------------------------------------------------------------------------*
//                                                                           *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This program is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU General Public License as published by the    *
//  Free Software Foundation.                                                *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*
//                                                                           *
// This header checks the LPC2294_CRYSTAL_FREQUENCY, LPC2294_APB_DIVIDER,    *
// and the LPC2294_PLL_FREQUENCY_MULTIPLIER values. It also computes the     *
// PCLK and CCLK resulting values.                                           *
//                                                                           *
// The LPC2294_CRYSTAL_FREQUENCY value:                                      *
//   - this value, expressed in Hz, should be the actual quartz frequency;   *
//   - constraint: 10 MHz <= LPC2294_CRYSTAL_FREQUENCY <= 15 MHz.            *
//                                                                           *
// The LPC2294_PLL_FREQUENCY_MULTIPLIER value:                               *
//   - it defines the system clock CCLK, used by the ARM7 processor;         *
//       CCLK = LPC2294_CRYSTAL_FREQUENCY * LPC2294_PLL_FREQUENCY_MULTIPLIER *
//   - constraint: 10 MHz <= CCLK <= 60 MHz.                                 *
//                                                                           *
// The LPC2294_APB_DIVIDER value:                                            *
//   - it defines the peripherical clock PCLK, used by the all               *
//     on chip peripheral devices;                                           *
//        PCLK = CCLK / LPC2294_APB_DIVIDER                                  *
//   - constraint: LPC2294_APB_DIVIDER should be 1, 2 or 4;                  *
//   - using 1 provides best timing accuracy.                                *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef CHECK_LPC2294_TIMING_SETTINGS_HEADER_ALREADY_INCLUDED
#define CHECK_LPC2294_TIMING_SETTINGS_HEADER_ALREADY_INCLUDED

//---------------------------------------------------------------------------*

#define LPC2294_CRYSTAL_FREQUENCY  (14745600)
#define LPC2294_PLL_FREQUENCY_MULTIPLIER (4)
#define LPC2294_APB_DIVIDER (1)

//---------------------------------------------------------------------------*

#ifndef LPC2294_CRYSTAL_FREQUENCY
  #error LPC2294_CRYSTAL_FREQUENCY is not defined
  #define LPC2294_CRYSTAL_FREQUENCY (0) // Any value, for not raising an other error
#elif (LPC2294_CRYSTAL_FREQUENCY < 10000000) || (LPC2294_CRYSTAL_FREQUENCY > 25000000)
  #error invalid LPC2294_CRYSTAL_FREQUENCY value: should between 10000000 and 25000000
#endif

//---------------------------------------------------------------------------*

#ifndef LPC2294_PLL_FREQUENCY_MULTIPLIER
  #error LPC2294_PLL_FREQUENCY_MULTIPLIER is not defined
  #define LPC2294_PLL_FREQUENCY_MULTIPLIER (0) // Any value, for not raising an other error
#else
  #define CCLK ((LPC2294_PLL_FREQUENCY_MULTIPLIER) * (LPC2294_CRYSTAL_FREQUENCY))
  #if ((CCLK) < 1000000) || (CLK > 60000000)
    #error invalid LPC2294_PLL_FREQUENCY_MULTIPLIER value: resulting CCLK should between 10000000 and 60000000
  #endif
#endif

//---------------------------------------------------------------------------*

#ifndef LPC2294_APB_DIVIDER
  #error LPC2294_APB_DIVIDER is not defined
  #define LPC2294_APB_DIVIDER (1) // Any value (but not zero), for not raising an other error
#elif (LPC2294_APB_DIVIDER != 1) && (LPC2294_APB_DIVIDER != 2) && (LPC2294_APB_DIVIDER != 4)
  #error invalid LPC2294_APB_DIVIDER value: should be 1, 2 or 4
  #undef LPC2294_APB_DIVIDER
  #define LPC2294_APB_DIVIDER (1) // Any value (but not zero), for not raising an other error
#endif

//---------------------------------------------------------------------------*

#define CCLK ((LPC2294_PLL_FREQUENCY_MULTIPLIER) * (LPC2294_CRYSTAL_FREQUENCY))
#define PCLK ((CCLK) / (LPC2294_APB_DIVIDER))

//---------------------------------------------------------------------------*

#endif

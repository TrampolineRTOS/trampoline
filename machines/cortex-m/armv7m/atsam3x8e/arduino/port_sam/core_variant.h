/*
  Copyright (c) 2011 Arduino LLC.  All right reserved.
  Copyright (c) 2015 Thibaut VIARD.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _ARDUINO_CORE_VARIANT_H_
#define _ARDUINO_CORE_VARIANT_H_

#include <stdint.h>
#define __SAM3X8E__
#include "sam.h"
#include "../arch_common/core_constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/* The 2 following symbols must be present into variant_startup.c */
extern uint32_t SystemCoreClock;
extern DeviceVectors exception_table;

/* Definitions and types for pins */
typedef enum _EAnalogChannel
{
  NOT_ON_ANALOG=-1,
  ADC_CHL0=0,
  ADC_CHL1=1,
  ADC_CHL2=2,
  ADC_CHL3=3,
  ADC_CHL4=4,
  ADC_CHL5=5,
  ADC_CHL6=6,
  ADC_CHL7=7,
  ADC_CHL8=8,
  ADC_CHL9=9,
  ADC_CHL10=10,
  ADC_CHL11=11,
  ADC_CHL12=12,
  ADC_CHL13=13,
  ADC_CHL14=14,
  ADC_CHL15=15,

  DAC_CHL0,
  DAC_CHL1
} EAnalogChannel ;

// Definitions for TC channels
typedef enum _ETimerChannel
{
  NOT_ON_TIMER=-1,
#ifdef TC0
  TC0_CHA0=0,
  TC0_CHB0,
  TC0_CHA1,
  TC0_CHB1,
  TC0_CHA2,
  TC0_CHB2,
#endif // TC0
#ifdef TC1
  TC1_CHA3,
  TC1_CHB3,
  TC1_CHA4,
  TC1_CHB4,
  TC1_CHA5,
  TC1_CHB5,
#endif // TC1
#ifdef TC2
  TC2_CHA6,
  TC2_CHB6,
  TC2_CHA7,
  TC2_CHB7,
  TC2_CHA8,
  TC2_CHB8
#endif // TC2
} ETimerChannel ;

// Definitions for PWM channels
typedef enum _EPWMChannel
{
  NOT_ON_PWM=-1,
  PWM_CHL0=0,
  PWM_CHL1,
  PWM_CHL2,
  PWM_CHL3,
  PWM_CHL4,
  PWM_CHL5,
  PWM_CHL6,
  PWM_CHL7
} EPWMChannel ;

// I/O controllers indexes, should be affined to device packages instead of product series
typedef enum _PortNumber
{
  NOT_A_PORT=-1, // Won't have any pin associated, then.

#if SAM3XA_SERIES
  PORTA=0,
  PORTB=1,
  PORTC=2,
  PORTD=3,
#endif // SAM3XA_SERIES

#if SAM4S_SERIES
  PORTA=0,
  PORTB=1,
  PORTC=2,
#endif // SAM4S_SERIES

#if SAM4E_SERIES
  PORTA=0,
  PORTB=1,
  PORTC=2,
  PORTD=3,
  PORTE=4,
#endif // SAM4E_SERIES

#if SAMG55_SERIES
  PORTA=0,
  PORTB=1,
#endif // SAMG55_SERIES

  NUM_PORTS // Number of declared I/O controllers
} PortNumber ;

typedef struct _Port
{
  Pio* pGPIO;
  uint32_t ulId;
} Port;

extern const Port Ports[NUM_PORTS];

typedef enum _EExt_Interrupts
{

  EXTERNAL_NUM_INTERRUPTS,
  NOT_AN_INTERRUPT = -1,
  EXTERNAL_INT_NONE = NOT_AN_INTERRUPT,
} EExt_Interrupts ;

typedef enum _EGPIOType
{
  GPIO_NOMUX,
  GPIO_PERIPH_A,
  GPIO_PERIPH_B,
#if (SAM4S_SERIES || SAM4E_SERIES)
  GPIO_PERIPH_C, // Only on SAM4S and SAM4E
#endif /* (SAM4S_SERIES || SAM4E_SERIES) */
#if (SAM4S_SERIES)
  GPIO_PERIPH_D // Only on some SAM4S
#endif /* SAM4S_SERIES */
} EGPIOType ;

/* Types used for the table below */
typedef struct _PinDescription
{
  PortNumber      iPort ;
  uint32_t        ulPin ;
  EGPIOType       ulPinType ;
  EAnalogChannel  ulADCChannelNumber ; /* ADC Channel number in the SAM device */
  EPWMChannel     ulPWMChannel ;
  ETimerChannel   ulTimerChannel ;
} PinDescription ;

/* Pins table to be instantiated into variant.cpp */
extern const PinDescription g_aPinMap[] ;

#define digitalPinToPort(P)        ( Ports[g_aPinMap[ulPin].iPort].pGPIO )
#define digitalPinToBitMask(P)     ( g_aPinMap[P].ulPin )
#define digitalPinHasPWM(P)        ( g_aPinMap[P].ulPWMChannel != NOT_ON_PWM || g_aPinMap[P].ulTCChannel != NOT_ON_TIMER )


/**
 * \brief Initialize the variant.
 */
extern void initVariant(void);

/**
 * \brief Setup the microcontroller system.
 *
 * Initialize the System and update the SystemFrequency variable.
 */
extern void SystemInit(void);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _ARDUINO_CORE_VARIANT_H_

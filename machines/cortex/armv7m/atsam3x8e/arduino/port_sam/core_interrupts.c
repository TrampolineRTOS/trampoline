/*
  Copyright (c) 2011-2014 Arduino.  All right reserved.

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

#include "core_interrupts.h"

typedef void (*interruptCB)(void);

#if defined PIOA
static interruptCB callbacksPioA[32];
#endif // defined PIOA
#if defined PIOB
static interruptCB callbacksPioB[32];
#endif // defined PIOB
#if defined PIOC
static interruptCB callbacksPioC[32];
#endif // defined PIOC
#if defined PIOD
static interruptCB callbacksPioD[32];
#endif // defined PIOD
#if defined PIOE
static interruptCB callbacksPioE[32];
#endif // defined PIOE

/* Configure PIO interrupt sources */
static void interruptInitialize(void)
{
  int i;
  for (i=0; i<32; i++)
  {
#if defined PIOA
    callbacksPioA[i] = NULL;
#endif // defined PIOA
#if defined PIOB
    callbacksPioB[i] = NULL;
#endif // defined PIOB
#if defined PIOC
    callbacksPioC[i] = NULL;
#endif // defined PIOC
#if defined PIOD
    callbacksPioD[i] = NULL;
#endif // defined PIOD
#if defined PIOE
    callbacksPioE[i] = NULL;
#endif // defined PIOE
  }

#if defined PIOA
  PMC->PMC_PCER0 = 1 << ID_PIOA;
  NVIC_DisableIRQ(PIOA_IRQn);
  NVIC_ClearPendingIRQ(PIOA_IRQn);
  NVIC_SetPriority(PIOA_IRQn, 0);
  NVIC_EnableIRQ(PIOA_IRQn);
#endif // defined PIOA

#if defined PIOB
  PMC->PMC_PCER0 = 1 << ID_PIOB;
  NVIC_DisableIRQ(PIOB_IRQn);
  NVIC_ClearPendingIRQ(PIOB_IRQn);
  NVIC_SetPriority(PIOB_IRQn, 0);
  NVIC_EnableIRQ(PIOB_IRQn);
#endif // defined PIOB

#if defined PIOC
  PMC->PMC_PCER0 = 1 << ID_PIOC;
  NVIC_DisableIRQ(PIOC_IRQn);
  NVIC_ClearPendingIRQ(PIOC_IRQn);
  NVIC_SetPriority(PIOC_IRQn, 0);
  NVIC_EnableIRQ(PIOC_IRQn);
#endif // defined PIOC

#if defined PIOD
  PMC->PMC_PCER0 = 1 << ID_PIOD;
  NVIC_DisableIRQ(PIOD_IRQn);
  NVIC_ClearPendingIRQ(PIOD_IRQn);
  NVIC_SetPriority(PIOD_IRQn, 0);
  NVIC_EnableIRQ(PIOD_IRQn);
#endif // defined PIOD

#if defined PIOE
  PMC->PMC_PCER0 = 1 << ID_PIOE;
  NVIC_DisableIRQ(PIOE_IRQn);
  NVIC_ClearPendingIRQ(PIOE_IRQn);
  NVIC_SetPriority(PIOE_IRQn, 0);
  NVIC_EnableIRQ(PIOE_IRQn);
#endif // defined PIOE
}


void attachInterrupt(uint32_t ulPin, void (*callback)(void), uint32_t mode)
{
  static int enabled = 0;

  /* TODO: this should be done in libc init() function array */
  if (!enabled)
  {
    interruptInitialize();
    enabled = 1;
  }

  // Retrieve pin information
  Pio *pio = Ports[g_aPinMap[ulPin].iPort].pGPIO;
  uint32_t mask = g_aPinMap[ulPin].ulPin;
  uint32_t pos = 0;

  uint32_t t;
  for (t = mask; t>1; t>>=1, pos++)
    ;

  // Set callback function
#if defined PIOA
  if (pio == PIOA)
  {
    callbacksPioA[pos] = callback;
  }
#endif // defined PIOA

#if defined PIOB
  if (pio == PIOB)
  {
    callbacksPioB[pos] = callback;
  }
#endif // defined PIOB

#if defined PIOC
  if (pio == PIOC)
  {
    callbacksPioC[pos] = callback;
  }
#endif // defined PIOC

#if defined PIOD
  if (pio == PIOD)
  {
    callbacksPioD[pos] = callback;
  }
#endif // defined PIOD

#if defined PIOE
  if (pio == PIOE)
  {
    callbacksPioE[pos] = callback;
  }
#endif // defined PIOE

  // Configure the interrupt mode
  if (mode == CHANGE)
  {
    // Disable additional interrupt mode (detects both rising and falling edges)
    pio->PIO_AIMDR = mask;
  }
  else
  {
    // Enable additional interrupt mode
    pio->PIO_AIMER = mask;

    // Select mode of operation
    if (mode == LOW)
    {
      pio->PIO_LSR = mask;    // "Level" Select Register
      pio->PIO_FELLSR = mask; // "Falling Edge / Low Level" Select Register
    }
    if (mode == HIGH)
    {
      pio->PIO_LSR = mask;    // "Level" Select Register
      pio->PIO_REHLSR = mask; // "Rising Edge / High Level" Select Register
    }
    if (mode == FALLING)
    {
      pio->PIO_ESR = mask;    // "Edge" Select Register
      pio->PIO_FELLSR = mask; // "Falling Edge / Low Level" Select Register
    }
    if (mode == RISING)
    {
      pio->PIO_ESR = mask;    // "Edge" Select Register
      pio->PIO_REHLSR = mask; // "Rising Edge / High Level" Select Register
    }
  }

  // Enable interrupt
  pio->PIO_IER = mask;
}

void detachInterrupt(uint32_t ulPin)
{
  // Disable interrupt
  Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_IDR = g_aPinMap[ulPin].ulPin;
}

#ifdef __cplusplus
extern "C" {
#endif

#if defined PIOA
void PIOA_Handler(void)
{
  uint32_t isr = PIOA->PIO_ISR;
  uint32_t i;
  for (i=0; i<32; i++, isr>>=1)
  {
    if ((isr & 0x1) == 0)
      continue;
    if (callbacksPioA[i])
    {
      callbacksPioA[i]();
    }
  }
}
#endif // defined PIOA

#if defined PIOB
void PIOB_Handler(void)
{
  uint32_t isr = PIOB->PIO_ISR;
  uint32_t i;
  for (i=0; i<32; i++, isr>>=1)
  {
    if ((isr & 0x1) == 0)
      continue;
    if (callbacksPioB[i])
      callbacksPioB[i]();
  }
}
#endif // defined PIOB

#if defined PIOC
void PIOC_Handler(void)
{
  uint32_t isr = PIOC->PIO_ISR;
  uint32_t i;
  for (i=0; i<32; i++, isr>>=1)
  {
    if ((isr & 0x1) == 0)
      continue;
    if (callbacksPioC[i])
      callbacksPioC[i]();
  }
}
#endif // defined PIOC

#if defined PIOD
void PIOD_Handler(void)
{
  uint32_t isr = PIOD->PIO_ISR;
  uint32_t i;
  for (i=0; i<32; i++, isr>>=1)
  {
    if ((isr & 0x1) == 0)
      continue;
    if (callbacksPioD[i])
      callbacksPioD[i]();
  }
}
#endif // defined PIOD

#if defined PIOE
void PIOE_Handler(void)
{
  uint32_t isr = PIOE->PIO_ISR;
  uint32_t i;
  for (i=0; i<32; i++, isr>>=1)
  {
    if ((isr & 0x1) == 0)
      continue;
    if (callbacksPioE[i])
      callbacksPioE[i]();
  }
}
#endif // defined PIOE

#ifdef __cplusplus
}
#endif

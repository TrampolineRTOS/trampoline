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
/*
 * This file needs to be C++ because of default value of 'duration'
 * parameter in 'tone' function.
 */

#include "core_tone.hpp"

void tone(uint32_t pin, uint32_t frequency, uint32_t duration)
{
}

void noTone(uint32_t pin)
{
}

/*
#define TONE_PIN      2 // TIOA0

static Tc *chTC = TC0;
static uint32_t chNo = 0;

void configureToneTimer(void)
{
  // Configure TONE_PIN pin as timer output
  // pmc_enable_periph_clk( ID_PIOB ) ;
  int result = PIO_Configure( PIOB,
			      PIO_PERIPH_B,
			      PIO_PB25B_TIOA0,
			      PIO_DEFAULT);
  Serial.println(result);

  pmc_set_writeprotect(false);
  pmc_enable_periph_clk(ID_TC0);
  TC_Configure(chTC, chNo,
	       TC_CMR_TCCLKS_TIMER_CLOCK4 |
	       TC_CMR_WAVE |         // Waveform mode
	       TC_CMR_WAVSEL_UP_RC | // Counter running up and reset when equals to RC
	       TC_CMR_ACPA_SET |     // RA compare sets TIOA
	       TC_CMR_ACPC_CLEAR );  // RC compare clears TIOA

  chTC->TC_CHANNEL[chNo].TC_IER=TC_IER_CPCS;  // RC compare interrupt
  chTC->TC_CHANNEL[chNo].TC_IDR=~TC_IER_CPCS;
  //NVIC_EnableIRQ(TC0_IRQn);
}

void setFrequencytone(uint32_t frequency)
{
  if(frequency < 20 || frequency > 20000) {
    TC_Stop(chTC, chNo);
    return;
  }
  const uint32_t rc = VARIANT_MCK / 128 / frequency;
  const uint32_t ra = rc >> 2; // 50% duty cycle
  const uint32_t rb = ra >> 2; // 20% duty cycle

  Serial.print("rc=");Serial.println(rc);
  Serial.print("ra=");Serial.println(ra);
  Serial.print("rb=");Serial.println(rb);

  TC_Stop(chTC, chNo);
  TC_SetRC(chTC, chNo, rc);    // set frequency
  TC_SetRA(chTC, chNo, ra);
  TC_SetRB(chTC, chNo, rb);
  TC_Start(chTC, chNo);
}

//static unsigned long acc = 0;
//void TC0_Handler ( void ) {
//  Serial.println(acc++);
//}
*/

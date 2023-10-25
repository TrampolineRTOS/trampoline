/*
  Copyright (c) 2014 Arduino LLC.  All right reserved.

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

#include "Arduino.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

void watchdogEnable(uint32_t timeout)
{
  /* this assumes the slow clock is running at 32.768 kHz
   * watchdog frequency is therefore 32768 / 128 = 256 Hz
   */
  timeout = timeout * 256 / 1000;

  if (timeout == 0)
  {
    timeout = 1;
  }
  else
  {
    if (timeout > 0xFFF)
    {
      timeout = 0xFFF;
    }
  }

  WDT->WDT_MR = WDT_MR_WDRSTEN | WDT_MR_WDV(timeout) | WDT_MR_WDD(timeout) | WDT_MR_WDDBGHLT;
}

void watchdogDisable(void)
{
  WDT->WDT_MR=WDT_MR_WDDIS;
}

void watchdogReset(void)
{
  WDT->WDT_CR=WDT_CR_KEY_PASSWD|WDT_CR_WDRSTT;
}

static void _watchdogDefaultSetup(void)
{
  WDT->WDT_MR=WDT_MR_WDDIS;
}
void watchdogSetup(void) __attribute__ ((weak, alias("_watchdogDefaultSetup")));

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

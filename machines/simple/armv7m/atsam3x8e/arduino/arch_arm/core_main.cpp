/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

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

//#define ARDUINO_MAIN // TODO: check if really used somewhere outside core API
//#include <Arduino.h>
#include "core_init.h"
#include "core_delay.h"
#include "core_watchdog.h"
#if defined(USBCON)
//#include ""
#endif
#include "variant.h"
#include "CoreHardwareSerial.hpp"
#include "Arduino.h" // for setup() and loop() declarations

// Weak empty variant initialization function.
// May be redefined by variant files.
//void initVariant(void) __attribute__((weak));
//void initVariant(void) { }

/*
 * \brief Main entry point of Arduino application
 */
int main( void )
{
  /* Initialize watchdog */
  watchdogSetup();

  /* Initialize the Arduino Core API */
  init();

  /* Initialize the variant */
  initVariant();

  delay(1);
#if defined(USBCON)
  USBDevice.init();
  USBDevice.attach();
#endif

  setup();

  for (;;)
  {
    loop();
    if (serialEventRun) serialEventRun();
  }

  return 0;
}

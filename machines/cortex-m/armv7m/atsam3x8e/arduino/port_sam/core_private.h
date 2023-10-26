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

#ifndef _ARDUINO_CORE_PRIVATE_H_
#define _ARDUINO_CORE_PRIVATE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

// Includes Atmel CMSIS headers
#define __SAM3X8E__
#include "sam.h"
#include "core_variant.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * \brief Allocates a pin to a specific peripheral (GPIO mutiplexer).
 *
 * \param ulPin         pin number
 * \param ulPeripheral  peripheral
 */
int pinPeripheral( uint32_t ulPin, EGPIOType ulPeripheral );

/*
 * \brief Faster digitalRead. Assumes the pin is fully configured before.
 *
 * \param pPin         pin description, eg &g_aPinMap[ulPin]
 */
inline uint32_t digitalReadFast( const PinDescription* pPin ) __attribute__((always_inline));
inline uint32_t digitalReadFast( const PinDescription* pPin )
{
  if ( (Ports[pPin->iPort].pGPIO->PIO_PDSR & pPin->ulPin) != 0 )
  {
    return HIGH ;
  }

  return LOW ;
}

/*
 * \brief Faster digitalWrite. Assumes the pin is fully configured before.
 *
 * \param pPin         pin description, eg &g_aPinMap[ulPin]
 * \param ulVal        0 means LOW, any other value means HIGH
 */
inline void digitalWriteFast( const PinDescription* pPin, uint32_t ulVal ) __attribute__((always_inline));
inline void digitalWriteFast( const PinDescription* pPin, uint32_t ulVal )
{
  if ( ulVal )
  {
    Ports[pPin->iPort].pGPIO->PIO_SODR=pPin->ulPin;
  }
  else
  {
    Ports[pPin->iPort].pGPIO->PIO_CODR=pPin->ulPin;
  }
}


#ifdef __cplusplus
} // extern "C"

#include "CoreHardwareSerial.hpp"
#endif // __cplusplus

#endif // _ARDUINO_CORE_PRIVATE_H_

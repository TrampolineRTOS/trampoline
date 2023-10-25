/*
  Copyright (c) 2011 Arduino LLC.  All right reserved.

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
 * This file needs to be C++ because of default value of 'ulTimeout'
 * parameter in 'pulseIn' function.
 */

#ifndef _ARDUINO_CORE_PULSE_HPP_
#define _ARDUINO_CORE_PULSE_HPP_

#ifdef __cplusplus
 extern "C" {
#endif

/*
 * \brief Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse.
 */
extern uint32_t pulseIn( uint32_t ulPin, uint32_t ulState, uint32_t ulTimeout = 1000000L ) ;

#ifdef __cplusplus
}
#endif

#endif /* _ARDUINO_CORE_PULSE_HPP_ */

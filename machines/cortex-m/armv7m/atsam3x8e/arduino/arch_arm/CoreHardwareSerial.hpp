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

#ifndef _ARDUINO_CORE_HARDWARESERIAL_HPP_
#define _ARDUINO_CORE_HARDWARESERIAL_HPP_

#include <inttypes.h>

#include "CoreStream.hpp"


#define SERIAL_5N1 (HardwareSerial::Mode_5N1)
#define SERIAL_6N1 (HardwareSerial::Mode_6N1)
#define SERIAL_7N1 (HardwareSerial::Mode_7N1)
#define SERIAL_8N1 (HardwareSerial::Mode_8N1)
#define SERIAL_5N2 (HardwareSerial::Mode_5N2)
#define SERIAL_6N2 (HardwareSerial::Mode_6N2)
#define SERIAL_7N2 (HardwareSerial::Mode_7N2)
#define SERIAL_8N2 (HardwareSerial::Mode_8N2)

#define SERIAL_5E1 (HardwareSerial::Mode_5E1)
#define SERIAL_6E1 (HardwareSerial::Mode_6E1)
#define SERIAL_7E1 (HardwareSerial::Mode_7E1)
#define SERIAL_8E1 (HardwareSerial::Mode_8E1)
#define SERIAL_5E2 (HardwareSerial::Mode_5E2)
#define SERIAL_6E2 (HardwareSerial::Mode_6E2)
#define SERIAL_7E2 (HardwareSerial::Mode_7E2)
#define SERIAL_8E2 (HardwareSerial::Mode_8E2)

#define SERIAL_5O1 (HardwareSerial::Mode_5O1)
#define SERIAL_6O1 (HardwareSerial::Mode_6O1)
#define SERIAL_7O1 (HardwareSerial::Mode_7O1)
#define SERIAL_8O1 (HardwareSerial::Mode_8O1)
#define SERIAL_5O2 (HardwareSerial::Mode_5O2)
#define SERIAL_6O2 (HardwareSerial::Mode_6O2)
#define SERIAL_7O2 (HardwareSerial::Mode_7O2)
#define SERIAL_8O2 (HardwareSerial::Mode_8O2)

class HardwareSerial : public Stream
{
  public:
    enum ParityValues
    {
      HARDSER_PARITY_EVEN=0x1ul,
      HARDSER_PARITY_ODD=0x2ul,
      HARDSER_PARITY_NONE=0x3ul,
      HARDSER_PARITY_SPACE=0x4ul,
      HARDSER_PARITY_MARK=0x5ul,
      HARDSER_PARITY_MULTIDROP=0x6ul,
      HARDSER_PARITY_MASK=0xFul
    };

    enum StopValues
    {
      HARDSER_STOP_BIT_1=0x10ul,
      HARDSER_STOP_BIT_1_5=0x20ul,
      HARDSER_STOP_BIT_2=0x30ul,
      HARDSER_STOP_BIT_MASK=0xF0ul
    };

    enum DataValues
    {
      HARDSER_DATA_5=0x100ul,
      HARDSER_DATA_6=0x200ul,
      HARDSER_DATA_7=0x300ul,
      HARDSER_DATA_8=0x400ul,
      HARDSER_DATA_MASK=0xF00ul
    };

    enum UARTModes
    {
      Mode_5N1 = HARDSER_DATA_5 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_1,
      Mode_6N1 = HARDSER_DATA_6 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_1,
      Mode_7N1 = HARDSER_DATA_7 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_1,
      Mode_8N1 = HARDSER_DATA_8 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_1,
      Mode_5N2 = HARDSER_DATA_5 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_2,
      Mode_6N2 = HARDSER_DATA_6 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_2,
      Mode_7N2 = HARDSER_DATA_7 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_2,
      Mode_8N2 = HARDSER_DATA_8 | HARDSER_PARITY_NONE | HARDSER_STOP_BIT_2,
/*
      Mode_5N1 = US_MR_CHRL_5_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_1_BIT,
      Mode_6N1 = US_MR_CHRL_6_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_1_BIT,
      Mode_7N1 = US_MR_CHRL_7_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_1_BIT,
      Mode_8N1 = US_MR_CHRL_8_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_1_BIT,
      Mode_5N2 = US_MR_CHRL_5_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_2_BIT,
      Mode_6N2 = US_MR_CHRL_6_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_2_BIT,
      Mode_7N2 = US_MR_CHRL_7_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_2_BIT,
      Mode_8N2 = US_MR_CHRL_8_BIT | US_MR_PAR_NO    | US_MR_NBSTOP_2_BIT,
*/

      Mode_5E1 = HARDSER_DATA_5 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_1,
      Mode_6E1 = HARDSER_DATA_6 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_1,
      Mode_7E1 = HARDSER_DATA_7 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_1,
      Mode_8E1 = HARDSER_DATA_8 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_1,
      Mode_5E2 = HARDSER_DATA_5 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_2,
      Mode_6E2 = HARDSER_DATA_6 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_2,
      Mode_7E2 = HARDSER_DATA_7 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_2,
      Mode_8E2 = HARDSER_DATA_8 | HARDSER_PARITY_EVEN | HARDSER_STOP_BIT_2,
/*
      Mode_5E1 = US_MR_CHRL_5_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_1_BIT,
      Mode_6E1 = US_MR_CHRL_6_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_1_BIT,
      Mode_7E1 = US_MR_CHRL_7_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_1_BIT,
      Mode_8E1 = US_MR_CHRL_8_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_1_BIT,
      Mode_5E2 = US_MR_CHRL_5_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_2_BIT,
      Mode_6E2 = US_MR_CHRL_6_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_2_BIT,
      Mode_7E2 = US_MR_CHRL_7_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_2_BIT,
      Mode_8E2 = US_MR_CHRL_8_BIT | US_MR_PAR_EVEN  | US_MR_NBSTOP_2_BIT,
*/

      Mode_5O1 = HARDSER_DATA_5 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_1,
      Mode_6O1 = HARDSER_DATA_6 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_1,
      Mode_7O1 = HARDSER_DATA_7 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_1,
      Mode_8O1 = HARDSER_DATA_8 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_1,
      Mode_5O2 = HARDSER_DATA_5 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_2,
      Mode_6O2 = HARDSER_DATA_6 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_2,
      Mode_7O2 = HARDSER_DATA_7 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_2,
      Mode_8O2 = HARDSER_DATA_8 | HARDSER_PARITY_ODD | HARDSER_STOP_BIT_2,
/*
      Mode_5O1 = US_MR_CHRL_5_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_1_BIT,
      Mode_6O1 = US_MR_CHRL_6_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_1_BIT,
      Mode_7O1 = US_MR_CHRL_7_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_1_BIT,
      Mode_8O1 = US_MR_CHRL_8_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_1_BIT,
      Mode_5O2 = US_MR_CHRL_5_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_2_BIT,
      Mode_6O2 = US_MR_CHRL_6_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_2_BIT,
      Mode_7O2 = US_MR_CHRL_7_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_2_BIT,
      Mode_8O2 = US_MR_CHRL_8_BIT | US_MR_PAR_ODD   | US_MR_NBSTOP_2_BIT,
*/

      Mode_5M1 = HARDSER_DATA_5 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_1,
      Mode_6M1 = HARDSER_DATA_6 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_1,
      Mode_7M1 = HARDSER_DATA_7 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_1,
      Mode_8M1 = HARDSER_DATA_8 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_1,
      Mode_5M2 = HARDSER_DATA_5 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_2,
      Mode_6M2 = HARDSER_DATA_6 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_2,
      Mode_7M2 = HARDSER_DATA_7 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_2,
      Mode_8M2 = HARDSER_DATA_8 | HARDSER_PARITY_MARK | HARDSER_STOP_BIT_2,
/*
      Mode_5M1 = US_MR_CHRL_5_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_1_BIT,
      Mode_6M1 = US_MR_CHRL_6_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_1_BIT,
      Mode_7M1 = US_MR_CHRL_7_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_1_BIT,
      Mode_8M1 = US_MR_CHRL_8_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_1_BIT,
      Mode_5M2 = US_MR_CHRL_5_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_2_BIT,
      Mode_6M2 = US_MR_CHRL_6_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_2_BIT,
      Mode_7M2 = US_MR_CHRL_7_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_2_BIT,
      Mode_8M2 = US_MR_CHRL_8_BIT | US_MR_PAR_MARK  | US_MR_NBSTOP_2_BIT,
*/

      Mode_5S1 = HARDSER_DATA_5 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_1,
      Mode_6S1 = HARDSER_DATA_6 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_1,
      Mode_7S1 = HARDSER_DATA_7 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_1,
      Mode_8S1 = HARDSER_DATA_8 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_1,
      Mode_5S2 = HARDSER_DATA_5 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_2,
      Mode_6S2 = HARDSER_DATA_6 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_2,
      Mode_7S2 = HARDSER_DATA_7 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_2,
      Mode_8S2 = HARDSER_DATA_8 | HARDSER_PARITY_SPACE | HARDSER_STOP_BIT_2,
/*
      Mode_5S1 = US_MR_CHRL_5_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT,
      Mode_6S1 = US_MR_CHRL_6_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT,
      Mode_7S1 = US_MR_CHRL_7_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT,
      Mode_8S1 = US_MR_CHRL_8_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_1_BIT,
      Mode_5S2 = US_MR_CHRL_5_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT,
      Mode_6S2 = US_MR_CHRL_6_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT,
      Mode_7S2 = US_MR_CHRL_7_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT,
      Mode_8S2 = US_MR_CHRL_8_BIT | US_MR_PAR_SPACE | US_MR_NBSTOP_2_BIT,
*/
    };

  public:
    virtual void begin(unsigned long) = 0;
    virtual void end(void) = 0;
    virtual int available(void) = 0;
    virtual int peek(void) = 0;
    virtual int read(void) = 0;
    virtual void flush(void) = 0;
    virtual size_t write(uint8_t) = 0;
    using Print::write; // pull in write(str) and write(buf, size) from Print
    virtual operator bool() = 0;
};

extern void serialEventRun(void) __attribute__((weak));

#endif // _ARDUINO_CORE_HARDWARESERIAL_HPP_

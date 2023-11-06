/*
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

#ifndef _SAM_SERIAL_
#define _SAM_SERIAL_

#include "../arch_arm/CoreHardwareSerial.hpp"
#include "../arch_arm/CoreRingBuffer.hpp"
#include "core_variant.h"

// Includes Atmel CMSIS
#define __SAM3X8E__
#include "sam.h"

class SAMSerial : public HardwareSerial
{
  public:
    SAMSerial(Usart* pUsart, uint32_t pinRX, uint32_t pinTX, void (*irq_handler)(void), uint32_t isUART=0);

    void begin(const uint32_t dwBaudRate);
    void begin(const uint32_t dwBaudRate, const UARTModes config);
    void end(void);
    int available(void);
    int availableForWrite(void);
    int peek(void);
    int read(void);
    void flush(void);
    size_t write(const uint8_t c);
    using Print::write; // pull in write(str) and write(buf, size) from Print

    void setInterruptPriority(uint32_t priority);
    uint32_t getInterruptPriority();

    void IrqHandler(void);

    operator bool() { return true; }; // UART always active

  protected:
    void init(const uint32_t dwBaudRate, const UARTModes ulMode);
    // peripheral clock and interrupt setup
    int initClockNVIC(void);

    RingBuffer _rx_buffer;
    RingBuffer _tx_buffer;

    Usart* _pUsart;
    uint32_t _ulPinRX;
    EGPIOType _ulPinRXMux;
    uint32_t _ulPinTX;
    EGPIOType _ulPinTXMux;
    IRQn_Type _IdNVIC;
    uint8_t _uc_clockId;
    boolean _isUART;
    void (*_irq_handler)(void);
};

#endif // _SAM_SERIAL_

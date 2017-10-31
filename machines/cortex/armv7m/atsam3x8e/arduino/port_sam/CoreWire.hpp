/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@arduino.cc>. All rights reserved.
 * Copyright (c) 2016 Thibaut VIARD.  All right reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _ARDUINO_CORE_WIRE_HPP_
#define _ARDUINO_CORE_WIRE_HPP_

#include "arch_arm/CoreStream.hpp"
#include "core_variant.h"

// Includes Atmel CMSIS
#define __SAM3X8E__
#include "sam.h"

#define BUFFER_LENGTH 32

// WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1

class TwoWire : public Stream
{
  public:
    TwoWire(Twi *pTwi, uint8_t uc_pinSDA, EGPIOType uc_pinSDA_mux, uint8_t uc_pinSCL, EGPIOType uc_pinSCL_mux, void (*irq_handler)(void));
    TwoWire(Twi *pTwi, uint8_t uc_pinSDA, uint8_t uc_pinSCL, void (*irq_handler)(void));

    // I2C Master
    void begin(void);

    // I2C Slave
    void begin(uint8_t);
    void begin(int);

    void end(void);

    void setClock(uint32_t ulFrequency);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);

    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);

    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *, size_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive(void(*)(int));
    void onRequest(void(*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

    void onService(void);

  private:
    // TWI instance
    Twi *_pTwi;
    uint8_t _uc_clockId;

    uint8_t _uc_pinSDA;
    EGPIOType _uc_pinSDA_mux;
    uint8_t _uc_pinSCL;
    EGPIOType _uc_pinSCL_mux;

    IRQn_Type _IdNVIC;
    void (*_irq_handler)(void);

    // RX Buffer
    uint8_t _rxBuffer[BUFFER_LENGTH];
    uint8_t _rxBufferIndex;
    uint8_t _rxBufferLength;

    // TX Buffer
    uint8_t _txAddress;
    uint8_t _txBuffer[BUFFER_LENGTH];
    uint8_t _txBufferLength;

    // Service buffer
    uint8_t _srvBuffer[BUFFER_LENGTH];
    uint8_t _srvBufferIndex;
    uint8_t _srvBufferLength;

    // Callback user functions
    void (*onRequestCallback)(void);
    void (*onReceiveCallback)(int);

    // peripheral clock and interrupt setup
    int initClockNVIC(void);

    // low-level peripheral initialization
    void init(void);
    void deinit(void);

    // TWI state
    enum TwoWireStatus
    {
      UNINITIALIZED,
      MASTER_IDLE,
      MASTER_SEND,
      MASTER_RECV,
      SLAVE_IDLE,
      SLAVE_RECV,
      SLAVE_SEND
    };
    TwoWireStatus _status;

    // TWI clock frequency
    static const uint32_t _TWI_CLOCK = 100000;
    uint32_t _twiClock;

    // Timeouts
    static const uint32_t _RECV_TIMEOUT = 100000;
    static const uint32_t _XMIT_TIMEOUT = 100000;
};

#endif // _ARDUINO_CORE_WIRE_HPP_

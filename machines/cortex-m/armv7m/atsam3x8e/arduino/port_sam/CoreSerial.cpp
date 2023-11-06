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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CoreSerial.hpp"
#include "core_private.h"
#include "core_cortex_vectors.h"

// Constructors ////////////////////////////////////////////////////////////////

SAMSerial::SAMSerial(Usart *pUsart, uint32_t pinRX, uint32_t pinTX, void (*irq_handler)(void), uint32_t isUART)
{
  _pUsart=pUsart;

  _ulPinRX=pinRX;
  _ulPinTX=pinTX;

  _irq_handler=irq_handler;

  _isUART=isUART;
}

// Public Methods //////////////////////////////////////////////////////////////

int SAMSerial::initClockNVIC(void)
{
  _uc_clockId = 0;
  _IdNVIC=HardFault_IRQn ; // Dummy init to intercept potential error later

#if (SAM4S_SERIES || SAM4E_SERIES || SAM3XA_SERIES)
  if(_pUsart == (Usart*)UART0)
  {
    _uc_clockId = ID_UART0;
    _IdNVIC = UART0_IRQn;
  }
#if (SAM4S_SERIES)
  else if(_pUsart == (Usart*)UART1)
  {
    _uc_clockId = ID_UART1;
    _IdNVIC = UART1_IRQn;
  }
#endif /* (SAM4S_SERIES) */
  else if(_pUsart == USART0)
  {
    _uc_clockId = ID_USART0;
    _IdNVIC = USART0_IRQn;
  }
  else if(_pUsart == USART1)
  {
    _uc_clockId = ID_USART1;
    _IdNVIC = USART1_IRQn;
  }
#if (SAM3XA_SERIES)
  else if(_pUsart == USART2)
  {
    _uc_clockId = ID_USART2;
    _IdNVIC = USART2_IRQn;
  }
#endif /* (SAM3XA_SERIES) */
#endif /* (SAM4S_SERIES || SAM4E_SERIES || SAM3XA_SERIES) */

#if (SAMG55_SERIES)
  if(_pUsart == USART0)
  {
    _uc_clockId = ID_FLEXCOM0;
    _IdNVIC = FLEXCOM0_IRQn;
  }
  else if(_pUsart == USART1)
  {
    _uc_clockId = ID_FLEXCOM1;
    _IdNVIC = FLEXCOM1_IRQn;
  }
  else if(_pUsart == USART2)
  {
    _uc_clockId = ID_FLEXCOM2;
    _IdNVIC = FLEXCOM2_IRQn;
  }
  else if(_pUsart == USART3)
  {
    _uc_clockId = ID_FLEXCOM3;
    _IdNVIC = FLEXCOM3_IRQn;
  }
  else if(_pUsart == USART4)
  {
    _uc_clockId = ID_FLEXCOM4;
    _IdNVIC = FLEXCOM4_IRQn;
  }
  else if(_pUsart == USART5)
  {
    _uc_clockId = ID_FLEXCOM5;
    _IdNVIC = FLEXCOM5_IRQn;
  }
  else if(_pUsart == USART6)
  {
    _uc_clockId = ID_FLEXCOM6;
    _IdNVIC = FLEXCOM6_IRQn;
  }
#ifdef __SAMG55J19__
  else if(_pUsart == USART7) // only in SAMG55J19
  {
    _uc_clockId = ID_FLEXCOM7;
    _IdNVIC = FLEXCOM7_IRQn;
  }
#endif // __SAMG55J19__
#endif /* (SAMG55_SERIES) */

#if (SAME70_SERIES)
  if(_pUsart == (Usart*)UART0)
  {
    _uc_clockId = ID_UART0;
    _IdNVIC = UART0_IRQn;
  }
  else if(_pUsart == (Usart*)UART1)
  {
    _uc_clockId = ID_UART1;
    _IdNVIC = UART1_IRQn;
  }
  else if(_pUsart == (Usart*)UART2)
  {
    _uc_clockId = ID_UART2;
    _IdNVIC = UART2_IRQn;
  }
  else if(_pUsart == (Usart*)UART3)
  {
    _uc_clockId = ID_UART3;
    _IdNVIC = UART3_IRQn;
  }
  else if(_pUsart == (Usart*)UART4)
  {
    _uc_clockId = ID_UART4;
    _IdNVIC = UART4_IRQn;
  }
  else if(_pUsart == USART0)
  {
    _uc_clockId = ID_USART0;
    _IdNVIC = USART0_IRQn;
  }
  else if(_pUsart == USART1)
  {
    _uc_clockId = ID_USART1;
    _IdNVIC = USART1_IRQn;
  }
  else if(_pUsart == USART2)
  {
    _uc_clockId = ID_USART2;
    _IdNVIC = USART2_IRQn;
  }
#endif /* (SAME70_SERIES) */

  if ( _IdNVIC == HardFault_IRQn )
  {
    // We got a problem here
    return -1L;
  }

  // Setting NVIC configuration for this peripheral
  NVIC_DisableIRQ(_IdNVIC);
  NVIC_ClearPendingIRQ(_IdNVIC);
  NVIC_SetPriority(_IdNVIC, (1<<__NVIC_PRIO_BITS) - 1);
  NVIC_EnableIRQ(_IdNVIC);

  /* Activate Serial peripheral clock
   * All UART/USART peripheral ids are below 32, so on PCER0
   *
   * !!! NOT TRUE FOR SAME70/S70 !!!
   *
   */
  PMC->PMC_PCER0 = 1 << _uc_clockId;

#if 0
  // Activate Serial peripheral clock
  if (_uc_clockId < 32)
  {
    PMC->PMC_PCER0 = 1 << _uc_clockId;
  }
#if (SAM3XA_SERIES || SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES || SAME70_SERIES)
  else
  {
    PMC->PMC_PCER1 = 1 << (_uc_clockId-32);
  }
#endif
#endif // 0

  return 0L;
}

void SAMSerial::init(const uint32_t ulBaudrate, const UARTModes mode)
{
  uint32_t ulRegister=0;

  _ulPinRXMux=g_aPinMap[_ulPinRX].ulPinType;
  _ulPinTXMux=g_aPinMap[_ulPinTX].ulPinType;

  pinPeripheral(_ulPinRX, _ulPinRXMux);
  pinPeripheral(_ulPinTX, _ulPinTXMux);

  // Enable UART interrupt in NVIC
  initClockNVIC();

#if SAMG55_SERIES
  ((Flexcom*)((uint32_t)_pUsart-(0x200)))->FLEXCOM_MR=FLEXCOM_MR_OPMODE_USART;
#endif

  // Disable PDC channel
  _pUsart->US_PTCR = US_PTCR_RXTDIS | US_PTCR_TXTDIS;

  // Reset and disable receiver and transmitter
  _pUsart->US_CR = US_CR_RSTRX | US_CR_RSTTX | US_CR_RXDIS | US_CR_TXDIS;

  // Configure mode
  switch ( mode & HARDSER_PARITY_MASK)
  {
    case HARDSER_PARITY_EVEN:
      ulRegister|=US_MR_PAR_EVEN;
    break;

    case HARDSER_PARITY_ODD:
      ulRegister|=US_MR_PAR_ODD;
    break;

    case HARDSER_PARITY_NONE:
      ulRegister|=US_MR_PAR_NO;
   break;
  }

  switch ( mode & HARDSER_STOP_BIT_MASK)
  {
    case HARDSER_STOP_BIT_1:
      ulRegister|=US_MR_NBSTOP_1_BIT;
    break;

    case HARDSER_STOP_BIT_1_5:
      ulRegister|=US_MR_NBSTOP_1_5_BIT;
    break;

    case HARDSER_STOP_BIT_2:
      ulRegister|=US_MR_NBSTOP_2_BIT;
    break;
  }

  /* UART has CHaracter Length fixed to 8bits */
  if ( _isUART == 0)
  {
    switch ( mode & HARDSER_DATA_MASK)
    {
      case HARDSER_DATA_5:
        ulRegister|=US_MR_CHRL_5_BIT;
      break;

      case HARDSER_DATA_6:
        ulRegister|=US_MR_CHRL_6_BIT;
      break;

      case HARDSER_DATA_7:
        ulRegister|=US_MR_CHRL_7_BIT;
      break;

      case HARDSER_DATA_8:
        ulRegister|=US_MR_CHRL_8_BIT;
      break;
    }
  }

  _pUsart->US_MR = ulRegister;

  // Configure baudrate (asynchronous, no oversampling)
  // CD = (Peripheral clock) / (baudrate * 16)
  _pUsart->US_BRGR = (SystemCoreClock / ulBaudrate) >> 4;

  // Configure interrupts
  _pUsart->US_IDR = 0xFFFFFFFF;
  _pUsart->US_IER = US_IER_RXRDY | US_IER_OVRE | US_IER_FRAME;

  // Dynamic assignment of IRQ handler
  vectorAssign(_IdNVIC, _irq_handler);

  // Make sure both ring buffers are initialized back to empty.
  _rx_buffer.clear();
  _tx_buffer.clear();

  // Enable receiver and transmitter
  _pUsart->US_CR = US_CR_RXEN | US_CR_TXEN;
}

void SAMSerial::begin(const uint32_t ulBaudrate)
{
  init(ulBaudrate, SERIAL_8N1);
}

void SAMSerial::begin(const uint32_t ulBaudrate, const UARTModes mode)
{
  init(ulBaudrate, mode);
}

void SAMSerial::end( void )
{
  // Clear any received data
  _rx_buffer.clear();

  // Wait for any outstanding data to be sent
  flush();

  // Disable all UART interrupts
  _pUsart->US_IER=0;

  // Disable UART interrupt in NVIC
  NVIC_DisableIRQ(_IdNVIC);
  NVIC_ClearPendingIRQ(_IdNVIC);

  // Dynamic assignment of IRQ handler
  vectorAssign(_IdNVIC, NULL);

  /* Remove clock of Serial peripheral
   * All UART/USART peripheral ids are below 32, so on PCDR0
   */
  PMC->PMC_PCDR0 = 1 << _uc_clockId;
}

void SAMSerial::setInterruptPriority(uint32_t priority)
{
  NVIC_SetPriority(_IdNVIC, priority & 0x0F);
}

uint32_t SAMSerial::getInterruptPriority()
{
  return NVIC_GetPriority(_IdNVIC);
}

int SAMSerial::available(void)
{
  return _rx_buffer.available();
}

int SAMSerial::availableForWrite(void)
{
  int head = _tx_buffer._iHead;
  int tail = _tx_buffer._iTail;

  if (head >= tail)
  {
    return SERIAL_BUFFER_SIZE - 1 - head + tail;
  }
  else
  {
    return tail - head - 1;
  }
}

int SAMSerial::peek( void )
{
  return _rx_buffer.peek();
}

int SAMSerial::read( void )
{
  // if the head isn't ahead of the tail, we don't have any characters
  if ( _rx_buffer._iHead == _rx_buffer._iTail )
    return -1;

  uint8_t uc = _rx_buffer._aucBuffer[_rx_buffer._iTail];
  _rx_buffer._iTail = (unsigned int)(_rx_buffer._iTail + 1) % SERIAL_BUFFER_SIZE;

  return uc;
}

void SAMSerial::flush( void )
{
  while (_tx_buffer._iHead != _tx_buffer._iTail); //wait for transmit data to be sent
  // Wait for transmission to complete
  while ((_pUsart->US_CSR & US_CSR_TXRDY) != US_CSR_TXRDY)
   ;
}

size_t SAMSerial::write( const uint8_t uc_data )
{
  // Is the hardware currently busy?
  if (((_pUsart->US_CSR & US_CSR_TXRDY) != US_CSR_TXRDY) |
      (_tx_buffer._iTail != _tx_buffer._iHead))
  {
    // If busy we buffer
    /*unsigned*/ int l = (_tx_buffer._iHead + 1) % SERIAL_BUFFER_SIZE;
    while (_tx_buffer._iTail == l)
      ; // Spin locks if we're about to overwrite the buffer. This continues once the data is sent

    _tx_buffer._aucBuffer[_tx_buffer._iHead] = uc_data;
    _tx_buffer._iHead = l;
    // Make sure TX interrupt is enabled
    _pUsart->US_IER = US_IER_TXRDY;
  }
  else
  {
     // Bypass buffering and send character directly
     _pUsart->US_THR = uc_data;
  }
  return 1;
}

void SAMSerial::IrqHandler( void )
{
  uint32_t status = _pUsart->US_CSR;

  // Did we receive data?
  if ((status & US_CSR_RXRDY) == US_CSR_RXRDY)
    _rx_buffer.store_char(_pUsart->US_RHR);

  // Do we need to keep sending data?
  if ((status & US_CSR_TXRDY) == US_CSR_TXRDY)
  {
    if (_tx_buffer._iTail != _tx_buffer._iHead)
    {
      _pUsart->US_THR = _tx_buffer._aucBuffer[_tx_buffer._iTail];
      _tx_buffer._iTail = (unsigned int)(_tx_buffer._iTail + 1) % SERIAL_BUFFER_SIZE;
    }
    else
    {
      // Mask off transmit interrupt so we don't get it anymore
      _pUsart->US_IDR = US_IDR_TXRDY;
    }
  }

  // Acknowledge errors
  if ((status & US_CSR_OVRE) == US_CSR_OVRE || (status & US_CSR_FRAME) == US_CSR_FRAME)
  {
    // TODO: error reporting outside ISR
    _pUsart->US_CR |= US_CR_RSTSTA;
  }
}


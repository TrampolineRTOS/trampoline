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

#include <string.h>
#include "CoreWire.hpp"
#include "core_delay.h"
#include "core_private.h"
#include "core_cortex_vectors.h"

static inline bool TWI_FailedAcknowledge(Twi *_twi)
{
  return _twi->TWI_SR & TWI_SR_NACK;
}

static inline bool TWI_WaitTransferComplete(Twi *_twi, uint32_t _timeout)
{
  uint32_t status_reg = 0;

  while ((status_reg & TWI_SR_TXCOMP) != TWI_SR_TXCOMP)
  {
    status_reg = _twi->TWI_SR;

    if (status_reg & TWI_SR_NACK)
      return false;

    if (--_timeout == 0)
      return false;
  }
  return true;
}

static inline bool TWI_WaitByteSent(Twi *_twi, uint32_t _timeout)
{
  uint32_t status_reg = 0;

  while ((status_reg & TWI_SR_TXRDY) != TWI_SR_TXRDY)
  {
    status_reg = _twi->TWI_SR;

    if (status_reg & TWI_SR_NACK)
      return false;

    if (--_timeout == 0)
      return false;
  }

  return true;
}

static inline bool TWI_WaitByteReceived(Twi *_twi, uint32_t _timeout)
{
  uint32_t _status_reg = 0;

  while ((_status_reg & TWI_SR_RXRDY) != TWI_SR_RXRDY)
  {
    _status_reg = _twi->TWI_SR;

    if (_status_reg & TWI_SR_NACK)
      return false;

    if (--_timeout == 0)
      return false;
  }

  return true;
}

static inline bool TWI_STATUS_EOSACC(uint32_t status)
{
  return (status & TWI_SR_EOSACC) == TWI_SR_EOSACC;
}

TwoWire::TwoWire(Twi *pTwi, uint8_t uc_pinSDA, uint8_t uc_pinSCL, void (*irq_handler)(void))
{
  _pTwi=pTwi;
  _irq_handler=irq_handler;

  _uc_pinSDA=uc_pinSDA;
  _uc_pinSDA_mux=g_aPinMap[_uc_pinSDA].ulPinType;

  _uc_pinSCL=uc_pinSCL;
  _uc_pinSCL_mux=g_aPinMap[_uc_pinSCL].ulPinType;

  _rxBufferIndex=0;
  _rxBufferLength=0;

  _txAddress=0;
  _txBufferLength=0;

  _srvBufferIndex=0;
  _srvBufferLength=0;

  _status=UNINITIALIZED;
  _twiClock=_TWI_CLOCK;
}

int TwoWire::initClockNVIC(void)
{
  _uc_clockId = 0;
  _IdNVIC=HardFault_IRQn ; // Dummy init to intercept potential error later

#if (SAM4S_SERIES || SAM4E_SERIES || SAM3XA_SERIES)
  if(_pTwi == TWI0)
  {
    _uc_clockId = ID_TWI0;
    _IdNVIC = TWI0_IRQn;
  }
  else if(_pTwi == TWI1)
  {
    _uc_clockId = ID_TWI1;
    _IdNVIC = TWI1_IRQn;
  }
#endif /* (SAM4S_SERIES || SAM4E_SERIES || SAM3XA_SERIES) */

#if (SAMG55_SERIES)
  if(_pTwi == TWI0)
  {
    _uc_clockId = ID_FLEXCOM0;
    _IdNVIC = FLEXCOM0_IRQn;
  }
  else if(_pTwi == TWI1)
  {
    _uc_clockId = ID_FLEXCOM1;
    _IdNVIC = FLEXCOM1_IRQn;
  }
  else if(_pTwi == TWI2)
  {
    _uc_clockId = ID_FLEXCOM2;
    _IdNVIC = FLEXCOM2_IRQn;
  }
  else if(_pTwi == TWI3)
  {
    _uc_clockId = ID_FLEXCOM3;
    _IdNVIC = FLEXCOM3_IRQn;
  }
  else if(_pTwi == TWI4)
  {
    _uc_clockId = ID_FLEXCOM4;
    _IdNVIC = FLEXCOM4_IRQn;
  }
  else if(_pTwi == TWI5)
  {
    _uc_clockId = ID_FLEXCOM5;
    _IdNVIC = FLEXCOM5_IRQn;
  }
  else if(_pTwi == TWI6)
  {
    _uc_clockId = ID_FLEXCOM6;
    _IdNVIC = FLEXCOM6_IRQn;
  }
#ifdef __SAMG55J19__
  else if(_pTwi == TWI7) // only in SAMG55J19
  {
    _uc_clockId = ID_FLEXCOM7;
    _IdNVIC = FLEXCOM7_IRQn;
  }
#endif // __SAMG55J19__
#endif /* (SAMG55_SERIES) */

#if (SAME70_SERIES)
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

  //Setting clock
  if (_uc_clockId < 32)
  {
    PMC->PMC_PCER0 = 1 << _uc_clockId;
  }
#if (SAM3XA_SERIES || SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES)
  else
  {
    PMC->PMC_PCER1 = 1 << (_uc_clockId-32);
  }
#endif

  return 0L;
}

void TwoWire::init(void)
{
  // Assign pins to Wire interface
  pinPeripheral(_uc_pinSDA, _uc_pinSDA_mux);
  pinPeripheral(_uc_pinSCL, _uc_pinSCL_mux);

#if 0
  /* Activate Serial peripheral clock
   * All TWI peripheral ids are below 32, so on PCER0
   */
  PMC->PMC_PCER0 = 1 << WIRE_INTERFACE_ID;

#if SAMG55_SERIES
  ((Flexcom*)((uint32_t)WIRE_INTERFACE-(0x600)))->FLEXCOM_MR=FLEXCOM_MR_OPMODE_TWI;
#endif

  pinPeripheral(PIN_WIRE_SDA, PIN_WIRE_SDA_PERIPH);
  pinPeripheral(PIN_WIRE_SCL, PIN_WIRE_SCL_PERIPH);

  NVIC_DisableIRQ(WIRE_ISR_ID);
  NVIC_ClearPendingIRQ(WIRE_ISR_ID);
  NVIC_SetPriority(WIRE_ISR_ID, 0);
  NVIC_EnableIRQ(WIRE_ISR_ID);
#endif // 0

  initClockNVIC();

  // Dynamic assignment of IRQ handler
  vectorAssign(_IdNVIC, _irq_handler);
}

void TwoWire::deinit(void)
{
  NVIC_DisableIRQ(_IdNVIC);
  NVIC_ClearPendingIRQ(_IdNVIC);

  // Dynamic assignment of IRQ handler
  vectorAssign(_IdNVIC, NULL);

  //Setting clock
  if (_uc_clockId < 32)
  {
    PMC->PMC_PCDR0 = 1 << _uc_clockId;
  }
#if (SAM3XA_SERIES || SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES)
  else
  {
    PMC->PMC_PCDR1 = 1 << (_uc_clockId-32);
  }
#endif

  // Give back the pins to GPIO
  pinPeripheral(_uc_pinSDA, GPIO_NOMUX);
  pinPeripheral(_uc_pinSCL, GPIO_NOMUX);
}

void TwoWire::begin(void)
{
  init();

  // Disable PDC channel
  _pTwi->TWI_PTCR = TWI_PTCR_RXTDIS | TWI_PTCR_TXTDIS;

  /* SVEN: TWI Slave Mode Enabled */
  _pTwi->TWI_CR = TWI_CR_SVEN ;
  /* Reset the TWI */
  _pTwi->TWI_CR = TWI_CR_SWRST ;
  _pTwi->TWI_RHR ;

  /* We disable first both Slave and Master */
  _pTwi->TWI_CR = TWI_CR_SVDIS ;
  _pTwi->TWI_CR = TWI_CR_MSDIS ;

  /* Then we set the Master mode */
  _pTwi->TWI_CR = TWI_CR_MSEN ;

  setClock( _twiClock );

  _status = MASTER_IDLE;
}

// Slave mode
void TwoWire::begin(uint8_t address)
{
  init();

  // Disable PDC channel
  _pTwi->TWI_PTCR = TWI_PTCR_RXTDIS | TWI_PTCR_TXTDIS;

  /* TWI software reset */
  _pTwi->TWI_CR = TWI_CR_SWRST;
  _pTwi->TWI_RHR;

  /* Wait at least 10 ms */
  delay(10);

  /* TWI Slave Mode Disabled, TWI Master Mode Disabled*/
  _pTwi->TWI_CR = TWI_CR_SVDIS | TWI_CR_MSDIS;

  /* Configure slave address. */
  _pTwi->TWI_SMR = 0;
  _pTwi->TWI_SMR = TWI_SMR_SADR(address);

  /* SVEN: TWI Slave Mode Enabled */
  _pTwi->TWI_CR = TWI_CR_SVEN;

  /* Wait at least 10 ms */
  delay(10);

  _status = SLAVE_IDLE;
  _pTwi->TWI_IER=TWI_IER_SVACC;
  //| TWI_IER_RXRDY | TWI_IER_TXRDY	| TWI_IER_TXCOMP);
}

// Slave mode
void TwoWire::begin(int address)
{
  begin((uint8_t)address);
}

void TwoWire::end(void)
{
  /* TWI software reset */
  _pTwi->TWI_CR = TWI_CR_SWRST;
  _pTwi->TWI_RHR;

  /* Wait at least 10 ms
   * Considering 2 operations in the following loop, we can use the formula:
   * ms*F_CPU/(2*1000)
   * This is clearly approximative but less than a useless for loop with a constant max
   */
  for (uint32_t i=0; i < SystemCoreClock/(2*100); i++)
  {
    __asm("nop");
  }

  /* TWI Slave Mode Disabled, TWI Master Mode Disabled */
  _pTwi->TWI_CR = TWI_CR_SVDIS | TWI_CR_MSDIS;

  // Enable PDC channel
  #warning "todo"
//  _pTwi->TWI_PTCR &= ~(TWI_PTCR_RXTDIS | TWI_PTCR_TXTDIS);

  deinit();
}

void TwoWire::setClock(uint32_t ulFrequency)
{
  uint32_t ulCkDiv = 0 ;
  uint32_t ulClDiv ;

#if (SAMG55_SERIES || SAMS_SERIES || SAME_SERIES)
#define TWI_CLK_DELTA (3ul)
#else
#define TWI_CLK_DELTA (4ul)
#endif

  /* Configure clock */
  while (1)
  {
    ulClDiv = ((VARIANT_MCK / (2 * ulFrequency)) - TWI_CLK_DELTA) / (1<<ulCkDiv) ;

    if ( ulClDiv <= 255 )
    {
      break;
    }
    else
    {
      ulCkDiv++ ;
    }
  }

//  assert( ulCkDiv < 8 ) ;

  _pTwi->TWI_CWGR = 0 ;
  _pTwi->TWI_CWGR = (ulCkDiv << 16) | (ulClDiv << 8) | ulClDiv ;

  _twiClock = ulFrequency;
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
//  assert( (address & 0x80) == 0 ) ;

  if (quantity > BUFFER_LENGTH)
  {
    quantity = BUFFER_LENGTH;
  }

  // perform blocking read into buffer
  int bytes_read = 0;

  /* Set slave address and number of internal address bytes. */
  _pTwi->TWI_MMR = 0;
  _pTwi->TWI_MMR = (0 << 8) | TWI_MMR_MREAD | (address << 16);

  /* Set internal address bytes */
  _pTwi->TWI_IADR = 0;
  _pTwi->TWI_IADR = 0;

  /* Send START condition */
  _pTwi->TWI_CR = TWI_CR_START;

  do
  {
    // Stop condition must be set during the reception of last byte
    if (bytes_read + 1 == quantity)
    {
      _pTwi->TWI_CR |= TWI_CR_STOP;
    }

    if (TWI_WaitByteReceived(_pTwi, _RECV_TIMEOUT))
	{
      _rxBuffer[bytes_read++] = _pTwi->TWI_RHR;
    }
    else
	{
      break;
    }
  } while (bytes_read < quantity);

  TWI_WaitTransferComplete(_pTwi, _RECV_TIMEOUT);

  // set rx buffer iterator vars
  _rxBufferIndex = 0;
  _rxBufferLength = bytes_read;

  return bytes_read;
}

//uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
//{
//  return requestFrom((uint8_t) address, (uint8_t) quantity, (uint32_t) 0, (uint8_t) 0, (uint8_t) sendStop);
//}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
  return requestFrom((uint8_t) address, (uint8_t) quantity, (uint8_t) true);
}

uint8_t TwoWire::requestFrom(int address, int quantity)
{
  return requestFrom((uint8_t) address, (uint8_t) quantity, (uint8_t) true);
}

uint8_t TwoWire::requestFrom(int address, int quantity, int sendStop)
{
  return requestFrom((uint8_t) address, (uint8_t) quantity, (uint8_t) sendStop);
}

void TwoWire::beginTransmission(uint8_t address)
{
  _status = MASTER_SEND;

  // save address of target and empty buffer
  _txAddress = address;
  _txBufferLength = 0;
}

void TwoWire::beginTransmission(int address)
{
  beginTransmission((uint8_t) address);
}

//
//	Originally, 'endTransmission' was an f(void) function.
//	It has been modified to take one parameter indicating
//	whether or not a STOP should be performed on the bus.
//	Calling endTransmission(false) allows a sketch to
//	perform a repeated start.
//
//	WARNING: Nothing in the library keeps track of whether
//	the bus tenure has been properly ended with a STOP. It
//	is very possible to leave the bus in a hung state if
//	no call to endTransmission(true) is made. Some I2C
//	devices will behave oddly if they do not see a STOP.
//
uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
  uint8_t error = 0;

  // transmit buffer (blocking)
  /* Set slave address and number of internal address bytes. */
  _pTwi->TWI_MMR = 0;
  _pTwi->TWI_MMR = (0 << 8) | (_txAddress << 16);

  /* Set internal address bytes. */
  _pTwi->TWI_IADR = 0;
  _pTwi->TWI_IADR = 0;

  /* Write first byte to send.*/
  _pTwi->TWI_THR = _txBuffer[0];

  if (!TWI_WaitByteSent(_pTwi, _XMIT_TIMEOUT))
    error = 2;	// error, got NACK on address transmit

  if (error == 0)
  {
    uint16_t sent = 1;

    while (sent < _txBufferLength)
    {
      _pTwi->TWI_THR=_txBuffer[sent++];
      if (!TWI_WaitByteSent(_pTwi, _XMIT_TIMEOUT))
        error = 3;	// error, got NACK during data transmmit
    }
  }

  if (error == 0)
  {
    _pTwi->TWI_CR = TWI_CR_STOP;

    if (!TWI_WaitTransferComplete(_pTwi, _XMIT_TIMEOUT))
      error = 4;	// error, finishing up
  }

  _txBufferLength = 0;		// empty buffer
  _status = MASTER_IDLE;

  return error;
}

//	This provides backwards compatibility with the original
//	definition, and expected behaviour, of endTransmission
//
uint8_t TwoWire::endTransmission(void)
{
  return endTransmission(true);
}

size_t TwoWire::write(uint8_t data)
{
  if (_status == MASTER_SEND)
  {
    if (_txBufferLength >= BUFFER_LENGTH)
      return 0;
    _txBuffer[_txBufferLength++] = data;

    return 1;
  }
  else
  {
    if (_srvBufferLength >= BUFFER_LENGTH)
      return 0;
    _srvBuffer[_srvBufferLength++] = data;

    return 1;
  }
}

size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
  if (_status == MASTER_SEND)
  {
    for (size_t i = 0; i < quantity; ++i)
    {
      if (_txBufferLength >= BUFFER_LENGTH)
        return i;

      _txBuffer[_txBufferLength++] = data[i];
    }
  }
  else
  {
    for (size_t i = 0; i < quantity; ++i)
      {
      if (_srvBufferLength >= BUFFER_LENGTH)
        return i;

      _srvBuffer[_srvBufferLength++] = data[i];
    }
  }
  return quantity;
}

int TwoWire::available(void)
{
  return _rxBufferLength - _rxBufferIndex;
}

int TwoWire::read(void)
{
  if (_rxBufferIndex < _rxBufferLength)
  {
    return _rxBuffer[_rxBufferIndex++];
  }

  return -1;
}

int TwoWire::peek(void)
{
  if (_rxBufferIndex < _rxBufferLength)
  {
    return _rxBuffer[_rxBufferIndex];
  }

  return -1;
}

void TwoWire::flush(void)
{
  // Do nothing, use endTransmission(..) to force
  // data transfer.
}

void TwoWire::onReceive(void(*function)(int))
{
  onReceiveCallback = function;
}

void TwoWire::onRequest(void(*function)(void))
{
  onRequestCallback = function;
}

void TwoWire::onService(void)
{
  // Retrieve interrupt status
  uint32_t sr = _pTwi->TWI_SR;

  if (_status == SLAVE_IDLE && ((sr & TWI_SR_SVACC) == TWI_SR_SVACC))
  {
    _pTwi->TWI_IDR=TWI_IDR_SVACC;
    _pTwi->TWI_IER=TWI_IER_RXRDY | TWI_IER_GACC | TWI_IER_NACK
                   | TWI_IER_EOSACC | TWI_IER_SCL_WS | TWI_IER_TXCOMP;

    _srvBufferLength = 0;
    _srvBufferIndex = 0;

    // Detect if we should go into RECV or SEND status
    // SVREAD==1 means *master* reading -> SLAVE_SEND
    if ((sr & TWI_SR_SVREAD) != TWI_SR_SVREAD)
    {
      _status = SLAVE_RECV;
    }
    else
    {
      _status = SLAVE_SEND;

      // Alert calling program to generate a response ASAP
      if (onRequestCallback)
      {
        onRequestCallback();
      }
      else
      {
        // create a default 1-byte response
        write((uint8_t) 0);
      }
    }
  }

  if ((_status != SLAVE_IDLE) && ((sr & TWI_SR_EOSACC) == TWI_SR_EOSACC))
  {
      if (_status == SLAVE_RECV && onReceiveCallback)
      {
        // Copy data into rxBuffer
        // (allows to receive another packet while the
        // user program reads actual data)
        for (uint8_t i = 0; i < _srvBufferLength; ++i)
        {
          _rxBuffer[i] = _srvBuffer[i];
        }
        _rxBufferIndex = 0;
        _rxBufferLength = _srvBufferLength;

        // Alert calling program
        onReceiveCallback( _rxBufferLength);
      }

      // Transfer completed
      _pTwi->TWI_IER=TWI_SR_SVACC;
      _pTwi->TWI_IDR=TWI_IDR_RXRDY | TWI_IDR_GACC | TWI_IDR_NACK
                     | TWI_IDR_EOSACC | TWI_IDR_SCL_WS | TWI_IER_TXCOMP;
      _status = SLAVE_IDLE;
  }

  if (_status == SLAVE_RECV)
  {
    if ((sr & TWI_SR_RXRDY) == TWI_SR_RXRDY)
    {
      if (_srvBufferLength < BUFFER_LENGTH)
        _srvBuffer[_srvBufferLength++] = _pTwi->TWI_RHR;
    }
  }

  if (_status == SLAVE_SEND)
  {
    if (((sr & TWI_SR_TXRDY) == TWI_SR_TXRDY) && ((_status & TWI_SR_NACK) != TWI_SR_NACK))
    {
      uint8_t c = 'x';
      if (_srvBufferIndex < _srvBufferLength)
      {
        c = _srvBuffer[_srvBufferIndex++];
      }
      _pTwi->TWI_THR = c;
    }
  }
}

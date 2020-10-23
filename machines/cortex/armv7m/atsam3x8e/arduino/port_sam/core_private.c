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

#include "core_private.h"

int pinPeripheral( uint32_t pin, EGPIOType ulPeripheral )
{
  uint32_t mask=g_aPinMap[pin].ulPin;
  Port* pPort=(Port*)Ports+g_aPinMap[pin].iPort;

  /* Disable interrupts on the pin(s) */
  pPort->pGPIO->PIO_IDR=mask;

  /* SAM3X/3A series have two (2) peripheral multiplexer levels */
  /* SAM4S/4E/G55 series have four (4) peripheral multiplexer levels */
  switch ( ulPeripheral )
  {
    case GPIO_PERIPH_A:
#if (SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES)
      pPort->pGPIO->PIO_ABCDSR[0]&=~mask & pPort->pGPIO->PIO_ABCDSR[0];
      pPort->pGPIO->PIO_ABCDSR[1]&=~mask & pPort->pGPIO->PIO_ABCDSR[1];
#endif /* (SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES) */

#if (SAM3XA_SERIES)
      pPort->pGPIO->PIO_ABSR&=~mask & pPort->pGPIO->PIO_ABSR;
#endif /* (SAM3XA_SERIES) */
      pPort->pGPIO->PIO_PDR=mask;
    break ;

    case GPIO_PERIPH_B:
#if (SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES)
      pPort->pGPIO->PIO_ABCDSR[0]=mask | pPort->pGPIO->PIO_ABCDSR[0];
      pPort->pGPIO->PIO_ABCDSR[1]&=~mask & pPort->pGPIO->PIO_ABCDSR[1];
#endif /* (SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES) */

#if (SAM3XA_SERIES)
      pPort->pGPIO->PIO_ABSR=mask | pPort->pGPIO->PIO_ABSR;
#endif /* (SAM3XA_SERIES) */
      pPort->pGPIO->PIO_PDR=mask;
    break ;

#if !(SAM3XA_SERIES || SAMG55_SERIES)
    case GPIO_PERIPH_C:
      pPort->pGPIO->PIO_ABCDSR[0]&=~mask & pPort->pGPIO->PIO_ABCDSR[0];
      pPort->pGPIO->PIO_ABCDSR[1]=mask | pPort->pGPIO->PIO_ABCDSR[1];
      pPort->pGPIO->PIO_PDR=mask;
    break ;
#endif /* (SAM3XA_SERIES) */

#if !(SAM3XA_SERIES || SAM4E_SERIES || SAMG55_SERIES)
    case GPIO_PERIPH_D:
      pPort->pGPIO->PIO_ABCDSR[0]=mask | pPort->pGPIO->PIO_ABCDSR[0];
      pPort->pGPIO->PIO_ABCDSR[1]=mask | pPort->pGPIO->PIO_ABCDSR[1];
      pPort->pGPIO->PIO_PDR=mask;
    break ;
#endif /* (SAM3XA_SERIES) */

    // Assign the pin to GPIO
    case GPIO_NOMUX:
      pPort->pGPIO->PIO_PER=mask;
    break;

    default:
      return -1l ;
    break ;
  }

  return 0l ;
}

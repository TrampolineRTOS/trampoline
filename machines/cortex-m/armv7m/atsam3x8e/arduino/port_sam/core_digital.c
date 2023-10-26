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

#include "Arduino.h"

#ifdef __cplusplus
 extern "C" {
#endif

void pinMode( uint32_t ulPin, PinMode ulMode )
{
  /* Handle non-pin index */
	if ( ulPin >= PINS_COUNT )
  {
    return;
  }

  if ( (ulMode == INPUT) || (ulMode == INPUT_PULLUP) || (ulMode == INPUT_PULLDOWN) )
  {
    /* if all pins are OUTPUT, enable PIO Controller clocking */
    if ( Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_OSR == 0xffffffff )
    {
//      if (Ports[g_aPinMap[ulPin].iPort].ulId < 32)
      {
        PMC->PMC_PCER0 = 1 << Ports[g_aPinMap[ulPin].iPort].ulId;
      }
/*
#if (SAM3XA_SERIES || SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES)
      else
      {
        PMC->PMC_PCER1 = 1 << (Ports[g_aPinMap[ulPin].iPort].ulId-32);
      }
#endif
*/
    }
  }
  else
  {
    if ( ulMode == OUTPUT )
    {
      /* if all pins are OUTPUT, disable PIO Controller clocking, reduce power consumption */
      if ( Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_OSR == 0xffffffff )
      {
//        if (Ports[g_aPinMap[ulPin].iPort].ulId < 32)
        {
          PMC->PMC_PCDR0 = 1 << Ports[g_aPinMap[ulPin].iPort].ulId;
        }
/*
#if (SAM3XA_SERIES || SAM4S_SERIES || SAM4E_SERIES || SAMG55_SERIES)
        else
        {
          PMC->PMC_PCDR1 = 1 << (Ports[g_aPinMap[ulPin].iPort].ulId-32);
        }
#endif
*/
      }
    }
  }

  if ( (ulMode == INPUT) || (ulMode == INPUT_PULLUP) || (ulMode == INPUT_PULLDOWN) )
  {
    // Configure pin as input
    Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_ODR=g_aPinMap[ulPin].ulPin;

    // Configure pull-up
    if ( ulMode == INPUT_PULLUP )
    {
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PUER=g_aPinMap[ulPin].ulPin;
    }
    else
    {
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PUDR=g_aPinMap[ulPin].ulPin;
    }

#if !(SAM3XA_SERIES)

    // Configure pull-down
    if ( ulMode == INPUT_PULLDOWN )
    {
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PPDER=g_aPinMap[ulPin].ulPin;
    }
    else
    {
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PPDDR=g_aPinMap[ulPin].ulPin;
    }
#endif // SAM3XA_SERIES
  }
  else
  {
    if ( ulMode == OUTPUT )
    {
      // Configure pin as output
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_OER=g_aPinMap[ulPin].ulPin;
    }
  }

  /* Assign the pin to GPIO controller */
  Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PER=g_aPinMap[ulPin].ulPin;
}

void digitalWrite( uint32_t ulPin, uint32_t ulVal )
{
  /* Handle non-pin index */
  if ( ulPin >= PINS_COUNT )
  {
    return ;
  }

  /* Test if pin is under control of GPIO */
  if ( (Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PSR & g_aPinMap[ulPin].ulPin) != 0 )
  {
    /* Give the pin to GPIO controller */
    Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PER=g_aPinMap[ulPin].ulPin;
    /* Set pull-up */
    Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PUER=g_aPinMap[ulPin].ulPin;

    if ( (Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_OSR & g_aPinMap[ulPin].ulPin) != 0 )
    {
      /* Disable interrupts on the pin */
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_IDR=g_aPinMap[ulPin].ulPin;

      /* Configure pin(s) as output(s) */
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_OER=g_aPinMap[ulPin].ulPin;

      if ( ulVal )
      {
        Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_SODR=g_aPinMap[ulPin].ulPin;
      }
      else
      {
        Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_CODR=g_aPinMap[ulPin].ulPin;
      }
    }
  }
  else // Pin is configured as input, in this case we set internal pull-up resistor (yes, I know it is weird)
  {
    // Configure pull-up
    if ( ulVal == LOW )
    {
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PUDR=g_aPinMap[ulPin].ulPin;
    }
    else /* HIGH or other non-zero values */
    {
      Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PUER=g_aPinMap[ulPin].ulPin;
    }
  }
}

int digitalRead( uint32_t ulPin )
{
  /* Handle non-pin index */
  if ( ulPin >= PINS_COUNT )
  {
    return LOW ;
  }

  /* Test if pin is under control of GPIO */
  if ( (Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PSR & g_aPinMap[ulPin].ulPin) != 0 )
  {
    /* Read Output Status */
    if ( (Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_ODSR & g_aPinMap[ulPin].ulPin) != 0)
    {
      return HIGH;
    }
  }
  else // Pin is configured as input
  {
    /* Read Pin Status */
    if ( (Ports[g_aPinMap[ulPin].iPort].pGPIO->PIO_PDSR & g_aPinMap[ulPin].ulPin) != 0 )
    {
      return HIGH ;
    }
  }

  return LOW ;
}

#ifdef __cplusplus
}
#endif

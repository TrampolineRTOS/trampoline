/*
  Copyright (c) 2014 Arduino LLC.  All right reserved.

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
 * This file needs to be C++ because of overloaded 'random' and 'makeWord'
 * functions.
 */

#define __STRICT_ANSI__
#include <stdlib.h>
#undef __STRICT_ANSI__
#include "stdint.h"

#include "core_math.hpp"

void randomSeed(uint32_t seed)
{
  if ( seed != 0 )
  {
    srand( seed ) ;
  }
}

long random(long howbig)
{
  if ( howbig == 0 )
  {
    return 0;
  }

  return rand() % howbig;
}

long random(long howsmall, long howbig)
{
  if (howsmall >= howbig)
  {
    return howsmall;
  }

  long diff = howbig - howsmall;

  return random(diff) + howsmall;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t makeWord( uint16_t w )
{
  return w ;
}

uint16_t makeWord( uint8_t h, uint8_t l )
{
  return (h << 8) | l ;
}

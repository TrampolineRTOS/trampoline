//----------------------------------------------------------------------------------------------------------------------
//
//  Definition of a random function
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2023, ..., 2023 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#include "galgas-random.h"
#include "M_machine.h"

//--------------------------------------------------------------------------------------------------

#include <stdlib.h>

//--------------------------------------------------------------------------------------------------

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//--------------------------------------------------------------------------------------------------

#if (COMPILE_FOR_WINDOWS == 1) || defined (__CYGWIN__)
  int64_t galgas_random (void) {
    return rand () ;
  }
#else
  int64_t galgas_random (void) {
    return random () ;
  }
#endif

//--------------------------------------------------------------------------------------------------

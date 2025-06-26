//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#include "galgas-random.h"
#include "M_machine.h"

//--------------------------------------------------------------------------------------------------

#include <stdlib.h>

//--------------------------------------------------------------------------------------------------

static uint64_t gSeed = 0 ;

//--------------------------------------------------------------------------------------------------

void set_galgas_random_seed (const uint64_t inSeed) {
  gSeed = inSeed ;
}

//--------------------------------------------------------------------------------------------------

static uint64_t multiplyIgnoringOverflow (const uint64_t inA, const uint64_t inB) {
  uint64_t r ;
  __builtin_mul_overflow (inA, inB, &r) ;
  return r ;
}

//--------------------------------------------------------------------------------------------------

static uint64_t addIgnoringOverflow (const uint64_t inA, const uint64_t inB) {
  uint64_t r ;
  __builtin_add_overflow (inA, inB, &r) ;
  return r ;
}

//--------------------------------------------------------------------------------------------------
// https://en.wikipedia.org/wiki/Linear_congruential_generator
// ANSI C linear congruential PRNG : gSeed = gSeed * 1103515245 + 12345
// Newlib : gSeed = gSeed * 6364136223846793005 + 1
//--------------------------------------------------------------------------------------------------

uint32_t galgas_random (void) {
  gSeed = multiplyIgnoringOverflow (gSeed, 6364136223846793005) ;
  gSeed = addIgnoringOverflow (gSeed, 1) ;
  return uint32_t (gSeed) ; // Period is 2**32
}

//--------------------------------------------------------------------------------------------------

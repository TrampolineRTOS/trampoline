//----------------------------------------------------------------------------------------------------------------------
//
//  128 bits unsigned integer multiplication and division by 64 bits
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

#pragma once

#include <stdint.h>

//--------------------------------------------------------------------------------------------------

void mul64x64to128 (const uint64_t inOperand1,
                    const uint64_t inOperand2,
                    uint64_t & outProductHigh,
                    uint64_t & outProductLow) ;

//--------------------------------------------------------------------------------------------------

void div128By64 (const uint64_t inDividendH,
                 const uint64_t inDividendL,
                 const uint64_t inDivisor,
                 uint64_t & outQuotientH,
                 uint64_t & outQuotientL,
                 uint64_t & outRemainder) ;

//--------------------------------------------------------------------------------------------------

void divmod128by64 (const uint64_t inDividendH, // inDividendH < inDivisor
                    const uint64_t inDividendL,
                    const uint64_t inDivisor,
                    uint64_t & outQuotient,
                    uint64_t & outRemainder) ;

//--------------------------------------------------------------------------------------------------

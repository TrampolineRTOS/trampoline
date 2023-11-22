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

#include <stdio.h>

#include "uint128-multiply-divide.h"

//--------------------------------------------------------------------------------------------------

void mul64x64to128 (uint64_t op1,
                    uint64_t op2,
                    uint64_t & outHigh,
                    uint64_t & outLow) {
  const uint64_t u1 = (op1 & 0xffffffff) ;
  const uint64_t v1 = (op2 & 0xffffffff) ;
  uint64_t t = (u1 * v1);
  const uint64_t w3 = (t & 0xffffffff);
  uint64_t k = (t >> 32);

  op1 >>= 32;
  t = (op1 * v1) + k;
  k = (t & 0xffffffff);
  uint64_t w1 = (t >> 32);

  op2 >>= 32;
  t = (u1 * op2) + k;
  k = (t >> 32);

  outHigh = (op1 * op2) + w1 + k;
  outLow = (t << 32) + w3;
}

//--------------------------------------------------------------------------------------------------
// https://copyprogramming.com/howto/mostly-portable-128-by-64-bit-division
// https://www.codeproject.com/Tips/785014/UInt-Division-Modulus

void divmod128by64 (const uint64_t inDividendH, // inDividendH < inDivisor
                    const uint64_t inDividendL,
                    const uint64_t inDivisor,
                    uint64_t & outQuotient,
                    uint64_t & outRemainder) {
    const uint64_t b = 1ll << 32;
    uint64_t un1, un0, vn1, vn0, q1, q0, un32, un21, un10, rhat, left, right;

    const int s = __builtin_clzll (inDivisor) ;

    const uint64_t v = inDivisor << s;
    vn1 = v >> 32;
    vn0 = v & 0xffffffff;

    if (s > 0)
    {
        un32 = (inDividendH << s) | (inDividendL >> (64 - s));
        un10 = inDividendL << s;
    }
    else
    {
        un32 = inDividendH;
        un10 = inDividendL;
    }

    un1 = un10 >> 32;
    un0 = un10 & 0xffffffff;

    q1 = un32 / vn1;
    rhat = un32 % vn1;

    left = q1 * vn0;
    right = (rhat << 32) + un1;
again1:
    if ((q1 >= b) || (left > right))
    {
        --q1;
        rhat += vn1;
        if (rhat < b)
        {
            left -= vn0;
            right = (rhat << 32) | un1;
            goto again1;
        }
    }

    un21 = (un32 << 32) + (un1 - (q1 * v));

    q0 = un21 / vn1;
    rhat = un21 % vn1;

    left = q0 * vn0;
    right = (rhat << 32) | un0;
again2:
    if ((q0 >= b) || (left > right))
    {
        --q0;
        rhat += vn1;
        if (rhat < b)
        {
            left -= vn0;
            right = (rhat << 32) | un0;
            goto again2;
        }
    }

    outRemainder = ((un21 << 32) + (un0 - (q0 * v))) >> s;
    outQuotient = (q1 << 32) | q0;
}

//--------------------------------------------------------------------------------------------------

void div128By64 (const uint64_t inDividendH,
                 const uint64_t inDividendL,
                 const uint64_t inDivisor,
                 uint64_t & outQuotientH,
                 uint64_t & outQuotientL,
                 uint64_t & outRemainder) {
  outQuotientH = inDividendH / inDivisor ;
  const uint64_t rH = inDividendH % inDivisor ;
  divmod128by64 (rH, inDividendL, inDivisor, outQuotientL, outRemainder) ;
}

//--------------------------------------------------------------------------------------------------

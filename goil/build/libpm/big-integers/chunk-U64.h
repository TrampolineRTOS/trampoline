//                                           
//  MIT License
//                                           
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//                                           
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "macroAssert.h"
#include <cinttypes>

//--------------------------------------------------------------------------------------------------

typedef uint64_t ChunkUInt ;
static const ChunkUInt ChunkUIntMax = UINT64_MAX ;

static const ChunkUInt greatestPowerOf10 = 10'000'000'000'000'000'000U ; // 10**19
static const size_t greatestPowerOf10DigitCount = 19 ;

//--------------------------------------------------------------------------------------------------

inline uint32_t countLeadingZeros (const ChunkUInt inValue) {
  return uint32_t (__builtin_clzll (inValue)) ;
}

//--------------------------------------------------------------------------------------------------

#ifndef __SIZEOF_INT128__
  static const uint64_t HALF_MASK = 0xFFFF'FFFF ;
#endif

//--------------------------------------------------------------------------------------------------

#ifdef __SIZEOF_INT128__
  inline void baseMultiplication (const uint64_t inLeft,
                                  const uint64_t inRight,
                                  uint64_t & outHigh,
                                  uint64_t & outLow) {
    const __uint128_t left = inLeft ;
    const __uint128_t right = inRight ;
    const __uint128_t product = left * right ;
    outHigh = uint64_t (product >> 64) ;
    outLow = uint64_t (product) ;
  }
#else
  inline void baseMultiplication (const uint64_t inLeft,
                                  const uint64_t inRight,
                                  uint64_t & outHigh,
                                  uint64_t & outLow) {
    const uint64_t leftH = inLeft >> 32 ;
    const uint64_t leftL = (inLeft & HALF_MASK) ;
    const uint64_t rightH = inRight >> 32 ;
    const uint64_t rightL = (inRight & HALF_MASK) ;
  //--- Low word
    outLow = leftL * rightL ;
  //--- High word
    outHigh = leftH * rightH ;
  //--- First intermediate
    const uint64_t leftH_rightL = leftH * rightL ;
    const uint64_t leftH_rightL_forLowWord = leftH_rightL << 32 ;
    outLow += leftH_rightL_forLowWord ;
    outHigh += outLow < leftH_rightL_forLowWord ; // Propagate carry
    const uint64_t leftH_rightL_forHighWord = leftH_rightL >> 32 ;
    outHigh += leftH_rightL_forHighWord ; // No carry
  //--- Second intermediate
    const uint64_t leftL_rightH = leftL * rightH ;
    const uint64_t leftL_rightH_forLowWord = leftL_rightH << 32 ;
    outLow += leftL_rightH_forLowWord ;
    outHigh += outLow < leftL_rightH_forLowWord ; // Propagate carry
    const uint64_t leftL_rightH_forHighWord = leftL_rightH >> 32 ;
    outHigh += leftL_rightH_forHighWord ; // No carry
  }
#endif

//--------------------------------------------------------------------------------------------------
// https://copyprogramming.com/howto/mostly-portable-128-by-64-bit-division
// https://www.codeproject.com/Tips/785014/UInt-Division-Modulus
//--------------------------------------------------------------------------------------------------

#ifdef __SIZEOF_INT128__
  inline void divForSingleWordDivision (const uint64_t inDividendH, // inDividendH < inDivisor
                                        const uint64_t inDividendL,
                                        const uint64_t inDivisor,
                                        uint64_t & outQuotient,
                                        uint64_t & outRemainder) {
      __uint128_t dividend = inDividendH ;
      dividend <<= 64 ;
      dividend |= inDividendL ;
      outQuotient = uint64_t (dividend / inDivisor) ;
      outRemainder = uint64_t (dividend % inDivisor) ;
  }
#else
  inline void divForSingleWordDivision (const uint64_t inDividendH, // inDividendH < inDivisor
                                        const uint64_t inDividendL,
                                        const uint64_t inDivisor,
                                        uint64_t & outQuotient,
                                        uint64_t & outRemainder) {
      const uint64_t b = 1ll << 32;
      uint64_t un1, un0, vn1, vn0, q1, q0, un32, un21, un10, rhat, left, right;

      const int s = __builtin_clzll (inDivisor) ;

      const uint64_t v = inDivisor << s ;
      vn1 = v >> 32 ;
      vn0 = v & HALF_MASK;

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
      un0 = un10 & HALF_MASK;

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
#endif

//--------------------------------------------------------------------------------------------------

#ifdef __SIZEOF_INT128__
  inline uint64_t divForDivision (const uint64_t inDividendH, // inDividendH <= inDivisor
                                  const uint64_t inDividendL,
                                  const uint64_t inDivisor) { // inDivisor >= 0x'8000'0000'0000'0000
    if (inDividendH == inDivisor) {
      return ChunkUIntMax ;
    }else{
      __uint128_t dividend = inDividendH ;
      dividend <<= 64 ;
      dividend |= inDividendL ;
      return uint64_t (dividend / inDivisor) ;
    }
  }
#else
  inline uint64_t divForDivision (const uint64_t inDividendH, // inDividendH < inDivisor
                                  const uint64_t inDividendL,
                                  const uint64_t inDivisor) { // inDivisor >= 0x'8000'0000'0000'0000
      const uint64_t vn1 = inDivisor >> 32 ;
      const uint64_t vn0 = inDivisor & HALF_MASK ;
      const uint64_t un32 = inDividendH ;

      const uint64_t un1 = inDividendL >> 32;
      const uint64_t un0 = inDividendL & HALF_MASK;

      uint64_t q1 = inDividendH / vn1 ;
      uint64_t rhat = inDividendH % vn1 ;

      uint64_t left = q1 * vn0;
      uint64_t right = (rhat << 32) + un1 ;
  again1:
      if ((q1 > HALF_MASK) || (left > right)) {
          --q1 ;
          rhat += vn1;
          if (rhat <= HALF_MASK) {
              left -= vn0;
              right = (rhat << 32) | un1;
              goto again1;
          }
      }

      const uint64_t un21 = (un32 << 32) + (un1 - (q1 * inDivisor));

      uint64_t q0 = un21 / vn1;
      rhat = un21 % vn1;

      left = q0 * vn0;
      right = (rhat << 32) | un0;
  again2:
      if ((q0 > HALF_MASK) || (left > right)) {
          --q0;
          rhat += vn1;
          if (rhat <= HALF_MASK)
          {
              left -= vn0;
              right = (rhat << 32) | un0;
              goto again2;
          }
      }

    return (q1 << 32) | q0;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef __SIZEOF_INT128__
  inline uint64_t divForNaiveDivision (const uint64_t inDividendH, // inDividendH < inDivisor
                                       const uint64_t inDividendL,
                                       const uint64_t inDivisor) {
    if (inDividendH == inDivisor) {
      return ChunkUIntMax ;
    }else{
      __uint128_t dividend = inDividendH ;
      dividend <<= 64 ;
      dividend |= inDividendL ;
      return uint64_t (dividend / inDivisor) ;
    }
  }
#else
  inline uint64_t divForNaiveDivision (const uint64_t inDividendH, // inDividendH < inDivisor
                                       const uint64_t inDividendL,
                                       const uint64_t inDivisor) {
      const uint64_t b = 1ll << 32;
      uint64_t un1, un0, vn1, vn0, q1, q0, un32, un21, un10, rhat, left, right;

      const int s = __builtin_clzll (inDivisor) ;

      const uint64_t v = inDivisor << s ;
      vn1 = v >> 32 ;
      vn0 = v & HALF_MASK;

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
      un0 = un10 & HALF_MASK;

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

      return (q1 << 32) | q0;
  }
#endif

//--------------------------------------------------------------------------------------------------

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

typedef uint32_t ChunkUInt ;
static const ChunkUInt ChunkUIntMax = UINT32_MAX ;

static const ChunkUInt greatestPowerOf10 = 1'000'000'000 ; // 10**9
static const size_t greatestPowerOf10DigitCount = 9 ;

//--------------------------------------------------------------------------------------------------

inline uint32_t countLeadingZeros (const ChunkUInt inValue) {
  return uint32_t (__builtin_clzl (inValue) - 32) ;
}

//--------------------------------------------------------------------------------------------------

inline void baseMultiplication (const uint32_t inLeft,
                                const uint32_t inRight,
                                uint32_t & outHigh,
                                uint32_t & outLow) {
  const uint64_t left = inLeft ;
  const uint64_t right = inRight ;
  const uint64_t product = left * right ;
  outHigh = uint32_t (product >> 32) ;
  outLow = uint32_t (product) ;
}

//--------------------------------------------------------------------------------------------------

inline void divForSingleWordDivision (const uint32_t inDividendH, // inDividendH < inDivisor
                                      const uint32_t inDividendL,
                                      const uint32_t inDivisor,
                                      uint32_t & outQuotient,
                                      uint32_t & outRemainder) {
  macroAssert (inDividendH < inDivisor, "inDividendH error (%llu, %llu)", int64_t (inDividendH), int64_t (inDivisor)) ;
  uint64_t dividend = inDividendH ;
  dividend <<= 32 ;
  dividend |= inDividendL ;
  outQuotient = uint32_t (dividend / inDivisor) ;
  outRemainder = uint32_t (dividend % inDivisor) ;
}

//--------------------------------------------------------------------------------------------------

inline uint32_t divForNaiveDivision (const uint32_t inDividendH, // inDividendH <= inDivisor
                                     const uint32_t inDividendL,
                                     const uint32_t inDivisor) {
  if (inDividendH == inDivisor) {
    return ChunkUIntMax ;
  }else{
    macroAssert (inDividendH < inDivisor, "inDividendH error (%llx, %llx)", int64_t (inDividendH), int64_t (inDivisor)) ;
    uint64_t dividend = inDividendH ;
    dividend <<= 32 ;
    dividend |= inDividendL ;
    return uint32_t (dividend / inDivisor) ;
  }
}

//--------------------------------------------------------------------------------------------------

inline uint32_t divForDivision (const uint32_t inDividendH, // inDividendH <= inDivisor
                                const uint32_t inDividendL,
                                const uint32_t inDivisor) { // inDivisor >= 0x8000'000
  macroAssert (inDivisor > (ChunkUIntMax / 2), "Indivisor error (%llx)", int64_t (inDivisor), 0) ;
  if (inDividendH == inDivisor) {
    return ChunkUIntMax ;
  }else{
    uint64_t dividend = inDividendH ;
    dividend <<= 32 ;
    dividend |= inDividendL ;
    const uint64_t quotient = dividend / inDivisor ;
    return uint32_t (quotient) ;
  }
}

//--------------------------------------------------------------------------------------------------

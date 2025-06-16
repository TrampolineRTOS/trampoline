//--------------------------------------------------------------------------------------------------
//
//  Handling 128-bits unsigned integer                                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.
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

#include "UInt128.h"

//--------------------------------------------------------------------------------------------------

UInt128::UInt128 (void) :
mLow (0),
mHigh (0) {
}

//--------------------------------------------------------------------------------------------------

UInt128::UInt128 (const uint64_t inLow) :
mLow (inLow),
mHigh (0) {
}

//--------------------------------------------------------------------------------------------------

UInt128::UInt128 (const uint64_t inHigh, const uint64_t inLow) :
mLow (inLow),
mHigh (inHigh) {
}

//--------------------------------------------------------------------------------------------------

bool UInt128::isZero (void) const {
  return (mLow | mHigh) == 0 ;
}

//--------------------------------------------------------------------------------------------------

bool UInt128::bitAtIndex (const uint32_t inIndex) const {
  bool result = false ;
  if (inIndex < 64) {
    result = ((mLow >> inIndex) & 1) != 0 ;
  }else if (inIndex < 128) {
    result = ((mHigh >> (inIndex - 64)) & 1) != 0 ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void UInt128::setBitAtIndex (const bool inValue, const uint32_t inIndex) {
  if (inIndex < 64) {
    const uint64_t mask = ((uint64_t) 1) << inIndex ;
    if (inValue) {
      mLow |= mask ;
    }else{
      mLow &= ~mask ;
    }
  }else if (inIndex < 128) {
    const uint64_t mask = ((uint64_t) 1) << (inIndex - 64) ;
    if (inValue) {
      mHigh |= mask ;
    }else{
      mHigh &= ~mask ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

UInt128 & UInt128::operator ++ (void) {
  mLow ++ ;
  if (0 == mLow) {
    mHigh ++ ;
  }
  return *this ;
}

//--------------------------------------------------------------------------------------------------

UInt128 & UInt128::operator -- (void) {
  if (0 == mLow) {
    mHigh -- ;
  }
  mLow -- ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

void UInt128::operator += (const UInt128 & inValue) {
  const uint64_t previousLow = mLow ;
  mLow += inValue.mLow ;
  const uint64_t carry = mLow < previousLow ;
  mHigh += inValue.mHigh + carry ;
}

//--------------------------------------------------------------------------------------------------

UInt128 UInt128::operator + (const UInt128 & inValue) const {
  UInt128 result = *this ;
  result += inValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool UInt128::operator == (const UInt128 & inValue) const {
  return (mLow == inValue.mLow) && (mHigh == inValue.mHigh) ;
}

//--------------------------------------------------------------------------------------------------

bool UInt128::operator != (const UInt128 & inValue) const {
  return ! (*this == inValue) ;
}

//--------------------------------------------------------------------------------------------------

bool UInt128::operator > (const uint32_t inOperand) const {
  bool result = mHigh > 0 ;
  if (! result) {
    result = mLow > inOperand ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void UInt128::operator *= (const uint32_t inMultiplicand) {
  const uint64_t p0 = (mLow & UINT32_MAX) * inMultiplicand ;
  const uint64_t p1 = (mLow >> 32) * inMultiplicand + (p0 >> 32) ;
  const uint64_t p2 = (mHigh & UINT32_MAX) * inMultiplicand + (p1 >> 32) ;
  const uint64_t p3 = (mHigh >> 32) * inMultiplicand + (p2 >> 32) ;
  mLow = (p0 & UINT32_MAX) + (p1 << 32) ;
  mHigh = (p2 & UINT32_MAX) + (p3 << 32) ;
}

//--------------------------------------------------------------------------------------------------

void UInt128::divideBy (const uint32_t inDivisor,
                          uint32_t & outRemainder) {
  const uint64_t d3 = mHigh >> 32 ;
  const uint64_t q3 = d3 / inDivisor ; 
  const uint64_t r3 = d3 % inDivisor ; 
  const uint64_t d2 = (mHigh & UINT32_MAX) + (r3 << 32) ;
  const uint64_t q2 = d2 / inDivisor ; 
  const uint64_t r2 = d2 % inDivisor ; 
  const uint64_t d1 = (mLow >> 32) + (r2 << 32) ;
  const uint64_t q1 = d1 / inDivisor ; 
  const uint64_t r1 = d1 % inDivisor ; 
  const uint64_t d0 = (mLow & UINT32_MAX) + (r1 << 32) ;
  const uint64_t q0 = d0 / inDivisor ; 
  const uint64_t r0 = d0 % inDivisor ; 
  mHigh = (q3 << 32) + q2 ;
  mLow = (q1 << 32) + q0 ;
  outRemainder = (uint32_t) r0 ;
}

//--------------------------------------------------------------------------------------------------

void UInt128::operator /= (const uint32_t inDivisor) {
  uint32_t unusedRemainder ;
  divideBy (inDivisor, unusedRemainder) ;
}

//--------------------------------------------------------------------------------------------------

String UInt128::decimalString (void) const {
  String result ;
  if (isZero()) {
    result.appendCString ("0") ;
  }else{
    UInt128 value = *this ;
    TC_UniqueArray <uint32_t> values ;
    while (! value.isZero ()) {
      uint32_t remainder = 0 ;
      value.divideBy (1000, remainder) ;
      values.appendObject (remainder) ;
    }
    result.appendUnsigned (values.lastObject (HERE)) ;
    for (int32_t i=values.count () - 2 ; i>=0 ; i--) {
      char s [16] ;
      snprintf (s, 16, " %03u", values (i COMMA_HERE)) ;
      result.appendString (s) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void UInt128::example (void) {
  UInt128 v (1000000) ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v *= 1000000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v *= 1000000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v *= 1000000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v *= 1000000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v *= 1000000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
  v /= 1000 ;
  printf ("%s\n", v.decimalString ().cString ()) ;
}

//--------------------------------------------------------------------------------------------------

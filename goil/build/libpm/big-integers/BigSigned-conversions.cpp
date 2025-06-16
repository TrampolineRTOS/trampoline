//
//  BigSigned.cpp
//  BigUnsigned
//
//  Created by Pierre Molinaro on 08/12/2023.
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

#include "BigSigned.h"

//--------------------------------------------------------------------------------------------------

bool BigSigned::fitsInUInt32 (void) const {
  return mIsPositive && mUnsigned.fitsInUInt32 () ;
}

//--------------------------------------------------------------------------------------------------

bool BigSigned::fitsInUInt64 (void) const {
  return mIsPositive && mUnsigned.fitsInUInt64 () ;
}

//--------------------------------------------------------------------------------------------------

bool BigSigned::fitsInSInt32 (void) const {
  if (isZero ()) {
    return true ;
  }else if (mIsPositive) {
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return v <= INT32_MAX ;
  }else{
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return v <= (uint64_t (INT32_MAX) + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

bool BigSigned::fitsInSInt64 (void) const {
  if (isZero ()) {
    return true ;
  }else if (mIsPositive) {
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return v <= INT64_MAX ;
  }else{
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return v <= (uint64_t (INT64_MAX) + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

uint32_t BigSigned::uint32 (void) const {
  return mUnsigned.uint32 () ;
}

//--------------------------------------------------------------------------------------------------

uint64_t BigSigned::uint64 (void) const {
  return mUnsigned.uint64 () ;
}

//--------------------------------------------------------------------------------------------------

int32_t BigSigned::int32 (void) const {
  if (isZero ()) {
    return 0 ;
  }else if (mIsPositive) {
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return int32_t (v) ;
  }else{
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return -int32_t (v) ;
  }
}

//--------------------------------------------------------------------------------------------------

int64_t BigSigned::int64 (void) const {
  if (isZero ()) {
    return 0 ;
  }else if (mIsPositive) {
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return int64_t (v) ;
  }else{
    const uint64_t v = mUnsigned.u64AtIndex (0) ;
    return -int64_t (v) ;
  }
}

//--------------------------------------------------------------------------------------------------

uint32_t BigSigned::requiredBitCountForSignedRepresentation (void) const {
  return mUnsigned.requiredBitCountForUnsignedRepresentation () ;
}

//--------------------------------------------------------------------------------------------------

uint32_t BigSigned::requiredBitCountForUnsignedRepresentation (void) const {
  return mUnsigned.requiredBitCountForUnsignedRepresentation () ;
}

//--------------------------------------------------------------------------------------------------

void BigSigned::extractBytesForUnsignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const {
  mUnsigned.extractBytesForUnsignedRepresentation (outValue) ;
}

//--------------------------------------------------------------------------------------------------

void BigSigned::extractBytesForSignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const {
  if (mUnsigned.isZero ()) {
    outValue.appendObject (0) ;
  }else if (mIsPositive) {
    mUnsigned.extractBytesForUnsignedRepresentation (outValue) ;
    const uint8_t msb = mUnsigned.u8AtIndex (mUnsigned.u8Count () - 1) ;
    if ((msb & 0x80) != 0) {
      outValue.appendObject (0) ;
    }
  }else{
    const BigUnsigned v = mUnsigned.subtractedOneAndComplemented (mUnsigned.chunkCount ()) ;
    v.extractBytesForUnsignedRepresentation (outValue) ;
    while ((outValue.count () > 0) && (outValue.lastObject (HERE) == 0xFF)) {
      outValue.removeLastObject (HERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

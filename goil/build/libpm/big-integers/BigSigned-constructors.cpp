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
#include "galgas-random.h"

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (void) : // Zero
mIsPositive (true),
mUnsigned () {
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const bool inPositive,
                      const BigUnsigned inValue) :
mIsPositive (inPositive),
mUnsigned (inValue) {
  if (mUnsigned.isZero ()) {
    mIsPositive = true ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const bool inPositive,
                      const uint64_t inValue) :
mIsPositive (inPositive),
mUnsigned (inValue) {
  if (mUnsigned.isZero ()) {
    mIsPositive = true ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const int64_t inValue) :
mIsPositive (inValue >= 0),
mUnsigned (BigUnsigned ((inValue >= 0) ? uint64_t (inValue) : uint64_t (-inValue))) {
  if (mUnsigned.isZero ()) {
    mIsPositive = true ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const bool inPositive,
                      const size_t inByteCount,
                      const uint8_t * inSourceByteArray) :
mIsPositive (inPositive),
mUnsigned (inByteCount, inSourceByteArray) {
  if (mUnsigned.isZero ()) {
    mIsPositive = true ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const bool inPositive,
                      const size_t inU64Count,
                      const uint64_t * inSourceU64Array) :
mIsPositive (inPositive),
mUnsigned (inU64Count, inSourceU64Array) {
  if (mUnsigned.isZero ()) {
    mIsPositive = true ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const char * inString, const uint8_t inSeparator) :
mIsPositive (true),
mUnsigned (inString, inSeparator) {
  if (mUnsigned.isZero ()) {
    mIsPositive = true ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned::BigSigned (const char * inString, const BigUnsignedBase inBase, bool & outOk):
mIsPositive (true),
mUnsigned () {
  if (inString != nullptr) {
    if (inString [0] == '-') {
      mUnsigned = BigUnsigned (& inString [1], inBase, outOk) ;
      mIsPositive = mUnsigned.isZero () ;
    }else{
      mUnsigned = BigUnsigned (inString, inBase, outOk) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::powerOfTwo (const bool inPositive,
                                 const uint32_t inPowerOfTwo) {
  return BigSigned (inPositive, BigUnsigned::powerOfTwo (inPowerOfTwo)) ;
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::randomNumber (void) {
  return BigSigned ((galgas_random () & 1) != 0, BigUnsigned::randomNumber ()) ;
}

//--------------------------------------------------------------------------------------------------

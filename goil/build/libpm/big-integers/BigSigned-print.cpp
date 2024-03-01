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

#include <cinttypes>

//--------------------------------------------------------------------------------------------------

void BigSigned::printHex (const char * inName) const {
  if (isZero ()) {
    printf ("%s: 0\n", inName) ;
  }else{
    printf ("%s: [%" PRIu64 "] %s0x", inName, uint64_t (mUnsigned.u8Count ()), mIsPositive ? "" : "-") ;
    for (size_t i = mUnsigned.u64Count () ; i > 0 ; i--) {
      printf ("%016" PRIX64, mUnsigned.u64AtIndex (i-1)) ;
    }
    printf ("\n") ;
  }
}

//--------------------------------------------------------------------------------------------------

String BigSigned::decimalString (void) const {
  if (mIsPositive) {
    return mUnsigned.decimalString () ;
  }else{
    String s = "-" ;
    s.appendString (mUnsigned.decimalString ()) ;
    return s ;
  }
}

//--------------------------------------------------------------------------------------------------

String BigSigned::spacedDecimalString (const uint32_t inSeparation) const {
  if (mIsPositive) {
    return mUnsigned.spacedDecimalString (inSeparation) ;
  }else{
    String s = "-" ;
    s.appendString (mUnsigned.spacedDecimalString (inSeparation)) ;
    return s ;
  }
}

//--------------------------------------------------------------------------------------------------

String BigSigned::hexString (void) const {
  if (mIsPositive) {
    return mUnsigned.hexString () ;
  }else{
    String s = "-" ;
    s.appendString (mUnsigned.hexString ()) ;
    return s ;
  }
}

//--------------------------------------------------------------------------------------------------

String BigSigned::xString (void) const {
  if (mIsPositive) {
    return mUnsigned.xString () ;
  }else{
    String s = "-" ;
    s.appendString (mUnsigned.xString ()) ;
    return s ;
  }
}

//--------------------------------------------------------------------------------------------------

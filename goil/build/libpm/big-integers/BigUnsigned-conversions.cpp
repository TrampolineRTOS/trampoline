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

#include "BigUnsigned.h"

//--------------------------------------------------------------------------------------------------

bool BigUnsigned::fitsInUInt32 (void) const {
  return u8Count () <= 4 ;
}

//--------------------------------------------------------------------------------------------------

bool BigUnsigned::fitsInUInt64 (void) const {
  return u8Count () <= 8 ;
}

//--------------------------------------------------------------------------------------------------

uint32_t BigUnsigned::requiredBitCountForUnsignedRepresentation (void) const {
  if (isZero ()) {
    return 0 ;
  }else{
    uint32_t n = uint32_t (u8Count () - 1) * 8 ;
    uint8_t last = u8AtIndex (u8Count () - 1) ;
    macroAssert (last != 0, "last is null", 0, 0) ;
    while (last != 0) {
      n += 1 ;
      last /= 2 ;
    }
    return n ;
  }
}

//--------------------------------------------------------------------------------------------------

uint32_t BigUnsigned::uint32 (void) const {
  if (isZero ()) {
    return 0 ;
  }else{
    return uint32_t (u64AtIndex (0)) ;
  }
}

//--------------------------------------------------------------------------------------------------

uint64_t BigUnsigned::uint64 (void) const {
  if (isZero ()) {
    return 0 ;
  }else{
    return u64AtIndex (0) ;
  }
}

//--------------------------------------------------------------------------------------------------

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
#include "M_machine.h"
#include "M_SourceLocation.h"
#include "galgas-random.h"

//--------------------------------------------------------------------------------------------------

#include <cinttypes>

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Shifts
#endif

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator << (const size_t inShiftCount) const {
  return BigSigned (mIsPositive, mUnsigned << inShiftCount) ;
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator >> (const size_t inShiftCount) const {
  if (mIsPositive) {
    return BigSigned (true, mUnsigned >> inShiftCount) ;
  }else if (mUnsigned.countTrailingZeros () < inShiftCount) {
    return BigSigned (false, (mUnsigned >> inShiftCount) + 1) ;
  }else{
    return BigSigned (false, mUnsigned >> inShiftCount) ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigSigned::operator <<= (const size_t inShiftCount) {
  if (inShiftCount > 0) {
    *this = *this << inShiftCount ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigSigned::operator >>= (const size_t inShiftCount) {
  if (inShiftCount > 0) {
    *this = * this >> inShiftCount ;
  }
}

//--------------------------------------------------------------------------------------------------

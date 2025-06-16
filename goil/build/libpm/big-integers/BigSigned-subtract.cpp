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

void BigSigned::operator -= (const BigSigned inOperand) {
  if (!inOperand.isZero ()) {
    *this = *this - inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator - (const BigSigned inOperand) const {
  if (inOperand.isZero ()) {
    return *this ;
  }else if (isZero ()) {
    return - inOperand ;
  }else if (mIsPositive != inOperand.mIsPositive) { // Opposite sign, addition
    return BigSigned (mIsPositive, mUnsigned + inOperand.mUnsigned) ;
  }else if (mUnsigned < inOperand.mUnsigned) { // Same sign
    return BigSigned (!mIsPositive, inOperand.mUnsigned - mUnsigned) ;
  }else{
    return BigSigned (mIsPositive, mUnsigned - inOperand.mUnsigned) ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator - (void) const {
  if (isZero ()) {
    return BigSigned () ;
  }else{
    return BigSigned (!mIsPositive, mUnsigned) ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigSigned::negateInPlace (void) {
  if (!isZero ()) {
    mIsPositive = !mIsPositive ;
  }
}

//--------------------------------------------------------------------------------------------------

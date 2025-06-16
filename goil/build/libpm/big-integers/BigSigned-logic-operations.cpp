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
  #pragma mark Complement
#endif

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator ~ (void) const {
  if (isZero ()) {
    return BigSigned (false, 1) ; // Complement of zero is -1
  }else if (mIsPositive) { // Positive -> result is negative
    return BigSigned (false, mUnsigned + 1) ;
  }else{  // Negative -> result is positive
    return BigSigned (true, mUnsigned - 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator & (const BigSigned inOperand) const {
  if (isZero () || inOperand.isZero ()) {
    return BigSigned () ;
  }else if (mIsPositive && inOperand.mIsPositive) { // Both are positive
    return BigSigned (true, mUnsigned & inOperand.mUnsigned) ;
  }else if (!mIsPositive && !inOperand.mIsPositive) { // Both are negative
    return BigSigned (false, mUnsigned.utilityForNegativeAndNegative (inOperand.mUnsigned)) ;
  }else if (!mIsPositive && inOperand.mIsPositive) { // negative, operand is positive
    return BigSigned (true, inOperand.mUnsigned.utilityForPositiveAndNegative (mUnsigned)) ;
  }else{ // positive, operand is negative -> Result is positive
    return BigSigned (true, mUnsigned.utilityForPositiveAndNegative (inOperand.mUnsigned)) ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator | (const BigSigned inOperand) const {
  if (isZero ()) {
    return inOperand ;
  }else if (inOperand.isZero ()) {
    return *this ;
  }else if (mIsPositive && inOperand.mIsPositive) { // Both are positive
    return BigSigned (true, mUnsigned | inOperand.mUnsigned) ;
  }else if (!mIsPositive && !inOperand.mIsPositive) { // Both are negative
    return BigSigned (false, mUnsigned.utilityForNegativeOrNegative (inOperand.mUnsigned)) ;
  }else if (!mIsPositive && inOperand.mIsPositive) { // negative, operand is positive
    return BigSigned (false, inOperand.mUnsigned.utilityForPositiveOrNegative (mUnsigned)) ;
  }else{ // positive, operand is negative -> result is negative
    return BigSigned (false, mUnsigned.utilityForPositiveOrNegative (inOperand.mUnsigned)) ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned BigSigned::operator ^ (const BigSigned inOperand) const {
  if (isZero ()) {
    return inOperand ;
  }else if (inOperand.isZero ()) {
    return *this ;
  }else if (mIsPositive && inOperand.mIsPositive) { // Both are positive
    return BigSigned (true, mUnsigned ^ inOperand.mUnsigned) ;
  }else if (!mIsPositive && !inOperand.mIsPositive) { // Both are negative
    return BigSigned (true, mUnsigned.utilityForNegativeXorNegative (inOperand.mUnsigned)) ;
  }else if (!mIsPositive && inOperand.mIsPositive) { // negative, operand is positive
    return BigSigned (false, inOperand.mUnsigned.utilityForPositiveXorNegative (mUnsigned)) ;
  }else{ // positive, operand is negative -> result is negative
    return BigSigned (false, mUnsigned.utilityForPositiveXorNegative (inOperand.mUnsigned)) ;
  }
}

//--------------------------------------------------------------------------------------------------

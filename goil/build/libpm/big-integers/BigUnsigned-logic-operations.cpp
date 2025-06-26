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

BigUnsigned BigUnsigned::operator | (const BigUnsigned inOperand) const {
  if (mSharedArray.chunkCount () == 0) { // Receiver is zero
    return inOperand ;
  }else if (inOperand.mSharedArray.chunkCount () == 0) { // Operand is zero
    return *this ;
  }else{
    const size_t maxChunkCount = std::max (mSharedArray.chunkCount (), inOperand.mSharedArray.chunkCount ()) ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (maxChunkCount) ;
    const size_t minChunkCount = std::min (mSharedArray.chunkCount (), inOperand.mSharedArray.chunkCount ()) ;
    for (size_t i = 1 ; i <= minChunkCount ; i++) {
      result.mSharedArray.appendChunk (mSharedArray.chunkAtIndex (i COMMA_HERE) | inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    for (size_t i = mSharedArray.chunkCount () + 1 ; i <= maxChunkCount ; i++) {
      result.mSharedArray.appendChunk (inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    for (size_t i = inOperand.mSharedArray.chunkCount () + 1 ; i <= maxChunkCount ; i++) {
      result.mSharedArray.appendChunk (mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator ^ (const BigUnsigned inOperand) const {
  if (mSharedArray.chunkCount () == 0) { // Receiver is zero
    return inOperand ;
  }else if (inOperand.mSharedArray.chunkCount () == 0) { // Operand is zero
    return *this ;
  }else{
    const size_t maxChunkCount = std::max (mSharedArray.chunkCount (), inOperand.mSharedArray.chunkCount ()) ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (maxChunkCount) ;
    const size_t minChunkCount = std::min (mSharedArray.chunkCount (), inOperand.mSharedArray.chunkCount ()) ;
    for (size_t i = 1 ; i <= minChunkCount ; i++) {
      result.mSharedArray.appendChunk (mSharedArray.chunkAtIndex (i COMMA_HERE) ^ inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    for (size_t i = minChunkCount + 1 ; i <= inOperand.mSharedArray.chunkCount () ; i++) {
      result.mSharedArray.appendChunk (inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    for (size_t i = minChunkCount + 1 ; i <= mSharedArray.chunkCount () ; i++) {
      result.mSharedArray.appendChunk (mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    result.mSharedArray.removeLeadingZeroChunks (HERE) ;
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator & (const BigUnsigned inOperand) const {
  if ((mSharedArray.chunkCount () == 0) || (inOperand.mSharedArray.chunkCount () == 0)) {
    return BigUnsigned () ;
  }else{ // Operand are not zero
    const size_t minChunkCount = std::min (mSharedArray.chunkCount (), inOperand.mSharedArray.chunkCount ()) ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (minChunkCount) ;
    for (size_t i = 1 ; i <= minChunkCount ; i++) {
      result.mSharedArray.appendChunk (mSharedArray.chunkAtIndex (i COMMA_HERE) & inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) COMMA_HERE) ;
    }
    result.mSharedArray.removeLeadingZeroChunks (HERE) ;
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned & BigUnsigned::operator |= (const ChunkUInt inOperand) {
  if (isZero ()) {
    *this = BigUnsigned (inOperand) ;
  }else{
    mSharedArray.insulateWithChunkCapacity (chunkCount ()) ;
    const ChunkUInt v = mSharedArray.chunkAtIndex (1 COMMA_HERE) | inOperand ;
    mSharedArray.setChunkAtIndex (v, 1 COMMA_HERE) ;
  }
  return *this ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::complemented (const size_t inChunkCount) const {
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (std::max (chunkCount (), inChunkCount)) ;
  for (size_t i = 1 ; i <= chunkCount () ; i++) {
    const ChunkUInt v = ChunkUInt (~ mSharedArray.chunkAtIndex (i COMMA_HERE)) ;
    result.mSharedArray.appendChunk (v COMMA_HERE) ;
  }
  for (size_t i = chunkCount () + 1 ; i <= inChunkCount ; i++) {
    result.mSharedArray.appendChunk (ChunkUIntMax COMMA_HERE) ;
  }
  result.mSharedArray.removeLeadingZeroChunks (HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::subtractedOneAndComplemented (const size_t inChunkCount) const {
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (std::max (chunkCount (), inChunkCount)) ;
  ChunkUInt borrow = 1 ;
  for (size_t i = 1 ; i <= chunkCount () ; i++) {
    const ChunkUInt v = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt r = v - borrow ;
    borrow = v < borrow ;
    result.mSharedArray.appendChunk (~ r COMMA_HERE) ;
  }
  macroAssert (borrow == 0, "Borrow non null (%llu)", int64_t (borrow), 0) ;
  for (size_t i = chunkCount () + 1 ; i <= inChunkCount ; i++) {
    result.mSharedArray.appendChunk (ChunkUIntMax COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::utilityForNegativeOrNegative (const BigUnsigned & inOperand) const {
//  return ((*this - 1) & (inOperand - 1)) + 1 ;
  const size_t minChunkCount = std::min (chunkCount(), inOperand.chunkCount()) ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (minChunkCount + 1) ;
  ChunkUInt thisBorrow = 1 ;
  ChunkUInt operandBorrow = 1 ;
  ChunkUInt carry = 1 ;
  for (size_t i = 1 ; i <= minChunkCount ; i++) {
    const ChunkUInt thisValue = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt leftValue = thisValue - thisBorrow ;
    thisBorrow = thisValue < thisBorrow ;
    const ChunkUInt operand = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt rightValue = operand - operandBorrow ;
    operandBorrow = operand < operandBorrow ;
    const ChunkUInt r = (leftValue & rightValue) + carry ;
    carry = r < carry ;
    result.mSharedArray.appendChunk (r COMMA_HERE) ;
  }
  if (carry == 0) {
    result.mSharedArray.removeLeadingZeroChunks (HERE) ;
  }else{
    macroAssert (carry == 1, "carry != 1", 0, 0) ;
    result.mSharedArray.appendChunk (carry COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::utilityForNegativeAndNegative (const BigUnsigned & inOperand) const {
//  return ((*this - 1) | (inOperand - 1)) + 1 ;
  const size_t maxChunkCount = std::max (chunkCount(), inOperand.chunkCount()) ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (maxChunkCount + 1) ;
  ChunkUInt thisBorrow = 1 ;
  ChunkUInt operandBorrow = 1 ;
  ChunkUInt carry = 1 ;
  const size_t minChunkCount = std::min (chunkCount(), inOperand.chunkCount()) ;
  for (size_t i = 1 ; i <= minChunkCount ; i++) {
    const ChunkUInt thisValue = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt leftValue = thisValue - thisBorrow ;
    thisBorrow = thisValue < thisBorrow ;
    const ChunkUInt operandValue = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt rightValue = operandValue - operandBorrow ;
    operandBorrow = operandValue < operandBorrow ;
    ChunkUInt r = leftValue | rightValue ;
    ChunkUInt newCarry = 0 ;
    addReportingOverflow (r, carry, newCarry) ;
    carry = newCarry ;
    result.mSharedArray.appendChunk (r COMMA_HERE) ;
//    const ChunkUInt r = (leftValue | rightValue) + carry ;
//    carry = r < carry ;
//    result.mSharedArray.appendChunk (r COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= chunkCount() ; i++) {
    macroAssert (operandBorrow == 0, "operandBorrow not null", 0, 0) ;
    const ChunkUInt thisValue = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt leftValue = thisValue - thisBorrow ;
    thisBorrow = thisValue < thisBorrow ;
    const ChunkUInt r = leftValue + carry ;
    carry = r < carry ;
    result.mSharedArray.appendChunk (r COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= inOperand.chunkCount() ; i++) {
    macroAssert (thisBorrow == 0, "thisBorrow not null", 0, 0) ;
    const ChunkUInt operandValue = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt rightValue = operandValue - operandBorrow ;
    operandBorrow = operandValue < operandBorrow ;
    const ChunkUInt r = rightValue + carry ;
    carry = r < carry ;
    result.mSharedArray.appendChunk (r COMMA_HERE) ;
  }
  if (carry > 0) {
    macroAssert (carry == 1, "carry != 1", 0, 0) ;
    result.mSharedArray.appendChunk (carry COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::utilityForPositiveAndNegative (const BigUnsigned & inNegative) const {
//  return *this & inNegative.subtractedOneAndComplemented (chunkCount()) ;
  const size_t maxChunkCount = std::max (chunkCount(), inNegative.chunkCount()) ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (maxChunkCount) ;
  ChunkUInt borrow = 1 ; // 0 or 1
  const size_t minChunkCount = std::min (chunkCount(), inNegative.chunkCount()) ;
  for (size_t i = 1 ; i <= minChunkCount ; i++) {
    const ChunkUInt positive = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt negative = inNegative.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt n = negative - borrow ;
    borrow = negative < borrow ;
    const ChunkUInt andResult = positive & ~ n ;
    result.mSharedArray.appendChunk (andResult COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= chunkCount () ; i++) {
    const ChunkUInt positive = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt negative = 0 ;
    const ChunkUInt n = negative - borrow ;
    borrow = negative < borrow ;
    const ChunkUInt andResult = positive & ~ n ;
    result.mSharedArray.appendChunk (andResult COMMA_HERE) ;
  }
 // macroAssert (borrow == 0, "borrow != 0", 0, 0) ;
  result.mSharedArray.removeLeadingZeroChunks (HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::utilityForPositiveOrNegative (const BigUnsigned & inNegative) const {
//  return (complemented (inNegative.chunkCount ()) & (inNegative - 1)) + 1 ;
  const size_t maxChunkCount = std::max (chunkCount(), inNegative.chunkCount()) ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (maxChunkCount + 1) ;
  ChunkUInt carry = 1 ; // 0 or 1
  ChunkUInt borrow = 1 ; // 0 or 1
  const size_t minChunkCount = std::min (chunkCount(), inNegative.chunkCount()) ;
  for (size_t i = 1 ; i <= minChunkCount ; i++) {
    const ChunkUInt positiveComplemented = ChunkUInt (~ mSharedArray.chunkAtIndex (i COMMA_HERE)) ;
    ChunkUInt n = inNegative.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    ChunkUInt newBorrow = 0 ;
    subtractReportingOverflow (n, borrow, newBorrow) ;
    borrow = newBorrow ;
    const ChunkUInt andResult = positiveComplemented & n ;
    const ChunkUInt v = andResult + carry ;
    carry = v < carry ;
    result.mSharedArray.appendChunk (v COMMA_HERE) ;
  }
//  macroAssert (carry >= borrow, "carry, borrow error", 0, 0) ;
  for (size_t i = minChunkCount + 1 ; i <= inNegative.chunkCount() ; i++) {
    const ChunkUInt negative = inNegative.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt n = negative - borrow ;
    borrow = negative < borrow ;
    const ChunkUInt v = n + carry ;
    carry = v < carry ;
    result.mSharedArray.appendChunk (v COMMA_HERE) ;
  }
  result.mSharedArray.removeLeadingZeroChunks (HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::utilityForNegativeXorNegative (const BigUnsigned & inOperand) const {
//  return (*this - 1) ^ (inOperand - 1) ;
  const size_t maxChunkCount = std::max (chunkCount(), inOperand.chunkCount()) ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (maxChunkCount) ;
  ChunkUInt leftBorrow = 1 ;
  ChunkUInt rightBorrow = 1 ;
  const size_t minChunkCount = std::min (chunkCount(), inOperand.chunkCount()) ;
  for (size_t i = 1 ; i <= minChunkCount ; i++) {
    const ChunkUInt leftOp = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt leftValue = leftOp - leftBorrow ;
    leftBorrow = leftOp < leftBorrow ;
    const ChunkUInt rightOp = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt rightValue = rightOp - rightBorrow ;
    rightBorrow = rightOp < rightBorrow ;
    result.mSharedArray.appendChunk (leftValue ^ rightValue COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= chunkCount() ; i++) {
    const ChunkUInt leftOp = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt leftValue = leftOp - leftBorrow ;
    leftBorrow = leftOp < leftBorrow ;
    result.mSharedArray.appendChunk (leftValue COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= inOperand.chunkCount() ; i++) {
    const ChunkUInt rightOp = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt rightValue = rightOp - rightBorrow ;
    rightBorrow = rightOp < rightBorrow ;
    result.mSharedArray.appendChunk (rightValue COMMA_HERE) ;
  }
  macroAssert (rightBorrow == 0, "borrow != 0", 0, 0) ;
  macroAssert (leftBorrow == 0, "borrow != 0", 0, 0) ;
  result.mSharedArray.removeLeadingZeroChunks (HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::utilityForPositiveXorNegative (const BigUnsigned & inNegative) const {
//  const BigUnsigned r = *this ^ inNegative.subtractedOneAndComplemented (chunkCount ()) ;
//  return r.complemented (r.chunkCount ()) + 1 ;
  const size_t maxChunkCount = std::max (chunkCount(), inNegative.chunkCount()) ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (maxChunkCount + 1) ;
  ChunkUInt carry = 1 ;
  ChunkUInt borrow = 1 ;
  const size_t minChunkCount = std::min (chunkCount(), inNegative.chunkCount()) ;
  for (size_t i = 1 ; i <= minChunkCount ; i++) {
    const ChunkUInt positive = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt negative = inNegative.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt n = negative - borrow ;
    borrow = negative < borrow ;
    const ChunkUInt xorResultComplemented = ~(positive ^ ~n) ;
    const ChunkUInt v = xorResultComplemented + carry ;
    carry = v < carry ;
    result.mSharedArray.appendChunk (v COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= chunkCount() ; i++) {
    const ChunkUInt positive = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt v = positive + carry ;
    carry = v < carry ;
    result.mSharedArray.appendChunk (v COMMA_HERE) ;
  }
  for (size_t i = minChunkCount + 1 ; i <= inNegative.chunkCount() ; i++) {
    const ChunkUInt negative = inNegative.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
    const ChunkUInt n = negative - borrow ;
    borrow = negative < borrow ;
    const ChunkUInt v = n + carry ;
    carry = v < carry ;
    result.mSharedArray.appendChunk (v COMMA_HERE) ;
  }
  macroAssert (borrow == 0, "borrow != 0", 0, 0) ;
  if (carry > 0) {
    macroAssert (carry == 1, "carry != 1", 0, 0) ;
    result.mSharedArray.appendChunk (carry COMMA_HERE) ;
  }
  result.mSharedArray.removeLeadingZeroChunks (HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

size_t BigUnsigned::countTrailingZeros (void) const {
  size_t result = 0 ;
  if (!isZero ()) {
    size_t idx = 1 ;
    while (mSharedArray.chunkAtIndex (idx COMMA_HERE) == 0) {
      result += ChunkUIntBitCount ;
      idx += 1 ;
    }
    const size_t r = size_t (__builtin_ctzl (unsigned (mSharedArray.chunkAtIndex (idx COMMA_HERE)))) ;
    result += r ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

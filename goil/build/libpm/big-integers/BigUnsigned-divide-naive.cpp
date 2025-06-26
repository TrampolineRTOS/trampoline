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
#include "M_machine.h"
#include "M_SourceLocation.h"

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Divide (naive, can be very slow)
#endif

//--------------------------------------------------------------------------------------------------

BigUnsignedQuotientRemainder BigUnsigned::naiveDivideByBigUnsigned (const BigUnsigned & inDivisor) const {
  if (inDivisor.isZero ()) { // Divide by 0
    std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
    exit (1) ;
  }else if (inDivisor.isOne ()) { // Divide by 1: quotient <- dividend, remainder <- 0
    return BigUnsignedQuotientRemainder (*this, BigUnsigned ()) ;
  }else if (*this < inDivisor) { // dividend < divisor: remainder <- dividend, quotient <- 0
    return BigUnsignedQuotientRemainder (BigUnsigned (), *this) ;
  }else{ // mSharedArray.lastChunk (HERE) >= inDivisor.mSharedArray.lastChunk (HERE)
    BigUnsigned remainder = *this ;
    remainder.mSharedArray.insulateWithChunkCapacity (remainder.chunkCount () + 1) ;
    if (mSharedArray.lastChunk (HERE) >= inDivisor.mSharedArray.lastChunk (HERE)) {
      remainder.mSharedArray.appendChunk (0 COMMA_HERE) ;
    }
    const size_t quotientWordCount = remainder.mSharedArray.chunkCount () - inDivisor.mSharedArray.chunkCount () ;
    BigUnsigned quotient ;
    quotient.mSharedArray.insulateWithChunkCapacity (quotientWordCount) ;
    quotient.mSharedArray.appendRandomChunks (quotientWordCount COMMA_HERE) ;
    for (size_t quotientIndex = quotientWordCount ; quotientIndex > 0 ; quotientIndex--) {
      const size_t remainderIndexH = remainder.mSharedArray.chunkCount () + quotientIndex - quotientWordCount ;
      ChunkUInt u64Quotient = divForNaiveDivision (
        remainder.mSharedArray.chunkAtIndex (remainderIndexH COMMA_HERE), // inDividendH < inDivisor
        remainder.mSharedArray.chunkAtIndex (remainderIndexH - 1 COMMA_HERE),
        inDivisor.mSharedArray.lastChunk (HERE)
      ) ;
      if (u64Quotient > 0) {
        ChunkUInt currentCarry = 0 ;
        for (size_t i = 1 ; i <= inDivisor.mSharedArray.chunkCount () ; i++) {
          ChunkUInt resultH ;
          ChunkUInt resultL ;
          baseMultiplication (u64Quotient, inDivisor.mSharedArray.chunkAtIndex (i COMMA_HERE), resultH, resultL) ;
          resultL += currentCarry ; // Can overflow
          resultH += resultL < currentCarry ; // Propagate Overflow, no add overflowf
          currentCarry = resultH ;
          const size_t remainderIndex = i + quotientIndex - 1 ;
          const ChunkUInt r = remainder.mSharedArray.chunkAtIndex (remainderIndex COMMA_HERE) ;
          currentCarry += r < resultL ;
          macroAssert (! ((r < resultL) && (currentCarry == 0)), "double ovf", 0, 0) ;
          remainder.mSharedArray.subtractFromChunkAtIndex (resultL, remainderIndex COMMA_HERE) ;
        }
        const size_t remainderLastIndex = quotientIndex + inDivisor.mSharedArray.chunkCount () ;
        bool underflow = remainder.mSharedArray.chunkAtIndex (remainderLastIndex COMMA_HERE) < currentCarry ;
        remainder.mSharedArray.subtractFromChunkAtIndex (currentCarry, remainderLastIndex COMMA_HERE) ;
        while (underflow) {
          macroAssert (u64Quotient > 0, "Error", 0, 0) ; // Quotient is > 0, no underflow
          u64Quotient -= 1 ;
          ChunkUInt carry = 0 ; // 0 or 1
          for (size_t i = 1 ; i <= inDivisor.mSharedArray.chunkCount () ; i++) {
            const ChunkUInt v1 = remainder.mSharedArray.chunkAtIndex (i + quotientIndex - 1 COMMA_HERE) ;
            const ChunkUInt v2 = inDivisor.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
            ChunkUInt sum = v1 + v2 ;
            const ChunkUInt carry1 = sum < v1 ;
            sum += carry ;
            const ChunkUInt carry2 = sum < carry ;
            remainder.mSharedArray.setChunkAtIndex (sum, i + quotientIndex - 1 COMMA_HERE) ;
            carry = carry1 + carry2 ;
            macroAssert (carry <= 1, "Invalid carry", 0, 0) ;
          }
          ChunkUInt lastRemainderValue = remainder.mSharedArray.chunkAtIndex (remainderLastIndex COMMA_HERE) ;
          lastRemainderValue += carry ;
          carry = lastRemainderValue < carry ;
          remainder.mSharedArray.setChunkAtIndex (lastRemainderValue, remainderLastIndex COMMA_HERE) ;
          underflow = carry == 0 ;
        }
      }
      quotient.mSharedArray.setChunkAtIndex (u64Quotient, quotientIndex COMMA_HERE) ;
    }
  //--- Remove leading zeros
    remainder.mSharedArray.removeLeadingZeroChunks (HERE) ;
    return BigUnsignedQuotientRemainder (quotient, remainder) ;
  }
}

//--------------------------------------------------------------------------------------------------

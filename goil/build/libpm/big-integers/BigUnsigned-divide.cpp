//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"
#include "M_machine.h"
#include "M_SourceLocation.h"

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator /= (const BigUnsigned inDivisor) {
  const BigUnsignedQuotientRemainder r = divideByBigUnsigned (inDivisor) ;
  *this = r.quotient () ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator / (const BigUnsigned inDivisor) const {
  const BigUnsignedQuotientRemainder r = divideByBigUnsigned (inDivisor) ;
  return r.quotient () ;
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator %= (const BigUnsigned inDivisor) {
  const BigUnsignedQuotientRemainder r = divideByBigUnsigned (inDivisor) ;
  *this = r.remainder () ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator % (const BigUnsigned inDivisor) const {
  const BigUnsignedQuotientRemainder r = divideByBigUnsigned (inDivisor) ;
  return r.remainder () ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Divide
#endif

//--------------------------------------------------------------------------------------------------

BigUnsignedQuotientRemainder BigUnsigned::divideByBigUnsigned (const BigUnsigned & inDivisor) const {
  if (inDivisor.isZero ()) { // Divide by 0
    std::cout << "Error, division by zero " << __FILE__ << ":" << __LINE__ << "\n" ;
    exit (1) ;
  }else if (inDivisor.isOne ()) { // Divide by 1: quotient <- dividend, remainder <- 0
    return BigUnsignedQuotientRemainder (*this, BigUnsigned ()) ;
  }else if (*this < inDivisor) { // dividend < divisor: remainder <- dividend, quotient <- 0
    return BigUnsignedQuotientRemainder (BigUnsigned (), *this) ;
  }else{
    const uint32_t s = countLeadingZeros (inDivisor.mSharedArray.lastChunk (HERE)) ;
    macroAssert (s < ChunkUIntBitCount, "Error (0x%llx -> %llu)", int64_t (inDivisor.mSharedArray.lastChunk (HERE)), int32_t (s)) ;
    const BigUnsigned divisor = inDivisor << s ;
    BigUnsigned remainder = *this << s ;
    remainder.mSharedArray.insulateWithChunkCapacity (remainder.chunkCount () + 1) ;
    if (remainder.mSharedArray.lastChunk (HERE) >= divisor.mSharedArray.lastChunk (HERE)) {
      remainder.mSharedArray.appendChunk (0 COMMA_HERE) ;
    }
    const size_t quotientWordCount = remainder.mSharedArray.chunkCount () - divisor.mSharedArray.chunkCount () ;
    BigUnsigned quotient ;
    quotient.mSharedArray.insulateWithChunkCapacity (quotientWordCount) ;
    quotient.mSharedArray.appendRandomChunks (quotientWordCount COMMA_HERE) ;
    for (size_t quotientIndex = quotientWordCount ; quotientIndex > 0 ; quotientIndex--) {
      const size_t remainderIndexH = remainder.mSharedArray.chunkCount () + quotientIndex - quotientWordCount ;
      ChunkUInt u64Quotient = divForDivision (
        remainder.mSharedArray.chunkAtIndex (remainderIndexH COMMA_HERE), // inDividendH < divisor
        remainder.mSharedArray.chunkAtIndex (remainderIndexH - 1 COMMA_HERE),
        divisor.mSharedArray.lastChunk (HERE)
      ) ;
      if (u64Quotient > 0) {
        ChunkUInt currentCarry = 0 ;
        for (size_t i = 1 ; i <= divisor.mSharedArray.chunkCount () ; i++) {
          ChunkUInt resultH ;
          ChunkUInt resultL ;
          baseMultiplication (u64Quotient, divisor.mSharedArray.chunkAtIndex (i COMMA_HERE), resultH, resultL) ;
          addReportingOverflow (resultL, currentCarry, resultH) ;
          currentCarry = resultH ;
          const size_t remainderIndex = i + quotientIndex - 1 ;
          const ChunkUInt r = remainder.mSharedArray.chunkAtIndex (remainderIndex COMMA_HERE) ;
          currentCarry += r < resultL ;
          macroAssert (! ((r < resultL) && (currentCarry == 0)), "double ovf", 0, 0) ;
          remainder.mSharedArray.subtractFromChunkAtIndex (resultL, remainderIndex COMMA_HERE) ;
        }
        const size_t remainderLastIndex = quotientIndex + divisor.mSharedArray.chunkCount () ;
        bool underflow = remainder.mSharedArray.chunkAtIndex (remainderLastIndex COMMA_HERE) < currentCarry ;
        remainder.mSharedArray.subtractFromChunkAtIndex (currentCarry, remainderLastIndex COMMA_HERE) ;
        while (underflow) {
          macroAssert (u64Quotient > 0, "Error", 0, 0) ; // Quotient is > 0, no underflow
          u64Quotient -= 1 ;
          ChunkUInt carry = 0 ; // 0 or 1
          for (size_t i = 1 ; i <= divisor.mSharedArray.chunkCount () ; i++) {
            const ChunkUInt v1 = remainder.mSharedArray.chunkAtIndex (i + quotientIndex - 1 COMMA_HERE) ;
            const ChunkUInt v2 = divisor.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
            ChunkUInt sum = v1 ;
            ChunkUInt newCarry = 0 ;
            addReportingOverflow (sum, v2, newCarry) ;
            addReportingOverflow (sum, carry, newCarry) ;
            remainder.mSharedArray.setChunkAtIndex (sum, i + quotientIndex - 1 COMMA_HERE) ;
            carry = newCarry ;
            macroAssert (carry <= 1, "Invalid carry", 0, 0) ;
          }
          ChunkUInt lastRemainderValue = remainder.mSharedArray.chunkAtIndex (remainderLastIndex COMMA_HERE) ;
          ChunkUInt newCarry = 0 ;
          addReportingOverflow (lastRemainderValue, carry, newCarry) ;
          carry = newCarry ;
          remainder.mSharedArray.setChunkAtIndex (lastRemainderValue, remainderLastIndex COMMA_HERE) ;
          underflow = carry == 0 ;
        }
      }
      quotient.mSharedArray.setChunkAtIndex (u64Quotient, quotientIndex COMMA_HERE) ;
    }
  //--- Remove leading zeros
    remainder.mSharedArray.removeLeadingZeroChunks (HERE) ;
    remainder >>= s ;
    return BigUnsignedQuotientRemainder (quotient, remainder) ;
  }
}

//--------------------------------------------------------------------------------------------------

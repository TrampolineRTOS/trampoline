//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Add ChunkUInt
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator + (const ChunkUInt inOperand) const {
  if (inOperand == 0) {
    return *this ;
  }else if (mSharedArray.chunkCount () == 0) { // Receiver is zero
    return BigUnsigned (inOperand) ;
  }else{
    const size_t n = mSharedArray.chunkCount () ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (n + 1) ;
    ChunkUInt carry = inOperand ;
    for (size_t i = 1 ; i <= mSharedArray.chunkCount () ; i++) {
      ChunkUInt newCarry = 0 ;
      ChunkUInt sum = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
      addReportingOverflow (sum, carry, newCarry) ;
      carry = newCarry ;
      result.mSharedArray.appendChunk (sum COMMA_HERE) ;
    }
    if (carry != 0) {
      result.mSharedArray.appendChunk (carry COMMA_HERE) ;
    }
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator += (const ChunkUInt inOperand) {
  if (inOperand > 0) {
    *this = *this + inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Subtract ChunkUInt
#endif

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator -= (const ChunkUInt inOperand) {
  if (inOperand != 0) {
    *this = *this - inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator - (const ChunkUInt inOperand) const {
  if (inOperand == 0) {
    return *this ;
  }else if ((mSharedArray.chunkCount () == 1) && (mSharedArray.lastChunk (HERE) < inOperand)) {
    std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
    exit (1) ;
  }else{
    const size_t n = mSharedArray.chunkCount () ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (n) ;
    ChunkUInt carry = inOperand ;
    for (size_t i = 1 ; i <= n ; i++) {
      ChunkUInt v = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
      ChunkUInt newCarry = 0 ;
      subtractReportingOverflow (v, carry, newCarry) ;
      carry = newCarry ;
      result.mSharedArray.appendChunk (v COMMA_HERE) ;
    }
    if (carry > 0) {
      std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
      exit (1) ;
    }
    result.mSharedArray.removeLeadingZeroChunks (HERE) ;
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Multiply by ChunkUInt
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator * (const ChunkUInt inOperand) const {
  BigUnsigned result = *this ;
  result *= inOperand ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator *= (const ChunkUInt inOperand) {
  if ((inOperand == 0) || (mSharedArray.chunkCount () == 0)) {
    *this = BigUnsigned () ; // Zero
  }else{ // Operands are not zero
    const size_t n = mSharedArray.chunkCount () ;
    mSharedArray.insulateWithChunkCapacity (n + 1) ;
    ChunkUInt carry = 0 ;
    for (size_t i = 1 ; i <= n ; i++) {
    //--- multiplication 64 x 64 -> 128
      ChunkUInt high ;
      ChunkUInt low ;
      baseMultiplication (mSharedArray.chunkAtIndex (i COMMA_HERE), inOperand, high, low) ;
    //--- Add carry
      addReportingOverflow (low, carry, high) ;
    //--- Store result
      mSharedArray.setChunkAtIndex (low, i COMMA_HERE) ;
      carry = high ;
    }
    if (carry > 0) {
      mSharedArray.appendChunk (carry COMMA_HERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Divide by ChunkUInt
#endif

//--------------------------------------------------------------------------------------------------

BigUnsignedQuotientU64Remainder BigUnsigned::dividingByChunkUInt (const ChunkUInt inDivisor) const {
  if (inDivisor == 0) {
    std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
    exit (1) ;
  }else if (inDivisor == 1) {
    return BigUnsignedQuotientU64Remainder (*this, 0) ;
  }else if (mSharedArray.chunkCount () == 1) {
    return BigUnsignedQuotientU64Remainder (BigUnsigned (mSharedArray.chunkAtIndex (1 COMMA_HERE) / inDivisor),
                                            mSharedArray.chunkAtIndex (1 COMMA_HERE) % inDivisor) ;
  }else{
    const size_t n = mSharedArray.chunkCount () ;
    BigUnsigned quotient ;
    quotient.mSharedArray.insulateWithChunkCapacity (n) ;
    quotient.mSharedArray.appendRandomChunks (n COMMA_HERE) ;
    ChunkUInt remainder = 0 ;
    for (size_t i = n ; i > 0 ; i--) {
      ChunkUInt u64Quotient ;
      ChunkUInt r ;
      divForSingleWordDivision (remainder, mSharedArray.chunkAtIndex (i COMMA_HERE), inDivisor, u64Quotient, r) ;
      quotient.mSharedArray.setChunkAtIndex (u64Quotient, i COMMA_HERE) ;
      remainder = r ;
    }
    quotient.mSharedArray.removeLeadingZeroChunks (HERE) ;
    return BigUnsignedQuotientU64Remainder (quotient, remainder) ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator %= (const ChunkUInt inDivisor) {
  const BigUnsignedQuotientU64Remainder result = dividingByChunkUInt (inDivisor) ;
  *this = BigUnsigned (result.remainder ()) ;
}

//--------------------------------------------------------------------------------------------------

ChunkUInt BigUnsigned::operator % (const ChunkUInt inDivisor) const {
  const BigUnsignedQuotientU64Remainder result = dividingByChunkUInt (inDivisor) ;
  return result.remainder () ;
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator + (const BigUnsigned inOperand) const {
  if (inOperand.isZero ()) {
    return *this ;
  }else if (isZero ()) {
    return inOperand ;
  }else{
    const size_t n = mSharedArray.chunkCount () ;
    const size_t maxChunkCount = std::max (n, inOperand.mSharedArray.chunkCount ()) ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (maxChunkCount + 1) ;
    const size_t minChunkCount = std::min (n, inOperand.mSharedArray.chunkCount ()) ;
    ChunkUInt carry = 0 ; // 0 or 1
    for (size_t i = 1 ; i <= minChunkCount ; i++) {
      const ChunkUInt v1 = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
      const ChunkUInt v2 = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
      ChunkUInt sum = v1 ;
      ChunkUInt newCarry = 0 ;
      addReportingOverflow (sum, v2, newCarry) ;
      addReportingOverflow (sum, carry, newCarry) ;
      carry = newCarry ;
      result.mSharedArray.appendChunk (sum COMMA_HERE) ;
    }
    if (n < inOperand.mSharedArray.chunkCount ()) {
      for (size_t i = n + 1 ; i <= inOperand.mSharedArray.chunkCount () ; i++) {
        const ChunkUInt v2 = inOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
        const ChunkUInt sum = v2 + carry ;
        carry = sum < v2 ;
        result.mSharedArray.appendChunk (sum COMMA_HERE) ;
      }
    }else if (n > inOperand.mSharedArray.chunkCount ()) {
      for (size_t i = inOperand.mSharedArray.chunkCount () + 1 ; i <= n ; i++) {
        const ChunkUInt v2 = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
        const ChunkUInt sum = v2 + carry ;
        carry = sum < v2 ;
        result.mSharedArray.appendChunk (sum COMMA_HERE) ;
      }
    }
    if (carry != 0) {
      result.mSharedArray.appendChunk (carry COMMA_HERE) ;
    }
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator += (const BigUnsigned inOperand) {
  if (!inOperand.isZero ()) {
    *this = *this + inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::multiply (const BigUnsigned inLeft, const BigUnsigned inRight) {
  if ((inLeft.mSharedArray.chunkCount () == 0) || (inRight.mSharedArray.chunkCount () == 0)) {
    return BigUnsigned () ;
  }else{ // Operands are not zero
    BigUnsigned leftOperand ;
    BigUnsigned rightOperand ;
    if (inLeft.mSharedArray.chunkCount () < inRight.mSharedArray.chunkCount ()) {
      leftOperand = inLeft ;
      rightOperand = inRight ;
    }else{
      leftOperand = inRight ;
      rightOperand = inLeft ;
    }
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (rightOperand.mSharedArray.chunkCount () + leftOperand.mSharedArray.chunkCount ()) ;
    result.mSharedArray.appendChunks (rightOperand.mSharedArray.chunkCount () + leftOperand.mSharedArray.chunkCount (), 0 COMMA_HERE) ;
    for (size_t i = 1 ; i <= leftOperand.mSharedArray.chunkCount () ; i++) {
      const ChunkUInt leftValue = leftOperand.mSharedArray.chunkAtIndex (i COMMA_HERE) ;
      ChunkUInt carry = 0 ;
      for (size_t j = 1 ; j <= rightOperand.mSharedArray.chunkCount () ; j++) {
      //--- multiplication 64 x 64 -> 128
        ChunkUInt high ;
        ChunkUInt low ;
        baseMultiplication (leftValue, rightOperand.mSharedArray.chunkAtIndex (j COMMA_HERE), high, low) ;
      //--- Add carry
        addReportingOverflow (low, carry, high) ;
      //--- Store result
        ChunkUInt v = result.mSharedArray.chunkAtIndex (i + j - 1 COMMA_HERE) ;
        addReportingOverflow (v, low, high) ;
        result.mSharedArray.setChunkAtIndex (v, i + j - 1 COMMA_HERE) ;
        carry = high ;
      }
      size_t idx = rightOperand.mSharedArray.chunkCount () + i ;
      while (carry > 0) {
        ChunkUInt v = result.mSharedArray.chunkAtIndex (idx COMMA_HERE) ;
        v += carry ;
        carry = v < carry ;
        result.mSharedArray.setChunkAtIndex (v, idx COMMA_HERE) ;
        idx += 1 ;
      }
    }
  //--- Remove leading zeros
    result.mSharedArray.removeLeadingZeroChunks (HERE) ;
    return result ;
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator * (const BigUnsigned inOperand) const {
  return multiply (*this, inOperand) ;
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator *= (const BigUnsigned inOperand) {
  *this = multiply (*this, inOperand) ;
}

//--------------------------------------------------------------------------------------------------

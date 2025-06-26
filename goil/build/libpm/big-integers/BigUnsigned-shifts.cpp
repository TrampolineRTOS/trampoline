//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"
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

BigUnsigned BigUnsigned::operator << (const size_t inShiftCount) const {
  if ((mSharedArray.chunkCount () > 0) && (inShiftCount > 0)) {
    const size_t n = mSharedArray.chunkCount () ;
    const size_t insertedWordCount = inShiftCount / ChunkUIntBitCount ;
    BigUnsigned result ;
    result.mSharedArray.insulateWithChunkCapacity (n + insertedWordCount + 1) ;
    result.mSharedArray.appendChunks (insertedWordCount, 0 COMMA_HERE) ;
    const size_t bitShiftCount = inShiftCount % ChunkUIntBitCount ;
    if (bitShiftCount == 0) {
      for (size_t i = 1 ; i <= n ; i++) {
        const ChunkUInt v = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
        result.mSharedArray.appendChunk (v COMMA_HERE) ;
      }
    }else{
      ChunkUInt carry = 0 ;
      for (size_t i = 1 ; i <= n ; i++) {
        const ChunkUInt v = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
        result.mSharedArray.appendChunk (leftShiftIgnoringOverflow (v, bitShiftCount) | carry COMMA_HERE) ;
        carry = v >> (ChunkUIntBitCount - bitShiftCount) ;
      }
      if (carry != 0) {
        result.mSharedArray.appendChunk (carry COMMA_HERE) ;
      }
    }
    return result ;
  }else{
    return *this ;
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::operator >> (const size_t inShiftCount) const {
  if ((mSharedArray.chunkCount () > 0) && (inShiftCount > 0)) {
    const size_t n = mSharedArray.chunkCount () ;
    const size_t wordShiftCount = inShiftCount / ChunkUIntBitCount ;
    if (wordShiftCount >= n) {
      return BigUnsigned () ;
    }else{
      BigUnsigned result ;
      result.mSharedArray.insulateWithChunkCapacity (n - wordShiftCount) ;
      result.mSharedArray.appendRandomChunks (n - wordShiftCount COMMA_HERE) ;
      const uint32_t bitShiftCount = inShiftCount % ChunkUIntBitCount ;
      if (bitShiftCount > 0) {
        ChunkUInt carry = 0 ;
        for (size_t i = n ; i > wordShiftCount ; i--) {
          const ChunkUInt v = mSharedArray.chunkAtIndex (i COMMA_HERE) ;
          result.mSharedArray.setChunkAtIndex ((v >> bitShiftCount) | carry, i - wordShiftCount COMMA_HERE) ;
          carry = leftShiftIgnoringOverflow (v, ChunkUIntBitCount - bitShiftCount) ;
        }
      }else{ // wordShiftCount > 0
        for (size_t i = 1 + wordShiftCount ; i <= n ; i++) {
          result.mSharedArray.setChunkAtIndex (mSharedArray.chunkAtIndex (i COMMA_HERE), i - wordShiftCount COMMA_HERE) ;
        }
      }
      result.mSharedArray.removeLeadingZeroChunks (HERE) ;
      return result ;
    }
  }else{
    return *this ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator <<= (const size_t inShiftCount) {
  if (inShiftCount > 0) {
    *this = *this << inShiftCount ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::operator >>= (const size_t inShiftCount) {
  if (inShiftCount > 0) {
    *this = * this >> inShiftCount ;
  }
}

//--------------------------------------------------------------------------------------------------

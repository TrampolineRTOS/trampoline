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

bool BigUnsigned::bitAtIndex (const uint32_t inBitIndex) const {
  if (isZero ()) {
    return false ;
  }else if (inBitIndex < (chunkCount () * ChunkUIntBitCount)) {
    const size_t u64Index = inBitIndex / ChunkUIntBitCount + 1 ;
    const size_t bitIndex = inBitIndex % ChunkUIntBitCount ;
    return (mSharedArray.chunkAtIndex (u64Index COMMA_HERE) & (ChunkUInt (ChunkUInt (1) << bitIndex))) != 0 ;
  }else{
    return false ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::setBitAtIndex (const bool inBit, const uint32_t inBitIndex) {
  if (inBitIndex < (chunkCount () * ChunkUIntBitCount)) {
    mSharedArray.insulateWithChunkCapacity (chunkCount ()) ;
    const size_t u64Index = inBitIndex / ChunkUIntBitCount + 1 ;
    const ChunkUInt mask = ChunkUInt (ChunkUInt (1) << (inBitIndex % ChunkUIntBitCount)) ;
    const ChunkUInt v = mSharedArray.chunkAtIndex (u64Index COMMA_HERE) ;
    if (inBit) {
      mSharedArray.setChunkAtIndex (v | mask, u64Index COMMA_HERE) ;
    }else{
      mSharedArray.setChunkAtIndex (v & ~ mask, u64Index COMMA_HERE) ;
    }
  }else if (inBit) {
    const size_t u64Index = inBitIndex / ChunkUIntBitCount + 1 ;
    const ChunkUInt mask = ChunkUInt (ChunkUInt (1) << (inBitIndex % ChunkUIntBitCount)) ;
    mSharedArray.insulateWithChunkCapacity (u64Index) ;
    for (size_t i = chunkCount () + 1 ; i < u64Index ; i++) {
      mSharedArray.appendChunk (0 COMMA_HERE) ;
    }
    mSharedArray.appendChunk (mask COMMA_HERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::complementBitAtIndex (const uint32_t inBitIndex) {
  if (inBitIndex < (chunkCount () * ChunkUIntBitCount)) {
    mSharedArray.insulateWithChunkCapacity (chunkCount ()) ;
    const size_t u64Index = inBitIndex / ChunkUIntBitCount + 1 ;
    const ChunkUInt mask = ChunkUInt (ChunkUInt (1) << (inBitIndex % ChunkUIntBitCount)) ;
    const ChunkUInt v = mSharedArray.chunkAtIndex (u64Index COMMA_HERE) ;
    if ((v & mask) == 0) {
      mSharedArray.setChunkAtIndex (v | mask, u64Index COMMA_HERE) ;
    }else{
      mSharedArray.setChunkAtIndex (v & ~ mask, u64Index COMMA_HERE) ;
      mSharedArray.removeLeadingZeroChunks (HERE) ;
    }
  }else{
    const size_t u64Index = inBitIndex / ChunkUIntBitCount + 1 ;
    const ChunkUInt mask = ChunkUInt (ChunkUInt (1) << (inBitIndex % ChunkUIntBitCount)) ;
    mSharedArray.insulateWithChunkCapacity (u64Index) ;
    for (size_t i = chunkCount () + 1 ; i < u64Index ; i++) {
      mSharedArray.appendChunk (0 COMMA_HERE) ;
    }
    mSharedArray.appendChunk (mask COMMA_HERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

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

bool BigSigned::bitAtIndex (const uint32_t inBitIndex) const {
  if (mIsPositive) {
    return mUnsigned.bitAtIndex (inBitIndex) ;
  }else if (inBitIndex < (mUnsigned.chunkCount () * ChunkUIntBitCount)) {
    const BigUnsigned negated = mUnsigned.subtractedOneAndComplemented (mUnsigned.chunkCount ()) ;
    return negated.bitAtIndex (inBitIndex) ;
  }else{
    return true ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigSigned::setBitAtIndex (const bool inBit, const uint32_t inBitIndex) {
  if (mIsPositive) {
    mUnsigned.setBitAtIndex (inBit, inBitIndex) ;
  }else{
    BigUnsigned negated = mUnsigned.subtractedOneAndComplemented (1 + inBitIndex / ChunkUIntBitCount) ;
    negated.setBitAtIndex (inBit, inBitIndex) ;
    mUnsigned = negated.complemented (negated.chunkCount ()) ;
    mUnsigned += 1 ;
  }
}

//--------------------------------------------------------------------------------------------------

void BigSigned::complementBitAtIndex (const uint32_t inBitIndex) {
  if (mIsPositive) {
    mUnsigned.complementBitAtIndex (inBitIndex) ;
  }else{
    const bool bit = bitAtIndex (inBitIndex) ;
    setBitAtIndex (!bit, inBitIndex) ;
  }
}

//--------------------------------------------------------------------------------------------------

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
#include "galgas-random.h"

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::randomNumber (void) {
  const size_t MAX_BYTE_SIZE = 160 ;
  const size_t randomByteCount = 1 + galgas_random () % MAX_BYTE_SIZE ;
  uint8_t array [MAX_BYTE_SIZE] ;
  for (size_t i = 0 ; i < randomByteCount ; i ++) {
    array [i] = uint8_t (galgas_random ()) ;
  }
  return BigUnsigned (randomByteCount, array) ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned::BigUnsigned (void) :
mSharedArray () {
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::powerOfTwo (const uint32_t inPowerOfTwo) {
  const size_t wordCount = 1 + inPowerOfTwo / ChunkUIntBitCount ;
  const int32_t bitIndex = inPowerOfTwo % ChunkUIntBitCount ;
  BigUnsigned result ;
  result.mSharedArray.insulateWithChunkCapacity (wordCount) ;
  result.mSharedArray.appendChunks (wordCount - 1, 0 COMMA_HERE) ;
  result.mSharedArray.appendChunk (ChunkUInt (ChunkUInt (1) << bitIndex) COMMA_HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned::BigUnsigned (const char * inString, const BigUnsignedBase inBase, bool & outOk) :
mSharedArray () {
  outOk = true ;
  if (inString != nullptr) {
    switch (inBase) {
    case BigUnsignedBase::two :
      { size_t accumulatorIndex = 0 ;
        size_t stringIndex = 0 ;
        ChunkUInt accumulator = 0 ;
        while (inString [stringIndex] != '\0') {
          const char c = inString [stringIndex] ;
          stringIndex += 1 ;
          if ((c >= '0') && (c <= '1')) {
            accumulator *= 2 ;
            accumulator |= ChunkUInt (c - '0') ;
            accumulatorIndex += 1 ;
            if (accumulatorIndex == ChunkUIntBitCount) {
              accumulatorIndex = 0 ;
              *this <<= ChunkUIntBitCount ;
              *this |= accumulator ;
              accumulator = 0 ;
            }
          }else{
            outOk = false ;
          }
        }
        if (accumulatorIndex > 0) {
          *this <<= accumulatorIndex ;
          *this |= accumulator ;
        }
      }
      break ;
    case BigUnsignedBase::ten :
      { size_t accumulatorIndex = 0 ;
        size_t stringIndex = 0 ;
        ChunkUInt accumulator = 0 ;
        while (inString [stringIndex] != '\0') {
          const char c = inString [stringIndex] ;
          stringIndex += 1 ;
          if ((c >= '0') && (c <= '9')) {
            accumulator *= 10 ;
            accumulator += ChunkUInt (c - '0') ;
            accumulatorIndex += 1 ;
            if (accumulatorIndex == greatestPowerOf10DigitCount) {
              accumulatorIndex = 0 ;
              *this *= greatestPowerOf10 ;
              *this += accumulator ;
              accumulator = 0 ;
            }
          }else{
            outOk = false ;
          }
        }
        if (accumulatorIndex > 0) {
          ChunkUInt multiplier = 10 ;
          for (size_t i = 1 ; i < accumulatorIndex ; i++) {
            multiplier *= 10 ;
          }
          *this *= multiplier ;
          *this += accumulator ;
        }
      }
      break ;
    case BigUnsignedBase::sixteen :
      { size_t accumulatorIndex = 0 ;
        size_t stringIndex = 0 ;
        ChunkUInt accumulator = 0 ;
        while (inString [stringIndex] != '\0') {
          const char c = inString [stringIndex] ;
          stringIndex += 1 ;
          accumulator <<= 4 ;
          if ((c >= '0') && (c <= '9')) {
            accumulator |= ChunkUInt (c - '0') ;
          }else if ((c >= 'A') && (c <= 'F')) {
            accumulator |= ChunkUInt (c + 10 - 'A') ;
          }else if ((c >= 'a') && (c <= 'f')) {
            accumulator |= ChunkUInt (c + 10 - 'a') ;
          }else{
            outOk = false ;
          }
          accumulatorIndex += 4 ;
          if (accumulatorIndex == ChunkUIntBitCount) {
            accumulatorIndex = 0 ;
            *this <<= ChunkUIntBitCount ;
            *this |= accumulator ;
            accumulator = 0 ;
          }
        }
        if (accumulatorIndex > 0) {
          *this <<= accumulatorIndex ;
          *this |= accumulator ;
        }
      }
      break ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned::BigUnsigned (const char * inString, const uint8_t inSeparator) :
mSharedArray () {
  if (inString != nullptr) {
    size_t idx = 0 ;
    ChunkUInt accumulator = 0 ;
    size_t stringIndex = 0 ;
    while (inString [stringIndex] != '\0') {
      const char c = inString [stringIndex] ;
      stringIndex += 1 ;
      if ((c >= '0') && (c <= '9')) {
        accumulator *= 10 ;
        accumulator += ChunkUInt (c - '0') ;
        idx += 1 ;
        if (idx == greatestPowerOf10DigitCount) {
          idx = 0 ;
          *this *= greatestPowerOf10 ;
          *this += accumulator ;
          accumulator = 0 ;
        }
      }else if (c != inSeparator) {
        std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
        exit (1) ;
      }
    }
    if (idx > 0) {
      ChunkUInt multiplier = 10 ;
      for (size_t i = 1 ; i < idx ; i++) {
        multiplier *= 10 ;
      }
      *this *= multiplier ;
      *this += accumulator ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

BigUnsigned::BigUnsigned (const BigUnsigned & inSource) :
mSharedArray (inSource.mSharedArray) {
}

//--------------------------------------------------------------------------------------------------

BigUnsigned & BigUnsigned::operator = (const BigUnsigned & inSource) {
  mSharedArray = inSource.mSharedArray ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors for 8 bits chunks
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_8_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const uint64_t inValue) :
  mSharedArray (8) {
    uint64_t v = inValue ;
    for (size_t i = 0 ; i < 8 ; i++) {
      mSharedArray.appendChunk (uint8_t (v) COMMA_HERE) ;
      v >>= 8 ;
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_8_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU8Count,
                            const uint8_t * inSourceU8Array) :
  mSharedArray (inU8Count) {
    for (size_t i = inU8Count ; i > 0 ; i--) {
      mSharedArray.appendChunk (inSourceU8Array [i-1] COMMA_HERE) ;
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_8_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU64Count,
                            const uint64_t * inSourceU64Array) :
    mSharedArray (inU64Count * 8) {
    for (size_t i = inU64Count ; i > 0 ; i--) {
      uint64_t v = inSourceU64Array [i-1] ;
      for (size_t j = 0 ; j < 8 ; j++) {
        mSharedArray.appendChunk (uint8_t (v) COMMA_HERE) ;
        v >>= 8 ;
      }
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors for 32 bits chunks
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_32_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const uint64_t inValue) :
  mSharedArray (2) {
    mSharedArray.appendChunk (uint32_t (inValue) COMMA_HERE) ;
    mSharedArray.appendChunk (uint32_t (inValue >> 32) COMMA_HERE) ;
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_32_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU8Count,
                            const uint8_t * inSourceU8Array) :
  mSharedArray ((inU8Count + 3) / 4) {
    uint32_t accumulator = 0 ;
    size_t phase = 0 ;
    for (size_t i = inU8Count ; i > 0 ; i--) {
      const uint64_t v = inSourceU8Array [i-1] ;
      accumulator |= (v << phase) ;
      phase += 8 ;
      if (phase == 32) {
        mSharedArray.appendChunk (accumulator COMMA_HERE) ;
        accumulator = 0 ;
        phase = 0 ;
      }
    }
    if (phase > 0) {
      mSharedArray.appendChunk (accumulator COMMA_HERE) ;
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_32_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU64Count,
                            const uint64_t * inSourceU64Array) :
    mSharedArray (inU64Count * 2) {
    for (size_t i = inU64Count ; i > 0 ; i--) {
      uint64_t v = inSourceU64Array [i-1] ;
      for (size_t j = 0 ; j < 2 ; j++) {
        mSharedArray.appendChunk (uint32_t (v) COMMA_HERE) ;
        v >>= 32 ;
      }
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors for 16 bits chunks
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_16_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const uint64_t inValue) :
  mSharedArray (4) {
    mSharedArray.appendChunk (uint16_t (inValue) COMMA_HERE) ;
    mSharedArray.appendChunk (uint16_t (inValue >> 16) COMMA_HERE) ;
    mSharedArray.appendChunk (uint16_t (inValue >> 32) COMMA_HERE) ;
    mSharedArray.appendChunk (uint16_t (inValue >> 48) COMMA_HERE) ;
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_16_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU8Count,
                            const uint8_t * inSourceU8Array) :
  mSharedArray ((inU8Count + 1) / 2) {
    uint16_t accumulator = 0 ;
    size_t phase = 0 ;
    for (size_t i = inU8Count ; i > 0 ; i--) {
      const uint64_t v = inSourceU8Array [i-1] ;
      accumulator |= (v << phase) ;
      phase += 8 ;
      if (phase == 16) {
        mSharedArray.appendChunk (accumulator COMMA_HERE) ;
        accumulator = 0 ;
        phase = 0 ;
      }
    }
    if (phase > 0) {
      mSharedArray.appendChunk (accumulator COMMA_HERE) ;
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_16_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU64Count,
                            const uint64_t * inSourceU64Array) :
    mSharedArray (inU64Count * 4) {
    for (size_t i = inU64Count ; i > 0 ; i--) {
      uint64_t v = inSourceU64Array [i-1] ;
      for (size_t j = 0 ; j < 4 ; j++) {
        mSharedArray.appendChunk (uint16_t (v) COMMA_HERE) ;
        v >>= 16 ;
      }
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors for 64 bits chunks
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_64_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const uint64_t inValue) :
  mSharedArray (1) {
    mSharedArray.appendChunk (inValue COMMA_HERE) ;
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_64_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU8Count,
                            const uint8_t * inSourceU8Array) :
  mSharedArray ((inU8Count + 7) / 8) {
    uint64_t accumulator = 0 ;
    size_t phase = 0 ;
    for (size_t i = inU8Count ; i > 0 ; i--) {
      const uint64_t v = inSourceU8Array [i-1] ;
      accumulator |= (v << phase) ;
      phase += 8 ;
      if (phase == 64) {
        mSharedArray.appendChunk (accumulator COMMA_HERE) ;
        accumulator = 0 ;
        phase = 0 ;
      }
    }
    if (phase > 0) {
      mSharedArray.appendChunk (accumulator COMMA_HERE) ;
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_64_BITS_CHUNKS
  BigUnsigned::BigUnsigned (const size_t inU64Count,
                            const uint64_t * inSourceU64Array) :
    mSharedArray (inU64Count) {
    for (size_t i = inU64Count ; i > 0 ; i--) {
      mSharedArray.appendChunk (inSourceU64Array [i-1] COMMA_HERE) ;
    }
    mSharedArray.removeLeadingZeroChunks (HERE) ;
  }
#endif

//--------------------------------------------------------------------------------------------------

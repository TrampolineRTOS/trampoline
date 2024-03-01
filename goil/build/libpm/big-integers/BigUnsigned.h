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

#pragma once

//--------------------------------------------------------------------------------------------------

#include "ChunkSharedArray.h"
#include "String-class.h"
#include <vector>

//--------------------------------------------------------------------------------------------------

class BigUnsignedQuotientU64Remainder ;
class BigUnsignedQuotientRemainder ;

//--------------------------------------------------------------------------------------------------

enum class BigUnsignedBase { two, ten, sixteen } ;

//--------------------------------------------------------------------------------------------------

class BigUnsigned final {

//--- Constructors
  public: explicit BigUnsigned (void) ; // Zero

  public: explicit BigUnsigned (const uint64_t inValue) ;

  public: explicit BigUnsigned (const size_t inU8Count,
                                const uint8_t * inSourceU8Array) ;

  public: explicit BigUnsigned (const size_t inU64Count,
                                const uint64_t * inSourceU64Array) ;

  public: explicit BigUnsigned (const char * inString, const uint8_t inSeparator) ;

  public: explicit BigUnsigned (const char * inString, const BigUnsignedBase inBase, bool & outOk) ;

  public: static BigUnsigned powerOfTwo (const uint32_t inPowerOfTwo) ;

  public: static BigUnsigned randomNumber (void) ;

//--- Handle copy
  public: BigUnsigned (const BigUnsigned & inSource) ;
  public: BigUnsigned & operator = (const BigUnsigned & inSource) ;

//--- Testing value
  public: bool isZero (void) const ;
  public: bool isOne (void) const ;

  public: size_t chunkCount (void) const  { return mSharedArray.chunkCount () ; }
  public: ChunkUInt chunkAtIndex (const size_t inChunkIndex COMMA_LOCATION_ARGS) const { // 0-Based Indexing
     return mSharedArray.chunkAtIndex (inChunkIndex + 1 COMMA_THERE) ; // 1-Based Indexing
  }

//--- Get U64 chunks
  public: size_t u64Count (void) const ;
  public: uint64_t u64AtIndex (const size_t inU64Index) const ; // 0-Based Indexing

//--- Get U8 chunks
  public: size_t u8Count (void) const ;
  public: uint8_t u8AtIndex (const size_t inU8Index) const ; // 0-Based Indexing

//--- Shift operators
  public: BigUnsigned operator << (const size_t inShiftCount) const ;
  public: void operator <<= (const size_t inShiftCount) ;

  public: void operator >>= (const size_t inShiftCount) ;
  public: BigUnsigned operator >> (const size_t inShiftCount) const ;

//--- Operations with ChunkUInt
  public: void operator += (const ChunkUInt inOperand) ;
  public: void operator -= (const ChunkUInt inOperand) ;
  public: void operator *= (const ChunkUInt inOperand) ;

  public: BigUnsigned operator + (const ChunkUInt inOperand) const ;
  public: BigUnsigned operator - (const ChunkUInt inOperand) const ;
  public: BigUnsigned operator * (const ChunkUInt inOperand) const ;

//--- Division, returns quotient and remainder
  public: BigUnsignedQuotientU64Remainder dividingByChunkUInt (const ChunkUInt inDivisor) const ;

//--- Division, returns quotient, remainder is lost
  public: void operator /= (const ChunkUInt inDivisor) ;
  public: BigUnsigned operator / (const ChunkUInt inDivisor) const ;

//--- Division, returns remainder, quotient is lost
  public: void operator %= (const ChunkUInt inDivisor) ;
  public: ChunkUInt operator % (const ChunkUInt inDivisor) const ;

//--- Logical operations
  public: BigUnsigned & operator |= (const ChunkUInt inOperand) ;
  public: BigUnsigned operator | (const BigUnsigned inOperand) const ;
  public: BigUnsigned operator ^ (const BigUnsigned inOperand) const ;
  public: BigUnsigned operator & (const BigUnsigned inOperand) const ;
  public: size_t countTrailingZeros (void) const ;
  public: BigUnsigned complemented (const size_t inChunkCount) const ;
  public: BigUnsigned subtractedOneAndComplemented (const size_t inChunkCount) const ;
  public: BigUnsigned utilityForPositiveOrNegative (const BigUnsigned & inNegative) const ;
  public: BigUnsigned utilityForNegativeOrNegative (const BigUnsigned & inNegative) const ;
  public: BigUnsigned utilityForPositiveAndNegative (const BigUnsigned & inNegative) const ;
  public: BigUnsigned utilityForNegativeAndNegative (const BigUnsigned & inNegative) const ;
  public: BigUnsigned utilityForPositiveXorNegative (const BigUnsigned & inNegative) const ;
  public: BigUnsigned utilityForNegativeXorNegative (const BigUnsigned & inNegative) const ;

//--- Add
  public: void operator += (const BigUnsigned inOperand) ;
  public: BigUnsigned operator + (const BigUnsigned inOperand) const ;

//--- Substract
  public: void operator -= (const BigUnsigned inOperand) ;
  public: BigUnsigned operator - (const BigUnsigned inOperand) const ;

//--- Multiply
  public: void operator *= (const BigUnsigned inOperand) ;
  public: BigUnsigned operator * (const BigUnsigned inOperand) const ;
  public: static BigUnsigned multiply (const BigUnsigned inLeft, const BigUnsigned inRight) ;

//--- Divide, returns quotient and remainder
  public: BigUnsignedQuotientRemainder divideByBigUnsigned (const BigUnsigned & inDivisor) const ;

  //--- naiveDivideByBigUnsigned can be very slow!
  public: BigUnsignedQuotientRemainder naiveDivideByBigUnsigned (const BigUnsigned & inDivisor) const ;

//--- Division, returns quotient, remainder is lost
  public: void operator /= (const BigUnsigned inDivisor) ;
  public: BigUnsigned operator / (const BigUnsigned inDivisor) const ;

//--- Division, returns remainder, quotient is lost
  public: void operator %= (const BigUnsigned inDivisor) ;
  public: BigUnsigned operator % (const BigUnsigned inDivisor) const ;

//--- Compare
  public: int compare (const BigUnsigned & inOperand) const ;
  public: bool operator == (const BigUnsigned & inOperand) const { return compare (inOperand) == 0 ; }
  public: bool operator != (const BigUnsigned & inOperand) const { return compare (inOperand) != 0 ; }
  public: bool operator >  (const BigUnsigned & inOperand) const { return compare (inOperand) >  0 ; }
  public: bool operator >= (const BigUnsigned & inOperand) const { return compare (inOperand) >= 0 ; }
  public: bool operator <  (const BigUnsigned & inOperand) const { return compare (inOperand) <  0 ; }
  public: bool operator <= (const BigUnsigned & inOperand) const { return compare (inOperand) <= 0 ; }

//--- Bit manipulation
  public: bool bitAtIndex (const uint32_t inBitIndex) const ;
  public: void setBitAtIndex (const bool inBit, const uint32_t inBitIndex) ;
  public: void complementBitAtIndex (const uint32_t inBitIndex) ;

//--- Print
  public: String decimalString (void) const ;
  public: String spacedDecimalString (const uint32_t inSeparation) const ;
  public: String spacedDecimalStringWithDigitCount (const uint32_t inSeparation) const ;
  public: String hexString (void) const ;
  public: String xString (void) const ;
  public: String bitString (void) const ;
  public: void printHex (const char * inName) const ;

//--- Testing value
  public: bool fitsInUInt32 (void) const ;
  public: bool fitsInUInt64 (void) const ;
  public: uint32_t requiredBitCountForUnsignedRepresentation (void) const ;

//--- Value access (returns invalid values if receiver does not fit)
  public: uint32_t uint32 (void) const ;
  public: uint64_t uint64 (void) const ;
  public: void extractBytesForUnsignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const ;

//--- Private property
  private: ChunkSharedArray mSharedArray ;
} ;

//--------------------------------------------------------------------------------------------------

class BigUnsignedQuotientRemainder final {
  private: BigUnsigned mQuotient ;
  public: BigUnsigned quotient (void) const { return mQuotient ; }
  private: BigUnsigned mRemainder ;
  public: BigUnsigned remainder (void) const { return mRemainder ; }

  public: explicit BigUnsignedQuotientRemainder () :
  mQuotient (),
  mRemainder () {
  }
  
  public: explicit BigUnsignedQuotientRemainder (const BigUnsigned & inQuotient,
                                                 const BigUnsigned & inRemainder) :
  mQuotient (inQuotient),
  mRemainder (inRemainder) {
  }
  
} ;

//--------------------------------------------------------------------------------------------------

class BigUnsignedQuotientU64Remainder final {
  private: BigUnsigned mQuotient ;
  public: BigUnsigned quotient (void) const { return mQuotient ; }
  private: ChunkUInt mRemainder ;
  public: ChunkUInt remainder (void) const { return mRemainder ; }

  public: explicit BigUnsignedQuotientU64Remainder () :
  mQuotient (),
  mRemainder (0) {
  }
  
  public: explicit BigUnsignedQuotientU64Remainder (const BigUnsigned & inQuotient,
                                                    const ChunkUInt inRemainder) :
  mQuotient (inQuotient),
  mRemainder (inRemainder) {
  }
  
} ;

//--------------------------------------------------------------------------------------------------

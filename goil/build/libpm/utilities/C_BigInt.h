//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  Handing signed integer of arbitrary size                                                                           *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2015, ..., 2015 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#ifndef PM_BIG_INT_CLASS_DEFINED
#define PM_BIG_INT_CLASS_DEFINED

//----------------------------------------------------------------------------------------------------------------------
// http://stackoverflow.com/questions/6943862/is-there-a-a-define-for-64-bit-in-gcc
// http://stackoverflow.com/questions/5272825/detecting-64bit-compile-in-c
//----------------------------------------------------------------------------------------------------------------------

#include "gmp/gmp.h"

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

#include <stdint.h>

//----------------------------------------------------------------------------------------------------------------------

class C_BigInt {
//--- Constructors
  public : C_BigInt (void) ;
  public : explicit C_BigInt (const uint64_t inValue, const bool inNegate) ;
  public : explicit C_BigInt (const uint64_t inHighValue, const uint64_t inLowValue, const bool inNegate) ;
  public : explicit C_BigInt (const int64_t inValue) ;
  public : explicit C_BigInt (const char * inString, const int32_t inBase, bool & outOk) ;
  public : static C_BigInt randomNumber (void) ;

//--- Destructor
  public : virtual ~ C_BigInt (void) ;

//--- Handle copy
  public : C_BigInt (const C_BigInt & inOperand) ;
  public : C_BigInt & operator = (const C_BigInt & inOperand) ;

//--- Set to value
  public : void setToZero (void) ;
  public : void setFromUnsigned (const uint32_t inValue) ;

//--- Sign
  public : bool isZero (void) const ;
  public : bool isOne (void) const ;
  public : bool isMinusOne (void) const ;
  public : bool isPositive (void) const ; // >0
  public : bool isNegative (void) const ; // <0

//--- Comparison
  public : bool operator == (const C_BigInt & inValue) const ;
  public : bool operator != (const C_BigInt & inValue) const ;
  public : bool operator > (const C_BigInt & inOperand) const ;
  public : bool operator >= (const C_BigInt & inOperand) const ;
  public : bool operator < (const C_BigInt & inOperand) const ;
  public : bool operator <= (const C_BigInt & inOperand) const ;
  public : int32_t compare (const C_BigInt & inValue) const ;
  public : int32_t sign (void) const ;

//--- Incrementation, decrementation
  public : C_BigInt & operator ++ (void) ;
  public : C_BigInt & operator -- (void) ;

//--- Shift
  public : C_BigInt operator << (const uint32_t inValue) const ;
  public : void operator <<= (const uint32_t inValue) ;
  public : C_BigInt operator >> (const uint32_t inValue) const ;
  public : void operator >>= (const uint32_t inValue) ;

//--- String
  public : C_String decimalString (void) const ;
  public : C_String spacedDecimalString (const uint32_t inSeparation) const ;
  public : C_String hexString (void) const ;
  public : C_String xString (void) const ;

//--- Add, subtract
  public : void operator += (const C_BigInt inValue) ;
  public : C_BigInt operator + (const C_BigInt & inValue) const ;

  public : void operator -= (const C_BigInt inValue) ;
  public : C_BigInt operator - (const C_BigInt & inValue) const ;

  public : void operator += (const uint32_t inValue) ;
  public : C_BigInt operator + (const uint32_t inValue) const ;

  public : void operator -= (const uint32_t inValue) ;
  public : C_BigInt operator - (const uint32_t inValue) const ;

//--- Negate
  public : C_BigInt operator - (void) const ;
  public : void negateInPlace (void) ;

//--- Multiplication
  public : void operator *= (const uint32_t inMultiplicand) ;
  public : C_BigInt operator * (const uint32_t inMultiplicand) const ;

  public : void operator *= (const C_BigInt inMultiplicand) ;
  public : C_BigInt operator * (const C_BigInt & inMultiplicand) const ;

//--- Division
  public : void divideInPlace (const uint32_t inDivisor, uint32_t & outRemainder) ;
  public : void divideBy (const uint32_t inDivisor, C_BigInt & outQuotient, uint32_t & outRemainder) const ;

  public : void divideInPlace (const C_BigInt inDivisor, C_BigInt & outRemainder) ;
  public : void divideBy (const C_BigInt inDivisor, C_BigInt & outQuotient, C_BigInt & outRemainder) const ;

  public : void floorDivideInPlace (const C_BigInt inDivisor, C_BigInt & outRemainder) ;
  public : void floorDivideBy (const C_BigInt inDivisor, C_BigInt & outQuotient, C_BigInt & outRemainder) const ;

  public : void ceilDivideInPlace (const C_BigInt inDivisor, C_BigInt & outRemainder) ;
  public : void ceilDivideBy (const C_BigInt inDivisor, C_BigInt & outQuotient, C_BigInt & outRemainder) const ;

  public : void operator /= (const C_BigInt inDivisor) ;
  public : C_BigInt operator / (const C_BigInt & inDivisor) const ;

  public : void operator %= (const C_BigInt inDivisor) ;
  public : C_BigInt operator % (const C_BigInt & inDivisor) const ;

//--- Absolute value
  public : C_BigInt abs (void) const ;

//--- Logical operators
  public : void operator &= (const C_BigInt inOperand) ;
  public : C_BigInt operator & (const C_BigInt & inOperand) const ;

  public : void operator |= (const C_BigInt inOperand) ;
  public : C_BigInt operator | (const C_BigInt & inOperand) const ;

  public : void operator ^= (const C_BigInt inOperand) ;
  public : C_BigInt operator ^ (const C_BigInt & inOperand) const ;

  public : C_BigInt operator ~ (void) const ;

//--- Bit manipulation
  public : bool bitAtIndex (const uint32_t inIndex) const ;
  public : void setBitAtIndex (const bool inBit, const uint32_t inIndex) ;
  public : void complementBitAtIndex (const uint32_t inIndex) ;
  
//--- Value access
  public : uint32_t uint32 (void) const ;
  public : uint64_t uint64 (void) const ;
  public :  int32_t int32  (void) const ;
  public :  int64_t int64  (void) const ;
  public : void extractBytesForUnsignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const ;
  public : void extractBytesForSignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const ;

//--- Testing value
  public : bool fitsInUInt32 (void) const ;
  public : bool fitsInUInt64 (void) const ;
  public : bool fitsInSInt32 (void) const ;
  public : bool fitsInSInt64 (void) const ;
  public : uint32_t requiredBitCountForSignedRepresentation (void) const ;
  public : uint32_t requiredBitCountForUnsignedRepresentation (void) const ;
  
//--- Value
  protected : mpz_t mGMPint ;

//--- Friend
  friend void swap (C_BigInt & ioOp1, C_BigInt & ioOp2) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#endif

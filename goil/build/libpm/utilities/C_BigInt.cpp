//----------------------------------------------------------------------------------------------------------------------
//
//  Handing signed integer of arbitrary size                                                     
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2015, ..., 2019 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#include "utilities/C_BigInt.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Default constructor, destructor, copy
#endif

//----------------------------------------------------------------------------------------------------------------------
//  Default Constructor: init to zero
//----------------------------------------------------------------------------------------------------------------------

C_BigInt::C_BigInt (void) :
mGMPint () {
  mpz_init (mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------
//  Destructor
//----------------------------------------------------------------------------------------------------------------------

C_BigInt::~C_BigInt (void) {
  mpz_clear (mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------
//  Handle copy
//----------------------------------------------------------------------------------------------------------------------

C_BigInt::C_BigInt (const C_BigInt & inOperand) :
mGMPint () {
  mpz_init (mGMPint) ;
  mpz_set (mGMPint, inOperand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt & C_BigInt::operator = (const C_BigInt & inOperand) {
  if (this != & inOperand) {
    mpz_set (mGMPint, inOperand.mGMPint) ;
  }
  return *this ;
}

//----------------------------------------------------------------------------------------------------------------------
// Normalize and tests
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Tests
#endif

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::isZero (void) const {
  return mpz_cmp_ui (mGMPint, 0) == 0 ;
}
  
//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::isOne (void) const {
  return mpz_cmp_ui (mGMPint, 1) == 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::isMinusOne (void) const {
  return mpz_cmp_si (mGMPint, -1) == 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_BigInt::sign (void) const {
  return mpz_sgn (mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::isNegative (void) const {
  return sign () < 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::isPositive (void) const {
  return sign () > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
// Constructors
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//----------------------------------------------------------------------------------------------------------------------

C_BigInt::C_BigInt (const uint64_t inValue, const bool inNegate) :
mGMPint () {
  mpz_init (mGMPint) ;
  const uint64_t high = inValue >> 32 ;
  if (high == 0) {
    mpz_set_ui (mGMPint, (uint32_t) inValue) ;
  }else{
    mpz_set_ui (mGMPint, (uint32_t) high) ;
    mpz_mul_2exp (mGMPint, mGMPint, 32) ;
    mpz_add_ui (mGMPint, mGMPint, (uint32_t) (inValue & UINT32_MAX)) ;
  }
  if (inNegate) {
    mpz_neg (mGMPint, mGMPint) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt::C_BigInt (const uint64_t inHighValue, const uint64_t inLowValue, const bool inNegate) :
mGMPint () {
  mpz_init (mGMPint) ;
  mpz_set_ui (mGMPint, 0) ;
  if (inHighValue != 0) {
    const uint64_t high = inHighValue >> 32 ;
    if (high == 0) {
      mpz_set_ui (mGMPint, (uint32_t) inHighValue) ;
    }else{
      mpz_set_ui (mGMPint, (uint32_t) high) ;
      mpz_mul_2exp (mGMPint, mGMPint, 32) ;
      mpz_add_ui (mGMPint, mGMPint, (uint32_t) (inHighValue & UINT32_MAX)) ;
    }
    mpz_mul_2exp (mGMPint, mGMPint, 32) ;
  }
  const uint64_t high = inLowValue >> 32 ;
  mpz_add_ui (mGMPint, mGMPint, (uint32_t) high) ;
  mpz_mul_2exp (mGMPint, mGMPint, 32) ;
  mpz_add_ui (mGMPint, mGMPint, (uint32_t) (inLowValue & UINT32_MAX)) ;
  if (inNegate) {
    mpz_neg (mGMPint, mGMPint) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt::C_BigInt (const int64_t inValue) :
mGMPint () {
  const bool negative = inValue < 0 ;
  const uint64_t v = (uint64_t) (negative ? (- inValue) : inValue) ;
  mpz_init (mGMPint) ;
  const uint64_t high = v >> 32 ;
  if (high == 0) {
    mpz_set_ui (mGMPint, (uint32_t) v) ;
  }else{
    mpz_set_ui (mGMPint, (uint32_t) high) ;
    mpz_mul_2exp (mGMPint, mGMPint, 32) ;
    mpz_add_ui (mGMPint, mGMPint, (uint32_t) (v & UINT32_MAX)) ;
  }
  if (negative) {
    mpz_neg (mGMPint, mGMPint) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::setToZero (void) {
  mpz_set_ui (mGMPint, 0) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::setFromUnsigned (const uint32_t inValue) {
  mpz_set_ui (mGMPint, inValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt::C_BigInt (const char * inString, const int32_t inBase, bool & outOk) :
mGMPint () {
  mpz_init (mGMPint) ;
  const int r = mpz_set_str (mGMPint, inString, inBase) ;
  outOk = r == 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
// increment
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Increment, decrement
#endif

//----------------------------------------------------------------------------------------------------------------------

C_BigInt & C_BigInt::operator ++ (void) {
  mpz_add_ui (mGMPint, mGMPint, 1) ;
  return *this ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt & C_BigInt::operator -- (void) {
  mpz_sub_ui (mGMPint, mGMPint, 1) ;
  return *this ;
}

//----------------------------------------------------------------------------------------------------------------------
// String
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Convert to string
#endif

//----------------------------------------------------------------------------------------------------------------------

C_String C_BigInt::decimalString (void) const {
  const size_t neededSize = mpz_sizeinbase (mGMPint, 10) + 2 ;
  char * s = NULL ;
  macroMyNewPODArray (s, char, neededSize) ;
  mpz_get_str (s, 10, mGMPint) ;
  C_String result ;
  result << s ;
  macroMyDeletePODArray (s) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_BigInt::spacedDecimalString (const uint32_t inSeparation) const {
  C_String result = decimalString () ;
  if (inSeparation > 0) {
    const bool valueIsNegative = sign () < 0 ;
    const int32_t lowBound = valueIsNegative ? 1 : 0 ;
    for (int32_t i = result.length () - (int32_t) inSeparation ; i > lowBound ; i -= (int32_t) inSeparation) {
      result.insertCharacterAtIndex (' ', i COMMA_HERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_BigInt::hexString (void) const {
  C_String result ;
  if (sign () >= 0) {
    result << "0x" << xString () ;
  }else{
    result << "-0x" << abs ().xString () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_BigInt::xString (void) const {
  char * s = NULL ;
  const size_t neededSize = mpz_sizeinbase (mGMPint, 16) + 2 ;
  macroMyNewPODArray (s, char, neededSize) ;
  mpz_get_str (s, -16, mGMPint) ; // -16 for getting 'A' to 'F' (16 provides 'a' to 'f')
  C_String result ;
  result << s ;
  macroMyDeletePODArray (s) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Absolute value
#endif

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::abs (void) const {
  C_BigInt result ;
  mpz_abs (result.mGMPint, mGMPint) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Logical operations
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator &= (const C_BigInt inOperand) {
  mpz_and (mGMPint, mGMPint, inOperand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator & (const C_BigInt & inOperand) const {
  C_BigInt result = *this ;
  result &= inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator |= (const C_BigInt inOperand) {
  mpz_ior (mGMPint, mGMPint, inOperand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator | (const C_BigInt & inOperand) const {
  C_BigInt result = *this ;
  result |= inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator ^= (const C_BigInt inOperand) {
  mpz_xor (mGMPint, mGMPint, inOperand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator ^ (const C_BigInt & inOperand) const {
  C_BigInt result = *this ;
  result ^= inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator ~ (void) const {
  C_BigInt result ;
  mpz_com (result.mGMPint, mGMPint) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Add, subtract uint32_t
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator += (const uint32_t inOperand) {
  mpz_add_ui (mGMPint, mGMPint, inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator + (const uint32_t inOperand) const {
  C_BigInt result = *this ;
  result += inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator -= (const uint32_t inOperand) {
  mpz_sub_ui (mGMPint, mGMPint, inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator - (const uint32_t inOperand) const {
  C_BigInt result = *this ;
  result -= inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Add, subtract C_BigInt
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator += (const C_BigInt inOperand) {
  mpz_add (mGMPint, mGMPint, inOperand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator -= (const C_BigInt inOperand) {
  mpz_sub (mGMPint, mGMPint, inOperand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator + (const C_BigInt & inOperand) const {
  C_BigInt result = *this ;
  result += inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator - (const C_BigInt & inOperand) const {
  C_BigInt result = *this ;
  result -= inOperand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//    Negate
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Negate
#endif

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator - (void) const {
  C_BigInt result = *this ;
  result.negateInPlace () ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::negateInPlace (void) {
  mpz_neg (mGMPint, mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Multiplication with uint32_t
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator *= (const uint32_t inMultiplicand) {
  mpz_mul_ui (mGMPint, mGMPint, inMultiplicand) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator * (const uint32_t inMultiplicand) const {
  C_BigInt result = *this ;
  result *= inMultiplicand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Multiplication with C_BigInt
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator *= (const C_BigInt inMultiplicand) {
  mpz_mul (mGMPint, mGMPint, inMultiplicand.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator * (const C_BigInt & inMultiplicand) const {
  C_BigInt result = *this ;
  result *= inMultiplicand ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Division
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::divideBy (const uint32_t inDivisor,
                         C_BigInt & outQuotient,
                         uint32_t & outRemainder) const {
  outRemainder = (uint32_t) mpz_fdiv_q_ui (outQuotient.mGMPint, mGMPint, inDivisor) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::divideInPlace (const uint32_t inDivisor, uint32_t & outRemainder) {
  mpz_t quotient ;
  mpz_init (quotient) ;
  if (mpz_sgn (mGMPint) >= 0) {
    outRemainder = (uint32_t) mpz_fdiv_q_ui (quotient, mGMPint, inDivisor) ;
  }else{
    outRemainder = (uint32_t) mpz_cdiv_q_ui (quotient, mGMPint, inDivisor) ;
  }
  mpz_swap (quotient, mGMPint) ;
  mpz_clear (quotient) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::divideBy (const C_BigInt inDivisor,
                         C_BigInt & outQuotient,
                         C_BigInt & outRemainder) const {
  outQuotient = *this ;
  outQuotient.divideInPlace (inDivisor, outRemainder) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::divideInPlace (const C_BigInt inDivisor, C_BigInt & outRemainder) {
  mpz_t quotient ;
  mpz_init (quotient) ;
  mpz_tdiv_qr (quotient, outRemainder.mGMPint, mGMPint, inDivisor.mGMPint) ;
  mpz_swap (quotient, mGMPint) ;
  mpz_clear (quotient) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::ceilDivideInPlace (const C_BigInt inDivisor, C_BigInt & outRemainder) {
  mpz_t quotient ;
  mpz_init (quotient) ;
  mpz_cdiv_qr (quotient, outRemainder.mGMPint, mGMPint, inDivisor.mGMPint) ;
  mpz_swap (quotient, mGMPint) ;
  mpz_clear (quotient) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::ceilDivideBy (const C_BigInt inDivisor,
                             C_BigInt & outQuotient,
                             C_BigInt & outRemainder) const {
  outQuotient = *this ;
  outQuotient.ceilDivideInPlace (inDivisor, outRemainder) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::floorDivideInPlace (const C_BigInt inDivisor, C_BigInt & outRemainder) {
  mpz_t quotient ;
  mpz_init (quotient) ;
  mpz_fdiv_qr (quotient, outRemainder.mGMPint, mGMPint, inDivisor.mGMPint) ;
  mpz_swap (quotient, mGMPint) ;
  mpz_clear (quotient) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::floorDivideBy (const C_BigInt inDivisor,
                              C_BigInt & outQuotient,
                              C_BigInt & outRemainder) const {
  outQuotient = *this ;
  outQuotient.floorDivideInPlace (inDivisor, outRemainder) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator /= (const C_BigInt inDivisor) {
  C_BigInt unusedRemainder ;
  divideInPlace (inDivisor, unusedRemainder) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator / (const C_BigInt & inDivisor) const {
  C_BigInt result = *this ;
  result /= inDivisor ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator %= (const C_BigInt inDivisor) {
  mpz_t quotient ;
  mpz_init (quotient) ;
  mpz_t remainder ;
  mpz_init (remainder) ;
  mpz_tdiv_qr (quotient, remainder, mGMPint, inDivisor.mGMPint) ;
  mpz_swap (remainder, mGMPint) ;
  mpz_clear (quotient) ;
  mpz_clear (remainder) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator % (const C_BigInt & inDivisor) const {
  C_BigInt result = *this ;
  result %= inDivisor ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Shift left
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator <<= (const uint32_t inValue) {
  mpz_mul_2exp (mGMPint, mGMPint, inValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator << (const uint32_t inValue) const {
  C_BigInt result = *this ;
  result <<= inValue ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator << (const C_BigInt inValue) const {
  C_BigInt result = *this ;
  if (inValue > C_BigInt (0)) {
    const uint32_t v = inValue.uint32 () ;
    result <<= v ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Shift right
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::operator >>= (const uint32_t inValue) {
  mpz_t quotient ;
  mpz_init (quotient) ;
  mpz_fdiv_q_2exp (quotient, mGMPint, inValue) ;
  mpz_swap (quotient, mGMPint) ;
  mpz_clear (quotient) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator >> (const uint32_t inValue) const {
  C_BigInt result = *this ;
  result >>= inValue ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::operator >> (const C_BigInt inValue) const {
  C_BigInt result = *this ;
  if (inValue > C_BigInt (0)) {
    const uint32_t v = inValue.uint32 () ;
    result >>= v ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Compare
#endif

//----------------------------------------------------------------------------------------------------------------------

int32_t C_BigInt::compare (const C_BigInt & inValue) const {
  return mpz_cmp (mGMPint, inValue.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::operator == (const C_BigInt & inOperand) const {
  return compare (inOperand) == 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::operator != (const C_BigInt & inOperand) const {
  return compare (inOperand) != 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::operator >= (const C_BigInt & inOperand) const {
  return compare (inOperand) >= 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::operator > (const C_BigInt & inOperand) const {
  return compare (inOperand) > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::operator <= (const C_BigInt & inOperand) const {
  return compare (inOperand) <= 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::operator < (const C_BigInt & inOperand) const {
  return compare (inOperand) < 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Bit manipulation
#endif

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::bitAtIndex (const uint32_t inIndex) const {
  return mpz_tstbit (mGMPint, inIndex) != 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::setBitAtIndex (const bool inBit, const uint32_t inIndex) {
  if (inBit) {
    mpz_setbit (mGMPint, inIndex) ;
  }else{
    mpz_clrbit (mGMPint, inIndex) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::complementBitAtIndex (const uint32_t inIndex) {
  mpz_combit (mGMPint, inIndex) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Testing Value
#endif

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::fitsInUInt32 (void) const {
  return mpz_fits_uint_p (mGMPint) != 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::fitsInUInt64 (void) const {
  return (mpz_sgn (mGMPint) >= 0) && (mpz_sizeinbase (mGMPint, 2) <= 64) ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::fitsInSInt32 (void) const {
  return mpz_fits_sint_p (mGMPint) != 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_BigInt::fitsInSInt64 (void) const {
  const size_t requiredBitCount = mpz_sizeinbase (mGMPint, 2) ;
  bool ok = requiredBitCount <= 63 ;
  if ((requiredBitCount == 64) && (mpz_sgn (mGMPint) < 0)) { // INT64_MIN is a particular case
    int64_t r ;
    mpz_export (& r, NULL, 1, sizeof (int64_t), 0, 0, mGMPint) ;
    ok = r == INT64_MIN ;
  }
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_BigInt::requiredBitCountForSignedRepresentation (void) const {
  size_t requiredBitCount = mpz_sizeinbase (mGMPint, 2) ;
  if (mpz_sgn (mGMPint) > 0) {
    requiredBitCount ++ ;
  }
  return (uint32_t) requiredBitCount ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_BigInt::requiredBitCountForUnsignedRepresentation (void) const {
  return (uint32_t) mpz_sizeinbase (mGMPint, 2) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value access
#endif

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_BigInt::uint32 (void) const {
  return (uint32_t) mpz_get_ui (mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

uint64_t C_BigInt::uint64 (void) const {
  uint64_t result = UINT64_MAX ;
  if (fitsInUInt64 ()) {
    mpz_export (& result, NULL, 1, sizeof (uint64_t), 0, 0, mGMPint) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_BigInt::int32 (void) const {
  return (int32_t) mpz_get_si (mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

int64_t C_BigInt::int64 (void) const {
  uint64_t r = UINT64_MAX ;
  if (fitsInSInt64 ()) {
    mpz_export (& r, NULL, 1, sizeof (uint64_t), 0, 0, mGMPint) ;
  }
  int64_t result = (int64_t) r ;
  if (mpz_sgn (mGMPint) < 0) {
    result = - result ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::extractBytesForUnsignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const {
  size_t count = 0 ;
  const uint8_t * ptr = (const uint8_t *) mpz_export (NULL, & count, -1, sizeof (uint8_t), 0, 0, mGMPint) ;
  outValue.setCountToZero () ;
  for (size_t i=0 ; i<count ; i++) {
    outValue.appendObject (ptr [i]) ;
  }
  ::free ((void *) ptr) ;
  if (count == 0) {
    outValue.appendObject (0) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_BigInt::extractBytesForSignedRepresentation (TC_UniqueArray <uint8_t> & outValue) const {
  if (mpz_sgn (mGMPint) == 0) { // zero
    outValue.setCountToZero () ;
    outValue.appendObject (0) ;
  }else if (mpz_sgn (mGMPint) > 0) { // > 0
    extractBytesForUnsignedRepresentation (outValue) ;
    if ((outValue.lastObject (HERE) & 0x80) != 0) {
      outValue.appendObject (0) ;
    }
  }else{ // < 0
    extractBytesForUnsignedRepresentation (outValue) ;
  //--- Perform two's complement
    uint8_t carry = 1 ;
    for (int32_t i=0 ; i<outValue.count () ; i++) {
      const uint8_t v = (uint8_t) (carry + ~ outValue (i COMMA_HERE)) ;
      outValue (i COMMA_HERE) = v ;
      carry = v == 0 ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Swap
#endif

//----------------------------------------------------------------------------------------------------------------------

void swap (C_BigInt & ioOp1, C_BigInt & ioOp2) {
  mpz_swap (ioOp1.mGMPint, ioOp2.mGMPint) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Swap
#endif

//----------------------------------------------------------------------------------------------------------------------

static uint32_t randomUInt32 (void) {
  return (uint32_t) rand () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_BigInt::randomNumber (void) {
  C_BigInt result (randomUInt32 ()) ;
  for (uint32_t i=0 ; i<20 ; i++) {
    result <<= 32 ;
    result += randomUInt32 () ;
  }
  if ((randomUInt32 () & 1) == 0) {
    result.negateInPlace () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


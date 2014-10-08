//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'GALGAS_uint_36__34_' : galgas uint64                                      *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2006, ..., 2010 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark GALGAS Constructors
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_::GALGAS_uint_36__34_ (const uint64_t inValue) :
mIsValid (true),
mUInt64Value (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("uint64", true, cStringWithUnsigned (inValue)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_ (0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_::GALGAS_uint_36__34_ (void) :
mIsValid (false),
mUInt64Value (0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_ (UINT64_MAX) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::constructor_uint_36__34_MaskWithCompressedBitString (const GALGAS_string & inBitString,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result ;
  if (inBitString.isValid ()) {
    const int32_t bitStringLength = inBitString.stringValue ().length () ;
    bool ok = true ;
    uint64_t v = 0 ;
    for (int32_t i=0 ; (i<bitStringLength) && ok ; i++) {
      v <<= 1 ;
      const utf32 c = inBitString.stringValue () (i COMMA_HERE) ;
      if ((UNICODE_VALUE (c) == '1') || (UNICODE_VALUE (c) == '0')) {
        v ++ ;
      }else if (UNICODE_VALUE (c) != 'X') {
        ok = false ;
      }
    }
    if (ok) {
      result = GALGAS_uint_36__34_ (v) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("incorrect bit string for 'uint64MaskWithCompressedBitString' @uint64 constructor" COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::constructor_uint_36__34_BaseValueWithCompressedBitString (const GALGAS_string & inBitString,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result ;
  if (inBitString.isValid ()) {
    bool ok = true ;
    uint64_t v = 0 ;
    const int32_t bitStringLength = inBitString.stringValue ().length () ;
    for (int32_t i=0 ; (i<bitStringLength) && ok ; i++) {
      v <<= 1 ;
      const utf32 c = inBitString.stringValue () (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) == '1') {
        v ++ ;
      }else if ((UNICODE_VALUE (c) != '0') && (UNICODE_VALUE (c) != 'X')) {
        ok = false ;
      }
    }
    if (ok) {
      result = GALGAS_uint_36__34_ (v) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("incorrect bit string for 'uint64BaseValueWithCompressedBitString' @uint64_t constructor" COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::constructor_uint_36__34_WithBitString (const GALGAS_string & inBitString,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result ;
  if (inBitString.isValid ()) {
    bool ok = true ;
    uint64_t v = 0 ;
    const int32_t bitStringLength = inBitString.stringValue ().length () ;
    for (int32_t i=0 ; (i<bitStringLength) && ok ; i++) {
      v <<= 1 ;
      const utf32 c = inBitString.stringValue () (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) == '1') {
        v ++ ;
      }else if (UNICODE_VALUE (c) != '0') {
        ok = false ;
      }
    }
    if (ok) {
      result = GALGAS_uint_36__34_ (UINT64_MAX) ;
    }else{
      inCompiler->onTheFlyRunTimeError ("incorrect bit string for 'uint64WithBitString' @uint64_t constructor" COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark GALGAS Operators
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::operator_and (const GALGAS_uint_36__34_ & inOperand2
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_uint_36__34_ (mUInt64Value & inOperand2.mUInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::operator_or (const GALGAS_uint_36__34_ & inOperand2
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_uint_36__34_ (mUInt64Value | inOperand2.mUInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::operator_xor (const GALGAS_uint_36__34_ & inOperand2
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_uint_36__34_ (mUInt64Value ^ inOperand2.mUInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid ()) {
    result = GALGAS_uint_36__34_ (~ mUInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::modulo_operation (const GALGAS_uint_36__34_ & inOperand2,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mUInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero in @uint64 modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ (mUInt64Value % inOperand2.mUInt64Value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::left_shift_operation (const GALGAS_uint inShiftOperand
                                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_uint_36__34_ (mUInt64Value << (inShiftOperand.uintValue () & 63)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::right_shift_operation (const GALGAS_uint inShiftOperand
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_uint_36__34_ (mUInt64Value >> (inShiftOperand.uintValue () & 63)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void productUint64 (const uint64_t inOperand1,
                           const uint64_t inOperand2,
                           uint64_t & outResult,
                           bool & outOverflow) {
  const uint64_t lowWord1 = inOperand1 & UINT32_MAX ;
  const uint64_t highWord1 = inOperand1 >> 32 ;
  const uint64_t lowWord2 = inOperand2 & UINT32_MAX ;
  const uint64_t highWord2 = inOperand2 >> 32 ;
  const uint64_t lowResult = lowWord1 * lowWord2 ;
  const uint64_t crossResult = (lowWord1 * highWord2) + (lowWord2 * highWord1) + (lowResult >> 32) ;
  const uint64_t highResult = (highWord1 * highWord2) + (crossResult >> 32) ;
  outResult = (crossResult << 32) + (lowResult & UINT32_MAX) ;
  outOverflow = highResult > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::multiply_operation (const GALGAS_uint_36__34_ & inOperand2,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    uint64_t v ;
    bool overflow ;
    productUint64 (mUInt64Value, inOperand2.mUInt64Value, v, overflow) ;
    if (overflow) {
      inCompiler->onTheFlyRunTimeError ("* operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ (v) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::divide_operation (const GALGAS_uint_36__34_ & inOperand2,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mUInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ (mUInt64Value / inOperand2.mUInt64Value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_::increment_operation (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mUInt64Value == UINT64_MAX) {
      inCompiler->onTheFlyRunTimeError ("++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mUInt64Value ++ ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_::decrement_operation (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mUInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("@uint 64 -- operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mUInt64Value -- ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::add_operation (const GALGAS_uint_36__34_ & inOperand2,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    const uint64_t lowWord1 = mUInt64Value & UINT32_MAX ;
    const uint64_t highWord1 = mUInt64Value >> 32 ;
    const uint64_t lowWord2 = inOperand2.mUInt64Value & UINT32_MAX ;
    const uint64_t highWord2 = inOperand2.mUInt64Value >> 32 ;
    const uint64_t lowSum = lowWord1 + lowWord2 ;
    const uint64_t lowResult = lowSum & UINT32_MAX ;
    const uint64_t highSum = highWord1 + highWord2 + (lowSum >> 32) ;
    if (highSum > UINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("+ operation overflow" COMMA_THERE) ;
    }else{
      const uint64_t v = (highSum << 32) | lowResult ;
      result = GALGAS_uint_36__34_ (v) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_::substract_operation (const GALGAS_uint_36__34_ & inOperand2,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (mUInt64Value < inOperand2.mUInt64Value) {
      inCompiler->onTheFlyRunTimeError ("- operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ (mUInt64Value - inOperand2.mUInt64Value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_uint_36__34_::objectCompare (const GALGAS_uint_36__34_ & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mUInt64Value < inOperand.mUInt64Value) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mUInt64Value > inOperand.mUInt64Value) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark GALGAS Readers
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_uint_36__34_::reader_sint_36__34_ (C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (mUInt64Value > ((uint64_t) INT64_MAX)) {
    inCompiler->onTheFlyRunTimeError ("unsigned value to signed value conversion overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_sint_36__34_ ((int64_t) mUInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_uint_36__34_::reader_sint (C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (mUInt64Value > ((uint64_t) INT32_MAX)) {
    inCompiler->onTheFlyRunTimeError ("unsigned value to signed value conversion overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_sint ((int32_t) (mUInt64Value & UINT32_MAX)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_36__34_::reader_uint (C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (mUInt64Value > ((uint64_t) UINT32_MAX)) {
    inCompiler->onTheFlyRunTimeError ("64-bit unsigned value to 32-bit unsigned value conversion overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_uint ((uint32_t) (mUInt64Value & UINT32_MAX)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_uint_36__34_::reader_double (UNUSED_LOCATION_ARGS) const {
  return GALGAS_double ((double) mUInt64Value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_uint_36__34_::reader_string (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendUnsigned (mUInt64Value) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_uint_36__34_::reader_hexString (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendCString ("0x") ;
  s.appendUnsignedHex16 (mUInt64Value) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_uint_36__34_::reader_xString (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendUnsignedHex16 (mUInt64Value) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_::description (C_String & ioString,
                                       const int32_t /* inIndentation */) const {
  ioString << "<@uint64:" ;
  if (isValid ()) {
    ioString.appendUnsigned (mUInt64Value) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_36__34_::reader_uintSlice (const GALGAS_uint & inStartBit,
                                                     const GALGAS_uint & inBitCount,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (inStartBit.isValid () && inBitCount.isValid ()) {
    if (inBitCount.uintValue () > 32) {
      inCompiler->onTheFlyRunTimeError ("bit count operand > 32" COMMA_THERE) ;
    }else if ((inStartBit.uintValue () + inBitCount.uintValue ()) > 64) {
      inCompiler->onTheFlyRunTimeError ("start bit + bit count operand > 64" COMMA_THERE) ;
    }else{
      uint64_t v = mUInt64Value >> inStartBit.uintValue () ;
      v &= ((1ULL << inBitCount.uintValue ()) - 1ULL) ;
      result = GALGAS_uint ((uint32_t) (v & UINT32_MAX)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

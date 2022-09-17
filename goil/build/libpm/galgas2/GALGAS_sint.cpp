//----------------------------------------------------------------------------------------------------------------------
//
//  'GALGAS_sint' : galgas sint32                                                                
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2004, ..., 2019 Pierre Molinaro.
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

#include "all-predefined-types.h"
#include "galgas2/C_Compiler.h"

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint::GALGAS_sint (void) :
AC_GALGAS_root (),
mIsValid (false),
mSIntValue (0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint (0) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint::GALGAS_sint (const int32_t inValue) :
AC_GALGAS_root (),
mIsValid (true),
mSIntValue (inValue) {
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sint::objectCompare (const GALGAS_sint & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mSIntValue < inOperand.mSIntValue) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mSIntValue > inOperand.mSIntValue) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint (INT32_MAX) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::constructor_min (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint (INT32_MIN) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_sint::getter_uint (C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    if (mSIntValue < 0) {
      inCompiler->onTheFlyRunTimeError ("cannot convert a negative @sint into unsigned value" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (uint32_t (mSIntValue)) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_sint::getter_uint_36__34_ (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid ()) {
    if (mSIntValue < 0) {
      inCompiler->onTheFlyRunTimeError ("cannot convert a negative @sint into unsigned value" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ ((uint64_t) mSIntValue) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint::getter_sint_36__34_ (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    result = GALGAS_sint_36__34_ (mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_sint::getter_double (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double ((double) mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint GALGAS_sint::getter_bigint (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (isValid ()) {
    result = GALGAS_bigint (C_BigInt (mSIntValue)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint::getter_string (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ; s.appendSigned (mSIntValue) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint::getter_hexString (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const uint32_t v = (uint32_t) mSIntValue ;
    C_String s ;
    s << "0x" ;
    s.appendUnsignedHex8 (v) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint::getter_hexStringSeparatedBy (const GALGAS_char & inSeparator,
                                                        const GALGAS_uint & inGroup,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inSeparator.isValid () && inGroup.isValid ()) {
    const int group = (int) inGroup.uintValue () ;
    if (group <= 0) {
      inCompiler->onTheFlyRunTimeError ("last argument should be > 0" COMMA_THERE) ;
    }else{
      C_String s ;
      s.appendUnsignedHex ((uint32_t) mSIntValue) ;
      const utf32 separator = inSeparator.charValue() ;
      for (int i = (int) (s.length () - group) ; i > 0 ; i -= group) {
        s.insertCharacterAtIndex (separator, i COMMA_HERE) ;
      }
      result = GALGAS_string (C_String ("0x") + s) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint::getter_xString (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const uint32_t v = (uint32_t) mSIntValue ;
    C_String s ; s.appendUnsignedHex8 (v) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@sint:" ;
  if (isValid ()) {
    ioString << cStringWithSigned (mSIntValue) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::increment_operation_no_overflow (void) {
  mSIntValue ++ ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::decrement_operation_no_overflow (void) {
  mSIntValue -- ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::increment_operation (C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mSIntValue == INT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("@sint ++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSIntValue ++ ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::decrement_operation (C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mSIntValue == INT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("@sint -- operation underflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSIntValue -- ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::plusAssign_operation (const GALGAS_sint inOperand,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue + inOperand.mSIntValue ;
    const bool signA = mSIntValue >= 0 ;
    const bool signB = inOperand.mSIntValue >= 0 ;
    const bool signR = r >= 0 ;
    const bool ovf = (signA == signB) && (signA != signR) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint += operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSIntValue = r ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::minusAssign_operation (const GALGAS_sint inOperand,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue - inOperand.mSIntValue ;
    const bool ovf = (mSIntValue >= inOperand.mSIntValue) != (r >= 0) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint -= operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSIntValue = r ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::mulAssign_operation (const GALGAS_sint inOperand,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue * inOperand.mSIntValue ;
    bool ovf = false ;
    if (inOperand.mSIntValue == -1) {
      ovf = mSIntValue == INT32_MIN ;
    }else if (inOperand.mSIntValue != 0) {
      ovf = (r / inOperand.mSIntValue) != mSIntValue ;
    }
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint *= operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSIntValue = r ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint::divAssign_operation (const GALGAS_sint inOperand,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mSIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@sint /= divide by zero" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSIntValue /= inOperand.mSIntValue ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::add_operation_no_ovf (const GALGAS_sint & inOperand) const {
  GALGAS_sint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_sint (mSIntValue + inOperand.mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::add_operation (const GALGAS_sint & inOperand,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue + inOperand.mSIntValue ;
    const bool signA = mSIntValue >= 0 ;
    const bool signB = inOperand.mSIntValue >= 0 ;
    const bool signR = r >= 0 ;
    const bool ovf = (signA == signB) && (signA != signR) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint + operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (r) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint::getter_canAdd (const GALGAS_sint & inOperand
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue + inOperand.mSIntValue ;
    const bool signA = mSIntValue >= 0 ;
    const bool signB = inOperand.mSIntValue >= 0 ;
    const bool signR = r >= 0 ;
    const bool ovf = (signA == signB) && (signA != signR) ;
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::substract_operation (const GALGAS_sint & inOperand,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue - inOperand.mSIntValue ;
    const bool ovf = (mSIntValue >= inOperand.mSIntValue) != (r >= 0) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint - operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (r) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint::getter_canSubstract (const GALGAS_sint & inOperand
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue - inOperand.mSIntValue ;
    const bool ovf = (mSIntValue >= inOperand.mSIntValue) != (r >= 0) ;
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::substract_operation_no_ovf (const GALGAS_sint & inOperand2) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue - inOperand2.mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::multiply_operation_no_ovf (const GALGAS_sint & inOperand2) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue * inOperand2.mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::multiply_operation (const GALGAS_sint & inOperand,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue * inOperand.mSIntValue ;
    bool ovf = false ;
    if (inOperand.mSIntValue == -1) {
      ovf = mSIntValue == INT32_MIN ;
    }else if (inOperand.mSIntValue != 0) {
      ovf = (r / inOperand.mSIntValue) != mSIntValue ;
    }
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint * operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (r) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint::getter_canMultiply (const GALGAS_sint & inOperand
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t r = mSIntValue * inOperand.mSIntValue ;
    bool ovf = false ;
    if (inOperand.mSIntValue == -1) {
      ovf = mSIntValue == INT32_MIN ;
    }else if (inOperand.mSIntValue != 0) {
      ovf = (r / inOperand.mSIntValue) != mSIntValue ;
    }
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::divide_operation (const GALGAS_sint & inOperand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand.isValid ()) {
    if (mSIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@sint divide by zero" COMMA_THERE) ;
    }else if ((mSIntValue == INT32_MIN) && (inOperand.mSIntValue == -1)) {
      inCompiler->onTheFlyRunTimeError ("@sint / operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (mSIntValue / inOperand.mSIntValue) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint::getter_canDivide (const GALGAS_sint & inOperand
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const bool ok = (mSIntValue != 0) && !((mSIntValue == INT32_MIN) && (inOperand.mSIntValue == -1)) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::divide_operation_no_ovf (const GALGAS_sint & inOperand) const {
  GALGAS_sint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_sint ((inOperand.mSIntValue == 0) ? 0 : (mSIntValue / inOperand.mSIntValue)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::modulo_operation (const GALGAS_sint & inOperand2,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    if (mSIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@sint divide by zero in modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (mSIntValue % inOperand2.mSIntValue) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::operator_unary_minus (C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid ()) {
    if (mSIntValue == INT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("@sint unary '-' operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (- mSIntValue) ;
    }
  }
  return result ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::operator_unary_minus_no_ovf (void) const {
  GALGAS_sint result ;
  if (isValid ()) {
    result = GALGAS_sint (- mSIntValue) ;
  }
  return result ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::left_shift_operation (const GALGAS_uint inShiftOperand,
                                               class C_Compiler * /* inCompiler*/
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint (mSIntValue << (inShiftOperand.uintValue () & 31)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::left_shift_operation (const GALGAS_bigint inShiftOperand,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inShiftOperand.isValid ()) {
    if (inShiftOperand.bigintValue().isNegative ()) {
      inCompiler->onTheFlyRunTimeError ("@sint left shift by a negative amount" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (mSIntValue << (inShiftOperand.bigintValue ().uint32 () & 31)) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::right_shift_operation (const GALGAS_uint inShiftOperand,
                                                class C_Compiler * /* inCompiler*/
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint (mSIntValue >> (inShiftOperand.uintValue () & 31)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inShiftOperand.isValid ()) {
    if (inShiftOperand.bigintValue().isNegative ()) {
      inCompiler->onTheFlyRunTimeError ("@sint right shift by a negative amount" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (mSIntValue >> (inShiftOperand.bigintValue ().uint32 () & 31)) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::operator_and (const GALGAS_sint & inOperand2
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue & inOperand2.mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::operator_or (const GALGAS_sint & inOperand2
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue | inOperand2.mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::operator_xor (const GALGAS_sint & inOperand2
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue ^ inOperand2.mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid ()) {
    result = GALGAS_sint (~ mSIntValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

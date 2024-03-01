//----------------------------------------------------------------------------------------------------------------------
//
//  'GALGAS_sint64' : galgas sint64                                                              
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2006, ..., 2019 Pierre Molinaro.
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
//
//               GALGAS_sint64                                                                   
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_::GALGAS_sint_36__34_ (void) :
AC_GALGAS_root (),
mIsValid (false),
mSInt64Value (0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_ (0) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_::GALGAS_sint_36__34_ (const int64_t inValue) :
AC_GALGAS_root (),
mIsValid (true),
mSInt64Value (inValue) {
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sint_36__34_::objectCompare (const GALGAS_sint_36__34_ & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mSInt64Value < inOperand.mSInt64Value) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mSInt64Value > inOperand.mSInt64Value) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_ (INT64_MAX) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::constructor_min (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_ (INT64_MIN) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_sint_36__34_::getter_uint_36__34_ (C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (mSInt64Value < 0) {
    inCompiler->onTheFlyRunTimeError ("cannot convert a negative sint64 into an uint64" COMMA_THERE) ;
  }else{
    result = GALGAS_uint_36__34_ ((uint64_t) mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_sint_36__34_::getter_uint (C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (mSInt64Value < 0) {
    inCompiler->onTheFlyRunTimeError ("cannot convert a negative @sint64 into an uint" COMMA_THERE) ;
  }else if (mSInt64Value > ((int64_t) UINT32_MAX)) {
    inCompiler->onTheFlyRunTimeError ("@sint64 conversion to unsigned value overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_uint ((uint32_t) (mSInt64Value & UINT32_MAX)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_36__34_::getter_sint (C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (mSInt64Value < INT32_MIN) {
    inCompiler->onTheFlyRunTimeError ("conversion from 64-bit signed value to 32-bit signed value overflow" COMMA_THERE) ;
  }else if (mSInt64Value > INT32_MAX) {
    inCompiler->onTheFlyRunTimeError ("conversion from 64-bit signed value to 32-bit signed value overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_sint ((int32_t) (mSInt64Value & UINT32_MAX)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint GALGAS_sint_36__34_::getter_bigint (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (isValid ()) {
    result = GALGAS_bigint (C_BigInt (mSInt64Value)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_sint_36__34_::getter_double (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double ((double) mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint_36__34_::getter_string (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    C_String s ;
    s.appendSigned (mSInt64Value) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint_36__34_::getter_hexString (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const uint64_t v = (uint64_t) mSInt64Value ;
    C_String s ;
    s << "0x" ;
    s.appendUnsignedHex16 (v) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_sint_36__34_::getter_hexStringSeparatedBy (const GALGAS_char & inSeparator,
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
      s.appendUnsignedHex ((uint64_t) mSInt64Value) ;
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

GALGAS_string GALGAS_sint_36__34_::getter_xString (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    const uint64_t v = (uint64_t) mSInt64Value ;
    C_String s ; s.appendUnsignedHex16 (v) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::description (C_String & ioString,
                                       const int32_t /* inIndentation */) const {
  ioString << "<@sint64:" ;
  ioString.appendSigned (mSInt64Value) ;
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::increment_operation (C_Compiler * inCompiler 
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mSInt64Value == INT64_MAX) {
      inCompiler->onTheFlyRunTimeError ("@sint64 ++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSInt64Value ++ ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::increment_operation_no_overflow (void) {
  mSInt64Value ++ ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::decrement_operation_no_overflow (void) {
  mSInt64Value -- ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::decrement_operation (C_Compiler * inCompiler 
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
  //--- Overflow ?
    if (mSInt64Value == INT64_MIN) {
      inCompiler->onTheFlyRunTimeError ("@sint64 -- operation underflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSInt64Value -- ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::plusAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value + inOperand.mSInt64Value ;
    const bool signA = mSInt64Value >= 0 ;
    const bool signB = inOperand.mSInt64Value >= 0 ;
    const bool signR = r >= 0 ;
    const bool ovf = (signA == signB) && (signA != signR) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint64 += operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSInt64Value = r ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::minusAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value - inOperand.mSInt64Value ;
    const bool ovf = (mSInt64Value >= inOperand.mSInt64Value) != (r >= 0) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint64 -= operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSInt64Value = r ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::mulAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value * inOperand.mSInt64Value ;
    bool ovf = false ;
    if (inOperand.mSInt64Value == -1) {
      ovf = mSInt64Value == INT64_MIN ;
    }else if (inOperand.mSInt64Value != 0) {
      ovf = (r / inOperand.mSInt64Value) != mSInt64Value ;
    }
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint64 *= operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSInt64Value = r ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_::divAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mSInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("@sint64 /= divide by zero" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mSInt64Value /= inOperand.mSInt64Value ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::add_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value + inOperand.mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::add_operation (const GALGAS_sint_36__34_ & inOperand,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value + inOperand.mSInt64Value ;
    const bool signA = mSInt64Value >= 0 ;
    const bool signB = inOperand.mSInt64Value >= 0 ;
    const bool signR = r >= 0 ;
    const bool ovf = (signA == signB) && (signA != signR) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint64 + operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (r) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint_36__34_::getter_canAdd (const GALGAS_sint_36__34_ & inOperand
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value + inOperand.mSInt64Value ;
    const bool signA = mSInt64Value >= 0 ;
    const bool signB = inOperand.mSInt64Value >= 0 ;
    const bool signR = r >= 0 ;
    const bool ovf = (signA == signB) && (signA != signR) ;
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
// http://stackoverflow.com/questions/199333/how-to-detect-integer-overflow-in-c-c
// For signed integers you can check the signs of the arguments and of the result. integers of different signs
// can't overflow, and integers of same sign overflow only is the result is of different sign

GALGAS_sint_36__34_ GALGAS_sint_36__34_::substract_operation (const GALGAS_sint_36__34_ & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value - inOperand.mSInt64Value ;
    const bool ovf = (mSInt64Value >= inOperand.mSInt64Value) != (r >= 0) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint64 - operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (r) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint_36__34_::getter_canSubstract (const GALGAS_sint_36__34_ & inOperand
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value - inOperand.mSInt64Value ;
    const bool ovf = (mSInt64Value >= inOperand.mSInt64Value) != (r >= 0) ;
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::substract_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand2) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    const int64_t r = mSInt64Value - inOperand2.mSInt64Value ;
    result = GALGAS_sint_36__34_ (r) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::multiply_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand2) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value * inOperand2.mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::multiply_operation (const GALGAS_sint_36__34_ & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value * inOperand.mSInt64Value ;
    bool ovf = false ;
    if (inOperand.mSInt64Value == -1) {
      ovf = mSInt64Value == INT64_MIN ;
    }else if (inOperand.mSInt64Value != 0) {
      ovf = (r / inOperand.mSInt64Value) != mSInt64Value ;
    }
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@sint64 * operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (r) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint_36__34_::getter_canMultiply (const GALGAS_sint_36__34_ & inOperand
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const int64_t r = mSInt64Value * inOperand.mSInt64Value ;
    bool ovf = false ;
    if (inOperand.mSInt64Value == -1) {
      ovf = mSInt64Value == INT64_MIN ;
    }else if (inOperand.mSInt64Value != 0) {
      ovf = (r / inOperand.mSInt64Value) != mSInt64Value ;
    }
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::divide_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mSInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("@sint64 divide by zero" COMMA_THERE) ;
    }else if ((mSInt64Value == INT32_MIN) && (inOperand2.mSInt64Value == -1)) {
      inCompiler->onTheFlyRunTimeError ("@sint64 / operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (mSInt64Value / inOperand2.mSInt64Value) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_sint_36__34_::getter_canDivide (const GALGAS_sint_36__34_ & inOperand
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const bool ok = (mSInt64Value != 0) && !((mSInt64Value == INT64_MIN) && (inOperand.mSInt64Value == -1)) ;
    result = GALGAS_bool (ok) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::divide_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_sint_36__34_ ((inOperand.mSInt64Value == 0) ? 0 : (mSInt64Value / inOperand.mSInt64Value)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::modulo_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mSInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("@sint64 divide by zero in modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (mSInt64Value % inOperand2.mSInt64Value) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_unary_minus (C_Compiler * inCompiler 
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    if (mSInt64Value == INT64_MIN) {
      inCompiler->onTheFlyRunTimeError ("@sint64 unary '-' operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (- mSInt64Value) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_unary_minus_no_ovf (void) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    result = GALGAS_sint_36__34_ (- mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::left_shift_operation (const GALGAS_uint inShiftOperand,
                                                               class C_Compiler * /* inCompiler*/
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value << (inShiftOperand.uintValue () & 63)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::left_shift_operation (const GALGAS_bigint inShiftOperand,
                                                               class C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    if (inShiftOperand.bigintValue().isNegative ()) {
      inCompiler->onTheFlyRunTimeError ("@sint64 left shift by a negative amount" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (mSInt64Value << (inShiftOperand.bigintValue().uint32() & 63)) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::right_shift_operation (const GALGAS_uint inShiftOperand,
                                                                class C_Compiler * /* inCompiler*/
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value >> (inShiftOperand.uintValue () & 63)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::right_shift_operation (const GALGAS_bigint inShiftOperand,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    if (inShiftOperand.bigintValue().isNegative ()) {
      inCompiler->onTheFlyRunTimeError ("@sint64 right shift by a negative amount" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (mSInt64Value >> (inShiftOperand.bigintValue().uint32() & 63)) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_and (const GALGAS_sint_36__34_ & inOperand2
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value & inOperand2.mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_or (const GALGAS_sint_36__34_ & inOperand2
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value | inOperand2.mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_xor (const GALGAS_sint_36__34_ & inOperand2
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value ^ inOperand2.mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    result = GALGAS_sint_36__34_ (~ mSInt64Value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

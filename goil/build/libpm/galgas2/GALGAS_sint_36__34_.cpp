//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'GALGAS_sint64' : galgas sint64                                                                                    *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2006, ..., 2011 Pierre Molinaro.                                                                     *
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
//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"
#include "galgas2/C_Compiler.h"
#include "files/C_TextFileWrite.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               GALGAS_sint64                                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_::GALGAS_sint_36__34_ (void) :
mIsValid (false),
mSInt64Value (0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_ (0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_::GALGAS_sint_36__34_ (const int64_t inValue) :
mIsValid (true),
mSInt64Value (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("sint64", true, cStringWithSigned (inValue)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_ (INT64_MAX) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::constructor_min (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_ (INT64_MIN) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_sint_36__34_::reader_uint_36__34_ (C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (mSInt64Value < 0) {
    inCompiler->onTheFlyRunTimeError ("cannot convert a negative sint64 into an uint64" COMMA_THERE) ;
  }else{
    result = GALGAS_uint_36__34_ ((uint64_t) mSInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_sint_36__34_::reader_uint (C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (mSInt64Value < 0) {
    inCompiler->onTheFlyRunTimeError ("cannot convert a negative sint64 into an uint" COMMA_THERE) ;
  }else if (mSInt64Value > ((int64_t) UINT32_MAX)) {
    inCompiler->onTheFlyRunTimeError ("conversion to unsigned value overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_uint ((uint32_t) (mSInt64Value & UINT32_MAX)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_36__34_::reader_sint (C_Compiler * inCompiler
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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_sint_36__34_::reader_double (UNUSED_LOCATION_ARGS) const {
  return GALGAS_double ((double) mSInt64Value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_sint_36__34_::reader_string (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendSigned (mSInt64Value) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_::description (C_String & ioString,
                                       const int32_t /* inIndentation */) const {
  ioString << "<@sint64:" ;
  ioString.appendSigned (mSInt64Value) ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_::increment_operation (C_Compiler * inCompiler 
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mSInt64Value == INT64_MAX) {
      inCompiler->onTheFlyRunTimeError ("++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSInt64Value ++ ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_::decrement_operation (C_Compiler * inCompiler 
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
  //--- Overflow ?
    if (mSInt64Value == INT64_MIN) {
      inCompiler->onTheFlyRunTimeError ("-- operation underflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSInt64Value -- ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::add_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                            C_Compiler * /* inCompiler */ 
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    const int64_t v = mSInt64Value + inOperand2.mSInt64Value ;
    result = GALGAS_sint_36__34_ (v) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::substract_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                                  C_Compiler * /* inCompiler */ 
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    const int64_t v = mSInt64Value - inOperand2.mSInt64Value ;
    result = GALGAS_sint_36__34_ (v) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void productSint64 (const uint64_t inOperand1,
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

GALGAS_sint_36__34_ GALGAS_sint_36__34_::multiply_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                                 C_Compiler * inCompiler 
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    uint64_t operand1 ;
    if (mSInt64Value == INT64_MIN) {
      operand1 = (uint64_t) INT64_MIN ;
    }else if (mSInt64Value < 0) {
      operand1 = (uint64_t) (- mSInt64Value) ;
    }else{
      operand1 = (uint64_t) mSInt64Value ;
    }
    uint64_t operand2 ;
    if (inOperand2.mSInt64Value == INT64_MIN) {
      operand2 = (uint64_t) INT64_MIN ;
    }else if (inOperand2.mSInt64Value < 0) {
      operand2 = (uint64_t) (- inOperand2.mSInt64Value) ;
    }else{
      operand2 = (uint64_t) inOperand2.mSInt64Value ;
    }
    bool resultIsPositive = (mSInt64Value >= 0) == (inOperand2.mSInt64Value >= 0) ;
    uint64_t unsignedResult ;
    bool overflow ;
    productSint64 (operand1, operand2, unsignedResult, overflow) ;
    int64_t resultValue = 0 ;
    if (! overflow) {
      if (resultIsPositive) {
        overflow = unsignedResult > ((uint64_t) INT64_MAX) ;
        resultValue = (int64_t) unsignedResult ;
      }else{
        overflow = unsignedResult > (1LLU << 63) ;
        if (unsignedResult == (1LLU << 63)) {
          resultValue = INT64_MIN ;
        }else{
          resultValue = - ((int64_t) unsignedResult) ;
        }
      }
    }
    if (overflow) {
      inCompiler->onTheFlyRunTimeError ("* operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (resultValue) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::divide_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                               C_Compiler * inCompiler 
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mSInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero" COMMA_THERE) ;
    }else if ((mSInt64Value == INT32_MIN) && (inOperand2.mSInt64Value == -1)) {
      inCompiler->onTheFlyRunTimeError ("/ operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (mSInt64Value / inOperand2.mSInt64Value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::modulo_operation (const GALGAS_sint_36__34_ & inOperand2,
                                                               C_Compiler * inCompiler 
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mSInt64Value == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero in modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (mSInt64Value % inOperand2.mSInt64Value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_unary_minus (C_Compiler * inCompiler 
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    if (mSInt64Value == INT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("unary '-' operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint_36__34_ (- mSInt64Value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::left_shift_operation (const GALGAS_uint inShiftOperand
                                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value << (inShiftOperand.uintValue () & 63)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::right_shift_operation (const GALGAS_uint inShiftOperand
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value >> (inShiftOperand.uintValue () & 63)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_and (const GALGAS_sint_36__34_ & inOperand2
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value & inOperand2.mSInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_or (const GALGAS_sint_36__34_ & inOperand2
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value | inOperand2.mSInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_xor (const GALGAS_sint_36__34_ & inOperand2
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint_36__34_ (mSInt64Value ^ inOperand2.mSInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (isValid ()) {
    result = GALGAS_sint_36__34_ (~ mSInt64Value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

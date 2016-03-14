//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'GALGAS_uint' : galgas uint32                                                                                      *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2015 Pierre Molinaro.                                                                     *
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
#include "galgas2/C_galgas_io.h"
#include "strings/unicode_character_cpp.h"

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint::GALGAS_uint (void) :
mIsValid (false),
mUIntValue (0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint (0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint::GALGAS_uint (const uint32_t inValue) :
mIsValid (true),
mUIntValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("uint", true, cStringWithUnsigned (inValue)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint::GALGAS_uint (const bool inValid, const uint32_t inValue) :
mIsValid (inValid),
mUIntValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("uint", inValid, cStringWithUnsigned (inValue)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint (UINT32_MAX) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_errorCount (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint ((uint32_t) totalErrorCount ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_warningCount (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint ((uint32_t) totalWarningCount ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_valueWithMask (const GALGAS_uint & inLowerIndex,
                                                    const GALGAS_uint & inUpperIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_uint result ;
  if (inLowerIndex.isValid () && inUpperIndex.isValid ()) {
    const uint32_t lowerIndex = inLowerIndex.mUIntValue ;
    const uint32_t upperIndex = inUpperIndex.mUIntValue ;
    if (lowerIndex > upperIndex) {
      inCompiler->onTheFlyRunTimeError ("lower index greater than upper index" COMMA_THERE) ;
    }else if (upperIndex > 31) {
      inCompiler->onTheFlyRunTimeError ("upper index greater than 31" COMMA_THERE) ;
    }else{
      const uint32_t value = (uint32_t) (((1 << (upperIndex + 1)) - 1) & ~ ((1 << lowerIndex) - 1)) ;
      result = GALGAS_uint (value) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_compilationMode (UNUSED_LOCATION_ARGS) {
  #ifdef __LP64__
    return GALGAS_uint (64) ;
  #else
    return GALGAS_uint (32) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operators
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//       Operators                                                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_and (const GALGAS_uint & inOperand
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue & inOperand.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_or (const GALGAS_uint & inOperand
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue | inOperand.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_xor (const GALGAS_uint & inOperand
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue ^ inOperand.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (~ mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_uint::objectCompare (const GALGAS_uint & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mUIntValue < inOperand.mUIntValue) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mUIntValue > inOperand.mUIntValue) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Readers
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::getter_isInRange (const GALGAS_range & inRange
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inRange.isValid ()) {
    const uint32_t start = inRange.mAttribute_start.uintValue () ;
    const uint32_t end = start + inRange.mAttribute_length.uintValue () ;
    result = GALGAS_bool ((mUIntValue >= start) && (mUIntValue < end)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_uint::getter_sint (C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (mUIntValue > ((uint32_t) INT32_MAX)) {
    inCompiler->onTheFlyRunTimeError ("@uint to signed value conversion overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_sint ((int32_t) mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_uint::getter_sint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint_36__34_ ((int64_t) mUIntValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint::getter_uint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint_36__34_ (mUIntValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_uint::getter_double (UNUSED_LOCATION_ARGS) const {
  return GALGAS_double (mUIntValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_uint::getter_bigint (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (isValid ()) {
    result = GALGAS_bigint (C_BigInt (mUIntValue, false)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_uint::getter_string (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendUnsigned (mUIntValue) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_uint::getter_hexString (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendCString ("0x") ;
  s.appendUnsignedHex (mUIntValue) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_uint::getter_xString (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendUnsignedHex (mUIntValue) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@uint:" ;
  if (isValid ()) {
    ioString.appendUnsigned (mUIntValue) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::getter_significantBitCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    uint32_t v = mUIntValue ;
    uint32_t idx = 0 ;
    while (v != 0) {
      idx ++ ;
      v >>= 1 ;
    }
    result = GALGAS_uint (idx) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::getter_oneBitCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    uint32_t v = mUIntValue ;
    uint32_t idx = 0 ;
    while (v != 0) {
      idx += v & 1 ;
      v >>= 1 ;
    }
    result = GALGAS_uint (idx) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::getter_lsbIndex (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  uint32_t v = mUIntValue ;
  if (v == 0) {
    inCompiler->onTheFlyRunTimeError ("null receiver for lsbIndex reader" COMMA_THERE) ;
  }else{
    uint32_t idx = 0 ;
    while ((v != 0) && ((v & 1) == 0)) {
      idx ++ ;
      v >>= 1 ;
    }
    result = GALGAS_uint (idx) ;
  }
  return result ;  
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::getter_isUnicodeValueAssigned (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeCharacterAssigned (TO_UNICODE (mUIntValue))) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operations
#endif

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::increment_operation_no_overflow (void) {
  mUIntValue ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::decrement_operation_no_overflow (void) {
  mUIntValue -- ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::increment_operation (C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mUIntValue == UINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("@uint ++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mUIntValue ++ ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::decrement_operation (C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
  //--- Overflow ?
    if (mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@uint -- operation underflow" COMMA_THERE) ;
      drop () ;
    }else{
      mUIntValue -- ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::add_operation (const GALGAS_uint & inOperand,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue + inOperand.mUIntValue ;
    const bool ovf = r < mUIntValue ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@uint + operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (r) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::getter_canAdd (const GALGAS_uint & inOperand
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue + inOperand.mUIntValue ;
    const bool ovf = r < mUIntValue ;
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::plusAssign_operation (const GALGAS_uint inOperand,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue + inOperand.mUIntValue ;
    const bool ovf = r < mUIntValue ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@uint += operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mUIntValue = r ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::minusAssign_operation (const GALGAS_uint inOperand,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const bool ovf = mUIntValue < inOperand.mUIntValue ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@uint -= operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mUIntValue -= inOperand.mUIntValue ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::mulAssign_operation (const GALGAS_uint inOperand,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue * inOperand.mUIntValue ;
    const bool ovf = (inOperand.mUIntValue != 0) && ((r / inOperand.mUIntValue) != mUIntValue) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@uint *= operation overflow" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mUIntValue = r ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint::divAssign_operation (const GALGAS_uint inOperand,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@uint /= divide by zero" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mUIntValue /= inOperand.mUIntValue ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::add_operation_no_ovf (const GALGAS_uint & inOperand) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue + inOperand.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::substract_operation (const GALGAS_uint & inOperand,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue - inOperand.mUIntValue ;
    const bool ovf = mUIntValue < inOperand.mUIntValue ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@uint - operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (r) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::getter_canSubstract (const GALGAS_uint & inOperand
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_bool (mUIntValue >= inOperand.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::substract_operation_no_ovf (const GALGAS_uint & inOperand2) const {
  GALGAS_uint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_uint (mUIntValue - inOperand2.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::multiply_operation_no_ovf (const GALGAS_uint & inOperand2) const {
  GALGAS_uint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_uint (mUIntValue * inOperand2.mUIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::multiply_operation (const GALGAS_uint & inOperand,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue * inOperand.mUIntValue ;
    const bool ovf = (inOperand.mUIntValue != 0) && ((r / inOperand.mUIntValue) != mUIntValue) ;
    if (ovf) {
      inCompiler->onTheFlyRunTimeError ("@uint * operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (r) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::getter_canMultiply (const GALGAS_uint & inOperand
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    const uint32_t r = mUIntValue * inOperand.mUIntValue ;
    const bool ovf = (inOperand.mUIntValue != 0) && ((r / inOperand.mUIntValue) != mUIntValue) ;
    result = GALGAS_bool (!ovf) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::divide_operation (const GALGAS_uint & inOperand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@uint divide by zero" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (mUIntValue / inOperand.mUIntValue) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::getter_canDivide (const GALGAS_uint & inOperand
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_bool (inOperand.mUIntValue != 0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::divide_operation_no_ovf (const GALGAS_uint & inOperand) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint ((inOperand.mUIntValue == 0) ? 0 : (mUIntValue / inOperand.mUIntValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::modulo_operation (const GALGAS_uint & inOperand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@uint divide by zero in modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (mUIntValue % inOperand.mUIntValue) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::left_shift_operation (const GALGAS_uint inOperand
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue << (inOperand.mUIntValue & 31)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::right_shift_operation (const GALGAS_uint inOperand
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue >> (inOperand.mUIntValue & 31)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

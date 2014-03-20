//-----------------------------------------------------------------------------*
//                                                                             *
//  'GALGAS_uint' : galgas uint32                                            *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2009, ..., 2011 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#include "predefined-types.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "strings/unicode_character_cpp.h"

//-----------------------------------------------------------------------------*

GALGAS_uint::GALGAS_uint (void) :
mIsValid (false),
mUIntValue (0) {
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint (0) ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint::GALGAS_uint (const PMUInt32 inValue) :
mIsValid (true),
mUIntValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("uint", true, cStringWithUnsigned (inValue)) ;
  }
}

//-----------------------------------------------------------------------------*

GALGAS_uint::GALGAS_uint (const bool inValid, const PMUInt32 inValue) :
mIsValid (inValid),
mUIntValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("uint", inValid, cStringWithUnsigned (inValue)) ;
  }
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint (PMUINT32_MAX) ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_errorCount (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint ((PMUInt32) totalErrorCount ()) ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_warningCount (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint ((PMUInt32) totalWarningCount ()) ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_valueWithMask (const GALGAS_uint & inLowerIndex,
                                                    const GALGAS_uint & inUpperIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_uint result ;
  if (inLowerIndex.isValid () && inUpperIndex.isValid ()) {
    const PMUInt32 lowerIndex = inLowerIndex.mUIntValue ;
    const PMUInt32 upperIndex = inUpperIndex.mUIntValue ;
    if (lowerIndex > upperIndex) {
      inCompiler->onTheFlyRunTimeError ("lower index greater than upper index" COMMA_THERE) ;
    }else if (upperIndex > 31) {
      inCompiler->onTheFlyRunTimeError ("upper index greater than 31" COMMA_THERE) ;
    }else{
      const PMUInt32 value = (PMUInt32) (((1 << (upperIndex + 1)) - 1) & ~ ((1 << lowerIndex) - 1)) ;
      result = GALGAS_uint (value) ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::constructor_compilationMode (UNUSED_LOCATION_ARGS) {
  #ifdef __LP64__
    return GALGAS_uint (64) ;
  #else
    return GALGAS_uint (32) ;
  #endif
}

//-----------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operators
#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//       Operators                                                           *
//                                                                             *
//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_and (const GALGAS_uint & inOperand
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue & inOperand.mUIntValue) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_or (const GALGAS_uint & inOperand
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue | inOperand.mUIntValue) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_xor (const GALGAS_uint & inOperand
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue ^ inOperand.mUIntValue) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (~ mUIntValue) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Readers
#endif

//-----------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::reader_isInRange (const GALGAS_range & inRange
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inRange.isValid ()) {
    const PMUInt32 start = inRange.mAttribute_start.uintValue () ;
    const PMUInt32 end = start + inRange.mAttribute_length.uintValue () ;
    result = GALGAS_bool ((mUIntValue >= start) && (mUIntValue < end)) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_sint GALGAS_uint::reader_sint (C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (mUIntValue > ((PMUInt32) PMSINT32_MAX)) {
    inCompiler->onTheFlyRunTimeError ("unsigned value to signed value conversion overflow" COMMA_THERE) ;
  }else{
    result = GALGAS_sint ((PMSInt32) mUIntValue) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_uint::reader_sint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint_36__34_ ((PMSInt64) mUIntValue) ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint::reader_uint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint_36__34_ (mUIntValue) ;
}

//-----------------------------------------------------------------------------*

GALGAS_double GALGAS_uint::reader_double (UNUSED_LOCATION_ARGS) const {
  return GALGAS_double (mUIntValue) ;
}

//-----------------------------------------------------------------------------*

GALGAS_string GALGAS_uint::reader_string (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendUnsigned (mUIntValue) ;
  return GALGAS_string (s) ;
}

//-----------------------------------------------------------------------------*

GALGAS_string GALGAS_uint::reader_hexString (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendCString ("0x") ;
  s.appendUnsignedHex (mUIntValue) ;
  return GALGAS_string (s) ;
}

//-----------------------------------------------------------------------------*

GALGAS_string GALGAS_uint::reader_xString (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendUnsignedHex (mUIntValue) ;
  return GALGAS_string (s) ;
}

//-----------------------------------------------------------------------------*

void GALGAS_uint::description (C_String & ioString,
                               const PMSInt32 /* inIndentation */) const {
  ioString << "<@uint:" ;
  if (isValid ()) {
    ioString.appendUnsigned (mUIntValue) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::reader_significantBitCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    PMUInt32 v = mUIntValue ;
    PMUInt32 idx = 0 ;
    while (v != 0) {
      idx ++ ;
      v >>= 1 ;
    }
    result = GALGAS_uint (idx) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::reader_oneBitCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    PMUInt32 v = mUIntValue ;
    PMUInt32 idx = 0 ;
    while (v != 0) {
      idx += v & 1 ;
      v >>= 1 ;
    }
    result = GALGAS_uint (idx) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::reader_lsbIndex (C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  PMUInt32 v = mUIntValue ;
  if (v == 0) {
    inCompiler->onTheFlyRunTimeError ("null receiver for lsbIndex reader" COMMA_THERE) ;
  }else{
    PMUInt32 idx = 0 ;
    while ((v != 0) && ((v & 1) == 0)) {
      idx ++ ;
      v >>= 1 ;
    }
    result = GALGAS_uint (idx) ;
  }
  return result ;  
}

//-----------------------------------------------------------------------------*

GALGAS_bool GALGAS_uint::reader_isUnicodeValueAssigned (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (isUnicodeCharacterAssigned (TO_UNICODE (mUIntValue))) ;
}

//-----------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operations
#endif

//-----------------------------------------------------------------------------*

void GALGAS_uint::increment_operation (C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mUIntValue == PMUINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mUIntValue ++ ;
    }
  }
}

//-----------------------------------------------------------------------------*

void GALGAS_uint::decrement_operation (C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
  //--- Overflow ?
    if (mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("-- operation underflow" COMMA_THERE) ;
      drop () ;
    }else{
      mUIntValue -- ;
    }
  }
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::add_operation (const GALGAS_uint & inOperand,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    const PMUInt64 v = ((PMUInt64) mUIntValue) + ((PMUInt64) inOperand.mUIntValue) ;
    if (v > PMUINT32_MAX) {
        inCompiler->onTheFlyRunTimeError ("+ operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((PMUInt32) (v & PMUINT32_MAX)) ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::substract_operation (const GALGAS_uint & inOperand,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    if (mUIntValue < inOperand.mUIntValue) {
        inCompiler->onTheFlyRunTimeError ("@uint - operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (mUIntValue - inOperand.mUIntValue) ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::multiply_operation (const GALGAS_uint & inOperand,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    const PMUInt64 v = ((PMUInt64) mUIntValue) * ((PMUInt64) inOperand.mUIntValue) ;
    if (v > PMUINT32_MAX) {
        inCompiler->onTheFlyRunTimeError ("* operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_uint ((PMUInt32) (v & PMUINT32_MAX)) ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::divide_operation (const GALGAS_uint & inOperand,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (mUIntValue / inOperand.mUIntValue) ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::modulo_operation (const GALGAS_uint & inOperand,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mUIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero in modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_uint (mUIntValue % inOperand.mUIntValue) ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::left_shift_operation (const GALGAS_uint inOperand
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue << (inOperand.mUIntValue & 31)) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint::right_shift_operation (const GALGAS_uint inOperand
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_uint (mUIntValue >> (inOperand.mUIntValue & 31)) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

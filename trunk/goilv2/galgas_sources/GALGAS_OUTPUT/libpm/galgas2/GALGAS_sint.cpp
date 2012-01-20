//---------------------------------------------------------------------------*
//                                                                           *
//  'GALGAS_sint' : galgas sint32                                            *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2004, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------*

GALGAS_sint::GALGAS_sint (void) :
mIsValid (false),
mSIntValue (0) {
}

//---------------------------------------------------------------------------*

GALGAS_sint::GALGAS_sint (const PMSInt32 inValue) :
mIsValid (true),
mSIntValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("sint", true, cStringWithSigned (inValue)) ;
  }
}

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::constructor_max (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint (PMSINT32_MAX) ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::constructor_min (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint (PMSINT32_MIN) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_sint::reader_uint (C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (mSIntValue < 0) {
    inCompiler->onTheFlyRunTimeError ("cannot convert a negative integer into unsigned value" COMMA_THERE) ;
  }else{
    result = GALGAS_uint ((PMUInt32) mSIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_sint::reader_uint_36__34_ (C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (mSIntValue < 0) {
    inCompiler->onTheFlyRunTimeError ("cannot convert a negative integer into unsigned value" COMMA_THERE) ;
  }else{
    result = GALGAS_uint_36__34_ ((PMUInt64) mSIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint::reader_sint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint_36__34_ (mSIntValue) ;
}

//---------------------------------------------------------------------------*

GALGAS_double GALGAS_sint::reader_double (UNUSED_LOCATION_ARGS) const {
  return GALGAS_double (mSIntValue) ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_sint::reader_string (UNUSED_LOCATION_ARGS) const {
  C_String s ; s.appendSigned (mSIntValue) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------*

void GALGAS_sint::description (C_String & ioString,
                               const PMSInt32 /* inIndentation */) const {
  ioString << "<@sint:" ;
  if (isValid ()) {
    ioString << cStringWithSigned (mSIntValue) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

void GALGAS_sint::increment_operation (C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mSIntValue == PMSINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("++ operation overflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSIntValue ++ ;
    }
  }
}

//---------------------------------------------------------------------------*

void GALGAS_sint::decrement_operation (C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (mSIntValue == PMSINT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("-- operation underflow" COMMA_THERE) ;
      drop () ;
    }else{
      mSIntValue -- ;
    }
  }
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::add_operation (const GALGAS_sint & inOperand2,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    const PMSInt64 v = ((PMSInt64) mSIntValue) + ((PMSInt64) inOperand2.mSIntValue) ;
    if (v > PMSINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("+ operation overflow" COMMA_THERE) ;
    }else if (v < PMSINT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("+ operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint ((PMSInt32) (mSIntValue + inOperand2.mSIntValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::substract_operation (const GALGAS_sint & inOperand2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    const PMSInt64 v = ((PMSInt64) mSIntValue) - ((PMSInt64) inOperand2.mSIntValue) ;
    if (v > PMSINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("@sint - operation overflow" COMMA_THERE) ;
    }else if (v < PMSINT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("@sint - operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint ((PMSInt32) (mSIntValue - inOperand2.mSIntValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::multiply_operation (const GALGAS_sint & inOperand2,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    const PMSInt64 v = ((PMSInt64) mSIntValue) * ((PMSInt64) inOperand2.mSIntValue) ;
    if (v > PMSINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("* operation overflow" COMMA_THERE) ;
    }else if (v < PMSINT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("* operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint ((PMSInt32) (mSIntValue * inOperand2.mSIntValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::divide_operation (const GALGAS_sint & inOperand2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    if (mSIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero" COMMA_THERE) ;
    }else if ((mSIntValue == PMSINT32_MIN) && (inOperand2.mSIntValue == -1)) {
      inCompiler->onTheFlyRunTimeError ("/ operation overflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (mSIntValue / inOperand2.mSIntValue) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::modulo_operation (const GALGAS_sint & inOperand2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    if (mSIntValue == 0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero in modulo operation" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (mSIntValue % inOperand2.mSIntValue) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::operator_unary_minus (C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid ()) {
    if (mSIntValue == PMSINT32_MIN) {
      inCompiler->onTheFlyRunTimeError ("unary '-' operation underflow" COMMA_THERE) ;
    }else{
      result = GALGAS_sint (- mSIntValue) ;
    }
  }
  return result ;
}


//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::left_shift_operation (const GALGAS_uint inShiftOperand
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint (mSIntValue << (inShiftOperand.uintValue () & 31)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::right_shift_operation (const GALGAS_uint inShiftOperand
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inShiftOperand.isValid ()) {
    result = GALGAS_sint (mSIntValue >> (inShiftOperand.uintValue () & 31)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::operator_and (const GALGAS_sint & inOperand2
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue & inOperand2.mSIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::operator_or (const GALGAS_sint & inOperand2
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue | inOperand2.mSIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::operator_xor (const GALGAS_sint & inOperand2
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_sint (mSIntValue ^ inOperand2.mSIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (isValid ()) {
    result = GALGAS_sint (~ mSIntValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

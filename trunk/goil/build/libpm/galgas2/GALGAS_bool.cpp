//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   GALGAS_bool : this class implements the GALGAS 'bool' native type                                                 *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2014 Pierre Molinaro.                                                                     *
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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     'GALGAS_bool' class                                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool::GALGAS_bool (void) :
mIsValid (false),
mBoolValue (false) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_bool::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_bool (false) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool::GALGAS_bool (const bool inValue) :
mIsValid (true),
mBoolValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("bool", true, inValue ? "true" : "false") ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool::GALGAS_bool (const bool inIsBuilt,
                          const bool inValue) :
mIsValid (inIsBuilt),
mBoolValue (inValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool::GALGAS_bool (const typeComparisonKind inComparisonKind,
                          const typeComparisonResult inComparisonResult) :
mIsValid (kOperandNotValid != inComparisonResult),
mBoolValue (boolValueFromComparisonKindAndComparisonResult (inComparisonKind, inComparisonResult)) {
}

//---------------------------------------------------------------------------------------------------------------------*

enumGalgasBool GALGAS_bool::boolEnum (void) const {
  enumGalgasBool result = kBoolNotValid ;
  if (isValid ()) {
    result = mBoolValue ? kBoolTrue : kBoolFalse ;
  }
  return result ;  
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_bool::objectCompare (const GALGAS_bool & inOperand) const {
  //printf ("COMPARE BOOL %d %d\n", inOperand1.mBoolValue, inOperand2.mBoolValue) ;
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mBoolValue < inOperand.mBoolValue) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mBoolValue > inOperand.mBoolValue) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_bool::operator_and (const GALGAS_bool & inOperand2
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_bool (mBoolValue && inOperand2.mBoolValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_bool::operator_or (const GALGAS_bool & inOperand2
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && (inOperand2.isValid ())) {
    result = GALGAS_bool (mBoolValue || inOperand2.mBoolValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_bool::operator_xor (const GALGAS_bool & inOperand2
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_bool (mBoolValue != inOperand2.mBoolValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_bool::operator_not (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (! mBoolValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_bool::reader_cString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mBoolValue ? "true" : "false") ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_bool::reader_ocString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mBoolValue ? "YES" : "NO") ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_bool::reader_uint (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint ((uint32_t) (mBoolValue ? 1 : 0)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_bool::reader_sint (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint (mBoolValue ? 1 : 0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_bool::reader_uint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint_36__34_ (mBoolValue ? 1 : 0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_bool::reader_sint_36__34_ (UNUSED_LOCATION_ARGS) const {
  return GALGAS_sint_36__34_ (mBoolValue ? 1 : 0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bool::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@bool:" ;
  if (isValid ()) {
    ioString << (mBoolValue ? "true" : "false") ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   GALGAS_double                                                                                                     *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2002, ..., 2013 Pierre Molinaro.                                                                     *
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

#include <math.h>

//---------------------------------------------------------------------------------------------------------------------*

static const double PI_CONSTANT = 3.14159265358979323846 ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double::GALGAS_double (void) :
mIsValid (false),
mDoubleValue (0.0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_double (0.0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double::GALGAS_double (const double inValue) :
mIsValid (true),
mDoubleValue (inValue) {
  if (traceIsEnabled ()) {
    appendTrace ("double", true, cStringWithDouble (inValue)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::constructor_pi (UNUSED_LOCATION_ARGS) {
  return GALGAS_double (PI_CONSTANT) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::constructor_doubleWithBinaryImage (const GALGAS_uint_36__34_ & inImage
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result ;
  if (inImage.isValid ()) {
    union {
      uint64_t unsignedIntegerValue ;
      double   doubleValue ;
    } ;
    unsignedIntegerValue = inImage.uint64Value () ;
    result = GALGAS_double (doubleValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_double::getter_binaryImage (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid ()) {
    union {
      uint64_t unsignedIntegerValue ;
      double   doubleValue ;
    } ;
    doubleValue = mDoubleValue ;
    result = GALGAS_uint_36__34_ (unsignedIntegerValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_cos (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (cos (mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_sqrt (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue < 0.0) {
      C_String s ;
      s << "Cannot compute square root of a negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (sqrt (mDoubleValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_log_32_ (C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue <= 0.0) {
      C_String s ;
      s << "Cannot compute log2 of a null or negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (log2 (mDoubleValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_log_31__30_ (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue <= 0.0) {
      C_String s ;
      s << "Cannot compute log10 of a null or negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (log10 (mDoubleValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_logn (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue <= 0.0) {
      C_String s ;
      s << "Cannot compute logn of a null or negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (::log (mDoubleValue)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_exp (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (::exp (mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_cosDegree (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (cos (mDoubleValue * PI_CONSTANT / 180.0)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_sin (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (sin (mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_sinDegree (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (sin (mDoubleValue * PI_CONSTANT / 180.0)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_tan (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (tan (mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_tanDegree (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (tan (mDoubleValue * PI_CONSTANT / 180.0)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::getter_power (const GALGAS_double & inExponant,
                                           C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inExponant.isValid ()) {
    result = GALGAS_double (pow (mDoubleValue, inExponant.mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_double::getter_uint (C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if ((mDoubleValue > (double) UINT32_MAX) || (mDoubleValue < 0.0)) {
    C_String s ;
    s << "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s << ") to @uint" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_uint ((uint32_t) (lround (mDoubleValue) & INT32_MAX)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_double::getter_uint_36__34_ (C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if ((mDoubleValue > (double) UINT64_MAX) || (mDoubleValue < 0.0)) {
    C_String s ;
    s << "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s << ") to @uint64" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_uint_36__34_ ((uint64_t) lround (mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_double::getter_sint (C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if ((mDoubleValue > (double) INT32_MAX) || (mDoubleValue < (double) INT32_MIN)) {
    C_String s ;
    s << "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s << ") to @sint" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_sint ((int32_t) (lround (mDoubleValue) & INT32_MAX)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_double::getter_sint_36__34_ (C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if ((mDoubleValue > (double) INT64_MAX) || (mDoubleValue < (double) INT64_MIN)) {
    C_String s ;
    s << "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s << ") to @sint64" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_sint_36__34_ (lround (mDoubleValue)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_double::objectCompare (const GALGAS_double & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mDoubleValue < inOperand.mDoubleValue) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mDoubleValue > inOperand.mDoubleValue) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_double::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@double:" ;
  if (isValid ()) {
    ioString.appendDouble (mDoubleValue) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_double::getter_string (UNUSED_LOCATION_ARGS) const {
  C_String s ;
  s.appendDouble (mDoubleValue) ;
  return GALGAS_string (s) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::add_operation (const GALGAS_double & inOperand2,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_double (mDoubleValue + inOperand2.mDoubleValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::substract_operation (const GALGAS_double & inOperand2,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_double (mDoubleValue - inOperand2.mDoubleValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::multiply_operation (const GALGAS_double & inOperand2,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_double (mDoubleValue * inOperand2.mDoubleValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::divide_operation (const GALGAS_double & inOperand2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    if (inOperand2.mDoubleValue == 0.0) {
      inCompiler->onTheFlyRunTimeError ("divide by zero" COMMA_THERE) ;
    }else{
      result = GALGAS_double (mDoubleValue / inOperand2.mDoubleValue) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::operator_unary_minus (C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (- mDoubleValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_double::modulo_operation (const GALGAS_double & inOperand,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand.isValid ()) {
    const uint64_t times = (uint64_t) (mDoubleValue / inOperand.mDoubleValue) ;
    result = GALGAS_double (mDoubleValue - ((double) times) * inOperand.mDoubleValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

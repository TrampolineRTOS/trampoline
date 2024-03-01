//--------------------------------------------------------------------------------------------------
//
//   GALGAS_double                                                                               
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2002, ..., 2016 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"
#include "Compiler.h"

//--------------------------------------------------------------------------------------------------
// https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
//--------------------------------------------------------------------------------------------------

#define _USE_MATH_DEFINES
#include <math.h>

//--------------------------------------------------------------------------------------------------

static const double PI_CONSTANT = M_PI ;

//--------------------------------------------------------------------------------------------------

GALGAS_double::GALGAS_double (void) :
AC_GALGAS_root (),
mIsValid (false),
mDoubleValue (0.0) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_double::GALGAS_double (const double inValue) :
AC_GALGAS_root (),
mIsValid (true),
mDoubleValue (inValue) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::class_func_pi (UNUSED_LOCATION_ARGS) {
  return GALGAS_double (PI_CONSTANT) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::class_func_doubleWithBinaryImage (const GALGAS_uint_36__34_ & inImage
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

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_double::getter_binaryImage (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid ()) {
    union {
      uint64_t unsignedIntegerValue ;
      double theDoubleValue ;
    } ;
    theDoubleValue = mDoubleValue ;
    result = GALGAS_uint_36__34_ (unsignedIntegerValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_cos (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (cos (mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_sqrt (Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue < 0.0) {
      String s = "Cannot compute square root of a negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (sqrt (mDoubleValue)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_log_32_ (Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue <= 0.0) {
      String s ;
      s.appendCString ("Cannot compute log2 of a null or negative @double") ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (log2 (mDoubleValue)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_log_31__30_ (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue <= 0.0) {
      String s = "Cannot compute log10 of a null or negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (log10 (mDoubleValue)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_logn (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    if (mDoubleValue <= 0.0) {
      String s = "Cannot compute logn of a null or negative @double" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_double (::log (mDoubleValue)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_exp (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (::exp (mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_cosDegree (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (cos (mDoubleValue * PI_CONSTANT / 180.0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_sin (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (sin (mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_sinDegree (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (sin (mDoubleValue * PI_CONSTANT / 180.0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_tan (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (tan (mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_tanDegree (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (tan (mDoubleValue * PI_CONSTANT / 180.0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::getter_power (const GALGAS_double & inExponant,
                                           Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inExponant.isValid ()) {
    result = GALGAS_double (pow (mDoubleValue, inExponant.mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_double::getter_uint (Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if ((mDoubleValue > (double) UINT32_MAX) || (mDoubleValue < 0.0)) {
    String s = "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s.appendCString (") to @uint") ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_uint ((uint32_t) (lround (mDoubleValue) & INT32_MAX)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_double::getter_uint_36__34_ (Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if ((mDoubleValue > (double) UINT64_MAX) || (mDoubleValue < 0.0)) {
    String s = "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s.appendCString (") to @uint64") ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_uint_36__34_ ((uint64_t) lround (mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_double::getter_sint (Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if ((mDoubleValue > (double) INT32_MAX) || (mDoubleValue < (double) INT32_MIN)) {
    String s = "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s.appendCString (") to @sint") ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_sint ((int32_t) (lround (mDoubleValue) & INT32_MAX)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_double::getter_sint_36__34_ (Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if ((mDoubleValue > (double) INT64_MAX) || (mDoubleValue < (double) INT64_MIN)) {
    String s = "Cannot convert @double (" ;
    s.appendDouble (mDoubleValue) ;
    s.appendCString (") to @sint64") ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    result = GALGAS_sint_36__34_ (lround (mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void GALGAS_double::description (String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@double:") ;
  if (isValid ()) {
    ioString.appendDouble (mDoubleValue) ;
  }else{
    ioString.appendCString ("not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_double::getter_string (UNUSED_LOCATION_ARGS) const {
  String s ;
  s.appendDouble (mDoubleValue) ;
  return GALGAS_string (s) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::add_operation (const GALGAS_double & inOperand2,
                                            Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_double (mDoubleValue + inOperand2.mDoubleValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::substract_operation (const GALGAS_double & inOperand2,
                                                  Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_double (mDoubleValue - inOperand2.mDoubleValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_double::plusAssign_operation (const GALGAS_double inOperand,
                                          Compiler *
                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    mDoubleValue += inOperand.mDoubleValue ;
  }else{
    mIsValid = false ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_double::minusAssign_operation (const GALGAS_double inOperand,
                                           Compiler *
                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    mDoubleValue -= inOperand.mDoubleValue ;
  }else{
    mIsValid = false ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_double::mulAssign_operation (const GALGAS_double inOperand,
                                         Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    mDoubleValue *= inOperand.mDoubleValue ;
  }else{
    mIsValid = false ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_double::divAssign_operation (const GALGAS_double inOperand,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid ()) {
    if (inOperand.mDoubleValue == 0) {
      inCompiler->onTheFlyRunTimeError ("@double /= divide by zero" COMMA_THERE) ;
      mIsValid = false ;
    }else{
      mDoubleValue /= inOperand.mDoubleValue ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::multiply_operation (const GALGAS_double & inOperand2,
                                                 Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_double (mDoubleValue * inOperand2.mDoubleValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::divide_operation (const GALGAS_double & inOperand2,
                                               Compiler * inCompiler
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

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::divide_operation_no_ovf (const GALGAS_double & inOperand) const {
  GALGAS_double result ;
  if (isValid () && inOperand.isValid ()) {
    result = GALGAS_double ((inOperand.mDoubleValue == 0.0) ? 0.0 : (mDoubleValue / inOperand.mDoubleValue)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::operator_unary_minus (Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid ()) {
    result = GALGAS_double (- mDoubleValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::modulo_operation (const GALGAS_double & inOperand,
                                               Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (isValid () && inOperand.isValid ()) {
    const uint64_t times = (uint64_t) (mDoubleValue / inOperand.mDoubleValue) ;
    result = GALGAS_double (mDoubleValue - ((double) times) * inOperand.mDoubleValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

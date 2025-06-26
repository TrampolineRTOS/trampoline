//--------------------------------------------------------------------------------------------------
//
//  GALGAS_timer                                                                                 
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2015, ..., 2015 Pierre Molinaro.
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

GALGAS_timer::GALGAS_timer (void) :
AC_GALGAS_root (),
mIsValid (false),
mTimer () {
}

//--------------------------------------------------------------------------------------------------

void GALGAS_timer::description (String & ioString,
                                const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@timer: ") ;
  if (!mIsValid) {
    ioString.appendCString ("not built") ;
  }else{
    ioString.appendString (mTimer.timeString ()) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_timer GALGAS_timer::class_func_start (UNUSED_LOCATION_ARGS) {
  GALGAS_timer result ;
  result.mIsValid = true ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_timer::setter_stop (UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    mTimer.stopTimer () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_timer::setter_resume (UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    mTimer = Timer () ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_timer::getter_isRunning (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid ()) {
    result = GALGAS_bool (mTimer.isRunning ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_timer::getter_msFromStart (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mTimer.msFromStart ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_timer::getter_string (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mTimer.timeString ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

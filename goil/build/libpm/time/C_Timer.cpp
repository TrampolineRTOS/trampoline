//----------------------------------------------------------------------------------------------------------------------
//
//  Timer class.
//
//  This file is part of libpm library
//
//  Copyright (C) 1999, ..., 2023 Pierre Molinaro.
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

#include "time/C_Timer.h"
#include "utilities/M_machine.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

C_Timer::C_Timer (void) :
mStart (::clock ()),
mEnd (::clock ()),
mRunning (true) {
  mEnd = mStart ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Timer::stopTimer (void) {
  if (mRunning) {
    mEnd = ::clock () ;
    mRunning = false ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Timer::startTimer (void) {
  mStart = ::clock () ;
  mEnd = mStart ;
  mRunning = true ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Timer::msFromStart (void) const {
  clock_t duration ;
  if (mRunning) {
    duration = ::clock () - mStart ;
  }else{
    duration = mEnd - mStart ;
  }
  duration /= CLOCKS_PER_SEC / 1000 ;
  return uint32_t (duration) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Timer::timeString (void) const {
  const uint32_t d = msFromStart () ;
  const uint32_t ms = d % 1000 ;
  const uint32_t secondes = (d / 1000) % 60 ;
  const uint32_t minutes  = d / 60000 ;
  C_String result ;
  if (minutes > 0) {
    result.appendUnsigned (minutes) ;
    result << " min " ;
  }
  result.appendUnsigned (secondes) ;
  result << " s " ;
  result.appendUnsigned (ms / 100) ;
  result.appendUnsigned ((ms / 10) % 10) ;
  result.appendUnsigned (ms % 10) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const C_Timer & inTimer) {
  clock_t duration ;
  if (inTimer.mRunning) {
    duration = ::clock () - inTimer.mStart ;
  }else{
    duration = inTimer.mEnd - inTimer.mStart ;
  }
  duration /= CLOCKS_PER_SEC / 100 ;
  const clock_t cs = duration % 100 ;
  const clock_t secondes = (duration / 100) % 60 ;
  const clock_t minutes = duration / 6000 ;
  if (minutes > 0) {
    inStream.appendUnsigned (minutes) ;
    inStream << " min " ;
  }
  inStream.appendUnsigned (secondes) ;
  inStream << " s " ;
  inStream.appendUnsigned (cs / 10) ;
  inStream.appendUnsigned (cs % 10) ;
  return inStream ;
}

//----------------------------------------------------------------------------------------------------------------------

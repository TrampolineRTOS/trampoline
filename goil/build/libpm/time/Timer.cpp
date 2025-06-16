//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#include "Timer.h"
#include "M_machine.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

Timer::Timer (void) :
mStart (::clock ()),
mEnd (::clock ()),
mRunning (true) {
  mEnd = mStart ;
}

//--------------------------------------------------------------------------------------------------

void Timer::stopTimer (void) {
  if (mRunning) {
    mEnd = ::clock () ;
    mRunning = false ;
  }
}

//--------------------------------------------------------------------------------------------------

void Timer::startTimer (void) {
  mStart = ::clock () ;
  mEnd = mStart ;
  mRunning = true ;
}

//--------------------------------------------------------------------------------------------------

uint32_t Timer::msFromStart (void) const {
  clock_t duration ;
  if (mRunning) {
    duration = ::clock () - mStart ;
  }else{
    duration = mEnd - mStart ;
  }
  duration /= CLOCKS_PER_SEC / 1000 ;
  return uint32_t (duration) ;
}

//--------------------------------------------------------------------------------------------------

String Timer::timeString (void) const {
  const uint32_t d = msFromStart () ;
  const uint32_t ms = d % 1000 ;
  const uint32_t secondes = (d / 1000) % 60 ;
  const uint32_t minutes  = d / 60000 ;
  String result ;
  if (minutes > 0) {
    result.appendUnsigned (minutes) ;
    result.appendCString (" min ") ;
  }
  result.appendUnsigned (secondes) ;
  result.appendCString (" s ") ;
  result.appendUnsigned (ms / 100) ;
  result.appendUnsigned ((ms / 10) % 10) ;
  result.appendUnsigned (ms % 10) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

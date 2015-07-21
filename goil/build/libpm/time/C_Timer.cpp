//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Timer class.                                                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "time/C_Timer.h"
#include "utilities/M_machine.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifdef LIBPM_USES_TIMEVAL_STRUCT
  static timeval gTime ;
  static timeval now (void) {
    gettimeofday (& gTime, NULL) ;
    return gTime ;
  }
#else
  static clock_t now (void) {
    return ::clock () ;
  }
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_Timer::C_Timer (void) :
mStart (now ()),
mEnd (now ()),
mRunning (true) {
  mEnd = mStart ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Timer::stopTimer (void) {
  if (mRunning) {
    #ifdef LIBPM_USES_TIMEVAL_STRUCT
      gettimeofday (& mEnd, NULL) ;
    #else
      mEnd = ::clock () ;
    #endif
    mRunning = false ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Timer::startTimer (void) {
  #ifdef LIBPM_USES_TIMEVAL_STRUCT
    gettimeofday (& mStart, NULL) ;
  #else
    mStart = ::clock () ;
  #endif
  mEnd = mStart ;
  mRunning = true ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Timer::msFromStart (void) const {
  #ifdef LIBPM_USES_TIMEVAL_STRUCT
    timeval t ;
    if (mRunning) {
      timeval now ;
      gettimeofday (& now, NULL) ;
      timersub (& now, & mStart, & t) ;
    }else{
      timersub (& mEnd, & mStart, & t) ;
    }
    const uint32_t duration = ((uint32_t) t.tv_sec) * 1000 + (uint32_t) (t.tv_usec / 1000) ;
  #else
    uint32_t duration ;
    if (mRunning) {
      duration = (uint32_t) (::clock () - mStart) ;
    }else{
      duration = (uint32_t) (mEnd - mStart) ;
    }
    duration /= CLOCKS_PER_SEC / 1000 ;
  #endif
  return duration ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Timer::timeString (void) const {
  const uint32_t d = msFromStart () ;
  const uint32_t ms = d % 1000 ;
  const uint32_t secondes = (d / 1000) % 60 ; // (uint32_t) ((((uint32_t) duration.tv_sec) % 60) & UINT32_MAX) ;
  const uint32_t minutes  = d / 60000 ; // (uint32_t) ((((uint32_t) duration.tv_sec) / 60) & UINT32_MAX) ;
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

//---------------------------------------------------------------------------------------------------------------------*

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const C_Timer & inTimer) {
  #ifdef LIBPM_USES_TIMEVAL_STRUCT
    timeval duration ;
    if (inTimer.mRunning) {
      timeval now ;
      gettimeofday (& now, NULL) ;
      timersub (& now, & inTimer.mStart, & duration) ;
    }else{
      timersub (& inTimer.mEnd, & inTimer.mStart, & duration) ;
    }
    const uint32_t cs = (uint32_t) (duration.tv_usec / 10000) ;
    const uint32_t secondes = (uint32_t) ((((uint32_t) duration.tv_sec) % 60) & UINT32_MAX) ;
    const uint32_t minutes  = (uint32_t) ((((uint32_t) duration.tv_sec) / 60) & UINT32_MAX) ;
  #else
    uint32_t duration ;
    if (inTimer.mRunning) {
      duration = (uint32_t) (::clock () - inTimer.mStart) ;
    }else{
      duration = (uint32_t) (inTimer.mEnd - inTimer.mStart) ;
    }
    duration /= CLOCKS_PER_SEC / 100 ;
    const uint32_t cs = (uint32_t) (duration % 100) ;
    const uint32_t secondes = (uint32_t) ((duration / 100) % 60) ;
    const uint32_t minutes = (uint32_t) (duration / 6000) ;
  #endif
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

//---------------------------------------------------------------------------------------------------------------------*

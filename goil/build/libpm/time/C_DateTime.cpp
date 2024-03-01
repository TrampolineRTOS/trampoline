//----------------------------------------------------------------------------------------------------------------------
//
//  Class for date handling.                                                                     
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1999, ..., 2009 Pierre Molinaro.
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

#include "time/C_DateTime.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

#include <sys/stat.h>

//----------------------------------------------------------------------------------------------------------------------

C_DateTime::C_DateTime (void) :
mDate (std::chrono::system_clock::now ()) {
}

//----------------------------------------------------------------------------------------------------------------------

C_DateTime::C_DateTime (const time_t inTimeInSeconds) :
mDate (std::chrono::system_clock::from_time_t (inTimeInSeconds)) {
}

//----------------------------------------------------------------------------------------------------------------------

C_DateTime::~C_DateTime (void) {
}

//----------------------------------------------------------------------------------------------------------------------

const char * C_DateTime::getMonthName (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux, Cygwin
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  switch (time.tm_mon) {
  case  0 : return "january" ;
  case  1 : return "february" ;
  case  2 : return "march" ;
  case  3 : return "april" ;
  case  4 : return "may" ;
  case  5 : return "june" ;
  case  6 : return "july" ;
  case  7 : return "august" ;
  case  8 : return "september" ;
  case  9 : return "october" ;
  case 10 : return "november" ;
  case 11 : return "december" ;
  }
  return (const char *) nullptr ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * C_DateTime::getDayName (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  switch (time.tm_wday) {
  case  0 : return "sunday" ;
  case  1 : return "monday" ;
  case  2 : return "tuesday" ;
  case  3 : return "wednesday" ;
  case  4 : return "thursday" ;
  case  5 : return "friday" ;
  case  6 : return "saturday" ;
  }
  return (const char *) nullptr ;
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getYearCount (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return 1900 + time.tm_year ; // (1900, ...)
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getMonthCount (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return 1 + time.tm_mon ; // (1, 12)
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getDayOfMonth (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_mday ; // (1, 31)
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getHourOfDay (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_hour ; // (0, 23)
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getMinuteOfHour (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_min ; // (0, 59)
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getSecondOfMinute (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_sec ; // (0, 59)
}

//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::getDayOfWeek (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_wday ; // 0 = dimanche
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator == (const C_DateTime & inDate) const {
  return mDate == inDate.mDate ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator != (const C_DateTime & inDate) const {
  return mDate != inDate.mDate ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator > (const C_DateTime & inDate) const {
  return mDate > inDate.mDate ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator < (const C_DateTime & inDate) const {
  return mDate < inDate.mDate ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator >= (const C_DateTime & inDate) const {
  return mDate >= inDate.mDate ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator <= (const C_DateTime & inDate) const {
  return mDate <= inDate.mDate ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_OutputStream & operator << (AC_OutputStream & inStream,
                                const C_DateTime & inDate) {
  const int32_t dayOfMonth = inDate.getDayOfMonth () ;
  inStream << inDate.getMonthName ()
           << " "
           << cStringWithSigned (dayOfMonth) ;
  switch (dayOfMonth) {
  case 1 :
    inStream << "st" ;
    break ;
  case 2 :
    inStream << "nd" ;
    break ;
  case 3 :
    inStream << "rd" ;
    break ;
  default :
    inStream << "th" ;
    break ;
  }
  inStream << ", "
           << cStringWithSigned (inDate.getYearCount ())
           << ", at "
           << cStringWithSigned (inDate.getHourOfDay ()) << "h"
           << cStringWithSigned (inDate.getMinuteOfHour ()) << "\'"
           << cStringWithSigned (inDate.getSecondOfMinute ()) << "\"" ;
  return inStream ;
}

//----------------------------------------------------------------------------------------------------------------------

static time_t gCurrentToolModificationTime ;

//----------------------------------------------------------------------------------------------------------------------

void C_DateTime::enterCurrentToolModificationTime (const char * inMainRoutineFirstArgument) {
  struct stat fileProperties ;
  const int err = ::stat (inMainRoutineFirstArgument, & fileProperties) ;
  if ((err == 0) && ((fileProperties.st_mode & S_IFREG) != 0)) {
    gCurrentToolModificationTime = fileProperties.st_mtime ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

C_DateTime C_DateTime::currentToolModificationTime (void) {
  return C_DateTime (gCurrentToolModificationTime) ;
}

//----------------------------------------------------------------------------------------------------------------------

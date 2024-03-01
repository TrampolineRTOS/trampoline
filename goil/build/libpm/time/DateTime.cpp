//--------------------------------------------------------------------------------------------------
//
//  Class for date handling.                                                                     
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

#include "DateTime.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

#include <sys/stat.h>

//--------------------------------------------------------------------------------------------------

DateTime::DateTime (void) :
mDate (std::chrono::system_clock::now ()) {
}

//--------------------------------------------------------------------------------------------------

DateTime::DateTime (const time_t inTimeInSeconds) :
mDate (std::chrono::system_clock::from_time_t (inTimeInSeconds)) {
}

//--------------------------------------------------------------------------------------------------

DateTime::~DateTime (void) {
}

//--------------------------------------------------------------------------------------------------

const char * DateTime::getMonthName (void) const {
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
  return nullptr ;
}

//--------------------------------------------------------------------------------------------------

const char * DateTime::getDayName (void) const {
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
  return nullptr ;
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getYearCount (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return 1900 + time.tm_year ; // (1900, ...)
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getMonthCount (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return 1 + time.tm_mon ; // (1, 12)
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getDayOfMonth (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_mday ; // (1, 31)
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getHourOfDay (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_hour ; // (0, 23)
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getMinuteOfHour (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_min ; // (0, 59)
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getSecondOfMinute (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_sec ; // (0, 59)
}

//--------------------------------------------------------------------------------------------------

int32_t DateTime::getDayOfWeek (void) const {
  const time_t tt = std::chrono::system_clock::to_time_t (mDate) ;
  struct tm time ;
  #if COMPILE_FOR_WINDOWS == 0
   ::localtime_r (&tt, &time) ; // Mac, Linux
  #else
   ::localtime_s (&time, &tt) ; // Windows
  #endif
  return time.tm_wday ; // 0 = dimanche
}

//--------------------------------------------------------------------------------------------------

bool DateTime::operator == (const DateTime & inDate) const {
  return mDate == inDate.mDate ;
}

//--------------------------------------------------------------------------------------------------

bool DateTime::operator != (const DateTime & inDate) const {
  return mDate != inDate.mDate ;
}

//--------------------------------------------------------------------------------------------------

bool DateTime::operator > (const DateTime & inDate) const {
  return mDate > inDate.mDate ;
}

//--------------------------------------------------------------------------------------------------

bool DateTime::operator < (const DateTime & inDate) const {
  return mDate < inDate.mDate ;
}

//--------------------------------------------------------------------------------------------------

bool DateTime::operator >= (const DateTime & inDate) const {
  return mDate >= inDate.mDate ;
}

//--------------------------------------------------------------------------------------------------

bool DateTime::operator <= (const DateTime & inDate) const {
  return mDate <= inDate.mDate ;
}

//--------------------------------------------------------------------------------------------------

String DateTime::string (void) const {
  String result ;
  const int32_t dayOfMonth = getDayOfMonth () ;
  result.appendCString (getMonthName ()) ;
  result.appendCString (" ") ;
  result.appendSigned (dayOfMonth) ;
  switch (dayOfMonth) {
  case 1 :
    result.appendCString ("st") ;
    break ;
  case 2 :
    result.appendCString ("nd") ;
    break ;
  case 3 :
    result.appendCString ("rd") ;
    break ;
  default :
    result.appendCString ("th") ;
    break ;
  }
  result.appendCString (", ") ;
  result.appendSigned (getYearCount ()) ;
  result.appendCString (", at ") ;
  result.appendSigned (getHourOfDay ()) ;
  result.appendCString ("h") ;
  result.appendSigned (getMinuteOfHour ()) ;
  result.appendCString ("\'") ;
  result.appendSigned (getSecondOfMinute ()) ;
  result.appendCString ("\"") ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static time_t gCurrentToolModificationTime ;

//--------------------------------------------------------------------------------------------------

void DateTime::enterCurrentToolModificationTime (const char * inMainRoutineFirstArgument) {
  struct stat fileProperties ;
  const int err = ::stat (inMainRoutineFirstArgument, & fileProperties) ;
  if ((err == 0) && ((fileProperties.st_mode & S_IFREG) != 0)) {
    gCurrentToolModificationTime = fileProperties.st_mtime ;
  }
}

//--------------------------------------------------------------------------------------------------

DateTime DateTime::currentToolModificationTime (void) {
  return DateTime (gCurrentToolModificationTime) ;
}

//--------------------------------------------------------------------------------------------------

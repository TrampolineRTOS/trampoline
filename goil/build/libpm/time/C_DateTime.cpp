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

static struct tm gDate ;

//----------------------------------------------------------------------------------------------------------------------

static struct tm currentDate (void) {
  const time_t currentTime = ::time (nullptr) ;
  gDate = * ::localtime (& currentTime) ;
  return gDate ;
}

//----------------------------------------------------------------------------------------------------------------------

static struct tm initWithSeconds (const time_t inTimeInSeconds) {
  gDate = * ::localtime (& inTimeInSeconds) ;
  return gDate ;
}

//----------------------------------------------------------------------------------------------------------------------

C_DateTime::C_DateTime (void) :
mDate (currentDate ()) {
}

//----------------------------------------------------------------------------------------------------------------------

C_DateTime::C_DateTime (const time_t inTimeInSeconds) :
mDate (initWithSeconds (inTimeInSeconds)) {
}

//----------------------------------------------------------------------------------------------------------------------

C_DateTime::~C_DateTime (void) {
}

//----------------------------------------------------------------------------------------------------------------------

const char * C_DateTime::getMonthName (void) const {
  switch (mDate.tm_mon) {
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
  switch (mDate.tm_wday) {
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
//
//    Date comparisons                                                                           
//
//----------------------------------------------------------------------------------------------------------------------

int32_t C_DateTime::compare (const C_DateTime & inDate) const {
  int32_t result = getYearCount () - inDate.getYearCount () ;
  if (result == 0) {
    result = getMonthCount () - inDate.getMonthCount () ;
  }
  if (result == 0) {
    result = getDayOfMonth () - inDate.getDayOfMonth () ;
  }
  if (result == 0) {
    result = getHourOfDay () - inDate.getHourOfDay () ;
  }
  if (result == 0) {
    result = getMinuteOfHour () - inDate.getMinuteOfHour () ;
  }
  if (result == 0) {
    result = getSecondOfMinute () - inDate.getSecondOfMinute () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator == (const C_DateTime & inDate) const {
  return compare (inDate) == 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator != (const C_DateTime & inDate) const {
  return compare (inDate) != 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator > (const C_DateTime & inDate) const {
  return compare (inDate) > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator < (const C_DateTime & inDate) const {
  return compare (inDate) < 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator >= (const C_DateTime & inDate) const {
  return compare (inDate) >= 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_DateTime::operator <= (const C_DateTime & inDate) const {
  return compare (inDate) <= 0 ;
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

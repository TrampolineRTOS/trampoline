//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "streams/AC_OutputStream.h"

//----------------------------------------------------------------------------------------------------------------------

#include <chrono>

//----------------------------------------------------------------------------------------------------------------------

class C_DateTime final {
  private: std::chrono::time_point<std::chrono::system_clock> mDate ;

//--- Constructors et destructor
  public: C_DateTime (void) ; // Current date
  public: C_DateTime (const time_t inTimeInSeconds) ;
  public: ~C_DateTime (void) ;

//--- Get date components
  public: int32_t getYearCount (void) const ; // (1900, ...)
  public: int32_t getMonthCount (void) const ; // (1, 12)
  public: int32_t getDayOfMonth (void) const ; // (1, 31)
  public: int32_t getHourOfDay (void) const ; // (0, 23)
  public: int32_t getMinuteOfHour (void) const ; // (0, 59)
  public: int32_t getSecondOfMinute (void) const ; // (0, 59)
  public: int32_t getDayOfWeek (void) const ; // 0 = dimanche
  public: const char * getDayName (void) const ;
  public: const char * getMonthName (void) const ;

//--- Date comparisons
  public: int32_t compare (const C_DateTime & inDate) const ;
  public: bool operator == (const C_DateTime & inDate) const ;
  public: bool operator != (const C_DateTime & inDate) const ;
  public: bool operator <= (const C_DateTime & inDate) const ;
  public: bool operator >= (const C_DateTime & inDate) const ;
  public: bool operator <  (const C_DateTime & inDate) const ;
  public: bool operator >  (const C_DateTime & inDate) const ;

//--- Modification date of current tool
  public: static void enterCurrentToolModificationTime (const char * inMainRoutineFirstArgument) ;
  public: static C_DateTime currentToolModificationTime (void) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const C_DateTime & inDate) ;

//----------------------------------------------------------------------------------------------------------------------

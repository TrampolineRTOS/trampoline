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

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdint>
#include <time.h>

//----------------------------------------------------------------------------------------------------------------------

class AC_OutputStream ;
class C_String ;

//----------------------------------------------------------------------------------------------------------------------

class C_Timer final {
  private: clock_t mStart ;
  private: clock_t mEnd ;
  
  private: bool mRunning ;
  
  public: C_Timer (void) ;

  public: void stopTimer (void) ;

  public: void startTimer (void) ;

  public: uint32_t msFromStart (void) const ;

  public: C_String timeString (void) const ;
  
  public: inline bool isRunning (void) const { return mRunning ; }

  friend AC_OutputStream & operator << (AC_OutputStream & inStream,
                                        const C_Timer & inTimer) ;

} ;

//----------------------------------------------------------------------------------------------------------------------

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const C_Timer & inTimer) ;

//----------------------------------------------------------------------------------------------------------------------

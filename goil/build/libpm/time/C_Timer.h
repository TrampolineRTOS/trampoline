//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Timer class.                                                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1999, ..., 2013 Pierre Molinaro.                                                                     *
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

#ifndef CLASS_TIMER_DEFINED
#define CLASS_TIMER_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/M_machine.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if COMPILE_FOR_WINDOWS == 1
  #include <time.h>
#else
  #include <sys/time.h>
#endif

//---------------------------------------------------------------------------------------------------------------------*

class AC_OutputStream ;
class C_String ;

//---------------------------------------------------------------------------------------------------------------------*

class C_Timer {
  #if COMPILE_FOR_WINDOWS == 0
    private : timeval mStart ;
    private : timeval mEnd ;
  #else
    private : clock_t mStart ;
    private : clock_t mEnd ;
  #endif
  
  private : bool mRunning ;
  
  public : C_Timer (void) ;

  public : void stopTimer (void) ;

  public : void startTimer (void) ;

  public : uint32_t msFromStart (void) const ;

  public : C_String timeString (void) const ;
  
  public : inline bool isRunning (void) const { return mRunning ; }

  friend AC_OutputStream & operator << (AC_OutputStream & inStream,
                                        const C_Timer & inTimer) ;

} ;

//---------------------------------------------------------------------------------------------------------------------*

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const C_Timer & inTimer) ;

//---------------------------------------------------------------------------------------------------------------------*

#endif

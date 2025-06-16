//--------------------------------------------------------------------------------------------------
//
//  'C_ColoredConsole' : a class for colored console output                                      
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2023 Pierre Molinaro.
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

#include "C_ColoredConsole.h"

//--------------------------------------------------------------------------------------------------

#include <stdio.h>

//--------------------------------------------------------------------------------------------------

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  #include <windows.h>
#endif

//--------------------------------------------------------------------------------------------------

static bool gTextAttributesAreUsed = true ;

//--------------------------------------------------------------------------------------------------

void C_ColoredConsole::setUseTextAttributes (const bool inUsesTextAttributes) {
  gTextAttributesAreUsed = inUsesTextAttributes ;
}
  
//--------------------------------------------------------------------------------------------------

bool C_ColoredConsole::usesTextAttributes (void) {
  return gTextAttributesAreUsed ;
}

//--------------------------------------------------------------------------------------------------
//
// http://ascii-table.com/ansi-escape-sequences.php                                              
//
// Win32 console:                                                                                
//   http://www.adrianxw.dk/SoftwareSite/Consoles/Consoles1.html                                 
//   http://www.adrianxw.dk/SoftwareSite/Consoles/Consoles2.html                                 
//   http://www.adrianxw.dk/SoftwareSite/Consoles/Consoles3.html                                 
//   http://www.adrianxw.dk/SoftwareSite/Consoles/Consoles4.html                                 
//
//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  void C_ColoredConsole::setForeColor (const consoleForeColorEnum inForeColor) {
    if (gTextAttributesAreUsed) {
      switch (inForeColor) {
      case kBlackForeColor   : printf ("\x1B[30m") ; break ;
      case kRedForeColor     : printf ("\x1B[31m") ; break ;
      case kGreenForeColor   : printf ("\x1B[32m") ; break ;
      case kYellowForeColor  : printf ("\x1B[33m") ; break ;
      case kBlueForeColor    : printf ("\x1B[34m") ; break ;
      case kMagentaForeColor : printf ("\x1B[35m") ; break ;
      case kCyanForeColor    : printf ("\x1B[36m") ; break ;
      case kWhiteForeColor   : printf ("\x1B[37m") ; break ;
      }
    }
  }
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  void C_ColoredConsole::setForeColor (const consoleForeColorEnum /* inForeColor */) {
  }
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  void C_ColoredConsole::setBackgroundColor (const consoleBackgroundColorEnum inBackgroundColor) {
    if (gTextAttributesAreUsed) {
      switch (inBackgroundColor) {
      case kBlackBackgroundColor   : printf ("\x1B[40m") ; break ;
      case kRedBackgroundColor     : printf ("\x1B[41m") ; break ;
      case kGreenBackgroundColor   : printf ("\x1B[42m") ; break ;
      case kYellowBackgroundColor  : printf ("\x1B[43m") ; break ;
      case kBlueBackgroundColor    : printf ("\x1B[44m") ; break ;
      case kMagentaBackgroundColor : printf ("\x1B[45m") ; break ;
      case kCyanBackgroundColor    : printf ("\x1B[46m") ; break ;
      case kWhiteBackgroundColor   : printf ("\x1B[47m") ; break ;
      }
    }
  }
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  void C_ColoredConsole::setBackgroundColor (const consoleBackgroundColorEnum /* inBackgroundColor */) {
  }
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  void C_ColoredConsole::setTextAttribute (const consoleTextAttributeEnum inTextAttribute) {
    if (gTextAttributesAreUsed) {
      switch (inTextAttribute) {
      case kAllAttributesOff          : printf ("\x1B[0m") ; break ;
      case kBoldTextAttribute         : printf ("\x1B[1m") ; break ;
      case kBlinkTextAttribute        : printf ("\x1B[5m") ; break ;
      case kReverseVideoTextAttribute : printf ("\x1B[7m") ; break ;
      case kConcealedTextAttribute    : printf ("\x1B[8m") ; break ;
      }
    }
  }
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  void C_ColoredConsole::setTextAttribute (const consoleTextAttributeEnum /* inTextAttribute */) {
  }
#endif

//--------------------------------------------------------------------------------------------------

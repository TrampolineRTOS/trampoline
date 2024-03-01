//----------------------------------------------------------------------------------------------------------------------
//
//  Routine 'F_default_display_exception'.
//
//  This file is part of libpm library
//
//  Copyright (C) 1997, ..., 2008 Pierre Molinaro.
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

#include "utilities/F_DisplayException.h"
#include "streams/C_ConsoleOut.h"
#include "streams/C_ErrorOut.h"

//----------------------------------------------------------------------------------------------------------------------

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//----------------------------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  #include <windows.h>
#endif

#include <stdio.h>

//----------------------------------------------------------------------------------------------------------------------
//
//         'F_default_display_exception' for WIN 32
//
//----------------------------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  void F_default_display_exception (const ::std:: exception & inException) {
    ::MessageBox ((HWND__ *) nullptr,
                  inException.what (),
                  "C++ exception",
                  MB_OK | MB_ICONERROR) ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//         'F_default_display_exception' for UNIX
//
//----------------------------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  void F_default_display_exception (const ::std:: exception & inException) {
    co.flush () ;
    ce << "\n*** Exception: " << inException.what () << " ***\n" ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//     'F_default_display_unknown_exception' for WIN 32
//
//----------------------------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  void F_default_display_unknown_exception (void) {
    ::MessageBox ((HWND__ *) nullptr,
                  "An unknown C++ exception has been raised.",
                  "Unknown exception",
                  MB_OK | MB_ICONERROR) ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//     'F_default_display_unknown_exception' for UNIX
//
//----------------------------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  void F_default_display_unknown_exception (void) {
    ::fflush (stdout) ;
    ::fprintf (stderr, "\n*** Unknown exception ***\n") ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

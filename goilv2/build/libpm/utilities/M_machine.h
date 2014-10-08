//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Collection of macros for determining machine and compiler.                                                         *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1997, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
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

#ifndef MACHINE_MACROS_DEFINED
#define MACHINE_MACROS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------------------------------------------------*

#define __STDC_LIMIT_MACROS
#include <stdint.h>

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                  P L A T F O R M   D E T E C T I O N                                                                *
//                                                                                                                     *
// * WIN32 is defined when compiling for Microsoft Windows                                                             *
// * __APPLE__is defined, but __NEXT_RUNTIME__ is not when compiling for                                               *
//   Mac OS X Darwin (command line tools)                                                                              *
// * __APPLE__and __NEXT_RUNTIME__ are both defined when compiling for                                                 *
//   Mac OS X Cocoa (GUI applications)                                                                                 *
// * __MINGW32__ is defined when compiling by MinGW (for Windows)                                                      *
// * __linux is defined when compiling by GCC (for Linux)                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef __MINGW32__
  //--- Compile for Win32
  #define COMPILE_FOR_WIN32
  #define MACHINE_IS_DEFINED
#elif defined (WIN32)
  //--- Compile for Win32
  #define COMPILE_FOR_WIN32
  #define MACHINE_IS_DEFINED
#elif defined (__APPLE__)
  #define PRAGMA_MARK_ALLOWED
  #ifdef __NEXT_RUNTIME__
   //--- Compile for Mac OS X Cocoa
    #define MACHINE_IS_DEFINED
  #else
   //--- Compile for Mac OS X Darwin
    #define UNIX_TOOL
    #define MACHINE_IS_DEFINED
  #endif
#elif defined (__linux)
  //--- Compile for Linux
  #define UNIX_TOOL
  #define MACHINE_IS_DEFINED
#else
  #error Undefined platform
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//             M I N ,    M A X    F U N C T I O N S                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static inline uint32_t uimin32 (const uint32_t inA, const uint32_t inB) {
  return (inA < inB) ? inA : inB ;
}

//---------------------------------------------------------------------------------------------------------------------*

static inline uint32_t uimax32 (const uint32_t inA, const uint32_t inB) {
  return (inA > inB) ? inA : inB ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      U T F 3 2    T Y P E                                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  class utf32 {
    private : uint32_t mCode ;
    public : inline uint32_t value (void) const { return mCode ; }
    public : inline static utf32 construct (const uint32_t inCode) {
      utf32 code ;
      code.mCode = inCode ;
      return code ;
    }
  } ;
  #define UNICODE_VALUE(C) ((C).value ())
  #define TO_UNICODE(C) utf32::construct (C)
#else
  typedef uint32_t utf32 ;
  #define UNICODE_VALUE(C) (C)
  #define TO_UNICODE(C) (C)
#endif

//---------------------------------------------------------------------------------------------------------------------*

#endif

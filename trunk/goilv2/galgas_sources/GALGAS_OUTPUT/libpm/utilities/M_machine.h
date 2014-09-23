//-----------------------------------------------------------------------------*
//                                                                             *
//  Collection of macros for determining machine and compiler.                 *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1997, ..., 2014 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef MACHINE_MACROS_DEFINED
#define MACHINE_MACROS_DEFINED

//-----------------------------------------------------------------------------*

#include <stddef.h>

//-----------------------------------------------------------------------------*

#define __STDC_LIMIT_MACROS
#include <stdint.h>

//-----------------------------------------------------------------------------*
//                                                                             *
//                  P L A T F O R M   D E T E C T I O N                        *
//                                                                             *
// * WIN32 is defined when compiling for Microsoft Windows                     *
// * __APPLE__is defined, but __NEXT_RUNTIME__ is not when compiling for       *
//   Mac OS X Darwin (command line tools)                                      * 
// * __APPLE__and __NEXT_RUNTIME__ are both defined when compiling for         *
//   Mac OS X Cocoa (GUI applications)                                         * 
// * __MINGW32__ is defined when compiling by MinGW (for Windows)              *
// * __linux is defined when compiling by GCC (for Linux)                      *
//                                                                             *
//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*
//                                                                             *
//                  C O M P I L E R   D E T E C T I O N                        *
//                                                                             *
//-----------------------------------------------------------------------------*

//---- METROWERKS CODE WARRIOR COMPILER ? -----------------------
  #ifdef __MWERKS__
    #include <mslconfig>
//    #define M_STD_NAMESPACE _STD::
//    typedef   signed        char int8_t ;
//    typedef unsigned        char uint8_t ;
//    typedef                short int16_t ;
//    typedef unsigned       short uint16_t ;
//    typedef                  int int32_t ;
//    typedef unsigned         int uint32_t ;
//    typedef           long  long int64_t ;
//    typedef unsigned  long  long uint64_t ;
//---- GNU GCC COMPILER ? ---------------------------------------
  #elif defined (__GNUG__)
//    #define M_STD_NAMESPACE ::std::
//    typedef   signed        char int8_t ;
//    typedef unsigned        char uint8_t ;
//    typedef                short int16_t ;
//    typedef unsigned       short uint16_t ;
//    typedef                  int int32_t ;
//    typedef unsigned         int uint32_t ;
//    typedef           long  long int64_t ;
//    typedef unsigned  long  long uint64_t ;
//    typedef           __int128 PMSInt128 ;
//    typedef   __int128_t PMUInt128 ;
//---- UNKNOWN COMPILER -----------------------------------------
  #else
    #error "Unknown Compiler"
  #endif

//-----------------------------------------------------------------------------*
//                                                                             *
// D E F I N E    M I N    A N D    M A X     F O R    I N T    T Y P E S      *
//                                                                             *
//-----------------------------------------------------------------------------*

//--- Signed integer max
// #define PMSINT8_MAX       ((int8_t) 0x7F)
// #define PMSINT16_MAX      ((int16_t) 0x7FFF)
// #define INT32_MAX      ((int32_t) 0x7FFFFFFFL)
// #define INT64_MAX      ((int64_t) 0x7FFFFFFFFFFFFFFFLL)

//--- Signed integer min
// #define PMSINT8_MIN       (~PMSINT8_MAX)
// #define PMSINT16_MIN      (~PMSINT16_MAX)
// #define INT32_MIN      (~INT32_MAX)
// #define INT64_MIN      (~INT64_MAX)

//--- Unsigned integer max
// #define UINT8_MAX       ((uint8_t) 0xFFU)
// #define UINT16_MAX      ((uint16_t) 0xFFFFU)
// #define UINT32_MAX      ((uint32_t) 0xFFFFFFFFUL)
// #define UINT64_MAX      ((uint64_t) 0xFFFFFFFFFFFFFFFFULL)  

//-----------------------------------------------------------------------------*
//                                                                             *
// I N T E G E R    T Y P E S ,    3 2    O R    6 4    B I T S                *
//                                                                             *
// When building 32-bit tools, uintptr_t is a 32-bit unsigned integer,         *
// intptr_t is a 32-bit signed integer.                                        *
// When building 64-bit tools, uintptr_t is a 64-bit unsigned integer,         *
// intptr_t is a 64-bit signed integer.                                        *
//-----------------------------------------------------------------------------*

//#ifdef __LP64__
//  typedef int64_t intptr_t ;
//  typedef uint64_t uintptr_t ;
//  #define PMUINT_MAX (UINT64_MAX)
//  #define PMSINT_MIN (INT64_MIN)
//  #define PMSINT_MAX (INT64_MAX)
//#else
//  typedef int32_t intptr_t ;
//  typedef uint32_t uintptr_t ;
//  #define PMUINT_MAX (UINT32_MAX)
//  #define PMSINT_MIN (INT32_MIN)
//  #define PMSINT_MAX (INT32_MAX)
//#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//             M I N ,    M A X    F U N C T I O N S                           *
//                                                                             *
//-----------------------------------------------------------------------------*

static inline uint32_t uimin32 (const uint32_t inA, const uint32_t inB) {
  return (inA < inB) ? inA : inB ;
}

//-----------------------------------------------------------------------------*

static inline uint32_t uimax32 (const uint32_t inA, const uint32_t inB) {
  return (inA > inB) ? inA : inB ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//                      U T F 3 2    T Y P E                                   *
//                                                                             *
//-----------------------------------------------------------------------------*

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

//-----------------------------------------------------------------------------*

#endif

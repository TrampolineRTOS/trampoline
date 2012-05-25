//---------------------------------------------------------------------------*
//                                                                           *
//  Collection of macros for determining machine and compiler.               *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997, ..., 2012 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef MACHINE_MACROS_DEFINED
#define MACHINE_MACROS_DEFINED

//---------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------*
//                                                                           *
//                  P L A T F O R M   D E T E C T I O N                      *
//                                                                           *
// * WIN32 is defined when compiling for Microsoft Windows                   *
// * __APPLE__is defined, but __NEXT_RUNTIME__ is not when compiling for     *
//   Mac OS X Darwin (command line tools)                                    * 
// * __APPLE__and __NEXT_RUNTIME__ are both defined when compiling for       *
//   Mac OS X Cocoa (GUI applications)                                       * 
// * __MINGW32__ is defined when compiling by MinGW (for Windows)            *
// * __linux is defined when compiling by GCC (for Linux)                    *
//                                                                           *
//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*
//                                                                           *
//                  C O M P I L E R   D E T E C T I O N                      *
//                                                                           *
//---------------------------------------------------------------------------*

//---- METROWERKS CODE WARRIOR COMPILER ? -----------------------
  #ifdef __MWERKS__
    #include <mslconfig>
    #define M_STD_NAMESPACE _STD::
    typedef   signed        char PMSInt8 ;
    typedef unsigned        char PMUInt8 ;
    typedef                short PMSInt16 ;
    typedef unsigned       short PMUInt16 ;
    typedef                  int PMSInt32 ;
    typedef unsigned         int PMUInt32 ;
    typedef           long  long PMSInt64 ;
    typedef unsigned  long  long PMUInt64 ;
//---- GNU GCC COMPILER ? ---------------------------------------
  #elif defined (__GNUG__)
    #define M_STD_NAMESPACE ::std::
    typedef   signed        char PMSInt8 ;
    typedef unsigned        char PMUInt8 ;
    typedef                short PMSInt16 ;
    typedef unsigned       short PMUInt16 ;
    typedef                  int PMSInt32 ;
    typedef unsigned         int PMUInt32 ;
    typedef           long  long PMSInt64 ;
    typedef unsigned  long  long PMUInt64 ;
//---- UNKNOWN COMPILER -----------------------------------------
  #else
    #error "Unknown Compiler"
  #endif

//---------------------------------------------------------------------------*
//                                                                           *
// D E F I N E    M I N    A N D    M A X     F O R    I N T    T Y P E S    *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Signed integer max
#define PMSINT8_MAX       0x7F
#define PMSINT16_MAX      0x7FFF
#define PMSINT32_MAX      0x7FFFFFFFL
#define PMSINT64_MAX      0x7FFFFFFFFFFFFFFFLL

//--- Signed integer min
#define PMSINT8_MIN       (~PMSINT8_MAX)
#define PMSINT16_MIN      (~PMSINT16_MAX)
#define PMSINT32_MIN      (~PMSINT32_MAX)
#define PMSINT64_MIN      (~PMSINT64_MAX)

//--- Unsigned integer max
#define PMUINT8_MAX       0xFFU
#define PMUINT16_MAX      0xFFFFU
#define PMUINT32_MAX      0xFFFFFFFFUL
#define PMUINT64_MAX      0xFFFFFFFFFFFFFFFFULL    

//---------------------------------------------------------------------------*
//                                                                           *
// I N T E G E R    T Y P E S ,    3 2    O R    6 4    B I T S              *
//                                                                           *
// When building 32-bit tools, PMUInt is a 32-bit unsigned integer,          *
// PMSInt is a 32-bit signed integer.                                        *
// When building 64-bit tools, PMUInt is a 64-bit unsigned integer,          *
// PMSInt is a 64-bit signed integer.                                        *
//---------------------------------------------------------------------------*

#ifdef __LP64__
  typedef PMSInt64 PMSInt ;
  typedef PMUInt64 PMUInt ;
  #define PMUINT_MAX (PMUINT64_MAX)
  #define PMSINT_MIN (PMSINT64_MIN)
  #define PMSINT_MAX (PMSINT64_MAX)
#else
  typedef PMSInt32 PMSInt ;
  typedef PMUInt32 PMUInt ;
  #define PMUINT_MAX (PMUINT32_MAX)
  #define PMSINT_MIN (PMSINT32_MIN)
  #define PMSINT_MAX (PMSINT32_MAX)
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//             M I N ,    M A X    F U N C T I O N S                         *
//                                                                           *
//---------------------------------------------------------------------------*

static inline PMUInt32 uimin32 (const PMUInt32 inA, const PMUInt32 inB) {
  return (inA < inB) ? inA : inB ;
}

//---------------------------------------------------------------------------*

static inline PMUInt32 uimax32 (const PMUInt32 inA, const PMUInt32 inB) {
  return (inA > inB) ? inA : inB ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      U T F 3 2    T Y P E                                 *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  class utf32 {
    private : PMUInt32 mCode ;
    public : inline PMUInt32 value (void) const { return mCode ; }
    public : inline static utf32 construct (const PMUInt32 inCode) {
      utf32 code ;
      code.mCode = inCode ;
      return code ;
    }
  } ;
  #define UNICODE_VALUE(C) ((C).value ())
  #define TO_UNICODE(C) utf32::construct (C)
#else
  typedef PMUInt32 utf32 ;
  #define UNICODE_VALUE(C) (C)
  #define TO_UNICODE(C) (C)
#endif

//---------------------------------------------------------------------------*

#endif

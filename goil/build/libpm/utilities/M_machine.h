//--------------------------------------------------------------------------------------------------
//
//  Collection of macros for determining machine and compiler.                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1997, ..., 2023 Pierre Molinaro.
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

#pragma once

//--------------------------------------------------------------------------------------------------

#include <stddef.h>

//--------------------------------------------------------------------------------------------------

#define __STDC_LIMIT_MACROS
#include <stdint.h>

//--------------------------------------------------------------------------------------------------
//
//                  P L A T F O R M   D E T E C T I O N                                          
//
// * WIN32 is defined when compiling for Microsoft Windows                                       
// * __APPLE__is defined, but __NEXT_RUNTIME__ is not when compiling for                         
//   OS X Darwin (command line tools)                                                            
// * __APPLE__and __NEXT_RUNTIME__ are both defined when compiling for                           
//   OS X Cocoa (GUI applications)                                                               
// * __MINGW32__ is defined when compiling by MinGW (for Windows)
// * __CYGWIN__ is defined when compiling by Cygwin (for Unix on Windows, https://gist.github.com/basman/587688)
// * __linux is defined when compiling by GCC (for Linux)
//
//--------------------------------------------------------------------------------------------------

#if defined (__CYGWIN__)
  #define COMPILE_FOR_WINDOWS (0)
#elif defined (__MINGW32__)
  #define COMPILE_FOR_WINDOWS (1)
#elif defined (WIN32)
  #define COMPILE_FOR_WINDOWS (1)
#elif defined (__APPLE__)
  #define COMPILE_FOR_WINDOWS (0)
#elif defined (__linux)
  #define COMPILE_FOR_WINDOWS (0)
#elif defined (__unix__)
  #define COMPILE_FOR_WINDOWS (0)
#else
  #error Undefined platform
#endif

//--------------------------------------------------------------------------------------------------
//
//                      U T F 3 2    T Y P E                                                     
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  class utf32 final {
    private: uint32_t mCode ;
    public: inline uint32_t value (void) const { return mCode ; }
    public: inline utf32 (void) :
    mCode (0) {
    }
    public: inline utf32 (const uint32_t & inCode) :
    mCode (inCode) {
    }
    public: inline utf32 (const utf32 & inOperand) :
    mCode (inOperand.mCode) {
    }
    public: inline utf32 & operator = (const utf32 & inOperand) {
      mCode = inOperand.mCode ;
      return *this ;
    }
    public: inline bool operator == (const utf32 inOperand) const {
      return mCode == inOperand.mCode ;
    }
  } ;
  #define UNICODE_VALUE(C) ((C).value ())
  #define TO_UNICODE(C) utf32 (C)
#else
  typedef uint32_t utf32 ;
  #define UNICODE_VALUE(C) (C)
  #define TO_UNICODE(C) (C)
#endif

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//  'LocationInSource'                                                                         
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1996, ..., 2023 Pierre Molinaro.
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

#include "M_machine.h"
#include "macroAssert.h"
#include "SourceTextInString.h"

//--------------------------------------------------------------------------------------------------

class String ;

//--------------------------------------------------------------------------------------------------
//
//                 Class for referencing a location in source text                               
//
//--------------------------------------------------------------------------------------------------

class LocationInSource final {
  private: int32_t mIndex ;
  private: int32_t mLineNumber ;
  private: int32_t mColumnNumber ;
  private: SourceTextInString mSourceText ;

  public: LocationInSource (void) ;

  public: void gotoNextLocation (void) ;

  public: void goForward (const uint32_t inCount) ;

  public: void resetLocation (void) ;

  public: void resetWithSourceText (const SourceTextInString & inSourceText) ;

  public: inline int32_t index (void) const { return mIndex ; }

  public: int32_t lineNumber (void) const ;

  public: int32_t columnNumber (void) const ;

  public: String sourceFilePath (void) const ;
} ;

//--------------------------------------------------------------------------------------------------

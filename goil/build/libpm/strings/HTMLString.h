//--------------------------------------------------------------------------------------------------
//
//  HTMLString : generating HTML text                                                          
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2014, ..., 2024 Pierre Molinaro.
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

#include "String-class.h"

//--------------------------------------------------------------------------------------------------
//
//      Fully dynamic character string : String                                                
//
//--------------------------------------------------------------------------------------------------

class HTMLString : public String {
//--- Constructors
  public: HTMLString (void) ;

//--- Output data, without HTML formatting
  public: void addRawData (const char * inCString) ;

//--- General stream methods
  protected: virtual void handleAppendUTF8Array (const char * inCharArray,
                                                 const int32_t inArrayCount) ;

  protected: virtual void handleAppendCharacter (const utf32 inCharacter) ;

//--- Method for writing a HTML table
  public: void appendTitleComment (const String & inCommentString,
                                   const char * inTableStyleClass) ;

//--- Write start code
  public: void writeStartCode (const String & inWindowTitle,
                               const String & inCSSFileName,
                               const String & inCSSContents) ;

//--- Write end code
  public: void writeEndCode (void) ;

//--- Private attributes
  private: typedef String super ;
} ;

//--------------------------------------------------------------------------------------------------

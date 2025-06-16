//--------------------------------------------------------------------------------------------------
//
//  Generic String list Command Line Interface Option                                            
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2014, ..., 2023 Pierre Molinaro.
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

#include "C_CommandLineOption.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

class C_StringListCommandLineOption final : public C_CommandLineOption {
//--- Constructor
  public: C_StringListCommandLineOption (const char * inDomainName,
                                         const char * inIdentifier,
                                         const char inChar,
                                         const char * inString,
                                         const char * inComment) ;
//--- No Copy
  private: C_StringListCommandLineOption (const C_StringListCommandLineOption &) = delete ;
  private: C_StringListCommandLineOption & operator = (const C_StringListCommandLineOption &) = delete ;

//--- Attributes
  private: C_StringListCommandLineOption * mNext ;
  public: TC_Array <String> mValue ;
  public: inline TC_Array <String> readProperty_value (void) const { return mValue ; }

//--- Static methods
  public: static void setStringListOptionForCommandChar (const String & inCommandCommandLineOptionString,
                                                         bool & outFound,
                                                         bool & outCommandLineOptionStringIsValid) ;

  public: static void setStringListOptionForCommandString (const String & inCommandCommandLineOptionString,
                                                           bool & outFound,
                                                           bool & outCommandLineOptionStringIsValid)  ;
  public: static void printUsageOfStringOptions (void) ;
  public: static void printStringOptions (void) ;

  public: static void releaseStrings (void) ; // Called at the end of main routine

//--- Option introspection
  public: static void getStringOptionNameList (TC_UniqueArray <String> & outArray) ;

  public: static utf32 getStringOptionInvocationLetter (const String & inDomainName,
                                                       const String & inIdentifier) ;

  public: static String getStringOptionInvocationString (const String & inDomainName,
                                                          const String & inIdentifier) ;

  public: static String getStringOptionCommentString (const String & inDomainName,
                                                       const String & inIdentifier) ;
} ;

//--------------------------------------------------------------------------------------------------

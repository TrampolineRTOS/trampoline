//--------------------------------------------------------------------------------------------------
//
//  Generic Boolean Command Line Interface Option                                                
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2023 Pierre Molinaro.
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
#include "M_machine.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

class C_BoolCommandLineOption final : public C_CommandLineOption {
//--- Constructor
  public: C_BoolCommandLineOption (const String & inDomainName,
                                   const String & inIdentifier,
                                   const char inChar,
                                   const String & inString,
                                   const String & inComment,
                                   const bool inVisibleInGalgas = true) ;

//--- No Copy
  private: C_BoolCommandLineOption (const C_BoolCommandLineOption &) = delete ;
  private: C_BoolCommandLineOption & operator = (const C_BoolCommandLineOption &) = delete ;

//--- Attributes
  private: C_BoolCommandLineOption * mNext ;
  public: bool mValue ;
  public: inline bool readProperty_value (void) const { return mValue ; }
  public: const bool mVisibleInGalgas ;

//--- Static methods
  public: static void setBoolOptionForCommandChar (const utf32 inCommandChar,
                                                   bool & outFound) ;

  public: static void setBoolOptionForCommandString (const String & inCommandString,
                                                     bool & outFound,
                                                     bool & outCocoaOutput) ;
  public: static void printUsageOfBoolOptions (void) ;
  public: static void printBoolOptions (void) ;

//--- Option introspection
  public: static void getBoolOptionNameList (TC_UniqueArray <String> & outArray) ;

  public: static utf32 getBoolOptionInvocationLetter (const String & inDomainName,
                                                      const String & inIdentifier) ;

  public: static String getBoolOptionInvocationString (const String & inDomainName,
                                                       const String & inIdentifier) ;

  public: static String getBoolOptionCommentString (const String & inDomainName,
                                                    const String & inIdentifier) ;

  public: static bool getBoolOptionValue (const String & inDomainName,
                                          const String & inIdentifier) ;

  public: static void setBoolOptionValue (const String & inDomainName,
                                          const String & inIdentifier,
                                          const bool inValue) ;
} ;

//--------------------------------------------------------------------------------------------------

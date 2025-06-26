//--------------------------------------------------------------------------------------------------
//
//  Generic Unsigned Command Line Interface Option                                               
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2024 Pierre Molinaro.
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

class C_UIntCommandLineOption final : public C_CommandLineOption {
//--- Constructor
  public: C_UIntCommandLineOption (const char * inDomainName,
                                   const char * inIdentifier,
                                   const char inChar,
                                   const char * inString,
                                   const char * inComment,
                                   const uint32_t inDefaultValue) ;
//--- No Copy
  private: C_UIntCommandLineOption (const C_UIntCommandLineOption &) ;
  private: C_UIntCommandLineOption & operator = (const C_UIntCommandLineOption &) ;

//--- Attributes
  private: C_UIntCommandLineOption * mNext ;
  public: uint32_t mValue ;
  public: inline uint32_t readProperty_value (void) const { return mValue ; }
  public: const uint32_t mDefaultValue ;

//--- Static methods
  public: static void setUIntOptionForCommandChar (const String & inCommandCommandLineOptionString,
                                                   bool & outFound,
                                                   bool & outCommandLineOptionStringIsValid) ;
  public: static void setUIntOptionForCommandString (const String & inCommandCommandLineOptionString,
                                                     bool & outFound,
                                                     bool & outCommandLineOptionStringIsValid)  ;
  public: static void printUsageOfUIntOptions (void) ;
  public: static void printUIntOptions (void) ;

//--- Option introspection
  public: static void getUIntOptionNameList (TC_UniqueArray <String> & outArray) ;

  public: static utf32 getUIntOptionInvocationLetter (const String & inDomainName,
                                                       const String & inIdentifier) ;

  public: static String getUIntOptionInvocationString (const String & inDomainName,
                                                          const String & inIdentifier) ;

  public: static String getUIntOptionCommentString (const String & inDomainName,
                                                       const String & inIdentifier) ;

  public: static uint32_t getUIntOptionValue (const String & inDomainName,
                                               const String & inIdentifier) ;

  public: static void setUIntOptionValue (const String & inDomainName,
                                           const String & inIdentifier,
                                           const uint32_t inValue) ;
} ;

//--------------------------------------------------------------------------------------------------

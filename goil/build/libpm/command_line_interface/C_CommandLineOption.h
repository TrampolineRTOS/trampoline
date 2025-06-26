//--------------------------------------------------------------------------------------------------
//
//  Generic Command Line Interface Option                                                        
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

#include "M_SourceLocation.h"
#include "String-class.h"

//--------------------------------------------------------------------------------------------------

class C_CommandLineOption {
//--- Constructor
  public: C_CommandLineOption (const char * inDomainName,
                               const char * inIdentifier,
                               const char inChar,
                               const char * inString,
                               const char * inComment) ;

//--- Virtual destructor
  public: virtual ~ C_CommandLineOption (void) ;

//--- No Copy
  private: C_CommandLineOption (const C_CommandLineOption &) = delete ;
  private: C_CommandLineOption & operator = (const C_CommandLineOption &) = delete ;

//--- Properties
  public: const char * mDomainName ;
  public: const char * mIdentifier ;
  public: const char mCommandChar ;
  public: const char * mCommandString ;
  public: const char * mComment ;

//--- Accessing option parameters from GALGAS
  public: inline char readProperty_char (void) const { return mCommandChar ; }
  public: inline String readProperty_string (void) const { return mCommandString ; }
  public: inline String readProperty_comment (void) const { return mComment ; }
} ;

//--------------------------------------------------------------------------------------------------

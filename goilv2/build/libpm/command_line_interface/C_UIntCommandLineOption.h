//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Generic Unsigned Command Line Interface Option                                                                     *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef UINT_COMMAND_LINE_OPTION_CLASS_DEFINED
#define UINT_COMMAND_LINE_OPTION_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "C_CommandLineOption.h"
#include "utilities/M_machine.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_UIntCommandLineOption : public C_CommandLineOption {
//--- Constructor
  public : C_UIntCommandLineOption (const char * inDomainName,
                                    const char * inIdentifier,
                                    const char inChar,
                                    const char * inString,
                                    const char * inComment,
                                    const uint32_t inDefaultValue) ;
//--- No Copy
  private : C_UIntCommandLineOption (const C_UIntCommandLineOption &) ;
  private : C_UIntCommandLineOption & operator = (const C_UIntCommandLineOption &) ;

//--- Attributes
  private : C_UIntCommandLineOption * mNext ;
  public : uint32_t mValue ;
  public : inline uint32_t reader_value (void) const { return mValue ; }
  public : const uint32_t mDefaultValue ;

//--- Static methods
  public : static void setUIntOptionForCommandChar (const char * inCommandCommandLineOptionString,
                                                    bool & outFound,
                                                    bool & outCommandLineOptionStringIsValid) ;
  public : static void setUIntOptionForCommandString (const char * inCommandCommandLineOptionString,
                                                      bool & outFound,
                                                      bool & outCommandLineOptionStringIsValid)  ;
  public : static void printUsageOfUIntOptions (void) ;
  public : static void printUIntOptions (const uint32_t inDisplayLength) ;

//--- Option introspection
  public : static void getUIntOptionNameList (TC_UniqueArray <C_String> & outArray) ;

  public : static utf32 getUIntOptionInvocationLetter (const C_String & inDomainName,
                                                       const C_String & inIdentifier) ;

  public : static C_String getUIntOptionInvocationString (const C_String & inDomainName,
                                                          const C_String & inIdentifier) ;

  public : static C_String getUIntOptionCommentString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif

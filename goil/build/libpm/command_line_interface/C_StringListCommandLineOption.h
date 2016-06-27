//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  Generic String list Command Line Interface Option                                                                  *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2014, ..., 2014 Pierre Molinaro.                                                                     *
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
//----------------------------------------------------------------------------------------------------------------------

#ifndef STRING_LIST_COMMAND_LINE_OPTION_CLASS_DEFINED
#define STRING_LIST_COMMAND_LINE_OPTION_CLASS_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include "C_CommandLineOption.h"
#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

class C_StringListCommandLineOption : public C_CommandLineOption {
//--- Constructor
  public : C_StringListCommandLineOption (const char * inDomainName,
                                          const char * inIdentifier,
                                          const char inChar,
                                          const char * inString,
                                          const char * inComment) ;
//--- No Copy
  private : C_StringListCommandLineOption (const C_StringListCommandLineOption &) ;
  private : C_StringListCommandLineOption & operator = (const C_StringListCommandLineOption &) ;

//--- Attributes
  private : C_StringListCommandLineOption * mNext ;
  public : TC_Array <C_String> mValue ;
  public : inline TC_Array <C_String> getter_value (void) const { return mValue ; }

//--- Static methods
  public : static void setStringListOptionForCommandChar (const char * inCommandCommandLineOptionString,
                                                          bool & outFound,
                                                          bool & outCommandLineOptionStringIsValid) ;
  public : static void setStringListOptionForCommandString (const char * inCommandCommandLineOptionString,
                                                            bool & outFound,
                                                            bool & outCommandLineOptionStringIsValid)  ;
  public : static void printUsageOfStringOptions (void) ;
  public : static void printStringOptions (const uint32_t inDisplayLength) ;

  public : static void releaseStrings (void) ; // Called at the end of main routine

//--- Option introspection
  public : static void getStringOptionNameList (TC_UniqueArray <C_String> & outArray) ;

  public : static utf32 getStringOptionInvocationLetter (const C_String & inDomainName,
                                                       const C_String & inIdentifier) ;

  public : static C_String getStringOptionInvocationString (const C_String & inDomainName,
                                                          const C_String & inIdentifier) ;

  public : static C_String getStringOptionCommentString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#endif

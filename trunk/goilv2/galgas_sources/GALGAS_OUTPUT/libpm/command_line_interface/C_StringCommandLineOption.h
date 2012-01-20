//---------------------------------------------------------------------------*
//                                                                           *
//  Generic String Command Line Interface Option                             *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                           *
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

#ifndef STRING_COMMAND_LINE_OPTION_CLASS_DEFINED
#define STRING_COMMAND_LINE_OPTION_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "command_line_interface/C_CommandLineOption.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

class C_StringCommandLineOption : public C_CommandLineOption {
//--- Constructor
  public : C_StringCommandLineOption (const char * inDomainName,
                                      const char * inIdentifier,
                                      const char inChar,
                                      const char * inString,
                                      const char * inComment,
                                      const char * inDefaultValue) ;
//--- No Copy
  private : C_StringCommandLineOption (const C_StringCommandLineOption &) ;
  private : C_StringCommandLineOption & operator = (const C_StringCommandLineOption &) ;

//--- Attributes
  private : C_StringCommandLineOption * mNext ;
  public : C_String mValue ;
  public : inline C_String reader_value (void) const { return mValue ; }
  public : const char * mDefaultValue ;

//--- Static methods
  public : static void setStringOptionForCommandChar (const char * inCommandCommandLineOptionString,
                                                      bool & outFound,
                                                      bool & outCommandLineOptionStringIsValid) ;
  public : static void setStringOptionForCommandString (const char * inCommandCommandLineOptionString,
                                                        bool & outFound,
                                                        bool & outCommandLineOptionStringIsValid)  ;
  public : static void printUsageOfStringOptions (void) ;
  public : static void printStringOptions (const PMUInt32 inDisplayLength) ;

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

//---------------------------------------------------------------------------*

#endif

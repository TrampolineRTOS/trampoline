//-----------------------------------------------------------------------------*
//                                                                             *
//  Generic Boolean Command Line Interface Option                              *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef BOOL_COMMAND_LINE_OPTION_CLASS_DEFINED
#define BOOL_COMMAND_LINE_OPTION_CLASS_DEFINED

//-----------------------------------------------------------------------------*

#include "C_CommandLineOption.h"
#include "utilities/M_machine.h"
#include "strings/C_String.h"

//-----------------------------------------------------------------------------*

class C_BoolCommandLineOption : public C_CommandLineOption {
//--- Constructor
  public : C_BoolCommandLineOption (const char * inDomainName,
                                    const char * inIdentifier,
                                    const char inChar,
                                    const char * inString,
                                    const char * inComment) ;

//--- No Copy
  private : C_BoolCommandLineOption (const C_BoolCommandLineOption &) ;
  private : C_BoolCommandLineOption & operator = (const C_BoolCommandLineOption &) ;

//--- Attributes
  private : C_BoolCommandLineOption * mNext ;
  public : bool mValue ;
  public : inline bool reader_value (void) const { return mValue ; }

//--- Static methods
  public : static void setBoolOptionForCommandChar (const char inCommandChar,
                                                    bool & outFound) ;
  public : static void setBoolOptionForCommandString (const char * inCommandString,
                                                      bool & outFound,
                                                      bool & outCocoaOutput) ;
  public : static void printUsageOfBoolOptions (void) ;
  public : static void printBoolOptions (const uint32_t inDisplayLength) ;

//--- Option introspection
  public : static void getBoolOptionNameList (TC_UniqueArray <C_String> & outArray) ;

  public : static utf32 getBoolOptionInvocationLetter (const C_String & inDomainName,
                                                       const C_String & inIdentifier) ;

  public : static C_String getBoolOptionInvocationString (const C_String & inDomainName,
                                                          const C_String & inIdentifier) ;

  public : static C_String getBoolOptionCommentString (const C_String & inDomainName,
                                                       const C_String & inIdentifier) ;
} ;

//-----------------------------------------------------------------------------*

#endif

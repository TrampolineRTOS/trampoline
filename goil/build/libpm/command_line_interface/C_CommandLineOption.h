//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  Generic Command Line Interface Option                                                                              *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2017 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "utilities/M_SourceLocation.h"
#include "strings/C_String.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class C_CommandLineOption {
//--- Constructor
  public : C_CommandLineOption (const char * inDomainName,
                                const char * inIdentifier,
                                const char inChar,
                                const char * inString,
                                const char * inComment) ;

//--- Virtual destructor
  public : virtual ~ C_CommandLineOption (void) ;

//--- No Copy
  private : C_CommandLineOption (const C_CommandLineOption &) ;
  private : C_CommandLineOption & operator = (const C_CommandLineOption &) ;

//--- Attributes
  public : const char * const mDomainName ;
  public : const char * const mIdentifier ;
  public : const char mCommandChar ;
  public : const char * const mCommandString ;
  public : const char * const mComment ;

//--- Accessing option parameters from GALGAS
  public : inline char getter_char (void) const { return mCommandChar ; }
  public : inline C_String getter_string (void) const { return mCommandString ; }
  public : inline C_String getter_comment (void) const { return mComment ; }
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

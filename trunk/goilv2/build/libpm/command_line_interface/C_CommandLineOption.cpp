//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Generic Command Line Interface Option                                      *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include <string.h>
#include <stdio.h>

//---------------------------------------------------------------------------------------------------------------------*

#include "C_CommandLineOption.h"

//---------------------------------------------------------------------------------------------------------------------*

C_CommandLineOption::C_CommandLineOption (const char * inDomainName,
                                          const char * inIdentifier,
                                          const char inChar,
                                          const char * inString,
                                          const char * inComment) :
mDomainName (inDomainName),
mIdentifier (inIdentifier),
mCommandChar (inChar),
mCommandString (inString),
mComment (inComment) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_CommandLineOption::~C_CommandLineOption (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

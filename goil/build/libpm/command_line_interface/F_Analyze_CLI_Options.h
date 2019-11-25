//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  Routine 'F_Analyze_CLI_Options' : a way for automatic command                                                      *
//  line options analysis for MacOS, Win32 and Unix.                                                                   *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2001, ..., 2015 Pierre Molinaro.                                                                     *
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

#include "strings/C_String.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//     F_Analyze_CLI_Options                                                                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void F_Analyze_CLI_Options (const int argv,
                            const char * argc [],
                            TC_UniqueArray <C_String> & outSourceFileArray,
                            const char * inExtensions [],
                            const char * inHelpMessages [],
                            void print_tool_help_message (void)) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * projectVersionString (void) ;

const char * galgasVersionString (void) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t commandLineArgumentCount (void) ;

C_String commandLineArgumentAtIndex (const uint32_t inIndex) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cocoaOutput (void) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

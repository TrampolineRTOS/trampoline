//---------------------------------------------------------------------------*
//                                                                           *
//  Generic Command Line Interface Options                                   *
//   --help : Display help information                                       *
//   --version : Display software current version                            *
//   --no-color: Do not issue colored messages                               *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, ..., 2011 Pierre Molinaro.                           *
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

#ifndef GENERIC_CLI_OPTIONS_DEFINED
#define GENERIC_CLI_OPTIONS_DEFINED

//---------------------------------------------------------------------------*

#include "command_line_interface/C_BoolCommandLineOption.h"

//---------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_display_5F_help ;

//---------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_display_5F_version ;

//---------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_xml ;

//---------------------------------------------------------------------------*

#ifdef SIOUX_IS_IMPLEMENTED
  extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_options_asktosaveonclose ;
#endif

//---------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_nodialog ;
#endif

//---------------------------------------------------------------------------*

#ifdef __LP64__
  extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_enable_5F_allocation_5F_debugging ;
#endif

//---------------------------------------------------------------------------*

#ifndef COMPILE_FOR_WIN32
  extern C_BoolCommandLineOption gOption_generic_5F_cli_5F_options_no_5F_color ;
#endif

//---------------------------------------------------------------------------*

#endif

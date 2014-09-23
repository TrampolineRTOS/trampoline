//-----------------------------------------------------------------------------*
//                                                                             *
//  GALGAS Command Line Interface Options                                      *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2006, ..., 2011 Pierre Molinaro.                             *
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

#ifndef GALGAS_CLI_OPTIONS_DEFINED
#define GALGAS_CLI_OPTIONS_DEFINED

//-----------------------------------------------------------------------------*

#include "command_line_interface/C_BoolCommandLineOption.h"
#include "command_line_interface/C_UIntCommandLineOption.h"
#include "command_line_interface/C_StringCommandLineOption.h"

//-----------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_trace ;

//-----------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_outputConcreteSyntaxTree ;

//-----------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_verbose_5F_output ;

//-----------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_log_5F_file_5F_read ;

//-----------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_do_5F_not_5F_generate_5F_any_5F_file ;

//-----------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error ;

//-----------------------------------------------------------------------------*

extern C_UIntCommandLineOption gOption_galgas_5F_builtin_5F_options_max_5F_errors ;

//-----------------------------------------------------------------------------*

extern C_UIntCommandLineOption gOption_galgas_5F_builtin_5F_options_max_5F_warnings ;

//-----------------------------------------------------------------------------*

extern C_StringCommandLineOption gOption_generic_5F_cli_5F_options_mode ;

//-----------------------------------------------------------------------------*

void setExecutionMode (C_String & outErrorMessage) ;

bool executionModeIsNormal (void) ;

bool executionModeIsLexicalAnalysisOnly (void) ;

bool executionModeIsSyntaxAnalysisOnly (void) ;

bool executionModeIsIndexing (void) ;

uint32_t contextHelpStartLocation (void) ;

uint32_t contextHelpEndLocation (void) ;

void setCurrentCompiledFilePath (const C_String & inPath) ;

bool isCurrentCompiledFilePath (const C_String & inPath) ;

//-----------------------------------------------------------------------------*

#endif

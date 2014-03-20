//-----------------------------------------------------------------------------*
//                                                                             *
//  Built-in GALGAS Command Line Interface Options                           *
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

#include <string.h>

//-----------------------------------------------------------------------------*

#include "galgas2/C_galgas_CLI_Options.h"
#include "streams/C_TCPSocketOut.h"
#include "utilities/C_PrologueEpilogue.h"

//-----------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_outputConcreteSyntaxTree ("galgas_builtin_options",
                                         "outputConcreteSyntaxTree",
                                         0,
                                         "output-concrete-syntax-tree",
                                         "Generate the concrete syntax tree, in .dot format (suitable for Graphviz)") ;

//-----------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_trace ("galgas_builtin_options",
                                         "trace",
                                         0,
                                         "trace",
                                         "Outputs a trace file") ;

//-----------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_verbose_5F_output ("galgas_builtin_options",
                                                    "verbose_output",
                                                    'v',
                                                    "verbose",
                                                    "Verbose Output") ;

//-----------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_log_5F_file_5F_read ("galgas_cli_options",
                                                      "log_file_read",
                                                      '\0',
                                                      "log-file-read",
                                                      "Log every file read") ;

//-----------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_do_5F_not_5F_generate_5F_any_5F_file ("galgas_cli_options",
                                                                       "do_not_generate_any_file",
                                                                       '\0',
                                                                       "no-file-generation",
                                                                       "Do not generate any file") ;

//-----------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error ("galgas_cli_options",
                                                                   "treat_warnings_as_error",
                                                                   '\0',
                                                                   "Werror",
                                                                   "Treat warnings as errors") ;

//-----------------------------------------------------------------------------*

C_UIntCommandLineOption
gOption_galgas_5F_builtin_5F_options_max_5F_errors ("galgas_cli_options",
                                                "max_errors",
                                                '\0',
                                                "max-errors",
                                                "Stop after the given number of errors has been reached",
                                                100) ;

//-----------------------------------------------------------------------------*

C_UIntCommandLineOption
gOption_galgas_5F_builtin_5F_options_max_5F_warnings ("galgas_cli_options",
                                                "max_warnings",
                                                '\0',
                                                "max-warnings",
                                                "Stop after the given number of warnings has been reached",
                                                100) ;

//-----------------------------------------------------------------------------*

C_StringCommandLineOption gOption_galgas_5F_builtin_5F_options_mode ("galgas_cli_options",
                                         "mode",
                                         0,
                                         "mode",
                                         "'lexical-only' or 'syntax-only'",
                                         "") ;

//-----------------------------------------------------------------------------*

static PMUInt32 gMode ;
static PMUInt32 gContextHelpStartLocation ;
static PMUInt32 gContextHelpEndLocation ;
static C_String gCurrentlyCompiledBaseFilePath ;

//-----------------------------------------------------------------------------*

void setExecutionMode (C_String & outErrorMessage) {
  const C_String mode = gOption_galgas_5F_builtin_5F_options_mode.mValue ;
  if (mode == "") {
    gMode = 0 ;
  }else if (mode == "lexical-only") {
    gMode = 1 ;
  }else if (mode == "syntax-only") {
    gMode = 2 ;
  }else if (mode == "indexing") {
    gMode = 3 ;
  }else{
    outErrorMessage << "** Fatal Error: invalid '--mode=" << mode << "' parameter; it should be:\n"
      "  --mode=                     default mode: perform compilation;\n"
      "  --mode=lexical-only         perform only lexical analysis;\n"
      "  --mode=syntax-only          perform only syntax analysis.\n" ;
  }
}

//-----------------------------------------------------------------------------*

bool executionModeIsNormal (void) {
  return gMode == 0 ;
}

//-----------------------------------------------------------------------------*

bool executionModeIsLexicalAnalysisOnly (void) {
  return gMode == 1 ;
}

//-----------------------------------------------------------------------------*

bool executionModeIsSyntaxAnalysisOnly (void) {
  return gMode == 2 ;
}

//-----------------------------------------------------------------------------*

bool executionModeIsIndexing (void) {
  return gMode == 3 ;
}

//-----------------------------------------------------------------------------*

PMUInt32 contextHelpStartLocation (void) {
  return gContextHelpStartLocation ;
}

//-----------------------------------------------------------------------------*

PMUInt32 contextHelpEndLocation (void) {
  return gContextHelpEndLocation ;
}

//-----------------------------------------------------------------------------*

void setCurrentCompiledFilePath (const C_String & inPath) {
  gCurrentlyCompiledBaseFilePath = inPath ;
}

//-----------------------------------------------------------------------------*

bool isCurrentCompiledFilePath (const C_String & inPath) {
  return gCurrentlyCompiledBaseFilePath == inPath ;
}

//-----------------------------------------------------------------------------*

static void epilogueAction (void) {
  gCurrentlyCompiledBaseFilePath.releaseString () ;
}

//-----------------------------------------------------------------------------*

C_PrologueEpilogue prologueEpilogue (NULL, epilogueAction) ;

//-----------------------------------------------------------------------------*


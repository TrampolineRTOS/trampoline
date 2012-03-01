//---------------------------------------------------------------------------*
//                                                                           *
//  Built-in GALGAS Command Line Interface Options                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2006, ..., 2011 Pierre Molinaro.                           *
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

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas2/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_galgas_5F_cli_5F_options_outputConcreteSyntaxTree ("galgas_cli_options",
                                         "outputConcreteSyntaxTree",
                                         0,
                                         "output-concrete-syntax-tree",
                                         "Generate the concrete syntax tree, in .dot format (suitable for Graphviz)") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_galgas_5F_cli_5F_options_trace ("galgas_cli_options",
                                         "trace",
                                         0,
                                         "trace",
                                         "Outputs a trace file") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_galgas_5F_cli_5F_options_noteFileAccess ("galgas_cli_options",
                                         "noteFileAccess",
                                         0,
                                         "note-file-access",
                                         "Print a message for every file access") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_cli_5F_options_lexical_5F_analysis_5F_only ("galgas_cli_options",
                                                              "lexical_analysis_only",
                                                              '\0',
                                                              "lexical-analysis-only",
                                                              "Perform only lexical analysis on input files") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_cli_5F_options_parse_5F_only ("galgas_cli_options",
                                                "parse_only",
                                                '\0',
                                                "parse-only",
                                                "Parse only input files") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_cli_5F_options_verbose_5F_output ("galgas_cli_options",
                                                    "verbose_output",
                                                    'v',
                                                    "verbose",
                                                    "Verbose Output") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_cli_5F_options_log_5F_file_5F_read ("galgas_cli_options",
                                                      "log_file_read",
                                                      '\0',
                                                      "log-file-read",
                                                      "Log every file read") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_cli_5F_options_do_5F_not_5F_generate_5F_any_5F_file ("galgas_cli_options",
                                                                       "do_not_generate_any_file",
                                                                       '\0',
                                                                       "no-file-generation",
                                                                       "Do not generate any file") ;

//---------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_cli_5F_options_treat_5F_warnings_5F_as_5F_error ("galgas_cli_options",
                                                                   "treat_warnings_as_error",
                                                                   '\0',
                                                                   "Werror",
                                                                   "Treat warnings as errors") ;

//---------------------------------------------------------------------------*

C_UIntCommandLineOption
gOption_galgas_5F_cli_5F_options_max_5F_errors ("galgas_cli_options",
                                                "max_errors",
                                                '\0',
                                                "max-errors",
                                                "Stop after the given number of errors has been reached",
                                                100) ;

//---------------------------------------------------------------------------*

C_UIntCommandLineOption
gOption_galgas_5F_cli_5F_options_max_5F_warnings ("galgas_cli_options",
                                                "max_warnings",
                                                '\0',
                                                "max-warnings",
                                                "Stop after the given number of warnings has been reached",
                                                100) ;

//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Built-in GALGAS Command Line Interface Options                                                                     *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2006, ..., 2015 Pierre Molinaro.                                                                     *
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
//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/C_galgas_CLI_Options.h"
#include "streams/C_TCPSocketOut.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_galgas_5F_builtin_5F_options_outputConcreteSyntaxTree ("galgas_builtin_options",
                                         "outputConcreteSyntaxTree",
                                         0,
                                         "output-concrete-syntax-tree",
                                         "Generate the concrete syntax tree, in .dot format (suitable for Graphviz)") ;

//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_log_5F_file_5F_read ("galgas_cli_options",
                                                      "log_file_read",
                                                      '\0',
                                                      "log-file-read",
                                                      "Log every file read") ;

//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_do_5F_not_5F_generate_5F_any_5F_file ("galgas_cli_options",
                                                                           "do_not_generate_any_file",
                                                                           '\0',
                                                                           "no-file-generation",
                                                                           "Do not generate any file") ;

//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption
gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error ("galgas_cli_options",
                                                                       "treat_warnings_as_error",
                                                                       '\0',
                                                                       "Werror",
                                                                       "Treat warnings as errors") ;

//---------------------------------------------------------------------------------------------------------------------*

C_UIntCommandLineOption
gOption_galgas_5F_builtin_5F_options_max_5F_errors ("galgas_cli_options",
                                                    "max_errors",
                                                    '\0',
                                                    "max-errors",
                                                    "Stop after the given number of errors has been reached",
                                                    100) ;

//---------------------------------------------------------------------------------------------------------------------*

C_UIntCommandLineOption
gOption_galgas_5F_builtin_5F_options_max_5F_warnings ("galgas_cli_options",
                                                "max_warnings",
                                                '\0',
                                                "max-warnings",
                                                "Stop after the given number of warnings has been reached",
                                                100) ;

//---------------------------------------------------------------------------------------------------------------------*

C_StringCommandLineOption gOption_galgas_5F_builtin_5F_options_mode ("galgas_cli_options",
                                         "mode",
                                         0,
                                         "mode",
                                         "'lexical-only', 'syntax-only' or 'latex'",
                                         "") ;

//---------------------------------------------------------------------------------------------------------------------*

C_StringCommandLineOption gOption_galgas_5F_builtin_5F_options_outputKeywordList ("galgas_cli_options",
                                         "outputKeywordList",
                                         0,
                                         "output-keyword-list-file",
                                         "Output a Latex file containing keyword list",
                                         "") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   EXECUTION MODE                                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static EnumExecutionMode gExecutionMode = kExecutionModeNormal ;
static C_String gModeLatexSuffixString ;

//---------------------------------------------------------------------------------------------------------------------*

void setExecutionMode (C_String & outErrorMessage) {
  const C_String mode = gOption_galgas_5F_builtin_5F_options_mode.mValue ;
  TC_UniqueArray <C_String> modeComponents ;
  mode.componentsSeparatedByString (":", modeComponents) ;
  if (mode == "") {
    gExecutionMode = kExecutionModeNormal ;
  }else if (mode == "lexical-only") {
    gExecutionMode = kExecutionModeLexicalAnalysisOnly ;
  }else if (mode == "syntax-only") {
    gExecutionMode = kExecutionModeSyntaxAnalysisOnly ;
  }else if (mode == "indexing") {
    gExecutionMode = kExecutionModeIndexing ;
  }else if ((modeComponents.count () == 2) && (modeComponents (0 COMMA_HERE) == "latex")) {
    gExecutionMode = kExecutionModeLatex ;
    gModeLatexSuffixString = modeComponents (1 COMMA_HERE) ;
    bool ok = true ;
    for (int32_t i=0 ; (i<gModeLatexSuffixString.length ()) && ok ; i++) {
      const uint32_t c = UNICODE_VALUE (gModeLatexSuffixString (i COMMA_HERE)) ;
      ok = ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ;
    }
    if (! ok) {
      outErrorMessage << "** Fatal Error: invalid '--mode=latex:suffix' parameter; suffix should contain only letters\n" ;
    }
  }else if ((modeComponents.count () == 1) && (mode == "latex")) {
    gExecutionMode = kExecutionModeLatex ;
    gModeLatexSuffixString = "" ;
  }else{
    outErrorMessage << "** Fatal Error: invalid '--mode=" << mode << "' parameter; it should be:\n"
      "  --mode=                     default mode: perform compilation;\n"
      "  --mode=lexical-only         perform only lexical analysis;\n"
      "  --mode=syntax-only          perform only syntax analysis;\n"
      "  --mode=latex:suffix         perform latex formatting.\n" ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

EnumExecutionMode executionMode (void) {
  return gExecutionMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool executionModeIsLexicalAnalysisOnly (void) {
  return gExecutionMode == kExecutionModeLexicalAnalysisOnly ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool executionModeIsSyntaxAnalysisOnly (void) {
  return gExecutionMode == kExecutionModeSyntaxAnalysisOnly ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool executionModeIsIndexing (void) {
  return gExecutionMode == kExecutionModeIndexing ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool executionModeIsLatex (void) {
  return gExecutionMode == kExecutionModeLatex ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String latexModeStyleSuffixString (void) {
  return gModeLatexSuffixString ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void epilogueAction (void) {
  gModeLatexSuffixString.releaseString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue prologueEpilogue (NULL, epilogueAction) ;

//---------------------------------------------------------------------------------------------------------------------*


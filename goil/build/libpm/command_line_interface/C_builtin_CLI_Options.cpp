//--------------------------------------------------------------------------------------------------
//
//  Generic Command Line Interface Options                                                       
//   --help : Display help information                                                           
//   --version : Display software current version                                                
//   --no-color: Do not issue colored messages                                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2003, ..., 2012 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#include "C_builtin_CLI_Options.h"

//--------------------------------------------------------------------------------------------------

C_BoolCommandLineOption
gOption_generic_5F_cli_5F_options_display_5F_help ("generic_cli_options",
                                                   "display_help",
                                                   '\0',
                                                   "help",
                                                   "Display help information") ;

//--------------------------------------------------------------------------------------------------

C_BoolCommandLineOption
gOption_generic_5F_cli_5F_options_display_5F_version ("generic_cli_options",
                                                      "display_version",
                                                      '\0',
                                                      "version",
                                                      "Display version") ;

//--------------------------------------------------------------------------------------------------

C_StringCommandLineOption
gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file ("generic_cli_options",
                                                      "emit_issue_json_file",
                                                      '\0',
                                                      "emit-issue-json-file",
                                                      "Emit a JSON file that contains all compilation issues",
                                                      "") ;

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 0
  C_BoolCommandLineOption
  gOption_generic_5F_cli_5F_options_no_5F_color ("generic_cli_options",
                                                 "no_color",
                                                 '\0',
                                                 "no-color",
                                                 "Do not issue colored messages") ;
#endif

//--------------------------------------------------------------------------------------------------

  #if COMPILE_FOR_WINDOWS == 1
  C_BoolCommandLineOption
  gOption_generic_5F_cli_5F_options_nodialog ("generic_cli_options",
                                              "nodialog",
                                              '\0',
                                              "no-dialog",
                                              "Do Not Display any dialog when no input file (Windows only)") ;
#endif

//--------------------------------------------------------------------------------------------------

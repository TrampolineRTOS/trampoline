//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2014 Pierre Molinaro.                                                                     *
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
//----------------------------------------------------------------------------------------------------------------------

#import "enterDefaultCommandLineOptions.h"
#import "OC_GGS_CommandLineOption.h"

//----------------------------------------------------------------------------------------------------------------------

void enterDefaultCommandLineOptions (NSMutableArray * ioBoolOptionArray,
                                     NSMutableArray * ioUIntOptionArray,
                                     NSMutableArray * ioStringOptionArray) {
  OC_GGS_CommandLineOption * option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"generic_cli_options"
    identifier:@"display_help"
    commandChar:0
    commandString:@"help"
    comment:@"Display help information"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"generic_cli_options"
    identifier:@"display_version"
    commandChar:0
    commandString:@"version"
    comment:@"Display version"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"log_file_read"
    commandChar:'\0'
    commandString:@"log-file-read"
    comment:@"Log every file read"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"do_not_generate_any_file"
    commandChar:'\0'
    commandString:@"no-file-generation"
    comment:@"Do not generate any file"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"treat_warnings_as_error"
    commandChar:'\0'
    commandString:@"Werror"
    comment:@"Treat warnings as errors"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"outputConcreteSyntaxTree"
    commandChar:'\0'
    commandString:@"output-concrete-syntax-tree"
    comment:@"Generate the concrete syntax tree, in .dot format (suitable for Graphviz)"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;


  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"max_errors"
    commandChar:'\0'
    commandString:@"max-errors"
    comment:@"Stop after the given number of errors has been reached (by default: 100)"
    defaultValue:@""
  ] ;
  [ioUIntOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"max_warnings"
    commandChar:'\0'
    commandString:@"max-warnings"
    comment:@"Stop after the given number of warnings has been reached (by default: 100)"
    defaultValue:@""
  ] ;
  [ioUIntOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"mode"
    commandChar:'\0'
    commandString:@"mode"
    comment:@"Mode: empty, 'lexical-only' or 'syntax-only'"
    defaultValue:@""
  ] ;
  [ioStringOptionArray addObject:option] ;
  

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"outputKeywordList"
    commandChar:'\0'
    commandString:@"output-keyword-list-file"
    comment:@"Output a Latex file containing keyword list"
    defaultValue:@""
  ] ;
  [ioStringOptionArray addObject:option] ;
}

//----------------------------------------------------------------------------------------------------------------------

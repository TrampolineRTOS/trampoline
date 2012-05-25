//
//  enterDefaultCommandLineOptions.m
//  galgas
//
//  Created by Pierre Molinaro on 06/07/09.
//  Copyright 2009 ECN / IRCCyN. All rights reserved.
//

#import "enterDefaultCommandLineOptions.h"
#import "OC_GGS_CommandLineOption.h"

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
    identifier:@"verbose_output"
    commandChar:'v'
    commandString:@"verbose"
    comment:@"Verbose Output"
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
    identifier:@"outputAbstractSyntaxTree"
    commandChar:'\0'
    commandString:@"output-abstract-syntax-tree"
    comment:@"Generate the abstract syntax tree, in .dot format (suitable for Graphviz)"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;

  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"galgas_cli_options"
    identifier:@"trace"
    commandChar:'\0'
    commandString:@"trace"
    comment:@"Outputs a trace file"
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
}

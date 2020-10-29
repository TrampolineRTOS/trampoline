//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------

#import "option-goil-5F-options-cocoa.h"
#import "OC_GGS_CommandLineOption.h"

//----------------------------------------------------------------------------------------------------------------------

void enterOptionsFor_goil_5F_options (NSMutableArray * ioBoolOptionArray,
                                      NSMutableArray * ioUIntOptionArray,
                                      NSMutableArray * ioStringOptionArray,
                                      NSMutableArray * ioStringListOptionArray) {
  OC_GGS_CommandLineOption * option ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"arxmlDisplayOil"
    commandChar:0
    commandString:@"arxmlPrintOil"
    comment:@"Display an Oil version while parsing an arxml file"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"generate_log"
    commandChar:108
    commandString:@"logfile"
    comment:@"generate a goil.log file containing the a log of the compilation"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"pierreOption"
    commandChar:0
    commandString:@"pierre"
    comment:@"Special option to pass a galgas bug to Pierre"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"warnMultiple"
    commandChar:0
    commandString:@"warn-multiple"
    comment:@"Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"config"
    commandChar:99
    commandString:@"config"
    comment:@"Specifies the OIL config file used by goil"
    defaultValue:@"config"
  ] ;
  [ioStringOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"passOption"
    commandChar:111
    commandString:@"option"
    comment:@"Pass options to the template root script"
    defaultValue:@""
  ] ;
  [ioStringOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"project_dir"
    commandChar:112
    commandString:@"project"
    comment:@"Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)"
    defaultValue:@""
  ] ;
  [ioStringOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"root"
    commandChar:114
    commandString:@"root"
    comment:@"Specifies the root template file to use to generate the output files"
    defaultValue:@"root"
  ] ;
  [ioStringOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"target_platform"
    commandChar:116
    commandString:@"target"
    comment:@"Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino."
    defaultValue:@""
  ] ;
  [ioStringOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"goil_options"
    identifier:@"template_dir"
    commandChar:0
    commandString:@"templates"
    comment:@"Specifies template directory (used by goil for code generation)"
    defaultValue:@""
  ] ;
  [ioStringOptionArray addObject:option] ;
}

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



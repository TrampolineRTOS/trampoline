//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------

#import "option-gtl-5F-options-cocoa.h"
#import "OC_GGS_CommandLineOption.h"

//----------------------------------------------------------------------------------------------------------------------

void enterOptionsFor_gtl_5F_options (NSMutableArray * ioBoolOptionArray,
                                     NSMutableArray * ioUIntOptionArray,
                                     NSMutableArray * ioStringOptionArray,
                                     NSMutableArray * ioStringListOptionArray) {
  OC_GGS_CommandLineOption * option ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"gtl_options"
    identifier:@"debug"
    commandChar:0
    commandString:@"debug"
    comment:@"Execute the GTL templates in debug mode"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"gtl_options"
    identifier:@"warnDeprecated"
    commandChar:0
    commandString:@"warn-deprecated"
    comment:@"Warns about deprecated constructs in the GTL template language"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
}

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



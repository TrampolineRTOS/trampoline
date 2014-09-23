//
//  OC_GGS_CommandLineOption.h
//  galgas
//
//  Created by Pierre Molinaro on 06/07/09.
//  Copyright 2009 ECN / IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//-----------------------------------------------------------------------------*

@interface OC_GGS_CommandLineOption : NSObject {
  @private NSString * mDomainName ;
  @private NSString * mIdentifier ;
  @private char mCommandChar ;
  @private NSString * mCommandString ;
  @private NSString * mComment ;
  @private NSString * mDefaultValue ;
  
}

- (id) initWithDomainName: (NSString *) inDomainName
       identifier: (NSString *) inIdentifier
       commandChar: (char) inCommandChar
       commandString: (NSString *) inCommandString
       comment: (NSString *) inComment
       defaultValue: (NSString *) inDefaultValue ;

- (NSString *) identifier ;

- (char) commandChar ;

- (NSString *) commandString ;

- (NSString *) title ;

@end

//-----------------------------------------------------------------------------*

//
//  OC_GGS_CommandLineOption.m
//  galgas
//
//  Created by Pierre Molinaro on 06/07/09.
//  Copyright 2009 ECN / IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------------------------------------------------*

#import "OC_GGS_CommandLineOption.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation OC_GGS_CommandLineOption

//---------------------------------------------------------------------------------------------------------------------*

- (id) initWithDomainName: (NSString *) inDomainName
       identifier: (NSString *) inIdentifier
       commandChar: (char) inCommandChar
       commandString: (NSString *) inCommandString
       comment: (NSString *) inComment
       defaultValue: (NSString *) inDefaultValue {
  self = [super init] ;
  if (self) {
    mDomainName = inDomainName.copy ;
    mIdentifier = inIdentifier.copy ;
    mCommandChar = inCommandChar ;
    mCommandString = inCommandString.copy ;
    mComment = inComment.copy ;
    mDefaultValue = inDefaultValue.copy ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) identifier {
  return mIdentifier ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (char) commandChar {
  return mCommandChar ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) commandString {
  return mCommandString ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) title {
  return ([mDefaultValue length] == 0)
    ? mComment
    : [NSString stringWithFormat:@"%@ (default value: %@)", mComment, mDefaultValue]
  ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end

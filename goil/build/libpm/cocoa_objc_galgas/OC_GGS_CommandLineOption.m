//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2014 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------------------------------------

#import "OC_GGS_CommandLineOption.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_CommandLineOption

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) identifier {
  return mIdentifier ;
}

//----------------------------------------------------------------------------------------------------------------------

- (char) commandChar {
  return mCommandChar ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) commandString {
  return mCommandString ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) title {
  return ([mDefaultValue length] == 0)
    ? mComment
    : [NSString stringWithFormat:@"%@ (default value: %@)", mComment, mDefaultValue]
  ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

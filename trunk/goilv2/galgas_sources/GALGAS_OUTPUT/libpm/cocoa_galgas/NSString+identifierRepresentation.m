//
//  NSString+identifierRepresentation.m
//  galgas-developer-v2
//
//  Created by Pierre Molinaro on 04/09/2014.
//  Copyright (c) 2014 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------------------------------------------------*

#import "NSString+identifierRepresentation.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation NSString (IdentifierRepresentation)

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) identifierRepresentation {
  NSMutableString * result = [NSMutableString new] ;
  for (NSUInteger i=0 ; i<self.length ; i++) {
    const unichar c = [self characterAtIndex:i] ;
    if ((c >= 'A') && (c <= 'Z')) {
      [result appendFormat:@"%c", c] ;
    }else if ((c >= 'a') && (c <= 'z')) {
      [result appendFormat:@"%c", c] ;
    }else{
      [result appendFormat:@"_%u_", c] ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end

//
//  OC_Token.h
//  galgas
//
//  Created by Pierre Molinaro on 26/06/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface OC_Token : NSObject {
  @private NSUInteger mTokenCode ;
  @private NSRange mRange ;
  @private SInt32 mStyle ;
  @private SInt32 mMatchedTemplateDelimiterIndex ;
}

- (id) initWithTokenCode: (UInt32) inTokenCode
       range: (NSRange) inRange
       style: (SInt32) inStyle
       matchedTemplateDelimiterIndex: (SInt32) inMatchedTemplateDelimiterIndex ;

- (NSUInteger) tokenCode ;

- (NSRange) range ;

- (SInt32) style ;

- (SInt32) matchedTemplateDelimiterIndex ;

- (void) translateRange: (NSInteger) inTranslation ;

@end

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
  @private NSInteger mStyle ;
  @private NSInteger mMatchedTemplateDelimiterIndex ;
}

- (id) initWithTokenCode: (NSUInteger) inTokenCode
       range: (NSRange) inRange
       style: (NSInteger) inStyle
       matchedTemplateDelimiterIndex: (NSInteger) inMatchedTemplateDelimiterIndex ;

- (NSUInteger) tokenCode ;

- (NSRange) range ;

- (NSInteger) style ;

- (NSInteger) matchedTemplateDelimiterIndex ;

- (void) translateRange: (NSInteger) inTranslation ;

@end

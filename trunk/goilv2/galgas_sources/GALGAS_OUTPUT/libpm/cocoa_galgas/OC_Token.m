//
//  OC_Token.m
//  galgas
//
//  Created by Pierre Molinaro on 26/06/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_Token.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------*

@implementation OC_Token

//---------------------------------------------------------------------------*

- (id) initWithTokenCode: (NSUInteger) inTokenCode
       range: (NSRange) inRange
       style: (NSInteger) inStyle
       matchedTemplateDelimiterIndex: (NSInteger) inMatchedTemplateDelimiterIndex {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mTokenCode = inTokenCode ;
    mRange = inRange ;
    mStyle = inStyle ;
    mMatchedTemplateDelimiterIndex = inMatchedTemplateDelimiterIndex ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------*

- (NSUInteger) tokenCode {
  return mTokenCode ;
}

//---------------------------------------------------------------------------*

- (NSRange) range {
  return mRange ;
}

//---------------------------------------------------------------------------*

- (NSInteger) style {
  return mStyle ;
}

//---------------------------------------------------------------------------*

- (NSInteger) matchedTemplateDelimiterIndex {
  return mMatchedTemplateDelimiterIndex ;
}

//---------------------------------------------------------------------------*

- (void) translateRange: (NSInteger) inTranslation {
  if ((inTranslation < 0) && (mRange.location < ((NSUInteger) - inTranslation))) {
    NSLog (@"ERROR in %s : range [%llu %llu], inTranslation %lld",
           __PRETTY_FUNCTION__,
           (UInt64) mRange.location,
           (UInt64) mRange.length,
           (SInt64) inTranslation) ;
  }
  mRange.location += (NSUInteger) inTranslation ;
}

//---------------------------------------------------------------------------*

@end

//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#import "OC_Token.h"
#import "PMDebug.h"

//--------------------------------------------------------------------------------------------------

@implementation OC_Token

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) tokenCode {
  return mTokenCode ;
}

//--------------------------------------------------------------------------------------------------

- (NSRange) range {
  return mRange ;
}

//--------------------------------------------------------------------------------------------------

- (NSInteger) style {
  return mStyle ;
}

//--------------------------------------------------------------------------------------------------

- (NSInteger) matchedTemplateDelimiterIndex {
  return mMatchedTemplateDelimiterIndex ;
}

//--------------------------------------------------------------------------------------------------

- (void) translateRange: (NSInteger) inTranslation {
  if ((inTranslation < 0) && (mRange.location < ((NSUInteger) - inTranslation))) {
    NSLog (@"ERROR in %s : range [%llu %llu], inTranslation %lld",
           __PRETTY_FUNCTION__,
           (UInt64) mRange.location,
           (UInt64) mRange.length,
           (SInt64) inTranslation) ;
  }
  if (inTranslation >= 0) {
    mRange.location += (NSUInteger) inTranslation ;
  }else{
    mRange.location -= (NSUInteger) -inTranslation ;
  }
}

//--------------------------------------------------------------------------------------------------

@end

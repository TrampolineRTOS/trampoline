//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2013, ..., 2014 Pierre Molinaro.
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

#import "PMSearchResultDescriptor.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation PMSearchResultDescriptor

//----------------------------------------------------------------------------------------------------------------------

//#define DEBUG_MESSAGES

//----------------------------------------------------------------------------------------------------------------------

- (PMSearchResultDescriptor *) initWithLine: (NSString *) inLine
                               range: (NSRange) inRange
                               sourceFilePath: (NSString *) inFilePath {
  self = [self init] ;
  if (self) {
    mFoundItem = inLine ;
    mRange = inRange ;
    mFilePath = inFilePath.copy ;
    mColor = [NSColor blackColor] ;
  }
  return self ;
}

//----------------------------------------------------------------------------------------------------------------------

- (PMSearchResultDescriptor *) initWithEntries: (NSArray *) inEntryArray
                               sourceFilePath: (NSString *) inFilePath {
  self = [self init] ;
  if (self) {
    mFoundItem = inFilePath.copy ;
    mEntryArray = inEntryArray ;
    mFilePath = inFilePath.copy ;
    mColor = [NSColor blackColor] ;
  }
  return self ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSRange) range {
  return mRange ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) foundItem {
  return mFoundItem ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) filePath {
  return mFilePath ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) countString {
  return (mEntryArray.count > 0) ? [NSString stringWithFormat:@"%lu", mEntryArray.count] : nil ;
}

//----------------------------------------------------------------------------------------------------------------------

- (BOOL) boldDisplay {
  return mEntryArray.count > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSArray *) children {
  return mEntryArray ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSColor *) color {
  return mColor ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) updateSearchResultForFile: (NSString *) inFilePath
         previousRange: (NSRange) inPreviousRange
         changeInLength: (NSInteger) inChangeInLength {
  #ifdef DEBUG_MESSAGES
    NSLog (@"mFilePath %@, inFilePath %@", mFilePath, inFilePath) ;
  #endif
  if ((nil != mFilePath) && [mFilePath isEqualToString:inFilePath] && ((mRange.location + mRange.length) > 0)) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"mRange [%lu, %lu], inPreviousRange [%lu, %lu], inChangeInLength %ld", mRange.location, mRange.length, inPreviousRange.location, inPreviousRange.length, inChangeInLength) ;
    #endif
    if ((inPreviousRange.location + inPreviousRange.length) <= mRange.location) { // Change before
      mRange.location += (NSUInteger) inChangeInLength ;
      #ifdef DEBUG_MESSAGES
        NSLog (@" - Change before -> mRange [%lu, %lu]", mRange.location, mRange.length) ;
      #endif
    }else if (inPreviousRange.location > (mRange.location + mRange.length)) { // Change after
      #ifdef DEBUG_MESSAGES
        NSLog (@" - Change after") ;
      #endif
    }else{ // Change within
      mRange.location = 0 ;
      mRange.length = 0 ;
      #ifdef DEBUG_MESSAGES
        NSLog (@" - Change within -> mRange [%lu, %lu]", mRange.location, mRange.length) ;
      #endif
      [self willChangeValueForKey:@"mColor"] ;
        mColor = [NSColor redColor] ;
      [self didChangeValueForKey:@"mColor"] ;
    }
  }
//---
  for (PMSearchResultDescriptor * d in mEntryArray) {
    [d
      updateSearchResultForFile:inFilePath
      previousRange:inPreviousRange
      changeInLength:inChangeInLength
    ] ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

@end

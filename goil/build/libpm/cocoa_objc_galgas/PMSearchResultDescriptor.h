//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>

//--------------------------------------------------------------------------------------------------

@interface PMSearchResultDescriptor : NSObject {
  @private NSString * mFoundItem ;
  @private NSRange mRange ;
  @private NSString * mFilePath ;
  @private NSArray * mEntryArray ;
  @private NSColor * mColor ;
}

- (PMSearchResultDescriptor *) initWithLine: (NSString *) inLine
    range: (NSRange) inRange
    sourceFilePath: (NSString *) inFilePath ;

- (PMSearchResultDescriptor *) initWithEntries: (NSArray *) inEntryArray
    sourceFilePath: (NSString *) inFilePath ;

- (NSString *) foundItem ;

- (NSString *) filePath ;

- (NSString *) countString ;

- (NSColor *) color ;

- (NSRange) range ;

- (BOOL) boldDisplay ;

- (NSArray *) children ;

- (void) updateSearchResultForFile: (NSString *) inFilePath
         previousRange: (NSRange) inPreviousRange
         changeInLength: (NSInteger) inChangeInLength ;

@end

//--------------------------------------------------------------------------------------------------

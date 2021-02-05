//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.
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

#import <Cocoa/Cocoa.h>

//----------------------------------------------------------------------------------------------------------------------

@class OC_GGS_RulerViewForBuildOutput ;
@class OC_GGS_TextDisplayDescriptor ;

//----------------------------------------------------------------------------------------------------------------------

typedef enum {
 kLocationInSourceStringNotSolved,
 kLocationInSourceStringSolved,
 kLocationInSourceStringInvalid
} enumLocationInSourceStringStatus ;

//----------------------------------------------------------------------------------------------------------------------

@interface PMIssueDescriptor : NSObject {
  @private BOOL mIsError ;
  @private NSString * mFullMessage ;
  @private NSURL * mURL ;
  @private NSUInteger mLine ;
  @private NSUInteger mStartColumn ;
  @private NSUInteger mEndColumn ;
  @private NSRange mRangeInOutputData ;
  @private NSUInteger mStartLocationInSourceString ;
  @private NSUInteger mEndLocationInSourceString ;
  @private enumLocationInSourceStringStatus mLocationInSourceStringStatus ;
  @private OC_GGS_RulerViewForBuildOutput * mBuildOutputRuler ;
}

- (PMIssueDescriptor *) initWithMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        startColumn: (NSInteger) inStartColumn
                        endColumn: (NSInteger) inEndColumn
                        isError: (BOOL) inIsError
                        rangeInOutputData: (NSRange) inRangeInOutputData
                        buildOutputRuler: (OC_GGS_RulerViewForBuildOutput *) inRuler ;

- (void) detach ;

- (NSString *) fullMessage ;

- (NSURL *) issueStandardizedURL ;

- (BOOL) isError ;

- (NSUInteger) issueLine ;

- (NSUInteger) issueStartColumn ;

- (NSUInteger) issueEndColumn ;

- (NSUInteger) locationInOutputData ;

- (enumLocationInSourceStringStatus) locationInSourceStringStatus ;

- (NSUInteger) startLocationInSourceString ;

- (NSUInteger) endLocationInSourceString ;

- (BOOL) intersectWithRange: (NSRange) inRange ;

- (void) setStartLocationInSourceString: (NSUInteger) inStartLocationInSourceString
         endLocation: (NSUInteger) inEndLocationInSourceString ;

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (void) scrollAndSelectErrorMessage ;

- (void) storeItemsToMenu: (NSMenu *) inMenu
         displayDescriptor: (OC_GGS_TextDisplayDescriptor *) inTextView ;

@end

//----------------------------------------------------------------------------------------------------------------------

//
//  PMIssueDescriptor.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 07/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//---------------------------------------------------------------------------*

@class OC_GGS_RulerViewForBuildOutput ;

//---------------------------------------------------------------------------*

typedef enum {
 kLocationInSourceStringNotSolved,
 kLocationInSourceStringSolved,
 kLocationInSourceStringInvalid
} enumLocationInSourceStringStatus ;

//---------------------------------------------------------------------------*

@interface PMIssueDescriptor : NSObject {
  @private BOOL mIsError ;
  @private NSString * mMessage ;
  @private NSURL * mURL ;
  @private NSUInteger mLine ;
  @private NSUInteger mColumn ;
  @private NSRange mRangeInOutputData ;
  @private NSUInteger mLocationInSourceString ;
  @private enumLocationInSourceStringStatus mLocationInSourceStringStatus ;
  @private OC_GGS_RulerViewForBuildOutput * mBuildOutputRuler ;
}

- (PMIssueDescriptor *) initWithMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn
                        isError: (BOOL) inIsError
                        rangeInOutputData: (NSRange) inRangeInOutputData
                        buildOutputRuler: (OC_GGS_RulerViewForBuildOutput *) inRuler ;

- (void) detach ;

- (NSString *) issueMessage ;

- (NSURL *) issueURL ;

- (BOOL) isError ;

- (NSUInteger) issueLine ;

- (NSUInteger) issueColumn ;

- (NSUInteger) locationInOutputData ;

- (enumLocationInSourceStringStatus) locationInSourceStringStatus ;

- (NSUInteger) locationInSourceString ;
- (void) setLocationInSourceString: (NSUInteger) inLocationInSourceString ;

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (void) scrollAndSelectErrorMessage ;
@end

//---------------------------------------------------------------------------*

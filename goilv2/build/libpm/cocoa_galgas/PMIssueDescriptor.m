//
//  PMIssueDescriptor.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 07/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------------------------------------------------*

#import "PMIssueDescriptor.h"
#import "PMDebug.h"
#import "OC_GGS_RulerViewForBuildOutput.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation PMIssueDescriptor

//---------------------------------------------------------------------------------------------------------------------*

- (void) normalizeMessage {
  while ((mMessage.length > 1) && ([mMessage characterAtIndex:mMessage.length-1] == '\n')) {
    mMessage = [mMessage substringToIndex:mMessage.length-1] ;
  }
  while ((mMessage.length > 0) && ([mMessage characterAtIndex:0] == '\n')) {
    mMessage = [mMessage substringFromIndex:1] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (PMIssueDescriptor *) initWithMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn
                        isError: (BOOL) inIsError
                        rangeInOutputData: (NSRange) inRangeInOutputData
                        buildOutputRuler: (OC_GGS_RulerViewForBuildOutput *) inRuler {
  self = [self init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mMessage = inMessage.copy ;
    mURL = inURL.standardizedURL ;
    mLine = (NSUInteger) inLine ;
    mColumn = (NSUInteger) inColumn ;
    mIsError = inIsError ;
    mRangeInOutputData = inRangeInOutputData ;
    mLocationInSourceStringStatus = kLocationInSourceStringNotSolved ;
    mBuildOutputRuler = inRuler ;
    [self normalizeMessage] ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) issueMessage {
  return mMessage ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSURL *) issueStandardizedURL {
  return mURL ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) isError {
  return mIsError ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) issueLine {
  return mLine ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) issueColumn {
  return mColumn ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) locationInOutputData {
  return mRangeInOutputData.location ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (enumLocationInSourceStringStatus) locationInSourceStringStatus {
  return mLocationInSourceStringStatus ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) locationInSourceString {
  return mLocationInSourceString ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) setLocationInSourceString: (NSUInteger) inLocationInSourceString {
  mLocationInSourceString = inLocationInSourceString ;
  mLocationInSourceStringStatus = kLocationInSourceStringSolved ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
  if (((NSUInteger) mLocationInSourceString) >= (inEditedRange.location + inEditedRange.length)) {
    mLocationInSourceString += (NSUInteger) inChangeInLength ;
  }else if (((NSUInteger) mLocationInSourceString) >= inEditedRange.location) {
    mLocationInSourceStringStatus = kLocationInSourceStringInvalid ;
    [mBuildOutputRuler setNeedsDisplay:YES] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) detach {
  mBuildOutputRuler = nil ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) scrollAndSelectErrorMessage {
  NSTextView * errorMessageTextView = mBuildOutputRuler.scrollView.documentView ;
  [errorMessageTextView setSelectedRange:mRangeInOutputData] ;
  [errorMessageTextView scrollRangeToVisible:mRangeInOutputData] ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end

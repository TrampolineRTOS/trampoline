//
//  PMErrorOrWarningDescriptor.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import "PMErrorOrWarningDescriptor.h"

@implementation PMErrorOrWarningDescriptor

- (PMErrorOrWarningDescriptor *) initWithMessage: (NSString *) inMessage
                                 location: (NSUInteger) inLocation
                                 isError: (BOOL) inIsError
                                 originalIssue: (PMIssueDescriptor *) inOriginalIssue {
  self = [self init] ;
  if (self) {
    mMessage = inMessage.copy ;
    mLocation = inLocation ;
    mIsError = inIsError ;
    mOriginalIssue = inOriginalIssue ;
  }
  return self ;
}

- (BOOL) isInRange: (NSRange) inRange {
  return (mLocation >= inRange.location) && (mLocation < (inRange.location + inRange.length)) ;
}

- (NSString *) message {
  return mMessage ;
}

- (BOOL) isError {
  return mIsError ;
}

- (NSUInteger) location {
  return mLocation ;
}

- (PMIssueDescriptor *) originalIssue {
  return mOriginalIssue ;
}

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
  if (mLocation >= (inEditedRange.location + inEditedRange.length)) {
    mLocation += inChangeInLength ;
  }
}

@end

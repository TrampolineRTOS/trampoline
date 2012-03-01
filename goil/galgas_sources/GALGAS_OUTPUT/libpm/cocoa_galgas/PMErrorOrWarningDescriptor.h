//
//  PMErrorOrWarningDescriptor.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PMIssueDescriptor ;

@interface PMErrorOrWarningDescriptor : NSObject {
  @private BOOL mIsError ;
  @private NSString * mMessage ;
  @private NSUInteger mLocation ;
  @private PMIssueDescriptor * mOriginalIssue ;
}

- (PMErrorOrWarningDescriptor *) initWithMessage: (NSString *) inMessage
                                 location: (NSUInteger) inLocation
                                 isError: (BOOL) inIsError
                                 originalIssue: (PMIssueDescriptor *) inOriginalIssue ;

- (BOOL) isInRange: (NSRange) inRange ;

- (BOOL) isError ;

- (NSString *) message ;

- (NSUInteger) location ;

- (void) updateLocationForPreviousRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (PMIssueDescriptor *) originalIssue ;
@end

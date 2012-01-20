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

typedef enum {
 kFileOperationIssue,
 kMessageIssue,
 kWarningIssue,
 kErrorIssue
} enumIssueKind ;

//---------------------------------------------------------------------------*

@interface PMIssueDescriptor : NSObject {
  @private enumIssueKind mIssueKind ;
  @private NSString * mMessage ;
  @private NSURL * mURL ;
  @private NSInteger mLine ;
  @private NSInteger mColumn ;

}

- (PMIssueDescriptor *) initWithMessage: (NSString *) inMessage ;

- (PMIssueDescriptor *) initWithFileOperation: (NSString *) inMessage ;

- (PMIssueDescriptor *) initWithErrorMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn ;

- (PMIssueDescriptor *) initWithWarningMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn ;

- (NSString *) issueMessage ;

- (NSURL *) issueURL ;

- (enumIssueKind) issueKind ;

- (BOOL) errorKind ;

- (BOOL) errorOrWarningKind ;

- (NSInteger) issueLine ;

- (NSInteger) issueColumn ;

@end

//---------------------------------------------------------------------------*

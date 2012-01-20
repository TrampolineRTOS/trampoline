//
//  PMIssueDescriptor.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 07/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "PMIssueDescriptor.h"

//---------------------------------------------------------------------------*

@implementation PMIssueDescriptor

//---------------------------------------------------------------------------*

- (void) normalizeMessage {
  while ((mMessage.length > 1) && ([mMessage characterAtIndex:mMessage.length-1] == '\n')) {
    mMessage = [mMessage substringToIndex:mMessage.length-1] ;
  }
  while ((mMessage.length > 0) && ([mMessage characterAtIndex:0] == '\n')) {
    mMessage = [mMessage substringFromIndex:1] ;
  }
}

//---------------------------------------------------------------------------*

- (PMIssueDescriptor *) initWithMessage : (NSString *) inMessage {
  self = [self init] ;
  if (self) {
    mIssueKind = kMessageIssue ;
    mMessage = inMessage.copy ;
    [self normalizeMessage] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (PMIssueDescriptor *) initWithFileOperation: (NSString *) inMessage {
  self = [self init] ;
  if (self) {
    mIssueKind = kFileOperationIssue ;
    mMessage = inMessage.copy ;
    [self normalizeMessage] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (PMIssueDescriptor *) initWithErrorMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn {
  self = [self init] ;
  if (self) {
    mIssueKind = kErrorIssue ;
    mMessage = inMessage.copy ;
    mURL = inURL.copy ;
    mLine = inLine ;
    mColumn = inColumn ;
    [self normalizeMessage] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (PMIssueDescriptor *) initWithWarningMessage: (NSString *) inMessage
                        URL: (NSURL *) inURL
                        line: (NSInteger) inLine
                        column: (NSInteger) inColumn {
  self = [self init] ;
  if (self) {
    mIssueKind = kWarningIssue ;
    mMessage = inMessage.copy ;
    mURL = inURL.copy ;
    mLine = inLine ;
    mColumn = inColumn ;
    [self normalizeMessage] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (NSString *) issueMessage {
  return mMessage ;
}

//---------------------------------------------------------------------------*

- (NSURL *) issueURL {
  return mURL ;
}

//---------------------------------------------------------------------------*

- (enumIssueKind) issueKind {
  return mIssueKind ;
}

//---------------------------------------------------------------------------*

- (BOOL) errorOrWarningKind {
  return (kErrorIssue == mIssueKind) || (kWarningIssue == mIssueKind) ;
}

//---------------------------------------------------------------------------*

- (BOOL) errorKind {
  return kErrorIssue == mIssueKind ;
}

//---------------------------------------------------------------------------*

- (NSInteger) issueLine {
  return mLine ;
}

//---------------------------------------------------------------------------*

- (NSInteger) issueColumn {
  return mColumn ;
}

//---------------------------------------------------------------------------*

- (NSColor *) issueColor {
  NSColor * color = [NSColor blackColor] ;
  switch (mIssueKind) {
  case kErrorIssue : color = [NSColor redColor] ; break ;
  case kWarningIssue : color = [NSColor orangeColor] ; break ;
  case kFileOperationIssue : color = [NSColor blueColor] ; break ;
  default : break ;
  }
  return color ;
}

//---------------------------------------------------------------------------*

@end

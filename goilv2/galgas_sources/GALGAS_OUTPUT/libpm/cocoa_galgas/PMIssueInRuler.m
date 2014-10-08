//
//  PMIssueInRuler.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 28/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------------------------------------------------*

#import "PMIssueInRuler.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation PMIssueInRuler

//---------------------------------------------------------------------------------------------------------------------*

- (PMIssueInRuler *) initWithRect: (NSRect) inRect
                     message: (NSString *) inMessage
                     isError: (BOOL) inIsError {
  self = [self init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mBulletRect = inRect ;
    mMessage = inMessage.copy ;
    mIsError = inIsError ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSRect) rect {
  return mBulletRect ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) isError {
  return mIsError ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) message {
  return mMessage ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end

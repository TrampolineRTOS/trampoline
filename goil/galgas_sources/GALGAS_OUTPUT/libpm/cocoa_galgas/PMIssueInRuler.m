//
//  PMIssueInRuler.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 28/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import "PMIssueInRuler.h"

@implementation PMIssueInRuler

- (PMIssueInRuler *) initWithRect: (NSRect) inRect
                     message: (NSString *) inMessage {
  self = [self init] ;
  if (self) {
    mBulletRect = inRect ;
    mMessage = inMessage.copy ;
  }
  return self ;
}

- (NSRect) rect {
  return mBulletRect ;
}

- (NSString *) message {
  return mMessage ;
}

@end

//
//  PMIssueInRuler.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 28/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------*

@interface PMIssueInRuler : NSObject {
  @private NSRect mBulletRect ;
  @private NSString * mMessage ;
  @private BOOL mIsError ;
}

- (PMIssueInRuler *) initWithRect: (NSRect) inRect
                     message: (NSString *) inMessage
                     isError: (BOOL) inIsError ;

- (BOOL) isError ;

- (NSRect) rect ;

- (NSString *) message ;

@end

//-----------------------------------------------------------------------------*

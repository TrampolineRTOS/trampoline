//
//  PMIssueInRuler.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 28/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PMIssueInRuler : NSObject {
  @private NSRect mBulletRect ;
  @private NSString * mMessage ;
}

- (PMIssueInRuler *) initWithRect: (NSRect) inRect
                     message: (NSString *) inMessage ;

- (NSRect) rect ;

- (NSString *) message ;

@end

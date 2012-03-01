//
//  PMTabBarView.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 25/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface PMTabBarView : NSView {
  @private NSMutableArray * mButtonArray ;
  @private NSArray * mObservedArray ;
  @private SEL mChangeSourceTabAction ;
  @private SEL mRemoveSourceTabAction ;
  @private id mTarget ;
}

- (void) setTarget: (id) inTarget ;
- (void) setRemoveSourceTabAction: (SEL) inAction ;
- (void) setChangeSourceTabAction: (SEL) inAction ;
@end

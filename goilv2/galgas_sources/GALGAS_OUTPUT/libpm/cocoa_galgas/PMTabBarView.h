//
//  PMTabBarView.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 25/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <AppKit/AppKit.h>

//---------------------------------------------------------------------------*

@class OC_GGS_TextDisplayDescriptor ;
@class PMButtonWithRemove ;

//---------------------------------------------------------------------------*

@protocol PMTabBarViewDelegateProtocol
  - (void) removeSelectedTabAction: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor ;
  - (void) changeSelectedSourceViewAction: (PMButtonWithRemove *) inSender ;
@end

//---------------------------------------------------------------------------*

@interface PMTabBarView : NSView {
  @private NSMutableArray * mButtonArray ; // of PMButtonWithRemove
  @private NSArray * mObservedArray ; // Of OC_GGS_TextDisplayDescriptor
  @private id <PMTabBarViewDelegateProtocol> mTarget ;
}

- (void) setTarget: (id <PMTabBarViewDelegateProtocol>) inTarget ;
- (void) removeTabAction: (PMButtonWithRemove *) inSender ;
- (void) detach ;
@end

//---------------------------------------------------------------------------*

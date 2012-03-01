//---------------------------------------------------------------------------*
//                                                                           *
//  NSSplitViewExtensions.m          This file is part of libpm library      *
//                                                                           *
//  Copyright (C) 2007 Pierre Molinaro.                                      *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#import "NSSplitViewExtensions.h"
#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

@implementation NSSplitViewExtensions

//---------------------------------------------------------------------------*

- (CGFloat) fraction {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  CGFloat result = 0.0f ;
  if ([[self subviews] count] > 1) {
    NSRect topFrame = [[[self subviews] objectAtIndex:0 HERE] frame];
    NSRect bottomFrame = [[[self subviews] objectAtIndex:1 HERE] frame];
    const CGFloat height = bottomFrame.size.height + topFrame.size.height ;
    if (height > 0) {
      result = topFrame.size.height / height ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (void) setFraction: (CGFloat) inNewFraction {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  if ([[self subviews] count] > 1) {
    CGFloat newFraction = inNewFraction ;
    if (newFraction < 0.0f) {
      newFraction = 0.0f ;
    }else if (newFraction > 1.0f) {
      newFraction = 1.0f ;
    }
    const CGFloat currentFraction = [self fraction] ;
    //[self setPosition:newFraction ofDividerAtIndex:0] ;
    if (currentFraction != newFraction) {
      NSView * topSubView = [[self subviews] objectAtIndex:0 HERE];
      NSView * bottomSubView = [[self subviews] objectAtIndex:1 HERE];
      NSRect topFrame = [topSubView frame];
      NSRect bottomFrame = [bottomSubView frame];
      CGFloat totalHeight = bottomFrame.size.height + topFrame.size.height;
      topFrame.size.height = newFraction * totalHeight;
      bottomFrame.size.height = totalHeight - topFrame.size.height ;
      [topSubView setFrame:topFrame];
      [bottomSubView setFrame:bottomFrame];
      [self adjustSubviews];
      [self setNeedsDisplay:YES];
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                                initialize                                 *
//                                                                           *
//---------------------------------------------------------------------------*

+ (void) initialize {
  [NSSplitViewExtensions exposeBinding:@"fraction"] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Method for 'descriptor' binding                       *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) valueFor_fraction_didChange: (id) inValue {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  if (inValue == NULL) {
    [self setFraction:0.0f] ;
  }else if ([inValue isKindOfClass:[NSNumber class]]) {
    [self setFraction:[inValue floatValue]] ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                    bind:toObject:withKeyPath:options:                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) bind:(NSString *) inBindingName
         toObject:(id) inObservableObject
         withKeyPath:(NSString *) inObservableKeyPath
         options:(NSDictionary *) inOptions {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  if ([inBindingName isEqualToString:@"fraction"]) {
    [self setDelegate:self] ;
    mBoundObjectFor_fraction = inObservableObject ;
    mKeyPathFor_fraction = [inObservableKeyPath copy] ;
    [mKeyPathFor_fraction retain] ;
    [inObservableObject addObserver:self
      forKeyPath:inObservableKeyPath
      options:0
      context:nil
    ] ;
    id value = [inObservableObject valueForKeyPath:inObservableKeyPath] ;
    [self valueFor_fraction_didChange:value] ;
  }else{
    [super bind:inBindingName toObject:inObservableObject withKeyPath:inObservableKeyPath options:inOptions] ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                                 unbind:                                   *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) unbind:(NSString *) inBindingName {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  if ([inBindingName isEqualToString:@"fraction"]) {
    [mBoundObjectFor_fraction removeObserver:self forKeyPath:mKeyPathFor_fraction] ;
    mBoundObjectFor_fraction = nil ;
    [mKeyPathFor_fraction release] ;
    mKeyPathFor_fraction = nil ;
  }else{
    [super unbind:inBindingName] ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//             observeValueForKeyPath:ofObject:change:context:               *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject:(id) inObject
         change:(NSDictionary *) inChangeDictionary
         context:(void *) inContext {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  if ((mBoundObjectFor_fraction == inObject) && [inKeyPath isEqualToString:mKeyPathFor_fraction]) {
    id value = [inObject valueForKeyPath:inKeyPath] ;
    [self valueFor_fraction_didChange:value] ;
  }else{
    [super
      observeValueForKeyPath:inKeyPath
      ofObject:inObject
      change:inChangeDictionary
      context:inContext
    ] ;
  }
}

//---------------------------------------------------------------------------*

- (void) splitViewDidResizeSubviews:(NSNotification *) aNotification {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  const CGFloat f = [self fraction] ;
  [mBoundObjectFor_fraction setValue:[NSNumber numberWithDouble:f] forKeyPath:mKeyPathFor_fraction] ;
//--- Change first responder, depending from subview height
  NSArray * subviews = [self subviews] ;
  NSView * subView0 = [subviews objectAtIndex:0 HERE] ;
  const CGFloat height0 = [subView0 frame].size.height ;
  NSView * subView1 = [subviews objectAtIndex:1 HERE] ;
  const CGFloat height1 = [subView1 frame].size.height ;
  if (height0 == 0.0f) {
    // NSLog (@"height0 is 0.0") ;
    [[self window] makeFirstResponder:subView1] ;
  }else if (height1 == 0.0f) {
    // NSLog (@"height1 is 0.0") ;
    [[self window] makeFirstResponder:subView0] ;
  }

}


//---------------------------------------------------------------------------*

@end

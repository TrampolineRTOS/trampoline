//
//  PMTableViewRefusesFirstResponder.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 18/12/13.
//  Copyright (c) 2013 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import "PMTableViewRefusesFirstResponder.h"

//-----------------------------------------------------------------------------*

@implementation PMTableViewRefusesFirstResponder

//-----------------------------------------------------------------------------*

- (BOOL) becomeFirstResponder {
  return NO ;
}

//-----------------------------------------------------------------------------*

- (NSMenu *) menuForEvent: (NSEvent *) inEvent {
  const NSPoint location = [self convertPoint:inEvent.locationInWindow fromView:nil] ;
  const NSInteger clickedRow = [self rowAtPoint:location] ;
  NSMenu * result = nil ;
  if (clickedRow >= 0) {
    [self selectRowIndexes:[NSIndexSet indexSetWithIndex:(NSUInteger) clickedRow] byExtendingSelection:NO];
    result = mContextualMenu ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

@end

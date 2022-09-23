//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2013, ..., 2022 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#import "PMTableViewHandlesContextualMenu.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation PMTableViewHandlesContextualMenu

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

@end

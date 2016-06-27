//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2013, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#import "PMTableViewRefusesFirstResponder.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation PMTableViewRefusesFirstResponder

//----------------------------------------------------------------------------------------------------------------------

- (BOOL) becomeFirstResponder {
  return NO ;
}

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

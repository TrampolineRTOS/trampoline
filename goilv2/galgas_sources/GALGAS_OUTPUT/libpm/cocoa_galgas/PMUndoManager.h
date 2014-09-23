//
//  PMUndoManager.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 20/07/13.
//  Copyright (c) 2013 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------*

@interface PMUndoManager : NSUndoManager

- (NSArray *) undoStack ;

- (NSArray *) redoStack ;

@end

//-----------------------------------------------------------------------------*

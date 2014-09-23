//
//  PMUndoManager.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 20/07/13.
//  Copyright (c) 2013 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import "PMUndoManager.h"
#import "PMDebug.h"

//-----------------------------------------------------------------------------*

@implementation PMUndoManager

//-----------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
  }
  return self;
}

//-----------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//-----------------------------------------------------------------------------*

- (NSArray *) undoStack {
  return [self valueForKey:@"_undoStack"] ;
}

//-----------------------------------------------------------------------------*

- (NSArray *) redoStack {
  return [self valueForKey:@"_redoStack"] ;
}

//-----------------------------------------------------------------------------*

@end

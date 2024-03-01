//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>

//--------------------------------------------------------------------------------------------------

void showAllocationStatsWindow (void) ;
void noteObjectAllocation (NSObject * inObject) ;
void noteObjectDeallocation (NSObject * inObject) ;

//--------------------------------------------------------------------------------------------------

@interface PMDebug : NSObject <NSTableViewDataSource> {
  @private IBOutlet NSButton * mAllocationStatsWindowVisibleAtLaunchCheckbox ;
  @private IBOutlet NSButton * mCollectExhaustivelyButton ;
  @private IBOutlet NSPopUpButton * mDisplayFilterPopUpButton ;
  @private IBOutlet NSMenu * mDebugMenu ;
  @private IBOutlet NSWindow * mAllocationStatsWindow ;
  @private IBOutlet NSTextField * mCurrentlyAllocatedObjectCountTextField ;
  @private IBOutlet NSTextField * mTotalAllocatedObjectCountTextField ;
  @private IBOutlet NSTableView * mStatsTableView ;
  
  @private NSCountedSet * mAllocatedObjectCountByClass ;
  @private NSCountedSet * mTotalAllocatedObjectCountByClass ;
  @private BOOL mRefreshStatsHasBeenTriggered ;
  @private NSUInteger mLiveAllocatedObjectCount ;
  @private NSUInteger mLiveTotalObjectCount ;
  @private NSArray * mAllocationStatsDataSource ;
  @private NSLock * mLock ;
  #if ! __has_feature(objc_arc)
    @private NSTimer * mRefreshTimer ;
  #endif
}

@property (atomic) BOOL mAllocationStatsWindowVisibleAtLaunch ;
@property (atomic) NSUInteger mAllocatedObjectCount ;
@property (atomic) NSUInteger mTotalAllocatedObjectCount ;
@property (atomic) NSInteger mDisplayFilter ;

- (void) pmNoteObjectAllocation: (NSObject *) inObject ;
- (void) pmNoteObjectDeallocation: (NSObject *) inObject ;
- (void) showAllocationWindow ;
@end

//--------------------------------------------------------------------------------------------------

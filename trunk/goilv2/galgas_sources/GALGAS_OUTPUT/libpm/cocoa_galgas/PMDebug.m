//-----------------------------------------------------------------------------*

#import "PMDebug.h"

//-----------------------------------------------------------------------------*

static PMDebug * gDebugObject ;

//-----------------------------------------------------------------------------*

void noteObjectAllocation (NSObject * inObject) {
  if (nil == gDebugObject) {
    gDebugObject = [PMDebug new] ;
    #ifdef MAC_OS_X_VERSION_10_8
      NSArray * objects = nil ;
      const BOOL ok = [[NSBundle mainBundle] loadNibNamed:@"PMDebug" owner:gDebugObject topLevelObjects:& objects] ;
    #else
      const BOOL ok = [NSBundle loadNibNamed:@"PMDebug" owner:gDebugObject] ;
    #endif
    if (! ok) {
//      presentErrorWindow (__FILE__, __LINE__, @"Cannot load 'PMDebug' nib file") ;
    }
  }
  [gDebugObject pmNoteObjectAllocation:inObject] ;
}

//-----------------------------------------------------------------------------*

void noteObjectDeallocation (NSObject * inObject) {
  [gDebugObject pmNoteObjectDeallocation:inObject] ;
}

//-----------------------------------------------------------------------------*


@implementation PMDebug

//-----------------------------------------------------------------------------*

@synthesize mAllocationStatsWindowVisibleAtLaunch ;
@synthesize mAllocatedObjectCount ;
@synthesize mTotalAllocatedObjectCount ;
@synthesize mDisplayFilter ;

//-----------------------------------------------------------------------------*

- (void) showAllocationWindow {
  [mAllocationStatsWindow makeKeyAndOrderFront:nil] ;
}

//-----------------------------------------------------------------------------*

void showAllocationStatsWindow (void) {
  if (nil == gDebugObject) {
    gDebugObject = [PMDebug new] ;
    #ifdef MAC_OS_X_VERSION_10_8
      NSArray * objects = nil ;
      const BOOL ok = [[NSBundle mainBundle] loadNibNamed:@"PMDebug" owner:gDebugObject topLevelObjects:& objects] ;
    #else
      const BOOL ok = [NSBundle loadNibNamed:@"PMDebug" owner:gDebugObject] ;
    #endif
    if (! ok) {
//      presentErrorWindow (__FILE__, __LINE__, @"Cannot load 'PMDebug' nib file") ;
    }
  }
  [gDebugObject showAllocationWindow] ;
}

//-----------------------------------------------------------------------------*
//    init                                                                     *
//-----------------------------------------------------------------------------*

- (instancetype) init {
  //  NSLog (@"%s %p", __PRETTY_FUNCTION__, self) ;
  self = [super init] ;
  if (self) {
    mAllocatedObjectCountByClass = [NSCountedSet new] ;
    mTotalAllocatedObjectCountByClass = [NSCountedSet new] ;
    mLock = [NSLock new] ;
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector (applicationWillTerminateAction:)
      name:NSApplicationWillTerminateNotification
      object:nil
    ] ;
  }
  return self ;
}

//-----------------------------------------------------------------------------*
//    awakeFromNib                                                             *
//-----------------------------------------------------------------------------*

- (void) awakeFromNib {
  // NSLog (@"%s %p %p", __PRETTY_FUNCTION__, self, mDebugMenu) ;
//--- Allocation Window visibility
  self.mAllocationStatsWindowVisibleAtLaunch = [[NSUserDefaults standardUserDefaults]
    boolForKey:@"PMDebug:allocationStatsWindowVisible"
  ] ;
  self.mDisplayFilter = [[NSUserDefaults standardUserDefaults]
    integerForKey:@"PMDebug:allocationStatsDisplayFilter"
  ] ;
//--- Allocation stats window visibility at Launch
  if (self.mAllocationStatsWindowVisibleAtLaunch) {
    [mAllocationStatsWindow makeKeyAndOrderFront:nil] ;
  }
//--- Bindings
  [mAllocationStatsWindowVisibleAtLaunchCheckbox
    bind:@"value"
    toObject:self
    withKeyPath:@"mAllocationStatsWindowVisibleAtLaunch"
    options:nil
  ] ;
  [mCurrentlyAllocatedObjectCountTextField
    bind:@"value"
    toObject:self
    withKeyPath:@"mAllocatedObjectCount"
    options:nil
  ] ;
  [mTotalAllocatedObjectCountTextField
    bind:@"value"
    toObject:self
    withKeyPath:@"mTotalAllocatedObjectCount"
    options:nil
  ] ;
  [mDisplayFilterPopUpButton
    bind:@"selectedIndex"
    toObject:self
    withKeyPath:@"mDisplayFilter"
    options:nil
  ] ;
  #if ! __has_feature(objc_arc)
    mCollectExhaustivelyButton.target = self ;
    mCollectExhaustivelyButton.action = @selector (collectExhaustively:) ;
  #else
    mCollectExhaustivelyButton.hidden = YES ;
  #endif
}

//-----------------------------------------------------------------------------*
//    applicationWillTerminateAction:                                          *
//-----------------------------------------------------------------------------*

- (void) applicationWillTerminateAction: (NSNotification *) inNotification {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  // NSLog (@"%d", self.mAllocationStatsWindowVisibleAtLaunch) ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud
    setBool:self.mAllocationStatsWindowVisibleAtLaunch
    forKey:@"PMDebug:allocationStatsWindowVisible"
  ] ;
  [ud
    setInteger:self.mDisplayFilter
    forKey:@"PMDebug:allocationStatsDisplayFilter"
  ] ;
}

//-----------------------------------------------------------------------------*
//    triggerRefreshAllocationStatsDisplay                                     *
//-----------------------------------------------------------------------------*

- (void) triggerRefreshAllocationStatsDisplay {
  [mLock lock] ;
    const BOOL refreshStatsHasBeenTriggered = mRefreshStatsHasBeenTriggered ;
    mRefreshStatsHasBeenTriggered = YES ;
  [mLock unlock] ;
  if (! refreshStatsHasBeenTriggered) {
    [[NSRunLoop mainRunLoop]
      performSelector:@selector (refreshAllocationStats)
      target:self
      argument:nil
      order:NSUIntegerMax
      modes:[NSArray arrayWithObject:NSRunLoopCommonModes]
    ] ;
    #if ! __has_feature(objc_arc)
      mRefreshTimer = [NSTimer
        timerWithTimeInterval:1.0
        target:self
        selector:@selector (refreshTimerDidFire:)
        userInfo:nil
        repeats:NO
      ] ;
      [[NSRunLoop mainRunLoop]
        addTimer:mRefreshTimer
        forMode:NSRunLoopCommonModes
      ] ;
    #endif
  }
}

//-----------------------------------------------------------------------------*
//    refreshAllocationStats                                                  *
//-----------------------------------------------------------------------------*

- (void) refreshAllocationStats {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  [mLock lock] ;
    mRefreshStatsHasBeenTriggered = NO ;
  //---
    self.mAllocatedObjectCount = mLiveAllocatedObjectCount ;
    self.mTotalAllocatedObjectCount = mLiveTotalObjectCount ;
  //---
    NSMutableArray * array = [NSMutableArray new] ;
    for (NSString * className in [mTotalAllocatedObjectCountByClass.allObjects sortedArrayUsingSelector:@selector(compare:)]) {
      const NSUInteger currentlyAllocated = [mAllocatedObjectCountByClass countForObject:className] ;
      if ((currentlyAllocated != 0) || (self.mDisplayFilter == 0)) {
        [array addObject: [NSDictionary
          dictionaryWithObjectsAndKeys:
            className, @"classname",
            [NSNumber numberWithUnsignedInteger:[mTotalAllocatedObjectCountByClass countForObject:className]], @"allCount",
            [NSNumber numberWithUnsignedInteger:currentlyAllocated], @"live",
            nil
          ]
        ] ;
      }
    }
  [mLock unlock] ;
//---
  mAllocationStatsDataSource = array ;
  [mStatsTableView setDataSource:self] ;
  [mStatsTableView reloadData] ;
}

//-----------------------------------------------------------------------------*
//    refreshTimerDidFire:                                                     *
//-----------------------------------------------------------------------------*

#if ! __has_feature(objc_arc)
  - (void) refreshTimerDidFire: (NSTimer *) inTimer {
    mRefreshTimer = nil ;
    [[NSGarbageCollector defaultCollector] collectExhaustively] ;
  }
#endif

//-----------------------------------------------------------------------------*
//    collectExhaustively:                                                     *
//-----------------------------------------------------------------------------*

#if ! __has_feature(objc_arc)
  - (void) collectExhaustively: (id) inSender {
    [[NSGarbageCollector defaultCollector] collectExhaustively] ;
  }
#endif

//-----------------------------------------------------------------------------*
//    didChangeValueForKey:                                                    *
//-----------------------------------------------------------------------------*

- (void) didChangeValueForKey: (NSString *) inKey {
  [super didChangeValueForKey:inKey] ;
  if ([inKey isEqualToString:@"mDisplayFilter"]) {
    [self triggerRefreshAllocationStatsDisplay] ;
  }
}

//-----------------------------------------------------------------------------*
//    pmNoteObjectAllocation:                                                  *
//-----------------------------------------------------------------------------*

- (void) pmNoteObjectAllocation: (NSObject *) inObject {
  [mLock lock] ;
    mLiveAllocatedObjectCount ++ ;
    mLiveTotalObjectCount ++ ;
    NSString * objectClassName = inObject.className ;
    [mAllocatedObjectCountByClass addObject:objectClassName] ;
    [mTotalAllocatedObjectCountByClass addObject:objectClassName] ;
  [mLock unlock] ;
  [self triggerRefreshAllocationStatsDisplay] ;
}

//-----------------------------------------------------------------------------*
//    pmNoteObjectDeallocation:                                                *
//-----------------------------------------------------------------------------*

- (void) pmNoteObjectDeallocation: (NSObject *) inObject {
  [mLock lock] ;
    mLiveAllocatedObjectCount -- ;
    NSString * objectClassName = inObject.className ;
    [mAllocatedObjectCountByClass removeObject:objectClassName] ;
  [mLock unlock] ;
  [self triggerRefreshAllocationStatsDisplay] ;
}

//-----------------------------------------------------------------------------*
//    T A B L E   V I E W    D A T A    S O U R C E                            *
//-----------------------------------------------------------------------------*

- (id) tableView: (NSTableView *) aTableView
       objectValueForTableColumn: (NSTableColumn *) aTableColumn
       row: (NSInteger) rowIndex {
  NSDictionary * theRecord = [mAllocationStatsDataSource objectAtIndex:(NSUInteger) rowIndex];
  return [theRecord valueForKey:aTableColumn.identifier] ;
}

//-----------------------------------------------------------------------------*

- (NSInteger) numberOfRowsInTableView: (NSTableView *) aTableView {
  return (NSInteger) [mAllocationStatsDataSource count] ;
}

//-----------------------------------------------------------------------------*

@end


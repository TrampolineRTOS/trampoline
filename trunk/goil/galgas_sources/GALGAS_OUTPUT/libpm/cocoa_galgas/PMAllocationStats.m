//---------------------------------------------------------------------------*
//                                                                           *
//      A L L O C A T I O N    S T A T S                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#import "PMAllocationStats.h"

//---------------------------------------------------------------------------*

static NSMutableDictionary * gCurrentInstancesDictionary ;
static NSMutableDictionary * gCreatedInstancesDictionary ;
static PMAllocationStats * gEBAllocationStats ;
static BOOL gPerformAllocationStats ;

//---------------------------------------------------------------------------*

#ifdef PM_DEBUG_ALLOC
  void objectHasBeenAllocated (Class inDymanicObjectClass, Class inStaticClass) {
    if (gPerformAllocationStats && (inDymanicObjectClass == inStaticClass)) {
      [gEBAllocationStats marksForRedisplay] ;
      NSString * s = [inDymanicObjectClass className] ;
      if (gCurrentInstancesDictionary == nil) {
        gCurrentInstancesDictionary = [NSMutableDictionary dictionaryWithCapacity:100] ;
        [gCurrentInstancesDictionary retain] ;
      }
      NSNumber * n = [gCurrentInstancesDictionary objectForKey:s] ;
      NSNumber * newValue = [NSNumber numberWithInt: [n intValue] + 1] ;
      [gCurrentInstancesDictionary setObject:newValue forKey:s] ;
      if (gCreatedInstancesDictionary == nil) {
        gCreatedInstancesDictionary = [NSMutableDictionary dictionaryWithCapacity:100] ;
        [gCreatedInstancesDictionary retain] ;
      }
      n = [gCreatedInstancesDictionary objectForKey:s] ;
      newValue = [NSNumber numberWithInt: [n intValue] + 1] ;
      [gCreatedInstancesDictionary setObject:newValue forKey:s] ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PM_DEBUG_ALLOC
  void objectWillBeDeallocated (Class inDymanicObjectClass, Class inStaticClass) {
    if (gPerformAllocationStats && (inDymanicObjectClass == inStaticClass)) {
      [gEBAllocationStats marksForRedisplay] ;
      NSString * s = [inDymanicObjectClass className] ;
      NSNumber * n = [gCurrentInstancesDictionary objectForKey:s] ;
      NSNumber * newValue = [NSNumber numberWithInt: [n intValue] - 1] ;
      [gCurrentInstancesDictionary setObject:newValue forKey:s] ;
    }
  }
#endif

//---------------------------------------------------------------------------*

@implementation PMAllocationStats

//---------------------------------------------------------------------------*
//                                                                           *
//           I N I T                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mNeedsRedisplay = NO ;
    gEBAllocationStats = self ;
    NSUserDefaultsController * sudc = [NSUserDefaultsController sharedUserDefaultsController] ;
    gPerformAllocationStats = [[[sudc values] valueForKey:@"performAllocationStats"] boolValue] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//           A W A K E    F R O M    N I B                                   *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) awakeFromNib {
//--- Set 'mShowOnlyCurrentlyAllocatedObjectsCheckBox' target and action
  [mShowOnlyCurrentlyAllocatedObjectsCheckBox setTarget:self] ;
  [mShowOnlyCurrentlyAllocatedObjectsCheckBox setAction:@selector (upDateAllocationStats:)] ;
//--- Bind 'mShowOnlyCurrentlyAllocatedObjectsCheckBox' value
  NSUserDefaultsController * sudc = [NSUserDefaultsController sharedUserDefaultsController] ;
  [mShowOnlyCurrentlyAllocatedObjectsCheckBox bind:@"value" toObject:sudc withKeyPath:@"values.showOnlyCurrentlyAllocatedObjects" options:nil] ;
  [mVisibleAtLauchTimeCheckBox bind:@"value" toObject:sudc withKeyPath:@"values.visibleAtLauchTime" options:nil] ;
//--- Bind 'mPerformAllocationStats' value
  [mPerformAllocationStats bind:@"value" toObject:sudc withKeyPath:@"values.performAllocationStats" options:nil] ;
//--- Set up settings
  const BOOL visibleAtLauchTime = [[[sudc values] valueForKey:@"visibleAtLauchTime"] boolValue] ;
  if (visibleAtLauchTime) {
    [[mStatsTableView window] makeKeyAndOrderFront:nil] ;
  }
  
}

//---------------------------------------------------------------------------*
//                                                                           *
//           A W A K E    F R O M    N I B                                   *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) marksForRedisplay {
  if (! mNeedsRedisplay) {
    mNeedsRedisplay = YES ;
    [[NSRunLoop currentRunLoop]
      performSelector: @selector (upDateAllocationStats:)
      target:self
      argument:nil
      order:0
      modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
    ] ;
  }
}

//---------------------------------------------------------------------------*

- (void) upDateAllocationStats: (id) inSender {
  NSUserDefaultsController * sudc = [NSUserDefaultsController sharedUserDefaultsController] ;
  mNeedsRedisplay = NO ;
  const BOOL onlyAllocated = [[[sudc values] valueForKey:@"showOnlyCurrentlyAllocatedObjects"] boolValue] ;
  NSArray * a = [gCreatedInstancesDictionary allKeys] ;
  NSMutableArray * dataSource = [NSMutableArray arrayWithCapacity: [a count]] ;
  unsigned i ;
  int currentCount = 0 ;
  int totalCount = 0 ;
  for (i=0 ; i<[a count] ; i++) {
    NSString * className = [a objectAtIndex:i] ;
    const int n = [[gCurrentInstancesDictionary objectForKey:className] intValue] ;
    totalCount += [[gCreatedInstancesDictionary objectForKey:className] intValue] ;
    if ((! onlyAllocated) || (n != 0)) {
      currentCount += n ;
      NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
        className, @"classname",
        [gCurrentInstancesDictionary objectForKey:className], @"current",
        [gCreatedInstancesDictionary objectForKey:className], @"alloccount",
        nil
      ] ;
      [dataSource addObject:d] ;
    }
  }
//--- Sort by name
  NSSortDescriptor * sort = [NSSortDescriptor alloc] ;
  [sort initWithKey:@"classname" ascending:YES] ;
  [dataSource sortUsingDescriptors:[NSArray arrayWithObject:sort]] ;
  [sort release] ;
//--- Store Data source
  [dataSource retain] ;
  [mAllocationStatsDataSource release] ;
  mAllocationStatsDataSource = dataSource ;
  [mStatsTableView reloadData] ;
  [mCurrentlyAllocatedCount setStringValue:[NSString stringWithFormat:@"%d currently allocated object%s", currentCount, (currentCount>1) ? "s" : ""]] ;
  [mTotalAllocatedCount setStringValue:[NSString stringWithFormat:@"%d object%s been allocated",
                        totalCount, (totalCount>1) ? "s have" : " has"]] ;
  [mStatsTableView setDataSource:self] ;
}

//---------------------------------------------------------------------------*

- (id) tableView: (NSTableView *) aTableView
       objectValueForTableColumn: (NSTableColumn *) aTableColumn
       row: (int) rowIndex {
  NSDictionary * theRecord = [mAllocationStatsDataSource objectAtIndex:rowIndex];
  return [theRecord objectForKey:[aTableColumn identifier]] ;
}

//---------------------------------------------------------------------------*

- (int) numberOfRowsInTableView: (NSTableView *) aTableView {
  return [mAllocationStatsDataSource count] ;
}

//---------------------------------------------------------------------------*

@end

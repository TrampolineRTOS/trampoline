//-----------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------*

#if __has_feature(objc_arc)
  #define macroAutoreleasingInARC __autoreleasing
#else
  #define macroAutoreleasingInARC
#endif

//-----------------------------------------------------------------------------*

void showAllocationStatsWindow (void) ;
void noteObjectAllocation (NSObject * inObject) ;
void noteObjectDeallocation (NSObject * inObject) ;

//-----------------------------------------------------------------------------*

@interface PMDebug : NSObject
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
  <NSTableViewDataSource>
#endif  
{
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

@property PROPERTY_ATOMIC BOOL mAllocationStatsWindowVisibleAtLaunch ;
@property PROPERTY_ATOMIC NSUInteger mAllocatedObjectCount ;
@property PROPERTY_ATOMIC NSUInteger mTotalAllocatedObjectCount ;
@property PROPERTY_ATOMIC NSInteger mDisplayFilter ;

- (void) pmNoteObjectAllocation: (NSObject *) inObject ;
- (void) pmNoteObjectDeallocation: (NSObject *) inObject ;
- (void) showAllocationWindow ;
@end

//-----------------------------------------------------------------------------*

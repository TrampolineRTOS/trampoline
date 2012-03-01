//---------------------------------------------------------------------------*
//                                                                           *
//      A L L O C A T I O N    S T A T S                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//---------------------------------------------------------------------------*

#ifdef PM_DEBUG_ALLOC
  #ifdef __cplusplus
    extern "C" {
  #endif
  void objectHasBeenAllocated (Class inDymanicObjectClass, Class inStaticClass) ;
  void objectWillBeDeallocated (Class inDymanicObjectClass, Class inStaticClass) ;
  #ifdef __cplusplus
    }
  #endif
#endif

//---------------------------------------------------------------------------*

@interface PMAllocationStats : NSObject {
  @private IBOutlet NSTableView * mStatsTableView ;
  @private IBOutlet NSButton * mShowOnlyCurrentlyAllocatedObjectsCheckBox ;
  @private IBOutlet NSButton * mVisibleAtLauchTimeCheckBox ;
  @private IBOutlet NSButton * mPerformAllocationStats ;
  @private IBOutlet NSTextField * mCurrentlyAllocatedCount ;
  @private IBOutlet NSTextField * mTotalAllocatedCount ;
  @private NSMutableArray * mAllocationStatsDataSource ;
  @private BOOL mNeedsRedisplay ;
}

- (IBAction) upDateAllocationStats: (id) inSender ;
- (void) marksForRedisplay ;

@end

//---------------------------------------------------------------------------*

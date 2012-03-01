#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@interface NSArrayController (PMArrayControllerDebugCategory)

- (void) addObject: (id) inObject LOCATION_ARGS ;

- (void) removeObject: (id) inObject LOCATION_ARGS ;

@end

//---------------------------------------------------------------------------*

#endif

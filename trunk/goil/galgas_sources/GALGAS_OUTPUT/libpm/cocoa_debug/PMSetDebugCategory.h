#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@interface NSSet (PMSetDebugCategory)

- (NSEnumerator *) objectEnumerator COLON_LOCATION_ARGS ;

@end

//---------------------------------------------------------------------------*

#endif

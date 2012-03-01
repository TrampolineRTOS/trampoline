#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@interface NSMutableDictionary (PMMutableDictionaryDebugCategory)

- (void) removeAllObjects COLON_LOCATION_ARGS ;

@end

//---------------------------------------------------------------------------*

#endif

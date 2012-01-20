#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@interface NSMutableString (PMMutableStringDebugCategory)

- (void) appendString: (NSString *) inString LOCATION_ARGS ;

@end

//---------------------------------------------------------------------------*

#endif

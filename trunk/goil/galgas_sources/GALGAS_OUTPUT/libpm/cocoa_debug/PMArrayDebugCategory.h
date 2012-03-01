#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@interface NSArray (PMArrayDebugCategory)

+ (id) arrayWithObject: (id) anObject LOCATION_ARGS ;

- (id) objectAtIndex: (NSUInteger) inIndex LOCATION_ARGS ;

- (id) objectAtIndex: (NSUInteger) inIndex LOCATION_ARGS OF_CLASS_ARG ;

- (id) lastObject COLON_LOCATION_ARGS ;

- (id) lastObject COLON_LOCATION_ARGS OF_CLASS_ARG ;

- (NSEnumerator *) objectEnumerator COLON_LOCATION_ARGS ;

@end

//---------------------------------------------------------------------------*

#endif

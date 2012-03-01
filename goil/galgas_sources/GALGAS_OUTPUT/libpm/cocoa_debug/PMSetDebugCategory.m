#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSSet (PMSetDebugCategory)

//---------------------------------------------------------------------------*

//--- Define DEBUG_ENUMERATORS (in PMCocoaCallsDebug.h), in order to detect
//    "Collection ... was mutated while being enumerated" exception
- (NSEnumerator *) objectEnumerator COLON_LOCATION_ARGS {
  #ifdef DEBUG_ENUMERATORS
    NSLog (@"%p <objectEnumerator> in:%s:%d", self, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  #endif
  return [self objectEnumerator] ; // DO NOT ADD COLON_HERE !!!
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

#endif

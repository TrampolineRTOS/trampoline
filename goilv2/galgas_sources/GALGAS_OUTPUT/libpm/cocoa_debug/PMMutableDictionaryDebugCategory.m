#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSMutableDictionary (PMMutableDictionaryDebugCategory)

//---------------------------------------------------------------------------*

- (void) removeAllObjects COLON_LOCATION_ARGS {
  if (! [self isKindOfClass:[NSMutableDictionary class]]) {
    NSLog (@"removeAllObjects: receiver is not an instance of NSMutableDictionary in source file:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  [self removeAllObjects] ;
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

#endif

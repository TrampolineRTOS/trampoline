#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSMutableString (PMMutableStringDebugCategory)

//---------------------------------------------------------------------------*

- (void) appendString: (NSString *) inString LOCATION_ARGS {
  if (inString == nil) {
    NSLog (@"appendString: argument is nil in:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  [self appendString:inString] ; // DO NOT ADD 'HERE' !!!
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

#endif

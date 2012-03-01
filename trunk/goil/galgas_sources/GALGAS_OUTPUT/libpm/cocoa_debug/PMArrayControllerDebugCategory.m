#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSArrayController (PMArrayControllerDebugCategory)

//---------------------------------------------------------------------------*

- (void) addObject: (id) inObject LOCATION_ARGS {
  if (! [self isKindOfClass:[NSArrayController class]]) {
    NSLog (@"addObject: receiver is not an instance of NSArrayController in sourceFile:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }else if (inObject == nil) {
    NSLog (@"in '%s' file at line %d, attempt to insert nil", IN_SOURCE_FILE, IN_SOURCE_LINE) ;  
  }
  [self addObject:inObject] ;
}

//---------------------------------------------------------------------------*

- (void) removeObject: (id) inObject LOCATION_ARGS {
  if (! [self isKindOfClass:[NSArrayController class]]) {
    NSLog (@"removeObject: receiver is not an instance of NSArrayController in source file:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }else if (inObject == nil) {
    NSLog (@"removeObject: argument is nil in source file:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  [self removeObject:inObject] ;
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

#endif

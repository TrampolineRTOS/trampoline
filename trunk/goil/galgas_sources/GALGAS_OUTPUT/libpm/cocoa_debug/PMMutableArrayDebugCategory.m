#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSMutableArray (PMMutableArrayDebugCategory)

//---------------------------------------------------------------------------*

- (void) addObject: (id) inObject LOCATION_ARGS {
  if (! [self isKindOfClass:[NSMutableArray class]]) {
    NSLog (@"addObject: receiver is not an instance of NSMutableArray in sourceFile:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }else if (inObject == nil) {
    NSLog (@"in '%s' file at line %d, attempt to insert nil", IN_SOURCE_FILE, IN_SOURCE_LINE) ;  
  }
  [self addObject:inObject] ;
}

//---------------------------------------------------------------------------*

- (void) removeAllObjects COLON_LOCATION_ARGS {
  if (! [self isKindOfClass:[NSMutableArray class]]) {
    NSLog (@"removeAllObjects: receiver is not an instance of NSMutableArray in source file:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  [self removeAllObjects] ;
}

//---------------------------------------------------------------------------*

- (void) removeObject: (id) inObject LOCATION_ARGS {
  if (! [self isKindOfClass:[NSMutableArray class]]) {
    NSLog (@"removeObject: receiver is not an instance of NSMutableArray in source file:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }else if (inObject == nil) {
    NSLog (@"removeObject: argument is nil in source file:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  [self removeObject:inObject] ;
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

#endif

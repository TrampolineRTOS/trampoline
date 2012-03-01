#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSArray (PMArrayDebugCategory)

//---------------------------------------------------------------------------*

+ (id) arrayWithObject: (id) anObject LOCATION_ARGS {
  if (nil == anObject) {
    NSLog (@"arrayWithObject: argument is nil in:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return [NSArray arrayWithObject:anObject] ; // DO NOT ADD HERE !!!
}

//---------------------------------------------------------------------------*

- (id) objectAtIndex: (NSUInteger) inIndex LOCATION_ARGS {
  if (! [self isKindOfClass:[NSArray class]]) {
    NSLog (@"objectAtIndex: receiver is not an instance of NSArray in:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }else if (inIndex >= [self count]) {
    NSLog (@"objectAtIndex: index (%lu) >= object count (%lu) in:%s:%d", (unsigned long) inIndex, (unsigned long) self.count, IN_SOURCE_FILE, IN_SOURCE_LINE) ;  
  }
  return [self objectAtIndex:inIndex] ;
}

//---------------------------------------------------------------------------*

- (id) objectAtIndex: (NSUInteger) inIndex LOCATION_ARGS OF_CLASS_ARG {
  id result = [self objectAtIndex:inIndex THERE] ;
  if (! [result isKindOfClass:inClass]) {
    NSLog (@"objectAtIndex: receiver is an instance of %@ class (instead of %@ class) in:%s:%d",
          [[result class] className], [inClass className], IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (id) lastObject COLON_LOCATION_ARGS {
  if (! [self isKindOfClass:[NSArray class]]) {
    NSLog (@"<lastObject>: receiver is not an instance of NSArray in:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return [self lastObject] ;
}

//---------------------------------------------------------------------------*

- (id) lastObject COLON_LOCATION_ARGS OF_CLASS_ARG {
  if (! [self isKindOfClass:[NSArray class]]) {
    NSLog (@"<lastObject>: receiver is not an instance of NSArray in:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  id result = [self lastObject] ;
  if (! [result isKindOfClass:inClass]) {
    NSLog (@"<lastObject>: receiver is an instance of %@ class (instead of %@ class) in:%s:%d",
          [[result class] className], [inClass className], IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return result ;
}

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

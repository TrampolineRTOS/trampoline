//
//  PMPointerArrayDebugCategory.m
//  canari
//
//  Created by Pierre MOLINARO on 23/11/07.
//  Copyright 2007 __MyCompanyName__. All rights reserved.
//
#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG
  #if MAC_OS_X_VERSION_10_5 <= MAC_OS_X_VERSION_MAX_ALLOWED

//---------------------------------------------------------------------------*

@implementation NSPointerArray (PMPointerArrayDebugCategory)

//---------------------------------------------------------------------------*

- (void *) pointerAtIndex: (NSUInteger) inIndex LOCATION_ARGS {
  if (! [self isKindOfClass:[NSPointerArray class]]) {
    NSLog (@"pointerAtIndex: receiver is not an instance of NSPointerArray in:%s:%d", IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }else if (inIndex >= [self count]) {
    NSLog (@"pointerAtIndex: index (%lu) >= object count (%lu) in:%s:%d", (unsigned long) inIndex, (unsigned long) self.count, IN_SOURCE_FILE, IN_SOURCE_LINE) ;  
  }
  return [self pointerAtIndex:inIndex] ;
}

//---------------------------------------------------------------------------*

- (void *) pointerAtIndex: (NSUInteger) inIndex LOCATION_ARGS OF_CLASS_ARG {
  id result = [self pointerAtIndex:inIndex THERE] ;
  if (! [result isKindOfClass:inClass]) {
    NSLog (@"pointerAtIndex: receiver is an instance of %@ class (instead of %@ class) in:%s:%d",
          [[result class] className], [inClass className], IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

#endif
#endif

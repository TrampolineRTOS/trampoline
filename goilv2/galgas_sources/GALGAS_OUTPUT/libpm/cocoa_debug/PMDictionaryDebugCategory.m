//
//  PMDictionaryDebugCategory.m
//  canari
//
//  Created by Pierre Molinaro on 14/07/06.
//  Copyright 2006 Pierre Molinaro. All rights reserved.
//

#import "PMDictionaryDebugCategory.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@implementation NSDictionary (PMDictionaryDebugCategory)

//---------------------------------------------------------------------------*

- (id) objectForKey: (id) inKey LOCATION_ARGS {
  if (inKey == nil) {
    NSLog (@"NSDictionary <objectForKey:>: inKey is nil at:%s:%d",
           IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return [self objectForKey:inKey] ;
}

//---------------------------------------------------------------------------*

- (id) objectForKey: (id) inKey LOCATION_ARGS   OF_CLASS_ARG {
  id result = [self objectForKey:inKey THERE] ;
  if ((result != nil) && ! [result isKindOfClass:inClass]) {
    NSLog (@"NSDictionary <objectForKey:>: result is an instance of %@ instead of %@ at:%s:%d",
           [result className], [inClass className],
           IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

//--- Define DEBUG_ENUMERATORS (in PMCocoaCallsDebug.h), in order to detect
//    "Collection ... was mutated while being enumerated" exception
- (NSEnumerator *) keyEnumerator COLON_LOCATION_ARGS {
  #ifdef DEBUG_ENUMERATORS
    NSLog (@"%p <keyEnumerator> in:%s:%d", self, IN_SOURCE_FILE, IN_SOURCE_LINE) ;
  #endif
  return [self keyEnumerator] ; // DO NOT ADD COLON_HERE !!!
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

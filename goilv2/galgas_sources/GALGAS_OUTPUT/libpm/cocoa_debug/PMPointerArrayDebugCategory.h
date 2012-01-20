//
//  PMPointerArrayDebugCategory.h
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

    @interface NSPointerArray (PMPointerArrayDebugCategory)

    - (void *) pointerAtIndex: (NSUInteger) inIndex LOCATION_ARGS ;

    - (void *) pointerAtIndex: (NSUInteger) inIndex LOCATION_ARGS OF_CLASS_ARG ;

    @end

    //---------------------------------------------------------------------------*

  #endif
#endif

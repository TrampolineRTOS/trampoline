//
//  PMDictionaryDebugCategory.h
//  canari
//
//  Created by Pierre Molinaro on 14/07/06.
//  Copyright 2006 Pierre Molinaro. All rights reserved.
//

#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

#ifdef PM_COCOA_DEBUG

//---------------------------------------------------------------------------*

@interface NSDictionary (PMDictionaryDebugCategory)

- (id) objectForKey: (id) inKey LOCATION_ARGS ;

- (id) objectForKey: (id) inKey LOCATION_ARGS   OF_CLASS_ARG ;

- (NSEnumerator *) keyEnumerator COLON_LOCATION_ARGS ;

- (NSEnumerator *) objectEnumerator COLON_LOCATION_ARGS ;

@end

//---------------------------------------------------------------------------*

#endif

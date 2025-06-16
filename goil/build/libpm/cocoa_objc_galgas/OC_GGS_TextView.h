//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2020 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#import <AppKit/AppKit.h>

//--------------------------------------------------------------------------------------------------

@class OC_GGS_TextDisplayDescriptor ;
@class OC_GGS_Document ;

//--------------------------------------------------------------------------------------------------

@interface OC_GGS_TextView : NSTextView {
   @private OC_GGS_Document * mDocumentUsedForDisplaying ;
   @private OC_GGS_TextDisplayDescriptor * mDisplayDescriptor ;
   @private NSArray * mIssueArray ; // Of PMIssueDescriptor
}

- (id) initWithFrame:(NSRect)frameRect
       documentUsedForDisplaying: (OC_GGS_Document *) inDocumentUsedForDisplaying
       displayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor ;

- (void) detachTextView ;

- (void) setIssueArray: (NSArray *) inIssueArray ;

- (void) indexingMenuAction: (id) inSender ;

- (void) selectAllTokenCharacters: (id) inSender  ;
@end

//--------------------------------------------------------------------------------------------------

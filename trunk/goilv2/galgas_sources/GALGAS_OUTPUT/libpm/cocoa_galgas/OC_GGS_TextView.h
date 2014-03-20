//
//  OC_GGS_TextView.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#import <AppKit/AppKit.h>

//-----------------------------------------------------------------------------*

@class OC_GGS_TextDisplayDescriptor ;
@class OC_GGS_Document ;

//-----------------------------------------------------------------------------*

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
@end

//-----------------------------------------------------------------------------*

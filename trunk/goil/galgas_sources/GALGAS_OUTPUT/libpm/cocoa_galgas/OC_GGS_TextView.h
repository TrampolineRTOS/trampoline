//
//  OC_GGS_TextView.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 27/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <AppKit/AppKit.h>

//---------------------------------------------------------------------------*

@class OC_GGS_TextDisplayDescriptor ;

//---------------------------------------------------------------------------*

@interface OC_GGS_TextView : NSTextView {
  @private NSArray * mIssueArray ;
  @private __weak OC_GGS_TextDisplayDescriptor * mDisplayDescriptor ;
}

- (void) setDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor ;

- (void) setIssueArray: (NSArray *) inIssueArray ;

- (NSArray *) issueArray ;

@end

//---------------------------------------------------------------------------*

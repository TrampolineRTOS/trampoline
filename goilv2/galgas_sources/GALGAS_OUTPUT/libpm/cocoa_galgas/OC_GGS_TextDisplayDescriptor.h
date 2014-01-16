//
//  OC_GGS_TextDisplayDescriptor.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 24/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import <Foundation/Foundation.h>

//---------------------------------------------------------------------------*

@class OC_GGS_TextSyntaxColoring ;
@class OC_GGS_DocumentData ;
@class OC_GGS_Document ;
@class OC_GGS_TextView ;
@class PMIssueDescriptor ;
@class OC_GGS_RulerViewForTextView ;

//---------------------------------------------------------------------------*

@interface OC_GGS_TextDisplayDescriptor : NSObject <NSTextViewDelegate, NSPortDelegate> {

  @private OC_GGS_TextView * mTextView ;
  @private NSPopUpButton * mEntryListPopUpButton ;
  @private OC_GGS_RulerViewForTextView * mRulerView ;
  @private NSScrollView * mScrollView ;
  @private NSView * mEnclosingView ;
  @private NSUInteger mTextSelectionStart ;
  @private OC_GGS_Document * mDocumentUsedForDisplaying ;
}

@property (assign, readonly PROPERTY_COMMA_ATOMIC) OC_GGS_DocumentData * documentData ;
@property PROPERTY_ATOMIC BOOL isDirty ;

- (OC_GGS_TextDisplayDescriptor *) initWithDocumentData: (OC_GGS_DocumentData *) inDocumentData
                                   displayDocument: (OC_GGS_Document *) inDocumentUsedForDisplaying ;

- (void) detachTextDisplayDescriptor ;

- (NSImage *) imageForClosingInUserInterface ;

- (NSURL *) sourceURL ;

- (NSString *) title ;

- (NSTextView *) textView ;

- (NSView *) enclosingView ;

- (NSUInteger) textSelectionStart ;

- (void) gotoLine: (NSUInteger) inLine ;

- (void) selectEntryPopUp ;

- (void) populatePopUpButtonWithMenu: (NSMenu *) inMenu ;

- (void) commentSelection ;
- (void) uncommentSelection ;
- (void) shiftLeftAction ;
- (void) shiftRightAction ;

- (void) setTextDisplayIssueArray: (NSArray *) inIssueArray ; 

- (void) setSelectionRangeAndMakeItVisible: (NSRange) inRange ;

- (void) actionInsertTextMacro: (NSMenuItem *) inSender ;

@end

//---------------------------------------------------------------------------*

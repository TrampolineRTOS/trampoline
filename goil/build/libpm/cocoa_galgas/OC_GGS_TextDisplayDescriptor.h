//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#import "CocoaGalgasPrefix.h"

//----------------------------------------------------------------------------------------------------------------------

@class OC_GGS_TextSyntaxColoring ;
@class OC_GGS_DocumentData ;
@class OC_GGS_Document ;
@class OC_GGS_TextView ;
@class PMIssueDescriptor ;
@class OC_GGS_RulerViewForTextView ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

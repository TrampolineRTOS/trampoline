//
//  OC_GGS_HiddenDocument.h
//  galgas
//
//  Created by Pierre Molinaro on 11/07/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//---------------------------------------------------------------------------*

@class OC_GGS_Document ;
@class OC_GGS_TextView ;
@class OC_GGS_DelegateForSyntaxColoring ;
@class OC_Lexique ;

//---------------------------------------------------------------------------*

@interface OC_GGS_HiddenDocument : NSObject {
  @private OC_GGS_Document * mActualDocument ;
  @private NSURL * mDocumentURLForNonOpenedDocument ; // Is nil if mActualDocument != nil
  @private OC_GGS_DelegateForSyntaxColoring * mDelegateForSyntaxColoring ;
  @private OC_Lexique * mTokenizer ;
  @private NSUndoManager * mUndoManager ;
  @private NSTextStorage * mTextStorage ;
}

- (OC_GGS_Document *) actualDocument ;

- (OC_Lexique *) tokenizer ;

- (void) setDocument: (OC_GGS_Document *) inDocument ;

- (NSTextStorage *) textStorage ;
@end

//---------------------------------------------------------------------------*

void associateDocumentWithURL (OC_GGS_Document * inDocument, NSURL * inDocumentURL) ;

void associateTextViewWithURL (OC_GGS_TextView * inTextView, NSURL * inDocumentURL) ;

void saveActualDocumentToURL (OC_GGS_Document * inDocument, NSURL * inDocumentURL) ;

void noteDocumentWillClose (OC_GGS_Document * inDocument) ;

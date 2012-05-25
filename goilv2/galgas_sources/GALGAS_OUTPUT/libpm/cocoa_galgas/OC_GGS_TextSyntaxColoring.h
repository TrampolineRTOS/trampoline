//
//  OC_GGS_TextSyntaxColoring.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 24/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OC_GGS_TextDisplayDescriptor ;
@class OC_Lexique ;
@class OC_GGS_Document ;

@interface OC_GGS_TextSyntaxColoring : NSObject {
  @private NSTextStorage * mSourceTextStorage ;
  @private NSMutableSet * mTextDisplayDescriptorSet ; // Set of OC_GGS_TextDisplayDescriptor
  @private OC_Lexique * mTokenizer ;
  @private OC_GGS_Document * mDocument ;
  @private BOOL mIsDirty ;
  @private NSArray * mIssueArray ;

  @private double mMaxAscender ; // Only mMaxAscender is observable
  @private double mMaxLeadingMinusDescender ; // leading - descender (because descender is < 0)

  @private NSUInteger mSavePointUndoStackCount ;
  
//--- Undo manager
  @private NSUndoManager * mUndoManager ;
  
//--- Attributes for syntax coloring
  @private NSMutableArray * mTokenArray ;
  @private NSMutableArray * mFontAttributesDictionaryArray ; // Array of OC_Token
  @private NSMutableDictionary * mTemplateTextAttributeDictionary ;
}

- (OC_GGS_TextSyntaxColoring *) initWithSourceString: (NSString *) inSource
                                tokenizer: (OC_Lexique *) inTokenizer
                                document: (OC_GGS_Document *) inDocument
                                issueArray: (NSArray *) inIssueArray ;

- (NSTextStorage *) textStorage ;
- (NSUndoManager *) undoManager ;
- (OC_Lexique *) tokenizer ;
- (OC_GGS_Document *) document ;
- (NSUInteger) textDisplayDescriptorCount ;
- (NSRange) rangeForLine: (NSInteger) inLineNumber ;

- (NSArray *) buildIndexingDictionaryArray ;

- (NSArray *) tokenArray ;
- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex ;

- (BOOL) isDirty ;

- (NSString *) sourceString ;
- (void) replaceSourceStringWithString: (NSString *) inString ;

- (void) updateSyntaxColoringForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (NSMenu *) menuForEntryPopUpButton ;

- (void) breakUndoCoalescing ;

- (NSRange) uncommentRange: (NSRange) initialSelectedRange ;
- (NSRange) commentRange: (NSRange) initialSelectedRange ;

- (void) documentHasBeenSaved ;

- (NSMenu *) indexMenuForRange: (NSRange) inSelectedRange
             textDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor ;
@end

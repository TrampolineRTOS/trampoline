//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#import "CocoaGalgasPrefix.h"

@class OC_GGS_TextDisplayDescriptor ;
@class OC_Lexique ;
@class OC_GGS_DocumentData ;
@class PMUndoManager ;


@interface OC_GGS_TextSyntaxColoring : NSObject {
  @private NSMutableSet * mTextDisplayDescriptorSet ; // Of OC_GGS_TextDisplayDescriptor
  @private NSTextStorage * mSourceTextStorage ;
  @private OC_Lexique * mTokenizer ;
  @private NSMutableArray * mIssueArray ; // Of PMIssueDescriptor
  

  @private double mMaxAscender ; // Only mMaxAscender is observable
  @private double mMaxLeadingMinusDescender ; // leading - descender (because descender is < 0)

  @private NSUInteger mSavePointUndoStackCount ;
  @private NSUInteger mSavePointRedoStackCount ;
  
//--- Undo manager
  @private PMUndoManager * mUndoManager ;
  
//--- Attributes for syntax coloring
  @private NSMutableArray * mTokenArray ; // Array of OC_Token
  @private NSMutableArray * mFontAttributesDictionaryArray ; // Array of NSMutableDictionary
  @private NSMutableDictionary * mTemplateTextAttributeDictionary ;
  
//--- Timer for autosaving
  @private NSTimer * mTimerForAutosaving ;
}

@property (readonly PROPERTY_COMMA_ATOMIC) BOOL isDirty ;
@property (assign, readonly PROPERTY_COMMA_ATOMIC) OC_GGS_DocumentData * documentData ;

- (OC_GGS_TextSyntaxColoring *) initWithSourceString: (NSString *) inSource
                                tokenizer: (OC_Lexique *) inTokenizer
                                documentData: (OC_GGS_DocumentData *) inDocument
                                issueArray: (NSArray *) inIssueArray ;

- (void) detach ;

- (void) setIssueArray: (NSArray *) inIssueArray ;

- (NSUndoManager *) undoManager ;
- (OC_Lexique *) tokenizer ;

- (NSRange) rangeForLine: (NSInteger) inLineNumber ;

- (NSArray *) buildIndexingDictionaryArray ;

- (NSArray *) tokenArray ;
- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex ;

- (NSString *) sourceString ;
- (void) replaceSourceStringWithString: (NSString *) inString ;

- (void) replaceCharactersInRange: (NSRange) inRange withString: (NSString *) inReplaceString ;

- (void) updateSyntaxColoringForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength ;

- (void) breakUndoCoalescing ;

- (NSRange) uncommentRange: (NSRange) initialSelectedRange ;
- (NSRange) commentRange: (NSRange) initialSelectedRange ;

- (void) documentHasBeenSaved ;

- (void) appendIndexingToMenu: (NSMenu *) inMenu
         forRange: (NSRange) inSelectedRange
         textDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor ;

- (NSUInteger) displayDescriptorCount ;

//--- RESERVED to OC_GGS_TextDisplayDescriptor
- (void) addDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor ;
- (void) removeDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor ;
@end

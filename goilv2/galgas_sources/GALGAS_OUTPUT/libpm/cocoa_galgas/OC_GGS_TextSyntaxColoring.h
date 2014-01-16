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
  @private NSMutableArray * mTokenArray ;
  @private NSMutableArray * mFontAttributesDictionaryArray ; // Array of OC_Token
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

- (NSMenu *) indexMenuForRange: (NSRange) inSelectedRange
             textDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor ;

- (NSUInteger) displayDescriptorCount ;

//--- RESERVED to OC_GGS_TextDisplayDescriptor
- (void) addDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor ;
- (void) removeDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor ;
@end

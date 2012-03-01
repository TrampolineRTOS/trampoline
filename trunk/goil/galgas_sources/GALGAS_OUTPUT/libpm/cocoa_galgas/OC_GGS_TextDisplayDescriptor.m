//
//  OC_GGS_TextDisplayDescriptor.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 24/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_GGS_TextSyntaxColoring.h"
#import "OC_Lexique.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_TextView.h"
#import "PMErrorOrWarningDescriptor.h"
#import "OC_GGS_RulerViewForTextView.h"
#import "OC_GGS_PreferencesController.h"
#import "OC_GGS_Scroller.h"

//---------------------------------------------------------------------------*

static inline NSInteger imin (const NSInteger a, const NSInteger b) { return a < b ? a : b ; }
static inline NSInteger imax (const NSInteger a, const NSInteger b) { return a > b ? a : b ; }

//---------------------------------------------------------------------------*

@implementation OC_GGS_TextDisplayDescriptor

//---------------------------------------------------------------------------*

- (void) refreshShowInvisibleCharacters {
  const BOOL show = [[NSUserDefaults standardUserDefaults] boolForKey:@"PMShowInvisibleCharacters"] ;
  [mTextView.layoutManager setShowsInvisibleCharacters:show] ;
  [mTextView setNeedsDisplay:YES] ;
}

//---------------------------------------------------------------------------*

- (NSUInteger) textSelectionStart {
  return mTextSelectionStart ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_TextDisplayDescriptor *) initWithDelegateForSyntaxColoring: (OC_GGS_TextSyntaxColoring *) inDelegateForSyntaxColoring
                                   document: (OC_GGS_Document *) inDocument  {
  self = [self init] ;
  if (self) {
    mDocument = inDocument ;
    [self setSyntaxColoringDelegate:inDelegateForSyntaxColoring] ;
    mTextView = [[OC_GGS_TextView alloc] initWithFrame:NSMakeRect (0.0, 0.0, 10.0, 10.0)] ;
    [mTextView setDisplayDescriptor:self] ;
    mTextView.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable ;
    mTextView.usesFindPanel = YES ;
    mTextView.grammarCheckingEnabled = NO ;
    mTextView.allowsUndo = YES ;
  //---
    if ([mTextView respondsToSelector:@selector (setUsesFindBar:)]) {
      [mTextView setValue:[NSNumber numberWithBool:YES] forKey:@"usesFindBar"] ;
    }
  //---
    [mTextSyntaxColoring.textStorage addLayoutManager:mTextView.layoutManager] ;
    // NSLog (@"mTextSyntaxColoring.textStorage %p", mTextSyntaxColoring.textStorage) ;
    // NSLog (@"mTextView.layoutManager %p", mTextView.layoutManager) ;
    [mTextView setDelegate:self] ;
  //---
    mScrollView = [[NSScrollView alloc] initWithFrame:NSMakeRect (0.0, 0.0, 100.0, 100.0)] ;
    mScrollView.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable ;
    [mScrollView setHasVerticalScroller:YES] ;
    mRulerView = [[OC_GGS_RulerViewForTextView alloc] initWithDocument:inDocument] ;
    [mScrollView setVerticalRulerView:mRulerView] ;
    [mScrollView.verticalRulerView setRuleThickness:gCocoaGalgasPreferencesController.ruleThickness] ;
    [mScrollView setRulersVisible:[[NSUserDefaults standardUserDefaults] boolForKey:GGS_show_ruler]] ;
    [mScrollView setHasVerticalRuler:YES] ;
    mScrollView.documentView = mTextView ;
    [mScrollView setVerticalScroller:[OC_GGS_Scroller new]] ;
  //--- Add "Show Invisible Character" preference observer
    [[NSUserDefaultsController sharedUserDefaultsController]
      addObserver:self
      forKeyPath:@"values.PMShowInvisibleCharacters"
      options:0
      context:NULL
    ] ;
    [self refreshShowInvisibleCharacters] ;
    [self setIssueArray:inDelegateForSyntaxColoring.issueArray] ;
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector(myProcessEditing:)
      name: NSTextStorageDidProcessEditingNotification
      object:mTextSyntaxColoring.textStorage
    ] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) setSyntaxColoringDelegate: (OC_GGS_TextSyntaxColoring *) inDelegate {
  if (mTextSyntaxColoring != inDelegate) {
    [mTextSyntaxColoring performSelector:@selector (removeTextDisplayDescriptor:) withObject:self] ;
    mTextSyntaxColoring = inDelegate ;
    [mTextSyntaxColoring performSelector:@selector (addTextDisplayDescriptor:) withObject:self] ;
  }
}

//---------------------------------------------------------------------------*

- (OC_GGS_TextSyntaxColoring *) textSyntaxColoring {
  return mTextSyntaxColoring ;
}

//---------------------------------------------------------------------------*

- (NSMenu *) menuForEntryPopUpButton {
  return mTextSyntaxColoring.menuForEntryPopUpButton ;
}

//---------------------------------------------------------------------------*

- (NSTextView *) textView {
  return mTextView ;
}

//---------------------------------------------------------------------------*

- (NSScrollView *) scrollView {
  return mScrollView ;
}

//---------------------------------------------------------------------------*

- (NSURL *) sourceURL {
  return mTextSyntaxColoring.sourceURL ;
}

//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject: (id) inObject
         change:(NSDictionary *) inChange
         context:(void *) inContext {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if ([inKeyPath isEqualToString:@"values.PMShowInvisibleCharacters"]) {
    [self refreshShowInvisibleCharacters] ;
  }else if ([inKeyPath isEqualToString:@"menuForEntryPopUpButton"]) {
    [self willChangeValueForKey:@"menuForEntryPopUpButton"] ;
    [self  didChangeValueForKey:@"menuForEntryPopUpButton"] ;
  }else{
    [super
      observeValueForKeyPath:inKeyPath
      ofObject:inObject
      change:inChange
      context:inContext
    ] ;
  }
}

//---------------------------------------------------------------------------*

#pragma mark Goto Line

//---------------------------------------------------------------------------*
//                                                                           *
//        G O T O    L I N E    A N D     C O L U M N                        *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) gotoLine: (NSUInteger) inLine {
//--- Find index
  NSUInteger currentLine = 0 ;
  NSString * sourceString = [[mTextView textStorage] string] ;
  NSRange range = [sourceString lineRangeForRange: NSMakeRange (0, 0)] ;
  NSUInteger lastStartOfLine = 0 ;
  while ((currentLine < inLine) && (range.length > 0)) {
    currentLine ++ ;
    lastStartOfLine = range.location ;
    range = [sourceString lineRangeForRange: NSMakeRange (NSMaxRange (range), 0)] ;
  }
//--- Change selected range
  if (range.length > 0) {
    range.location = lastStartOfLine ;
    range.length = 0 ;
  }
  [mTextView setSelectedRange:range] ;
  [mTextView scrollRangeToVisible:range] ;
}

//---------------------------------------------------------------------------*

#pragma mark Block Comment

//---------------------------------------------------------------------------*

- (void) commentSelection {
  const NSRange newRange = [mTextSyntaxColoring commentRange:mTextView.selectedRange] ;
  mTextView.selectedRange = newRange ;
}

//---------------------------------------------------------------------------*

- (void) uncommentSelection {
  const NSRange newRange = [mTextSyntaxColoring uncommentRange:mTextView.selectedRange] ;
  mTextView.selectedRange = newRange ;
}

//---------------------------------------------------------------------------*

#pragma mark Indentation

//---------------------------------------------------------------------------*

- (NSString *) shiftLeftString {
  const NSUInteger spaceCount = [[NSUserDefaults standardUserDefaults] integerForKey:@"PMShiftLeftInsertedSpaceCount"] ;
  //NSLog (@"spaceCount %u", spaceCount) ;
  NSMutableString * s = [[[NSMutableString alloc] init] autorelease] ;
  NSUInteger i ;
  for (i=0 ; i<spaceCount ; i++) {
    [s appendString:@" "] ;
  }
  return s ;
}

//---------------------------------------------------------------------------*

- (NSAttributedString *) shiftLeftAttributedString {
  NSDictionary * attributeDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
    [mTextView font], NSFontAttributeName,
    nil
  ] ;
  return [[[NSAttributedString alloc] initWithString:[self shiftLeftString] attributes:attributeDictionary] autorelease] ;
}

//---------------------------------------------------------------------------*

- (void) shiftRightRange: (NSValue *) inRangeValue {
  NSAttributedString * spaceString = [self shiftLeftAttributedString] ;
  const NSRange selectedRange = [inRangeValue rangeValue] ;
  //NSLog (@"selectedRange [%d, %d]", selectedRange.location, selectedRange.length) ;
  NSMutableAttributedString * mutableSourceString = [mTextView textStorage] ;
  NSString * sourceString = [mutableSourceString string] ;
  const NSRange lineRange = [sourceString lineRangeForRange:selectedRange] ;
  //NSLog (@"lineRange [%d, %d]", lineRange.location, lineRange.length) ;
  NSInteger insertedCharsCount = 0 ;
  NSRange currentLineRange = [sourceString lineRangeForRange:NSMakeRange (lineRange.location + lineRange.length - 1, 1)] ;
  do {
    //NSLog (@"currentLineRange [%d, %d]", currentLineRange.location, currentLineRange.length) ;
    [mutableSourceString insertAttributedString:spaceString atIndex:currentLineRange.location] ;
    insertedCharsCount += [spaceString length] ;
    if (currentLineRange.location > 0) {
      currentLineRange = [sourceString lineRangeForRange:NSMakeRange (currentLineRange.location - 1, 1)] ;
    }
  }while ((currentLineRange.location > 0) && (currentLineRange.location >= lineRange.location)) ;
//--- Update selected range
  const NSRange newSelectedRange = NSMakeRange (selectedRange.location, selectedRange.length + insertedCharsCount) ;
  [mTextView setSelectedRange:newSelectedRange] ;
//--- Register undo
  [mTextSyntaxColoring.undoManager 
    registerUndoWithTarget:self
    selector:@selector (shiftLeftRange:)
    object:[NSValue valueWithRange:newSelectedRange]
  ] ;
}

//---------------------------------------------------------------------------*

- (void) shiftRightAction {
  const NSRange selectedRange = [mTextView selectedRange] ;
  [self shiftRightRange:[NSValue valueWithRange:selectedRange]] ;
}

//---------------------------------------------------------------------------*

- (void) shiftLeftRange: (NSValue *) inRangeValue {
//--- Get range to be examined
  const NSRange initialSelectedRange = [inRangeValue rangeValue] ;
//--- Block comment string
  NSString * spaceString = [self shiftLeftString] ;
  const NSUInteger twoSpaceLength = [spaceString length] ;
//--- Get source string
  NSMutableAttributedString * mutableSourceString = [mTextView textStorage] ;
  NSString * sourceString = [mutableSourceString string] ;
  #ifdef DEBUG_UNCOMMENTRANGE
    NSLog (@"spaceString '%@', text length %u", spaceString, [sourceString length]) ;
    NSLog (@"initialSelectedRange [%d, %d]", initialSelectedRange.location, initialSelectedRange.length) ;
  #endif
//--- Final selection range
  NSRange finalSelectedRange = initialSelectedRange ;
//--- Get line range that is affected by the operation
  const NSRange lineRange = [sourceString lineRangeForRange:initialSelectedRange] ;
  #ifdef DEBUG_UNCOMMENTRANGE
    NSLog (@"lineRange [%d, %d]", lineRange.location, lineRange.length) ;
  #endif
  NSRange currentLineRange = [sourceString lineRangeForRange:NSMakeRange (lineRange.location + lineRange.length - 1, 1)] ;
  do {
    #ifdef DEBUG_UNCOMMENTRANGE
      NSLog (@"currentLineRange [%d, %d]", currentLineRange.location, currentLineRange.length) ;
    #endif
    NSString * lineString = [sourceString substringWithRange:currentLineRange] ;
    if ([lineString compare:spaceString options:0 range:NSMakeRange (0, twoSpaceLength)] == NSOrderedSame) {
      [mutableSourceString replaceCharactersInRange:NSMakeRange (currentLineRange.location, twoSpaceLength) withString:@""] ;
    //--- Examen du nombre de caractères à l'intérieur de la sélection
      const NSInteger withinSelectionCharacterCount = 
        imin (currentLineRange.location + twoSpaceLength, finalSelectedRange.location + finalSelectedRange.length)
      -
        imax (currentLineRange.location, finalSelectedRange.location) ;
      if (withinSelectionCharacterCount > 0) {
        finalSelectedRange.length -= withinSelectionCharacterCount ;
      }
    //--- Examen du nombre de caractères avant la sélection
      const NSInteger beforeSelectionCharacterCount = finalSelectedRange.location - currentLineRange.location ;
      if (beforeSelectionCharacterCount > 0) {
        finalSelectedRange.location -= imin (twoSpaceLength, beforeSelectionCharacterCount) ;
      }
      #ifdef DEBUG_UNCOMMENTRANGE
        NSLog (@"withinSelectionCharacterCount %d, beforeSelectionCharacterCount %d", withinSelectionCharacterCount, beforeSelectionCharacterCount) ;
        NSLog (@"finalSelectedRange [%d, %d]", finalSelectedRange.location, finalSelectedRange.length) ;
      #endif
    }
    if (currentLineRange.location > 0) {
      currentLineRange = [sourceString lineRangeForRange:NSMakeRange (currentLineRange.location - 1, 1)] ;
    }
  }while ((currentLineRange.location > 0) && (currentLineRange.location >= lineRange.location)) ;
//--- Update selected range
  [mTextView setSelectedRange:finalSelectedRange] ;
//--- Register undo
  [mTextSyntaxColoring.undoManager 
    registerUndoWithTarget:self
    selector:@selector (shiftRightRange:)
    object:[NSValue valueWithRange:finalSelectedRange]
  ] ;
}

//---------------------------------------------------------------------------*

- (void) shiftLeftAction {
  const NSRange selectedRange = [mTextView selectedRange] ;
  [self shiftLeftRange:[NSValue valueWithRange:selectedRange]] ;
}

//---------------------------------------------------------------------------*

#pragma mark Text Macros

//---------------------------------------------------------------------------*

- (void) actionInsertTextMacro: (NSMenuItem *) inSender {
  // NSLog (@"sender %@, tag %d", inSender, [inSender tag]) ;
  NSString * macroString = [mTextSyntaxColoring.tokenizer textMacroContentAtIndex:[inSender tag]] ;
  [mTextView insertText:macroString] ;
}

//---------------------------------------------------------------------------*

#pragma mark NSTextView delegate methods

//---------------------------------------------------------------------------*

- (NSUndoManager *) undoManagerForTextView: (NSTextView *) inTextView { // Delegate Method
  return mTextSyntaxColoring.undoManager ;
}

//---------------------------------------------------------------------------*

- (void) textViewDidChangeSelection:(NSNotification *) inNotification { // Delegate Method
  [self willChangeValueForKey:@"textSelectionStart"] ;
  mTextSelectionStart = mTextView.selectedRange.location ;
  [self  didChangeValueForKey:@"textSelectionStart"] ;
  [mRulerView setNeedsDisplay:YES] ;
}

//---------------------------------------------------------------------------*

/*- (NSMenu *) textView:(NSTextView *)view
             menu:(NSMenu *)menu
             forEvent:(NSEvent *)event
             atIndex:(NSUInteger) inCharacterIndex { // Delegate Method
  const NSRange selectedRange = {inCharacterIndex, 0} ;
  const NSRange r = [mTextView selectionRangeForProposedRange:selectedRange granularity:NSSelectByWord] ;
  [mTextView setSelectedRange:r] ;
  return [mTextSyntaxColoring indexMenuForRange:r] ;
}*/

//---------------------------------------------------------------------------*

- (void) noteUndoManagerCheckPointNotification {
  [mDocument triggerDocumentEditedStatusUpdate] ;
}

//---------------------------------------------------------------------------*

- (void) myProcessEditing: (NSNotification *) inNotification {
  [mDocument triggerLiveCompilation] ;
}

//---------------------------------------------------------------------------*

#pragma mark Displaying issues

//---------------------------------------------------------------------------*

- (void) setIssueArray: (NSArray *) inIssueArray {
  mIssueArray = inIssueArray ;
  [mTextView setIssueArray:inIssueArray] ;
}

//---------------------------------------------------------------------------*

- (BOOL) makeVisibleIssue: (PMIssueDescriptor *) inOriginalIssue {
  BOOL found = NO ;
  for (NSUInteger i=0 ; (i<mIssueArray.count) && ! found ; i++) {
    PMErrorOrWarningDescriptor * issue = [mIssueArray objectAtIndex:i] ;
    found = issue.originalIssue == inOriginalIssue ;
    if (found) {
      [mTextView scrollRangeToVisible:NSMakeRange (issue.location, 0)] ;
      [mTextView setSelectedRange:NSMakeRange (issue.location, 0)] ;
      [mTextView.window makeFirstResponder:mTextView] ;
    }
  }
//---
  return found ;
}

//---------------------------------------------------------------------------*

@end

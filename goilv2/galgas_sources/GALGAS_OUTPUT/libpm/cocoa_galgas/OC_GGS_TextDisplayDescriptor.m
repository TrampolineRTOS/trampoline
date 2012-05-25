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
#import "OC_GGS_ContextualHelpTask.h"
#import "PMCocoaCallsDebug.h"
#import "PMIssueDescriptor.h"

//---------------------------------------------------------------------------*

#include <netdb.h>
#include <netinet/in.h>

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

static inline NSInteger imin (const NSInteger a, const NSInteger b) { return a < b ? a : b ; }
static inline NSInteger imax (const NSInteger a, const NSInteger b) { return a > b ? a : b ; }

//---------------------------------------------------------------------------*

@implementation OC_GGS_TextDisplayDescriptor

//---------------------------------------------------------------------------*

- (void) refreshShowInvisibleCharacters {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self = [self init] ;
  if (self) {
    mPreviousBuildTasks = [NSMutableSet new] ;
    mDocument = inDocument ;
    [self setSyntaxColoringDelegate:inDelegateForSyntaxColoring] ;
    mTextView = [[OC_GGS_TextView alloc] initWithFrame:NSMakeRect (0.0, 0.0, 10.0, 10.0)] ;
    [mTextView setDisplayDescriptor:self] ;
    mTextView.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable ;
    mTextView.usesFindPanel = YES ;
    mTextView.grammarCheckingEnabled = NO ;
    mTextView.allowsUndo = YES ;
    mTextView.automaticQuoteSubstitutionEnabled = NO ;
    mTextView.smartInsertDeleteEnabled = NO ;
    if ([mTextView respondsToSelector:@selector(setAutomaticTextReplacementEnabled:)]) {
      // NSLog (@"AVANT %d", mTextView.isAutomaticTextReplacementEnabled) ;
      [mTextView setValue:[NSNumber numberWithBool:NO] forKey:@"automaticTextReplacementEnabled"] ;
      // NSLog (@"APRES %d", mTextView.isAutomaticTextReplacementEnabled) ;
    }
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
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector(myProcessEditing:)
      name: NSTextStorageDidProcessEditingNotification
      object:mTextSyntaxColoring.textStorage
    ] ;
  //--- Set selection
    NSString * key = [NSString stringWithFormat:@"SELECTION:%@:%@", mDocument.fileURL.path, mTextSyntaxColoring.document.fileURL.path] ;
    NSString * selectionRangeString = [[NSUserDefaults standardUserDefaults] objectForKey:key] ;
    // NSLog (@"READ '%@' -> %@", key, selectionRangeString) ;
    const NSRange selectionRange = NSRangeFromString (selectionRangeString) ;
    const NSUInteger sourceTextLength = mTextSyntaxColoring.textStorage.length ;
    if (NSMaxRange (selectionRange) <= sourceTextLength) {
      [self setSelectionRangeAndMakeItVisible:selectionRange] ;
    }
  //--- Set issues
    [self setTextDisplayIssueArray:mDocument.documentIssueArray] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) setSyntaxColoringDelegate: (OC_GGS_TextSyntaxColoring *) inDelegate {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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
  return mTextSyntaxColoring.document.fileURL ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_Document *) document {
  return mDocument ;
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSRange newRange = [mTextSyntaxColoring commentRange:mTextView.selectedRange] ;
  mTextView.selectedRange = newRange ;
}

//---------------------------------------------------------------------------*

- (void) uncommentSelection {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSDictionary * attributeDictionary = [NSDictionary dictionaryWithObjectsAndKeys:
    [mTextView font], NSFontAttributeName,
    nil
  ] ;
  return [[[NSAttributedString alloc] initWithString:[self shiftLeftString] attributes:attributeDictionary] autorelease] ;
}

//---------------------------------------------------------------------------*

- (void) shiftRightRange: (NSValue *) inRangeValue {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSRange selectedRange = [mTextView selectedRange] ;
  [self shiftRightRange:[NSValue valueWithRange:selectedRange]] ;
}

//---------------------------------------------------------------------------*

- (void) shiftLeftRange: (NSValue *) inRangeValue {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSRange selectedRange = [mTextView selectedRange] ;
  [self shiftLeftRange:[NSValue valueWithRange:selectedRange]] ;
}

//---------------------------------------------------------------------------*

#pragma mark Text Macros

//---------------------------------------------------------------------------*

- (void) actionInsertTextMacro: (NSMenuItem *) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * macroString = [mTextSyntaxColoring.tokenizer textMacroContentAtIndex:[inSender tag]] ;
  [mTextView insertText:macroString] ;
}

//---------------------------------------------------------------------------*

#pragma mark Contextual Help

//---------------------------------------------------------------------------*

- (void) purgePreviousContextualHelpTasks {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  // const NSUInteger n = mPreviousBuildTasks.count ;
  NSMutableString * s = [NSMutableString new] ;
  NSArray * allTasks = [mPreviousBuildTasks allObjects] ;
  [mPreviousBuildTasks removeAllObjects] ;
  for (NSUInteger idx = 0 ; idx < allTasks.count ; idx ++) {
    if (! [[allTasks objectAtIndex:idx] isCompleted]) {
      [mPreviousBuildTasks addObject:[allTasks objectAtIndex:idx]] ;
      [s appendString:[[allTasks objectAtIndex:idx] runningStatus]] ;
    }  
  }
  // NSLog (@"CONTEXT TASKS : %lu -> %lu%@", n, mPreviousBuildTasks.count, s) ;
}

//---------------------------------------------------------------------------*

- (void) performContextualHelpAtRange: (NSRange) inRange {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mDocument setContextualHelpMessage:@"Looking for Help…"] ;
//---
  if (nil != mContextualHelpTask) {
    [mContextualHelpTask terminate] ;
    [mPreviousBuildTasks addObject:mContextualHelpTask] ;
    mContextualHelpTask = nil ;
  }
  [self purgePreviousContextualHelpTasks] ;
//---
  mContextualHelpTask = [[OC_GGS_ContextualHelpTask alloc]
    initWithDocument:mDocument
    range:inRange
    proxy:self
    index:mTaskIndex
  ] ;
  mTaskIndex ++ ;
}

//---------------------------------------------------------------------------*

- (void) noteBuildTaskTermination: (OC_GGS_ContextualHelpTask *) inBuildTask {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if (mContextualHelpTask == inBuildTask) {
    mContextualHelpTask = nil ;
  }else{
    [mPreviousBuildTasks addObject:inBuildTask] ;
  }
  [self purgePreviousContextualHelpTasks] ;
}

//---------------------------------------------------------------------------*

- (void) noteSocketData: (NSData *) inData {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * message = [[NSString alloc] initWithData:inData encoding:NSUTF8StringEncoding] ;
  [mDocument setContextualHelpMessage:message] ;
}

//---------------------------------------------------------------------------*

#pragma mark Entry Pop up

//---------------------------------------------------------------------------*

- (void) populatePopUpButton {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMenu * menu = [self menuForEntryPopUpButton] ;
  NSPopUpButton * entryListPopUpButton = [self.document entryListPopUpButton] ;
  [entryListPopUpButton setAutoenablesItems:NO] ;

  const NSUInteger n = [menu numberOfItems] ;
  if (n == 0) {
    [menu
      addItemWithTitle:@"No entry"
      action:NULL
      keyEquivalent:@""
    ] ;
    [[menu itemAtIndex:0] setEnabled:NO] ;
    [entryListPopUpButton setEnabled:NO] ;
  }else{
    for (NSUInteger i=0 ; i<n ; i++) {
      NSMenuItem * item = [menu itemAtIndex:i] ;
      [item setTarget:self] ;
      [item setAction:@selector (gotoEntry:)] ;
    }
    [entryListPopUpButton setEnabled:YES] ;
  }
  [entryListPopUpButton setMenu:menu] ;
  // NSLog (@"entryListPopUpButton %@", entryListPopUpButton) ;
}

//---------------------------------------------------------------------------*

- (void) gotoEntry: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, TAG %ld", __PRETTY_FUNCTION__, [inSender tag]) ;
  #endif
  const NSRange range = {[inSender tag], 0} ;
  [mTextView setSelectedRange:range] ;
  [mTextView scrollRangeToVisible:range] ;
}

//---------------------------------------------------------------------------*

- (void) selectEntryPopUp {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSUInteger selectionStart = self.textSelectionStart ;
  NSPopUpButton * entryListPopUpButton = [self.document entryListPopUpButton] ;
  NSArray * menuItemArray = [entryListPopUpButton itemArray] ;
  if ([entryListPopUpButton isEnabled]) {
    NSInteger idx = NSNotFound ;
    NSInteger i ;
    const NSInteger n = [menuItemArray count] ;
    for (i=n-1 ; (i>=0) && (idx == NSNotFound) ; i--) {
      NSMenuItem * item = [menuItemArray objectAtIndex:i HERE] ;
      const NSUInteger startPoint = [item tag] ;
      if (selectionStart >= startPoint) {
        idx = i ;
      }
    }
    if (idx == NSNotFound) {
      [entryListPopUpButton selectItemAtIndex:0] ;
    }else{
      [entryListPopUpButton selectItemAtIndex:idx] ;
    }
  }
}

//---------------------------------------------------------------------------*

#pragma mark NSTextView delegate methods

//---------------------------------------------------------------------------*

- (NSUndoManager *) undoManagerForTextView: (NSTextView *) inTextView { // Delegate Method
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mTextSyntaxColoring.undoManager ;
}

//---------------------------------------------------------------------------*

- (void) textViewDidChangeSelection:(NSNotification *) inNotification { // Delegate Method
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self willChangeValueForKey:@"textSelectionStart"] ;
  mTextSelectionStart = mTextView.selectedRange.location ;
  [self  didChangeValueForKey:@"textSelectionStart"] ;
  [mRulerView setNeedsDisplay:YES] ;
  [self populatePopUpButton] ;
  if (! [mDocument isContextualHelpTextViewCollapsed]) {
    [self performContextualHelpAtRange:mTextView.selectedRange] ;
  }
//---
  NSString * key = [NSString stringWithFormat:@"SELECTION:%@:%@", mDocument.fileURL.path, mTextSyntaxColoring.document.fileURL.path] ;
  [[NSUserDefaults standardUserDefaults]
    setObject:NSStringFromRange (mTextView.selectedRange)
    forKey:key
  ] ;
  // NSLog (@"WRITE '%@' -> %@", key, NSStringFromRange (mTextView.selectedRange)) ;
}

//---------------------------------------------------------------------------*

- (void) noteUndoManagerCheckPointNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mDocument triggerDocumentEditedStatusUpdate] ;
}

//---------------------------------------------------------------------------*

- (void) myProcessEditing: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mDocument triggerLiveCompilation] ;
}

//---------------------------------------------------------------------------*

#pragma mark Displaying issues

//---------------------------------------------------------------------------*

- (void) setTextDisplayIssueArray: (NSArray *) inIssueArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, '%@', enter %lu issues", __PRETTY_FUNCTION__, mTextSyntaxColoring.sourceURL, inIssueArray.count) ;
  #endif
  NSMutableArray * filteredArray = [NSMutableArray new] ;
  for (PMIssueDescriptor * issue in inIssueArray) {
    // NSLog (@"  TEST with '%@' : %@", issue.issueURL, [issue.issueURL isEqual:mTextSyntaxColoring.sourceURL] ? @"yes" : @"no") ;
    if ([issue.issueURL isEqual:mTextSyntaxColoring.document.fileURL]) {
      const NSRange lineRange = [mTextSyntaxColoring rangeForLine:issue.issueLine] ;
      [filteredArray
        addObject:[[PMErrorOrWarningDescriptor alloc]
          initWithMessage:issue.issueMessage
          location:lineRange.location + issue.issueColumn - 1
          isError:issue.errorKind
          originalIssue:issue
        ]
      ] ;
      // NSLog (@"%c", [mSourceTextStorage.string characterAtIndex:lineRange.location + issue.issueColumn - 1 HERE]) ;
    }
  }
  mIssueArray = filteredArray ;
  [mTextView setIssueArray:filteredArray] ;
}

//---------------------------------------------------------------------------*

- (BOOL) makeVisibleIssue: (PMIssueDescriptor *) inOriginalIssue {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  // NSLog (@"mIssueArray %lu", mIssueArray.count) ;
  BOOL found = NO ;
  for (NSUInteger i=0 ; (i<mIssueArray.count) && ! found ; i++) {
    PMErrorOrWarningDescriptor * issue = [mIssueArray objectAtIndex:i] ;
    found = issue.originalIssue == inOriginalIssue ;
    if (found) {
      [self setSelectionRangeAndMakeItVisible:NSMakeRange (issue.location, 0)] ;
    }
  }
//---
  return found ;
}

//---------------------------------------------------------------------------*

- (void) setSelectionRangeAndMakeItVisible: (NSRange) inRange {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mTextView scrollRangeToVisible:inRange] ;
  [mTextView setSelectedRange:inRange] ;
  [mTextView.window makeFirstResponder:mTextView] ;
}

//---------------------------------------------------------------------------*

@end

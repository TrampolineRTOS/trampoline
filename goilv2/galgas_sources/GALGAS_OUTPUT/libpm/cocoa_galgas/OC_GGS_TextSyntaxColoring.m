//
//  OC_GGS_TextSyntaxColoring.m
//  galgas-developer
//
//  Created by Pierre Molinaro on 24/11/11.
//  Copyright (c) 2011 IRCCyN. All rights reserved.
//
//---------------------------------------------------------------------------*

#import "OC_GGS_TextSyntaxColoring.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_Lexique.h"
#import "OC_Token.h"
#import "PMCocoaCallsDebug.h"
#import "OC_GGS_PreferencesController.h"
#import "PMIssueDescriptor.h"
#import "PMErrorOrWarningDescriptor.h"
#import "OC_GGS_BuildTaskProxy.h"
#import "OC_GGS_Document.h"

//---------------------------------------------------------------------------*

#define TAG_MASK                          (0xFF000000)
#define TAG_FOR_FOREGROUND_COLOR          (0x80000000)
#define TAG_FOR_BACKGROUND_COLOR          (0x90000000)
#define TAG_FOR_FONT_ATTRIBUTE            (0xA0000000)
#define TAG_FOR_TEMPLATE_FOREGROUND_COLOR (0xB0000000)
#define TAG_FOR_TEMPLATE_BACKGROUND_COLOR (0xC0000000)
#define TAG_FOR_TEMPLATE_FONT_ATTRIBUTE   (0xD0000000)

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

@implementation OC_GGS_TextSyntaxColoring

//---------------------------------------------------------------------------*

- (void) refreshRulers {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  for (NSLayoutManager * lm in mSourceTextStorage.layoutManagers) {
    for (NSTextContainer * tc in lm.textContainers) {
      NSTextView * tw = [tc textView] ;
      NSScrollView * sv = (NSScrollView *) [[tw superview] superview] ;
      // NSLog (@"%@", sv) ;
      if ([sv isKindOfClass:[NSScrollView class]]) {
        NSRulerView * ruler = [sv verticalRulerView] ;
        [ruler setNeedsDisplay:YES] ;
      }
    }    
  }
}

//---------------------------------------------------------------------------*

- (void) computeMaxLineHeight: (BOOL *) outLineHeightDidChange {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSFont * font = [mTemplateTextAttributeDictionary objectForKey:NSFontAttributeName] ;
  double maxAscender = [font ascender] + 4.0 ;
  double maxLeadingMinusDescender = [font leading] - [font descender] ;
  UInt32 i ;
  for (i=0 ; i<[mFontAttributesDictionaryArray count] ; i++) {
    NSDictionary * d = [mFontAttributesDictionaryArray objectAtIndex:i HERE] ;
    font = [d objectForKey:NSFontAttributeName] ;
    maxAscender = fmax (maxAscender, [font ascender] + 4.0) ;
    maxLeadingMinusDescender = fmax (maxLeadingMinusDescender, [font leading] - [font descender]) ;
  }
  const BOOL maxLineHeightHasChanged = (mMaxAscender != maxAscender) || (mMaxLeadingMinusDescender != maxLeadingMinusDescender) ;
  #ifdef DEBUG_MESSAGES
    NSLog (@"maxLineHeightHasChanged: %@", maxLineHeightHasChanged ? @"yes" : @"no") ;
  #endif
  if (maxLineHeightHasChanged) {
    // NSLog (@"Max line Height: %f", maxLineHeight) ;
    mMaxAscender = maxAscender ;
    mMaxLeadingMinusDescender = maxLeadingMinusDescender ;
  //--- Set new value to default settings
    NSMutableParagraphStyle * paragraghStyle = [[[NSMutableParagraphStyle alloc] init] autorelease] ;
    [paragraghStyle setMaximumLineHeight:mMaxAscender + mMaxLeadingMinusDescender] ;
    [paragraghStyle setMinimumLineHeight:mMaxAscender + mMaxLeadingMinusDescender] ;
    if ([mFontAttributesDictionaryArray count] > 0) {
      NSMutableDictionary * d = [mFontAttributesDictionaryArray objectAtIndex:0 HERE] ;
      [d setObject:paragraghStyle forKey:NSParagraphStyleAttributeName] ;
    }
  }
  if (NULL != outLineHeightDidChange) {
    * outLineHeightDidChange = maxLineHeightHasChanged ;
  }
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s <computeMaxLineHeight:> DONE", __PRETTY_FUNCTION__) ;
  #endif
}

//---------------------------------------------------------------------------*

- (NSUInteger) textDisplayDescriptorCount {
  return mTextDisplayDescriptorSet.count ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_TextSyntaxColoring *) initWithSourceString: (NSString *) inSource
                                tokenizer: (OC_Lexique *) inTokenizer
                                document: (OC_GGS_Document *) inDocument
                                issueArray: (NSArray *) inIssueArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self = [super init] ;
  if (self) {
    mTokenizer = inTokenizer ;
    mDocument = inDocument ;
    mTextDisplayDescriptorSet = [NSMutableSet new] ;
    mSourceTextStorage = [NSTextStorage new] ;
    mTokenArray = [NSMutableArray new] ;
    mTemplateTextAttributeDictionary = [NSMutableDictionary new] ;
    mUndoManager = [NSUndoManager new] ;
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector (undoManagerCheckPointNotification:)
      name:NSUndoManagerCheckpointNotification
      object:mUndoManager
    ] ;
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector(myProcessEditing:)
      name: NSTextStorageDidProcessEditingNotification
      object:mSourceTextStorage
    ] ;
  //---
    [mTokenizer
      addObserver:self
      forKeyPath:@"menuForEntryPopUpButton"
      options:0
      context:NULL
    ] ;
  //--------------------------------------------------- Add foreground color observers
    NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
    NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
    if ([mTokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_foreground_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_TEMPLATE_FOREGROUND_COLOR)
      ] ;
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_foreground_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [mTemplateTextAttributeDictionary setObject:color forKey:NSForegroundColorAttributeName] ;
      }else{
        [mTemplateTextAttributeDictionary setObject:[NSColor blackColor] forKey:NSForegroundColorAttributeName] ;
      }
    }
    for (NSUInteger i=0 ; i<[mTokenizer styleCount] ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_FOREGROUND_COLOR | i)
      ] ;
    }
  //--------------------------------------------------- Add background color observers
    if ([mTokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_background_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_TEMPLATE_BACKGROUND_COLOR)
      ] ;
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_background_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [mTemplateTextAttributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
      }else{
        [mTemplateTextAttributeDictionary setObject:[NSColor blackColor] forKey:NSBackgroundColorAttributeName] ;
      }
    }
    for (NSUInteger i=0 ; i<[mTokenizer styleCount] ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_background_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_BACKGROUND_COLOR | i)
      ] ;
    }
  //--------------------------------------------------- Add font observers
    if ([mTokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_font, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_TEMPLATE_FONT_ATTRIBUTE)
      ] ;
    //--- Add font attribute   
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_font, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSFont * font = (NSFont *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [mTemplateTextAttributeDictionary setObject:font forKey:NSFontAttributeName] ;
      }
    }
    for (NSUInteger i=0 ; i<[mTokenizer styleCount] ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_font, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_FONT_ATTRIBUTE | i)
      ] ;
    }
  //---
    // NSLog (@"%p [mTokenizer styleCount] %u", mTokenizer, [mTokenizer styleCount]) ;
    mFontAttributesDictionaryArray = [NSMutableArray new] ;
    for (NSUInteger i=0 ; i<[mTokenizer styleCount] ; i++) {
      NSMutableDictionary * attributeDictionary = [NSMutableDictionary new] ;
    //--- Add foreground color   
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [attributeDictionary setObject:color forKey:NSForegroundColorAttributeName] ;
      }else{
        [attributeDictionary setObject:[NSColor blackColor] forKey:NSForegroundColorAttributeName] ;
      }
    //--- Add background color   
      name = [NSString stringWithFormat:@"%@_%@", GGS_named_background_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [attributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
      }else{
        [attributeDictionary setObject:[NSColor blackColor] forKey:NSBackgroundColorAttributeName] ;
      }
    //--- Add font attribute   
      name = [NSString stringWithFormat:@"%@_%@", GGS_named_font, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSFont * font = (NSFont *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [attributeDictionary setObject:font forKey:NSFontAttributeName] ;
      }
    //--- Add dictionary
      [mFontAttributesDictionaryArray addObject:attributeDictionary] ;
    }
  //--- Max line height
    [self computeMaxLineHeight:NULL] ;
  //--- Enter source string
    [mSourceTextStorage beginEditing] ;
    // NSLog (@"LINE %d, inSource '%@'", __LINE__, inSource) ;
    [mSourceTextStorage replaceCharactersInRange:NSMakeRange (0, mSourceTextStorage.length) withString:inSource] ;
    [mSourceTextStorage endEditing] ;
  //---
    [self setIssueArray:inIssueArray] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (OC_GGS_Document *) document {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mDocument ;
}

//---------------------------------------------------------------------------*

- (void) addTextDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mTextDisplayDescriptorSet addObject:inDisplayDescriptor] ;
}

//---------------------------------------------------------------------------*

- (void) removeTextDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mTextDisplayDescriptorSet removeObject:inDisplayDescriptor] ;
}

//---------------------------------------------------------------------------*

- (NSTextStorage *) textStorage {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mSourceTextStorage ;
}

//---------------------------------------------------------------------------*

- (NSString *) sourceString {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mSourceTextStorage.string ;
}

//---------------------------------------------------------------------------*

- (void) replaceSourceStringWithString: (NSString *) inString {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [mSourceTextStorage beginEditing] ;
  [mSourceTextStorage replaceCharactersInRange:NSMakeRange (0, mSourceTextStorage.length) withString:inString] ;
  [mSourceTextStorage endEditing] ;
}

//---------------------------------------------------------------------------*

- (NSUndoManager *) undoManager {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mUndoManager ;
}

//---------------------------------------------------------------------------*

- (OC_Lexique *) tokenizer {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mTokenizer ;
}

//---------------------------------------------------------------------------*

- (NSMenu *) menuForEntryPopUpButton {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mTokenizer.menuForEntryPopUpButton ;
}

//---------------------------------------------------------------------------*

- (NSArray *) tokenArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mTokenArray ;
}

//---------------------------------------------------------------------------*

- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return [mTokenizer atomicSelectionForToken:inTokenIndex] ;
}

//---------------------------------------------------------------------------*

#pragma mark Text attribute did change

//---------------------------------------------------------------------------*

- (void) applyTextAttributeForIndex: (NSInteger) inChangedColorIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if ((mTokenizer != NULL) && ([mSourceTextStorage length] > 0)) {
    [self refreshRulers] ;
  //--- Remove observer so that myProcessEditing will not be called at the end of edition
    [[NSNotificationCenter defaultCenter]
      removeObserver:self
      name: NSTextStorageDidProcessEditingNotification
      object:mSourceTextStorage
    ];
    [mSourceTextStorage beginEditing] ;
  //--- Change default style ?
    if (inChangedColorIndex == 0) {
      const NSRange allTextRange = {0, [mSourceTextStorage length]} ;
      [mSourceTextStorage
        setAttributes:[mFontAttributesDictionaryArray objectAtIndex:0 HERE]
        range:allTextRange
      ] ;
      for (NSUInteger i=0 ; i<[mTokenArray count] ; i++) {
        OC_Token * token = [mTokenArray objectAtIndex:i HERE] ;
        const SInt32 colorIndex = [token style] ;
        const NSRange range = [token range] ;
        if (colorIndex == -2) {
          [mSourceTextStorage
            addAttributes:mTemplateTextAttributeDictionary
            range:range
          ] ;
        }else if (colorIndex == -1) {
        
        }else if (colorIndex > 0) {
          [mSourceTextStorage
            addAttributes:[mFontAttributesDictionaryArray objectAtIndex:colorIndex HERE]
            range:range
          ] ;
        }
      }    
    }else{
      for (NSUInteger i=0 ; i<[mTokenArray count] ; i++) {
        OC_Token * token = [mTokenArray objectAtIndex:i HERE] ;
        const SInt32 colorIndex = [token style] ;
        if (colorIndex == inChangedColorIndex) {
          const NSRange range = [token range] ;
          #ifdef DEBUG_MESSAGES
            NSLog (@"change attribute for index %lu [%lu, %lu]>", i, range.location, range.length) ;
          #endif
          if (colorIndex == -2) {
            [mSourceTextStorage
              addAttributes:mTemplateTextAttributeDictionary
              range:range
            ] ;
          }else if (colorIndex == -1) {
          
          }else if (colorIndex > 0) {
            [mSourceTextStorage
              addAttributes:[mFontAttributesDictionaryArray objectAtIndex:colorIndex HERE]
              range:range
            ] ;
          }
        }
      }
    }
    [mSourceTextStorage endEditing] ;
  //--- Resinstall observer
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector(myProcessEditing:)
      name: NSTextStorageDidProcessEditingNotification
      object:mSourceTextStorage
    ] ;
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s DONE", __PRETTY_FUNCTION__) ;
    #endif
  }
}

//---------------------------------------------------------------------------*

#pragma mark Error and Warning Display

//---------------------------------------------------------------------------*

- (NSRange) rangeForLine: (NSInteger) inLineNumber {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSRange range = {0, 0} ;
  for (NSInteger i=1 ; i<=inLineNumber ; i++) {
    range.location += range.length ;
    range.length = 0 ;
    NSUInteger startIndex ;
    NSUInteger lineEndIndex ;
    [mSourceTextStorage.string
      getLineStart:& startIndex
      end:& lineEndIndex
      contentsEnd:NULL
      forRange:range
    ] ;
    range = NSMakeRange (startIndex, lineEndIndex - startIndex) ;
 //   NSLog (@"line %d: range [%u, %u]", i, range.location, range.length) ;
  }
  return range ;
}

//---------------------------------------------------------------------------*

- (void) setIssueArray: (NSArray *) inIssueArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMutableArray * filteredArray = [NSMutableArray new] ;
  for (PMIssueDescriptor * issue in inIssueArray) {
    if ([issue.issueURL isEqual:mDocument.fileURL]) {
      const NSRange lineRange = [self rangeForLine:issue.issueLine] ;
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
//---
  mIssueArray = filteredArray ;
//---
  for (OC_GGS_TextDisplayDescriptor * textDisplay in mTextDisplayDescriptorSet) {
    [textDisplay setTextDisplayIssueArray:mIssueArray] ; 
  }
}  

//---------------------------------------------------------------------------*

- (void) updateIssuesForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  // NSLog (@"inEditedRange %lu:%lu, inChangeInLength %ld", inEditedRange.location, inEditedRange.length, inChangeInLength) ;
  const NSRange previousRange = {inEditedRange.location, inEditedRange.length - inChangeInLength} ;
  NSMutableArray * newIssueArray = [NSMutableArray new] ;
  for (PMErrorOrWarningDescriptor * issue in mIssueArray) {
    if (! [issue isInRange:previousRange]) {
      [issue updateLocationForPreviousRange:previousRange changeInLength:inChangeInLength] ;
      [newIssueArray addObject:issue] ;
    }
  }
//---
  mIssueArray = newIssueArray ;
//---
  for (OC_GGS_TextDisplayDescriptor * textDisplay in mTextDisplayDescriptorSet) {
    [textDisplay setTextDisplayIssueArray:mIssueArray] ; 
  }
}

//---------------------------------------------------------------------------*

#pragma mark Syntax Coloring

//---------------------------------------------------------------------------*

- (void) updateSyntaxColoringForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
  const NSInteger textLength = mSourceTextStorage.string.length ;
  if (textLength > 0) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"%s, edited range [%lu, %lu], changeInLength %ld", __PRETTY_FUNCTION__, inEditedRange.location, inEditedRange.length, inChangeInLength) ;
    #endif
    NSInteger firstIndexToRedraw = 0 ;
    NSInteger lastIndexToRedraw = 0 ;
    NSInteger eraseRangeStart = 0 ;
    NSInteger eraseRangeEnd = 0 ;
    [mTokenizer
      tokenizeForSourceString:mSourceTextStorage.string
      tokenArray:mTokenArray // Array of OC_Token
      editedRange:inEditedRange
      changeInLength:inChangeInLength
      firstIndexToRedraw: & firstIndexToRedraw
      lastIndexToRedraw: & lastIndexToRedraw
      eraseRangeStart: & eraseRangeStart
      eraseRangeEnd: & eraseRangeEnd
    ] ;
    #ifdef DEBUG_MESSAGES
      NSLog (@"scanThenGetStyledRangeArray DONE (%lu)", [mFontAttributesDictionaryArray count]) ;
    #endif
  //--- Erase text attributes
    if (eraseRangeEnd >= textLength) {
      eraseRangeEnd = textLength - 1 ;
    }
    if (eraseRangeStart < eraseRangeEnd) {
      const NSRange eraseRange = {eraseRangeStart, eraseRangeEnd - eraseRangeStart} ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"PERFORM REMOVE ATTRIBUTE range [%lu, %lu] text length %lu", eraseRange.location, eraseRange.length, textLength) ;
      #endif
      [mSourceTextStorage
        setAttributes:[mFontAttributesDictionaryArray objectAtIndex:0 HERE]
        range:eraseRange
      ] ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"mSourceTextStorage setAttributes DONE") ;
      #endif
    }
  //--- Perform text coloring
    #ifdef DEBUG_MESSAGES
     NSLog (@"COLORING from %ld to %ld", firstIndexToRedraw, lastIndexToRedraw) ;
    #endif
    for (NSInteger i=firstIndexToRedraw ; i<=lastIndexToRedraw ; i++) {
      OC_Token * token = [mTokenArray objectAtIndex:i HERE] ;
      const NSRange range = [token range] ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"PERFORM COLORING '%@' range [%lu, %lu] [mSourceTextStorage length] %lu", [mSourceTextStorage.string substringWithRange:range], range.location, range.length, mSourceTextStorage.string.length) ;
      #endif
      const int style = [token style] ;
      if (style == -1) { // Error
        [mSourceTextStorage
          addAttribute:NSForegroundColorAttributeName
          value:[NSColor redColor]
          range:range
        ] ;
      }else if (style == -2) { // Template string
        [mSourceTextStorage
          addAttributes:mTemplateTextAttributeDictionary
          range:range
        ] ;
      }else if (style > 0) {
        [mSourceTextStorage
          addAttributes:[mFontAttributesDictionaryArray objectAtIndex:style HERE]
          range:range
        ] ;
      }
    }
  }
//---
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s DONE", __PRETTY_FUNCTION__) ;
  #endif
}

//---------------------------------------------------------------------------*

- (void) myProcessEditing: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSRange editedRange = mSourceTextStorage.editedRange ;
  const NSInteger changeInLength = mSourceTextStorage.changeInLength ;
    // NSLog (@"editedRange [%lu, %lu], changeInLength %ld", editedRange.location, editedRange.length, changeInLength) ;
  [self updateSyntaxColoringForEditedRange:editedRange changeInLength:changeInLength] ;
  [self updateIssuesForEditedRange:editedRange changeInLength:changeInLength] ;
    // NSLog (@"%@", self.textStorage.string) ;
}

//---------------------------------------------------------------------------*

- (void) breakUndoCoalescing {
  for (NSLayoutManager * lm in mSourceTextStorage.layoutManagers) {
    for (NSTextContainer * tc in lm.textContainers) {
      [tc.textView breakUndoCoalescing] ;
    }    
  }
}


//---------------------------------------------------------------------------*
//                                                                           *
//           C O M M E N T R A N G E                                         *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSRange) commentRange: (NSRange) inSelectedRangeValue {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self.textStorage beginEditing] ;
//---
  NSAttributedString * blockCommentString = [[[NSAttributedString alloc] initWithString:[mTokenizer blockComment] attributes:nil] autorelease] ;
  //NSLog (@"selectedRange [%d, %d]", selectedRange.location, selectedRange.length) ;
  NSMutableAttributedString * mutableSourceString = self.textStorage ;
  NSString * sourceString = [mutableSourceString string] ;
  const NSRange lineRange = [sourceString lineRangeForRange:inSelectedRangeValue] ;
  //NSLog (@"lineRange [%d, %d]", lineRange.location, lineRange.length) ;
  NSInteger insertedCharsCount = 0 ;
  NSRange currentLineRange = [sourceString lineRangeForRange:NSMakeRange (lineRange.location + lineRange.length - 1, 1)] ;
  do {
    //NSLog (@"currentLineRange [%d, %d]", currentLineRange.location, currentLineRange.length) ;
    [mutableSourceString insertAttributedString:blockCommentString atIndex:currentLineRange.location] ;
    insertedCharsCount += [blockCommentString length] ;
    if (currentLineRange.location > 0) {
      currentLineRange = [sourceString lineRangeForRange:NSMakeRange (currentLineRange.location - 1, 1)] ;
    }
  }while ((currentLineRange.location > 0) && (currentLineRange.location >= lineRange.location)) ;
//---
  [self.textStorage endEditing] ;
//--- Update selected range
  const NSRange newSelectedRange = NSMakeRange (inSelectedRangeValue.location, inSelectedRangeValue.length + insertedCharsCount) ;
//--- Register undo
  [mUndoManager
    registerUndoWithTarget:self
    selector:@selector (uncommentRangeForUndo:)
    object:[NSValue valueWithRange:newSelectedRange]
  ] ;
//---
  return newSelectedRange ;
}

//---------------------------------------------------------------------------*

- (void) commentRangeForUndo: (NSValue *) inRangeValue { // An NSValue of NSRange
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self commentRange:inRangeValue.rangeValue] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       U N C O M M E N T R A N G E                         *
//                                                                           *
// Cette méthode a plusieurs rôles :                                         *
//   - supprimer les marques de commentaires des lignes concernées par la    *
//     sélection, uniquement quand ces le commentaire commence une ligne ;   *
//   - ajuster la sélection en conséquence ; en effet, dès que la méthode    *
//     replaceCharactersInRange:withString: est appelée, Cocoa ramène la     *
//     sélection à un point d'insertion. La sélection est ajustée et         *
//     maintenue dans la variable finalSelectedRange.                        *
//                                                                           *
// Le plus difficile est l'ajustement de la sélection. Pour cela, on calcule:*
//   - le nombre beforeSelectionCharacterCount de caractères du commentaire  *
//     supprimé qui sont avant la sélection ; si ce nombre est > 0, on       *
//     le début de la sélection du min entre ce nombre et le nombre de carac-*
//     tères du commentaire ;                                                *
//   - le nombre withinSelectionCharacterCount de caractères du commentaire  *
//     supprimé qui sont à l'intérieur de la sélection ; si ce nombre est    *
//     > 0, on le retranche de la longueur de la sélection.                  *
//                                                                           *
//---------------------------------------------------------------------------*

// #define DEBUG_UNCOMMENTRANGE

//---------------------------------------------------------------------------*

static inline NSInteger imin (const NSInteger a, const NSInteger b) { return a < b ? a : b ; }
static inline NSInteger imax (const NSInteger a, const NSInteger b) { return a > b ? a : b ; }

//---------------------------------------------------------------------------*

- (NSRange) uncommentRange: (NSRange) initialSelectedRange {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//---
  [self.textStorage beginEditing] ;
//--- Block comment string
  NSString * blockCommentString = [mTokenizer blockComment] ;
  const NSUInteger blockCommentLength = [blockCommentString length] ;
//--- Get source string
  NSMutableAttributedString * mutableSourceString = [self textStorage] ;
  NSString * sourceString = [mutableSourceString string] ;
  #ifdef DEBUG_UNCOMMENTRANGE
    NSLog (@"blockCommentString '%@', text length %u", blockCommentString, [sourceString length]) ;
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
    if ([lineString compare:blockCommentString options:0 range:NSMakeRange (0, blockCommentLength)] == NSOrderedSame) {
      [mutableSourceString replaceCharactersInRange:NSMakeRange (currentLineRange.location, blockCommentLength) withString:@""] ;
    //--- Examen du nombre de caractères à l'intérieur de la sélection
      const NSInteger withinSelectionCharacterCount = 
        imin (currentLineRange.location + blockCommentLength, finalSelectedRange.location + finalSelectedRange.length)
      -
        imax (currentLineRange.location, finalSelectedRange.location) ;
      if (withinSelectionCharacterCount > 0) {
        finalSelectedRange.length -= withinSelectionCharacterCount ;
      }
    //--- Examen du nombre de caractères avant la sélection
      const NSInteger beforeSelectionCharacterCount = finalSelectedRange.location - currentLineRange.location ;
      if (beforeSelectionCharacterCount > 0) {
        finalSelectedRange.location -= imin (blockCommentLength, beforeSelectionCharacterCount) ;
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
//---
  [self.textStorage endEditing] ;
//--- Register undo
  [mUndoManager 
    registerUndoWithTarget:self
    selector:@selector (commentRangeForUndo:)
    object:[NSValue valueWithRange:finalSelectedRange]
  ] ;
//---
  return finalSelectedRange ;
}

//---------------------------------------------------------------------------*

- (void) uncommentRangeForUndo: (NSValue *) inRangeValue { // An NSValue of NSRange
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self uncommentRange:inRangeValue.rangeValue] ;
}

//---------------------------------------------------------------------------*

- (void) undoManagerCheckPointNotification: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * undoStack = [mUndoManager valueForKey:@"_undoStack"] ;
  //NSArray * redoStack = [mUndoManager valueForKey:@"_redoStack"] ;
  //NSLog (@"undoManagerCheckPointNotification: undoStack %lu, redoStack %lu", undoStack.count, redoStack.count) ;
//---
  [self willChangeValueForKey:@"isDirty"] ;
//  mIsDirty = mUndoManager.canUndo || mUndoManager.canRedo ;
  mIsDirty = (mSavePointUndoStackCount != undoStack.count) ;
  [self didChangeValueForKey:@"isDirty"] ;
  for (OC_GGS_TextDisplayDescriptor * textDisplayDescriptor in mTextDisplayDescriptorSet) {
    [textDisplayDescriptor noteUndoManagerCheckPointNotification] ;
  }
}

//---------------------------------------------------------------------------*

- (BOOL) isDirty {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mIsDirty ;
}

//---------------------------------------------------------------------------*

- (void) documentHasBeenSaved {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * undoStack = [mUndoManager valueForKey:@"_undoStack"] ;
  // NSArray * redoStack = [mUndoManager valueForKey:@"_redoStack"] ;
  mSavePointUndoStackCount = undoStack.count ;
  // NSLog (@"documentHasBeenSaved: undoStack %lu, redoStack %lu", mSavePointUndoStackCount, mSavePointRedoStackCount) ;
  [self undoManagerCheckPointNotification:nil] ;
}

//---------------------------------------------------------------------------*

- (NSArray *) issueArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mIssueArray.copy ;
}

//---------------------------------------------------------------------------*

#pragma mark observeValueForKeyPath

//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath: (NSString *) inKeyPath
         ofObject: (id) inObject
         change: (NSDictionary *) inChangeDictionary
         context: (void *) inContext {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s, inKeyPath '%@'", __PRETTY_FUNCTION__, inKeyPath) ;
  #endif
  if ([inKeyPath isEqualToString:@"menuForEntryPopUpButton"]) {
    [self willChangeValueForKey:@"menuForEntryPopUpButton"] ;
    [self  didChangeValueForKey:@"menuForEntryPopUpButton"] ;
  }else if (mTokenizer != NULL) {
    BOOL lineHeightDidChange = NO ;
    NSColor * color = nil ;
    NSMutableDictionary * d = nil ;
    NSData * data = [inObject valueForKeyPath:inKeyPath] ;
    const NSUInteger tag = ((NSUInteger) inContext) & TAG_MASK ;
    const NSUInteger idx = ((NSUInteger) inContext) & ~ TAG_MASK ;
    switch (tag) {
    case TAG_FOR_FOREGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
      }
      d = [mFontAttributesDictionaryArray objectAtIndex:idx HERE] ;
      [d setObject:color forKey:NSForegroundColorAttributeName] ;
      [self applyTextAttributeForIndex:idx] ;
      break;
    case TAG_FOR_TEMPLATE_FOREGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
      }
      [mTemplateTextAttributeDictionary setObject:color forKey:NSForegroundColorAttributeName] ;
      [self applyTextAttributeForIndex:-2] ;
      break;
    case TAG_FOR_BACKGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
      }
      d = [mFontAttributesDictionaryArray objectAtIndex:idx HERE] ;
      [d setObject:color forKey:NSBackgroundColorAttributeName] ;
      [self applyTextAttributeForIndex:idx] ;
      break;
    case TAG_FOR_TEMPLATE_BACKGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
      }
      [mTemplateTextAttributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
      [self applyTextAttributeForIndex:-2] ;
      break;
    case TAG_FOR_FONT_ATTRIBUTE:
      d = [mFontAttributesDictionaryArray objectAtIndex:idx HERE] ;
      [d setObject:[NSUnarchiver unarchiveObjectWithData:data] forKey:NSFontAttributeName] ;
      [self computeMaxLineHeight: & lineHeightDidChange] ;
      [self applyTextAttributeForIndex:lineHeightDidChange ? 0 : idx] ;
      break;
    case TAG_FOR_TEMPLATE_FONT_ATTRIBUTE:
      [mTemplateTextAttributeDictionary setObject:[NSUnarchiver unarchiveObjectWithData:data] forKey:NSFontAttributeName] ;
      [self computeMaxLineHeight: & lineHeightDidChange] ;
      [self applyTextAttributeForIndex:lineHeightDidChange ? 0 : -2] ;
      break;
    default:
      break;
    }
  }
}

//---------------------------------------------------------------------------*

#pragma mark Source Indexing

//---------------------------------------------------------------------------*

- (NSSet *) handledExtensions {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMutableSet * result = [NSMutableSet new] ;
//--- Get Info.plist file
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  // NSLog (@"infoDictionary '%@'", infoDictionary) ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  // NSLog (@"allDocumentTypes '%@'", allDocumentTypes) ;
  for (NSUInteger i=0 ; i<[allDocumentTypes count] ; i++) {
    NSDictionary * docTypeDict = [allDocumentTypes objectAtIndex:i HERE] ;
    // NSLog (@"docTypeDict '%@'", docTypeDict) ;
    NSArray * documentTypeExtensions = [docTypeDict objectForKey:@"CFBundleTypeExtensions"] ;
    // NSLog (@"documentTypeExtensions '%@'", documentTypeExtensions) ;
    [result addObjectsFromArray:documentTypeExtensions] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (BOOL) sourceFile:(NSString *) inFile1
         newerThanFile: (NSString *) inFile2 {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSFileManager * fm = [[NSFileManager alloc] init] ;
  NSDictionary * file1_dictionary = [fm attributesOfItemAtPath:inFile1 error:NULL] ;
  NSDate * file1_modificationDate = [file1_dictionary fileModificationDate] ;
  NSDictionary * file2_dictionary = [fm attributesOfItemAtPath:inFile2 error:NULL] ;
  NSDate * file2_modificationDate = [file2_dictionary fileModificationDate] ;
  return NSOrderedDescending == [file1_modificationDate compare:file2_modificationDate] ;
}

//---------------------------------------------------------------------------*

- (void) parseSourceFileForBuildingIndexFile: (NSString *) inSourceFileFullPath {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * compilerToolPath = [gCocoaGalgasPreferencesController compilerToolPath] ;
//--- Command line tool does actually exist ? (First argument is not "?")
  if (! [compilerToolPath isEqualToString:@"?"]) {
  //--- Build argument array
    NSMutableArray * arguments = [NSMutableArray new] ;
    [arguments addObject:inSourceFileFullPath] ;
    [arguments addObject:@"--mode=indexing"] ;
  //--- Create task
    NSTask * task = [[NSTask alloc] init] ;
    [task setLaunchPath:compilerToolPath] ;
    [task setArguments:arguments] ;
    // NSLog (@"'%@' %@", [task launchPath], arguments) ;
  //--- Start task
    [task launch] ;
  //--- Wait the task is completed
    [task waitUntilExit] ;
  }
}

//---------------------------------------------------------------------------*

- (NSArray *) buildIndexingDictionaryArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMutableArray * result = nil ;
//--- Source directory
  NSString * sourceDirectory = mDocument.fileURL.path.stringByDeletingLastPathComponent ;
//--- index directory
  NSString * indexingDirectory = [mTokenizer indexingDirectory] ;
  if (indexingDirectory.length > 0) {
    if ([indexingDirectory characterAtIndex:0] != '/') {
      NSMutableString * s = [NSMutableString new] ;
      [s appendString:sourceDirectory] ;
      [s appendString:@"/"] ;
      [s appendString:indexingDirectory] ;
      indexingDirectory = s ;
      // NSLog (@"indexingDirectory '%@'", indexingDirectory) ;
    }
  //--- Handled extensions
    NSSet * handledExtensions = [self handledExtensions] ;
  //--- All files in source directory
    NSFileManager * fm = [[NSFileManager alloc] init] ;
    NSArray * files = [fm contentsOfDirectoryAtPath:sourceDirectory error:NULL] ;
    NSMutableArray * availableDictionaryPathArray = [NSMutableArray new] ;
    NSOperationQueue * opq = [NSOperationQueue new] ;
    for (NSString * filePath in files) {
      NSString * fullFilePath = [NSString stringWithFormat:@"%@/%@", sourceDirectory, filePath] ;
      if ([handledExtensions containsObject:[filePath pathExtension]]) {
      //--- Index file path
        NSString * indexFileFullPath = [NSString stringWithFormat:@"%@/%@.plist", indexingDirectory, [filePath lastPathComponent]] ;
      //--- Parse source file ?
        if (! [fm fileExistsAtPath:indexFileFullPath]) { // Parse source file
          NSInvocationOperation * op = [[NSInvocationOperation alloc] 
            initWithTarget:self
            selector:@selector (parseSourceFileForBuildingIndexFile:)
            object:fullFilePath
          ] ;
          [opq addOperation:op] ;
          [availableDictionaryPathArray addObject:indexFileFullPath] ;
        }else if ([self sourceFile:fullFilePath newerThanFile:indexFileFullPath]) {
          [fm removeItemAtPath:indexFileFullPath error:NULL] ;
          NSInvocationOperation * op = [[NSInvocationOperation alloc] 
            initWithTarget:self
            selector:@selector (parseSourceFileForBuildingIndexFile:)
            object:fullFilePath
          ] ;
          [opq addOperation:op] ;
          [availableDictionaryPathArray addObject:indexFileFullPath] ;
        }else{
          [availableDictionaryPathArray addObject:indexFileFullPath] ;
        }
      }
    }
  //--- Wait operations are completed
    [opq waitUntilAllOperationsAreFinished] ;
  //--- Parse available dictionaries
    result = [NSMutableArray new] ;
    for (NSString * fullPath in availableDictionaryPathArray) {
      NSDictionary * dict = [NSDictionary dictionaryWithContentsOfFile:fullPath] ;
      if (nil != dict) {
        [result addObject:dict] ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

static NSInteger numericSort (NSString * inOperand1,
                              NSString * inOperand2,
                              void * inUnusedContext) {
  return [inOperand1 compare:inOperand2 options:NSNumericSearch] ;
}

//---------------------------------------------------------------------------*
// Every plist list is a dictionary: the key is the indexed to token; the 
// associated value is an NSArray of NSString that has the following format:
//   "kind:line:locationIndex:length:sourceFileFullPath"

//---------------------------------------------------------------------------*

- (NSMenu *) indexMenuForRange: (NSRange) inSelectedRange
             textDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSMenu * menu = [[NSMenu alloc] initWithTitle:@""] ;
//--- Save all sources
  [[NSDocumentController sharedDocumentController] saveAllDocuments:self] ;
//--- Check if current has atomic selection
  BOOL hasAtomicSelection = YES ;
  BOOL found = NO ;
  NSRange allTokenCharacterRange = {0, 0} ;
  for (NSUInteger i=0 ; (i<[mTokenArray count]) && ! found ; i++) {
    OC_Token * token = [mTokenArray objectAtIndex:i HERE] ;
    allTokenCharacterRange = [token range] ;
    found = ((allTokenCharacterRange.location + allTokenCharacterRange.length) > inSelectedRange.location)
         && (allTokenCharacterRange.location <= inSelectedRange.location) ;
    if (found) {
      hasAtomicSelection = [mTokenizer atomicSelectionForToken:[token tokenCode]] ;
    }
  }
//---
  NSString * token = [mSourceTextStorage.string substringWithRange:inSelectedRange] ;
  // NSLog (@"%@", token) ;
//---
  NSArray * dictionaryArray = [self buildIndexingDictionaryArray] ;
//--- Build array of all references of given token
  NSMutableArray * allReferences = [NSMutableArray new] ;
  for (NSDictionary * currentIndexDictionary in dictionaryArray) {
    NSArray * references = [currentIndexDictionary objectForKey:token] ;
    [allReferences addObjectsFromArray:references] ;
  }
//--- Build dictionary for the given token, organized by Kind
  NSMutableDictionary * kindDictionary = [NSMutableDictionary new] ;
  for (NSString * descriptor in allReferences) {
    NSArray * components = [descriptor componentsSeparatedByString:@":"] ;
    NSString * kind = [components objectAtIndex:0] ;
    if ([kindDictionary objectForKey:kind] == NULL) {
      [kindDictionary setObject:[NSMutableArray new] forKey:kind] ;
    }
    NSMutableArray * a = [kindDictionary objectForKey:kind] ;
    [a addObject:descriptor] ;
  }
//--- Build Menu
  if (! hasAtomicSelection) {
    NSMenuItem * item = [menu addItemWithTitle:@"Select all token characters" action:@selector (selectAllTokenCharacters:) keyEquivalent:@""] ;
    [item setTarget:inTextDisplayDescriptor.textView] ;
    [item setRepresentedObject:[NSValue valueWithRange:inSelectedRange]] ;
  }
//---
  [menu addItem:[NSMenuItem separatorItem]] ;
  if ([kindDictionary count] == 0) {
    NSString * title = [NSString stringWithFormat:@"No index for '%@'", token] ;
    [menu addItemWithTitle:title action:nil keyEquivalent:@""] ;
  }else{
    NSArray * indexingTitles = [mTokenizer indexingTitles] ;
    NSArray * allKeys = [[kindDictionary allKeys] sortedArrayUsingFunction:numericSort context:NULL] ;
    BOOL first = YES ;
    for (NSString * kindObject in allKeys) {
      if (first) {
        first = NO ;
      }else{
        [menu addItem:[NSMenuItem separatorItem]] ;
      }
      const NSUInteger kind = [kindObject integerValue] ;
      NSArray * references = [kindDictionary objectForKey:kindObject] ;
      NSString * title = [NSString
        stringWithFormat:@"%@ (%d item%@)",
        [indexingTitles objectAtIndex:kind HERE],
        [references count],
        (([references count] > 1) ? @"s" : @"")
      ] ;
      [menu addItemWithTitle:title action:nil keyEquivalent:@""] ;
      for (NSString * descriptor in references) {
        NSArray * components = [descriptor componentsSeparatedByString:@":"] ;
        NSString * filePath = [components objectAtIndex:4 HERE] ;
        title = [NSString stringWithFormat:@"%@, line %@", filePath.lastPathComponent, [components objectAtIndex:1]] ;
        NSMenuItem * item = [menu addItemWithTitle:title action:@selector (indexingMenuAction:) keyEquivalent:@""] ;
        [item setTarget:inTextDisplayDescriptor.textView] ;
        [item setRepresentedObject:descriptor] ;
      }
    }
  }
//---
  return menu ;
}

//---------------------------------------------------------------------------*

@end

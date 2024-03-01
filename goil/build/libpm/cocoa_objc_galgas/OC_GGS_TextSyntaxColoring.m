//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2023 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#import "OC_GGS_ColorTransformer.h"
#import "OC_GGS_TextSyntaxColoring.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_Lexique.h"
#import "OC_Token.h"
#import "OC_GGS_ApplicationDelegate.h"
#import "PMIssueDescriptor.h"
#import "OC_GGS_DocumentData.h"
#import "PMDebug.h"
#import "PMUndoManager.h"
#import "OC_GGS_Document.h"
#import "OC_GGS_TextView.h"
#import "F_CocoaWrapperForGalgas.h"

//--------------------------------------------------------------------------------------------------

#define TAG_MASK                           (0xFF000000)
#define TAG_FOR_FOREGROUND_COLOR           (0x80000000)
#define TAG_FOR_BACKGROUND_COLOR           (0x90000000)
#define TAG_FOR_ENABLING_BACKGROUND        (0xA0000000)
#define TAG_FOR_FONT_ATTRIBUTE             (0xB0000000)
#define TAG_FOR_TEMPLATE_FOREGROUND_COLOR  (0xC0000000)
#define TAG_FOR_ENABLE_TEMPLATE_BACKGROUND (0xD0000000)
#define TAG_FOR_TEMPLATE_BACKGROUND_COLOR  (0xE0000000)
#define TAG_FOR_TEMPLATE_FONT_ATTRIBUTE    (0xF0000000)

//--------------------------------------------------------------------------------------------------

@implementation OC_GGS_TextSyntaxColoring

//--------------------------------------------------------------------------------------------------

@synthesize documentData ;
@synthesize isDirty ;

//--------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//--------------------------------------------------------------------------------------------------

- (void) computeMaxLineHeight: (BOOL *) outLineHeightDidChange {
  NSFont * font = [mTemplateTextAttributeDictionary objectForKey: NSFontAttributeName] ;
  if (font == nil) {
    font = [NSFont fontWithName: @"Helvetica" size: 12.0] ;
  }
  double maxAscender = [font ascender] + 4.0 ;
  double maxLeadingMinusDescender = [font leading] - [font descender] ;
  for (NSUInteger i=0 ; i<[mFontAttributesDictionaryArray count] ; i++) {
    NSDictionary * d = [mFontAttributesDictionaryArray objectAtIndex:i] ;
    font = [d objectForKey:NSFontAttributeName] ;
    maxAscender = fmax (maxAscender, [font ascender] + 4.0) ;
    maxLeadingMinusDescender = fmax (maxLeadingMinusDescender, [font leading] - [font descender]) ;
  }
  const BOOL maxLineHeightHasChanged = (mMaxAscender != maxAscender) || (mMaxLeadingMinusDescender != maxLeadingMinusDescender) ;
  if (maxLineHeightHasChanged) {
    // NSLog (@"Max line Height: %f", maxLineHeight) ;
    mMaxAscender = maxAscender ;
    mMaxLeadingMinusDescender = maxLeadingMinusDescender ;
  //--- Set new value to default settings
    NSMutableParagraphStyle * paragraghStyle = [[NSMutableParagraphStyle alloc] init] ;
    [paragraghStyle setMaximumLineHeight:mMaxAscender + mMaxLeadingMinusDescender] ;
    [paragraghStyle setMinimumLineHeight:mMaxAscender + mMaxLeadingMinusDescender] ;
    if ([mFontAttributesDictionaryArray count] > 0) {
      NSMutableDictionary * d = [mFontAttributesDictionaryArray objectAtIndex: 0] ;
      [d setObject:paragraghStyle forKey: NSParagraphStyleAttributeName] ;
    }
  }
  if (NULL != outLineHeightDidChange) {
    * outLineHeightDidChange = maxLineHeightHasChanged ;
  }
}

//--------------------------------------------------------------------------------------------------

- (OC_GGS_TextSyntaxColoring *) initWithSourceString: (NSString *) inSource
                                tokenizer: (OC_Lexique *) inTokenizer
                                documentData: (OC_GGS_DocumentData *) inDocumentData
                                issueArray: (NSArray *) inIssueArray {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mTokenizer = inTokenizer ;
    documentData = inDocumentData ;
    mSourceTextStorage = [NSTextStorage new] ;
  //  mSourceTextStorage.font = [NSFont fontWithName: @"Consolas" size:14.0] ;
    mTokenArray = [NSMutableArray new] ;
    mTemplateTextAttributeDictionary = [NSMutableDictionary new] ;
    mUndoManager = [PMUndoManager new] ;
    mTextDisplayDescriptorSet = [NSMutableSet new] ;
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver: self
      selector:@selector (undoManagerCheckPointNotification:)
      name: NSUndoManagerCheckpointNotification
      object: mUndoManager
    ] ;
    [[NSNotificationCenter defaultCenter]
      addObserver: self
      selector: @selector (undoManagerCheckPointNotification:)
      name: NSUndoManagerDidUndoChangeNotification
      object: mUndoManager
    ] ;
    [[NSNotificationCenter defaultCenter]
      addObserver: self
      selector: @selector (undoManagerCheckPointNotification:)
      name: NSUndoManagerDidRedoChangeNotification
      object: mUndoManager
    ] ;
  //--------------------------------------------------- Add foreground color observers
    NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
    NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
    OC_GGS_ColorTransformer * colorTransformer = [OC_GGS_ColorTransformer new] ;
    if ([mTokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_foreground_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver: self
        forKeyPath: keyPath
        options: NSKeyValueObservingOptionNew
        context:(void *) (TAG_FOR_TEMPLATE_FOREGROUND_COLOR)
      ] ;
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_foreground_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey: name] ;
      if (data != nil) {
        NSColor * color = [colorTransformer transformedValue: data] ;
        [mTemplateTextAttributeDictionary setObject: color forKey: NSForegroundColorAttributeName] ;
      }else{
        [mTemplateTextAttributeDictionary setObject: [NSColor blackColor] forKey: NSForegroundColorAttributeName] ;
      }
    }
    for (NSInteger i=0 ; i< (NSInteger) mTokenizer.styleCount ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver: self
        forKeyPath: keyPath
        options: NSKeyValueObservingOptionNew
        context: (void *) (TAG_FOR_FOREGROUND_COLOR | i)
      ] ;
    }
  //--------------------------------------------------- Add background color observers
    if ([mTokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_background_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver: self
        forKeyPath: keyPath
        options: NSKeyValueObservingOptionNew
        context:(void *) (TAG_FOR_TEMPLATE_BACKGROUND_COLOR)
      ] ;
      keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_enable_template_background, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:NSKeyValueObservingOptionNew
        context:(void *) (TAG_FOR_ENABLE_TEMPLATE_BACKGROUND)
      ] ;
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_enable_template_background, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      if ([defaults boolForKey:name]) {
        name = [NSString stringWithFormat:@"%@_%@", GGS_template_background_color, [mTokenizer styleIdentifierForStyleIndex:0]] ;
        NSData * data = [defaults dataForKey:name] ;
        if (data != nil) {
          NSColor * color = [colorTransformer transformedValue: data] ;
          [mTemplateTextAttributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
        }else{
          [mTemplateTextAttributeDictionary setObject:[NSColor blackColor] forKey:NSBackgroundColorAttributeName] ;
        }
      }
    }
    for (NSInteger i=0 ; i<(NSInteger) mTokenizer.styleCount ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_background_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:NSKeyValueObservingOptionNew
        context:(void *) (TAG_FOR_BACKGROUND_COLOR | i)
      ] ;
      keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_enable_background, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:NSKeyValueObservingOptionNew
        context:(void *) (TAG_FOR_ENABLING_BACKGROUND | i)
      ] ;
    }
  //--------------------------------------------------- Add font observers
    if ([mTokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat: @"values.%@_%@", GGS_template_font, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver: self
        forKeyPath: keyPath
        options: NSKeyValueObservingOptionNew
        context:(void *) (TAG_FOR_TEMPLATE_FONT_ATTRIBUTE)
      ] ;
    //--- Add font attribute   
      NSString * name = [NSString stringWithFormat: @"%@_%@", GGS_template_font, [mTokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey: name] ;
      if (data != nil) {
        NSFont * font = (NSFont *) [NSUnarchiver unarchiveObjectWithData: data] ;
        [mTemplateTextAttributeDictionary setObject: font forKey: NSFontAttributeName] ;
      }
    }
    for (NSInteger i=0 ; i<(NSInteger) mTokenizer.styleCount ; i++) {
      NSString * keyPath = [NSString stringWithFormat: @"values.%@_%@", GGS_named_font, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver: self
        forKeyPath: keyPath
        options: NSKeyValueObservingOptionNew
        context: (void *) (TAG_FOR_FONT_ATTRIBUTE | i)
      ] ;
    }
  //---
    // NSLog (@"%p [mTokenizer styleCount] %u", mTokenizer, [mTokenizer styleCount]) ;
    mFontAttributesDictionaryArray = [NSMutableArray new] ;
    for (NSInteger i=0 ; i<(NSInteger) mTokenizer.styleCount ; i++) {
      NSMutableDictionary * attributeDictionary = [NSMutableDictionary new] ;
    //--- Add foreground color   
      NSString * name = [NSString stringWithFormat: @"%@_%@", GGS_named_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      NSData * data = [defaults dataForKey: name] ;
      if (data != nil) {
        NSColor * color = [colorTransformer transformedValue: data] ;
        if (color == nil) {
          color = [NSColor blackColor] ;
        }
        [attributeDictionary setObject: color forKey: NSForegroundColorAttributeName] ;
      }else{
        [attributeDictionary setObject: [NSColor blackColor] forKey: NSForegroundColorAttributeName] ;
      }
    //--- Add background color   
      name = [NSString stringWithFormat: @"%@_%@", GGS_named_enable_background, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      if ([defaults boolForKey: name]) {
        name = [NSString stringWithFormat: @"%@_%@", GGS_named_background_color, [mTokenizer styleIdentifierForStyleIndex:i]] ;
        data = [defaults dataForKey: name] ;
        if (data != nil) {
          NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
          if (color == nil) {
            color = [NSColor whiteColor] ;
          }
          [attributeDictionary setObject:color forKey: NSBackgroundColorAttributeName] ;
        }else{
          [attributeDictionary setObject:[NSColor blackColor] forKey: NSBackgroundColorAttributeName] ;
        }
      }
    //--- Add font attribute   
      name = [NSString stringWithFormat: @"%@_%@", GGS_named_font, [mTokenizer styleIdentifierForStyleIndex:i]] ;
      data = [defaults dataForKey: name] ;
      if (data != nil) {
        NSFont * font = (NSFont *) [NSUnarchiver unarchiveObjectWithData: data] ; // §
        [attributeDictionary setObject: font forKey: NSFontAttributeName] ;
      }
    //--- Add dictionary
      [mFontAttributesDictionaryArray addObject: attributeDictionary] ;
    }
  //--- Max line height
    [self computeMaxLineHeight: NULL] ;
  //---
    [[NSNotificationCenter defaultCenter]
      addObserver: self
      selector: @selector(textStorageDidProcessEditingNotification:)
      name: NSTextStorageDidProcessEditingNotification
      object: mSourceTextStorage
    ] ;
  //--- Enter source string
    [mSourceTextStorage beginEditing] ;
    [mSourceTextStorage replaceCharactersInRange: NSMakeRange (0, mSourceTextStorage.length) withString: inSource] ;
    [mSourceTextStorage endEditing] ;
  //---
    [self setIssueArray: inIssueArray] ;
  }
  return self ;
}

//--------------------------------------------------------------------------------------------------

- (void) detach {
  [[NSNotificationCenter defaultCenter]
    removeObserver: self
    name: NSUndoManagerCheckpointNotification
    object: mUndoManager
  ] ;
  [[NSNotificationCenter defaultCenter]
    removeObserver: self
    name: NSUndoManagerDidUndoChangeNotification
    object: mUndoManager
  ] ;
  [[NSNotificationCenter defaultCenter]
    removeObserver: self
    name:NSUndoManagerDidRedoChangeNotification
    object: mUndoManager
  ] ;
//---
  [[NSNotificationCenter defaultCenter]
    removeObserver: self
    name: NSTextStorageDidProcessEditingNotification
    object: mSourceTextStorage
  ] ;
//---
//  NSLog (@"%s:observationInfo %@", __PRETTY_FUNCTION__, (id) self.observationInfo) ;
  documentData = nil ;
  [mTokenizer detach] ;
  mTokenizer = nil ;
}


//--------------------------------------------------------------------------------------------------

- (NSString *) sourceString {
  return mSourceTextStorage.string ;
}

//--------------------------------------------------------------------------------------------------

- (void) replaceSourceStringWithString: (NSString *) inString {
  if (![mSourceTextStorage.string isEqualToString: inString]) {
    NSArray * allDisplays = mTextDisplayDescriptorSet.allObjects ;
  //--- Save selection
    NSRange * savedRangeArray = malloc (sizeof (NSRange) * allDisplays.count) ;
    NSInteger idx = 0 ;
    for (OC_GGS_TextDisplayDescriptor * tdd in allDisplays) {
      const NSRange selectedRange = [tdd selectedRange] ;
      savedRangeArray [idx] = selectedRange ;
      idx += 1 ;
    }
    [mSourceTextStorage beginEditing] ;
    [mSourceTextStorage replaceCharactersInRange: NSMakeRange (0, mSourceTextStorage.length) withString: inString] ;
    [mSourceTextStorage endEditing] ;
  //--- Restore selection
    const NSRange newFullRange = NSMakeRange (0, mSourceTextStorage.length) ;
    idx = 0 ;
    for (OC_GGS_TextDisplayDescriptor * tdd in allDisplays) {
      const NSRange savedSelectedRange = savedRangeArray [idx] ;
      const NSRange newRange = NSIntersectionRange (savedSelectedRange, newFullRange) ;
      [tdd setSelectionRange: newRange] ;
      idx += 1 ;
    }
  //--- Free selection range array
    free (savedRangeArray) ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) replaceCharactersInRange: (NSRange) inRange
         withString: (NSString *) inReplaceString {
  const NSRange replacementRange = {inRange.location, inReplaceString.length} ;
  NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
    [mSourceTextStorage.string substringWithRange:inRange], @"str",
    NSStringFromRange (replacementRange), @"range",
    nil
  ] ;
  [mUndoManager
    registerUndoWithTarget: self
    selector: @selector (replaceUsingDictionary:)
    object: d
  ] ;
  [mSourceTextStorage beginEditing] ;
  [mSourceTextStorage replaceCharactersInRange: inRange withString: inReplaceString] ;
  [mSourceTextStorage endEditing] ;
}

//--------------------------------------------------------------------------------------------------

- (void) replaceUsingDictionary: (NSDictionary *) inDictionary {
  [self
    replaceCharactersInRange: NSRangeFromString ([inDictionary objectForKey:@"range"])
    withString: [inDictionary objectForKey:@"str"]
  ] ;
}

//--------------------------------------------------------------------------------------------------

- (NSUndoManager *) undoManager {
  return mUndoManager ;
}

//--------------------------------------------------------------------------------------------------

- (OC_Lexique *) tokenizer {
  return mTokenizer ;
}

//--------------------------------------------------------------------------------------------------

- (NSArray *) tokenArray {
  return mTokenArray ;
}

//--------------------------------------------------------------------------------------------------

- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex {
  return [mTokenizer atomicSelectionForToken:inTokenIndex] ;
}

//--------------------------------------------------------------------------------------------------

#pragma mark Text attribute did change

//--------------------------------------------------------------------------------------------------

- (void) applyTextAttributeForIndex: (NSInteger) inChangedColorIndex {
  if ((mTokenizer != NULL) && ([mSourceTextStorage length] > 0)) {
    [mSourceTextStorage beginEditing] ;
  //--- Change default style ?
    if (inChangedColorIndex == 0) {
      const NSRange allTextRange = {0, [mSourceTextStorage length]} ;
      [mSourceTextStorage
        addAttributes: [mFontAttributesDictionaryArray objectAtIndex:0]
        range: allTextRange
      ] ;
      [mSourceTextStorage fixAttributesInRange: allTextRange] ;
      for (NSUInteger i=0 ; i<mTokenArray.count ; i++) {
        OC_Token * token = [mTokenArray objectAtIndex:i] ;
        const NSInteger colorIndex = [token style] ;
        const NSRange range = [token range] ;
        if (colorIndex == -2) {
          [mSourceTextStorage
            addAttributes: mTemplateTextAttributeDictionary
            range: range
          ] ;
          [mSourceTextStorage fixAttributesInRange: range] ;
        }else if (colorIndex == -1) {
        
        }else if (colorIndex > 0) {
          [mSourceTextStorage
            addAttributes: [mFontAttributesDictionaryArray objectAtIndex:(NSUInteger) colorIndex]
            range: range
          ] ;
          [mSourceTextStorage fixAttributesInRange: range] ;
        }
      }    
    }else{
      for (NSUInteger i=0 ; i<mTokenArray.count ; i++) {
        OC_Token * token = [mTokenArray objectAtIndex:i] ;
        const NSInteger colorIndex = [token style] ;
        if (colorIndex == inChangedColorIndex) {
          const NSRange range = [token range] ;
          [mSourceTextStorage
            addAttributes: [mFontAttributesDictionaryArray objectAtIndex:0]
            range: range
          ] ;
          [mSourceTextStorage fixAttributesInRange: range] ;
          if (colorIndex == -2) {
            [mSourceTextStorage
              addAttributes:mTemplateTextAttributeDictionary
              range:range
            ] ;
            [mSourceTextStorage fixAttributesInRange: range] ;
          }else if (colorIndex == -1) {
          
          }else if (colorIndex > 0) {
            [mSourceTextStorage
              addAttributes:[mFontAttributesDictionaryArray objectAtIndex:(NSUInteger) colorIndex]
              range:range
            ] ;
            [mSourceTextStorage fixAttributesInRange: range] ;
          }
        }
      }
    }
    [mSourceTextStorage endEditing] ;
  }
}

//--------------------------------------------------------------------------------------------------

#pragma mark Error and Warning Display

//--------------------------------------------------------------------------------------------------

- (NSRange) rangeForLine: (NSInteger) inLineNumber {
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
  }
  return range ;
}

//--------------------------------------------------------------------------------------------------

- (void) updateIssuesForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
//  const NSRange previousRange = {inEditedRange.location, inEditedRange.length - (NSUInteger) inChangeInLength} ;
  const NSRange previousRange = {
    inEditedRange.location,
    (inChangeInLength >= 0)
      ? (inEditedRange.length - (NSUInteger) inChangeInLength)
      : (inEditedRange.length + (NSUInteger) -inChangeInLength)
  } ;
  for (PMIssueDescriptor * issue in mIssueArray) {
    [issue updateLocationForPreviousRange:previousRange changeInLength:inChangeInLength] ;
  }
//---
  for (OC_GGS_TextDisplayDescriptor * textDisplay in mTextDisplayDescriptorSet) {
    [textDisplay setTextDisplayIssueArray:mIssueArray] ; 
  }
//--- mIssueArray is nil on init, so this prevent search result to be changed by insertion of file contents
  if (nil != mIssueArray) {
    for (OC_GGS_Document * doc in [[NSDocumentController sharedDocumentController] documents]) {
      [doc
        updateSearchResultForFile:self.documentData.fileURL.path
        previousRange:previousRange
        changeInLength:inChangeInLength
      ] ; 
    }
  }
}

//--------------------------------------------------------------------------------------------------

- (void) setIssueArray: (NSArray *) inIssueArray {
  mIssueArray = inIssueArray.mutableCopy ;
  // NSLog (@"mIssueArray %@", mIssueArray) ;
  for (OC_GGS_TextDisplayDescriptor * textDisplay in mTextDisplayDescriptorSet) {
    [textDisplay setTextDisplayIssueArray:mIssueArray] ; 
  }
}

//--------------------------------------------------------------------------------------------------

#pragma mark Syntax Coloring

//--------------------------------------------------------------------------------------------------

- (void) updateSyntaxColoringForEditedRange: (NSRange) inEditedRange
         changeInLength: (NSInteger) inChangeInLength {
  const NSUInteger textLength = mSourceTextStorage.string.length ;
  if (textLength > 0) {
    NSInteger firstIndexToRedraw = 0 ;
    NSInteger lastIndexToRedraw = -1 ;
    NSInteger eraseRangeStart = 0 ;
    NSInteger eraseRangeEnd = 0 ;
    [mTokenizer
      tokenizeForSourceString: mSourceTextStorage.string
      tokenArray: mTokenArray // Array of OC_Token
      editedRange: inEditedRange
      changeInLength: inChangeInLength
      firstIndexToRedraw: & firstIndexToRedraw
      lastIndexToRedraw: & lastIndexToRedraw
      eraseRangeStart: & eraseRangeStart
      eraseRangeEnd: & eraseRangeEnd
    ] ;
  //--- Erase text attributes
    if (eraseRangeEnd >= (NSInteger) textLength) {
      eraseRangeEnd = (NSInteger) (textLength - 1) ;
    }
    [mSourceTextStorage beginEditing] ;
    if (eraseRangeStart < eraseRangeEnd) {
      const NSRange eraseRange = {(NSUInteger) eraseRangeStart, (NSUInteger) (eraseRangeEnd - eraseRangeStart)} ;
      [mSourceTextStorage
        addAttributes: [mFontAttributesDictionaryArray objectAtIndex: 0]
        range: eraseRange
      ] ;
      [mSourceTextStorage fixAttributesInRange: eraseRange] ;
    }
  //--- Perform text coloring
    for (NSInteger i=firstIndexToRedraw ; i<=lastIndexToRedraw ; i++) {
      OC_Token * token = [mTokenArray objectAtIndex:(NSUInteger) i] ;
      const NSRange range = [token range] ;
      const NSInteger style = [token style] ;
      if (style == -1) { // Error
        [mSourceTextStorage
          addAttribute: NSForegroundColorAttributeName
          value: [NSColor redColor]
          range:range
        ] ;
      }else if (style == -2) { // Template string
        [mSourceTextStorage
          addAttributes: mTemplateTextAttributeDictionary
          range: range
        ] ;
        [mSourceTextStorage fixAttributesInRange: range] ;
      }else if (style > 0) {
        [mSourceTextStorage
          addAttributes: [mFontAttributesDictionaryArray objectAtIndex:(NSUInteger) style]
          range: range
        ] ;
        [mSourceTextStorage fixAttributesInRange: range] ;
      }
    }
    [mSourceTextStorage endEditing] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) textStorageDidProcessEditingNotification: (NSNotification *) inNotification {
  const NSRange editedRange = mSourceTextStorage.editedRange ;
  const NSInteger changeInLength = mSourceTextStorage.changeInLength ;
  [self updateSyntaxColoringForEditedRange: editedRange changeInLength: changeInLength] ;
  [self updateIssuesForEditedRange: editedRange changeInLength: changeInLength] ;
//---
  NSMenu * menu = mTokenizer.menuForEntryPopUpButton ;
  for (OC_GGS_TextDisplayDescriptor * tdd in mTextDisplayDescriptorSet) {
    [tdd populatePopUpButtonWithMenu: menu] ;
  }
//--- If there is no enabled timer, create one
  if (nil == mTimerForAutosaving) {
    mTimerForAutosaving = [NSTimer
      timerWithTimeInterval: 5.0
      target: self
      selector: @selector (autosaveTimerDidFire:)
      userInfo: nil
      repeats: NO
    ] ;
    [[NSRunLoop mainRunLoop]
      addTimer: mTimerForAutosaving
      forMode: NSDefaultRunLoopMode
    ] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) autosaveTimerDidFire: (NSTimer *) inTimer {
  [mTimerForAutosaving invalidate] ;
  mTimerForAutosaving = nil ;
  [documentData save] ;
}

//--------------------------------------------------------------------------------------------------

- (void) breakUndoCoalescing {
  for (NSLayoutManager * lm in mSourceTextStorage.layoutManagers) {
    for (NSTextContainer * tc in lm.textContainers) {
      [tc.textView breakUndoCoalescing] ;
    }    
  }
}

//--------------------------------------------------------------------------------------------------
//           C O M M E N T R A N G E
//--------------------------------------------------------------------------------------------------

- (NSRange) commentRange: (NSRange) inSelectedRangeValue {
  [mSourceTextStorage beginEditing] ;
//---
  NSAttributedString * blockCommentString = [[NSAttributedString alloc] initWithString:[mTokenizer blockComment] attributes:nil] ;
  NSMutableAttributedString * mutableSourceString = mSourceTextStorage ;
  NSString * sourceString = [mutableSourceString string] ;
  const NSRange lineRange = [sourceString lineRangeForRange:inSelectedRangeValue] ;
  NSInteger insertedCharsCount = 0 ;
  NSRange currentLineRange = [sourceString lineRangeForRange:NSMakeRange (lineRange.location + lineRange.length - 1, 1)] ;
  do {
    [mutableSourceString insertAttributedString:blockCommentString atIndex:currentLineRange.location] ;
    insertedCharsCount += [blockCommentString length] ;
    if (currentLineRange.location > 0) {
      currentLineRange = [sourceString lineRangeForRange:NSMakeRange (currentLineRange.location - 1, 1)] ;
    }
  }while ((currentLineRange.location > 0) && (currentLineRange.location >= lineRange.location)) ;
//---
  [mSourceTextStorage endEditing] ;
//--- Update selected range
  const NSRange newSelectedRange = NSMakeRange (inSelectedRangeValue.location, inSelectedRangeValue.length + (NSUInteger) insertedCharsCount) ;
//--- Register undo
  [mUndoManager
    registerUndoWithTarget: self
    selector: @selector (uncommentRangeForUndo:)
    object: [NSValue valueWithRange: newSelectedRange]
  ] ;
//---
  return newSelectedRange ;
}

//--------------------------------------------------------------------------------------------------

- (void) commentRangeForUndo: (NSValue *) inRangeValue { // An NSValue of NSRange
  [self commentRange: inRangeValue.rangeValue] ;
}

//--------------------------------------------------------------------------------------------------
//
//                       U N C O M M E N T R A N G E                                             
//
// Cette méthode a plusieurs rôles :                                                             
//   - supprimer les marques de commentaires des lignes concernées par la sélection, uniquement quand le
//     commentaire commence une ligne ;                                                          
//   - ajuster la sélection en conséquence ; en effet, dès que la méthode replaceCharactersInRange:withString: est
//     appelée, Cocoa ramène la sélection à un point d'insertion. La sélection est ajustée et maintenue dans la
//     variable finalSelectedRange.                                                              
//
// Le plus difficile est l'ajustement de la sélection. Pour cela, on calcule :                   
//   - le nombre beforeSelectionCharacterCount de caractères du commentaire supprimé qui sont avant la sélection ; si
//     ce nombre est > 0, on le début de la sélection du min entre ce nombre et le nombre de caractères du
//     commentaire ;                                                                             
//   - le nombre withinSelectionCharacterCount de caractères du commentaire supprimé qui sont à l'intérieur de la
//     sélection ; si ce nombre est > 0, on le retranche de la longueur de la sélection.          
//
//--------------------------------------------------------------------------------------------------

static inline NSUInteger imin (const NSUInteger a, const NSUInteger b) { return a < b ? a : b ; }
static inline NSUInteger imax (const NSUInteger a, const NSUInteger b) { return a > b ? a : b ; }

//--------------------------------------------------------------------------------------------------

- (NSRange) uncommentRange: (NSRange) initialSelectedRange {
//---
  [mSourceTextStorage beginEditing] ;
//--- Block comment string
  NSString * blockCommentString = [mTokenizer blockComment] ;
  const NSUInteger blockCommentLength = [blockCommentString length] ;
//--- Get source string
  NSMutableAttributedString * mutableSourceString = mSourceTextStorage ;
  NSString * sourceString = [mutableSourceString string] ;
//--- Final selection range
  NSRange finalSelectedRange = initialSelectedRange ;
//--- Get line range that is affected by the operation
  const NSRange lineRange = [sourceString lineRangeForRange:initialSelectedRange] ;
  NSRange currentLineRange = [sourceString lineRangeForRange:NSMakeRange (lineRange.location + lineRange.length - 1, 1)] ;
  do {
    NSString * lineString = [sourceString substringWithRange:currentLineRange] ;
    if ([lineString compare:blockCommentString options:NSLiteralSearch range:NSMakeRange (0, blockCommentLength)] == NSOrderedSame) {
      [mutableSourceString replaceCharactersInRange:NSMakeRange (currentLineRange.location, blockCommentLength) withString:@""] ;
    //--- Examen du nombre de caractères à l'intérieur de la sélection
      const NSInteger withinSelectionCharacterCount = 
        (NSInteger) imin (currentLineRange.location + blockCommentLength, finalSelectedRange.location + finalSelectedRange.length)
      -
        (NSInteger) imax (currentLineRange.location, finalSelectedRange.location) ;
      if (withinSelectionCharacterCount > 0) {
        finalSelectedRange.length -= (NSUInteger) withinSelectionCharacterCount ;
      }
    //--- Examen du nombre de caractères avant la sélection
      const NSInteger beforeSelectionCharacterCount = ((NSInteger) finalSelectedRange.location) - ((NSInteger) currentLineRange.location) ;
      if (beforeSelectionCharacterCount > 0) {
        finalSelectedRange.location -= imin (blockCommentLength, (NSUInteger) beforeSelectionCharacterCount) ;
      }
    }
    if (currentLineRange.location > 0) {
      currentLineRange = [sourceString lineRangeForRange:NSMakeRange (currentLineRange.location - 1, 1)] ;
    }
  }while ((currentLineRange.location > 0) && (currentLineRange.location >= lineRange.location)) ;
//---
  [mSourceTextStorage endEditing] ;
//--- Register undo
  [mUndoManager 
    registerUndoWithTarget: self
    selector: @selector (commentRangeForUndo:)
    object: [NSValue valueWithRange: finalSelectedRange]
  ] ;
//---
  return finalSelectedRange ;
}

//--------------------------------------------------------------------------------------------------

- (void) uncommentRangeForUndo: (NSValue *) inRangeValue { // An NSValue of NSRange
  [self uncommentRange:inRangeValue.rangeValue] ;
}

//--------------------------------------------------------------------------------------------------

- (void) undoManagerCheckPointNotification: (NSNotification *) inNotification {
  isDirty = mTimerForAutosaving != nil ;
  for (OC_GGS_TextDisplayDescriptor * textDisplayDescriptor in mTextDisplayDescriptorSet) {
    textDisplayDescriptor.isDirty = isDirty ;
  }
}

//--------------------------------------------------------------------------------------------------

- (void) documentHasBeenSaved {
  [self undoManagerCheckPointNotification:nil] ;
}

//--------------------------------------------------------------------------------------------------

#pragma mark observeValueForKeyPath

//--------------------------------------------------------------------------------------------------

- (void) observeValueForKeyPath: (NSString *) inKeyPath
         ofObject: (id) inObject
         change: (NSDictionary *) inChangeDictionary
         context: (void *) inContext {
  if (mTokenizer != NULL) {
    [mSourceTextStorage beginEditing] ;
    BOOL lineHeightDidChange = NO ;
    NSColor * color = nil ;
    NSMutableDictionary * d = nil ;
    NSData * data = [inObject valueForKeyPath: inKeyPath] ;
    const NSUInteger tag = ((NSUInteger) inContext) & TAG_MASK ;
    const NSUInteger idx = ((NSUInteger) inContext) & ~ TAG_MASK ;
    switch (tag) {
    case TAG_FOR_FOREGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSKeyedUnarchiver unarchiveObjectWithData: data] ;
      }
      d = [mFontAttributesDictionaryArray objectAtIndex: idx] ;
      [d setObject: color forKey: NSForegroundColorAttributeName] ;
      [self applyTextAttributeForIndex: (NSInteger) idx] ;
      break;
    case TAG_FOR_TEMPLATE_FOREGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSKeyedUnarchiver unarchiveObjectWithData: data] ;
      }
      [mTemplateTextAttributeDictionary setObject:color forKey:NSForegroundColorAttributeName] ;
      [self applyTextAttributeForIndex: -2] ;
      break;
    case TAG_FOR_ENABLING_BACKGROUND:
      if (data != nil)  {
        const BOOL enableBackground = [[inObject valueForKeyPath:inKeyPath] boolValue] ;
        d = [mFontAttributesDictionaryArray objectAtIndex:idx] ;
        if (enableBackground) {
          NSString * keyPath = [NSString stringWithFormat:@"%@_%@",
            GGS_named_background_color,
            [mTokenizer styleIdentifierForStyleIndex:(NSInteger) idx]
          ] ;
          NSData * colorData = [[NSUserDefaults standardUserDefaults] objectForKey:keyPath] ;
          color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:colorData] ;
          [d setValue:color forKey:NSBackgroundColorAttributeName] ;
        }else{
          [d removeObjectForKey:NSBackgroundColorAttributeName] ;
        }
        [self applyTextAttributeForIndex:(NSInteger) idx] ;
      }
      break;
    case TAG_FOR_BACKGROUND_COLOR:
      if (data == nil) {
        color = [NSColor whiteColor] ;
      }else{
        color = (NSColor *) [NSKeyedUnarchiver unarchiveObjectWithData:data] ;
      }
      d = [mFontAttributesDictionaryArray objectAtIndex:idx] ;
      [d setObject:color forKey: NSBackgroundColorAttributeName] ;
      [self applyTextAttributeForIndex: (NSInteger) idx] ;
      break;
    case TAG_FOR_ENABLE_TEMPLATE_BACKGROUND :
      if (data != nil)  {
        const BOOL enableBackground = [[inObject valueForKeyPath:inKeyPath] boolValue] ;
        if (enableBackground) {
          NSString * keyPath = [NSString stringWithFormat:@"%@_%@",
            GGS_template_background_color,
            [mTokenizer styleIdentifierForStyleIndex:(NSInteger) idx]
          ] ;
          NSData * colorData = [[NSUserDefaults standardUserDefaults] objectForKey:keyPath] ;
          color = (NSColor *) [NSKeyedUnarchiver unarchiveObjectWithData:colorData] ;
          [mTemplateTextAttributeDictionary setValue:color forKey:NSBackgroundColorAttributeName] ;
        }else{
          [mTemplateTextAttributeDictionary removeObjectForKey:NSBackgroundColorAttributeName] ;
        }
        [self applyTextAttributeForIndex:-2] ;
      }
      break ;
    case TAG_FOR_TEMPLATE_BACKGROUND_COLOR:
      if (data != nil) {
        color = (NSColor *) [NSUnarchiver unarchiveObjectWithData: data] ;
      }
      if (color == nil) {
        color = [NSColor whiteColor] ;
      }
      [mTemplateTextAttributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
      [self applyTextAttributeForIndex:-2] ;
      break;
    case TAG_FOR_FONT_ATTRIBUTE:
      d = [mFontAttributesDictionaryArray objectAtIndex: idx] ;
      [d setObject:[NSUnarchiver unarchiveObjectWithData: data] forKey: NSFontAttributeName] ;
      [self computeMaxLineHeight: & lineHeightDidChange] ;
      [self applyTextAttributeForIndex:lineHeightDidChange ? 0 : (NSInteger) idx] ;
      break;
    case TAG_FOR_TEMPLATE_FONT_ATTRIBUTE:
      [mTemplateTextAttributeDictionary setObject: [NSUnarchiver unarchiveObjectWithData:data] forKey: NSFontAttributeName] ;
      [self computeMaxLineHeight: & lineHeightDidChange] ;
      [self applyTextAttributeForIndex: lineHeightDidChange ? 0 : -2] ;
      break;
    default:
      break;
    }
    [mSourceTextStorage endEditing] ;
  }
}

//--------------------------------------------------------------------------------------------------

#pragma mark Source Indexing

//--------------------------------------------------------------------------------------------------

- (BOOL) sourceFile:(NSString *) inFile1
         newerThanFile: (NSString *) inFile2 {
  NSFileManager * fm = [NSFileManager new] ;
  NSDictionary * file1_dictionary = [fm attributesOfItemAtPath:inFile1 error:NULL] ;
  NSDate * file1_modificationDate = [file1_dictionary fileModificationDate] ;
  NSDictionary * file2_dictionary = [fm attributesOfItemAtPath:inFile2 error:NULL] ;
  NSDate * file2_modificationDate = [file2_dictionary fileModificationDate] ;
  return NSOrderedDescending == [file1_modificationDate compare:file2_modificationDate] ;
}

//--------------------------------------------------------------------------------------------------

- (void) parseSourceFileForBuildingIndexFile: (NSArray *) inArray {
  NSString * sourceFileFullPath = [inArray objectAtIndex: 0] ;
  const NSInteger selectedToolIndex = [[inArray objectAtIndex: 1] integerValue] ;
  NSString * indexFileFullPath = [inArray objectAtIndex: 2] ;
  NSString * compilerToolPath = [gCocoaApplicationDelegate compilerToolPath: selectedToolIndex] ;
//--- Command line tool does actually exist ? (First argument is not "?")
  if (! [compilerToolPath isEqualToString: @"?"]) {
  //--- Build argument array
    NSMutableArray * arguments = [NSMutableArray new] ;
    [arguments addObject: sourceFileFullPath] ;
    NSString * indexArgument = [NSString stringWithFormat: @"--mode=indexing:%@", indexFileFullPath] ;
    [arguments addObject: indexArgument] ;
  //--- Create task
    NSTask * task = [NSTask new] ;
    [task setLaunchPath: compilerToolPath] ;
    [task setArguments: arguments] ;
  //--- Start task
    [task launch] ;
  //--- Wait the task is completed
    [task waitUntilExit] ;
  }
}

//--------------------------------------------------------------------------------------------------

- (NSArray *) buildIndexingDictionaryArray {
  NSFileManager * fm = [NSFileManager new] ;
  NSMutableArray * result = nil ;
//--- Save all sources
  [[NSDocumentController sharedDocumentController] saveAllDocuments:self] ;
//--- Source directory
  NSString * sourceDirectory = documentData.fileURL.path.stringByDeletingLastPathComponent ;
//--- Project file path directory
  NSDictionary * indexingDescriptors = indexingDescriptorDictionary () ;
  NSString * projectFilePath = nil ;
  NSString * indexingSuffix = nil ;
  NSArray * allDocuments = [OC_GGS_DocumentData allDocuments] ;
  for (NSDocument * document in allDocuments) {
    NSString * possibleIndexingSuffix = [indexingDescriptors valueForKey: document.fileURL.path.pathExtension] ;
    if (possibleIndexingSuffix != nil) {
      projectFilePath = document.fileURL.path ;
      indexingSuffix = possibleIndexingSuffix ;
    }
  }
//--- index directory
  if (projectFilePath.length > 0) {
    NSString * projectFileDirectory = [projectFilePath stringByDeletingLastPathComponent] ;
    NSString * projectFileName = [projectFilePath lastPathComponent] ;
    NSString * projectFileNameModified = [projectFileName stringByReplacingOccurrencesOfString: @"." withString: @"-"] ;
    NSString * modifiedIndexingSuffix = [indexingSuffix stringByReplacingOccurrencesOfString: @"*" withString: projectFileNameModified] ;
    NSString * indexingDirectory = [NSString stringWithFormat: @"%@/%@", projectFileDirectory, modifiedIndexingSuffix] ;
    [fm createDirectoryAtPath: indexingDirectory withIntermediateDirectories: YES attributes: nil error: nil] ;
  //--- Handled extensions
    NSSet * handledExtensions = gCocoaApplicationDelegate.allExtensionsOfCurrentApplication ;
  //--- All files in source directory
    NSArray * files = [fm contentsOfDirectoryAtPath: sourceDirectory error:NULL] ;
    NSMutableArray * availableDictionaryPathArray = [NSMutableArray new] ;
    NSOperationQueue * opq = [NSOperationQueue new] ;
    for (NSString * filePath in files) {
      NSString * fullFilePath = [NSString stringWithFormat:@"%@/%@", sourceDirectory, filePath] ;
      if ([handledExtensions containsObject:[filePath pathExtension]]) {
      //--- Index file path
        NSString * indexFileFullPath = [NSString stringWithFormat:@"%@/%@.plist", indexingDirectory, [filePath lastPathComponent]] ;
      //--- Parse source file ?
        if (! [fm fileExistsAtPath: indexFileFullPath]) { // Parse source file
          NSNumber * toolIndexNumber = [NSNumber numberWithInteger: gCocoaApplicationDelegate.selectedToolIndex] ;
          NSInvocationOperation * op = [[NSInvocationOperation alloc] 
            initWithTarget:self
            selector: @selector (parseSourceFileForBuildingIndexFile:)
            object: [NSArray arrayWithObjects: fullFilePath, toolIndexNumber, indexFileFullPath, nil]
          ] ;
          [opq addOperation: op] ;
          [availableDictionaryPathArray addObject:indexFileFullPath] ;
        }else if ([self sourceFile: fullFilePath newerThanFile: indexFileFullPath]) {
          NSNumber * toolIndexNumber = [NSNumber numberWithInteger: gCocoaApplicationDelegate.selectedToolIndex] ;
          [fm removeItemAtPath: indexFileFullPath error:NULL] ;
          NSInvocationOperation * op = [[NSInvocationOperation alloc] 
            initWithTarget:self
            selector:@selector (parseSourceFileForBuildingIndexFile:)
            object:[NSArray arrayWithObjects: fullFilePath, toolIndexNumber, indexFileFullPath, nil]
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

//--------------------------------------------------------------------------------------------------

static NSInteger numericSort (NSString * inOperand1,
                              NSString * inOperand2,
                              void * inUnusedContext) {
  return [inOperand1 compare:inOperand2 options:NSNumericSearch] ;
}

//--------------------------------------------------------------------------------------------------
// Every plist list is a dictionary: the key is the indexed to token; the 
// associated value is an NSArray of NSString that has the following format:
//   "kind:line:locationIndex:length:sourceFileFullPath"
//--------------------------------------------------------------------------------------------------

- (void) appendIndexingToMenu: (NSMenu *) inMenu
         forRange: (NSRange) inSelectedRange
         textDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inTextDisplayDescriptor {
//--- Check if current has atomic selection
  BOOL hasAtomicSelection = YES ;
  BOOL found = NO ;
  for (NSUInteger i=0 ; (i<[mTokenArray count]) && ! found ; i++) {
    OC_Token * token = [mTokenArray objectAtIndex:i] ;
    const NSRange allTokenCharacterRange = [token range] ;
    found = ((allTokenCharacterRange.location + allTokenCharacterRange.length) > inSelectedRange.location)
         && (allTokenCharacterRange.location <= inSelectedRange.location) ;
    if (found) {
      hasAtomicSelection = [mTokenizer atomicSelectionForToken:[token tokenCode]] ;
    }
  }
//---
  NSString * token = [mSourceTextStorage.string substringWithRange:inSelectedRange] ;
//---
  NSArray * dictionaryArray = self.buildIndexingDictionaryArray ;
//--- Build array of all references of given token
  NSMutableArray * allReferences = [NSMutableArray new] ;
  for (NSDictionary * currentIndexDictionary in dictionaryArray) {
    NSArray * references = [currentIndexDictionary objectForKey: token] ;
    if (references != nil) {
      [allReferences addObjectsFromArray: references] ;
    }
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
    NSMenuItem * item = [inMenu addItemWithTitle:@"Select all token characters" action:@selector (selectAllTokenCharacters:) keyEquivalent:@""] ;
    [item setTarget:inTextDisplayDescriptor.textView] ;
    [item setRepresentedObject:[NSValue valueWithRange:inSelectedRange]] ;
  }
//---
  [inMenu addItem:[NSMenuItem separatorItem]] ;
  if ([kindDictionary count] == 0) {
    NSString * title = [NSString stringWithFormat:@"No index for '%@'", token] ;
    [inMenu addItemWithTitle:title action:nil keyEquivalent:@""] ;
  }else{
    NSArray * indexingTitles = [mTokenizer indexingTitles] ;
    NSArray * allKeys = [[kindDictionary allKeys] sortedArrayUsingFunction:numericSort context:NULL] ;
    BOOL first = YES ;
    for (NSString * kindObject in allKeys) {
      if (first) {
        first = NO ;
      }else{
        [inMenu addItem:[NSMenuItem separatorItem]] ;
      }
      const NSInteger kind = [kindObject integerValue] ;
      NSArray * references = [kindDictionary objectForKey:kindObject] ;
      NSString * title = [NSString
        stringWithFormat:@"%@ (%ld item%@)",
        [indexingTitles objectAtIndex:(NSUInteger) kind],
        [references count],
        (([references count] > 1) ? @"s" : @"")
      ] ;
      [inMenu addItemWithTitle:title action:nil keyEquivalent:@""] ;
      for (NSString * descriptor in references) {
        NSArray * components = [descriptor componentsSeparatedByString:@":"] ;
        NSString * filePath = [components objectAtIndex:4] ;
        title = [NSString stringWithFormat:@"%@, line %@", filePath.lastPathComponent, [components objectAtIndex:1]] ;
        NSMenuItem * item = [inMenu addItemWithTitle:title action:@selector (indexingMenuAction:) keyEquivalent:@""] ;
        [item setTarget:inTextDisplayDescriptor.textView] ;
        [item setRepresentedObject:descriptor] ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

- (void) addDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
  [mTextDisplayDescriptorSet addObject:inDisplayDescriptor] ;
  [inDisplayDescriptor.textView.layoutManager replaceTextStorage:mSourceTextStorage] ;
  NSMenu * menu = mTokenizer.menuForEntryPopUpButton ;
  [inDisplayDescriptor populatePopUpButtonWithMenu:menu] ;
  [inDisplayDescriptor setTextDisplayIssueArray:mIssueArray] ; 
}

//--------------------------------------------------------------------------------------------------

- (void) removeDisplayDescriptor: (OC_GGS_TextDisplayDescriptor *) inDisplayDescriptor {
  [mTextDisplayDescriptorSet removeObject:inDisplayDescriptor] ;
  [mSourceTextStorage removeLayoutManager:inDisplayDescriptor.textView.layoutManager] ;
}

//--------------------------------------------------------------------------------------------------

- (NSUInteger) displayDescriptorCount {
  return mTextDisplayDescriptorSet.count ;
}

//--------------------------------------------------------------------------------------------------

@end

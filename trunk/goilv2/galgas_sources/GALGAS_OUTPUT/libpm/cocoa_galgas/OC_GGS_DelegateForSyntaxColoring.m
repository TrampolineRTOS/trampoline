//---------------------------------------------------------------------------*
//                                                                           *
//  OC_GGS_DelegateForSyntaxColoring.m (started march 7th, 2007)             *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2007, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#import "OC_GGS_DelegateForSyntaxColoring.h"
#import "F_CocoaWrapperForGalgas.h"
#import "OC_GGS_PreferencesController.h"
#import "OC_GGS_Document.h"
#import "OC_Token.h"
#import "OC_Lexique.h"
#import "OC_GGS_TextView.h"
#import "PMCocoaCallsDebug.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

static inline CGFloat floatMin (const CGFloat a, const CGFloat b) { return (a < b) ? a : b ; }
static inline CGFloat floatMax (const CGFloat a, const CGFloat b) { return (a > b) ? a : b ; }

//---------------------------------------------------------------------------*

#define TAG_MASK                          (0xFF000000)
#define TAG_FOR_FOREGROUND_COLOR          (0x80000000)
#define TAG_FOR_BACKGROUND_COLOR          (0x90000000)
#define TAG_FOR_FONT_ATTRIBUTE            (0xA0000000)
#define TAG_FOR_TEMPLATE_FOREGROUND_COLOR (0xB0000000)
#define TAG_FOR_TEMPLATE_BACKGROUND_COLOR (0xC0000000)
#define TAG_FOR_TEMPLATE_FONT_ATTRIBUTE   (0xD0000000)

//---------------------------------------------------------------------------*

@implementation OC_GGS_DelegateForSyntaxColoring

//---------------------------------------------------------------------------*

- (void) refreshShowInvisibleCharacters {
  const BOOL show = [[NSUserDefaults standardUserDefaults] boolForKey:@"PMShowInvisibleCharacters"] ;
  NSArray * layoutManagers = [mTextStorage layoutManagers] ;
  UInt32 n ;
  for (n=0 ; n<[layoutManagers count] ; n++) {
    NSLayoutManager * lm = [layoutManagers objectAtIndex:n HERE] ;
    [lm setShowsInvisibleCharacters:show] ;
  }
}

//---------------------------------------------------------------------------*

- (void) computeMaxLineHeight: (BOOL *) outLineHeightDidChange {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <computeMaxLineHeight:>") ;
  #endif
  NSFont * font = [mTemplateTextAttributeDictionary objectForKey:NSFontAttributeName] ;
  CGFloat maxAscender = [font ascender] + 4.0f ;
  CGFloat maxLeadingMinusDescender = [font leading] - [font descender] ;
  UInt32 i ;
  for (i=0 ; i<[mFontAttributesDictionaryArray count] ; i++) {
    NSDictionary * d = [mFontAttributesDictionaryArray objectAtIndex:i HERE] ;
    font = [d objectForKey:NSFontAttributeName] ;
    maxAscender = floatMax (maxAscender, [font ascender] + 4.0f) ;
    maxLeadingMinusDescender = floatMax (maxLeadingMinusDescender, [font leading] - [font descender]) ;
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
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <computeMaxLineHeight:> DONE") ;
  #endif
}

//---------------------------------------------------------------------------*

- (id) initWithDocument: (OC_GGS_Document *) inDocument
       withSourceString: (NSString *) inSource {
  self = [super init] ;
  if (self) {
    NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
    mDocument = [inDocument retain] ;
    mUndoManager = [[mDocument undoManager] retain] ;
    mTextStorage = [[NSTextStorage alloc] init] ;
    mStyledRangeArray = [[NSMutableArray alloc] init] ;
    mTemplateTextAttributeDictionary = [[NSMutableDictionary alloc] init] ;
  //--- Add "Show Invisible Character" preference observer
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector(myProcessEditing:)
      name: NSTextStorageDidProcessEditingNotification
      object:mTextStorage
    ] ;
  //--- Add editing observer
    [udc
      addObserver:self
      forKeyPath:@"values.PMShowInvisibleCharacters"
      options:0
      context:NULL
    ] ;
    [self refreshShowInvisibleCharacters] ;
  //--------------------------------------------------- Add foreground color observers
    NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
    OC_Lexique * tokenizer = [mDocument tokenizer] ;
    if ([tokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_foreground_color, [tokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_TEMPLATE_FOREGROUND_COLOR)
      ] ;
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_foreground_color, [tokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [mTemplateTextAttributeDictionary setObject:color forKey:NSForegroundColorAttributeName] ;
      }else{
        [mTemplateTextAttributeDictionary setObject:[NSColor blackColor] forKey:NSForegroundColorAttributeName] ;
      }
    }
    NSUInteger i ;
    for (i=0 ; i<[tokenizer styleCount] ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_color, [tokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_FOREGROUND_COLOR | i)
      ] ;
    }
  //--------------------------------------------------- Add background color observers
    if ([tokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_background_color, [tokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_TEMPLATE_BACKGROUND_COLOR)
      ] ;
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_background_color, [tokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [mTemplateTextAttributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
      }else{
        [mTemplateTextAttributeDictionary setObject:[NSColor blackColor] forKey:NSBackgroundColorAttributeName] ;
      }
    }
    for (i=0 ; i<[tokenizer styleCount] ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_background_color, [tokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_BACKGROUND_COLOR | i)
      ] ;
    }
  //--------------------------------------------------- Add font observers
    if ([tokenizer isTemplateLexique]) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_template_font, [tokenizer styleIdentifierForStyleIndex:0]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_TEMPLATE_FONT_ATTRIBUTE)
      ] ;
    //--- Add font attribute   
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_font, [tokenizer styleIdentifierForStyleIndex:0]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSFont * font = (NSFont *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [mTemplateTextAttributeDictionary setObject:font forKey:NSFontAttributeName] ;
      }
    }
    for (i=0 ; i<[tokenizer styleCount] ; i++) {
      NSString * keyPath = [NSString stringWithFormat:@"values.%@_%@", GGS_named_font, [tokenizer styleIdentifierForStyleIndex:i]] ;
      [udc
        addObserver:self
        forKeyPath:keyPath
        options:0
        context:(void *) (TAG_FOR_FONT_ATTRIBUTE | i)
      ] ;
    }
  //---
    // NSLog (@"%p [tokenizer styleCount] %u", tokenizer, [tokenizer styleCount]) ;
    mFontAttributesDictionaryArray = [NSMutableArray new] ;
    [mFontAttributesDictionaryArray retain] ;
    for (i=0 ; i<[tokenizer styleCount] ; i++) {
      NSMutableDictionary * attributeDictionary = [NSMutableDictionary new] ;
    //--- Add foreground color   
      NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [tokenizer styleIdentifierForStyleIndex:i]] ;
      NSData * data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [attributeDictionary setObject:color forKey:NSForegroundColorAttributeName] ;
      }else{
        [attributeDictionary setObject:[NSColor blackColor] forKey:NSForegroundColorAttributeName] ;
      }
    //--- Add background color   
      name = [NSString stringWithFormat:@"%@_%@", GGS_named_background_color, [tokenizer styleIdentifierForStyleIndex:i]] ;
      data = [defaults dataForKey:name] ;
      if (data != nil) {
        NSColor * color = (NSColor *) [NSUnarchiver unarchiveObjectWithData:data] ;
        [attributeDictionary setObject:color forKey:NSBackgroundColorAttributeName] ;
      }else{
        [attributeDictionary setObject:[NSColor blackColor] forKey:NSBackgroundColorAttributeName] ;
      }
    //--- Add font attribute   
      name = [NSString stringWithFormat:@"%@_%@", GGS_named_font, [tokenizer styleIdentifierForStyleIndex:i]] ;
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
    [mTextStorage beginEditing] ;
    // NSLog (@"LINE %d, inSource '%@'", __LINE__, inSource) ;
    [mTextStorage replaceCharactersInRange:NSMakeRange (0, [mTextStorage length]) withString:inSource] ;
    [mTextStorage endEditing] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) dealloc {
  [[NSNotificationCenter defaultCenter]
    removeObserver:self
    name: NSTextStorageDidProcessEditingNotification
    object:mTextStorage
  ];
//--- Remove observers
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  OC_Lexique * tokenizer = [mDocument tokenizer] ;
  UInt32 i ;
  for (i=0 ; i<[mFontAttributesDictionaryArray count] ; i++) {
    [udc
      removeObserver:self
      forKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_background_color, [tokenizer styleIdentifierForStyleIndex:i]]
    ] ;
    [udc
      removeObserver:self
      forKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_color, [tokenizer styleIdentifierForStyleIndex:i]]
    ] ;
    [udc
      removeObserver:self
      forKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_font, [tokenizer styleIdentifierForStyleIndex:i]]
    ] ;
  }
//---
  if ([tokenizer isTemplateLexique]) {
    [udc
      removeObserver:self
      forKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_background_color, [tokenizer styleIdentifierForStyleIndex:0]]
    ] ;
    [udc
      removeObserver:self
      forKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_foreground_color, [tokenizer styleIdentifierForStyleIndex:0]]
    ] ;
    [udc
      removeObserver:self
      forKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_font, [tokenizer styleIdentifierForStyleIndex:0]]
    ] ;
  }
//---
  [super dealloc] ;
}

//---------------------------------------------------------------------------*

- (NSUndoManager *) undoManagerForTextView:(NSTextView *)aTextView {
  // NSLog (@"<undoManagerForTextView:> -> %@", mUndoManager) ;
  return mUndoManager ;
}

//---------------------------------------------------------------------------*

- (NSTextStorage *) textStorage {
  return mTextStorage ;
}

//---------------------------------------------------------------------------*

- (void) breakUndoCoalescing {
  NSArray * layoutManagers = [mTextStorage layoutManagers] ;
  UInt32 n ;
  for (n=0 ; n<[layoutManagers count] ; n++) {
    NSLayoutManager * lm = [layoutManagers objectAtIndex:n HERE] ;
    NSArray * textContainers = [lm textContainers] ;
    UInt32 j ;
    for (j=0 ; j<[textContainers count] ; j++) {
      NSTextContainer * tc = [textContainers objectAtIndex:j HERE] ;
      NSTextView * tw = [tc textView] ;
      [tw breakUndoCoalescing] ;
    }    
  }
}

//---------------------------------------------------------------------------*

- (void) setSourceString: (NSString *) inSource {
  [mUndoManager
     registerUndoWithTarget:self
     selector:@selector (setSourceString:)
     object:[[mTextStorage string] copy]
  ] ;
  [mTextStorage beginEditing] ;
  //  NSLog (@"LINE %d, inSource '%@'", __LINE__, inSource) ;
  [mTextStorage replaceCharactersInRange:NSMakeRange (0, [mTextStorage length]) withString:inSource] ;
  [mTextStorage endEditing] ;
}

//---------------------------------------------------------------------------*

- (NSString *) sourceString {
  return [mTextStorage string] ;
}

//---------------------------------------------------------------------------*

- (void) refreshRulers {
  NSArray * layoutManagers = [mTextStorage layoutManagers] ;
  UInt32 n ;
  for (n=0 ; n<[layoutManagers count] ; n++) {
    NSLayoutManager * lm = [layoutManagers objectAtIndex:n HERE] ;
    NSArray * textContainers = [lm textContainers] ;
    UInt32 j ;
    for (j=0 ; j<[textContainers count] ; j++) {
      NSTextContainer * tc = [textContainers objectAtIndex:j HERE] ;
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

- (void) myProcessEditing: (NSNotification *) inNotification {
 //  NSLog (@"myProcessEditing") ;
//--- 
  OC_Lexique * tokenizer = [mDocument tokenizer] ;
  if (tokenizer != NULL) {
    [self refreshRulers] ;
    if ([mTextStorage length] == 0) {
      #ifdef DEBUG_MESSAGES
        NSLog (@"Empty text") ;
      #endif
    }else{
      NSString * theString = [mTextStorage string] ;
      const NSInteger textLength = [theString length] ;
      const NSRange editedRange = [mTextStorage editedRange] ;
      const NSInteger changeInLength = [mTextStorage changeInLength] ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"OC_GGS_DelegateForSyntaxColoring <myProcessEditing:>, edited range [%d, %d], changeInLength %d", editedRange.location, editedRange.length, changeInLength) ;
      #endif
      NSInteger firstIndexToRedraw = 0 ;
      NSInteger lastIndexToRedraw = 0 ;
      NSInteger eraseRangeStart = 0 ;
      NSInteger eraseRangeEnd = 0 ;
      [tokenizer
        tokenizeForSourceString:theString
        tokenArray:mStyledRangeArray // Array of OC_Token
        editedRange: & editedRange
        changeInLength: changeInLength
        firstIndexToRedraw: & firstIndexToRedraw
        lastIndexToRedraw: & lastIndexToRedraw
        eraseRangeStart: & eraseRangeStart
        eraseRangeEnd: & eraseRangeEnd
      ] ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"scanThenGetStyledRangeArray DONE (%u)", [mFontAttributesDictionaryArray count]) ;
      #endif
    //--- Erase text attributes
      if (eraseRangeEnd >= textLength) {
        eraseRangeEnd = textLength - 1 ;
      }
      if (eraseRangeStart < eraseRangeEnd) {
        const NSRange eraseRange = {eraseRangeStart, eraseRangeEnd - eraseRangeStart} ;
        #ifdef DEBUG_MESSAGES
          NSLog (@"PERFORM REMOVE ATTRIBUTE range [%d, %d] text length %u", eraseRange.location, eraseRange.length, textLength) ;
        #endif
        [mTextStorage
          setAttributes:[mFontAttributesDictionaryArray objectAtIndex:0 HERE]
          range:eraseRange
        ] ;
        #ifdef DEBUG_MESSAGES
          NSLog (@"mTextStorage setAttributes DONE") ;
        #endif
      }
    //--- Perform text coloring
      #ifdef DEBUG_MESSAGES
       NSLog (@"COLORING from %d to %d", firstIndexToRedraw, lastIndexToRedraw) ;
      #endif
      NSInteger i ;
      for (i=firstIndexToRedraw ; i<=lastIndexToRedraw ; i++) {
        OC_Token * token = [mStyledRangeArray objectAtIndex:i HERE] ;
        const NSRange range = [token range] ;
        #ifdef DEBUG_MESSAGES
        //  NSLog (@"PERFORM COLORING '%@' range [%u, %u] [mTextStorage length] %u", [[mTextStorage string] substringWithRange:range], range.location, range.length, [mTextStorage length]) ;
        #endif
        const int style = [token style] ;
        if (style == -1) { // Error
          [mTextStorage
            addAttribute:NSForegroundColorAttributeName
            value:[NSColor redColor]
            range:range
          ] ;
        }else if (style == -2) { // Template string
          [mTextStorage
            addAttributes:mTemplateTextAttributeDictionary
            range:range
          ] ;
        }else if (style > 0) {
          [mTextStorage
            addAttributes:[mFontAttributesDictionaryArray objectAtIndex:style HERE]
            range:range
          ] ;
        }
      }
    }
  }
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <myProcessEditing:> DONE") ;
  #endif
}

//---------------------------------------------------------------------------*

#pragma mark Text attribute did change

//---------------------------------------------------------------------------*

- (void) applyTextAttributeForIndex: (NSInteger) inChangedColorIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <applyTextAttributeForIndex:%u>", inChangedColorIndex) ;
  #endif
  OC_Lexique * tokenizer = [mDocument tokenizer] ;
  if ((tokenizer != NULL) && ([mTextStorage length] > 0)) {
    [self refreshRulers] ;
  //--- Remove observer so that myProcessEditing will not be called at the end of edition
    [[NSNotificationCenter defaultCenter]
      removeObserver:self
      name: NSTextStorageDidProcessEditingNotification
      object:mTextStorage
    ];
    [mTextStorage beginEditing] ;
  //--- Change default style ?
    if (inChangedColorIndex == 0) {
      const NSRange allTextRange = {0, [mTextStorage length]} ;
      [mTextStorage
        setAttributes:[mFontAttributesDictionaryArray objectAtIndex:0 HERE]
        range:allTextRange
      ] ;
      UInt32 i ;
      for (i=0 ; i<[mStyledRangeArray count] ; i++) {
        OC_Token * token = [mStyledRangeArray objectAtIndex:i HERE] ;
        const SInt32 colorIndex = [token style] ;
        const NSRange range = [token range] ;
        if (colorIndex == -2) {
          [mTextStorage
            addAttributes:mTemplateTextAttributeDictionary
            range:range
          ] ;
        }else if (colorIndex == -1) {
        
        }else if (colorIndex > 0) {
          [mTextStorage
            addAttributes:[mFontAttributesDictionaryArray objectAtIndex:colorIndex HERE]
            range:range
          ] ;
        }
      }    
    }else{
      UInt32 i ;
      for (i=0 ; i<[mStyledRangeArray count] ; i++) {
        OC_Token * token = [mStyledRangeArray objectAtIndex:i HERE] ;
        const SInt32 colorIndex = [token style] ;
        if (colorIndex == inChangedColorIndex) {
          const NSRange range = [token range] ;
          #ifdef DEBUG_MESSAGES
            NSLog (@"change attribute for index %d [%d, %d]>", i, range.location, range.length) ;
          #endif
          if (colorIndex == -2) {
            [mTextStorage
              addAttributes:mTemplateTextAttributeDictionary
              range:range
            ] ;
          }else if (colorIndex == -1) {
          
          }else if (colorIndex > 0) {
            [mTextStorage
              addAttributes:[mFontAttributesDictionaryArray objectAtIndex:colorIndex HERE]
              range:range
            ] ;
          }
        }
      }
    }
    [mTextStorage endEditing] ;
  //--- Resinstall observer
    [[NSNotificationCenter defaultCenter]
      addObserver:self
      selector:@selector(myProcessEditing:)
      name: NSTextStorageDidProcessEditingNotification
      object:mTextStorage
    ] ;
    #ifdef DEBUG_MESSAGES
      NSLog (@"OC_GGS_DelegateForSyntaxColoring <applyTextAttributeForIndex:> DONE") ;
    #endif
  }
}

//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath: (NSString *) inKeyPath
         ofObject: (id) inObject
         change: (NSDictionary *) inChangeDictionary
         context: (void *) inContext {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <observeValueForKeyPath:>") ;
  #endif
  if ([inKeyPath isEqualToString:@"values.PMShowInvisibleCharacters"]) {
    [self refreshShowInvisibleCharacters] ;
  }else{
    OC_Lexique * tokenizer = [mDocument tokenizer] ;
    if (tokenizer != NULL) {
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
}

//---------------------------------------------------------------------------*

- (NSArray *) tokenArray { // Array of OC_Token
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <tokenArray> (%u tokens)", [mStyledRangeArray count]) ;
  #endif
  return mStyledRangeArray ;
}

//---------------------------------------------------------------------------*

- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex {
  OC_Lexique * tokenizer = [mDocument tokenizer] ;
  return [tokenizer atomicSelectionForToken:inTokenIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S O U R C E   T E X T    D I D    C H A N G E    S E L E C T I O N      *
//                     N O T I F I C A T I O N                               *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) textViewDidChangeSelection: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_TextView <textViewDidChangeSelection:>") ;
  #endif
  OC_GGS_TextView * textView = [inNotification object] ;
  // NSLog (@"%@", textView) ;
  [textView updateTextLineAndColumnSelectionLocation:nil] ;
  
  NSRange editedRange = [mTextStorage editedRange] ;
  NSInteger changeInLength = [mTextStorage changeInLength] ;
  OC_GGS_Document * doc = [mDocument currentlyEditedDocumentInBuildWindow] ;
  NSString * docPath = doc.fileURL.path ;
  [mDocument
    editedFilePath:docPath
    editedRange:editedRange
    changeInLength:changeInLength
  ] ;
}

//---------------------------------------------------------------------------*

@end

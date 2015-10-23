//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                                                                     *
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
//---------------------------------------------------------------------------------------------------------------------*

#import "OC_Lexique.h"
#import "OC_Token.h"
#import "unicode_character_m.h"

//---------------------------------------------------------------------------------------------------------------------*
//   OC_GGS_TemplateDelimiter                                                                                          *
//---------------------------------------------------------------------------------------------------------------------*

@implementation OC_GGS_TemplateDelimiter

//---------------------------------------------------------------------------------------------------------------------*

@synthesize startString ;
@synthesize endString ;
@synthesize discardStartString ;

//---------------------------------------------------------------------------------------------------------------------*

- (id) initWithStartString: (NSString *) inStartString
       endString: (NSString *) inEndString
       discardStartString: (BOOL) inDiscardStartString {
  self = [super init] ;
  if (self) {
    startString = inStartString ;
    endString = inEndString ;
    discardStartString = inDiscardStartString ;
  }
  return self ;
}

@end

//---------------------------------------------------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------------------------------------------------*
//   OC_Lexique                                                                                                        *
//---------------------------------------------------------------------------------------------------------------------*

@implementation OC_Lexique

//---------------------------------------------------------------------------------------------------------------------*

@synthesize menuForEntryPopUpButton ;

//---------------------------------------------------------------------------------------------------------------------*

- (instancetype) init {
  self = [super init] ;
  if (self) {
    mMatchedTemplateDelimiterIndex = -1 ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) detach {
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) indexingDirectory {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSArray *) indexingTitles { // Array of NSString
  return [NSArray array] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) advance {
  // NSLog (@"mCurrentLocation %d, [mSourceString length] %u", mCurrentLocation, [mSourceString length]) ;
  if ((mCurrentLocation + 1) < [mSourceString length]) {
    mPreviousChar = mCurrentChar ;
    mCurrentLocation ++ ;
    mCurrentChar = [mSourceString characterAtIndex:mCurrentLocation] ;
  }else{
    mCurrentLocation = [mSourceString length] ;
    mPreviousChar = mCurrentChar ;
    mCurrentChar = '\0' ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) searchForReplacementPattern:(NSArray *) inReplacementPatternArray {
  BOOL found = NO ;
  NSUInteger idx = 0 ;
  while ((idx < inReplacementPatternArray.count) && ! found) {
    NSString * s = [inReplacementPatternArray objectAtIndex:idx] ;
    BOOL stringMatch = YES ;
    const NSUInteger sLength = [s length] ;
    for (NSUInteger i=0 ; (i<sLength) && stringMatch ; i++) {
      stringMatch = [s characterAtIndex:i] == [mSourceString characterAtIndex:mCurrentLocation + i] ;
    }
    if (stringMatch) {
      found = YES ;
      mCurrentLocation += sLength ;
      mPreviousChar = [mSourceString characterAtIndex:mCurrentLocation-1] ;
      mCurrentChar = [mSourceString characterAtIndex:mCurrentLocation] ;
    }
    idx ++ ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) saveScanningPoint: (scanningPointStructForCocoa *) outScanningPoint {
  outScanningPoint->mPreviousChar = mPreviousChar ; 
  outScanningPoint->mCurrentChar = mCurrentChar ; 
  outScanningPoint->mCurrentLocation = mCurrentLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) restoreScanningPoint: (scanningPointStructForCocoa *) inScanningPoint {
  mPreviousChar = inScanningPoint->mPreviousChar ; 
  mCurrentChar = inScanningPoint->mCurrentChar ; 
  mCurrentLocation = inScanningPoint->mCurrentLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) testForInputChar: (utf32) inUnicodeCharacter {
  const BOOL result = mCurrentChar == inUnicodeCharacter ;
  if (result) {
    [self advance] ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) testForInputFromChar:(utf32) inUnicodeLowerBound toChar:(utf32) inUnicodeUpperBound {
  const BOOL result = (mCurrentChar >= inUnicodeLowerBound) && (mCurrentChar <= inUnicodeUpperBound) ;
  if (result) {
    [self advance] ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) testForCharWithFunction: (bool (*) (const utf32 inUnicodeCharacter)) inFunction {
  const BOOL ok = inFunction (mCurrentChar) ;
  if (ok) {
    [self advance] ;
  }
  return ok ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) testForInputString: (NSString *) inTestedString advance:(BOOL) inFlag {
  //NSLog (@"testForInputString: mCurrentLocation %d, [mSourceString length] %u, inTestedString '%@'", mCurrentLocation, [mSourceString length], inTestedString) ;
  const NSUInteger testedStringLength = [inTestedString length] ;
  BOOL result = NO ;
  if ((mCurrentLocation + testedStringLength) <= [mSourceString length]) {
    const NSComparisonResult cmp = [mSourceString
      compare:inTestedString
      options:NSLiteralSearch
      range:NSMakeRange (mCurrentLocation, testedStringLength)
    ] ;
    result = cmp == NSOrderedSame ;
    if (result & inFlag) {
      // NSLog (@"FOUND") ;
      for (UInt32 i=0 ; i<testedStringLength ; i++) {
        [self advance] ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) notTestForInputString: (NSString *) inSearchString error: (BOOL *) ioScanningOk {
  BOOL loop = NO ;
  if ((mCurrentLocation + [inSearchString length]) <= [mSourceString length]) {
    const NSComparisonResult cmp = [mSourceString
      compare:inSearchString
      options:NSLiteralSearch
      range:NSMakeRange (mCurrentLocation, [inSearchString length])
    ] ;
    loop = cmp != NSOrderedSame ;
  //--- Advance if found
    if (loop) {
      [self advance] ;
    }else{
      for (UInt32 i=0 ; i<[inSearchString length] ; i++) {
        [self advance] ;
      }
    }
  }else{
    * ioScanningOk = NO ;
  }
  return loop ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (SInt32) findTemplateDelimiterIndex: (NSArray *) inTemplateDelimiterArray { // Array of OC_GGS_TemplateDelimiter
  SInt32 templateIndex = 0 ;
  BOOL found = NO ;
  
  while ((templateIndex < (SInt32) inTemplateDelimiterArray.count) && ! found) {
    OC_GGS_TemplateDelimiter * td = [inTemplateDelimiterArray objectAtIndex:(NSUInteger) templateIndex] ;
    found = [self
      testForInputString:td.startString
      advance:td.discardStartString
    ] ;
    templateIndex ++ ;
  }
  templateIndex -- ;
  if (! found) {
    templateIndex = -1 ;
  }
  return templateIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (const UInt16 **) popupListData {
  return NULL ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) parseLexicalTokenForLexicalColoring {
  NSLog (@"Error: OC_Lexique <parseLexicalTokenForLexicalColoring> is abstract!") ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  return 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) buildPopupMenuItemArrayWithStyleArray:(NSArray *) inTokenArray {
  NSDictionary * defaultAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
    [NSFont systemFontOfSize:11.0], NSFontAttributeName,
    nil
  ] ;
  NSDictionary * specialAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
    [NSFont boldSystemFontOfSize:11.0], NSFontAttributeName,
    nil
  ] ;
  NSAttributedString * prefixString = [[NSAttributedString alloc]
    initWithString:@"———————————————————————————————————"
    attributes:[NSDictionary dictionaryWithObjectsAndKeys:
      [NSFont fontWithName:@"Courier" size:11.0], NSFontAttributeName,
      nil
    ]
  ] ;
  NSMenu * menu = [[NSMenu alloc] initWithTitle:@""] ;
  const UInt16 ** popUpListData = [self popupListData] ;
  if (NULL != popUpListData) {
    const NSUInteger tokenCount = inTokenArray.count ;
    for (NSUInteger tokenIndex=0 ; tokenIndex<tokenCount ; tokenIndex++) {
      OC_Token * token = [inTokenArray objectAtIndex:tokenIndex] ;
      const NSUInteger terminal = token.tokenCode ;
      // printf ("terminal %u\n", terminal) ;
      BOOL found = NO ;
      NSUInteger idx = 0 ;
      NSUInteger labelLength = 0 ;
      const UInt16 * p = popUpListData [idx] ;
      while ((p != NULL) && ! found) {
        p++ ; // Pass display flags
        if (*p == terminal) {
          found = YES ;
          p += 2 ;
          labelLength = 0 ;
          while ((*p != 0) && found) {
            labelLength ++ ;
            found = ((tokenIndex+labelLength) < tokenCount) && ([[inTokenArray objectAtIndex:tokenIndex+labelLength] tokenCode] == *p) ;
            p += 2 ;
          }
        }else{
          idx ++ ;
          p = popUpListData [idx] ;
        }
      }
      if (found) {
        p = popUpListData [idx] ;
        const UInt16 displayFlags = *p ;
        p += 2 ; // Goto display strip description
        NSMutableString * title = [NSMutableString new] ;
        [title appendString:@" "] ;
        for (NSUInteger k=0 ; k<=labelLength ; k++) {
          const UInt16 stripDescription = *p ;
          if (stripDescription != 0xFFFF) {
            NSRange range = [[inTokenArray objectAtIndex:tokenIndex+k] range] ;
            if (stripDescription != 0) {
              const NSUInteger leadingStrip = stripDescription >> 4 ;
              if (leadingStrip < range.length) {
                range.location += leadingStrip ;
                range.length -= leadingStrip ;
              }else{
                range.length = 0 ;
              }
              const NSUInteger tailStrip = stripDescription & 15 ;
              if (tailStrip < range.length) {
                range.length -= tailStrip ;
              }else{
                range.length = 0 ;
              }
            }
            if (k > 0) {
              [title appendString:@" "] ;
            }
            [title appendString:[mSourceString substringWithRange:range]] ;
          }
          p += 2 ;
        }
        NSMenuItem * item = [[NSMenuItem alloc]
          initWithTitle:@""
          action:NULL
          keyEquivalent:@""
        ] ;
        if (displayFlags == 0) {
          [item setAttributedTitle:[[NSAttributedString alloc]
            initWithString:title
            attributes:defaultAttributes
          ]] ;
        }else{
          NSMutableAttributedString * s = prefixString.mutableCopy ;
          [s appendAttributedString:[[NSAttributedString alloc]
            initWithString:title
            attributes:specialAttributes
          ]] ;
          [item setAttributedTitle:s] ;
        }
        [item setTag:(NSInteger) [[inTokenArray objectAtIndex:tokenIndex] range].location] ;
        [menu addItem:item] ;
        tokenIndex += labelLength ;
      }
    }
  }
  menuForEntryPopUpButton = menu ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) presentCustomSyntaxColoringErrorForKey: (NSString *) inKey
         forStyle: (NSString *) inStyle
         path: (NSString *) inPath {
  NSMutableString * message = [NSMutableString new] ;
  [message
    appendFormat:@"For the '%@' key, there is no '%@' style in the '%@' application bundle resource file",
    inKey, inStyle, [inPath lastPathComponent]
  ] ;
  static NSPoint origin = {20.0, 20.0} ;
  const NSRect r = {origin, {300.0, 200.0}} ;
  origin.x += 20.0 ;
  origin.y += 20.0 ;
  NSWindow * window = [[NSWindow alloc] initWithContentRect:r
    styleMask:NSTitledWindowMask | NSClosableWindowMask
    backing:NSBackingStoreBuffered
    defer:YES
    screen:nil
  ] ;
  [window setTitle:@"Custom Style Error"] ;
  NSView * contentView = [window contentView] ;
  const NSRect tfRect = NSInsetRect ([contentView bounds], 10.0, 10.0) ;
  NSTextField * tf = [[NSTextField alloc] initWithFrame:tfRect] ;
  [tf setEditable:NO] ;
  [tf setSelectable:YES] ;
  [tf setFont:[NSFont boldSystemFontOfSize:0.0]] ;
  [tf setTextColor:[NSColor redColor]] ;
  [tf setStringValue:message] ;
  [contentView addSubview:tf] ;
  NSBeep () ;
  [window makeKeyAndOrderFront:nil] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) lexiqueIdentifier {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSDictionary *) customSyntaxColoringDictionary {
  if (nil == mCustomSyntaxColoringDictionary) {
    NSString * pathForCustomDictionary = [[NSBundle mainBundle]
      pathForResource:[[self lexiqueIdentifier] stringByAppendingString:@"-syntax-coloring-adds"]
      ofType:@"plist"
      inDirectory:@""
    ] ;
    if (nil == pathForCustomDictionary) {
      mCustomSyntaxColoringDictionary = [NSDictionary dictionary] ;
    }else{
    //--- Compute style index dictionary
      NSMutableDictionary * styleIndexDictionary = [NSMutableDictionary new] ;
      SInt32 currentIndex = 0 ;
      while (nil != [self styleIdentifierForStyleIndex:currentIndex]) {
        [styleIndexDictionary setObject:[NSNumber numberWithInt:currentIndex] forKey:[self styleIdentifierForStyleIndex:currentIndex]] ;
        currentIndex ++ ;
      }
   //---
      NSDictionary * dict = [NSDictionary dictionaryWithContentsOfFile:pathForCustomDictionary] ;
      NSMutableDictionary * d = [NSMutableDictionary new] ;
      for (NSString * key in [dict allKeys]) {
        NSString * styleName = [dict objectForKey:key] ;
        // NSLog (@"styleName %@", styleName) ;
        NSNumber * styleIndexNumber = [styleIndexDictionary objectForKey:[[self lexiqueIdentifier] stringByAppendingFormat:@"-%@", styleName]] ;
        if (nil == styleIndexNumber) {
          [self presentCustomSyntaxColoringErrorForKey:key forStyle:styleName path:pathForCustomDictionary] ;
        }else{
          [d setObject:styleIndexNumber forKey:key] ;
        }
      }
      mCustomSyntaxColoringDictionary = d  ;
    }
  }
  return mCustomSyntaxColoringDictionary ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) styleIndexForTokenCode: (NSInteger) inTokenCode
               spelling: (NSString *) inSpelling {
  NSUInteger result = 0 ;
  NSString * customColoringGroupIndex = [[self customSyntaxColoringDictionary] objectForKey:inSpelling] ;
  if (nil != customColoringGroupIndex) {
    result = (NSUInteger) [customColoringGroupIndex integerValue] ;
  }else{
    result = [self styleIndexForTerminal:inTokenCode] ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) tokenizeForSourceString: (NSString *) inSourceString
         tokenArray: (NSMutableArray *) ioStyledRangeArray // Array of OC_Token
         editedRange: (const NSRange) inEditedRange
         changeInLength: (const NSInteger) inChangeInLength
         firstIndexToRedraw: (NSInteger *) outLowerIndexToRedrawInStyleArray // In ioStyledRangeArray
         lastIndexToRedraw: (NSInteger *) outUpperIndexToRedrawInStyleArray // In ioStyledRangeArray
         eraseRangeStart: (NSInteger *) outEraseRangeStart
         eraseRangeEnd: (NSInteger *) outEraseRangeEnd {
  #ifdef DEBUG_MESSAGES
    NSLog (@"tokenizeForSourceString:tokenArray:...") ;
  #endif
//--- Set source string
  mSourceString = inSourceString ;
//--- Finding lower index in ioStyledRangeArray to redraw
  #ifdef DEBUG_MESSAGES
    NSLog (@"  Finding lower index in ioStyledRangeArray to redraw") ;
  #endif
  const NSUInteger initialArrayLength = [ioStyledRangeArray count] ;
  * outLowerIndexToRedrawInStyleArray = 0 ;
  BOOL search = YES ;
  while ((((NSUInteger) *outLowerIndexToRedrawInStyleArray) < initialArrayLength) && search) {
    OC_Token * token = [ioStyledRangeArray objectAtIndex:(NSUInteger) * outLowerIndexToRedrawInStyleArray] ;
    const NSRange range = [token range] ;
    search = (range.location + range.length) < inEditedRange.location ;
    *outLowerIndexToRedrawInStyleArray += search ;
  }
//--- Determine if we are within template string, or outside
  if (*outLowerIndexToRedrawInStyleArray > 2) {
    *outLowerIndexToRedrawInStyleArray -= 2 ;
    if ([self isTemplateLexique]) {
      while (((*outLowerIndexToRedrawInStyleArray) > 0) && ([[ioStyledRangeArray objectAtIndex:((NSUInteger) * outLowerIndexToRedrawInStyleArray)] matchedTemplateDelimiterIndex] < 0)) {
        (*outLowerIndexToRedrawInStyleArray) -- ;
      }
    }
    mCurrentLocation = [[ioStyledRangeArray objectAtIndex:(NSUInteger) * outLowerIndexToRedrawInStyleArray] range].location ;
    if ((* outLowerIndexToRedrawInStyleArray) > 0) {
      mMatchedTemplateDelimiterIndex = [[ioStyledRangeArray objectAtIndex:((NSUInteger) * outLowerIndexToRedrawInStyleArray)] matchedTemplateDelimiterIndex] ;
    }else{
      mMatchedTemplateDelimiterIndex = -1 ; // Within Template string
    }
  }else{
    *outLowerIndexToRedrawInStyleArray = 0 ;
    mCurrentLocation = 0 ;
    mMatchedTemplateDelimiterIndex = -1 ;
  }
  *outEraseRangeStart = (NSInteger) mCurrentLocation ;
//--- Suppress affected Tokens
  #ifdef DEBUG_MESSAGES
    NSLog (@"  Suppress affected Tokens") ;
  #endif
  search = YES ;
  const NSUInteger affectedRangeEndLocation = inEditedRange.location + inEditedRange.length - (NSUInteger) inChangeInLength ;
  while ((*outLowerIndexToRedrawInStyleArray < (SInt32) [ioStyledRangeArray count]) && search) {
    OC_Token * token = [ioStyledRangeArray objectAtIndex:(NSUInteger) * outLowerIndexToRedrawInStyleArray] ;
    search = [token range].location < affectedRangeEndLocation ;
    if (search) {
      [ioStyledRangeArray removeObjectAtIndex:(NSUInteger) * outLowerIndexToRedrawInStyleArray] ;
    }
  }
//--- Translate range for items beyond affected range
  #ifdef DEBUG_MESSAGES
    NSLog (@"  Translate range for items beyond affected range") ;
  #endif
  for (NSUInteger i=((NSUInteger) *outLowerIndexToRedrawInStyleArray) ; i<[ioStyledRangeArray count] ; i++) {
    OC_Token * token = [ioStyledRangeArray objectAtIndex:i] ;
    [token translateRange:inChangeInLength] ;
  }
//--- Parse 
  *outUpperIndexToRedrawInStyleArray = *outLowerIndexToRedrawInStyleArray ;
  search = YES ;
  mCurrentChar = [mSourceString characterAtIndex:mCurrentLocation] ;
  mPreviousChar = (mCurrentLocation == 0) ? '\0' : [mSourceString characterAtIndex:mCurrentLocation - 1] ;
  while (search) {
    #ifdef DEBUG_MESSAGES
      NSLog (@"  parseLexicalTokenForLexicalColoring from %lu, character '%C', mMatchedTemplateDelimiterIndex %ld",
              mCurrentLocation,
              (mCurrentChar == '\n') ? 0x21B5 : mCurrentChar,
              mMatchedTemplateDelimiterIndex) ;
    #endif
    [self parseLexicalTokenForLexicalColoring] ;
    search = (mTokenStartLocation < mCurrentLocation) && (mCurrentLocation < [mSourceString length]) ;
    #ifdef DEBUG_MESSAGES
      NSLog (@"  parseLexicalTokenForLexicalColoring DONE, mCurrentLocation %lu, mTokenStartLocation %lu", mCurrentLocation, mTokenStartLocation) ;
    #endif
    if (mTokenCode < 0) { // Error or template
      const NSRange range = {mTokenStartLocation, mCurrentLocation - mTokenStartLocation} ;
      OC_Token * token = [[OC_Token alloc]
        initWithTokenCode:0 // No token
        range:range
        style:mTokenCode // 'Error' (-1) or 'template' (-2) style
        matchedTemplateDelimiterIndex:-1
      ] ;
      // NSLog (@"range [%ld, %ld] --> '%@'", range.location, range.length, [mSourceString substringWithRange:range]) ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"  error -> insertAtIndex:%ld, range %lu, %lu", * outUpperIndexToRedrawInStyleArray, [token range].location, [token range].length) ;
      #endif
      [ioStyledRangeArray insertObject:token atIndex:(NSUInteger) * outUpperIndexToRedrawInStyleArray] ;
      (*outUpperIndexToRedrawInStyleArray) ++ ;
    }else if ((mTokenCode > 0) && ((* outUpperIndexToRedrawInStyleArray) >= (SInt32) [ioStyledRangeArray count])) { // Regular token
      const NSRange range = {mTokenStartLocation, mCurrentLocation - mTokenStartLocation} ;
      OC_Token * token = [[OC_Token alloc]
        initWithTokenCode:(NSUInteger) mTokenCode
        range:range
        style:(NSInteger) [self styleIndexForTokenCode:mTokenCode spelling:[mSourceString substringWithRange:range]]
        matchedTemplateDelimiterIndex:mMatchedTemplateDelimiterIndex
      ] ;
      #ifdef DEBUG_MESSAGES
        NSLog (@"  token -> insertObject:atIndex:%ld", * outUpperIndexToRedrawInStyleArray) ;
      #endif
      [ioStyledRangeArray insertObject:token atIndex:(NSUInteger) * outUpperIndexToRedrawInStyleArray] ;
      (*outUpperIndexToRedrawInStyleArray) ++ ;
    }else if (mTokenCode > 0) { // Regular token
      const NSRange range = {mTokenStartLocation, mCurrentLocation - mTokenStartLocation} ;
      OC_Token * token = [ioStyledRangeArray objectAtIndex:(NSUInteger) *outUpperIndexToRedrawInStyleArray] ;
      if (NSEqualRanges (range, [token range]) && (mTokenCode == (SInt32) [token tokenCode])) {
        search = NO ;
        (*outUpperIndexToRedrawInStyleArray) ++ ;
      }else{
        token = [[OC_Token alloc]
          initWithTokenCode:(NSUInteger) mTokenCode
          range:range
          style:(NSInteger) [self styleIndexForTokenCode:mTokenCode spelling:[mSourceString substringWithRange:range]]
          matchedTemplateDelimiterIndex:mMatchedTemplateDelimiterIndex
        ] ;
        #ifdef DEBUG_MESSAGES
          NSLog (@"  token -> insertObject:atIndex:%ld", * outUpperIndexToRedrawInStyleArray) ;
        #endif
        [ioStyledRangeArray insertObject:token atIndex:(NSUInteger) * outUpperIndexToRedrawInStyleArray] ;
        (*outUpperIndexToRedrawInStyleArray) ++ ;
      }
    }
  //--- Delete style items before current location
    BOOL removeStyle = YES ;
    while (((*outUpperIndexToRedrawInStyleArray) < (SInt32) [ioStyledRangeArray count]) && removeStyle) {
      OC_Token * token = [ioStyledRangeArray objectAtIndex:(NSUInteger) * outUpperIndexToRedrawInStyleArray] ;
      removeStyle = [token range].location < mCurrentLocation ;
      if (removeStyle) {
        [ioStyledRangeArray removeObjectAtIndex:(NSUInteger) * outUpperIndexToRedrawInStyleArray] ;
      }
    }
  //---
  }
//---
  *outEraseRangeEnd = (NSInteger) mCurrentLocation ;
  (*outUpperIndexToRedrawInStyleArray) -- ;
//--- Display token list
  #ifdef DEBUG_MESSAGES
    NSLog (@"New token list (%lu elements):", [ioStyledRangeArray count]) ;
    for (NSUInteger i=0 ; i<[ioStyledRangeArray count] ; i++) {
      OC_Token * token = [ioStyledRangeArray objectAtIndex:i] ;
      NSString * s = [mSourceString substringWithRange:[token range]] ;
      s = [s stringByReplacingOccurrencesOfString:@"\n" withString:@"\u21B5"] ;
      NSLog (@"  #%lu: token %lu '%@', range [%lu, %lu], style %ld, delimitor %ld", i, [token tokenCode], s, [token range].location, [token range].length, [token style], [token matchedTemplateDelimiterIndex]) ;
    }
  #endif
//--- Build popup menu
  #ifdef DEBUG_MESSAGES
    NSLog (@"build popup") ;
  #endif
  [self buildPopupMenuItemArrayWithStyleArray:ioStyledRangeArray] ;
//---
  #ifdef DEBUG_MESSAGES
    NSLog (@"tokenizeForSourceString:tokenArray:... DONE") ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) blockComment {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) isTemplateLexique {
  return NO ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) styleCount {
  return 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) styleIdentifierForStyleIndex: (const NSInteger) inIndex {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) styleNameForStyleIndex: (const NSInteger) inIndex {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) textMacroCount {
  return 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) textMacroTitleAtIndex: (const NSUInteger) inIndex {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) textMacroContentAtIndex: (const NSUInteger) inIndex {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) tabItemTitle {
  return @"Source" ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  return YES ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------------------------------------------------*

NSInteger searchStringInTable (NSString * inSearchedString,
                               const C_cocoa_lexique_table_entry * inTable,
                               const NSUInteger inTableSize) {
  const char * cString = [inSearchedString cStringUsingEncoding:NSUTF8StringEncoding] ;
  NSInteger result = 0 ;
  NSUInteger idx = inTableSize ;
  while ((idx > 0) && (result == 0)) {
    idx -- ;
    if (strcmp (cString, inTable [idx].mEntry) == 0) {
      result = inTable [idx].mTokenCode ;
    }
  }
  return result ;
}


//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Lexical Routines

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   P R E D E F I N E D    S C A N N E R    A C T I O N S                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterHexDigitIntoASCIIcharacter (BOOL * ioScanningOk,
                                                            UInt32 * ioValue,
                                                            const utf32 inChar) {
  if (isxdigit ((int) inChar)) {
    UInt32 tempo = (* ioValue) << 4 ;
    if ((inChar >= '0') && (inChar <= '9')) {
      tempo += inChar - '0' ;
    }else if ((inChar >= 'A') && (inChar <= 'F')) {
      tempo += inChar + 10 - 'A' ;
    }else{ // ((inChar >= 'a') && (inChar <= 'f')) {
      tempo += inChar + 10 - 'a' ;
    }
    if (tempo > 255) {
      * ioScanningOk = NO ;
    }else{
      * ioValue = tempo ;
    }
  }else{
    *ioScanningOk = NO ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterDigitIntoASCIIcharacter (BOOL * ioScanningOk,
                                                         UInt32 * ioValue,
                                                         const utf32 inChar) {
  if ((inChar >= '0') && (inChar <= '9')) {
    UInt32 tempo = * ioValue ;
    tempo *= 10  ;
    tempo += inChar - '0' ;
    if (tempo > 255) {
      *ioScanningOk = NO ;
    }else{
      * ioValue = tempo ;
    }
  }else{
    *ioScanningOk = NO ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterCharacterIntoString (BOOL * ioScanningOk,
                                                     NSMutableString * ioString,
                                                     const utf32 inChar) {
  [ioString appendFormat:@"%C", (uint16_t) inChar] ;
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertStringToDouble (BOOL * ioScanningOk,
                                                  NSMutableString * inString,
                                                  double * outValue) {
  * outValue = [inString doubleValue] ;
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterCharacterIntoCharacter (BOOL * ioScanningOk,
                                                        utf32 * outCharacter,
                                                        const utf32 inCharacter) {
  * outCharacter = inCharacter ;
}

//---------------------------------------------------------------------------------------------------------------------*

utf32 scanner_cocoa_function_toLower (const utf32 c) {
  return unicodeToLower (c) ;
}

//---------------------------------------------------------------------------------------------------------------------*

utf32 scanner_cocoa_function_toUpper (const utf32 c) {
  return unicodeToUpper (c) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_negateSInt (BOOL * ioScanningOk,
                                       SInt32 * ioValue) {
  if (*ioValue == INT32_MIN) {
    * ioScanningOk = YES ;
  }else{
    * ioValue = - * ioValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_negateSInt64 (BOOL * ioScanningOk,
                                         SInt64 * ioValue) {
  if (* ioValue == INT64_MIN) {
    * ioScanningOk = NO ;
  }else{
    * ioValue = - * ioValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertUIntToSInt (BOOL * ioScanningOk,
                                              const UInt32 inValue,
                                              SInt32 * outValue) {
  if (inValue > INT32_MAX) {
    * ioScanningOk = NO ;
  }else{
    * outValue = (SInt32) inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertUInt64ToSInt64 (BOOL * ioScanningOk,
                                                  const UInt64 inValue,
                                                  SInt64 * outValue) {
  if (inValue > INT64_MAX) {
  }else{
    * outValue = (SInt64) inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterDigitIntoUInt (BOOL * ioScanningOk,
                                               const utf32 inCharacter,
                                               UInt32 * ioValue) {
  if ((UNICODE_VALUE (inCharacter) < '0') || (UNICODE_VALUE (inCharacter) > '9')) {
    * ioScanningOk = NO ;
  }else{
    const UInt32 digit = UNICODE_VALUE (inCharacter) - '0' ;
    const UInt32 max = UINT32_MAX / 10 ;
    if (* ioValue > max) {
      * ioScanningOk = NO ;
    }else if ((* ioValue == max) && (digit > 5)) {
      * ioScanningOk = NO ;
    }else{
      * ioValue = (* ioValue) * 10 + digit ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterDigitIntoUInt64 (BOOL * ioScanningOk,
                                                 const utf32 inCharacter,
                                                 UInt64 * ioValue) {
  if ((UNICODE_VALUE (inCharacter) < '0') || (UNICODE_VALUE (inCharacter) > '9')) {
    * ioScanningOk = NO ;
  }else{
    const UInt64 digit = UNICODE_VALUE (inCharacter) - '0' ;
    const UInt64 max = UINT64_MAX / 10 ;
    if (* ioValue > max) {
      * ioScanningOk = NO ;
    }else if ((*ioValue == max) && (digit > 5)) {
      * ioScanningOk = NO ;
    }else{
      *ioValue = *ioValue * 10 + digit ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterHexDigitIntoUInt (BOOL * ioScanningOk,
                                                  const utf32 inCharacter,
                                                  UInt32 * ioValue) {
  bool carOk = (UNICODE_VALUE (inCharacter) >= '0') && (UNICODE_VALUE (inCharacter) <= '9') ;
  UInt32 digit = UNICODE_VALUE (inCharacter) - '0' ;
  if (! carOk) {
    carOk = (UNICODE_VALUE (inCharacter) >= 'A') && (UNICODE_VALUE (inCharacter) <= 'F') ;
    digit = UNICODE_VALUE (inCharacter) - 'A' + 10 ;
  }
  if (! carOk) {
    carOk = (UNICODE_VALUE (inCharacter) >= 'a') && (UNICODE_VALUE (inCharacter) <= 'f') ;
    digit = UNICODE_VALUE (inCharacter) - 'a' + 10 ;
  }
  if (! carOk) {
    * ioScanningOk = NO ;
  }else{
    const UInt32 max = UINT32_MAX >> 4 ;
    if (*ioValue > max) {
      * ioScanningOk = NO ;
    }else{
      *ioValue = (*ioValue << 4) + digit ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterHexDigitIntoUInt64 (BOOL * ioScanningOk,
                                                    const utf32 inCharacter,
                                                    UInt64 * ioValue) {
  bool carOk = (UNICODE_VALUE (inCharacter) >= '0') && (UNICODE_VALUE (inCharacter) <= '9') ;
  UInt64 digit = UNICODE_VALUE (inCharacter) - '0' ;
  if (! carOk) {
    carOk = (UNICODE_VALUE (inCharacter) >= 'A') && (UNICODE_VALUE (inCharacter) <= 'F') ;
    digit = UNICODE_VALUE (inCharacter) - 'A' + 10 ;
  }
  if (! carOk) {
    carOk = (UNICODE_VALUE (inCharacter) >= 'a') && (UNICODE_VALUE (inCharacter) <= 'f') ;
    digit = UNICODE_VALUE (inCharacter) - 'a' + 10 ;
  }
  if (! carOk) {
    * ioScanningOk = NO ;
  }else{
    const UInt64 max = UINT64_MAX >> 4 ;
    if (*ioValue > max) {
      * ioScanningOk = NO ;
    }else{
      *ioValue = (*ioValue << 4) + digit ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertDecimalStringIntoUInt (BOOL * ioScanningOk,
                                                         NSString * inDecimalString,
                                                         UInt32 * outValue) {
  * outValue = 0 ;
  bool ok = true ;
  const UInt32 max = UINT32_MAX / 10 ;
  for (UInt32 i=0 ; (i<[inDecimalString length]) && ok ; i++) {
    const UInt32 c = [inDecimalString characterAtIndex:i] ;
    if ((UNICODE_VALUE (c) < '0') || (UNICODE_VALUE (c) > '9')) {
      * ioScanningOk = NO ;
      ok = false ;
    }else{
      const UInt32 digit = (UInt32) (UNICODE_VALUE (c) - '0') ;
      if (*outValue > max) {
        * ioScanningOk = NO ;
        ok = false ;
      }else if ((*outValue == max) && (digit > (ULONG_MAX % 10))) {
        * ioScanningOk = NO ;
        ok = false ;
      }else{
        *outValue = *outValue * 10 + digit ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertDecimalStringIntoSInt (BOOL * ioScanningOk,
                                                         NSString * inDecimalString,
                                                         SInt32 * outValue) {
  * outValue = 0 ;
  bool ok = true ;
  for (UInt32 i=0 ; (i<[inDecimalString length]) && ok ; i++) {
    const UInt32 c = [inDecimalString characterAtIndex:i] ;
    if ((UNICODE_VALUE (c) < '0') || (UNICODE_VALUE (c) > '9')) {
      * ioScanningOk = NO ;
    }else{
      const SInt32 digit = (SInt32) (UNICODE_VALUE (c) - '0') ;
      const SInt32 max = INT32_MAX / 10 ;
      if (*outValue > max) {
        * ioScanningOk = NO ;
        ok = false ;
      }else if ((*outValue == max) && (digit > (LONG_MAX % 10))) {
        * ioScanningOk = NO ;
        ok = false ;
      }else{
        *outValue = *outValue * 10 + digit ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertDecimalStringIntoUInt64 (BOOL * ioScanningOk,
                                                           NSString * inDecimalString,
                                                           UInt64 * outValue) {
  *outValue = 0 ;
  bool ok = true ;
  for (UInt32 i=0 ; (i<[inDecimalString length]) && ok ; i++) {
    const UInt32 c = [inDecimalString characterAtIndex:i] ;
    if ((UNICODE_VALUE (c) < '0') || (UNICODE_VALUE (c) > '9')) {
      * ioScanningOk = NO ;
    }else{
      const UInt64 digit = (UInt64) (UNICODE_VALUE (c) - '0') ;
      const UInt64 max = UINT32_MAX / 10 ;
      if (*outValue > max) {
        * ioScanningOk = NO ;
        ok = false ;
      }else if ((*outValue == max) && (digit > (UINT64_MAX % 10))) {
        * ioScanningOk = NO ;
        ok = false ;
      }else{
        *outValue = *outValue * 10 + digit ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertDecimalStringIntoSInt64 (BOOL * ioScanningOk,
                                                           NSString * inDecimalString,
                                                           SInt64 * outValue) {
  * outValue = 0 ;
  bool ok = true ;
  for (UInt32 i=0 ; (i<[inDecimalString length]) && ok ; i++) {
    const UInt32 c = [inDecimalString characterAtIndex:i] ;
    if ((UNICODE_VALUE (c) < '0') || (UNICODE_VALUE (c) > '9')) {
        * ioScanningOk = NO ;
    }else{
      const SInt64 digit = (SInt64) (UNICODE_VALUE (c) - '0') ;
      const SInt64 max = LLONG_MAX / 10 ;
      if (*outValue > max) {
        * ioScanningOk = NO ;
        ok = false ;
      }else if ((*outValue == max) && (digit > (LLONG_MAX % 10))) {
        * ioScanningOk = NO ;
        ok = false ;
      }else{
        *outValue = *outValue * 10 + digit ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterBinDigitIntoUInt (BOOL * ioScanningOk,
                                                  const utf32 inCharacter,
                                                  UInt32 * ioValue) {
  if ((UNICODE_VALUE (inCharacter) < '0') || (UNICODE_VALUE (inCharacter) > '1')) {
    * ioScanningOk = NO ;
  }else{
    const UInt32 max = UINT32_MAX >> 1 ;
    if (* ioValue > max) {
      * ioScanningOk = NO ;
    }else{
      const UInt32 bit = UNICODE_VALUE (inCharacter) - '0' ;
      *ioValue = (*ioValue << 1) | bit ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterBinDigitIntoUInt64 (BOOL * ioScanningOk,
                                                    const utf32 inCharacter,
                                                    UInt64 * ioValue) {
  if ((inCharacter < '0') || (inCharacter > '1')) {
    * ioScanningOk = NO ;
  }else{
    const UInt64 max = ULLONG_MAX >> 1 ;
    if (*ioValue > max) {
      * ioScanningOk = NO ;
    }else{
      const UInt64 bit = (UInt64) (inCharacter - '0') ;
      *ioValue = (*ioValue << 1) | bit ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterOctDigitIntoUInt (BOOL * ioScanningOk,
                                                  const utf32 inCharacter,
                                                  UInt32 * ioValue) {
  if ((UNICODE_VALUE (inCharacter) < '0') || (UNICODE_VALUE (inCharacter) > '7')) {
    * ioScanningOk = NO ;
  }else{
    const uint32_t max = UINT32_MAX >> 3 ;
    if (*ioValue > max) {
      * ioScanningOk = NO ;
    }else{
      const UInt32 octVal = UNICODE_VALUE (inCharacter) - '0' ;
      *ioValue = (*ioValue << 3) | octVal ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterOctDigitIntoUInt64 (BOOL * ioScanningOk,
                                                    const utf32 inCharacter,
                                                    UInt64 * ioValue) {
  if ((UNICODE_VALUE (inCharacter) < '0') || (UNICODE_VALUE (inCharacter) > '7')) {
    * ioScanningOk = NO ;
  }else{
    const UInt64 max = ULLONG_MAX >> 3 ;
    if (*ioValue > max) {
      * ioScanningOk = NO ;
    }else{
      const UInt64 octVal = UNICODE_VALUE (inCharacter) - '0' ;
      *ioValue = (*ioValue << 3) | octVal ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_multiplyUInt (BOOL * ioScanningOk,
                                         const UInt32 inFactor,
                                         UInt32 * ioValue) {
  const UInt64 factor = inFactor ;
  const UInt64 value = *ioValue ;
  const UInt64 result = factor * value ;
  if (result > UINT32_MAX) {
    * ioScanningOk = NO ;
  }else{
    * ioValue = (UInt32) result ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_multiplyUInt64 (BOOL * ioScanningOk,
                                           const UInt64 inFactor,
                                           UInt64 * ioValue) {
  const UInt64 lowWord1 = inFactor & ULONG_MAX ;
  const UInt64 highWord1 = inFactor >> 32 ;
  const UInt64 lowWord2 = *ioValue & ULONG_MAX ;
  const UInt64 highWord2 = *ioValue >> 32 ;
  const UInt64 lowResult = lowWord1 * lowWord2 ;
  const UInt64 crossResult = (lowWord1 * highWord2) + (lowWord2 * highWord1) + (lowResult >> 32) ;
  const UInt64 highResult = (highWord1 * highWord2) + (crossResult >> 32) ;
  if (highResult > 0) {
    * ioScanningOk = NO ;
  }else{
    *ioValue = (crossResult << 32) + (lowResult & ULONG_MAX) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertHexStringIntoUInt (BOOL * ioScanningOk,
                                                     NSString * inHexString,
                                                     UInt32 * outValue) {
  *outValue = 0 ;
  bool ok = true ;
  const UInt32 max = UINT32_MAX >> 4 ;
  for (NSUInteger i=0 ; (i<[inHexString length]) && ok ; i++) {
    const UInt32 c = [inHexString characterAtIndex:i] ;
    if (*outValue > max) {
      * ioScanningOk = NO ;
      ok = false ;
    }else if ((UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9')) {
      const UInt32 digit = (UInt32) (UNICODE_VALUE (c) - '0') ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'A') && (UNICODE_VALUE (c) <= 'F')) {
      const UInt32 digit = (UInt32) (UNICODE_VALUE (c) - 'A' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'a') && (UNICODE_VALUE (c) <= 'f')) {
      const UInt32 digit = (UInt32) (UNICODE_VALUE (c) - 'a' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else{
      * ioScanningOk = NO ;
      ok = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertHexStringIntoUInt64 (BOOL * ioScanningOk,
                                                       NSString * inHexString,
                                                       UInt64 * outValue) {
  *outValue = 0 ;
  bool ok = true ;
  const UInt64 max = UINT64_MAX >> 4 ;
  for (NSUInteger i=0 ; (i<[inHexString length]) && ok ; i++) {
    const UInt32 c = [inHexString characterAtIndex:i] ;
    if (*outValue > max) {
      * ioScanningOk = NO ;
      ok = false ;
    }else if ((UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9')) {
      const UInt64 digit = (UInt64) (UNICODE_VALUE (c) - '0') ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'A') && (UNICODE_VALUE (c) <= 'F')) {
      const UInt64 digit = (UInt64) (UNICODE_VALUE (c) - 'A' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'a') && (UNICODE_VALUE (c) <= 'f')) {
      const UInt64 digit = (UInt64) (UNICODE_VALUE (c) - 'a' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else{
      * ioScanningOk = NO ;
      ok = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertHexStringIntoSInt (BOOL * ioScanningOk,
                                                     NSString * inHexString,
                                                     SInt32 * outValue) {
  *outValue = 0 ;
  bool ok = true ;
  const SInt32 max = INT32_MAX >> 4 ;
  for (NSUInteger i=0 ; (i<[inHexString length]) && ok ; i++) {
    const UInt32 c = [inHexString characterAtIndex:i] ;
    if (*outValue > max) {
      * ioScanningOk = NO ;
      ok = false ;
    }else if ((UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9')) {
      const SInt32 digit = (SInt32) (UNICODE_VALUE (c) - '0') ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'A') && (UNICODE_VALUE (c) <= 'F')) {
      const SInt32 digit = (SInt32) (UNICODE_VALUE (c) - 'A' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'a') && (UNICODE_VALUE (c) <= 'f')) {
      const SInt32 digit = (SInt32) (UNICODE_VALUE (c) - 'a' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else{
      * ioScanningOk = NO ;
      ok = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertHexStringIntoSInt64 (BOOL * ioScanningOk,
                                                       NSString * inHexString,
                                                       SInt64 * outValue) {
  *outValue = 0 ;
  bool ok = true ;
  const SInt64 max = LLONG_MAX >> 4 ;
  for (NSUInteger i=0 ; (i<[inHexString length]) && ok ; i++) {
    const UInt32 c = [inHexString characterAtIndex:i] ;
    if (*outValue > max) {
      * ioScanningOk = NO ;
      ok = false ;
    }else if ((UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9')) {
      const SInt64 digit = (SInt64) (UNICODE_VALUE (c) - '0') ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'A') && (UNICODE_VALUE (c) <= 'F')) {
      const SInt64 digit = (SInt64) (UNICODE_VALUE (c) - 'A' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else if ((UNICODE_VALUE (c) >= 'a') && (UNICODE_VALUE (c) <= 'f')) {
      const SInt64 digit = (SInt64) (UNICODE_VALUE (c) - 'a' + 10) ;
      *outValue = (*outValue << 4) + digit ;
    }else{
      * ioScanningOk = NO ;
      ok = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (BOOL * ioScanningOk,
                                                               UInt32 * ioValue,
                                                               utf32 * outUnicodeCharacter) {
  *outUnicodeCharacter = TO_UNICODE (*ioValue) ;
  if (! isUnicodeCharacterAssigned (*outUnicodeCharacter)) {
    * ioScanningOk = NO ;
  }
  *ioValue = 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertHTMLSequenceToUnicodeCharacter (BOOL * ioScanningOk,
                                                                  NSMutableString * ioStringValue,
                                                                  utf32 * outUnicodeCharacter) {
  *outUnicodeCharacter = unicodeCharacterFromHTMLSequence (ioStringValue) ;
  if (UNICODE_VALUE (outUnicodeCharacter) == 0) {
    * ioScanningOk = NO ;
  }
  [ioStringValue setString:@""] ;
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_codePointToUnicode (BOOL * ioScanningOk,
                                               NSString * inElementString,
                                               NSMutableString * ioTemplateString) {
  if ([inElementString length] == 0) {
    * ioScanningOk = NO ;
  }else if ((UNICODE_VALUE ([inElementString characterAtIndex:0]) == 'x') || (UNICODE_VALUE ([inElementString characterAtIndex:0]) == 'X')) {
    bool ok = true ;
    UInt32 code = 0 ;
    for (NSUInteger i=1 ; (i<[inElementString length]) && ok ; i++) {
      code <<= 4 ;
      const UInt32 c = [inElementString characterAtIndex:i] ;
      if ((UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9')) {
        code += UNICODE_VALUE (c) - '0' ;
      }else if ((UNICODE_VALUE (c) >= 'A') && (UNICODE_VALUE (c) <= 'F')) {
        code += UNICODE_VALUE (c) + 10 - 'A' ;
      }else if ((UNICODE_VALUE (c) >= 'a') && (UNICODE_VALUE (c) <= 'f')) {
        code += UNICODE_VALUE (c) + 10 - 'a' ;
      }else{
        ok = false ;
        * ioScanningOk = NO ;
      }
    }
    if (isUnicodeCharacterAssigned (TO_UNICODE (code))) {
      [ioTemplateString appendFormat:@"%C", (uint16_t) code] ;
    }else{
      * ioScanningOk = NO ;
    }
  }else{ // Decimal value
    bool ok = true ;
    UInt32 code = 0 ;
    for (UInt32 i=0 ; (i<[inElementString length]) && ok ; i++) {
      code *= 10 ;
      const UInt32 c = [inElementString characterAtIndex:i] ;
      if ((UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9')) {
        code += UNICODE_VALUE (c) - '0' ;
      }else{
        ok = false ;
        * ioScanningOk = NO ;
      }
    }
    if (isUnicodeCharacterAssigned (TO_UNICODE (code))) {
      [ioTemplateString appendFormat:@"%c", code] ;
    }else{
      * ioScanningOk = NO ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_resetString (BOOL * ioNoLexicalError,
                                        NSMutableString * ioString) {
  [ioString setString:@""] ;
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterDecimalDigitIntoBigInt (BOOL * ioScanningOk,
                                                        const utf32 inChar,
                                                        NSMutableString * ioString) {
  if ((UNICODE_VALUE (inChar) >= '0') && (UNICODE_VALUE (inChar) <= '9')) {
    [ioString appendFormat:@"%C", (uint16_t) inChar] ;
  }else{
    * ioScanningOk = NO ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_enterHexDigitIntoBigInt (BOOL * ioScanningOk,
                                                    const utf32 inChar,
                                                    NSMutableString * ioString) {
  if ((UNICODE_VALUE (inChar) >= '0') && (UNICODE_VALUE (inChar) <= '9')) {
    [ioString appendFormat:@"%C", (uint16_t) inChar] ;
  }else if ((UNICODE_VALUE (inChar) >= 'A') && (UNICODE_VALUE (inChar) <= 'F')) {
    [ioString appendFormat:@"%C", (uint16_t) inChar] ;
  }else if ((UNICODE_VALUE (inChar) >= 'a') && (UNICODE_VALUE (inChar) <= 'f')) {
    [ioString appendFormat:@"%C", (uint16_t) inChar] ;
  }else{
    * ioScanningOk = NO ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertDecimalStringIntoBigInt (BOOL * ioScanningOk,
                                                           NSString * inDecimalString,
                                                           NSMutableString * ioString) {
  for (NSUInteger i=0 ; i < inDecimalString.length ; i++) {
    const unichar c = [inDecimalString characterAtIndex:i] ;
    if ((c >= '0') && (c <= '9')) {
      [ioString appendFormat:@"%C", c] ;
    }else{
      * ioScanningOk = NO ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void scanner_cocoa_routine_convertHexStringIntoBigInt (BOOL * ioScanningOk,
                                                       NSString * inHexString,
                                                       NSMutableString * ioString) {
  for (NSUInteger i=0 ; i < inHexString.length ; i++) {
    const unichar c = [inHexString characterAtIndex:i] ;
    if ((c >= '0') && (c <= '9')) {
      [ioString appendFormat:@"%C", c] ;
    }else if ((c >= 'A') && (c <= 'F')) {
      [ioString appendFormat:@"%C", c] ;
    }else if ((c >= 'a') && (c <= 'f')) {
      [ioString appendFormat:@"%C", c] ;
    }else{
      * ioScanningOk = NO ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

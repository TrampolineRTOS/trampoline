//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-arxml-5F-scanner-cocoa.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_Lexique_arxml_scanner

//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Replacements
//
//----------------------------------------------------------------------------------------------------------------------

static NSArray * kTemplateReplacementArray_arxml_5F_scanner ; // Of NSString 


//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Delimiters
//
//----------------------------------------------------------------------------------------------------------------------

static NSArray * kTemplateDefinitionArray_arxml_5F_scanner ;

//----------------------------------------------------------------------------------------------------------------------

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_tokenString = [[NSMutableString alloc] init] ;
  }
  if (nil == kTemplateDefinitionArray_arxml_5F_scanner) {
    kTemplateDefinitionArray_arxml_5F_scanner = [NSArray arrayWithObjects:
      [[OC_GGS_TemplateDelimiter alloc] initWithStartString:@"<" endString:nil discardStartString:NO],
      nil
    ] ;
  }
  if (nil == kTemplateReplacementArray_arxml_5F_scanner) {

    kTemplateReplacementArray_arxml_5F_scanner = [NSArray arrayWithObjects:
      @"&amp;",       @"&lt;",       @"&gt;",       @"&quot;",       @"&apos;",       @"&#",       nil
    ] ;
  }
  return self ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                 I N D E X I N G    T I T L E S
//
//----------------------------------------------------------------------------------------------------------------------

- (NSArray *) indexingTitles { // Array of NSString

  return [NSArray array] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//----------------------------------------------------------------------------------------------------------------------

static const BOOL kEndOfScriptInTemplateArray_arxml_5F_scanner [10] = {
  YES /* comment */,
  NO /* name */,
  NO /* value */,
  NO /* < */,
  NO /* <? */,
  YES /* > */,
  YES /* ?> */,
  YES /* /> */,
  NO /* </ */,
  NO /* = */
} ;



//----------------------------------------------------------------------------------------------------------------------
//
//               I N T E R N A L    P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) internalParseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  [mLexicalAttribute_tokenString setString:@""] ;
  mTokenStartLocation = mCurrentLocation ;
  if (scanningOk && ([self testForInputString:@"<!--" advance:YES])) {
    BOOL loop1308 = YES ;
    do {
      if (scanningOk && ([self testForInputString:@"&amp;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 38) ;
      }else if (scanningOk && ([self testForInputString:@"&lt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 60) ;
      }else if (scanningOk && ([self testForInputString:@"&gt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 62) ;
      }else if (scanningOk && ([self testForInputString:@"&quot;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 34) ;
      }else if (scanningOk && ([self testForInputString:@"&apos;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 39) ;
      }else if (scanningOk && ([self testForInputFromChar:1 toChar:44] || [self testForInputFromChar:46 toChar:1114111])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else if (scanningOk && ([self notTestForInputString:@"-->" error:& scanningOk])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 45) ;
      }else{
        loop1308 = NO ;
      }
    }while (loop1308 && scanningOk) ;
    mTokenCode = arxml_scanner_1_comment ;
  }else if (scanningOk && [self testForInputString:@"\?>" advance:YES]) {
    mTokenCode = arxml_scanner_1__3F__3E_ ;
  }else if (scanningOk && [self testForInputString:@"<\?" advance:YES]) {
    mTokenCode = arxml_scanner_1__3C__3F_ ;
  }else if (scanningOk && [self testForInputString:@"</" advance:YES]) {
    mTokenCode = arxml_scanner_1__3C__2F_ ;
  }else if (scanningOk && [self testForInputString:@"/>" advance:YES]) {
    mTokenCode = arxml_scanner_1__2F__3E_ ;
  }else if (scanningOk && [self testForInputString:@">" advance:YES]) {
    mTokenCode = arxml_scanner_1__3E_ ;
  }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
    mTokenCode = arxml_scanner_1__3D_ ;
  }else if (scanningOk && [self testForInputString:@"<" advance:YES]) {
    mTokenCode = arxml_scanner_1__3C_ ;
  }else if (scanningOk && ([self testForCharWithFunction: isUnicodeLetter])) {
    BOOL loop2329 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      if (scanningOk && ([self testForCharWithFunction: isUnicodeLetter] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:45] || [self testForInputChar:58])) {
      }else{
        loop2329 = NO ;
      }
    }while (loop2329 && scanningOk) ;
    mTokenCode = arxml_scanner_1_name ;
  }else if (scanningOk && ([self testForInputChar:34])) {
    BOOL loop2735 = YES ;
    do {
      if (scanningOk && ([self testForInputString:@"&amp;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 38) ;
      }else if (scanningOk && ([self testForInputString:@"&lt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 60) ;
      }else if (scanningOk && ([self testForInputString:@"&gt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 62) ;
      }else if (scanningOk && ([self testForInputString:@"&quot;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 34) ;
      }else if (scanningOk && ([self testForInputString:@"&apos;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 39) ;
      }else if (scanningOk && ([self notTestForInputString:@"\"" error:& scanningOk])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else{
        loop2735 = NO ;
      }
    }while (loop2735 && scanningOk) ;
    mTokenCode = arxml_scanner_1_value ;
  }else if (scanningOk && ([self testForInputChar:39])) {
    BOOL loop3224 = YES ;
    do {
      if (scanningOk && ([self testForInputString:@"&amp;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 38) ;
      }else if (scanningOk && ([self testForInputString:@"&lt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 60) ;
      }else if (scanningOk && ([self testForInputString:@"&gt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 62) ;
      }else if (scanningOk && ([self testForInputString:@"&quot;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 34) ;
      }else if (scanningOk && ([self testForInputString:@"&apos;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 39) ;
      }else if (scanningOk && ([self notTestForInputString:@"'" error:& scanningOk])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else{
        loop3224 = NO ;
      }
    }while (loop3224 && scanningOk) ;
    mTokenCode = arxml_scanner_1_value ;
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
  }else   if ([self testForInputChar:'\0']) { // End of source text ?
    mTokenCode = arxml_scanner_1_ ; // Empty string code
  }else{ // Unknown input character
    scanningOk = NO ;
    [self advance] ;
  }
  return scanningOk ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//               P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

- (void) parseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0) && ([[kTemplateDefinitionArray_arxml_5F_scanner objectAtIndex:(NSUInteger) mMatchedTemplateDelimiterIndex] startString].length > 0)) {
      const BOOL foundEndDelimitor = [self testForInputString:[[kTemplateDefinitionArray_arxml_5F_scanner objectAtIndex:(NSUInteger) mMatchedTemplateDelimiterIndex] endString] advance:YES] ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (mCurrentChar != '\0')) {
      
      [self searchForReplacementPattern:kTemplateReplacementArray_arxml_5F_scanner] ;
      
      mMatchedTemplateDelimiterIndex = [self findTemplateDelimiterIndex:kTemplateDefinitionArray_arxml_5F_scanner] ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        [self advance] ;
        mTokenCode = -2 ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (mTokenCode == 0) && (mCurrentChar != '\0') && scanningOk) {
      scanningOk = [self internalParseLexicalTokenForLexicalColoring] ;
    }
    if ((mTokenCode > 0) && kEndOfScriptInTemplateArray_arxml_5F_scanner [mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  }
//--- Error ?
  if (! scanningOk) {
    mTokenCode = -1 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//                   T E R M I N A L    C O U N T
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) terminalVocabularyCount {
  return 10 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                     S T Y L E   C O U N T
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleCount {
  return 6 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                I S    T E M P L A T E    L E X I Q U E
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) isTemplateLexique {
  return YES ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   S T Y L E   I N D E X    F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [11] = {0,
    4 /* arxml_scanner_1_comment */,
    2 /* arxml_scanner_1_name */,
    3 /* arxml_scanner_1_value */,
    1 /* arxml_scanner_1__3C_ */,
    1 /* arxml_scanner_1__3C__3F_ */,
    1 /* arxml_scanner_1__3E_ */,
    1 /* arxml_scanner_1__3F__3E_ */,
    1 /* arxml_scanner_1__2F__3E_ */,
    1 /* arxml_scanner_1__3C__2F_ */,
    1 /* arxml_scanner_1__3D_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [11] = {NO,
    YES /* arxml_scanner_1_comment */,
    YES /* arxml_scanner_1_name */,
    YES /* arxml_scanner_1_value */,
    YES /* arxml_scanner_1__3C_ */,
    YES /* arxml_scanner_1__3C__3F_ */,
    YES /* arxml_scanner_1__3E_ */,
    YES /* arxml_scanner_1__3F__3E_ */,
    YES /* arxml_scanner_1__2F__3E_ */,
    YES /* arxml_scanner_1__3C__2F_ */,
    YES /* arxml_scanner_1__3D_ */
  } ;
  return kTerminalAtomicSelection [inTokenIndex] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             S T Y L E   N A M E    F O R    I N D E X
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 6)) {
    NSString * kStyleArray [6] = {
      @"Default Style",
      @"Delimiter",
      @"Name",
      @"Attribute value",
      @"Comment",
      @"Text"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 6)) {
    NSString * kStyleArray [6] = {
      @"arxml_scanner",
      @"arxml_scanner-delimitersStyle",
      @"arxml_scanner-nameStyle",
      @"arxml_scanner-attributeValue",
      @"arxml_scanner-commentStyle",
      @"arxml_scanner-textStyle"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//         L E X I Q U E   I D E N T I F I E R
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) lexiqueIdentifier {
  return @"arxml_scanner" ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-options-5F-scanner-cocoa.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_Lexique_options_scanner

//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Replacements
//
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Delimiters
//
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_floatNumber = 0.0 ;
    mLexicalAttribute_integerNumber = 0 ;
    mLexicalAttribute_key = [[NSMutableString alloc] init] ;
    mLexicalAttribute_number = [[NSMutableString alloc] init] ;
    mLexicalAttribute_string = [[NSMutableString alloc] init] ;
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




//----------------------------------------------------------------------------------------------------------------------
//
//               I N T E R N A L    P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) internalParseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  mLexicalAttribute_floatNumber = 0.0 ;
  mLexicalAttribute_integerNumber = 0 ;
  [mLexicalAttribute_key setString:@""] ;
  [mLexicalAttribute_number setString:@""] ;
  [mLexicalAttribute_string setString:@""] ;
  mTokenStartLocation = mCurrentLocation ;
  if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
    BOOL loop1116 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_key, mPreviousChar) ;
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
      }else{
        loop1116 = NO ;
      }
    }while (loop1116 && scanningOk) ;
    mTokenCode = options_scanner_1_idf ;
  }else if (scanningOk && ([self testForInputChar:34])) {
    BOOL loop1476 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:32 toChar:33] || [self testForInputFromChar:35 toChar:65533])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_string, mPreviousChar) ;
      }else{
        loop1476 = NO ;
      }
    }while (loop1476 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:34])) {
      mTokenCode = options_scanner_1_string ;
    }else{
      scanningOk = NO ;
    }
  }else if (scanningOk && ([self testForInputString:@"0x" advance:YES] || [self testForInputString:@"0X" advance:YES])) {
    BOOL loop2268 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
        scanner_cocoa_routine_enterHexDigitIntoUInt64 (& scanningOk, mPreviousChar, & mLexicalAttribute_integerNumber) ;
      }else{
        loop2268 = NO ;
      }
    }while (loop2268 && scanningOk) ;
    mTokenCode = options_scanner_1_uint_5F_number ;
  }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
    BOOL loop2520 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_number, mPreviousChar) ;
      scanner_cocoa_routine_enterDigitIntoUInt64 (& scanningOk, mPreviousChar, & mLexicalAttribute_integerNumber) ;
      if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      }else{
        loop2520 = NO ;
      }
    }while (loop2520 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:46])) {
      BOOL loop2717 = YES ;
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_number, mPreviousChar) ;
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
        }else{
          loop2717 = NO ;
        }
      }while (loop2717 && scanningOk) ;
      scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_number, & mLexicalAttribute_floatNumber) ;
      mTokenCode = options_scanner_1_float_5F_number ;
    }else{
      mTokenCode = options_scanner_1_uint_5F_number ;
    }
  }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
    mTokenCode = options_scanner_1__3D_ ;
  }else if (scanningOk && [self testForInputString:@"-" advance:YES]) {
    mTokenCode = options_scanner_1__2D_ ;
  }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
    mTokenCode = options_scanner_1__2C_ ;
  }else if (scanningOk && [self testForInputString:@")" advance:YES]) {
    mTokenCode = options_scanner_1__29_ ;
  }else if (scanningOk && [self testForInputString:@"(" advance:YES]) {
    mTokenCode = options_scanner_1__28_ ;
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
  }else   if ([self testForInputChar:'\0']) { // End of source text ?
    mTokenCode = options_scanner_1_ ; // Empty string code
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
    scanningOk = [self internalParseLexicalTokenForLexicalColoring] ;
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
  return 9 ;
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
  return NO ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   S T Y L E   I N D E X    F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [10] = {0,
    1 /* options_scanner_1_idf */,
    3 /* options_scanner_1_string */,
    4 /* options_scanner_1_uint_5F_number */,
    5 /* options_scanner_1_float_5F_number */,
    2 /* options_scanner_1__3D_ */,
    2 /* options_scanner_1__2C_ */,
    2 /* options_scanner_1__2D_ */,
    2 /* options_scanner_1__28_ */,
    2 /* options_scanner_1__29_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [10] = {NO,
    YES /* options_scanner_1_idf */,
    YES /* options_scanner_1_string */,
    YES /* options_scanner_1_uint_5F_number */,
    YES /* options_scanner_1_float_5F_number */,
    YES /* options_scanner_1__3D_ */,
    YES /* options_scanner_1__2C_ */,
    YES /* options_scanner_1__2D_ */,
    YES /* options_scanner_1__28_ */,
    YES /* options_scanner_1__29_ */
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
      @"Option:",
      @"Delimiters:",
      @"String literals:",
      @"Integer Literals:",
      @"Floating Point Literals:"
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
      @"options_scanner",
      @"options_scanner-identifierStyle",
      @"options_scanner-delimitersStyle",
      @"options_scanner-stringStyle",
      @"options_scanner-integerStyle",
      @"options_scanner-floatStyle"
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
  return @"options_scanner" ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



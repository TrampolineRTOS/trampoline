//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-goil-5F-lexique-cocoa.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_Lexique_goil_lexique

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
    mLexicalAttribute_a_string = [[NSMutableString alloc] init] ;
    mLexicalAttribute_att_token = [[NSMutableString alloc] init] ;
    mLexicalAttribute_floatNumber = 0.0 ;
    mLexicalAttribute_integerNumber = 0 ;
    mLexicalAttribute_number = [[NSMutableString alloc] init] ;
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
//             Key words table 'boolean'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_goil_5F_lexique_boolean [2] = {
  {"TRUE", goil_lexique_1_TRUE},
  {"FALSE", goil_lexique_1_FALSE}
} ;

static NSInteger search_into_goil_5F_lexique_boolean (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_goil_5F_lexique_boolean, 2) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'commands'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_goil_5F_lexique_commands [2] = {
  {"include", goil_lexique_1_include},
  {"includeifexists", goil_lexique_1_includeifexists}
} ;

static NSInteger search_into_goil_5F_lexique_commands (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_goil_5F_lexique_commands, 2) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'dataTypes'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_goil_5F_lexique_dataTypes [10] = {
  {"ENUM", goil_lexique_1_ENUM},
  {"FLOAT", goil_lexique_1_FLOAT},
  {"INT32", goil_lexique_1_INT_33__32_},
  {"INT64", goil_lexique_1_INT_36__34_},
  {"STRING", goil_lexique_1_STRING},
  {"STRUCT", goil_lexique_1_STRUCT},
  {"UINT32", goil_lexique_1_UINT_33__32_},
  {"UINT64", goil_lexique_1_UINT_36__34_},
  {"BOOLEAN", goil_lexique_1_BOOLEAN},
  {"IDENTIFIER", goil_lexique_1_IDENTIFIER}
} ;

static NSInteger search_into_goil_5F_lexique_dataTypes (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_goil_5F_lexique_dataTypes, 10) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'miscSpecifiers'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_goil_5F_lexique_miscSpecifiers [3] = {
  {"AUTO", goil_lexique_1_AUTO},
  {"WITH_AUTO", goil_lexique_1_WITH_5F_AUTO},
  {"NO_DEFAULT", goil_lexique_1_NO_5F_DEFAULT}
} ;

static NSInteger search_into_goil_5F_lexique_miscSpecifiers (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_goil_5F_lexique_miscSpecifiers, 3) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'oilDefinitions'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_goil_5F_lexique_oilDefinitions [2] = {
  {"CPU", goil_lexique_1_CPU},
  {"IMPLEMENTATION", goil_lexique_1_IMPLEMENTATION}
} ;

static NSInteger search_into_goil_5F_lexique_oilDefinitions (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_goil_5F_lexique_oilDefinitions, 2) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'oilVersion'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_goil_5F_lexique_oilVersion [1] = {
  {"OIL_VERSION", goil_lexique_1_OIL_5F_VERSION}
} ;

static NSInteger search_into_goil_5F_lexique_oilVersion (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_goil_5F_lexique_oilVersion, 1) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//               I N T E R N A L    P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) internalParseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  [mLexicalAttribute_a_string setString:@""] ;
  [mLexicalAttribute_att_token setString:@""] ;
  mLexicalAttribute_floatNumber = 0.0 ;
  mLexicalAttribute_integerNumber = 0 ;
  [mLexicalAttribute_number setString:@""] ;
  mTokenStartLocation = mCurrentLocation ;
  if (scanningOk && ([self testForInputString:@"//" advance:YES])) {
    BOOL loop1945 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
      }else{
        loop1945 = NO ;
      }
    }while (loop1945 && scanningOk) ;
    mTokenCode = goil_lexique_1_comment ;
  }else if (scanningOk && ([self testForInputString:@"/*" advance:YES])) {
    BOOL loop2167 = YES ;
    do {
      if (scanningOk && ([self notTestForInputString:@"*/" error:& scanningOk])) {
      }else{
        loop2167 = NO ;
      }
    }while (loop2167 && scanningOk) ;
    mTokenCode = goil_lexique_1_comment ;
  }else if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
    BOOL loop2428 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_att_token, mPreviousChar) ;
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
      }else{
        loop2428 = NO ;
      }
    }while (loop2428 && scanningOk) ;
    if (mTokenCode == 0) {
      mTokenCode = search_into_goil_5F_lexique_oilVersion (mLexicalAttribute_att_token) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = search_into_goil_5F_lexique_oilDefinitions (mLexicalAttribute_att_token) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = search_into_goil_5F_lexique_dataTypes (mLexicalAttribute_att_token) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = search_into_goil_5F_lexique_miscSpecifiers (mLexicalAttribute_att_token) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = search_into_goil_5F_lexique_boolean (mLexicalAttribute_att_token) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = goil_lexique_1_idf ;
    }
  }else if (scanningOk && [self testForInputString:@".." advance:YES]) {
    mTokenCode = goil_lexique_1__2E__2E_ ;
  }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
    mTokenCode = goil_lexique_1__7D_ ;
  }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
    mTokenCode = goil_lexique_1__7B_ ;
  }else if (scanningOk && [self testForInputString:@"]" advance:YES]) {
    mTokenCode = goil_lexique_1__5D_ ;
  }else if (scanningOk && [self testForInputString:@"[" advance:YES]) {
    mTokenCode = goil_lexique_1__5B_ ;
  }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
    mTokenCode = goil_lexique_1__3D_ ;
  }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
    mTokenCode = goil_lexique_1__3B_ ;
  }else if (scanningOk && [self testForInputString:@":" advance:YES]) {
    mTokenCode = goil_lexique_1__3A_ ;
  }else if (scanningOk && [self testForInputString:@"." advance:YES]) {
    mTokenCode = goil_lexique_1__2E_ ;
  }else if (scanningOk && [self testForInputString:@"-" advance:YES]) {
    mTokenCode = goil_lexique_1__2D_ ;
  }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
    mTokenCode = goil_lexique_1__2C_ ;
  }else if (scanningOk && [self testForInputString:@"+" advance:YES]) {
    mTokenCode = goil_lexique_1__2B_ ;
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
  }else if (scanningOk && ([self testForInputChar:34])) {
    BOOL loop3481 = YES ;
    do {
      if (scanningOk && ([self testForInputChar:92])) {
        if (scanningOk && ([self testForInputChar:34])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 34) ;
        }else if (scanningOk && ([self testForInputChar:92])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 92) ;
        }else if (scanningOk && ([self testForInputChar:110])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 10) ;
        }else if (scanningOk && ([self testForInputChar:114])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 13) ;
        }else{
          scanningOk = NO ;
        }
      }else if (scanningOk && ([self testForInputFromChar:32 toChar:33] || [self testForInputFromChar:35 toChar:65533])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mPreviousChar) ;
      }else{
        loop3481 = NO ;
      }
    }while (loop3481 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:34])) {
      mTokenCode = goil_lexique_1_string ;
    }else{
      scanningOk = NO ;
    }
  }else if (scanningOk && ([self testForInputChar:39])) {
    BOOL loop4024 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:32 toChar:38] || [self testForInputFromChar:40 toChar:65533])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mPreviousChar) ;
      }else{
        loop4024 = NO ;
      }
    }while (loop4024 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:39])) {
      mTokenCode = goil_lexique_1_string ;
    }else{
      scanningOk = NO ;
    }
  }else if (scanningOk && ([self testForInputChar:60])) {
    BOOL loop4324 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:32 toChar:61] || [self testForInputFromChar:63 toChar:65533])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mPreviousChar) ;
      }else{
        loop4324 = NO ;
      }
    }while (loop4324 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:62])) {
      mTokenCode = goil_lexique_1_g_5F_string ;
    }else{
      scanningOk = NO ;
    }
  }else if (scanningOk && ([self testForInputString:@"0x" advance:YES] || [self testForInputString:@"0X" advance:YES])) {
    BOOL loop4975 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
        scanner_cocoa_routine_enterHexDigitIntoUInt64 (& scanningOk, mPreviousChar, & mLexicalAttribute_integerNumber) ;
      }else{
        loop4975 = NO ;
      }
    }while (loop4975 && scanningOk) ;
    mTokenCode = goil_lexique_1_uint_5F_number ;
  }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
    BOOL loop5227 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_number, mPreviousChar) ;
      scanner_cocoa_routine_enterDigitIntoUInt64 (& scanningOk, mPreviousChar, & mLexicalAttribute_integerNumber) ;
      if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      }else{
        loop5227 = NO ;
      }
    }while (loop5227 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:46])) {
      if (scanningOk && ([self testForInputChar:46])) {
        mTokenCode = goil_lexique_1_set_5F_start_5F_uint_5F_number ;
      }else{
        BOOL loop5515 = YES ;
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_number, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          }else{
            loop5515 = NO ;
          }
        }while (loop5515 && scanningOk) ;
        scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_number, & mLexicalAttribute_floatNumber) ;
        mTokenCode = goil_lexique_1_float_5F_number ;
      }
    }else{
      mTokenCode = goil_lexique_1_uint_5F_number ;
    }
  }else if (scanningOk && ([self testForInputChar:35])) {
    BOOL loop5994 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_att_token, mPreviousChar) ;
      }else{
        loop5994 = NO ;
      }
    }while (loop5994 && scanningOk) ;
    if (mTokenCode == 0) {
      mTokenCode = search_into_goil_5F_lexique_commands (mLexicalAttribute_att_token) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = goil_lexique_1_command ;
    }
  }else   if ([self testForInputChar:'\0']) { // End of source text ?
    mTokenCode = goil_lexique_1_ ; // Empty string code
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
  return 40 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                     S T Y L E   C O U N T
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleCount {
  return 10 ;
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
  static const NSUInteger kTerminalSymbolStyles [41] = {0,
    9 /* goil_lexique_1_comment */,
    2 /* goil_lexique_1_idf */,
    4 /* goil_lexique_1_string */,
    5 /* goil_lexique_1_g_5F_string */,
    6 /* goil_lexique_1_uint_5F_number */,
    7 /* goil_lexique_1_float_5F_number */,
    6 /* goil_lexique_1_set_5F_start_5F_uint_5F_number */,
    8 /* goil_lexique_1_command */,
    1 /* goil_lexique_1_OIL_5F_VERSION */,
    1 /* goil_lexique_1_IMPLEMENTATION */,
    1 /* goil_lexique_1_CPU */,
    1 /* goil_lexique_1_UINT_33__32_ */,
    1 /* goil_lexique_1_INT_33__32_ */,
    1 /* goil_lexique_1_UINT_36__34_ */,
    1 /* goil_lexique_1_INT_36__34_ */,
    1 /* goil_lexique_1_FLOAT */,
    1 /* goil_lexique_1_ENUM */,
    1 /* goil_lexique_1_STRING */,
    1 /* goil_lexique_1_BOOLEAN */,
    1 /* goil_lexique_1_IDENTIFIER */,
    1 /* goil_lexique_1_STRUCT */,
    1 /* goil_lexique_1_WITH_5F_AUTO */,
    1 /* goil_lexique_1_NO_5F_DEFAULT */,
    1 /* goil_lexique_1_AUTO */,
    1 /* goil_lexique_1_FALSE */,
    1 /* goil_lexique_1_TRUE */,
    3 /* goil_lexique_1__3B_ */,
    3 /* goil_lexique_1__3A_ */,
    3 /* goil_lexique_1__3D_ */,
    3 /* goil_lexique_1__7B_ */,
    3 /* goil_lexique_1__7D_ */,
    3 /* goil_lexique_1__2E__2E_ */,
    3 /* goil_lexique_1__5B_ */,
    3 /* goil_lexique_1__5D_ */,
    3 /* goil_lexique_1__2C_ */,
    3 /* goil_lexique_1__2E_ */,
    3 /* goil_lexique_1__2B_ */,
    3 /* goil_lexique_1__2D_ */,
    1 /* goil_lexique_1_include */,
    1 /* goil_lexique_1_includeifexists */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [41] = {NO,
    YES /* goil_lexique_1_comment */,
    YES /* goil_lexique_1_idf */,
    YES /* goil_lexique_1_string */,
    YES /* goil_lexique_1_g_5F_string */,
    YES /* goil_lexique_1_uint_5F_number */,
    YES /* goil_lexique_1_float_5F_number */,
    YES /* goil_lexique_1_set_5F_start_5F_uint_5F_number */,
    YES /* goil_lexique_1_command */,
    YES /* goil_lexique_1_OIL_5F_VERSION */,
    YES /* goil_lexique_1_IMPLEMENTATION */,
    YES /* goil_lexique_1_CPU */,
    YES /* goil_lexique_1_UINT_33__32_ */,
    YES /* goil_lexique_1_INT_33__32_ */,
    YES /* goil_lexique_1_UINT_36__34_ */,
    YES /* goil_lexique_1_INT_36__34_ */,
    YES /* goil_lexique_1_FLOAT */,
    YES /* goil_lexique_1_ENUM */,
    YES /* goil_lexique_1_STRING */,
    YES /* goil_lexique_1_BOOLEAN */,
    YES /* goil_lexique_1_IDENTIFIER */,
    YES /* goil_lexique_1_STRUCT */,
    YES /* goil_lexique_1_WITH_5F_AUTO */,
    YES /* goil_lexique_1_NO_5F_DEFAULT */,
    YES /* goil_lexique_1_AUTO */,
    YES /* goil_lexique_1_FALSE */,
    YES /* goil_lexique_1_TRUE */,
    YES /* goil_lexique_1__3B_ */,
    YES /* goil_lexique_1__3A_ */,
    YES /* goil_lexique_1__3D_ */,
    YES /* goil_lexique_1__7B_ */,
    YES /* goil_lexique_1__7D_ */,
    YES /* goil_lexique_1__2E__2E_ */,
    YES /* goil_lexique_1__5B_ */,
    YES /* goil_lexique_1__5D_ */,
    YES /* goil_lexique_1__2C_ */,
    YES /* goil_lexique_1__2E_ */,
    YES /* goil_lexique_1__2B_ */,
    YES /* goil_lexique_1__2D_ */,
    YES /* goil_lexique_1_include */,
    YES /* goil_lexique_1_includeifexists */
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
  if ((inIndex >= 0) && (inIndex < 10)) {
    NSString * kStyleArray [10] = {
      @"Default Style",
      @"Keywords:",
      @"Identifiers:",
      @"Delimiters:",
      @"String literals:",
      @"Path String:",
      @"Integer Literals:",
      @"Floating Point Literals:",
      @"Commands:",
      @"Comments:"
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
  if ((inIndex >= 0) && (inIndex < 10)) {
    NSString * kStyleArray [10] = {
      @"goil_lexique",
      @"goil_lexique-keywordsStyle",
      @"goil_lexique-identifierStyle",
      @"goil_lexique-delimitersStyle",
      @"goil_lexique-stringStyle",
      @"goil_lexique-pathStyle",
      @"goil_lexique-integerStyle",
      @"goil_lexique-floatStyle",
      @"goil_lexique-commandStyle",
      @"goil_lexique-commentStyle"
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
  return @"goil_lexique" ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



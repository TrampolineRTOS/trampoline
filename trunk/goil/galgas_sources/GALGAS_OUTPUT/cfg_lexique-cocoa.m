//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'cfg_lexique-cocoa.m'                         *
//                       Generated by version 1.9.12                         *
//                       may 17th, 2010, at 15h24'40"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1


//---------------------------------------------------------------------------*

#import "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 742
  #error "This file has been compiled with a version of GALGAS that uses libpm version 742, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#import "cfg_lexique-cocoa.h"

//---------------------------------------------------------------------------*

@implementation OC_Lexique_cfg_lexique

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mLexicalAttribute_integer = 0 ;
    mLexicalAttribute_keyword = [[NSMutableString alloc] init] ;
    mLexicalAttribute_number = [[NSMutableString alloc] init] ;
    mLexicalAttribute_string = [[NSMutableString alloc] init] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) dealloc {
  [mLexicalAttribute_keyword release] ;
  [mLexicalAttribute_number release] ;
  [mLexicalAttribute_string release] ;
  [super dealloc] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Delimiters                             *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                           Template Replacments                            *
//                                                                           *
//---------------------------------------------------------------------------*



//---------------------------------------------------------------------------*
//                                                                           *
//            Terminal Symbols as end of script in template mark             *
//                                                                           *
//---------------------------------------------------------------------------*

static const BOOL kEndOfScriptInTemplateArray_cfg_5F_lexique [24] = {
  NO /* idf */,
  NO /* string */,
  NO /* uint */,
  NO /* tp_ns_per_counter_tick */,
  NO /* stack_alignment */,
  NO /* task */,
  NO /* isr */,
  NO /* isr_code */,
  NO /* counter_code */,
  NO /* interrupts */,
  NO /* uint8 */,
  NO /* sint8 */,
  NO /* uint16 */,
  NO /* sint16 */,
  NO /* uint32 */,
  NO /* sint32 */,
  NO /* uint64 */,
  NO /* sint64 */,
  NO /* ; */,
  NO /* = */,
  NO /* { */,
  NO /* } */,
  NO /* [ */,
  NO /* ] */
} ;


//---------------------------------------------------------------------------*
//                                                                           *
//             Key words table 'cfg_keywords'                            *
//                                                                           *
//---------------------------------------------------------------------------*

static const C_cocoa_lexique_table_entry ktable_for_cfg_5F_lexique_cfg_keywords [7] = {
  {@"isr", cfg_lexique_1_isr},
  {@"task", cfg_lexique_1_task},
  {@"isr_code", cfg_lexique_1_isr_5F_code},
  {@"interrupts", cfg_lexique_1_interrupts},
  {@"counter_code", cfg_lexique_1_counter_5F_code},
  {@"stack_alignment", cfg_lexique_1_stack_5F_alignment},
  {@"tp_ns_per_counter_tick", cfg_lexique_1_tp_5F_ns_5F_per_5F_counter_5F_tick}
} ;

static SInt32 search_into_cfg_5F_lexique_cfg_keywords (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_cfg_5F_lexique_cfg_keywords, 7) ;
}


//---------------------------------------------------------------------------*
//                                                                           *
//               P A R S E    L E X I C A L    T O K E N                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) parseLexicalTokenForLexicalColoring {
  mLoop = YES ;
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    mTokenFirstLocation = mCurrentLocation ;
    mLexicalAttribute_integer = 0 ;
    [mLexicalAttribute_keyword setString:@""] ;
    [mLexicalAttribute_number setString:@""] ;
    [mLexicalAttribute_string setString:@""] ;
    mTokenFirstLocation = mCurrentLocation ;
    if (scanningOk && ([self testForInputString:@"//" advance:YES])) {
      do {
        if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
    }else if (scanningOk && ([self testForInputString:@"/*" advance:YES])) {
      do {
        if (scanningOk && ([self notTestForInputString:@"*/" error:& scanningOk])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
    }else if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_keyword, mPreviousChar) ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (mTokenCode == 0) {
        mTokenCode = search_into_cfg_5F_lexique_cfg_keywords (mLexicalAttribute_keyword) ;
      }
      if (mTokenCode == 0) {
        mTokenCode = cfg_lexique_1_idf ;
      }
    }else if (scanningOk && ([self testForInputChar:34])) {
      do {
        if (scanningOk && ([self testForInputFromChar:32 toChar:33] || [self testForInputFromChar:35 toChar:65533])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_string, mPreviousChar) ;
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (scanningOk && ([self testForInputChar:34])) {
        mTokenCode = cfg_lexique_1_string ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_number, mPreviousChar) ;
        scanner_cocoa_routine_enterDigitIntoUInt64 (& scanningOk, mPreviousChar, & mLexicalAttribute_integer) ;
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = cfg_lexique_1_uint ;
    }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
      mTokenCode = cfg_lexique_1__7D_ ;
    }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
      mTokenCode = cfg_lexique_1__7B_ ;
    }else if (scanningOk && [self testForInputString:@"]" advance:YES]) {
      mTokenCode = cfg_lexique_1__5D_ ;
    }else if (scanningOk && [self testForInputString:@"[" advance:YES]) {
      mTokenCode = cfg_lexique_1__5B_ ;
    }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
      mTokenCode = cfg_lexique_1__3D_ ;
    }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
      mTokenCode = cfg_lexique_1__3B_ ;
    }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
    }else if ([self testForInputChar:'\0']) { // End of source text ? 
      mTokenCode = cfg_lexique_1_ ; // Empty string code
    }else{ // Unknown input character
      scanningOk = NO ;
    }
  //--- Error ?
    if (! scanningOk) {
      mTokenCode = -1 ;
      [self advance] ;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//                   T E R M I N A L    C O U N T                            *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) terminalVocabularyCount {
  return 24 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     S T Y L E   C O U N T                                 *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) styleCount {
  return 1 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                I S    T E M P L A T E    L E X I Q U E                    *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) isTemplateLexique {
  return NO ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              S T Y L E   F O R    T E R M I N A L                         *
//                                                                           *
//---------------------------------------------------------------------------*

- (UInt32) styleIndexForTerminal: (SInt32) inTerminal {
  static const UInt32 kTerminalSymbolStyles [25] = {0,
    0 /* cfg_lexique_1_idf */,
    0 /* cfg_lexique_1_string */,
    0 /* cfg_lexique_1_uint */,
    0 /* cfg_lexique_1_tp_5F_ns_5F_per_5F_counter_5F_tick */,
    0 /* cfg_lexique_1_stack_5F_alignment */,
    0 /* cfg_lexique_1_task */,
    0 /* cfg_lexique_1_isr */,
    0 /* cfg_lexique_1_isr_5F_code */,
    0 /* cfg_lexique_1_counter_5F_code */,
    0 /* cfg_lexique_1_interrupts */,
    0 /* cfg_lexique_1_uint_38_ */,
    0 /* cfg_lexique_1_sint_38_ */,
    0 /* cfg_lexique_1_uint_31__36_ */,
    0 /* cfg_lexique_1_sint_31__36_ */,
    0 /* cfg_lexique_1_uint_33__32_ */,
    0 /* cfg_lexique_1_sint_33__32_ */,
    0 /* cfg_lexique_1_uint_36__34_ */,
    0 /* cfg_lexique_1_sint_36__34_ */,
    0 /* cfg_lexique_1__3B_ */,
    0 /* cfg_lexique_1__3D_ */,
    0 /* cfg_lexique_1__7B_ */,
    0 /* cfg_lexique_1__7D_ */,
    0 /* cfg_lexique_1__5B_ */,
    0 /* cfg_lexique_1__5D_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             S T Y L E   N A M E    F O R    I N D E X                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) styleNameForStyleIndex: (SInt32) inIndex {
  NSString * kStyleArray [1] = {
    @"Default Style"
  } ;
  return kStyleArray [inIndex] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X             *
//                                                                           *
//---------------------------------------------------------------------------*

- (NSString *) styleIdentifierForStyleIndex: (SInt32) inIndex {
  NSString * kStyleArray [1] = {
    @"cfg_lexique"
  } ;
  return kStyleArray [inIndex] ;
}

//---------------------------------------------------------------------------*

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2




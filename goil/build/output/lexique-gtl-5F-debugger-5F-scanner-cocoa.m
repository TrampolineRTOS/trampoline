//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-gtl-5F-debugger-5F-scanner-cocoa.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_Lexique_gtl_debugger_scanner

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
    mLexicalAttribute_charValue = 0 ;
    mLexicalAttribute_floatValue = 0.0 ;
    mLexicalAttribute_functionContent = [[NSMutableString alloc] init] ;
    mLexicalAttribute_identifierString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_intValue = [[NSMutableString alloc] init] ;
    mLexicalAttribute_tokenString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_uint32value = 0 ;
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
//             Key words table 'goilTemplateKeyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList [39] = {
  {"by", gtl_debugger_scanner_1_by},
  {"do", gtl_debugger_scanner_1_do},
  {"if", gtl_debugger_scanner_1_if},
  {"no", gtl_debugger_scanner_1_no},
  {"or", gtl_debugger_scanner_1_or},
  {"all", gtl_debugger_scanner_1_all},
  {"end", gtl_debugger_scanner_1_end},
  {"let", gtl_debugger_scanner_1_let},
  {"mod", gtl_debugger_scanner_1_mod},
  {"not", gtl_debugger_scanner_1_not},
  {"yes", gtl_debugger_scanner_1_yes},
  {"cont", gtl_debugger_scanner_1_cont},
  {"else", gtl_debugger_scanner_1_else},
  {"help", gtl_debugger_scanner_1_help},
  {"hist", gtl_debugger_scanner_1_hist},
  {"list", gtl_debugger_scanner_1_list},
  {"load", gtl_debugger_scanner_1_load},
  {"sort", gtl_debugger_scanner_1_sort},
  {"step", gtl_debugger_scanner_1_step},
  {"then", gtl_debugger_scanner_1_then},
  {"true", gtl_debugger_scanner_1_true},
  {"break", gtl_debugger_scanner_1_break},
  {"elsif", gtl_debugger_scanner_1_elsif},
  {"false", gtl_debugger_scanner_1_false},
  {"mapof", gtl_debugger_scanner_1_mapof},
  {"print", gtl_debugger_scanner_1_print},
  {"unlet", gtl_debugger_scanner_1_unlet},
  {"watch", gtl_debugger_scanner_1_watch},
  {"exists", gtl_debugger_scanner_1_exists},
  {"import", gtl_debugger_scanner_1_import},
  {"listof", gtl_debugger_scanner_1_listof},
  {"typeof", gtl_debugger_scanner_1_typeof},
  {"default", gtl_debugger_scanner_1_default},
  {"display", gtl_debugger_scanner_1_display},
  {"continue", gtl_debugger_scanner_1_continue},
  {"emptymap", gtl_debugger_scanner_1_emptymap},
  {"emptylist", gtl_debugger_scanner_1_emptylist},
  {"libraries", gtl_debugger_scanner_1_libraries},
  {"variables", gtl_debugger_scanner_1_variables}
} ;

static NSInteger search_into_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList, 39) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//               I N T E R N A L    P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) internalParseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  [mLexicalAttribute_a_string setString:@""] ;
  mLexicalAttribute_charValue = 0 ;
  mLexicalAttribute_floatValue = 0.0 ;
  [mLexicalAttribute_functionContent setString:@""] ;
  [mLexicalAttribute_identifierString setString:@""] ;
  [mLexicalAttribute_intValue setString:@""] ;
  [mLexicalAttribute_tokenString setString:@""] ;
  mLexicalAttribute_uint32value = 0 ;
  mTokenStartLocation = mCurrentLocation ;
  if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
    BOOL loop1798 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_identifierString, mPreviousChar) ;
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
      }else{
        loop1798 = NO ;
      }
    }while (loop1798 && scanningOk) ;
    if (mTokenCode == 0) {
      mTokenCode = search_into_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList (mLexicalAttribute_identifierString) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = gtl_debugger_scanner_1_identifier ;
    }
  }else if (scanningOk && ([self testForInputChar:36])) {
    BOOL loop2203 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else{
        loop2203 = NO ;
      }
    }while (loop2203 && scanningOk) ;
    mTokenCode = gtl_debugger_scanner_1_literal_5F_enum ;
  }else if (scanningOk && [self testForInputString:@"mod=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1_mod_3D_ ;
  }else if (scanningOk && [self testForInputString:@">>=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3E__3E__3D_ ;
  }else if (scanningOk && [self testForInputString:@"<<=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3C__3C__3D_ ;
  }else if (scanningOk && [self testForInputString:@"|=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__7C__3D_ ;
  }else if (scanningOk && [self testForInputString:@"^=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__5E__3D_ ;
  }else if (scanningOk && [self testForInputString:@"[!" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__5B__21_ ;
  }else if (scanningOk && [self testForInputString:@"@{" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__40__7B_ ;
  }else if (scanningOk && [self testForInputString:@"@[" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__40__5B_ ;
  }else if (scanningOk && [self testForInputString:@"@(" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__40__28_ ;
  }else if (scanningOk && [self testForInputString:@"@!" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__40__21_ ;
  }else if (scanningOk && [self testForInputString:@">>" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3E__3E_ ;
  }else if (scanningOk && [self testForInputString:@">=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3E__3D_ ;
  }else if (scanningOk && [self testForInputString:@"==" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3D__3D_ ;
  }else if (scanningOk && [self testForInputString:@"<=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3C__3D_ ;
  }else if (scanningOk && [self testForInputString:@"<<" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3C__3C_ ;
  }else if (scanningOk && [self testForInputString:@"<-" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3C__2D_ ;
  }else if (scanningOk && [self testForInputString:@":=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3A__3D_ ;
  }else if (scanningOk && [self testForInputString:@"::" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3A__3A_ ;
  }else if (scanningOk && [self testForInputString:@"/=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2F__3D_ ;
  }else if (scanningOk && [self testForInputString:@"->" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2D__3E_ ;
  }else if (scanningOk && [self testForInputString:@"-=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2D__3D_ ;
  }else if (scanningOk && [self testForInputString:@"+=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2B__3D_ ;
  }else if (scanningOk && [self testForInputString:@"*=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2A__3D_ ;
  }else if (scanningOk && [self testForInputString:@"&=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__26__3D_ ;
  }else if (scanningOk && [self testForInputString:@"!=" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__21__3D_ ;
  }else if (scanningOk && [self testForInputString:@"~" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__7E_ ;
  }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__7D_ ;
  }else if (scanningOk && [self testForInputString:@"|" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__7C_ ;
  }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__7B_ ;
  }else if (scanningOk && [self testForInputString:@"^" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__5E_ ;
  }else if (scanningOk && [self testForInputString:@"]" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__5D_ ;
  }else if (scanningOk && [self testForInputString:@"[" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__5B_ ;
  }else if (scanningOk && [self testForInputString:@"@" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__40_ ;
  }else if (scanningOk && [self testForInputString:@"\?" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3F_ ;
  }else if (scanningOk && [self testForInputString:@">" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3E_ ;
  }else if (scanningOk && [self testForInputString:@"<" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3C_ ;
  }else if (scanningOk && [self testForInputString:@":" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__3A_ ;
  }else if (scanningOk && [self testForInputString:@"/" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2F_ ;
  }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2C_ ;
  }else if (scanningOk && [self testForInputString:@"+" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2B_ ;
  }else if (scanningOk && [self testForInputString:@"*" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__2A_ ;
  }else if (scanningOk && [self testForInputString:@")" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__29_ ;
  }else if (scanningOk && [self testForInputString:@"(" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__28_ ;
  }else if (scanningOk && [self testForInputString:@"&" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__26_ ;
  }else if (scanningOk && [self testForInputString:@"!" advance:YES]) {
    mTokenCode = gtl_debugger_scanner_1__21_ ;
  }else if (scanningOk && ([self testForInputChar:45])) {
    if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 45) ;
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      BOOL loop3530 = YES ;
      do {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        }else if (scanningOk && ([self testForInputChar:95])) {
        }else{
          loop3530 = NO ;
        }
      }while (loop3530 && scanningOk) ;
      if (scanningOk && ([self testForInputChar:46])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 46) ;
        BOOL loop3714 = YES ;
        do {
          if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
            scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          }else if (scanningOk && ([self testForInputChar:95])) {
          }else{
            loop3714 = NO ;
          }
        }while (loop3714 && scanningOk) ;
        scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_floatValue) ;
        mTokenCode = gtl_debugger_scanner_1_literal_5F_double ;
      }else{
        scanner_cocoa_routine_convertDecimalStringIntoBigInt (& scanningOk, mLexicalAttribute_tokenString, mLexicalAttribute_intValue) ;
        mTokenCode = gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint ;
      }
    }else{
      mTokenCode = gtl_debugger_scanner_1__2D_ ;
    }
  }else if (scanningOk && ([self testForInputString:@"0x" advance:YES] || [self testForInputString:@"0X" advance:YES])) {
    BOOL loop4137 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else{
        loop4137 = NO ;
      }
    }while (loop4137 && scanningOk) ;
    scanner_cocoa_routine_convertHexStringIntoBigInt (& scanningOk, mLexicalAttribute_tokenString, mLexicalAttribute_intValue) ;
    mTokenCode = gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint ;
  }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
    scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
    BOOL loop4417 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else if (scanningOk && ([self testForInputChar:95])) {
      }else{
        loop4417 = NO ;
      }
    }while (loop4417 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:46])) {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 46) ;
      BOOL loop4585 = YES ;
      do {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        }else if (scanningOk && ([self testForInputChar:95])) {
        }else{
          loop4585 = NO ;
        }
      }while (loop4585 && scanningOk) ;
      scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_floatValue) ;
      mTokenCode = gtl_debugger_scanner_1_literal_5F_double ;
    }else{
      scanner_cocoa_routine_convertDecimalStringIntoBigInt (& scanningOk, mLexicalAttribute_tokenString, mLexicalAttribute_intValue) ;
      mTokenCode = gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint ;
    }
  }else if (scanningOk && ([self testForInputChar:46])) {
    if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 48) ;
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 46) ;
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      BOOL loop5440 = YES ;
      do {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        }else if (scanningOk && ([self testForInputChar:95])) {
        }else{
          loop5440 = NO ;
        }
      }while (loop5440 && scanningOk) ;
      scanner_cocoa_routine_convertStringToDouble (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_floatValue) ;
      mTokenCode = gtl_debugger_scanner_1_literal_5F_double ;
    }else{
      if (scanningOk && ([self testForInputString:@".." advance:YES])) {
        mTokenCode = gtl_debugger_scanner_1__2E__2E__2E_ ;
      }else if (scanningOk && ([self testForInputString:@"=" advance:YES])) {
        mTokenCode = gtl_debugger_scanner_1__2E__3D_ ;
      }else{
        mTokenCode = gtl_debugger_scanner_1__2E_ ;
      }
    }
  }else if (scanningOk && ([self testForInputChar:39])) {
    if (scanningOk && ([self testForInputChar:92])) {
      if (scanningOk && ([self testForInputChar:102])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 12) ;
      }else if (scanningOk && ([self testForInputChar:110])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 10) ;
      }else if (scanningOk && ([self testForInputChar:114])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 13) ;
      }else if (scanningOk && ([self testForInputChar:116])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 9) ;
      }else if (scanningOk && ([self testForInputChar:118])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 11) ;
      }else if (scanningOk && ([self testForInputChar:92])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 92) ;
      }else if (scanningOk && ([self testForInputChar:48])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 0) ;
      }else if (scanningOk && ([self testForInputChar:39])) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, 39) ;
      }else if (scanningOk && ([self testForInputChar:117])) {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
          scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
          if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
            scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
            if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
              if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (& scanningOk, & mLexicalAttribute_uint32value, & mLexicalAttribute_charValue) ;
              }else{
                scanningOk = NO ;
              }
            }else{
              scanningOk = NO ;
            }
          }else{
            scanningOk = NO ;
          }
        }else{
          scanningOk = NO ;
        }
      }else if (scanningOk && ([self testForInputChar:85])) {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
          scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
          if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
            scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
            if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
              if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                  if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                    scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                    if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                      scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                      if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                        scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                        scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (& scanningOk, & mLexicalAttribute_uint32value, & mLexicalAttribute_charValue) ;
                      }else{
                        scanningOk = NO ;
                      }
                    }else{
                      scanningOk = NO ;
                    }
                  }else{
                    scanningOk = NO ;
                  }
                }else{
                  scanningOk = NO ;
                }
              }else{
                scanningOk = NO ;
              }
            }else{
              scanningOk = NO ;
            }
          }else{
            scanningOk = NO ;
          }
        }else{
          scanningOk = NO ;
        }
      }else if (scanningOk && ([self testForInputChar:38])) {
        BOOL loop10421 = YES ;
        do {
          if (scanningOk && ([self notTestForInputString:@";" error:& scanningOk])) {
            scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          }else{
            loop10421 = NO ;
          }
        }while (loop10421 && scanningOk) ;
        scanner_cocoa_routine_convertHTMLSequenceToUnicodeCharacter (& scanningOk, mLexicalAttribute_tokenString, & mLexicalAttribute_charValue) ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && ([self testForInputFromChar:32 toChar:65533])) {
      scanner_cocoa_routine_enterCharacterIntoCharacter (& scanningOk, & mLexicalAttribute_charValue, mPreviousChar) ;
    }else{
      scanningOk = NO ;
    }
    if (scanningOk && ([self testForInputChar:39])) {
      mTokenCode = gtl_debugger_scanner_1_literal_5F_char ;
    }else{
      scanningOk = NO ;
    }
  }else if (scanningOk && ([self testForInputChar:34])) {
    BOOL loop11009 = YES ;
    do {
      if (scanningOk && ([self testForInputChar:92])) {
        if (scanningOk && ([self testForInputChar:102])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 12) ;
        }else if (scanningOk && ([self testForInputChar:110])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 10) ;
        }else if (scanningOk && ([self testForInputChar:114])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 13) ;
        }else if (scanningOk && ([self testForInputChar:116])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 9) ;
        }else if (scanningOk && ([self testForInputChar:118])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 11) ;
        }else if (scanningOk && ([self testForInputChar:92])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 92) ;
        }else if (scanningOk && ([self testForInputChar:34])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 34) ;
        }else if (scanningOk && ([self testForInputChar:39])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 39) ;
        }else if (scanningOk && ([self testForInputChar:63])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, 63) ;
        }else if (scanningOk && ([self testForInputChar:38])) {
          BOOL loop11657 = YES ;
          do {
            if (scanningOk && ([self notTestForInputString:@";" error:& scanningOk])) {
              scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_identifierString, mPreviousChar) ;
            }else{
              loop11657 = NO ;
            }
          }while (loop11657 && scanningOk) ;
          scanner_cocoa_routine_convertHTMLSequenceToUnicodeCharacter (& scanningOk, mLexicalAttribute_identifierString, & mLexicalAttribute_charValue) ;
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mLexicalAttribute_charValue) ;
        }else if (scanningOk && ([self testForInputChar:117])) {
          if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
            scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
            if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
              if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                  scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (& scanningOk, & mLexicalAttribute_uint32value, & mLexicalAttribute_charValue) ;
                  scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mLexicalAttribute_charValue) ;
                }else{
                  scanningOk = NO ;
                }
              }else{
                scanningOk = NO ;
              }
            }else{
              scanningOk = NO ;
            }
          }else{
            scanningOk = NO ;
          }
        }else if (scanningOk && ([self testForInputChar:85])) {
          if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
            scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
            if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
              if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                  if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                    scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                    if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                      scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                      if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                        scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                        if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
                          scanner_cocoa_routine_enterHexDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_uint32value) ;
                          scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (& scanningOk, & mLexicalAttribute_uint32value, & mLexicalAttribute_charValue) ;
                          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mLexicalAttribute_charValue) ;
                        }else{
                          scanningOk = NO ;
                        }
                      }else{
                        scanningOk = NO ;
                      }
                    }else{
                      scanningOk = NO ;
                    }
                  }else{
                    scanningOk = NO ;
                  }
                }else{
                  scanningOk = NO ;
                }
              }else{
                scanningOk = NO ;
              }
            }else{
              scanningOk = NO ;
            }
          }else{
            scanningOk = NO ;
          }
        }else{
          scanningOk = NO ;
        }
      }else if (scanningOk && ([self testForInputChar:32] || [self testForInputChar:33] || [self testForInputFromChar:35 toChar:65533])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_a_string, mPreviousChar) ;
      }else{
        loop11009 = NO ;
      }
    }while (loop11009 && scanningOk) ;
    if (scanningOk && ([self testForInputChar:34])) {
      mTokenCode = gtl_debugger_scanner_1_string ;
    }else{
      scanningOk = NO ;
    }
  }else if (scanningOk && ([self testForInputChar:35])) {
    BOOL loop15719 = YES ;
    do {
      if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
      }else{
        loop15719 = NO ;
      }
    }while (loop15719 && scanningOk) ;
    mTokenCode = gtl_debugger_scanner_1_comment ;
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
  }else   if ([self testForInputChar:'\0']) { // End of source text ?
    mTokenCode = gtl_debugger_scanner_1_ ; // Empty string code
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
  return 95 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                     S T Y L E   C O U N T
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleCount {
  return 9 ;
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
  static const NSUInteger kTerminalSymbolStyles [96] = {0,
    0 /* gtl_debugger_scanner_1_identifier */,
    0 /* gtl_debugger_scanner_1_literal_5F_enum */,
    5 /* gtl_debugger_scanner_1_literal_5F_double */,
    4 /* gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint */,
    2 /* gtl_debugger_scanner_1__2D_ */,
    2 /* gtl_debugger_scanner_1__2E_ */,
    2 /* gtl_debugger_scanner_1__2E__3D_ */,
    2 /* gtl_debugger_scanner_1__2E__2E__2E_ */,
    8 /* gtl_debugger_scanner_1_literal_5F_char */,
    6 /* gtl_debugger_scanner_1_string */,
    7 /* gtl_debugger_scanner_1_comment */,
    1 /* gtl_debugger_scanner_1_default */,
    1 /* gtl_debugger_scanner_1_display */,
    1 /* gtl_debugger_scanner_1_do */,
    1 /* gtl_debugger_scanner_1_emptylist */,
    1 /* gtl_debugger_scanner_1_emptymap */,
    1 /* gtl_debugger_scanner_1_exists */,
    1 /* gtl_debugger_scanner_1_false */,
    1 /* gtl_debugger_scanner_1_list */,
    1 /* gtl_debugger_scanner_1_import */,
    1 /* gtl_debugger_scanner_1_listof */,
    1 /* gtl_debugger_scanner_1_let */,
    1 /* gtl_debugger_scanner_1_mapof */,
    1 /* gtl_debugger_scanner_1_mod */,
    1 /* gtl_debugger_scanner_1_no */,
    1 /* gtl_debugger_scanner_1_not */,
    1 /* gtl_debugger_scanner_1_or */,
    1 /* gtl_debugger_scanner_1_print */,
    1 /* gtl_debugger_scanner_1_sort */,
    1 /* gtl_debugger_scanner_1_step */,
    1 /* gtl_debugger_scanner_1_true */,
    1 /* gtl_debugger_scanner_1_typeof */,
    1 /* gtl_debugger_scanner_1_yes */,
    1 /* gtl_debugger_scanner_1_variables */,
    1 /* gtl_debugger_scanner_1_unlet */,
    1 /* gtl_debugger_scanner_1_libraries */,
    1 /* gtl_debugger_scanner_1_break */,
    1 /* gtl_debugger_scanner_1_watch */,
    1 /* gtl_debugger_scanner_1_by */,
    1 /* gtl_debugger_scanner_1_end */,
    1 /* gtl_debugger_scanner_1_cont */,
    1 /* gtl_debugger_scanner_1_continue */,
    1 /* gtl_debugger_scanner_1_help */,
    1 /* gtl_debugger_scanner_1_if */,
    1 /* gtl_debugger_scanner_1_then */,
    1 /* gtl_debugger_scanner_1_else */,
    1 /* gtl_debugger_scanner_1_elsif */,
    1 /* gtl_debugger_scanner_1_hist */,
    1 /* gtl_debugger_scanner_1_all */,
    1 /* gtl_debugger_scanner_1_load */,
    2 /* gtl_debugger_scanner_1__2A_ */,
    2 /* gtl_debugger_scanner_1__7C_ */,
    2 /* gtl_debugger_scanner_1__2C_ */,
    2 /* gtl_debugger_scanner_1__2B_ */,
    2 /* gtl_debugger_scanner_1__3A__3A_ */,
    2 /* gtl_debugger_scanner_1__3E_ */,
    2 /* gtl_debugger_scanner_1__3A_ */,
    2 /* gtl_debugger_scanner_1__28_ */,
    2 /* gtl_debugger_scanner_1__29_ */,
    2 /* gtl_debugger_scanner_1__2D__3E_ */,
    2 /* gtl_debugger_scanner_1__3F_ */,
    2 /* gtl_debugger_scanner_1__3D__3D_ */,
    2 /* gtl_debugger_scanner_1__21_ */,
    2 /* gtl_debugger_scanner_1__3A__3D_ */,
    2 /* gtl_debugger_scanner_1__5B_ */,
    2 /* gtl_debugger_scanner_1__5D_ */,
    2 /* gtl_debugger_scanner_1__2B__3D_ */,
    2 /* gtl_debugger_scanner_1__2D__3D_ */,
    2 /* gtl_debugger_scanner_1__2F_ */,
    2 /* gtl_debugger_scanner_1__21__3D_ */,
    2 /* gtl_debugger_scanner_1__3E__3D_ */,
    2 /* gtl_debugger_scanner_1__26_ */,
    2 /* gtl_debugger_scanner_1__3C__3D_ */,
    2 /* gtl_debugger_scanner_1__7B_ */,
    2 /* gtl_debugger_scanner_1__7D_ */,
    2 /* gtl_debugger_scanner_1__3C_ */,
    2 /* gtl_debugger_scanner_1__5E_ */,
    2 /* gtl_debugger_scanner_1__3E__3E_ */,
    2 /* gtl_debugger_scanner_1__7E_ */,
    2 /* gtl_debugger_scanner_1__3C__2D_ */,
    2 /* gtl_debugger_scanner_1__3C__3C_ */,
    2 /* gtl_debugger_scanner_1__40_ */,
    2 /* gtl_debugger_scanner_1__2A__3D_ */,
    2 /* gtl_debugger_scanner_1__2F__3D_ */,
    2 /* gtl_debugger_scanner_1__26__3D_ */,
    2 /* gtl_debugger_scanner_1__7C__3D_ */,
    2 /* gtl_debugger_scanner_1__3C__3C__3D_ */,
    2 /* gtl_debugger_scanner_1__3E__3E__3D_ */,
    2 /* gtl_debugger_scanner_1_mod_3D_ */,
    2 /* gtl_debugger_scanner_1__5E__3D_ */,
    2 /* gtl_debugger_scanner_1__40__5B_ */,
    2 /* gtl_debugger_scanner_1__40__28_ */,
    2 /* gtl_debugger_scanner_1__40__7B_ */,
    2 /* gtl_debugger_scanner_1__5B__21_ */,
    2 /* gtl_debugger_scanner_1__40__21_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [96] = {NO,
    YES /* gtl_debugger_scanner_1_identifier */,
    YES /* gtl_debugger_scanner_1_literal_5F_enum */,
    YES /* gtl_debugger_scanner_1_literal_5F_double */,
    YES /* gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint */,
    YES /* gtl_debugger_scanner_1__2D_ */,
    YES /* gtl_debugger_scanner_1__2E_ */,
    YES /* gtl_debugger_scanner_1__2E__3D_ */,
    YES /* gtl_debugger_scanner_1__2E__2E__2E_ */,
    YES /* gtl_debugger_scanner_1_literal_5F_char */,
    YES /* gtl_debugger_scanner_1_string */,
    YES /* gtl_debugger_scanner_1_comment */,
    YES /* gtl_debugger_scanner_1_default */,
    YES /* gtl_debugger_scanner_1_display */,
    YES /* gtl_debugger_scanner_1_do */,
    YES /* gtl_debugger_scanner_1_emptylist */,
    YES /* gtl_debugger_scanner_1_emptymap */,
    YES /* gtl_debugger_scanner_1_exists */,
    YES /* gtl_debugger_scanner_1_false */,
    YES /* gtl_debugger_scanner_1_list */,
    YES /* gtl_debugger_scanner_1_import */,
    YES /* gtl_debugger_scanner_1_listof */,
    YES /* gtl_debugger_scanner_1_let */,
    YES /* gtl_debugger_scanner_1_mapof */,
    YES /* gtl_debugger_scanner_1_mod */,
    YES /* gtl_debugger_scanner_1_no */,
    YES /* gtl_debugger_scanner_1_not */,
    YES /* gtl_debugger_scanner_1_or */,
    YES /* gtl_debugger_scanner_1_print */,
    YES /* gtl_debugger_scanner_1_sort */,
    YES /* gtl_debugger_scanner_1_step */,
    YES /* gtl_debugger_scanner_1_true */,
    YES /* gtl_debugger_scanner_1_typeof */,
    YES /* gtl_debugger_scanner_1_yes */,
    YES /* gtl_debugger_scanner_1_variables */,
    YES /* gtl_debugger_scanner_1_unlet */,
    YES /* gtl_debugger_scanner_1_libraries */,
    YES /* gtl_debugger_scanner_1_break */,
    YES /* gtl_debugger_scanner_1_watch */,
    YES /* gtl_debugger_scanner_1_by */,
    YES /* gtl_debugger_scanner_1_end */,
    YES /* gtl_debugger_scanner_1_cont */,
    YES /* gtl_debugger_scanner_1_continue */,
    YES /* gtl_debugger_scanner_1_help */,
    YES /* gtl_debugger_scanner_1_if */,
    YES /* gtl_debugger_scanner_1_then */,
    YES /* gtl_debugger_scanner_1_else */,
    YES /* gtl_debugger_scanner_1_elsif */,
    YES /* gtl_debugger_scanner_1_hist */,
    YES /* gtl_debugger_scanner_1_all */,
    YES /* gtl_debugger_scanner_1_load */,
    YES /* gtl_debugger_scanner_1__2A_ */,
    YES /* gtl_debugger_scanner_1__7C_ */,
    YES /* gtl_debugger_scanner_1__2C_ */,
    YES /* gtl_debugger_scanner_1__2B_ */,
    YES /* gtl_debugger_scanner_1__3A__3A_ */,
    YES /* gtl_debugger_scanner_1__3E_ */,
    YES /* gtl_debugger_scanner_1__3A_ */,
    YES /* gtl_debugger_scanner_1__28_ */,
    YES /* gtl_debugger_scanner_1__29_ */,
    YES /* gtl_debugger_scanner_1__2D__3E_ */,
    YES /* gtl_debugger_scanner_1__3F_ */,
    YES /* gtl_debugger_scanner_1__3D__3D_ */,
    YES /* gtl_debugger_scanner_1__21_ */,
    YES /* gtl_debugger_scanner_1__3A__3D_ */,
    YES /* gtl_debugger_scanner_1__5B_ */,
    YES /* gtl_debugger_scanner_1__5D_ */,
    YES /* gtl_debugger_scanner_1__2B__3D_ */,
    YES /* gtl_debugger_scanner_1__2D__3D_ */,
    YES /* gtl_debugger_scanner_1__2F_ */,
    YES /* gtl_debugger_scanner_1__21__3D_ */,
    YES /* gtl_debugger_scanner_1__3E__3D_ */,
    YES /* gtl_debugger_scanner_1__26_ */,
    YES /* gtl_debugger_scanner_1__3C__3D_ */,
    YES /* gtl_debugger_scanner_1__7B_ */,
    YES /* gtl_debugger_scanner_1__7D_ */,
    YES /* gtl_debugger_scanner_1__3C_ */,
    YES /* gtl_debugger_scanner_1__5E_ */,
    YES /* gtl_debugger_scanner_1__3E__3E_ */,
    YES /* gtl_debugger_scanner_1__7E_ */,
    YES /* gtl_debugger_scanner_1__3C__2D_ */,
    YES /* gtl_debugger_scanner_1__3C__3C_ */,
    YES /* gtl_debugger_scanner_1__40_ */,
    YES /* gtl_debugger_scanner_1__2A__3D_ */,
    YES /* gtl_debugger_scanner_1__2F__3D_ */,
    YES /* gtl_debugger_scanner_1__26__3D_ */,
    YES /* gtl_debugger_scanner_1__7C__3D_ */,
    YES /* gtl_debugger_scanner_1__3C__3C__3D_ */,
    YES /* gtl_debugger_scanner_1__3E__3E__3D_ */,
    YES /* gtl_debugger_scanner_1_mod_3D_ */,
    YES /* gtl_debugger_scanner_1__5E__3D_ */,
    YES /* gtl_debugger_scanner_1__40__5B_ */,
    YES /* gtl_debugger_scanner_1__40__28_ */,
    YES /* gtl_debugger_scanner_1__40__7B_ */,
    YES /* gtl_debugger_scanner_1__5B__21_ */,
    YES /* gtl_debugger_scanner_1__40__21_ */
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
  if ((inIndex >= 0) && (inIndex < 9)) {
    NSString * kStyleArray [9] = {
      @"Default Style",
      @"Keywords",
      @"Delimiters",
      @"Non Terminal Symbols",
      @"Integer Constants",
      @"Floating Point Constants",
      @"String literals",
      @"Comments",
      @"Character Constants"
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
  if ((inIndex >= 0) && (inIndex < 9)) {
    NSString * kStyleArray [9] = {
      @"gtl_debugger_scanner",
      @"gtl_debugger_scanner-keywordsStyle",
      @"gtl_debugger_scanner-delimitersStyle",
      @"gtl_debugger_scanner-nonTerminalStyle",
      @"gtl_debugger_scanner-integerStyle",
      @"gtl_debugger_scanner-floatCsts",
      @"gtl_debugger_scanner-stringStyle",
      @"gtl_debugger_scanner-commentStyle",
      @"gtl_debugger_scanner-characterStyle"
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
  return @"gtl_debugger_scanner" ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



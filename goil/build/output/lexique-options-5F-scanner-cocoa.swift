//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE options_scanner
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_options_scanner = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + options_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_options_scanner = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + options_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_options_scanner : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_options_scanner"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_options_scanner-identifierStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_options_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_options_scanner-stringStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_options_scanner-integerStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_options_scanner-floatStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_options_scanner_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_options_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_options_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner-identifierStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner-floatStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_options_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_options_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_options_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner-identifierStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner-floatStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_options_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//----------------------------------------------------------------------------------------------------------------------

let options_scanner_1_ : UInt16 = 0
let options_scanner_1_idf : UInt16 = 1
let options_scanner_1_string : UInt16 = 2
let options_scanner_1_uint_5F_number : UInt16 = 3
let options_scanner_1_float_5F_number : UInt16 = 4
let options_scanner_1__3D_ : UInt16 = 5
let options_scanner_1__2C_ : UInt16 = 6
let options_scanner_1__2D_ : UInt16 = 7
let options_scanner_1__28_ : UInt16 = 8
let options_scanner_1__29_ : UInt16 = 9
let options_scanner_2_ERROR : UInt16 = 10
let options_scanner_2_TEMPLATE : UInt16 = 11

//----------------------------------------------------------------------------------------------------------------------

func options_scanner_lexiqueIdentifier () -> String {
  return "options_scanner"
}

//----------------------------------------------------------------------------------------------------------------------

func options_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Option:", // 1
    "Delimiters:", // 2
    "String literals:", // 3
    "Integer Literals:", // 4
    "Floating Point Literals:", // 5
    "Lexical error", // 6
    "Template" // 7
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------

func options_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "options_scanner", // 0
    "options_scanner-identifierStyle", // 1
    "options_scanner-delimitersStyle", // 2
    "options_scanner-stringStyle", // 3
    "options_scanner-integerStyle", // 4
    "options_scanner-floatStyle", // 5
    "options_scanner.ERROR", // 6
    "options_scanner.TEMPLATE" // 7
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_options_scanner : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_floatNumber : Double = 0.0
  private var mLexicalAttribute_integerNumber : UInt64 = 0
  private var mLexicalAttribute_key : String = ""
  private var mLexicalAttribute_number : String = ""
  private var mLexicalAttribute_string : String = ""

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return options_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 9
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_options_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_options_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_options_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_options_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_options_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      1, // 1 : options_scanner_1_idf
      3, // 2 : options_scanner_1_string
      4, // 3 : options_scanner_1_uint_5F_number
      5, // 4 : options_scanner_1_float_5F_number
      2, // 5 : options_scanner_1__3D_
      2, // 6 : options_scanner_1__2C_
      2, // 7 : options_scanner_1__2D_
      2, // 8 : options_scanner_1__28_
      2, // 9 : options_scanner_1__29_
      6, // 10 : options_scanner_2_ERROR
      7  // 11 : options_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : options_scanner_1_idf
      true, // 2 : options_scanner_1_string
      true, // 3 : options_scanner_1_uint_5F_number
      true, // 4 : options_scanner_1_float_5F_number
      true, // 5 : options_scanner_1__3D_
      true, // 6 : options_scanner_1__2C_
      true, // 7 : options_scanner_1__2D_
      true, // 8 : options_scanner_1__28_
      true, // 9 : options_scanner_1__29_
      false, // 10 : options_scanner_2_ERROR
      false  // 11 : options_scanner_2_TEMPLATE
    ]
    return kTerminalAtomicSelection [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func indexingTitles () -> [String] {

    return []
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //  S T Y L E S
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleCount () -> UInt8 {
    return 5
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return options_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return options_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_floatNumber = 0.0
    self.mLexicalAttribute_integerNumber = 0
    self.mLexicalAttribute_key = ""
    self.mLexicalAttribute_number = ""
    self.mLexicalAttribute_string = ""
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_key, self.previousChar)
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = options_scanner_1_idf
    }else if scanningOk && (self.testForInputChar (34)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (32, toChar:33) || self.testForInputFromChar (35, toChar:65533)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_string, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (34)) {
        tokenCode = options_scanner_1_string
      }else{
        scanningOk = false
      }
    }else if scanningOk && (self.testForInputString ("0x", advance: true) || self.testForInputString ("0X", advance: true)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
          scanner_cocoa_routine_enterHexDigitIntoUInt64 (&scanningOk, self.previousChar, &self.mLexicalAttribute_integerNumber)
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = options_scanner_1_uint_5F_number
    }else if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_number, self.previousChar)
        scanner_cocoa_routine_enterDigitIntoUInt64 (&scanningOk, self.previousChar, &self.mLexicalAttribute_integerNumber)
        if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (46)) {
        while (loop && scanningOk) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_number, self.previousChar)
          if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
          }else{
            loop = false
          }
        }
        loop = true
        scanner_cocoa_routine_convertStringToDouble (&scanningOk, mLexicalAttribute_number, &self.mLexicalAttribute_floatNumber)
        tokenCode = options_scanner_1_float_5F_number
      }else{
        tokenCode = options_scanner_1_uint_5F_number
      }
    }else if scanningOk && self.testForInputString ("=", advance: true) {
      tokenCode = options_scanner_1__3D_
    }else if scanningOk && self.testForInputString ("-", advance: true) {
      tokenCode = options_scanner_1__2D_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = options_scanner_1__2C_
    }else if scanningOk && self.testForInputString (")", advance: true) {
      tokenCode = options_scanner_1__29_
    }else if scanningOk && self.testForInputString ("(", advance: true) {
      tokenCode = options_scanner_1__28_
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = options_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = options_scanner_2_TEMPLATE
      self.advance ()
    }
    return SWIFT_Token (
      range: NSRange (location: startLocation, length: self.currentLocation - startLocation),
      tokenCode: tokenCode,
      templateDelimiterIndex: self.mEndTemplateDelimiterIndex
    )
  }
  
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//----------------------------------------------------------------------------------------------------------------------

/* - (instancetype) init {
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
} */

//----------------------------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//----------------------------------------------------------------------------------------------------------------------

/*

*/






//----------------------------------------------------------------------------------------------------------------------
//
//               P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

/* - (void) parseLexicalTokenForLexicalColoring {
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

*/

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



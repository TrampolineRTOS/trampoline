//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE goil_lexique
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_goil_lexique = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + goil_lexique_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_goil_lexique = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + goil_lexique_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_goil_lexique : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-keywordsStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-identifierStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-delimitersStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-stringStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-pathStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-integerStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-floatStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-commandStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_goil_lexique-commentStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_goil_lexique_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_goil_lexique_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_goil_lexique : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-identifierStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-pathStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-floatStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-commandStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_goil_lexique_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_goil_lexique_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_goil_lexique : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-identifierStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-pathStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-floatStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-commandStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_goil_lexique_template")
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

let goil_lexique_1_ : UInt16 = 0
let goil_lexique_1_comment : UInt16 = 1
let goil_lexique_1_idf : UInt16 = 2
let goil_lexique_1_string : UInt16 = 3
let goil_lexique_1_g_5F_string : UInt16 = 4
let goil_lexique_1_uint_5F_number : UInt16 = 5
let goil_lexique_1_float_5F_number : UInt16 = 6
let goil_lexique_1_set_5F_start_5F_uint_5F_number : UInt16 = 7
let goil_lexique_1_command : UInt16 = 8
let goil_lexique_1_OIL_5F_VERSION : UInt16 = 9
let goil_lexique_1_IMPLEMENTATION : UInt16 = 10
let goil_lexique_1_CPU : UInt16 = 11
let goil_lexique_1_UINT_33__32_ : UInt16 = 12
let goil_lexique_1_INT_33__32_ : UInt16 = 13
let goil_lexique_1_UINT_36__34_ : UInt16 = 14
let goil_lexique_1_INT_36__34_ : UInt16 = 15
let goil_lexique_1_FLOAT : UInt16 = 16
let goil_lexique_1_ENUM : UInt16 = 17
let goil_lexique_1_STRING : UInt16 = 18
let goil_lexique_1_BOOLEAN : UInt16 = 19
let goil_lexique_1_IDENTIFIER : UInt16 = 20
let goil_lexique_1_STRUCT : UInt16 = 21
let goil_lexique_1_WITH_5F_AUTO : UInt16 = 22
let goil_lexique_1_NO_5F_DEFAULT : UInt16 = 23
let goil_lexique_1_AUTO : UInt16 = 24
let goil_lexique_1_FALSE : UInt16 = 25
let goil_lexique_1_TRUE : UInt16 = 26
let goil_lexique_1__3B_ : UInt16 = 27
let goil_lexique_1__3A_ : UInt16 = 28
let goil_lexique_1__3D_ : UInt16 = 29
let goil_lexique_1__7B_ : UInt16 = 30
let goil_lexique_1__7D_ : UInt16 = 31
let goil_lexique_1__2E__2E_ : UInt16 = 32
let goil_lexique_1__5B_ : UInt16 = 33
let goil_lexique_1__5D_ : UInt16 = 34
let goil_lexique_1__2C_ : UInt16 = 35
let goil_lexique_1__2E_ : UInt16 = 36
let goil_lexique_1__2B_ : UInt16 = 37
let goil_lexique_1__2D_ : UInt16 = 38
let goil_lexique_1_include : UInt16 = 39
let goil_lexique_1_includeifexists : UInt16 = 40
let goil_lexique_2_ERROR : UInt16 = 41
let goil_lexique_2_TEMPLATE : UInt16 = 42

//----------------------------------------------------------------------------------------------------------------------

func goil_lexique_lexiqueIdentifier () -> String {
  return "goil_lexique"
}

//----------------------------------------------------------------------------------------------------------------------

func goil_lexique_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Keywords:", // 1
    "Identifiers:", // 2
    "Delimiters:", // 3
    "String literals:", // 4
    "Path String:", // 5
    "Integer Literals:", // 6
    "Floating Point Literals:", // 7
    "Commands:", // 8
    "Comments:", // 9
    "Lexical error", // 10
    "Template" // 11
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------

func goil_lexique_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "goil_lexique", // 0
    "goil_lexique-keywordsStyle", // 1
    "goil_lexique-identifierStyle", // 2
    "goil_lexique-delimitersStyle", // 3
    "goil_lexique-stringStyle", // 4
    "goil_lexique-pathStyle", // 5
    "goil_lexique-integerStyle", // 6
    "goil_lexique-floatStyle", // 7
    "goil_lexique-commandStyle", // 8
    "goil_lexique-commentStyle", // 9
    "goil_lexique.ERROR", // 10
    "goil_lexique.TEMPLATE" // 11
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_goil_lexique : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_a_string : String = ""
  private var mLexicalAttribute_att_token : String = ""
  private var mLexicalAttribute_floatNumber : Double = 0.0
  private var mLexicalAttribute_integerNumber : UInt64 = 0
  private var mLexicalAttribute_number : String = ""

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return goil_lexique_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 40
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_goil_lexique }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_goil_lexique }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_goil_lexique [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_goil_lexique [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_goil_lexique [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      9, // 1 : goil_lexique_1_comment
      2, // 2 : goil_lexique_1_idf
      4, // 3 : goil_lexique_1_string
      5, // 4 : goil_lexique_1_g_5F_string
      6, // 5 : goil_lexique_1_uint_5F_number
      7, // 6 : goil_lexique_1_float_5F_number
      6, // 7 : goil_lexique_1_set_5F_start_5F_uint_5F_number
      8, // 8 : goil_lexique_1_command
      1, // 9 : goil_lexique_1_OIL_5F_VERSION
      1, // 10 : goil_lexique_1_IMPLEMENTATION
      1, // 11 : goil_lexique_1_CPU
      1, // 12 : goil_lexique_1_UINT_33__32_
      1, // 13 : goil_lexique_1_INT_33__32_
      1, // 14 : goil_lexique_1_UINT_36__34_
      1, // 15 : goil_lexique_1_INT_36__34_
      1, // 16 : goil_lexique_1_FLOAT
      1, // 17 : goil_lexique_1_ENUM
      1, // 18 : goil_lexique_1_STRING
      1, // 19 : goil_lexique_1_BOOLEAN
      1, // 20 : goil_lexique_1_IDENTIFIER
      1, // 21 : goil_lexique_1_STRUCT
      1, // 22 : goil_lexique_1_WITH_5F_AUTO
      1, // 23 : goil_lexique_1_NO_5F_DEFAULT
      1, // 24 : goil_lexique_1_AUTO
      1, // 25 : goil_lexique_1_FALSE
      1, // 26 : goil_lexique_1_TRUE
      3, // 27 : goil_lexique_1__3B_
      3, // 28 : goil_lexique_1__3A_
      3, // 29 : goil_lexique_1__3D_
      3, // 30 : goil_lexique_1__7B_
      3, // 31 : goil_lexique_1__7D_
      3, // 32 : goil_lexique_1__2E__2E_
      3, // 33 : goil_lexique_1__5B_
      3, // 34 : goil_lexique_1__5D_
      3, // 35 : goil_lexique_1__2C_
      3, // 36 : goil_lexique_1__2E_
      3, // 37 : goil_lexique_1__2B_
      3, // 38 : goil_lexique_1__2D_
      1, // 39 : goil_lexique_1_include
      1, // 40 : goil_lexique_1_includeifexists
      10, // 41 : goil_lexique_2_ERROR
      11  // 42 : goil_lexique_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : goil_lexique_1_comment
      true, // 2 : goil_lexique_1_idf
      true, // 3 : goil_lexique_1_string
      true, // 4 : goil_lexique_1_g_5F_string
      true, // 5 : goil_lexique_1_uint_5F_number
      true, // 6 : goil_lexique_1_float_5F_number
      true, // 7 : goil_lexique_1_set_5F_start_5F_uint_5F_number
      true, // 8 : goil_lexique_1_command
      true, // 9 : goil_lexique_1_OIL_5F_VERSION
      true, // 10 : goil_lexique_1_IMPLEMENTATION
      true, // 11 : goil_lexique_1_CPU
      true, // 12 : goil_lexique_1_UINT_33__32_
      true, // 13 : goil_lexique_1_INT_33__32_
      true, // 14 : goil_lexique_1_UINT_36__34_
      true, // 15 : goil_lexique_1_INT_36__34_
      true, // 16 : goil_lexique_1_FLOAT
      true, // 17 : goil_lexique_1_ENUM
      true, // 18 : goil_lexique_1_STRING
      true, // 19 : goil_lexique_1_BOOLEAN
      true, // 20 : goil_lexique_1_IDENTIFIER
      true, // 21 : goil_lexique_1_STRUCT
      true, // 22 : goil_lexique_1_WITH_5F_AUTO
      true, // 23 : goil_lexique_1_NO_5F_DEFAULT
      true, // 24 : goil_lexique_1_AUTO
      true, // 25 : goil_lexique_1_FALSE
      true, // 26 : goil_lexique_1_TRUE
      true, // 27 : goil_lexique_1__3B_
      true, // 28 : goil_lexique_1__3A_
      true, // 29 : goil_lexique_1__3D_
      true, // 30 : goil_lexique_1__7B_
      true, // 31 : goil_lexique_1__7D_
      true, // 32 : goil_lexique_1__2E__2E_
      true, // 33 : goil_lexique_1__5B_
      true, // 34 : goil_lexique_1__5D_
      true, // 35 : goil_lexique_1__2C_
      true, // 36 : goil_lexique_1__2E_
      true, // 37 : goil_lexique_1__2B_
      true, // 38 : goil_lexique_1__2D_
      true, // 39 : goil_lexique_1_include
      true, // 40 : goil_lexique_1_includeifexists
      false, // 41 : goil_lexique_2_ERROR
      false  // 42 : goil_lexique_2_TEMPLATE
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
    return 9
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return goil_lexique_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return goil_lexique_styleIdentifierFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_a_string = ""
    self.mLexicalAttribute_att_token = ""
    self.mLexicalAttribute_floatNumber = 0.0
    self.mLexicalAttribute_integerNumber = 0
    self.mLexicalAttribute_number = ""
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputString ("//", advance: true)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (1, toChar:9) || self.testForInputChar (11) || self.testForInputChar (12) || self.testForInputFromChar (14, toChar:65533)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = goil_lexique_1_comment
    }else if scanningOk && (self.testForInputString ("/*", advance: true)) {
      while (loop && scanningOk) {
        if scanningOk && (self.notTestForInputString ("*/", error: &scanningOk)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = goil_lexique_1_comment
    }else if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_att_token, self.previousChar)
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_goil_5F_lexique_oilVersion (mLexicalAttribute_att_token) ;
      }
      if (tokenCode == 0) {
        tokenCode = search_into_goil_5F_lexique_oilDefinitions (mLexicalAttribute_att_token) ;
      }
      if (tokenCode == 0) {
        tokenCode = search_into_goil_5F_lexique_dataTypes (mLexicalAttribute_att_token) ;
      }
      if (tokenCode == 0) {
        tokenCode = search_into_goil_5F_lexique_miscSpecifiers (mLexicalAttribute_att_token) ;
      }
      if (tokenCode == 0) {
        tokenCode = search_into_goil_5F_lexique_boolean (mLexicalAttribute_att_token) ;
      }
      if tokenCode == 0 {
        tokenCode = goil_lexique_1_idf ;
      }
    }else if scanningOk && self.testForInputString ("..", advance: true) {
      tokenCode = goil_lexique_1__2E__2E_
    }else if scanningOk && self.testForInputString ("}", advance: true) {
      tokenCode = goil_lexique_1__7D_
    }else if scanningOk && self.testForInputString ("{", advance: true) {
      tokenCode = goil_lexique_1__7B_
    }else if scanningOk && self.testForInputString ("]", advance: true) {
      tokenCode = goil_lexique_1__5D_
    }else if scanningOk && self.testForInputString ("[", advance: true) {
      tokenCode = goil_lexique_1__5B_
    }else if scanningOk && self.testForInputString ("=", advance: true) {
      tokenCode = goil_lexique_1__3D_
    }else if scanningOk && self.testForInputString (";", advance: true) {
      tokenCode = goil_lexique_1__3B_
    }else if scanningOk && self.testForInputString (":", advance: true) {
      tokenCode = goil_lexique_1__3A_
    }else if scanningOk && self.testForInputString (".", advance: true) {
      tokenCode = goil_lexique_1__2E_
    }else if scanningOk && self.testForInputString ("-", advance: true) {
      tokenCode = goil_lexique_1__2D_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = goil_lexique_1__2C_
    }else if scanningOk && self.testForInputString ("+", advance: true) {
      tokenCode = goil_lexique_1__2B_
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if scanningOk && (self.testForInputChar (34)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputChar (92)) {
          if scanningOk && (self.testForInputChar (34)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 34)
          }else if scanningOk && (self.testForInputChar (92)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 92)
          }else if scanningOk && (self.testForInputChar (110)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 10)
          }else if scanningOk && (self.testForInputChar (114)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 13)
          }else{
            scanningOk = false
          }
        }else if scanningOk && (self.testForInputFromChar (32, toChar:33) || self.testForInputFromChar (35, toChar:65533)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (34)) {
        tokenCode = goil_lexique_1_string
      }else{
        scanningOk = false
      }
    }else if scanningOk && (self.testForInputChar (39)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (32, toChar:38) || self.testForInputFromChar (40, toChar:65533)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (39)) {
        tokenCode = goil_lexique_1_string
      }else{
        scanningOk = false
      }
    }else if scanningOk && (self.testForInputChar (60)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (32, toChar:61) || self.testForInputFromChar (63, toChar:65533)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (62)) {
        tokenCode = goil_lexique_1_g_5F_string
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
      tokenCode = goil_lexique_1_uint_5F_number
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
        if scanningOk && (self.testForInputChar (46)) {
          tokenCode = goil_lexique_1_set_5F_start_5F_uint_5F_number
        }else{
          while (loop && scanningOk) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_number, self.previousChar)
            if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
            }else{
              loop = false
            }
          }
          loop = true
          scanner_cocoa_routine_convertStringToDouble (&scanningOk, mLexicalAttribute_number, &self.mLexicalAttribute_floatNumber)
          tokenCode = goil_lexique_1_float_5F_number
        }
      }else{
        tokenCode = goil_lexique_1_uint_5F_number
      }
    }else if scanningOk && (self.testForInputChar (35)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_att_token, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_goil_5F_lexique_commands (mLexicalAttribute_att_token) ;
      }
      if tokenCode == 0 {
        tokenCode = goil_lexique_1_command ;
      }
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = goil_lexique_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = goil_lexique_2_TEMPLATE
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
    mLexicalAttribute_a_string = [[NSMutableString alloc] init] ;
    mLexicalAttribute_att_token = [[NSMutableString alloc] init] ;
    mLexicalAttribute_floatNumber = 0.0 ;
    mLexicalAttribute_integerNumber = 0 ;
    mLexicalAttribute_number = [[NSMutableString alloc] init] ;
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
//             Key words table 'boolean'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_goil_5F_lexique_boolean (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "TRUE" : goil_lexique_1_TRUE,
    "FALSE" : goil_lexique_1_FALSE
  ]
  return dictionary [inSearchedString, default: goil_lexique_1_]
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'commands'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_goil_5F_lexique_commands (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "include" : goil_lexique_1_include,
    "includeifexists" : goil_lexique_1_includeifexists
  ]
  return dictionary [inSearchedString, default: goil_lexique_1_]
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'dataTypes'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_goil_5F_lexique_dataTypes (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "ENUM" : goil_lexique_1_ENUM,
    "FLOAT" : goil_lexique_1_FLOAT,
    "INT32" : goil_lexique_1_INT_33__32_,
    "INT64" : goil_lexique_1_INT_36__34_,
    "STRING" : goil_lexique_1_STRING,
    "STRUCT" : goil_lexique_1_STRUCT,
    "UINT32" : goil_lexique_1_UINT_33__32_,
    "UINT64" : goil_lexique_1_UINT_36__34_,
    "BOOLEAN" : goil_lexique_1_BOOLEAN,
    "IDENTIFIER" : goil_lexique_1_IDENTIFIER
  ]
  return dictionary [inSearchedString, default: goil_lexique_1_]
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'miscSpecifiers'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_goil_5F_lexique_miscSpecifiers (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "AUTO" : goil_lexique_1_AUTO,
    "WITH_AUTO" : goil_lexique_1_WITH_5F_AUTO,
    "NO_DEFAULT" : goil_lexique_1_NO_5F_DEFAULT
  ]
  return dictionary [inSearchedString, default: goil_lexique_1_]
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'oilDefinitions'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_goil_5F_lexique_oilDefinitions (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "CPU" : goil_lexique_1_CPU,
    "IMPLEMENTATION" : goil_lexique_1_IMPLEMENTATION
  ]
  return dictionary [inSearchedString, default: goil_lexique_1_]
}

//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'oilVersion'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_goil_5F_lexique_oilVersion (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "OIL_VERSION" : goil_lexique_1_OIL_5F_VERSION
  ]
  return dictionary [inSearchedString, default: goil_lexique_1_]
}





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



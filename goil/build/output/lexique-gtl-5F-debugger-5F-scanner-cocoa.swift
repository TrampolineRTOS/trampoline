//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE gtl_debugger_scanner
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_gtl_debugger_scanner = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + gtl_debugger_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_gtl_debugger_scanner = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + gtl_debugger_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_gtl_debugger_scanner : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-nonTerminalStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-integerStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-floatCsts"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-stringStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-commentStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_debugger_scanner-characterStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_gtl_debugger_scanner_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_gtl_debugger_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_gtl_debugger_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-nonTerminalStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-floatCsts"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner-characterStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_gtl_debugger_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_debugger_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_gtl_debugger_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-nonTerminalStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-floatCsts"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner-characterStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_debugger_scanner_template")
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

let gtl_debugger_scanner_1_ : UInt16 = 0
let gtl_debugger_scanner_1_identifier : UInt16 = 1
let gtl_debugger_scanner_1_literal_5F_enum : UInt16 = 2
let gtl_debugger_scanner_1_literal_5F_double : UInt16 = 3
let gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint : UInt16 = 4
let gtl_debugger_scanner_1__2D_ : UInt16 = 5
let gtl_debugger_scanner_1__2E_ : UInt16 = 6
let gtl_debugger_scanner_1__2E__3D_ : UInt16 = 7
let gtl_debugger_scanner_1__2E__2E__2E_ : UInt16 = 8
let gtl_debugger_scanner_1_literal_5F_char : UInt16 = 9
let gtl_debugger_scanner_1_string : UInt16 = 10
let gtl_debugger_scanner_1_comment : UInt16 = 11
let gtl_debugger_scanner_1_default : UInt16 = 12
let gtl_debugger_scanner_1_display : UInt16 = 13
let gtl_debugger_scanner_1_do : UInt16 = 14
let gtl_debugger_scanner_1_emptylist : UInt16 = 15
let gtl_debugger_scanner_1_emptymap : UInt16 = 16
let gtl_debugger_scanner_1_exists : UInt16 = 17
let gtl_debugger_scanner_1_false : UInt16 = 18
let gtl_debugger_scanner_1_list : UInt16 = 19
let gtl_debugger_scanner_1_import : UInt16 = 20
let gtl_debugger_scanner_1_listof : UInt16 = 21
let gtl_debugger_scanner_1_let : UInt16 = 22
let gtl_debugger_scanner_1_mapof : UInt16 = 23
let gtl_debugger_scanner_1_mod : UInt16 = 24
let gtl_debugger_scanner_1_no : UInt16 = 25
let gtl_debugger_scanner_1_not : UInt16 = 26
let gtl_debugger_scanner_1_or : UInt16 = 27
let gtl_debugger_scanner_1_print : UInt16 = 28
let gtl_debugger_scanner_1_sort : UInt16 = 29
let gtl_debugger_scanner_1_step : UInt16 = 30
let gtl_debugger_scanner_1_true : UInt16 = 31
let gtl_debugger_scanner_1_typeof : UInt16 = 32
let gtl_debugger_scanner_1_yes : UInt16 = 33
let gtl_debugger_scanner_1_variables : UInt16 = 34
let gtl_debugger_scanner_1_unlet : UInt16 = 35
let gtl_debugger_scanner_1_libraries : UInt16 = 36
let gtl_debugger_scanner_1_break : UInt16 = 37
let gtl_debugger_scanner_1_watch : UInt16 = 38
let gtl_debugger_scanner_1_by : UInt16 = 39
let gtl_debugger_scanner_1_end : UInt16 = 40
let gtl_debugger_scanner_1_cont : UInt16 = 41
let gtl_debugger_scanner_1_continue : UInt16 = 42
let gtl_debugger_scanner_1_help : UInt16 = 43
let gtl_debugger_scanner_1_if : UInt16 = 44
let gtl_debugger_scanner_1_then : UInt16 = 45
let gtl_debugger_scanner_1_else : UInt16 = 46
let gtl_debugger_scanner_1_elsif : UInt16 = 47
let gtl_debugger_scanner_1_hist : UInt16 = 48
let gtl_debugger_scanner_1_all : UInt16 = 49
let gtl_debugger_scanner_1_load : UInt16 = 50
let gtl_debugger_scanner_1__2A_ : UInt16 = 51
let gtl_debugger_scanner_1__7C_ : UInt16 = 52
let gtl_debugger_scanner_1__2C_ : UInt16 = 53
let gtl_debugger_scanner_1__2B_ : UInt16 = 54
let gtl_debugger_scanner_1__3A__3A_ : UInt16 = 55
let gtl_debugger_scanner_1__3E_ : UInt16 = 56
let gtl_debugger_scanner_1__3A_ : UInt16 = 57
let gtl_debugger_scanner_1__28_ : UInt16 = 58
let gtl_debugger_scanner_1__29_ : UInt16 = 59
let gtl_debugger_scanner_1__2D__3E_ : UInt16 = 60
let gtl_debugger_scanner_1__3F_ : UInt16 = 61
let gtl_debugger_scanner_1__3D__3D_ : UInt16 = 62
let gtl_debugger_scanner_1__21_ : UInt16 = 63
let gtl_debugger_scanner_1__3A__3D_ : UInt16 = 64
let gtl_debugger_scanner_1__5B_ : UInt16 = 65
let gtl_debugger_scanner_1__5D_ : UInt16 = 66
let gtl_debugger_scanner_1__2B__3D_ : UInt16 = 67
let gtl_debugger_scanner_1__2D__3D_ : UInt16 = 68
let gtl_debugger_scanner_1__2F_ : UInt16 = 69
let gtl_debugger_scanner_1__21__3D_ : UInt16 = 70
let gtl_debugger_scanner_1__3E__3D_ : UInt16 = 71
let gtl_debugger_scanner_1__26_ : UInt16 = 72
let gtl_debugger_scanner_1__3C__3D_ : UInt16 = 73
let gtl_debugger_scanner_1__7B_ : UInt16 = 74
let gtl_debugger_scanner_1__7D_ : UInt16 = 75
let gtl_debugger_scanner_1__3C_ : UInt16 = 76
let gtl_debugger_scanner_1__5E_ : UInt16 = 77
let gtl_debugger_scanner_1__3E__3E_ : UInt16 = 78
let gtl_debugger_scanner_1__7E_ : UInt16 = 79
let gtl_debugger_scanner_1__3C__2D_ : UInt16 = 80
let gtl_debugger_scanner_1__3C__3C_ : UInt16 = 81
let gtl_debugger_scanner_1__40_ : UInt16 = 82
let gtl_debugger_scanner_1__2A__3D_ : UInt16 = 83
let gtl_debugger_scanner_1__2F__3D_ : UInt16 = 84
let gtl_debugger_scanner_1__26__3D_ : UInt16 = 85
let gtl_debugger_scanner_1__7C__3D_ : UInt16 = 86
let gtl_debugger_scanner_1__3C__3C__3D_ : UInt16 = 87
let gtl_debugger_scanner_1__3E__3E__3D_ : UInt16 = 88
let gtl_debugger_scanner_1_mod_3D_ : UInt16 = 89
let gtl_debugger_scanner_1__5E__3D_ : UInt16 = 90
let gtl_debugger_scanner_1__40__5B_ : UInt16 = 91
let gtl_debugger_scanner_1__40__28_ : UInt16 = 92
let gtl_debugger_scanner_1__40__7B_ : UInt16 = 93
let gtl_debugger_scanner_1__5B__21_ : UInt16 = 94
let gtl_debugger_scanner_1__40__21_ : UInt16 = 95
let gtl_debugger_scanner_2_ERROR : UInt16 = 96
let gtl_debugger_scanner_2_TEMPLATE : UInt16 = 97

//----------------------------------------------------------------------------------------------------------------------

func gtl_debugger_scanner_lexiqueIdentifier () -> String {
  return "gtl_debugger_scanner"
}

//----------------------------------------------------------------------------------------------------------------------

func gtl_debugger_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Keywords", // 1
    "Delimiters", // 2
    "Non Terminal Symbols", // 3
    "Integer Constants", // 4
    "Floating Point Constants", // 5
    "String literals", // 6
    "Comments", // 7
    "Character Constants", // 8
    "Lexical error", // 9
    "Template" // 10
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------

func gtl_debugger_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "gtl_debugger_scanner", // 0
    "gtl_debugger_scanner-keywordsStyle", // 1
    "gtl_debugger_scanner-delimitersStyle", // 2
    "gtl_debugger_scanner-nonTerminalStyle", // 3
    "gtl_debugger_scanner-integerStyle", // 4
    "gtl_debugger_scanner-floatCsts", // 5
    "gtl_debugger_scanner-stringStyle", // 6
    "gtl_debugger_scanner-commentStyle", // 7
    "gtl_debugger_scanner-characterStyle", // 8
    "gtl_debugger_scanner.ERROR", // 9
    "gtl_debugger_scanner.TEMPLATE" // 10
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_gtl_debugger_scanner : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_a_string : String = ""
  private var mLexicalAttribute_charValue : UInt32 = 0
  private var mLexicalAttribute_floatValue : Double = 0.0
  private var mLexicalAttribute_functionContent : String = ""
  private var mLexicalAttribute_identifierString : String = ""
  private var mLexicalAttribute_intValue : String = ""
  private var mLexicalAttribute_tokenString : String = ""
  private var mLexicalAttribute_uint32value : UInt32 = 0

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return gtl_debugger_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 95
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_gtl_debugger_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_gtl_debugger_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_gtl_debugger_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_gtl_debugger_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_gtl_debugger_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      0, // 1 : gtl_debugger_scanner_1_identifier
      0, // 2 : gtl_debugger_scanner_1_literal_5F_enum
      5, // 3 : gtl_debugger_scanner_1_literal_5F_double
      4, // 4 : gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint
      2, // 5 : gtl_debugger_scanner_1__2D_
      2, // 6 : gtl_debugger_scanner_1__2E_
      2, // 7 : gtl_debugger_scanner_1__2E__3D_
      2, // 8 : gtl_debugger_scanner_1__2E__2E__2E_
      8, // 9 : gtl_debugger_scanner_1_literal_5F_char
      6, // 10 : gtl_debugger_scanner_1_string
      7, // 11 : gtl_debugger_scanner_1_comment
      1, // 12 : gtl_debugger_scanner_1_default
      1, // 13 : gtl_debugger_scanner_1_display
      1, // 14 : gtl_debugger_scanner_1_do
      1, // 15 : gtl_debugger_scanner_1_emptylist
      1, // 16 : gtl_debugger_scanner_1_emptymap
      1, // 17 : gtl_debugger_scanner_1_exists
      1, // 18 : gtl_debugger_scanner_1_false
      1, // 19 : gtl_debugger_scanner_1_list
      1, // 20 : gtl_debugger_scanner_1_import
      1, // 21 : gtl_debugger_scanner_1_listof
      1, // 22 : gtl_debugger_scanner_1_let
      1, // 23 : gtl_debugger_scanner_1_mapof
      1, // 24 : gtl_debugger_scanner_1_mod
      1, // 25 : gtl_debugger_scanner_1_no
      1, // 26 : gtl_debugger_scanner_1_not
      1, // 27 : gtl_debugger_scanner_1_or
      1, // 28 : gtl_debugger_scanner_1_print
      1, // 29 : gtl_debugger_scanner_1_sort
      1, // 30 : gtl_debugger_scanner_1_step
      1, // 31 : gtl_debugger_scanner_1_true
      1, // 32 : gtl_debugger_scanner_1_typeof
      1, // 33 : gtl_debugger_scanner_1_yes
      1, // 34 : gtl_debugger_scanner_1_variables
      1, // 35 : gtl_debugger_scanner_1_unlet
      1, // 36 : gtl_debugger_scanner_1_libraries
      1, // 37 : gtl_debugger_scanner_1_break
      1, // 38 : gtl_debugger_scanner_1_watch
      1, // 39 : gtl_debugger_scanner_1_by
      1, // 40 : gtl_debugger_scanner_1_end
      1, // 41 : gtl_debugger_scanner_1_cont
      1, // 42 : gtl_debugger_scanner_1_continue
      1, // 43 : gtl_debugger_scanner_1_help
      1, // 44 : gtl_debugger_scanner_1_if
      1, // 45 : gtl_debugger_scanner_1_then
      1, // 46 : gtl_debugger_scanner_1_else
      1, // 47 : gtl_debugger_scanner_1_elsif
      1, // 48 : gtl_debugger_scanner_1_hist
      1, // 49 : gtl_debugger_scanner_1_all
      1, // 50 : gtl_debugger_scanner_1_load
      2, // 51 : gtl_debugger_scanner_1__2A_
      2, // 52 : gtl_debugger_scanner_1__7C_
      2, // 53 : gtl_debugger_scanner_1__2C_
      2, // 54 : gtl_debugger_scanner_1__2B_
      2, // 55 : gtl_debugger_scanner_1__3A__3A_
      2, // 56 : gtl_debugger_scanner_1__3E_
      2, // 57 : gtl_debugger_scanner_1__3A_
      2, // 58 : gtl_debugger_scanner_1__28_
      2, // 59 : gtl_debugger_scanner_1__29_
      2, // 60 : gtl_debugger_scanner_1__2D__3E_
      2, // 61 : gtl_debugger_scanner_1__3F_
      2, // 62 : gtl_debugger_scanner_1__3D__3D_
      2, // 63 : gtl_debugger_scanner_1__21_
      2, // 64 : gtl_debugger_scanner_1__3A__3D_
      2, // 65 : gtl_debugger_scanner_1__5B_
      2, // 66 : gtl_debugger_scanner_1__5D_
      2, // 67 : gtl_debugger_scanner_1__2B__3D_
      2, // 68 : gtl_debugger_scanner_1__2D__3D_
      2, // 69 : gtl_debugger_scanner_1__2F_
      2, // 70 : gtl_debugger_scanner_1__21__3D_
      2, // 71 : gtl_debugger_scanner_1__3E__3D_
      2, // 72 : gtl_debugger_scanner_1__26_
      2, // 73 : gtl_debugger_scanner_1__3C__3D_
      2, // 74 : gtl_debugger_scanner_1__7B_
      2, // 75 : gtl_debugger_scanner_1__7D_
      2, // 76 : gtl_debugger_scanner_1__3C_
      2, // 77 : gtl_debugger_scanner_1__5E_
      2, // 78 : gtl_debugger_scanner_1__3E__3E_
      2, // 79 : gtl_debugger_scanner_1__7E_
      2, // 80 : gtl_debugger_scanner_1__3C__2D_
      2, // 81 : gtl_debugger_scanner_1__3C__3C_
      2, // 82 : gtl_debugger_scanner_1__40_
      2, // 83 : gtl_debugger_scanner_1__2A__3D_
      2, // 84 : gtl_debugger_scanner_1__2F__3D_
      2, // 85 : gtl_debugger_scanner_1__26__3D_
      2, // 86 : gtl_debugger_scanner_1__7C__3D_
      2, // 87 : gtl_debugger_scanner_1__3C__3C__3D_
      2, // 88 : gtl_debugger_scanner_1__3E__3E__3D_
      2, // 89 : gtl_debugger_scanner_1_mod_3D_
      2, // 90 : gtl_debugger_scanner_1__5E__3D_
      2, // 91 : gtl_debugger_scanner_1__40__5B_
      2, // 92 : gtl_debugger_scanner_1__40__28_
      2, // 93 : gtl_debugger_scanner_1__40__7B_
      2, // 94 : gtl_debugger_scanner_1__5B__21_
      2, // 95 : gtl_debugger_scanner_1__40__21_
      9, // 96 : gtl_debugger_scanner_2_ERROR
      10  // 97 : gtl_debugger_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : gtl_debugger_scanner_1_identifier
      true, // 2 : gtl_debugger_scanner_1_literal_5F_enum
      true, // 3 : gtl_debugger_scanner_1_literal_5F_double
      true, // 4 : gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint
      true, // 5 : gtl_debugger_scanner_1__2D_
      true, // 6 : gtl_debugger_scanner_1__2E_
      true, // 7 : gtl_debugger_scanner_1__2E__3D_
      true, // 8 : gtl_debugger_scanner_1__2E__2E__2E_
      true, // 9 : gtl_debugger_scanner_1_literal_5F_char
      true, // 10 : gtl_debugger_scanner_1_string
      true, // 11 : gtl_debugger_scanner_1_comment
      true, // 12 : gtl_debugger_scanner_1_default
      true, // 13 : gtl_debugger_scanner_1_display
      true, // 14 : gtl_debugger_scanner_1_do
      true, // 15 : gtl_debugger_scanner_1_emptylist
      true, // 16 : gtl_debugger_scanner_1_emptymap
      true, // 17 : gtl_debugger_scanner_1_exists
      true, // 18 : gtl_debugger_scanner_1_false
      true, // 19 : gtl_debugger_scanner_1_list
      true, // 20 : gtl_debugger_scanner_1_import
      true, // 21 : gtl_debugger_scanner_1_listof
      true, // 22 : gtl_debugger_scanner_1_let
      true, // 23 : gtl_debugger_scanner_1_mapof
      true, // 24 : gtl_debugger_scanner_1_mod
      true, // 25 : gtl_debugger_scanner_1_no
      true, // 26 : gtl_debugger_scanner_1_not
      true, // 27 : gtl_debugger_scanner_1_or
      true, // 28 : gtl_debugger_scanner_1_print
      true, // 29 : gtl_debugger_scanner_1_sort
      true, // 30 : gtl_debugger_scanner_1_step
      true, // 31 : gtl_debugger_scanner_1_true
      true, // 32 : gtl_debugger_scanner_1_typeof
      true, // 33 : gtl_debugger_scanner_1_yes
      true, // 34 : gtl_debugger_scanner_1_variables
      true, // 35 : gtl_debugger_scanner_1_unlet
      true, // 36 : gtl_debugger_scanner_1_libraries
      true, // 37 : gtl_debugger_scanner_1_break
      true, // 38 : gtl_debugger_scanner_1_watch
      true, // 39 : gtl_debugger_scanner_1_by
      true, // 40 : gtl_debugger_scanner_1_end
      true, // 41 : gtl_debugger_scanner_1_cont
      true, // 42 : gtl_debugger_scanner_1_continue
      true, // 43 : gtl_debugger_scanner_1_help
      true, // 44 : gtl_debugger_scanner_1_if
      true, // 45 : gtl_debugger_scanner_1_then
      true, // 46 : gtl_debugger_scanner_1_else
      true, // 47 : gtl_debugger_scanner_1_elsif
      true, // 48 : gtl_debugger_scanner_1_hist
      true, // 49 : gtl_debugger_scanner_1_all
      true, // 50 : gtl_debugger_scanner_1_load
      true, // 51 : gtl_debugger_scanner_1__2A_
      true, // 52 : gtl_debugger_scanner_1__7C_
      true, // 53 : gtl_debugger_scanner_1__2C_
      true, // 54 : gtl_debugger_scanner_1__2B_
      true, // 55 : gtl_debugger_scanner_1__3A__3A_
      true, // 56 : gtl_debugger_scanner_1__3E_
      true, // 57 : gtl_debugger_scanner_1__3A_
      true, // 58 : gtl_debugger_scanner_1__28_
      true, // 59 : gtl_debugger_scanner_1__29_
      true, // 60 : gtl_debugger_scanner_1__2D__3E_
      true, // 61 : gtl_debugger_scanner_1__3F_
      true, // 62 : gtl_debugger_scanner_1__3D__3D_
      true, // 63 : gtl_debugger_scanner_1__21_
      true, // 64 : gtl_debugger_scanner_1__3A__3D_
      true, // 65 : gtl_debugger_scanner_1__5B_
      true, // 66 : gtl_debugger_scanner_1__5D_
      true, // 67 : gtl_debugger_scanner_1__2B__3D_
      true, // 68 : gtl_debugger_scanner_1__2D__3D_
      true, // 69 : gtl_debugger_scanner_1__2F_
      true, // 70 : gtl_debugger_scanner_1__21__3D_
      true, // 71 : gtl_debugger_scanner_1__3E__3D_
      true, // 72 : gtl_debugger_scanner_1__26_
      true, // 73 : gtl_debugger_scanner_1__3C__3D_
      true, // 74 : gtl_debugger_scanner_1__7B_
      true, // 75 : gtl_debugger_scanner_1__7D_
      true, // 76 : gtl_debugger_scanner_1__3C_
      true, // 77 : gtl_debugger_scanner_1__5E_
      true, // 78 : gtl_debugger_scanner_1__3E__3E_
      true, // 79 : gtl_debugger_scanner_1__7E_
      true, // 80 : gtl_debugger_scanner_1__3C__2D_
      true, // 81 : gtl_debugger_scanner_1__3C__3C_
      true, // 82 : gtl_debugger_scanner_1__40_
      true, // 83 : gtl_debugger_scanner_1__2A__3D_
      true, // 84 : gtl_debugger_scanner_1__2F__3D_
      true, // 85 : gtl_debugger_scanner_1__26__3D_
      true, // 86 : gtl_debugger_scanner_1__7C__3D_
      true, // 87 : gtl_debugger_scanner_1__3C__3C__3D_
      true, // 88 : gtl_debugger_scanner_1__3E__3E__3D_
      true, // 89 : gtl_debugger_scanner_1_mod_3D_
      true, // 90 : gtl_debugger_scanner_1__5E__3D_
      true, // 91 : gtl_debugger_scanner_1__40__5B_
      true, // 92 : gtl_debugger_scanner_1__40__28_
      true, // 93 : gtl_debugger_scanner_1__40__7B_
      true, // 94 : gtl_debugger_scanner_1__5B__21_
      true, // 95 : gtl_debugger_scanner_1__40__21_
      false, // 96 : gtl_debugger_scanner_2_ERROR
      false  // 97 : gtl_debugger_scanner_2_TEMPLATE
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
    return 8
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return gtl_debugger_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return gtl_debugger_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_a_string = ""
    self.mLexicalAttribute_charValue = 0
    self.mLexicalAttribute_floatValue = 0.0
    self.mLexicalAttribute_functionContent = ""
    self.mLexicalAttribute_identifierString = ""
    self.mLexicalAttribute_intValue = ""
    self.mLexicalAttribute_tokenString = ""
    self.mLexicalAttribute_uint32value = 0
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_identifierString, self.previousChar)
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList (mLexicalAttribute_identifierString) ;
      }
      if tokenCode == 0 {
        tokenCode = gtl_debugger_scanner_1_identifier ;
      }
    }else if scanningOk && (self.testForInputChar (36)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = gtl_debugger_scanner_1_literal_5F_enum
    }else if scanningOk && self.testForInputString ("mod=", advance: true) {
      tokenCode = gtl_debugger_scanner_1_mod_3D_
    }else if scanningOk && self.testForInputString (">>=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3E__3E__3D_
    }else if scanningOk && self.testForInputString ("<<=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3C__3C__3D_
    }else if scanningOk && self.testForInputString ("|=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__7C__3D_
    }else if scanningOk && self.testForInputString ("^=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__5E__3D_
    }else if scanningOk && self.testForInputString ("[!", advance: true) {
      tokenCode = gtl_debugger_scanner_1__5B__21_
    }else if scanningOk && self.testForInputString ("@{", advance: true) {
      tokenCode = gtl_debugger_scanner_1__40__7B_
    }else if scanningOk && self.testForInputString ("@[", advance: true) {
      tokenCode = gtl_debugger_scanner_1__40__5B_
    }else if scanningOk && self.testForInputString ("@(", advance: true) {
      tokenCode = gtl_debugger_scanner_1__40__28_
    }else if scanningOk && self.testForInputString ("@!", advance: true) {
      tokenCode = gtl_debugger_scanner_1__40__21_
    }else if scanningOk && self.testForInputString (">>", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3E__3E_
    }else if scanningOk && self.testForInputString (">=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3E__3D_
    }else if scanningOk && self.testForInputString ("==", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3D__3D_
    }else if scanningOk && self.testForInputString ("<=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3C__3D_
    }else if scanningOk && self.testForInputString ("<<", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3C__3C_
    }else if scanningOk && self.testForInputString ("<-", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3C__2D_
    }else if scanningOk && self.testForInputString (":=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3A__3D_
    }else if scanningOk && self.testForInputString ("::", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3A__3A_
    }else if scanningOk && self.testForInputString ("/=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2F__3D_
    }else if scanningOk && self.testForInputString ("->", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2D__3E_
    }else if scanningOk && self.testForInputString ("-=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2D__3D_
    }else if scanningOk && self.testForInputString ("+=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2B__3D_
    }else if scanningOk && self.testForInputString ("*=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2A__3D_
    }else if scanningOk && self.testForInputString ("&=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__26__3D_
    }else if scanningOk && self.testForInputString ("!=", advance: true) {
      tokenCode = gtl_debugger_scanner_1__21__3D_
    }else if scanningOk && self.testForInputString ("~", advance: true) {
      tokenCode = gtl_debugger_scanner_1__7E_
    }else if scanningOk && self.testForInputString ("}", advance: true) {
      tokenCode = gtl_debugger_scanner_1__7D_
    }else if scanningOk && self.testForInputString ("|", advance: true) {
      tokenCode = gtl_debugger_scanner_1__7C_
    }else if scanningOk && self.testForInputString ("{", advance: true) {
      tokenCode = gtl_debugger_scanner_1__7B_
    }else if scanningOk && self.testForInputString ("^", advance: true) {
      tokenCode = gtl_debugger_scanner_1__5E_
    }else if scanningOk && self.testForInputString ("]", advance: true) {
      tokenCode = gtl_debugger_scanner_1__5D_
    }else if scanningOk && self.testForInputString ("[", advance: true) {
      tokenCode = gtl_debugger_scanner_1__5B_
    }else if scanningOk && self.testForInputString ("@", advance: true) {
      tokenCode = gtl_debugger_scanner_1__40_
    }else if scanningOk && self.testForInputString ("\?", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3F_
    }else if scanningOk && self.testForInputString (">", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3E_
    }else if scanningOk && self.testForInputString ("<", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3C_
    }else if scanningOk && self.testForInputString (":", advance: true) {
      tokenCode = gtl_debugger_scanner_1__3A_
    }else if scanningOk && self.testForInputString ("/", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2F_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2C_
    }else if scanningOk && self.testForInputString ("+", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2B_
    }else if scanningOk && self.testForInputString ("*", advance: true) {
      tokenCode = gtl_debugger_scanner_1__2A_
    }else if scanningOk && self.testForInputString (")", advance: true) {
      tokenCode = gtl_debugger_scanner_1__29_
    }else if scanningOk && self.testForInputString ("(", advance: true) {
      tokenCode = gtl_debugger_scanner_1__28_
    }else if scanningOk && self.testForInputString ("&", advance: true) {
      tokenCode = gtl_debugger_scanner_1__26_
    }else if scanningOk && self.testForInputString ("!", advance: true) {
      tokenCode = gtl_debugger_scanner_1__21_
    }else if scanningOk && (self.testForInputChar (45)) {
      if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 45)
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        while (loop && scanningOk) {
          if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
          }else if scanningOk && (self.testForInputChar (95)) {
          }else{
            loop = false
          }
        }
        loop = true
        if scanningOk && (self.testForInputChar (46)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 46)
          while (loop && scanningOk) {
            if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
              scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
            }else if scanningOk && (self.testForInputChar (95)) {
            }else{
              loop = false
            }
          }
          loop = true
          scanner_cocoa_routine_convertStringToDouble (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_floatValue)
          tokenCode = gtl_debugger_scanner_1_literal_5F_double
        }else{
          scanner_cocoa_routine_convertDecimalStringIntoBigInt (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_intValue)
          tokenCode = gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint
        }
      }else{
        tokenCode = gtl_debugger_scanner_1__2D_
      }
    }else if scanningOk && (self.testForInputString ("0x", advance: true) || self.testForInputString ("0X", advance: true)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      scanner_cocoa_routine_convertHexStringIntoBigInt (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_intValue)
      tokenCode = gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint
    }else if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
      scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        }else if scanningOk && (self.testForInputChar (95)) {
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (46)) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 46)
        while (loop && scanningOk) {
          if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
          }else if scanningOk && (self.testForInputChar (95)) {
          }else{
            loop = false
          }
        }
        loop = true
        scanner_cocoa_routine_convertStringToDouble (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_floatValue)
        tokenCode = gtl_debugger_scanner_1_literal_5F_double
      }else{
        scanner_cocoa_routine_convertDecimalStringIntoBigInt (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_intValue)
        tokenCode = gtl_debugger_scanner_1_signed_5F_literal_5F_integer_5F_bigint
      }
    }else if scanningOk && (self.testForInputChar (46)) {
      if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 48)
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 46)
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        while (loop && scanningOk) {
          if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
          }else if scanningOk && (self.testForInputChar (95)) {
          }else{
            loop = false
          }
        }
        loop = true
        scanner_cocoa_routine_convertStringToDouble (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_floatValue)
        tokenCode = gtl_debugger_scanner_1_literal_5F_double
      }else{
        if scanningOk && (self.testForInputString ("..", advance: true)) {
          tokenCode = gtl_debugger_scanner_1__2E__2E__2E_
        }else if scanningOk && (self.testForInputString ("=", advance: true)) {
          tokenCode = gtl_debugger_scanner_1__2E__3D_
        }else{
          tokenCode = gtl_debugger_scanner_1__2E_
        }
      }
    }else if scanningOk && (self.testForInputChar (39)) {
      if scanningOk && (self.testForInputChar (92)) {
        if scanningOk && (self.testForInputChar (102)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 12)
        }else if scanningOk && (self.testForInputChar (110)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 10)
        }else if scanningOk && (self.testForInputChar (114)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 13)
        }else if scanningOk && (self.testForInputChar (116)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 9)
        }else if scanningOk && (self.testForInputChar (118)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 11)
        }else if scanningOk && (self.testForInputChar (92)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 92)
        }else if scanningOk && (self.testForInputChar (48)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 0)
        }else if scanningOk && (self.testForInputChar (39)) {
          scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, 39)
        }else if scanningOk && (self.testForInputChar (117)) {
          if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
            scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
            if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
              if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                  scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (&scanningOk, &self.mLexicalAttribute_uint32value, &self.mLexicalAttribute_charValue)
                }else{
                  scanningOk = false
                }
              }else{
                scanningOk = false
              }
            }else{
              scanningOk = false
            }
          }else{
            scanningOk = false
          }
        }else if scanningOk && (self.testForInputChar (85)) {
          if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
            scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
            if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
              if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                  if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                    scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                    if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                      scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                      if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                        scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                        if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                          scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                          scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (&scanningOk, &self.mLexicalAttribute_uint32value, &self.mLexicalAttribute_charValue)
                        }else{
                          scanningOk = false
                        }
                      }else{
                        scanningOk = false
                      }
                    }else{
                      scanningOk = false
                    }
                  }else{
                    scanningOk = false
                  }
                }else{
                  scanningOk = false
                }
              }else{
                scanningOk = false
              }
            }else{
              scanningOk = false
            }
          }else{
            scanningOk = false
          }
        }else if scanningOk && (self.testForInputChar (38)) {
          while (loop && scanningOk) {
            if scanningOk && (self.notTestForInputString (";", error: &scanningOk)) {
              scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
            }else{
              loop = false
            }
          }
          loop = true
          scanner_cocoa_routine_convertHTMLSequenceToUnicodeCharacter (&scanningOk, &self.mLexicalAttribute_tokenString, &self.mLexicalAttribute_charValue)
        }else{
          scanningOk = false
        }
      }else if scanningOk && (self.testForInputFromChar (32, toChar:65533)) {
        scanner_cocoa_routine_enterCharacterIntoCharacter (&scanningOk, &self.mLexicalAttribute_charValue, self.previousChar)
      }else{
        scanningOk = false
      }
      if scanningOk && (self.testForInputChar (39)) {
        tokenCode = gtl_debugger_scanner_1_literal_5F_char
      }else{
        scanningOk = false
      }
    }else if scanningOk && (self.testForInputChar (34)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputChar (92)) {
          if scanningOk && (self.testForInputChar (102)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 12)
          }else if scanningOk && (self.testForInputChar (110)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 10)
          }else if scanningOk && (self.testForInputChar (114)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 13)
          }else if scanningOk && (self.testForInputChar (116)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 9)
          }else if scanningOk && (self.testForInputChar (118)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 11)
          }else if scanningOk && (self.testForInputChar (92)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 92)
          }else if scanningOk && (self.testForInputChar (34)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 34)
          }else if scanningOk && (self.testForInputChar (39)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 39)
          }else if scanningOk && (self.testForInputChar (63)) {
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, 63)
          }else if scanningOk && (self.testForInputChar (38)) {
            while (loop && scanningOk) {
              if scanningOk && (self.notTestForInputString (";", error: &scanningOk)) {
                scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_identifierString, self.previousChar)
              }else{
                loop = false
              }
            }
            loop = true
            scanner_cocoa_routine_convertHTMLSequenceToUnicodeCharacter (&scanningOk, &self.mLexicalAttribute_identifierString, &self.mLexicalAttribute_charValue)
            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, mLexicalAttribute_charValue)
          }else if scanningOk && (self.testForInputChar (117)) {
            if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
              if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                  if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                    scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                    scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (&scanningOk, &self.mLexicalAttribute_uint32value, &self.mLexicalAttribute_charValue)
                    scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, mLexicalAttribute_charValue)
                  }else{
                    scanningOk = false
                  }
                }else{
                  scanningOk = false
                }
              }else{
                scanningOk = false
              }
            }else{
              scanningOk = false
            }
          }else if scanningOk && (self.testForInputChar (85)) {
            if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
              scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
              if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                  scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                  if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                    scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                    if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                      scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                      if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                        scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                        if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                          scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                          if scanningOk && (self.testForInputFromChar (48, toChar:57) || self.testForInputFromChar (97, toChar:102) || self.testForInputFromChar (65, toChar:70)) {
                            scanner_cocoa_routine_enterHexDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_uint32value)
                            scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (&scanningOk, &self.mLexicalAttribute_uint32value, &self.mLexicalAttribute_charValue)
                            scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, mLexicalAttribute_charValue)
                          }else{
                            scanningOk = false
                          }
                        }else{
                          scanningOk = false
                        }
                      }else{
                        scanningOk = false
                      }
                    }else{
                      scanningOk = false
                    }
                  }else{
                    scanningOk = false
                  }
                }else{
                  scanningOk = false
                }
              }else{
                scanningOk = false
              }
            }else{
              scanningOk = false
            }
          }else{
            scanningOk = false
          }
        }else if scanningOk && (self.testForInputChar (32) || self.testForInputChar (33) || self.testForInputFromChar (35, toChar:65533)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_a_string, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (34)) {
        tokenCode = gtl_debugger_scanner_1_string
      }else{
        scanningOk = false
      }
    }else if scanningOk && (self.testForInputChar (35)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (1, toChar:9) || self.testForInputChar (11) || self.testForInputChar (12) || self.testForInputFromChar (14, toChar:65533)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = gtl_debugger_scanner_1_comment
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = gtl_debugger_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = gtl_debugger_scanner_2_TEMPLATE
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
    mLexicalAttribute_charValue = 0 ;
    mLexicalAttribute_floatValue = 0.0 ;
    mLexicalAttribute_functionContent = [[NSMutableString alloc] init] ;
    mLexicalAttribute_identifierString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_intValue = [[NSMutableString alloc] init] ;
    mLexicalAttribute_tokenString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_uint32value = 0 ;
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
//             Key words table 'goilTemplateKeyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_gtl_5F_debugger_5F_scanner_goilTemplateKeyWordList (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "by" : gtl_debugger_scanner_1_by,
    "do" : gtl_debugger_scanner_1_do,
    "if" : gtl_debugger_scanner_1_if,
    "no" : gtl_debugger_scanner_1_no,
    "or" : gtl_debugger_scanner_1_or,
    "all" : gtl_debugger_scanner_1_all,
    "end" : gtl_debugger_scanner_1_end,
    "let" : gtl_debugger_scanner_1_let,
    "mod" : gtl_debugger_scanner_1_mod,
    "not" : gtl_debugger_scanner_1_not,
    "yes" : gtl_debugger_scanner_1_yes,
    "cont" : gtl_debugger_scanner_1_cont,
    "else" : gtl_debugger_scanner_1_else,
    "help" : gtl_debugger_scanner_1_help,
    "hist" : gtl_debugger_scanner_1_hist,
    "list" : gtl_debugger_scanner_1_list,
    "load" : gtl_debugger_scanner_1_load,
    "sort" : gtl_debugger_scanner_1_sort,
    "step" : gtl_debugger_scanner_1_step,
    "then" : gtl_debugger_scanner_1_then,
    "true" : gtl_debugger_scanner_1_true,
    "break" : gtl_debugger_scanner_1_break,
    "elsif" : gtl_debugger_scanner_1_elsif,
    "false" : gtl_debugger_scanner_1_false,
    "mapof" : gtl_debugger_scanner_1_mapof,
    "print" : gtl_debugger_scanner_1_print,
    "unlet" : gtl_debugger_scanner_1_unlet,
    "watch" : gtl_debugger_scanner_1_watch,
    "exists" : gtl_debugger_scanner_1_exists,
    "import" : gtl_debugger_scanner_1_import,
    "listof" : gtl_debugger_scanner_1_listof,
    "typeof" : gtl_debugger_scanner_1_typeof,
    "default" : gtl_debugger_scanner_1_default,
    "display" : gtl_debugger_scanner_1_display,
    "continue" : gtl_debugger_scanner_1_continue,
    "emptymap" : gtl_debugger_scanner_1_emptymap,
    "emptylist" : gtl_debugger_scanner_1_emptylist,
    "libraries" : gtl_debugger_scanner_1_libraries,
    "variables" : gtl_debugger_scanner_1_variables
  ]
  return dictionary [inSearchedString, default: gtl_debugger_scanner_1_]
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



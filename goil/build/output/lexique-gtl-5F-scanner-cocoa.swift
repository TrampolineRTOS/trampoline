//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE gtl_scanner
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_gtl_scanner = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + gtl_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_gtl_scanner = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + gtl_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_gtl_scanner : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-nonTerminalStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-integerStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-floatCsts"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-stringStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-commentStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_gtl_scanner-characterStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_gtl_scanner_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_gtl_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_gtl_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-nonTerminalStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-floatCsts"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner-characterStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_gtl_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_gtl_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_gtl_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-nonTerminalStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-floatCsts"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner-characterStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_gtl_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements
//----------------------------------------------------------------------------------------------------------------------

fileprivate let kTemplateReplacementArray_gtl_5F_scanner : [String] = [
  "\\%",
  "\\n",
  "\\\\"
]


//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters
//----------------------------------------------------------------------------------------------------------------------

fileprivate let kTemplateDefinitionArray_gtl_5F_scanner : [SWIFT_TemplateDelimiter] = [
  SWIFT_TemplateDelimiter (startString: "%", endString: "%", discardStartString: true)
]


//----------------------------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//----------------------------------------------------------------------------------------------------------------------

let gtl_scanner_1_ : UInt16 = 0
let gtl_scanner_1_identifier : UInt16 = 1
let gtl_scanner_1_literal_5F_enum : UInt16 = 2
let gtl_scanner_1_literal_5F_double : UInt16 = 3
let gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint : UInt16 = 4
let gtl_scanner_1__2D_ : UInt16 = 5
let gtl_scanner_1__2E_ : UInt16 = 6
let gtl_scanner_1__2E__3D_ : UInt16 = 7
let gtl_scanner_1__2E__2E__2E_ : UInt16 = 8
let gtl_scanner_1_literal_5F_char : UInt16 = 9
let gtl_scanner_1_string : UInt16 = 10
let gtl_scanner_1_comment : UInt16 = 11
let gtl_scanner_1_after : UInt16 = 12
let gtl_scanner_1_before : UInt16 = 13
let gtl_scanner_1_between : UInt16 = 14
let gtl_scanner_1_by : UInt16 = 15
let gtl_scanner_1_default : UInt16 = 16
let gtl_scanner_1_display : UInt16 = 17
let gtl_scanner_1_do : UInt16 = 18
let gtl_scanner_1_down : UInt16 = 19
let gtl_scanner_1_else : UInt16 = 20
let gtl_scanner_1_elsif : UInt16 = 21
let gtl_scanner_1_emptylist : UInt16 = 22
let gtl_scanner_1_emptymap : UInt16 = 23
let gtl_scanner_1_end : UInt16 = 24
let gtl_scanner_1_error : UInt16 = 25
let gtl_scanner_1_exists : UInt16 = 26
let gtl_scanner_1_false : UInt16 = 27
let gtl_scanner_1_for : UInt16 = 28
let gtl_scanner_1_foreach : UInt16 = 29
let gtl_scanner_1_from : UInt16 = 30
let gtl_scanner_1_func : UInt16 = 31
let gtl_scanner_1_here : UInt16 = 32
let gtl_scanner_1_if : UInt16 = 33
let gtl_scanner_1_in : UInt16 = 34
let gtl_scanner_1_import : UInt16 = 35
let gtl_scanner_1_listof : UInt16 = 36
let gtl_scanner_1_let : UInt16 = 37
let gtl_scanner_1_loop : UInt16 = 38
let gtl_scanner_1_mapof : UInt16 = 39
let gtl_scanner_1_mod : UInt16 = 40
let gtl_scanner_1_no : UInt16 = 41
let gtl_scanner_1_not : UInt16 = 42
let gtl_scanner_1_or : UInt16 = 43
let gtl_scanner_1_print : UInt16 = 44
let gtl_scanner_1_println : UInt16 = 45
let gtl_scanner_1_seed : UInt16 = 46
let gtl_scanner_1_repeat : UInt16 = 47
let gtl_scanner_1_sort : UInt16 = 48
let gtl_scanner_1_step : UInt16 = 49
let gtl_scanner_1_tab : UInt16 = 50
let gtl_scanner_1_template : UInt16 = 51
let gtl_scanner_1_then : UInt16 = 52
let gtl_scanner_1_to : UInt16 = 53
let gtl_scanner_1_true : UInt16 = 54
let gtl_scanner_1_typeof : UInt16 = 55
let gtl_scanner_1_up : UInt16 = 56
let gtl_scanner_1_yes : UInt16 = 57
let gtl_scanner_1_warning : UInt16 = 58
let gtl_scanner_1_while : UInt16 = 59
let gtl_scanner_1_write : UInt16 = 60
let gtl_scanner_1_executable : UInt16 = 61
let gtl_scanner_1_variables : UInt16 = 62
let gtl_scanner_1_getter : UInt16 = 63
let gtl_scanner_1_unlet : UInt16 = 64
let gtl_scanner_1_setter : UInt16 = 65
let gtl_scanner_1_libraries : UInt16 = 66
let gtl_scanner_1_input : UInt16 = 67
let gtl_scanner_1_break : UInt16 = 68
let gtl_scanner_1__5F__5F_VARS_5F__5F_ : UInt16 = 69
let gtl_scanner_1__2A_ : UInt16 = 70
let gtl_scanner_1__7C_ : UInt16 = 71
let gtl_scanner_1__2C_ : UInt16 = 72
let gtl_scanner_1__2B_ : UInt16 = 73
let gtl_scanner_1__3A__3A_ : UInt16 = 74
let gtl_scanner_1__3E_ : UInt16 = 75
let gtl_scanner_1__3A_ : UInt16 = 76
let gtl_scanner_1__28_ : UInt16 = 77
let gtl_scanner_1__29_ : UInt16 = 78
let gtl_scanner_1__2D__3E_ : UInt16 = 79
let gtl_scanner_1__3F_ : UInt16 = 80
let gtl_scanner_1__3D__3D_ : UInt16 = 81
let gtl_scanner_1__21_ : UInt16 = 82
let gtl_scanner_1__3A__3D_ : UInt16 = 83
let gtl_scanner_1__5B_ : UInt16 = 84
let gtl_scanner_1__5D_ : UInt16 = 85
let gtl_scanner_1__2B__3D_ : UInt16 = 86
let gtl_scanner_1__2D__3D_ : UInt16 = 87
let gtl_scanner_1__2F_ : UInt16 = 88
let gtl_scanner_1__21__3D_ : UInt16 = 89
let gtl_scanner_1__3E__3D_ : UInt16 = 90
let gtl_scanner_1__26_ : UInt16 = 91
let gtl_scanner_1__3C__3D_ : UInt16 = 92
let gtl_scanner_1__7B_ : UInt16 = 93
let gtl_scanner_1__7D_ : UInt16 = 94
let gtl_scanner_1__3C_ : UInt16 = 95
let gtl_scanner_1__5E_ : UInt16 = 96
let gtl_scanner_1__3E__3E_ : UInt16 = 97
let gtl_scanner_1__7E_ : UInt16 = 98
let gtl_scanner_1__3C__2D_ : UInt16 = 99
let gtl_scanner_1__3C__3C_ : UInt16 = 100
let gtl_scanner_1__40_ : UInt16 = 101
let gtl_scanner_1__2A__3D_ : UInt16 = 102
let gtl_scanner_1__2F__3D_ : UInt16 = 103
let gtl_scanner_1__26__3D_ : UInt16 = 104
let gtl_scanner_1__7C__3D_ : UInt16 = 105
let gtl_scanner_1__3C__3C__3D_ : UInt16 = 106
let gtl_scanner_1__3E__3E__3D_ : UInt16 = 107
let gtl_scanner_1_mod_3D_ : UInt16 = 108
let gtl_scanner_1__5E__3D_ : UInt16 = 109
let gtl_scanner_1__40__5B_ : UInt16 = 110
let gtl_scanner_1__40__28_ : UInt16 = 111
let gtl_scanner_1__40__7B_ : UInt16 = 112
let gtl_scanner_1__5B__21_ : UInt16 = 113
let gtl_scanner_1__40__21_ : UInt16 = 114
let gtl_scanner_1__40__3F_ : UInt16 = 115
let gtl_scanner_2_ERROR : UInt16 = 116
let gtl_scanner_2_TEMPLATE : UInt16 = 117

//----------------------------------------------------------------------------------------------------------------------

func gtl_scanner_lexiqueIdentifier () -> String {
  return "gtl_scanner"
}

//----------------------------------------------------------------------------------------------------------------------

func gtl_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
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

func gtl_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "gtl_scanner", // 0
    "gtl_scanner-keywordsStyle", // 1
    "gtl_scanner-delimitersStyle", // 2
    "gtl_scanner-nonTerminalStyle", // 3
    "gtl_scanner-integerStyle", // 4
    "gtl_scanner-floatCsts", // 5
    "gtl_scanner-stringStyle", // 6
    "gtl_scanner-commentStyle", // 7
    "gtl_scanner-characterStyle", // 8
    "gtl_scanner.ERROR", // 9
    "gtl_scanner.TEMPLATE" // 10
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_gtl_scanner : SWIFT_Lexique {

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
    return gtl_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return true
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 115
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_gtl_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_gtl_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_gtl_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_gtl_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_gtl_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      0, // 1 : gtl_scanner_1_identifier
      0, // 2 : gtl_scanner_1_literal_5F_enum
      5, // 3 : gtl_scanner_1_literal_5F_double
      4, // 4 : gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint
      2, // 5 : gtl_scanner_1__2D_
      2, // 6 : gtl_scanner_1__2E_
      2, // 7 : gtl_scanner_1__2E__3D_
      2, // 8 : gtl_scanner_1__2E__2E__2E_
      8, // 9 : gtl_scanner_1_literal_5F_char
      6, // 10 : gtl_scanner_1_string
      7, // 11 : gtl_scanner_1_comment
      1, // 12 : gtl_scanner_1_after
      1, // 13 : gtl_scanner_1_before
      1, // 14 : gtl_scanner_1_between
      1, // 15 : gtl_scanner_1_by
      1, // 16 : gtl_scanner_1_default
      1, // 17 : gtl_scanner_1_display
      1, // 18 : gtl_scanner_1_do
      1, // 19 : gtl_scanner_1_down
      1, // 20 : gtl_scanner_1_else
      1, // 21 : gtl_scanner_1_elsif
      1, // 22 : gtl_scanner_1_emptylist
      1, // 23 : gtl_scanner_1_emptymap
      1, // 24 : gtl_scanner_1_end
      1, // 25 : gtl_scanner_1_error
      1, // 26 : gtl_scanner_1_exists
      1, // 27 : gtl_scanner_1_false
      1, // 28 : gtl_scanner_1_for
      1, // 29 : gtl_scanner_1_foreach
      1, // 30 : gtl_scanner_1_from
      1, // 31 : gtl_scanner_1_func
      1, // 32 : gtl_scanner_1_here
      1, // 33 : gtl_scanner_1_if
      1, // 34 : gtl_scanner_1_in
      1, // 35 : gtl_scanner_1_import
      1, // 36 : gtl_scanner_1_listof
      1, // 37 : gtl_scanner_1_let
      1, // 38 : gtl_scanner_1_loop
      1, // 39 : gtl_scanner_1_mapof
      1, // 40 : gtl_scanner_1_mod
      1, // 41 : gtl_scanner_1_no
      1, // 42 : gtl_scanner_1_not
      1, // 43 : gtl_scanner_1_or
      1, // 44 : gtl_scanner_1_print
      1, // 45 : gtl_scanner_1_println
      1, // 46 : gtl_scanner_1_seed
      1, // 47 : gtl_scanner_1_repeat
      1, // 48 : gtl_scanner_1_sort
      1, // 49 : gtl_scanner_1_step
      1, // 50 : gtl_scanner_1_tab
      1, // 51 : gtl_scanner_1_template
      1, // 52 : gtl_scanner_1_then
      1, // 53 : gtl_scanner_1_to
      1, // 54 : gtl_scanner_1_true
      1, // 55 : gtl_scanner_1_typeof
      1, // 56 : gtl_scanner_1_up
      1, // 57 : gtl_scanner_1_yes
      1, // 58 : gtl_scanner_1_warning
      1, // 59 : gtl_scanner_1_while
      1, // 60 : gtl_scanner_1_write
      1, // 61 : gtl_scanner_1_executable
      1, // 62 : gtl_scanner_1_variables
      1, // 63 : gtl_scanner_1_getter
      1, // 64 : gtl_scanner_1_unlet
      1, // 65 : gtl_scanner_1_setter
      1, // 66 : gtl_scanner_1_libraries
      1, // 67 : gtl_scanner_1_input
      1, // 68 : gtl_scanner_1_break
      1, // 69 : gtl_scanner_1__5F__5F_VARS_5F__5F_
      2, // 70 : gtl_scanner_1__2A_
      2, // 71 : gtl_scanner_1__7C_
      2, // 72 : gtl_scanner_1__2C_
      2, // 73 : gtl_scanner_1__2B_
      2, // 74 : gtl_scanner_1__3A__3A_
      2, // 75 : gtl_scanner_1__3E_
      2, // 76 : gtl_scanner_1__3A_
      2, // 77 : gtl_scanner_1__28_
      2, // 78 : gtl_scanner_1__29_
      2, // 79 : gtl_scanner_1__2D__3E_
      2, // 80 : gtl_scanner_1__3F_
      2, // 81 : gtl_scanner_1__3D__3D_
      2, // 82 : gtl_scanner_1__21_
      2, // 83 : gtl_scanner_1__3A__3D_
      2, // 84 : gtl_scanner_1__5B_
      2, // 85 : gtl_scanner_1__5D_
      2, // 86 : gtl_scanner_1__2B__3D_
      2, // 87 : gtl_scanner_1__2D__3D_
      2, // 88 : gtl_scanner_1__2F_
      2, // 89 : gtl_scanner_1__21__3D_
      2, // 90 : gtl_scanner_1__3E__3D_
      2, // 91 : gtl_scanner_1__26_
      2, // 92 : gtl_scanner_1__3C__3D_
      2, // 93 : gtl_scanner_1__7B_
      2, // 94 : gtl_scanner_1__7D_
      2, // 95 : gtl_scanner_1__3C_
      2, // 96 : gtl_scanner_1__5E_
      2, // 97 : gtl_scanner_1__3E__3E_
      2, // 98 : gtl_scanner_1__7E_
      2, // 99 : gtl_scanner_1__3C__2D_
      2, // 100 : gtl_scanner_1__3C__3C_
      2, // 101 : gtl_scanner_1__40_
      2, // 102 : gtl_scanner_1__2A__3D_
      2, // 103 : gtl_scanner_1__2F__3D_
      2, // 104 : gtl_scanner_1__26__3D_
      2, // 105 : gtl_scanner_1__7C__3D_
      2, // 106 : gtl_scanner_1__3C__3C__3D_
      2, // 107 : gtl_scanner_1__3E__3E__3D_
      2, // 108 : gtl_scanner_1_mod_3D_
      2, // 109 : gtl_scanner_1__5E__3D_
      2, // 110 : gtl_scanner_1__40__5B_
      2, // 111 : gtl_scanner_1__40__28_
      2, // 112 : gtl_scanner_1__40__7B_
      2, // 113 : gtl_scanner_1__5B__21_
      2, // 114 : gtl_scanner_1__40__21_
      2, // 115 : gtl_scanner_1__40__3F_
      9, // 116 : gtl_scanner_2_ERROR
      10  // 117 : gtl_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : gtl_scanner_1_identifier
      true, // 2 : gtl_scanner_1_literal_5F_enum
      true, // 3 : gtl_scanner_1_literal_5F_double
      true, // 4 : gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint
      true, // 5 : gtl_scanner_1__2D_
      true, // 6 : gtl_scanner_1__2E_
      true, // 7 : gtl_scanner_1__2E__3D_
      true, // 8 : gtl_scanner_1__2E__2E__2E_
      true, // 9 : gtl_scanner_1_literal_5F_char
      true, // 10 : gtl_scanner_1_string
      true, // 11 : gtl_scanner_1_comment
      true, // 12 : gtl_scanner_1_after
      true, // 13 : gtl_scanner_1_before
      true, // 14 : gtl_scanner_1_between
      true, // 15 : gtl_scanner_1_by
      true, // 16 : gtl_scanner_1_default
      true, // 17 : gtl_scanner_1_display
      true, // 18 : gtl_scanner_1_do
      true, // 19 : gtl_scanner_1_down
      true, // 20 : gtl_scanner_1_else
      true, // 21 : gtl_scanner_1_elsif
      true, // 22 : gtl_scanner_1_emptylist
      true, // 23 : gtl_scanner_1_emptymap
      true, // 24 : gtl_scanner_1_end
      true, // 25 : gtl_scanner_1_error
      true, // 26 : gtl_scanner_1_exists
      true, // 27 : gtl_scanner_1_false
      true, // 28 : gtl_scanner_1_for
      true, // 29 : gtl_scanner_1_foreach
      true, // 30 : gtl_scanner_1_from
      true, // 31 : gtl_scanner_1_func
      true, // 32 : gtl_scanner_1_here
      true, // 33 : gtl_scanner_1_if
      true, // 34 : gtl_scanner_1_in
      true, // 35 : gtl_scanner_1_import
      true, // 36 : gtl_scanner_1_listof
      true, // 37 : gtl_scanner_1_let
      true, // 38 : gtl_scanner_1_loop
      true, // 39 : gtl_scanner_1_mapof
      true, // 40 : gtl_scanner_1_mod
      true, // 41 : gtl_scanner_1_no
      true, // 42 : gtl_scanner_1_not
      true, // 43 : gtl_scanner_1_or
      true, // 44 : gtl_scanner_1_print
      true, // 45 : gtl_scanner_1_println
      true, // 46 : gtl_scanner_1_seed
      true, // 47 : gtl_scanner_1_repeat
      true, // 48 : gtl_scanner_1_sort
      true, // 49 : gtl_scanner_1_step
      true, // 50 : gtl_scanner_1_tab
      true, // 51 : gtl_scanner_1_template
      true, // 52 : gtl_scanner_1_then
      true, // 53 : gtl_scanner_1_to
      true, // 54 : gtl_scanner_1_true
      true, // 55 : gtl_scanner_1_typeof
      true, // 56 : gtl_scanner_1_up
      true, // 57 : gtl_scanner_1_yes
      true, // 58 : gtl_scanner_1_warning
      true, // 59 : gtl_scanner_1_while
      true, // 60 : gtl_scanner_1_write
      true, // 61 : gtl_scanner_1_executable
      true, // 62 : gtl_scanner_1_variables
      true, // 63 : gtl_scanner_1_getter
      true, // 64 : gtl_scanner_1_unlet
      true, // 65 : gtl_scanner_1_setter
      true, // 66 : gtl_scanner_1_libraries
      true, // 67 : gtl_scanner_1_input
      true, // 68 : gtl_scanner_1_break
      true, // 69 : gtl_scanner_1__5F__5F_VARS_5F__5F_
      true, // 70 : gtl_scanner_1__2A_
      true, // 71 : gtl_scanner_1__7C_
      true, // 72 : gtl_scanner_1__2C_
      true, // 73 : gtl_scanner_1__2B_
      true, // 74 : gtl_scanner_1__3A__3A_
      true, // 75 : gtl_scanner_1__3E_
      true, // 76 : gtl_scanner_1__3A_
      true, // 77 : gtl_scanner_1__28_
      true, // 78 : gtl_scanner_1__29_
      true, // 79 : gtl_scanner_1__2D__3E_
      true, // 80 : gtl_scanner_1__3F_
      true, // 81 : gtl_scanner_1__3D__3D_
      true, // 82 : gtl_scanner_1__21_
      true, // 83 : gtl_scanner_1__3A__3D_
      true, // 84 : gtl_scanner_1__5B_
      true, // 85 : gtl_scanner_1__5D_
      true, // 86 : gtl_scanner_1__2B__3D_
      true, // 87 : gtl_scanner_1__2D__3D_
      true, // 88 : gtl_scanner_1__2F_
      true, // 89 : gtl_scanner_1__21__3D_
      true, // 90 : gtl_scanner_1__3E__3D_
      true, // 91 : gtl_scanner_1__26_
      true, // 92 : gtl_scanner_1__3C__3D_
      true, // 93 : gtl_scanner_1__7B_
      true, // 94 : gtl_scanner_1__7D_
      true, // 95 : gtl_scanner_1__3C_
      true, // 96 : gtl_scanner_1__5E_
      true, // 97 : gtl_scanner_1__3E__3E_
      true, // 98 : gtl_scanner_1__7E_
      true, // 99 : gtl_scanner_1__3C__2D_
      true, // 100 : gtl_scanner_1__3C__3C_
      true, // 101 : gtl_scanner_1__40_
      true, // 102 : gtl_scanner_1__2A__3D_
      true, // 103 : gtl_scanner_1__2F__3D_
      true, // 104 : gtl_scanner_1__26__3D_
      true, // 105 : gtl_scanner_1__7C__3D_
      true, // 106 : gtl_scanner_1__3C__3C__3D_
      true, // 107 : gtl_scanner_1__3E__3E__3D_
      true, // 108 : gtl_scanner_1_mod_3D_
      true, // 109 : gtl_scanner_1__5E__3D_
      true, // 110 : gtl_scanner_1__40__5B_
      true, // 111 : gtl_scanner_1__40__28_
      true, // 112 : gtl_scanner_1__40__7B_
      true, // 113 : gtl_scanner_1__5B__21_
      true, // 114 : gtl_scanner_1__40__21_
      true, // 115 : gtl_scanner_1__40__3F_
      false, // 116 : gtl_scanner_2_ERROR
      false  // 117 : gtl_scanner_2_TEMPLATE
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
    return gtl_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return gtl_scanner_styleIdentifierFor (styleIndex: inIndex)
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
    if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95)) {
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
        tokenCode = search_into_gtl_5F_scanner_goilTemplateKeyWordList (mLexicalAttribute_identifierString) ;
      }
      if tokenCode == 0 {
        tokenCode = gtl_scanner_1_identifier ;
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
      tokenCode = gtl_scanner_1_literal_5F_enum
    }else if scanningOk && self.testForInputString ("mod=", advance: true) {
      tokenCode = gtl_scanner_1_mod_3D_
    }else if scanningOk && self.testForInputString (">>=", advance: true) {
      tokenCode = gtl_scanner_1__3E__3E__3D_
    }else if scanningOk && self.testForInputString ("<<=", advance: true) {
      tokenCode = gtl_scanner_1__3C__3C__3D_
    }else if scanningOk && self.testForInputString ("|=", advance: true) {
      tokenCode = gtl_scanner_1__7C__3D_
    }else if scanningOk && self.testForInputString ("^=", advance: true) {
      tokenCode = gtl_scanner_1__5E__3D_
    }else if scanningOk && self.testForInputString ("[!", advance: true) {
      tokenCode = gtl_scanner_1__5B__21_
    }else if scanningOk && self.testForInputString ("@{", advance: true) {
      tokenCode = gtl_scanner_1__40__7B_
    }else if scanningOk && self.testForInputString ("@[", advance: true) {
      tokenCode = gtl_scanner_1__40__5B_
    }else if scanningOk && self.testForInputString ("@\?", advance: true) {
      tokenCode = gtl_scanner_1__40__3F_
    }else if scanningOk && self.testForInputString ("@(", advance: true) {
      tokenCode = gtl_scanner_1__40__28_
    }else if scanningOk && self.testForInputString ("@!", advance: true) {
      tokenCode = gtl_scanner_1__40__21_
    }else if scanningOk && self.testForInputString (">>", advance: true) {
      tokenCode = gtl_scanner_1__3E__3E_
    }else if scanningOk && self.testForInputString (">=", advance: true) {
      tokenCode = gtl_scanner_1__3E__3D_
    }else if scanningOk && self.testForInputString ("==", advance: true) {
      tokenCode = gtl_scanner_1__3D__3D_
    }else if scanningOk && self.testForInputString ("<=", advance: true) {
      tokenCode = gtl_scanner_1__3C__3D_
    }else if scanningOk && self.testForInputString ("<<", advance: true) {
      tokenCode = gtl_scanner_1__3C__3C_
    }else if scanningOk && self.testForInputString ("<-", advance: true) {
      tokenCode = gtl_scanner_1__3C__2D_
    }else if scanningOk && self.testForInputString (":=", advance: true) {
      tokenCode = gtl_scanner_1__3A__3D_
    }else if scanningOk && self.testForInputString ("::", advance: true) {
      tokenCode = gtl_scanner_1__3A__3A_
    }else if scanningOk && self.testForInputString ("/=", advance: true) {
      tokenCode = gtl_scanner_1__2F__3D_
    }else if scanningOk && self.testForInputString ("->", advance: true) {
      tokenCode = gtl_scanner_1__2D__3E_
    }else if scanningOk && self.testForInputString ("-=", advance: true) {
      tokenCode = gtl_scanner_1__2D__3D_
    }else if scanningOk && self.testForInputString ("+=", advance: true) {
      tokenCode = gtl_scanner_1__2B__3D_
    }else if scanningOk && self.testForInputString ("*=", advance: true) {
      tokenCode = gtl_scanner_1__2A__3D_
    }else if scanningOk && self.testForInputString ("&=", advance: true) {
      tokenCode = gtl_scanner_1__26__3D_
    }else if scanningOk && self.testForInputString ("!=", advance: true) {
      tokenCode = gtl_scanner_1__21__3D_
    }else if scanningOk && self.testForInputString ("~", advance: true) {
      tokenCode = gtl_scanner_1__7E_
    }else if scanningOk && self.testForInputString ("}", advance: true) {
      tokenCode = gtl_scanner_1__7D_
    }else if scanningOk && self.testForInputString ("|", advance: true) {
      tokenCode = gtl_scanner_1__7C_
    }else if scanningOk && self.testForInputString ("{", advance: true) {
      tokenCode = gtl_scanner_1__7B_
    }else if scanningOk && self.testForInputString ("^", advance: true) {
      tokenCode = gtl_scanner_1__5E_
    }else if scanningOk && self.testForInputString ("]", advance: true) {
      tokenCode = gtl_scanner_1__5D_
    }else if scanningOk && self.testForInputString ("[", advance: true) {
      tokenCode = gtl_scanner_1__5B_
    }else if scanningOk && self.testForInputString ("@", advance: true) {
      tokenCode = gtl_scanner_1__40_
    }else if scanningOk && self.testForInputString ("\?", advance: true) {
      tokenCode = gtl_scanner_1__3F_
    }else if scanningOk && self.testForInputString (">", advance: true) {
      tokenCode = gtl_scanner_1__3E_
    }else if scanningOk && self.testForInputString ("<", advance: true) {
      tokenCode = gtl_scanner_1__3C_
    }else if scanningOk && self.testForInputString (":", advance: true) {
      tokenCode = gtl_scanner_1__3A_
    }else if scanningOk && self.testForInputString ("/", advance: true) {
      tokenCode = gtl_scanner_1__2F_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = gtl_scanner_1__2C_
    }else if scanningOk && self.testForInputString ("+", advance: true) {
      tokenCode = gtl_scanner_1__2B_
    }else if scanningOk && self.testForInputString ("*", advance: true) {
      tokenCode = gtl_scanner_1__2A_
    }else if scanningOk && self.testForInputString (")", advance: true) {
      tokenCode = gtl_scanner_1__29_
    }else if scanningOk && self.testForInputString ("(", advance: true) {
      tokenCode = gtl_scanner_1__28_
    }else if scanningOk && self.testForInputString ("&", advance: true) {
      tokenCode = gtl_scanner_1__26_
    }else if scanningOk && self.testForInputString ("!", advance: true) {
      tokenCode = gtl_scanner_1__21_
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
          tokenCode = gtl_scanner_1_literal_5F_double
        }else{
          scanner_cocoa_routine_convertDecimalStringIntoBigInt (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_intValue)
          tokenCode = gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint
        }
      }else{
        tokenCode = gtl_scanner_1__2D_
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
      tokenCode = gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint
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
        tokenCode = gtl_scanner_1_literal_5F_double
      }else{
        scanner_cocoa_routine_convertDecimalStringIntoBigInt (&scanningOk, mLexicalAttribute_tokenString, &self.mLexicalAttribute_intValue)
        tokenCode = gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint
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
        tokenCode = gtl_scanner_1_literal_5F_double
      }else{
        if scanningOk && (self.testForInputString ("..", advance: true)) {
          tokenCode = gtl_scanner_1__2E__2E__2E_
        }else if scanningOk && (self.testForInputString ("=", advance: true)) {
          tokenCode = gtl_scanner_1__2E__3D_
        }else{
          tokenCode = gtl_scanner_1__2E_
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
        tokenCode = gtl_scanner_1_literal_5F_char
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
        tokenCode = gtl_scanner_1_string
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
      tokenCode = gtl_scanner_1_comment
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = gtl_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = gtl_scanner_2_TEMPLATE
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
  if (nil == kTemplateDefinitionArray_gtl_5F_scanner) {
    kTemplateDefinitionArray_gtl_5F_scanner = [NSArray arrayWithObjects:
      [[OC_GGS_TemplateDelimiter alloc] initWithStartString:@"%" endString:@"%" discardStartString:YES],
      nil
    ] ;
  }
  if (nil == kTemplateReplacementArray_gtl_5F_scanner) {

    kTemplateReplacementArray_gtl_5F_scanner = [NSArray arrayWithObjects:
      @"\\%",       @"\\n",       @"\\\\",       nil
    ] ;
  }
  return self ;
} */

//----------------------------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//----------------------------------------------------------------------------------------------------------------------

/*
static const BOOL kEndOfScriptInTemplateArray_gtl_5F_scanner [115] = {
  NO /* identifier */,
  NO /* literal_enum */,
  NO /* literal_double */,
  NO /* signed_literal_integer_bigint */,
  NO /* - */,
  NO /* . */,
  NO /* .= */,
  NO /* ... */,
  NO /* literal_char */,
  NO /* string */,
  NO /* comment */,
  NO /* after */,
  NO /* before */,
  NO /* between */,
  NO /* by */,
  NO /* default */,
  NO /* display */,
  NO /* do */,
  NO /* down */,
  NO /* else */,
  NO /* elsif */,
  NO /* emptylist */,
  NO /* emptymap */,
  NO /* end */,
  NO /* error */,
  NO /* exists */,
  NO /* false */,
  NO /* for */,
  NO /* foreach */,
  NO /* from */,
  NO /* func */,
  NO /* here */,
  NO /* if */,
  NO /* in */,
  NO /* import */,
  NO /* listof */,
  NO /* let */,
  NO /* loop */,
  NO /* mapof */,
  NO /* mod */,
  NO /* no */,
  NO /* not */,
  NO /* or */,
  NO /* print */,
  NO /* println */,
  NO /* seed */,
  NO /* repeat */,
  NO /* sort */,
  NO /* step */,
  NO /* tab */,
  NO /* template */,
  NO /* then */,
  NO /* to */,
  NO /* true */,
  NO /* typeof */,
  NO /* up */,
  NO /* yes */,
  NO /* warning */,
  NO /* while */,
  NO /* write */,
  NO /* executable */,
  NO /* variables */,
  NO /* getter */,
  NO /* unlet */,
  NO /* setter */,
  NO /* libraries */,
  NO /* input */,
  NO /* break */,
  NO /* __VARS__ */,
  NO /* * */,
  NO /* | */,
  NO /* , */,
  NO /* + */,
  NO /* :: */,
  NO /* > */,
  NO /* : */,
  NO /* ( */,
  NO /* ) */,
  NO /* -> */,
  NO /* ? */,
  NO /* == */,
  NO /* ! */,
  NO /* := */,
  NO /* [ */,
  NO /* ] */,
  NO /* += */,
  NO /* -= */,
  NO /* / */,
  NO /* != */,
  NO /* >= */,
  NO /* & */,
  NO /* <= */,
  NO /* { */,
  NO /* } */,
  NO /* < */,
  NO /* ^ */,
  NO /* >> */,
  NO /* ~ */,
  NO /* <- */,
  NO /* << */,
  NO /* @ */,
  NO /* *= */,
  NO /* /= */,
  NO /* &= */,
  NO /* |= */,
  NO /* <<= */,
  NO /* >>= */,
  NO /* mod= */,
  NO /* ^= */,
  NO /* @[ */,
  NO /* @( */,
  NO /* @{ */,
  NO /* [! */,
  NO /* @! */,
  NO /* @? */
} ;

*/


//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'goilTemplateKeyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_gtl_5F_scanner_goilTemplateKeyWordList (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "by" : gtl_scanner_1_by,
    "do" : gtl_scanner_1_do,
    "if" : gtl_scanner_1_if,
    "in" : gtl_scanner_1_in,
    "no" : gtl_scanner_1_no,
    "or" : gtl_scanner_1_or,
    "to" : gtl_scanner_1_to,
    "up" : gtl_scanner_1_up,
    "end" : gtl_scanner_1_end,
    "for" : gtl_scanner_1_for,
    "let" : gtl_scanner_1_let,
    "mod" : gtl_scanner_1_mod,
    "not" : gtl_scanner_1_not,
    "tab" : gtl_scanner_1_tab,
    "yes" : gtl_scanner_1_yes,
    "down" : gtl_scanner_1_down,
    "else" : gtl_scanner_1_else,
    "from" : gtl_scanner_1_from,
    "func" : gtl_scanner_1_func,
    "here" : gtl_scanner_1_here,
    "loop" : gtl_scanner_1_loop,
    "seed" : gtl_scanner_1_seed,
    "sort" : gtl_scanner_1_sort,
    "step" : gtl_scanner_1_step,
    "then" : gtl_scanner_1_then,
    "true" : gtl_scanner_1_true,
    "after" : gtl_scanner_1_after,
    "break" : gtl_scanner_1_break,
    "elsif" : gtl_scanner_1_elsif,
    "error" : gtl_scanner_1_error,
    "false" : gtl_scanner_1_false,
    "input" : gtl_scanner_1_input,
    "mapof" : gtl_scanner_1_mapof,
    "print" : gtl_scanner_1_print,
    "unlet" : gtl_scanner_1_unlet,
    "while" : gtl_scanner_1_while,
    "write" : gtl_scanner_1_write,
    "before" : gtl_scanner_1_before,
    "exists" : gtl_scanner_1_exists,
    "getter" : gtl_scanner_1_getter,
    "import" : gtl_scanner_1_import,
    "listof" : gtl_scanner_1_listof,
    "repeat" : gtl_scanner_1_repeat,
    "setter" : gtl_scanner_1_setter,
    "typeof" : gtl_scanner_1_typeof,
    "between" : gtl_scanner_1_between,
    "default" : gtl_scanner_1_default,
    "display" : gtl_scanner_1_display,
    "foreach" : gtl_scanner_1_foreach,
    "println" : gtl_scanner_1_println,
    "warning" : gtl_scanner_1_warning,
    "__VARS__" : gtl_scanner_1__5F__5F_VARS_5F__5F_,
    "emptymap" : gtl_scanner_1_emptymap,
    "template" : gtl_scanner_1_template,
    "emptylist" : gtl_scanner_1_emptylist,
    "libraries" : gtl_scanner_1_libraries,
    "variables" : gtl_scanner_1_variables,
    "executable" : gtl_scanner_1_executable
  ]
  return dictionary [inSearchedString, default: gtl_scanner_1_]
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
    if ((mMatchedTemplateDelimiterIndex >= 0) && ([[kTemplateDefinitionArray_gtl_5F_scanner objectAtIndex:(NSUInteger) mMatchedTemplateDelimiterIndex] startString].length > 0)) {
      const BOOL foundEndDelimitor = [self testForInputString:[[kTemplateDefinitionArray_gtl_5F_scanner objectAtIndex:(NSUInteger) mMatchedTemplateDelimiterIndex] endString] advance:YES] ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (mCurrentChar != '\0')) {
      
      [self searchForReplacementPattern:kTemplateReplacementArray_gtl_5F_scanner] ;
      
      mMatchedTemplateDelimiterIndex = [self findTemplateDelimiterIndex:kTemplateDefinitionArray_gtl_5F_scanner] ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        [self advance] ;
        mTokenCode = -2 ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (mTokenCode == 0) && (mCurrentChar != '\0') && scanningOk) {
      scanningOk = [self internalParseLexicalTokenForLexicalColoring] ;
    }
    if ((mTokenCode > 0) && kEndOfScriptInTemplateArray_gtl_5F_scanner [mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
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



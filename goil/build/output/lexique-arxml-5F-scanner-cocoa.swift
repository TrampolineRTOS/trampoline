//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE arxml_scanner
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_arxml_scanner = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + arxml_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_arxml_scanner = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + arxml_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_arxml_scanner : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxml_scanner"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxml_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxml_scanner-nameStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxml_scanner-attributeValue"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxml_scanner-commentStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxml_scanner-textStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_arxml_scanner_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_arxml_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_arxml_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner-nameStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner-attributeValue"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner-textStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_arxml_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxml_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_arxml_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner-nameStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner-attributeValue"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner-textStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxml_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements
//----------------------------------------------------------------------------------------------------------------------

fileprivate let kTemplateReplacementArray_arxml_5F_scanner : [String] = [
  "&amp;",
  "&lt;",
  "&gt;",
  "&quot;",
  "&apos;",
  "&#"
]


//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters
//----------------------------------------------------------------------------------------------------------------------

fileprivate let kTemplateDefinitionArray_arxml_5F_scanner : [SWIFT_TemplateDelimiter] = [
  SWIFT_TemplateDelimiter (startString: "<", endString: nil, discardStartString: false)
]


//----------------------------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//----------------------------------------------------------------------------------------------------------------------

let arxml_scanner_1_ : UInt16 = 0
let arxml_scanner_1_comment : UInt16 = 1
let arxml_scanner_1_name : UInt16 = 2
let arxml_scanner_1_value : UInt16 = 3
let arxml_scanner_1__3C_ : UInt16 = 4
let arxml_scanner_1__3C__3F_ : UInt16 = 5
let arxml_scanner_1__3E_ : UInt16 = 6
let arxml_scanner_1__3F__3E_ : UInt16 = 7
let arxml_scanner_1__2F__3E_ : UInt16 = 8
let arxml_scanner_1__3C__2F_ : UInt16 = 9
let arxml_scanner_1__3D_ : UInt16 = 10
let arxml_scanner_2_ERROR : UInt16 = 11
let arxml_scanner_2_TEMPLATE : UInt16 = 12

//----------------------------------------------------------------------------------------------------------------------

func arxml_scanner_lexiqueIdentifier () -> String {
  return "arxml_scanner"
}

//----------------------------------------------------------------------------------------------------------------------

func arxml_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Delimiter", // 1
    "Name", // 2
    "Attribute value", // 3
    "Comment", // 4
    "Text", // 5
    "Lexical error", // 6
    "Template" // 7
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------

func arxml_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "arxml_scanner", // 0
    "arxml_scanner-delimitersStyle", // 1
    "arxml_scanner-nameStyle", // 2
    "arxml_scanner-attributeValue", // 3
    "arxml_scanner-commentStyle", // 4
    "arxml_scanner-textStyle", // 5
    "arxml_scanner.ERROR", // 6
    "arxml_scanner.TEMPLATE" // 7
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_arxml_scanner : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_tokenString : String = ""

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return arxml_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return true
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 10
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_arxml_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_arxml_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_arxml_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_arxml_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_arxml_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      4, // 1 : arxml_scanner_1_comment
      2, // 2 : arxml_scanner_1_name
      3, // 3 : arxml_scanner_1_value
      1, // 4 : arxml_scanner_1__3C_
      1, // 5 : arxml_scanner_1__3C__3F_
      1, // 6 : arxml_scanner_1__3E_
      1, // 7 : arxml_scanner_1__3F__3E_
      1, // 8 : arxml_scanner_1__2F__3E_
      1, // 9 : arxml_scanner_1__3C__2F_
      1, // 10 : arxml_scanner_1__3D_
      6, // 11 : arxml_scanner_2_ERROR
      7  // 12 : arxml_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : arxml_scanner_1_comment
      true, // 2 : arxml_scanner_1_name
      true, // 3 : arxml_scanner_1_value
      true, // 4 : arxml_scanner_1__3C_
      true, // 5 : arxml_scanner_1__3C__3F_
      true, // 6 : arxml_scanner_1__3E_
      true, // 7 : arxml_scanner_1__3F__3E_
      true, // 8 : arxml_scanner_1__2F__3E_
      true, // 9 : arxml_scanner_1__3C__2F_
      true, // 10 : arxml_scanner_1__3D_
      false, // 11 : arxml_scanner_2_ERROR
      false  // 12 : arxml_scanner_2_TEMPLATE
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
    return arxml_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return arxml_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_tokenString = ""
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputString ("<!--", advance: true)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputString ("&amp;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 38)
        }else if scanningOk && (self.testForInputString ("&lt;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 60)
        }else if scanningOk && (self.testForInputString ("&gt;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 62)
        }else if scanningOk && (self.testForInputString ("&quot;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 34)
        }else if scanningOk && (self.testForInputString ("&apos;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 39)
        }else if scanningOk && (self.testForInputFromChar (1, toChar:44) || self.testForInputFromChar (46, toChar:1114111)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        }else if scanningOk && (self.notTestForInputString ("-->", error: &scanningOk)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 45)
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = arxml_scanner_1_comment
    }else if scanningOk && self.testForInputString ("\?>", advance: true) {
      tokenCode = arxml_scanner_1__3F__3E_
    }else if scanningOk && self.testForInputString ("<\?", advance: true) {
      tokenCode = arxml_scanner_1__3C__3F_
    }else if scanningOk && self.testForInputString ("</", advance: true) {
      tokenCode = arxml_scanner_1__3C__2F_
    }else if scanningOk && self.testForInputString ("/>", advance: true) {
      tokenCode = arxml_scanner_1__2F__3E_
    }else if scanningOk && self.testForInputString (">", advance: true) {
      tokenCode = arxml_scanner_1__3E_
    }else if scanningOk && self.testForInputString ("=", advance: true) {
      tokenCode = arxml_scanner_1__3D_
    }else if scanningOk && self.testForInputString ("<", advance: true) {
      tokenCode = arxml_scanner_1__3C_
    }else if scanningOk && (self.testForCharWithFunction (isUnicodeLetter)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        if scanningOk && (self.testForCharWithFunction (isUnicodeLetter) || self.testForInputFromChar (48, toChar:57) || self.testForInputChar (45) || self.testForInputChar (58)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = arxml_scanner_1_name
    }else if scanningOk && (self.testForInputChar (34)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputString ("&amp;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 38)
        }else if scanningOk && (self.testForInputString ("&lt;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 60)
        }else if scanningOk && (self.testForInputString ("&gt;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 62)
        }else if scanningOk && (self.testForInputString ("&quot;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 34)
        }else if scanningOk && (self.testForInputString ("&apos;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 39)
        }else if scanningOk && (self.notTestForInputString ("\"", error: &scanningOk)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = arxml_scanner_1_value
    }else if scanningOk && (self.testForInputChar (39)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputString ("&amp;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 38)
        }else if scanningOk && (self.testForInputString ("&lt;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 60)
        }else if scanningOk && (self.testForInputString ("&gt;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 62)
        }else if scanningOk && (self.testForInputString ("&quot;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 34)
        }else if scanningOk && (self.testForInputString ("&apos;", advance: true)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, 39)
        }else if scanningOk && (self.notTestForInputString ("'", error: &scanningOk)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = arxml_scanner_1_value
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = arxml_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = arxml_scanner_2_TEMPLATE
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
} */

//----------------------------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//----------------------------------------------------------------------------------------------------------------------

/*
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

*/

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



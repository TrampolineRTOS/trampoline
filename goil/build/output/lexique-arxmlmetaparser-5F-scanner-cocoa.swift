//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE arxmlmetaparser_scanner
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_arxmlmetaparser_scanner = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + arxmlmetaparser_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_arxmlmetaparser_scanner = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + arxmlmetaparser_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_arxmlmetaparser_scanner : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner-nameStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner-attributeValue"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner-commentStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner-textStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_arxmlmetaparser_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_arxmlmetaparser_scanner_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_arxmlmetaparser_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_arxmlmetaparser_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner-nameStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner-attributeValue"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner-textStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_arxmlmetaparser_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_arxmlmetaparser_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_arxmlmetaparser_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner-delimitersStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner-nameStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner-attributeValue"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner-commentStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner-textStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner-keywordsStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_arxmlmetaparser_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements
//----------------------------------------------------------------------------------------------------------------------

fileprivate let kTemplateReplacementArray_arxmlmetaparser_5F_scanner : [String] = [
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

fileprivate let kTemplateDefinitionArray_arxmlmetaparser_5F_scanner : [SWIFT_TemplateDelimiter] = [
  SWIFT_TemplateDelimiter (startString: "<", endString: nil, discardStartString: false)
]


//----------------------------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//----------------------------------------------------------------------------------------------------------------------

let arxmlmetaparser_scanner_1_ : UInt16 = 0
let arxmlmetaparser_scanner_1_comment : UInt16 = 1
let arxmlmetaparser_scanner_1_xmlTag : UInt16 = 2
let arxmlmetaparser_scanner_1_xmlTagValue : UInt16 = 3
let arxmlmetaparser_scanner_1_identifier : UInt16 = 4
let arxmlmetaparser_scanner_1__3C_ : UInt16 = 5
let arxmlmetaparser_scanner_1__3C_xsd_3A_ : UInt16 = 6
let arxmlmetaparser_scanner_1__3C__2F_xsd_3A_ : UInt16 = 7
let arxmlmetaparser_scanner_1__3C__3F_xml : UInt16 = 8
let arxmlmetaparser_scanner_1__3E_ : UInt16 = 9
let arxmlmetaparser_scanner_1__3F__3E_ : UInt16 = 10
let arxmlmetaparser_scanner_1__2F__3E_ : UInt16 = 11
let arxmlmetaparser_scanner_1__3C__2F_ : UInt16 = 12
let arxmlmetaparser_scanner_1__3D_ : UInt16 = 13
let arxmlmetaparser_scanner_1_group : UInt16 = 14
let arxmlmetaparser_scanner_1_annotation : UInt16 = 15
let arxmlmetaparser_scanner_1_appinfo : UInt16 = 16
let arxmlmetaparser_scanner_1_attribute : UInt16 = 17
let arxmlmetaparser_scanner_1_attributeGroup : UInt16 = 18
let arxmlmetaparser_scanner_1_choice : UInt16 = 19
let arxmlmetaparser_scanner_1_complexType : UInt16 = 20
let arxmlmetaparser_scanner_1_documentation : UInt16 = 21
let arxmlmetaparser_scanner_1_element : UInt16 = 22
let arxmlmetaparser_scanner_1_enumeration : UInt16 = 23
let arxmlmetaparser_scanner_1_extension : UInt16 = 24
let arxmlmetaparser_scanner_1_import : UInt16 = 25
let arxmlmetaparser_scanner_1_maxLength : UInt16 = 26
let arxmlmetaparser_scanner_1_pattern : UInt16 = 27
let arxmlmetaparser_scanner_1_restriction : UInt16 = 28
let arxmlmetaparser_scanner_1_schema : UInt16 = 29
let arxmlmetaparser_scanner_1_sequence : UInt16 = 30
let arxmlmetaparser_scanner_1_simpleContent : UInt16 = 31
let arxmlmetaparser_scanner_1_simpleType : UInt16 = 32
let arxmlmetaparser_scanner_1_whiteSpace : UInt16 = 33
let arxmlmetaparser_scanner_1_abstract : UInt16 = 34
let arxmlmetaparser_scanner_1_attributeFormDefault : UInt16 = 35
let arxmlmetaparser_scanner_1_attributeRef : UInt16 = 36
let arxmlmetaparser_scanner_1_base : UInt16 = 37
let arxmlmetaparser_scanner_1_category : UInt16 = 38
let arxmlmetaparser_scanner_1_CATEGORY : UInt16 = 39
let arxmlmetaparser_scanner_1_color : UInt16 = 40
let arxmlmetaparser_scanner_1_customType : UInt16 = 41
let arxmlmetaparser_scanner_1_elementFormDefault : UInt16 = 42
let arxmlmetaparser_scanner_1_encoding : UInt16 = 43
let arxmlmetaparser_scanner_1_enforceMinMultiplicity : UInt16 = 44
let arxmlmetaparser_scanner_1_globalElement : UInt16 = 45
let arxmlmetaparser_scanner_1_id : UInt16 = 46
let arxmlmetaparser_scanner_1_latestBindingTime : UInt16 = 47
let arxmlmetaparser_scanner_1_maxOccurs : UInt16 = 48
let arxmlmetaparser_scanner_1_minOccurs : UInt16 = 49
let arxmlmetaparser_scanner_1_mixed : UInt16 = 50
let arxmlmetaparser_scanner_1_name : UInt16 = 51
let arxmlmetaparser_scanner_1_namePlural : UInt16 = 52
let arxmlmetaparser_scanner_1_namespace : UInt16 = 53
let arxmlmetaparser_scanner_1_noteType : UInt16 = 54
let arxmlmetaparser_scanner_1_nsPrefix : UInt16 = 55
let arxmlmetaparser_scanner_1_qualifiedName : UInt16 = 56
let arxmlmetaparser_scanner_1_recommendedPackage : UInt16 = 57
let arxmlmetaparser_scanner_1_ref : UInt16 = 58
let arxmlmetaparser_scanner_1_roleElement : UInt16 = 59
let arxmlmetaparser_scanner_1_roleWrapperElement : UInt16 = 60
let arxmlmetaparser_scanner_1_schemaLocation : UInt16 = 61
let arxmlmetaparser_scanner_1_sequenceOffset : UInt16 = 62
let arxmlmetaparser_scanner_1_source : UInt16 = 63
let arxmlmetaparser_scanner_1_Splitkey : UInt16 = 64
let arxmlmetaparser_scanner_1_Status : UInt16 = 65
let arxmlmetaparser_scanner_1_StatusRevisionBegin : UInt16 = 66
let arxmlmetaparser_scanner_1_targetNamespace : UInt16 = 67
let arxmlmetaparser_scanner_1_type : UInt16 = 68
let arxmlmetaparser_scanner_1_typeElement : UInt16 = 69
let arxmlmetaparser_scanner_1_typeWrapperElement : UInt16 = 70
let arxmlmetaparser_scanner_1_use : UInt16 = 71
let arxmlmetaparser_scanner_1_value : UInt16 = 72
let arxmlmetaparser_scanner_1_version : UInt16 = 73
let arxmlmetaparser_scanner_1_xmlns_3A_AR : UInt16 = 74
let arxmlmetaparser_scanner_1_xmlns_3A_xsd : UInt16 = 75
let arxmlmetaparser_scanner_1_TODO : UInt16 = 76
let arxmlmetaparser_scanner_2_ERROR : UInt16 = 77
let arxmlmetaparser_scanner_2_TEMPLATE : UInt16 = 78

//----------------------------------------------------------------------------------------------------------------------

func arxmlmetaparser_scanner_lexiqueIdentifier () -> String {
  return "arxmlmetaparser_scanner"
}

//----------------------------------------------------------------------------------------------------------------------

func arxmlmetaparser_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Delimiter", // 1
    "Name", // 2
    "Attribute value", // 3
    "Comment", // 4
    "Text", // 5
    "Keywords", // 6
    "Lexical error", // 7
    "Template" // 8
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------

func arxmlmetaparser_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "arxmlmetaparser_scanner", // 0
    "arxmlmetaparser_scanner-delimitersStyle", // 1
    "arxmlmetaparser_scanner-nameStyle", // 2
    "arxmlmetaparser_scanner-attributeValue", // 3
    "arxmlmetaparser_scanner-commentStyle", // 4
    "arxmlmetaparser_scanner-textStyle", // 5
    "arxmlmetaparser_scanner-keywordsStyle", // 6
    "arxmlmetaparser_scanner.ERROR", // 7
    "arxmlmetaparser_scanner.TEMPLATE" // 8
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_arxmlmetaparser_scanner : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_tokenString : String = ""

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return arxmlmetaparser_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return true
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 76
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_arxmlmetaparser_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_arxmlmetaparser_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_arxmlmetaparser_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_arxmlmetaparser_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_arxmlmetaparser_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      4, // 1 : arxmlmetaparser_scanner_1_comment
      2, // 2 : arxmlmetaparser_scanner_1_xmlTag
      3, // 3 : arxmlmetaparser_scanner_1_xmlTagValue
      5, // 4 : arxmlmetaparser_scanner_1_identifier
      1, // 5 : arxmlmetaparser_scanner_1__3C_
      1, // 6 : arxmlmetaparser_scanner_1__3C_xsd_3A_
      1, // 7 : arxmlmetaparser_scanner_1__3C__2F_xsd_3A_
      1, // 8 : arxmlmetaparser_scanner_1__3C__3F_xml
      1, // 9 : arxmlmetaparser_scanner_1__3E_
      1, // 10 : arxmlmetaparser_scanner_1__3F__3E_
      1, // 11 : arxmlmetaparser_scanner_1__2F__3E_
      1, // 12 : arxmlmetaparser_scanner_1__3C__2F_
      1, // 13 : arxmlmetaparser_scanner_1__3D_
      6, // 14 : arxmlmetaparser_scanner_1_group
      6, // 15 : arxmlmetaparser_scanner_1_annotation
      6, // 16 : arxmlmetaparser_scanner_1_appinfo
      6, // 17 : arxmlmetaparser_scanner_1_attribute
      6, // 18 : arxmlmetaparser_scanner_1_attributeGroup
      6, // 19 : arxmlmetaparser_scanner_1_choice
      6, // 20 : arxmlmetaparser_scanner_1_complexType
      6, // 21 : arxmlmetaparser_scanner_1_documentation
      6, // 22 : arxmlmetaparser_scanner_1_element
      6, // 23 : arxmlmetaparser_scanner_1_enumeration
      6, // 24 : arxmlmetaparser_scanner_1_extension
      6, // 25 : arxmlmetaparser_scanner_1_import
      6, // 26 : arxmlmetaparser_scanner_1_maxLength
      6, // 27 : arxmlmetaparser_scanner_1_pattern
      6, // 28 : arxmlmetaparser_scanner_1_restriction
      6, // 29 : arxmlmetaparser_scanner_1_schema
      6, // 30 : arxmlmetaparser_scanner_1_sequence
      6, // 31 : arxmlmetaparser_scanner_1_simpleContent
      6, // 32 : arxmlmetaparser_scanner_1_simpleType
      6, // 33 : arxmlmetaparser_scanner_1_whiteSpace
      6, // 34 : arxmlmetaparser_scanner_1_abstract
      6, // 35 : arxmlmetaparser_scanner_1_attributeFormDefault
      6, // 36 : arxmlmetaparser_scanner_1_attributeRef
      6, // 37 : arxmlmetaparser_scanner_1_base
      6, // 38 : arxmlmetaparser_scanner_1_category
      6, // 39 : arxmlmetaparser_scanner_1_CATEGORY
      6, // 40 : arxmlmetaparser_scanner_1_color
      6, // 41 : arxmlmetaparser_scanner_1_customType
      6, // 42 : arxmlmetaparser_scanner_1_elementFormDefault
      6, // 43 : arxmlmetaparser_scanner_1_encoding
      6, // 44 : arxmlmetaparser_scanner_1_enforceMinMultiplicity
      6, // 45 : arxmlmetaparser_scanner_1_globalElement
      6, // 46 : arxmlmetaparser_scanner_1_id
      6, // 47 : arxmlmetaparser_scanner_1_latestBindingTime
      6, // 48 : arxmlmetaparser_scanner_1_maxOccurs
      6, // 49 : arxmlmetaparser_scanner_1_minOccurs
      6, // 50 : arxmlmetaparser_scanner_1_mixed
      6, // 51 : arxmlmetaparser_scanner_1_name
      6, // 52 : arxmlmetaparser_scanner_1_namePlural
      6, // 53 : arxmlmetaparser_scanner_1_namespace
      6, // 54 : arxmlmetaparser_scanner_1_noteType
      6, // 55 : arxmlmetaparser_scanner_1_nsPrefix
      6, // 56 : arxmlmetaparser_scanner_1_qualifiedName
      6, // 57 : arxmlmetaparser_scanner_1_recommendedPackage
      6, // 58 : arxmlmetaparser_scanner_1_ref
      6, // 59 : arxmlmetaparser_scanner_1_roleElement
      6, // 60 : arxmlmetaparser_scanner_1_roleWrapperElement
      6, // 61 : arxmlmetaparser_scanner_1_schemaLocation
      6, // 62 : arxmlmetaparser_scanner_1_sequenceOffset
      6, // 63 : arxmlmetaparser_scanner_1_source
      6, // 64 : arxmlmetaparser_scanner_1_Splitkey
      6, // 65 : arxmlmetaparser_scanner_1_Status
      6, // 66 : arxmlmetaparser_scanner_1_StatusRevisionBegin
      6, // 67 : arxmlmetaparser_scanner_1_targetNamespace
      6, // 68 : arxmlmetaparser_scanner_1_type
      6, // 69 : arxmlmetaparser_scanner_1_typeElement
      6, // 70 : arxmlmetaparser_scanner_1_typeWrapperElement
      6, // 71 : arxmlmetaparser_scanner_1_use
      6, // 72 : arxmlmetaparser_scanner_1_value
      6, // 73 : arxmlmetaparser_scanner_1_version
      6, // 74 : arxmlmetaparser_scanner_1_xmlns_3A_AR
      6, // 75 : arxmlmetaparser_scanner_1_xmlns_3A_xsd
      6, // 76 : arxmlmetaparser_scanner_1_TODO
      7, // 77 : arxmlmetaparser_scanner_2_ERROR
      8  // 78 : arxmlmetaparser_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : arxmlmetaparser_scanner_1_comment
      true, // 2 : arxmlmetaparser_scanner_1_xmlTag
      true, // 3 : arxmlmetaparser_scanner_1_xmlTagValue
      true, // 4 : arxmlmetaparser_scanner_1_identifier
      true, // 5 : arxmlmetaparser_scanner_1__3C_
      true, // 6 : arxmlmetaparser_scanner_1__3C_xsd_3A_
      true, // 7 : arxmlmetaparser_scanner_1__3C__2F_xsd_3A_
      true, // 8 : arxmlmetaparser_scanner_1__3C__3F_xml
      true, // 9 : arxmlmetaparser_scanner_1__3E_
      true, // 10 : arxmlmetaparser_scanner_1__3F__3E_
      true, // 11 : arxmlmetaparser_scanner_1__2F__3E_
      true, // 12 : arxmlmetaparser_scanner_1__3C__2F_
      true, // 13 : arxmlmetaparser_scanner_1__3D_
      true, // 14 : arxmlmetaparser_scanner_1_group
      true, // 15 : arxmlmetaparser_scanner_1_annotation
      true, // 16 : arxmlmetaparser_scanner_1_appinfo
      true, // 17 : arxmlmetaparser_scanner_1_attribute
      true, // 18 : arxmlmetaparser_scanner_1_attributeGroup
      true, // 19 : arxmlmetaparser_scanner_1_choice
      true, // 20 : arxmlmetaparser_scanner_1_complexType
      true, // 21 : arxmlmetaparser_scanner_1_documentation
      true, // 22 : arxmlmetaparser_scanner_1_element
      true, // 23 : arxmlmetaparser_scanner_1_enumeration
      true, // 24 : arxmlmetaparser_scanner_1_extension
      true, // 25 : arxmlmetaparser_scanner_1_import
      true, // 26 : arxmlmetaparser_scanner_1_maxLength
      true, // 27 : arxmlmetaparser_scanner_1_pattern
      true, // 28 : arxmlmetaparser_scanner_1_restriction
      true, // 29 : arxmlmetaparser_scanner_1_schema
      true, // 30 : arxmlmetaparser_scanner_1_sequence
      true, // 31 : arxmlmetaparser_scanner_1_simpleContent
      true, // 32 : arxmlmetaparser_scanner_1_simpleType
      true, // 33 : arxmlmetaparser_scanner_1_whiteSpace
      true, // 34 : arxmlmetaparser_scanner_1_abstract
      true, // 35 : arxmlmetaparser_scanner_1_attributeFormDefault
      true, // 36 : arxmlmetaparser_scanner_1_attributeRef
      true, // 37 : arxmlmetaparser_scanner_1_base
      true, // 38 : arxmlmetaparser_scanner_1_category
      true, // 39 : arxmlmetaparser_scanner_1_CATEGORY
      true, // 40 : arxmlmetaparser_scanner_1_color
      true, // 41 : arxmlmetaparser_scanner_1_customType
      true, // 42 : arxmlmetaparser_scanner_1_elementFormDefault
      true, // 43 : arxmlmetaparser_scanner_1_encoding
      true, // 44 : arxmlmetaparser_scanner_1_enforceMinMultiplicity
      true, // 45 : arxmlmetaparser_scanner_1_globalElement
      true, // 46 : arxmlmetaparser_scanner_1_id
      true, // 47 : arxmlmetaparser_scanner_1_latestBindingTime
      true, // 48 : arxmlmetaparser_scanner_1_maxOccurs
      true, // 49 : arxmlmetaparser_scanner_1_minOccurs
      true, // 50 : arxmlmetaparser_scanner_1_mixed
      true, // 51 : arxmlmetaparser_scanner_1_name
      true, // 52 : arxmlmetaparser_scanner_1_namePlural
      true, // 53 : arxmlmetaparser_scanner_1_namespace
      true, // 54 : arxmlmetaparser_scanner_1_noteType
      true, // 55 : arxmlmetaparser_scanner_1_nsPrefix
      true, // 56 : arxmlmetaparser_scanner_1_qualifiedName
      true, // 57 : arxmlmetaparser_scanner_1_recommendedPackage
      true, // 58 : arxmlmetaparser_scanner_1_ref
      true, // 59 : arxmlmetaparser_scanner_1_roleElement
      true, // 60 : arxmlmetaparser_scanner_1_roleWrapperElement
      true, // 61 : arxmlmetaparser_scanner_1_schemaLocation
      true, // 62 : arxmlmetaparser_scanner_1_sequenceOffset
      true, // 63 : arxmlmetaparser_scanner_1_source
      true, // 64 : arxmlmetaparser_scanner_1_Splitkey
      true, // 65 : arxmlmetaparser_scanner_1_Status
      true, // 66 : arxmlmetaparser_scanner_1_StatusRevisionBegin
      true, // 67 : arxmlmetaparser_scanner_1_targetNamespace
      true, // 68 : arxmlmetaparser_scanner_1_type
      true, // 69 : arxmlmetaparser_scanner_1_typeElement
      true, // 70 : arxmlmetaparser_scanner_1_typeWrapperElement
      true, // 71 : arxmlmetaparser_scanner_1_use
      true, // 72 : arxmlmetaparser_scanner_1_value
      true, // 73 : arxmlmetaparser_scanner_1_version
      true, // 74 : arxmlmetaparser_scanner_1_xmlns_3A_AR
      true, // 75 : arxmlmetaparser_scanner_1_xmlns_3A_xsd
      true, // 76 : arxmlmetaparser_scanner_1_TODO
      false, // 77 : arxmlmetaparser_scanner_2_ERROR
      false  // 78 : arxmlmetaparser_scanner_2_TEMPLATE
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
    return 6
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return arxmlmetaparser_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return arxmlmetaparser_scanner_styleIdentifierFor (styleIndex: inIndex)
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
      tokenCode = arxmlmetaparser_scanner_1_comment
    }else if scanningOk && self.testForInputString ("</xsd:", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3C__2F_xsd_3A_
    }else if scanningOk && self.testForInputString ("<xsd:", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3C_xsd_3A_
    }else if scanningOk && self.testForInputString ("<\?xml", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3C__3F_xml
    }else if scanningOk && self.testForInputString ("\?>", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3F__3E_
    }else if scanningOk && self.testForInputString ("</", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3C__2F_
    }else if scanningOk && self.testForInputString ("/>", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__2F__3E_
    }else if scanningOk && self.testForInputString (">", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3E_
    }else if scanningOk && self.testForInputString ("=", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3D_
    }else if scanningOk && self.testForInputString ("<", advance: true) {
      tokenCode = arxmlmetaparser_scanner_1__3C_
    }else if scanningOk && (self.testForCharWithFunction (isUnicodeLetter)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        if scanningOk && (self.testForCharWithFunction (isUnicodeLetter) || self.testForInputFromChar (48, toChar:57) || self.testForInputChar (45) || self.testForInputChar (58)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_arxmlmetaparser_5F_scanner_keyWordList (mLexicalAttribute_tokenString) ;
      }
      if tokenCode == 0 {
        tokenCode = arxmlmetaparser_scanner_1_xmlTag ;
      }
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
      tokenCode = arxmlmetaparser_scanner_1_xmlTagValue
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
      tokenCode = arxmlmetaparser_scanner_1_xmlTagValue
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if scanningOk && (self.testForInputFromChar (1, toChar:59) || self.testForInputFromChar (61, toChar:1114111)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_tokenString, self.previousChar)
        if scanningOk && (self.testForInputFromChar (1, toChar:59) || self.testForInputFromChar (61, toChar:1114111)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_arxmlmetaparser_5F_scanner_keyWordList (mLexicalAttribute_tokenString) ;
      }
      if tokenCode == 0 {
        tokenCode = arxmlmetaparser_scanner_1_identifier ;
      }
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = arxmlmetaparser_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = arxmlmetaparser_scanner_2_TEMPLATE
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
  if (nil == kTemplateDefinitionArray_arxmlmetaparser_5F_scanner) {
    kTemplateDefinitionArray_arxmlmetaparser_5F_scanner = [NSArray arrayWithObjects:
      [[OC_GGS_TemplateDelimiter alloc] initWithStartString:@"<" endString:nil discardStartString:NO],
      nil
    ] ;
  }
  if (nil == kTemplateReplacementArray_arxmlmetaparser_5F_scanner) {

    kTemplateReplacementArray_arxmlmetaparser_5F_scanner = [NSArray arrayWithObjects:
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
static const BOOL kEndOfScriptInTemplateArray_arxmlmetaparser_5F_scanner [76] = {
  YES /* comment */,
  NO /* xmlTag */,
  NO /* xmlTagValue */,
  NO /* identifier */,
  NO /* < */,
  NO /* <xsd: */,
  NO /* </xsd: */,
  NO /* <?xml */,
  YES /* > */,
  YES /* ?> */,
  YES /* /> */,
  NO /* </ */,
  NO /* = */,
  NO /* group */,
  NO /* annotation */,
  NO /* appinfo */,
  NO /* attribute */,
  NO /* attributeGroup */,
  NO /* choice */,
  NO /* complexType */,
  NO /* documentation */,
  NO /* element */,
  NO /* enumeration */,
  NO /* extension */,
  NO /* import */,
  NO /* maxLength */,
  NO /* pattern */,
  NO /* restriction */,
  NO /* schema */,
  NO /* sequence */,
  NO /* simpleContent */,
  NO /* simpleType */,
  NO /* whiteSpace */,
  NO /* abstract */,
  NO /* attributeFormDefault */,
  NO /* attributeRef */,
  NO /* base */,
  NO /* category */,
  NO /* CATEGORY */,
  NO /* color */,
  NO /* customType */,
  NO /* elementFormDefault */,
  NO /* encoding */,
  NO /* enforceMinMultiplicity */,
  NO /* globalElement */,
  NO /* id */,
  NO /* latestBindingTime */,
  NO /* maxOccurs */,
  NO /* minOccurs */,
  NO /* mixed */,
  NO /* name */,
  NO /* namePlural */,
  NO /* namespace */,
  NO /* noteType */,
  NO /* nsPrefix */,
  NO /* qualifiedName */,
  NO /* recommendedPackage */,
  NO /* ref */,
  NO /* roleElement */,
  NO /* roleWrapperElement */,
  NO /* schemaLocation */,
  NO /* sequenceOffset */,
  NO /* source */,
  NO /* Splitkey */,
  NO /* Status */,
  NO /* StatusRevisionBegin */,
  NO /* targetNamespace */,
  NO /* type */,
  NO /* typeElement */,
  NO /* typeWrapperElement */,
  NO /* use */,
  NO /* value */,
  NO /* version */,
  NO /* xmlns:AR */,
  NO /* xmlns:xsd */,
  NO /* TODO */
} ;

*/


//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'keyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_arxmlmetaparser_5F_scanner_keyWordList (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "id" : arxmlmetaparser_scanner_1_id,
    "ref" : arxmlmetaparser_scanner_1_ref,
    "use" : arxmlmetaparser_scanner_1_use,
    "TODO" : arxmlmetaparser_scanner_1_TODO,
    "base" : arxmlmetaparser_scanner_1_base,
    "name" : arxmlmetaparser_scanner_1_name,
    "type" : arxmlmetaparser_scanner_1_type,
    "color" : arxmlmetaparser_scanner_1_color,
    "group" : arxmlmetaparser_scanner_1_group,
    "mixed" : arxmlmetaparser_scanner_1_mixed,
    "value" : arxmlmetaparser_scanner_1_value,
    "Status" : arxmlmetaparser_scanner_1_Status,
    "choice" : arxmlmetaparser_scanner_1_choice,
    "import" : arxmlmetaparser_scanner_1_import,
    "schema" : arxmlmetaparser_scanner_1_schema,
    "source" : arxmlmetaparser_scanner_1_source,
    "appinfo" : arxmlmetaparser_scanner_1_appinfo,
    "element" : arxmlmetaparser_scanner_1_element,
    "pattern" : arxmlmetaparser_scanner_1_pattern,
    "version" : arxmlmetaparser_scanner_1_version,
    "CATEGORY" : arxmlmetaparser_scanner_1_CATEGORY,
    "Splitkey" : arxmlmetaparser_scanner_1_Splitkey,
    "abstract" : arxmlmetaparser_scanner_1_abstract,
    "category" : arxmlmetaparser_scanner_1_category,
    "encoding" : arxmlmetaparser_scanner_1_encoding,
    "noteType" : arxmlmetaparser_scanner_1_noteType,
    "nsPrefix" : arxmlmetaparser_scanner_1_nsPrefix,
    "sequence" : arxmlmetaparser_scanner_1_sequence,
    "xmlns:AR" : arxmlmetaparser_scanner_1_xmlns_3A_AR,
    "attribute" : arxmlmetaparser_scanner_1_attribute,
    "extension" : arxmlmetaparser_scanner_1_extension,
    "maxLength" : arxmlmetaparser_scanner_1_maxLength,
    "maxOccurs" : arxmlmetaparser_scanner_1_maxOccurs,
    "minOccurs" : arxmlmetaparser_scanner_1_minOccurs,
    "namespace" : arxmlmetaparser_scanner_1_namespace,
    "xmlns:xsd" : arxmlmetaparser_scanner_1_xmlns_3A_xsd,
    "annotation" : arxmlmetaparser_scanner_1_annotation,
    "customType" : arxmlmetaparser_scanner_1_customType,
    "namePlural" : arxmlmetaparser_scanner_1_namePlural,
    "simpleType" : arxmlmetaparser_scanner_1_simpleType,
    "whiteSpace" : arxmlmetaparser_scanner_1_whiteSpace,
    "complexType" : arxmlmetaparser_scanner_1_complexType,
    "enumeration" : arxmlmetaparser_scanner_1_enumeration,
    "restriction" : arxmlmetaparser_scanner_1_restriction,
    "roleElement" : arxmlmetaparser_scanner_1_roleElement,
    "typeElement" : arxmlmetaparser_scanner_1_typeElement,
    "attributeRef" : arxmlmetaparser_scanner_1_attributeRef,
    "documentation" : arxmlmetaparser_scanner_1_documentation,
    "globalElement" : arxmlmetaparser_scanner_1_globalElement,
    "qualifiedName" : arxmlmetaparser_scanner_1_qualifiedName,
    "simpleContent" : arxmlmetaparser_scanner_1_simpleContent,
    "attributeGroup" : arxmlmetaparser_scanner_1_attributeGroup,
    "schemaLocation" : arxmlmetaparser_scanner_1_schemaLocation,
    "sequenceOffset" : arxmlmetaparser_scanner_1_sequenceOffset,
    "targetNamespace" : arxmlmetaparser_scanner_1_targetNamespace,
    "latestBindingTime" : arxmlmetaparser_scanner_1_latestBindingTime,
    "elementFormDefault" : arxmlmetaparser_scanner_1_elementFormDefault,
    "recommendedPackage" : arxmlmetaparser_scanner_1_recommendedPackage,
    "roleWrapperElement" : arxmlmetaparser_scanner_1_roleWrapperElement,
    "typeWrapperElement" : arxmlmetaparser_scanner_1_typeWrapperElement,
    "StatusRevisionBegin" : arxmlmetaparser_scanner_1_StatusRevisionBegin,
    "attributeFormDefault" : arxmlmetaparser_scanner_1_attributeFormDefault,
    "enforceMinMultiplicity" : arxmlmetaparser_scanner_1_enforceMinMultiplicity
  ]
  return dictionary [inSearchedString, default: arxmlmetaparser_scanner_1_]
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
    if ((mMatchedTemplateDelimiterIndex >= 0) && ([[kTemplateDefinitionArray_arxmlmetaparser_5F_scanner objectAtIndex:(NSUInteger) mMatchedTemplateDelimiterIndex] startString].length > 0)) {
      const BOOL foundEndDelimitor = [self testForInputString:[[kTemplateDefinitionArray_arxmlmetaparser_5F_scanner objectAtIndex:(NSUInteger) mMatchedTemplateDelimiterIndex] endString] advance:YES] ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (mCurrentChar != '\0')) {
      
      [self searchForReplacementPattern:kTemplateReplacementArray_arxmlmetaparser_5F_scanner] ;
      
      mMatchedTemplateDelimiterIndex = [self findTemplateDelimiterIndex:kTemplateDefinitionArray_arxmlmetaparser_5F_scanner] ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        [self advance] ;
        mTokenCode = -2 ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (mTokenCode == 0) && (mCurrentChar != '\0') && scanningOk) {
      scanningOk = [self internalParseLexicalTokenForLexicalColoring] ;
    }
    if ((mTokenCode > 0) && kEndOfScriptInTemplateArray_arxmlmetaparser_5F_scanner [mTokenCode - 1]) {
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



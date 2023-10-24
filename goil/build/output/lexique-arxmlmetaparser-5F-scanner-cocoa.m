//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-arxmlmetaparser-5F-scanner-cocoa.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_Lexique_arxmlmetaparser_scanner

//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Replacements
//
//----------------------------------------------------------------------------------------------------------------------

static NSArray * kTemplateReplacementArray_arxmlmetaparser_5F_scanner ; // Of NSString 


//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Delimiters
//
//----------------------------------------------------------------------------------------------------------------------

static NSArray * kTemplateDefinitionArray_arxmlmetaparser_5F_scanner ;

//----------------------------------------------------------------------------------------------------------------------

- (instancetype) init {
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


//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'keyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_arxmlmetaparser_5F_scanner_keyWordList [63] = {
  {"id", arxmlmetaparser_scanner_1_id},
  {"ref", arxmlmetaparser_scanner_1_ref},
  {"use", arxmlmetaparser_scanner_1_use},
  {"TODO", arxmlmetaparser_scanner_1_TODO},
  {"base", arxmlmetaparser_scanner_1_base},
  {"name", arxmlmetaparser_scanner_1_name},
  {"type", arxmlmetaparser_scanner_1_type},
  {"color", arxmlmetaparser_scanner_1_color},
  {"group", arxmlmetaparser_scanner_1_group},
  {"mixed", arxmlmetaparser_scanner_1_mixed},
  {"value", arxmlmetaparser_scanner_1_value},
  {"Status", arxmlmetaparser_scanner_1_Status},
  {"choice", arxmlmetaparser_scanner_1_choice},
  {"import", arxmlmetaparser_scanner_1_import},
  {"schema", arxmlmetaparser_scanner_1_schema},
  {"source", arxmlmetaparser_scanner_1_source},
  {"appinfo", arxmlmetaparser_scanner_1_appinfo},
  {"element", arxmlmetaparser_scanner_1_element},
  {"pattern", arxmlmetaparser_scanner_1_pattern},
  {"version", arxmlmetaparser_scanner_1_version},
  {"CATEGORY", arxmlmetaparser_scanner_1_CATEGORY},
  {"Splitkey", arxmlmetaparser_scanner_1_Splitkey},
  {"abstract", arxmlmetaparser_scanner_1_abstract},
  {"category", arxmlmetaparser_scanner_1_category},
  {"encoding", arxmlmetaparser_scanner_1_encoding},
  {"noteType", arxmlmetaparser_scanner_1_noteType},
  {"nsPrefix", arxmlmetaparser_scanner_1_nsPrefix},
  {"sequence", arxmlmetaparser_scanner_1_sequence},
  {"xmlns:AR", arxmlmetaparser_scanner_1_xmlns_3A_AR},
  {"attribute", arxmlmetaparser_scanner_1_attribute},
  {"extension", arxmlmetaparser_scanner_1_extension},
  {"maxLength", arxmlmetaparser_scanner_1_maxLength},
  {"maxOccurs", arxmlmetaparser_scanner_1_maxOccurs},
  {"minOccurs", arxmlmetaparser_scanner_1_minOccurs},
  {"namespace", arxmlmetaparser_scanner_1_namespace},
  {"xmlns:xsd", arxmlmetaparser_scanner_1_xmlns_3A_xsd},
  {"annotation", arxmlmetaparser_scanner_1_annotation},
  {"customType", arxmlmetaparser_scanner_1_customType},
  {"namePlural", arxmlmetaparser_scanner_1_namePlural},
  {"simpleType", arxmlmetaparser_scanner_1_simpleType},
  {"whiteSpace", arxmlmetaparser_scanner_1_whiteSpace},
  {"complexType", arxmlmetaparser_scanner_1_complexType},
  {"enumeration", arxmlmetaparser_scanner_1_enumeration},
  {"restriction", arxmlmetaparser_scanner_1_restriction},
  {"roleElement", arxmlmetaparser_scanner_1_roleElement},
  {"typeElement", arxmlmetaparser_scanner_1_typeElement},
  {"attributeRef", arxmlmetaparser_scanner_1_attributeRef},
  {"documentation", arxmlmetaparser_scanner_1_documentation},
  {"globalElement", arxmlmetaparser_scanner_1_globalElement},
  {"qualifiedName", arxmlmetaparser_scanner_1_qualifiedName},
  {"simpleContent", arxmlmetaparser_scanner_1_simpleContent},
  {"attributeGroup", arxmlmetaparser_scanner_1_attributeGroup},
  {"schemaLocation", arxmlmetaparser_scanner_1_schemaLocation},
  {"sequenceOffset", arxmlmetaparser_scanner_1_sequenceOffset},
  {"targetNamespace", arxmlmetaparser_scanner_1_targetNamespace},
  {"latestBindingTime", arxmlmetaparser_scanner_1_latestBindingTime},
  {"elementFormDefault", arxmlmetaparser_scanner_1_elementFormDefault},
  {"recommendedPackage", arxmlmetaparser_scanner_1_recommendedPackage},
  {"roleWrapperElement", arxmlmetaparser_scanner_1_roleWrapperElement},
  {"typeWrapperElement", arxmlmetaparser_scanner_1_typeWrapperElement},
  {"StatusRevisionBegin", arxmlmetaparser_scanner_1_StatusRevisionBegin},
  {"attributeFormDefault", arxmlmetaparser_scanner_1_attributeFormDefault},
  {"enforceMinMultiplicity", arxmlmetaparser_scanner_1_enforceMinMultiplicity}
} ;

static NSInteger search_into_arxmlmetaparser_5F_scanner_keyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_arxmlmetaparser_5F_scanner_keyWordList, 63) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//               I N T E R N A L    P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) internalParseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  [mLexicalAttribute_tokenString setString:@""] ;
  mTokenStartLocation = mCurrentLocation ;
  if (scanningOk && ([self testForInputString:@"<!--" advance:YES])) {
    BOOL loop1350 = YES ;
    do {
      if (scanningOk && ([self testForInputString:@"&amp;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 38) ;
      }else if (scanningOk && ([self testForInputString:@"&lt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 60) ;
      }else if (scanningOk && ([self testForInputString:@"&gt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 62) ;
      }else if (scanningOk && ([self testForInputString:@"&quot;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 34) ;
      }else if (scanningOk && ([self testForInputString:@"&apos;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 39) ;
      }else if (scanningOk && ([self testForInputFromChar:1 toChar:44] || [self testForInputFromChar:46 toChar:1114111])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else if (scanningOk && ([self notTestForInputString:@"-->" error:& scanningOk])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 45) ;
      }else{
        loop1350 = NO ;
      }
    }while (loop1350 && scanningOk) ;
    mTokenCode = arxmlmetaparser_scanner_1_comment ;
  }else if (scanningOk && [self testForInputString:@"</xsd:" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3C__2F_xsd_3A_ ;
  }else if (scanningOk && [self testForInputString:@"<xsd:" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3C_xsd_3A_ ;
  }else if (scanningOk && [self testForInputString:@"<\?xml" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3C__3F_xml ;
  }else if (scanningOk && [self testForInputString:@"\?>" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3F__3E_ ;
  }else if (scanningOk && [self testForInputString:@"</" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3C__2F_ ;
  }else if (scanningOk && [self testForInputString:@"/>" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__2F__3E_ ;
  }else if (scanningOk && [self testForInputString:@">" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3E_ ;
  }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3D_ ;
  }else if (scanningOk && [self testForInputString:@"<" advance:YES]) {
    mTokenCode = arxmlmetaparser_scanner_1__3C_ ;
  }else if (scanningOk && ([self testForCharWithFunction: isUnicodeLetter])) {
    BOOL loop2417 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      if (scanningOk && ([self testForCharWithFunction: isUnicodeLetter] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:45] || [self testForInputChar:58])) {
      }else{
        loop2417 = NO ;
      }
    }while (loop2417 && scanningOk) ;
    if (mTokenCode == 0) {
      mTokenCode = search_into_arxmlmetaparser_5F_scanner_keyWordList (mLexicalAttribute_tokenString) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = arxmlmetaparser_scanner_1_xmlTag ;
    }
  }else if (scanningOk && ([self testForInputChar:34])) {
    BOOL loop2873 = YES ;
    do {
      if (scanningOk && ([self testForInputString:@"&amp;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 38) ;
      }else if (scanningOk && ([self testForInputString:@"&lt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 60) ;
      }else if (scanningOk && ([self testForInputString:@"&gt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 62) ;
      }else if (scanningOk && ([self testForInputString:@"&quot;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 34) ;
      }else if (scanningOk && ([self testForInputString:@"&apos;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 39) ;
      }else if (scanningOk && ([self notTestForInputString:@"\"" error:& scanningOk])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else{
        loop2873 = NO ;
      }
    }while (loop2873 && scanningOk) ;
    mTokenCode = arxmlmetaparser_scanner_1_xmlTagValue ;
  }else if (scanningOk && ([self testForInputChar:39])) {
    BOOL loop3368 = YES ;
    do {
      if (scanningOk && ([self testForInputString:@"&amp;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 38) ;
      }else if (scanningOk && ([self testForInputString:@"&lt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 60) ;
      }else if (scanningOk && ([self testForInputString:@"&gt;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 62) ;
      }else if (scanningOk && ([self testForInputString:@"&quot;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 34) ;
      }else if (scanningOk && ([self testForInputString:@"&apos;" advance:YES])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, 39) ;
      }else if (scanningOk && ([self notTestForInputString:@"'" error:& scanningOk])) {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      }else{
        loop3368 = NO ;
      }
    }while (loop3368 && scanningOk) ;
    mTokenCode = arxmlmetaparser_scanner_1_xmlTagValue ;
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
  }else if (scanningOk && ([self testForInputFromChar:1 toChar:59] || [self testForInputFromChar:61 toChar:1114111])) {
    BOOL loop5362 = YES ;
    do {
      scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
      if (scanningOk && ([self testForInputFromChar:1 toChar:59] || [self testForInputFromChar:61 toChar:1114111])) {
      }else{
        loop5362 = NO ;
      }
    }while (loop5362 && scanningOk) ;
    if (mTokenCode == 0) {
      mTokenCode = search_into_arxmlmetaparser_5F_scanner_keyWordList (mLexicalAttribute_tokenString) ;
    }
    if (mTokenCode == 0) {
      mTokenCode = arxmlmetaparser_scanner_1_identifier ;
    }
  }else   if ([self testForInputChar:'\0']) { // End of source text ?
    mTokenCode = arxmlmetaparser_scanner_1_ ; // Empty string code
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

//----------------------------------------------------------------------------------------------------------------------
//
//                   T E R M I N A L    C O U N T
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) terminalVocabularyCount {
  return 76 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                     S T Y L E   C O U N T
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleCount {
  return 7 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                I S    T E M P L A T E    L E X I Q U E
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) isTemplateLexique {
  return YES ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   S T Y L E   I N D E X    F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [77] = {0,
    4 /* arxmlmetaparser_scanner_1_comment */,
    2 /* arxmlmetaparser_scanner_1_xmlTag */,
    3 /* arxmlmetaparser_scanner_1_xmlTagValue */,
    5 /* arxmlmetaparser_scanner_1_identifier */,
    1 /* arxmlmetaparser_scanner_1__3C_ */,
    1 /* arxmlmetaparser_scanner_1__3C_xsd_3A_ */,
    1 /* arxmlmetaparser_scanner_1__3C__2F_xsd_3A_ */,
    1 /* arxmlmetaparser_scanner_1__3C__3F_xml */,
    1 /* arxmlmetaparser_scanner_1__3E_ */,
    1 /* arxmlmetaparser_scanner_1__3F__3E_ */,
    1 /* arxmlmetaparser_scanner_1__2F__3E_ */,
    1 /* arxmlmetaparser_scanner_1__3C__2F_ */,
    1 /* arxmlmetaparser_scanner_1__3D_ */,
    6 /* arxmlmetaparser_scanner_1_group */,
    6 /* arxmlmetaparser_scanner_1_annotation */,
    6 /* arxmlmetaparser_scanner_1_appinfo */,
    6 /* arxmlmetaparser_scanner_1_attribute */,
    6 /* arxmlmetaparser_scanner_1_attributeGroup */,
    6 /* arxmlmetaparser_scanner_1_choice */,
    6 /* arxmlmetaparser_scanner_1_complexType */,
    6 /* arxmlmetaparser_scanner_1_documentation */,
    6 /* arxmlmetaparser_scanner_1_element */,
    6 /* arxmlmetaparser_scanner_1_enumeration */,
    6 /* arxmlmetaparser_scanner_1_extension */,
    6 /* arxmlmetaparser_scanner_1_import */,
    6 /* arxmlmetaparser_scanner_1_maxLength */,
    6 /* arxmlmetaparser_scanner_1_pattern */,
    6 /* arxmlmetaparser_scanner_1_restriction */,
    6 /* arxmlmetaparser_scanner_1_schema */,
    6 /* arxmlmetaparser_scanner_1_sequence */,
    6 /* arxmlmetaparser_scanner_1_simpleContent */,
    6 /* arxmlmetaparser_scanner_1_simpleType */,
    6 /* arxmlmetaparser_scanner_1_whiteSpace */,
    6 /* arxmlmetaparser_scanner_1_abstract */,
    6 /* arxmlmetaparser_scanner_1_attributeFormDefault */,
    6 /* arxmlmetaparser_scanner_1_attributeRef */,
    6 /* arxmlmetaparser_scanner_1_base */,
    6 /* arxmlmetaparser_scanner_1_category */,
    6 /* arxmlmetaparser_scanner_1_CATEGORY */,
    6 /* arxmlmetaparser_scanner_1_color */,
    6 /* arxmlmetaparser_scanner_1_customType */,
    6 /* arxmlmetaparser_scanner_1_elementFormDefault */,
    6 /* arxmlmetaparser_scanner_1_encoding */,
    6 /* arxmlmetaparser_scanner_1_enforceMinMultiplicity */,
    6 /* arxmlmetaparser_scanner_1_globalElement */,
    6 /* arxmlmetaparser_scanner_1_id */,
    6 /* arxmlmetaparser_scanner_1_latestBindingTime */,
    6 /* arxmlmetaparser_scanner_1_maxOccurs */,
    6 /* arxmlmetaparser_scanner_1_minOccurs */,
    6 /* arxmlmetaparser_scanner_1_mixed */,
    6 /* arxmlmetaparser_scanner_1_name */,
    6 /* arxmlmetaparser_scanner_1_namePlural */,
    6 /* arxmlmetaparser_scanner_1_namespace */,
    6 /* arxmlmetaparser_scanner_1_noteType */,
    6 /* arxmlmetaparser_scanner_1_nsPrefix */,
    6 /* arxmlmetaparser_scanner_1_qualifiedName */,
    6 /* arxmlmetaparser_scanner_1_recommendedPackage */,
    6 /* arxmlmetaparser_scanner_1_ref */,
    6 /* arxmlmetaparser_scanner_1_roleElement */,
    6 /* arxmlmetaparser_scanner_1_roleWrapperElement */,
    6 /* arxmlmetaparser_scanner_1_schemaLocation */,
    6 /* arxmlmetaparser_scanner_1_sequenceOffset */,
    6 /* arxmlmetaparser_scanner_1_source */,
    6 /* arxmlmetaparser_scanner_1_Splitkey */,
    6 /* arxmlmetaparser_scanner_1_Status */,
    6 /* arxmlmetaparser_scanner_1_StatusRevisionBegin */,
    6 /* arxmlmetaparser_scanner_1_targetNamespace */,
    6 /* arxmlmetaparser_scanner_1_type */,
    6 /* arxmlmetaparser_scanner_1_typeElement */,
    6 /* arxmlmetaparser_scanner_1_typeWrapperElement */,
    6 /* arxmlmetaparser_scanner_1_use */,
    6 /* arxmlmetaparser_scanner_1_value */,
    6 /* arxmlmetaparser_scanner_1_version */,
    6 /* arxmlmetaparser_scanner_1_xmlns_3A_AR */,
    6 /* arxmlmetaparser_scanner_1_xmlns_3A_xsd */,
    6 /* arxmlmetaparser_scanner_1_TODO */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [77] = {NO,
    YES /* arxmlmetaparser_scanner_1_comment */,
    YES /* arxmlmetaparser_scanner_1_xmlTag */,
    YES /* arxmlmetaparser_scanner_1_xmlTagValue */,
    YES /* arxmlmetaparser_scanner_1_identifier */,
    YES /* arxmlmetaparser_scanner_1__3C_ */,
    YES /* arxmlmetaparser_scanner_1__3C_xsd_3A_ */,
    YES /* arxmlmetaparser_scanner_1__3C__2F_xsd_3A_ */,
    YES /* arxmlmetaparser_scanner_1__3C__3F_xml */,
    YES /* arxmlmetaparser_scanner_1__3E_ */,
    YES /* arxmlmetaparser_scanner_1__3F__3E_ */,
    YES /* arxmlmetaparser_scanner_1__2F__3E_ */,
    YES /* arxmlmetaparser_scanner_1__3C__2F_ */,
    YES /* arxmlmetaparser_scanner_1__3D_ */,
    YES /* arxmlmetaparser_scanner_1_group */,
    YES /* arxmlmetaparser_scanner_1_annotation */,
    YES /* arxmlmetaparser_scanner_1_appinfo */,
    YES /* arxmlmetaparser_scanner_1_attribute */,
    YES /* arxmlmetaparser_scanner_1_attributeGroup */,
    YES /* arxmlmetaparser_scanner_1_choice */,
    YES /* arxmlmetaparser_scanner_1_complexType */,
    YES /* arxmlmetaparser_scanner_1_documentation */,
    YES /* arxmlmetaparser_scanner_1_element */,
    YES /* arxmlmetaparser_scanner_1_enumeration */,
    YES /* arxmlmetaparser_scanner_1_extension */,
    YES /* arxmlmetaparser_scanner_1_import */,
    YES /* arxmlmetaparser_scanner_1_maxLength */,
    YES /* arxmlmetaparser_scanner_1_pattern */,
    YES /* arxmlmetaparser_scanner_1_restriction */,
    YES /* arxmlmetaparser_scanner_1_schema */,
    YES /* arxmlmetaparser_scanner_1_sequence */,
    YES /* arxmlmetaparser_scanner_1_simpleContent */,
    YES /* arxmlmetaparser_scanner_1_simpleType */,
    YES /* arxmlmetaparser_scanner_1_whiteSpace */,
    YES /* arxmlmetaparser_scanner_1_abstract */,
    YES /* arxmlmetaparser_scanner_1_attributeFormDefault */,
    YES /* arxmlmetaparser_scanner_1_attributeRef */,
    YES /* arxmlmetaparser_scanner_1_base */,
    YES /* arxmlmetaparser_scanner_1_category */,
    YES /* arxmlmetaparser_scanner_1_CATEGORY */,
    YES /* arxmlmetaparser_scanner_1_color */,
    YES /* arxmlmetaparser_scanner_1_customType */,
    YES /* arxmlmetaparser_scanner_1_elementFormDefault */,
    YES /* arxmlmetaparser_scanner_1_encoding */,
    YES /* arxmlmetaparser_scanner_1_enforceMinMultiplicity */,
    YES /* arxmlmetaparser_scanner_1_globalElement */,
    YES /* arxmlmetaparser_scanner_1_id */,
    YES /* arxmlmetaparser_scanner_1_latestBindingTime */,
    YES /* arxmlmetaparser_scanner_1_maxOccurs */,
    YES /* arxmlmetaparser_scanner_1_minOccurs */,
    YES /* arxmlmetaparser_scanner_1_mixed */,
    YES /* arxmlmetaparser_scanner_1_name */,
    YES /* arxmlmetaparser_scanner_1_namePlural */,
    YES /* arxmlmetaparser_scanner_1_namespace */,
    YES /* arxmlmetaparser_scanner_1_noteType */,
    YES /* arxmlmetaparser_scanner_1_nsPrefix */,
    YES /* arxmlmetaparser_scanner_1_qualifiedName */,
    YES /* arxmlmetaparser_scanner_1_recommendedPackage */,
    YES /* arxmlmetaparser_scanner_1_ref */,
    YES /* arxmlmetaparser_scanner_1_roleElement */,
    YES /* arxmlmetaparser_scanner_1_roleWrapperElement */,
    YES /* arxmlmetaparser_scanner_1_schemaLocation */,
    YES /* arxmlmetaparser_scanner_1_sequenceOffset */,
    YES /* arxmlmetaparser_scanner_1_source */,
    YES /* arxmlmetaparser_scanner_1_Splitkey */,
    YES /* arxmlmetaparser_scanner_1_Status */,
    YES /* arxmlmetaparser_scanner_1_StatusRevisionBegin */,
    YES /* arxmlmetaparser_scanner_1_targetNamespace */,
    YES /* arxmlmetaparser_scanner_1_type */,
    YES /* arxmlmetaparser_scanner_1_typeElement */,
    YES /* arxmlmetaparser_scanner_1_typeWrapperElement */,
    YES /* arxmlmetaparser_scanner_1_use */,
    YES /* arxmlmetaparser_scanner_1_value */,
    YES /* arxmlmetaparser_scanner_1_version */,
    YES /* arxmlmetaparser_scanner_1_xmlns_3A_AR */,
    YES /* arxmlmetaparser_scanner_1_xmlns_3A_xsd */,
    YES /* arxmlmetaparser_scanner_1_TODO */
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
  if ((inIndex >= 0) && (inIndex < 7)) {
    NSString * kStyleArray [7] = {
      @"Default Style",
      @"Delimiter",
      @"Name",
      @"Attribute value",
      @"Comment",
      @"Text",
      @"Keywords"
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
  if ((inIndex >= 0) && (inIndex < 7)) {
    NSString * kStyleArray [7] = {
      @"arxmlmetaparser_scanner",
      @"arxmlmetaparser_scanner-delimitersStyle",
      @"arxmlmetaparser_scanner-nameStyle",
      @"arxmlmetaparser_scanner-attributeValue",
      @"arxmlmetaparser_scanner-commentStyle",
      @"arxmlmetaparser_scanner-textStyle",
      @"arxmlmetaparser_scanner-keywordsStyle"
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
  return @"arxmlmetaparser_scanner" ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



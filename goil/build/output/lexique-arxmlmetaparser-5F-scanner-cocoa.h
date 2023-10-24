//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "OC_Lexique.h"

//----------------------------------------------------------------------------------------------------------------------
//
//                    E X T E R N    R O U T I N E S
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                    E X T E R N    F U N C T I O N S
//
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//
//----------------------------------------------------------------------------------------------------------------------

enum {arxmlmetaparser_scanner_1_,
  arxmlmetaparser_scanner_1_comment,
  arxmlmetaparser_scanner_1_xmlTag,
  arxmlmetaparser_scanner_1_xmlTagValue,
  arxmlmetaparser_scanner_1_identifier,
  arxmlmetaparser_scanner_1__3C_,
  arxmlmetaparser_scanner_1__3C_xsd_3A_,
  arxmlmetaparser_scanner_1__3C__2F_xsd_3A_,
  arxmlmetaparser_scanner_1__3C__3F_xml,
  arxmlmetaparser_scanner_1__3E_,
  arxmlmetaparser_scanner_1__3F__3E_,
  arxmlmetaparser_scanner_1__2F__3E_,
  arxmlmetaparser_scanner_1__3C__2F_,
  arxmlmetaparser_scanner_1__3D_,
  arxmlmetaparser_scanner_1_group,
  arxmlmetaparser_scanner_1_annotation,
  arxmlmetaparser_scanner_1_appinfo,
  arxmlmetaparser_scanner_1_attribute,
  arxmlmetaparser_scanner_1_attributeGroup,
  arxmlmetaparser_scanner_1_choice,
  arxmlmetaparser_scanner_1_complexType,
  arxmlmetaparser_scanner_1_documentation,
  arxmlmetaparser_scanner_1_element,
  arxmlmetaparser_scanner_1_enumeration,
  arxmlmetaparser_scanner_1_extension,
  arxmlmetaparser_scanner_1_import,
  arxmlmetaparser_scanner_1_maxLength,
  arxmlmetaparser_scanner_1_pattern,
  arxmlmetaparser_scanner_1_restriction,
  arxmlmetaparser_scanner_1_schema,
  arxmlmetaparser_scanner_1_sequence,
  arxmlmetaparser_scanner_1_simpleContent,
  arxmlmetaparser_scanner_1_simpleType,
  arxmlmetaparser_scanner_1_whiteSpace,
  arxmlmetaparser_scanner_1_abstract,
  arxmlmetaparser_scanner_1_attributeFormDefault,
  arxmlmetaparser_scanner_1_attributeRef,
  arxmlmetaparser_scanner_1_base,
  arxmlmetaparser_scanner_1_category,
  arxmlmetaparser_scanner_1_CATEGORY,
  arxmlmetaparser_scanner_1_color,
  arxmlmetaparser_scanner_1_customType,
  arxmlmetaparser_scanner_1_elementFormDefault,
  arxmlmetaparser_scanner_1_encoding,
  arxmlmetaparser_scanner_1_enforceMinMultiplicity,
  arxmlmetaparser_scanner_1_globalElement,
  arxmlmetaparser_scanner_1_id,
  arxmlmetaparser_scanner_1_latestBindingTime,
  arxmlmetaparser_scanner_1_maxOccurs,
  arxmlmetaparser_scanner_1_minOccurs,
  arxmlmetaparser_scanner_1_mixed,
  arxmlmetaparser_scanner_1_name,
  arxmlmetaparser_scanner_1_namePlural,
  arxmlmetaparser_scanner_1_namespace,
  arxmlmetaparser_scanner_1_noteType,
  arxmlmetaparser_scanner_1_nsPrefix,
  arxmlmetaparser_scanner_1_qualifiedName,
  arxmlmetaparser_scanner_1_recommendedPackage,
  arxmlmetaparser_scanner_1_ref,
  arxmlmetaparser_scanner_1_roleElement,
  arxmlmetaparser_scanner_1_roleWrapperElement,
  arxmlmetaparser_scanner_1_schemaLocation,
  arxmlmetaparser_scanner_1_sequenceOffset,
  arxmlmetaparser_scanner_1_source,
  arxmlmetaparser_scanner_1_Splitkey,
  arxmlmetaparser_scanner_1_Status,
  arxmlmetaparser_scanner_1_StatusRevisionBegin,
  arxmlmetaparser_scanner_1_targetNamespace,
  arxmlmetaparser_scanner_1_type,
  arxmlmetaparser_scanner_1_typeElement,
  arxmlmetaparser_scanner_1_typeWrapperElement,
  arxmlmetaparser_scanner_1_use,
  arxmlmetaparser_scanner_1_value,
  arxmlmetaparser_scanner_1_version,
  arxmlmetaparser_scanner_1_xmlns_3A_AR,
  arxmlmetaparser_scanner_1_xmlns_3A_xsd,
  arxmlmetaparser_scanner_1_TODO
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//                     S C A N N E R    C L A S S
//
//----------------------------------------------------------------------------------------------------------------------

@interface OC_Lexique_arxmlmetaparser_scanner : OC_Lexique {
//--- Attributes
  @protected NSMutableString * mLexicalAttribute_tokenString ;

}

- (NSUInteger) terminalVocabularyCount ;

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal ;

- (BOOL) internalParseLexicalTokenForLexicalColoring ;

- (void) parseLexicalTokenForLexicalColoring ;

- (NSUInteger) styleCount ;

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex ;

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex ;

- (NSArray *) indexingTitles ; // Array of NSString

- (BOOL) isTemplateLexique ;

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex ;

@end

//----------------------------------------------------------------------------------------------------------------------
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-5.h"

//----------------------------------------------------------------------------------------------------------------------
//  GRAMMAR options_grammar
//----------------------------------------------------------------------------------------------------------------------

class cGrammar_options_5F_grammar : public cParser_options_5F_parser {
//------------------------------------- 'list_option_value' non terminal
//--- 'parse' label
  public: virtual void nt_list_5F_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_list_5F_option_5F_value_indexing (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_list_5F_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                                    C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_item' non terminal
//--- 'parse' label
  public: virtual void nt_option_5F_item_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_option_5F_item_indexing (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_option_5F_item_ (GALGAS_gtlData & ioArgument0,
                                           C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_parser_start' non terminal
//--- 'parse' label
  public: virtual void nt_option_5F_parser_5F_start_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_option_5F_parser_5F_start_indexing (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_option_5F_parser_5F_start_ (GALGAS_gtlData & outArgument0,
                                                      C_Lexique_options_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_gtlData & outArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_gtlData & outArgument0
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (C_Compiler * inCompiler,
                                       const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                 const C_String & inSourceFilePath) ;

//------------------------------------- 'option_value' non terminal
//--- 'parse' label
  public: virtual void nt_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_option_5F_value_indexing (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                            C_Lexique_options_5F_scanner * inCompiler) ;

  public: virtual int32_t select_options_5F_parser_0 (C_Lexique_options_5F_scanner *) ;

  public: virtual int32_t select_options_5F_parser_1 (C_Lexique_options_5F_scanner *) ;

  public: virtual int32_t select_options_5F_parser_2 (C_Lexique_options_5F_scanner *) ;

  public: virtual int32_t select_options_5F_parser_3 (C_Lexique_options_5F_scanner *) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'arxml_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_arxml_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_arxml_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_arxml_5F_start_5F_symbol_ (class GALGAS_arxmlNode & outArgument0,
                                                        const class GALGAS_bool constinArgument1,
                                                        const class GALGAS_bool constinArgument2,
                                                        class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxml_5F_start_5F_symbol_parse (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxml_5F_start_5F_symbol_indexing (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_ (class GALGAS_arxmlNodeList & ioArgument0,
                                       const class GALGAS_bool constinArgument1,
                                       const class GALGAS_bool constinArgument2,
                                       class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_parse (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_indexing (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_5F_list_ (class GALGAS_arxmlNodeList & ioArgument0,
                                               const class GALGAS_bool constinArgument1,
                                               const class GALGAS_bool constinArgument2,
                                               class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_5F_list_parse (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_5F_list_indexing (class C_Lexique_arxml_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_ (GALGAS_arxmlNode & outArgument0,
                                                                     const GALGAS_bool constinArgument1,
                                                                     const GALGAS_bool constinArgument2,
                                                                     C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_indexing (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_5F_list_i1_ (GALGAS_arxmlNodeList & ioArgument0,
                                                            const GALGAS_bool constinArgument1,
                                                            const GALGAS_bool constinArgument2,
                                                            C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_5F_list_i1_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_5F_list_i1_indexing (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i2_ (GALGAS_arxmlNodeList & ioArgument0,
                                                    const GALGAS_bool constinArgument1,
                                                    const GALGAS_bool constinArgument2,
                                                    C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i2_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i2_indexing (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i3_ (GALGAS_arxmlNodeList & ioArgument0,
                                                    const GALGAS_bool constinArgument1,
                                                    const GALGAS_bool constinArgument2,
                                                    C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i3_parse (C_Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i3_indexing (C_Lexique_arxml_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_arxml_5F_parser_0 (C_Lexique_arxml_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxml_5F_parser_1 (C_Lexique_arxml_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxml_5F_parser_2 (C_Lexique_arxml_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxml_5F_parser_3 (C_Lexique_arxml_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlCommentNode  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlCommentNode : public GALGAS_arxmlNode {
//--------------------------------- Default constructor
  public: GALGAS_arxmlCommentNode (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlCommentNode constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlCommentNode * ptr (void) const {
    return (const cPtr_arxmlCommentNode *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlCommentNode (const cPtr_arxmlCommentNode * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_comment (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlCommentNode extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlCommentNode constructor_new (const class GALGAS_lstring & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlCommentNode & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setComment (class GALGAS_lstring inArgument0
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlCommentNode class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlCommentNode ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlCommentNode class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_arxmlCommentNode : public cPtr_arxmlNode {

//--- Extension method getElementsFromName
  public: virtual void method_getElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getProperty
  public: virtual void method_getProperty (const class GALGAS_string nodeName,
           class GALGAS_lstring & value,
           class GALGAS_bool & found,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getSubElementsFromName
  public: virtual void method_getSubElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method print
  public: virtual void method_print (const class GALGAS_uint indentation,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_comment ;

//--- Constructor
  public: cPtr_arxmlCommentNode (const GALGAS_lstring & in_comment
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_comment (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setComment (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'templates_directory'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_templates_5F_directory (class GALGAS_string inArgument0,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'arxmlmetaparser_syntax' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_arxmlmetaparser_5F_syntax {
//--- Virtual destructor
  public: virtual ~ cParser_arxmlmetaparser_5F_syntax (void) {}

//--- Non terminal declarations
  protected: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_ (class GALGAS_arxmlMetaClassMap & outArgument0,
                                                                  class GALGAS_bool inArgument1,
                                                                  class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xml_5F_header_ (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xml_5F_header_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xml_5F_header_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_annotation_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_annotation_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_annotation_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_appinfo_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                              class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              class GALGAS_lstring inArgument2,
                                              class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_appinfo_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_appinfo_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attribute_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attribute_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attribute_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attributeGroup_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                     class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                     class GALGAS_lstring inArgument2,
                                                     class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attributeGroup_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attributeGroup_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_choice_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                             class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             class GALGAS_lstring inArgument2,
                                             class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_choice_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_choice_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_complexType_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  class GALGAS_lstring inArgument2,
                                                  class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_complexType_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_complexType_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_documentation_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                    class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                    class GALGAS_lstring inArgument2,
                                                    class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_documentation_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_documentation_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_element_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                              class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              class GALGAS_lstring inArgument2,
                                              class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_element_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_element_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_enumeration_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  class GALGAS_lstring inArgument2,
                                                  class GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                  class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_enumeration_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_enumeration_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_extension_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_extension_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_extension_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_group_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                            class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                            class GALGAS_lstring inArgument2,
                                            class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_group_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_group_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_ignore_5F_attributes_ (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_ignore_5F_attributes_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_ignore_5F_attributes_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_import_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                             class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             class GALGAS_lstring inArgument2,
                                             class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_import_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_import_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_maxLength_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_maxLength_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_maxLength_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_pattern_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                              class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              class GALGAS_lstring inArgument2,
                                              class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_pattern_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_pattern_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_restriction_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  class GALGAS_lstring inArgument2,
                                                  class GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                  class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_restriction_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_restriction_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_schema_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                             class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_schema_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_schema_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_sequence_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                               class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               class GALGAS_lstring inArgument2,
                                               class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_sequence_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_sequence_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleContent_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                    class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                    class GALGAS_lstring inArgument2,
                                                    class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleContent_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleContent_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleType_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleType_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleType_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_whiteSpace_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_whiteSpace_parse (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_whiteSpace_indexing (class C_Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_ (GALGAS_arxmlMetaClassMap & outArgument0,
                                                                                         GALGAS_bool inArgument1,
                                                                                         C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_ (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                        GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                        GALGAS_lstring inArgument2,
                                                                        C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     GALGAS_lstring inArgument2,
                                                                     C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                       GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                       GALGAS_lstring inArgument2,
                                                                       C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                            GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                            GALGAS_lstring inArgument2,
                                                                            C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                    GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                    GALGAS_lstring inArgument2,
                                                                    C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                         GALGAS_lstring inArgument2,
                                                                         C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                           GALGAS_lstring inArgument2,
                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     GALGAS_lstring inArgument2,
                                                                     C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                          GALGAS_lstring inArgument2,
                                                                          GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                                          C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                        GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                        GALGAS_lstring inArgument2,
                                                                        C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                    GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                    GALGAS_lstring inArgument2,
                                                                    C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     GALGAS_lstring inArgument2,
                                                                     C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                          GALGAS_lstring inArgument2,
                                                                          GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                                          C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                       GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                       GALGAS_lstring inArgument2,
                                                                       C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                            GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                            GALGAS_lstring inArgument2,
                                                                            C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                         GALGAS_lstring inArgument2,
                                                                         C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                        GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                        GALGAS_lstring inArgument2,
                                                                        C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                      GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                      GALGAS_lstring inArgument2,
                                                                      C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                         GALGAS_lstring inArgument2,
                                                                         C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_ (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_0 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_1 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_2 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_3 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_4 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_5 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_6 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_7 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_8 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_9 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_10 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_11 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_12 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_13 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_14 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_15 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_16 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_17 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_18 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_19 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_20 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_21 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_22 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_23 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_24 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_25 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_26 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_27 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_28 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_29 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_30 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_31 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_32 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_33 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_34 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_35 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_36 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_37 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_38 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_39 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_40 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_41 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_42 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_43 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_44 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_45 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_46 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_47 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_48 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_49 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_50 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_51 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_52 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_53 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_54 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_55 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_56 (C_Lexique_arxmlmetaparser_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//  GRAMMAR arxmlmetaparser_grammar
//----------------------------------------------------------------------------------------------------------------------

class cGrammar_arxmlmetaparser_5F_grammar : public cParser_arxmlmetaparser_5F_syntax {
//------------------------------------- 'arxmlmetaparser_start_symbol' non terminal
//--- 'parse' label
  public: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_ (GALGAS_arxmlMetaClassMap & outArgument0,
                                                               GALGAS_bool inArgument1,
                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_arxmlMetaClassMap & outArgument0,
                                                  GALGAS_bool inArgument1
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_arxmlMetaClassMap & outArgument0,
                                                    GALGAS_bool inArgument1
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (C_Compiler * inCompiler,
                                       const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                 const C_String & inSourceFilePath) ;

//------------------------------------- 'xml_header' non terminal
//--- 'parse' label
  public: virtual void nt_xml_5F_header_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xml_5F_header_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xml_5F_header_ (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_annotation' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_annotation_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_annotation_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_annotation_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                              GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_appinfo' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_appinfo_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_appinfo_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_appinfo_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                           GALGAS_lstring inArgument2,
                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_attribute_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_attribute_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_attribute_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                             GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             GALGAS_lstring inArgument2,
                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_attributeGroup' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_attributeGroup_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_attributeGroup_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_attributeGroup_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  GALGAS_lstring inArgument2,
                                                  C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_choice' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_choice_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_choice_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_choice_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                          GALGAS_lstring inArgument2,
                                          C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_complexType' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_complexType_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_complexType_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_complexType_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                               GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               GALGAS_lstring inArgument2,
                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_documentation' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_documentation_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_documentation_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_documentation_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 GALGAS_lstring inArgument2,
                                                 C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_element' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_element_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_element_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_element_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                           GALGAS_lstring inArgument2,
                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_enumeration' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_enumeration_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_enumeration_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_enumeration_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                               GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               GALGAS_lstring inArgument2,
                                               GALGAS_arxmlMetaSimpletype & ioArgument3,
                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_extension' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_extension_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_extension_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_extension_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                             GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             GALGAS_lstring inArgument2,
                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_group' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_group_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_group_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_group_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                         GALGAS_lstring inArgument2,
                                         C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_ignore_attributes' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_ignore_5F_attributes_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_ignore_5F_attributes_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_ignore_5F_attributes_ (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_import' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_import_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_import_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_import_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                          GALGAS_lstring inArgument2,
                                          C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_maxLength' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_maxLength_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_maxLength_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_maxLength_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                             GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             GALGAS_lstring inArgument2,
                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_pattern' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_pattern_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_pattern_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_pattern_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                           GALGAS_lstring inArgument2,
                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_restriction' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_restriction_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_restriction_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_restriction_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                               GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               GALGAS_lstring inArgument2,
                                               GALGAS_arxmlMetaSimpletype & ioArgument3,
                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_schema' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_schema_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_schema_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_schema_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                          C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_sequence' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_sequence_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_sequence_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_sequence_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                            GALGAS_arxmlMetaClassGraph & ioArgument1,
                                            GALGAS_lstring inArgument2,
                                            C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_simpleContent' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_simpleContent_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_simpleContent_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_simpleContent_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 GALGAS_lstring inArgument2,
                                                 C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_simpleType' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_simpleType_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_simpleType_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_simpleType_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                              GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_whiteSpace' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_whiteSpace_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_whiteSpace_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_whiteSpace_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                              GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_0 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_1 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_2 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_3 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_4 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_5 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_6 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_7 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_8 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_9 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_10 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_11 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_12 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_13 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_14 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_15 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_16 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_17 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_18 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_19 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_20 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_21 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_22 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_23 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_24 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_25 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_26 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_27 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_28 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_29 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_30 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_31 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_32 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_33 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_34 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_35 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_36 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_37 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_38 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_39 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_40 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_41 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_42 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_43 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_44 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_45 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_46 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_47 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_48 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_49 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_50 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_51 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_52 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_53 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_54 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_55 (C_Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_56 (C_Lexique_arxmlmetaparser_5F_scanner *) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'addText'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_addText (class GALGAS_arxmlNodeList & ioArgument0,
                      const class GALGAS_bool constinArgument1,
                      class C_Compiler * inCompiler
                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'convertToOil'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_convertToOil (class GALGAS_implementation & ioArgument0,
                           class GALGAS_applicationDefinition & ioArgument1,
                           class GALGAS_arxmlElementValue inArgument2,
                           class C_Compiler * inCompiler
                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'displayOil'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_displayOil (class GALGAS_string inArgument0,
                         class C_Compiler * inCompiler
                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'getAutosarVersion'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_getAutosarVersion (class GALGAS_arxmlNode inArgument0,
                                class GALGAS_lstring & outArgument1,
                                class GALGAS_lstring & outArgument2,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'includeConfigs'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_includeConfigs (class GALGAS_implementation & ioArgument0,
                             class GALGAS_applicationDefinition & ioArgument1,
                             class GALGAS_string & ioArgument2,
                             class GALGAS_lstring inArgument3,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClass'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_nodeToClass (class GALGAS_arxmlNode inArgument0,
                          class GALGAS_arxmlMetaClassMap & ioArgument1,
                          class GALGAS_arxmlElementValue & outArgument2,
                          class C_Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getSubElements'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getSubElements (class cPtr_arxmlElementNode * inObject,
                                         class GALGAS_arxmlElementList & out_nodeList,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getText'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getText (class cPtr_arxmlElementNode * inObject,
                                  class GALGAS_lstring & io_value,
                                  class GALGAS_bool & io_found,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlTextNode  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlTextNode : public GALGAS_arxmlNode {
//--------------------------------- Default constructor
  public: GALGAS_arxmlTextNode (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlTextNode constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlTextNode * ptr (void) const {
    return (const cPtr_arxmlTextNode *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlTextNode (const cPtr_arxmlTextNode * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_text (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlTextNode extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlTextNode constructor_new (const class GALGAS_lstring & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlTextNode & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setText (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlTextNode class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlTextNode ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlTextNode class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_arxmlTextNode : public cPtr_arxmlNode {

//--- Extension method getElementsFromName
  public: virtual void method_getElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getProperty
  public: virtual void method_getProperty (const class GALGAS_string nodeName,
           class GALGAS_lstring & value,
           class GALGAS_bool & found,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getSubElementsFromName
  public: virtual void method_getSubElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getText
  public: virtual void method_getText (class GALGAS_lstring & outText,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method print
  public: virtual void method_print (const class GALGAS_uint indentation,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_text ;

//--- Constructor
  public: cPtr_arxmlTextNode (const GALGAS_lstring & in_text
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_text (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setText (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlTextNode getText'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getText (class cPtr_arxmlTextNode * inObject,
                                  class GALGAS_lstring & out_outText,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getAttributes (class cPtr_arxmlElementNode * inObject,
                                        class GALGAS_arxmlAttributeMap & io_outAttributes,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getAttribute (class cPtr_arxmlElementNode * inObject,
                                       class GALGAS_string in_attributeName,
                                       class GALGAS_lstring & out_outAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getName'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getName (class cPtr_arxmlElementNode * inObject,
                                  class GALGAS_lstring & out_outName,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlElementValue insertElement'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlElementValue_insertElement) (class cPtr_arxmlElementValue * inObject,
                                                                          class GALGAS_lstring inArgument0,
                                                                          class GALGAS_arxmlElementValue inArgument1,
                                                                          class C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_insertElement (const int32_t inClassIndex,
                                         extensionSetterSignature_arxmlElementValue_insertElement inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_insertElement (class cPtr_arxmlElementValue * inObject,
                                        GALGAS_lstring in_key,
                                        GALGAS_arxmlElementValue in_element,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElementsByPath'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElementsByPath (class cPtr_arxmlElementValue * inObject,
                                            class GALGAS_stringlist in_path,
                                            class GALGAS_arxmlElementValueList & io_outElements,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElements'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElements (class cPtr_arxmlElementValue * inObject,
                                      class GALGAS_string in_elementName,
                                      class GALGAS_arxmlElementValueList & out_outElements,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElement'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElement (class cPtr_arxmlElementValue * inObject,
                                     class GALGAS_string in_elementName,
                                     class GALGAS_arxmlElementValue & out_outElement,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue hasElement'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlElementValue * inObject,
                                                  class GALGAS_string in_elementName,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue getTextFromElement'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_getTextFromElement (const cPtr_arxmlElementValue * inObject,
                                                             class GALGAS_string in_elementName,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getAllTextsInSelf'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getAllTextsInSelf (class cPtr_arxmlElementValue * inObject,
                                            class GALGAS_string in_separator,
                                            class GALGAS_lstring & io_outString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue getAttributeValueFromElement'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_getAttributeValueFromElement (const cPtr_arxmlElementValue * inObject,
                                                                       class GALGAS_string in_elementName,
                                                                       class GALGAS_string in_attributeName,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass legacyAddParameters'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_legacyAddParameters) (class cPtr_arxmlMetaClass * inObject,
                                                                             class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                             class GALGAS_lstringlist inArgument1,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_legacyAddParameters (const int32_t inClassIndex,
                                               extensionSetterSignature_arxmlMetaClass_legacyAddParameters inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyAddParameters (class cPtr_arxmlMetaClass * inObject,
                                              GALGAS_arxmlMetaClassMap & io_classMap,
                                              GALGAS_lstringlist in_successors,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass setDescription'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_setDescription) (class cPtr_arxmlMetaClass * inObject,
                                                                        class GALGAS_lstring inArgument0,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setDescription (const int32_t inClassIndex,
                                          extensionSetterSignature_arxmlMetaClass_setDescription inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setDescription (class cPtr_arxmlMetaClass * inObject,
                                         GALGAS_lstring in_iDesc,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaClass hasElement'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlMetaClass * inObject,
                                                  class GALGAS_string in_eleName,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaClass hasAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasAttribute (const cPtr_arxmlMetaClass * inObject,
                                                    class GALGAS_string in_attrName,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaSimpletype  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaSimpletype : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaSimpletype (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlMetaSimpletype * ptr (void) const {
    return (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlMetaSimpletype (const cPtr_arxmlMetaSimpletype * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_restrictionType readProperty_type (void) const ;

  public: class GALGAS_restrictionBaseType readProperty_base (void) const ;

  public: class GALGAS_lstringlist readProperty_values (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaSimpletype extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaSimpletype constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_restrictionType & inOperand1,
                                                                   const class GALGAS_restrictionBaseType & inOperand2,
                                                                   const class GALGAS_lstringlist & inOperand3
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaSimpletype & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setBase (class GALGAS_restrictionBaseType inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setType (class GALGAS_restrictionType inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValues (class GALGAS_lstringlist inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaSimpletype class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaSimpletype ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaSimpletype class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_arxmlMetaSimpletype : public acPtr_class {

//--- Extension method display
  public: virtual void method_display (class GALGAS_arxmlMetaClassMap classMap,
           class GALGAS_string & ioString,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_restrictionType mProperty_type ;
  public: GALGAS_restrictionBaseType mProperty_base ;
  public: GALGAS_lstringlist mProperty_values ;

//--- Constructor
  public: cPtr_arxmlMetaSimpletype (const GALGAS_lstring & in_name,
                                    const GALGAS_restrictionType & in_type,
                                    const GALGAS_restrictionBaseType & in_base,
                                    const GALGAS_lstringlist & in_values
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_restrictionType getter_type (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setType (GALGAS_restrictionType inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_restrictionBaseType getter_base (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBase (GALGAS_restrictionBaseType inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_values (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValues (GALGAS_lstringlist inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaSimpletype display'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_display (class cPtr_arxmlMetaSimpletype * inObject,
                                  class GALGAS_arxmlMetaClassMap in_classMap,
                                  class GALGAS_string & io_ioString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaSimpletype addValue'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaSimpletype_addValue) (class cPtr_arxmlMetaSimpletype * inObject,
                                                                       class GALGAS_lstring inArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addValue (const int32_t inClassIndex,
                                    extensionSetterSignature_arxmlMetaSimpletype_addValue inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addValue (class cPtr_arxmlMetaSimpletype * inObject,
                                   GALGAS_lstring in_value,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'fillLegacy'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_fillLegacy (class GALGAS_arxmlMetaClassMap & ioArgument0,
                         class GALGAS_arxmlMetaClassGraph & ioArgument1,
                         class C_Compiler * inCompiler
                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'lstringhere'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_lstringhere (class GALGAS_lstring & outArgument0,
                          class GALGAS_string inArgument1,
                          class C_Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;


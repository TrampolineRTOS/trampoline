#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-5.h"

//--------------------------------------------------------------------------------------------------
//  GRAMMAR options_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_options_5F_grammar : public cParser_options_5F_parser {
//------------------------------------- 'list_option_value' non terminal
//--- 'parse' label
  public: virtual void nt_list_5F_option_5F_value_parse (Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_list_5F_option_5F_value_indexing (Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_list_5F_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                                    Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_item' non terminal
//--- 'parse' label
  public: virtual void nt_option_5F_item_parse (Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_option_5F_item_indexing (Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_option_5F_item_ (GALGAS_gtlData & ioArgument0,
                                           Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_parser_start' non terminal
//--- 'parse' label
  public: virtual void nt_option_5F_parser_5F_start_parse (Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_option_5F_parser_5F_start_indexing (Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_option_5F_parser_5F_start_ (GALGAS_gtlData & outArgument0,
                                                      Lexique_options_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_gtlData & outArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_gtlData & outArgument0
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'option_value' non terminal
//--- 'parse' label
  public: virtual void nt_option_5F_value_parse (Lexique_options_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_option_5F_value_indexing (Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                            Lexique_options_5F_scanner * inCompiler) ;

  public: virtual int32_t select_options_5F_parser_0 (Lexique_options_5F_scanner *) ;

  public: virtual int32_t select_options_5F_parser_1 (Lexique_options_5F_scanner *) ;

  public: virtual int32_t select_options_5F_parser_2 (Lexique_options_5F_scanner *) ;

  public: virtual int32_t select_options_5F_parser_3 (Lexique_options_5F_scanner *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Parser class 'arxml_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_arxml_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_arxml_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_arxml_5F_start_5F_symbol_ (class GALGAS_arxmlNode & outArgument0,
                                                        const class GALGAS_bool constinArgument1,
                                                        const class GALGAS_bool constinArgument2,
                                                        class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxml_5F_start_5F_symbol_parse (class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxml_5F_start_5F_symbol_indexing (class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_ (class GALGAS_arxmlNodeList & ioArgument0,
                                       const class GALGAS_bool constinArgument1,
                                       const class GALGAS_bool constinArgument2,
                                       class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_parse (class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_indexing (class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_5F_list_ (class GALGAS_arxmlNodeList & ioArgument0,
                                               const class GALGAS_bool constinArgument1,
                                               const class GALGAS_bool constinArgument2,
                                               class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_5F_list_parse (class Lexique_arxml_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_element_5F_list_indexing (class Lexique_arxml_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_ (GALGAS_arxmlNode & outArgument0,
                                                                     const GALGAS_bool constinArgument1,
                                                                     const GALGAS_bool constinArgument2,
                                                                     Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_indexing (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_5F_list_i1_ (GALGAS_arxmlNodeList & ioArgument0,
                                                            const GALGAS_bool constinArgument1,
                                                            const GALGAS_bool constinArgument2,
                                                            Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_5F_list_i1_parse (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_5F_list_i1_indexing (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i2_ (GALGAS_arxmlNodeList & ioArgument0,
                                                    const GALGAS_bool constinArgument1,
                                                    const GALGAS_bool constinArgument2,
                                                    Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i2_parse (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i2_indexing (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i3_ (GALGAS_arxmlNodeList & ioArgument0,
                                                    const GALGAS_bool constinArgument1,
                                                    const GALGAS_bool constinArgument2,
                                                    Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i3_parse (Lexique_arxml_5F_scanner * inLexique) ;

  protected: void rule_arxml_5F_parser_element_i3_indexing (Lexique_arxml_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_arxml_5F_parser_0 (Lexique_arxml_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxml_5F_parser_1 (Lexique_arxml_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxml_5F_parser_2 (Lexique_arxml_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxml_5F_parser_3 (Lexique_arxml_5F_scanner *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlCommentNode  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlCommentNode : public GALGAS_arxmlNode {
//--------------------------------- Default constructor
  public: GALGAS_arxmlCommentNode (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlCommentNode * ptr (void) const {
    return (const cPtr_arxmlCommentNode *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlCommentNode (const cPtr_arxmlCommentNode * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_comment (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlCommentNode extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlCommentNode class_func_new (const class GALGAS_lstring & inOperand0
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


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlCommentNode ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlCommentNode class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlCommentNode : public cPtr_arxmlNode {

//--- Extension method getElementsFromName
  public: virtual void method_getElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getProperty
  public: virtual void method_getProperty (const class GALGAS_string nodeName,
           class GALGAS_lstring & value,
           class GALGAS_bool & found,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getSubElementsFromName
  public: virtual void method_getSubElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method print
  public: virtual void method_print (const class GALGAS_uint indentation,
           Compiler * COMMA_LOCATION_ARGS) override ;


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
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Function 'templates_directory'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_templates_5F_directory (class GALGAS_string inArgument0,
                                                     class Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'arxmlmetaparser_syntax' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_arxmlmetaparser_5F_syntax {
//--- Virtual destructor
  public: virtual ~ cParser_arxmlmetaparser_5F_syntax (void) {}

//--- Non terminal declarations
  protected: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_ (class GALGAS_arxmlMetaClassMap & outArgument0,
                                                                  class GALGAS_bool inArgument1,
                                                                  class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xml_5F_header_ (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xml_5F_header_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xml_5F_header_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_annotation_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_annotation_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_annotation_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_appinfo_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                              class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              class GALGAS_lstring inArgument2,
                                              class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_appinfo_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_appinfo_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attribute_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attribute_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attribute_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attributeGroup_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                     class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                     class GALGAS_lstring inArgument2,
                                                     class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attributeGroup_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_attributeGroup_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_choice_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                             class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             class GALGAS_lstring inArgument2,
                                             class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_choice_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_choice_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_complexType_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  class GALGAS_lstring inArgument2,
                                                  class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_complexType_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_complexType_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_documentation_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                    class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                    class GALGAS_lstring inArgument2,
                                                    class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_documentation_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_documentation_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_element_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                              class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              class GALGAS_lstring inArgument2,
                                              class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_element_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_element_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_enumeration_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  class GALGAS_lstring inArgument2,
                                                  class GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                  class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_enumeration_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_enumeration_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_extension_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_extension_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_extension_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_group_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                            class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                            class GALGAS_lstring inArgument2,
                                            class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_group_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_group_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_ignore_5F_attributes_ (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_ignore_5F_attributes_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_ignore_5F_attributes_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_import_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                             class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             class GALGAS_lstring inArgument2,
                                             class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_import_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_import_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_maxLength_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_maxLength_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_maxLength_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_pattern_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                              class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              class GALGAS_lstring inArgument2,
                                              class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_pattern_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_pattern_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_restriction_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  class GALGAS_lstring inArgument2,
                                                  class GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                  class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_restriction_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_restriction_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_schema_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                             class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_schema_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_schema_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_sequence_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                               class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               class GALGAS_lstring inArgument2,
                                               class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_sequence_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_sequence_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleContent_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                    class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                    class GALGAS_lstring inArgument2,
                                                    class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleContent_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleContent_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleType_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleType_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_simpleType_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_whiteSpace_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_whiteSpace_parse (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_xsd_5F_whiteSpace_indexing (class Lexique_arxmlmetaparser_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_ (GALGAS_arxmlMetaClassMap & outArgument0,
                                                                                         GALGAS_bool inArgument1,
                                                                                         Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_ (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                        GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                        GALGAS_lstring inArgument2,
                                                                        Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     GALGAS_lstring inArgument2,
                                                                     Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                       GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                       GALGAS_lstring inArgument2,
                                                                       Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                            GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                            GALGAS_lstring inArgument2,
                                                                            Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                    GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                    GALGAS_lstring inArgument2,
                                                                    Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                         GALGAS_lstring inArgument2,
                                                                         Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                           GALGAS_lstring inArgument2,
                                                                           Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     GALGAS_lstring inArgument2,
                                                                     Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                          GALGAS_lstring inArgument2,
                                                                          GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                                          Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                        GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                        GALGAS_lstring inArgument2,
                                                                        Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                    GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                    GALGAS_lstring inArgument2,
                                                                    Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     GALGAS_lstring inArgument2,
                                                                     Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                          GALGAS_lstring inArgument2,
                                                                          GALGAS_arxmlMetaSimpletype & ioArgument3,
                                                                          Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                     GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                     Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                       GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                       GALGAS_lstring inArgument2,
                                                                       Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                            GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                            GALGAS_lstring inArgument2,
                                                                            Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                         GALGAS_lstring inArgument2,
                                                                         Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                        GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                        GALGAS_lstring inArgument2,
                                                                        Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                      GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                      GALGAS_lstring inArgument2,
                                                                      Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                                         GALGAS_lstring inArgument2,
                                                                         Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_ (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_parse (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;

  protected: void rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_indexing (Lexique_arxmlmetaparser_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_0 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_1 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_2 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_3 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_4 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_5 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_6 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_7 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_8 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_9 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_10 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_11 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_12 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_13 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_14 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_15 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_16 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_17 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_18 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_19 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_20 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_21 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_22 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_23 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_24 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_25 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_26 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_27 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_28 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_29 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_30 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_31 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_32 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_33 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_34 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_35 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_36 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_37 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_38 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_39 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_40 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_41 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_42 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_43 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_44 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_45 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_46 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_47 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_48 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_49 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_50 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_51 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_52 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_53 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_54 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_55 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;

  protected: virtual int32_t select_arxmlmetaparser_5F_syntax_56 (Lexique_arxmlmetaparser_5F_scanner *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR arxmlmetaparser_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_arxmlmetaparser_5F_grammar : public cParser_arxmlmetaparser_5F_syntax {
//------------------------------------- 'arxmlmetaparser_start_symbol' non terminal
//--- 'parse' label
  public: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_arxmlmetaparser_5F_start_5F_symbol_ (GALGAS_arxmlMetaClassMap & outArgument0,
                                                               GALGAS_bool inArgument1,
                                                               Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_arxmlMetaClassMap & outArgument0,
                                                  GALGAS_bool inArgument1
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_arxmlMetaClassMap & outArgument0,
                                                    GALGAS_bool inArgument1
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'xml_header' non terminal
//--- 'parse' label
  public: virtual void nt_xml_5F_header_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xml_5F_header_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xml_5F_header_ (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_annotation' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_annotation_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_annotation_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_annotation_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                              GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              GALGAS_lstring inArgument2,
                                              Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_appinfo' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_appinfo_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_appinfo_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_appinfo_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                           GALGAS_lstring inArgument2,
                                           Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_attribute_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_attribute_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_attribute_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                             GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_attributeGroup' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_attributeGroup_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_attributeGroup_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_attributeGroup_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                  GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                  GALGAS_lstring inArgument2,
                                                  Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_choice' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_choice_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_choice_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_choice_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                          GALGAS_lstring inArgument2,
                                          Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_complexType' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_complexType_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_complexType_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_complexType_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                               GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               GALGAS_lstring inArgument2,
                                               Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_documentation' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_documentation_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_documentation_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_documentation_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 GALGAS_lstring inArgument2,
                                                 Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_element' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_element_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_element_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_element_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                           GALGAS_lstring inArgument2,
                                           Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_enumeration' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_enumeration_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_enumeration_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_enumeration_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                               GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               GALGAS_lstring inArgument2,
                                               GALGAS_arxmlMetaSimpletype & ioArgument3,
                                               Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_extension' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_extension_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_extension_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_extension_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                             GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_group' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_group_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_group_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_group_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                         GALGAS_arxmlMetaClassGraph & ioArgument1,
                                         GALGAS_lstring inArgument2,
                                         Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_ignore_attributes' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_ignore_5F_attributes_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_ignore_5F_attributes_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_ignore_5F_attributes_ (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_import' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_import_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_import_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_import_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                          GALGAS_lstring inArgument2,
                                          Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_maxLength' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_maxLength_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_maxLength_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_maxLength_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                             GALGAS_arxmlMetaClassGraph & ioArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_pattern' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_pattern_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_pattern_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_pattern_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                           GALGAS_arxmlMetaClassGraph & ioArgument1,
                                           GALGAS_lstring inArgument2,
                                           Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_restriction' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_restriction_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_restriction_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_restriction_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                               GALGAS_arxmlMetaClassGraph & ioArgument1,
                                               GALGAS_lstring inArgument2,
                                               GALGAS_arxmlMetaSimpletype & ioArgument3,
                                               Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_schema' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_schema_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_schema_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_schema_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                          GALGAS_arxmlMetaClassGraph & ioArgument1,
                                          Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_sequence' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_sequence_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_sequence_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_sequence_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                            GALGAS_arxmlMetaClassGraph & ioArgument1,
                                            GALGAS_lstring inArgument2,
                                            Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_simpleContent' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_simpleContent_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_simpleContent_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_simpleContent_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                                 GALGAS_arxmlMetaClassGraph & ioArgument1,
                                                 GALGAS_lstring inArgument2,
                                                 Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_simpleType' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_simpleType_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_simpleType_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_simpleType_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                              GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              GALGAS_lstring inArgument2,
                                              Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//------------------------------------- 'xsd_whiteSpace' non terminal
//--- 'parse' label
  public: virtual void nt_xsd_5F_whiteSpace_parse (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_xsd_5F_whiteSpace_indexing (Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_xsd_5F_whiteSpace_ (GALGAS_arxmlMetaClassMap & ioArgument0,
                                              GALGAS_arxmlMetaClassGraph & ioArgument1,
                                              GALGAS_lstring inArgument2,
                                              Lexique_arxmlmetaparser_5F_scanner * inCompiler) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_0 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_1 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_2 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_3 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_4 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_5 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_6 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_7 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_8 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_9 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_10 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_11 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_12 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_13 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_14 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_15 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_16 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_17 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_18 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_19 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_20 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_21 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_22 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_23 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_24 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_25 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_26 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_27 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_28 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_29 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_30 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_31 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_32 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_33 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_34 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_35 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_36 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_37 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_38 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_39 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_40 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_41 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_42 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_43 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_44 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_45 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_46 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_47 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_48 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_49 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_50 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_51 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_52 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_53 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_54 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_55 (Lexique_arxmlmetaparser_5F_scanner *) ;

  public: virtual int32_t select_arxmlmetaparser_5F_syntax_56 (Lexique_arxmlmetaparser_5F_scanner *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Routine 'addText&?'
//
//--------------------------------------------------------------------------------------------------

void routine_addText_26__3F_ (class GALGAS_arxmlNodeList & ioArgument0,
                              const class GALGAS_bool constinArgument1,
                              class Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'convertToOil&&?'
//
//--------------------------------------------------------------------------------------------------

void routine_convertToOil_26__26__3F_ (class GALGAS_implementation & ioArgument0,
                                       class GALGAS_applicationDefinition & ioArgument1,
                                       class GALGAS_arxmlElementValue inArgument2,
                                       class Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'displayOil?'
//
//--------------------------------------------------------------------------------------------------

void routine_displayOil_3F_ (class GALGAS_string inArgument0,
                             class Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'getAutosarVersion?!!'
//
//--------------------------------------------------------------------------------------------------

void routine_getAutosarVersion_3F__21__21_ (class GALGAS_arxmlNode inArgument0,
                                            class GALGAS_lstring & outArgument1,
                                            class GALGAS_lstring & outArgument2,
                                            class Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'includeConfigs&&&?'
//
//--------------------------------------------------------------------------------------------------

void routine_includeConfigs_26__26__26__3F_ (class GALGAS_implementation & ioArgument0,
                                             class GALGAS_applicationDefinition & ioArgument1,
                                             class GALGAS_string & ioArgument2,
                                             class GALGAS_lstring inArgument3,
                                             class Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClass?&!'
//
//--------------------------------------------------------------------------------------------------

void routine_nodeToClass_3F__26__21_ (class GALGAS_arxmlNode inArgument0,
                                      class GALGAS_arxmlMetaClassMap & ioArgument1,
                                      class GALGAS_arxmlElementValue & outArgument2,
                                      class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getSubElements'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getSubElements (class cPtr_arxmlElementNode * inObject,
                                         class GALGAS_arxmlElementList & out_nodeList,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getText'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getText (class cPtr_arxmlElementNode * inObject,
                                  class GALGAS_lstring & io_value,
                                  class GALGAS_bool & io_found,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlTextNode  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlTextNode : public GALGAS_arxmlNode {
//--------------------------------- Default constructor
  public: GALGAS_arxmlTextNode (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlTextNode * ptr (void) const {
    return (const cPtr_arxmlTextNode *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlTextNode (const cPtr_arxmlTextNode * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_text (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlTextNode extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlTextNode class_func_new (const class GALGAS_lstring & inOperand0
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


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlTextNode ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlTextNode class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlTextNode : public cPtr_arxmlNode {

//--- Extension method getElementsFromName
  public: virtual void method_getElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getProperty
  public: virtual void method_getProperty (const class GALGAS_string nodeName,
           class GALGAS_lstring & value,
           class GALGAS_bool & found,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getSubElementsFromName
  public: virtual void method_getSubElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getText
  public: virtual void method_getText (class GALGAS_lstring & outText,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method print
  public: virtual void method_print (const class GALGAS_uint indentation,
           Compiler * COMMA_LOCATION_ARGS) override ;


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
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlTextNode getText'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getText (class cPtr_arxmlTextNode * inObject,
                                  class GALGAS_lstring & out_outText,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getAttributes'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getAttributes (class cPtr_arxmlElementNode * inObject,
                                        class GALGAS_arxmlAttributeMap & io_outAttributes,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getAttribute'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getAttribute (class cPtr_arxmlElementNode * inObject,
                                       class GALGAS_string in_attributeName,
                                       class GALGAS_lstring & out_outAttribute,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getName'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getName (class cPtr_arxmlElementNode * inObject,
                                  class GALGAS_lstring & out_outName,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlElementValue insertElement'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlElementValue_insertElement) (class cPtr_arxmlElementValue * inObject,
                                                                          class GALGAS_lstring inArgument0,
                                                                          class GALGAS_arxmlElementValue inArgument1,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_insertElement (const int32_t inClassIndex,
                                         extensionSetterSignature_arxmlElementValue_insertElement inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_insertElement (class cPtr_arxmlElementValue * inObject,
                                        GALGAS_lstring in_key,
                                        GALGAS_arxmlElementValue in_element,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElementsByPath'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getElementsByPath (class cPtr_arxmlElementValue * inObject,
                                            class GALGAS_stringlist in_path,
                                            class GALGAS_arxmlElementValueList & io_outElements,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElements'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getElements (class cPtr_arxmlElementValue * inObject,
                                      class GALGAS_string in_elementName,
                                      class GALGAS_arxmlElementValueList & out_outElements,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElement'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getElement (class cPtr_arxmlElementValue * inObject,
                                     class GALGAS_string in_elementName,
                                     class GALGAS_arxmlElementValue & out_outElement,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue hasElement'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlElementValue * inObject,
                                                  class GALGAS_string in_elementName,
                                                  class Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue getTextFromElement'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_getTextFromElement (const cPtr_arxmlElementValue * inObject,
                                                             class GALGAS_string in_elementName,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getAllTextsInSelf'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getAllTextsInSelf (class cPtr_arxmlElementValue * inObject,
                                            class GALGAS_string in_separator,
                                            class GALGAS_lstring & io_outString,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue getAttributeValueFromElement'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_getAttributeValueFromElement (const cPtr_arxmlElementValue * inObject,
                                                                       class GALGAS_string in_elementName,
                                                                       class GALGAS_string in_attributeName,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass legacyAddParameters'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_legacyAddParameters) (class cPtr_arxmlMetaClass * inObject,
                                                                             class GALGAS_arxmlMetaClassMap & ioArgument0,
                                                                             class GALGAS_lstringlist inArgument1,
                                                                             class Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_legacyAddParameters (const int32_t inClassIndex,
                                               extensionSetterSignature_arxmlMetaClass_legacyAddParameters inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyAddParameters (class cPtr_arxmlMetaClass * inObject,
                                              GALGAS_arxmlMetaClassMap & io_classMap,
                                              GALGAS_lstringlist in_successors,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass setDescription'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_setDescription) (class cPtr_arxmlMetaClass * inObject,
                                                                        class GALGAS_lstring inArgument0,
                                                                        class Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setDescription (const int32_t inClassIndex,
                                          extensionSetterSignature_arxmlMetaClass_setDescription inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setDescription (class cPtr_arxmlMetaClass * inObject,
                                         GALGAS_lstring in_iDesc,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaClass hasElement'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlMetaClass * inObject,
                                                  class GALGAS_string in_eleName,
                                                  class Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaClass hasAttribute'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasAttribute (const cPtr_arxmlMetaClass * inObject,
                                                    class GALGAS_string in_attrName,
                                                    class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaSimpletype  value class
//
//--------------------------------------------------------------------------------------------------

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

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaSimpletype extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaSimpletype class_func_new (const class GALGAS_lstring & inOperand0,
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


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaSimpletype ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaSimpletype class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlMetaSimpletype : public acPtr_class {

//--- Extension method display
  public: virtual void method_display (class GALGAS_arxmlMetaClassMap classMap,
           class GALGAS_string & ioString,
           Compiler * COMMA_LOCATION_ARGS) ;


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
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaSimpletype display'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_display (class cPtr_arxmlMetaSimpletype * inObject,
                                  class GALGAS_arxmlMetaClassMap in_classMap,
                                  class GALGAS_string & io_ioString,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaSimpletype addValue'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaSimpletype_addValue) (class cPtr_arxmlMetaSimpletype * inObject,
                                                                       class GALGAS_lstring inArgument0,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_addValue (const int32_t inClassIndex,
                                    extensionSetterSignature_arxmlMetaSimpletype_addValue inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_addValue (class cPtr_arxmlMetaSimpletype * inObject,
                                   GALGAS_lstring in_value,
                                   Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'fillLegacy&&'
//
//--------------------------------------------------------------------------------------------------

void routine_fillLegacy_26__26_ (class GALGAS_arxmlMetaClassMap & ioArgument0,
                                 class GALGAS_arxmlMetaClassGraph & ioArgument1,
                                 class Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'lstringhere!?'
//
//--------------------------------------------------------------------------------------------------

void routine_lstringhere_21__3F_ (class GALGAS_lstring & outArgument0,
                                  class GALGAS_string inArgument1,
                                  class Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext addModulePath'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_addModulePath) (class cPtr_gtlContext * inObject,
                                                                   const class GALGAS_string constinArgument0,
                                                                   const class GALGAS_string constinArgument1,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_addModulePath (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_addModulePath inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_addModulePath (class cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_rootPath,
                                        const GALGAS_string constin_modulePath,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext addInputVariable'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_addInputVariable) (class cPtr_gtlContext * inObject,
                                                                      class GALGAS_gtlData inArgument0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_addInputVariable (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_addInputVariable inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_addInputVariable (class cPtr_gtlContext * inObject,
                                           GALGAS_gtlData in_inputVariable,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext popFirstInputArg'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_popFirstInputArg) (class cPtr_gtlContext * inObject,
                                                                      class GALGAS_location inArgument0,
                                                                      class GALGAS_gtlData & outArgument1,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_popFirstInputArg (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_popFirstInputArg inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_popFirstInputArg (class cPtr_gtlContext * inObject,
                                           GALGAS_location in_where,
                                           GALGAS_gtlData & out_result,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext fullPrefix'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_fullPrefix (const cPtr_gtlContext * inObject,
                                                     const class GALGAS_gtlData constin_vars,
                                                     class Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext fullTemplateFileName'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                               class GALGAS_gtlContext in_context,
                                                               class GALGAS_gtlData in_vars,
                                                               class GALGAS_lstring in_simpleName,
                                                               class Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'pathWithExtension'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_pathWithExtension (class GALGAS_gtlContext inArgument0,
                                                class GALGAS_string inArgument1,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'gtl_module_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_gtl_5F_module_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_gtl_5F_module_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_gtl_5F_argument_5F_list_ (class GALGAS_gtlArgumentList & outArgument0,
                                                       class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_argument_5F_list_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_argument_5F_list_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                 class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_function_ (class GALGAS_gtlFunction & outArgument0,
                                               class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_function_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_function_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_getter_ (class GALGAS_gtlGetter & outArgument0,
                                             class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_getter_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_getter_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_ (class GALGAS_gtlContext inArgument0,
                                             class GALGAS_library & ioArgument1,
                                             class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                  class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_instruction_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_instruction_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_instruction_5F_list_ (class GALGAS_gtlInstructionList & outArgument0,
                                                          class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_instruction_5F_list_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_instruction_5F_list_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_module_5F_start_5F_symbol_ (class GALGAS_gtlContext inArgument0,
                                                                class GALGAS_library & ioArgument1,
                                                                class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_module_5F_start_5F_symbol_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_module_5F_start_5F_symbol_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_setter_ (class GALGAS_gtlSetter & outArgument0,
                                             class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_setter_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_setter_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                            class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_parse (class Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_indexing (class Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_ (GALGAS_gtlInstructionList & outArgument0,
                                                                               Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_ (GALGAS_gtlContext inArgument0,
                                                                                     GALGAS_library & ioArgument1,
                                                                                     Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_ (GALGAS_gtlFunction & outArgument0,
                                                                    Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_ (GALGAS_gtlGetter & outArgument0,
                                                                  Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_ (GALGAS_gtlSetter & outArgument0,
                                                                  Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                       Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                       Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                       Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                       Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_indexing (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                       Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_parse (Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_indexing (Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_gtl_5F_module_5F_parser_0 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_1 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_2 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_3 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_4 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_5 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_6 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_7 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_8 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_9 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_10 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_11 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_12 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_13 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_14 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_15 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_16 (Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_module_5F_parser_17 (Lexique_gtl_5F_scanner *) = 0 ;


} ;


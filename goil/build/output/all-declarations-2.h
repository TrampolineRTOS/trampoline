#ifndef all_2D_declarations_2D__32__ENTITIES_DEFINED
#define all_2D_declarations_2D__32__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-1.h"

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR options_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_options_5F_grammar : public cParser_options_5F_parser {
//------------------------------------- 'list_option_value' non terminal
//--- 'parse' label
  public : virtual void nt_list_5F_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_list_5F_option_5F_value_ (GALGAS_Ttype & outArgument0,
                                                     GALGAS_Tvalue & outArgument1,
                                                     C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_item' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_item_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_item_ (GALGAS_TfieldMap & ioArgument0,
                                            C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_parser_start' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_parser_5F_start_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_parser_5F_start_ (GALGAS_TfieldMap & outArgument0,
                                                       C_Lexique_options_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_TfieldMap & outArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_TfieldMap & outArgument0
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'option_value' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_value_ (GALGAS_Ttype & outArgument0,
                                             GALGAS_Tvalue & outArgument1,
                                             C_Lexique_options_5F_scanner * inCompiler) ;

  public : virtual int32_t select_options_5F_parser_0 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_1 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_2 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_3 (C_Lexique_options_5F_scanner *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR goil_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_goil_5F_grammar : public cParser_goil_5F_syntax,
                                 public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public : virtual void nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public : virtual void nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       GALGAS_string & ioArgument2,
                                                       const GALGAS_bool inArgument3,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                                GALGAS_impType & outArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public : virtual void nt_description_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                         C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public : virtual void nt_file_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                  GALGAS_applicationDefinition & ioArgument1,
                                  GALGAS_string & ioArgument2,
                                  const GALGAS_bool inArgument3,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                           C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                    GALGAS_impType & outArgument1,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                     GALGAS_objectsMap & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public : virtual void nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                                const GALGAS_dataType inArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public : virtual void nt_multiple_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public : virtual void nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               const GALGAS_dataType inArgument2,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public : virtual void nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                          GALGAS_objectsMap & ioArgument1,
                                                          GALGAS_string & ioArgument2,
                                                          const GALGAS_bool inArgument3,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public : virtual void nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                                GALGAS_objectAttributes & ioArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public : virtual void nt_range_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                   const GALGAS_dataType inArgument1,
                                   C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public : virtual void nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                              const GALGAS_dataType inArgument1,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public : virtual void nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                             const GALGAS_dataType inArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public : virtual void nt_sign_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public : virtual void nt_start_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_start_ (C_Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public : virtual void nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public : virtual void nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public : virtual void nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             const GALGAS_dataType inArgument2,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public : virtual void nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

  public : virtual int32_t select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithBool'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithBool (const class GALGAS_bool & constinArgument0,
                                            const class GALGAS_lstring & constinArgument1,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'valueWithStruct'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithStruct (const class GALGAS_TfieldMap & constinArgument0,
                                              const class GALGAS_lstring & constinArgument1,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addBoolValue'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addBoolValue (class GALGAS_TfieldMap & ioArgument0,
                           const class GALGAS_lstring constinArgument1,
                           const class GALGAS_bool constinArgument2,
                           const class GALGAS_lstring constinArgument3,
                           class C_Compiler * inCompiler
                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addSignedValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addSignedValue (class GALGAS_TfieldMap & ioArgument0,
                             const class GALGAS_lstring constinArgument1,
                             const class GALGAS_sint_36__34_ constinArgument2,
                             const class GALGAS_lstring constinArgument3,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addFloatValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addFloatValue (class GALGAS_TfieldMap & ioArgument0,
                            const class GALGAS_lstring constinArgument1,
                            const class GALGAS_double constinArgument2,
                            const class GALGAS_lstring constinArgument3,
                            class C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'addLUnsignedValue'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addLUnsignedValue (class GALGAS_TfieldMap & ioArgument0,
                                const class GALGAS_string constinArgument1,
                                const class GALGAS_luint_36__34_ constinArgument2,
                                const class GALGAS_lstring constinArgument3,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addStringValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addStringValue (class GALGAS_TfieldMap & ioArgument0,
                             const class GALGAS_lstring constinArgument1,
                             const class GALGAS_string constinArgument2,
                             const class GALGAS_lstring constinArgument3,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addListValue'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addListValue (class GALGAS_TfieldMap & ioArgument0,
                           const class GALGAS_lstring constinArgument1,
                           const class GALGAS_TfieldMapList constinArgument2,
                           const class GALGAS_lstring constinArgument3,
                           class C_Compiler * inCompiler
                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addStructValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addStructValue (class GALGAS_TfieldMap & ioArgument0,
                             const class GALGAS_lstring constinArgument1,
                             const class GALGAS_TfieldMap constinArgument2,
                             const class GALGAS_lstring constinArgument3,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addEnumValue'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addEnumValue (class GALGAS_TfieldMap & ioArgument0,
                           const class GALGAS_lstring constinArgument1,
                           const class GALGAS_string constinArgument2,
                           const class GALGAS_lstring constinArgument3,
                           class C_Compiler * inCompiler
                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'substraction_types_checkForTemplate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_substraction_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                        const class GALGAS_Ttype constinArgument1,
                                                        class GALGAS_Ttype & outArgument2,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'argumentListSignature'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_argumentListSignature (const class GALGAS_TexpressionList & constinArgument0,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'checkInvocationHasNoArgument'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkInvocationHasNoArgument (const class GALGAS_Ttype constinArgument0,
                                           const class GALGAS_lstring constinArgument1,
                                           const class GALGAS_TexpressionList constinArgument2,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'checkInvocationHasArguments'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkInvocationHasArguments (const class GALGAS_Ttype constinArgument0,
                                          const class GALGAS_lstring constinArgument1,
                                          const class GALGAS_TexpressionList constinArgument2,
                                          const class GALGAS_Ttype constinArgument3,
                                          const class GALGAS_uint constinArgument4,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'structCompare'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint function_structCompare (const class GALGAS_TfieldMap & constinArgument0,
                                          const class GALGAS_TfieldMap & constinArgument1,
                                          class GALGAS_sortingKeyList inArgument2,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Routine 'swap'                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_swap (class GALGAS_TfieldMapList & ioArgument0,
                   const class GALGAS_uint constinArgument1,
                   const class GALGAS_uint constinArgument2,
                   class C_Compiler * inCompiler
                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'partition'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_partition (class GALGAS_TfieldMapList & ioArgument0,
                        class GALGAS_uint inArgument1,
                        class GALGAS_uint inArgument2,
                        const class GALGAS_sortingKeyList constinArgument3,
                        class GALGAS_uint & ioArgument4,
                        class C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'allowedFunctions'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringset function_allowedFunctions (class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'displayTypeAndValue'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_displayTypeAndValue (const class GALGAS_Ttype & constinArgument0,
                                                  const class GALGAS_Tvalue & constinArgument1,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

#endif

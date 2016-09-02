#ifndef all_2D_declarations_2D__35__ENTITIES_DEFINED
#define all_2D_declarations_2D__35__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-4.h"

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR options_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_options_5F_grammar : public cParser_options_5F_parser {
//------------------------------------- 'list_option_value' non terminal
//--- 'parse' label
  public : virtual void nt_list_5F_option_5F_value_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_list_5F_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                                     C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_item' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_item_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_item_ (GALGAS_gtlData & ioArgument0,
                                            C_Lexique_options_5F_scanner * inCompiler) ;

//------------------------------------- 'option_parser_start' non terminal
//--- 'parse' label
  public : virtual void nt_option_5F_parser_5F_start_parse (C_Lexique_options_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_option_5F_parser_5F_start_ (GALGAS_gtlData & outArgument0,
                                                       C_Lexique_options_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_gtlData & outArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_gtlData & outArgument0
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
  public : virtual void nt_option_5F_value_ (GALGAS_gtlData & outArgument0,
                                             C_Lexique_options_5F_scanner * inCompiler) ;

  public : virtual int32_t select_options_5F_parser_0 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_1 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_2 (C_Lexique_options_5F_scanner *) ;

  public : virtual int32_t select_options_5F_parser_3 (C_Lexique_options_5F_scanner *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext addModulePath'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlContext_addModulePath) (class cPtr_gtlContext * inObject,
                                                                   const class GALGAS_string constinArgument0,
                                                                   const class GALGAS_string constinArgument1,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addModulePath (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_addModulePath inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_addModulePath (class cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_rootPath,
                                        const GALGAS_string constin_modulePath,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext addInputVariable'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlContext_addInputVariable) (class cPtr_gtlContext * inObject,
                                                                      class GALGAS_gtlData inArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addInputVariable (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_addInputVariable inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_addInputVariable (class cPtr_gtlContext * inObject,
                                           GALGAS_gtlData in_inputVariable,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext popFirstInputArg'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_gtlContext_popFirstInputArg) (class cPtr_gtlContext * inObject,
                                                                      class GALGAS_location inArgument0,
                                                                      class GALGAS_gtlData & outArgument1,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_popFirstInputArg (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_popFirstInputArg inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_popFirstInputArg (class cPtr_gtlContext * inObject,
                                           GALGAS_location in_where,
                                           GALGAS_gtlData & out_result,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlContext fullPrefix'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlContext_fullPrefix) (const class cPtr_gtlContext * inObject,
                                                                            const class GALGAS_gtlData & constinArgument0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fullPrefix (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlContext_fullPrefix inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_fullPrefix (const cPtr_gtlContext * inObject,
                                                     const GALGAS_gtlData & constin_vars,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension getter '@gtlContext fullTemplateFileName'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlContext_fullTemplateFileName) (const class cPtr_gtlContext * inObject,
                                                                                      class GALGAS_gtlContext inArgument0,
                                                                                      class GALGAS_gtlData inArgument1,
                                                                                      class GALGAS_lstring inArgument2,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fullTemplateFileName (const int32_t inClassIndex,
                                                enterExtensionGetter_gtlContext_fullTemplateFileName inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                               GALGAS_gtlContext in_context,
                                                               GALGAS_gtlData in_vars,
                                                               GALGAS_lstring in_simpleName,
                                                               class C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'pathWithExtension'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_pathWithExtension (class GALGAS_gtlContext inArgument0,
                                                class GALGAS_string inArgument1,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Parser class 'gtl_module_parser' declaration                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_gtl_5F_module_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_gtl_5F_module_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_gtl_5F_argument_5F_list_ (class GALGAS_gtlArgumentList & outArgument0,
                                                        class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_argument_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                  class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_function_ (class GALGAS_gtlFunction & outArgument0,
                                                class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_function_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_getter_ (class GALGAS_gtlGetter & outArgument0,
                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_getter_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_import_ (class GALGAS_gtlContext inArgument0,
                                              class GALGAS_library & ioArgument1,
                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_import_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                   class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_instruction_5F_list_ (class GALGAS_gtlInstructionList & outArgument0,
                                                           class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_instruction_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_module_5F_start_5F_symbol_ (class GALGAS_gtlContext inArgument0,
                                                                 class GALGAS_library & ioArgument1,
                                                                 class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_module_5F_start_5F_symbol_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_setter_ (class GALGAS_gtlSetter & outArgument0,
                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_setter_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_simple_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_simple_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_ (GALGAS_gtlInstructionList & outArgument0,
                                                                                C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_ (GALGAS_gtlContext inArgument0,
                                                                                      GALGAS_library & ioArgument1,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_ (GALGAS_gtlFunction & outArgument0,
                                                                     C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_ (GALGAS_gtlGetter & outArgument0,
                                                                   C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_ (GALGAS_gtlSetter & outArgument0,
                                                                   C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_gtl_5F_module_5F_parser_0 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_1 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_2 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_3 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_4 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_5 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_6 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_7 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_8 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_9 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_10 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_11 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_12 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_13 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_14 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_15 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_16 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_module_5F_parser_17 (C_Lexique_gtl_5F_scanner *) = 0 ;


} ;

#endif

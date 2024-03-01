#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-6.h"

//--------------------------------------------------------------------------------------------------
//  GRAMMAR gtl_module_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_gtl_5F_module_5F_grammar : public cParser_gtl_5F_module_5F_parser,
                                          public cParser_gtl_5F_instruction_5F_parser,
                                          public cParser_gtl_5F_expression_5F_parser {
//------------------------------------- 'gtl_argument_list' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_argument_5F_list_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_argument_5F_list_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & outArgument0,
                                                    Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_expression' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_expression_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_expression_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                              Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_factor' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_factor_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_factor_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                          Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_function' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_function_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_function_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_function_ (GALGAS_gtlFunction & outArgument0,
                                            Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_getter' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_getter_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_getter_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_getter_ (GALGAS_gtlGetter & outArgument0,
                                          Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_import' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_import_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_import_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_import_ (GALGAS_gtlContext inArgument0,
                                          GALGAS_library & ioArgument1,
                                          Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_instruction' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_instruction_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_instruction_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_instruction_ (GALGAS_gtlInstruction & outArgument0,
                                               Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_instruction_list' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_instruction_5F_list_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_instruction_5F_list_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_instruction_5F_list_ (GALGAS_gtlInstructionList & outArgument0,
                                                       Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_module_start_symbol' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_module_5F_start_5F_symbol_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_module_5F_start_5F_symbol_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_module_5F_start_5F_symbol_ (GALGAS_gtlContext inArgument0,
                                                             GALGAS_library & ioArgument1,
                                                             Lexique_gtl_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_gtlContext inArgument0,
                                                  GALGAS_library & ioArgument1
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_gtlContext inArgument0,
                                                    GALGAS_library & ioArgument1
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

//------------------------------------- 'gtl_relation_factor' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_relation_5F_factor_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_relation_5F_factor_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                                      Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_relation_term' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_relation_5F_term_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_relation_5F_term_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                                    Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_setter' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_setter_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_setter_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_setter_ (GALGAS_gtlSetter & outArgument0,
                                          Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_expression' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_simple_5F_expression_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_simple_5F_expression_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                                        Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_instruction' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_simple_5F_instruction_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_simple_5F_instruction_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_simple_5F_instruction_ (GALGAS_gtlInstruction & outArgument0,
                                                         Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_sorting_order' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_sorting_5F_order_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_sorting_5F_order_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_sorting_5F_order_ (GALGAS_lsint & outArgument0,
                                                    Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_term' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_term_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_term_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                        Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_variable_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_variable_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_variable_ (GALGAS_gtlVarPath & outArgument0,
                                            Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable_or_here' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_variable_5F_or_5F_here_indexing (Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & outArgument0,
                                                          GALGAS_bool & outArgument1,
                                                          Lexique_gtl_5F_scanner * inCompiler) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_0 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_1 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_2 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_3 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_4 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_5 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_6 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_7 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_8 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_9 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_10 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_11 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_12 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_13 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_14 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_15 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_16 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_module_5F_parser_17 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_0 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_1 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_2 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_3 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_4 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_5 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_6 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_0 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_1 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_2 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_3 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_4 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_5 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_6 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_7 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_8 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_9 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_10 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_11 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_12 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_13 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_14 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_15 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_16 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_17 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_18 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_19 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_20 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_21 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_22 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_23 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_24 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_25 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_26 (Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_27 (Lexique_gtl_5F_scanner *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext appendInstructionToStepDo'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_appendInstructionToStepDo) (class cPtr_gtlContext * inObject,
                                                                               class GALGAS_gtlInstruction inArgument0,
                                                                               class Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_appendInstructionToStepDo (const int32_t inClassIndex,
                                                     extensionSetterSignature_gtlContext_appendInstructionToStepDo inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_appendInstructionToStepDo (class cPtr_gtlContext * inObject,
                                                    GALGAS_gtlInstruction in_instruction,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext deleteStepDoInstruction'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_deleteStepDoInstruction) (class cPtr_gtlContext * inObject,
                                                                             const class GALGAS_lbigint constinArgument0,
                                                                             class Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteStepDoInstruction (const int32_t inClassIndex,
                                                   extensionSetterSignature_gtlContext_deleteStepDoInstruction inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteStepDoInstruction (class cPtr_gtlContext * inObject,
                                                  const GALGAS_lbigint constin_numToDelete,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext deleteAllStepDoInstructions'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_deleteAllStepDoInstructions) (class cPtr_gtlContext * inObject,
                                                                                 class Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllStepDoInstructions (const int32_t inClassIndex,
                                                       extensionSetterSignature_gtlContext_deleteAllStepDoInstructions inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllStepDoInstructions (class cPtr_gtlContext * inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlContext listStepDoInstructions'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_listStepDoInstructions (class cPtr_gtlContext * inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setBreakpoint'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setBreakpoint) (class cPtr_gtlContext * inObject,
                                                                   const class GALGAS_string constinArgument0,
                                                                   const class GALGAS_uint constinArgument1,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setBreakpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_setBreakpoint inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setBreakpoint (class cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_fileName,
                                        const GALGAS_uint constin_lineNum,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlContext listBreakpoints'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_listBreakpoints (class cPtr_gtlContext * inObject,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext deleteBreakpoint'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_deleteBreakpoint) (class cPtr_gtlContext * inObject,
                                                                      const class GALGAS_lbigint constinArgument0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteBreakpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_deleteBreakpoint inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteBreakpoint (class cPtr_gtlContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext deleteAllBreakpoints'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_deleteAllBreakpoints) (class cPtr_gtlContext * inObject,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllBreakpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_gtlContext_deleteAllBreakpoints inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllBreakpoints (class cPtr_gtlContext * inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setWatchpoint'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setWatchpoint) (class cPtr_gtlContext * inObject,
                                                                   const class GALGAS_gtlExpression constinArgument0,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setWatchpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_setWatchpoint inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setWatchpoint (class cPtr_gtlContext * inObject,
                                        const GALGAS_gtlExpression constin_watchExpression,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlContext listWatchpoints'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_listWatchpoints (class cPtr_gtlContext * inObject,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext deleteWatchpoint'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_deleteWatchpoint) (class cPtr_gtlContext * inObject,
                                                                      const class GALGAS_lbigint constinArgument0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteWatchpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_deleteWatchpoint inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteWatchpoint (class cPtr_gtlContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext deleteAllWatchpoints'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_deleteAllWatchpoints) (class cPtr_gtlContext * inObject,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteAllWatchpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_gtlContext_deleteAllWatchpoints inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteAllWatchpoints (class cPtr_gtlContext * inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@gtlContext hereWeAre'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_hereWeAre (class cPtr_gtlContext * inObject,
                                    const class GALGAS_uint constin_window,
                                    Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setExecuteDebuggerCommand'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setExecuteDebuggerCommand) (class cPtr_gtlContext * inObject,
                                                                               class GALGAS_bool inArgument0,
                                                                               class Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setExecuteDebuggerCommand (const int32_t inClassIndex,
                                                     extensionSetterSignature_gtlContext_setExecuteDebuggerCommand inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setExecuteDebuggerCommand (class cPtr_gtlContext * inObject,
                                                    GALGAS_bool in_debuggerCommand,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'arch'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_arch (class Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'board'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_board (class Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'chip'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_chip (class Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'projectName'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_projectName (class Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'targetPathList'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_list function_targetPathList (class Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @goilContext  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_goilContext : public GALGAS_gtlContext {
//--------------------------------- Default constructor
  public: GALGAS_goilContext (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_goilContext * ptr (void) const {
    return (const cPtr_goilContext *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_goilContext (const cPtr_goilContext * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_goilContext extractObject (const GALGAS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_goilContext class_func_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_string & inOperand1,
                                                          const class GALGAS_string & inOperand2,
                                                          const class GALGAS_string & inOperand3,
                                                          const class GALGAS_string & inOperand4,
                                                          const class GALGAS_stringlist & inOperand5,
                                                          const class GALGAS_gtlDataList & inOperand6,
                                                          const class GALGAS_bool & inOperand7,
                                                          const class GALGAS_debuggerContext & inOperand8
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_goilContext & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_goilContext class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_goilContext ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @goilContext class
//
//--------------------------------------------------------------------------------------------------

class cPtr_goilContext : public cPtr_gtlContext {

//--- Extension getter fullPrefix
  public: virtual class GALGAS_lstring getter_fullPrefix (const class GALGAS_gtlData vars,
           Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_goilContext (const GALGAS_lstring & in_prefix,
                            const GALGAS_string & in_path,
                            const GALGAS_string & in_templateDirectory,
                            const GALGAS_string & in_userTemplateDirectory,
                            const GALGAS_string & in_templateExtension,
                            const GALGAS_stringlist & in_importPath,
                            const GALGAS_gtlDataList & in_inputVars,
                            const GALGAS_bool & in_propagateError,
                            const GALGAS_debuggerContext & in_debuggerContext
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_grammar : public cParser_goil_5F_syntax,
                                 public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_item_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_item_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_attribute_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_attribute_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                          Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_object_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_object_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_objects_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_objects_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_type_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_type_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                   GALGAS_impType & outArgument1,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_implementation_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_implementation_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_type_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_type_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public: virtual void nt_int_5F_or_5F_float_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_int_5F_or_5F_float_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                               const GALGAS_dataType inArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public: virtual void nt_multiple_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_multiple_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public: virtual void nt_number_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_number_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              const GALGAS_dataType inArgument2,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public: virtual void nt_objref_5F_option_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_objref_5F_option_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public: virtual void nt_range_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                  const GALGAS_dataType inArgument1,
                                  Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public: virtual void nt_range_5F_content_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_5F_content_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                             const GALGAS_dataType inArgument1,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public: virtual void nt_set_5F_followup_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_set_5F_followup_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                            const GALGAS_dataType inArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString
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

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public: virtual void nt_string_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_string_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public: virtual void nt_struct_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_struct_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public: virtual void nt_type_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_type_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            const GALGAS_dataType inArgument2,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public: virtual void nt_with_5F_auto_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_with_5F_auto_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_19 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_20 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_21 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_22 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_23 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_24 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_25 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_26 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_27 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_28 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_29 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_30 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//  GRAMMAR arxml_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_arxml_5F_grammar : public cParser_arxml_5F_parser {
//------------------------------------- 'arxml_start_symbol' non terminal
//--- 'parse' label
  public: virtual void nt_arxml_5F_start_5F_symbol_parse (Lexique_arxml_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_arxml_5F_start_5F_symbol_indexing (Lexique_arxml_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_arxml_5F_start_5F_symbol_ (GALGAS_arxmlNode & outArgument0,
                                                     const GALGAS_bool inArgument1,
                                                     const GALGAS_bool inArgument2,
                                                     Lexique_arxml_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_arxmlNode & outArgument0,
                                                  const GALGAS_bool inArgument1,
                                                  const GALGAS_bool inArgument2
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_arxmlNode & outArgument0,
                                                    const GALGAS_bool inArgument1,
                                                    const GALGAS_bool inArgument2
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

//------------------------------------- 'element' non terminal
//--- 'parse' label
  public: virtual void nt_element_parse (Lexique_arxml_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_element_indexing (Lexique_arxml_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_element_ (GALGAS_arxmlNodeList & ioArgument0,
                                    const GALGAS_bool inArgument1,
                                    const GALGAS_bool inArgument2,
                                    Lexique_arxml_5F_scanner * inCompiler) ;

//------------------------------------- 'element_list' non terminal
//--- 'parse' label
  public: virtual void nt_element_5F_list_parse (Lexique_arxml_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_element_5F_list_indexing (Lexique_arxml_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_element_5F_list_ (GALGAS_arxmlNodeList & ioArgument0,
                                            const GALGAS_bool inArgument1,
                                            const GALGAS_bool inArgument2,
                                            Lexique_arxml_5F_scanner * inCompiler) ;

  public: virtual int32_t select_arxml_5F_parser_0 (Lexique_arxml_5F_scanner *) ;

  public: virtual int32_t select_arxml_5F_parser_1 (Lexique_arxml_5F_scanner *) ;

  public: virtual int32_t select_arxml_5F_parser_2 (Lexique_arxml_5F_scanner *) ;

  public: virtual int32_t select_arxml_5F_parser_3 (Lexique_arxml_5F_scanner *) ;
} ;

//--------------------------------------------------------------------------------------------------

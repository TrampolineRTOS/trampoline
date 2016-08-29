#ifndef all_2D_declarations_2D__32__ENTITIES_DEFINED
#define all_2D_declarations_2D__32__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @debuggerContext class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_debuggerContext : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_debuggerContext (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_debuggerContext constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_debuggerContext * ptr (void) const { return (const cPtr_debuggerContext *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_debuggerContext (const cPtr_debuggerContext * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_debuggerContext extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_debuggerContext constructor_new (const class GALGAS_bool & inOperand0,
                                                                const class GALGAS_bool & inOperand1,
                                                                const class GALGAS_bool & inOperand2,
                                                                const class GALGAS_string & inOperand3,
                                                                const class GALGAS_string & inOperand4,
                                                                const class GALGAS_string & inOperand5,
                                                                const class GALGAS_string & inOperand6,
                                                                const class GALGAS_string & inOperand7,
                                                                const class GALGAS_string & inOperand8,
                                                                const class GALGAS_string & inOperand9,
                                                                const class GALGAS_string & inOperand10,
                                                                const class GALGAS_gtlInstructionList & inOperand11
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_debuggerContext & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setBreakOnNext (class GALGAS_bool inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setDebugActive (class GALGAS_bool inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setInstructionColor (class GALGAS_string inArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setInstructionFace (class GALGAS_string inArgument0
                                                            COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setLoopOnCommand (class GALGAS_bool inArgument0
                                                          COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setOutputColor (class GALGAS_string inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setOutputFace (class GALGAS_string inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setPromptColor (class GALGAS_string inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setPromptFace (class GALGAS_string inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setWarningColor (class GALGAS_string inArgument0
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setWarningFace (class GALGAS_string inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_breakOnNext (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_debugActive (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_instructionColor (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_instructionFace (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_loopOnCommand (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_outputColor (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_outputFace (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_promptColor (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_promptFace (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_warningColor (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_warningFace (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_debuggerContext class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_debuggerContext ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @debuggerContext class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_debuggerContext : public acPtr_class {
//--- Attributes
  public : GALGAS_bool mAttribute_debugActive ;
  public : GALGAS_bool mAttribute_breakOnNext ;
  public : GALGAS_bool mAttribute_loopOnCommand ;
  public : GALGAS_string mAttribute_promptColor ;
  public : GALGAS_string mAttribute_promptFace ;
  public : GALGAS_string mAttribute_instructionColor ;
  public : GALGAS_string mAttribute_instructionFace ;
  public : GALGAS_string mAttribute_outputColor ;
  public : GALGAS_string mAttribute_outputFace ;
  public : GALGAS_string mAttribute_warningColor ;
  public : GALGAS_string mAttribute_warningFace ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_debuggerContext (const GALGAS_bool & in_debugActive,
                                 const GALGAS_bool & in_breakOnNext,
                                 const GALGAS_bool & in_loopOnCommand,
                                 const GALGAS_string & in_promptColor,
                                 const GALGAS_string & in_promptFace,
                                 const GALGAS_string & in_instructionColor,
                                 const GALGAS_string & in_instructionFace,
                                 const GALGAS_string & in_outputColor,
                                 const GALGAS_string & in_outputFace,
                                 const GALGAS_string & in_warningColor,
                                 const GALGAS_string & in_warningFace,
                                 const GALGAS_gtlInstructionList & in_doList
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_debugActive (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setDebugActive (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_breakOnNext (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setBreakOnNext (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_loopOnCommand (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setLoopOnCommand (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_promptColor (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setPromptColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_promptFace (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setPromptFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_instructionColor (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setInstructionColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_instructionFace (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setInstructionFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_outputColor (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setOutputColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_outputFace (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setOutputFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_warningColor (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setWarningColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_warningFace (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setWarningFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlContext class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlContext : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_gtlContext (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlContext constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlContext * ptr (void) const { return (const cPtr_gtlContext *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlContext (const cPtr_gtlContext * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlContext extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlContext constructor_new (const class GALGAS_lstring & inOperand0,
                                                           const class GALGAS_string & inOperand1,
                                                           const class GALGAS_string & inOperand2,
                                                           const class GALGAS_string & inOperand3,
                                                           const class GALGAS_stringlist & inOperand4,
                                                           const class GALGAS_gtlDataList & inOperand5,
                                                           const class GALGAS_debuggerContext & inOperand6
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlContext & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setDebuggerContext (class GALGAS_debuggerContext inArgument0
                                                            COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setInputVars (class GALGAS_gtlDataList inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setPath (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setPrefix (class GALGAS_lstring inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setTemplateDirectory (class GALGAS_string inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setTemplateExtension (class GALGAS_string inArgument0
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_debuggerContext getter_debuggerContext (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_importPath (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlDataList getter_inputVars (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_path (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_templateDirectory (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_templateExtension (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlContext class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlContext ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlContext class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlContext : public acPtr_class {
//--- Attributes
  public : GALGAS_lstring mAttribute_prefix ;
  public : GALGAS_string mAttribute_path ;
  public : GALGAS_string mAttribute_templateDirectory ;
  public : GALGAS_string mAttribute_templateExtension ;
  public : GALGAS_stringlist mAttribute_importPath ;
  public : GALGAS_gtlDataList mAttribute_inputVars ;
  public : GALGAS_debuggerContext mAttribute_debuggerContext ;

//--- Constructor
  public : cPtr_gtlContext (const GALGAS_lstring & in_prefix,
                            const GALGAS_string & in_path,
                            const GALGAS_string & in_templateDirectory,
                            const GALGAS_string & in_templateExtension,
                            const GALGAS_stringlist & in_importPath,
                            const GALGAS_gtlDataList & in_inputVars,
                            const GALGAS_debuggerContext & in_debuggerContext
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setPrefix (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_path (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setPath (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_templateDirectory (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setTemplateDirectory (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_templateExtension (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setTemplateExtension (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_stringlist getter_importPath (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlDataList getter_inputVars (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setInputVars (GALGAS_gtlDataList inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_debuggerContext getter_debuggerContext (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setDebuggerContext (GALGAS_debuggerContext inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlForStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlForStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlForStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlForStatementInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlForStatementInstruction * ptr (void) const { return (const cPtr_gtlForStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlForStatementInstruction (const cPtr_gtlForStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlForStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlForStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                           const class GALGAS_string & inOperand1,
                                                                           const class GALGAS_lstring & inOperand2,
                                                                           const class GALGAS_gtlExpressionList & inOperand3,
                                                                           const class GALGAS_gtlInstructionList & inOperand4,
                                                                           const class GALGAS_gtlInstructionList & inOperand5
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlForStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_iterable (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlForStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlForStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlForStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_identifier ;
  public : GALGAS_gtlExpressionList mAttribute_iterable ;
  public : GALGAS_gtlInstructionList mAttribute_betweenList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlForStatementInstruction (const GALGAS_location & in_where,
                                            const GALGAS_string & in_signature,
                                            const GALGAS_lstring & in_identifier,
                                            const GALGAS_gtlExpressionList & in_iterable,
                                            const GALGAS_gtlInstructionList & in_betweenList,
                                            const GALGAS_gtlInstructionList & in_doList
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_iterable (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlForeachStatementInstruction class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlForeachStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlForeachStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlForeachStatementInstruction * ptr (void) const { return (const cPtr_gtlForeachStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlForeachStatementInstruction (const cPtr_gtlForeachStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlForeachStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlForeachStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                               const class GALGAS_string & inOperand1,
                                                                               const class GALGAS_lstring & inOperand2,
                                                                               const class GALGAS_lstring & inOperand3,
                                                                               const class GALGAS_lstring & inOperand4,
                                                                               const class GALGAS_gtlExpression & inOperand5,
                                                                               const class GALGAS_gtlInstructionList & inOperand6,
                                                                               const class GALGAS_gtlInstructionList & inOperand7,
                                                                               const class GALGAS_gtlInstructionList & inOperand8,
                                                                               const class GALGAS_gtlInstructionList & inOperand9
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlForeachStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_indexName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_iterable (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_keyName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_variableName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlForeachStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlForeachStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Pointer class for @gtlForeachStatementInstruction class                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlForeachStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_keyName ;
  public : GALGAS_lstring mAttribute_variableName ;
  public : GALGAS_lstring mAttribute_indexName ;
  public : GALGAS_gtlExpression mAttribute_iterable ;
  public : GALGAS_gtlInstructionList mAttribute_beforeList ;
  public : GALGAS_gtlInstructionList mAttribute_betweenList ;
  public : GALGAS_gtlInstructionList mAttribute_afterList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlForeachStatementInstruction (const GALGAS_location & in_where,
                                                const GALGAS_string & in_signature,
                                                const GALGAS_lstring & in_keyName,
                                                const GALGAS_lstring & in_variableName,
                                                const GALGAS_lstring & in_indexName,
                                                const GALGAS_gtlExpression & in_iterable,
                                                const GALGAS_gtlInstructionList & in_beforeList,
                                                const GALGAS_gtlInstructionList & in_betweenList,
                                                const GALGAS_gtlInstructionList & in_afterList,
                                                const GALGAS_gtlInstructionList & in_doList
                                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_keyName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_variableName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_indexName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_iterable (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlGetter class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlGetter : public cPtr_gtlFunction {
//--- Attributes
  public : GALGAS_type mAttribute_targetType ;

//--- Constructor
  public : cPtr_gtlGetter (const GALGAS_location & in_where,
                           const GALGAS_lstring & in_name,
                           const GALGAS_gtlArgumentList & in_formalArguments,
                           const GALGAS_gtlInstructionList & in_instructions,
                           const GALGAS_lstring & in_returnVariable,
                           const GALGAS_type & in_targetType
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlIfStatementInstruction class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlIfStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlIfStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlIfStatementInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlIfStatementInstruction * ptr (void) const { return (const cPtr_gtlIfStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlIfStatementInstruction (const cPtr_gtlIfStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlIfStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlIfStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                          const class GALGAS_string & inOperand1,
                                                                          const class GALGAS_gtlThenElsifStatementList & inOperand2,
                                                                          const class GALGAS_gtlInstructionList & inOperand3
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlIfStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_elseList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlThenElsifStatementList getter_thenElsifList (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlIfStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlIfStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlIfStatementInstruction class                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlIfStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlThenElsifStatementList mAttribute_thenElsifList ;
  public : GALGAS_gtlInstructionList mAttribute_elseList ;

//--- Constructor
  public : cPtr_gtlIfStatementInstruction (const GALGAS_location & in_where,
                                           const GALGAS_string & in_signature,
                                           const GALGAS_gtlThenElsifStatementList & in_thenElsifList,
                                           const GALGAS_gtlInstructionList & in_elseList
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlThenElsifStatementList getter_thenElsifList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_elseList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlLoopStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlLoopStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlLoopStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlLoopStatementInstruction * ptr (void) const { return (const cPtr_gtlLoopStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlLoopStatementInstruction (const cPtr_gtlLoopStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlLoopStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlLoopStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_lstring & inOperand2,
                                                                            const class GALGAS_gtlExpression & inOperand3,
                                                                            const class GALGAS_gtlExpression & inOperand4,
                                                                            const class GALGAS_gtlExpression & inOperand5,
                                                                            const class GALGAS_sint_36__34_ & inOperand6,
                                                                            const class GALGAS_gtlInstructionList & inOperand7,
                                                                            const class GALGAS_gtlInstructionList & inOperand8,
                                                                            const class GALGAS_gtlInstructionList & inOperand9,
                                                                            const class GALGAS_gtlInstructionList & inOperand10
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlLoopStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_start (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_step (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_stop (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_upDown (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlLoopStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLoopStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlLoopStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlLoopStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_identifier ;
  public : GALGAS_gtlExpression mAttribute_start ;
  public : GALGAS_gtlExpression mAttribute_stop ;
  public : GALGAS_gtlExpression mAttribute_step ;
  public : GALGAS_sint_36__34_ mAttribute_upDown ;
  public : GALGAS_gtlInstructionList mAttribute_beforeList ;
  public : GALGAS_gtlInstructionList mAttribute_betweenList ;
  public : GALGAS_gtlInstructionList mAttribute_afterList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlLoopStatementInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_lstring & in_identifier,
                                             const GALGAS_gtlExpression & in_start,
                                             const GALGAS_gtlExpression & in_stop,
                                             const GALGAS_gtlExpression & in_step,
                                             const GALGAS_sint_36__34_ & in_upDown,
                                             const GALGAS_gtlInstructionList & in_beforeList,
                                             const GALGAS_gtlInstructionList & in_betweenList,
                                             const GALGAS_gtlInstructionList & in_afterList,
                                             const GALGAS_gtlInstructionList & in_doList
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_start (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_stop (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_step (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ getter_upDown (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_beforeList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_betweenList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_afterList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlRepeatStatementInstruction class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlRepeatStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlRepeatStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlRepeatStatementInstruction * ptr (void) const { return (const cPtr_gtlRepeatStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlRepeatStatementInstruction (const cPtr_gtlRepeatStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlRepeatStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlRepeatStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                              const class GALGAS_string & inOperand1,
                                                                              const class GALGAS_gtlExpression & inOperand2,
                                                                              const class GALGAS_gtlExpression & inOperand3,
                                                                              const class GALGAS_gtlInstructionList & inOperand4,
                                                                              const class GALGAS_gtlInstructionList & inOperand5
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlRepeatStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_condition (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_continueList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_limit (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlRepeatStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlRepeatStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Pointer class for @gtlRepeatStatementInstruction class                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlRepeatStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_limit ;
  public : GALGAS_gtlExpression mAttribute_condition ;
  public : GALGAS_gtlInstructionList mAttribute_continueList ;
  public : GALGAS_gtlInstructionList mAttribute_doList ;

//--- Constructor
  public : cPtr_gtlRepeatStatementInstruction (const GALGAS_location & in_where,
                                               const GALGAS_string & in_signature,
                                               const GALGAS_gtlExpression & in_limit,
                                               const GALGAS_gtlExpression & in_condition,
                                               const GALGAS_gtlInstructionList & in_continueList,
                                               const GALGAS_gtlInstructionList & in_doList
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_limit (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_condition (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_continueList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @gtlSetter class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSetter : public cPtr_gtlExecutableEntity {
//--- Attributes
  public : GALGAS_type mAttribute_targetType ;

//--- Constructor
  public : cPtr_gtlSetter (const GALGAS_location & in_where,
                           const GALGAS_lstring & in_name,
                           const GALGAS_gtlArgumentList & in_formalArguments,
                           const GALGAS_gtlInstructionList & in_instructions,
                           const GALGAS_type & in_targetType
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @library class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_library : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_library (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_library constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_library * ptr (void) const { return (const cPtr_library *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_library (const cPtr_library * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_library extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_library constructor_new (const class GALGAS_gtlFuncMap & inOperand0,
                                                        const class GALGAS_gtlGetterMap & inOperand1,
                                                        const class GALGAS_gtlSetterMap & inOperand2,
                                                        const class GALGAS_gtlTemplateMap & inOperand3,
                                                        const class GALGAS_stringset & inOperand4
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_library & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_stringset getter_doneImports (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlFuncMap getter_funcMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlGetterMap getter_getterMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlSetterMap getter_setterMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlTemplateMap getter_templateMap (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_library class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_library ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @library class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_library : public acPtr_class {
//--- Attributes
  public : GALGAS_gtlFuncMap mAttribute_funcMap ;
  public : GALGAS_gtlGetterMap mAttribute_getterMap ;
  public : GALGAS_gtlSetterMap mAttribute_setterMap ;
  public : GALGAS_gtlTemplateMap mAttribute_templateMap ;
  public : GALGAS_stringset mAttribute_doneImports ;

//--- Constructor
  public : cPtr_library (const GALGAS_gtlFuncMap & in_funcMap,
                         const GALGAS_gtlGetterMap & in_getterMap,
                         const GALGAS_gtlSetterMap & in_setterMap,
                         const GALGAS_gtlTemplateMap & in_templateMap,
                         const GALGAS_stringset & in_doneImports
                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlFuncMap getter_funcMap (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlGetterMap getter_getterMap (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlSetterMap getter_setterMap (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlTemplateMap getter_templateMap (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_stringset getter_doneImports (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'signature'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_signature (class GALGAS_location inArgument0,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlGetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlGetter_typedName) (const class cPtr_gtlGetter * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlGetter_typedName inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlGetter * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlSetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_lstring (*enterExtensionGetter_gtlSetter_typedName) (const class cPtr_gtlSetter * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlSetter_typedName inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlSetter * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library putFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_putFunction) (class cPtr_library * inObject,
                                                              const class GALGAS_lstring constinArgument0,
                                                              const class GALGAS_gtlFunction constinArgument1,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putFunction (class cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_putGetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlGetter constinArgument1,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putGetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_putSetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlSetter constinArgument1,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putSetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Parser class 'gtl_instruction_parser' declaration                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_gtl_5F_instruction_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_gtl_5F_instruction_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                  class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_import_ (class GALGAS_gtlContext inArgument0,
                                              class GALGAS_library & ioArgument1,
                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_import_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_simple_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_simple_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_sorting_5F_order_ (class GALGAS_lsint & outArgument0,
                                                        class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_sorting_5F_order_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                                class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_5F_or_5F_here_ (class GALGAS_gtlVarPath & outArgument0,
                                                              class GALGAS_bool & outArgument1,
                                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument0,
                                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument0,
                                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_ (GALGAS_lsint & outArgument0,
                                                                                   C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_ (GALGAS_gtlContext inArgument0,
                                                                         GALGAS_library & ioArgument1,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse (C_Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_0 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_1 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_2 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_3 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_4 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_5 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_instruction_5F_parser_6 (C_Lexique_gtl_5F_scanner *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlErrorStatementInstruction class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlErrorStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlErrorStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlErrorStatementInstruction * ptr (void) const { return (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlErrorStatementInstruction (const cPtr_gtlErrorStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlErrorStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlErrorStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                             const class GALGAS_string & inOperand1,
                                                                             const class GALGAS_gtlVarPath & inOperand2,
                                                                             const class GALGAS_bool & inOperand3,
                                                                             const class GALGAS_gtlExpression & inOperand4
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlErrorStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_errorMessage (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlErrorStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlErrorStatementInstruction class                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlErrorStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_identifier ;
  public : GALGAS_bool mAttribute_hereInstead ;
  public : GALGAS_gtlExpression mAttribute_errorMessage ;

//--- Constructor
  public : cPtr_gtlErrorStatementInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature,
                                              const GALGAS_gtlVarPath & in_identifier,
                                              const GALGAS_bool & in_hereInstead,
                                              const GALGAS_gtlExpression & in_errorMessage
                                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_errorMessage (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlLibrariesInstruction class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlLibrariesInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlLibrariesInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlLibrariesInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlLibrariesInstruction * ptr (void) const { return (const cPtr_gtlLibrariesInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlLibrariesInstruction (const cPtr_gtlLibrariesInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlLibrariesInstruction extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlLibrariesInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                        const class GALGAS_string & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlLibrariesInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlLibrariesInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLibrariesInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @gtlLibrariesInstruction class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlLibrariesInstruction : public cPtr_gtlInstruction {
//--- Attributes

//--- Constructor
  public : cPtr_gtlLibrariesInstruction (const GALGAS_location & in_where,
                                         const GALGAS_string & in_signature
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlSetterCallInstruction class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSetterCallInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlSetterCallInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlSetterCallInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlSetterCallInstruction * ptr (void) const { return (const cPtr_gtlSetterCallInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlSetterCallInstruction (const cPtr_gtlSetterCallInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlSetterCallInstruction extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlSetterCallInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                         const class GALGAS_string & inOperand1,
                                                                         const class GALGAS_gtlVarPath & inOperand2,
                                                                         const class GALGAS_lstring & inOperand3,
                                                                         const class GALGAS_gtlExpressionList & inOperand4
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlSetterCallInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_setterName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_target (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlSetterCallInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetterCallInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @gtlSetterCallInstruction class                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSetterCallInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_target ;
  public : GALGAS_lstring mAttribute_setterName ;
  public : GALGAS_gtlExpressionList mAttribute_arguments ;

//--- Constructor
  public : cPtr_gtlSetterCallInstruction (const GALGAS_location & in_where,
                                          const GALGAS_string & in_signature,
                                          const GALGAS_gtlVarPath & in_target,
                                          const GALGAS_lstring & in_setterName,
                                          const GALGAS_gtlExpressionList & in_arguments
                                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_target (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_setterName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlAbstractSortInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlAbstractSortInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlAbstractSortInstruction (void) ;

//---
  public : inline const class cPtr_gtlAbstractSortInstruction * ptr (void) const { return (const cPtr_gtlAbstractSortInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlAbstractSortInstruction (const cPtr_gtlAbstractSortInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlAbstractSortInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlAbstractSortInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_variablePath (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlAbstractSortInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAbstractSortInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlAbstractSortInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlAbstractSortInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_variablePath ;

//--- Constructor
  public : cPtr_gtlAbstractSortInstruction (const GALGAS_location & in_where,
                                            const GALGAS_string & in_signature,
                                            const GALGAS_gtlVarPath & in_variablePath
                                            COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_variablePath (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlSortStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSortStatementInstruction : public GALGAS_gtlAbstractSortInstruction {
//--- Constructor
  public : GALGAS_gtlSortStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlSortStatementInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlSortStatementInstruction * ptr (void) const { return (const cPtr_gtlSortStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlSortStatementInstruction (const cPtr_gtlSortStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlSortStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlSortStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_gtlVarPath & inOperand2,
                                                                            const class GALGAS_lsint & inOperand3
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlSortStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lsint getter_order (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlSortStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlSortStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSortStatementInstruction : public cPtr_gtlAbstractSortInstruction {
//--- Attributes
  public : GALGAS_lsint mAttribute_order ;

//--- Constructor
  public : cPtr_gtlSortStatementInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_gtlVarPath & in_variablePath,
                                             const GALGAS_lsint & in_order
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lsint getter_order (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @gtlSortStatementStructInstruction class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlSortStatementStructInstruction : public GALGAS_gtlAbstractSortInstruction {
//--- Constructor
  public : GALGAS_gtlSortStatementStructInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlSortStatementStructInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlSortStatementStructInstruction * ptr (void) const { return (const cPtr_gtlSortStatementStructInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlSortStatementStructInstruction (const cPtr_gtlSortStatementStructInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlSortStatementStructInstruction extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlSortStatementStructInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                                  const class GALGAS_string & inOperand1,
                                                                                  const class GALGAS_gtlVarPath & inOperand2,
                                                                                  const class GALGAS_sortingKeyList & inOperand3
                                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlSortStatementStructInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList getter_sortingKey (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlSortStatementStructInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Pointer class for @gtlSortStatementStructInstruction class                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlSortStatementStructInstruction : public cPtr_gtlAbstractSortInstruction {
//--- Attributes
  public : GALGAS_sortingKeyList mAttribute_sortingKey ;

//--- Constructor
  public : cPtr_gtlSortStatementStructInstruction (const GALGAS_location & in_where,
                                                   const GALGAS_string & in_signature,
                                                   const GALGAS_gtlVarPath & in_variablePath,
                                                   const GALGAS_sortingKeyList & in_sortingKey
                                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_sortingKeyList getter_sortingKey (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlTabStatementInstruction class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlTabStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlTabStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlTabStatementInstruction * ptr (void) const { return (const cPtr_gtlTabStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlTabStatementInstruction (const cPtr_gtlTabStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlTabStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlTabStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                           const class GALGAS_string & inOperand1,
                                                                           const class GALGAS_gtlExpression & inOperand2
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlTabStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_tabValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlTabStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTabStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Pointer class for @gtlTabStatementInstruction class                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTabStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_tabValue ;

//--- Constructor
  public : cPtr_gtlTabStatementInstruction (const GALGAS_location & in_where,
                                            const GALGAS_string & in_signature,
                                            const GALGAS_gtlExpression & in_tabValue
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_tabValue (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlWarningStatementInstruction class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlWarningStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlWarningStatementInstruction (void) ;

//---
  public : inline const class cPtr_gtlWarningStatementInstruction * ptr (void) const { return (const cPtr_gtlWarningStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlWarningStatementInstruction (const cPtr_gtlWarningStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlWarningStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlWarningStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                               const class GALGAS_string & inOperand1,
                                                                               const class GALGAS_gtlVarPath & inOperand2,
                                                                               const class GALGAS_bool & inOperand3,
                                                                               const class GALGAS_gtlExpression & inOperand4
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlWarningStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_warningMessage (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlWarningStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWarningStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Pointer class for @gtlWarningStatementInstruction class                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlWarningStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_identifier ;
  public : GALGAS_bool mAttribute_hereInstead ;
  public : GALGAS_gtlExpression mAttribute_warningMessage ;

//--- Constructor
  public : cPtr_gtlWarningStatementInstruction (const GALGAS_location & in_where,
                                                const GALGAS_string & in_signature,
                                                const GALGAS_gtlVarPath & in_identifier,
                                                const GALGAS_bool & in_hereInstead,
                                                const GALGAS_gtlExpression & in_warningMessage
                                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_identifier (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_hereInstead (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_warningMessage (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library hasImport'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*enterExtensionGetter_library_hasImport) (const class cPtr_library * inObject,
                                                                     const class GALGAS_string & constinArgument0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasImport (const int32_t inClassIndex,
                                     enterExtensionGetter_library_hasImport inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                                 const GALGAS_string & constin_importPath,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension getter '@string stringByAppendingPath' (as function)                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_stringByAppendingPath (const class GALGAS_string & inObject,
                                                           const class GALGAS_string & constinArgument0,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR gtl_module_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_gtl_5F_module_5F_grammar : public cParser_gtl_5F_module_5F_parser,
                                          public cParser_gtl_5F_instruction_5F_parser,
                                          public cParser_gtl_5F_expression_5F_parser {
//------------------------------------- 'gtl_argument_list' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_argument_5F_list_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & outArgument0,
                                                     C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_expression' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_expression_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                               C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_factor' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_factor_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                           C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_function' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_function_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_function_ (GALGAS_gtlFunction & outArgument0,
                                             C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_getter' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_getter_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_getter_ (GALGAS_gtlGetter & outArgument0,
                                           C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_import' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_import_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_import_ (GALGAS_gtlContext inArgument0,
                                           GALGAS_library & ioArgument1,
                                           C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_instruction' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_instruction_ (GALGAS_gtlInstruction & outArgument0,
                                                C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_instruction_list' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_instruction_5F_list_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_instruction_5F_list_ (GALGAS_gtlInstructionList & outArgument0,
                                                        C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_module_start_symbol' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_module_5F_start_5F_symbol_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_module_5F_start_5F_symbol_ (GALGAS_gtlContext inArgument0,
                                                              GALGAS_library & ioArgument1,
                                                              C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_gtlContext inArgument0,
                                                   GALGAS_library & ioArgument1
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_gtlContext inArgument0,
                                                     GALGAS_library & ioArgument1
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

//------------------------------------- 'gtl_relation_factor' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_relation_5F_factor_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                                       C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_relation_term' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_relation_5F_term_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                                     C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_setter' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_setter_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_setter_ (GALGAS_gtlSetter & outArgument0,
                                           C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_expression' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_simple_5F_expression_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                                         C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_instruction' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_simple_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_simple_5F_instruction_ (GALGAS_gtlInstruction & outArgument0,
                                                          C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_sorting_order' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_sorting_5F_order_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_sorting_5F_order_ (GALGAS_lsint & outArgument0,
                                                     C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_term' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_term_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                         C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_variable_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_variable_ (GALGAS_gtlVarPath & outArgument0,
                                             C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable_or_here' non terminal
//--- 'parse' label
  public : virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & outArgument0,
                                                           GALGAS_bool & outArgument1,
                                                           C_Lexique_gtl_5F_scanner * inCompiler) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_0 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_1 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_2 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_3 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_4 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_5 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_6 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_7 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_8 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_9 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_10 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_11 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_12 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_13 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_14 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_15 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_16 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_module_5F_parser_17 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_0 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_1 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_2 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_3 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_4 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_5 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_instruction_5F_parser_6 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_24 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_25 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_26 (C_Lexique_gtl_5F_scanner *) ;

  public : virtual int32_t select_gtl_5F_expression_5F_parser_27 (C_Lexique_gtl_5F_scanner *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library doImport'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionSetterSignature_library_doImport) (class cPtr_library * inObject,
                                                           const class GALGAS_string constinArgument0,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_doImport (class cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Parser class 'gtl_parser' declaration                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_gtl_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_gtl_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_gtl_5F_argument_5F_list_ (class GALGAS_gtlArgumentList & outArgument0,
                                                        class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_argument_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                  class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_file_5F_name_ (class GALGAS_gtlExpression & outArgument0,
                                                    class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_file_5F_name_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_import_ (class GALGAS_gtlContext inArgument0,
                                              class GALGAS_library & ioArgument1,
                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_import_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_simple_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_simple_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_start_5F_symbol_ (class GALGAS_gtlContext inArgument0,
                                                       class GALGAS_library & ioArgument1,
                                                       class GALGAS_gtlInstructionList & outArgument2,
                                                       class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_start_5F_symbol_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_template_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                               class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_template_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_template_5F_instruction_5F_list_ (class GALGAS_gtlInstructionList & outArgument0,
                                                                       class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_template_5F_instruction_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                                class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_5F_or_5F_here_ (class GALGAS_gtlVarPath & outArgument0,
                                                              class GALGAS_bool & outArgument1,
                                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_ (GALGAS_gtlContext inArgument0,
                                                                  GALGAS_library & ioArgument1,
                                                                  GALGAS_gtlInstructionList & outArgument2,
                                                                  C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_ (GALGAS_gtlInstructionList & outArgument0,
                                                                                  C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument0,
                                                                           C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument0,
                                                                           C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_ (GALGAS_gtlExpression & outArgument0,
                                                                C_Lexique_gtl_5F_scanner * inLexique) ;

  protected : void rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse (C_Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_gtl_5F_parser_0 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_1 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_2 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_3 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_4 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_5 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_6 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_7 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_8 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_9 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_10 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_11 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_12 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_13 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_14 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_15 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_16 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_17 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_18 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_19 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_20 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_21 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_22 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_23 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_24 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected : virtual int32_t select_gtl_5F_parser_25 (C_Lexique_gtl_5F_scanner *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlEmitInstruction class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlEmitInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlEmitInstruction (void) ;

//---
  public : inline const class cPtr_gtlEmitInstruction * ptr (void) const { return (const cPtr_gtlEmitInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlEmitInstruction (const cPtr_gtlEmitInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlEmitInstruction extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlEmitInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_string & inOperand1,
                                                                   const class GALGAS_gtlExpression & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlEmitInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_rValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlEmitInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEmitInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @gtlEmitInstruction class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlEmitInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_rValue ;

//--- Constructor
  public : cPtr_gtlEmitInstruction (const GALGAS_location & in_where,
                                    const GALGAS_string & in_signature,
                                    const GALGAS_gtlExpression & in_rValue
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_rValue (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlGetColumnInstruction class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlGetColumnInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlGetColumnInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlGetColumnInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlGetColumnInstruction * ptr (void) const { return (const cPtr_gtlGetColumnInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlGetColumnInstruction (const cPtr_gtlGetColumnInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlGetColumnInstruction extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlGetColumnInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                        const class GALGAS_string & inOperand1,
                                                                        const class GALGAS_gtlVarPath & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlGetColumnInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_destVariable (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlGetColumnInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGetColumnInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Pointer class for @gtlGetColumnInstruction class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlGetColumnInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlVarPath mAttribute_destVariable ;

//--- Constructor
  public : cPtr_gtlGetColumnInstruction (const GALGAS_location & in_where,
                                         const GALGAS_string & in_signature,
                                         const GALGAS_gtlVarPath & in_destVariable
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_destVariable (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlInputStatementInstruction class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlInputStatementInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlInputStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlInputStatementInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlInputStatementInstruction * ptr (void) const { return (const cPtr_gtlInputStatementInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlInputStatementInstruction (const cPtr_gtlInputStatementInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlInputStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlInputStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                             const class GALGAS_string & inOperand1,
                                                                             const class GALGAS_gtlArgumentList & inOperand2
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlInputStatementInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlArgumentList getter_formalArguments (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlInputStatementInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInputStatementInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlInputStatementInstruction class                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlInputStatementInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlArgumentList mAttribute_formalArguments ;

//--- Constructor
  public : cPtr_gtlInputStatementInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature,
                                              const GALGAS_gtlArgumentList & in_formalArguments
                                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlArgumentList getter_formalArguments (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlTemplateInstruction class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlTemplateInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlTemplateInstruction (void) ;

//---
  public : inline const class cPtr_gtlTemplateInstruction * ptr (void) const { return (const cPtr_gtlTemplateInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlTemplateInstruction (const cPtr_gtlTemplateInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlTemplateInstruction extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlTemplateInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_string & inOperand1,
                                                                       const class GALGAS_lstring & inOperand2,
                                                                       const class GALGAS_gtlExpression & inOperand3,
                                                                       const class GALGAS_bool & inOperand4,
                                                                       const class GALGAS_bool & inOperand5,
                                                                       const class GALGAS_gtlExpressionList & inOperand6,
                                                                       const class GALGAS_gtlInstructionList & inOperand7
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlTemplateInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_fileName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_ifExists (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_instructionsIfNotFound (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isGlobal (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlTemplateInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlTemplateInstruction class                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTemplateInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_lstring mAttribute_prefix ;
  public : GALGAS_gtlExpression mAttribute_fileName ;
  public : GALGAS_bool mAttribute_ifExists ;
  public : GALGAS_bool mAttribute_isGlobal ;
  public : GALGAS_gtlExpressionList mAttribute_arguments ;
  public : GALGAS_gtlInstructionList mAttribute_instructionsIfNotFound ;

//--- Constructor
  public : cPtr_gtlTemplateInstruction (const GALGAS_location & in_where,
                                        const GALGAS_string & in_signature,
                                        const GALGAS_lstring & in_prefix,
                                        const GALGAS_gtlExpression & in_fileName,
                                        const GALGAS_bool & in_ifExists,
                                        const GALGAS_bool & in_isGlobal,
                                        const GALGAS_gtlExpressionList & in_arguments,
                                        const GALGAS_gtlInstructionList & in_instructionsIfNotFound
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_fileName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_ifExists (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isGlobal (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructionsIfNotFound (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlTemplateStringInstruction class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlTemplateStringInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlTemplateStringInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_gtlTemplateStringInstruction constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_gtlTemplateStringInstruction * ptr (void) const { return (const cPtr_gtlTemplateStringInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlTemplateStringInstruction (const cPtr_gtlTemplateStringInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlTemplateStringInstruction extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlTemplateStringInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                             const class GALGAS_string & inOperand1,
                                                                             const class GALGAS_string & inOperand2
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlTemplateStringInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlTemplateStringInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Pointer class for @gtlTemplateStringInstruction class                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlTemplateStringInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_string mAttribute_value ;

//--- Constructor
  public : cPtr_gtlTemplateStringInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature,
                                              const GALGAS_string & in_value
                                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlWriteToInstruction class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_gtlWriteToInstruction : public GALGAS_gtlInstruction {
//--- Constructor
  public : GALGAS_gtlWriteToInstruction (void) ;

//---
  public : inline const class cPtr_gtlWriteToInstruction * ptr (void) const { return (const cPtr_gtlWriteToInstruction *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_gtlWriteToInstruction (const cPtr_gtlWriteToInstruction * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_gtlWriteToInstruction extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_gtlWriteToInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_string & inOperand1,
                                                                      const class GALGAS_gtlExpression & inOperand2,
                                                                      const class GALGAS_bool & inOperand3,
                                                                      const class GALGAS_gtlInstructionList & inOperand4
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_gtlWriteToInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_fileNameExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_instructions (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isExecutable (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_gtlWriteToInstruction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlWriteToInstruction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @gtlWriteToInstruction class                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_gtlWriteToInstruction : public cPtr_gtlInstruction {
//--- Attributes
  public : GALGAS_gtlExpression mAttribute_fileNameExpression ;
  public : GALGAS_bool mAttribute_isExecutable ;
  public : GALGAS_gtlInstructionList mAttribute_instructions ;

//--- Constructor
  public : cPtr_gtlWriteToInstruction (const GALGAS_location & in_where,
                                       const GALGAS_string & in_signature,
                                       const GALGAS_gtlExpression & in_fileNameExpression,
                                       const GALGAS_bool & in_isExecutable,
                                       const GALGAS_gtlInstructionList & in_instructions
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_fileNameExpression (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isExecutable (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructions (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

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
#endif

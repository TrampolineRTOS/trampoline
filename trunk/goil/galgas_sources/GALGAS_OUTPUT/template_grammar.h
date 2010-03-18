//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'template_grammar.h'                          *
//                       Generated by version 1.9.10                         *
//                      march 18th, 2010, at 9h48'42"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_template_5F_grammar_HAS_BEEN_DEFINED
#define GRAMMAR_template_5F_grammar_HAS_BEEN_DEFINED

//---------------------------------------------------------------------------*

#include "template_parser.h"
#include "template_expression_parser.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

class C_Grammar_template_5F_grammar : public template_parser,
                                      public template_expression_parser {
  public : virtual void nt_expression_ (C_Lexique_template_5F_scanner &,
                                        const GGS_string,
                                        const GGS_string,
                                        const GGS_string,
                                        const GGS_goilTemplateVariableMap,
                                        GGS_goilTemplateValue &,
                                        GGS_goilTemplateType &) ;

  public : virtual void nt_expression_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_factor_ (C_Lexique_template_5F_scanner &,
                                    const GGS_string,
                                    const GGS_string,
                                    const GGS_string,
                                    const GGS_goilTemplateVariableMap,
                                    GGS_goilTemplateValue &,
                                    GGS_goilTemplateType &) ;

  public : virtual void nt_factor_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_goil_5F_template_5F_start_5F_symbol_ (C_Lexique_template_5F_scanner &,
                                                                 const GGS_string,
                                                                 const GGS_string,
                                                                 const GGS_string,
                                                                 GGS_goilTemplateVariableMap,
                                                                 GGS_string &) ;

  public : static void _performSourceFileParsing_ (C_Compiler & inCompiler,
                                                   const C_String & inDependancyExtension,
                                                   const C_String & inDependancyPath,
                                                   GGS_string * inSentStringPtr,
                                                   const GGS_lstring inFileName,
                                                   const GGS_string,
                                                   const GGS_string,
                                                   const GGS_string,
                                                   GGS_goilTemplateVariableMap,
                                                   GGS_string &
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler & inCompiler,
                                                     GGS_string * inSentStringPtr,
                                                     const GGS_string inSourceString,
                                                     const GGS_string,
                                                     const GGS_string,
                                                     const GGS_string,
                                                     GGS_goilTemplateVariableMap,
                                                     GGS_string &
                                                     COMMA_LOCATION_ARGS) ;

  public : virtual void nt_relation_5F_factor_ (C_Lexique_template_5F_scanner &,
                                                const GGS_string,
                                                const GGS_string,
                                                const GGS_string,
                                                const GGS_goilTemplateVariableMap,
                                                GGS_goilTemplateValue &,
                                                GGS_goilTemplateType &) ;

  public : virtual void nt_relation_5F_factor_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_relation_5F_term_ (C_Lexique_template_5F_scanner &,
                                              const GGS_string,
                                              const GGS_string,
                                              const GGS_string,
                                              const GGS_goilTemplateVariableMap,
                                              GGS_goilTemplateValue &,
                                              GGS_goilTemplateType &) ;

  public : virtual void nt_relation_5F_term_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_simple_5F_expression_ (C_Lexique_template_5F_scanner &,
                                                  const GGS_string,
                                                  const GGS_string,
                                                  const GGS_string,
                                                  const GGS_goilTemplateVariableMap,
                                                  GGS_goilTemplateValue &,
                                                  GGS_goilTemplateType &) ;

  public : virtual void nt_simple_5F_expression_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_template_5F_instruction_ (C_Lexique_template_5F_scanner &,
                                                     const GGS_string,
                                                     const GGS_string,
                                                     const GGS_string,
                                                     GGS_goilTemplateVariableMap &,
                                                     GGS_string &) ;

  public : virtual void nt_template_5F_instruction_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_template_5F_instruction_5F_list_ (C_Lexique_template_5F_scanner &,
                                                             const GGS_string,
                                                             const GGS_string,
                                                             const GGS_string,
                                                             GGS_goilTemplateVariableMap &,
                                                             GGS_string &) ;

  public : virtual void nt_template_5F_instruction_5F_list_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_template_5F_instruction_5F_list_parseAndResetTemplateString (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_term_ (C_Lexique_template_5F_scanner &,
                                  const GGS_string,
                                  const GGS_string,
                                  const GGS_string,
                                  const GGS_goilTemplateVariableMap,
                                  GGS_goilTemplateValue &,
                                  GGS_goilTemplateType &) ;

  public : virtual void nt_term_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual void nt_variable_5F_or_5F_here_ (C_Lexique_template_5F_scanner &,
                                                    const GGS_goilTemplateVariableMap,
                                                    GGS_location &) ;

  public : virtual void nt_variable_5F_or_5F_here_parse (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_0 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_1 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_2 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_3 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_4 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_5 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_6 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_7 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_8 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_9 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_10 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_11 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_12 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_13 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_14 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_15 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_16 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_17 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_parser_18 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_0 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_1 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_2 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_3 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_4 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_5 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_6 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_7 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_8 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_9 (C_Lexique_template_5F_scanner &) ;

  public : virtual PMSInt16 select_template_5F_expression_5F_parser_10 (C_Lexique_template_5F_scanner &) ;
} ;

//---------------------------------------------------------------------------*

#endif

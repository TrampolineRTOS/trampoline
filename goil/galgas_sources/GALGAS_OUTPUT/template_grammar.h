//---------------------------------------------------------------------------*
//                                                                           *
//                        File 'template_grammar.h'                          *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 27th, 2010, at 20h10'19"                        *
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

class cGrammar_template_5F_grammar : public cParser_template_5F_parser,
                                     public cParser_template_5F_expression_5F_parser {
  public : virtual void nt_expression_ (GALGASap_string const inArgument0,
                                        GALGASap_string const inArgument1,
                                        GALGASap_string const inArgument2,
                                        GALGASap_goilTemplateVariableMap const inArgument3,
                                        GALGASap_goilTemplateValue & outArgument4,
                                        GALGASap_goilTemplateType & outArgument5,
                                        C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_expression_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_factor_ (GALGASap_string const inArgument0,
                                    GALGASap_string const inArgument1,
                                    GALGASap_string const inArgument2,
                                    GALGASap_goilTemplateVariableMap const inArgument3,
                                    GALGASap_goilTemplateValue & outArgument4,
                                    GALGASap_goilTemplateType & outArgument5,
                                    C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_factor_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_goil_5F_template_5F_start_5F_symbol_ (GALGASap_string const inArgument0,
                                                                 GALGASap_string const inArgument1,
                                                                 GALGASap_string const inArgument2,
                                                                 GALGASap_goilTemplateVariableMap inArgument3,
                                                                 GALGASap_string & ioArgument4,
                                                                 C_Lexique_template_5F_scanner * inCompiler) ;

  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGASap_lstring inFileName,
                                                   GALGASap_string const inArgument0,
                                                   GALGASap_string const inArgument1,
                                                   GALGASap_string const inArgument2,
                                                   GALGASap_goilTemplateVariableMap inArgument3,
                                                   GALGASap_string & ioArgument4
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGASap_string inSourceString,
                                                     GALGASap_string const inArgument0,
                                                     GALGASap_string const inArgument1,
                                                     GALGASap_string const inArgument2,
                                                     GALGASap_goilTemplateVariableMap inArgument3,
                                                     GALGASap_string & ioArgument4
                                                     COMMA_LOCATION_ARGS) ;

  public : virtual void nt_relation_5F_factor_ (GALGASap_string const inArgument0,
                                                GALGASap_string const inArgument1,
                                                GALGASap_string const inArgument2,
                                                GALGASap_goilTemplateVariableMap const inArgument3,
                                                GALGASap_goilTemplateValue & outArgument4,
                                                GALGASap_goilTemplateType & outArgument5,
                                                C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_relation_5F_factor_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_relation_5F_term_ (GALGASap_string const inArgument0,
                                              GALGASap_string const inArgument1,
                                              GALGASap_string const inArgument2,
                                              GALGASap_goilTemplateVariableMap const inArgument3,
                                              GALGASap_goilTemplateValue & outArgument4,
                                              GALGASap_goilTemplateType & outArgument5,
                                              C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_relation_5F_term_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_simple_5F_expression_ (GALGASap_string const inArgument0,
                                                  GALGASap_string const inArgument1,
                                                  GALGASap_string const inArgument2,
                                                  GALGASap_goilTemplateVariableMap const inArgument3,
                                                  GALGASap_goilTemplateValue & outArgument4,
                                                  GALGASap_goilTemplateType & outArgument5,
                                                  C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_simple_5F_expression_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_struct_5F_member_ (GALGASap_goilTemplateFieldMap const inArgument0,
                                              GALGASap_goilTemplateValue & outArgument1,
                                              GALGASap_goilTemplateType & outArgument2,
                                              C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_struct_5F_member_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_template_5F_instruction_ (GALGASap_string const inArgument0,
                                                     GALGASap_string const inArgument1,
                                                     GALGASap_string const inArgument2,
                                                     GALGASap_goilTemplateVariableMap & ioArgument3,
                                                     GALGASap_string & ioArgument4,
                                                     C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_template_5F_instruction_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_template_5F_instruction_5F_list_ (GALGASap_string const inArgument0,
                                                             GALGASap_string const inArgument1,
                                                             GALGASap_string const inArgument2,
                                                             GALGASap_goilTemplateVariableMap & ioArgument3,
                                                             GALGASap_string & ioArgument4,
                                                             C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_template_5F_instruction_5F_list_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_term_ (GALGASap_string const inArgument0,
                                  GALGASap_string const inArgument1,
                                  GALGASap_string const inArgument2,
                                  GALGASap_goilTemplateVariableMap const inArgument3,
                                  GALGASap_goilTemplateValue & outArgument4,
                                  GALGASap_goilTemplateType & outArgument5,
                                  C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_term_parse (C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_variable_5F_or_5F_here_ (GALGASap_goilTemplateVariableMap const inArgument0,
                                                    GALGASap_location & outArgument1,
                                                    C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual void nt_variable_5F_or_5F_here_parse (C_Lexique_template_5F_scanner * inCompiler) ;


  public : virtual PMSInt32 select_template_5F_parser_0 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_1 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_2 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_3 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_4 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_5 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_6 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_7 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_8 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_9 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_10 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_11 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_12 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_13 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_14 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_15 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_16 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_17 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_parser_18 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_0 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_1 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_2 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_3 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_4 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_5 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_6 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_7 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_8 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_9 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_10 (C_Lexique_template_5F_scanner *) ;

  public : virtual PMSInt32 select_template_5F_expression_5F_parser_11 (C_Lexique_template_5F_scanner *) ;
} ;

//---------------------------------------------------------------------------*

#endif
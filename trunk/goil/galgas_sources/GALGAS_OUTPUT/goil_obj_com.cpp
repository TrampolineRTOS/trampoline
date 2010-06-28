//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_obj_com.cpp'                           *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 17th, 2010, at 18h54'33"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER
  #error "This file has been compiled with a version of GALGAS that uses libpm version VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include "goil_obj_com.h"
#include "galgas/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"
#include "template_grammar.h"
#include "cfg_grammar.h"
#include "api_grammar.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_com.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_com_i0_ (GALGASap_com & ioArgument_com,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @trueExpressionForGeneration
  GALGASap_bool temp_0 (true COMMA_SOURCE_FILE_AT_LINE (80)) ;
  GALGASap_bool var_usecom (temp_0) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_basic_5F_type temp_1 (ioArgument_com.readerCall_timebase (SOURCE_FILE_AT_LINE (81))) ;
  GALGASap_basic_5F_type var_tb (temp_1) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_basic_5F_type temp_2 (ioArgument_com.readerCall_errorhook (SOURCE_FILE_AT_LINE (82))) ;
  GALGASap_basic_5F_type var_eh (temp_2) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_basic_5F_type temp_3 (ioArgument_com.readerCall_usegetserviceid (SOURCE_FILE_AT_LINE (83))) ;
  GALGASap_basic_5F_type var_ugsid (temp_3) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_basic_5F_type temp_4 (ioArgument_com.readerCall_useparameteraccess (SOURCE_FILE_AT_LINE (84))) ;
  GALGASap_basic_5F_type var_upa (temp_4) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_basic_5F_type temp_5 (ioArgument_com.readerCall_startcomextension (SOURCE_FILE_AT_LINE (85))) ;
  GALGASap_basic_5F_type var_sce (temp_5) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_lstringlist temp_6 (ioArgument_com.readerCall_appmodes (SOURCE_FILE_AT_LINE (86))) ;
  GALGASap_lstringlist var_am (temp_6) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_lstring temp_7 (ioArgument_com.readerCall_status (SOURCE_FILE_AT_LINE (87))) ;
  GALGASap_lstring var_s (temp_7) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  //--- @readerCallExpressionForGeneration
  GALGASap_lstringlist temp_8 (ioArgument_com.readerCall_uses (SOURCE_FILE_AT_LINE (88))) ;
  GALGASap_lstringlist var_u (temp_8) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COM) COMMA_SOURCE_FILE_AT_LINE (90)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (91)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (92)) ;
  //-------- @repeatInstructionForGeneration
  bool repeatFlag_9 = true ;
  while (repeatFlag_9) {
    switch (select_goil_5F_obj_5F_com_0 (inCompiler)) {
    case 2: {
      //-------- @nonterminalInstructionForGeneration
      nt_comtimebase_ (var_tb, inCompiler) ;
    } break ;
    case 3: {
      //-------- @nonterminalInstructionForGeneration
      nt_comerrorhook_ (var_eh, inCompiler) ;
    } break ;
    case 4: {
      //-------- @nonterminalInstructionForGeneration
      nt_comusegetserviceid_ (var_ugsid, inCompiler) ;
    } break ;
    case 5: {
      //-------- @nonterminalInstructionForGeneration
      nt_comuseparameteraccess_ (var_upa, inCompiler) ;
    } break ;
    case 6: {
      //-------- @nonterminalInstructionForGeneration
      nt_comstartcomextension_ (var_sce, inCompiler) ;
    } break ;
    case 7: {
      //-------- @nonterminalInstructionForGeneration
      nt_comappmode_ (var_am, inCompiler) ;
    } break ;
    case 8: {
      //-------- @nonterminalInstructionForGeneration
      nt_comstatus_ (var_s, inCompiler) ;
    } break ;
    case 9: {
      //-------- @nonterminalInstructionForGeneration
      nt_use_ (var_u, inCompiler) ;
    } break ;
    default:
      repeatFlag_9 = false ;
      break ;
    }
  }
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (103)) ;
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_2191_0 ; // Joker input parameter
  nt_description_ (joker_2191_0, inCompiler) ;
  joker_2191_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (104)) ;
  //-------- @assignmentInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_10 ("" COMMA_SOURCE_FILE_AT_LINE (107)) ;
  GALGASap_location temp_11 (inCompiler->here (SOURCE_FILE_AT_LINE (107))) ;
  GALGASap_lstring temp_12 (GALGASap_lstring::constructor_new (temp_10, temp_11 COMMA_SOURCE_FILE_AT_LINE (107))) ;
  GALGASap_com temp_13 (GALGASap_com::constructor_new (temp_12, var_usecom, var_tb, var_eh, var_ugsid, var_upa, var_sce, var_am, var_s, var_u COMMA_SOURCE_FILE_AT_LINE (106))) ;
  ioArgument_com = temp_13 ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_com_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COM) COMMA_SOURCE_FILE_AT_LINE (90)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (91)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (92)) ;
  //-------- @repeatInstructionForGeneration
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_obj_5F_com_0 (inCompiler)) {
    case 2: {
      //-------- @nonterminalInstructionForGeneration
      nt_comtimebase_parse (inCompiler) ;
    } break ;
    case 3: {
      //-------- @nonterminalInstructionForGeneration
      nt_comerrorhook_parse (inCompiler) ;
    } break ;
    case 4: {
      //-------- @nonterminalInstructionForGeneration
      nt_comusegetserviceid_parse (inCompiler) ;
    } break ;
    case 5: {
      //-------- @nonterminalInstructionForGeneration
      nt_comuseparameteraccess_parse (inCompiler) ;
    } break ;
    case 6: {
      //-------- @nonterminalInstructionForGeneration
      nt_comstartcomextension_parse (inCompiler) ;
    } break ;
    case 7: {
      //-------- @nonterminalInstructionForGeneration
      nt_comappmode_parse (inCompiler) ;
    } break ;
    case 8: {
      //-------- @nonterminalInstructionForGeneration
      nt_comstatus_parse (inCompiler) ;
    } break ;
    case 9: {
      //-------- @nonterminalInstructionForGeneration
      nt_use_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (103)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (104)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comtimebase_i1_ (GALGASap_basic_5F_type & ioArgument_tb,
                                                                          C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_ldouble var_f ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMTIMEBASE) COMMA_SOURCE_FILE_AT_LINE (124)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (124)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_f = inCompiler->synthetizedAttribute_floatNumber () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE_AT_LINE (124)) ;
  //-------- @structuredCastInstructionForGeneration
  if (ioArgument_tb.isValid ()) {
    if (ioArgument_tb.ptr (HERE)->typeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      //-------- @errorInstructionForGeneration
      //--- @literalStringExpressionForGeneration
      GALGASap_string temp_0 ("Redefinition of COMTIMEBASE" COMMA_SOURCE_FILE_AT_LINE (127)) ;
      GALGASap_location location_1 (var_f.readerCall_location (HERE)) ; // Implicit use of 'location' reader
      inCompiler->emitSemanticError (location_1, temp_0 COMMA_SOURCE_FILE_AT_LINE (127)) ;
      //-------- @errorInstructionForGeneration
      //--- @readerCallExpressionForGeneration
      GALGASap_location temp_2 (ioArgument_tb.readerCall_location (SOURCE_FILE_AT_LINE (128))) ;
      //--- @literalStringExpressionForGeneration
      GALGASap_string temp_3 ("was defined here" COMMA_SOURCE_FILE_AT_LINE (128)) ;
      inCompiler->emitSemanticError (temp_2, temp_3 COMMA_SOURCE_FILE_AT_LINE (128)) ;
    }else{
      //-------- @assignmentInstructionForGeneration
      //--- @readerCallExpressionForGeneration
      GALGASap_location temp_4 (var_f.readerCall_location (SOURCE_FILE_AT_LINE (130))) ;
      //--- @readerCallExpressionForGeneration
      GALGASap_double temp_5 (var_f.readerCall_double (SOURCE_FILE_AT_LINE (130))) ;
      GALGASap_float_5F_class temp_6 (GALGASap_float_5F_class::constructor_new (temp_4, temp_5 COMMA_SOURCE_FILE_AT_LINE (130))) ;
      ioArgument_tb = temp_6 ;
    }
  }
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_2673_0 ; // Joker input parameter
  nt_description_ (joker_2673_0, inCompiler) ;
  joker_2673_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (132)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comtimebase_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMTIMEBASE) COMMA_SOURCE_FILE_AT_LINE (124)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (124)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE_AT_LINE (124)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (132)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comerrorhook_i2_ (GALGASap_basic_5F_type & ioArgument_eh,
                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMERRORHOOK) COMMA_SOURCE_FILE_AT_LINE (139)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (139)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_0 ("COMERRORHOOK" COMMA_SOURCE_FILE_AT_LINE (140)) ;
  routine_set_5F_bool (ioArgument_eh, var_b, temp_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (140)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_2842_0 ; // Joker input parameter
  nt_description_ (joker_2842_0, inCompiler) ;
  joker_2842_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (141)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comerrorhook_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMERRORHOOK) COMMA_SOURCE_FILE_AT_LINE (139)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (139)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (141)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comusegetserviceid_i3_ (GALGASap_basic_5F_type & ioArgument_ugsid,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEGETSERVICEID) COMMA_SOURCE_FILE_AT_LINE (148)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (148)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_0 ("COMUSEGETSERVICEID" COMMA_SOURCE_FILE_AT_LINE (149)) ;
  routine_set_5F_bool (ioArgument_ugsid, var_b, temp_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (149)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_3034_0 ; // Joker input parameter
  nt_description_ (joker_3034_0, inCompiler) ;
  joker_3034_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (150)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comusegetserviceid_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEGETSERVICEID) COMMA_SOURCE_FILE_AT_LINE (148)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (148)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (150)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comuseparameteraccess_i4_ (GALGASap_basic_5F_type & ioArgument_upa,
                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEPARAMETERACCESS) COMMA_SOURCE_FILE_AT_LINE (157)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (157)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_0 ("COMUSEPARAMETERACCESS" COMMA_SOURCE_FILE_AT_LINE (158)) ;
  routine_set_5F_bool (ioArgument_upa, var_b, temp_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (158)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_3231_0 ; // Joker input parameter
  nt_description_ (joker_3231_0, inCompiler) ;
  joker_3231_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (159)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comuseparameteraccess_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEPARAMETERACCESS) COMMA_SOURCE_FILE_AT_LINE (157)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (157)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (159)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstartcomextension_i5_ (GALGASap_basic_5F_type & ioArgument_sce,
                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTARTCOMEXTENSION) COMMA_SOURCE_FILE_AT_LINE (166)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (166)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_0 ("COMSTARTCOMEXTENSION" COMMA_SOURCE_FILE_AT_LINE (167)) ;
  routine_set_5F_bool (ioArgument_sce, var_b, temp_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (167)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_3425_0 ; // Joker input parameter
  nt_description_ (joker_3425_0, inCompiler) ;
  joker_3425_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (168)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstartcomextension_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTARTCOMEXTENSION) COMMA_SOURCE_FILE_AT_LINE (166)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (166)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comappmode_i6_ (GALGASap_lstringlist & ioArgument_am,
                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lstring var_s ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMAPPMODE) COMMA_SOURCE_FILE_AT_LINE (175)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (175)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_s = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (175)) ;
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_0 ("COMAPPMODE" COMMA_SOURCE_FILE_AT_LINE (176)) ;
  routine_add_5F_lstring_5F_unique (ioArgument_am, var_s, temp_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (176)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_3599_0 ; // Joker input parameter
  nt_description_ (joker_3599_0, inCompiler) ;
  joker_3599_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (177)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comappmode_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMAPPMODE) COMMA_SOURCE_FILE_AT_LINE (175)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (175)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (175)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (177)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstatus_i7_ (GALGASap_lstring & ioArgument_s,
                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lstring var_ss ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTATUS) COMMA_SOURCE_FILE_AT_LINE (184)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (184)) ;
  //-------- @selectInstructionForGeneration
  switch (select_goil_5F_obj_5F_com_1 (inCompiler)) {
  case 1: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMEXTENDED) COMMA_SOURCE_FILE_AT_LINE (186)) ;
    //-------- @assignmentInstructionForGeneration
    //--- @literalStringExpressionForGeneration
    GALGASap_string temp_0 ("extended" COMMA_SOURCE_FILE_AT_LINE (186)) ;
    GALGASap_location temp_1 (inCompiler->here (SOURCE_FILE_AT_LINE (186))) ;
    GALGASap_lstring temp_2 (GALGASap_lstring::constructor_new (temp_0, temp_1 COMMA_SOURCE_FILE_AT_LINE (186))) ;
    var_ss = temp_2 ;
  } break ;
  case 2: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTANDARD) COMMA_SOURCE_FILE_AT_LINE (188)) ;
    //-------- @assignmentInstructionForGeneration
    //--- @literalStringExpressionForGeneration
    GALGASap_string temp_3 ("standard" COMMA_SOURCE_FILE_AT_LINE (188)) ;
    GALGASap_location temp_4 (inCompiler->here (SOURCE_FILE_AT_LINE (188))) ;
    GALGASap_lstring temp_5 (GALGASap_lstring::constructor_new (temp_3, temp_4 COMMA_SOURCE_FILE_AT_LINE (188))) ;
    var_ss = temp_5 ;
  } break ;
  default:
    break ;
  }
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_6 ("COMSTATUS" COMMA_SOURCE_FILE_AT_LINE (190)) ;
  routine_set_5F_lstring_5F_if_5F_empty (ioArgument_s, var_ss, temp_6, inCompiler COMMA_SOURCE_FILE_AT_LINE (190)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_3906_0 ; // Joker input parameter
  nt_description_ (joker_3906_0, inCompiler) ;
  joker_3906_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (191)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstatus_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTATUS) COMMA_SOURCE_FILE_AT_LINE (184)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (184)) ;
  //-------- @selectInstructionForGeneration
  switch (select_goil_5F_obj_5F_com_1 (inCompiler)) {
  case 1: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMEXTENDED) COMMA_SOURCE_FILE_AT_LINE (186)) ;
  } break ;
  case 2: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTANDARD) COMMA_SOURCE_FILE_AT_LINE (188)) ;
  } break ;
  default:
    break ;
  }
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_use_i8_ (GALGASap_lstringlist & ioArgument_u,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGASap_lstring var_use ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_USE) COMMA_SOURCE_FILE_AT_LINE (198)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (198)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_use = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (198)) ;
  { //-------- @routineCallInstructionForGeneration
  //--- @literalStringExpressionForGeneration
  GALGASap_string temp_0 ("USE" COMMA_SOURCE_FILE_AT_LINE (199)) ;
  routine_add_5F_lstring_5F_unique (ioArgument_u, var_use, temp_0, inCompiler COMMA_SOURCE_FILE_AT_LINE (199)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGASap_lstring joker_4064_0 ; // Joker input parameter
  nt_description_ (joker_4064_0, inCompiler) ;
  joker_4064_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (200)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_use_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_USE) COMMA_SOURCE_FILE_AT_LINE (198)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (198)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (198)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (200)) ;
  inCompiler->resetTemplateString () ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



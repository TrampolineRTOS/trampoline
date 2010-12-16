//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_obj_com.cpp'                           *
//                    Generated by version version 2.1.0                     *
//                     november 18th, 2010, at 7h24'8"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 909
  #error "This file has been compiled with a version of GALGAS that uses libpm version 909, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include "goil_obj_com.h"
#include "galgas2/C_galgas_CLI_Options.h"

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

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_com_i0_ (GALGAS_com & ioArgument_com,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_bool var_usecom = GALGAS_bool (true) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_basic_5F_type var_tb = ioArgument_com.reader_timebase (SOURCE_FILE_AT_LINE (74)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_basic_5F_type var_eh = ioArgument_com.reader_errorhook (SOURCE_FILE_AT_LINE (75)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_basic_5F_type var_ugsid = ioArgument_com.reader_usegetserviceid (SOURCE_FILE_AT_LINE (76)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_basic_5F_type var_upa = ioArgument_com.reader_useparameteraccess (SOURCE_FILE_AT_LINE (77)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_basic_5F_type var_sce = ioArgument_com.reader_startcomextension (SOURCE_FILE_AT_LINE (78)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_lstringlist var_am = ioArgument_com.reader_appmodes (SOURCE_FILE_AT_LINE (79)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_lstring var_s = ioArgument_com.reader_status (SOURCE_FILE_AT_LINE (80)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_lstringlist var_u = ioArgument_com.reader_uses (SOURCE_FILE_AT_LINE (81)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COM) COMMA_SOURCE_FILE_AT_LINE (83)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (84)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (85)) ;
  //-------- @repeatInstructionForGeneration
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
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
      repeatFlag_0 = false ;
      break ;
    }
  }
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (96)) ;
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_1879_0 ; // Joker input parameter
  nt_description_ (joker_1879_0, inCompiler) ;
  joker_1879_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (97)) ;
  //-------- @assignmentInstructionForGeneration
  ioArgument_com = GALGAS_com::constructor_new (GALGAS_lstring::constructor_new (GALGAS_string (""), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (100)), var_usecom, var_tb, var_eh, var_ugsid, var_upa, var_sce, var_am, var_s, var_u COMMA_SOURCE_FILE_AT_LINE (99)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_com_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COM) COMMA_SOURCE_FILE_AT_LINE (83)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (84)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (85)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (96)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (97)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comtimebase_i1_ (GALGAS_basic_5F_type & ioArgument_tb,
                                                                          C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_ldouble var_f ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMTIMEBASE) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_f = inCompiler->synthetizedAttribute_floatNumber () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @structuredCastInstructionForGeneration
  if (ioArgument_tb.isValid ()) {
    if (ioArgument_tb.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      //-------- @errorInstructionForGeneration
      GALGAS_location location_0 (var_f.reader_location (HERE)) ; // Implicit use of 'location' reader
      inCompiler->emitSemanticError (location_0, GALGAS_string ("Redefinition of COMTIMEBASE") COMMA_SOURCE_FILE_AT_LINE (120)) ;
      //-------- @errorInstructionForGeneration
      inCompiler->emitSemanticError (ioArgument_tb.reader_location (SOURCE_FILE_AT_LINE (121)), GALGAS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (121)) ;
    }else{
      //-------- @assignmentInstructionForGeneration
      ioArgument_tb = GALGAS_float_5F_class::constructor_new (var_f.reader_location (SOURCE_FILE_AT_LINE (123)), var_f.reader_double (SOURCE_FILE_AT_LINE (123)) COMMA_SOURCE_FILE_AT_LINE (123)) ;
    }
  }
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_2361_0 ; // Joker input parameter
  nt_description_ (joker_2361_0, inCompiler) ;
  joker_2361_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (125)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comtimebase_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMTIMEBASE) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (125)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comerrorhook_i2_ (GALGAS_basic_5F_type & ioArgument_eh,
                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMERRORHOOK) COMMA_SOURCE_FILE_AT_LINE (132)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (132)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  routine_set_5F_bool (ioArgument_eh, var_b, GALGAS_string ("COMERRORHOOK"), inCompiler COMMA_SOURCE_FILE_AT_LINE (133)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_2530_0 ; // Joker input parameter
  nt_description_ (joker_2530_0, inCompiler) ;
  joker_2530_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (134)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comerrorhook_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMERRORHOOK) COMMA_SOURCE_FILE_AT_LINE (132)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (132)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (134)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comusegetserviceid_i3_ (GALGAS_basic_5F_type & ioArgument_ugsid,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEGETSERVICEID) COMMA_SOURCE_FILE_AT_LINE (141)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (141)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  routine_set_5F_bool (ioArgument_ugsid, var_b, GALGAS_string ("COMUSEGETSERVICEID"), inCompiler COMMA_SOURCE_FILE_AT_LINE (142)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_2722_0 ; // Joker input parameter
  nt_description_ (joker_2722_0, inCompiler) ;
  joker_2722_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (143)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comusegetserviceid_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEGETSERVICEID) COMMA_SOURCE_FILE_AT_LINE (141)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (141)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (143)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comuseparameteraccess_i4_ (GALGAS_basic_5F_type & ioArgument_upa,
                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEPARAMETERACCESS) COMMA_SOURCE_FILE_AT_LINE (150)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (150)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  routine_set_5F_bool (ioArgument_upa, var_b, GALGAS_string ("COMUSEPARAMETERACCESS"), inCompiler COMMA_SOURCE_FILE_AT_LINE (151)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_2919_0 ; // Joker input parameter
  nt_description_ (joker_2919_0, inCompiler) ;
  joker_2919_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (152)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comuseparameteraccess_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMUSEPARAMETERACCESS) COMMA_SOURCE_FILE_AT_LINE (150)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (150)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (152)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstartcomextension_i5_ (GALGAS_basic_5F_type & ioArgument_sce,
                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lbool var_b ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTARTCOMEXTENSION) COMMA_SOURCE_FILE_AT_LINE (159)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (159)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_ (var_b, inCompiler) ;
  { //-------- @routineCallInstructionForGeneration
  routine_set_5F_bool (ioArgument_sce, var_b, GALGAS_string ("COMSTARTCOMEXTENSION"), inCompiler COMMA_SOURCE_FILE_AT_LINE (160)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_3113_0 ; // Joker input parameter
  nt_description_ (joker_3113_0, inCompiler) ;
  joker_3113_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (161)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstartcomextension_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTARTCOMEXTENSION) COMMA_SOURCE_FILE_AT_LINE (159)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (159)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_boolean_parse (inCompiler) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (161)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comappmode_i6_ (GALGAS_lstringlist & ioArgument_am,
                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lstring var_s ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMAPPMODE) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_s = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  { //-------- @routineCallInstructionForGeneration
  routine_add_5F_lstring_5F_unique (ioArgument_am, var_s, GALGAS_string ("COMAPPMODE"), inCompiler COMMA_SOURCE_FILE_AT_LINE (169)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_3287_0 ; // Joker input parameter
  nt_description_ (joker_3287_0, inCompiler) ;
  joker_3287_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (170)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comappmode_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMAPPMODE) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (168)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (170)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstatus_i7_ (GALGAS_lstring & ioArgument_s,
                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lstring var_ss ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTATUS) COMMA_SOURCE_FILE_AT_LINE (177)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (177)) ;
  //-------- @selectInstructionForGeneration
  switch (select_goil_5F_obj_5F_com_1 (inCompiler)) {
  case 1: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMEXTENDED) COMMA_SOURCE_FILE_AT_LINE (179)) ;
    //-------- @assignmentInstructionForGeneration
    var_ss = GALGAS_lstring::constructor_new (GALGAS_string ("extended"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (179)) ;
  } break ;
  case 2: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTANDARD) COMMA_SOURCE_FILE_AT_LINE (181)) ;
    //-------- @assignmentInstructionForGeneration
    var_ss = GALGAS_lstring::constructor_new (GALGAS_string ("standard"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (181)) ;
  } break ;
  default:
    break ;
  }
  { //-------- @routineCallInstructionForGeneration
  routine_set_5F_lstring_5F_if_5F_empty (ioArgument_s, var_ss, GALGAS_string ("COMSTATUS"), inCompiler COMMA_SOURCE_FILE_AT_LINE (183)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_3594_0 ; // Joker input parameter
  nt_description_ (joker_3594_0, inCompiler) ;
  joker_3594_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (184)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_comstatus_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTATUS) COMMA_SOURCE_FILE_AT_LINE (177)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (177)) ;
  //-------- @selectInstructionForGeneration
  switch (select_goil_5F_obj_5F_com_1 (inCompiler)) {
  case 1: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMEXTENDED) COMMA_SOURCE_FILE_AT_LINE (179)) ;
  } break ;
  case 2: {
    //-------- @terminalCheckInstructionForGeneration
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COMSTANDARD) COMMA_SOURCE_FILE_AT_LINE (181)) ;
  } break ;
  default:
    break ;
  }
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (184)) ;
  inCompiler->resetTemplateString () ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_use_i8_ (GALGAS_lstringlist & ioArgument_u,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @localVariableDeclarationForGeneration
  GALGAS_lstring var_use ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_USE) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_use = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  { //-------- @routineCallInstructionForGeneration
  routine_add_5F_lstring_5F_unique (ioArgument_u, var_use, GALGAS_string ("USE"), inCompiler COMMA_SOURCE_FILE_AT_LINE (192)) ;
  } //-------- @routineCallInstructionForGeneration
  //-------- @nonterminalInstructionForGeneration
  GALGAS_lstring joker_3752_0 ; // Joker input parameter
  nt_description_ (joker_3752_0, inCompiler) ;
  joker_3752_0.drop () ; // Release temporary input variables (joker in source)
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (193)) ;
}

void cParser_goil_5F_obj_5F_com::rule_goil_5F_obj_5F_com_use_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_USE) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE_AT_LINE (191)) ;
  //-------- @nonterminalInstructionForGeneration
  nt_description_parse (inCompiler) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (193)) ;
  inCompiler->resetTemplateString () ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


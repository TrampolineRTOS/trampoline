//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'cfg_syntax.cpp'                            *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'56"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER
  #error "This file has been compiled with a version of GALGAS that uses libpm version VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include "cfg_syntax.h"
#include "galgas2/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "cfg_syntax.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

void cParser_cfg_5F_syntax::rule_cfg_5F_syntax_cfg_5F_start_i0_ (GALGAS_config & outArgument_cfg,
                                                                 C_Lexique_cfg_5F_lexique * inCompiler) {
  outArgument_cfg.drop () ; // Release 'out' argument
  //-------- @assignmentInstructionForGeneration
  outArgument_cfg = GALGAS_config::constructor_emptyMap (SOURCE_FILE_AT_LINE (37)) ;
  //-------- @localVariableOrConstantDeclarationWithConstructorCallForGeneration
  GALGAS_cfg_5F_attrs var_task_5F_attrs = GALGAS_cfg_5F_attrs::constructor_emptyMap (SOURCE_FILE_AT_LINE (39)) ;
  //-------- @localVariableOrConstantDeclarationWithConstructorCallForGeneration
  GALGAS_cfg_5F_attrs var_isr_5F_attrs = GALGAS_cfg_5F_attrs::constructor_emptyMap (SOURCE_FILE_AT_LINE (40)) ;
  //-------- @localVariableOrConstantDeclarationWithConstructorCallForGeneration
  GALGAS_cfg_5F_attrs var_isr_5F_code_5F_attrs = GALGAS_cfg_5F_attrs::constructor_emptyMap (SOURCE_FILE_AT_LINE (41)) ;
  //-------- @localVariableOrConstantDeclarationWithConstructorCallForGeneration
  GALGAS_cfg_5F_attrs var_counter_5F_code_5F_attrs = GALGAS_cfg_5F_attrs::constructor_emptyMap (SOURCE_FILE_AT_LINE (42)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_basic_5F_type var_its = GALGAS_void::constructor_new (inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (43)) ;
  //-------- @repeatInstructionForGeneration
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_cfg_5F_syntax_0 (inCompiler)) {
    case 2: {
      //-------- @localVariableDeclarationForGeneration
      GALGAS_luint_36__34_ var_tpn ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_tp_5F_ns_5F_per_5F_counter_5F_tick) COMMA_SOURCE_FILE_AT_LINE (48)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (48)) ;
      //-------- @terminalCheckInstructionForGeneration
      var_tpn = inCompiler->synthetizedAttribute_integer () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_SOURCE_FILE_AT_LINE (48)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (48)) ;
      //-------- @ifInstructionForGeneration
      if (outArgument_cfg.reader_hasKey (GALGAS_string ("wd_ticks_per_ns") COMMA_SOURCE_FILE_AT_LINE (49)).isValidAndTrue ()) {
        //-------- @errorInstructionForGeneration
        inCompiler->emitSemanticError (inCompiler->here (), GALGAS_string ("Redefinition of tp_ns_per_counter_tick") COMMA_SOURCE_FILE_AT_LINE (50)) ;
      }else{
        { //-------- @modifierCallInstructionForGeneration
        outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("wd_ticks_per_ns"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (53)), GALGAS_uint_36__34__5F_class::constructor_new (var_tpn.reader_location (SOURCE_FILE_AT_LINE (54)), var_tpn.reader_uint_36__34_ (SOURCE_FILE_AT_LINE (54)) COMMA_SOURCE_FILE_AT_LINE (54)), inCompiler COMMA_SOURCE_FILE_AT_LINE (52)) ;
        } //-------- END @typeMethodInstructionForGeneration
      }
    } break ;
    case 3: {
      //-------- @localVariableDeclarationForGeneration
      GALGAS_luint_36__34_ var_s_5F_align ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_stack_5F_alignment) COMMA_SOURCE_FILE_AT_LINE (59)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (59)) ;
      //-------- @terminalCheckInstructionForGeneration
      var_s_5F_align = inCompiler->synthetizedAttribute_integer () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_SOURCE_FILE_AT_LINE (59)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (59)) ;
      //-------- @ifInstructionForGeneration
      if (outArgument_cfg.reader_hasKey (GALGAS_string ("stack_align") COMMA_SOURCE_FILE_AT_LINE (60)).isValidAndTrue ()) {
        //-------- @errorInstructionForGeneration
        inCompiler->emitSemanticError (inCompiler->here (), GALGAS_string ("Redefinition of stack_alignment") COMMA_SOURCE_FILE_AT_LINE (61)) ;
      }else{
        { //-------- @modifierCallInstructionForGeneration
        outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("stack_align"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (64)), GALGAS_uint_36__34__5F_class::constructor_new (var_s_5F_align.reader_location (SOURCE_FILE_AT_LINE (65)), var_s_5F_align.reader_uint_36__34_ (SOURCE_FILE_AT_LINE (65)) COMMA_SOURCE_FILE_AT_LINE (65)), inCompiler COMMA_SOURCE_FILE_AT_LINE (63)) ;
        } //-------- END @typeMethodInstructionForGeneration
      }
    } break ;
    case 4: {
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_task) COMMA_SOURCE_FILE_AT_LINE (69)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (69)) ;
      //-------- @nonterminalInstructionForGeneration
      nt_cfg_5F_attrs_ (var_task_5F_attrs, inCompiler) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (69)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (69)) ;
    } break ;
    case 5: {
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_isr) COMMA_SOURCE_FILE_AT_LINE (71)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (71)) ;
      //-------- @nonterminalInstructionForGeneration
      nt_cfg_5F_attrs_ (var_isr_5F_attrs, inCompiler) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (71)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (71)) ;
    } break ;
    case 6: {
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_isr_5F_code) COMMA_SOURCE_FILE_AT_LINE (73)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (73)) ;
      //-------- @nonterminalInstructionForGeneration
      nt_cfg_5F_attrs_ (var_isr_5F_code_5F_attrs, inCompiler) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (73)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (73)) ;
    } break ;
    case 7: {
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_counter_5F_code) COMMA_SOURCE_FILE_AT_LINE (75)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (75)) ;
      //-------- @nonterminalInstructionForGeneration
      nt_cfg_5F_attrs_ (var_counter_5F_code_5F_attrs, inCompiler) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (75)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (75)) ;
    } break ;
    case 8: {
      //-------- @nonterminalInstructionForGeneration
      nt_interrupts_ (var_its, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  { //-------- @modifierCallInstructionForGeneration
  outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("task_attrs"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (81)), GALGAS_attrs::constructor_new (inCompiler->here (), var_task_5F_attrs COMMA_SOURCE_FILE_AT_LINE (82)), inCompiler COMMA_SOURCE_FILE_AT_LINE (80)) ;
  } //-------- END @typeMethodInstructionForGeneration
  { //-------- @modifierCallInstructionForGeneration
  outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("isr_attrs"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (85)), GALGAS_attrs::constructor_new (inCompiler->here (), var_isr_5F_attrs COMMA_SOURCE_FILE_AT_LINE (86)), inCompiler COMMA_SOURCE_FILE_AT_LINE (84)) ;
  } //-------- END @typeMethodInstructionForGeneration
  { //-------- @modifierCallInstructionForGeneration
  outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("isr_code_attrs"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (89)), GALGAS_attrs::constructor_new (inCompiler->here (), var_isr_5F_code_5F_attrs COMMA_SOURCE_FILE_AT_LINE (90)), inCompiler COMMA_SOURCE_FILE_AT_LINE (88)) ;
  } //-------- END @typeMethodInstructionForGeneration
  { //-------- @modifierCallInstructionForGeneration
  outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("counter_code_attrs"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (93)), GALGAS_attrs::constructor_new (inCompiler->here (), var_counter_5F_code_5F_attrs COMMA_SOURCE_FILE_AT_LINE (94)), inCompiler COMMA_SOURCE_FILE_AT_LINE (92)) ;
  } //-------- END @typeMethodInstructionForGeneration
  { //-------- @modifierCallInstructionForGeneration
  outArgument_cfg.modifier_put (GALGAS_lstring::constructor_new (GALGAS_string ("it_sources"), inCompiler->here () COMMA_SOURCE_FILE_AT_LINE (96)), var_its, inCompiler COMMA_SOURCE_FILE_AT_LINE (96)) ;
  } //-------- END @typeMethodInstructionForGeneration
}

void cParser_cfg_5F_syntax::rule_cfg_5F_syntax_cfg_5F_attrs_i1_ (GALGAS_cfg_5F_attrs & ioArgument_attrs,
                                                                 C_Lexique_cfg_5F_lexique * inCompiler) {
  //-------- @repeatInstructionForGeneration
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_cfg_5F_syntax_1 (inCompiler)) {
    case 2: {
      //-------- @localVariableDeclarationForGeneration
      GALGAS_lstring var_oil_5F_attr ;
      //-------- @localVariableDeclarationForGeneration
      GALGAS_lstring var_tpl_5F_attr ;
      //-------- @terminalCheckInstructionForGeneration
      var_oil_5F_attr = inCompiler->synthetizedAttribute_keyword () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (107)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (107)) ;
      //-------- @terminalCheckInstructionForGeneration
      var_tpl_5F_attr = inCompiler->synthetizedAttribute_keyword () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (107)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (107)) ;
      { //-------- @modifierCallInstructionForGeneration
      ioArgument_attrs.modifier_put (var_oil_5F_attr, var_tpl_5F_attr, inCompiler COMMA_SOURCE_FILE_AT_LINE (108)) ;
      } //-------- END @typeMethodInstructionForGeneration
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

void cParser_cfg_5F_syntax::rule_cfg_5F_syntax_interrupts_i2_ (GALGAS_basic_5F_type & ioArgument_its,
                                                               C_Lexique_cfg_5F_lexique * inCompiler) {
  //-------- @localVariableOrConstantDeclarationWithConstructorCallForGeneration
  GALGAS_ident_5F_map var_it_5F_src = GALGAS_ident_5F_map::constructor_emptyMap (SOURCE_FILE_AT_LINE (115)) ;
  //-------- @localVariableDeclarationForGeneration
  GALGAS_luint_36__34_ var_it_5F_count ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_interrupts) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  var_it_5F_count = inCompiler->synthetizedAttribute_integer () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE_AT_LINE (117)) ;
  //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
  GALGAS_location var_it_5F_loc = inCompiler->here () ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE_AT_LINE (119)) ;
  //-------- @repeatInstructionForGeneration
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_cfg_5F_syntax_2 (inCompiler)) {
    case 2: {
      //-------- @localVariableDeclarationForGeneration
      GALGAS_lstring var_src ;
      //-------- @localVariableDeclarationForGeneration
      GALGAS_luint_36__34_ var_id ;
      //-------- @terminalCheckInstructionForGeneration
      var_src = inCompiler->synthetizedAttribute_keyword () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_idf) COMMA_SOURCE_FILE_AT_LINE (123)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE_AT_LINE (123)) ;
      //-------- @terminalCheckInstructionForGeneration
      var_id = inCompiler->synthetizedAttribute_integer () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken_uint) COMMA_SOURCE_FILE_AT_LINE (123)) ;
      //-------- @terminalCheckInstructionForGeneration
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (123)) ;
      //-------- @ifInstructionForGeneration
      if (GALGAS_bool (kIsSupOrEqual, var_id.reader_uint_36__34_ (SOURCE_FILE_AT_LINE (124)).objectCompare (var_it_5F_count.reader_uint_36__34_ (SOURCE_FILE_AT_LINE (124)))).isValidAndTrue ()) {
        //-------- @errorInstructionForGeneration
        GALGAS_location location_1 (var_id.reader_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_1, GALGAS_string ("Interrupt id out of range") COMMA_SOURCE_FILE_AT_LINE (125)) ;
        //-------- @errorInstructionForGeneration
        GALGAS_location location_2 (var_it_5F_count.reader_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_2, GALGAS_string ("Range was defined here") COMMA_SOURCE_FILE_AT_LINE (126)) ;
      }
      { //-------- @modifierCallInstructionForGeneration
      var_it_5F_src.modifier_put (var_src, GALGAS_uint_36__34__5F_class::constructor_new (var_id.reader_location (SOURCE_FILE_AT_LINE (128)), var_id.reader_uint_36__34_ (SOURCE_FILE_AT_LINE (128)) COMMA_SOURCE_FILE_AT_LINE (128)), inCompiler COMMA_SOURCE_FILE_AT_LINE (128)) ;
      } //-------- END @typeMethodInstructionForGeneration
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE_AT_LINE (130)) ;
  //-------- @terminalCheckInstructionForGeneration
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_cfg_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE_AT_LINE (130)) ;
  //-------- @assignmentInstructionForGeneration
  ioArgument_its = GALGAS_interrupts::constructor_new (var_it_5F_loc, var_it_5F_count, var_it_5F_src COMMA_SOURCE_FILE_AT_LINE (131)) ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



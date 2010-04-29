//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_obj_counter.cpp'                         *
//                       Generated by version 1.9.11                         *
//                      april 29th, 2010, at 10h36'22"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 725
  #error "This file has been compiled with a version of GALGAS that uses libpm version 725, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_counter.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_counter.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of production rule 'counter'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_counter::rule_goil_5F_obj_5F_counter_counter_i0_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_counter_map  &var_cas_counters) {
  GGS_lstring  var_cas_counter_name ;
  GGS_counter_obj  var_cas_counter ;
  GGS_basic_type  var_cas_max_allowed_value ;
  GGS_basic_type  var_cas_ticks_per_base ;
  GGS_basic_type  var_cas_min_cycle ;
  GGS_lstring  var_cas_source ;
  GGS_lstringlist  var_cas_acc_apps ;
  GGS_counter_type  var_cas_type ;
  GGS_lstring  var_cas_unit ;
  GGS_lstring  var_cas_desc ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_COUNTER) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_5F_token (var_cas_counter_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  const GGS_bool cond_1978 = var_cas_counters.reader_hasKey (var_cas_counter_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (73))) ;
  if (cond_1978.isBuiltAndTrue ()) {
    var_cas_counters.modifier_del (inLexique, var_cas_counter_name, var_cas_counter COMMA_SOURCE_FILE_AT_LINE (74)) ;
    var_cas_max_allowed_value = var_cas_counter.reader_max_allowed_value (inLexique COMMA_SOURCE_FILE_AT_LINE (75)) ;
    var_cas_ticks_per_base = var_cas_counter.reader_ticks_per_base (inLexique COMMA_SOURCE_FILE_AT_LINE (76)) ;
    var_cas_min_cycle = var_cas_counter.reader_min_cycle (inLexique COMMA_SOURCE_FILE_AT_LINE (77)) ;
    var_cas_source = var_cas_counter.reader_source (inLexique COMMA_SOURCE_FILE_AT_LINE (78)) ;
    var_cas_acc_apps = var_cas_counter.reader_acc_apps (inLexique COMMA_SOURCE_FILE_AT_LINE (79)) ;
    var_cas_type = var_cas_counter.reader_type (inLexique COMMA_SOURCE_FILE_AT_LINE (80)) ;
    var_cas_unit = var_cas_counter.reader_unit (inLexique COMMA_SOURCE_FILE_AT_LINE (81)) ;
    var_cas_desc = var_cas_counter.reader_desc (inLexique COMMA_SOURCE_FILE_AT_LINE (82)) ;
  }else if (cond_1978.isBuiltAndFalse ()) {
    var_cas_max_allowed_value = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (84)) ;
    var_cas_ticks_per_base = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (85)) ;
    var_cas_min_cycle = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (86)) ;
    var_cas_source = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (87)) ;
    var_cas_acc_apps = GGS_lstringlist ::constructor_emptyList () ;
    var_cas_type = GGS_void_counter ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (89)) ;
    var_cas_unit = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (90)) ;
    var_cas_desc = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (91)) ;
    var_cas_counter = GGS_counter_obj ::constructor_new (inLexique, var_cas_desc, var_cas_max_allowed_value, var_cas_ticks_per_base, var_cas_min_cycle, var_cas_source, var_cas_acc_apps, var_cas_type, var_cas_unit COMMA_SOURCE_FILE_AT_LINE (92)) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  nt_counter_5F_parameters_ (inLexique, var_cas_max_allowed_value, var_cas_ticks_per_base, var_cas_min_cycle, var_cas_source, var_cas_acc_apps, var_cas_type, var_cas_unit) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
  var_cas_counter = GGS_counter_obj ::constructor_new (inLexique, var_cas_desc, var_cas_max_allowed_value, var_cas_ticks_per_base, var_cas_min_cycle, var_cas_source, var_cas_acc_apps, var_cas_type, var_cas_unit COMMA_SOURCE_FILE_AT_LINE (108)) ;
  var_cas_counters.modifier_put (inLexique, var_cas_counter_name, var_cas_counter COMMA_SOURCE_FILE_AT_LINE (117)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'counter_parameters'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_counter::rule_goil_5F_obj_5F_counter_counter_5F_parameters_i1_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_basic_type  &var_cas_max_allowed_value,
                                GGS_basic_type  &var_cas_ticks_per_base,
                                GGS_basic_type  &var_cas_min_cycle,
                                GGS_lstring  &var_cas_source,
                                GGS_lstringlist  &var_cas_acc_apps,
                                GGS_counter_type  &var_cas_type,
                                GGS_lstring  &var_cas_unit) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_counter_0 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_m ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_MAXALLOWEDVALUE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_m) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_3331_0 ;
          nt_description_ (inLexique, automatic_var_3331_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_set_uint32 (inLexique,  var_cas_max_allowed_value,  var_cas_m,  GGS_string ("MAXALLOWEDVALUE") COMMA_SOURCE_FILE_AT_LINE (133)) ;
          } break ;
        case 3 : {
          GGS_luint64  var_cas_t ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TICKSPERBASE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_t) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_3486_0 ;
          nt_description_ (inLexique, automatic_var_3486_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_set_uint32 (inLexique,  var_cas_ticks_per_base,  var_cas_t,  GGS_string ("TICKSPERBASE") COMMA_SOURCE_FILE_AT_LINE (137)) ;
          } break ;
        case 4 : {
          GGS_luint64  var_cas_c ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_MINCYCLE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_integerNumber (var_cas_c) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
          GGS_lstring  automatic_var_3631_0 ;
          nt_description_ (inLexique, automatic_var_3631_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_set_uint32 (inLexique,  var_cas_min_cycle,  var_cas_c,  GGS_string ("MINCYCLE") COMMA_SOURCE_FILE_AT_LINE (141)) ;
          } break ;
        case 5 : {
          const GGS_bool cond_3852 = (gOption_goil_5F_options_autosar_5F_on.reader_value ()).operator_isEqual (GGS_bool (false)) ;
          if (cond_3852.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use TYPE attribute in COUNTER object") COMMA_SOURCE_FILE_AT_LINE (145)) ;
          }
          GGS_counter_type  var_cas_cpt_type ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TYPE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          nt_counter_5F_type_5F_attrs_ (inLexique, var_cas_cpt_type) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          { const GGS_counter_type _var_4127 = var_cas_type ; // CAST instruction
            if (_var_4127.getPtr () != NULL) {
              macroValidPointer (_var_4127.getPtr ()) ;
              if (typeid (cPtr_void_counter) == typeid (* (_var_4127.getPtr ()))) {
                var_cas_type = var_cas_cpt_type ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Redefinitiion of TYPE") COMMA_SOURCE_FILE_AT_LINE (153)) ;
                var_cas_type.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (153)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (154)) ;
              }
            }
          }
          } break ;
        case 6 : {
          const GGS_bool cond_4311 = (gOption_goil_5F_options_autosar_5F_on.reader_value ()).operator_isEqual (GGS_bool (false)) ;
          if (cond_4311.isBuiltAndTrue ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use UNIT attribute in COUNTER object") COMMA_SOURCE_FILE_AT_LINE (158)) ;
          }
          GGS_lstring  var_cas_cpt_unit ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UNIT) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_counter_1 (inLexique)) {
            case 1 : {
              inLexique.assignFromAttribute_att_5F_token (var_cas_cpt_unit) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TICKS) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.assignFromAttribute_att_5F_token (var_cas_cpt_unit) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NANOSECONDS) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          const GGS_bool cond_4528 = (var_cas_unit.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (167))).operator_isEqual (GGS_string ("")) ;
          if (cond_4528.isBuiltAndTrue ()) {
            var_cas_unit = var_cas_cpt_unit ;
          }else if (cond_4528.isBuiltAndFalse ()) {
            GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("UNIT attribute already defined for this counter") COMMA_SOURCE_FILE_AT_LINE (171)) ;
            var_cas_unit.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (172)) ;
          }
          } break ;
        case 7 : {
          GGS_lstring  var_cas_src ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_SOURCE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_5F_token (var_cas_src) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_4728_0 ;
          nt_description_ (inLexique, automatic_var_4728_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_set_lstring_if_empty (inLexique,  var_cas_source,  var_cas_src,  GGS_string ("SOURCE") COMMA_SOURCE_FILE_AT_LINE (176)) ;
          } break ;
        case 8 : {
          GGS_lstring  var_cas_app ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACCESSING_5F_APPLICATION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_5F_token (var_cas_app) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_4879_0 ;
          nt_description_ (inLexique, automatic_var_4879_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_acc_apps,  var_cas_app,  GGS_string ("ACCESSING_APPLICATION") COMMA_SOURCE_FILE_AT_LINE (180)) ;
          } break ;
        case 9 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_counter_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_5052_0 ;
          nt_description_ (inLexique, automatic_var_5052_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'counter_type_attrs'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_counter::rule_goil_5F_obj_5F_counter_counter_5F_type_5F_attrs_i2_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_counter_type  &var_cas_type) {
  switch (select_goil_5F_obj_5F_counter_3 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_SOFTWARE) COMMA_HERE) ;
      var_cas_type = GGS_software_counter ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (191)) ;
      } break ;
    case 2 : {
      GGS_time_constants  var_cas_tc = GGS_time_constants ::constructor_emptyList () ;
      GGS_counter_driver  var_cas_cd = GGS_void_driver ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (194)) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_HARDWARE) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
      { bool syntaxRepeat_4 = true ;
        while (syntaxRepeat_4) {
          switch (select_goil_5F_obj_5F_counter_4 (inLexique)) {
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_DRIVER) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              GGS_counter_driver  var_cas_cpt_cd ;
              switch (select_goil_5F_obj_5F_counter_5 (inLexique)) {
                case 1 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_OSINTERNAL) COMMA_HERE) ;
                  var_cas_cpt_cd = GGS_os_internal_driver ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (202)) ;
                  } break ;
                case 2 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_GPT) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
                  GGS_basic_type  var_cas_npht = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (205)) ;
                  GGS_lstring  var_cas_gcn = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (206)) ;
                  { bool syntaxRepeat_6 = true ;
                    while (syntaxRepeat_6) {
                      switch (select_goil_5F_obj_5F_counter_6 (inLexique)) {
                        case 2 : {
                          GGS_luint64  var_cas_ui ;
                          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NS_5F_PER_5F_HW_5F_TICK) COMMA_HERE) ;
                          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
                          inLexique.assignFromAttribute_integerNumber (var_cas_ui) ;
                          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
                          ::routine_set_uint64 (inLexique,  var_cas_npht,  var_cas_ui,  GGS_string ("NS_PER_HW_TICK") COMMA_SOURCE_FILE_AT_LINE (211)) ;
                          } break ;
                        case 3 : {
                          GGS_lstring  var_cas_cn ;
                          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_GPTCHANNELNAME) COMMA_HERE) ;
                          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
                          inLexique.assignFromAttribute_a_5F_string (var_cas_cn) ;
                          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_HERE) ;
                          ::routine_set_lstring_if_empty (inLexique,  var_cas_gcn,  var_cas_cn,  GGS_string ("GPTCHANNELNAME") COMMA_SOURCE_FILE_AT_LINE (215)) ;
                          } break ;
                        default :
                          syntaxRepeat_6 = false ;
                          break ;
                      }
                    }
                  }
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
                  { const GGS_basic_type _var_6119 = var_cas_npht ; // CAST instruction
                    if (_var_6119.getPtr () != NULL) {
                      macroValidPointer (_var_6119.getPtr ()) ;
                      if (typeid (cPtr_void) == typeid (* (_var_6119.getPtr ()))) {
                        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NS_PER_HW_TICK subattribute not defined for this hardware counter GPT") COMMA_SOURCE_FILE_AT_LINE (221)) ;
                      }else{
                      }
                    }
                  }
                  const GGS_bool cond_6270 = (var_cas_gcn.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (222))).operator_isEqual (GGS_string ("")) ;
                  if (cond_6270.isBuiltAndTrue ()) {
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("GPTCHANNELNAME subattribute not defined for this hardware counter GPT") COMMA_SOURCE_FILE_AT_LINE (224)) ;
                  }
                  var_cas_cpt_cd = GGS_gpt_driver ::constructor_new (inLexique, GGS_location (inLexique), var_cas_npht, var_cas_gcn COMMA_SOURCE_FILE_AT_LINE (225)) ;
                  } break ;
                default :
                  break ;
              }
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              { const GGS_counter_driver _var_6589 = var_cas_cd ; // CAST instruction
                if (_var_6589.getPtr () != NULL) {
                  macroValidPointer (_var_6589.getPtr ()) ;
                  if (typeid (cPtr_void_driver) == typeid (* (_var_6589.getPtr ()))) {
                    var_cas_cd = var_cas_cpt_cd ;
                  }else{
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("DRIVER subattribute already defined for this hardware counter") COMMA_SOURCE_FILE_AT_LINE (233)) ;
                    var_cas_cd.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (233)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (234)) ;
                  }
                }
              }
              } break ;
            case 3 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TIMECONSTANTS) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TIMECONSTANT) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
              GGS_basic_type  var_cas_ns = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (237)) ;
              GGS_lstring  var_cas_cn = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_SOURCE_FILE_AT_LINE (238)) ;
              { bool syntaxRepeat_7 = true ;
                while (syntaxRepeat_7) {
                  switch (select_goil_5F_obj_5F_counter_7 (inLexique)) {
                    case 2 : {
                      GGS_luint64  var_cas_ui ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NS) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
                      inLexique.assignFromAttribute_integerNumber (var_cas_ui) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
                      ::routine_set_uint64 (inLexique,  var_cas_ns,  var_cas_ui,  GGS_string ("NS") COMMA_SOURCE_FILE_AT_LINE (243)) ;
                      } break ;
                    case 3 : {
                      GGS_lstring  var_cas_c ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CONSTNAME) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
                      inLexique.assignFromAttribute_a_5F_string (var_cas_c) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_HERE) ;
                      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
                      ::routine_set_lstring_if_empty (inLexique,  var_cas_cn,  var_cas_c,  GGS_string ("CONSTNAME") COMMA_SOURCE_FILE_AT_LINE (247)) ;
                      } break ;
                    default :
                      syntaxRepeat_7 = false ;
                      break ;
                  }
                }
              }
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              var_cas_tc.addAssign_operation (var_cas_ns, var_cas_cn) ;
              } break ;
            default :
              syntaxRepeat_4 = false ;
              break ;
          }
        }
      }
      inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
      var_cas_type = GGS_hardware_counter ::constructor_new (inLexique, GGS_location (inLexique), var_cas_cd, var_cas_tc COMMA_SOURCE_FILE_AT_LINE (253)) ;
      } break ;
    default :
      break ;
  }
}

//---------------------------------------------------------------------------*


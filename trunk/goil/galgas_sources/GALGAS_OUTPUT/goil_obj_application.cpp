//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_obj_application.cpp'                       *
//                        Generated by version 1.9.1                         *
//                    september 21th, 2009, at 18h19'1"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 572
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_application.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_application.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of production rule 'appli'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_application::
pr_appli_goil_obj_application_41_12_ (goil_lexique & inLexique,
                                GGS_app_map  &var_cas_applis) {
  GGS_lstring  var_cas_name ;
  GGS_lstring  var_cas_desc ;
  GGS_app_obj  var_cas_app ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_APPLICATION) COMMA_HERE) ;
  if (((gOption_goil_5F_options_autosar_5F_on.value ()).operator_isEqual (GGS_bool (false))).isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("AUTOSAR flag is off, turn it on to use APPLICATION objects") COMMA_SOURCE_FILE_AT_LINE (52)) ;
  }
  inLexique.assignFromAttribute_att_token (var_cas_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  if ((var_cas_applis.reader_hasKey (inLexique, var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (55)) COMMA_SOURCE_FILE_AT_LINE (55))).isBuiltAndTrue ()) {
    var_cas_applis.modifier_del (inLexique, var_cas_name, var_cas_app COMMA_SOURCE_FILE_AT_LINE (56)) ;
  }else{
    var_cas_app = GGS_app_obj ::constructor_new (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), GGS_app_trusted_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE), GGS_ident_map ::constructor_emptyMap (inLexique COMMA_HERE) COMMA_HERE) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  nt_app_attributes_ (inLexique, var_cas_app, var_cas_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
  var_cas_applis.modifier_put (inLexique, var_cas_name, var_cas_app COMMA_SOURCE_FILE_AT_LINE (81)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of production rule 'app_attributes'             *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_application::
pr_app_attributes_goil_obj_application_85_21_ (goil_lexique & inLexique,
                                GGS_app_obj  &var_cas_app,
                                GGS_lstring  var_cas_name) {
  GGS_app_trusted_obj  var_cas_trusted ;
  var_cas_trusted = var_cas_app.reader_trusted (inLexique COMMA_SOURCE_FILE_AT_LINE (89)) ;
  GGS_basic_type  var_cas_startuphook ;
  var_cas_startuphook = var_cas_app.reader_startuphook (inLexique COMMA_SOURCE_FILE_AT_LINE (90)) ;
  GGS_basic_type  var_cas_shutdownhook ;
  var_cas_shutdownhook = var_cas_app.reader_shutdownhook (inLexique COMMA_SOURCE_FILE_AT_LINE (91)) ;
  GGS_basic_type  var_cas_errorhook ;
  var_cas_errorhook = var_cas_app.reader_errorhook (inLexique COMMA_SOURCE_FILE_AT_LINE (92)) ;
  GGS_basic_type  var_cas_restart ;
  var_cas_restart = var_cas_app.reader_restart (inLexique COMMA_SOURCE_FILE_AT_LINE (93)) ;
  GGS_ident_map  var_cas_tasks ;
  var_cas_tasks = var_cas_app.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (94)) ;
  GGS_ident_map  var_cas_isrs ;
  var_cas_isrs = var_cas_app.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (95)) ;
  GGS_ident_map  var_cas_alarms ;
  var_cas_alarms = var_cas_app.reader_alarms (inLexique COMMA_SOURCE_FILE_AT_LINE (96)) ;
  GGS_ident_map  var_cas_schedtables ;
  var_cas_schedtables = var_cas_app.reader_schedtables (inLexique COMMA_SOURCE_FILE_AT_LINE (97)) ;
  GGS_ident_map  var_cas_counters ;
  var_cas_counters = var_cas_app.reader_counters (inLexique COMMA_SOURCE_FILE_AT_LINE (98)) ;
  GGS_ident_map  var_cas_resources ;
  var_cas_resources = var_cas_app.reader_resources (inLexique COMMA_SOURCE_FILE_AT_LINE (99)) ;
  GGS_ident_map  var_cas_messages ;
  var_cas_messages = var_cas_app.reader_messages (inLexique COMMA_SOURCE_FILE_AT_LINE (100)) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_obj_application_0 (inLexique)) {
        case 2 : {
          GGS_app_trusted_obj  var_cas_trust ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUSTED) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              nt_trusted_fcts_ (inLexique, var_cas_trust) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_trust = GGS_app_trusted_false ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          GGS_lstring  automatic_var_0 ;
          nt_description_ (inLexique, automatic_var_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          { const GGS_app_trusted_obj _var_3173 = var_cas_trusted ; // CAST instruction
            if (_var_3173.getPtr () != NULL) {
              macroValidPointer (_var_3173.getPtr ()) ;
              if (typeid (cPtr_app_trusted_void) == typeid (* (_var_3173.getPtr ()))) {
                var_cas_trusted = var_cas_trust ;
              }else{
                var_cas_trust.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (116)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("TRUSTED attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (116))) COMMA_SOURCE_FILE_AT_LINE (117)) ;
                var_cas_trusted.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (117)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (118)) ;
              }
            }
          }
          } break ;
        case 3 : {
          GGS_bool var_cas_sh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STARTUPHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_2 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_3645 = var_cas_startuphook ; // CAST instruction
            if (_var_3645.getPtr () != NULL) {
              macroValidPointer (_var_3645.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_3645.getPtr ()))) {
                var_cas_startuphook = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_sh COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("STARTUPHOOK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (130))) COMMA_SOURCE_FILE_AT_LINE (131)) ;
                var_cas_startuphook.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (131)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (132)) ;
              }
            }
          }
          GGS_lstring  automatic_var_1 ;
          nt_description_ (inLexique, automatic_var_1) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 4 : {
          GGS_bool var_cas_sh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SHUTDOWNHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_3 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_sh = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_4154 = var_cas_shutdownhook ; // CAST instruction
            if (_var_4154.getPtr () != NULL) {
              macroValidPointer (_var_4154.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_4154.getPtr ()))) {
                var_cas_shutdownhook = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_sh COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("SHUTDOWNHOOK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (145))) COMMA_SOURCE_FILE_AT_LINE (146)) ;
                var_cas_shutdownhook.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (146)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (147)) ;
              }
            }
          }
          GGS_lstring  automatic_var_2 ;
          nt_description_ (inLexique, automatic_var_2) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 5 : {
          GGS_bool var_cas_eh ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ERRORHOOK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_4 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              var_cas_eh = GGS_bool (true) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_eh = GGS_bool (false) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_4649 = var_cas_errorhook ; // CAST instruction
            if (_var_4649.getPtr () != NULL) {
              macroValidPointer (_var_4649.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_4649.getPtr ()))) {
                var_cas_errorhook = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_eh COMMA_HERE) ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("ERRORHOOK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (160))) COMMA_SOURCE_FILE_AT_LINE (161)) ;
                var_cas_errorhook.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (161)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (162)) ;
              }
            }
          }
          GGS_lstring  automatic_var_3 ;
          nt_description_ (inLexique, automatic_var_3) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 6 : {
          GGS_basic_type  var_cas_hr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_HAS_5F_RESTARTTASK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          switch (select_goil_obj_application_5 (inLexique)) {
            case 1 : {
              GGS_lstring  var_cas_res_task ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESTARTTASK) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
              inLexique.assignFromAttribute_att_token (var_cas_res_task) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
              var_cas_hr = GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_res_task.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (170)) COMMA_HERE) ;
              } break ;
            case 2 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
              var_cas_hr = GGS_bool_class ::constructor_new (inLexique, GGS_location (inLexique), GGS_bool (false) COMMA_HERE) ;
              } break ;
            default :
              break ;
          }
          { const GGS_basic_type _var_5306 = var_cas_restart ; // CAST instruction
            if (_var_5306.getPtr () != NULL) {
              macroValidPointer (_var_5306.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_5306.getPtr ()))) {
                var_cas_restart = var_cas_hr ;
              }else{
                GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("RESTARTTASK attribute already defined for Application ")).operator_concat (var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (178))) COMMA_SOURCE_FILE_AT_LINE (179)) ;
                var_cas_restart.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (179)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Was previously define here") COMMA_SOURCE_FILE_AT_LINE (180)) ;
              }
            }
          }
          GGS_lstring  automatic_var_4 ;
          nt_description_ (inLexique, automatic_var_4) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 7 : {
          GGS_lstring  var_cas_task ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TASK) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_task) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_tasks.modifier_put (inLexique, var_cas_task, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_task.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (185)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (185)) ;
          GGS_lstring  automatic_var_5 ;
          nt_description_ (inLexique, automatic_var_5) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 8 : {
          GGS_lstring  var_cas_isr ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ISR) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_isr) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_isrs.modifier_put (inLexique, var_cas_isr, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_isr.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (190)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (190)) ;
          GGS_lstring  automatic_var_6 ;
          nt_description_ (inLexique, automatic_var_6) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 9 : {
          GGS_lstring  var_cas_alarm ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ALARM) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_alarm) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_alarms.modifier_put (inLexique, var_cas_alarm, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_alarm.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (195)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (195)) ;
          GGS_lstring  automatic_var_7 ;
          nt_description_ (inLexique, automatic_var_7) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 10 : {
          GGS_lstring  var_cas_st ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SCHEDULETABLE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_st) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_schedtables.modifier_put (inLexique, var_cas_st, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_st.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (200)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (200)) ;
          GGS_lstring  automatic_var_8 ;
          nt_description_ (inLexique, automatic_var_8) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 11 : {
          GGS_lstring  var_cas_ct ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_COUNTER) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_ct) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_counters.modifier_put (inLexique, var_cas_ct, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_ct.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (205)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (205)) ;
          GGS_lstring  automatic_var_9 ;
          nt_description_ (inLexique, automatic_var_9) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 12 : {
          GGS_lstring  var_cas_rez ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RESOURCE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_rez) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_resources.modifier_put (inLexique, var_cas_rez, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_rez.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (210)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (210)) ;
          GGS_lstring  automatic_var_10 ;
          nt_description_ (inLexique, automatic_var_10) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        case 13 : {
          GGS_lstring  var_cas_mes ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MESSAGE) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_token (var_cas_mes) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
          var_cas_messages.modifier_put (inLexique, var_cas_mes, GGS_string_class ::constructor_new (inLexique, GGS_location (inLexique), var_cas_mes.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (215)) COMMA_HERE) COMMA_SOURCE_FILE_AT_LINE (215)) ;
          GGS_lstring  automatic_var_11 ;
          nt_description_ (inLexique, automatic_var_11) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  var_cas_app = GGS_app_obj ::constructor_new (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), var_cas_trusted, var_cas_startuphook, var_cas_shutdownhook, var_cas_errorhook, var_cas_restart, var_cas_tasks, var_cas_isrs, var_cas_alarms, var_cas_schedtables, var_cas_counters, var_cas_resources, var_cas_messages COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'trusted_fcts'              *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_application::
pr_trusted_fcts_goil_obj_application_237_19_ (goil_lexique & inLexique,
                                GGS_app_trusted_obj  &var_cas_trust_attr) {
  GGS_stringset  var_cas_t_funcs ;
  var_cas_t_funcs = GGS_stringset ::constructor_emptySet () ;
  switch (select_goil_obj_application_6 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
      { bool syntaxRepeat_7 = true ;
        while (syntaxRepeat_7) {
          switch (select_repeat_goil_obj_application_7 (inLexique)) {
            case 2 : {
              GGS_lstring  var_cas_f_name ;
              var_cas_f_name = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUSTED_5F_FUNCTION) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
              GGS_bool var_cas_tfok ;
              var_cas_tfok = GGS_bool (false) ;
              switch (select_goil_obj_application_8 (inLexique)) {
                case 1 : {
                  inLexique.assignFromAttribute_att_token (var_cas_f_name) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  var_cas_tfok = GGS_bool (true) ;
                  } break ;
                case 2 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_TRUE) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_NAME) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
                  inLexique.assignFromAttribute_a_string (var_cas_f_name) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_string) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
                  var_cas_tfok = GGS_bool (true) ;
                  } break ;
                case 3 : {
                  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_FALSE) COMMA_HERE) ;
                  } break ;
                default :
                  break ;
              }
              if ((var_cas_tfok).isBuiltAndTrue ()) {
                var_cas_t_funcs._addAssign_operation (var_cas_f_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (257))) ;
              }
              } break ;
            default :
              syntaxRepeat_7 = false ;
              break ;
          }
        }
      }
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
      } break ;
    case 2 : {
      } break ;
    default :
      break ;
  }
  var_cas_trust_attr = GGS_app_trusted_true ::constructor_new (inLexique, GGS_location (inLexique), var_cas_t_funcs COMMA_HERE) ;
}

//---------------------------------------------------------------------------*


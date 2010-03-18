//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_obj_resource.cpp'                        *
//                       Generated by version 1.9.10                         *
//                      march 18th, 2010, at 9h49'22"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 688
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_resource.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_resource.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of production rule 'resource'                *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_resource::rule_goil_5F_obj_5F_resource_resource_i0_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_resource_map  &var_cas_resources) {
  GGS_resource_obj  var_cas_resource ;
  GGS_lstring  var_cas_resource_name ;
  GGS_resource_property_obj  var_cas_property ;
  GGS_lstringlist  var_cas_acc_apps ;
  GGS_lstring  var_cas_desc ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_RESOURCE) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_5F_token (var_cas_resource_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  const GGS_bool cond_1237 = (var_cas_resource_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (54))).operator_isEqual (GGS_string ("res_sched")) ;
  if (cond_1237.isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("'res_sched' is a reserved name of the scheduler resource") COMMA_SOURCE_FILE_AT_LINE (56)) ;
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  const GGS_bool cond_1358 = var_cas_resources.reader_hasKey (var_cas_resource_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (58))) ;
  if (cond_1358.isBuiltAndTrue ()) {
    var_cas_resources.modifier_del (inLexique, var_cas_resource_name, var_cas_resource COMMA_SOURCE_FILE_AT_LINE (59)) ;
  }else if (cond_1358.isBuiltAndFalse ()) {
    var_cas_resource = function_default_resource_obj (inLexique COMMA_SOURCE_FILE_AT_LINE (61)) ;
  }
  var_cas_property = var_cas_resource.reader_property (inLexique COMMA_SOURCE_FILE_AT_LINE (63)) ;
  var_cas_acc_apps = var_cas_resource.reader_acc_apps (inLexique COMMA_SOURCE_FILE_AT_LINE (64)) ;
  var_cas_desc = var_cas_resource.reader_desc (inLexique COMMA_SOURCE_FILE_AT_LINE (65)) ;
  nt_resource_5F_attributes_ (inLexique, var_cas_property, var_cas_acc_apps) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  nt_description_ (inLexique, var_cas_desc) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
  var_cas_resource = GGS_resource_obj ::constructor_new (inLexique, var_cas_desc, var_cas_property, var_cas_acc_apps COMMA_HERE) ;
  var_cas_resources.modifier_put (inLexique, var_cas_resource_name, var_cas_resource COMMA_SOURCE_FILE_AT_LINE (70)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of production rule 'resource_attributes'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_resource::rule_goil_5F_obj_5F_resource_resource_5F_attributes_i1_ (C_Lexique_goil_5F_lexique & inLexique,
                                GGS_resource_property_obj  &var_cas_property,
                                GGS_lstringlist  &var_cas_acc_apps) {
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_resource_0 (inLexique)) {
        case 2 : {
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_RESOURCEPROPERTY) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          switch (select_goil_5F_obj_5F_resource_1 (inLexique)) {
            case 1 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STANDARD) COMMA_HERE) ;
              { const GGS_resource_property_obj _var_2202 = var_cas_property ; // CAST instruction
                if (_var_2202.getPtr () != NULL) {
                  macroValidPointer (_var_2202.getPtr ()) ;
                  if (typeid (cPtr_resource_property_void_obj) == typeid (* (_var_2202.getPtr ()))) {
                    var_cas_property = GGS_resource_property_standard_obj ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
                  }else{
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("RESOURCEPROPERTY attribute already defined for this resource") COMMA_SOURCE_FILE_AT_LINE (87)) ;
                    var_cas_property.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (87)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was already defined here") COMMA_SOURCE_FILE_AT_LINE (88)) ;
                  }
                }
              }
              } break ;
            case 2 : {
              GGS_lstring  var_cas_linked_resource ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_LINKED) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_LINKEDRESOURCE) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
              inLexique.assignFromAttribute_att_5F_token (var_cas_linked_resource) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
              { const GGS_resource_property_obj _var_2654 = var_cas_property ; // CAST instruction
                if (_var_2654.getPtr () != NULL) {
                  macroValidPointer (_var_2654.getPtr ()) ;
                  if (typeid (cPtr_resource_property_void_obj) == typeid (* (_var_2654.getPtr ()))) {
                    var_cas_property = GGS_resource_property_linked_obj ::constructor_new (inLexique, GGS_location (inLexique), var_cas_linked_resource COMMA_HERE) ;
                  }else{
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("RESOURCEPROPERTY attribute already defined for this resource") COMMA_SOURCE_FILE_AT_LINE (97)) ;
                    var_cas_property.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (97)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was already defined here") COMMA_SOURCE_FILE_AT_LINE (98)) ;
                  }
                }
              }
              } break ;
            case 3 : {
              inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INTERNAL) COMMA_HERE) ;
              { const GGS_resource_property_obj _var_2990 = var_cas_property ; // CAST instruction
                if (_var_2990.getPtr () != NULL) {
                  macroValidPointer (_var_2990.getPtr ()) ;
                  if (typeid (cPtr_resource_property_void_obj) == typeid (* (_var_2990.getPtr ()))) {
                    var_cas_property = GGS_resource_property_internal_obj ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
                  }else{
                    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("RESOURCEPROPERTY attribute already defined for this resource") COMMA_SOURCE_FILE_AT_LINE (106)) ;
                    var_cas_property.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (106)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was already defined here") COMMA_SOURCE_FILE_AT_LINE (107)) ;
                  }
                }
              }
              } break ;
            default :
              break ;
          }
          } break ;
        case 3 : {
          GGS_lstring  var_cas_app ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ACCESSING_5F_APPLICATION) COMMA_HERE) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_HERE) ;
          inLexique.assignFromAttribute_att_5F_token (var_cas_app) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
          GGS_lstring  automatic_var_3106_0 ;
          nt_description_ (inLexique, automatic_var_3106_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          ::routine_add_lstring_unique (inLexique,  var_cas_acc_apps,  var_cas_app,  GGS_string ("ACCESSING_APPLICATION") COMMA_SOURCE_FILE_AT_LINE (112)) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  GGS_lstring  automatic_var_3214_0 ;
  nt_description_ (inLexique, automatic_var_3214_0) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*


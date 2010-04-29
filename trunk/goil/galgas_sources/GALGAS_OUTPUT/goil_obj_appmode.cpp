//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_obj_appmode.cpp'                         *
//                       Generated by version 1.9.11                         *
//                      april 29th, 2010, at 10h36'25"                       *
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
#include "goil_obj_appmode.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_appmode.gSyntax", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of production rule 'appmode'                 *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_appmode::rule_goil_5F_obj_5F_appmode_appmode_i0_ (C_Lexique_goil_5F_lexique & inLexique) {
  GGS_ident_map  var_cas_others = GGS_ident_map ::constructor_emptyMap (inLexique COMMA_SOURCE_FILE_AT_LINE (36)) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_APPMODE) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_goil_5F_obj_5F_appmode_0 (inLexique)) {
        case 2 : {
          nt_free_5F_field_ (inLexique, var_cas_others) ;
          GGS_lstring  automatic_var_891_0 ;
          nt_description_ (inLexique, automatic_var_891_0) ;
          inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_HERE) ;
  GGS_lstring  automatic_var_947_0 ;
  nt_description_ (inLexique, automatic_var_947_0) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                    File 'goil_obj_networkmessage.cpp'                     *
//                        Generated by version 1.9.3                         *
//                     november 10th, 2009, at 15h4'52"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 598
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_obj_networkmessage.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_obj_networkmessage.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'networkmess'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_networkmess_goil_obj_networkmessage_57_18_ (goil_lexique & inLexique,
                                GGS_netmess_map  &var_cas_netmess) {
  GGS_netmess_obj  var_cas_nm ;
  GGS_lstring  var_cas_name ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_NETWORKMESSAGE) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_token (var_cas_name) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  const GGS_bool cond_1606 = var_cas_netmess.reader_hasKey (inLexique, var_cas_name.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (65)) COMMA_SOURCE_FILE_AT_LINE (65)) ;
  if (cond_1606.isBuiltAndTrue ()) {
    var_cas_netmess.modifier_del (inLexique, var_cas_name, var_cas_nm COMMA_SOURCE_FILE_AT_LINE (66)) ;
  }else if (cond_1606.isBuiltAndFalse ()) {
    var_cas_nm = GGS_netmess_obj ::constructor_new (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), GGS_void_netprop ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) COMMA_HERE) ;
  }
  GGS_lstring  var_cas_ipdu = var_cas_nm.reader_ipdu (inLexique COMMA_SOURCE_FILE_AT_LINE (75)) ;
  GGS_base_netprop  var_cas_netprop = var_cas_nm.reader_netprop (inLexique COMMA_SOURCE_FILE_AT_LINE (76)) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_0 = true ;
    while (syntaxRepeat_0) {
      switch (select_repeat_goil_obj_networkmessage_0 (inLexique)) {
        case 2 : {
          nt_ipdu_ref_ (inLexique, var_cas_ipdu) ;
          } break ;
        case 3 : {
          nt_net_messageproperty_ (inLexique, var_cas_netprop) ;
          } break ;
        default :
          syntaxRepeat_0 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  GGS_lstring  automatic_var_0 ;
  nt_description_ (inLexique, automatic_var_0) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
  var_cas_nm = GGS_netmess_obj ::constructor_new (inLexique, GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE), var_cas_ipdu, var_cas_netprop COMMA_HERE) ;
  var_cas_netmess.modifier_put (inLexique, var_cas_name, var_cas_nm COMMA_SOURCE_FILE_AT_LINE (91)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of production rule 'ipdu_ref'                *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_ipdu_ref_goil_obj_networkmessage_94_15_ (goil_lexique & inLexique,
                                GGS_lstring  &var_cas_ipdu) {
  GGS_lstring  var_cas_ip ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_IPDU) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  inLexique.assignFromAttribute_att_token (var_cas_ip) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_idf) COMMA_HERE) ;
  const GGS_bool cond_2312 = (var_cas_ipdu.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (99))).operator_isNotEqual (GGS_string ("")) ;
  if (cond_2312.isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("IPDU is already defined for this network message") COMMA_SOURCE_FILE_AT_LINE (101)) ;
    var_cas_ipdu.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("wad defined here") COMMA_SOURCE_FILE_AT_LINE (102)) ;
  }else if (cond_2312.isBuiltAndFalse ()) {
    var_cas_ipdu = var_cas_ip ;
  }
  GGS_lstring  automatic_var_1 ;
  nt_description_ (inLexique, automatic_var_1) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of production rule 'net_messageproperty'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_net_messageproperty_goil_obj_networkmessage_108_26_ (goil_lexique & inLexique,
                                GGS_base_netprop  &var_cas_netprop) {
  GGS_base_netprop  var_cas_nn ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MESSAGEPROPERTY) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  switch (select_goil_obj_networkmessage_1 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_STATIC) COMMA_HERE) ;
      nt_static_mp_ (inLexique, var_cas_nn) ;
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_DYNAMIC) COMMA_HERE) ;
      nt_dynamic_mp_ (inLexique, var_cas_nn) ;
      } break ;
    case 3 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_ZERO) COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
      GGS_lstring  var_cas_dir ;
      nt_direction_ (inLexique, var_cas_dir) ;
      var_cas_nn = GGS_zero_netprop ::constructor_new (inLexique, GGS_location (inLexique), var_cas_dir COMMA_HERE) ;
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  { const GGS_base_netprop _var_3139 = var_cas_netprop ; // CAST instruction
    if (_var_3139.getPtr () != NULL) {
      macroValidPointer (_var_3139.getPtr ()) ;
      if (typeid (cPtr_void_netprop) == typeid (* (_var_3139.getPtr ()))) {
        var_cas_netprop = var_cas_nn ;
      }else{
        GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("MESSAGEPROPERTY is already defined") COMMA_SOURCE_FILE_AT_LINE (135)) ;
        var_cas_netprop.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (135)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (136)) ;
      }
    }
  }
  GGS_lstring  automatic_var_2 ;
  nt_description_ (inLexique, automatic_var_2) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'static_mp'                *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_static_mp_goil_obj_networkmessage_140_16_ (goil_lexique & inLexique,
                                GGS_base_netprop  &var_cas_netprop) {
  GGS_lsint  var_cas_sizeinbits = GGS_lsint ::constructor_new (inLexique, GGS_sint (1L).operator_unary_minus (inLexique COMMA_HERE), GGS_location (inLexique) COMMA_HERE) ;
  GGS_lstring  var_cas_bitordering = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
  GGS_lsint  var_cas_bitposition = GGS_lsint ::constructor_new (inLexique, GGS_sint (1L).operator_unary_minus (inLexique COMMA_HERE), GGS_location (inLexique) COMMA_HERE) ;
  GGS_lstring  var_cas_datainterpretation = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
  GGS_basic_type  var_cas_initialvalue = GGS_void ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
  GGS_lstring  var_cas_direction = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
  GGS_location  var_cas_where = GGS_location (inLexique) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_2 = true ;
    while (syntaxRepeat_2) {
      switch (select_repeat_goil_obj_networkmessage_2 (inLexique)) {
        case 2 : {
          GGS_luint64  var_cas_sib ;
          nt_sizeinbits_ (inLexique, var_cas_sib) ;
          const GGS_bool cond_3761 = (var_cas_sizeinbits.reader_sint (inLexique COMMA_SOURCE_FILE_AT_LINE (156))).operator_isEqual (GGS_sint (1L).operator_unary_minus (inLexique COMMA_HERE)) ;
          if (cond_3761.isBuiltAndTrue ()) {
            var_cas_sizeinbits = GGS_lsint ::constructor_new (inLexique, var_cas_sib.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (157)).reader_sint (inLexique COMMA_SOURCE_FILE_AT_LINE (157)), GGS_location (inLexique) COMMA_HERE) ;
          }else if (cond_3761.isBuiltAndFalse ()) {
            var_cas_sib.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("SIZEINBITS is already defined") COMMA_SOURCE_FILE_AT_LINE (160)) ;
            var_cas_sizeinbits.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (161)) ;
          }
          } break ;
        case 3 : {
          GGS_lstring  var_cas_bo ;
          nt_bitordering_ (inLexique, var_cas_bo) ;
          const GGS_bool cond_3995 = (var_cas_bitordering.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (166))).operator_isEqual (GGS_string ("")) ;
          if (cond_3995.isBuiltAndTrue ()) {
            var_cas_bitordering = var_cas_bo ;
          }else if (cond_3995.isBuiltAndFalse ()) {
            var_cas_bo.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("BITORDERING is already defined") COMMA_SOURCE_FILE_AT_LINE (170)) ;
            var_cas_bitordering.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was define here") COMMA_SOURCE_FILE_AT_LINE (171)) ;
          }
          } break ;
        case 4 : {
          GGS_luint64  var_cas_bp ;
          nt_bitposition_ (inLexique, var_cas_bp) ;
          const GGS_bool cond_4264 = (var_cas_bitposition.reader_sint (inLexique COMMA_SOURCE_FILE_AT_LINE (176))).operator_isEqual (GGS_sint (1L).operator_unary_minus (inLexique COMMA_HERE)) ;
          if (cond_4264.isBuiltAndTrue ()) {
            var_cas_bitposition = GGS_lsint ::constructor_new (inLexique, var_cas_bp.reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (177)).reader_sint (inLexique COMMA_SOURCE_FILE_AT_LINE (177)), GGS_location (inLexique) COMMA_HERE) ;
          }else if (cond_4264.isBuiltAndFalse ()) {
            var_cas_bp.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("BITPOSITION is already defined") COMMA_SOURCE_FILE_AT_LINE (180)) ;
            var_cas_bitposition.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (181)) ;
          }
          } break ;
        case 5 : {
          GGS_lstring  var_cas_di ;
          nt_datainterpretation_ (inLexique, var_cas_di) ;
          const GGS_bool cond_4520 = (var_cas_datainterpretation.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (186))).operator_isEqual (GGS_string ("")) ;
          if (cond_4520.isBuiltAndTrue ()) {
            var_cas_datainterpretation = var_cas_di ;
          }else if (cond_4520.isBuiltAndFalse ()) {
            var_cas_di.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("DATAINTERPRETATION is already defined") COMMA_SOURCE_FILE_AT_LINE (190)) ;
            var_cas_datainterpretation.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was define here") COMMA_SOURCE_FILE_AT_LINE (191)) ;
          }
          } break ;
        case 6 : {
          GGS_basic_type  var_cas_iv ;
          nt_initialvalue_ (inLexique, var_cas_iv) ;
          { const GGS_basic_type _var_4898 = var_cas_initialvalue ; // CAST instruction
            if (_var_4898.getPtr () != NULL) {
              macroValidPointer (_var_4898.getPtr ()) ;
              if (typeid (cPtr_void) == typeid (* (_var_4898.getPtr ()))) {
                var_cas_initialvalue = var_cas_iv ;
              }else{
                var_cas_iv.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (199)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("INITIALVALUE already defined") COMMA_SOURCE_FILE_AT_LINE (200)) ;
                var_cas_initialvalue.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (200)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was defined here") COMMA_SOURCE_FILE_AT_LINE (201)) ;
              }
            }
          }
          } break ;
        case 7 : {
          GGS_lstring  var_cas_dir ;
          nt_direction_ (inLexique, var_cas_dir) ;
          const GGS_bool cond_5027 = (var_cas_direction.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (206))).operator_isEqual (GGS_string ("")) ;
          if (cond_5027.isBuiltAndTrue ()) {
            var_cas_direction = var_cas_dir ;
          }else if (cond_5027.isBuiltAndFalse ()) {
            var_cas_dir.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("DIRECTION is already defined") COMMA_SOURCE_FILE_AT_LINE (210)) ;
            var_cas_direction.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("was define here") COMMA_SOURCE_FILE_AT_LINE (211)) ;
          }
          } break ;
        default :
          syntaxRepeat_2 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  const GGS_bool cond_5289 = (var_cas_direction.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (217))).operator_isEqual (GGS_string ("")) ;
  if (cond_5289.isBuiltAndTrue ()) {
    GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("DIRECTION attribute is missing") COMMA_SOURCE_FILE_AT_LINE (219)) ;
  }
  GGS_luint64  var_cas_iv ;
  { const GGS_basic_type _var_5467 = var_cas_initialvalue ; // CAST instruction
    if (_var_5467.getPtr () != NULL) {
      macroValidPointer (_var_5467.getPtr ()) ;
      if (typeid (cPtr_uint64_class) == typeid (* (_var_5467.getPtr ()))) {
        const GGS_uint64_class var_cas_ui (_var_5467.getPtr ()) ;
        var_cas_iv = GGS_luint64 ::constructor_new (inLexique, var_cas_ui.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (224)), var_cas_ui.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (224)) COMMA_HERE) ;
      }else{
        var_cas_iv = GGS_luint64 ::constructor_new (inLexique, GGS_uint64 (0ULL), GGS_location (inLexique) COMMA_HERE) ;
      }
    }
  }
  var_cas_netprop = GGS_static_netprop ::constructor_new (inLexique, var_cas_where, var_cas_sizeinbits, var_cas_bitordering, var_cas_bitposition, var_cas_datainterpretation, var_cas_iv, var_cas_direction COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'dynamic_mp'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_dynamic_mp_goil_obj_networkmessage_241_17_ (goil_lexique & inLexique,
                                GGS_base_netprop  &var_cas_netprop) {
  GGS_location (inLexique).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("DYNAMIC network messages are not supported") COMMA_SOURCE_FILE_AT_LINE (245)) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7B_) COMMA_HERE) ;
  { bool syntaxRepeat_3 = true ;
    while (syntaxRepeat_3) {
      switch (select_repeat_goil_obj_networkmessage_3 (inLexique)) {
        case 2 : {
          GGS_luint64  automatic_var_3 ;
          nt_maxsizeinbits_ (inLexique, automatic_var_3) ;
          } break ;
        case 3 : {
          GGS_lstring  automatic_var_4 ;
          nt_bitordering_ (inLexique, automatic_var_4) ;
          } break ;
        case 4 : {
          GGS_luint64  automatic_var_5 ;
          nt_bitposition_ (inLexique, automatic_var_5) ;
          } break ;
        case 5 : {
          GGS_basic_type  automatic_var_6 ;
          nt_initialvalue_ (inLexique, automatic_var_6) ;
          } break ;
        case 6 : {
          GGS_lstring  automatic_var_7 ;
          nt_direction_ (inLexique, automatic_var_7) ;
          } break ;
        default :
          syntaxRepeat_3 = false ;
          break ;
      }
    }
  }
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__7D_) COMMA_HERE) ;
  var_cas_netprop = GGS_void_netprop ::constructor_new (inLexique, GGS_location (inLexique) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'sizeinbits'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_sizeinbits_goil_obj_networkmessage_257_17_ (goil_lexique & inLexique,
                                GGS_luint64  &var_cas_sib) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SIZEINBITS) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  inLexique.assignFromAttribute_integerNumber (var_cas_sib) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
  GGS_lstring  automatic_var_8 ;
  nt_description_ (inLexique, automatic_var_8) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of production rule 'maxsizeinbits'              *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_maxsizeinbits_goil_obj_networkmessage_266_20_ (goil_lexique & inLexique,
                                GGS_luint64  &var_cas_msib) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_MAXSIZEINBITS) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  inLexique.assignFromAttribute_integerNumber (var_cas_msib) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
  GGS_lstring  automatic_var_9 ;
  nt_description_ (inLexique, automatic_var_9) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'bitordering'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_bitordering_goil_obj_networkmessage_275_18_ (goil_lexique & inLexique,
                                GGS_lstring  &var_cas_bo) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_BITORDERING) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  switch (select_goil_obj_networkmessage_4 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_BIGENDIAN) COMMA_HERE) ;
      var_cas_bo = GGS_lstring ::constructor_new (inLexique, GGS_string ("big"), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_LITTLEENDIAN) COMMA_HERE) ;
      var_cas_bo = GGS_lstring ::constructor_new (inLexique, GGS_string ("little"), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  GGS_lstring  automatic_var_10 ;
  nt_description_ (inLexique, automatic_var_10) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of production rule 'bitposition'               *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_bitposition_goil_obj_networkmessage_288_18_ (goil_lexique & inLexique,
                                GGS_luint64  &var_cas_bp) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_BITPOSITION) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  inLexique.assignFromAttribute_integerNumber (var_cas_bp) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_uint_5F_number) COMMA_HERE) ;
  GGS_lstring  automatic_var_11 ;
  nt_description_ (inLexique, automatic_var_11) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of production rule 'datainterpretation'           *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_datainterpretation_goil_obj_networkmessage_297_25_ (goil_lexique & inLexique,
                                GGS_lstring  &var_cas_di) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_DATAINTERPRETATION) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  switch (select_goil_obj_networkmessage_5 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_UNSIGNEDINTEGER) COMMA_HERE) ;
      var_cas_di = GGS_lstring ::constructor_new (inLexique, GGS_string ("unsignedinteger"), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_BYTEARRAY) COMMA_HERE) ;
      var_cas_di = GGS_lstring ::constructor_new (inLexique, GGS_string ("bytearray"), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  GGS_lstring  automatic_var_12 ;
  nt_description_ (inLexique, automatic_var_12) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of production rule 'direction'                *
//                                                                           *
//---------------------------------------------------------------------------*

void goil_obj_networkmessage::
pr_direction_goil_obj_networkmessage_310_16_ (goil_lexique & inLexique,
                                GGS_lstring  &var_cas_dir) {
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_DIRECTION) COMMA_HERE) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3D_) COMMA_HERE) ;
  switch (select_goil_obj_networkmessage_6 (inLexique)) {
    case 1 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_SENT) COMMA_HERE) ;
      var_cas_dir = GGS_lstring ::constructor_new (inLexique, GGS_string ("sent"), GGS_location (inLexique) COMMA_HERE) ;
      switch (select_goil_obj_networkmessage_7 (inLexique)) {
        case 1 : {
          GGS_lstring  automatic_var_13 ;
          nt_transferproperty_ (inLexique, automatic_var_13) ;
          } break ;
        case 2 : {
          } break ;
        default :
          break ;
      }
      } break ;
    case 2 : {
      inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1_RECEIVED) COMMA_HERE) ;
      var_cas_dir = GGS_lstring ::constructor_new (inLexique, GGS_string ("received"), GGS_location (inLexique) COMMA_HERE) ;
      } break ;
    default :
      break ;
  }
  GGS_lstring  automatic_var_14 ;
  nt_description_ (inLexique, automatic_var_14) ;
  inLexique.acceptTerminal (ACCEPT_TERMINAL (goil_lexique::goil_lexique_1__3B_) COMMA_HERE) ;
}

//---------------------------------------------------------------------------*


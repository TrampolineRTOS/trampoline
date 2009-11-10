//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'goil_message_verif.cpp'                        *
//                        Generated by version 1.9.3                         *
//                     november 10th, 2009, at 15h2'21"                      *
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
#include "goil_message_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_message_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of routine "check_net_dir"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_net_dir (C_Compiler & inLexique,
                                GGS_lstring   var_cas_net,
                                GGS_netmess_map   var_cas_netm,
                                GGS_string  var_cas_exp_dir COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_net_dir at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_netmess_obj  var_cas_nm ;
  GGS_lstring  var_cas_dir ;
  const GGS_netmess_map  temp_315 = var_cas_netm ;
  if (temp_315.isBuilt ()) {
    temp_315 (HERE)->method_get (inLexique, var_cas_net, var_cas_nm COMMA_SOURCE_FILE_AT_LINE (13)) ;
  }
  { const GGS_base_netprop _var_630 = var_cas_nm.reader_netprop (inLexique COMMA_SOURCE_FILE_AT_LINE (14)) ; // CAST instruction
    if (_var_630.getPtr () != NULL) {
      macroValidPointer (_var_630.getPtr ()) ;
      if (typeid (cPtr_static_netprop) == typeid (* (_var_630.getPtr ()))) {
        const GGS_static_netprop var_cas_sn (_var_630.getPtr ()) ;
        var_cas_dir = var_cas_sn.reader_direction (inLexique COMMA_SOURCE_FILE_AT_LINE (15)) ;
      }else if (typeid (cPtr_dynamic_netprop) == typeid (* (_var_630.getPtr ()))) {
        const GGS_dynamic_netprop var_cas_dn (_var_630.getPtr ()) ;
        var_cas_dir = var_cas_dn.reader_direction (inLexique COMMA_SOURCE_FILE_AT_LINE (16)) ;
      }else if (typeid (cPtr_zero_netprop) == typeid (* (_var_630.getPtr ()))) {
        const GGS_zero_netprop var_cas_zn (_var_630.getPtr ()) ;
        var_cas_dir = var_cas_zn.reader_direction (inLexique COMMA_SOURCE_FILE_AT_LINE (17)) ;
      }else{
        var_cas_dir = GGS_lstring ::constructor_new (inLexique, GGS_string (""), GGS_location (inLexique) COMMA_HERE) ;
        var_cas_nm.reader_netprop (inLexique COMMA_SOURCE_FILE_AT_LINE (20)).reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (20)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Internal error, unexpected type") COMMA_SOURCE_FILE_AT_LINE (21)) ;
      }
    }
  }
  const GGS_bool cond_884 = (var_cas_dir.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (22))).operator_isNotEqual (GGS_string ("")) ;
  if (cond_884.isBuiltAndTrue ()) {
    const GGS_bool cond_873 = (var_cas_dir.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (23))).operator_isNotEqual (var_cas_exp_dir) ;
    if (cond_873.isBuiltAndTrue ()) {
      var_cas_net.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("NETWORKMESSAGE does not have the DIRECTION = ")).operator_concat (var_cas_exp_dir.reader_uppercaseString (inLexique COMMA_SOURCE_FILE_AT_LINE (24)))).operator_concat (GGS_string (" attribute")) COMMA_SOURCE_FILE_AT_LINE (25)) ;
      var_cas_dir.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("DIRECTION attribute is defined here") COMMA_SOURCE_FILE_AT_LINE (26)) ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_net_dir\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "check_external_sent"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_sent (C_Compiler & inLexique,
                                GGS_lstring   var_cas_net,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_external_sent at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  const GGS_bool cond_1128 = (var_cas_netm.reader_hasKey (inLexique, var_cas_net.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (35)) COMMA_SOURCE_FILE_AT_LINE (35))).operator_not () ;
  if (cond_1128.isBuiltAndTrue ()) {
    var_cas_net.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("NETWORKMESSAGE ")).operator_concat (var_cas_net.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (36)))).operator_concat (GGS_string (" does not exist")) COMMA_SOURCE_FILE_AT_LINE (37)) ;
  }else if (cond_1128.isBuiltAndFalse ()) {
    ::routine_check_net_dir (inLexique,  var_cas_net,  var_cas_netm,  GGS_string ("sent") COMMA_SOURCE_FILE_AT_LINE (38)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_external_sent\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Implementation of routine "check_external_received"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_received (C_Compiler & inLexique,
                                GGS_lstring   var_cas_net,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_external_received at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  const GGS_bool cond_1421 = (var_cas_netm.reader_hasKey (inLexique, var_cas_net.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (47)) COMMA_SOURCE_FILE_AT_LINE (47))).operator_not () ;
  if (cond_1421.isBuiltAndTrue ()) {
    var_cas_net.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("NETWORKMESSAGE ")).operator_concat (var_cas_net.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (48)))).operator_concat (GGS_string (" does not exist")) COMMA_SOURCE_FILE_AT_LINE (49)) ;
  }else if (cond_1421.isBuiltAndFalse ()) {
    ::routine_check_net_dir (inLexique,  var_cas_net,  var_cas_netm,  GGS_string ("received") COMMA_SOURCE_FILE_AT_LINE (50)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_external_received\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "check_external_link_received"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_external_link_received (C_Compiler & inLexique,
                                GGS_link_obj   var_cas_link,
                                GGS_message_map   var_cas_messages,
                                GGS_netmess_map   var_cas_netm,
                                GGS_location   var_cas_link_ref,
                                GGS_uint   var_cas_depth COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_external_link_received at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  { const GGS_link_obj _var_3317 = var_cas_link ; // CAST instruction
    if (_var_3317.getPtr () != NULL) {
      macroValidPointer (_var_3317.getPtr ()) ;
      if (typeid (cPtr_true_link) == typeid (* (_var_3317.getPtr ()))) {
        const GGS_true_link var_cas_tl (_var_3317.getPtr ()) ;
        const GGS_bool cond_1916 = (var_cas_depth).operator_isEqual (GGS_uint (0U)) ;
        if (cond_1916.isBuiltAndTrue ()) {
          var_cas_link.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (64)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("This message is linked from another message.") COMMA_SOURCE_FILE_AT_LINE (65)) ;
          var_cas_link.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (65)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("So it should be linked to a network message.") COMMA_SOURCE_FILE_AT_LINE (66)) ;
          var_cas_link_ref.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Referencing message is here") COMMA_SOURCE_FILE_AT_LINE (67)) ;
        }else if (cond_1916.isBuiltAndFalse ()) {
          GGS_lstring  var_cas_mess = var_cas_tl.reader_receivemessage (inLexique COMMA_SOURCE_FILE_AT_LINE (68)) ;
          const GGS_bool cond_2897 = var_cas_messages.reader_hasKey (inLexique, var_cas_mess.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (70)) COMMA_SOURCE_FILE_AT_LINE (70)) ;
          if (cond_2897.isBuiltAndTrue ()) {
            GGS_message_obj  var_cas_lm ;
            const GGS_message_map  temp_2089 = var_cas_messages ;
            if (temp_2089.isBuilt ()) {
              temp_2089 (HERE)->method_get (inLexique, var_cas_mess, var_cas_lm COMMA_SOURCE_FILE_AT_LINE (72)) ;
            }
            { const GGS_mess_prop_obj _var_2879 = var_cas_lm.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (73)) ; // CAST instruction
              if (_var_2879.getPtr () != NULL) {
                macroValidPointer (_var_2879.getPtr ()) ;
                if (typeid (cPtr_rue_mess_prop) == typeid (* (_var_2879.getPtr ()))) {
                  const GGS_rue_mess_prop var_cas_ue (_var_2879.getPtr ()) ;
                  ::routine_check_external_link_received (inLexique,  var_cas_ue.reader_link (inLexique COMMA_SOURCE_FILE_AT_LINE (75)),  var_cas_messages,  var_cas_netm,  var_cas_tl.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (75)),  var_cas_depth.substract_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (75)) COMMA_SOURCE_FILE_AT_LINE (75)) ;
                }else if (typeid (cPtr_rqe_mess_prop) == typeid (* (_var_2879.getPtr ()))) {
                  const GGS_rqe_mess_prop var_cas_qe (_var_2879.getPtr ()) ;
                  ::routine_check_external_link_received (inLexique,  var_cas_qe.reader_link (inLexique COMMA_SOURCE_FILE_AT_LINE (77)),  var_cas_messages,  var_cas_netm,  var_cas_tl.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (77)),  var_cas_depth.substract_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (77)) COMMA_SOURCE_FILE_AT_LINE (77)) ;
                }else if (typeid (cPtr_rde_mess_prop) == typeid (* (_var_2879.getPtr ()))) {
                  const GGS_rde_mess_prop var_cas_de (_var_2879.getPtr ()) ;
                  ::routine_check_external_link_received (inLexique,  var_cas_de.reader_link (inLexique COMMA_SOURCE_FILE_AT_LINE (79)),  var_cas_messages,  var_cas_netm,  var_cas_tl.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (79)),  var_cas_depth.substract_operation (inLexique, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (79)) COMMA_SOURCE_FILE_AT_LINE (79)) ;
                }else{
                  var_cas_mess.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Linked message has a wrong MESSAGEPROPERTY") COMMA_SOURCE_FILE_AT_LINE (82)) ;
                  GGS_location  var_cas_loc = var_cas_lm.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (82)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (82)) ;
                  var_cas_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("expected MESSAGEPROPERTY are") COMMA_SOURCE_FILE_AT_LINE (84)) ;
                  var_cas_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("    RECEIVE_UNQUEUED_EXTERNAL,") COMMA_SOURCE_FILE_AT_LINE (85)) ;
                  var_cas_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("    RECEIVE_QUEUED_EXTERNAL or") COMMA_SOURCE_FILE_AT_LINE (86)) ;
                  var_cas_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("    RECEIVE_DYNAMIC_EXTERNAL") COMMA_SOURCE_FILE_AT_LINE (87)) ;
                }
              }
            }
          }else if (cond_2897.isBuiltAndFalse ()) {
            var_cas_mess.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("Linked message ")).operator_concat (var_cas_mess.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (89)))).operator_concat (GGS_string (" does not exist")) COMMA_SOURCE_FILE_AT_LINE (90)) ;
          }
        }
      }else if (typeid (cPtr_false_link) == typeid (* (_var_3317.getPtr ()))) {
        const GGS_false_link var_cas_fl (_var_3317.getPtr ()) ;
        GGS_lstring  var_cas_net = var_cas_fl.reader_networkmessage (inLexique COMMA_SOURCE_FILE_AT_LINE (93)) ;
        const GGS_bool cond_3188 = (var_cas_netm.reader_hasKey (inLexique, var_cas_net.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (94)) COMMA_SOURCE_FILE_AT_LINE (94))).operator_not () ;
        if (cond_3188.isBuiltAndTrue ()) {
          var_cas_net.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("NETWORKMESSAGE ")).operator_concat (var_cas_net.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (95)))).operator_concat (GGS_string (" does not exist")) COMMA_SOURCE_FILE_AT_LINE (96)) ;
        }else if (cond_3188.isBuiltAndFalse ()) {
          ::routine_check_net_dir (inLexique,  var_cas_net,  var_cas_netm,  GGS_string ("received") COMMA_SOURCE_FILE_AT_LINE (97)) ;
        }
      }else{
        var_cas_link.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (100)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Internal error, unexpected type") COMMA_SOURCE_FILE_AT_LINE (101)) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_external_link_received\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "messages_well_formed"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_messages_well_formed (C_Compiler & inLexique,
                                const GGS_message_map   var_cas_messages COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_messages_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_message_map::cEnumerator enumerator_3656 (var_cas_messages, true) ;
    const GGS_message_map::cElement * operand_3656 = NULL ;
    while (((operand_3656 = enumerator_3656.nextObject ()))) {
      macroValidPointer (operand_3656) ;
      { const GGS_mess_prop_obj _var_3888 = operand_3656->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (121)) ; // CAST instruction
        if (_var_3888.getPtr () != NULL) {
          macroValidPointer (_var_3888.getPtr ()) ;
          if (typeid (cPtr_void_mess_prop) == typeid (* (_var_3888.getPtr ()))) {
            operand_3656->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("MESSAGEPROPERTY attribute missing for message ")).operator_concat (operand_3656->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (123))) COMMA_SOURCE_FILE_AT_LINE (124)) ;
          }else{
          }
        }
      }
      { const GGS_action_obj _var_4522 = operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (127)) ; // CAST instruction
        if (_var_4522.getPtr () != NULL) {
          macroValidPointer (_var_4522.getPtr ()) ;
          if (typeid (cPtr_void_action) == typeid (* (_var_4522.getPtr ()))) {
          }else{
            { const GGS_mess_prop_obj _var_4508 = operand_3656->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (130)) ; // CAST instruction
              if (_var_4508.getPtr () != NULL) {
                macroValidPointer (_var_4508.getPtr ()) ;
                if (typeid (cPtr_ssi_mess_prop) == typeid (* (_var_4508.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (132)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (132)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATION is not allowed for SEND_STATIC_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (133)) ;
                }else if (typeid (cPtr_szi_mess_prop) == typeid (* (_var_4508.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (134)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (134)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATION is not allowed for SEND_ZERO_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (135)) ;
                }else if (typeid (cPtr_rzs_mess_prop) == typeid (* (_var_4508.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (136)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (136)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATION is not allowed for RECEIVE_ZERO_SENDERS message") COMMA_SOURCE_FILE_AT_LINE (137)) ;
                }else{
                }
              }
            }
          }
        }
      }
      { const GGS_action_obj _var_5658 = operand_3656->mInfo.mess.reader_notificationerror (inLexique COMMA_SOURCE_FILE_AT_LINE (141)) ; // CAST instruction
        if (_var_5658.getPtr () != NULL) {
          macroValidPointer (_var_5658.getPtr ()) ;
          if (typeid (cPtr_void_action) == typeid (* (_var_5658.getPtr ()))) {
          }else{
            { const GGS_mess_prop_obj _var_5644 = operand_3656->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (144)) ; // CAST instruction
              if (_var_5644.getPtr () != NULL) {
                macroValidPointer (_var_5644.getPtr ()) ;
                if (typeid (cPtr_ssi_mess_prop) == typeid (* (_var_5644.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (146)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (146)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATIONERROR is not allowed for SEND_STATIC_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (147)) ;
                }else if (typeid (cPtr_szi_mess_prop) == typeid (* (_var_5644.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (148)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (148)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATIONERROR is not allowed for SEND_ZERO_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (149)) ;
                }else if (typeid (cPtr_rzi_mess_prop) == typeid (* (_var_5644.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (150)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (150)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATIONERROR is not allowed for RECEIVE_ZERO_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (151)) ;
                }else if (typeid (cPtr_rui_mess_prop) == typeid (* (_var_5644.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (152)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (152)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATIONERROR is not allowed for RECEIVE_UNQUEUED_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (153)) ;
                }else if (typeid (cPtr_rqi_mess_prop) == typeid (* (_var_5644.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (154)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (154)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATIONERROR is not allowed for RECEIVE_QUEUED_INTERNAL message") COMMA_SOURCE_FILE_AT_LINE (155)) ;
                }else if (typeid (cPtr_rzs_mess_prop) == typeid (* (_var_5644.getPtr ()))) {
                  operand_3656->mInfo.mess.reader_notification (inLexique COMMA_SOURCE_FILE_AT_LINE (156)).reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (156)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("NOTIFICATIONERROR is not allowed for RECEIVE_ZERO_SENDERS message") COMMA_SOURCE_FILE_AT_LINE (157)) ;
                }else{
                }
              }
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_messages_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "networkmessages_exist_and_ok"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_networkmessages_exist_and_ok (C_Compiler & inLexique,
                                GGS_message_map   var_cas_messages,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_networkmessages_exist_and_ok at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_message_map::cEnumerator enumerator_5888 (var_cas_messages, true) ;
    const GGS_message_map::cElement * operand_5888 = NULL ;
    while (((operand_5888 = enumerator_5888.nextObject ()))) {
      macroValidPointer (operand_5888) ;
      { const GGS_mess_prop_obj _var_6626 = operand_5888->mInfo.mess.reader_messageproperty (inLexique COMMA_SOURCE_FILE_AT_LINE (171)) ; // CAST instruction
        if (_var_6626.getPtr () != NULL) {
          macroValidPointer (_var_6626.getPtr ()) ;
          if (typeid (cPtr_sse_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_sse_mess_prop var_cas_sse (_var_6626.getPtr ()) ;
            ::routine_check_external_sent (inLexique,  var_cas_sse.reader_networkmessage (inLexique COMMA_SOURCE_FILE_AT_LINE (173)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (173)) ;
          }else if (typeid (cPtr_sde_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_sde_mess_prop var_cas_sde (_var_6626.getPtr ()) ;
            ::routine_check_external_sent (inLexique,  var_cas_sde.reader_networkmessage (inLexique COMMA_SOURCE_FILE_AT_LINE (175)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (175)) ;
          }else if (typeid (cPtr_sze_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_sze_mess_prop var_cas_sze (_var_6626.getPtr ()) ;
            ::routine_check_external_sent (inLexique,  var_cas_sze.reader_networkmessage (inLexique COMMA_SOURCE_FILE_AT_LINE (177)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (177)) ;
          }else if (typeid (cPtr_rze_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_rze_mess_prop var_cas_rze (_var_6626.getPtr ()) ;
            ::routine_check_external_received (inLexique,  var_cas_rze.reader_networkmessage (inLexique COMMA_SOURCE_FILE_AT_LINE (179)),  var_cas_netm COMMA_SOURCE_FILE_AT_LINE (179)) ;
          }else if (typeid (cPtr_rue_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_rue_mess_prop var_cas_rue (_var_6626.getPtr ()) ;
            ::routine_check_external_link_received (inLexique,  var_cas_rue.reader_link (inLexique COMMA_SOURCE_FILE_AT_LINE (181)),  var_cas_messages,  var_cas_netm,  GGS_location (inLexique),  GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (181)) ;
          }else if (typeid (cPtr_rqe_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_rqe_mess_prop var_cas_rqe (_var_6626.getPtr ()) ;
            ::routine_check_external_link_received (inLexique,  var_cas_rqe.reader_link (inLexique COMMA_SOURCE_FILE_AT_LINE (183)),  var_cas_messages,  var_cas_netm,  GGS_location (inLexique),  GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (183)) ;
          }else if (typeid (cPtr_rde_mess_prop) == typeid (* (_var_6626.getPtr ()))) {
            const GGS_rde_mess_prop var_cas_rde (_var_6626.getPtr ()) ;
            ::routine_check_external_link_received (inLexique,  var_cas_rde.reader_link (inLexique COMMA_SOURCE_FILE_AT_LINE (185)),  var_cas_messages,  var_cas_netm,  GGS_location (inLexique),  GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (185)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_networkmessages_exist_and_ok\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "networkmessages_well_formed"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_networkmessages_well_formed (C_Compiler & inLexique,
                                GGS_netmess_map   var_cas_netm COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_networkmessages_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_netmess_map::cEnumerator enumerator_6738 (var_cas_netm, true) ;
    const GGS_netmess_map::cElement * operand_6738 = NULL ;
    while (((operand_6738 = enumerator_6738.nextObject ()))) {
      macroValidPointer (operand_6738) ;
      { const GGS_base_netprop _var_6903 = operand_6738->mInfo.netmess.reader_netprop (inLexique COMMA_SOURCE_FILE_AT_LINE (194)) ; // CAST instruction
        if (_var_6903.getPtr () != NULL) {
          macroValidPointer (_var_6903.getPtr ()) ;
          if (typeid (cPtr_void_netprop) == typeid (* (_var_6903.getPtr ()))) {
            operand_6738->mKey.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, (GGS_string ("MESSAGEPROPERTY attribute is missing for NETWORKMESSAGE ")).operator_concat (operand_6738->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (196))) COMMA_SOURCE_FILE_AT_LINE (197)) ;
          }else{
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_networkmessages_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_grammar.h'                            *
//                       Generated by version 1.9.11                         *
//                      april 29th, 2010, at 10h36'56"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_goil_5F_grammar_HAS_BEEN_DEFINED
#define GRAMMAR_goil_5F_grammar_HAS_BEEN_DEFINED

//---------------------------------------------------------------------------*

#include "goil_syntax.h"
#include "goil_imp_def.h"
#include "goil_obj_os.h"
#include "goil_obj_task.h"
#include "goil_obj_counter.h"
#include "goil_obj_appmode.h"
#include "goil_obj_alarm.h"
#include "goil_obj_resource.h"
#include "goil_obj_event.h"
#include "goil_obj_isr.h"
#include "goil_obj_message.h"
#include "goil_obj_networkmessage.h"
#include "goil_obj_com.h"
#include "goil_obj_ipdu.h"
#include "goil_obj_scheduletable.h"
#include "goil_obj_application.h"
#include "goil_timing_prot_attrs.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

class C_Grammar_goil_5F_grammar : public goil_syntax,
                                  public goil_imp_def,
                                  public goil_obj_os,
                                  public goil_obj_task,
                                  public goil_obj_counter,
                                  public goil_obj_appmode,
                                  public goil_obj_alarm,
                                  public goil_obj_resource,
                                  public goil_obj_event,
                                  public goil_obj_isr,
                                  public goil_obj_message,
                                  public goil_obj_networkmessage,
                                  public goil_obj_com,
                                  public goil_obj_ipdu,
                                  public goil_obj_scheduletable,
                                  public goil_obj_application,
                                  public goil_timing_prot_attrs {
  public : virtual void nt_OIL_5F_version_ (C_Lexique_goil_5F_lexique &,
                                            GGS_lstring &,
                                            GGS_lstring &) ;

  public : virtual void nt_alarm_ (C_Lexique_goil_5F_lexique &,
                                   GGS_alarm_map &) ;

  public : virtual void nt_alarm_5F_action_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                       GGS_action_obj &) ;

  public : virtual void nt_alarm_5F_autostart_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                          GGS_autostart_obj &) ;

  public : virtual void nt_alarm_5F_parameters_ (C_Lexique_goil_5F_lexique &,
                                                 GGS_lstring &,
                                                 GGS_action_obj &,
                                                 GGS_autostart_obj &,
                                                 GGS_lstringlist &) ;

  public : virtual void nt_app_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_app_obj &,
                                               GGS_lstring) ;

  public : virtual void nt_appli_ (C_Lexique_goil_5F_lexique &,
                                   GGS_app_map &) ;

  public : virtual void nt_application_5F_definition_ (C_Lexique_goil_5F_lexique &,
                                                       GGS_root_obj &) ;

  public : virtual void nt_appmode_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_attribute_5F_name_ (C_Lexique_goil_5F_lexique &,
                                               GGS_lstring &) ;

  public : virtual void nt_auto_5F_specifier_ (C_Lexique_goil_5F_lexique &,
                                               GGS_bool &) ;

  public : virtual void nt_bitordering_ (C_Lexique_goil_5F_lexique &,
                                         GGS_lstring &) ;

  public : virtual void nt_bitposition_ (C_Lexique_goil_5F_lexique &,
                                         GGS_luint64 &) ;

  public : virtual void nt_boolean_ (C_Lexique_goil_5F_lexique &,
                                     GGS_lbool &) ;

  public : virtual void nt_cdatatype_ (C_Lexique_goil_5F_lexique &,
                                       GGS_lstring &) ;

  public : virtual void nt_com_ (C_Lexique_goil_5F_lexique &,
                                 GGS_com &) ;

  public : virtual void nt_comappmode_ (C_Lexique_goil_5F_lexique &,
                                        GGS_lstringlist &) ;

  public : virtual void nt_comerrorhook_ (C_Lexique_goil_5F_lexique &,
                                          GGS_basic_type &) ;

  public : virtual void nt_comstartcomextension_ (C_Lexique_goil_5F_lexique &,
                                                  GGS_basic_type &) ;

  public : virtual void nt_comstatus_ (C_Lexique_goil_5F_lexique &,
                                       GGS_lstring &) ;

  public : virtual void nt_comtimebase_ (C_Lexique_goil_5F_lexique &,
                                         GGS_basic_type &) ;

  public : virtual void nt_comusegetserviceid_ (C_Lexique_goil_5F_lexique &,
                                                GGS_basic_type &) ;

  public : virtual void nt_comuseparameteraccess_ (C_Lexique_goil_5F_lexique &,
                                                   GGS_basic_type &) ;

  public : virtual void nt_counter_ (C_Lexique_goil_5F_lexique &,
                                     GGS_counter_map &) ;

  public : virtual void nt_counter_5F_parameters_ (C_Lexique_goil_5F_lexique &,
                                                   GGS_basic_type &,
                                                   GGS_basic_type &,
                                                   GGS_basic_type &,
                                                   GGS_lstring &,
                                                   GGS_lstringlist &,
                                                   GGS_counter_type &,
                                                   GGS_lstring &) ;

  public : virtual void nt_counter_5F_type_5F_attrs_ (C_Lexique_goil_5F_lexique &,
                                                      GGS_counter_type &) ;

  public : virtual void nt_cpuordercallout_ (C_Lexique_goil_5F_lexique &,
                                             GGS_lstring &) ;

  public : virtual void nt_datainterpretation_ (C_Lexique_goil_5F_lexique &,
                                                GGS_lstring &) ;

  public : virtual void nt_default_5F_bool_ (C_Lexique_goil_5F_lexique &,
                                             GGS_bool_class &) ;

  public : virtual void nt_default_5F_enum_ (C_Lexique_goil_5F_lexique &,
                                             GGS_basic_type &) ;

  public : virtual void nt_default_5F_float_5F_number_ (C_Lexique_goil_5F_lexique &,
                                                        GGS_float_class &) ;

  public : virtual void nt_default_5F_name_ (C_Lexique_goil_5F_lexique &,
                                             GGS_bool &,
                                             GGS_lstring &) ;

  public : virtual void nt_default_5F_number_ (C_Lexique_goil_5F_lexique &,
                                               GGS_bool &,
                                               GGS_luint64 &) ;

  public : virtual void nt_default_5F_sint_33__32__5F_number_ (C_Lexique_goil_5F_lexique &,
                                                               GGS_sint32_class &) ;

  public : virtual void nt_default_5F_sint_36__34__5F_number_ (C_Lexique_goil_5F_lexique &,
                                                               GGS_sint64_class &) ;

  public : virtual void nt_default_5F_string_ (C_Lexique_goil_5F_lexique &,
                                               GGS_string_class &) ;

  public : virtual void nt_default_5F_uint_33__32__5F_number_ (C_Lexique_goil_5F_lexique &,
                                                               GGS_uint32_class &) ;

  public : virtual void nt_default_5F_uint_36__34__5F_number_ (C_Lexique_goil_5F_lexique &,
                                                               GGS_uint64_class &) ;

  public : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                         GGS_lstring &) ;

  public : virtual void nt_direct_5F_attributes_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_direction_ (C_Lexique_goil_5F_lexique &,
                                       GGS_lstring &) ;

  public : virtual void nt_dynamic_5F_mp_ (C_Lexique_goil_5F_lexique &,
                                           GGS_base_netprop &) ;

  public : virtual void nt_enumeration_ (C_Lexique_goil_5F_lexique &,
                                         GGS_stringset &) ;

  public : virtual void nt_enumerator_ (C_Lexique_goil_5F_lexique &,
                                        GGS_stringset &) ;

  public : virtual void nt_event_ (C_Lexique_goil_5F_lexique &,
                                   GGS_event_map &) ;

  public : virtual void nt_event_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                                 GGS_event_mask_obj &) ;

  public : virtual void nt_file_ (C_Lexique_goil_5F_lexique &,
                                  GGS_implementation &,
                                  GGS_root_obj &) ;

  public : virtual void nt_filter_ (C_Lexique_goil_5F_lexique &,
                                    GGS_filter_prop_obj &) ;

  public : virtual void nt_firsttimeout_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_float_5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_float_set &) ;

  public : virtual void nt_free_5F_field_ (C_Lexique_goil_5F_lexique &,
                                           GGS_ident_map &) ;

  public : virtual void nt_impl_5F_attr_5F_def_ (C_Lexique_goil_5F_lexique &,
                                                 GGS_lstring &,
                                                 GGS_imp_type &) ;

  public : virtual void nt_impl_5F_parameter_5F_list_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_implementation_5F_def_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_implementation_5F_definition_ (C_Lexique_goil_5F_lexique &,
                                                          GGS_implementation &) ;

  public : virtual void nt_implementation_5F_list_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_string,
                                                    GGS_implementation &) ;

  public : virtual void nt_implementation_5F_spec_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_implementation &) ;

  public : virtual void nt_implementation_5F_spec_5F_list_ (C_Lexique_goil_5F_lexique &,
                                                            GGS_implementation &) ;

  public : virtual void nt_include_5F_cpu_5F_level_ (C_Lexique_goil_5F_lexique &,
                                                     GGS_os_obj &,
                                                     GGS_com &,
                                                     GGS_task_map &,
                                                     GGS_counter_map &,
                                                     GGS_alarm_map &,
                                                     GGS_resource_map &,
                                                     GGS_event_map &,
                                                     GGS_isr_map &,
                                                     GGS_message_map &,
                                                     GGS_netmess_map &,
                                                     GGS_scheduletable_map &,
                                                     GGS_app_map &) ;

  public : virtual void nt_include_5F_file_5F_level_ (C_Lexique_goil_5F_lexique &,
                                                      GGS_implementation &,
                                                      GGS_root_obj &) ;

  public : virtual void nt_initialvalue_ (C_Lexique_goil_5F_lexique &,
                                          GGS_basic_type &) ;

  public : virtual void nt_ipdu_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_ipdu_5F_ref_ (C_Lexique_goil_5F_lexique &,
                                         GGS_lstring &) ;

  public : virtual void nt_ipducallout_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_ipduproperty_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_isr_ (C_Lexique_goil_5F_lexique &,
                                 GGS_isr_map &) ;

  public : virtual void nt_isr_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_basic_type &,
                                               GGS_basic_type &,
                                               GGS_lstringlist &,
                                               GGS_lstringlist &,
                                               GGS_lstringlist &,
                                               GGS_timing_prot &,
                                               GGS_ident_map &) ;

  public : virtual void nt_layerused_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_link_ (C_Lexique_goil_5F_lexique &,
                                  GGS_link_obj &) ;

  public : virtual void nt_ltgt_5F_sync_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_ltgt_sync_obj &) ;

  public : virtual void nt_mask_5F_attribute_ (C_Lexique_goil_5F_lexique &,
                                               GGS_luint64 &) ;

  public : virtual void nt_mask_5F_x_5F_attribute_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_luint64 &,
                                                    GGS_luint64 &) ;

  public : virtual void nt_maxsizeinbits_ (C_Lexique_goil_5F_lexique &,
                                           GGS_luint64 &) ;

  public : virtual void nt_mess_ (C_Lexique_goil_5F_lexique &,
                                  GGS_message_map &) ;

  public : virtual void nt_message_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                                   GGS_action_obj &,
                                                   GGS_action_obj &,
                                                   GGS_lstringlist &,
                                                   GGS_ident_map &,
                                                   GGS_mess_prop_obj &) ;

  public : virtual void nt_message_5F_property_ (C_Lexique_goil_5F_lexique &,
                                                 GGS_mess_prop_obj &) ;

  public : virtual void nt_min_5F_max_5F_attribute_ (C_Lexique_goil_5F_lexique &,
                                                     GGS_luint64 &,
                                                     GGS_luint64 &) ;

  public : virtual void nt_minimumdelaytime_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_mixed_5F_attributes_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_multiple_5F_specifier_ (C_Lexique_goil_5F_lexique &,
                                                   GGS_bool &) ;

  public : virtual void nt_net_5F_messageproperty_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_base_netprop &) ;

  public : virtual void nt_networkmess_ (C_Lexique_goil_5F_lexique &,
                                         GGS_netmess_map &) ;

  public : virtual void nt_networkmessage_ (C_Lexique_goil_5F_lexique &,
                                            GGS_lstring &) ;

  public : virtual void nt_networkordercallout_ (C_Lexique_goil_5F_lexique &,
                                                 GGS_lstring &) ;

  public : virtual void nt_nm_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_notification_5F_property_ (C_Lexique_goil_5F_lexique &,
                                                      GGS_action_obj &) ;

  public : virtual void nt_object_5F_definition_5F_list_ (C_Lexique_goil_5F_lexique &,
                                                          GGS_os_obj &,
                                                          GGS_com &,
                                                          GGS_task_map &,
                                                          GGS_counter_map &,
                                                          GGS_alarm_map &,
                                                          GGS_resource_map &,
                                                          GGS_event_map &,
                                                          GGS_isr_map &,
                                                          GGS_message_map &,
                                                          GGS_netmess_map &,
                                                          GGS_scheduletable_map &,
                                                          GGS_app_map &) ;

  public : virtual void nt_os_ (C_Lexique_goil_5F_lexique &,
                                GGS_os_obj &) ;

  public : virtual void nt_period_5F_offset_5F_attribute_ (C_Lexique_goil_5F_lexique &,
                                                           GGS_luint64 &,
                                                           GGS_luint64 &) ;

  public : virtual void nt_periodic_5F_attributes_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_queuesize_ (C_Lexique_goil_5F_lexique &,
                                       GGS_luint64 &) ;

  public : virtual void nt_rde_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_received_5F_attributes_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_resource_ (C_Lexique_goil_5F_lexique &,
                                      GGS_resource_map &) ;

  public : virtual void nt_resource_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_resource_property_obj &,
                                                    GGS_lstringlist &) ;

  public : virtual void nt_rqe_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_rqi_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_rue_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_rui_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_rze_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_rzi_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_rzs_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_scheduletable_ (C_Lexique_goil_5F_lexique &,
                                           GGS_scheduletable_map &) ;

  public : virtual void nt_scheduletable_5F_parameters_ (C_Lexique_goil_5F_lexique &,
                                                         GGS_scheduletable_obj &,
                                                         GGS_lstring) ;

  public : virtual void nt_sde_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_sendingmessage_ (C_Lexique_goil_5F_lexique &,
                                            GGS_lstring &) ;

  public : virtual void nt_sent_5F_attributes_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_signed_5F_number_ (C_Lexique_goil_5F_lexique &,
                                              GGS_sint64 &) ;

  public : virtual void nt_sint_33__32__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                                           GGS_sint32_set &) ;

  public : virtual void nt_sint_36__34__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                                           GGS_sint64_set &) ;

  public : virtual void nt_sizeinbits_ (C_Lexique_goil_5F_lexique &,
                                        GGS_luint64 &) ;

  public : virtual void nt_sse_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_ssi_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_st_5F_action_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                    GGS_action_list &) ;

  public : virtual void nt_st_5F_autostart_5F_abs_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                              GGS_autostart_obj &) ;

  public : virtual void nt_st_5F_autostart_5F_rel_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                              GGS_autostart_obj &) ;

  public : virtual void nt_st_5F_autostart_5F_sync_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                               GGS_autostart_obj &) ;

  public : virtual void nt_st_5F_expiry_5F_pt_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                          GGS_lstring,
                                                          GGS_expiry_point_obj &) ;

  public : virtual void nt_start_ (C_Lexique_goil_5F_lexique &) ;

  public : static void _performSourceFileParsing_ (C_Compiler & inCompiler,
                                                   const C_String & inDependancyExtension,
                                                   const C_String & inDependancyPath,
                                                   GGS_string * inSentStringPtr,
                                                   const GGS_lstring inFileName
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler & inCompiler,
                                                     GGS_string * inSentStringPtr,
                                                     const GGS_string inSourceString
                                                     COMMA_LOCATION_ARGS) ;

  public : virtual void nt_static_5F_mp_ (C_Lexique_goil_5F_lexique &,
                                          GGS_base_netprop &) ;

  public : virtual void nt_sze_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                               GGS_mess_prop_obj &) ;

  public : virtual void nt_task_ (C_Lexique_goil_5F_lexique &,
                                  GGS_task_map &) ;

  public : virtual void nt_task_5F_attributes_ (C_Lexique_goil_5F_lexique &,
                                                GGS_basic_type &,
                                                GGS_lstring &,
                                                GGS_basic_type &,
                                                GGS_task_autostart_obj &,
                                                GGS_lstringlist &,
                                                GGS_lstringlist &,
                                                GGS_lstringlist &,
                                                GGS_lstringlist &,
                                                GGS_timing_prot &,
                                                GGS_ident_map &) ;

  public : virtual void nt_task_5F_autostart_5F_params_ (C_Lexique_goil_5F_lexique &,
                                                         GGS_task_autostart_obj &) ;

  public : virtual void nt_timeoffset_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_timeout_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_timeperiod_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_timing_5F_prot_5F_attrs_ (C_Lexique_goil_5F_lexique &,
                                                     GGS_basic_type &,
                                                     GGS_basic_type &,
                                                     GGS_basic_type &,
                                                     GGS_basic_type &,
                                                     GGS_basic_type &,
                                                     GGS_rezlock_map &) ;

  public : virtual void nt_transferproperty_ (C_Lexique_goil_5F_lexique &,
                                              GGS_lstring &) ;

  public : virtual void nt_transmissionmode_ (C_Lexique_goil_5F_lexique &) ;

  public : virtual void nt_trusted_5F_fcts_ (C_Lexique_goil_5F_lexique &,
                                             GGS_app_trusted_obj &) ;

  public : virtual void nt_uint_33__32__5F_attribute_5F_name_ (C_Lexique_goil_5F_lexique &,
                                                               GGS_lstring &) ;

  public : virtual void nt_uint_33__32__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                                           GGS_uint32_set &) ;

  public : virtual void nt_uint_36__34__5F_number_5F_set_ (C_Lexique_goil_5F_lexique &,
                                                           GGS_uint64_set &) ;

  public : virtual void nt_use_ (C_Lexique_goil_5F_lexique &,
                                 GGS_lstringlist &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_8 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_9 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_10 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_11 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_12 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_13 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_14 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_15 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_16 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_17 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_18 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_19 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_20 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_21 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_22 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_23 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_24 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_25 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_imp_5F_def_26 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_os_8 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_task_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_task_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_task_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_task_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_task_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_counter_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_appmode_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_alarm_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_alarm_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_alarm_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_alarm_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_alarm_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_alarm_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_resource_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_resource_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_event_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_event_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_isr_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_isr_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_8 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_9 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_10 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_11 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_12 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_13 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_14 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_15 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_16 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_17 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_18 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_19 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_20 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_message_21 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_networkmessage_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_com_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_com_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_ipdu_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_8 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_9 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_10 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_11 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_12 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_scheduletable_13 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_1 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_2 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_3 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_4 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_5 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_6 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_7 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_obj_5F_application_8 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_timing_5F_prot_5F_attrs_0 (C_Lexique_goil_5F_lexique &) ;

  public : virtual PMSInt16 select_goil_5F_timing_5F_prot_5F_attrs_1 (C_Lexique_goil_5F_lexique &) ;
} ;

//---------------------------------------------------------------------------*

#endif

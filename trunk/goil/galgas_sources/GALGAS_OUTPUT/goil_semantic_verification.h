//---------------------------------------------------------------------------*
//                                                                           *
//                   File 'goil_semantic_verification.h'                     *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'52"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_semantic_verification_ENTITIES_DEFINED
#define goil_semantic_verification_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "resources_verif.h"
#include "goil_types_resource.h"
#include "goil_basic_types.h"
#include "scheduletable_verif.h"
#include "goil_types_root.h"
#include "goil_types_os.h"
#include "goil_routines.h"
#include "com_type.h"
#include "goil_semantic_types.h"
#include "goil_types_action.h"
#include "goil_types_task.h"
#include "goil_types_timing_prot.h"
#include "cfg_types.h"
#include "goil_types_isr.h"
#include "goil_types_counter.h"
#include "goil_types_scheduletable.h"
#include "goil_types_app.h"
#include "goil_types_networkmessage.h"
#include "tasks_verif.h"
#include "isrs_verif.h"
#include "goil_message_verif.h"
#include "goil_alarm_verif.h"
#include "goil_app_verif.h"

//---------------------------------------------------------------------------*

class GALGAS__32_stringlist ;
class GALGAS_action_5F_list ;
class GALGAS_action_5F_obj ;
class GALGAS_activatetask_5F_action ;
class GALGAS_adjustable_5F_false ;
class GALGAS_adjustable_5F_obj ;
class GALGAS_adjustable_5F_true ;
class GALGAS_adjustable_5F_void ;
class GALGAS_alarm_5F_autostart_5F_true ;
class GALGAS_alarm_5F_map ;
class GALGAS_alarm_5F_obj ;
class GALGAS_always_5F_filter ;
class GALGAS_app_5F_map ;
class GALGAS_app_5F_obj ;
class GALGAS_app_5F_trusted_5F_false ;
class GALGAS_app_5F_trusted_5F_obj ;
class GALGAS_app_5F_trusted_5F_true ;
class GALGAS_app_5F_trusted_5F_void ;
class GALGAS_application ;
class GALGAS_attrs ;
class GALGAS_auto_5F_bool_5F_class ;
class GALGAS_auto_5F_sint_33__32__5F_class ;
class GALGAS_auto_5F_sint_36__34__5F_class ;
class GALGAS_auto_5F_string_5F_class ;
class GALGAS_auto_5F_uint_33__32__5F_class ;
class GALGAS_auto_5F_uint_36__34__5F_class ;
class GALGAS_autostart_5F_false ;
class GALGAS_autostart_5F_obj ;
class GALGAS_autostart_5F_void ;
class GALGAS_base_5F_mess ;
class GALGAS_base_5F_netprop ;
class GALGAS_basic_5F_type ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_bool_5F_class ;
class GALGAS_callback_5F_action ;
class GALGAS_cfg_5F_attrs ;
class GALGAS_char ;
class GALGAS_com ;
class GALGAS_config ;
class GALGAS_counter_5F_by_5F_source ;
class GALGAS_counter_5F_driver ;
class GALGAS_counter_5F_map ;
class GALGAS_counter_5F_obj ;
class GALGAS_counter_5F_type ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_dynamic_5F_netprop ;
class GALGAS_eventMaskMap ;
class GALGAS_event_5F_map ;
class GALGAS_event_5F_mask_5F_auto_5F_obj ;
class GALGAS_event_5F_mask_5F_obj ;
class GALGAS_event_5F_mask_5F_user_5F_obj ;
class GALGAS_event_5F_mask_5F_void_5F_obj ;
class GALGAS_event_5F_obj ;
class GALGAS_event_5F_usage_5F_map ;
class GALGAS_expiry_5F_point_5F_list ;
class GALGAS_expiry_5F_point_5F_obj ;
class GALGAS_false_5F_link ;
class GALGAS_false_5F_timing_5F_prot ;
class GALGAS_filewrapper ;
class GALGAS_filter_5F_prop_5F_obj ;
class GALGAS_finalize_5F_st_5F_action ;
class GALGAS_flag_5F_action ;
class GALGAS_float_5F_class ;
class GALGAS_float_5F_empty_5F_set ;
class GALGAS_float_5F_set ;
class GALGAS_function ;
class GALGAS_functionlist ;
class GALGAS_gpt_5F_driver ;
class GALGAS_hardware_5F_counter ;
class GALGAS_ident_5F_list ;
class GALGAS_ident_5F_list_5F_map ;
class GALGAS_ident_5F_map ;
class GALGAS_imp_5F_obj_5F_ref ;
class GALGAS_imp_5F_sca_5F_type ;
class GALGAS_imp_5F_type ;
class GALGAS_implementation ;
class GALGAS_implementation_5F_spec ;
class GALGAS_incrementcounter_5F_action ;
class GALGAS_interrupts ;
class GALGAS_isr_5F_list ;
class GALGAS_isr_5F_map ;
class GALGAS_isr_5F_obj ;
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_link_5F_obj ;
class GALGAS_linked_5F_resources ;
class GALGAS_list_5F_sint_33__32_ ;
class GALGAS_list_5F_sint_36__34_ ;
class GALGAS_list_5F_uint_33__32_ ;
class GALGAS_list_5F_uint_36__34_ ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringMap ;
class GALGAS_lstringlist ;
class GALGAS_ltgt_5F_sync_5F_false ;
class GALGAS_ltgt_5F_sync_5F_obj ;
class GALGAS_ltgt_5F_sync_5F_true ;
class GALGAS_ltgt_5F_sync_5F_void ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_maskednewdiffersmaskedold_5F_filter ;
class GALGAS_maskednewdiffersx_5F_filter ;
class GALGAS_maskednewequalsmaskedold_5F_filter ;
class GALGAS_maskednewequalsx_5F_filter ;
class GALGAS_memmap_5F_false ;
class GALGAS_memmap_5F_true ;
class GALGAS_mess_5F_prop_5F_obj ;
class GALGAS_message_5F_map ;
class GALGAS_message_5F_obj ;
class GALGAS_netmess_5F_map ;
class GALGAS_netmess_5F_obj ;
class GALGAS_never_5F_filter ;
class GALGAS_newisdifferent_5F_filter ;
class GALGAS_newisequal_5F_filter ;
class GALGAS_newisgreater_5F_filter ;
class GALGAS_newisgreaterorequal_5F_filter ;
class GALGAS_newisless_5F_filter ;
class GALGAS_newislessorequal_5F_filter ;
class GALGAS_newisoutside ;
class GALGAS_newiswithin ;
class GALGAS_nmcallback_5F_action ;
class GALGAS_no_5F_linker ;
class GALGAS_number_5F_set ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_objs_5F_by_5F_prio ;
class GALGAS_oil_5F_obj ;
class GALGAS_oneeveryn_5F_filter ;
class GALGAS_os_5F_imp ;
class GALGAS_os_5F_internal_5F_driver ;
class GALGAS_os_5F_obj ;
class GALGAS_prefix_5F_map ;
class GALGAS_prio_5F_list ;
class GALGAS_prio_5F_map ;
class GALGAS_rde_5F_mess_5F_prop ;
class GALGAS_resource_5F_map ;
class GALGAS_resource_5F_obj ;
class GALGAS_resource_5F_property_5F_internal_5F_obj ;
class GALGAS_resource_5F_property_5F_linked_5F_obj ;
class GALGAS_resource_5F_property_5F_obj ;
class GALGAS_resource_5F_property_5F_standard_5F_obj ;
class GALGAS_resource_5F_property_5F_void_5F_obj ;
class GALGAS_rezlock_5F_map ;
class GALGAS_root_5F_obj ;
class GALGAS_rqe_5F_mess_5F_prop ;
class GALGAS_rqi_5F_mess_5F_prop ;
class GALGAS_rue_5F_mess_5F_prop ;
class GALGAS_rui_5F_mess_5F_prop ;
class GALGAS_rze_5F_mess_5F_prop ;
class GALGAS_rzi_5F_mess_5F_prop ;
class GALGAS_rzs_5F_mess_5F_prop ;
class GALGAS_scheduletable_5F_map ;
class GALGAS_scheduletable_5F_obj ;
class GALGAS_sd_5F_autostart_5F_absolute ;
class GALGAS_sd_5F_autostart_5F_false ;
class GALGAS_sd_5F_autostart_5F_relative ;
class GALGAS_sd_5F_autostart_5F_synchron ;
class GALGAS_sd_5F_autostart_5F_true ;
class GALGAS_sde_5F_mess_5F_prop ;
class GALGAS_setevent_5F_action ;
class GALGAS_sint ;
class GALGAS_sint_33__32__5F_class ;
class GALGAS_sint_33__32__5F_empty_5F_set ;
class GALGAS_sint_33__32__5F_list ;
class GALGAS_sint_33__32__5F_range ;
class GALGAS_sint_33__32__5F_set ;
class GALGAS_sint_33__32__5F_type ;
class GALGAS_sint_36__34_ ;
class GALGAS_sint_36__34__5F_class ;
class GALGAS_sint_36__34__5F_empty_5F_set ;
class GALGAS_sint_36__34__5F_list ;
class GALGAS_sint_36__34__5F_range ;
class GALGAS_sint_36__34__5F_set ;
class GALGAS_sint_36__34__5F_type ;
class GALGAS_software_5F_counter ;
class GALGAS_sorted_5F_events ;
class GALGAS_sse_5F_mess_5F_prop ;
class GALGAS_ssi_5F_mess_5F_prop ;
class GALGAS_static_5F_netprop ;
class GALGAS_string ;
class GALGAS_stringMap ;
class GALGAS_string_5F_class ;
class GALGAS_stringlist ;
class GALGAS_stringset ;
class GALGAS_stringset_5F_map ;
class GALGAS_sze_5F_mess_5F_prop ;
class GALGAS_szi_5F_mess_5F_prop ;
class GALGAS_task_5F_autostart_5F_false ;
class GALGAS_task_5F_autostart_5F_obj ;
class GALGAS_task_5F_autostart_5F_true ;
class GALGAS_task_5F_autostart_5F_void ;
class GALGAS_task_5F_map ;
class GALGAS_task_5F_mask ;
class GALGAS_task_5F_obj ;
class GALGAS_tasks_5F_by_5F_type ;
class GALGAS_time_5F_constants ;
class GALGAS_timing_5F_prot ;
class GALGAS_timing_5F_prot_5F_isr ;
class GALGAS_timing_5F_prot_5F_task ;
class GALGAS_trace ;
class GALGAS_trace_5F_file ;
class GALGAS_trace_5F_method ;
class GALGAS_trace_5F_off ;
class GALGAS_trace_5F_on ;
class GALGAS_trace_5F_void ;
class GALGAS_true_5F_link ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_uint ;
class GALGAS_uint_33__32__5F_class ;
class GALGAS_uint_33__32__5F_empty_5F_set ;
class GALGAS_uint_33__32__5F_list ;
class GALGAS_uint_33__32__5F_range ;
class GALGAS_uint_33__32__5F_set ;
class GALGAS_uint_33__32__5F_type ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34__5F_class ;
class GALGAS_uint_36__34__5F_empty_5F_set ;
class GALGAS_uint_36__34__5F_list ;
class GALGAS_uint_36__34__5F_range ;
class GALGAS_uint_36__34__5F_set ;
class GALGAS_uint_36__34__5F_type ;
class GALGAS_uint_36__34_list ;
class GALGAS_uintlist ;
class GALGAS_void ;
class GALGAS_void_5F_action ;
class GALGAS_void_5F_bool_5F_class ;
class GALGAS_void_5F_counter ;
class GALGAS_void_5F_driver ;
class GALGAS_void_5F_filter ;
class GALGAS_void_5F_float_5F_class ;
class GALGAS_void_5F_link ;
class GALGAS_void_5F_mess_5F_prop ;
class GALGAS_void_5F_netprop ;
class GALGAS_void_5F_sint_33__32__5F_class ;
class GALGAS_void_5F_sint_36__34__5F_class ;
class GALGAS_void_5F_string_5F_class ;
class GALGAS_void_5F_timing_5F_prot ;
class GALGAS_void_5F_type ;
class GALGAS_void_5F_uint_33__32__5F_class ;
class GALGAS_void_5F_uint_36__34__5F_class ;
class GALGAS_yes_5F_linker ;
class GALGAS_zero_5F_netprop ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'counters_well_formed'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_counters_5F_well_5F_formed (const GALGAS_counter_5F_map constinArgument0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'alarms_well_formed'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_alarms_5F_well_5F_formed (const GALGAS_alarm_5F_map constinArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'events_well_formed'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_events_5F_well_5F_formed (const GALGAS_event_5F_map constinArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//     Routine 'all_events_and_resources_and_messages_defined_and_used'      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_all_5F_events_5F_and_5F_resources_5F_and_5F_messages_5F_defined_5F_and_5F_used (const GALGAS_root_5F_obj constinArgument0,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Routine 'all_event_masks_different'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_all_5F_event_5F_masks_5F_different (GALGAS_event_5F_map inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Routine 'all_alarm_actions_correct'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_all_5F_alarm_5F_actions_5F_correct (GALGAS_alarm_5F_map inArgument0,
                                                 GALGAS_task_5F_map inArgument1,
                                                 GALGAS_counter_5F_map inArgument2,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Routine 'verify_all'                            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_verify_5F_all (GALGAS_root_5F_obj & ioArgument0,
                            C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif

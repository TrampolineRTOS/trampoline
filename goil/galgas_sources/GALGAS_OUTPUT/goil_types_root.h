//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_types_root.h'                          *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'46"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_types_root_ENTITIES_DEFINED
#define goil_types_root_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "goil_types_os.h"
#include "goil_basic_types.h"
#include "goil_routines.h"
#include "com_type.h"
#include "goil_semantic_types.h"
#include "goil_types_action.h"
#include "goil_types_task.h"
#include "goil_types_timing_prot.h"
#include "goil_types_resource.h"
#include "cfg_types.h"
#include "goil_types_isr.h"
#include "goil_types_counter.h"
#include "goil_types_scheduletable.h"
#include "goil_types_app.h"
#include "goil_types_networkmessage.h"

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
//                         Function 'void_root_obj'                          *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_root_5F_obj function_void_5F_root_5F_obj (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'scalabilityClass'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_scalabilityClass (const GALGAS_root_5F_obj constinArgument0,
                               GALGAS_uint_36__34_ & outArgument1,
                               GALGAS_bool & outArgument2,
                               GALGAS_bool & outArgument3,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                            @root_5F_obj class                             *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_root_5F_obj ;

//---------------------------------------------------------------------------*

class GALGAS_root_5F_obj : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_root_5F_obj (void) ;

//---
  public : inline const cPtr_root_5F_obj * ptr (void) const { return (const cPtr_root_5F_obj *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_root_5F_obj (const cPtr_root_5F_obj * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_root_5F_obj extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler,
                                                    const GALGAS_location & inErrorLocation
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_root_5F_obj constructor_new (const GALGAS_lstring & inOperand0,
                                                      const GALGAS_os_5F_obj & inOperand1,
                                                      const GALGAS_com & inOperand2,
                                                      const GALGAS_task_5F_map & inOperand3,
                                                      const GALGAS_counter_5F_map & inOperand4,
                                                      const GALGAS_alarm_5F_map & inOperand5,
                                                      const GALGAS_resource_5F_map & inOperand6,
                                                      const GALGAS_event_5F_map & inOperand7,
                                                      const GALGAS_isr_5F_map & inOperand8,
                                                      const GALGAS_message_5F_map & inOperand9,
                                                      const GALGAS_netmess_5F_map & inOperand10,
                                                      const GALGAS_scheduletable_5F_map & inOperand11,
                                                      const GALGAS_app_5F_map & inOperand12
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_root_5F_obj & inOperand) const ;

//--------------------------------- Modifiers
  public : VIRTUAL_IN_DEBUG void modifier_setCounters (GALGAS_counter_5F_map inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setIsrs (GALGAS_isr_5F_map inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setOs (GALGAS_os_5F_obj inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setResources (GALGAS_resource_5F_map inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setScheduletables (GALGAS_scheduletable_5F_map inArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setTasks (GALGAS_task_5F_map inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_alarm_5F_map reader_alarms (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_app_5F_map reader_applis (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_com reader_com (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_counter_5F_map reader_counters (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_event_5F_map reader_events (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_isr_5F_map reader_isrs (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_message_5F_map reader_messages (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_name (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_netmess_5F_map reader_net_5F_messages (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_os_5F_obj reader_os (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_resource_5F_map reader_resources (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_scheduletable_5F_map reader_scheduletables (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_task_5F_map reader_tasks (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_root_5F_obj class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_root_5F_obj ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Pointer class for @root_obj class                     *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_root_5F_obj : public acPtr_class {

//--- Attributes
  public : GALGAS_lstring mAttribute_name ;
  public : GALGAS_os_5F_obj mAttribute_os ;
  public : GALGAS_com mAttribute_com ;
  public : GALGAS_task_5F_map mAttribute_tasks ;
  public : GALGAS_counter_5F_map mAttribute_counters ;
  public : GALGAS_alarm_5F_map mAttribute_alarms ;
  public : GALGAS_resource_5F_map mAttribute_resources ;
  public : GALGAS_event_5F_map mAttribute_events ;
  public : GALGAS_isr_5F_map mAttribute_isrs ;
  public : GALGAS_message_5F_map mAttribute_messages ;
  public : GALGAS_netmess_5F_map mAttribute_net_5F_messages ;
  public : GALGAS_scheduletable_5F_map mAttribute_scheduletables ;
  public : GALGAS_app_5F_map mAttribute_applis ;

//--- Constructor
  public : cPtr_root_5F_obj (const GALGAS_lstring & in_name,
                             const GALGAS_os_5F_obj & in_os,
                             const GALGAS_com & in_com,
                             const GALGAS_task_5F_map & in_tasks,
                             const GALGAS_counter_5F_map & in_counters,
                             const GALGAS_alarm_5F_map & in_alarms,
                             const GALGAS_resource_5F_map & in_resources,
                             const GALGAS_event_5F_map & in_events,
                             const GALGAS_isr_5F_map & in_isrs,
                             const GALGAS_message_5F_map & in_messages,
                             const GALGAS_netmess_5F_map & in_net_5F_messages,
                             const GALGAS_scheduletable_5F_map & in_scheduletables,
                             const GALGAS_app_5F_map & in_applis
                             COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
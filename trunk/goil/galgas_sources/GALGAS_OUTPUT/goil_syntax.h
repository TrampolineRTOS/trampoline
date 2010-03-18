//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'goil_syntax.h'                            *
//                       Generated by version 1.9.10                         *
//                      march 18th, 2010, at 9h48'47"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_syntax_DEFINED
#define goil_syntax_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"
#include "goil_lexique.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "cfg_types.h"
#include "com_type.h"
#include "config_type.h"
#include "goil_env_verification.h"
#include "goil_semantics.h"
#include "goil_types_app.h"
#include "goil_types_networkmessage.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                   Parser class goil_syntax declaration                    *
//                                                                           *
//---------------------------------------------------------------------------*

class goil_syntax {
  public : virtual ~goil_syntax (void) {}

  protected : virtual void nt_start_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_file_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) = 0 ;

  protected : virtual void nt_OIL_5F_version_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_description_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) = 0 ;

  protected : virtual void nt_application_5F_definition_ (C_Lexique_goil_5F_lexique &,
                                GGS_root_obj  &) = 0 ;

  protected : virtual void nt_object_5F_definition_5F_list_ (C_Lexique_goil_5F_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) = 0 ;

  protected : virtual void nt_nm_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_boolean_ (C_Lexique_goil_5F_lexique &,
                                GGS_lbool  &) = 0 ;

  protected : virtual void nt_free_5F_field_ (C_Lexique_goil_5F_lexique &,
                                GGS_ident_map  &) = 0 ;

  protected : virtual void nt_include_5F_file_5F_level_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) = 0 ;

  protected : virtual void nt_include_5F_cpu_5F_level_ (C_Lexique_goil_5F_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) = 0 ;

  protected : virtual void nt_implementation_5F_definition_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &) = 0 ;

  protected : virtual void nt_os_ (C_Lexique_goil_5F_lexique &,
                                GGS_os_obj  &) = 0 ;

  protected : virtual void nt_appmode_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : virtual void nt_task_ (C_Lexique_goil_5F_lexique &,
                                GGS_task_map  &) = 0 ;

  protected : virtual void nt_counter_ (C_Lexique_goil_5F_lexique &,
                                GGS_counter_map  &) = 0 ;

  protected : virtual void nt_alarm_ (C_Lexique_goil_5F_lexique &,
                                GGS_alarm_map  &) = 0 ;

  protected : virtual void nt_resource_ (C_Lexique_goil_5F_lexique &,
                                GGS_resource_map  &) = 0 ;

  protected : virtual void nt_event_ (C_Lexique_goil_5F_lexique &,
                                GGS_event_map  &) = 0 ;

  protected : virtual void nt_isr_ (C_Lexique_goil_5F_lexique &,
                                GGS_isr_map  &) = 0 ;

  protected : virtual void nt_mess_ (C_Lexique_goil_5F_lexique &,
                                GGS_message_map  &) = 0 ;

  protected : virtual void nt_scheduletable_ (C_Lexique_goil_5F_lexique &,
                                GGS_scheduletable_map  &) = 0 ;

  protected : virtual void nt_appli_ (C_Lexique_goil_5F_lexique &,
                                GGS_app_map  &) = 0 ;

  protected : virtual void nt_networkmess_ (C_Lexique_goil_5F_lexique &,
                                GGS_netmess_map  &) = 0 ;

  protected : virtual void nt_com_ (C_Lexique_goil_5F_lexique &,
                                GGS_com  &) = 0 ;

  protected : virtual void nt_ipdu_ (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_start_i0_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_syntax_file_i1_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_description_i2_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_OIL_5F_version_i3_ (C_Lexique_goil_5F_lexique &,
                                GGS_lstring  &,
                                GGS_lstring  &) ;

  protected : void rule_goil_5F_syntax_application_5F_definition_i4_ (C_Lexique_goil_5F_lexique &,
                                GGS_root_obj  &) ;

  protected : void rule_goil_5F_syntax_object_5F_definition_5F_list_i5_ (C_Lexique_goil_5F_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_nm_i6_ (C_Lexique_goil_5F_lexique &) ;

  protected : void rule_goil_5F_syntax_boolean_i7_ (C_Lexique_goil_5F_lexique &,
                                GGS_lbool  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_free_5F_field_i8_ (C_Lexique_goil_5F_lexique &,
                                GGS_ident_map  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_include_5F_file_5F_level_i9_ (C_Lexique_goil_5F_lexique &,
                                GGS_implementation  &,
                                GGS_root_obj  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique &) = 0 ;

  protected : void rule_goil_5F_syntax_include_5F_cpu_5F_level_i10_ (C_Lexique_goil_5F_lexique &,
                                GGS_os_obj  &,
                                GGS_com  &,
                                GGS_task_map  &,
                                GGS_counter_map  &,
                                GGS_alarm_map  &,
                                GGS_resource_map  &,
                                GGS_event_map  &,
                                GGS_isr_map  &,
                                GGS_message_map  &,
                                GGS_netmess_map  &,
                                GGS_scheduletable_map  &,
                                GGS_app_map  &) ;

  protected : virtual PMSInt16 select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique &) = 0 ;

} ;

//---------------------------------------------------------------------------*

#endif

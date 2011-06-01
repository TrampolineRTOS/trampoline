//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'goil_code_generation.h'                        *
//                        Generated by version 1.9.9                         *
//                     january 28th, 2010, at 15h59'37"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_code_generation_DEFINED
#define goil_code_generation_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "cfg_types.h"
#include "config_type.h"
#include "goil_env_verification.h"
#include "goil_options.h"
#include "goil_routines.h"
#include "goil_semantic_types.h"
#include "goil_types_app.h"
#include "goil_types_os.h"
#include "goil_types_task.h"
#include "system_config.h"
#include "template_routines.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_signed_type'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_signed_type (C_Compiler &,
                                GGS_uint64  ,
                                GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'generate_unsigned_type'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_unsigned_type (C_Compiler &,
                                GGS_uint64  ,
                                GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'generate_mask_type'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_mask_type (C_Compiler &,
                                GGS_uint64  ,
                                GGS_string ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'generate_types'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_types (C_Compiler &,
                                GGS_task_map  ,
                                GGS_isr_map  ,
                                GGS_alarm_map  ,
                                GGS_counter_map  ,
                                GGS_resource_map  ,
                                GGS_scheduletable_map  ,
                                GGS_app_map  ,
                                GGS_uint  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'generate_timing_prot'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_timing_prot (C_Compiler &,
                                GGS_task_map  ,
                                GGS_resource_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'compute_actual_task_priority'                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_actual_task_priority (C_Compiler &,
                                GGS_task_map  ,
                                GGS_prio_map  &,
                                GGS_uint  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'compute_actual_isr_priority'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_actual_isr_priority (C_Compiler &,
                                GGS_isr_map  ,
                                GGS_prio_map  &,
                                GGS_uint  ,
                                GGS_uint  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'compute_rez_priority'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_rez_priority (C_Compiler &,
                                GGS_resource_map  ,
                                GGS_task_map  ,
                                GGS_isr_map  ,
                                GGS_prio_map  ,
                                GGS_prio_map  &,
                                GGS_stringMap  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'compute_ready_list'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_ready_list (C_Compiler &,
                                GGS_prio_map  ,
                                GGS_prio_map  ,
                                GGS_uint  ,
                                GGS_uint  ,
                                GGS_prio_list  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'compute_app_for_obj'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_compute_app_for_obj (C_Compiler &,
                                GGS_app_map  ,
                                GGS_stringMap  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'computeEvents'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_computeEvents (C_Compiler &,
                                const GGS_root_obj  ,
                                GGS_eventMaskMap  & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'generate_all'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_all (C_Compiler &,
                                const GGS_root_obj   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_targets.h'                            *
//                        Generated by version 1.9.1                         *
//                    september 21th, 2009, at 18h19'16"                     *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_targets_DEFINED
#define goil_targets_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/C_GGS_Object.h"
#include "galgas/GGS_location.h"
#include "galgas/GGS_data.h"
#include "galgas/GGS_lbool.h"
#include "galgas/GGS_lchar.h"
#include "galgas/GGS_lstring.h"
#include "galgas/GGS_ldouble.h"
#include "galgas/GGS_luint.h"
#include "galgas/GGS_lsint.h"
#include "galgas/GGS_luint64.h"
#include "galgas/GGS_lsint64.h"
#include "galgas/GGS_stringset.h"
#include "galgas/GGS_binaryset.h"
#include "galgas/GGS_filewrapper.h"
#include "galgas/predefined_types.h"
#include "galgas/AC_galgas_class.h"
#include "galgas/AC_galgas_domain.h"
#include "galgas/AC_galgas_mapindex.h"
#include "galgas/AC_galgas_map.h"
#include "galgas/AC_galgas_listmap.h"
#include "galgas/AC_galgas_list.h"
#include "galgas/AC_galgas_sortedlist.h"

//---------------------------------------------------------------------------*

#include "galgas/C_Lexique.h"

// Include imported semantics
#include "cfg_types.h"
#include "goil_options.h"
#include "goil_routines.h"
#include "goil_target_arm7.h"
#include "goil_target_avr.h"
#include "goil_target_c166.h"
#include "goil_target_h8300h.h"
#include "goil_target_hcs12.h"
#include "goil_target_libpcl.h"
#include "goil_target_posix.h"
#include "goil_target_posix_vp2.h"
#include "goil_target_ppc.h"
#include "goil_target_v850e.h"
#include "goil_types_isr.h"
#include "goil_types_os.h"
#include "goil_types_task.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                   Routine 'generate_context_and_stack'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_context_and_stack (C_Compiler &,
                                GGS_config  ,
                                GGS_lstring  ,
                                GGS_oil_obj  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'generate_isr_specific'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_specific (C_Compiler &,
                                const GGS_isr_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Routine 'generate_counter_for_target'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_for_target (C_Compiler &,
                                const GGS_string ,
                                const GGS_counter_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Routine 'generate_counter_specific'                     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_specific (C_Compiler &,
                                const GGS_counter_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'goil_target_cortex_m3.h'                       *
//                        Generated by version 1.9.7                         *
//                     december 17th, 2009, at 9h55'50"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_target_cortex_m3_DEFINED
#define goil_target_cortex_m3_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_routines.h"
#include "goil_semantic_types.h"
#include "goil_types_counter.h"
#include "goil_types_isr.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                   Routine 'generate_target_cortex_m3'                     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_target_cortex_m3 (C_Compiler &,
                                const GGS_lstring  ,
                                const GGS_ident_map  ,
                                const GGS_oil_obj  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'generate_isr_cortex_m3'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_cortex_m3 (C_Compiler &,
                                const GGS_isr_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Routine 'generate_counter_cortex_m3'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_cortex_m3 (C_Compiler &,
                                const GGS_counter_map  ,
                                GGS_string & COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*

#endif

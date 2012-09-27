//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'template_functions.h'                         *
//                    Generated by version version 2.1.4                     *
//                     january 10th, 2011, at 14h31'42"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef template_functions_ENTITIES_DEFINED
#define template_functions_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "system_config.h"
#include "goil_types_root.h"
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
#include "template_invocation.h"
#include "template_semantics.h"
#include "goil_env_verification.h"

//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'trueFalse'                            *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_trueFalse (const GALGAS_bool & constinArgument0,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             Function 'yesNo'                              *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_yesNo (const GALGAS_bool & constinArgument0,
                              C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'TRUEFALSE'                            *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_TRUEFALSE (const GALGAS_bool & constinArgument0,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
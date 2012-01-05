//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'tasks_verif.cpp'                           *
//                    Generated by version version 2.2.7                     *
//                     december 2nd, 2011, at 14h25'19"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "tasks_verif.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "tasks_verif.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'tasks_well_formed'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_tasks_5F_well_5F_formed (const GALGAS_task_5F_map constinArgument_tasks,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  //-------- @foreachInstructionForGeneration
  cEnumerator_task_5F_map enumerator_841 (constinArgument_tasks, kEnumeration_up) ;
  //--- simple foreach instruction
  while (enumerator_841.hasCurrentObject ()) {
    //-------- @structuredCastInstructionForGeneration
    if (enumerator_841.current_task (HERE).reader_priority (SOURCE_FILE_AT_LINE (48)).isValid ()) {
      if (enumerator_841.current_task (HERE).reader_priority (SOURCE_FILE_AT_LINE (48)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
        //-------- @errorInstructionForGeneration
        GALGAS_location location_0 (enumerator_841.current_lkey (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_0, GALGAS_string ("PRIORITY attribute not defined for TASK ").operator_concat (enumerator_841.current_lkey (HERE).reader_string (SOURCE_FILE_AT_LINE (50)) COMMA_SOURCE_FILE_AT_LINE (50)) COMMA_SOURCE_FILE_AT_LINE (50)) ;
      }
    }
    //-------- @structuredCastInstructionForGeneration
    if (enumerator_841.current_task (HERE).reader_activation (SOURCE_FILE_AT_LINE (54)).isValid ()) {
      if (enumerator_841.current_task (HERE).reader_activation (SOURCE_FILE_AT_LINE (54)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
        //-------- @errorInstructionForGeneration
        GALGAS_location location_1 (enumerator_841.current_lkey (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_1, GALGAS_string ("ACTIVATION attribute not defined for TASK ").operator_concat (enumerator_841.current_lkey (HERE).reader_string (SOURCE_FILE_AT_LINE (56)) COMMA_SOURCE_FILE_AT_LINE (56)) COMMA_SOURCE_FILE_AT_LINE (56)) ;
      }else if (enumerator_841.current_task (HERE).reader_activation (SOURCE_FILE_AT_LINE (54)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
        GALGAS_uint_33__32__5F_class cast_1214_ui ((cPtr_uint_33__32__5F_class *) enumerator_841.current_task (HERE).reader_activation (SOURCE_FILE_AT_LINE (54)).ptr ()) ;
        //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
        GALGAS_lstringlist var_defined_5F_events = enumerator_841.current_task (HERE).reader_events (SOURCE_FILE_AT_LINE (58)) ;
        //-------- @ifInstructionForGeneration
        const enumGalgasBool test_2 = GALGAS_bool (kIsStrictSup, var_defined_5F_events.reader_length (SOURCE_FILE_AT_LINE (59)).objectCompare (GALGAS_uint ((PMUInt32) 0U))).operator_and (GALGAS_bool (kIsStrictSup, cast_1214_ui.reader_value (SOURCE_FILE_AT_LINE (59)).objectCompare (GALGAS_uint ((PMUInt32) 1U))) COMMA_SOURCE_FILE_AT_LINE (59)).boolEnum () ;
        if (kBoolTrue == test_2) {
          //-------- @errorInstructionForGeneration
          GALGAS_location location_3 (enumerator_841.current_lkey (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
          inCompiler->emitSemanticError (location_3, GALGAS_string ("ACTIVATION attribute for extended task ").operator_concat (enumerator_841.current_lkey (HERE).reader_string (SOURCE_FILE_AT_LINE (60)) COMMA_SOURCE_FILE_AT_LINE (60)).operator_concat (GALGAS_string (" should be set to 1") COMMA_SOURCE_FILE_AT_LINE (60)) COMMA_SOURCE_FILE_AT_LINE (60)) ;
          //-------- @errorInstructionForGeneration
          inCompiler->emitSemanticError (cast_1214_ui.reader_location (SOURCE_FILE_AT_LINE (61)), GALGAS_string ("ACTIVATION attribute set to ").operator_concat (cast_1214_ui.reader_value (SOURCE_FILE_AT_LINE (61)).reader_string (SOURCE_FILE_AT_LINE (61)) COMMA_SOURCE_FILE_AT_LINE (61)).operator_concat (GALGAS_string (" here") COMMA_SOURCE_FILE_AT_LINE (61)) COMMA_SOURCE_FILE_AT_LINE (61)) ;
        }
      }else{
        //-------- @errorInstructionForGeneration
        inCompiler->emitSemanticError (inCompiler->here (), GALGAS_string ("Internal error, wrong datatype for ACTIVATION in task ").operator_concat (enumerator_841.current_lkey (HERE).reader_string (SOURCE_FILE_AT_LINE (64)) COMMA_SOURCE_FILE_AT_LINE (64)) COMMA_SOURCE_FILE_AT_LINE (64)) ;
      }
    }
    //-------- @ifInstructionForGeneration
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_841.current_task (HERE).reader_schedule (SOURCE_FILE_AT_LINE (67)).reader_string (SOURCE_FILE_AT_LINE (67)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      //-------- @errorInstructionForGeneration
      GALGAS_location location_5 (enumerator_841.current_lkey (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
      inCompiler->emitSemanticError (location_5, GALGAS_string ("SCHEDULE attribute not defined for TASK ").operator_concat (enumerator_841.current_lkey (HERE).reader_string (SOURCE_FILE_AT_LINE (68)) COMMA_SOURCE_FILE_AT_LINE (68)) COMMA_SOURCE_FILE_AT_LINE (68)) ;
    }
    //-------- @structuredCastInstructionForGeneration
    if (enumerator_841.current_task (HERE).reader_autostart (SOURCE_FILE_AT_LINE (71)).isValid ()) {
      if (enumerator_841.current_task (HERE).reader_autostart (SOURCE_FILE_AT_LINE (71)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_task_5F_autostart_5F_void) {
        //-------- @errorInstructionForGeneration
        GALGAS_location location_6 (enumerator_841.current_lkey (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_6, GALGAS_string ("AUTOSTART attribute not defined for TASK ").operator_concat (enumerator_841.current_lkey (HERE).reader_string (SOURCE_FILE_AT_LINE (73)) COMMA_SOURCE_FILE_AT_LINE (73)) COMMA_SOURCE_FILE_AT_LINE (73)) ;
      }
    }
    enumerator_841.gotoNextObject () ;
  }
}


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



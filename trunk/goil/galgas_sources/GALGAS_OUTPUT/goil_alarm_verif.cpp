//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_alarm_verif.cpp'                         *
//                    Generated by version version 2.2.7                     *
//                     december 2nd, 2011, at 14h25'16"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "goil_alarm_verif.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_alarm_verif.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                   Routine 'counters_of_alarms_defined'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_counters_5F_of_5F_alarms_5F_defined (GALGAS_alarm_5F_map inArgument_alarms,
                                                  GALGAS_counter_5F_map inArgument_counters,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  //-------- @foreachInstructionForGeneration
  cEnumerator_alarm_5F_map enumerator_252 (inArgument_alarms, kEnumeration_up) ;
  //--- simple foreach instruction
  while (enumerator_252.hasCurrentObject ()) {
    //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
    GALGAS_lstring var_counter = enumerator_252.current_alarm (HERE).reader_counter_5F_name (SOURCE_FILE_AT_LINE (16)) ;
    //-------- @ifInstructionForGeneration
    const enumGalgasBool test_0 = inArgument_counters.reader_hasKey (var_counter.reader_string (SOURCE_FILE_AT_LINE (17)) COMMA_SOURCE_FILE_AT_LINE (17)).operator_not (SOURCE_FILE_AT_LINE (17)).operator_and (GALGAS_bool (kIsNotEqual, var_counter.reader_string (SOURCE_FILE_AT_LINE (17)).objectCompare (GALGAS_string ("SystemCounter"))) COMMA_SOURCE_FILE_AT_LINE (17)).boolEnum () ;
    if (kBoolTrue == test_0) {
      //-------- @errorInstructionForGeneration
      GALGAS_location location_1 (var_counter.reader_location (HERE)) ; // Implicit use of 'location' reader
      inCompiler->emitSemanticError (location_1, GALGAS_string ("counter ").operator_concat (var_counter.reader_string (SOURCE_FILE_AT_LINE (18)) COMMA_SOURCE_FILE_AT_LINE (18)).operator_concat (GALGAS_string (" is not defined !") COMMA_SOURCE_FILE_AT_LINE (18)) COMMA_SOURCE_FILE_AT_LINE (18)) ;
    }else if (kBoolFalse == test_0) {
      //-------- @structuredCastInstructionForGeneration
      if (enumerator_252.current_alarm (HERE).reader_autostart_5F_params (SOURCE_FILE_AT_LINE (25)).isValid ()) {
        if (enumerator_252.current_alarm (HERE).reader_autostart_5F_params (SOURCE_FILE_AT_LINE (25)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_alarm_5F_autostart_5F_true) {
          GALGAS_alarm_5F_autostart_5F_true cast_730_a ((cPtr_alarm_5F_autostart_5F_true *) enumerator_252.current_alarm (HERE).reader_autostart_5F_params (SOURCE_FILE_AT_LINE (25)).ptr ()) ;
          //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
          GALGAS_location var_alarm_5F_loc = cast_730_a.reader_location (SOURCE_FILE_AT_LINE (27)) ;
          //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
          GALGAS_uint var_alarm_5F_time = cast_730_a.reader_alarm_5F_time (SOURCE_FILE_AT_LINE (28)).reader_uint_36__34_ (SOURCE_FILE_AT_LINE (28)).reader_uint (inCompiler COMMA_SOURCE_FILE_AT_LINE (28)) ;
          //-------- @localVariableOrConstantDeclarationWithSourceExpressionForGeneration
          GALGAS_uint var_cycle_5F_time = cast_730_a.reader_cycle_5F_time (SOURCE_FILE_AT_LINE (29)).reader_uint_36__34_ (SOURCE_FILE_AT_LINE (29)).reader_uint (inCompiler COMMA_SOURCE_FILE_AT_LINE (29)) ;
          //-------- @ifInstructionForGeneration
          const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_alarm_5F_time.objectCompare (GALGAS_uint ((PMUInt32) 0U))).boolEnum () ;
          if (kBoolTrue == test_2) {
            //-------- @ifInstructionForGeneration
            const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, GALGAS_bool (gOption_goil_5F_options_autosar_5F_on.reader_value ()).objectCompare (GALGAS_bool (true))).boolEnum () ;
            if (kBoolTrue == test_3) {
              //-------- @errorInstructionForGeneration
              GALGAS_location location_4 (cast_730_a.reader_alarm_5F_time (SOURCE_FILE_AT_LINE (34)).reader_location (HERE)) ; // Implicit use of 'location' reader
              inCompiler->emitSemanticError (location_4, GALGAS_string ("ALARMTIME must be > 0") COMMA_SOURCE_FILE_AT_LINE (34)) ;
            }else if (kBoolFalse == test_3) {
              //-------- @warningInstructionForGeneration
              GALGAS_location location_5 (cast_730_a.reader_alarm_5F_time (SOURCE_FILE_AT_LINE (36)).reader_location (HERE)) ; // Implicit use of 'location' reader
              inCompiler->emitSemanticWarning (location_5, GALGAS_string ("ALARMTIME equal to 0 has an undefined behavior") COMMA_SOURCE_FILE_AT_LINE (36)) ;
            }
          }
          //-------- @localVariableDeclarationForGeneration
          GALGAS_counter_5F_obj var_ct ;
          //-------- @methodCallInstructionForGeneration
          inArgument_counters.method_getCounter (var_counter, var_ct, inCompiler COMMA_SOURCE_FILE_AT_LINE (41)) ;
          //-------- END @methodCallInstructionForGeneration
          //-------- @structuredCastInstructionForGeneration
          if (var_ct.reader_max_5F_allowed_5F_value (SOURCE_FILE_AT_LINE (42)).isValid ()) {
            if (var_ct.reader_max_5F_allowed_5F_value (SOURCE_FILE_AT_LINE (42)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
              GALGAS_uint_33__32__5F_class cast_1434_mc ((cPtr_uint_33__32__5F_class *) var_ct.reader_max_5F_allowed_5F_value (SOURCE_FILE_AT_LINE (42)).ptr ()) ;
              //-------- @ifInstructionForGeneration
              const enumGalgasBool test_6 = GALGAS_bool (kIsStrictSup, var_alarm_5F_time.objectCompare (cast_1434_mc.reader_value (SOURCE_FILE_AT_LINE (44)))).boolEnum () ;
              if (kBoolTrue == test_6) {
                //-------- @errorInstructionForGeneration
                inCompiler->emitSemanticError (cast_730_a.reader_location (SOURCE_FILE_AT_LINE (45)), GALGAS_string ("ALARMTIME is greater than counter MAXALLOWEDVALUE") COMMA_SOURCE_FILE_AT_LINE (45)) ;
              }
              //-------- @ifInstructionForGeneration
              const enumGalgasBool test_7 = GALGAS_bool (kIsStrictSup, var_cycle_5F_time.objectCompare (cast_1434_mc.reader_value (SOURCE_FILE_AT_LINE (47)))).boolEnum () ;
              if (kBoolTrue == test_7) {
                //-------- @errorInstructionForGeneration
                inCompiler->emitSemanticError (cast_730_a.reader_location (SOURCE_FILE_AT_LINE (48)), GALGAS_string ("CYCLETIME is greater than counter MAXALLOWEDVALUE") COMMA_SOURCE_FILE_AT_LINE (48)) ;
              }
            }
          }
        }
      }
    }
    enumerator_252.gotoNextObject () ;
  }
}


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



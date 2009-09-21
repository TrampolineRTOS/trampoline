//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'goil_alarm_verif.cpp'                         *
//                        Generated by version 1.9.1                         *
//                    september 21th, 2009, at 18h16'53"                     *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 572
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_alarm_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_alarm_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "counters_of_alarms_defined"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_counters_of_alarms_defined (C_Compiler & inLexique,
                                GGS_alarm_map   var_cas_alarms,
                                GGS_counter_map   var_cas_counters COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_counters_of_alarms_defined at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_alarm_map::cEnumerator enumerator_324 (var_cas_alarms, true) ;
    const GGS_alarm_map::cElement * operand_324 = NULL ;
    while (((operand_324 = enumerator_324.nextObject ()))) {
      macroValidPointer (operand_324) ;
      GGS_lstring  var_cas_counter ;
      var_cas_counter = operand_324->mInfo.alarm.reader_counter_name (inLexique COMMA_SOURCE_FILE_AT_LINE (16)) ;
      if ((((var_cas_counters.reader_hasKey (inLexique, var_cas_counter.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (17)) COMMA_SOURCE_FILE_AT_LINE (17))).operator_not ()).operator_and ((var_cas_counter.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (17))).operator_isNotEqual (GGS_string ("SystemCounter")))).isBuiltAndTrue ()) {
        var_cas_counter.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, ((GGS_string ("counter ")).operator_concat (var_cas_counter.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (18)))).operator_concat (GGS_string (" is not defined !")) COMMA_SOURCE_FILE_AT_LINE (19)) ;
      }else{
        { const GGS_autostart_obj _var_1840 = operand_324->mInfo.alarm.reader_autostart_params (inLexique COMMA_SOURCE_FILE_AT_LINE (25)) ; // CAST instruction
          if (_var_1840.getPtr () != NULL) {
            macroValidPointer (_var_1840.getPtr ()) ;
            if (typeid (cPtr_alarm_autostart_true) == typeid (* (_var_1840.getPtr ()))) {
              const GGS_alarm_autostart_true var_cas_a (_var_1840.getPtr ()) ;
              GGS_location  var_cas_alarm_loc ;
              var_cas_alarm_loc = var_cas_a.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (27)) ;
              GGS_uint  var_cas_alarm_time ;
              var_cas_alarm_time = var_cas_a.reader_alarm_time (inLexique COMMA_SOURCE_FILE_AT_LINE (28)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (28)).reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (28)) ;
              GGS_uint  var_cas_cycle_time ;
              var_cas_cycle_time = var_cas_a.reader_cycle_time (inLexique COMMA_SOURCE_FILE_AT_LINE (29)).reader_uint64 (inLexique COMMA_SOURCE_FILE_AT_LINE (29)).reader_uint (inLexique COMMA_SOURCE_FILE_AT_LINE (29)) ;
              if (((var_cas_alarm_time).operator_isEqual (GGS_uint (0U))).isBuiltAndTrue ()) {
                if (((gOption_goil_5F_options_autosar_5F_on.value ()).operator_isEqual (GGS_bool (true))).isBuiltAndTrue ()) {
                  var_cas_a.reader_alarm_time (inLexique COMMA_SOURCE_FILE_AT_LINE (34)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("ALARMTIME must be > 0") COMMA_SOURCE_FILE_AT_LINE (35)) ;
                }else{
                  var_cas_a.reader_alarm_time (inLexique COMMA_SOURCE_FILE_AT_LINE (36)).reader_location (inLexique COMMA_HERE).signalGGSSemanticWarning (inLexique, GGS_string ("ALARMTIME equal to 0 has an undefined behavior") COMMA_SOURCE_FILE_AT_LINE (36)) ;
                }
              }
              GGS_counter_obj  var_cas_ct ;
              const GGS_counter_map  temp_1415 = var_cas_counters ;
              if (temp_1415.isBuilt ()) {
                temp_1415 (HERE)->method_getCounter (inLexique, var_cas_counter, var_cas_ct COMMA_SOURCE_FILE_AT_LINE (41)) ;
              }
              { const GGS_basic_type _var_1818 = var_cas_ct.reader_max_allowed_value (inLexique COMMA_SOURCE_FILE_AT_LINE (42)) ; // CAST instruction
                if (_var_1818.getPtr () != NULL) {
                  macroValidPointer (_var_1818.getPtr ()) ;
                  if (typeid (cPtr_uint32_class) == typeid (* (_var_1818.getPtr ()))) {
                    const GGS_uint32_class var_cas_mc (_var_1818.getPtr ()) ;
                    if (((var_cas_alarm_time).operator_strictSup (var_cas_mc.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (44)))).isBuiltAndTrue ()) {
                      var_cas_a.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (45)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("ALARMTIME is greater than counter MAXALLOWEDVALUE") COMMA_SOURCE_FILE_AT_LINE (46)) ;
                    }
                    if (((var_cas_cycle_time).operator_strictSup (var_cas_mc.reader_value (inLexique COMMA_SOURCE_FILE_AT_LINE (47)))).isBuiltAndTrue ()) {
                      var_cas_a.reader_location (inLexique COMMA_SOURCE_FILE_AT_LINE (48)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("CYCLETIME is greater than counter MAXALLOWEDVALUE") COMMA_SOURCE_FILE_AT_LINE (49)) ;
                    }
                  }else{
                  }
                }
              }
            }else{
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_counters_of_alarms_defined\n") ;
  #endif
}

//---------------------------------------------------------------------------*


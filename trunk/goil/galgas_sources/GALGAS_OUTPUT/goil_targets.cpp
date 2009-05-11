//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_targets.cpp'                           *
//                        Generated by version 1.8.2                         *
//                        may 6th, 2009, at 12h3'16"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 463
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "goil_targets.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_targets.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "generate_context_and_stack"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_context_and_stack (C_Compiler & _inLexique,
                                GGS_config   var_cas_cfg,
                                GGS_lstring   var_cas_name,
                                GGS_oil_obj   var_cas_exe,
                                GGS_string & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_context_and_stack at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_tpl_context_and_stack ;
  var_cas_tpl_context_and_stack = GGS_string (true, "") ;
  GGS_string var_cas_context_and_stack ;
  var_cas_context_and_stack = GGS_string (true, "") ;
  GGS_ident_map  var_cas_idents ;
  var_cas_idents = GGS_ident_map ::constructor_emptyMap (_inLexique COMMA_HERE) ;
  GGS_attrs  var_cas_attrs ;
  var_cas_attrs = GGS_attrs ::constructor_new (_inLexique, GGS_location (_inLexique), GGS_cfg_attrs ::constructor_emptyMap (_inLexique COMMA_HERE) COMMA_HERE) ;
  GGS_string var_cas_target ;
  var_cas_target = function_arch (_inLexique COMMA_SOURCE_FILE_AT_LINE (58)) ;
  { const GGS_oil_obj _var_3106 = var_cas_exe ; // CAST instruction
    if (_var_3106.getPtr () != NULL) {
      macroValidPointer (_var_3106.getPtr ()) ;
      if (typeid (cPtr_task_obj) == typeid (* (_var_3106.getPtr ()))) {
        const GGS_task_obj var_cas_tk (_var_3106.getPtr ()) ;
        ::routine_retrieveTemplateString (_inLexique,  var_cas_tpl_context_and_stack,  GGS_string (true, "each_task_specific") COMMA_SOURCE_FILE_AT_LINE (62)) ;
        var_cas_context_and_stack = var_cas_tpl_context_and_stack ;
        var_cas_idents = var_cas_tk.reader_others (_inLexique COMMA_SOURCE_FILE_AT_LINE (64)) ;
        GGS_basic_type  var_cas_b_attrs ;
        const GGS_config  _temp_2376 = var_cas_cfg ;
        if (_temp_2376._isBuilt ()) {
          _temp_2376 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "task_attrs"), GGS_location (_inLexique) COMMA_HERE), var_cas_b_attrs COMMA_SOURCE_FILE_AT_LINE (66)) ;
        }
        { const GGS_basic_type _var_2579 = var_cas_b_attrs ; // CAST instruction
          if (_var_2579.getPtr () != NULL) {
            macroValidPointer (_var_2579.getPtr ()) ;
            if (typeid (cPtr_attrs) == typeid (* (_var_2579.getPtr ()))) {
              const GGS_attrs var_cas_at (_var_2579.getPtr ()) ;
              var_cas_attrs = var_cas_at ;
            }else{
              GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Internal error, unknown config task attributes") COMMA_SOURCE_FILE_AT_LINE (70)) ;
            }
          }
        }
      }else if (typeid (cPtr_isr_obj) == typeid (* (_var_3106.getPtr ()))) {
        const GGS_isr_obj var_cas_isr (_var_3106.getPtr ()) ;
        ::routine_retrieveTemplateString (_inLexique,  var_cas_tpl_context_and_stack,  GGS_string (true, "each_isr_specific") COMMA_SOURCE_FILE_AT_LINE (72)) ;
        var_cas_context_and_stack = var_cas_tpl_context_and_stack ;
        var_cas_idents = var_cas_isr.reader_other_fields (_inLexique COMMA_SOURCE_FILE_AT_LINE (74)) ;
        GGS_basic_type  var_cas_b_attrs ;
        const GGS_config  _temp_2830 = var_cas_cfg ;
        if (_temp_2830._isBuilt ()) {
          _temp_2830 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, GGS_string (true, "isr_attrs"), GGS_location (_inLexique) COMMA_HERE), var_cas_b_attrs COMMA_SOURCE_FILE_AT_LINE (76)) ;
        }
        { const GGS_basic_type _var_3031 = var_cas_b_attrs ; // CAST instruction
          if (_var_3031.getPtr () != NULL) {
            macroValidPointer (_var_3031.getPtr ()) ;
            if (typeid (cPtr_attrs) == typeid (* (_var_3031.getPtr ()))) {
              const GGS_attrs var_cas_at (_var_3031.getPtr ()) ;
              var_cas_attrs = var_cas_at ;
            }else{
              GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Internal error, unknown config isr attributes") COMMA_SOURCE_FILE_AT_LINE (80)) ;
            }
          }
        }
      }else{
        var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "Unknown executable object") COMMA_SOURCE_FILE_AT_LINE (83)) ;
      }
    }
  }
  if (((var_cas_target)._operator_isEqual (GGS_string (true, "c166"))).isBuiltAndTrue ()) {
    ::routine_generate_target_c166 (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (86)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "libpcl"))).isBuiltAndTrue ()) {
    ::routine_generate_target_libpcl (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (88)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "posix"))).isBuiltAndTrue ()) {
    ::routine_generate_target_posix (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (90)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "hcs12"))).isBuiltAndTrue ()) {
    ::routine_generate_target_hcs12 (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (92)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "ppc"))).isBuiltAndTrue ()) {
    ::routine_generate_target_ppc (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (94)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "v850e"))).isBuiltAndTrue ()) {
    ::routine_generate_target_v850e (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (96)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "h8300h"))).isBuiltAndTrue ()) {
    ::routine_generate_target_h8300h (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (98)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "arm"))).isBuiltAndTrue ()) {
    ::routine_generate_target_arm7 (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (100)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "avr"))).isBuiltAndTrue ()) {
    ::routine_generate_target_avr (_inLexique,  var_cas_name,  var_cas_idents,  var_cas_exe,  var_cas_context_and_stack COMMA_SOURCE_FILE_AT_LINE (102)) ;
  }else{
    GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string (true, "unknown target: "))._operator_concat (var_cas_target) COMMA_SOURCE_FILE_AT_LINE (105)) ;
  }
  var_cas_result = (var_cas_result)._operator_concat (var_cas_context_and_stack) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_context_and_stack\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "generate_isr_specific"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_isr_specific (C_Compiler & _inLexique,
                                const GGS_isr_map   var_cas_isrs,
                                GGS_string & var_cas_code COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_isr_specific at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_target ;
  var_cas_target = function_arch (_inLexique COMMA_SOURCE_FILE_AT_LINE (114)) ;
  ::routine_retrieveTemplateString (_inLexique,  var_cas_code,  GGS_string (true, "isr_specific") COMMA_SOURCE_FILE_AT_LINE (116)) ;
  if (((var_cas_target)._operator_isEqual (GGS_string (true, "c166"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_c166 (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (119)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "libpcl"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_libpcl (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (121)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "posix"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_posix (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (123)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "hcs12"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_hcs12 (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (125)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "ppc"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_ppc (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (127)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "v850e"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_v850e (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (129)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "h8300h"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_h8300h (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (131)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "arm"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_arm7 (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (133)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "avr"))).isBuiltAndTrue ()) {
    ::routine_generate_isr_avr (_inLexique,  var_cas_isrs,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (135)) ;
  }else{
    GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string (true, "unknown target: "))._operator_concat (var_cas_target) COMMA_SOURCE_FILE_AT_LINE (138)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_isr_specific\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//          Implementation of routine "generate_counter_specific"            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_counter_specific (C_Compiler & _inLexique,
                                const GGS_counter_map   var_cas_counters,
                                GGS_string & var_cas_code COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_counter_specific at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_target ;
  var_cas_target = function_arch (_inLexique COMMA_SOURCE_FILE_AT_LINE (146)) ;
  ::routine_retrieveTemplateString (_inLexique,  var_cas_code,  GGS_string (true, "counter_specific") COMMA_SOURCE_FILE_AT_LINE (148)) ;
  if (((var_cas_target)._operator_isEqual (GGS_string (true, "c166"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_c166 (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (151)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "libpcl"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_libpcl (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (153)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "posix"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_posix (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (155)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "hcs12"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_hcs12 (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (157)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "ppc"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_ppc (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (159)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "v850e"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_v850e (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (161)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "h8300h"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_h8300h (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (163)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "arm"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_arm7 (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (165)) ;
  }else if (((var_cas_target)._operator_isEqual (GGS_string (true, "avr"))).isBuiltAndTrue ()) {
    ::routine_generate_counter_avr (_inLexique,  var_cas_counters,  var_cas_code COMMA_SOURCE_FILE_AT_LINE (167)) ;
  }else{
    GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string (true, "unknown target: "))._operator_concat (var_cas_target) COMMA_SOURCE_FILE_AT_LINE (170)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_counter_specific\n") ;
  #endif
}

//---------------------------------------------------------------------------*


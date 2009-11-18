//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_proc_generation.cpp'                       *
//                        Generated by version 1.9.4                         *
//                     november 18th, 2009, at 10h1'5"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 599
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_proc_generation.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_proc_generation.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "generate_proc_table"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_generate_proc_table (C_Compiler & inLexique,
                                const GGS_task_map   var_cas_tasks,
                                const GGS_isr_map   var_cas_isrs,
                                GGS_string & var_cas_head,
                                GGS_string & var_cas_imp,
                                GGS_string & var_cas_obj_head COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_generate_proc_table at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_names_head ;
  GGS_string var_cas_names_imp ;
  GGS_string var_cas_proc_ids = GGS_string ("") ;
  GGS_string var_cas_proc_stat_imp = GGS_string ("") ;
  GGS_string var_cas_proc_dyn_imp = GGS_string ("") ;
  GGS_string var_cas_event_imp = GGS_string ("") ;
  GGS_string var_cas_isr_stat_imp = GGS_string ("") ;
  GGS_string var_cas_isr_ena_imp = GGS_string ("") ;
  GGS_uint  var_cas_id = GGS_uint (0U) ;
  GGS_uint  var_cas_ex_t_ct = GGS_uint (0U) ;
  GGS_tasks_by_type  var_cas_stasks = GGS_tasks_by_type ::constructor_emptySortedList () ;
  {
    GGS_task_map::cEnumerator enumerator_1195 (var_cas_tasks, true) ;
    const GGS_task_map::cElement * operand_1195 = NULL ;
    while (((operand_1195 = enumerator_1195.nextObject ()))) {
      macroValidPointer (operand_1195) ;
      const GGS_bool cond_1299 = (operand_1195->mInfo.task.reader_events (inLexique COMMA_SOURCE_FILE_AT_LINE (53)).reader_length (inLexique COMMA_SOURCE_FILE_AT_LINE (53))).operator_strictSup (GGS_uint (0U)) ;
      if (cond_1299.isBuiltAndTrue ()) {
        var_cas_stasks.addAssign_operation (GGS_uint (0U), operand_1195->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (54))) ;
        var_cas_ex_t_ct.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (55)) ;
      }else if (cond_1299.isBuiltAndFalse ()) {
        var_cas_stasks.addAssign_operation (GGS_uint (1U), operand_1195->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (57))) ;
      }
    }
  }
  ::routine_doReplace (inLexique,  var_cas_obj_head,  GGS_string ("$EXTENDED_TASK_COUNT$"),  var_cas_ex_t_ct.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (61)) COMMA_SOURCE_FILE_AT_LINE (61)) ;
  var_cas_names_head = GGS_string ("#if !defined(NO_TASK) || !defined(NO_ISR)\n") ;
  var_cas_names_head.appendCString ("#define API_START_SEC_CONST_UNSPECIFIED\n") ;
  var_cas_names_head.appendCString ("#include \"tpl_memmap.h\"\n") ;
  var_cas_names_head.appendCString ("extern CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT];\n") ;
  var_cas_names_head.appendCString ("#define API_STOP_SEC_CONST_UNSPECIFIED\n") ;
  var_cas_names_head.appendCString ("#include \"tpl_memmap.h\"\n") ;
  var_cas_names_head.appendCString ("#endif\n") ;
  var_cas_names_imp = GGS_string ("#if !defined(NO_TASK) || !defined(NO_ISR)\n") ;
  var_cas_names_imp.appendCString ("#define API_START_SEC_CONST_UNSPECIFIED\n") ;
  var_cas_names_imp.appendCString ("#include \"tpl_memmap.h\"\n") ;
  var_cas_names_imp.appendCString ("CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT] = {\n") ;
  {
    GGS_tasks_by_type::cEnumerator enumerator_2191 (var_cas_stasks, true) ;
    const GGS_tasks_by_type::cElement * operand_2191 = NULL ;
    while (((operand_2191 = enumerator_2191.nextObject ()))) {
      macroValidPointer (operand_2191) ;
      var_cas_names_imp.appendCString ("  \"") ;
      var_cas_names_imp.dotAssign_operation (operand_2191->name) ;
      var_cas_names_imp.appendCString ("\",\n") ;
      var_cas_proc_ids.appendCString ("#define ") ;
      var_cas_proc_ids.dotAssign_operation (operand_2191->name) ;
      var_cas_proc_ids.appendCString ("_id  ") ;
      var_cas_proc_ids.dotAssign_operation (var_cas_id.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (78))) ;
      var_cas_proc_ids.appendCString ("\n") ;
      var_cas_proc_ids.appendCString ("CONST(TaskType, AUTOMATIC) ") ;
      var_cas_proc_ids.dotAssign_operation (operand_2191->name) ;
      var_cas_proc_ids.appendCString (" = ") ;
      var_cas_proc_ids.dotAssign_operation (operand_2191->name) ;
      var_cas_proc_ids.appendCString ("_id;\n") ;
      var_cas_id.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (80)) ;
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_2489 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_2489 = NULL ;
    while (((operand_2489 = enumerator_2489.nextObject ()))) {
      macroValidPointer (operand_2489) ;
      var_cas_names_imp.appendCString ("  \"") ;
      var_cas_names_imp.dotAssign_operation (operand_2489->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (85))) ;
      var_cas_names_imp.appendCString ("\",\n") ;
      var_cas_proc_ids.appendCString ("#define ") ;
      var_cas_proc_ids.dotAssign_operation (operand_2489->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (87))) ;
      var_cas_proc_ids.appendCString ("_id  ") ;
      var_cas_proc_ids.dotAssign_operation (var_cas_id.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (87))) ;
      var_cas_proc_ids.appendCString ("\n") ;
      const GGS_bool cond_2814 = gOption_goil_5F_options_autosar_5F_on.value () ;
      if (cond_2814.isBuiltAndTrue ()) {
        var_cas_proc_ids.appendCString ("CONST(ISRType, AUTOMATIC) ") ;
        var_cas_proc_ids.dotAssign_operation (operand_2489->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (89))) ;
        var_cas_proc_ids.appendCString (" = ") ;
        var_cas_proc_ids.dotAssign_operation (operand_2489->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (89))) ;
        var_cas_proc_ids.appendCString ("_id;\n") ;
      }
      var_cas_id.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (91)) ;
    }
  }
  var_cas_names_imp.appendCString ("};\n") ;
  var_cas_names_imp.appendCString ("#define API_STOP_SEC_CONST_UNSPECIFIED\n") ;
  var_cas_names_imp.appendCString ("#include \"tpl_memmap.h\"\n") ;
  var_cas_names_imp.appendCString ("#endif\n") ;
  var_cas_proc_stat_imp = GGS_string ("CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)\n"
    "tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {\n") ;
  var_cas_proc_dyn_imp = GGS_string ("CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)\n"
    "tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {\n") ;
  var_cas_event_imp = GGS_string ("CONSTP2VAR(tpl_task_events, AUTOMATIC, OS_APPL_DATA)\n"
    "tpl_task_events_table[EXTENDED_TASK_COUNT] = {\n") ;
  {
    GGS_tasks_by_type::cEnumerator enumerator_3441 (var_cas_stasks, true) ;
    const GGS_tasks_by_type::cElement * operand_3441 = NULL ;
    while (((operand_3441 = enumerator_3441.nextObject ()))) {
      macroValidPointer (operand_3441) ;
      var_cas_proc_stat_imp.appendCString ("  &") ;
      var_cas_proc_stat_imp.dotAssign_operation (operand_3441->name) ;
      var_cas_proc_stat_imp.appendCString ("_task_stat_desc,\n") ;
      var_cas_proc_dyn_imp.appendCString ("  &") ;
      var_cas_proc_dyn_imp.dotAssign_operation (operand_3441->name) ;
      var_cas_proc_dyn_imp.appendCString ("_task_desc,\n") ;
    }
  }
  GGS_uint  var_cas_ct = GGS_uint (0U) ;
  {
    GGS_tasks_by_type::cEnumerator enumerator_3635 (var_cas_stasks, true) ;
    const GGS_tasks_by_type::cElement * operand_3635 = enumerator_3635.nextObject () ;
    if ((operand_3635 != NULL)) {
      bool _foreach_loop_3635 ;
      do{
        macroValidPointer (operand_3635) ;
        const GGS_bool cond_3799 = (operand_3635->type).operator_isEqual (GGS_uint (0U)) ;
        if (cond_3799.isBuiltAndTrue ()) {
          var_cas_ct.increment_operation (inLexique COMMA_SOURCE_FILE_AT_LINE (113)) ;
          var_cas_event_imp.appendCString ("  &") ;
          var_cas_event_imp.dotAssign_operation (operand_3635->name) ;
          var_cas_event_imp.appendCString ("_task_evts") ;
          const GGS_bool cond_3786 = (var_cas_ct).operator_strictInf (var_cas_ex_t_ct) ;
          if (cond_3786.isBuiltAndTrue ()) {
            var_cas_event_imp.appendCString (",\n") ;
          }
        }
        operand_3635 = enumerator_3635.nextObject () ;
        _foreach_loop_3635 = ((operand_3635 != NULL)) ;
        if (_foreach_loop_3635) {
        }
      }while (_foreach_loop_3635) ;
      var_cas_event_imp.appendCString ("\n"
        "};") ;
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_3870 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_3870 = NULL ;
    while (((operand_3870 = enumerator_3870.nextObject ()))) {
      macroValidPointer (operand_3870) ;
      var_cas_proc_stat_imp.appendCString ("  &") ;
      var_cas_proc_stat_imp.dotAssign_operation (operand_3870->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (124))) ;
      var_cas_proc_stat_imp.appendCString ("_isr_stat_desc,\n") ;
      var_cas_proc_dyn_imp.appendCString ("  &") ;
      var_cas_proc_dyn_imp.dotAssign_operation (operand_3870->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (125))) ;
      var_cas_proc_dyn_imp.appendCString ("_isr_desc,\n") ;
    }
  }
  var_cas_proc_stat_imp.appendCString ("  &idle_task_static\n"
    "};\n") ;
  var_cas_proc_dyn_imp.appendCString ("  &idle_task\n"
    "};\n") ;
  {
    GGS_isr_map::cEnumerator enumerator_4114 (var_cas_isrs, true) ;
    const GGS_isr_map::cElement * operand_4114 = enumerator_4114.nextObject () ;
    if ((operand_4114 != NULL)) {
      var_cas_isr_ena_imp = GGS_string ("VAR(tpl_isr2_enable_state, OS_VAR)\n"
        "tpl_isr2_enable_table[ISR_COUNT] = {\n") ;
      var_cas_isr_stat_imp = GGS_string ("CONSTP2CONST(tpl_isr_static, AUTOMATIC, OS_APPL_DATA)\n"
        "tpl_isr_stat_table[ISR_COUNT] = {\n") ;
      bool _foreach_loop_4114 ;
      do{
        macroValidPointer (operand_4114) ;
        var_cas_isr_stat_imp.appendCString ("  &") ;
        var_cas_isr_stat_imp.dotAssign_operation (operand_4114->mKey.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (136))) ;
        var_cas_isr_stat_imp.appendCString ("_isr_helper") ;
        var_cas_isr_ena_imp.appendCString ("  ENABLED") ;
        operand_4114 = enumerator_4114.nextObject () ;
        _foreach_loop_4114 = ((operand_4114 != NULL)) ;
        if (_foreach_loop_4114) {
          var_cas_isr_stat_imp.appendCString (",\n") ;
          var_cas_isr_ena_imp.appendCString (",\n") ;
        }
      }while (_foreach_loop_4114) ;
      var_cas_isr_stat_imp.appendCString ("\n"
        "};") ;
      var_cas_isr_ena_imp.appendCString ("\n"
        "};") ;
    }
  }
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$PROCIDS$"),  var_cas_proc_ids COMMA_SOURCE_FILE_AT_LINE (147)) ;
  ::routine_doReplace (inLexique,  var_cas_head,  GGS_string ("$PROC_NAMES$"),  var_cas_names_head COMMA_SOURCE_FILE_AT_LINE (148)) ;
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$PROC_NAMES$"),  var_cas_names_imp COMMA_SOURCE_FILE_AT_LINE (149)) ;
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$PROC_STATIC_TABLE$"),  var_cas_proc_stat_imp COMMA_SOURCE_FILE_AT_LINE (150)) ;
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$PROC_DYNAMIC_TABLE$"),  var_cas_proc_dyn_imp COMMA_SOURCE_FILE_AT_LINE (151)) ;
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$TASK_EVENTS_TABLE$"),  var_cas_event_imp COMMA_SOURCE_FILE_AT_LINE (152)) ;
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$ISR_HELPER_TABLE$"),  var_cas_isr_stat_imp COMMA_SOURCE_FILE_AT_LINE (153)) ;
  ::routine_doReplace (inLexique,  var_cas_imp,  GGS_string ("$ISR_ENABLE_TABLE$"),  var_cas_isr_ena_imp COMMA_SOURCE_FILE_AT_LINE (154)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_generate_proc_table\n") ;
  #endif
}

//---------------------------------------------------------------------------*


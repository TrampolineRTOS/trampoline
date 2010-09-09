//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_check.cpp'                            *
//                        Generated by version 2.0.1                         *
//                    september 3rd, 2010, at 11h11'37"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 837
  #error "This file has been compiled with a version of GALGAS that uses libpm version 837, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "goil_check.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_check.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "check_uint32_range"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_check_uint32_range (C_Compiler & inLexique,
                                GGS_uint32_set   var_cas_set,
                                GGS_location   var_cas_loc,
                                GGS_uint   var_cas_val
                        COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_check_uint32_range at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  { const GGS_uint32_set _var_1285 = var_cas_set ; // CAST instruction
    if (_var_1285.getPtr () != NULL) {
      macroValidPointer (_var_1285.getPtr ()) ;
      if (typeid (cPtr_uint32_range) == typeid (* (_var_1285.getPtr ()))) {
        const GGS_uint32_range var_cas_r (_var_1285.getPtr ()) ;
        const GGS_bool cond_873 = ((var_cas_val).operator_strictInf (var_cas_r.reader_min (inLexique COMMA_SOURCE_FILE_AT_LINE (39)))).operator_or ((var_cas_val).operator_strictSup (var_cas_r.reader_max (inLexique COMMA_SOURCE_FILE_AT_LINE (39)))) ;
        if (cond_873.isBuiltAndTrue ()) {
          var_cas_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("UINT32 not within specified range.") COMMA_SOURCE_FILE_AT_LINE (41)) ;
          var_cas_r.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (41)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Range was defined here") COMMA_SOURCE_FILE_AT_LINE (42)) ;
        }
      }else if (typeid (cPtr_uint32_list) == typeid (* (_var_1285.getPtr ()))) {
        const GGS_uint32_list var_cas_l (_var_1285.getPtr ()) ;
        GGS_bool var_cas_not_matched = GGS_bool (true) ;
        {
          GGS_list_uint32::cEnumerator enumerator_962 (var_cas_l.reader_li (inLexique COMMA_SOURCE_FILE_AT_LINE (45)), true) ;
          const GGS_list_uint32::cElement * operand_962 = NULL ;
          while (((operand_962 = enumerator_962.nextObject ()))) {
            macroValidPointer (operand_962) ;
            const GGS_bool cond_1078 = (var_cas_val).operator_isEqual (operand_962->val) ;
            if (cond_1078.isBuiltAndTrue ()) {
              var_cas_not_matched = GGS_bool (false) ;
            }
          }
        }
        const GGS_bool cond_1267 = var_cas_not_matched ;
        if (cond_1267.isBuiltAndTrue ()) {
          var_cas_loc.reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("UINT32 is not included in specified set.") COMMA_SOURCE_FILE_AT_LINE (52)) ;
          var_cas_l.reader_loc (inLexique COMMA_SOURCE_FILE_AT_LINE (52)).reader_location (inLexique COMMA_HERE).signalGGSSemanticError (inLexique, GGS_string ("Set was defined here") COMMA_SOURCE_FILE_AT_LINE (53)) ;
        }
      }else{
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_check_uint32_range\n") ;
  #endif
}

//---------------------------------------------------------------------------*


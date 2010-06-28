//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'isrs_verif.cpp'                            *
//                 Generated by version GALGAS_BETA_VERSION                  *
//                      june 15th, 2010, at 20h51'37"                        *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER
  #error "This file has been compiled with a version of GALGAS that uses libpm version VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include "isrs_verif.h"
#include "galgas-utilities/C_Compiler.h"
#include "galgas/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "isrs_verif.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'isrs_well_formed'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_isrs_5F_well_5F_formed (GALGASap_isr_5F_map constinArgument_isrs,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  //-------- @foreachInstructionForGeneration
  GALGAS_isr_5F_map::cEnumerator enumerator_817 (constinArgument_isrs, true) ;
  //--- simple foreach instruction
  while (enumerator_817.hasCurrentObject ()) {
    enumerator_817.updateAttributeProxies () ;
    //-------- @structuredCastInstructionForGeneration
    //--- @readerCallExpressionForGeneration
    GALGASap_basic_5F_type temp_0 (enumerator_817.attribute_isr.readerCall_category (SOURCE_FILE_AT_LINE (48))) ;
    if (temp_0.isValid ()) {
      if (temp_0.ptr (HERE)->typeDescriptor () == & kTypeDescriptor_GALGAS_void) {
        //-------- @errorInstructionForGeneration
        //--- @concatExpressionForGeneration
        //--- @literalStringExpressionForGeneration
        GALGASap_string temp_1 ("CATEGORY attribute undefined for ISR " COMMA_SOURCE_FILE_AT_LINE (50)) ;
        //--- @readerCallExpressionForGeneration
        GALGASap_string temp_2 (enumerator_817.attribute_lkey.readerCall_string (SOURCE_FILE_AT_LINE (50))) ;
        GALGASap_string temp_3 (temp_1.operator_concat (temp_2 COMMA_SOURCE_FILE_AT_LINE (50))) ;
        GALGASap_location location_4 (enumerator_817.attribute_lkey.readerCall_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_4, temp_3 COMMA_SOURCE_FILE_AT_LINE (50)) ;
      }
    }
    //-------- @structuredCastInstructionForGeneration
    //--- @readerCallExpressionForGeneration
    GALGASap_basic_5F_type temp_5 (enumerator_817.attribute_isr.readerCall_priority (SOURCE_FILE_AT_LINE (54))) ;
    if (temp_5.isValid ()) {
      if (temp_5.ptr (HERE)->typeDescriptor () == & kTypeDescriptor_GALGAS_void) {
        //-------- @errorInstructionForGeneration
        //--- @concatExpressionForGeneration
        //--- @literalStringExpressionForGeneration
        GALGASap_string temp_6 ("PRIORITY attribute undefined for ISR " COMMA_SOURCE_FILE_AT_LINE (56)) ;
        //--- @readerCallExpressionForGeneration
        GALGASap_string temp_7 (enumerator_817.attribute_lkey.readerCall_string (SOURCE_FILE_AT_LINE (56))) ;
        GALGASap_string temp_8 (temp_6.operator_concat (temp_7 COMMA_SOURCE_FILE_AT_LINE (56))) ;
        GALGASap_location location_9 (enumerator_817.attribute_lkey.readerCall_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_9, temp_8 COMMA_SOURCE_FILE_AT_LINE (56)) ;
      }
    }
    enumerator_817.next() ;
  }
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


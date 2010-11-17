//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'template_functions.cpp'                        *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'51"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER
  #error "This file has been compiled with a version of GALGAS that uses libpm version VERSION_OF_LIBPM_USED_BY_GALGAS_COMPILER, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include "template_functions.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_CLI_Options.h"

//---------------------------------------------------------------------------*

#include "goil_options.h"
#include "template_grammar.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "template_functions.gSemantics", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'trueFalse'                            *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_trueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_string ; // Returned variable
  //-------- @ifInstructionForGeneration
  if (constinArgument_inBool.isValidAndTrue ()) {
    //-------- @assignmentInstructionForGeneration
    result_string = GALGAS_string ("true") ;
  }else{
    //-------- @assignmentInstructionForGeneration
    result_string = GALGAS_string ("false") ;
  }
//---
  return result_string ;
}


//---------------------------------------------------------------------------*
//  Function introspection                                                   *
//---------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_trueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_trueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & inErrorLocation
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  return function_trueFalse (operand0, inCompiler COMMA_THERE).reader_object (THERE) ;
}

//---------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_trueFalse ("trueFalse",
                                                           functionWithGenericHeader_trueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_trueFalse) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             Function 'yesNo'                              *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_yesNo (const GALGAS_bool & constinArgument_inBool,
                              C_Compiler * /* inCompiler */
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_string ; // Returned variable
  //-------- @ifInstructionForGeneration
  if (constinArgument_inBool.isValidAndTrue ()) {
    //-------- @assignmentInstructionForGeneration
    result_string = GALGAS_string ("YES") ;
  }else{
    //-------- @assignmentInstructionForGeneration
    result_string = GALGAS_string ("NO") ;
  }
//---
  return result_string ;
}


//---------------------------------------------------------------------------*
//  Function introspection                                                   *
//---------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_yesNo [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_yesNo (C_Compiler * inCompiler,
                                                      const cObjectArray & inEffectiveParameterArray,
                                                      const GALGAS_location & inErrorLocation
                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  return function_yesNo (operand0, inCompiler COMMA_THERE).reader_object (THERE) ;
}

//---------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_yesNo ("yesNo",
                                                       functionWithGenericHeader_yesNo,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       1,
                                                       functionArgs_yesNo) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'TRUEFALSE'                            *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_TRUEFALSE (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_string ; // Returned variable
  //-------- @ifInstructionForGeneration
  if (constinArgument_inBool.isValidAndTrue ()) {
    //-------- @assignmentInstructionForGeneration
    result_string = GALGAS_string ("TRUE") ;
  }else{
    //-------- @assignmentInstructionForGeneration
    result_string = GALGAS_string ("FALSE") ;
  }
//---
  return result_string ;
}


//---------------------------------------------------------------------------*
//  Function introspection                                                   *
//---------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_TRUEFALSE [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_TRUEFALSE (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & inErrorLocation
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE), inCompiler, inErrorLocation COMMA_THERE) ;
  return function_TRUEFALSE (operand0, inCompiler COMMA_THERE).reader_object (THERE) ;
}

//---------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_TRUEFALSE ("TRUEFALSE",
                                                           functionWithGenericHeader_TRUEFALSE,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TRUEFALSE) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2



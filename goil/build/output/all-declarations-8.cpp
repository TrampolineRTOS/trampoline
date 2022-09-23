#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-8.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'invokeGTL'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_invokeGTL (GALGAS_gtlString inArgument_rootTemplateFileName,
                                  GALGAS_gtlContext inArgument_context,
                                  GALGAS_gtlData inArgument_vars,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  GALGAS_library var_lib_1098 = function_emptyLib (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 36)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("Starting debugger, type help for command list\n")  COMMA_SOURCE_FILE ("gtl_interface.galgas", 39)) ;
      extensionMethod_loadCommandFile (GALGAS_string (".gtlinit"), inArgument_context, inArgument_vars, var_lib_1098, inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 40)) ;
    }
  }
  GALGAS_gtlTemplateInstruction var_rootTemplateInstruction_1371 = GALGAS_gtlTemplateInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_interface.galgas", 45)), GALGAS_string::makeEmptyString (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 47)), GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_interface.galgas", 49)), inArgument_rootTemplateFileName  COMMA_SOURCE_FILE ("gtl_interface.galgas", 48)), GALGAS_bool (false), GALGAS_bool (true), GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_interface.galgas", 54)), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_interface.galgas", 55))  COMMA_SOURCE_FILE ("gtl_interface.galgas", 44)) ;
  callExtensionMethod_execute ((cPtr_gtlTemplateInstruction *) var_rootTemplateInstruction_1371.ptr (), inArgument_context, inArgument_vars, var_lib_1098, result_result, inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 59)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_invokeGTL [4] = {
  & kTypeDescriptor_GALGAS_gtlString,
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_invokeGTL (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_gtlString operand0 = GALGAS_gtlString::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_gtlContext operand1 = GALGAS_gtlContext::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_gtlData operand2 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_invokeGTL (operand0,
                             operand1,
                             operand2,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_invokeGTL ("invokeGTL",
                                                           functionWithGenericHeader_invokeGTL,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           3,
                                                           functionArgs_invokeGTL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyVarContainer'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData function_emptyVarContainer (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_nowhere (SOURCE_FILE ("gtl_interface.galgas", 73)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 73)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_interface.galgas", 73))  COMMA_SOURCE_FILE ("gtl_interface.galgas", 73)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyVarContainer [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyVarContainer (C_Compiler * inCompiler,
                                                                  const cObjectArray & /* inEffectiveParameterArray */,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  return function_emptyVarContainer (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyVarContainer ("emptyVarContainer",
                                                                   functionWithGenericHeader_emptyVarContainer,
                                                                   & kTypeDescriptor_GALGAS_gtlData,
                                                                   0,
                                                                   functionArgs_emptyVarContainer) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'lstringToGtlString'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlString function_lstringToGtlString (GALGAS_lstring inArgument_input,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlString result_output ; // Returned variable
  result_output = GALGAS_gtlString::constructor_new (inArgument_input.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 83)), inArgument_input.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_interface.galgas", 83)) ;
//---
  return result_output ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_lstringToGtlString [2] = {
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_lstringToGtlString (C_Compiler * inCompiler,
                                                                   const cObjectArray & inEffectiveParameterArray,
                                                                   const GALGAS_location & /* inErrorLocation */
                                                                   COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_lstringToGtlString (operand0,
                                      inCompiler
                                      COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_lstringToGtlString ("lstringToGtlString",
                                                                    functionWithGenericHeader_lstringToGtlString,
                                                                    & kTypeDescriptor_GALGAS_gtlString,
                                                                    1,
                                                                    functionArgs_lstringToGtlString) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringToGtlString'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlString function_stringToGtlString (GALGAS_string inArgument_input,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlString result_output ; // Returned variable
  result_output = GALGAS_gtlString::constructor_new (GALGAS_location::constructor_nowhere (SOURCE_FILE ("gtl_interface.galgas", 93)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 93)), inArgument_input  COMMA_SOURCE_FILE ("gtl_interface.galgas", 93)) ;
//---
  return result_output ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringToGtlString [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringToGtlString (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringToGtlString (operand0,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringToGtlString ("stringToGtlString",
                                                                   functionWithGenericHeader_stringToGtlString,
                                                                   & kTypeDescriptor_GALGAS_gtlString,
                                                                   1,
                                                                   functionArgs_stringToGtlString) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContext function_emptyContext (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlContext result_context ; // Returned variable
  result_context = GALGAS_gtlContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 46)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string ("gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 51)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 52)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 54))  COMMA_SOURCE_FILE ("gtl_types.galgas", 45)) ;
//---
  return result_context ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyContext [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyContext (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyContext ("emptyContext",
                                                              functionWithGenericHeader_emptyContext,
                                                              & kTypeDescriptor_GALGAS_gtlContext,
                                                              0,
                                                              functionArgs_emptyContext) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'pathWithExtension'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_pathWithExtension (GALGAS_gtlContext inArgument_context,
                                          GALGAS_string inArgument_path,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_extendedPath ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_pathExtension (SOURCE_FILE ("gtl_types.galgas", 96)).objectCompare (inArgument_context.readProperty_templateExtension ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_extendedPath = inArgument_path.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 97)).add_operation (inArgument_context.readProperty_templateExtension (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 97)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_extendedPath = inArgument_path ;
  }
//---
  return result_extendedPath ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_pathWithExtension [3] = {
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_pathWithExtension (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_gtlContext operand0 = GALGAS_gtlContext::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_pathWithExtension (operand0,
                                     operand1,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_pathWithExtension ("pathWithExtension",
                                                                   functionWithGenericHeader_pathWithExtension,
                                                                   & kTypeDescriptor_GALGAS_string,
                                                                   2,
                                                                   functionArgs_pathWithExtension) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyLib'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_library function_emptyLib (C_Compiler *
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_library result_result ; // Returned variable
  result_result = GALGAS_library::constructor_new (GALGAS_gtlFuncMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_gtlGetterMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_gtlSetterMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_gtlTemplateMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("gtl_types.galgas", 323))  COMMA_SOURCE_FILE ("gtl_types.galgas", 323)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyLib [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyLib (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_emptyLib (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyLib ("emptyLib",
                                                          functionWithGenericHeader_emptyLib,
                                                          & kTypeDescriptor_GALGAS_library,
                                                          0,
                                                          functionArgs_emptyLib) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct overrideMap'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStruct cPtr_gtlStruct::getter_overrideMap (C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlStruct result_mapOverriden ; // Returned variable
  result_mapOverriden = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 35)), GALGAS_gtlVarMap::constructor_mapWithMapToOverride (this->mProperty_value  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 36))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 33)) ;
//---
  return result_mapOverriden ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct overriddenMap'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStruct cPtr_gtlStruct::getter_overriddenMap (C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlStruct result_overriddenMap ; // Returned variable
  result_overriddenMap = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44)), this->mProperty_value.getter_overriddenMap (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44)) ;
//---
  return result_overriddenMap ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'wantGtlStruct'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData function_wantGtlStruct (GALGAS_gtlData inArgument_inData,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_1500_inDataStruct ((cPtr_gtlStruct *) inArgument_inData.ptr ()) ;
      result_outData = cast_1500_inDataStruct ;
    }else{
      result_outData = GALGAS_gtlStruct::constructor_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 56))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)) ;
    }
  }
//---
  return result_outData ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_wantGtlStruct [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_wantGtlStruct (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_gtlData operand0 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_wantGtlStruct (operand0,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_wantGtlStruct ("wantGtlStruct",
                                                               functionWithGenericHeader_wantGtlStruct,
                                                               & kTypeDescriptor_GALGAS_gtlData,
                                                               1,
                                                               functionArgs_wantGtlStruct) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'wantGtlMap'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData function_wantGtlMap (GALGAS_gtlData inArgument_inData,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_1793_inDataMap ((cPtr_gtlMap *) inArgument_inData.ptr ()) ;
      result_outData = cast_1793_inDataMap ;
    }else{
      result_outData = GALGAS_gtlMap::constructor_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 69))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)) ;
    }
  }
//---
  return result_outData ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_wantGtlMap [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_wantGtlMap (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_gtlData operand0 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_wantGtlMap (operand0,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_wantGtlMap ("wantGtlMap",
                                                            functionWithGenericHeader_wantGtlMap,
                                                            & kTypeDescriptor_GALGAS_gtlData,
                                                            1,
                                                            functionArgs_wantGtlMap) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'wantGtlList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData function_wantGtlList (GALGAS_gtlData inArgument_inData,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_2083_inDataList ((cPtr_gtlList *) inArgument_inData.ptr ()) ;
      result_outData = cast_2083_inDataList ;
    }else{
      result_outData = GALGAS_gtlList::constructor_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 82))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)) ;
    }
  }
//---
  return result_outData ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_wantGtlList [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_wantGtlList (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_gtlData operand0 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_wantGtlList (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_wantGtlList ("wantGtlList",
                                                             functionWithGenericHeader_wantGtlList,
                                                             & kTypeDescriptor_GALGAS_gtlData,
                                                             1,
                                                             functionArgs_wantGtlList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlVarItemField::getter_location (C_Compiler */* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_loc ; // Returned variable
  result_loc = this->mProperty_field.readProperty_location () ;
//---
  return result_loc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField stringPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemField::getter_stringPath (const GALGAS_gtlContext /* constinArgument_exeContext */,
                                                       const GALGAS_gtlData /* constinArgument_vars */,
                                                       const GALGAS_library /* constinArgument_lib */,
                                                       C_Compiler */* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_field.readProperty_string () ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemField setInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemField::method_setInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                GALGAS_gtlData & ioArgument_context,
                                                const GALGAS_gtlData constinArgument_vars,
                                                const GALGAS_library constinArgument_lib,
                                                const GALGAS_gtlVarPath constinArgument_path,
                                                const GALGAS_gtlData constinArgument_newData,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 184)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 185)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlData * ptr_5576 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5576, this->mProperty_field, constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 186)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_gtlData var_data_5662 ;
    GALGAS_bool joker_5664 ; // Joker input parameter
    callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_5662, joker_5664, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 188)) ;
    callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 189)).ptr (), constinArgument_exeContext, var_data_5662, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 194)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 189)) ;
    {
    ioArgument_context.insulate (HERE) ;
    cPtr_gtlData * ptr_5830 = (cPtr_gtlData *) ioArgument_context.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5830, this->mProperty_field, var_data_5662, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 197)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField getInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarItemField::getter_getInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                          const GALGAS_gtlData constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          const GALGAS_gtlVarPath constinArgument_path,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_data_6321 ;
  GALGAS_bool var_found_6338 ;
  callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_data_6321, var_found_6338, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 212)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 213)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_found_6338.boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = var_data_6321 ;
        }
      }
      if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_data_6321.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 217)), GALGAS_string ("Variable or field does not exist"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 217)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 220)).ptr (), constinArgument_exeContext, var_data_6321, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 225)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 220)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField existsInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVarItemField::getter_existsInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                          const GALGAS_gtlData constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          const GALGAS_gtlVarPath constinArgument_path,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 241)).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 242)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_bool (true) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_7205 ;
        GALGAS_bool joker_7207 ; // Joker input parameter
        callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_subContext_7205, joker_7207, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 245)) ;
        result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 246)).ptr (), constinArgument_exeContext, var_subContext_7205, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 251)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 246)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bool (false) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemField deleteInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemField::method_deleteInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                   GALGAS_gtlData & ioArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   const GALGAS_gtlVarPath constinArgument_path,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 269)).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 270)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_7894 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_deleteStructField ((cPtr_gtlData *) ptr_7894, this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 271)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_data_7978 ;
        GALGAS_bool joker_7980 ; // Joker input parameter
        callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_7978, joker_7980, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 273)) ;
        callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 274)).ptr (), constinArgument_exeContext, var_data_7978, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 279)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 274)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlData * ptr_8150 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_8150, this->mProperty_field, var_data_7978, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 281)) ;
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection stringPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemCollection::getter_stringPath (const GALGAS_gtlContext constinArgument_exeContext,
                                                            const GALGAS_gtlData constinArgument_vars,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_field.readProperty_string ().add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 297)) ;
  GALGAS_gtlData var_keyValue_8686 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 298)) ;
  if (var_keyValue_8686.isValid ()) {
    if (var_keyValue_8686.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_8769_keyString ((cPtr_gtlString *) var_keyValue_8686.ptr ()) ;
      result_result.plusAssign_operation(GALGAS_string ("\"").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) cast_8769_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)) ;
    }else if (var_keyValue_8686.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_8833_keyInt ((cPtr_gtlInt *) var_keyValue_8686.ptr ()) ;
      result_result.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlInt *) cast_8833_keyInt.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 303)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 303)) ;
    }
  }
  result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 305)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemCollection setInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemCollection::method_setInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                     GALGAS_gtlData & ioArgument_context,
                                                     const GALGAS_gtlData constinArgument_vars,
                                                     const GALGAS_library constinArgument_lib,
                                                     const GALGAS_gtlVarPath constinArgument_path,
                                                     const GALGAS_gtlData constinArgument_newData,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_9370_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).ptr ()) ;
      ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 321)) ;
      GALGAS_gtlData var_data_9456 ;
      GALGAS_bool joker_9458 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_9456, joker_9458, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 322)) ;
      var_data_9456 = function_wantGtlMap (var_data_9456, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 323)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 324)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          var_data_9456.insulate (HERE) ;
          cPtr_gtlData * ptr_9534 = (cPtr_gtlData *) var_data_9456.ptr () ;
          callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_9534, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_9370_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 325)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 325)) ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_9627 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) var_data_9456.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_9370_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 327)), var_subContext_9627, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 327)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 328)).ptr (), constinArgument_exeContext, var_subContext_9627, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 333)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 328)) ;
        {
        var_data_9456.insulate (HERE) ;
        cPtr_gtlData * ptr_9813 = (cPtr_gtlData *) var_data_9456.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_9813, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_9370_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 336)), var_subContext_9627, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 336)) ;
        }
      }
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlData * ptr_9871 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9871, this->mProperty_field, var_data_9456, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 338)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_9925_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).ptr ()) ;
      ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 340)) ;
      GALGAS_gtlData var_data_10011 ;
      GALGAS_bool joker_10013 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_10011, joker_10013, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 341)) ;
      var_data_10011 = function_wantGtlList (var_data_10011, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 342)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 343)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          var_data_10011.insulate (HERE) ;
          cPtr_gtlData * ptr_10090 = (cPtr_gtlData *) var_data_10011.ptr () ;
          callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_10090, constinArgument_newData, cast_9925_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 344)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_10177 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_data_10011.ptr (), var_subContext_10177, cast_9925_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 346)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 347)).ptr (), constinArgument_exeContext, var_subContext_10177, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 347)) ;
        {
        var_data_10011.insulate (HERE) ;
        cPtr_gtlData * ptr_10371 = (cPtr_gtlData *) var_data_10011.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_10371, var_subContext_10177, cast_9925_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 355)) ;
        }
      }
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlData * ptr_10430 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_10430, this->mProperty_field, var_data_10011, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 357)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 359)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 359)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection getInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarItemCollection::getter_getInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                               const GALGAS_gtlData constinArgument_context,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               const GALGAS_gtlVarPath constinArgument_path,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_collection_10981 ;
  GALGAS_bool joker_10983 ; // Joker input parameter
  callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_collection_10981, joker_10983, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 374)) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_11057_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 377)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          callExtensionMethod_mapItem ((cPtr_gtlData *) var_collection_10981.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11057_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 378)), result_result, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 378)) ;
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_11206 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) var_collection_10981.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11057_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 380)), var_subContext_11206, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 380)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 381)).ptr (), constinArgument_exeContext, var_subContext_11206, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 386)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 381)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_11402_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).ptr ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 390)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_collection_10981.ptr (), result_result, cast_11402_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 391)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_11545 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_collection_10981.ptr (), var_subContext_11545, cast_11402_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 393)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 394)).ptr (), constinArgument_exeContext, var_subContext_11545, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 399)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 394)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 403)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 403)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection existsInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVarItemCollection::getter_existsInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                               const GALGAS_gtlData constinArgument_context,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               const GALGAS_gtlVarPath constinArgument_path,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 419)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlData var_collection_12317 ;
      GALGAS_bool joker_12319 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_collection_12317, joker_12319, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 420)) ;
      if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).isValid ()) {
        if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
          GALGAS_gtlString cast_12397_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).ptr ()) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 423)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              result_result = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_collection_12317.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_12397_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 424)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 424)) ;
            }
          }
          if (kBoolFalse == test_1) {
            enumGalgasBool test_2 = kBoolTrue ;
            if (kBoolTrue == test_2) {
              test_2 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_collection_12317.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_12397_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 426)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 426)).boolEnum () ;
              if (kBoolTrue == test_2) {
                GALGAS_gtlData var_subContext_12611 ;
                callExtensionMethod_mapItem ((cPtr_gtlData *) var_collection_12317.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_12397_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 427)), var_subContext_12611, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 427)) ;
                result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 428)).ptr (), constinArgument_exeContext, var_subContext_12611, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 433)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 428)) ;
              }
            }
            if (kBoolFalse == test_2) {
              result_result = GALGAS_bool (false) ;
            }
          }
        }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
          GALGAS_gtlInt cast_12892_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).ptr ()) ;
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 440)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_3) {
              result_result = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_collection_12317.ptr (), cast_12892_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 441)) ;
            }
          }
          if (kBoolFalse == test_3) {
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              test_4 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_collection_12317.ptr (), cast_12892_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 443)).boolEnum () ;
              if (kBoolTrue == test_4) {
                GALGAS_gtlData var_subContext_13101 ;
                callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_collection_12317.ptr (), var_subContext_13101, cast_12892_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 444)) ;
                result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).ptr (), constinArgument_exeContext, var_subContext_13101, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 450)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)) ;
              }
            }
            if (kBoolFalse == test_4) {
              result_result = GALGAS_bool (false) ;
            }
          }
        }else{
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 457)), GALGAS_string ("string ot int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 457)) ;
          result_result.drop () ; // Release error dropped variable
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bool (false) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemCollection deleteInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemCollection::method_deleteInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                        GALGAS_gtlData & ioArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        const GALGAS_gtlVarPath constinArgument_path,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_13933_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 476)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_gtlData var_data_14027 ;
          GALGAS_bool joker_14029 ; // Joker input parameter
          callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_14027, joker_14029, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 477)) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 478)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              enumGalgasBool test_2 = kBoolTrue ;
              if (kBoolTrue == test_2) {
                test_2 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_data_14027.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13933_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 479)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 479)).boolEnum () ;
                if (kBoolTrue == test_2) {
                  {
                  var_data_14027.insulate (HERE) ;
                  cPtr_gtlData * ptr_14127 = (cPtr_gtlData *) var_data_14027.ptr () ;
                  callExtensionSetter_deleteMapItem ((cPtr_gtlData *) ptr_14127, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13933_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 480)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 480)) ;
                  }
                }
              }
            }
          }
          if (kBoolFalse == test_1) {
            GALGAS_gtlData var_subContext_14230 ;
            callExtensionMethod_mapItem ((cPtr_gtlData *) var_data_14027.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13933_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 483)), var_subContext_14230, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 483)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 484)).ptr (), constinArgument_exeContext, var_subContext_14230, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 489)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 484)) ;
            {
            var_data_14027.insulate (HERE) ;
            cPtr_gtlData * ptr_14418 = (cPtr_gtlData *) var_data_14027.ptr () ;
            callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_14418, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13933_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 491)), var_subContext_14230, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 491)) ;
            }
          }
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_14480 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_14480, this->mProperty_field, var_data_14027, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 493)) ;
          }
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_14542_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).ptr ()) ;
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 496)).boolEnum () ;
        if (kBoolTrue == test_3) {
          GALGAS_gtlData var_data_14636 ;
          GALGAS_bool joker_14638 ; // Joker input parameter
          callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_14636, joker_14638, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 497)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 498)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              enumGalgasBool test_5 = kBoolTrue ;
              if (kBoolTrue == test_5) {
                test_5 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_data_14636.ptr (), cast_14542_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 499)).boolEnum () ;
                if (kBoolTrue == test_5) {
                  {
                  var_data_14636.insulate (HERE) ;
                  cPtr_gtlData * ptr_14737 = (cPtr_gtlData *) var_data_14636.ptr () ;
                  callExtensionSetter_deleteItemAtIndex ((cPtr_gtlData *) ptr_14737, cast_14542_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 500)) ;
                  }
                }
              }
            }
          }
          if (kBoolFalse == test_4) {
            GALGAS_gtlData var_subContext_14834 ;
            callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_data_14636.ptr (), var_subContext_14834, cast_14542_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 503)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 504)).ptr (), constinArgument_exeContext, var_subContext_14834, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 509)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 504)) ;
            {
            var_data_14636.insulate (HERE) ;
            cPtr_gtlData * ptr_15030 = (cPtr_gtlData *) var_data_14636.ptr () ;
            callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_15030, var_subContext_14834, cast_14542_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 511)) ;
            }
          }
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_15093 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_15093, this->mProperty_field, var_data_14636, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 513)) ;
          }
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 516)), GALGAS_string ("string ot int expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 516)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlVarItemSubCollection::getter_location (C_Compiler */* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_loc ; // Returned variable
  result_loc = this->mProperty_subCollectionlocation ;
//---
  return result_loc ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection stringPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemSubCollection::getter_stringPath (const GALGAS_gtlContext constinArgument_exeContext,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("[") ;
  GALGAS_gtlData var_keyValue_15860 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 544)) ;
  if (var_keyValue_15860.isValid ()) {
    if (var_keyValue_15860.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_15943_keyString ((cPtr_gtlString *) var_keyValue_15860.ptr ()) ;
      result_result.plusAssign_operation(GALGAS_string ("\"").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) cast_15943_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)) ;
    }else if (var_keyValue_15860.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_16007_keyInt ((cPtr_gtlInt *) var_keyValue_15860.ptr ()) ;
      result_result.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlInt *) cast_16007_keyInt.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 549)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 549)) ;
    }
  }
  result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 551)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemSubCollection setInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemSubCollection::method_setInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                        GALGAS_gtlData & ioArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        const GALGAS_gtlVarPath constinArgument_path,
                                                        const GALGAS_gtlData constinArgument_newData,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_16550_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).ptr ()) ;
      ioArgument_context = function_wantGtlMap (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 567)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 568)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_16634 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_16634, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16550_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 569)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 569)) ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_16730 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16550_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 571)), var_subContext_16730, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 571)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 572)).ptr (), constinArgument_exeContext, var_subContext_16730, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 577)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 572)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlData * ptr_16919 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_16919, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16550_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 580)), var_subContext_16730, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 580)) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_16987_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).ptr ()) ;
      ioArgument_context = function_wantGtlList (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 583)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 584)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_17072 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_17072, constinArgument_newData, cast_16987_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 585)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_17162 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) ioArgument_context.ptr (), var_subContext_17162, cast_16987_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 587)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 588)).ptr (), constinArgument_exeContext, var_subContext_17162, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 593)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 588)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlData * ptr_17359 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_17359, var_subContext_17162, cast_16987_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 596)) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 599)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 599)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection getInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarItemSubCollection::getter_getInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                                  const GALGAS_gtlData constinArgument_context,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  const GALGAS_library constinArgument_lib,
                                                                  const GALGAS_gtlVarPath constinArgument_path,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_17945_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 616)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          callExtensionMethod_mapItem ((cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_17945_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 617)), result_result, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 617)) ;
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_18088 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_17945_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 619)), var_subContext_18088, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 619)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 620)).ptr (), constinArgument_exeContext, var_subContext_18088, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 625)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 620)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_18284_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).ptr ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 629)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          callExtensionMethod_itemAtIndex ((cPtr_gtlData *) constinArgument_context.ptr (), result_result, cast_18284_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 630)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_18421 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) constinArgument_context.ptr (), var_subContext_18421, cast_18284_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 632)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 633)).ptr (), constinArgument_exeContext, var_subContext_18421, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 638)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 633)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 642)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 642)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection existsInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVarItemSubCollection::getter_existsInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                                  const GALGAS_gtlData constinArgument_context,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  const GALGAS_library constinArgument_lib,
                                                                  const GALGAS_gtlVarPath constinArgument_path,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_19171_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 659)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          result_result = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19171_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 660)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 660)) ;
        }
      }
      if (kBoolFalse == test_0) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19171_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 662)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 662)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_gtlData var_subContext_19366 ;
            callExtensionMethod_mapItem ((cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19171_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 663)), var_subContext_19366, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 663)) ;
            result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 664)).ptr (), constinArgument_exeContext, var_subContext_19366, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 669)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 664)) ;
          }
        }
        if (kBoolFalse == test_1) {
          result_result = GALGAS_bool (false) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_19623_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).ptr ()) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 676)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_result = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), cast_19623_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 677)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), cast_19623_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 679)).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_gtlData var_subContext_19813 ;
            callExtensionMethod_itemAtIndex ((cPtr_gtlData *) constinArgument_context.ptr (), var_subContext_19813, cast_19623_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 680)) ;
            result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 681)).ptr (), constinArgument_exeContext, var_subContext_19813, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 686)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 681)) ;
          }
        }
        if (kBoolFalse == test_3) {
          result_result = GALGAS_bool (false) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 693)), GALGAS_string ("string ot int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 693)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemSubCollection deleteInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemSubCollection::method_deleteInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                           GALGAS_gtlData & ioArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           const GALGAS_gtlVarPath constinArgument_path,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_20591_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20591_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 709)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 709)).boolEnum () ;
        if (kBoolTrue == test_0) {
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 710)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              {
              ioArgument_context.insulate (HERE) ;
              cPtr_gtlData * ptr_20688 = (cPtr_gtlData *) ioArgument_context.ptr () ;
              callExtensionSetter_deleteMapItem ((cPtr_gtlData *) ptr_20688, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20591_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 711)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 711)) ;
              }
            }
          }
          if (kBoolFalse == test_1) {
            GALGAS_gtlData var_subContext_20782 ;
            callExtensionMethod_mapItem ((cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20591_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 713)), var_subContext_20782, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 713)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 714)).ptr (), constinArgument_exeContext, var_subContext_20782, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 719)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 714)) ;
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlData * ptr_20973 = (cPtr_gtlData *) ioArgument_context.ptr () ;
            callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_20973, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20591_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 721)), var_subContext_20782, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 721)) ;
            }
          }
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_21051_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).ptr ()) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) ioArgument_context.ptr (), cast_21051_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 725)).boolEnum () ;
        if (kBoolTrue == test_2) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 726)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_3) {
              {
              ioArgument_context.insulate (HERE) ;
              cPtr_gtlData * ptr_21149 = (cPtr_gtlData *) ioArgument_context.ptr () ;
              callExtensionSetter_deleteItemAtIndex ((cPtr_gtlData *) ptr_21149, cast_21051_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 727)) ;
              }
            }
          }
          if (kBoolFalse == test_3) {
            GALGAS_gtlData var_subContext_21237 ;
            callExtensionMethod_itemAtIndex ((cPtr_gtlData *) ioArgument_context.ptr (), var_subContext_21237, cast_21051_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 729)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 730)).ptr (), constinArgument_exeContext, var_subContext_21237, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 735)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 730)) ;
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlData * ptr_21436 = (cPtr_gtlData *) ioArgument_context.ptr () ;
            callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_21436, var_subContext_21237, cast_21051_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 737)) ;
            }
          }
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 741)), GALGAS_string ("string ot int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 741)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTerminal eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlTerminal::getter_eval (const GALGAS_gtlContext /* constinArgument_context */,
                                              const GALGAS_gtlData /* constinArgument_vars */,
                                              const GALGAS_library /* constinArgument_lib */,
                                              C_Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarRef eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarRef::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                            const GALGAS_gtlData constinArgument_vars,
                                            const GALGAS_library constinArgument_lib,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = extensionGetter_get (this->mProperty_variableName, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 931)) ;
  {
  result_result.setter_setWhere (this->mProperty_where COMMA_SOURCE_FILE ("gtl_expressions.galgas", 932)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAllVarsRef eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlAllVarsRef::getter_eval (const GALGAS_gtlContext /* constinArgument_context */,
                                                const GALGAS_gtlData constinArgument_vars,
                                                const GALGAS_library /* constinArgument_lib */,
                                                C_Compiler */* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = constinArgument_vars ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlParenthesizedExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlParenthesizedExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 962)) ;
  {
  result_result.setter_setWhere (this->mProperty_where COMMA_SOURCE_FILE ("gtl_expressions.galgas", 963)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMinusExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMinusExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_gtlData constinArgument_vars,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_minusOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 977)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 977)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlPlusExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlPlusExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_gtlData constinArgument_vars,
                                                    const GALGAS_library constinArgument_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_plusOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 991)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 991)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlNotExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_notOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1005)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1005)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAddExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlAddExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_addOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1021)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1022)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1021)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSubstractExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSubstractExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_subOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1036)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1037)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1036)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMultiplyExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMultiplyExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_mulOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1051)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1052)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1051)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlDivideExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlDivideExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_divOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1066)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1067)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1066)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlModulusExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlModulusExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                       const GALGAS_gtlData constinArgument_vars,
                                                       const GALGAS_library constinArgument_lib,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_modOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1081)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1082)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1081)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAndExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlAndExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_andOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1096)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1097)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1096)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlOrExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlOrExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_gtlData constinArgument_vars,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_orOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1111)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1112)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1111)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlXorExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlXorExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_xorOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1126)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1127)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1126)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftLeftExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlShiftLeftExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_slOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1141)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1142)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1141)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftRightExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlShiftRightExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_srOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1156)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1157)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1156)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotEqualExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlNotEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_neqOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1171)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1172)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1171)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEqualExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_gtlData constinArgument_vars,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_eqOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1186)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1187)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1186)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerThanExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLowerThanExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_ltOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1201)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1202)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1201)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerOrEqualExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLowerOrEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_gtlData constinArgument_vars,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_leOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1216)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1217)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1216)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterThanExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlGreaterThanExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_gtOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1231)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1232)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1231)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterOrEqualExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlGreaterOrEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                              const GALGAS_gtlData constinArgument_vars,
                                                              const GALGAS_library constinArgument_lib,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_geOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1246)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1247)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1246)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGetterCallExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlGetterCallExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlDataList var_dataArguments_38537 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1265)) ;
  cEnumerator_gtlExpressionList enumerator_38559 (this->mProperty_arguments, kENUMERATION_UP) ;
  while (enumerator_38559.hasCurrentObject ()) {
    var_dataArguments_38537.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_38559.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1267))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1267)) ;
    enumerator_38559.gotoNextObject () ;
  }
  GALGAS_gtlData var_targetData_38667 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_target.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1269)) ;
  result_result = callExtensionGetter_performGetter ((const cPtr_gtlData *) var_targetData_38667.ptr (), this->mProperty_getterName, var_dataArguments_38537, constinArgument_context, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1270)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'checkArgumentError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_checkArgumentError (const GALGAS_lstring constinArgument_name,
                                 const GALGAS_type constinArgument_formalType,
                                 const GALGAS_gtlData constinArgument_actualArgument,
                                 const GALGAS_uint constinArgument_argumentNum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, constinArgument_formalType.objectCompare (callExtensionGetter_embeddedType ((const cPtr_gtlData *) constinArgument_actualArgument.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1280)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), extensionGetter_typeName (constinArgument_formalType, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)).add_operation (GALGAS_string (" expected for argument "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)).add_operation (constinArgument_argumentNum.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1281)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)).add_operation (extensionGetter_typeName (constinArgument_actualArgument.getter_dynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)).add_operation (GALGAS_string (" provided"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'validateReturnValue'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData function_validateReturnValue (const GALGAS_lstring & constinArgument_functionName,
                                             const GALGAS_object & constinArgument_returnedValue,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_type var_returnedType_39272 = constinArgument_returnedValue.getter_objectDynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1292)) ;
  GALGAS_location var_loc_39328 = constinArgument_functionName.readProperty_location () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_returnedType_39272.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bigint))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_gtlInt::constructor_new (var_loc_39328, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295)), GALGAS_bigint::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, var_returnedType_39272.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_double))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_result = GALGAS_gtlFloat::constructor_new (var_loc_39328, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1297)), GALGAS_double::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1297))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1297)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, var_returnedType_39272.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_string))).boolEnum () ;
        if (kBoolTrue == test_4) {
          result_result = GALGAS_gtlString::constructor_new (var_loc_39328, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1299)), GALGAS_string::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1299))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1299)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, var_returnedType_39272.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bool))).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_result = GALGAS_gtlBool::constructor_new (var_loc_39328, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1301)), GALGAS_bool::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1301))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1301)) ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = GALGAS_bool (kIsEqual, var_returnedType_39272.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_list))).boolEnum () ;
            if (kBoolTrue == test_8) {
              result_result = GALGAS_gtlList::constructor_new (var_loc_39328, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1303)), GALGAS_list::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1303))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1303)) ;
            }
          }
          if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (constinArgument_functionName.readProperty_location (), GALGAS_string ("this function does not return a compatible type"), fixItArray10  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1305)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_validateReturnValue [3] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_object,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_validateReturnValue (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_object operand1 = GALGAS_object::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_validateReturnValue (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_validateReturnValue ("validateReturnValue",
                                                                     functionWithGenericHeader_validateReturnValue,
                                                                     & kTypeDescriptor_GALGAS_gtlData,
                                                                     2,
                                                                     functionArgs_validateReturnValue) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFunctionCallExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFunctionCallExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_gtlData constinArgument_vars,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_uint var_currentErrorCount_40560 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_expressions.galgas", 1324)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_function::constructor_isFunctionDefined (this->mProperty_functionName.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1326)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_objectlist var_arguments_40697 = GALGAS_objectlist::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1328)) ;
      GALGAS_gtlDataList var_dataArguments_40741 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1329)) ;
      cEnumerator_gtlExpressionList enumerator_40766 (this->mProperty_functionArguments, kENUMERATION_UP) ;
      while (enumerator_40766.hasCurrentObject ()) {
        GALGAS_gtlData var_arg_40813 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_40766.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1332)) ;
        var_dataArguments_40741.addAssign_operation (var_arg_40813  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1333)) ;
        callExtensionMethod_addMyValue ((cPtr_gtlData *) var_arg_40813.ptr (), var_arguments_40697, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1334)) ;
        enumerator_40766.gotoNextObject () ;
      }
      GALGAS_function var_function_40956 = GALGAS_function::constructor_functionWithName (this->mProperty_functionName.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1337)) ;
      GALGAS_typelist var_formalParameterList_41042 = var_function_40956.getter_formalParameterTypeList (SOURCE_FILE ("gtl_expressions.galgas", 1339)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_formalParameterList_41042.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1340)).objectCompare (var_arguments_40697.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1340)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_string temp_2 ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, var_arguments_40697.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1343)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            temp_2 = GALGAS_string ("s") ;
          }else if (kBoolFalse == test_3) {
            temp_2 = GALGAS_string::makeEmptyString () ;
          }
          GALGAS_string temp_4 ;
          const enumGalgasBool test_5 = GALGAS_bool (kIsStrictSup, var_formalParameterList_41042.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1345)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            temp_4 = GALGAS_string ("s") ;
          }else if (kBoolFalse == test_5) {
            temp_4 = GALGAS_string::makeEmptyString () ;
          }
          TC_Array <C_FixItDescription> fixItArray6 ;
          inCompiler->emitSemanticError (this->mProperty_functionName.readProperty_location (), GALGAS_string ("this function is invoked with ").add_operation (var_arguments_40697.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1342)).getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1341)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1341)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1342)).add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1342)).add_operation (GALGAS_string (", but requires "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1343)).add_operation (var_formalParameterList_41042.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1344)).getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1344)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1344)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1344)).add_operation (temp_4, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1344)), fixItArray6  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1341)) ;
          result_result.drop () ; // Release error dropped variable
        }
      }
      if (kBoolFalse == test_1) {
        cEnumerator_typelist enumerator_41485 (var_formalParameterList_41042, kENUMERATION_UP) ;
        cEnumerator_gtlDataList enumerator_41518 (var_dataArguments_40741, kENUMERATION_UP) ;
        GALGAS_uint index_41477 ((uint32_t) 0) ;
        while (enumerator_41485.hasCurrentObject () && enumerator_41518.hasCurrentObject ()) {
          {
          routine_checkArgumentError (this->mProperty_functionName, enumerator_41485.current_mValue (HERE), enumerator_41518.current_data (HERE), index_41477, inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1349)) ;
          }
          enumerator_41485.gotoNextObject () ;
          enumerator_41518.gotoNextObject () ;
          index_41477.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1348)) ;
        }
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_currentErrorCount_40560.objectCompare (GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_expressions.galgas", 1351)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_object var_returnedValue_41708 = var_function_40956.getter_invoke (var_arguments_40697, this->mProperty_functionName.readProperty_location (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1353)) ;
            result_result = function_validateReturnValue (this->mProperty_functionName, var_returnedValue_41708, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1354)) ;
          }
        }
        if (kBoolFalse == test_7) {
          result_result = GALGAS_gtlUnconstructed::constructor_new (this->mProperty_functionName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1358))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1356)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_gtlFunction var_function_42020 = callExtensionGetter_getFunction ((const cPtr_library *) constinArgument_lib.ptr (), this->mProperty_functionName, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1363)) ;
    GALGAS_gtlDataList var_arguments_42081 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1364)) ;
    cEnumerator_gtlExpressionList enumerator_42105 (this->mProperty_functionArguments, kENUMERATION_UP) ;
    while (enumerator_42105.hasCurrentObject ()) {
      var_arguments_42081.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_42105.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1366))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1366)) ;
      enumerator_42105.gotoNextObject () ;
    }
    result_result = callExtensionGetter_call ((const cPtr_gtlFunction *) var_function_42020.ptr (), this->mProperty_functionName.readProperty_location (), constinArgument_context, constinArgument_lib, var_arguments_42081, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1368)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExistsExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386)), extensionGetter_exists (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1385)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsDefaultExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExistsDefaultExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = extensionGetter_exists (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1404)).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = extensionGetter_get (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1405)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_defaultValue.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1407)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTypeOfExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlTypeOfExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_variableValue_43981 = extensionGetter_get (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1424)) ;
  result_result = GALGAS_gtlType::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1425)), var_variableValue_43981.getter_dynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1425))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1425)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMapOfStructExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMapOfStructExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_expressionValue_44577 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1441)) ;
  if (var_expressionValue_44577.isValid ()) {
    if (var_expressionValue_44577.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_44683_expressionValueStruct ((cPtr_gtlStruct *) var_expressionValue_44577.ptr ()) ;
      result_result = GALGAS_gtlMap::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1446)), cast_44683_expressionValueStruct.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1444)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct expected"), fixItArray0  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1450)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMapOfListExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMapOfListExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_expressionValue_45327 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1467)) ;
  if (var_expressionValue_45327.isValid ()) {
    if (var_expressionValue_45327.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_45429_expressionValueList ((cPtr_gtlList *) var_expressionValue_45327.ptr ()) ;
      GALGAS_gtlVarMap var_resultMap_45455 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1470)) ;
      cEnumerator_list enumerator_45481 (cast_45429_expressionValueList.readProperty_value (), kENUMERATION_UP) ;
      GALGAS_uint index_45475 ((uint32_t) 0) ;
      while (enumerator_45481.hasCurrentObject ()) {
        if (enumerator_45481.current_value (HERE).isValid ()) {
          if (enumerator_45481.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
            GALGAS_gtlStruct cast_45576_itemStruct ((cPtr_gtlStruct *) enumerator_45481.current_value (HERE).ptr ()) ;
            enumGalgasBool test_0 = kBoolTrue ;
            if (kBoolTrue == test_0) {
              test_0 = cast_45576_itemStruct.readProperty_value ().getter_hasKey (this->mProperty_key.readProperty_string () COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1474)).boolEnum () ;
              if (kBoolTrue == test_0) {
                GALGAS_gtlData var_keyValue_45697 ;
                cast_45576_itemStruct.readProperty_value ().method_get (this->mProperty_key, var_keyValue_45697, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1475)) ;
                {
                var_resultMap_45455.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_45697.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1477)), enumerator_45481.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1476)) ;
                }
              }
            }
            if (kBoolFalse == test_0) {
              TC_Array <C_FixItDescription> fixItArray1 ;
              inCompiler->emitSemanticError (var_expressionValue_45327.readProperty_where (), GALGAS_string ("item at index ").add_operation (index_45475.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1481)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1481)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1481)).add_operation (this->mProperty_key.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1482)), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1481)) ;
            }
          }else{
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (var_expressionValue_45327.readProperty_where (), GALGAS_string ("list of struct expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1485)) ;
          }
        }
        enumerator_45481.gotoNextObject () ;
        index_45475.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1471)) ;
      }
      result_result = GALGAS_gtlMap::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1488)), var_resultMap_45455  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1488)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (var_expressionValue_45327.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1490)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlListOfExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlListOfExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_expressionValue_46620 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1507)) ;
  if (var_expressionValue_46620.isValid ()) {
    if (var_expressionValue_46620.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_46720_expressionValueMap ((cPtr_gtlMap *) var_expressionValue_46620.ptr ()) ;
      GALGAS_list var_resultList_46742 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1510)) ;
      cEnumerator_gtlVarMap enumerator_46780 (cast_46720_expressionValueMap.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_46780.hasCurrentObject ()) {
        var_resultList_46742.addAssign_operation (enumerator_46780.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1512)) ;
        enumerator_46780.gotoNextObject () ;
      }
      result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1514)), var_resultList_46742  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1514)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map expected"), fixItArray0  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1516)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralStructExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralStructExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlVarMap var_resultStruct_47415 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1533)) ;
  cEnumerator_gtlExpressionMap enumerator_47443 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_47443.hasCurrentObject ()) {
    {
    var_resultStruct_47415.setter_put (enumerator_47443.current_lkey (HERE), callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_47443.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1535)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1535)) ;
    }
    enumerator_47443.gotoNextObject () ;
  }
  result_result = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1537)), var_resultStruct_47415  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1537)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralMapExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralMapExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlVarMap var_resultStruct_48030 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1553)) ;
  cEnumerator_gtlExpressionMap enumerator_48058 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_48058.hasCurrentObject ()) {
    {
    var_resultStruct_48030.setter_put (enumerator_48058.current_lkey (HERE), callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_48058.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1555)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1555)) ;
    }
    enumerator_48058.gotoNextObject () ;
  }
  result_result = GALGAS_gtlMap::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1557)), var_resultStruct_48030  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1557)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralListExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralListExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_list var_resultList_48639 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1573)) ;
  cEnumerator_gtlExpressionList enumerator_48664 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_48664.hasCurrentObject ()) {
    var_resultList_48639.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_48664.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1575))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1575)) ;
    enumerator_48664.gotoNextObject () ;
  }
  result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1577)), var_resultList_48639  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1577)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralSetExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralSetExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_lstringset var_resultSet_49234 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1593)) ;
  cEnumerator_gtlExpressionList enumerator_49258 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_49258.hasCurrentObject ()) {
    GALGAS_lstring var_itemValue_49298 = callExtensionGetter_lstring ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_49258.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1595)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1595)) ;
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = var_resultSet_49234.getter_hasKey (var_itemValue_49298.readProperty_string () COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1596)).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        var_resultSet_49234.setter_del (var_itemValue_49298, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1597)) ;
        }
      }
    }
    {
    var_resultSet_49234.setter_put (var_itemValue_49298, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1599)) ;
    }
    enumerator_49258.gotoNextObject () ;
  }
  result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1601)), var_resultSet_49234  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1601)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'noArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_noArgument (C_Compiler *
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 85)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_noArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_noArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_noArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_noArgument) {
    gOnceFunctionResult_noArgument = onceFunction_noArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_noArgument = true ;
  }
  return gOnceFunctionResult_noArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_noArgument (void) {
  gOnceFunctionResult_noArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_noArgument (NULL,
                                                        releaseOnceFunctionResult_noArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_noArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_noArgument (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_noArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_noArgument ("noArgument",
                                                            functionWithGenericHeader_noArgument,
                                                            & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                            0,
                                                            functionArgs_noArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'intArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_intArgument (C_Compiler *
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 90)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_intArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_intArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intArgument) {
    gOnceFunctionResult_intArgument = onceFunction_intArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intArgument = true ;
  }
  return gOnceFunctionResult_intArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_intArgument (void) {
  gOnceFunctionResult_intArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_intArgument (NULL,
                                                         releaseOnceFunctionResult_intArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_intArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_intArgument (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_intArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_intArgument ("intArgument",
                                                             functionWithGenericHeader_intArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_intArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'charArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_charArgument (C_Compiler *
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 95)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_charArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_charArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charArgument) {
    gOnceFunctionResult_charArgument = onceFunction_charArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charArgument = true ;
  }
  return gOnceFunctionResult_charArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_charArgument (void) {
  gOnceFunctionResult_charArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_charArgument (NULL,
                                                          releaseOnceFunctionResult_charArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_charArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_charArgument (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_charArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_charArgument ("charArgument",
                                                              functionWithGenericHeader_charArgument,
                                                              & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                              0,
                                                              functionArgs_charArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'charCharArguments'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_charCharArguments (C_Compiler *
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 100)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 101)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_charCharArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charCharArguments ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_charCharArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charCharArguments) {
    gOnceFunctionResult_charCharArguments = onceFunction_charCharArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charCharArguments = true ;
  }
  return gOnceFunctionResult_charCharArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_charCharArguments (void) {
  gOnceFunctionResult_charCharArguments.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_charCharArguments (NULL,
                                                               releaseOnceFunctionResult_charCharArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_charCharArguments [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_charCharArguments (C_Compiler * inCompiler,
                                                                  const cObjectArray & /* inEffectiveParameterArray */,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  return function_charCharArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_charCharArguments ("charCharArguments",
                                                                   functionWithGenericHeader_charCharArguments,
                                                                   & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                   0,
                                                                   functionArgs_charCharArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'charIntArguments'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_charIntArguments (C_Compiler *
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 106)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 107)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_charIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charIntArguments ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_charIntArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charIntArguments) {
    gOnceFunctionResult_charIntArguments = onceFunction_charIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charIntArguments = true ;
  }
  return gOnceFunctionResult_charIntArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_charIntArguments (void) {
  gOnceFunctionResult_charIntArguments.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_charIntArguments (NULL,
                                                              releaseOnceFunctionResult_charIntArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_charIntArguments [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_charIntArguments (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_charIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_charIntArguments ("charIntArguments",
                                                                  functionWithGenericHeader_charIntArguments,
                                                                  & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                  0,
                                                                  functionArgs_charIntArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'floatArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_floatArgument (C_Compiler *
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 112)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_floatArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_floatArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_floatArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_floatArgument) {
    gOnceFunctionResult_floatArgument = onceFunction_floatArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_floatArgument = true ;
  }
  return gOnceFunctionResult_floatArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_floatArgument (void) {
  gOnceFunctionResult_floatArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_floatArgument (NULL,
                                                           releaseOnceFunctionResult_floatArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_floatArgument (C_Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_floatArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_floatArgument ("floatArgument",
                                                               functionWithGenericHeader_floatArgument,
                                                               & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                               0,
                                                               functionArgs_floatArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'stringArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_stringArgument (C_Compiler *
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 117)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_stringArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_stringArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_stringArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_stringArgument) {
    gOnceFunctionResult_stringArgument = onceFunction_stringArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_stringArgument = true ;
  }
  return gOnceFunctionResult_stringArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_stringArgument (void) {
  gOnceFunctionResult_stringArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_stringArgument (NULL,
                                                            releaseOnceFunctionResult_stringArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringArgument (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_stringArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringArgument ("stringArgument",
                                                                functionWithGenericHeader_stringArgument,
                                                                & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                0,
                                                                functionArgs_stringArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'stringStringArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_stringStringArgument (C_Compiler *
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 122)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 123)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_stringStringArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_stringStringArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_stringStringArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_stringStringArgument) {
    gOnceFunctionResult_stringStringArgument = onceFunction_stringStringArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_stringStringArgument = true ;
  }
  return gOnceFunctionResult_stringStringArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_stringStringArgument (void) {
  gOnceFunctionResult_stringStringArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_stringStringArgument (NULL,
                                                                  releaseOnceFunctionResult_stringStringArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringStringArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringStringArgument (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_stringStringArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringStringArgument ("stringStringArgument",
                                                                      functionWithGenericHeader_stringStringArgument,
                                                                      & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                      0,
                                                                      functionArgs_stringStringArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'boolIntArguments'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_boolIntArguments (C_Compiler *
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 128)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 129)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_boolIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_boolIntArguments ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_boolIntArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_boolIntArguments) {
    gOnceFunctionResult_boolIntArguments = onceFunction_boolIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_boolIntArguments = true ;
  }
  return gOnceFunctionResult_boolIntArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_boolIntArguments (void) {
  gOnceFunctionResult_boolIntArguments.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_boolIntArguments (NULL,
                                                              releaseOnceFunctionResult_boolIntArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_boolIntArguments [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_boolIntArguments (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_boolIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_boolIntArguments ("boolIntArguments",
                                                                  functionWithGenericHeader_boolIntArguments,
                                                                  & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                  0,
                                                                  functionArgs_boolIntArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'intIntArguments'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_intIntArguments (C_Compiler *
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 134)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 135)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_intIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intIntArguments ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_intIntArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intIntArguments) {
    gOnceFunctionResult_intIntArguments = onceFunction_intIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intIntArguments = true ;
  }
  return gOnceFunctionResult_intIntArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_intIntArguments (void) {
  gOnceFunctionResult_intIntArguments.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_intIntArguments (NULL,
                                                             releaseOnceFunctionResult_intIntArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_intIntArguments [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_intIntArguments (C_Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_intIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_intIntArguments ("intIntArguments",
                                                                 functionWithGenericHeader_intIntArguments,
                                                                 & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                 0,
                                                                 functionArgs_intIntArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'intAnyArguments'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_intAnyArguments (C_Compiler *
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 140)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 141)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_intAnyArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intAnyArguments ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_intAnyArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intAnyArguments) {
    gOnceFunctionResult_intAnyArguments = onceFunction_intAnyArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intAnyArguments = true ;
  }
  return gOnceFunctionResult_intAnyArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_intAnyArguments (void) {
  gOnceFunctionResult_intAnyArguments.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_intAnyArguments (NULL,
                                                             releaseOnceFunctionResult_intAnyArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_intAnyArguments [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_intAnyArguments (C_Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_intAnyArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_intAnyArguments ("intAnyArguments",
                                                                 functionWithGenericHeader_intAnyArguments,
                                                                 & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                 0,
                                                                 functionArgs_intAnyArguments) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'anyArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_anyArgument (C_Compiler *
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 146)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_anyArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_anyArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_anyArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_anyArgument) {
    gOnceFunctionResult_anyArgument = onceFunction_anyArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_anyArgument = true ;
  }
  return gOnceFunctionResult_anyArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_anyArgument (void) {
  gOnceFunctionResult_anyArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_anyArgument (NULL,
                                                         releaseOnceFunctionResult_anyArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_anyArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_anyArgument (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_anyArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_anyArgument ("anyArgument",
                                                             functionWithGenericHeader_anyArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_anyArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'structArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_structArgument (C_Compiler *
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 151)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_structArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_structArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_structArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_structArgument) {
    gOnceFunctionResult_structArgument = onceFunction_structArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_structArgument = true ;
  }
  return gOnceFunctionResult_structArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_structArgument (void) {
  gOnceFunctionResult_structArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_structArgument (NULL,
                                                            releaseOnceFunctionResult_structArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_structArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_structArgument (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_structArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_structArgument ("structArgument",
                                                                functionWithGenericHeader_structArgument,
                                                                & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                0,
                                                                functionArgs_structArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'expressionArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_expressionArgument (C_Compiler *
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 156)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_expressionArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_expressionArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_expressionArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_expressionArgument) {
    gOnceFunctionResult_expressionArgument = onceFunction_expressionArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_expressionArgument = true ;
  }
  return gOnceFunctionResult_expressionArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_expressionArgument (void) {
  gOnceFunctionResult_expressionArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_expressionArgument (NULL,
                                                                releaseOnceFunctionResult_expressionArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_expressionArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_expressionArgument (C_Compiler * inCompiler,
                                                                   const cObjectArray & /* inEffectiveParameterArray */,
                                                                   const GALGAS_location & /* inErrorLocation */
                                                                   COMMA_LOCATION_ARGS) {
  return function_expressionArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_expressionArgument ("expressionArgument",
                                                                    functionWithGenericHeader_expressionArgument,
                                                                    & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                    0,
                                                                    functionArgs_expressionArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'setArgument'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_setArgument (C_Compiler *
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 161)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_setArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_setArgument ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_setArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_setArgument) {
    gOnceFunctionResult_setArgument = onceFunction_setArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_setArgument = true ;
  }
  return gOnceFunctionResult_setArgument ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_setArgument (void) {
  gOnceFunctionResult_setArgument.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_setArgument (NULL,
                                                         releaseOnceFunctionResult_setArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_setArgument [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_setArgument (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_setArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_setArgument ("setArgument",
                                                             functionWithGenericHeader_setArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_setArgument) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'argumentsCheck'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_argumentsCheck (const GALGAS_lstring constinArgument_methodName,
                             GALGAS_gtlTypedArgumentList inArgument_abstractArgumentList,
                             GALGAS_gtlDataList inArgument_concreteArgumentList,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_concreteLength_5063 = inArgument_concreteArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 169)) ;
  GALGAS_uint var_abstractLength_5122 = inArgument_abstractArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 170)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_abstractArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 171)).objectCompare (inArgument_concreteArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 171)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), constinArgument_methodName.readProperty_string ().add_operation (GALGAS_string (" expects "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)).add_operation (var_abstractLength_5122.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 172)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)).add_operation (GALGAS_string (" arguments. "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)).add_operation (var_concreteLength_5063.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 173)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 173)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 173)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)) ;
    }
  }
  if (kBoolFalse == test_0) {
    cEnumerator_gtlDataList enumerator_5401 (inArgument_concreteArgumentList, kENUMERATION_UP) ;
    cEnumerator_gtlTypedArgumentList enumerator_5429 (inArgument_abstractArgumentList, kENUMERATION_UP) ;
    GALGAS_uint index_5398 ((uint32_t) 0) ;
    while (enumerator_5401.hasCurrentObject () && enumerator_5429.hasCurrentObject ()) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, enumerator_5401.current_data (HERE).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 176)).objectCompare (enumerator_5429.current_type (HERE))).operator_and (GALGAS_bool (kIsNotEqual, enumerator_5429.current_type (HERE).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 176)).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) enumerator_5401.current_data (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)), extensionGetter_typeName (enumerator_5429.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)).add_operation (GALGAS_string (" expected for argument "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)).add_operation (index_5398.add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 179)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 178)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 178)), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)) ;
        }
      }
      enumerator_5401.gotoNextObject () ;
      enumerator_5429.gotoNextObject () ;
      index_5398.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 175)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'emptylstring'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_lstring onceFunction_emptylstring (C_Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("gtl_data_types.galgas", 187))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 187)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_emptylstring = false ;
static GALGAS_lstring gOnceFunctionResult_emptylstring ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring function_emptylstring (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptylstring) {
    gOnceFunctionResult_emptylstring = onceFunction_emptylstring (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptylstring = true ;
  }
  return gOnceFunctionResult_emptylstring ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_emptylstring (void) {
  gOnceFunctionResult_emptylstring.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_emptylstring (NULL,
                                                          releaseOnceFunctionResult_emptylstring) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptylstring [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptylstring (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptylstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptylstring ("emptylstring",
                                                              functionWithGenericHeader_emptylstring,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptylstring) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring function_lstring (GALGAS_string inArgument_string,
                                 C_Compiler *
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (inArgument_string, GALGAS_location::constructor_nowhere (SOURCE_FILE ("gtl_data_types.galgas", 192))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 192)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_lstring [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_lstring (C_Compiler * inCompiler,
                                                        const cObjectArray & inEffectiveParameterArray,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstring (operand0,
                           inCompiler
                           COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_lstring ("lstring",
                                                         functionWithGenericHeader_lstring,
                                                         & kTypeDescriptor_GALGAS_lstring,
                                                         1,
                                                         functionArgs_lstring) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlUnconstructed::getter_desc (const GALGAS_uint constinArgument_tab,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 377)).add_operation (GALGAS_string ("unconstructed\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 377)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlUnconstructed::getter_string (C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 382)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlUnconstructed::getter_lstring (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 386)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlUnconstructed::getter_bool (C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 390)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlUnconstructed::getter_int (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 394)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlUnconstructed::getter_float (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 398)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_plusOp (C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 402)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_minusOp (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 405)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_notOp (C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 408)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 411)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 414)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 417)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 420)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 423)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 426)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 429)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 432)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 435)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 438)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_neqOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 441)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_eqOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 444)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 447)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 450)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 453)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 456)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlUnconstructed::getter_embeddedType (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed data provided as argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 461)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlUnconstructed addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlUnconstructed::method_addMyValue (GALGAS_objectlist & /* ioArgument_objectList */,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("Attempting to pass an unconstructed data to a function"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 466)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 480)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 480)) ;
      }
      const GALGAS_gtlUnconstructed temp_1 = this ;
      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 482)), temp_1.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 482))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 481)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 485)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 485)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 487)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 486)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 490)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 490)) ;
          }
          result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 492)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 491)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 495)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 495)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 496)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 499)).boolEnum () ;
            if (kBoolTrue == test_5) {
              const GALGAS_gtlUnconstructed temp_6 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 500)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_6, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 500)) ;
            }
          }
          if (kBoolFalse == test_5) {
            TC_Array <C_FixItDescription> fixItArray7 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 508)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 508)), fixItArray7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 508)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlUnconstructed performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlUnconstructed_performSetter (cPtr_gtlData * inObject,
                                                            const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlUnconstructed * object = (cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 522)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 522)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_16293 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_16293.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 524)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 524)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 527)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 527)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 529)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlUnconstructed temp_4 = object ;
          GALGAS_gtlData var_copy_16598 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 531)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_16598, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 531)) ;
          object->mProperty_where = var_copy_16598.readProperty_where () ;
          object->mProperty_meta = var_copy_16598.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 541)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 541)), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 541)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlUnconstructed_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                      extensionSetter_gtlUnconstructed_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlUnconstructed_performSetter (defineExtensionSetter_gtlUnconstructed_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlType::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 555)).add_operation (GALGAS_string ("type: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 555)).add_operation (extensionGetter_typeName (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 556)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 556)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 556)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlType::getter_string (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = extensionGetter_typeName (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 559)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlType::getter_lstring (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 562)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 562)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlType::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a type to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 566)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlType::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a type to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 570)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlType::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a type to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 574)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 578)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 581)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 584)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 587)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 590)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 593)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 596)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 599)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 602)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 605)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 608)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 611)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 614)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlType temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 618)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 618)), GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (temp_1.readProperty_type ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 618)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 620)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlType temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 625)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 625)), GALGAS_bool (kIsEqual, this->mProperty_type.objectCompare (temp_1.readProperty_type ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 625)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 627)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 631)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 634)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 637)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 640)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlType::getter_embeddedType (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_type) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlType addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlType::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_type.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 650))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 650)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 664)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 664)) ;
      }
      const GALGAS_gtlType temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 666)), callExtensionGetter_string ((const cPtr_gtlType *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 666))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 665)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 669)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 669)) ;
        }
        const GALGAS_gtlType temp_3 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 671)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 671))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 670)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 674)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 674)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 676)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 675)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 679)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 679)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 681)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 680)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_6) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 684)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 684)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 686)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 686))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 685)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_7 = kBoolTrue ;
            if (kBoolTrue == test_7) {
              test_7 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 688)).boolEnum () ;
              if (kBoolTrue == test_7) {
                const GALGAS_gtlType temp_8 = this ;
                result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 689)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_8, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 689)) ;
              }
            }
            if (kBoolFalse == test_7) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 697)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 697)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 697)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlType performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlType_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlType * object = (cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 711)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 711)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_22646 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_22646.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 713)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 713)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 716)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 716)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 718)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlType temp_4 = object ;
          GALGAS_gtlData var_copy_22942 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 720)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_22942, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 720)) ;
          GALGAS_gtlType temp_5 ;
          if (var_copy_22942.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlType *> (var_copy_22942.ptr ())) {
              temp_5 = (cPtr_gtlType *) var_copy_22942.ptr () ;
            }else{
              inCompiler->castError ("gtlType", var_copy_22942.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 727)) ;
            }
          }
          object->mProperty_type = temp_5.readProperty_type () ;
          object->mProperty_where = var_copy_22942.readProperty_where () ;
          object->mProperty_meta = var_copy_22942.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlType_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                      extensionSetter_gtlType_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlType_performSetter (defineExtensionSetter_gtlType_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 744)).add_operation (GALGAS_string ("enum: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 744)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 745)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 745)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlEnum::getter_lstring (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value, this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 751)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlEnum::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 755)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlEnum::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 759)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlEnum::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 763)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 767)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 770)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 773)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 776)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 779)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 782)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 785)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 788)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 791)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 794)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 797)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 800)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 803)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 810)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 809)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 807)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 813)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 821)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 820)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 818)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 824)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 828)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 831)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 834)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 837)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlEnum::getter_embeddedType (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 842)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEnum addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlEnum::method_addMyValue (GALGAS_objectlist & /* ioArgument_objectList */,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 847)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)) ;
      }
      const GALGAS_gtlEnum temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863)), callExtensionGetter_string ((const cPtr_gtlEnum *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 862)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)) ;
        }
        const GALGAS_gtlEnum temp_3 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 868)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 868))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 867)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 873)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 872)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 878)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 877)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 880)).boolEnum () ;
            if (kBoolTrue == test_6) {
              const GALGAS_gtlEnum temp_7 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 881)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 881)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_8 = kBoolTrue ;
            if (kBoolTrue == test_8) {
              test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_8) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 891)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 891))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 890)) ;
              }
            }
            if (kBoolFalse == test_8) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlEnum performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlEnum_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlEnum * object = (cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_29129 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_29129.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 913)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 913)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 915)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlEnum temp_4 = object ;
          GALGAS_gtlData var_copy_29425 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 917)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_29425, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 917)) ;
          GALGAS_gtlEnum temp_5 ;
          if (var_copy_29425.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlEnum *> (var_copy_29425.ptr ())) {
              temp_5 = (cPtr_gtlEnum *) var_copy_29425.ptr () ;
            }else{
              inCompiler->castError ("gtlEnum", var_copy_29425.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 924)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_29425.readProperty_where () ;
          object->mProperty_meta = var_copy_29425.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlEnum_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionSetter_gtlEnum_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlEnum_performSetter (defineExtensionSetter_gtlEnum_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 941)).add_operation (GALGAS_string ("char: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 941)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 942)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 942)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 942)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 945)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlChar::getter_lstring (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 948)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 948)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlChar::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a char to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 952)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlChar::getter_int (C_Compiler */* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_uint (SOURCE_FILE ("gtl_data_types.galgas", 956)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 956)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlChar::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a char to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 960)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 964)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 968)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 972)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 976)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 980)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 984)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 988)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 992)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 996)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1000)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1004)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1008)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1012)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1020)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1019)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1017)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1032)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1031)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1029)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1044)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1043)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1041)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1047)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1047)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1056)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1055)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1053)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1059)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1068)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1067)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1065)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1071)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1080)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1079)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1077)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1083)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlChar::getter_embeddedType (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_char) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlChar addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlChar::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1094))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1094)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)) ;
      }
      const GALGAS_gtlChar temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110)), callExtensionGetter_string ((const cPtr_gtlChar *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1109)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlnum").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1115)), this->mProperty_value.getter_isalnum (SOURCE_FILE ("gtl_data_types.galgas", 1115))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1114)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isCntrl").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1120)), this->mProperty_value.getter_iscntrl (SOURCE_FILE ("gtl_data_types.galgas", 1120))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1119)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isDigit").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)) ;
            }
            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1125)), this->mProperty_value.getter_isdigit (SOURCE_FILE ("gtl_data_types.galgas", 1125))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlpha").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)) ;
              }
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1130)), this->mProperty_value.getter_isalpha (SOURCE_FILE ("gtl_data_types.galgas", 1130))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1129)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("isLower").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)) ;
                }
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1135)), this->mProperty_value.getter_islower (SOURCE_FILE ("gtl_data_types.galgas", 1135))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1134)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("isUpper").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)) ;
                  }
                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1140)), this->mProperty_value.getter_isupper (SOURCE_FILE ("gtl_data_types.galgas", 1140))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1139)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("isXDigit").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)) ;
                    }
                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1145)), this->mProperty_value.getter_isxdigit (SOURCE_FILE ("gtl_data_types.galgas", 1145))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1144)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)) ;
                      }
                      const GALGAS_gtlChar temp_10 = this ;
                      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1150)), temp_10.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1150))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1149)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_11 = kBoolTrue ;
                    if (kBoolTrue == test_11) {
                      test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)) ;
                        }
                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1155)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1154)) ;
                      }
                    }
                    if (kBoolFalse == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)) ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1160)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1159)) ;
                        }
                      }
                      if (kBoolFalse == test_12) {
                        enumGalgasBool test_13 = kBoolTrue ;
                        if (kBoolTrue == test_13) {
                          test_13 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1162)).boolEnum () ;
                          if (kBoolTrue == test_13) {
                            const GALGAS_gtlChar temp_14 = this ;
                            result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1163)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_14, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1163)) ;
                          }
                        }
                        if (kBoolFalse == test_13) {
                          enumGalgasBool test_15 = kBoolTrue ;
                          if (kBoolTrue == test_15) {
                            test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_15) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)) ;
                              }
                              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1173)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1173))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1172)) ;
                            }
                          }
                          if (kBoolFalse == test_15) {
                            TC_Array <C_FixItDescription> fixItArray16 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)), fixItArray16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)) ;
                            result_result.drop () ; // Release error dropped variable
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlChar performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlChar_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlChar * object = (cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_37595 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_37595.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1195)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1195)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1197)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlChar temp_4 = object ;
          GALGAS_gtlData var_copy_37891 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1199)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_37891, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1199)) ;
          GALGAS_gtlChar temp_5 ;
          if (var_copy_37891.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (var_copy_37891.ptr ())) {
              temp_5 = (cPtr_gtlChar *) var_copy_37891.ptr () ;
            }else{
              inCompiler->castError ("gtlChar", var_copy_37891.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1206)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_37891.readProperty_where () ;
          object->mProperty_meta = var_copy_37891.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlChar_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionSetter_gtlChar_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlChar_performSetter (defineExtensionSetter_gtlChar_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_desc (const GALGAS_uint constinArgument_tab,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1223)).add_operation (GALGAS_string ("integer: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1223)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1224)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1224)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_string (C_Compiler */* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1227)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlInt::getter_lstring (C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1230)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1230)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlInt::getter_bool (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an int to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1234)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlInt::getter_int (C_Compiler */* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlInt::getter_float (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1242)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 1242)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_plusOp (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlInt temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_minusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248)), this->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_notOp (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)), this->mProperty_value.operator_tilde (SOURCE_FILE ("gtl_data_types.galgas", 1252))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1260)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1259)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1260))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1257)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("*int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1263)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1272)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1271)), this->mProperty_value.substract_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1272))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1269)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1275)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1284)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1283)), this->mProperty_value.multiply_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1284))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1281)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1287)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1296)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1295)), this->mProperty_value.divide_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1293)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1299)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_modOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1308)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1307)), this->mProperty_value.modulo_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1308))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1305)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1311)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1319)), this->mProperty_value.operator_and (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1317)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1323)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1331)), this->mProperty_value.operator_or (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1329)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1335)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1343)), this->mProperty_value.operator_xor (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1341)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1347)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_slOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353)) ;
        }
      }
      GALGAS_bigint var_r_41727 = temp_1.readProperty_value () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_41727.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1354)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_gtlInt temp_3 ;
          if (constinArgument_right.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
              temp_3 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358)) ;
            }
          }
          result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1357)), this->mProperty_value.left_shift_operation (temp_3.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1355)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("positive int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1361)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1364)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_srOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1370)) ;
        }
      }
      GALGAS_bigint var_r_42163 = temp_1.readProperty_value () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_42163.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1371)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_result = GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)), this->mProperty_value.right_shift_operation (var_r_42163.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("positive int expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1374)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1377)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1386)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1385)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1383)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1389)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1398)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1397)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1395)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1401)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1410)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1409)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1407)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1413)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1422)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1421)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1419)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1434)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1431)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1437)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1446)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1445)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1443)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1449)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlInt::getter_embeddedType (C_Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bigint) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInt addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInt::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     C_Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1460))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1460)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)) ;
      }
      const GALGAS_gtlInt temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("padded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)) ;
        }
        GALGAS_gtlInt temp_3 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr ())) {
            temp_3 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
          }
        }
        GALGAS_uint var_fieldSize_44985 = temp_3.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
        const GALGAS_gtlInt temp_4 = this ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484)).getter_stringByLeftAndRightPadding (var_fieldSize_44985, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1481)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("leftPadded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)) ;
          }
          GALGAS_gtlInt temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr ())) {
              temp_6 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)) ;
            }
          }
          GALGAS_uint var_fieldSize_45328 = temp_6.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)) ;
          const GALGAS_gtlInt temp_7 = this ;
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_7.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492)).getter_stringByLeftPadding (var_fieldSize_45328, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1489)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("rightPadded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)) ;
            }
            GALGAS_gtlInt temp_9 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr ())) {
                temp_9 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)) ;
              }
            }
            GALGAS_uint var_fieldSize_45665 = temp_9.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)) ;
            const GALGAS_gtlInt temp_10 = this ;
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1499)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_10.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500)).getter_stringByRightPadding (var_fieldSize_45665, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1497)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("hexString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1505)), this->mProperty_value.getter_hexString (SOURCE_FILE ("gtl_data_types.galgas", 1505))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1504)) ;
            }
          }
          if (kBoolFalse == test_11) {
            enumGalgasBool test_12 = kBoolTrue ;
            if (kBoolTrue == test_12) {
              test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("xString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_12) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1510)), this->mProperty_value.getter_xString (SOURCE_FILE ("gtl_data_types.galgas", 1510))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1509)) ;
              }
            }
            if (kBoolFalse == test_12) {
              enumGalgasBool test_13 = kBoolTrue ;
              if (kBoolTrue == test_13) {
                test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBytes").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_13) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1513)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1513)) ;
                  }
                  result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1516)), this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1517)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1517)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)).divide_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1514)) ;
                }
              }
              if (kBoolFalse == test_13) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBytes").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1520)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1520)) ;
                    }
                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1523)), this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1524)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1524)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)).divide_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1521)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_15 = kBoolTrue ;
                  if (kBoolTrue == test_15) {
                    test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBits").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_15) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1527)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1527)) ;
                      }
                      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1530)), this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1531)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1531))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1528)) ;
                    }
                  }
                  if (kBoolFalse == test_15) {
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBits").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1534)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1534)) ;
                        }
                        result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1537)), this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1538)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1538))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1535)) ;
                      }
                    }
                    if (kBoolFalse == test_16) {
                      enumGalgasBool test_17 = kBoolTrue ;
                      if (kBoolTrue == test_17) {
                        test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("sign").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_17) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1541)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1541)) ;
                          }
                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1544)), this->mProperty_value.getter_sign (SOURCE_FILE ("gtl_data_types.galgas", 1545)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1545))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1542)) ;
                        }
                      }
                      if (kBoolFalse == test_17) {
                        enumGalgasBool test_18 = kBoolTrue ;
                        if (kBoolTrue == test_18) {
                          test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInByte").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_18) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1548)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1548)) ;
                            }
                            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1551)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1552)).objectCompare (GALGAS_uint (uint32_t (8U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1549)) ;
                          }
                        }
                        if (kBoolFalse == test_18) {
                          enumGalgasBool test_19 = kBoolTrue ;
                          if (kBoolTrue == test_19) {
                            test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInByte").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_19) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1555)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1555)) ;
                              }
                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1558)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1559)).objectCompare (GALGAS_uint (uint32_t (8U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1556)) ;
                            }
                          }
                          if (kBoolFalse == test_19) {
                            enumGalgasBool test_20 = kBoolTrue ;
                            if (kBoolTrue == test_20) {
                              test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInShort").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_20) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1562)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1562)) ;
                                }
                                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1565)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1566)).objectCompare (GALGAS_uint (uint32_t (16U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1563)) ;
                              }
                            }
                            if (kBoolFalse == test_20) {
                              enumGalgasBool test_21 = kBoolTrue ;
                              if (kBoolTrue == test_21) {
                                test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInShort").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_21) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1572)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1573)).objectCompare (GALGAS_uint (uint32_t (16U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1570)) ;
                                }
                              }
                              if (kBoolFalse == test_21) {
                                enumGalgasBool test_22 = kBoolTrue ;
                                if (kBoolTrue == test_22) {
                                  test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                  if (kBoolTrue == test_22) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)) ;
                                    }
                                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1579)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1580)).objectCompare (GALGAS_uint (uint32_t (32U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1577)) ;
                                  }
                                }
                                if (kBoolFalse == test_22) {
                                  enumGalgasBool test_23 = kBoolTrue ;
                                  if (kBoolTrue == test_23) {
                                    test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_23) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1583)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1583)) ;
                                      }
                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1587)).objectCompare (GALGAS_uint (uint32_t (32U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1584)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_23) {
                                    enumGalgasBool test_24 = kBoolTrue ;
                                    if (kBoolTrue == test_24) {
                                      test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLongLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                      if (kBoolTrue == test_24) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1590)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1590)) ;
                                        }
                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1593)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1594)).objectCompare (GALGAS_uint (uint32_t (64U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1591)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_24) {
                                      enumGalgasBool test_25 = kBoolTrue ;
                                      if (kBoolTrue == test_25) {
                                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLongLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                        if (kBoolTrue == test_25) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1597)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1597)) ;
                                          }
                                          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1601)).objectCompare (GALGAS_uint (uint32_t (64U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1598)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_25) {
                                        enumGalgasBool test_26 = kBoolTrue ;
                                        if (kBoolTrue == test_26) {
                                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("abs").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                          if (kBoolTrue == test_26) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1604)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1604)) ;
                                            }
                                            result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)), this->mProperty_value.getter_abs (SOURCE_FILE ("gtl_data_types.galgas", 1608))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1605)) ;
                                          }
                                        }
                                        if (kBoolFalse == test_26) {
                                          enumGalgasBool test_27 = kBoolTrue ;
                                          if (kBoolTrue == test_27) {
                                            test_27 = GALGAS_bool (kIsEqual, GALGAS_string ("bitAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                            if (kBoolTrue == test_27) {
                                              {
                                              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)) ;
                                              }
                                              GALGAS_gtlInt temp_28 ;
                                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).isValid ()) {
                                                if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr ())) {
                                                  temp_28 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr () ;
                                                }else{
                                                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
                                                }
                                              }
                                              GALGAS_uint var_index_49865 = temp_28.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
                                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1615)), this->mProperty_value.getter_bitAtIndex (var_index_49865 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1616))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1613)) ;
                                            }
                                          }
                                          if (kBoolFalse == test_27) {
                                            enumGalgasBool test_29 = kBoolTrue ;
                                            if (kBoolTrue == test_29) {
                                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                              if (kBoolTrue == test_29) {
                                                {
                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)) ;
                                                }
                                                const GALGAS_gtlInt temp_30 = this ;
                                                result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1621)), temp_30.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1621))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1620)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_29) {
                                              enumGalgasBool test_31 = kBoolTrue ;
                                              if (kBoolTrue == test_31) {
                                                test_31 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                if (kBoolTrue == test_31) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)) ;
                                                  }
                                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1626)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1625)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_31) {
                                                enumGalgasBool test_32 = kBoolTrue ;
                                                if (kBoolTrue == test_32) {
                                                  test_32 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                  if (kBoolTrue == test_32) {
                                                    {
                                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)) ;
                                                    }
                                                    result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1631)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1630)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_32) {
                                                  enumGalgasBool test_33 = kBoolTrue ;
                                                  if (kBoolTrue == test_33) {
                                                    test_33 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1633)).boolEnum () ;
                                                    if (kBoolTrue == test_33) {
                                                      const GALGAS_gtlInt temp_34 = this ;
                                                      result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1634)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_34, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1634)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_33) {
                                                    enumGalgasBool test_35 = kBoolTrue ;
                                                    if (kBoolTrue == test_35) {
                                                      test_35 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                      if (kBoolTrue == test_35) {
                                                        {
                                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)) ;
                                                        }
                                                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1644)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1644))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1643)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_35) {
                                                      TC_Array <C_FixItDescription> fixItArray36 ;
                                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)), fixItArray36  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)) ;
                                                      result_result.drop () ; // Release error dropped variable
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlInt performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlInt_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlInt * object = (cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("setBitAtIndex"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_boolIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1661)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1661)) ;
      }
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)) ;
        }
      }
      GALGAS_bool var_bit_51575 = temp_1.readProperty_value () ;
      GALGAS_gtlInt temp_2 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ())) {
          temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
        }
      }
      GALGAS_uint var_index_51644 = temp_2.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
      {
      object->mProperty_value.setter_setBitAtIndex (var_bit_51575, var_index_51644 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1664)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("complementBitAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)) ;
        }
        GALGAS_gtlInt temp_4 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ())) {
            temp_4 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
          }
        }
        GALGAS_uint var_index_51899 = temp_4.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
        {
        object->mProperty_value.setter_complementBitAtIndex (var_index_51899 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1669)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)) ;
          }
          GALGAS_gtlString temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr ())) {
              temp_6 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr () ;
            }else{
              inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)) ;
            }
          }
          GALGAS_gtlString var_descriptionToSet_52160 = temp_6 ;
          {
          object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_52160.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_7) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1677)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1677)) ;
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_7) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1679)).boolEnum () ;
            if (kBoolTrue == test_8) {
              const GALGAS_gtlInt temp_9 = object ;
              GALGAS_gtlData var_copy_52455 = temp_9 ;
              callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1681)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_52455, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1681)) ;
              GALGAS_gtlInt temp_10 ;
              if (var_copy_52455.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_copy_52455.ptr ())) {
                  temp_10 = (cPtr_gtlInt *) var_copy_52455.ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", var_copy_52455.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1688)) ;
                }
              }
              object->mProperty_value = temp_10.readProperty_value () ;
              object->mProperty_where = var_copy_52455.readProperty_where () ;
              object->mProperty_meta = var_copy_52455.readProperty_meta () ;
            }
          }
          if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray11 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)), fixItArray11  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlInt_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionSetter_gtlInt_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlInt_performSetter (defineExtensionSetter_gtlInt_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_desc (const GALGAS_uint constinArgument_tab,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1705)).add_operation (GALGAS_string ("float: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1705)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1706)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_string (C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1709)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlFloat::getter_lstring (C_Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1712)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1712)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlFloat::getter_bool (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a float to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1716)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlFloat::getter_int (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1720)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1720)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlFloat::getter_float (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_plusOp (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlFloat temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_minusOp (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730)), this->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_notOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1734)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1742)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1741)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1742))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1739)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1745)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1753)), this->mProperty_value.substract_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1751)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1757)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1765)), this->mProperty_value.multiply_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1763)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1769)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1777)), this->mProperty_value.divide_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1775)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1781)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1786)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1790)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1794)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1798)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1802)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1806)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1814)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1813)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1811)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1817)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1826)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1825)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1823)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1829)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1838)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1837)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1835)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1841)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1850)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1849)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1847)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1853)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1862)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1861)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1859)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1865)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1874)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1873)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1871)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1877)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlFloat::getter_embeddedType (C_Compiler */* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_double) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlFloat addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlFloat::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                       C_Compiler * /* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1888))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1888)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)) ;
      }
      const GALGAS_gtlFloat temp_1 = this ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904)), callExtensionGetter_string ((const cPtr_gtlFloat *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1903)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("cos").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)) ;
        }
        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1909)), this->mProperty_value.getter_cos (SOURCE_FILE ("gtl_data_types.galgas", 1909))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1908)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("sin").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)) ;
          }
          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1914)), this->mProperty_value.getter_sin (SOURCE_FILE ("gtl_data_types.galgas", 1914))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1913)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("tan").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)) ;
            }
            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1919)), this->mProperty_value.getter_tan (SOURCE_FILE ("gtl_data_types.galgas", 1919))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1918)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("cosDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)) ;
              }
              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1924)), this->mProperty_value.getter_cosDegree (SOURCE_FILE ("gtl_data_types.galgas", 1924))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1923)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("sinDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)) ;
                }
                result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1929)), this->mProperty_value.getter_sinDegree (SOURCE_FILE ("gtl_data_types.galgas", 1929))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1928)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("tanDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)) ;
                  }
                  result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1934)), this->mProperty_value.getter_tanDegree (SOURCE_FILE ("gtl_data_types.galgas", 1934))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1933)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("exp").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)) ;
                    }
                    result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1939)), this->mProperty_value.getter_exp (SOURCE_FILE ("gtl_data_types.galgas", 1939))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1938)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("logn").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)) ;
                      }
                      result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944)), this->mProperty_value.getter_logn (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1943)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_10 = kBoolTrue ;
                    if (kBoolTrue == test_10) {
                      test_10 = GALGAS_bool (kIsEqual, GALGAS_string ("log2").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)) ;
                        }
                        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949)), this->mProperty_value.getter_log_32_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1948)) ;
                      }
                    }
                    if (kBoolFalse == test_10) {
                      enumGalgasBool test_11 = kBoolTrue ;
                      if (kBoolTrue == test_11) {
                        test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("log10").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)) ;
                          }
                          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954)), this->mProperty_value.getter_log_31__30_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1953)) ;
                        }
                      }
                      if (kBoolFalse == test_11) {
                        enumGalgasBool test_12 = kBoolTrue ;
                        if (kBoolTrue == test_12) {
                          test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("sqrt").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_12) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)) ;
                            }
                            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959)), this->mProperty_value.getter_sqrt (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)) ;
                          }
                        }
                        if (kBoolFalse == test_12) {
                          enumGalgasBool test_13 = kBoolTrue ;
                          if (kBoolTrue == test_13) {
                            test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("power").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_13) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_floatArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1962)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1962)) ;
                              }
                              GALGAS_gtlFloat temp_14 ;
                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).isValid ()) {
                                if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr ())) {
                                  temp_14 = (cPtr_gtlFloat *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr () ;
                                }else{
                                  inCompiler->castError ("gtlFloat", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)) ;
                                }
                              }
                              GALGAS_double var_power_60705 = temp_14.readProperty_value () ;
                              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965)), this->mProperty_value.getter_power (var_power_60705, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1964)) ;
                            }
                          }
                          if (kBoolFalse == test_13) {
                            enumGalgasBool test_15 = kBoolTrue ;
                            if (kBoolTrue == test_15) {
                              test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_15) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)) ;
                                }
                                const GALGAS_gtlFloat temp_16 = this ;
                                result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1970)), temp_16.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1970))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1969)) ;
                              }
                            }
                            if (kBoolFalse == test_15) {
                              enumGalgasBool test_17 = kBoolTrue ;
                              if (kBoolTrue == test_17) {
                                test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_17) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1975)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1974)) ;
                                }
                              }
                              if (kBoolFalse == test_17) {
                                enumGalgasBool test_18 = kBoolTrue ;
                                if (kBoolTrue == test_18) {
                                  test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("int").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                  if (kBoolTrue == test_18) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)) ;
                                    }
                                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)), this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1980))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1979)) ;
                                  }
                                }
                                if (kBoolFalse == test_18) {
                                  enumGalgasBool test_19 = kBoolTrue ;
                                  if (kBoolTrue == test_19) {
                                    test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_19) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)) ;
                                      }
                                      result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1985)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1984)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_19) {
                                    enumGalgasBool test_20 = kBoolTrue ;
                                    if (kBoolTrue == test_20) {
                                      test_20 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1987)).boolEnum () ;
                                      if (kBoolTrue == test_20) {
                                        const GALGAS_gtlFloat temp_21 = this ;
                                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1988)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_21, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1988)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_20) {
                                      enumGalgasBool test_22 = kBoolTrue ;
                                      if (kBoolTrue == test_22) {
                                        test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                        if (kBoolTrue == test_22) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)) ;
                                          }
                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1998)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1998))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1997)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_22) {
                                        TC_Array <C_FixItDescription> fixItArray23 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)), fixItArray23  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)) ;
                                        result_result.drop () ; // Release error dropped variable
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlFloat performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlFloat_performSetter (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlFloat * object = (cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_62602 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_62602.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2020)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2020)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2022)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlFloat temp_4 = object ;
          GALGAS_gtlData var_copy_62899 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2024)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_62899, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2024)) ;
          GALGAS_gtlFloat temp_5 ;
          if (var_copy_62899.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlFloat *> (var_copy_62899.ptr ())) {
              temp_5 = (cPtr_gtlFloat *) var_copy_62899.ptr () ;
            }else{
              inCompiler->castError ("gtlFloat", var_copy_62899.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2031)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_62899.readProperty_where () ;
          object->mProperty_meta = var_copy_62899.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlFloat_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                      extensionSetter_gtlFloat_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlFloat_performSetter (defineExtensionSetter_gtlFloat_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_desc (const GALGAS_uint constinArgument_tab,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2048)).add_operation (GALGAS_string ("string: \""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2048)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_string (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlString::getter_lstring (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value, this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2054)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlString::getter_bool (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a string to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2057)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlString::getter_int (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2061)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2061)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlString::getter_float (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2065)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 2065)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_plusOp (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2069)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_minusOp (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2073)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_notOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2077)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2085)) ;
        }
      }
      result_result = GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2084)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2085))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2082)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2088)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2093)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2097)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2101)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2105)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2109)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2113)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2117)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2121)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2125)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2133)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2132)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2130)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2136)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2145)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2144)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2142)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2148)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2157)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2156)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2154)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2160)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2169)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2168)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2166)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2172)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2181)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2180)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2178)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2184)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2193)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2192)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2190)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2196)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlString::getter_embeddedType (C_Compiler */* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_string) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlString addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlString::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2207))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2207)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("string"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)) ;
      }
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2223)), this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("charAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2226)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2226)) ;
        }
        GALGAS_gtlInt temp_2 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr ())) {
            temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
          }
        }
        GALGAS_uint var_index_68509 = temp_2.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
        result_result = GALGAS_gtlChar::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2229)), this->mProperty_value.getter_characterAtIndex (var_index_68509, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2229))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("indexOfChar"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2232)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2232)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2233)) ;
            }
          }
          GALGAS_char var_lookedUpChar_68812 = temp_4.readProperty_value () ;
          GALGAS_uint var_index_68877 = GALGAS_uint (uint32_t (0U)) ;
          GALGAS_uint var_length_68902 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2235)) ;
          GALGAS_bool var_found_68935 = GALGAS_bool (false) ;
          if (var_length_68902.isValid ()) {
            uint32_t variant_68952 = var_length_68902.uintValue () ;
            bool loop_68952 = true ;
            while (loop_68952) {
              GALGAS_bool test_5 = var_found_68935.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2238)) ;
              if (kBoolTrue == test_5.boolEnum ()) {
                test_5 = GALGAS_bool (kIsStrictInf, var_index_68877.objectCompare (var_length_68902)) ;
              }
              loop_68952 = test_5.isValid () ;
              if (loop_68952) {
                loop_68952 = test_5.boolValue () ;
              }
              if (loop_68952 && (0 == variant_68952)) {
                loop_68952 = false ;
                inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2237)) ;
              }
              if (loop_68952) {
                variant_68952 -- ;
                enumGalgasBool test_6 = kBoolTrue ;
                if (kBoolTrue == test_6) {
                  test_6 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_characterAtIndex (var_index_68877, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2239)).objectCompare (var_lookedUpChar_68812)).boolEnum () ;
                  if (kBoolTrue == test_6) {
                    var_found_68935 = GALGAS_bool (true) ;
                  }
                }
                if (kBoolFalse == test_6) {
                  var_index_68877.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2242)) ;
                }
              }
            }
          }
          GALGAS_bigint temp_7 ;
          const enumGalgasBool test_8 = var_found_68935.boolEnum () ;
          if (kBoolTrue == test_8) {
            temp_7 = var_index_68877.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
          }else if (kBoolFalse == test_8) {
            temp_7 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
          }
          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)), temp_7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2245)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_9 = kBoolTrue ;
        if (kBoolTrue == test_9) {
          test_9 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("indexOfCharInRange"))).boolEnum () ;
          if (kBoolTrue == test_9) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2251)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2251)) ;
            }
            GALGAS_gtlChar temp_10 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr ())) {
                temp_10 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2252)) ;
              }
            }
            GALGAS_char var_minChar_69407 = temp_10.readProperty_value () ;
            GALGAS_gtlChar temp_11 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr ())) {
                temp_11 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2253)) ;
              }
            }
            GALGAS_char var_maxChar_69478 = temp_11.readProperty_value () ;
            GALGAS_uint var_index_69543 = GALGAS_uint (uint32_t (0U)) ;
            GALGAS_uint var_length_69568 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2255)) ;
            GALGAS_bool var_found_69601 = GALGAS_bool (false) ;
            if (var_length_69568.isValid ()) {
              uint32_t variant_69618 = var_length_69568.uintValue () ;
              bool loop_69618 = true ;
              while (loop_69618) {
                GALGAS_bool test_12 = var_found_69601.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2258)) ;
                if (kBoolTrue == test_12.boolEnum ()) {
                  test_12 = GALGAS_bool (kIsStrictInf, var_index_69543.objectCompare (var_length_69568)) ;
                }
                loop_69618 = test_12.isValid () ;
                if (loop_69618) {
                  loop_69618 = test_12.boolValue () ;
                }
                if (loop_69618 && (0 == variant_69618)) {
                  loop_69618 = false ;
                  inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2257)) ;
                }
                if (loop_69618) {
                  variant_69618 -- ;
                  GALGAS_char var_currentChar_69696 = this->mProperty_value.getter_characterAtIndex (var_index_69543, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2259)) ;
                  enumGalgasBool test_13 = kBoolTrue ;
                  if (kBoolTrue == test_13) {
                    GALGAS_bool test_14 = GALGAS_bool (kIsSupOrEqual, var_currentChar_69696.objectCompare (var_minChar_69407)) ;
                    if (kBoolTrue == test_14.boolEnum ()) {
                      test_14 = GALGAS_bool (kIsInfOrEqual, var_currentChar_69696.objectCompare (var_maxChar_69478)) ;
                    }
                    test_13 = test_14.boolEnum () ;
                    if (kBoolTrue == test_13) {
                      var_found_69601 = GALGAS_bool (true) ;
                    }
                  }
                  if (kBoolFalse == test_13) {
                    var_index_69543.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2263)) ;
                  }
                }
              }
            }
            GALGAS_bigint temp_15 ;
            const enumGalgasBool test_16 = var_found_69601.boolEnum () ;
            if (kBoolTrue == test_16) {
              temp_15 = var_index_69543.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }else if (kBoolFalse == test_16) {
              temp_15 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }
            result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)), temp_15  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2266)) ;
          }
        }
        if (kBoolFalse == test_9) {
          enumGalgasBool test_17 = kBoolTrue ;
          if (kBoolTrue == test_17) {
            test_17 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("containsChar"))).boolEnum () ;
            if (kBoolTrue == test_17) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272)) ;
              }
              GALGAS_gtlChar temp_18 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr ())) {
                  temp_18 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr () ;
                }else{
                  inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2273)) ;
                }
              }
              GALGAS_char var_lookedUpChar_70128 = temp_18.readProperty_value () ;
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)), this->mProperty_value.getter_containsCharacter (var_lookedUpChar_70128 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2274)) ;
            }
          }
          if (kBoolFalse == test_17) {
            enumGalgasBool test_19 = kBoolTrue ;
            if (kBoolTrue == test_19) {
              test_19 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("containsCharInRange"))).boolEnum () ;
              if (kBoolTrue == test_19) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)) ;
                }
                GALGAS_gtlChar temp_20 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr ())) {
                    temp_20 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281)) ;
                  }
                }
                GALGAS_char var_minChar_70455 = temp_20.readProperty_value () ;
                GALGAS_gtlChar temp_21 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr ())) {
                    temp_21 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2282)) ;
                  }
                }
                GALGAS_char var_maxChar_70526 = temp_21.readProperty_value () ;
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2285)), this->mProperty_value.getter_containsCharacterInRange (var_minChar_70455, var_maxChar_70526 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2286))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2283)) ;
              }
            }
            if (kBoolFalse == test_19) {
              enumGalgasBool test_22 = kBoolTrue ;
              if (kBoolTrue == test_22) {
                test_22 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("HTMLRepresentation"))).boolEnum () ;
                if (kBoolTrue == test_22) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)) ;
                  }
                  result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2291)), this->mProperty_value.getter_HTMLRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2291))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2290)) ;
                }
              }
              if (kBoolFalse == test_22) {
                enumGalgasBool test_23 = kBoolTrue ;
                if (kBoolTrue == test_23) {
                  test_23 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("identifierRepresentation"))).boolEnum () ;
                  if (kBoolTrue == test_23) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2296)), this->mProperty_value.getter_identifierRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2295)) ;
                  }
                }
                if (kBoolFalse == test_23) {
                  enumGalgasBool test_24 = kBoolTrue ;
                  if (kBoolTrue == test_24) {
                    test_24 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("fileExists"))).boolEnum () ;
                    if (kBoolTrue == test_24) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)) ;
                      }
                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2301)), this->mProperty_value.getter_fileExists (SOURCE_FILE ("gtl_data_types.galgas", 2301))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2300)) ;
                    }
                  }
                  if (kBoolFalse == test_24) {
                    enumGalgasBool test_25 = kBoolTrue ;
                    if (kBoolTrue == test_25) {
                      test_25 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("lowercaseString"))).boolEnum () ;
                      if (kBoolTrue == test_25) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)) ;
                        }
                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2306)), this->mProperty_value.getter_lowercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2306))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2305)) ;
                      }
                    }
                    if (kBoolFalse == test_25) {
                      enumGalgasBool test_26 = kBoolTrue ;
                      if (kBoolTrue == test_26) {
                        test_26 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("length"))).boolEnum () ;
                        if (kBoolTrue == test_26) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2309)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2309)) ;
                          }
                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2311)), this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2311)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2311))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2310)) ;
                        }
                      }
                      if (kBoolFalse == test_26) {
                        enumGalgasBool test_27 = kBoolTrue ;
                        if (kBoolTrue == test_27) {
                          GALGAS_bool test_28 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("capitalized"))) ;
                          if (kBoolTrue != test_28.boolEnum ()) {
                            test_28 = GALGAS_bool (kIsEqual, GALGAS_string ("stringByCapitalizingFirstCharacter").objectCompare (constinArgument_methodName.readProperty_string ())) ;
                          }
                          test_27 = test_28.boolEnum () ;
                          if (kBoolTrue == test_27) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)) ;
                            }
                            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2317)), this->mProperty_value.getter_stringByCapitalizingFirstCharacter (SOURCE_FILE ("gtl_data_types.galgas", 2317))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2316)) ;
                          }
                        }
                        if (kBoolFalse == test_27) {
                          enumGalgasBool test_29 = kBoolTrue ;
                          if (kBoolTrue == test_29) {
                            test_29 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("uppercaseString"))).boolEnum () ;
                            if (kBoolTrue == test_29) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)) ;
                              }
                              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2322)), this->mProperty_value.getter_uppercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2322))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2321)) ;
                            }
                          }
                          if (kBoolFalse == test_29) {
                            enumGalgasBool test_30 = kBoolTrue ;
                            if (kBoolTrue == test_30) {
                              test_30 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
                              if (kBoolTrue == test_30) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)) ;
                                }
                                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2327)), this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2327)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2327))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)) ;
                              }
                            }
                            if (kBoolFalse == test_30) {
                              enumGalgasBool test_31 = kBoolTrue ;
                              if (kBoolTrue == test_31) {
                                test_31 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                if (kBoolTrue == test_31) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2330)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2330)) ;
                                  }
                                  GALGAS_gtlString temp_32 ;
                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).isValid ()) {
                                    if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr ())) {
                                      temp_32 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr () ;
                                    }else{
                                      inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2331)) ;
                                    }
                                  }
                                  GALGAS_string var_subString_72679 = temp_32.readProperty_value () ;
                                  GALGAS_uint var_subStringLength_72760 = var_subString_72679.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2332)) ;
                                  GALGAS_uint var_start_72797 = GALGAS_uint (uint32_t (0U)) ;
                                  GALGAS_uint var_stop_72820 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2334)).substract_operation (var_subStringLength_72760, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2334)) ;
                                  GALGAS_bool var_exists_72872 = GALGAS_bool (false) ;
                                  if (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2336)).isValid ()) {
                                    uint32_t variant_72890 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2336)).uintValue () ;
                                    bool loop_72890 = true ;
                                    while (loop_72890) {
                                      GALGAS_bool test_33 = var_exists_72872.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2337)) ;
                                      if (kBoolTrue == test_33.boolEnum ()) {
                                        test_33 = GALGAS_bool (kIsInfOrEqual, var_start_72797.objectCompare (var_stop_72820)) ;
                                      }
                                      loop_72890 = test_33.isValid () ;
                                      if (loop_72890) {
                                        loop_72890 = test_33.boolValue () ;
                                      }
                                      if (loop_72890 && (0 == variant_72890)) {
                                        loop_72890 = false ;
                                        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2336)) ;
                                      }
                                      if (loop_72890) {
                                        variant_72890 -- ;
                                        enumGalgasBool test_34 = kBoolTrue ;
                                        if (kBoolTrue == test_34) {
                                          test_34 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_subString (var_start_72797, var_subStringLength_72760 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2338)).objectCompare (var_subString_72679)).boolEnum () ;
                                          if (kBoolTrue == test_34) {
                                            var_exists_72872 = GALGAS_bool (true) ;
                                          }
                                        }
                                        var_start_72797.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2341)) ;
                                      }
                                    }
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2344)), var_exists_72872  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)) ;
                                }
                              }
                              if (kBoolFalse == test_31) {
                                enumGalgasBool test_35 = kBoolTrue ;
                                if (kBoolTrue == test_35) {
                                  test_35 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("leftSubString"))).boolEnum () ;
                                  if (kBoolTrue == test_35) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2347)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2347)) ;
                                    }
                                    GALGAS_gtlInt temp_36 ;
                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).isValid ()) {
                                      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr ())) {
                                        temp_36 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr () ;
                                      }else{
                                        inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                      }
                                    }
                                    GALGAS_uint var_index_73302 = temp_36.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350)), this->mProperty_value.getter_leftSubString (var_index_73302 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)) ;
                                  }
                                }
                                if (kBoolFalse == test_35) {
                                  enumGalgasBool test_37 = kBoolTrue ;
                                  if (kBoolTrue == test_37) {
                                    test_37 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("rightSubString"))).boolEnum () ;
                                    if (kBoolTrue == test_37) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2353)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2353)) ;
                                      }
                                      GALGAS_gtlInt temp_38 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).isValid ()) {
                                        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr ())) {
                                          temp_38 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                        }
                                      }
                                      GALGAS_uint var_index_73599 = temp_38.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)), this->mProperty_value.getter_rightSubString (var_index_73599 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_37) {
                                    enumGalgasBool test_39 = kBoolTrue ;
                                    if (kBoolTrue == test_39) {
                                      test_39 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subString"))).boolEnum () ;
                                      if (kBoolTrue == test_39) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2359)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2359)) ;
                                        }
                                        GALGAS_gtlInt temp_40 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).isValid ()) {
                                          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr ())) {
                                            temp_40 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)) ;
                                          }
                                        }
                                        GALGAS_uint var_start_73896 = temp_40.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2360)) ;
                                        GALGAS_gtlInt temp_41 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).isValid ()) {
                                          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr ())) {
                                            temp_41 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                          }
                                        }
                                        GALGAS_uint var_length_73972 = temp_41.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363)), this->mProperty_value.getter_subString (var_start_73896, var_length_73972 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2362)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_39) {
                                      enumGalgasBool test_42 = kBoolTrue ;
                                      if (kBoolTrue == test_42) {
                                        test_42 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("reversedString"))).boolEnum () ;
                                        if (kBoolTrue == test_42) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)) ;
                                          }
                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2368)), this->mProperty_value.getter_reversedString (SOURCE_FILE ("gtl_data_types.galgas", 2368))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_42) {
                                        enumGalgasBool test_43 = kBoolTrue ;
                                        if (kBoolTrue == test_43) {
                                          test_43 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("componentsSeparatedByString"))).boolEnum () ;
                                          if (kBoolTrue == test_43) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)) ;
                                            }
                                            GALGAS_gtlString temp_44 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).isValid ()) {
                                              if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr ())) {
                                                temp_44 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)) ;
                                              }
                                            }
                                            GALGAS_string var_separator_74510 = temp_44.readProperty_value () ;
                                            GALGAS_stringlist var_stringlist_74592 = this->mProperty_value.getter_componentsSeparatedByString (var_separator_74510 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2373)) ;
                                            GALGAS_list var_components_74662 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2374)) ;
                                            cEnumerator_stringlist enumerator_74688 (var_stringlist_74592, kENUMERATION_UP) ;
                                            while (enumerator_74688.hasCurrentObject ()) {
                                              var_components_74662.addAssign_operation (GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2377)), enumerator_74688.current_mValue (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376)) ;
                                              enumerator_74688.gotoNextObject () ;
                                            }
                                            result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2381)), var_components_74662  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2380)) ;
                                          }
                                        }
                                        if (kBoolFalse == test_43) {
                                          enumGalgasBool test_45 = kBoolTrue ;
                                          if (kBoolTrue == test_45) {
                                            test_45 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("interpretEscape"))).boolEnum () ;
                                            if (kBoolTrue == test_45) {
                                              TC_Array <C_FixItDescription> fixItArray46 ;
                                              inCompiler->emitSemanticWarning (constinArgument_methodName.readProperty_location (), GALGAS_string ("deprecated method"), fixItArray46  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2384)) ;
                                              const GALGAS_gtlString temp_47 = this ;
                                              result_result = temp_47 ;
                                            }
                                          }
                                          if (kBoolFalse == test_45) {
                                            enumGalgasBool test_48 = kBoolTrue ;
                                            if (kBoolTrue == test_48) {
                                              test_48 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("columnPrefixedBy"))).boolEnum () ;
                                              if (kBoolTrue == test_48) {
                                                {
                                                routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)) ;
                                                }
                                                GALGAS_gtlString temp_49 ;
                                                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).isValid ()) {
                                                  if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr ())) {
                                                    temp_49 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr () ;
                                                  }else{
                                                    inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2388)) ;
                                                  }
                                                }
                                                GALGAS_string var_prefix_75159 = temp_49.readProperty_value () ;
                                                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)), var_prefix_75159.add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\n").add_operation (var_prefix_75159, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2389)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_48) {
                                              enumGalgasBool test_50 = kBoolTrue ;
                                              if (kBoolTrue == test_50) {
                                                test_50 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("wrap"))).boolEnum () ;
                                                if (kBoolTrue == test_50) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2395)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2395)) ;
                                                  }
                                                  GALGAS_gtlInt temp_51 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).isValid ()) {
                                                    if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr ())) {
                                                      temp_51 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_width_75500 = temp_51.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2396)) ;
                                                  GALGAS_gtlInt temp_52 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).isValid ()) {
                                                    if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr ())) {
                                                      temp_52 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_shift_75575 = temp_52.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                  GALGAS_string var_stringShift_75658 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_shift_75575  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2398)) ;
                                                  GALGAS_stringlist var_paragraphs_75739 = this->mProperty_value.getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2399)) ;
                                                  GALGAS_stringlist var_resultParagraphs_75820 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2400)) ;
                                                  cEnumerator_stringlist enumerator_75854 (var_paragraphs_75739, kENUMERATION_UP) ;
                                                  while (enumerator_75854.hasCurrentObject ()) {
                                                    GALGAS_stringlist var_words_75900 = enumerator_75854.current_mValue (HERE).getter_componentsSeparatedByString (GALGAS_string (" ") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2402)) ;
                                                    GALGAS_uint var_lineWidth_75969 = GALGAS_uint (uint32_t (0U)) ;
                                                    GALGAS_string var_line_75992 = GALGAS_string::makeEmptyString () ;
                                                    cEnumerator_stringlist enumerator_76013 (var_words_75900, kENUMERATION_UP) ;
                                                    while (enumerator_76013.hasCurrentObject ()) {
                                                      enumGalgasBool test_53 = kBoolTrue ;
                                                      if (kBoolTrue == test_53) {
                                                        test_53 = GALGAS_bool (kIsNotEqual, enumerator_76013.current_mValue (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                                                        if (kBoolTrue == test_53) {
                                                          enumGalgasBool test_54 = kBoolTrue ;
                                                          if (kBoolTrue == test_54) {
                                                            test_54 = GALGAS_bool (kIsStrictSup, var_lineWidth_75969.add_operation (enumerator_76013.current_mValue (HERE).getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2407)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2407)).objectCompare (var_width_75500)).boolEnum () ;
                                                            if (kBoolTrue == test_54) {
                                                              var_line_75992.plusAssign_operation(GALGAS_string ("\n").add_operation (var_stringShift_75658, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2408)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2408)) ;
                                                              var_lineWidth_75969 = var_shift_75575 ;
                                                            }
                                                          }
                                                          var_lineWidth_75969.plusAssign_operation(enumerator_76013.current_mValue (HERE).getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2411)).add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2411)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2411)) ;
                                                          var_line_75992.plusAssign_operation(enumerator_76013.current_mValue (HERE).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)) ;
                                                        }
                                                      }
                                                      enumerator_76013.gotoNextObject () ;
                                                    }
                                                    var_resultParagraphs_75820.addAssign_operation (var_line_75992  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2415)) ;
                                                    enumerator_75854.gotoNextObject () ;
                                                  }
                                                  result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)), GALGAS_string::constructor_componentsJoinedByString (var_resultParagraphs_75820, GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2417)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_50) {
                                                enumGalgasBool test_55 = kBoolTrue ;
                                                if (kBoolTrue == test_55) {
                                                  test_55 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("replaceString"))).boolEnum () ;
                                                  if (kBoolTrue == test_55) {
                                                    {
                                                    routine_argumentsCheck (constinArgument_methodName, function_stringStringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)) ;
                                                    }
                                                    GALGAS_gtlString temp_56 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).isValid ()) {
                                                      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr ())) {
                                                        temp_56 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_find_76624 = temp_56.readProperty_value () ;
                                                    GALGAS_gtlString temp_57 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).isValid ()) {
                                                      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr ())) {
                                                        temp_57 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2425)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_rep_76695 = temp_57.readProperty_value () ;
                                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)), this->mProperty_value.getter_stringByReplacingStringByString (var_find_76624, var_rep_76695, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2429))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2426)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_55) {
                                                  enumGalgasBool test_58 = kBoolTrue ;
                                                  if (kBoolTrue == test_58) {
                                                    test_58 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                                    if (kBoolTrue == test_58) {
                                                      {
                                                      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2432)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2432)) ;
                                                      }
                                                      GALGAS_gtlString temp_59 ;
                                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).isValid ()) {
                                                        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr ())) {
                                                          temp_59 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr () ;
                                                        }else{
                                                          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                        }
                                                      }
                                                      GALGAS_string var_subString_77034 = callExtensionGetter_string ((const cPtr_gtlString *) temp_59.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                      GALGAS_uint var_subLength_77110 = var_subString_77034.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2434)) ;
                                                      GALGAS_uint var_start_77147 = GALGAS_uint (uint32_t (0U)) ;
                                                      GALGAS_uint var_stop_77170 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2436)).substract_operation (var_subLength_77110, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2436)) ;
                                                      GALGAS_bool var_exists_77216 = GALGAS_bool (false) ;
                                                      if (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2438)).isValid ()) {
                                                        uint32_t variant_77233 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2438)).uintValue () ;
                                                        bool loop_77233 = true ;
                                                        while (loop_77233) {
                                                          loop_77233 = GALGAS_bool (kIsInfOrEqual, var_start_77147.objectCompare (var_stop_77170)).operator_and (var_exists_77216.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2439)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2439)).isValid () ;
                                                          if (loop_77233) {
                                                            loop_77233 = GALGAS_bool (kIsInfOrEqual, var_start_77147.objectCompare (var_stop_77170)).operator_and (var_exists_77216.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2439)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2439)).boolValue () ;
                                                          }
                                                          if (loop_77233 && (0 == variant_77233)) {
                                                            loop_77233 = false ;
                                                            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2438)) ;
                                                          }
                                                          if (loop_77233) {
                                                            variant_77233 -- ;
                                                            enumGalgasBool test_60 = kBoolTrue ;
                                                            if (kBoolTrue == test_60) {
                                                              test_60 = GALGAS_bool (kIsEqual, this->mProperty_value.getter_subString (var_start_77147, var_subLength_77110 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2440)).objectCompare (var_subString_77034)).boolEnum () ;
                                                              if (kBoolTrue == test_60) {
                                                                var_exists_77216 = GALGAS_bool (true) ;
                                                              }
                                                            }
                                                            var_start_77147.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2443)) ;
                                                          }
                                                        }
                                                      }
                                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2447)), var_exists_77216  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2445)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_58) {
                                                    enumGalgasBool test_61 = kBoolTrue ;
                                                    if (kBoolTrue == test_61) {
                                                      test_61 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("envVarExists"))).boolEnum () ;
                                                      if (kBoolTrue == test_61) {
                                                        {
                                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2451)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2451)) ;
                                                        }
                                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2454)), this->mProperty_value.getter_doesEnvironmentVariableExist (SOURCE_FILE ("gtl_data_types.galgas", 2455))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2452)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_61) {
                                                      enumGalgasBool test_62 = kBoolTrue ;
                                                      if (kBoolTrue == test_62) {
                                                        test_62 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("envVar"))).boolEnum () ;
                                                        if (kBoolTrue == test_62) {
                                                          {
                                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2458)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2458)) ;
                                                          }
                                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2461)), GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2462))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2459)) ;
                                                        }
                                                      }
                                                      if (kBoolFalse == test_62) {
                                                        enumGalgasBool test_63 = kBoolTrue ;
                                                        if (kBoolTrue == test_63) {
                                                          test_63 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                          if (kBoolTrue == test_63) {
                                                            {
                                                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)) ;
                                                            }
                                                            const GALGAS_gtlString temp_64 = this ;
                                                            result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2467)), temp_64.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2467))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2466)) ;
                                                          }
                                                        }
                                                        if (kBoolFalse == test_63) {
                                                          enumGalgasBool test_65 = kBoolTrue ;
                                                          if (kBoolTrue == test_65) {
                                                            test_65 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                            if (kBoolTrue == test_65) {
                                                              {
                                                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)) ;
                                                              }
                                                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2472)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2471)) ;
                                                            }
                                                          }
                                                          if (kBoolFalse == test_65) {
                                                            enumGalgasBool test_66 = kBoolTrue ;
                                                            if (kBoolTrue == test_66) {
                                                              test_66 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                              if (kBoolTrue == test_66) {
                                                                {
                                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)) ;
                                                                }
                                                                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2477)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2476)) ;
                                                              }
                                                            }
                                                            if (kBoolFalse == test_66) {
                                                              enumGalgasBool test_67 = kBoolTrue ;
                                                              if (kBoolTrue == test_67) {
                                                                test_67 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2479)).boolEnum () ;
                                                                if (kBoolTrue == test_67) {
                                                                  const GALGAS_gtlString temp_68 = this ;
                                                                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2480)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_68, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2480)) ;
                                                                }
                                                              }
                                                              if (kBoolFalse == test_67) {
                                                                enumGalgasBool test_69 = kBoolTrue ;
                                                                if (kBoolTrue == test_69) {
                                                                  test_69 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                  if (kBoolTrue == test_69) {
                                                                    {
                                                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)) ;
                                                                    }
                                                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2490)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2490))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2489)) ;
                                                                  }
                                                                }
                                                                if (kBoolFalse == test_69) {
                                                                  enumGalgasBool test_70 = kBoolTrue ;
                                                                  if (kBoolTrue == test_70) {
                                                                    test_70 = GALGAS_bool (kIsEqual, GALGAS_string ("files").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                    if (kBoolTrue == test_70) {
                                                                      {
                                                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2493)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2493)) ;
                                                                      }
                                                                      GALGAS_stringlist var_fileList_79084 = this->mProperty_value.getter_regularFiles (GALGAS_bool (false) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2494)) ;
                                                                      GALGAS_lstringset var_files_79136 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2495)) ;
                                                                      cEnumerator_stringlist enumerator_79162 (var_fileList_79084, kENUMERATION_UP) ;
                                                                      while (enumerator_79162.hasCurrentObject ()) {
                                                                        {
                                                                        var_files_79136.setter_put (GALGAS_lstring::constructor_new (enumerator_79162.current_mValue (HERE), constinArgument_methodName.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2497)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2497)) ;
                                                                        }
                                                                        enumerator_79162.gotoNextObject () ;
                                                                      }
                                                                      result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2500)), var_files_79136  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2499)) ;
                                                                    }
                                                                  }
                                                                  if (kBoolFalse == test_70) {
                                                                    enumGalgasBool test_71 = kBoolTrue ;
                                                                    if (kBoolTrue == test_71) {
                                                                      test_71 = GALGAS_bool (kIsEqual, GALGAS_string ("filesWithExtensions").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                                      if (kBoolTrue == test_71) {
                                                                        {
                                                                        routine_argumentsCheck (constinArgument_methodName, function_setArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)) ;
                                                                        }
                                                                        GALGAS_stringlist var_extensions_79473 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2504)) ;
                                                                        GALGAS_gtlSet temp_72 ;
                                                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).isValid ()) {
                                                                          if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr ())) {
                                                                            temp_72 = (cPtr_gtlSet *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr () ;
                                                                          }else{
                                                                            inCompiler->castError ("gtlSet", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)) ;
                                                                          }
                                                                        }
                                                                        cEnumerator_lstringset enumerator_79499 (temp_72.readProperty_value (), kENUMERATION_UP) ;
                                                                        while (enumerator_79499.hasCurrentObject ()) {
                                                                          var_extensions_79473.addAssign_operation (enumerator_79499.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2506)) ;
                                                                          enumerator_79499.gotoNextObject () ;
                                                                        }
                                                                        GALGAS_stringlist var_fileList_79624 = this->mProperty_value.getter_regularFilesWithExtensions (GALGAS_bool (false), var_extensions_79473 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2508)) ;
                                                                        GALGAS_lstringset var_files_79702 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2509)) ;
                                                                        cEnumerator_stringlist enumerator_79728 (var_fileList_79624, kENUMERATION_UP) ;
                                                                        while (enumerator_79728.hasCurrentObject ()) {
                                                                          {
                                                                          var_files_79702.setter_put (GALGAS_lstring::constructor_new (enumerator_79728.current_mValue (HERE), constinArgument_methodName.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)) ;
                                                                          }
                                                                          enumerator_79728.gotoNextObject () ;
                                                                        }
                                                                        result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2514)), var_files_79702  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)) ;
                                                                      }
                                                                    }
                                                                    if (kBoolFalse == test_71) {
                                                                      TC_Array <C_FixItDescription> fixItArray73 ;
                                                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)), fixItArray73  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)) ;
                                                                      result_result.drop () ; // Release error dropped variable
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlString performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlString_performSetter (cPtr_gtlData * inObject,
                                                     const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlString * object = (cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2532)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2532)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2533)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2533)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2533)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2533)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2533)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_80506 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_80506.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2534)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2534)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2537)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2537)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("setCharAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2540)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2540)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2541)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2541)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2541)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2541)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2541)) ;
            }
          }
          GALGAS_char var_charToSet_80866 = temp_4.readProperty_value () ;
          GALGAS_gtlInt temp_5 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2542)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2542)).ptr ())) {
              temp_5 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2542)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2542)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2542)) ;
            }
          }
          GALGAS_uint var_index_80935 = temp_5.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2542)) ;
          {
          object->mProperty_value.setter_setCharacterAtIndex (var_charToSet_80866, var_index_80935, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2543)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("insertCharAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_6) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2546)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2546)) ;
            }
            GALGAS_gtlChar temp_7 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2547)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2547)).ptr ())) {
                temp_7 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2547)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2547)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2547)) ;
              }
            }
            GALGAS_char var_charToInsert_81202 = temp_7.readProperty_value () ;
            GALGAS_gtlInt temp_8 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2548)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2548)).ptr ())) {
                temp_8 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2548)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2548)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2548)) ;
              }
            }
            GALGAS_uint var_index_81271 = temp_8.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2548)) ;
            {
            object->mProperty_value.setter_insertCharacterAtIndex (var_charToInsert_81202, var_index_81271, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2549)) ;
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_9 = kBoolTrue ;
          if (kBoolTrue == test_9) {
            test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("removeCharAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_9) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2552)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2552)) ;
              }
              GALGAS_gtlInt temp_10 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).ptr ())) {
                  temp_10 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)) ;
                }
              }
              GALGAS_uint var_index_81532 = temp_10.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)) ;
              {
              GALGAS_char joker_81625 ; // Joker input parameter
              object->mProperty_value.setter_removeCharacterAtIndex (joker_81625, var_index_81532, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)) ;
              }
              object->mProperty_where = constinArgument_methodName.readProperty_location () ;
            }
          }
          if (kBoolFalse == test_9) {
            enumGalgasBool test_11 = kBoolTrue ;
            if (kBoolTrue == test_11) {
              test_11 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2556)).boolEnum () ;
              if (kBoolTrue == test_11) {
                const GALGAS_gtlString temp_12 = object ;
                GALGAS_gtlData var_copy_81729 = temp_12 ;
                callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2558)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_81729, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2558)) ;
                GALGAS_gtlString temp_13 ;
                if (var_copy_81729.isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlString *> (var_copy_81729.ptr ())) {
                    temp_13 = (cPtr_gtlString *) var_copy_81729.ptr () ;
                  }else{
                    inCompiler->castError ("gtlString", var_copy_81729.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2565)) ;
                  }
                }
                object->mProperty_value = temp_13.readProperty_value () ;
                object->mProperty_where = var_copy_81729.readProperty_where () ;
                object->mProperty_meta = var_copy_81729.readProperty_meta () ;
              }
            }
            if (kBoolFalse == test_11) {
              TC_Array <C_FixItDescription> fixItArray14 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)), fixItArray14  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2569)) ;
            }
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlString_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                      extensionSetter_gtlString_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlString_performSetter (defineExtensionSetter_gtlString_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2582)).add_operation (GALGAS_string ("boolean: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2582)).add_operation (this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2583)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2583)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2583)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_string (C_Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2586)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlBool::getter_lstring (C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (this->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2589)), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2589)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlBool::getter_bool (C_Compiler */* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlBool::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_bigint temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2597)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2597)) ;
  }
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlBool::getter_float (C_Compiler */* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  GALGAS_double temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_double (1) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_double (0) ;
  }
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2605)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2609)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2613)), this->mProperty_value.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2613))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2613)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2617)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2621)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2625)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2629)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2633)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2641)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2640)), this->mProperty_value.operator_and (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2641))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2638)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2644)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2653)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2652)), this->mProperty_value.operator_or (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2653))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2650)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2656)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2665)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2664)), this->mProperty_value.operator_xor (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2665))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2662)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2668)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2673)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2677)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2685)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2684)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2682)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2688)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2697)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2696)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2694)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2700)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2709)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2708)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2706)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2712)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2721)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2720)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2718)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2724)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2733)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2732)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2730)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2736)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2745)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2744)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2742)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2748)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlBool::getter_embeddedType (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bool) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBool addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBool::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2759))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2759)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlBool::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("trueOrFalse"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2773)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2773)) ;
      }
      GALGAS_string temp_1 ;
      const enumGalgasBool test_2 = this->mProperty_value.boolEnum () ;
      if (kBoolTrue == test_2) {
        temp_1 = GALGAS_string ("true") ;
      }else if (kBoolFalse == test_2) {
        temp_1 = GALGAS_string ("false") ;
      }
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2776)), temp_1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2774)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("string"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2780)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2780)) ;
        }
        const GALGAS_gtlBool temp_4 = this ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2783)), callExtensionGetter_string ((const cPtr_gtlBool *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2784))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2781)) ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("yesOrNo"))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2787)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2787)) ;
          }
          GALGAS_string temp_6 ;
          const enumGalgasBool test_7 = this->mProperty_value.boolEnum () ;
          if (kBoolTrue == test_7) {
            temp_6 = GALGAS_string ("yes") ;
          }else if (kBoolFalse == test_7) {
            temp_6 = GALGAS_string ("no") ;
          }
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2790)), temp_6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2788)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("TRUEOrFALSE"))).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2794)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2794)) ;
            }
            GALGAS_string temp_9 ;
            const enumGalgasBool test_10 = this->mProperty_value.boolEnum () ;
            if (kBoolTrue == test_10) {
              temp_9 = GALGAS_string ("TRUE") ;
            }else if (kBoolFalse == test_10) {
              temp_9 = GALGAS_string ("FALSE") ;
            }
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2797)), temp_9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2795)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("YESOrNO"))).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2801)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2801)) ;
              }
              GALGAS_string temp_12 ;
              const enumGalgasBool test_13 = this->mProperty_value.boolEnum () ;
              if (kBoolTrue == test_13) {
                temp_12 = GALGAS_string ("YES") ;
              }else if (kBoolFalse == test_13) {
                temp_12 = GALGAS_string ("NO") ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2804)), temp_12  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2802)) ;
            }
          }
          if (kBoolFalse == test_11) {
            enumGalgasBool test_14 = kBoolTrue ;
            if (kBoolTrue == test_14) {
              GALGAS_bool test_15 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("int"))) ;
              if (kBoolTrue != test_15.boolEnum ()) {
                test_15 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("unsigned"))) ;
              }
              test_14 = test_15.boolEnum () ;
              if (kBoolTrue == test_14) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2808)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2808)) ;
                }
                GALGAS_bigint temp_16 ;
                const enumGalgasBool test_17 = this->mProperty_value.boolEnum () ;
                if (kBoolTrue == test_17) {
                  temp_16 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2812)) ;
                }else if (kBoolFalse == test_17) {
                  temp_16 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2812)) ;
                }
                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2811)), temp_16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2809)) ;
              }
            }
            if (kBoolFalse == test_14) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_18) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2815)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2815)) ;
                  }
                  const GALGAS_gtlBool temp_19 = this ;
                  result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2817)), temp_19.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2817))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2816)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2820)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2820)) ;
                    }
                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2822)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2821)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2825)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2825)) ;
                      }
                      result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2827)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2826)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_22 = kBoolTrue ;
                    if (kBoolTrue == test_22) {
                      test_22 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2829)).boolEnum () ;
                      if (kBoolTrue == test_22) {
                        const GALGAS_gtlBool temp_23 = this ;
                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_23, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)) ;
                      }
                    }
                    if (kBoolFalse == test_22) {
                      enumGalgasBool test_24 = kBoolTrue ;
                      if (kBoolTrue == test_24) {
                        test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_24) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2838)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2838)) ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2840)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2840))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2839)) ;
                        }
                      }
                      if (kBoolFalse == test_24) {
                        TC_Array <C_FixItDescription> fixItArray25 ;
                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2843)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2843)), fixItArray25  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2843)) ;
                        result_result.drop () ; // Release error dropped variable
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlBool performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlBool_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlBool * object = (cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2858)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2858)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2859)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_90162 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_90162.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2860)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2860)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2863)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2863)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2865)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlBool temp_4 = object ;
          GALGAS_gtlData var_copy_90458 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2867)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_90458, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2867)) ;
          GALGAS_gtlBool temp_5 ;
          if (var_copy_90458.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlBool *> (var_copy_90458.ptr ())) {
              temp_5 = (cPtr_gtlBool *) var_copy_90458.ptr () ;
            }else{
              inCompiler->castError ("gtlBool", var_copy_90458.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2874)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_90458.readProperty_where () ;
          object->mProperty_meta = var_copy_90458.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2878)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2878)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2878)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlBool_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                      extensionSetter_gtlBool_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlBool_performSetter (defineExtensionSetter_gtlBool_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_desc (const GALGAS_uint constinArgument_tab,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2902)).add_operation (GALGAS_string ("set: @!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2902)) ;
  cEnumerator_lstringset enumerator_91658 (this->mProperty_value, kENUMERATION_UP) ;
  const bool bool_0 = true ;
  if (enumerator_91658.hasCurrentObject () && bool_0) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2906))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2906)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2906)) ;
    while (enumerator_91658.hasCurrentObject () && bool_0) {
      result_result.plusAssign_operation(enumerator_91658.current_lkey (HERE).readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2908)) ;
      enumerator_91658.gotoNextObject () ;
      if (enumerator_91658.hasCurrentObject () && bool_0) {
        result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2910)) ;
      }
    }
    result_result.plusAssign_operation(GALGAS_string ("\n"), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2912)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2914)).add_operation (GALGAS_string ("!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2914)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2914)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_string (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2918)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlSet::getter_lstring (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2922)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlSet::getter_bool (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2926)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlSet::getter_int (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2930)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlSet::getter_float (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a set to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2934)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_plusOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2938)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_minusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2942)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_notOp (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2946)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_lstringset var_set_92832 = this->mProperty_value ;
  GALGAS_lstring var_element_92863 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2951)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_set_92832.getter_hasKey (var_element_92863.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2952)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_set_92832.setter_del (var_element_92863, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2953)) ;
      }
    }
  }
  {
  var_set_92832.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2955)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2955)) ;
  }
  result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2956)), var_set_92832  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2956)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_93160 = this->mProperty_value ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2962)) ;
        }
      }
      cEnumerator_lstringset enumerator_93182 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_93182.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_93160.getter_hasKey (enumerator_93182.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2963)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_93160.setter_del (enumerator_93182.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2964)) ;
            }
          }
        }
        enumerator_93182.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2968)), var_resultSet_93160  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2967)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2971)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2971)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2976)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2980)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2984)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_93927 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2989)) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2990)) ;
        }
      }
      cEnumerator_lstringset enumerator_93957 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_93957.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = this->mProperty_value.getter_hasKey (enumerator_93957.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2991)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_93927.setter_put (enumerator_93957.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2992)) ;
            }
          }
        }
        enumerator_93957.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2996)), var_resultSet_93927  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2995)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2999)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2999)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3005)) ;
        }
      }
      GALGAS_lstringset var_resultSet_94339 = temp_1.readProperty_value () ;
      cEnumerator_lstringset enumerator_94383 (this->mProperty_value, kENUMERATION_UP) ;
      while (enumerator_94383.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_94339.getter_hasKey (enumerator_94383.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3007)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3007)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_94339.setter_put (enumerator_94383.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3008)) ;
            }
          }
        }
        enumerator_94383.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3012)), var_resultSet_94339  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3011)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3015)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3015)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3020)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3024)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3028)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3034)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3034)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3033)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3037)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3037)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3044)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3044)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3043)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3047)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3047)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_gtlSet temp_2 ;
        if (constinArgument_right.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
            temp_2 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
          }else{
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3053)) ;
          }
        }
        test_1 = GALGAS_bool (kIsEqual, temp_2.readProperty_value ().objectCompare (this->mProperty_value)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3054)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3054)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_bool var_included_95741 = GALGAS_bool (true) ;
        GALGAS_gtlSet temp_3 ;
        if (constinArgument_right.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
            temp_3 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
          }else{
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3057)) ;
          }
        }
        cEnumerator_lstringset enumerator_95763 (temp_3.readProperty_value (), kENUMERATION_UP) ;
        bool bool_4 = var_included_95741.isValidAndTrue () ;
        if (enumerator_95763.hasCurrentObject () && bool_4) {
          while (enumerator_95763.hasCurrentObject () && bool_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = this->mProperty_value.getter_hasKey (enumerator_95763.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3058)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3058)).boolEnum () ;
              if (kBoolTrue == test_5) {
                var_included_95741 = GALGAS_bool (false) ;
              }
            }
            enumerator_95763.gotoNextObject () ;
            if (enumerator_95763.hasCurrentObject ()) {
              bool_4 = var_included_95741.isValidAndTrue () ;
            }
          }
        }
        result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3060)), var_included_95741  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3060)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3063)), GALGAS_string ("set expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3063)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}



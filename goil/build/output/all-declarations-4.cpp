#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-4.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'objectsForKind'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind function_objectsForKind (const GALGAS_objectsMap & constinArgument_objects,
                                           const GALGAS_string & constinArgument_kind,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKind result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 116)).boolEnum () ;
  if (kBoolTrue == test_0) {
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)), result_result, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 119))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 119)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectsForKind [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectsForKind (C_Compiler * inCompiler,
                                                               const cObjectArray & inEffectiveParameterArray,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectsForKind (operand0,
                                  operand1,
                                  inCompiler
                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectsForKind ("objectsForKind",
                                                                functionWithGenericHeader_objectsForKind,
                                                                & kTypeDescriptor_GALGAS_objectKind,
                                                                2,
                                                                functionArgs_objectsForKind) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'listInOS'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_listInOS (const GALGAS_objectsMap & constinArgument_objects,
                                         const GALGAS_string & constinArgument_attributeName,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_items ; // Returned variable
  GALGAS_object_5F_t var_itemsContainer_3252 ;
  GALGAS_objectAttributes var_os_3275 = function_osObject (constinArgument_objects, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 128)) ;
  var_os_3275.getter_objectParams (SOURCE_FILE ("goil_types_root.galgas", 129)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)), var_itemsContainer_3252, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)) ;
  result_items = function_multipleAttributeOrError (var_itemsContainer_3252, constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 130)) ;
//---
  return result_items ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_listInOS [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_listInOS (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_listInOS (operand0,
                            operand1,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_listInOS ("listInOS",
                                                          functionWithGenericHeader_listInOS,
                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                          2,
                                                          functionArgs_listInOS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'generate_signed_type'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_signed_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                         GALGAS_string inArgument_err,
                                         GALGAS_string & outArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_s_38__1049 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 7U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 37)) ;
  GALGAS_uint_36__34_ var_max_5F_s_31__36__1078 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 15U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 38)) ;
  GALGAS_uint_36__34_ var_max_5F_s_33__32__1107 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 31U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 39)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38__1049)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("s8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36__1078)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("s16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32__1107)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("s32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'generate_unsigned_type'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_unsigned_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                           GALGAS_string inArgument_err,
                                           GALGAS_string & outArgument_type,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1496 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 8U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 62)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1525 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 16U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 63)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1554 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 32U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 64)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38__1496)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36__1525)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32__1554)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'generate_mask_type'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_mask_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                       GALGAS_string inArgument_err,
                                       GALGAS_string & outArgument_type,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1937 = GALGAS_uint_36__34_ ((uint64_t) 8ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1961 = GALGAS_uint_36__34_ ((uint64_t) 16ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1985 = GALGAS_uint_36__34_ ((uint64_t) 32ULL) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38__1937)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36__1961)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32__1985)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'emptyGoilContext'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext function_emptyGoilContext (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_goilContext result_context ; // Returned variable
  result_context = GALGAS_goilContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 710)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string (".gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 714)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 715)), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 716))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 709)) ;
//---
  return result_context ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyGoilContext [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyGoilContext (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_emptyGoilContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyGoilContext ("emptyGoilContext",
                                                                  functionWithGenericHeader_emptyGoilContext,
                                                                  & kTypeDescriptor_GALGAS_goilContext,
                                                                  0,
                                                                  functionArgs_emptyGoilContext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'generate_all'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_all (GALGAS_gtlData inArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir_23384 = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 733)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir_23384.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_target_23462 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_target_23462.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_gtlTemplateInstruction var_rootTemplateInstruction_23635 = GALGAS_gtlTemplateInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 741)), GALGAS_string::makeEmptyString (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 743)), GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 745)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 747)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 748)), GALGAS_string (gOption_goil_5F_options_root.getter_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 744)), GALGAS_bool (false), GALGAS_bool (true), GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 754)), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 755))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 740)) ;
      GALGAS_gtlContext var_context_24197 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 758)) ;
      {
      var_context_24197.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 759)) ;
      }
      {
      var_context_24197.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 762)) ;
      }
      {
      var_context_24197.insulate (HERE) ;
      cPtr_gtlContext * ptr_24413 = (cPtr_gtlContext *) var_context_24197.ptr () ;
      callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_24413, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 766)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 765)) ;
      }
      {
      var_context_24197.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 769)) ;
      }
      GALGAS_library var_lib_24641 = function_emptyLib (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 773)) ;
      GALGAS_string var_goilLog_24684 = GALGAS_string::makeEmptyString () ;
      callExtensionMethod_execute ((const cPtr_gtlTemplateInstruction *) var_rootTemplateInstruction_23635.ptr (), var_context_24197, inArgument_cfg, var_lib_24641, var_goilLog_24684, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 776)) ;
      const enumGalgasBool test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_goilLog_24684.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 784)) ;
      }
    }else if (kBoolFalse == test_1) {
      inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 804)) ;
    }
  }else if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 807)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_applicationDefinition::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_applicationDefinition) ;
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_cpuDescription.objectCompare (p->mAttribute_cpuDescription) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_version.objectCompare (p->mAttribute_version) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_versionDescription.objectCompare (p->mAttribute_versionDescription) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_objects.objectCompare (p->mAttribute_objects) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_applicationDefinition::objectCompare (const GALGAS_applicationDefinition & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition::GALGAS_applicationDefinition (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition GALGAS_applicationDefinition::constructor_default (LOCATION_ARGS) {
  return GALGAS_applicationDefinition::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_objectsMap::constructor_emptyMap (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition::GALGAS_applicationDefinition (const cPtr_applicationDefinition * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_applicationDefinition) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition GALGAS_applicationDefinition::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                            const GALGAS_lstring & inAttribute_cpuDescription,
                                                                            const GALGAS_lstring & inAttribute_version,
                                                                            const GALGAS_lstring & inAttribute_versionDescription,
                                                                            const GALGAS_objectsMap & inAttribute_objects
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  if (inAttribute_name.isValid () && inAttribute_cpuDescription.isValid () && inAttribute_version.isValid () && inAttribute_versionDescription.isValid () && inAttribute_objects.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_applicationDefinition (inAttribute_name, inAttribute_cpuDescription, inAttribute_version, inAttribute_versionDescription, inAttribute_objects COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_cpuDescription (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_cpuDescription ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_cpuDescription (UNUSED_LOCATION_ARGS) const {
  return mAttribute_cpuDescription ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_version (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_version ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_version (UNUSED_LOCATION_ARGS) const {
  return mAttribute_version ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_versionDescription (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_versionDescription ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_versionDescription (UNUSED_LOCATION_ARGS) const {
  return mAttribute_versionDescription ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_applicationDefinition::getter_objects (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectsMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_objects ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap cPtr_applicationDefinition::getter_objects (UNUSED_LOCATION_ARGS) const {
  return mAttribute_objects ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::setter_setName (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_name = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::setter_setName (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_name = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::setter_setCpuDescription (GALGAS_lstring inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_cpuDescription = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::setter_setCpuDescription (GALGAS_lstring inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_cpuDescription = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::setter_setVersion (GALGAS_lstring inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_version = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::setter_setVersion (GALGAS_lstring inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_version = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::setter_setVersionDescription (GALGAS_lstring inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_versionDescription = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::setter_setVersionDescription (GALGAS_lstring inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_versionDescription = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::setter_setObjects (GALGAS_objectsMap inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_objects = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::setter_setObjects (GALGAS_objectsMap inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_objects = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @applicationDefinition class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_applicationDefinition::cPtr_applicationDefinition (const GALGAS_lstring & in_name,
                                                        const GALGAS_lstring & in_cpuDescription,
                                                        const GALGAS_lstring & in_version,
                                                        const GALGAS_lstring & in_versionDescription,
                                                        const GALGAS_objectsMap & in_objects
                                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_name (in_name),
mAttribute_cpuDescription (in_cpuDescription),
mAttribute_version (in_version),
mAttribute_versionDescription (in_versionDescription),
mAttribute_objects (in_objects) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_applicationDefinition::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_applicationDefinition ;
}

void cPtr_applicationDefinition::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@applicationDefinition:" ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_cpuDescription.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_version.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_versionDescription.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_objects.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_applicationDefinition::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_applicationDefinition (mAttribute_name, mAttribute_cpuDescription, mAttribute_version, mAttribute_versionDescription, mAttribute_objects COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @applicationDefinition type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_applicationDefinition ("applicationDefinition",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_applicationDefinition::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_applicationDefinition ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_applicationDefinition::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_applicationDefinition (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition GALGAS_applicationDefinition::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  const GALGAS_applicationDefinition * p = (const GALGAS_applicationDefinition *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_applicationDefinition *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("applicationDefinition", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_attributeRange::objectCompare (const GALGAS_attributeRange & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange::GALGAS_attributeRange (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange::GALGAS_attributeRange (const cPtr_attributeRange * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_attributeRange) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_attributeRange::getter_location (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_attributeRange * p = (const cPtr_attributeRange *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_attributeRange) ;
    result = p->mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_attributeRange::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @attributeRange class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_attributeRange::cPtr_attributeRange (const GALGAS_location & in_location
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_location (in_location) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @attributeRange type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_attributeRange ("attributeRange",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_attributeRange::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_attributeRange ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_attributeRange::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_attributeRange (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange GALGAS_attributeRange::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_attributeRange result ;
  const GALGAS_attributeRange * p = (const GALGAS_attributeRange *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_attributeRange *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("attributeRange", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_floatAttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_floatAttributeMinMax::objectCompare (const GALGAS_floatAttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                       GALGAS_double::constructor_default (HERE),
                                                       GALGAS_double::constructor_default (HERE)
                                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (const cPtr_floatAttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                          const GALGAS_double & inAttribute_min,
                                                                          const GALGAS_double & inAttribute_max
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_floatAttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @floatAttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_floatAttributeMinMax::cPtr_floatAttributeMinMax (const GALGAS_location & in_location,
                                                      const GALGAS_double & in_min,
                                                      const GALGAS_double & in_max
                                                      COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_floatAttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

void cPtr_floatAttributeMinMax::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@floatAttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_floatAttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_floatAttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @floatAttributeMinMax type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeMinMax ("floatAttributeMinMax",
                                             & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatAttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatAttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  const GALGAS_floatAttributeMinMax * p = (const GALGAS_floatAttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatAttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_floatAttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeSet * p = (const cPtr_floatAttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_floatAttributeSet::objectCompare (const GALGAS_floatAttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet::GALGAS_floatAttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_floatList::constructor_emptyList (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet::GALGAS_floatAttributeSet (const cPtr_floatAttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                    const GALGAS_floatList & inAttribute_valueList
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_floatAttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatAttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_floatList result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeSet * p = (const cPtr_floatAttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList cPtr_floatAttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @floatAttributeSet class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_floatAttributeSet::cPtr_floatAttributeSet (const GALGAS_location & in_location,
                                                const GALGAS_floatList & in_valueList
                                                COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_floatAttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeSet ;
}

void cPtr_floatAttributeSet::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@floatAttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_floatAttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_floatAttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @floatAttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeSet ("floatAttributeSet",
                                          & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatAttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatAttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeSet result ;
  const GALGAS_floatAttributeSet * p = (const GALGAS_floatAttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatAttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_noRange::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_noRange * p = (const cPtr_noRange *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_noRange) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_noRange::objectCompare (const GALGAS_noRange & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange::GALGAS_noRange (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange GALGAS_noRange::constructor_default (LOCATION_ARGS) {
  return GALGAS_noRange::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange::GALGAS_noRange (const cPtr_noRange * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_noRange) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange GALGAS_noRange::constructor_new (const GALGAS_location & inAttribute_location
                                                COMMA_LOCATION_ARGS) {
  GALGAS_noRange result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_noRange (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @noRange class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_noRange::cPtr_noRange (const GALGAS_location & in_location
                            COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_noRange::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noRange ;
}

void cPtr_noRange::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@noRange:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_noRange::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_noRange (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @noRange type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_noRange ("noRange",
                                & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_noRange::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noRange ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_noRange::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_noRange (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange GALGAS_noRange::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_noRange result ;
  const GALGAS_noRange * p = (const GALGAS_noRange *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_noRange *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("noRange", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_33__32_AttributeMinMax::objectCompare (const GALGAS_sint_33__32_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint::constructor_default (HERE),
                                                              GALGAS_sint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (const cPtr_sint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_sint & inAttribute_min,
                                                                                        const GALGAS_sint & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @sint32AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_33__32_AttributeMinMax::cPtr_sint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint & in_min,
                                                                    const GALGAS_sint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

void cPtr_sint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint32AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @sint32AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ("sint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  const GALGAS_sint_33__32_AttributeMinMax * p = (const GALGAS_sint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_33__32_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeSet * p = (const cPtr_sint_33__32_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_33__32_AttributeSet::objectCompare (const GALGAS_sint_33__32_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet::GALGAS_sint_33__32_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_sint_33__32_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet::GALGAS_sint_33__32_AttributeSet (const cPtr_sint_33__32_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_sint_33__32_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeSet * p = (const cPtr_sint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List cPtr_sint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @sint32AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_33__32_AttributeSet::cPtr_sint_33__32_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_sint_33__32_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ;
}

void cPtr_sint_33__32_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@sint32AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_33__32_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @sint32AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ("sint32AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeSet result ;
  const GALGAS_sint_33__32_AttributeSet * p = (const GALGAS_sint_33__32_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_36__34_AttributeMinMax::objectCompare (const GALGAS_sint_36__34_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (const cPtr_sint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_min,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @sint64AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_36__34_AttributeMinMax::cPtr_sint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint_36__34_ & in_min,
                                                                    const GALGAS_sint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

void cPtr_sint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint64AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @sint64AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ("sint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  const GALGAS_sint_36__34_AttributeMinMax * p = (const GALGAS_sint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_36__34_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeSet * p = (const cPtr_sint_36__34_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_36__34_AttributeSet::objectCompare (const GALGAS_sint_36__34_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet::GALGAS_sint_36__34_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_sint_36__34_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet::GALGAS_sint_36__34_AttributeSet (const cPtr_sint_36__34_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_sint_36__34_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeSet * p = (const cPtr_sint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List cPtr_sint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @sint64AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_36__34_AttributeSet::cPtr_sint_36__34_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_sint_36__34_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ;
}

void cPtr_sint_36__34_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@sint64AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_36__34_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @sint64AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ("sint64AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeSet result ;
  const GALGAS_sint_36__34_AttributeSet * p = (const GALGAS_sint_36__34_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_33__32_AttributeMinMax::objectCompare (const GALGAS_uint_33__32_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax::GALGAS_uint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_uint::constructor_default (HERE),
                                                              GALGAS_uint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax::GALGAS_uint_33__32_AttributeMinMax (const cPtr_uint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_uint & inAttribute_min,
                                                                                        const GALGAS_uint & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_uint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_uint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @uint32AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_33__32_AttributeMinMax::cPtr_uint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_uint & in_min,
                                                                    const GALGAS_uint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ;
}

void cPtr_uint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@uint32AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_33__32_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @uint32AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ("uint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeMinMax result ;
  const GALGAS_uint_33__32_AttributeMinMax * p = (const GALGAS_uint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_33__32_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32_AttributeSet * p = (const cPtr_uint_33__32_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_33__32_AttributeSet::objectCompare (const GALGAS_uint_33__32_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet::GALGAS_uint_33__32_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_uint_33__32_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet::GALGAS_uint_33__32_AttributeSet (const cPtr_uint_33__32_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_uint_33__32_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32_AttributeSet * p = (const cPtr_uint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List cPtr_uint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @uint32AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_33__32_AttributeSet::cPtr_uint_33__32_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_uint_33__32_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_33__32_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ;
}

void cPtr_uint_33__32_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@uint32AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_33__32_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_33__32_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @uint32AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ("uint32AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeSet result ;
  const GALGAS_uint_33__32_AttributeSet * p = (const GALGAS_uint_33__32_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_36__34_AttributeMinMax::objectCompare (const GALGAS_uint_36__34_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax::GALGAS_uint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_uint_36__34_::constructor_default (HERE),
                                                              GALGAS_uint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax::GALGAS_uint_36__34_AttributeMinMax (const cPtr_uint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_uint_36__34_ & inAttribute_min,
                                                                                        const GALGAS_uint_36__34_ & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cPtr_uint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cPtr_uint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @uint64AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_36__34_AttributeMinMax::cPtr_uint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_uint_36__34_ & in_min,
                                                                    const GALGAS_uint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ;
}

void cPtr_uint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@uint64AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @uint64AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ("uint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeMinMax result ;
  const GALGAS_uint_36__34_AttributeMinMax * p = (const GALGAS_uint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_36__34_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34_AttributeSet * p = (const cPtr_uint_36__34_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_36__34_AttributeSet::objectCompare (const GALGAS_uint_36__34_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet::GALGAS_uint_36__34_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_uint_36__34_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet::GALGAS_uint_36__34_AttributeSet (const cPtr_uint_36__34_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_uint_36__34_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34_AttributeSet * p = (const cPtr_uint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List cPtr_uint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @uint64AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_36__34_AttributeSet::cPtr_uint_36__34_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_uint_36__34_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_36__34_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ;
}

void cPtr_uint_36__34_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@uint64AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_36__34_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @uint64AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ("uint64AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeSet result ;
  const GALGAS_uint_36__34_AttributeSet * p = (const GALGAS_uint_36__34_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_autostart_5F_obj::objectCompare (const GALGAS_autostart_5F_obj & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (const cPtr_autostart_5F_obj * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_obj) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_autostart_5F_obj * p = (const cPtr_autostart_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_autostart_5F_obj) ;
    result = p->mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @autostart_obj class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_obj::cPtr_autostart_5F_obj (const GALGAS_location & in_location
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_location (in_location) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @autostart_obj type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_obj ("autostart_obj",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_obj ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_obj (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj GALGAS_autostart_5F_obj::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_obj result ;
  const GALGAS_autostart_5F_obj * p = (const GALGAS_autostart_5F_obj *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_obj *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_obj", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_autostart_5F_false::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_false * p = (const cPtr_autostart_5F_false *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_false) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_autostart_5F_false::objectCompare (const GALGAS_autostart_5F_false & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (void) :
GALGAS_autostart_5F_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_false::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (const cPtr_autostart_5F_false * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_false) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_new (const GALGAS_location & inAttribute_location
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_false (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @autostart_false class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_false::cPtr_autostart_5F_false (const GALGAS_location & in_location
                                                  COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_autostart_5F_false::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

void cPtr_autostart_5F_false::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@autostart_false:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_autostart_5F_false::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_autostart_5F_false (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @autostart_false type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_false ("autostart_false",
                                           & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_false::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_false::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_false (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  const GALGAS_autostart_5F_false * p = (const GALGAS_autostart_5F_false *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_false *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_false", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_autostart_5F_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_void * p = (const cPtr_autostart_5F_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_void) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_autostart_5F_void::objectCompare (const GALGAS_autostart_5F_void & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (void) :
GALGAS_autostart_5F_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_void::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (const cPtr_autostart_5F_void * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_void) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_new (const GALGAS_location & inAttribute_location
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_void (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @autostart_void class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_void::cPtr_autostart_5F_void (const GALGAS_location & in_location
                                                COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_autostart_5F_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

void cPtr_autostart_5F_void::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@autostart_void:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_autostart_5F_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_autostart_5F_void (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @autostart_void type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_void ("autostart_void",
                                          & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_void::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_void (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  const GALGAS_autostart_5F_void * p = (const GALGAS_autostart_5F_void *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_debuggerContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_debuggerContext) ;
  if (kOperandEqual == result) {
    result = mAttribute_debugActive.objectCompare (p->mAttribute_debugActive) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_breakOnNext.objectCompare (p->mAttribute_breakOnNext) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_loopOnCommand.objectCompare (p->mAttribute_loopOnCommand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_promptColor.objectCompare (p->mAttribute_promptColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_promptFace.objectCompare (p->mAttribute_promptFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionColor.objectCompare (p->mAttribute_instructionColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionFace.objectCompare (p->mAttribute_instructionFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_outputColor.objectCompare (p->mAttribute_outputColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_outputFace.objectCompare (p->mAttribute_outputFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_warningColor.objectCompare (p->mAttribute_warningColor) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_warningFace.objectCompare (p->mAttribute_warningFace) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doList.objectCompare (p->mAttribute_doList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_breakpoints.objectCompare (p->mAttribute_breakpoints) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionWindow.objectCompare (p->mAttribute_instructionWindow) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_nextInstructionIndex.objectCompare (p->mAttribute_nextInstructionIndex) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionList.objectCompare (p->mAttribute_instructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_contextStack.objectCompare (p->mAttribute_contextStack) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_debuggerContext::objectCompare (const GALGAS_debuggerContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext::GALGAS_debuggerContext (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_debuggerContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_debuggerContext::constructor_new (GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                  GALGAS_gtlBreakpointList::constructor_emptyList (HERE),
                                                  GALGAS_uint::constructor_default (HERE),
                                                  GALGAS_uint::constructor_default (HERE),
                                                  GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                  GALGAS_gtlInstructionListContextStack::constructor_emptyList (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext::GALGAS_debuggerContext (const cPtr_debuggerContext * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_debuggerContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_debuggerContext::constructor_new (const GALGAS_bool & inAttribute_debugActive,
                                                                const GALGAS_bool & inAttribute_breakOnNext,
                                                                const GALGAS_bool & inAttribute_loopOnCommand,
                                                                const GALGAS_string & inAttribute_promptColor,
                                                                const GALGAS_string & inAttribute_promptFace,
                                                                const GALGAS_string & inAttribute_instructionColor,
                                                                const GALGAS_string & inAttribute_instructionFace,
                                                                const GALGAS_string & inAttribute_outputColor,
                                                                const GALGAS_string & inAttribute_outputFace,
                                                                const GALGAS_string & inAttribute_warningColor,
                                                                const GALGAS_string & inAttribute_warningFace,
                                                                const GALGAS_gtlInstructionList & inAttribute_doList,
                                                                const GALGAS_gtlBreakpointList & inAttribute_breakpoints,
                                                                const GALGAS_uint & inAttribute_instructionWindow,
                                                                const GALGAS_uint & inAttribute_nextInstructionIndex,
                                                                const GALGAS_gtlInstructionList & inAttribute_instructionList,
                                                                const GALGAS_gtlInstructionListContextStack & inAttribute_contextStack
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_debuggerContext result ;
  if (inAttribute_debugActive.isValid () && inAttribute_breakOnNext.isValid () && inAttribute_loopOnCommand.isValid () && inAttribute_promptColor.isValid () && inAttribute_promptFace.isValid () && inAttribute_instructionColor.isValid () && inAttribute_instructionFace.isValid () && inAttribute_outputColor.isValid () && inAttribute_outputFace.isValid () && inAttribute_warningColor.isValid () && inAttribute_warningFace.isValid () && inAttribute_doList.isValid () && inAttribute_breakpoints.isValid () && inAttribute_instructionWindow.isValid () && inAttribute_nextInstructionIndex.isValid () && inAttribute_instructionList.isValid () && inAttribute_contextStack.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_debuggerContext (inAttribute_debugActive, inAttribute_breakOnNext, inAttribute_loopOnCommand, inAttribute_promptColor, inAttribute_promptFace, inAttribute_instructionColor, inAttribute_instructionFace, inAttribute_outputColor, inAttribute_outputFace, inAttribute_warningColor, inAttribute_warningFace, inAttribute_doList, inAttribute_breakpoints, inAttribute_instructionWindow, inAttribute_nextInstructionIndex, inAttribute_instructionList, inAttribute_contextStack COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_debugActive (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_debugActive ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_debugActive (UNUSED_LOCATION_ARGS) const {
  return mAttribute_debugActive ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_breakOnNext (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_breakOnNext ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_breakOnNext (UNUSED_LOCATION_ARGS) const {
  return mAttribute_breakOnNext ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_debuggerContext::getter_loopOnCommand (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_loopOnCommand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_debuggerContext::getter_loopOnCommand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_loopOnCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_promptColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_promptColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_promptColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_promptColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_promptFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_promptFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_promptFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_promptFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_instructionColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_instructionColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_instructionFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_instructionFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_outputColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_outputColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_outputColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_outputColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_outputFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_outputFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_outputFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_outputFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_warningColor (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_warningColor ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_warningColor (UNUSED_LOCATION_ARGS) const {
  return mAttribute_warningColor ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_debuggerContext::getter_warningFace (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_warningFace ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_debuggerContext::getter_warningFace (UNUSED_LOCATION_ARGS) const {
  return mAttribute_warningFace ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_debuggerContext::getter_doList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_doList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_debuggerContext::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_debuggerContext::getter_breakpoints (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_breakpoints ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList cPtr_debuggerContext::getter_breakpoints (UNUSED_LOCATION_ARGS) const {
  return mAttribute_breakpoints ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_debuggerContext::getter_instructionWindow (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionWindow ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_debuggerContext::getter_instructionWindow (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionWindow ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_debuggerContext::getter_nextInstructionIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_nextInstructionIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_debuggerContext::getter_nextInstructionIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_nextInstructionIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_debuggerContext::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_instructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_debuggerContext::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_debuggerContext::getter_contextStack (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result ;
  if (NULL != mObjectPtr) {
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    result = p->mAttribute_contextStack ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack cPtr_debuggerContext::getter_contextStack (UNUSED_LOCATION_ARGS) const {
  return mAttribute_contextStack ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setDebugActive (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_debugActive = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setDebugActive (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_debugActive = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setBreakOnNext (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_breakOnNext = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setBreakOnNext (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_breakOnNext = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setLoopOnCommand (GALGAS_bool inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_loopOnCommand = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setLoopOnCommand (GALGAS_bool inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_loopOnCommand = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setPromptColor (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_promptColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setPromptColor (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_promptColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setPromptFace (GALGAS_string inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_promptFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setPromptFace (GALGAS_string inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_promptFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setInstructionColor (GALGAS_string inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_instructionColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setInstructionColor (GALGAS_string inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_instructionColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setInstructionFace (GALGAS_string inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_instructionFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setInstructionFace (GALGAS_string inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_instructionFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setOutputColor (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_outputColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setOutputColor (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_outputColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setOutputFace (GALGAS_string inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_outputFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setOutputFace (GALGAS_string inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_outputFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setWarningColor (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_warningColor = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setWarningColor (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_warningColor = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setWarningFace (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_warningFace = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setWarningFace (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_warningFace = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setInstructionWindow (GALGAS_uint inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_instructionWindow = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setInstructionWindow (GALGAS_uint inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_instructionWindow = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_debuggerContext::setter_setNextInstructionIndex (GALGAS_uint inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mAttribute_nextInstructionIndex = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_debuggerContext::setter_setNextInstructionIndex (GALGAS_uint inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_nextInstructionIndex = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @debuggerContext class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_debuggerContext::cPtr_debuggerContext (const GALGAS_bool & in_debugActive,
                                            const GALGAS_bool & in_breakOnNext,
                                            const GALGAS_bool & in_loopOnCommand,
                                            const GALGAS_string & in_promptColor,
                                            const GALGAS_string & in_promptFace,
                                            const GALGAS_string & in_instructionColor,
                                            const GALGAS_string & in_instructionFace,
                                            const GALGAS_string & in_outputColor,
                                            const GALGAS_string & in_outputFace,
                                            const GALGAS_string & in_warningColor,
                                            const GALGAS_string & in_warningFace,
                                            const GALGAS_gtlInstructionList & in_doList,
                                            const GALGAS_gtlBreakpointList & in_breakpoints,
                                            const GALGAS_uint & in_instructionWindow,
                                            const GALGAS_uint & in_nextInstructionIndex,
                                            const GALGAS_gtlInstructionList & in_instructionList,
                                            const GALGAS_gtlInstructionListContextStack & in_contextStack
                                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_debugActive (in_debugActive),
mAttribute_breakOnNext (in_breakOnNext),
mAttribute_loopOnCommand (in_loopOnCommand),
mAttribute_promptColor (in_promptColor),
mAttribute_promptFace (in_promptFace),
mAttribute_instructionColor (in_instructionColor),
mAttribute_instructionFace (in_instructionFace),
mAttribute_outputColor (in_outputColor),
mAttribute_outputFace (in_outputFace),
mAttribute_warningColor (in_warningColor),
mAttribute_warningFace (in_warningFace),
mAttribute_doList (in_doList),
mAttribute_breakpoints (in_breakpoints),
mAttribute_instructionWindow (in_instructionWindow),
mAttribute_nextInstructionIndex (in_nextInstructionIndex),
mAttribute_instructionList (in_instructionList),
mAttribute_contextStack (in_contextStack) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_debuggerContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debuggerContext ;
}

void cPtr_debuggerContext::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@debuggerContext:" ;
  mAttribute_debugActive.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_breakOnNext.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_loopOnCommand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_promptColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_promptFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_outputColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_outputFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_warningColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_warningFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_breakpoints.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionWindow.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_nextInstructionIndex.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_contextStack.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_debuggerContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_debuggerContext (mAttribute_debugActive, mAttribute_breakOnNext, mAttribute_loopOnCommand, mAttribute_promptColor, mAttribute_promptFace, mAttribute_instructionColor, mAttribute_instructionFace, mAttribute_outputColor, mAttribute_outputFace, mAttribute_warningColor, mAttribute_warningFace, mAttribute_doList, mAttribute_breakpoints, mAttribute_instructionWindow, mAttribute_nextInstructionIndex, mAttribute_instructionList, mAttribute_contextStack COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @debuggerContext type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_debuggerContext ("debuggerContext",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_debuggerContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debuggerContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_debuggerContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_debuggerContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_debuggerContext::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_debuggerContext result ;
  const GALGAS_debuggerContext * p = (const GALGAS_debuggerContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_debuggerContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("debuggerContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlBreakpoint::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
  if (kOperandEqual == result) {
    result = mAttribute_fileName.objectCompare (p->mAttribute_fileName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lineNum.objectCompare (p->mAttribute_lineNum) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlBreakpoint::objectCompare (const GALGAS_gtlBreakpoint & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint::GALGAS_gtlBreakpoint (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint GALGAS_gtlBreakpoint::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpoint::constructor_new (GALGAS_string::constructor_default (HERE),
                                                GALGAS_uint::constructor_default (HERE),
                                                GALGAS_string::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint::GALGAS_gtlBreakpoint (const cPtr_gtlBreakpoint * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint GALGAS_gtlBreakpoint::constructor_new (const GALGAS_string & inAttribute_fileName,
                                                            const GALGAS_uint & inAttribute_lineNum,
                                                            const GALGAS_string & inAttribute_signature
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpoint result ;
  if (inAttribute_fileName.isValid () && inAttribute_lineNum.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpoint (inAttribute_fileName, inAttribute_lineNum, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlBreakpoint::getter_fileName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    result = p->mAttribute_fileName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlBreakpoint::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_fileName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_gtlBreakpoint::getter_lineNum (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    result = p->mAttribute_lineNum ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_gtlBreakpoint::getter_lineNum (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lineNum ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlBreakpoint::getter_signature (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBreakpoint * p = (const cPtr_gtlBreakpoint *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpoint) ;
    result = p->mAttribute_signature ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlBreakpoint::getter_signature (UNUSED_LOCATION_ARGS) const {
  return mAttribute_signature ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @gtlBreakpoint class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlBreakpoint::cPtr_gtlBreakpoint (const GALGAS_string & in_fileName,
                                        const GALGAS_uint & in_lineNum,
                                        const GALGAS_string & in_signature
                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_fileName (in_fileName),
mAttribute_lineNum (in_lineNum),
mAttribute_signature (in_signature) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlBreakpoint::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpoint ;
}

void cPtr_gtlBreakpoint::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@gtlBreakpoint:" ;
  mAttribute_fileName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lineNum.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlBreakpoint::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlBreakpoint (mAttribute_fileName, mAttribute_lineNum, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlBreakpoint type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpoint ("gtlBreakpoint",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBreakpoint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpoint ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBreakpoint::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpoint (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint GALGAS_gtlBreakpoint::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpoint result ;
  const GALGAS_gtlBreakpoint * p = (const GALGAS_gtlBreakpoint *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpoint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpoint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlContext * p = (const cPtr_gtlContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlContext) ;
  if (kOperandEqual == result) {
    result = mAttribute_prefix.objectCompare (p->mAttribute_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_path.objectCompare (p->mAttribute_path) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_templateDirectory.objectCompare (p->mAttribute_templateDirectory) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_templateExtension.objectCompare (p->mAttribute_templateExtension) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_importPath.objectCompare (p->mAttribute_importPath) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_inputVars.objectCompare (p->mAttribute_inputVars) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_debuggerContext.objectCompare (p->mAttribute_debuggerContext) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlContext::objectCompare (const GALGAS_gtlContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext::GALGAS_gtlContext (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext GALGAS_gtlContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlContext::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_stringlist::constructor_emptyList (HERE),
                                             GALGAS_gtlDataList::constructor_emptyList (HERE),
                                             GALGAS_debuggerContext::constructor_default (HERE)
                                             COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext::GALGAS_gtlContext (const cPtr_gtlContext * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext GALGAS_gtlContext::constructor_new (const GALGAS_lstring & inAttribute_prefix,
                                                      const GALGAS_string & inAttribute_path,
                                                      const GALGAS_string & inAttribute_templateDirectory,
                                                      const GALGAS_string & inAttribute_templateExtension,
                                                      const GALGAS_stringlist & inAttribute_importPath,
                                                      const GALGAS_gtlDataList & inAttribute_inputVars,
                                                      const GALGAS_debuggerContext & inAttribute_debuggerContext
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlContext result ;
  if (inAttribute_prefix.isValid () && inAttribute_path.isValid () && inAttribute_templateDirectory.isValid () && inAttribute_templateExtension.isValid () && inAttribute_importPath.isValid () && inAttribute_inputVars.isValid () && inAttribute_debuggerContext.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlContext (inAttribute_prefix, inAttribute_path, inAttribute_templateDirectory, inAttribute_templateExtension, inAttribute_importPath, inAttribute_inputVars, inAttribute_debuggerContext COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlContext::getter_prefix (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlContext::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mAttribute_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlContext::getter_path (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_path ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlContext::getter_path (UNUSED_LOCATION_ARGS) const {
  return mAttribute_path ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlContext::getter_templateDirectory (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_templateDirectory ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlContext::getter_templateDirectory (UNUSED_LOCATION_ARGS) const {
  return mAttribute_templateDirectory ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlContext::getter_templateExtension (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_templateExtension ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlContext::getter_templateExtension (UNUSED_LOCATION_ARGS) const {
  return mAttribute_templateExtension ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_gtlContext::getter_importPath (UNUSED_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_importPath ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist cPtr_gtlContext::getter_importPath (UNUSED_LOCATION_ARGS) const {
  return mAttribute_importPath ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlContext::getter_inputVars (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlDataList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_inputVars ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList cPtr_gtlContext::getter_inputVars (UNUSED_LOCATION_ARGS) const {
  return mAttribute_inputVars ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_gtlContext::getter_debuggerContext (UNUSED_LOCATION_ARGS) const {
  GALGAS_debuggerContext result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mAttribute_debuggerContext ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext cPtr_gtlContext::getter_debuggerContext (UNUSED_LOCATION_ARGS) const {
  return mAttribute_debuggerContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setPrefix (GALGAS_lstring inValue
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mAttribute_prefix = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setPrefix (GALGAS_lstring inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_prefix = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setPath (GALGAS_string inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mAttribute_path = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setPath (GALGAS_string inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_path = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setTemplateDirectory (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mAttribute_templateDirectory = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setTemplateDirectory (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_templateDirectory = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setTemplateExtension (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mAttribute_templateExtension = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setTemplateExtension (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_templateExtension = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setInputVars (GALGAS_gtlDataList inValue
                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mAttribute_inputVars = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setInputVars (GALGAS_gtlDataList inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_inputVars = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setDebuggerContext (GALGAS_debuggerContext inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mAttribute_debuggerContext = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setDebuggerContext (GALGAS_debuggerContext inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_debuggerContext = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlContext class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlContext::cPtr_gtlContext (const GALGAS_lstring & in_prefix,
                                  const GALGAS_string & in_path,
                                  const GALGAS_string & in_templateDirectory,
                                  const GALGAS_string & in_templateExtension,
                                  const GALGAS_stringlist & in_importPath,
                                  const GALGAS_gtlDataList & in_inputVars,
                                  const GALGAS_debuggerContext & in_debuggerContext
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_prefix (in_prefix),
mAttribute_path (in_path),
mAttribute_templateDirectory (in_templateDirectory),
mAttribute_templateExtension (in_templateExtension),
mAttribute_importPath (in_importPath),
mAttribute_inputVars (in_inputVars),
mAttribute_debuggerContext (in_debuggerContext) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContext ;
}

void cPtr_gtlContext::description (C_String & ioString,
                                   const int32_t inIndentation) const {
  ioString << "[@gtlContext:" ;
  mAttribute_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_templateDirectory.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_templateExtension.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_importPath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_inputVars.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_debuggerContext.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlContext (mAttribute_prefix, mAttribute_path, mAttribute_templateDirectory, mAttribute_templateExtension, mAttribute_importPath, mAttribute_inputVars, mAttribute_debuggerContext COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlContext type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlContext ("gtlContext",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext GALGAS_gtlContext::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlContext result ;
  const GALGAS_gtlContext * p = (const GALGAS_gtlContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_goilContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_goilContext * p = (const cPtr_goilContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_goilContext) ;
  if (kOperandEqual == result) {
    result = mAttribute_prefix.objectCompare (p->mAttribute_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_path.objectCompare (p->mAttribute_path) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_templateDirectory.objectCompare (p->mAttribute_templateDirectory) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_templateExtension.objectCompare (p->mAttribute_templateExtension) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_importPath.objectCompare (p->mAttribute_importPath) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_inputVars.objectCompare (p->mAttribute_inputVars) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_debuggerContext.objectCompare (p->mAttribute_debuggerContext) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_goilContext::objectCompare (const GALGAS_goilContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext::GALGAS_goilContext (void) :
GALGAS_gtlContext () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext GALGAS_goilContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_goilContext::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_string::constructor_default (HERE),
                                              GALGAS_string::constructor_default (HERE),
                                              GALGAS_string::constructor_default (HERE),
                                              GALGAS_stringlist::constructor_emptyList (HERE),
                                              GALGAS_gtlDataList::constructor_emptyList (HERE),
                                              GALGAS_debuggerContext::constructor_default (HERE)
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext::GALGAS_goilContext (const cPtr_goilContext * inSourcePtr) :
GALGAS_gtlContext (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_goilContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext GALGAS_goilContext::constructor_new (const GALGAS_lstring & inAttribute_prefix,
                                                        const GALGAS_string & inAttribute_path,
                                                        const GALGAS_string & inAttribute_templateDirectory,
                                                        const GALGAS_string & inAttribute_templateExtension,
                                                        const GALGAS_stringlist & inAttribute_importPath,
                                                        const GALGAS_gtlDataList & inAttribute_inputVars,
                                                        const GALGAS_debuggerContext & inAttribute_debuggerContext
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_goilContext result ;
  if (inAttribute_prefix.isValid () && inAttribute_path.isValid () && inAttribute_templateDirectory.isValid () && inAttribute_templateExtension.isValid () && inAttribute_importPath.isValid () && inAttribute_inputVars.isValid () && inAttribute_debuggerContext.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_goilContext (inAttribute_prefix, inAttribute_path, inAttribute_templateDirectory, inAttribute_templateExtension, inAttribute_importPath, inAttribute_inputVars, inAttribute_debuggerContext COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @goilContext class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_goilContext::cPtr_goilContext (const GALGAS_lstring & in_prefix,
                                    const GALGAS_string & in_path,
                                    const GALGAS_string & in_templateDirectory,
                                    const GALGAS_string & in_templateExtension,
                                    const GALGAS_stringlist & in_importPath,
                                    const GALGAS_gtlDataList & in_inputVars,
                                    const GALGAS_debuggerContext & in_debuggerContext
                                    COMMA_LOCATION_ARGS) :
cPtr_gtlContext (in_prefix, in_path, in_templateDirectory, in_templateExtension, in_importPath, in_inputVars, in_debuggerContext COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_goilContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_goilContext ;
}

void cPtr_goilContext::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@goilContext:" ;
  mAttribute_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_templateDirectory.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_templateExtension.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_importPath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_inputVars.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_debuggerContext.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_goilContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_goilContext (mAttribute_prefix, mAttribute_path, mAttribute_templateDirectory, mAttribute_templateExtension, mAttribute_importPath, mAttribute_inputVars, mAttribute_debuggerContext COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @goilContext type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_goilContext ("goilContext",
                                    & kTypeDescriptor_GALGAS_gtlContext) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_goilContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_goilContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_goilContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_goilContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext GALGAS_goilContext::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_goilContext result ;
  const GALGAS_goilContext * p = (const GALGAS_goilContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_goilContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("goilContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlData::objectCompare (const GALGAS_gtlData & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData::GALGAS_gtlData (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData::GALGAS_gtlData (const cPtr_gtlData * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlData) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlData::getter_where (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlData * p = (const cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    result = p->mAttribute_where ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlData::getter_where (UNUSED_LOCATION_ARGS) const {
  return mAttribute_where ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlData::getter_meta (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlData * p = (const cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    result = p->mAttribute_meta ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlData::getter_meta (UNUSED_LOCATION_ARGS) const {
  return mAttribute_meta ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlData::setter_setWhere (GALGAS_location inValue
                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlData * p = (cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    p->mAttribute_where = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlData::setter_setWhere (GALGAS_location inValue
                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_where = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlData::setter_setMeta (GALGAS_lstring inValue
                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlData * p = (cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    p->mAttribute_meta = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlData::setter_setMeta (GALGAS_lstring inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_meta = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlData class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlData::cPtr_gtlData (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_where (in_where),
mAttribute_meta (in_meta) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlData type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlData ("gtlData",
                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlData::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlData ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlData::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlData (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlData::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  const GALGAS_gtlData * p = (const GALGAS_gtlData *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlData *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlData", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlBool::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBool * p = (const cPtr_gtlBool *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBool) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlBool::objectCompare (const GALGAS_gtlBool & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBool::GALGAS_gtlBool (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBool GALGAS_gtlBool::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                          GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_bool::constructor_default (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBool::GALGAS_gtlBool (const cPtr_gtlBool * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBool GALGAS_gtlBool::constructor_new (const GALGAS_location & inAttribute_where,
                                                const GALGAS_lstring & inAttribute_meta,
                                                const GALGAS_bool & inAttribute_value
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlBool result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBool (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlBool::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBool * p = (const cPtr_gtlBool *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBool) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlBool::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlBool class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlBool::cPtr_gtlBool (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta,
                            const GALGAS_bool & in_value
                            COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlBool::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBool ;
}

void cPtr_gtlBool::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@gtlBool:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlBool::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlBool (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlBool type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBool ("gtlBool",
                                & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBool::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBool ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBool::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBool (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBool GALGAS_gtlBool::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlBool result ;
  const GALGAS_gtlBool * p = (const GALGAS_gtlBool *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBool *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBool", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlChar::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlChar * p = (const cPtr_gtlChar *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlChar) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlChar::objectCompare (const GALGAS_gtlChar & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlChar::GALGAS_gtlChar (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlChar GALGAS_gtlChar::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlChar::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                          GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_char::constructor_default (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlChar::GALGAS_gtlChar (const cPtr_gtlChar * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlChar) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlChar GALGAS_gtlChar::constructor_new (const GALGAS_location & inAttribute_where,
                                                const GALGAS_lstring & inAttribute_meta,
                                                const GALGAS_char & inAttribute_value
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlChar result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlChar (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_char GALGAS_gtlChar::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_char result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlChar * p = (const cPtr_gtlChar *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlChar) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_char cPtr_gtlChar::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlChar::setter_setValue (GALGAS_char inValue
                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlChar * p = (cPtr_gtlChar *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlChar) ;
    p->mAttribute_value = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlChar::setter_setValue (GALGAS_char inValue
                                    COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_value = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlChar class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlChar::cPtr_gtlChar (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta,
                            const GALGAS_char & in_value
                            COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlChar::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlChar ;
}

void cPtr_gtlChar::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@gtlChar:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlChar::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlChar (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlChar type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlChar ("gtlChar",
                                & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlChar::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlChar ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlChar::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlChar (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlChar GALGAS_gtlChar::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlChar result ;
  const GALGAS_gtlChar * p = (const GALGAS_gtlChar *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlChar *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlChar", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlEnum::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlEnum * p = (const cPtr_gtlEnum *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlEnum) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlEnum::objectCompare (const GALGAS_gtlEnum & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEnum::GALGAS_gtlEnum (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEnum GALGAS_gtlEnum::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlEnum::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                          GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEnum::GALGAS_gtlEnum (const cPtr_gtlEnum * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEnum GALGAS_gtlEnum::constructor_new (const GALGAS_location & inAttribute_where,
                                                const GALGAS_lstring & inAttribute_meta,
                                                const GALGAS_string & inAttribute_value
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlEnum result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlEnum (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlEnum::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlEnum * p = (const cPtr_gtlEnum *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlEnum) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlEnum::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlEnum class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlEnum::cPtr_gtlEnum (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta,
                            const GALGAS_string & in_value
                            COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlEnum::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEnum ;
}

void cPtr_gtlEnum::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@gtlEnum:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlEnum::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlEnum (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlEnum type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlEnum ("gtlEnum",
                                & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlEnum::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEnum ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlEnum::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlEnum (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEnum GALGAS_gtlEnum::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlEnum result ;
  const GALGAS_gtlEnum * p = (const GALGAS_gtlEnum *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlEnum *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlEnum", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlFloat::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlFloat * p = (const cPtr_gtlFloat *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlFloat) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlFloat::objectCompare (const GALGAS_gtlFloat & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFloat::GALGAS_gtlFloat (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFloat GALGAS_gtlFloat::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlFloat::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                           GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_double::constructor_default (HERE)
                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFloat::GALGAS_gtlFloat (const cPtr_gtlFloat * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlFloat) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFloat GALGAS_gtlFloat::constructor_new (const GALGAS_location & inAttribute_where,
                                                  const GALGAS_lstring & inAttribute_meta,
                                                  const GALGAS_double & inAttribute_value
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlFloat result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlFloat (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_gtlFloat::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlFloat * p = (const cPtr_gtlFloat *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFloat) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_gtlFloat::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlFloat class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlFloat::cPtr_gtlFloat (const GALGAS_location & in_where,
                              const GALGAS_lstring & in_meta,
                              const GALGAS_double & in_value
                              COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlFloat::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFloat ;
}

void cPtr_gtlFloat::description (C_String & ioString,
                                 const int32_t inIndentation) const {
  ioString << "[@gtlFloat:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlFloat::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlFloat (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlFloat type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFloat ("gtlFloat",
                                 & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlFloat::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFloat ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlFloat::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFloat (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFloat GALGAS_gtlFloat::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlFloat result ;
  const GALGAS_gtlFloat * p = (const GALGAS_gtlFloat *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFloat *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFloat", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlInt::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlInt * p = (const cPtr_gtlInt *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlInt) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlInt::objectCompare (const GALGAS_gtlInt & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInt::GALGAS_gtlInt (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInt GALGAS_gtlInt::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                         GALGAS_lstring::constructor_default (HERE),
                                         GALGAS_bigint::constructor_zero (HERE)
                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInt::GALGAS_gtlInt (const cPtr_gtlInt * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlInt) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInt GALGAS_gtlInt::constructor_new (const GALGAS_location & inAttribute_where,
                                              const GALGAS_lstring & inAttribute_meta,
                                              const GALGAS_bigint & inAttribute_value
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlInt result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlInt (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_gtlInt::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlInt * p = (const cPtr_gtlInt *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInt) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_gtlInt::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInt::setter_setValue (GALGAS_bigint inValue
                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlInt * p = (cPtr_gtlInt *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInt) ;
    p->mAttribute_value = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlInt::setter_setValue (GALGAS_bigint inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_value = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                           Pointer class for @gtlInt class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlInt::cPtr_gtlInt (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_meta,
                          const GALGAS_bigint & in_value
                          COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlInt::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInt ;
}

void cPtr_gtlInt::description (C_String & ioString,
                               const int32_t inIndentation) const {
  ioString << "[@gtlInt:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlInt::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlInt (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlInt type                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInt ("gtlInt",
                               & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInt::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInt ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInt::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInt (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInt GALGAS_gtlInt::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlInt result ;
  const GALGAS_gtlInt * p = (const GALGAS_gtlInt *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInt *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInt", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlList::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlList * p = (const cPtr_gtlList *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlList) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlList::objectCompare (const GALGAS_gtlList & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlList::GALGAS_gtlList (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlList GALGAS_gtlList::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlList::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                          GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_list::constructor_emptyList (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlList::GALGAS_gtlList (const cPtr_gtlList * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlList GALGAS_gtlList::constructor_new (const GALGAS_location & inAttribute_where,
                                                const GALGAS_lstring & inAttribute_meta,
                                                const GALGAS_list & inAttribute_value
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlList result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlList (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_gtlList::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_list result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlList * p = (const cPtr_gtlList *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlList) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list cPtr_gtlList::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlList class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlList::cPtr_gtlList (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta,
                            const GALGAS_list & in_value
                            COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlList::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlList ;
}

void cPtr_gtlList::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@gtlList:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlList::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlList (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlList type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlList ("gtlList",
                                & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlList GALGAS_gtlList::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlList result ;
  const GALGAS_gtlList * p = (const GALGAS_gtlList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlMap::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMap * p = (const cPtr_gtlMap *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMap) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlMap::objectCompare (const GALGAS_gtlMap & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMap::GALGAS_gtlMap (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMap GALGAS_gtlMap::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlMap::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                         GALGAS_lstring::constructor_default (HERE),
                                         GALGAS_gtlVarMap::constructor_emptyMap (HERE)
                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMap::GALGAS_gtlMap (const cPtr_gtlMap * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMap GALGAS_gtlMap::constructor_new (const GALGAS_location & inAttribute_where,
                                              const GALGAS_lstring & inAttribute_meta,
                                              const GALGAS_gtlVarMap & inAttribute_value
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlMap result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMap (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlMap::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlMap * p = (const cPtr_gtlMap *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap cPtr_gtlMap::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlMap::setter_setValue (GALGAS_gtlVarMap inValue
                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlMap * p = (cPtr_gtlMap *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMap) ;
    p->mAttribute_value = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlMap::setter_setValue (GALGAS_gtlVarMap inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_value = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                           Pointer class for @gtlMap class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlMap::cPtr_gtlMap (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_meta,
                          const GALGAS_gtlVarMap & in_value
                          COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlMap::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMap ;
}

void cPtr_gtlMap::description (C_String & ioString,
                               const int32_t inIndentation) const {
  ioString << "[@gtlMap:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlMap::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMap (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlMap type                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMap ("gtlMap",
                               & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMap GALGAS_gtlMap::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlMap result ;
  const GALGAS_gtlMap * p = (const GALGAS_gtlMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSet * p = (const cPtr_gtlSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlSet::objectCompare (const GALGAS_gtlSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSet::GALGAS_gtlSet (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSet GALGAS_gtlSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                         GALGAS_lstring::constructor_default (HERE),
                                         GALGAS_stringset::constructor_emptySet (HERE)
                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSet::GALGAS_gtlSet (const cPtr_gtlSet * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSet GALGAS_gtlSet::constructor_new (const GALGAS_location & inAttribute_where,
                                              const GALGAS_lstring & inAttribute_meta,
                                              const GALGAS_stringset & inAttribute_value
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlSet result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSet (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_gtlSet::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_stringset result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSet * p = (const cPtr_gtlSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSet) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset cPtr_gtlSet::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSet::setter_setValue (GALGAS_stringset inValue
                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlSet * p = (cPtr_gtlSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSet) ;
    p->mAttribute_value = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlSet::setter_setValue (GALGAS_stringset inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_value = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                           Pointer class for @gtlSet class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlSet::cPtr_gtlSet (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_meta,
                          const GALGAS_stringset & in_value
                          COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSet ;
}

void cPtr_gtlSet::description (C_String & ioString,
                               const int32_t inIndentation) const {
  ioString << "[@gtlSet:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSet (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlSet type                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSet ("gtlSet",
                               & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSet GALGAS_gtlSet::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlSet result ;
  const GALGAS_gtlSet * p = (const GALGAS_gtlSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlString::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlString * p = (const cPtr_gtlString *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlString) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlString::objectCompare (const GALGAS_gtlString & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlString::GALGAS_gtlString (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlString GALGAS_gtlString::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlString::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                            GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_string::constructor_default (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlString::GALGAS_gtlString (const cPtr_gtlString * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlString) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlString GALGAS_gtlString::constructor_new (const GALGAS_location & inAttribute_where,
                                                    const GALGAS_lstring & inAttribute_meta,
                                                    const GALGAS_string & inAttribute_value
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlString result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlString (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlString::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlString * p = (const cPtr_gtlString *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlString) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlString::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlString class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlString::cPtr_gtlString (const GALGAS_location & in_where,
                                const GALGAS_lstring & in_meta,
                                const GALGAS_string & in_value
                                COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlString::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlString ;
}

void cPtr_gtlString::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlString:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlString::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlString (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlString type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlString ("gtlString",
                                  & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlString::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlString ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlString::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlString (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlString GALGAS_gtlString::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlString result ;
  const GALGAS_gtlString * p = (const GALGAS_gtlString *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlString *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlString", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlStruct::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlStruct * p = (const cPtr_gtlStruct *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlStruct) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlStruct::objectCompare (const GALGAS_gtlStruct & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct::GALGAS_gtlStruct (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct GALGAS_gtlStruct::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                            GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_gtlVarMap::constructor_emptyMap (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct::GALGAS_gtlStruct (const cPtr_gtlStruct * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlStruct) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct GALGAS_gtlStruct::constructor_new (const GALGAS_location & inAttribute_where,
                                                    const GALGAS_lstring & inAttribute_meta,
                                                    const GALGAS_gtlVarMap & inAttribute_value
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlStruct (inAttribute_where, inAttribute_meta, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlStruct::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlStruct * p = (const cPtr_gtlStruct *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlStruct) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap cPtr_gtlStruct::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlStruct::setter_setValue (GALGAS_gtlVarMap inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlStruct * p = (cPtr_gtlStruct *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlStruct) ;
    p->mAttribute_value = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlStruct::setter_setValue (GALGAS_gtlVarMap inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_value = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlStruct class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlStruct::cPtr_gtlStruct (const GALGAS_location & in_where,
                                const GALGAS_lstring & in_meta,
                                const GALGAS_gtlVarMap & in_value
                                COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlStruct::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlStruct ;
}

void cPtr_gtlStruct::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlStruct:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlStruct::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlStruct (mAttribute_where, mAttribute_meta, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlStruct type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlStruct ("gtlStruct",
                                  & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlStruct::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlStruct ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlStruct::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlStruct (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct GALGAS_gtlStruct::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
  const GALGAS_gtlStruct * p = (const GALGAS_gtlStruct *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlStruct *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlStruct", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlType * p = (const cPtr_gtlType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlType) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlType::objectCompare (const GALGAS_gtlType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlType::GALGAS_gtlType (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlType::GALGAS_gtlType (const cPtr_gtlType * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlType GALGAS_gtlType::constructor_new (const GALGAS_location & inAttribute_where,
                                                const GALGAS_lstring & inAttribute_meta,
                                                const GALGAS_type & inAttribute_type
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlType result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid () && inAttribute_type.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlType (inAttribute_where, inAttribute_meta, inAttribute_type COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlType::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlType * p = (const cPtr_gtlType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlType) ;
    result = p->mAttribute_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cPtr_gtlType::getter_type (UNUSED_LOCATION_ARGS) const {
  return mAttribute_type ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @gtlType class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlType::cPtr_gtlType (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta,
                            const GALGAS_type & in_type
                            COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE),
mAttribute_type (in_type) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlType ;
}

void cPtr_gtlType::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@gtlType:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlType (mAttribute_where, mAttribute_meta, mAttribute_type COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @gtlType type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlType ("gtlType",
                                & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlType GALGAS_gtlType::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlType result ;
  const GALGAS_gtlType * p = (const GALGAS_gtlType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlUnconstructed::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlUnconstructed * p = (const cPtr_gtlUnconstructed *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlUnconstructed) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_meta.objectCompare (p->mAttribute_meta) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlUnconstructed::objectCompare (const GALGAS_gtlUnconstructed & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnconstructed::GALGAS_gtlUnconstructed (void) :
GALGAS_gtlData () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnconstructed GALGAS_gtlUnconstructed::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlUnconstructed::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                   GALGAS_lstring::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnconstructed::GALGAS_gtlUnconstructed (const cPtr_gtlUnconstructed * inSourcePtr) :
GALGAS_gtlData (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlUnconstructed) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnconstructed GALGAS_gtlUnconstructed::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_lstring & inAttribute_meta
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnconstructed result ;
  if (inAttribute_where.isValid () && inAttribute_meta.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlUnconstructed (inAttribute_where, inAttribute_meta COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlUnconstructed class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlUnconstructed::cPtr_gtlUnconstructed (const GALGAS_location & in_where,
                                              const GALGAS_lstring & in_meta
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlData (in_where, in_meta COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlUnconstructed::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnconstructed ;
}

void cPtr_gtlUnconstructed::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlUnconstructed:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_meta.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlUnconstructed::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlUnconstructed (mAttribute_where, mAttribute_meta COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlUnconstructed type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlUnconstructed ("gtlUnconstructed",
                                         & kTypeDescriptor_GALGAS_gtlData) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlUnconstructed::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnconstructed ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlUnconstructed::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlUnconstructed (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnconstructed GALGAS_gtlUnconstructed::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnconstructed result ;
  const GALGAS_gtlUnconstructed * p = (const GALGAS_gtlUnconstructed *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlUnconstructed *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlUnconstructed", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlExecutableEntity::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlExecutableEntity * p = (const cPtr_gtlExecutableEntity *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlExecutableEntity) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_formalArguments.objectCompare (p->mAttribute_formalArguments) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructions.objectCompare (p->mAttribute_instructions) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlExecutableEntity::objectCompare (const GALGAS_gtlExecutableEntity & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExecutableEntity::GALGAS_gtlExecutableEntity (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExecutableEntity GALGAS_gtlExecutableEntity::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlExecutableEntity::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_lstring::constructor_default (HERE),
                                                      GALGAS_gtlArgumentList::constructor_emptyList (HERE),
                                                      GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExecutableEntity::GALGAS_gtlExecutableEntity (const cPtr_gtlExecutableEntity * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExecutableEntity) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExecutableEntity GALGAS_gtlExecutableEntity::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_lstring & inAttribute_name,
                                                                        const GALGAS_gtlArgumentList & inAttribute_formalArguments,
                                                                        const GALGAS_gtlInstructionList & inAttribute_instructions
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlExecutableEntity result ;
  if (inAttribute_where.isValid () && inAttribute_name.isValid () && inAttribute_formalArguments.isValid () && inAttribute_instructions.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlExecutableEntity (inAttribute_where, inAttribute_name, inAttribute_formalArguments, inAttribute_instructions COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlExecutableEntity::getter_where (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExecutableEntity * p = (const cPtr_gtlExecutableEntity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExecutableEntity) ;
    result = p->mAttribute_where ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlExecutableEntity::getter_where (UNUSED_LOCATION_ARGS) const {
  return mAttribute_where ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlExecutableEntity::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExecutableEntity * p = (const cPtr_gtlExecutableEntity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExecutableEntity) ;
    result = p->mAttribute_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlExecutableEntity::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlExecutableEntity::getter_formalArguments (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExecutableEntity * p = (const cPtr_gtlExecutableEntity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExecutableEntity) ;
    result = p->mAttribute_formalArguments ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList cPtr_gtlExecutableEntity::getter_formalArguments (UNUSED_LOCATION_ARGS) const {
  return mAttribute_formalArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlExecutableEntity::getter_instructions (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExecutableEntity * p = (const cPtr_gtlExecutableEntity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExecutableEntity) ;
    result = p->mAttribute_instructions ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlExecutableEntity::getter_instructions (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructions ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlExecutableEntity class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlExecutableEntity::cPtr_gtlExecutableEntity (const GALGAS_location & in_where,
                                                    const GALGAS_lstring & in_name,
                                                    const GALGAS_gtlArgumentList & in_formalArguments,
                                                    const GALGAS_gtlInstructionList & in_instructions
                                                    COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_where (in_where),
mAttribute_name (in_name),
mAttribute_formalArguments (in_formalArguments),
mAttribute_instructions (in_instructions) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlExecutableEntity::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExecutableEntity ;
}

void cPtr_gtlExecutableEntity::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlExecutableEntity:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_formalArguments.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructions.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlExecutableEntity::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlExecutableEntity (mAttribute_where, mAttribute_name, mAttribute_formalArguments, mAttribute_instructions COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlExecutableEntity type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExecutableEntity ("gtlExecutableEntity",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExecutableEntity::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExecutableEntity ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExecutableEntity::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExecutableEntity (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExecutableEntity GALGAS_gtlExecutableEntity::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlExecutableEntity result ;
  const GALGAS_gtlExecutableEntity * p = (const GALGAS_gtlExecutableEntity *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExecutableEntity *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExecutableEntity", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlFunction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlFunction * p = (const cPtr_gtlFunction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlFunction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_formalArguments.objectCompare (p->mAttribute_formalArguments) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructions.objectCompare (p->mAttribute_instructions) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_returnVariable.objectCompare (p->mAttribute_returnVariable) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlFunction::objectCompare (const GALGAS_gtlFunction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction::GALGAS_gtlFunction (void) :
GALGAS_gtlExecutableEntity () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction GALGAS_gtlFunction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlFunction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                              GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_gtlArgumentList::constructor_emptyList (HERE),
                                              GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                              GALGAS_lstring::constructor_default (HERE)
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction::GALGAS_gtlFunction (const cPtr_gtlFunction * inSourcePtr) :
GALGAS_gtlExecutableEntity (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlFunction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction GALGAS_gtlFunction::constructor_new (const GALGAS_location & inAttribute_where,
                                                        const GALGAS_lstring & inAttribute_name,
                                                        const GALGAS_gtlArgumentList & inAttribute_formalArguments,
                                                        const GALGAS_gtlInstructionList & inAttribute_instructions,
                                                        const GALGAS_lstring & inAttribute_returnVariable
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunction result ;
  if (inAttribute_where.isValid () && inAttribute_name.isValid () && inAttribute_formalArguments.isValid () && inAttribute_instructions.isValid () && inAttribute_returnVariable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlFunction (inAttribute_where, inAttribute_name, inAttribute_formalArguments, inAttribute_instructions, inAttribute_returnVariable COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlFunction::getter_returnVariable (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlFunction * p = (const cPtr_gtlFunction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunction) ;
    result = p->mAttribute_returnVariable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlFunction::getter_returnVariable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_returnVariable ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @gtlFunction class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlFunction::cPtr_gtlFunction (const GALGAS_location & in_where,
                                    const GALGAS_lstring & in_name,
                                    const GALGAS_gtlArgumentList & in_formalArguments,
                                    const GALGAS_gtlInstructionList & in_instructions,
                                    const GALGAS_lstring & in_returnVariable
                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExecutableEntity (in_where, in_name, in_formalArguments, in_instructions COMMA_THERE),
mAttribute_returnVariable (in_returnVariable) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlFunction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFunction ;
}

void cPtr_gtlFunction::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@gtlFunction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_formalArguments.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructions.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_returnVariable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlFunction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlFunction (mAttribute_where, mAttribute_name, mAttribute_formalArguments, mAttribute_instructions, mAttribute_returnVariable COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlFunction type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFunction ("gtlFunction",
                                    & kTypeDescriptor_GALGAS_gtlExecutableEntity) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlFunction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFunction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlFunction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFunction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction GALGAS_gtlFunction::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunction result ;
  const GALGAS_gtlFunction * p = (const GALGAS_gtlFunction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFunction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFunction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlGetter::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGetter * p = (const cPtr_gtlGetter *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGetter) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_formalArguments.objectCompare (p->mAttribute_formalArguments) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructions.objectCompare (p->mAttribute_instructions) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_returnVariable.objectCompare (p->mAttribute_returnVariable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_targetType.objectCompare (p->mAttribute_targetType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlGetter::objectCompare (const GALGAS_gtlGetter & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter::GALGAS_gtlGetter (void) :
GALGAS_gtlFunction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter::GALGAS_gtlGetter (const cPtr_gtlGetter * inSourcePtr) :
GALGAS_gtlFunction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter GALGAS_gtlGetter::constructor_new (const GALGAS_location & inAttribute_where,
                                                    const GALGAS_lstring & inAttribute_name,
                                                    const GALGAS_gtlArgumentList & inAttribute_formalArguments,
                                                    const GALGAS_gtlInstructionList & inAttribute_instructions,
                                                    const GALGAS_lstring & inAttribute_returnVariable,
                                                    const GALGAS_type & inAttribute_targetType
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetter result ;
  if (inAttribute_where.isValid () && inAttribute_name.isValid () && inAttribute_formalArguments.isValid () && inAttribute_instructions.isValid () && inAttribute_returnVariable.isValid () && inAttribute_targetType.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGetter (inAttribute_where, inAttribute_name, inAttribute_formalArguments, inAttribute_instructions, inAttribute_returnVariable, inAttribute_targetType COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlGetter::getter_targetType (UNUSED_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlGetter * p = (const cPtr_gtlGetter *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetter) ;
    result = p->mAttribute_targetType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cPtr_gtlGetter::getter_targetType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_targetType ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlGetter class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlGetter::cPtr_gtlGetter (const GALGAS_location & in_where,
                                const GALGAS_lstring & in_name,
                                const GALGAS_gtlArgumentList & in_formalArguments,
                                const GALGAS_gtlInstructionList & in_instructions,
                                const GALGAS_lstring & in_returnVariable,
                                const GALGAS_type & in_targetType
                                COMMA_LOCATION_ARGS) :
cPtr_gtlFunction (in_where, in_name, in_formalArguments, in_instructions, in_returnVariable COMMA_THERE),
mAttribute_targetType (in_targetType) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlGetter::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetter ;
}

void cPtr_gtlGetter::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlGetter:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_formalArguments.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructions.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_returnVariable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_targetType.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlGetter::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGetter (mAttribute_where, mAttribute_name, mAttribute_formalArguments, mAttribute_instructions, mAttribute_returnVariable, mAttribute_targetType COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlGetter type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetter ("gtlGetter",
                                  & kTypeDescriptor_GALGAS_gtlFunction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGetter::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetter ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGetter::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetter (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter GALGAS_gtlGetter::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetter result ;
  const GALGAS_gtlGetter * p = (const GALGAS_gtlGetter *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetter *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetter", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlProcedure::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlProcedure * p = (const cPtr_gtlProcedure *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlProcedure) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_formalArguments.objectCompare (p->mAttribute_formalArguments) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructions.objectCompare (p->mAttribute_instructions) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlProcedure::objectCompare (const GALGAS_gtlProcedure & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure::GALGAS_gtlProcedure (void) :
GALGAS_gtlExecutableEntity () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure GALGAS_gtlProcedure::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlProcedure::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                               GALGAS_lstring::constructor_default (HERE),
                                               GALGAS_gtlArgumentList::constructor_emptyList (HERE),
                                               GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                               COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure::GALGAS_gtlProcedure (const cPtr_gtlProcedure * inSourcePtr) :
GALGAS_gtlExecutableEntity (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlProcedure) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure GALGAS_gtlProcedure::constructor_new (const GALGAS_location & inAttribute_where,
                                                          const GALGAS_lstring & inAttribute_name,
                                                          const GALGAS_gtlArgumentList & inAttribute_formalArguments,
                                                          const GALGAS_gtlInstructionList & inAttribute_instructions
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcedure result ;
  if (inAttribute_where.isValid () && inAttribute_name.isValid () && inAttribute_formalArguments.isValid () && inAttribute_instructions.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlProcedure (inAttribute_where, inAttribute_name, inAttribute_formalArguments, inAttribute_instructions COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @gtlProcedure class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlProcedure::cPtr_gtlProcedure (const GALGAS_location & in_where,
                                      const GALGAS_lstring & in_name,
                                      const GALGAS_gtlArgumentList & in_formalArguments,
                                      const GALGAS_gtlInstructionList & in_instructions
                                      COMMA_LOCATION_ARGS) :
cPtr_gtlExecutableEntity (in_where, in_name, in_formalArguments, in_instructions COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlProcedure::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcedure ;
}

void cPtr_gtlProcedure::description (C_String & ioString,
                                     const int32_t inIndentation) const {
  ioString << "[@gtlProcedure:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_formalArguments.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructions.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlProcedure::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlProcedure (mAttribute_where, mAttribute_name, mAttribute_formalArguments, mAttribute_instructions COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlProcedure type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcedure ("gtlProcedure",
                                     & kTypeDescriptor_GALGAS_gtlExecutableEntity) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlProcedure::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcedure ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlProcedure::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlProcedure (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure GALGAS_gtlProcedure::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcedure result ;
  const GALGAS_gtlProcedure * p = (const GALGAS_gtlProcedure *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlProcedure *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlProcedure", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlSetter::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSetter * p = (const cPtr_gtlSetter *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSetter) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_formalArguments.objectCompare (p->mAttribute_formalArguments) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructions.objectCompare (p->mAttribute_instructions) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_targetType.objectCompare (p->mAttribute_targetType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlSetter::objectCompare (const GALGAS_gtlSetter & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter::GALGAS_gtlSetter (void) :
GALGAS_gtlExecutableEntity () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter::GALGAS_gtlSetter (const cPtr_gtlSetter * inSourcePtr) :
GALGAS_gtlExecutableEntity (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter GALGAS_gtlSetter::constructor_new (const GALGAS_location & inAttribute_where,
                                                    const GALGAS_lstring & inAttribute_name,
                                                    const GALGAS_gtlArgumentList & inAttribute_formalArguments,
                                                    const GALGAS_gtlInstructionList & inAttribute_instructions,
                                                    const GALGAS_type & inAttribute_targetType
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetter result ;
  if (inAttribute_where.isValid () && inAttribute_name.isValid () && inAttribute_formalArguments.isValid () && inAttribute_instructions.isValid () && inAttribute_targetType.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSetter (inAttribute_where, inAttribute_name, inAttribute_formalArguments, inAttribute_instructions, inAttribute_targetType COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlSetter::getter_targetType (UNUSED_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSetter * p = (const cPtr_gtlSetter *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSetter) ;
    result = p->mAttribute_targetType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cPtr_gtlSetter::getter_targetType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_targetType ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlSetter class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlSetter::cPtr_gtlSetter (const GALGAS_location & in_where,
                                const GALGAS_lstring & in_name,
                                const GALGAS_gtlArgumentList & in_formalArguments,
                                const GALGAS_gtlInstructionList & in_instructions,
                                const GALGAS_type & in_targetType
                                COMMA_LOCATION_ARGS) :
cPtr_gtlExecutableEntity (in_where, in_name, in_formalArguments, in_instructions COMMA_THERE),
mAttribute_targetType (in_targetType) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlSetter::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetter ;
}

void cPtr_gtlSetter::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlSetter:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_formalArguments.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructions.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_targetType.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlSetter::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSetter (mAttribute_where, mAttribute_name, mAttribute_formalArguments, mAttribute_instructions, mAttribute_targetType COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlSetter type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetter ("gtlSetter",
                                  & kTypeDescriptor_GALGAS_gtlExecutableEntity) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSetter::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetter ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSetter::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetter (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter GALGAS_gtlSetter::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetter result ;
  const GALGAS_gtlSetter * p = (const GALGAS_gtlSetter *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSetter *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetter", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlExpression::objectCompare (const GALGAS_gtlExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression::GALGAS_gtlExpression (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression::GALGAS_gtlExpression (const cPtr_gtlExpression * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlExpression::getter_where (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExpression * p = (const cPtr_gtlExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExpression) ;
    result = p->mAttribute_where ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlExpression::getter_where (UNUSED_LOCATION_ARGS) const {
  return mAttribute_where ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @gtlExpression class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlExpression::cPtr_gtlExpression (const GALGAS_location & in_where
                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_where (in_where) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlExpression type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpression ("gtlExpression",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpression::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpression result ;
  const GALGAS_gtlExpression * p = (const GALGAS_gtlExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlBinaryExpression::objectCompare (const GALGAS_gtlBinaryExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBinaryExpression::GALGAS_gtlBinaryExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBinaryExpression::GALGAS_gtlBinaryExpression (const cPtr_gtlBinaryExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBinaryExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlBinaryExpression::getter_lSon (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBinaryExpression * p = (const cPtr_gtlBinaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBinaryExpression) ;
    result = p->mAttribute_lSon ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlBinaryExpression::getter_lSon (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lSon ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlBinaryExpression::getter_rSon (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBinaryExpression * p = (const cPtr_gtlBinaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBinaryExpression) ;
    result = p->mAttribute_rSon ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlBinaryExpression::getter_rSon (UNUSED_LOCATION_ARGS) const {
  return mAttribute_rSon ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlBinaryExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlBinaryExpression::cPtr_gtlBinaryExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlExpression & in_lSon,
                                                    const GALGAS_gtlExpression & in_rSon
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_lSon (in_lSon),
mAttribute_rSon (in_rSon) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlBinaryExpression type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBinaryExpression ("gtlBinaryExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBinaryExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBinaryExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBinaryExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBinaryExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBinaryExpression GALGAS_gtlBinaryExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlBinaryExpression result ;
  const GALGAS_gtlBinaryExpression * p = (const GALGAS_gtlBinaryExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBinaryExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBinaryExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlAddExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlAddExpression * p = (const cPtr_gtlAddExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlAddExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlAddExpression::objectCompare (const GALGAS_gtlAddExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAddExpression::GALGAS_gtlAddExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAddExpression::GALGAS_gtlAddExpression (const cPtr_gtlAddExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAddExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAddExpression GALGAS_gtlAddExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlAddExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlAddExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlAddExpression class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlAddExpression::cPtr_gtlAddExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_lSon,
                                              const GALGAS_gtlExpression & in_rSon
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlAddExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAddExpression ;
}

void cPtr_gtlAddExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlAddExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlAddExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlAddExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlAddExpression type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAddExpression ("gtlAddExpression",
                                         & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlAddExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAddExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlAddExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAddExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAddExpression GALGAS_gtlAddExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlAddExpression result ;
  const GALGAS_gtlAddExpression * p = (const GALGAS_gtlAddExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAddExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAddExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlAndExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlAndExpression * p = (const cPtr_gtlAndExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlAndExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlAndExpression::objectCompare (const GALGAS_gtlAndExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAndExpression::GALGAS_gtlAndExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAndExpression::GALGAS_gtlAndExpression (const cPtr_gtlAndExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAndExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAndExpression GALGAS_gtlAndExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlAndExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlAndExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlAndExpression class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlAndExpression::cPtr_gtlAndExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_lSon,
                                              const GALGAS_gtlExpression & in_rSon
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlAndExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAndExpression ;
}

void cPtr_gtlAndExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlAndExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlAndExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlAndExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlAndExpression type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAndExpression ("gtlAndExpression",
                                         & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlAndExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAndExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlAndExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAndExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAndExpression GALGAS_gtlAndExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlAndExpression result ;
  const GALGAS_gtlAndExpression * p = (const GALGAS_gtlAndExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAndExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAndExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlDivideExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDivideExpression * p = (const cPtr_gtlDivideExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDivideExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlDivideExpression::objectCompare (const GALGAS_gtlDivideExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDivideExpression::GALGAS_gtlDivideExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDivideExpression::GALGAS_gtlDivideExpression (const cPtr_gtlDivideExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDivideExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDivideExpression GALGAS_gtlDivideExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlExpression & inAttribute_lSon,
                                                                        const GALGAS_gtlExpression & inAttribute_rSon
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlDivideExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDivideExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlDivideExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlDivideExpression::cPtr_gtlDivideExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlExpression & in_lSon,
                                                    const GALGAS_gtlExpression & in_rSon
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlDivideExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDivideExpression ;
}

void cPtr_gtlDivideExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlDivideExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlDivideExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlDivideExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlDivideExpression type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDivideExpression ("gtlDivideExpression",
                                            & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDivideExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDivideExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDivideExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDivideExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDivideExpression GALGAS_gtlDivideExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDivideExpression result ;
  const GALGAS_gtlDivideExpression * p = (const GALGAS_gtlDivideExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDivideExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDivideExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlEqualExpression * p = (const cPtr_gtlEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlEqualExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlEqualExpression::objectCompare (const GALGAS_gtlEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEqualExpression::GALGAS_gtlEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEqualExpression::GALGAS_gtlEqualExpression (const cPtr_gtlEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlEqualExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEqualExpression GALGAS_gtlEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_gtlExpression & inAttribute_lSon,
                                                                      const GALGAS_gtlExpression & inAttribute_rSon
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlEqualExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlEqualExpression::cPtr_gtlEqualExpression (const GALGAS_location & in_where,
                                                  const GALGAS_gtlExpression & in_lSon,
                                                  const GALGAS_gtlExpression & in_rSon
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEqualExpression ;
}

void cPtr_gtlEqualExpression::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlEqualExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlEqualExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlEqualExpression type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlEqualExpression ("gtlEqualExpression",
                                           & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEqualExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlEqualExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEqualExpression GALGAS_gtlEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlEqualExpression result ;
  const GALGAS_gtlEqualExpression * p = (const GALGAS_gtlEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlGreaterOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGreaterOrEqualExpression * p = (const cPtr_gtlGreaterOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGreaterOrEqualExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlGreaterOrEqualExpression::objectCompare (const GALGAS_gtlGreaterOrEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterOrEqualExpression::GALGAS_gtlGreaterOrEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterOrEqualExpression::GALGAS_gtlGreaterOrEqualExpression (const cPtr_gtlGreaterOrEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGreaterOrEqualExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterOrEqualExpression GALGAS_gtlGreaterOrEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                        const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                        const GALGAS_gtlExpression & inAttribute_rSon
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterOrEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGreaterOrEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlGreaterOrEqualExpression class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlGreaterOrEqualExpression::cPtr_gtlGreaterOrEqualExpression (const GALGAS_location & in_where,
                                                                    const GALGAS_gtlExpression & in_lSon,
                                                                    const GALGAS_gtlExpression & in_rSon
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlGreaterOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ;
}

void cPtr_gtlGreaterOrEqualExpression::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@gtlGreaterOrEqualExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlGreaterOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGreaterOrEqualExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlGreaterOrEqualExpression type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ("gtlGreaterOrEqualExpression",
                                                    & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGreaterOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGreaterOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGreaterOrEqualExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterOrEqualExpression GALGAS_gtlGreaterOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterOrEqualExpression result ;
  const GALGAS_gtlGreaterOrEqualExpression * p = (const GALGAS_gtlGreaterOrEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGreaterOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGreaterOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlGreaterThanExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGreaterThanExpression * p = (const cPtr_gtlGreaterThanExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGreaterThanExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlGreaterThanExpression::objectCompare (const GALGAS_gtlGreaterThanExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterThanExpression::GALGAS_gtlGreaterThanExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterThanExpression::GALGAS_gtlGreaterThanExpression (const cPtr_gtlGreaterThanExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGreaterThanExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterThanExpression GALGAS_gtlGreaterThanExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterThanExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGreaterThanExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlGreaterThanExpression class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlGreaterThanExpression::cPtr_gtlGreaterThanExpression (const GALGAS_location & in_where,
                                                              const GALGAS_gtlExpression & in_lSon,
                                                              const GALGAS_gtlExpression & in_rSon
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlGreaterThanExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterThanExpression ;
}

void cPtr_gtlGreaterThanExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlGreaterThanExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlGreaterThanExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGreaterThanExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlGreaterThanExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGreaterThanExpression ("gtlGreaterThanExpression",
                                                 & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGreaterThanExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterThanExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGreaterThanExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGreaterThanExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGreaterThanExpression GALGAS_gtlGreaterThanExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterThanExpression result ;
  const GALGAS_gtlGreaterThanExpression * p = (const GALGAS_gtlGreaterThanExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGreaterThanExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGreaterThanExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLowerOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLowerOrEqualExpression * p = (const cPtr_gtlLowerOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLowerOrEqualExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLowerOrEqualExpression::objectCompare (const GALGAS_gtlLowerOrEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerOrEqualExpression::GALGAS_gtlLowerOrEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerOrEqualExpression::GALGAS_gtlLowerOrEqualExpression (const cPtr_gtlLowerOrEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLowerOrEqualExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerOrEqualExpression GALGAS_gtlLowerOrEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                    const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                    const GALGAS_gtlExpression & inAttribute_rSon
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerOrEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLowerOrEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlLowerOrEqualExpression class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLowerOrEqualExpression::cPtr_gtlLowerOrEqualExpression (const GALGAS_location & in_where,
                                                                const GALGAS_gtlExpression & in_lSon,
                                                                const GALGAS_gtlExpression & in_rSon
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLowerOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ;
}

void cPtr_gtlLowerOrEqualExpression::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlLowerOrEqualExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLowerOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLowerOrEqualExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlLowerOrEqualExpression type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ("gtlLowerOrEqualExpression",
                                                  & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLowerOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLowerOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLowerOrEqualExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerOrEqualExpression GALGAS_gtlLowerOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerOrEqualExpression result ;
  const GALGAS_gtlLowerOrEqualExpression * p = (const GALGAS_gtlLowerOrEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLowerOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLowerOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLowerThanExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLowerThanExpression * p = (const cPtr_gtlLowerThanExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLowerThanExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLowerThanExpression::objectCompare (const GALGAS_gtlLowerThanExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerThanExpression::GALGAS_gtlLowerThanExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerThanExpression::GALGAS_gtlLowerThanExpression (const cPtr_gtlLowerThanExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLowerThanExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerThanExpression GALGAS_gtlLowerThanExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_lSon,
                                                                              const GALGAS_gtlExpression & inAttribute_rSon
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerThanExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLowerThanExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlLowerThanExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLowerThanExpression::cPtr_gtlLowerThanExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_lSon,
                                                          const GALGAS_gtlExpression & in_rSon
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLowerThanExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerThanExpression ;
}

void cPtr_gtlLowerThanExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlLowerThanExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLowerThanExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLowerThanExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlLowerThanExpression type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLowerThanExpression ("gtlLowerThanExpression",
                                               & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLowerThanExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerThanExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLowerThanExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLowerThanExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLowerThanExpression GALGAS_gtlLowerThanExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerThanExpression result ;
  const GALGAS_gtlLowerThanExpression * p = (const GALGAS_gtlLowerThanExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLowerThanExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLowerThanExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlModulusExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlModulusExpression * p = (const cPtr_gtlModulusExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlModulusExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlModulusExpression::objectCompare (const GALGAS_gtlModulusExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModulusExpression::GALGAS_gtlModulusExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModulusExpression::GALGAS_gtlModulusExpression (const cPtr_gtlModulusExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlModulusExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModulusExpression GALGAS_gtlModulusExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_gtlExpression & inAttribute_lSon,
                                                                          const GALGAS_gtlExpression & inAttribute_rSon
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlModulusExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlModulusExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlModulusExpression class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlModulusExpression::cPtr_gtlModulusExpression (const GALGAS_location & in_where,
                                                      const GALGAS_gtlExpression & in_lSon,
                                                      const GALGAS_gtlExpression & in_rSon
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlModulusExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlModulusExpression ;
}

void cPtr_gtlModulusExpression::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlModulusExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlModulusExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlModulusExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlModulusExpression type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlModulusExpression ("gtlModulusExpression",
                                             & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlModulusExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlModulusExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlModulusExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlModulusExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModulusExpression GALGAS_gtlModulusExpression::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlModulusExpression result ;
  const GALGAS_gtlModulusExpression * p = (const GALGAS_gtlModulusExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlModulusExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlModulusExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlMultiplyExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMultiplyExpression * p = (const cPtr_gtlMultiplyExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMultiplyExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlMultiplyExpression::objectCompare (const GALGAS_gtlMultiplyExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMultiplyExpression::GALGAS_gtlMultiplyExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMultiplyExpression::GALGAS_gtlMultiplyExpression (const cPtr_gtlMultiplyExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMultiplyExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMultiplyExpression GALGAS_gtlMultiplyExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                            const GALGAS_gtlExpression & inAttribute_lSon,
                                                                            const GALGAS_gtlExpression & inAttribute_rSon
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlMultiplyExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMultiplyExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlMultiplyExpression class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlMultiplyExpression::cPtr_gtlMultiplyExpression (const GALGAS_location & in_where,
                                                        const GALGAS_gtlExpression & in_lSon,
                                                        const GALGAS_gtlExpression & in_rSon
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlMultiplyExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMultiplyExpression ;
}

void cPtr_gtlMultiplyExpression::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@gtlMultiplyExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlMultiplyExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMultiplyExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlMultiplyExpression type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMultiplyExpression ("gtlMultiplyExpression",
                                              & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlMultiplyExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMultiplyExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlMultiplyExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMultiplyExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMultiplyExpression GALGAS_gtlMultiplyExpression::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlMultiplyExpression result ;
  const GALGAS_gtlMultiplyExpression * p = (const GALGAS_gtlMultiplyExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMultiplyExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMultiplyExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlNotEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlNotEqualExpression * p = (const cPtr_gtlNotEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlNotEqualExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlNotEqualExpression::objectCompare (const GALGAS_gtlNotEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotEqualExpression::GALGAS_gtlNotEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotEqualExpression::GALGAS_gtlNotEqualExpression (const cPtr_gtlNotEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlNotEqualExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotEqualExpression GALGAS_gtlNotEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                            const GALGAS_gtlExpression & inAttribute_lSon,
                                                                            const GALGAS_gtlExpression & inAttribute_rSon
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlNotEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlNotEqualExpression class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlNotEqualExpression::cPtr_gtlNotEqualExpression (const GALGAS_location & in_where,
                                                        const GALGAS_gtlExpression & in_lSon,
                                                        const GALGAS_gtlExpression & in_rSon
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlNotEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotEqualExpression ;
}

void cPtr_gtlNotEqualExpression::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@gtlNotEqualExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlNotEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlNotEqualExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlNotEqualExpression type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlNotEqualExpression ("gtlNotEqualExpression",
                                              & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlNotEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotEqualExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlNotEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlNotEqualExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotEqualExpression GALGAS_gtlNotEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotEqualExpression result ;
  const GALGAS_gtlNotEqualExpression * p = (const GALGAS_gtlNotEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlNotEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlNotEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlOrExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlOrExpression * p = (const cPtr_gtlOrExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlOrExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlOrExpression::objectCompare (const GALGAS_gtlOrExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlOrExpression::GALGAS_gtlOrExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlOrExpression::GALGAS_gtlOrExpression (const cPtr_gtlOrExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlOrExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlOrExpression GALGAS_gtlOrExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                const GALGAS_gtlExpression & inAttribute_lSon,
                                                                const GALGAS_gtlExpression & inAttribute_rSon
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlOrExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlOrExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlOrExpression class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlOrExpression::cPtr_gtlOrExpression (const GALGAS_location & in_where,
                                            const GALGAS_gtlExpression & in_lSon,
                                            const GALGAS_gtlExpression & in_rSon
                                            COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlOrExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlOrExpression ;
}

void cPtr_gtlOrExpression::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@gtlOrExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlOrExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlOrExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlOrExpression type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlOrExpression ("gtlOrExpression",
                                        & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlOrExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlOrExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlOrExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlOrExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlOrExpression GALGAS_gtlOrExpression::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlOrExpression result ;
  const GALGAS_gtlOrExpression * p = (const GALGAS_gtlOrExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlOrExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlOrExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlShiftLeftExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlShiftLeftExpression * p = (const cPtr_gtlShiftLeftExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlShiftLeftExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlShiftLeftExpression::objectCompare (const GALGAS_gtlShiftLeftExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftLeftExpression::GALGAS_gtlShiftLeftExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftLeftExpression::GALGAS_gtlShiftLeftExpression (const cPtr_gtlShiftLeftExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlShiftLeftExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftLeftExpression GALGAS_gtlShiftLeftExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_lSon,
                                                                              const GALGAS_gtlExpression & inAttribute_rSon
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftLeftExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlShiftLeftExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlShiftLeftExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlShiftLeftExpression::cPtr_gtlShiftLeftExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_lSon,
                                                          const GALGAS_gtlExpression & in_rSon
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlShiftLeftExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftLeftExpression ;
}

void cPtr_gtlShiftLeftExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlShiftLeftExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlShiftLeftExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlShiftLeftExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlShiftLeftExpression type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlShiftLeftExpression ("gtlShiftLeftExpression",
                                               & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlShiftLeftExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftLeftExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlShiftLeftExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlShiftLeftExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftLeftExpression GALGAS_gtlShiftLeftExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftLeftExpression result ;
  const GALGAS_gtlShiftLeftExpression * p = (const GALGAS_gtlShiftLeftExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlShiftLeftExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlShiftLeftExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlShiftRightExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlShiftRightExpression * p = (const cPtr_gtlShiftRightExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlShiftRightExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlShiftRightExpression::objectCompare (const GALGAS_gtlShiftRightExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftRightExpression::GALGAS_gtlShiftRightExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftRightExpression::GALGAS_gtlShiftRightExpression (const cPtr_gtlShiftRightExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlShiftRightExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftRightExpression GALGAS_gtlShiftRightExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                const GALGAS_gtlExpression & inAttribute_rSon
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftRightExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlShiftRightExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlShiftRightExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlShiftRightExpression::cPtr_gtlShiftRightExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpression & in_lSon,
                                                            const GALGAS_gtlExpression & in_rSon
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlShiftRightExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftRightExpression ;
}

void cPtr_gtlShiftRightExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlShiftRightExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlShiftRightExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlShiftRightExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlShiftRightExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlShiftRightExpression ("gtlShiftRightExpression",
                                                & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlShiftRightExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftRightExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlShiftRightExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlShiftRightExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlShiftRightExpression GALGAS_gtlShiftRightExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftRightExpression result ;
  const GALGAS_gtlShiftRightExpression * p = (const GALGAS_gtlShiftRightExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlShiftRightExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlShiftRightExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlSubstractExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSubstractExpression * p = (const cPtr_gtlSubstractExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSubstractExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlSubstractExpression::objectCompare (const GALGAS_gtlSubstractExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSubstractExpression::GALGAS_gtlSubstractExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSubstractExpression::GALGAS_gtlSubstractExpression (const cPtr_gtlSubstractExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSubstractExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSubstractExpression GALGAS_gtlSubstractExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_lSon,
                                                                              const GALGAS_gtlExpression & inAttribute_rSon
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlSubstractExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSubstractExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlSubstractExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlSubstractExpression::cPtr_gtlSubstractExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_lSon,
                                                          const GALGAS_gtlExpression & in_rSon
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlSubstractExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSubstractExpression ;
}

void cPtr_gtlSubstractExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlSubstractExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlSubstractExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSubstractExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlSubstractExpression type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSubstractExpression ("gtlSubstractExpression",
                                               & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSubstractExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSubstractExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSubstractExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSubstractExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSubstractExpression GALGAS_gtlSubstractExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlSubstractExpression result ;
  const GALGAS_gtlSubstractExpression * p = (const GALGAS_gtlSubstractExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSubstractExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSubstractExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlXorExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlXorExpression * p = (const cPtr_gtlXorExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlXorExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lSon.objectCompare (p->mAttribute_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rSon.objectCompare (p->mAttribute_rSon) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlXorExpression::objectCompare (const GALGAS_gtlXorExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlXorExpression::GALGAS_gtlXorExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlXorExpression::GALGAS_gtlXorExpression (const cPtr_gtlXorExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlXorExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlXorExpression GALGAS_gtlXorExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlXorExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlXorExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlXorExpression class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlXorExpression::cPtr_gtlXorExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_lSon,
                                              const GALGAS_gtlExpression & in_rSon
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlXorExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlXorExpression ;
}

void cPtr_gtlXorExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlXorExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlXorExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlXorExpression (mAttribute_where, mAttribute_lSon, mAttribute_rSon COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlXorExpression type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlXorExpression ("gtlXorExpression",
                                         & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlXorExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlXorExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlXorExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlXorExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlXorExpression GALGAS_gtlXorExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlXorExpression result ;
  const GALGAS_gtlXorExpression * p = (const GALGAS_gtlXorExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlXorExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlXorExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlExistsExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlExistsExpression * p = (const cPtr_gtlExistsExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlExistsExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variable.objectCompare (p->mAttribute_variable) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlExistsExpression::objectCompare (const GALGAS_gtlExistsExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsExpression::GALGAS_gtlExistsExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsExpression GALGAS_gtlExistsExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlExistsExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsExpression::GALGAS_gtlExistsExpression (const cPtr_gtlExistsExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExistsExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsExpression GALGAS_gtlExistsExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlVarPath & inAttribute_variable
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsExpression result ;
  if (inAttribute_where.isValid () && inAttribute_variable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlExistsExpression (inAttribute_where, inAttribute_variable COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlExistsExpression::getter_variable (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExistsExpression * p = (const cPtr_gtlExistsExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExistsExpression) ;
    result = p->mAttribute_variable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlExistsExpression::getter_variable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_variable ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlExistsExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlExistsExpression::cPtr_gtlExistsExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlVarPath & in_variable
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_variable (in_variable) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlExistsExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsExpression ;
}

void cPtr_gtlExistsExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlExistsExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlExistsExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlExistsExpression (mAttribute_where, mAttribute_variable COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlExistsExpression type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExistsExpression ("gtlExistsExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExistsExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExistsExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExistsExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsExpression GALGAS_gtlExistsExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsExpression result ;
  const GALGAS_gtlExistsExpression * p = (const GALGAS_gtlExistsExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExistsExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExistsExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlExistsDefaultExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlExistsDefaultExpression * p = (const cPtr_gtlExistsDefaultExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlExistsDefaultExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variable.objectCompare (p->mAttribute_variable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlExistsDefaultExpression::objectCompare (const GALGAS_gtlExistsDefaultExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsDefaultExpression::GALGAS_gtlExistsDefaultExpression (void) :
GALGAS_gtlExistsExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsDefaultExpression::GALGAS_gtlExistsDefaultExpression (const cPtr_gtlExistsDefaultExpression * inSourcePtr) :
GALGAS_gtlExistsExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExistsDefaultExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsDefaultExpression GALGAS_gtlExistsDefaultExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_gtlVarPath & inAttribute_variable,
                                                                                      const GALGAS_gtlExpression & inAttribute_defaultValue
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsDefaultExpression result ;
  if (inAttribute_where.isValid () && inAttribute_variable.isValid () && inAttribute_defaultValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlExistsDefaultExpression (inAttribute_where, inAttribute_variable, inAttribute_defaultValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExistsDefaultExpression::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlExistsDefaultExpression * p = (const cPtr_gtlExistsDefaultExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExistsDefaultExpression) ;
    result = p->mAttribute_defaultValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlExistsDefaultExpression::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_defaultValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlExistsDefaultExpression class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlExistsDefaultExpression::cPtr_gtlExistsDefaultExpression (const GALGAS_location & in_where,
                                                                  const GALGAS_gtlVarPath & in_variable,
                                                                  const GALGAS_gtlExpression & in_defaultValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlExistsExpression (in_where, in_variable COMMA_THERE),
mAttribute_defaultValue (in_defaultValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlExistsDefaultExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ;
}

void cPtr_gtlExistsDefaultExpression::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlExistsDefaultExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlExistsDefaultExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlExistsDefaultExpression (mAttribute_where, mAttribute_variable, mAttribute_defaultValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlExistsDefaultExpression type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ("gtlExistsDefaultExpression",
                                                   & kTypeDescriptor_GALGAS_gtlExistsExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExistsDefaultExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExistsDefaultExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExistsDefaultExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExistsDefaultExpression GALGAS_gtlExistsDefaultExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsDefaultExpression result ;
  const GALGAS_gtlExistsDefaultExpression * p = (const GALGAS_gtlExistsDefaultExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExistsDefaultExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExistsDefaultExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlFunctionCallExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlFunctionCallExpression * p = (const cPtr_gtlFunctionCallExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_functionName.objectCompare (p->mAttribute_functionName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_functionArguments.objectCompare (p->mAttribute_functionArguments) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlFunctionCallExpression::objectCompare (const GALGAS_gtlFunctionCallExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunctionCallExpression::GALGAS_gtlFunctionCallExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunctionCallExpression GALGAS_gtlFunctionCallExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlFunctionCallExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                            GALGAS_lstring::constructor_default (HERE),
                                                            GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunctionCallExpression::GALGAS_gtlFunctionCallExpression (const cPtr_gtlFunctionCallExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlFunctionCallExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunctionCallExpression GALGAS_gtlFunctionCallExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                    const GALGAS_lstring & inAttribute_functionName,
                                                                                    const GALGAS_gtlExpressionList & inAttribute_functionArguments
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunctionCallExpression result ;
  if (inAttribute_where.isValid () && inAttribute_functionName.isValid () && inAttribute_functionArguments.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlFunctionCallExpression (inAttribute_where, inAttribute_functionName, inAttribute_functionArguments COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlFunctionCallExpression::getter_functionName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlFunctionCallExpression * p = (const cPtr_gtlFunctionCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
    result = p->mAttribute_functionName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlFunctionCallExpression::getter_functionName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_functionName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlFunctionCallExpression::getter_functionArguments (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlFunctionCallExpression * p = (const cPtr_gtlFunctionCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
    result = p->mAttribute_functionArguments ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlFunctionCallExpression::getter_functionArguments (UNUSED_LOCATION_ARGS) const {
  return mAttribute_functionArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlFunctionCallExpression class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlFunctionCallExpression::cPtr_gtlFunctionCallExpression (const GALGAS_location & in_where,
                                                                const GALGAS_lstring & in_functionName,
                                                                const GALGAS_gtlExpressionList & in_functionArguments
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_functionName (in_functionName),
mAttribute_functionArguments (in_functionArguments) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlFunctionCallExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFunctionCallExpression ;
}

void cPtr_gtlFunctionCallExpression::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlFunctionCallExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_functionName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_functionArguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlFunctionCallExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlFunctionCallExpression (mAttribute_where, mAttribute_functionName, mAttribute_functionArguments COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlFunctionCallExpression type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFunctionCallExpression ("gtlFunctionCallExpression",
                                                  & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlFunctionCallExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFunctionCallExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlFunctionCallExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFunctionCallExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunctionCallExpression GALGAS_gtlFunctionCallExpression::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunctionCallExpression result ;
  const GALGAS_gtlFunctionCallExpression * p = (const GALGAS_gtlFunctionCallExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFunctionCallExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFunctionCallExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlGetterCallExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_target.objectCompare (p->mAttribute_target) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_getterName.objectCompare (p->mAttribute_getterName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_arguments.objectCompare (p->mAttribute_arguments) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlGetterCallExpression::objectCompare (const GALGAS_gtlGetterCallExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterCallExpression::GALGAS_gtlGetterCallExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterCallExpression::GALGAS_gtlGetterCallExpression (const cPtr_gtlGetterCallExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGetterCallExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterCallExpression GALGAS_gtlGetterCallExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpression & inAttribute_target,
                                                                                const GALGAS_lstring & inAttribute_getterName,
                                                                                const GALGAS_gtlExpressionList & inAttribute_arguments
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterCallExpression result ;
  if (inAttribute_where.isValid () && inAttribute_target.isValid () && inAttribute_getterName.isValid () && inAttribute_arguments.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGetterCallExpression (inAttribute_where, inAttribute_target, inAttribute_getterName, inAttribute_arguments COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlGetterCallExpression::getter_target (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    result = p->mAttribute_target ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlGetterCallExpression::getter_target (UNUSED_LOCATION_ARGS) const {
  return mAttribute_target ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlGetterCallExpression::getter_getterName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    result = p->mAttribute_getterName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlGetterCallExpression::getter_getterName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_getterName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlGetterCallExpression::getter_arguments (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    result = p->mAttribute_arguments ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlGetterCallExpression::getter_arguments (UNUSED_LOCATION_ARGS) const {
  return mAttribute_arguments ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlGetterCallExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlGetterCallExpression::cPtr_gtlGetterCallExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpression & in_target,
                                                            const GALGAS_lstring & in_getterName,
                                                            const GALGAS_gtlExpressionList & in_arguments
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_target (in_target),
mAttribute_getterName (in_getterName),
mAttribute_arguments (in_arguments) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlGetterCallExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterCallExpression ;
}

void cPtr_gtlGetterCallExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlGetterCallExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_target.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_getterName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_arguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlGetterCallExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGetterCallExpression (mAttribute_where, mAttribute_target, mAttribute_getterName, mAttribute_arguments COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlGetterCallExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterCallExpression ("gtlGetterCallExpression",
                                                & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGetterCallExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterCallExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGetterCallExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterCallExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterCallExpression GALGAS_gtlGetterCallExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterCallExpression result ;
  const GALGAS_gtlGetterCallExpression * p = (const GALGAS_gtlGetterCallExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetterCallExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetterCallExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlListOfExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlListOfExpression * p = (const cPtr_gtlListOfExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlListOfExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_expression.objectCompare (p->mAttribute_expression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlListOfExpression::objectCompare (const GALGAS_gtlListOfExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlListOfExpression::GALGAS_gtlListOfExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlListOfExpression::GALGAS_gtlListOfExpression (const cPtr_gtlListOfExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlListOfExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlListOfExpression GALGAS_gtlListOfExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlExpression & inAttribute_expression
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlListOfExpression result ;
  if (inAttribute_where.isValid () && inAttribute_expression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlListOfExpression (inAttribute_where, inAttribute_expression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlListOfExpression::getter_expression (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlListOfExpression * p = (const cPtr_gtlListOfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlListOfExpression) ;
    result = p->mAttribute_expression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlListOfExpression::getter_expression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_expression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlListOfExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlListOfExpression::cPtr_gtlListOfExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlExpression & in_expression
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_expression (in_expression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlListOfExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlListOfExpression ;
}

void cPtr_gtlListOfExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlListOfExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_expression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlListOfExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlListOfExpression (mAttribute_where, mAttribute_expression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlListOfExpression type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlListOfExpression ("gtlListOfExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlListOfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlListOfExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlListOfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlListOfExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlListOfExpression GALGAS_gtlListOfExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlListOfExpression result ;
  const GALGAS_gtlListOfExpression * p = (const GALGAS_gtlListOfExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlListOfExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlListOfExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLiteralListExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralListExpression * p = (const cPtr_gtlLiteralListExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralListExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLiteralListExpression::objectCompare (const GALGAS_gtlLiteralListExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralListExpression::GALGAS_gtlLiteralListExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralListExpression GALGAS_gtlLiteralListExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralListExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralListExpression::GALGAS_gtlLiteralListExpression (const cPtr_gtlLiteralListExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralListExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralListExpression GALGAS_gtlLiteralListExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_gtlExpressionList & inAttribute_value
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralListExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralListExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlLiteralListExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLiteralListExpression * p = (const cPtr_gtlLiteralListExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralListExpression) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlLiteralListExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlLiteralListExpression class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLiteralListExpression::cPtr_gtlLiteralListExpression (const GALGAS_location & in_where,
                                                              const GALGAS_gtlExpressionList & in_value
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLiteralListExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralListExpression ;
}

void cPtr_gtlLiteralListExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlLiteralListExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLiteralListExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralListExpression (mAttribute_where, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlLiteralListExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralListExpression ("gtlLiteralListExpression",
                                                 & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLiteralListExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralListExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLiteralListExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralListExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralListExpression GALGAS_gtlLiteralListExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralListExpression result ;
  const GALGAS_gtlLiteralListExpression * p = (const GALGAS_gtlLiteralListExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralListExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralListExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLiteralMapExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralMapExpression * p = (const cPtr_gtlLiteralMapExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralMapExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLiteralMapExpression::objectCompare (const GALGAS_gtlLiteralMapExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralMapExpression::GALGAS_gtlLiteralMapExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralMapExpression GALGAS_gtlLiteralMapExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralMapExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_gtlExpressionMap::constructor_emptyMap (HERE)
                                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralMapExpression::GALGAS_gtlLiteralMapExpression (const cPtr_gtlLiteralMapExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralMapExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralMapExpression GALGAS_gtlLiteralMapExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpressionMap & inAttribute_value
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralMapExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralMapExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlLiteralMapExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLiteralMapExpression * p = (const cPtr_gtlLiteralMapExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralMapExpression) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap cPtr_gtlLiteralMapExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlLiteralMapExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLiteralMapExpression::cPtr_gtlLiteralMapExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpressionMap & in_value
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLiteralMapExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralMapExpression ;
}

void cPtr_gtlLiteralMapExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLiteralMapExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLiteralMapExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralMapExpression (mAttribute_where, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlLiteralMapExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralMapExpression ("gtlLiteralMapExpression",
                                                & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLiteralMapExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralMapExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLiteralMapExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralMapExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralMapExpression GALGAS_gtlLiteralMapExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralMapExpression result ;
  const GALGAS_gtlLiteralMapExpression * p = (const GALGAS_gtlLiteralMapExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralMapExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralMapExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLiteralSetExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralSetExpression * p = (const cPtr_gtlLiteralSetExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralSetExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLiteralSetExpression::objectCompare (const GALGAS_gtlLiteralSetExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralSetExpression::GALGAS_gtlLiteralSetExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralSetExpression GALGAS_gtlLiteralSetExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralSetExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralSetExpression::GALGAS_gtlLiteralSetExpression (const cPtr_gtlLiteralSetExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralSetExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralSetExpression GALGAS_gtlLiteralSetExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpressionList & inAttribute_value
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralSetExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralSetExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlLiteralSetExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLiteralSetExpression * p = (const cPtr_gtlLiteralSetExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralSetExpression) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlLiteralSetExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlLiteralSetExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLiteralSetExpression::cPtr_gtlLiteralSetExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpressionList & in_value
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLiteralSetExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralSetExpression ;
}

void cPtr_gtlLiteralSetExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLiteralSetExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLiteralSetExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralSetExpression (mAttribute_where, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlLiteralSetExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralSetExpression ("gtlLiteralSetExpression",
                                                & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLiteralSetExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralSetExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLiteralSetExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralSetExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralSetExpression GALGAS_gtlLiteralSetExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralSetExpression result ;
  const GALGAS_gtlLiteralSetExpression * p = (const GALGAS_gtlLiteralSetExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralSetExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralSetExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLiteralStructExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralStructExpression * p = (const cPtr_gtlLiteralStructExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralStructExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLiteralStructExpression::objectCompare (const GALGAS_gtlLiteralStructExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralStructExpression::GALGAS_gtlLiteralStructExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralStructExpression GALGAS_gtlLiteralStructExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralStructExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                             GALGAS_gtlExpressionMap::constructor_emptyMap (HERE)
                                                             COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralStructExpression::GALGAS_gtlLiteralStructExpression (const cPtr_gtlLiteralStructExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralStructExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralStructExpression GALGAS_gtlLiteralStructExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_gtlExpressionMap & inAttribute_value
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralStructExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralStructExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlLiteralStructExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlLiteralStructExpression * p = (const cPtr_gtlLiteralStructExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralStructExpression) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap cPtr_gtlLiteralStructExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlLiteralStructExpression class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLiteralStructExpression::cPtr_gtlLiteralStructExpression (const GALGAS_location & in_where,
                                                                  const GALGAS_gtlExpressionMap & in_value
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLiteralStructExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralStructExpression ;
}

void cPtr_gtlLiteralStructExpression::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlLiteralStructExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLiteralStructExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralStructExpression (mAttribute_where, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlLiteralStructExpression type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralStructExpression ("gtlLiteralStructExpression",
                                                   & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLiteralStructExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralStructExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLiteralStructExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralStructExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLiteralStructExpression GALGAS_gtlLiteralStructExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralStructExpression result ;
  const GALGAS_gtlLiteralStructExpression * p = (const GALGAS_gtlLiteralStructExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralStructExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralStructExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlMapOfStructExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMapOfStructExpression * p = (const cPtr_gtlMapOfStructExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMapOfStructExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_expression.objectCompare (p->mAttribute_expression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlMapOfStructExpression::objectCompare (const GALGAS_gtlMapOfStructExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfStructExpression::GALGAS_gtlMapOfStructExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfStructExpression::GALGAS_gtlMapOfStructExpression (const cPtr_gtlMapOfStructExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMapOfStructExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfStructExpression GALGAS_gtlMapOfStructExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_gtlExpression & inAttribute_expression
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfStructExpression result ;
  if (inAttribute_where.isValid () && inAttribute_expression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMapOfStructExpression (inAttribute_where, inAttribute_expression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlMapOfStructExpression::getter_expression (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlMapOfStructExpression * p = (const cPtr_gtlMapOfStructExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMapOfStructExpression) ;
    result = p->mAttribute_expression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlMapOfStructExpression::getter_expression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_expression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlMapOfStructExpression class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlMapOfStructExpression::cPtr_gtlMapOfStructExpression (const GALGAS_location & in_where,
                                                              const GALGAS_gtlExpression & in_expression
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_expression (in_expression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlMapOfStructExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfStructExpression ;
}

void cPtr_gtlMapOfStructExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlMapOfStructExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_expression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlMapOfStructExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMapOfStructExpression (mAttribute_where, mAttribute_expression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlMapOfStructExpression type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMapOfStructExpression ("gtlMapOfStructExpression",
                                                 & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlMapOfStructExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfStructExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlMapOfStructExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMapOfStructExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfStructExpression GALGAS_gtlMapOfStructExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfStructExpression result ;
  const GALGAS_gtlMapOfStructExpression * p = (const GALGAS_gtlMapOfStructExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMapOfStructExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMapOfStructExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlMapOfListExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMapOfListExpression * p = (const cPtr_gtlMapOfListExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMapOfListExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_expression.objectCompare (p->mAttribute_expression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_key.objectCompare (p->mAttribute_key) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlMapOfListExpression::objectCompare (const GALGAS_gtlMapOfListExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfListExpression::GALGAS_gtlMapOfListExpression (void) :
GALGAS_gtlMapOfStructExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfListExpression::GALGAS_gtlMapOfListExpression (const cPtr_gtlMapOfListExpression * inSourcePtr) :
GALGAS_gtlMapOfStructExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMapOfListExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfListExpression GALGAS_gtlMapOfListExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_expression,
                                                                              const GALGAS_lstring & inAttribute_key
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfListExpression result ;
  if (inAttribute_where.isValid () && inAttribute_expression.isValid () && inAttribute_key.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMapOfListExpression (inAttribute_where, inAttribute_expression, inAttribute_key COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlMapOfListExpression::getter_key (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlMapOfListExpression * p = (const cPtr_gtlMapOfListExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMapOfListExpression) ;
    result = p->mAttribute_key ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlMapOfListExpression::getter_key (UNUSED_LOCATION_ARGS) const {
  return mAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlMapOfListExpression class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlMapOfListExpression::cPtr_gtlMapOfListExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_expression,
                                                          const GALGAS_lstring & in_key
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlMapOfStructExpression (in_where, in_expression COMMA_THERE),
mAttribute_key (in_key) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlMapOfListExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfListExpression ;
}

void cPtr_gtlMapOfListExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlMapOfListExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_expression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_key.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlMapOfListExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMapOfListExpression (mAttribute_where, mAttribute_expression, mAttribute_key COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlMapOfListExpression type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMapOfListExpression ("gtlMapOfListExpression",
                                               & kTypeDescriptor_GALGAS_gtlMapOfStructExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlMapOfListExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfListExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlMapOfListExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMapOfListExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMapOfListExpression GALGAS_gtlMapOfListExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfListExpression result ;
  const GALGAS_gtlMapOfListExpression * p = (const GALGAS_gtlMapOfListExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMapOfListExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMapOfListExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlTerminal::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTerminal * p = (const cPtr_gtlTerminal *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTerminal) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlTerminal::objectCompare (const GALGAS_gtlTerminal & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTerminal::GALGAS_gtlTerminal (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTerminal::GALGAS_gtlTerminal (const cPtr_gtlTerminal * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTerminal) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTerminal GALGAS_gtlTerminal::constructor_new (const GALGAS_location & inAttribute_where,
                                                        const GALGAS_gtlData & inAttribute_value
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTerminal result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTerminal (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlTerminal::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTerminal * p = (const cPtr_gtlTerminal *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTerminal) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cPtr_gtlTerminal::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @gtlTerminal class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlTerminal::cPtr_gtlTerminal (const GALGAS_location & in_where,
                                    const GALGAS_gtlData & in_value
                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlTerminal::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTerminal ;
}

void cPtr_gtlTerminal::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@gtlTerminal:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlTerminal::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTerminal (mAttribute_where, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlTerminal type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTerminal ("gtlTerminal",
                                    & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTerminal::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTerminal ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTerminal::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTerminal (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTerminal GALGAS_gtlTerminal::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTerminal result ;
  const GALGAS_gtlTerminal * p = (const GALGAS_gtlTerminal *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTerminal *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTerminal", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlTypeOfExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTypeOfExpression * p = (const cPtr_gtlTypeOfExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTypeOfExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variable.objectCompare (p->mAttribute_variable) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlTypeOfExpression::objectCompare (const GALGAS_gtlTypeOfExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypeOfExpression::GALGAS_gtlTypeOfExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypeOfExpression GALGAS_gtlTypeOfExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlTypeOfExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypeOfExpression::GALGAS_gtlTypeOfExpression (const cPtr_gtlTypeOfExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTypeOfExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypeOfExpression GALGAS_gtlTypeOfExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlVarPath & inAttribute_variable
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypeOfExpression result ;
  if (inAttribute_where.isValid () && inAttribute_variable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTypeOfExpression (inAttribute_where, inAttribute_variable COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlTypeOfExpression::getter_variable (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlTypeOfExpression * p = (const cPtr_gtlTypeOfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTypeOfExpression) ;
    result = p->mAttribute_variable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlTypeOfExpression::getter_variable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_variable ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlTypeOfExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlTypeOfExpression::cPtr_gtlTypeOfExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlVarPath & in_variable
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_variable (in_variable) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlTypeOfExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypeOfExpression ;
}

void cPtr_gtlTypeOfExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlTypeOfExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlTypeOfExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTypeOfExpression (mAttribute_where, mAttribute_variable COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlTypeOfExpression type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypeOfExpression ("gtlTypeOfExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTypeOfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypeOfExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTypeOfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypeOfExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypeOfExpression GALGAS_gtlTypeOfExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypeOfExpression result ;
  const GALGAS_gtlTypeOfExpression * p = (const GALGAS_gtlTypeOfExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTypeOfExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypeOfExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlUnaryExpression::objectCompare (const GALGAS_gtlUnaryExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnaryExpression::GALGAS_gtlUnaryExpression (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnaryExpression::GALGAS_gtlUnaryExpression (const cPtr_gtlUnaryExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlUnaryExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlUnaryExpression::getter_son (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlUnaryExpression * p = (const cPtr_gtlUnaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlUnaryExpression) ;
    result = p->mAttribute_son ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlUnaryExpression::getter_son (UNUSED_LOCATION_ARGS) const {
  return mAttribute_son ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlUnaryExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlUnaryExpression::cPtr_gtlUnaryExpression (const GALGAS_location & in_where,
                                                  const GALGAS_gtlExpression & in_son
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_son (in_son) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlUnaryExpression type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlUnaryExpression ("gtlUnaryExpression",
                                           & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlUnaryExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnaryExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlUnaryExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlUnaryExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlUnaryExpression GALGAS_gtlUnaryExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnaryExpression result ;
  const GALGAS_gtlUnaryExpression * p = (const GALGAS_gtlUnaryExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlUnaryExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlUnaryExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlMinusExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMinusExpression * p = (const cPtr_gtlMinusExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMinusExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_son.objectCompare (p->mAttribute_son) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlMinusExpression::objectCompare (const GALGAS_gtlMinusExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMinusExpression::GALGAS_gtlMinusExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMinusExpression::GALGAS_gtlMinusExpression (const cPtr_gtlMinusExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMinusExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMinusExpression GALGAS_gtlMinusExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_gtlExpression & inAttribute_son
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlMinusExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMinusExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlMinusExpression class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlMinusExpression::cPtr_gtlMinusExpression (const GALGAS_location & in_where,
                                                  const GALGAS_gtlExpression & in_son
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlMinusExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMinusExpression ;
}

void cPtr_gtlMinusExpression::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlMinusExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlMinusExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMinusExpression (mAttribute_where, mAttribute_son COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlMinusExpression type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMinusExpression ("gtlMinusExpression",
                                           & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlMinusExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMinusExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlMinusExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMinusExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlMinusExpression GALGAS_gtlMinusExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlMinusExpression result ;
  const GALGAS_gtlMinusExpression * p = (const GALGAS_gtlMinusExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMinusExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMinusExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlNotExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlNotExpression * p = (const cPtr_gtlNotExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlNotExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_son.objectCompare (p->mAttribute_son) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlNotExpression::objectCompare (const GALGAS_gtlNotExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotExpression::GALGAS_gtlNotExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotExpression::GALGAS_gtlNotExpression (const cPtr_gtlNotExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlNotExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotExpression GALGAS_gtlNotExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_son
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlNotExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlNotExpression class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlNotExpression::cPtr_gtlNotExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_son
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlNotExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotExpression ;
}

void cPtr_gtlNotExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlNotExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlNotExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlNotExpression (mAttribute_where, mAttribute_son COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlNotExpression type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlNotExpression ("gtlNotExpression",
                                         & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlNotExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlNotExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlNotExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlNotExpression GALGAS_gtlNotExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotExpression result ;
  const GALGAS_gtlNotExpression * p = (const GALGAS_gtlNotExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlNotExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlNotExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlParenthesizedExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlParenthesizedExpression * p = (const cPtr_gtlParenthesizedExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlParenthesizedExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_son.objectCompare (p->mAttribute_son) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlParenthesizedExpression::objectCompare (const GALGAS_gtlParenthesizedExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlParenthesizedExpression::GALGAS_gtlParenthesizedExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlParenthesizedExpression::GALGAS_gtlParenthesizedExpression (const cPtr_gtlParenthesizedExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlParenthesizedExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlParenthesizedExpression GALGAS_gtlParenthesizedExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_gtlExpression & inAttribute_son
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlParenthesizedExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlParenthesizedExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlParenthesizedExpression class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlParenthesizedExpression::cPtr_gtlParenthesizedExpression (const GALGAS_location & in_where,
                                                                  const GALGAS_gtlExpression & in_son
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlParenthesizedExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlParenthesizedExpression ;
}

void cPtr_gtlParenthesizedExpression::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlParenthesizedExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlParenthesizedExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlParenthesizedExpression (mAttribute_where, mAttribute_son COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlParenthesizedExpression type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlParenthesizedExpression ("gtlParenthesizedExpression",
                                                   & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlParenthesizedExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlParenthesizedExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlParenthesizedExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlParenthesizedExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlParenthesizedExpression GALGAS_gtlParenthesizedExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlParenthesizedExpression result ;
  const GALGAS_gtlParenthesizedExpression * p = (const GALGAS_gtlParenthesizedExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlParenthesizedExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlParenthesizedExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlPlusExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlPlusExpression * p = (const cPtr_gtlPlusExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlPlusExpression) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_son.objectCompare (p->mAttribute_son) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlPlusExpression::objectCompare (const GALGAS_gtlPlusExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPlusExpression::GALGAS_gtlPlusExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPlusExpression::GALGAS_gtlPlusExpression (const cPtr_gtlPlusExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlPlusExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPlusExpression GALGAS_gtlPlusExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                    const GALGAS_gtlExpression & inAttribute_son
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlPlusExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlPlusExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlPlusExpression class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlPlusExpression::cPtr_gtlPlusExpression (const GALGAS_location & in_where,
                                                const GALGAS_gtlExpression & in_son
                                                COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlPlusExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPlusExpression ;
}

void cPtr_gtlPlusExpression::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@gtlPlusExpression:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlPlusExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlPlusExpression (mAttribute_where, mAttribute_son COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlPlusExpression type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlPlusExpression ("gtlPlusExpression",
                                          & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlPlusExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPlusExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlPlusExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlPlusExpression (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlPlusExpression GALGAS_gtlPlusExpression::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlPlusExpression result ;
  const GALGAS_gtlPlusExpression * p = (const GALGAS_gtlPlusExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlPlusExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlPlusExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlVarRef::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarRef * p = (const cPtr_gtlVarRef *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarRef) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variableName.objectCompare (p->mAttribute_variableName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlVarRef::objectCompare (const GALGAS_gtlVarRef & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarRef::GALGAS_gtlVarRef (void) :
GALGAS_gtlExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarRef GALGAS_gtlVarRef::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlVarRef::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                            GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarRef::GALGAS_gtlVarRef (const cPtr_gtlVarRef * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarRef) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarRef GALGAS_gtlVarRef::constructor_new (const GALGAS_location & inAttribute_where,
                                                    const GALGAS_gtlVarPath & inAttribute_variableName
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarRef result ;
  if (inAttribute_where.isValid () && inAttribute_variableName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarRef (inAttribute_where, inAttribute_variableName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarRef::getter_variableName (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlVarRef * p = (const cPtr_gtlVarRef *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarRef) ;
    result = p->mAttribute_variableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlVarRef::getter_variableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_variableName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlVarRef class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlVarRef::cPtr_gtlVarRef (const GALGAS_location & in_where,
                                const GALGAS_gtlVarPath & in_variableName
                                COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mAttribute_variableName (in_variableName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlVarRef::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarRef ;
}

void cPtr_gtlVarRef::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlVarRef:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variableName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlVarRef::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarRef (mAttribute_where, mAttribute_variableName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlVarRef type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarRef ("gtlVarRef",
                                  & kTypeDescriptor_GALGAS_gtlExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarRef::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarRef ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarRef::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarRef (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarRef GALGAS_gtlVarRef::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarRef result ;
  const GALGAS_gtlVarRef * p = (const GALGAS_gtlVarRef *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarRef *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarRef", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlInstruction::objectCompare (const GALGAS_gtlInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction::GALGAS_gtlInstruction (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction::GALGAS_gtlInstruction (const cPtr_gtlInstruction * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlInstruction::getter_where (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlInstruction * p = (const cPtr_gtlInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInstruction) ;
    result = p->mAttribute_where ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlInstruction::getter_where (UNUSED_LOCATION_ARGS) const {
  return mAttribute_where ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlInstruction::getter_signature (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlInstruction * p = (const cPtr_gtlInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInstruction) ;
    result = p->mAttribute_signature ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlInstruction::getter_signature (UNUSED_LOCATION_ARGS) const {
  return mAttribute_signature ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @gtlInstruction class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlInstruction::cPtr_gtlInstruction (const GALGAS_location & in_where,
                                          const GALGAS_string & in_signature
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_where (in_where),
mAttribute_signature (in_signature) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlInstruction type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstruction ("gtlInstruction",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction GALGAS_gtlInstruction::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstruction result ;
  const GALGAS_gtlInstruction * p = (const GALGAS_gtlInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlAbstractSortInstruction::objectCompare (const GALGAS_gtlAbstractSortInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAbstractSortInstruction::GALGAS_gtlAbstractSortInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAbstractSortInstruction::GALGAS_gtlAbstractSortInstruction (const cPtr_gtlAbstractSortInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAbstractSortInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlAbstractSortInstruction::getter_variablePath (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlAbstractSortInstruction * p = (const cPtr_gtlAbstractSortInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlAbstractSortInstruction) ;
    result = p->mAttribute_variablePath ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlAbstractSortInstruction::getter_variablePath (UNUSED_LOCATION_ARGS) const {
  return mAttribute_variablePath ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlAbstractSortInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlAbstractSortInstruction::cPtr_gtlAbstractSortInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlVarPath & in_variablePath
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_variablePath (in_variablePath) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlAbstractSortInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAbstractSortInstruction ("gtlAbstractSortInstruction",
                                                   & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlAbstractSortInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAbstractSortInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlAbstractSortInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAbstractSortInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAbstractSortInstruction GALGAS_gtlAbstractSortInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlAbstractSortInstruction result ;
  const GALGAS_gtlAbstractSortInstruction * p = (const GALGAS_gtlAbstractSortInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAbstractSortInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAbstractSortInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlSortStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSortStatementInstruction * p = (const cPtr_gtlSortStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSortStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variablePath.objectCompare (p->mAttribute_variablePath) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_order.objectCompare (p->mAttribute_order) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlSortStatementInstruction::objectCompare (const GALGAS_gtlSortStatementInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementInstruction::GALGAS_gtlSortStatementInstruction (void) :
GALGAS_gtlAbstractSortInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementInstruction GALGAS_gtlSortStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlSortStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_string::constructor_default (HERE),
                                                              GALGAS_gtlVarPath::constructor_emptyList (HERE),
                                                              GALGAS_lsint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementInstruction::GALGAS_gtlSortStatementInstruction (const cPtr_gtlSortStatementInstruction * inSourcePtr) :
GALGAS_gtlAbstractSortInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSortStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementInstruction GALGAS_gtlSortStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                        const GALGAS_string & inAttribute_signature,
                                                                                        const GALGAS_gtlVarPath & inAttribute_variablePath,
                                                                                        const GALGAS_lsint & inAttribute_order
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_variablePath.isValid () && inAttribute_order.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSortStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_variablePath, inAttribute_order COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint GALGAS_gtlSortStatementInstruction::getter_order (UNUSED_LOCATION_ARGS) const {
  GALGAS_lsint result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSortStatementInstruction * p = (const cPtr_gtlSortStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSortStatementInstruction) ;
    result = p->mAttribute_order ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint cPtr_gtlSortStatementInstruction::getter_order (UNUSED_LOCATION_ARGS) const {
  return mAttribute_order ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlSortStatementInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlSortStatementInstruction::cPtr_gtlSortStatementInstruction (const GALGAS_location & in_where,
                                                                    const GALGAS_string & in_signature,
                                                                    const GALGAS_gtlVarPath & in_variablePath,
                                                                    const GALGAS_lsint & in_order
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlAbstractSortInstruction (in_where, in_signature, in_variablePath COMMA_THERE),
mAttribute_order (in_order) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlSortStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;
}

void cPtr_gtlSortStatementInstruction::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@gtlSortStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variablePath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_order.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlSortStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSortStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_variablePath, mAttribute_order COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlSortStatementInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSortStatementInstruction ("gtlSortStatementInstruction",
                                                    & kTypeDescriptor_GALGAS_gtlAbstractSortInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSortStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSortStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSortStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementInstruction GALGAS_gtlSortStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementInstruction result ;
  const GALGAS_gtlSortStatementInstruction * p = (const GALGAS_gtlSortStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSortStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSortStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlSortStatementStructInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSortStatementStructInstruction * p = (const cPtr_gtlSortStatementStructInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSortStatementStructInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variablePath.objectCompare (p->mAttribute_variablePath) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_sortingKey.objectCompare (p->mAttribute_sortingKey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlSortStatementStructInstruction::objectCompare (const GALGAS_gtlSortStatementStructInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementStructInstruction::GALGAS_gtlSortStatementStructInstruction (void) :
GALGAS_gtlAbstractSortInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementStructInstruction GALGAS_gtlSortStatementStructInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlSortStatementStructInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                    GALGAS_string::constructor_default (HERE),
                                                                    GALGAS_gtlVarPath::constructor_emptyList (HERE),
                                                                    GALGAS_sortingKeyList::constructor_emptyList (HERE)
                                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementStructInstruction::GALGAS_gtlSortStatementStructInstruction (const cPtr_gtlSortStatementStructInstruction * inSourcePtr) :
GALGAS_gtlAbstractSortInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSortStatementStructInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementStructInstruction GALGAS_gtlSortStatementStructInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                                    const GALGAS_string & inAttribute_signature,
                                                                                                    const GALGAS_gtlVarPath & inAttribute_variablePath,
                                                                                                    const GALGAS_sortingKeyList & inAttribute_sortingKey
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementStructInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_variablePath.isValid () && inAttribute_sortingKey.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSortStatementStructInstruction (inAttribute_where, inAttribute_signature, inAttribute_variablePath, inAttribute_sortingKey COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_gtlSortStatementStructInstruction::getter_sortingKey (UNUSED_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlSortStatementStructInstruction * p = (const cPtr_gtlSortStatementStructInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSortStatementStructInstruction) ;
    result = p->mAttribute_sortingKey ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList cPtr_gtlSortStatementStructInstruction::getter_sortingKey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_sortingKey ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                             Pointer class for @gtlSortStatementStructInstruction class                              *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlSortStatementStructInstruction::cPtr_gtlSortStatementStructInstruction (const GALGAS_location & in_where,
                                                                                const GALGAS_string & in_signature,
                                                                                const GALGAS_gtlVarPath & in_variablePath,
                                                                                const GALGAS_sortingKeyList & in_sortingKey
                                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlAbstractSortInstruction (in_where, in_signature, in_variablePath COMMA_THERE),
mAttribute_sortingKey (in_sortingKey) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlSortStatementStructInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ;
}

void cPtr_gtlSortStatementStructInstruction::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "[@gtlSortStatementStructInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variablePath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_sortingKey.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlSortStatementStructInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSortStatementStructInstruction (mAttribute_where, mAttribute_signature, mAttribute_variablePath, mAttribute_sortingKey COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @gtlSortStatementStructInstruction type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ("gtlSortStatementStructInstruction",
                                                          & kTypeDescriptor_GALGAS_gtlAbstractSortInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSortStatementStructInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSortStatementStructInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSortStatementStructInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSortStatementStructInstruction GALGAS_gtlSortStatementStructInstruction::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementStructInstruction result ;
  const GALGAS_gtlSortStatementStructInstruction * p = (const GALGAS_gtlSortStatementStructInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSortStatementStructInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSortStatementStructInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlBreakpointDeleteInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointDeleteInstruction * p = (const cPtr_gtlBreakpointDeleteInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointDeleteInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_numToDelete.objectCompare (p->mAttribute_numToDelete) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlBreakpointDeleteInstruction::objectCompare (const GALGAS_gtlBreakpointDeleteInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointDeleteInstruction::GALGAS_gtlBreakpointDeleteInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointDeleteInstruction GALGAS_gtlBreakpointDeleteInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointDeleteInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_lbigint::constructor_default (HERE)
                                                                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointDeleteInstruction::GALGAS_gtlBreakpointDeleteInstruction (const cPtr_gtlBreakpointDeleteInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointDeleteInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointDeleteInstruction GALGAS_gtlBreakpointDeleteInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_lbigint & inAttribute_numToDelete
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointDeleteInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_numToDelete.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointDeleteInstruction (inAttribute_where, inAttribute_signature, inAttribute_numToDelete COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_gtlBreakpointDeleteInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  GALGAS_lbigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBreakpointDeleteInstruction * p = (const cPtr_gtlBreakpointDeleteInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointDeleteInstruction) ;
    result = p->mAttribute_numToDelete ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cPtr_gtlBreakpointDeleteInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  return mAttribute_numToDelete ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @gtlBreakpointDeleteInstruction class                               *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlBreakpointDeleteInstruction::cPtr_gtlBreakpointDeleteInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_lbigint & in_numToDelete
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_numToDelete (in_numToDelete) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlBreakpointDeleteInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction ;
}

void cPtr_gtlBreakpointDeleteInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointDeleteInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_numToDelete.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlBreakpointDeleteInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlBreakpointDeleteInstruction (mAttribute_where, mAttribute_signature, mAttribute_numToDelete COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlBreakpointDeleteInstruction type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction ("gtlBreakpointDeleteInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBreakpointDeleteInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointDeleteInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBreakpointDeleteInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointDeleteInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointDeleteInstruction GALGAS_gtlBreakpointDeleteInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointDeleteInstruction result ;
  const GALGAS_gtlBreakpointDeleteInstruction * p = (const GALGAS_gtlBreakpointDeleteInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpointDeleteInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointDeleteInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlBreakpointInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointInstruction * p = (const cPtr_gtlBreakpointInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_fileName.objectCompare (p->mAttribute_fileName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lineNum.objectCompare (p->mAttribute_lineNum) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlBreakpointInstruction::objectCompare (const GALGAS_gtlBreakpointInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointInstruction::GALGAS_gtlBreakpointInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointInstruction GALGAS_gtlBreakpointInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_string::constructor_default (HERE),
                                                           GALGAS_string::constructor_default (HERE),
                                                           GALGAS_uint::constructor_default (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointInstruction::GALGAS_gtlBreakpointInstruction (const cPtr_gtlBreakpointInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointInstruction GALGAS_gtlBreakpointInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_string & inAttribute_signature,
                                                                                  const GALGAS_string & inAttribute_fileName,
                                                                                  const GALGAS_uint & inAttribute_lineNum
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_fileName.isValid () && inAttribute_lineNum.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointInstruction (inAttribute_where, inAttribute_signature, inAttribute_fileName, inAttribute_lineNum COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlBreakpointInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBreakpointInstruction * p = (const cPtr_gtlBreakpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
    result = p->mAttribute_fileName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlBreakpointInstruction::getter_fileName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_fileName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_gtlBreakpointInstruction::getter_lineNum (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlBreakpointInstruction * p = (const cPtr_gtlBreakpointInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBreakpointInstruction) ;
    result = p->mAttribute_lineNum ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_gtlBreakpointInstruction::getter_lineNum (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lineNum ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlBreakpointInstruction class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlBreakpointInstruction::cPtr_gtlBreakpointInstruction (const GALGAS_location & in_where,
                                                              const GALGAS_string & in_signature,
                                                              const GALGAS_string & in_fileName,
                                                              const GALGAS_uint & in_lineNum
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_fileName (in_fileName),
mAttribute_lineNum (in_lineNum) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlBreakpointInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointInstruction ;
}

void cPtr_gtlBreakpointInstruction::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_fileName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lineNum.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlBreakpointInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlBreakpointInstruction (mAttribute_where, mAttribute_signature, mAttribute_fileName, mAttribute_lineNum COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlBreakpointInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointInstruction ("gtlBreakpointInstruction",
                                                 & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBreakpointInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBreakpointInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointInstruction GALGAS_gtlBreakpointInstruction::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointInstruction result ;
  const GALGAS_gtlBreakpointInstruction * p = (const GALGAS_gtlBreakpointInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpointInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlBreakpointListInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlBreakpointListInstruction * p = (const cPtr_gtlBreakpointListInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlBreakpointListInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlBreakpointListInstruction::objectCompare (const GALGAS_gtlBreakpointListInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointListInstruction::GALGAS_gtlBreakpointListInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointListInstruction GALGAS_gtlBreakpointListInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlBreakpointListInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE)
                                                               COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointListInstruction::GALGAS_gtlBreakpointListInstruction (const cPtr_gtlBreakpointListInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBreakpointListInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointListInstruction GALGAS_gtlBreakpointListInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointListInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlBreakpointListInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlBreakpointListInstruction class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlBreakpointListInstruction::cPtr_gtlBreakpointListInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlBreakpointListInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointListInstruction ;
}

void cPtr_gtlBreakpointListInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlBreakpointListInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlBreakpointListInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlBreakpointListInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlBreakpointListInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointListInstruction ("gtlBreakpointListInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBreakpointListInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointListInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBreakpointListInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointListInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointListInstruction GALGAS_gtlBreakpointListInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointListInstruction result ;
  const GALGAS_gtlBreakpointListInstruction * p = (const GALGAS_gtlBreakpointListInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpointListInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointListInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlContinueInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlContinueInstruction * p = (const cPtr_gtlContinueInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlContinueInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlContinueInstruction::objectCompare (const GALGAS_gtlContinueInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContinueInstruction::GALGAS_gtlContinueInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContinueInstruction GALGAS_gtlContinueInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlContinueInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                         GALGAS_string::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContinueInstruction::GALGAS_gtlContinueInstruction (const cPtr_gtlContinueInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlContinueInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContinueInstruction GALGAS_gtlContinueInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_string & inAttribute_signature
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlContinueInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlContinueInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @gtlContinueInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlContinueInstruction::cPtr_gtlContinueInstruction (const GALGAS_location & in_where,
                                                          const GALGAS_string & in_signature
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlContinueInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContinueInstruction ;
}

void cPtr_gtlContinueInstruction::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlContinueInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlContinueInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlContinueInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlContinueInstruction type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlContinueInstruction ("gtlContinueInstruction",
                                               & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlContinueInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContinueInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlContinueInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlContinueInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContinueInstruction GALGAS_gtlContinueInstruction::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlContinueInstruction result ;
  const GALGAS_gtlContinueInstruction * p = (const GALGAS_gtlContinueInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlContinueInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlContinueInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlDisplayStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDisplayStatementInstruction * p = (const cPtr_gtlDisplayStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDisplayStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_variablePath.objectCompare (p->mAttribute_variablePath) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlDisplayStatementInstruction::objectCompare (const GALGAS_gtlDisplayStatementInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDisplayStatementInstruction::GALGAS_gtlDisplayStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDisplayStatementInstruction GALGAS_gtlDisplayStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlDisplayStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                                 COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDisplayStatementInstruction::GALGAS_gtlDisplayStatementInstruction (const cPtr_gtlDisplayStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDisplayStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDisplayStatementInstruction GALGAS_gtlDisplayStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_gtlVarPath & inAttribute_variablePath
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlDisplayStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_variablePath.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDisplayStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_variablePath COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlDisplayStatementInstruction::getter_variablePath (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlDisplayStatementInstruction * p = (const cPtr_gtlDisplayStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDisplayStatementInstruction) ;
    result = p->mAttribute_variablePath ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlDisplayStatementInstruction::getter_variablePath (UNUSED_LOCATION_ARGS) const {
  return mAttribute_variablePath ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @gtlDisplayStatementInstruction class                               *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlDisplayStatementInstruction::cPtr_gtlDisplayStatementInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_gtlVarPath & in_variablePath
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_variablePath (in_variablePath) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlDisplayStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ;
}

void cPtr_gtlDisplayStatementInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlDisplayStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_variablePath.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlDisplayStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlDisplayStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_variablePath COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlDisplayStatementInstruction type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ("gtlDisplayStatementInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDisplayStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDisplayStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDisplayStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDisplayStatementInstruction GALGAS_gtlDisplayStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlDisplayStatementInstruction result ;
  const GALGAS_gtlDisplayStatementInstruction * p = (const GALGAS_gtlDisplayStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDisplayStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDisplayStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlDoInstInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoInstInstruction * p = (const cPtr_gtlDoInstInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoInstInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_instructionToDo.objectCompare (p->mAttribute_instructionToDo) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlDoInstInstruction::objectCompare (const GALGAS_gtlDoInstInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstInstruction::GALGAS_gtlDoInstInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstInstruction::GALGAS_gtlDoInstInstruction (const cPtr_gtlDoInstInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoInstInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstInstruction GALGAS_gtlDoInstInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_string & inAttribute_signature,
                                                                          const GALGAS_gtlInstruction & inAttribute_instructionToDo
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_instructionToDo.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoInstInstruction (inAttribute_where, inAttribute_signature, inAttribute_instructionToDo COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction GALGAS_gtlDoInstInstruction::getter_instructionToDo (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstruction result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlDoInstInstruction * p = (const cPtr_gtlDoInstInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDoInstInstruction) ;
    result = p->mAttribute_instructionToDo ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction cPtr_gtlDoInstInstruction::getter_instructionToDo (UNUSED_LOCATION_ARGS) const {
  return mAttribute_instructionToDo ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlDoInstInstruction class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlDoInstInstruction::cPtr_gtlDoInstInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlInstruction & in_instructionToDo
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_instructionToDo (in_instructionToDo) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlDoInstInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstInstruction ;
}

void cPtr_gtlDoInstInstruction::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlDoInstInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_instructionToDo.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlDoInstInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlDoInstInstruction (mAttribute_where, mAttribute_signature, mAttribute_instructionToDo COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlDoInstInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDoInstInstruction ("gtlDoInstInstruction",
                                             & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDoInstInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDoInstInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoInstInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstInstruction GALGAS_gtlDoInstInstruction::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstInstruction result ;
  const GALGAS_gtlDoInstInstruction * p = (const GALGAS_gtlDoInstInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDoInstInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoInstInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlDoInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoInstruction * p = (const cPtr_gtlDoInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlDoInstruction::objectCompare (const GALGAS_gtlDoInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstruction::GALGAS_gtlDoInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstruction GALGAS_gtlDoInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlDoInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                   GALGAS_string::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstruction::GALGAS_gtlDoInstruction (const cPtr_gtlDoInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstruction GALGAS_gtlDoInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_string & inAttribute_signature
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlDoInstruction class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlDoInstruction::cPtr_gtlDoInstruction (const GALGAS_location & in_where,
                                              const GALGAS_string & in_signature
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlDoInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstruction ;
}

void cPtr_gtlDoInstruction::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlDoInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlDoInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlDoInstruction (mAttribute_where, mAttribute_signature COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlDoInstruction type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDoInstruction ("gtlDoInstruction",
                                         & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDoInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDoInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoInstruction GALGAS_gtlDoInstruction::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoInstruction result ;
  const GALGAS_gtlDoInstruction * p = (const GALGAS_gtlDoInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDoInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlDoNotInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDoNotInstruction * p = (const cPtr_gtlDoNotInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDoNotInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_numToDelete.objectCompare (p->mAttribute_numToDelete) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlDoNotInstruction::objectCompare (const GALGAS_gtlDoNotInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoNotInstruction::GALGAS_gtlDoNotInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoNotInstruction GALGAS_gtlDoNotInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlDoNotInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_string::constructor_default (HERE),
                                                      GALGAS_lbigint::constructor_default (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoNotInstruction::GALGAS_gtlDoNotInstruction (const cPtr_gtlDoNotInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDoNotInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoNotInstruction GALGAS_gtlDoNotInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_string & inAttribute_signature,
                                                                        const GALGAS_lbigint & inAttribute_numToDelete
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoNotInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_numToDelete.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDoNotInstruction (inAttribute_where, inAttribute_signature, inAttribute_numToDelete COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_gtlDoNotInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  GALGAS_lbigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlDoNotInstruction * p = (const cPtr_gtlDoNotInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDoNotInstruction) ;
    result = p->mAttribute_numToDelete ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cPtr_gtlDoNotInstruction::getter_numToDelete (UNUSED_LOCATION_ARGS) const {
  return mAttribute_numToDelete ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlDoNotInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlDoNotInstruction::cPtr_gtlDoNotInstruction (const GALGAS_location & in_where,
                                                    const GALGAS_string & in_signature,
                                                    const GALGAS_lbigint & in_numToDelete
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_numToDelete (in_numToDelete) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlDoNotInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoNotInstruction ;
}

void cPtr_gtlDoNotInstruction::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlDoNotInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_numToDelete.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlDoNotInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlDoNotInstruction (mAttribute_where, mAttribute_signature, mAttribute_numToDelete COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlDoNotInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDoNotInstruction ("gtlDoNotInstruction",
                                            & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDoNotInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDoNotInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDoNotInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDoNotInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDoNotInstruction GALGAS_gtlDoNotInstruction::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDoNotInstruction result ;
  const GALGAS_gtlDoNotInstruction * p = (const GALGAS_gtlDoNotInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDoNotInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDoNotInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlEmitInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlEmitInstruction * p = (const cPtr_gtlEmitInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlEmitInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlEmitInstruction::objectCompare (const GALGAS_gtlEmitInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEmitInstruction::GALGAS_gtlEmitInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEmitInstruction::GALGAS_gtlEmitInstruction (const cPtr_gtlEmitInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlEmitInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEmitInstruction GALGAS_gtlEmitInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_string & inAttribute_signature,
                                                                      const GALGAS_gtlExpression & inAttribute_rValue
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlEmitInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlEmitInstruction (inAttribute_where, inAttribute_signature, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlEmitInstruction::getter_rValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlEmitInstruction * p = (const cPtr_gtlEmitInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlEmitInstruction) ;
    result = p->mAttribute_rValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlEmitInstruction::getter_rValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_rValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlEmitInstruction class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlEmitInstruction::cPtr_gtlEmitInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature,
                                                  const GALGAS_gtlExpression & in_rValue
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_rValue (in_rValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlEmitInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEmitInstruction ;
}

void cPtr_gtlEmitInstruction::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlEmitInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlEmitInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlEmitInstruction (mAttribute_where, mAttribute_signature, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlEmitInstruction type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlEmitInstruction ("gtlEmitInstruction",
                                           & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlEmitInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEmitInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlEmitInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlEmitInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlEmitInstruction GALGAS_gtlEmitInstruction::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlEmitInstruction result ;
  const GALGAS_gtlEmitInstruction * p = (const GALGAS_gtlEmitInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlEmitInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlEmitInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlErrorStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_identifier.objectCompare (p->mAttribute_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_hereInstead.objectCompare (p->mAttribute_hereInstead) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_errorMessage.objectCompare (p->mAttribute_errorMessage) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlErrorStatementInstruction::objectCompare (const GALGAS_gtlErrorStatementInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlErrorStatementInstruction::GALGAS_gtlErrorStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlErrorStatementInstruction::GALGAS_gtlErrorStatementInstruction (const cPtr_gtlErrorStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlErrorStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlErrorStatementInstruction GALGAS_gtlErrorStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                          const GALGAS_string & inAttribute_signature,
                                                                                          const GALGAS_gtlVarPath & inAttribute_identifier,
                                                                                          const GALGAS_bool & inAttribute_hereInstead,
                                                                                          const GALGAS_gtlExpression & inAttribute_errorMessage
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlErrorStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_identifier.isValid () && inAttribute_hereInstead.isValid () && inAttribute_errorMessage.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlErrorStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_identifier, inAttribute_hereInstead, inAttribute_errorMessage COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlErrorStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    result = p->mAttribute_identifier ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath cPtr_gtlErrorStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mAttribute_identifier ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlErrorStatementInstruction::getter_hereInstead (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    result = p->mAttribute_hereInstead ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlErrorStatementInstruction::getter_hereInstead (UNUSED_LOCATION_ARGS) const {
  return mAttribute_hereInstead ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlErrorStatementInstruction::getter_errorMessage (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlErrorStatementInstruction * p = (const cPtr_gtlErrorStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlErrorStatementInstruction) ;
    result = p->mAttribute_errorMessage ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlErrorStatementInstruction::getter_errorMessage (UNUSED_LOCATION_ARGS) const {
  return mAttribute_errorMessage ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @gtlErrorStatementInstruction class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlErrorStatementInstruction::cPtr_gtlErrorStatementInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_gtlVarPath & in_identifier,
                                                                      const GALGAS_bool & in_hereInstead,
                                                                      const GALGAS_gtlExpression & in_errorMessage
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_identifier (in_identifier),
mAttribute_hereInstead (in_hereInstead),
mAttribute_errorMessage (in_errorMessage) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlErrorStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;
}

void cPtr_gtlErrorStatementInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlErrorStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_identifier.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_hereInstead.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_errorMessage.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlErrorStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlErrorStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_identifier, mAttribute_hereInstead, mAttribute_errorMessage COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @gtlErrorStatementInstruction type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ("gtlErrorStatementInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlErrorStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlErrorStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlErrorStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlErrorStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlErrorStatementInstruction GALGAS_gtlErrorStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlErrorStatementInstruction result ;
  const GALGAS_gtlErrorStatementInstruction * p = (const GALGAS_gtlErrorStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlErrorStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlErrorStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlForStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_identifier.objectCompare (p->mAttribute_identifier) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_iterable.objectCompare (p->mAttribute_iterable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_betweenList.objectCompare (p->mAttribute_betweenList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_doList.objectCompare (p->mAttribute_doList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlForStatementInstruction::objectCompare (const GALGAS_gtlForStatementInstruction & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForStatementInstruction::GALGAS_gtlForStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForStatementInstruction GALGAS_gtlForStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlForStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                             GALGAS_string::constructor_default (HERE),
                                                             GALGAS_lstring::constructor_default (HERE),
                                                             GALGAS_gtlExpressionList::constructor_emptyList (HERE),
                                                             GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                             GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                                             COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForStatementInstruction::GALGAS_gtlForStatementInstruction (const cPtr_gtlForStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlForStatementInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForStatementInstruction GALGAS_gtlForStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_string & inAttribute_signature,
                                                                                      const GALGAS_lstring & inAttribute_identifier,
                                                                                      const GALGAS_gtlExpressionList & inAttribute_iterable,
                                                                                      const GALGAS_gtlInstructionList & inAttribute_betweenList,
                                                                                      const GALGAS_gtlInstructionList & inAttribute_doList
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlForStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_identifier.isValid () && inAttribute_iterable.isValid () && inAttribute_betweenList.isValid () && inAttribute_doList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlForStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_identifier, inAttribute_iterable, inAttribute_betweenList, inAttribute_doList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlForStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    result = p->mAttribute_identifier ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlForStatementInstruction::getter_identifier (UNUSED_LOCATION_ARGS) const {
  return mAttribute_identifier ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlForStatementInstruction::getter_iterable (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    result = p->mAttribute_iterable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList cPtr_gtlForStatementInstruction::getter_iterable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_iterable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlForStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    result = p->mAttribute_betweenList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlForStatementInstruction::getter_betweenList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_betweenList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlForStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlForStatementInstruction * p = (const cPtr_gtlForStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlForStatementInstruction) ;
    result = p->mAttribute_doList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cPtr_gtlForStatementInstruction::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_doList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlForStatementInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlForStatementInstruction::cPtr_gtlForStatementInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_lstring & in_identifier,
                                                                  const GALGAS_gtlExpressionList & in_iterable,
                                                                  const GALGAS_gtlInstructionList & in_betweenList,
                                                                  const GALGAS_gtlInstructionList & in_doList
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mAttribute_identifier (in_identifier),
mAttribute_iterable (in_iterable),
mAttribute_betweenList (in_betweenList),
mAttribute_doList (in_doList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlForStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForStatementInstruction ;
}

void cPtr_gtlForStatementInstruction::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlForStatementInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_identifier.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_iterable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_betweenList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_doList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlForStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlForStatementInstruction (mAttribute_where, mAttribute_signature, mAttribute_identifier, mAttribute_iterable, mAttribute_betweenList, mAttribute_doList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlForStatementInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlForStatementInstruction ("gtlForStatementInstruction",
                                                   & kTypeDescriptor_GALGAS_gtlInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlForStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlForStatementInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlForStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlForStatementInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlForStatementInstruction GALGAS_gtlForStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlForStatementInstruction result ;
  const GALGAS_gtlForStatementInstruction * p = (const GALGAS_gtlForStatementInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlForStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlForStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}


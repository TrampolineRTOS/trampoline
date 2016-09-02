#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-10.h"


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
//                                Overriding extension getter '@goilContext fullPrefix'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_goilContext_fullPrefix (const cPtr_gtlContext * inObject,
                                                              const GALGAS_gtlData & constinArgument_vars,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_full ; // Returned variable
  const cPtr_goilContext * object = (const cPtr_goilContext *) inObject ;
  macroValidSharedObject (object, cPtr_goilContext) ;
  GALGAS_string var_stringPrefix_22305 = object->mAttribute_prefix.getter_string (SOURCE_FILE ("goil_code_generation.galgas", 689)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("compiler").objectCompare (var_stringPrefix_22305)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlData var_compiler_22414 ;
    callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)), var_compiler_22414, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)) ;
    GALGAS_gtlString temp_1 ;
    if (var_compiler_22414.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlString *> (var_compiler_22414.ptr ())) {
        temp_1 = (cPtr_gtlString *) var_compiler_22414.ptr () ;
      }else{
        inCompiler->castError ("gtlString", var_compiler_22414.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
      }
    }
    var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("linker").objectCompare (var_stringPrefix_22305)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_gtlData var_linker_22563 ;
      callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)), var_linker_22563, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)) ;
      GALGAS_gtlString temp_3 ;
      if (var_linker_22563.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (var_linker_22563.ptr ())) {
          temp_3 = (cPtr_gtlString *) var_linker_22563.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_linker_22563.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
        }
      }
      var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_3.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("assembler").objectCompare (var_stringPrefix_22305)).boolEnum () ;
      if (kBoolTrue == test_4) {
        GALGAS_gtlData var_assembler_22719 ;
        callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)), var_assembler_22719, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)) ;
        GALGAS_gtlString temp_5 ;
        if (var_assembler_22719.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlString *> (var_assembler_22719.ptr ())) {
            temp_5 = (cPtr_gtlString *) var_assembler_22719.ptr () ;
          }else{
            inCompiler->castError ("gtlString", var_assembler_22719.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
          }
        }
        var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_5.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
      }else if (kBoolFalse == test_4) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_stringPrefix_22305.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
        if (kBoolTrue == test_6) {
          var_stringPrefix_22305 = GALGAS_string::makeEmptyString () ;
        }
      }
    }
  }
  result_full = GALGAS_lstring::constructor_new (var_stringPrefix_22305, object->mAttribute_prefix.getter_location (SOURCE_FILE ("goil_code_generation.galgas", 702))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 702)) ;
//---
  return result_full ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_goilContext_fullPrefix (void) {
  enterExtensionGetter_fullPrefix (kTypeDescriptor_GALGAS_goilContext.mSlotID,
                                   extensionGetter_goilContext_fullPrefix) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_goilContext_fullPrefix (defineExtensionGetter_goilContext_fullPrefix, NULL) ;

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


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  NULL
} ;    

//---------------------------------------------------------------------------------------------------------------------*

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  NULL
} ;    

//---------------------------------------------------------------------------------------------------------------------*

const char * projectVersionString (void) {
  return "3.0.5" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_1'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'programRule_2'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonLexique = NULL ;
    macroMyNew (commonLexique, C_Compiler (NULL, "", "" COMMA_HERE)) ;
    try{
      routine_before (commonLexique COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonLexique) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonLexique->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "oil") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "OIL") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__31_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "goilTemplate") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__32_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonLexique COMMA_HERE) ;
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonLexique) ;
  }
  return returnCode ;
}


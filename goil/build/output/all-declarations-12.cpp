#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-12.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Routine 'generate_signed_type'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_generate_5F_signed_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                         GALGAS_string inArgument_err,
                                         GALGAS_string & outArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_s_38__1049 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 7U), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 37)) ;
  GALGAS_uint_36__34_ var_max_5F_s_31__36__1078 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 15U), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 38)) ;
  GALGAS_uint_36__34_ var_max_5F_s_33__32__1107 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 31U), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 39)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38__1049)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("s8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36__1078)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("s16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32__1107)).boolEnum () ;
        if (kBoolTrue == test_2) {
          outArgument_type = GALGAS_string ("s32") ;
        }
      }
      if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)) ;
      }
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'generate_unsigned_type'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_generate_5F_unsigned_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                           GALGAS_string inArgument_err,
                                           GALGAS_string & outArgument_type,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1496 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 8U), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 62)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1525 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 16U), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 63)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1554 = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 32U), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 64)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38__1496)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("u8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36__1525)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("u16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32__1554)).boolEnum () ;
        if (kBoolTrue == test_2) {
          outArgument_type = GALGAS_string ("u32") ;
        }
      }
      if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)) ;
      }
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Routine 'generate_mask_type'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_generate_5F_mask_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                       GALGAS_string inArgument_err,
                                       GALGAS_string & outArgument_type,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38__1937 = GALGAS_uint_36__34_ ((uint64_t) 8ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36__1961 = GALGAS_uint_36__34_ ((uint64_t) 16ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32__1985 = GALGAS_uint_36__34_ ((uint64_t) 32ULL) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38__1937)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_type = GALGAS_string ("u8") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36__1961)).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_type = GALGAS_string ("u16") ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32__1985)).boolEnum () ;
        if (kBoolTrue == test_2) {
          outArgument_type = GALGAS_string ("u32") ;
        }
      }
      if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)), inArgument_err, fixItArray3  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)) ;
      }
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@goilContext fullPrefix'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_goilContext_fullPrefix (const cPtr_gtlContext * inObject,
                                                              const GALGAS_gtlData constinArgument_vars,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_full ; // Returned variable
  const cPtr_goilContext * object = (const cPtr_goilContext *) inObject ;
  macroValidSharedObject (object, cPtr_goilContext) ;
  GALGAS_string var_stringPrefix_22305 = object->mProperty_prefix.getter_string (SOURCE_FILE ("goil_code_generation.galgas", 689)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("compiler").objectCompare (var_stringPrefix_22305)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlData var_compiler_22414 ;
      GALGAS_bool joker_22416 ; // Joker input parameter
      callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)), var_compiler_22414, joker_22416, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 691)) ;
      GALGAS_gtlString temp_1 ;
      if (var_compiler_22414.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (var_compiler_22414.ptr ())) {
          temp_1 = (cPtr_gtlString *) var_compiler_22414.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_compiler_22414.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
        }
      }
      var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 692)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("linker").objectCompare (var_stringPrefix_22305)).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_gtlData var_linker_22566 ;
        GALGAS_bool joker_22568 ; // Joker input parameter
        callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)), var_linker_22566, joker_22568, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 694)) ;
        GALGAS_gtlString temp_3 ;
        if (var_linker_22566.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlString *> (var_linker_22566.ptr ())) {
            temp_3 = (cPtr_gtlString *) var_linker_22566.ptr () ;
          }else{
            inCompiler->castError ("gtlString", var_linker_22566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
          }
        }
        var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_3.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("assembler").objectCompare (var_stringPrefix_22305)).boolEnum () ;
        if (kBoolTrue == test_4) {
          GALGAS_gtlData var_assembler_22725 ;
          GALGAS_bool joker_22727 ; // Joker input parameter
          callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_vars.ptr (), function_lstring (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)), var_assembler_22725, joker_22727, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 697)) ;
          GALGAS_gtlString temp_5 ;
          if (var_assembler_22725.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlString *> (var_assembler_22725.ptr ())) {
              temp_5 = (cPtr_gtlString *) var_assembler_22725.ptr () ;
            }else{
              inCompiler->castError ("gtlString", var_assembler_22725.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
            }
          }
          var_stringPrefix_22305.plusAssign_operation(GALGAS_string ("/").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) temp_5.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)), inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 698)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, var_stringPrefix_22305.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
          if (kBoolTrue == test_6) {
            var_stringPrefix_22305 = GALGAS_string::makeEmptyString () ;
          }
        }
      }
    }
  }
  result_full = GALGAS_lstring::constructor_new (var_stringPrefix_22305, object->mProperty_prefix.getter_location (SOURCE_FILE ("goil_code_generation.galgas", 702))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 702)) ;
//---
  return result_full ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_goilContext_fullPrefix (void) {
  enterExtensionGetter_fullPrefix (kTypeDescriptor_GALGAS_goilContext.mSlotID,
                                   extensionGetter_goilContext_fullPrefix) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_goilContext_fullPrefix (defineExtensionGetter_goilContext_fullPrefix, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Function 'emptyGoilContext'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_goilContext function_emptyGoilContext (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_goilContext result_context ; // Returned variable
  result_context = GALGAS_goilContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 710)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string (".gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 715)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 716)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 718))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 709)) ;
//---
  return result_context ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//  Function introspection                                                                                             *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const C_galgas_type_descriptor * functionArgs_emptyGoilContext [1] = {
  NULL
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_object functionWithGenericHeader_emptyGoilContext (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_emptyGoilContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_galgas_function_descriptor functionDescriptor_emptyGoilContext ("emptyGoilContext",
                                                                  functionWithGenericHeader_emptyGoilContext,
                                                                  & kTypeDescriptor_GALGAS_goilContext,
                                                                  0,
                                                                  functionArgs_emptyGoilContext) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'generate_all'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_generate_5F_all (GALGAS_gtlData inArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir_23411 = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 735)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir_23411.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_target_23489 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_target_23489.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlContext var_context_23593 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 741)) ;
          {
          var_context_23593.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 743)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 742)) ;
          }
          {
          var_context_23593.setter_setUserTemplateDirectory (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_code_generation.galgas", 746)).add_operation (GALGAS_string ("/templates"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 745)) ;
          }
          {
          var_context_23593.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 749)) ;
          }
          {
          var_context_23593.insulate (HERE) ;
          cPtr_gtlContext * ptr_23977 = (cPtr_gtlContext *) var_context_23593.ptr () ;
          callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_23977, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 753)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 752)) ;
          }
          {
          var_context_23593.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 756)) ;
          }
          GALGAS_library var_lib_24205 = function_emptyLib (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) ;
          GALGAS_string var_goilLog_24248 = function_invokeGTL (GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 763)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 764)), GALGAS_string (gOption_goil_5F_options_root.getter_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 762)), var_context_23593, inArgument_cfg, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 761)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ()).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_goilLog_24248.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 772)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 776)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 779)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'getAutosarVersion'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_getAutosarVersion (GALGAS_arxmlNode inArgument_rootNode,
                                GALGAS_lstring & outArgument_iAutosarVersion,
                                GALGAS_lstring & outArgument_iAutosarDescription,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_iAutosarVersion.drop () ; // Release 'out' argument
  outArgument_iAutosarDescription.drop () ; // Release 'out' argument
  GALGAS_lstring var_autosarVersion_7850 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 273)) ;
  GALGAS_lstring var_autosarDescription_7899 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 274)) ;
  GALGAS_arxmlElementList var_autosarNodes_8018 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 277)) ;
  callExtensionMethod_getSubElementsFromName ((const cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_8018, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 278)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_8018.getter_length (SOURCE_FILE ("arxml_parser.galgas", 279)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)) ;
    }
  }
  GALGAS_arxmlElementList var_adminDataNodes_8237 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 283)) ;
  extensionMethod_getSubElementsFromName (var_autosarNodes_8018, GALGAS_string ("ADMIN-DATA"), var_adminDataNodes_8237, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 284)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_adminDataNodes_8237.getter_length (SOURCE_FILE ("arxml_parser.galgas", 285)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)), GALGAS_string ("[TPS_ECUC_06004] : Missing AUTOSAR's ADMIN-DATA node."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)) ;
    }
  }
  GALGAS_arxmlElementList var_revisions_8471 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 289)) ;
  extensionMethod_getElementsFromName (var_adminDataNodes_8237, GALGAS_string ("DOC-REVISION"), var_revisions_8471, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 290)) ;
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, var_adminDataNodes_8237.getter_length (SOURCE_FILE ("arxml_parser.galgas", 291)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_4) {
      TC_Array <C_FixItDescription> fixItArray5 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)), GALGAS_string ("Missing AUTOSAR'S ADMIN-DATA's DOC-REVISION NODE"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)) ;
    }
  }
  GALGAS_bool var_version_5F_found_8688 = GALGAS_bool (false) ;
  GALGAS_bool var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
  GALGAS_lstring var_issued_5F_by_8749 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 297)) ;
  cEnumerator_arxmlElementList enumerator_8817 (var_revisions_8471, kENUMERATION_UP) ;
  bool bool_6 = var_version_5F_found_8688.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
  if (enumerator_8817.hasCurrentObject () && bool_6) {
    while (enumerator_8817.hasCurrentObject () && bool_6) {
      var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
      callExtensionMethod_getProperty ((const cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("ISSUED-BY"), var_issued_5F_by_8749, var_issued_5F_by_5F_found_8720, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 302)) ;
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        GALGAS_bool test_8 = var_issued_5F_by_5F_found_8720 ;
        if (kBoolTrue == test_8.boolEnum ()) {
          test_8 = GALGAS_bool (kIsEqual, var_issued_5F_by_8749.getter_string (HERE).objectCompare (GALGAS_string ("AUTOSAR"))) ;
        }
        test_7 = test_8.boolEnum () ;
        if (kBoolTrue == test_7) {
          GALGAS_bool var_description_5F_found_9035 = GALGAS_bool (false) ;
          callExtensionMethod_getProperty ((const cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("REVISION-LABEL"), var_autosarVersion_7850, var_version_5F_found_8688, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 305)) ;
          callExtensionMethod_getProperty ((const cPtr_arxmlElementNode *) enumerator_8817.current_node (HERE).ptr (), GALGAS_string ("DATE"), var_autosarDescription_7899, var_description_5F_found_9035, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 306)) ;
        }
      }
      enumerator_8817.gotoNextObject () ;
      if (enumerator_8817.hasCurrentObject ()) {
        bool_6 = var_version_5F_found_8688.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
      }
    }
  }
  outArgument_iAutosarVersion = var_autosarVersion_7850 ;
  outArgument_iAutosarDescription = var_autosarDescription_7899 ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              Routine 'includeConfigs'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_includeConfigs (GALGAS_implementation & ioArgument_imp,
                             GALGAS_applicationDefinition & ioArgument_application,
                             GALGAS_string & ioArgument_fileIncludeList,
                             GALGAS_lstring inArgument_version,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_config_5F_file_5F_name_9570 = GALGAS_string (gOption_goil_5F_options_config.getter_value ()) ;
  GALGAS_stringlist var_configFiles_9635 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9570.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 325)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 324)) ;
  cEnumerator_stringlist enumerator_9903 (var_configFiles_9635, kENUMERATION_DOWN) ;
  while (enumerator_9903.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_9903.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)) ;
    enumerator_9903.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_10208 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9570.add_operation (inArgument_version.getter_string (SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 336)) ;
  cEnumerator_stringlist enumerator_10369 (var_configVersionFiles_10208, kENUMERATION_DOWN) ;
  while (enumerator_10369.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_10369.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)) ;
    enumerator_10369.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'nodeToClass'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_nodeToClass (GALGAS_arxmlNode inArgument_rootNode,
                          GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                          GALGAS_arxmlElementValue & outArgument_rootValue,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_rootValue.drop () ; // Release 'out' argument
  GALGAS_arxmlElementList var_autosarNodes_10723 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 351)) ;
  callExtensionMethod_getSubElementsFromName ((const cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_10723, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_10723.getter_length (SOURCE_FILE ("arxml_parser.galgas", 353)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsStrictSup, var_autosarNodes_10723.getter_length (SOURCE_FILE ("arxml_parser.galgas", 356)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)), GALGAS_string ("[TPS_GST_00077] : Too many AUTOSAR nodes."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)) ;
    }
  }
  GALGAS_arxmlElementNode var_autosarNode_11078 ;
  var_autosarNodes_10723.method_first (var_autosarNode_11078, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 362)) ;
  {
  routine_nodeToClassRes (var_autosarNode_11078, ioArgument_classMap, outArgument_rootValue, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 363)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              Routine 'nodeToClassRes'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_nodeToClassRes (GALGAS_arxmlElementNode inArgument_currentElement,
                             GALGAS_arxmlMetaClassMap inArgument_classMap,
                             GALGAS_arxmlElementValue & outArgument_elementValue,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_elementValue.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClass var_currentClass_11349 ;
  inArgument_classMap.method_searchKey (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 373)), var_currentClass_11349, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 373)) ;
  GALGAS_bool var_textFound_11455 = GALGAS_bool (false) ;
  GALGAS_lstring var_text_11479 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 377))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 377)) ;
  callExtensionMethod_getText ((const cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_text_11479, var_textFound_11455, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 378)) ;
  GALGAS_lstring var_type_11593 = var_currentClass_11349.getter_name (SOURCE_FILE ("arxml_parser.galgas", 381)) ;
  outArgument_elementValue = GALGAS_arxmlElementValue::constructor_new (var_type_11593, var_text_11479, GALGAS_arxmlElementValueMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 385)), inArgument_currentElement.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 386))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 382)) ;
  GALGAS_arxmlElementList var_subElements_12002 ;
  callExtensionMethod_getSubElements ((const cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_subElements_12002, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 390)) ;
  cEnumerator_arxmlElementList enumerator_12055 (var_subElements_12002, kENUMERATION_UP) ;
  while (enumerator_12055.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlMetaClass *) var_currentClass_11349.ptr (), enumerator_12055.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 392)).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 392)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 392)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_12055.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 393)).getter_location (SOURCE_FILE ("arxml_parser.galgas", 393)), GALGAS_string ("The element ").add_operation (enumerator_12055.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 393)).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 395)).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 394)).add_operation (GALGAS_string (" element.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (GALGAS_string ("Possible elements are :\n"
          " "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (extensionGetter_string (var_currentClass_11349.getter_lElementLegacy (SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)) ;
      }
    }
    enumerator_12055.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsNotEqual, inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 402)).getter_string (HERE).objectCompare (GALGAS_string ("AUTOSAR"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlAttributeMap enumerator_12593 (inArgument_currentElement.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 403)), kENUMERATION_UP) ;
      while (enumerator_12593.hasCurrentObject ()) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_hasAttribute ((const cPtr_arxmlMetaClass *) var_currentClass_11349.ptr (), enumerator_12593.current_lkey (HERE).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 404)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 404)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_12593.current_lkey (HERE).getter_location (SOURCE_FILE ("arxml_parser.galgas", 405)), GALGAS_string ("The attribute ").add_operation (enumerator_12593.current_lkey (HERE).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 406)).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" element.\n"
              "Possible "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (GALGAS_string ("attributes are :\n"
              " "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (extensionGetter_string (var_currentClass_11349.getter_lAttributeLegacy (SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)) ;
          }
        }
        enumerator_12593.gotoNextObject () ;
      }
    }
  }
  cEnumerator_arxmlMetaElementList enumerator_13043 (var_currentClass_11349.getter_lElementLegacy (SOURCE_FILE ("arxml_parser.galgas", 413)), kENUMERATION_UP) ;
  while (enumerator_13043.hasCurrentObject ()) {
    GALGAS_arxmlElementList var_subElements_13080 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 414)) ;
    callExtensionMethod_getSubElementsFromName ((const cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), enumerator_13043.current_lElement (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 416)).getter_string (HERE), var_subElements_13080, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 416)) ;
    GALGAS_uint var_minOccurs_13297 = GALGAS_uint ((uint32_t) 1U) ;
    GALGAS_uint var_maxOccurs_13321 = GALGAS_uint ((uint32_t) 1U) ;
    enumGalgasBool test_5 = kBoolTrue ;
    if (kBoolTrue == test_5) {
      GALGAS_bool test_6 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxml_parser.galgas", 423)).getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue == test_6.boolEnum ()) {
        test_6 = enumerator_13043.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxml_parser.galgas", 424)).getter_string (HERE).getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 424)) ;
      }
      test_5 = test_6.boolEnum () ;
      if (kBoolTrue == test_5) {
        var_minOccurs_13297 = enumerator_13043.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxml_parser.galgas", 425)).getter_string (HERE).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 425)) ;
      }
    }
    enumGalgasBool test_7 = kBoolTrue ;
    if (kBoolTrue == test_7) {
      test_7 = GALGAS_bool (kIsStrictInf, var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 428)).objectCompare (var_minOccurs_13297)).boolEnum () ;
      if (kBoolTrue == test_7) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 429)).getter_location (SOURCE_FILE ("arxml_parser.galgas", 429)), GALGAS_string ("Missing element ").add_operation (enumerator_13043.current_lElement (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 429)).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (var_minOccurs_13297.getter_string (SOURCE_FILE ("arxml_parser.galgas", 430)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 431)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 431)), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)) ;
      }
    }
    enumGalgasBool test_9 = kBoolTrue ;
    if (kBoolTrue == test_9) {
      GALGAS_bool test_10 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 435)).getter_string (HERE).objectCompare (GALGAS_string ("unbounded"))) ;
      if (kBoolTrue == test_10.boolEnum ()) {
        test_10 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 436)).getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())) ;
      }
      test_9 = test_10.boolEnum () ;
      if (kBoolTrue == test_9) {
        enumGalgasBool test_11 = kBoolTrue ;
        if (kBoolTrue == test_11) {
          GALGAS_bool test_12 = GALGAS_bool (kIsNotEqual, enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 438)).getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())) ;
          if (kBoolTrue == test_12.boolEnum ()) {
            test_12 = enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 439)).getter_string (HERE).getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 439)) ;
          }
          test_11 = test_12.boolEnum () ;
          if (kBoolTrue == test_11) {
            var_maxOccurs_13321 = enumerator_13043.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxml_parser.galgas", 440)).getter_string (HERE).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 440)) ;
          }
        }
        enumGalgasBool test_13 = kBoolTrue ;
        if (kBoolTrue == test_13) {
          test_13 = GALGAS_bool (kIsStrictSup, var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 443)).objectCompare (var_maxOccurs_13321)).boolEnum () ;
          if (kBoolTrue == test_13) {
            GALGAS_arxmlElementNode var_subElement_14334 ;
            var_subElements_13080.method_last (var_subElement_14334, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)) ;
            TC_Array <C_FixItDescription> fixItArray14 ;
            inCompiler->emitSemanticError (inArgument_currentElement.getter_name (SOURCE_FILE ("arxml_parser.galgas", 446)).getter_location (SOURCE_FILE ("arxml_parser.galgas", 446)), GALGAS_string ("Too many node ").add_operation (enumerator_13043.current_lElement (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 446)).getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)).add_operation (var_minOccurs_13297.getter_string (SOURCE_FILE ("arxml_parser.galgas", 447)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (GALGAS_string (" ; Maximum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (var_maxOccurs_13321.getter_string (SOURCE_FILE ("arxml_parser.galgas", 447)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (GALGAS_string (". Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 447)).add_operation (var_subElements_13080.getter_length (SOURCE_FILE ("arxml_parser.galgas", 448)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 448)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 448)), fixItArray14  COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)) ;
          }
        }
      }
    }
    cEnumerator_arxmlElementList enumerator_14691 (var_subElements_13080, kENUMERATION_UP) ;
    while (enumerator_14691.hasCurrentObject ()) {
      GALGAS_arxmlElementValue var_subElementValue_14735 ;
      {
      routine_nodeToClassRes (enumerator_14691.current_node (HERE), inArgument_classMap, var_subElementValue_14735, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 455)) ;
      }
      {
      outArgument_elementValue.insulate (HERE) ;
      cPtr_arxmlElementValue * ptr_14818 = (cPtr_arxmlElementValue *) outArgument_elementValue.ptr () ;
      callExtensionSetter_insertElement ((cPtr_arxmlElementValue *) ptr_14818, enumerator_14691.current_node (HERE).getter_name (SOURCE_FILE ("arxml_parser.galgas", 456)), var_subElementValue_14735, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 456)) ;
      }
      enumerator_14691.gotoNextObject () ;
    }
    enumerator_13043.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  Routine 'addText'                                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_addText (GALGAS_arxmlNodeList & ioArgument_nodes,
                      const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                      C_Compiler * inCompiler
                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_s_14982 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 465)) ;
  GALGAS_string var_trimmedString_15040 = var_s_14982.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("arxml_parser.galgas", 466)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_trimmedString_15040.getter_length (SOURCE_FILE ("arxml_parser.galgas", 467)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_ls_15127 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = constinArgument_doNotCondenseWhiteSpaces.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_ls_15127 = GALGAS_lstring::constructor_new (var_s_14982, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_ls_15127 = GALGAS_lstring::constructor_new (var_trimmedString_15040, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 472))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 472)) ;
      }
      ioArgument_nodes.addAssign_operation (GALGAS_arxmlTextNode::constructor_new (var_ls_15127  COMMA_SOURCE_FILE ("arxml_parser.galgas", 475))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 475)) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'convertToOil'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_convertToOil (GALGAS_implementation & ioArgument_imp,
                           GALGAS_applicationDefinition & ioArgument_application,
                           GALGAS_arxmlElementValue inArgument_rootValue,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_emptyPath_15444 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 484))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 484)) ;
  GALGAS_arxmlElementValueList var_packages_15530 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 487)) ;
  GALGAS_stringlist var_packagesPath_15562 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 488)) ;
  var_packagesPath_15562.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 489)) ;
  var_packagesPath_15562.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 490)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_rootValue.ptr (), var_packagesPath_15562, var_packages_15530, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 491)) ;
  cEnumerator_arxmlElementValueList enumerator_15759 (var_packages_15530, kENUMERATION_UP) ;
  while (enumerator_15759.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_15759.current_value (HERE), var_emptyPath_15444, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 495)) ;
    }
    enumerator_15759.gotoNextObject () ;
  }
  cEnumerator_arxmlElementValueList enumerator_15893 (var_packages_15530, kENUMERATION_UP) ;
  while (enumerator_15893.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_15893.current_value (HERE), var_emptyPath_15444, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 500)) ;
    }
    enumerator_15893.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        Routine 'arxmlImplementationPackage'                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationPackage (GALGAS_implementation & ioArgument_imp,
                                         GALGAS_arxmlElementValue inArgument_packageElement,
                                         GALGAS_lstring inArgument_parentPath,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_16253 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 514)) ;
  GALGAS_lstring var_currentPath_16362 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 517)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 517)).add_operation (var_packageName_16253.getter_string (SOURCE_FILE ("arxml_parser.galgas", 517)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 517)), var_packageName_16253.getter_location (SOURCE_FILE ("arxml_parser.galgas", 518))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 517)) ;
  GALGAS_arxmlElementValueList var_definitions_16588 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 521)) ;
  GALGAS_stringlist var_definitionPath_16622 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 522)) ;
  var_definitionPath_16622.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 523)) ;
  var_definitionPath_16622.addAssign_operation (GALGAS_string ("ECUC-MODULE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 524)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_16622, var_definitions_16588, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 525)) ;
  cEnumerator_arxmlElementValueList enumerator_16817 (var_definitions_16588, kENUMERATION_UP) ;
  while (enumerator_16817.hasCurrentObject ()) {
    {
    routine_arxmlImplementationRoot (ioArgument_imp, enumerator_16817.current_value (HERE), var_currentPath_16362, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 527)) ;
    }
    enumerator_16817.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_16975 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 531)) ;
  GALGAS_stringlist var_packagesPath_17007 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 532)) ;
  var_packagesPath_17007.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 533)) ;
  var_packagesPath_17007.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 534)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_17007, var_packages_16975, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 535)) ;
  cEnumerator_arxmlElementValueList enumerator_17185 (var_packages_16975, kENUMERATION_UP) ;
  while (enumerator_17185.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_17185.current_value (HERE), var_currentPath_16362, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 537)) ;
    }
    enumerator_17185.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'arxmlImplementationRoot'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationRoot (GALGAS_implementation & ioArgument_implementation,
                                      GALGAS_arxmlElementValue inArgument_packageElement,
                                      GALGAS_lstring inArgument_parentPath,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_objectName_17433 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 547)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "IMPLEMENTATION ").add_operation (var_objectName_17433.getter_string (SOURCE_FILE ("arxml_parser.galgas", 548)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 548)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 548)) ;
  }
  GALGAS_lstring var_currentPath_17589 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 551)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 551)).add_operation (var_objectName_17433.getter_string (SOURCE_FILE ("arxml_parser.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 551)), inArgument_parentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 552))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 551)) ;
  GALGAS_lstring var_oil_5F_desc_17788 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_17788, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 555)) ;
  }
  GALGAS_lbool var_multiple_17879 ;
  {
  routine_arxmlGetMultiplicity (inArgument_packageElement, var_objectName_17433, var_multiple_17879, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 558)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_17941 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 561)) ;
  GALGAS_stringlist var_subDefsPath_17972 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 562)) ;
  var_subDefsPath_17972.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 563)) ;
  var_subDefsPath_17972.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 564)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_17972, var_subDefs_17941, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 565)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "{\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 567)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_18230 (var_subDefs_17941, kENUMERATION_UP) ;
  while (enumerator_18230.hasCurrentObject ()) {
    {
    routine_arxmlImplementationObject (ioArgument_implementation, enumerator_18230.current_value (HERE), var_currentPath_17589, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 571)) ;
    }
    enumerator_18230.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END IMPLEMENTATION ").add_operation (var_objectName_17433.getter_string (SOURCE_FILE ("arxml_parser.galgas", 574)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 574)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 574)).add_operation (var_oil_5F_desc_17788.getter_string (SOURCE_FILE ("arxml_parser.galgas", 575)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 575)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 575)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 574)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                         Routine 'arxmlImplementationObject'                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationObject (GALGAS_implementation & ioArgument_implementation,
                                        GALGAS_arxmlElementValue inArgument_packageElement,
                                        GALGAS_lstring inArgument_parentPath,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap var_imp_18584 = ioArgument_implementation.getter_imp (SOURCE_FILE ("arxml_parser.galgas", 583)) ;
  GALGAS_implementationObjectMap var_objectAttributes_18651 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 584)) ;
  GALGAS_lstring var_objectName_18803 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 588)) ;
  GALGAS_lstring var_currentPath_18911 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 591)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)).add_operation (var_objectName_18803.getter_string (SOURCE_FILE ("arxml_parser.galgas", 591)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)), inArgument_parentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 592))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)) ;
  GALGAS_lstring var_objectKind_19159 = var_objectName_18803 ;
  var_objectKind_19159.mProperty_string = var_objectName_18803.getter_string (SOURCE_FILE ("arxml_parser.galgas", 596)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 596)) ;
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_19159.getter_string (SOURCE_FILE ("arxml_parser.galgas", 598)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 598)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 598)) ;
  }
  GALGAS_lbool var_multiple_19377 ;
  {
  routine_arxmlGetMultiplicity (inArgument_packageElement, var_objectName_18803, var_multiple_19377, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 601)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "  {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 602)) ;
  }
  GALGAS_lstring var_oil_5F_desc_19492 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_19492, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 605)) ;
  }
  {
  routine_arxmlImplementationContainer (var_objectAttributes_18651, inArgument_packageElement, var_currentPath_18911, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 608)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  }; /* \"").add_operation (var_oil_5F_desc_19492.getter_string (SOURCE_FILE ("arxml_parser.galgas", 612)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 612)).add_operation (GALGAS_string ("\"*/\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 612)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 612)) ;
  }
  GALGAS_implementationObject var_newObject_19794 = GALGAS_implementationObject::constructor_new (var_multiple_19377, var_objectAttributes_18651  COMMA_SOURCE_FILE ("arxml_parser.galgas", 616)) ;
  GALGAS_implementationObject var_object_19964 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_18803.getter_string (SOURCE_FILE ("arxml_parser.galgas", 621)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 621)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_imp_18584.setter_del (var_objectName_18803, var_object_19964, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 622)) ;
      }
      var_object_19964 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_19964.ptr (), var_newObject_19794, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 623)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_object_19964 = var_newObject_19794 ;
  }
  {
  var_imp_18584.setter_put (var_objectName_18803, var_object_19964, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 629)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_18584 COMMA_SOURCE_FILE ("arxml_parser.galgas", 630)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       Routine 'arxmlImplementationContainer'                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainer (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                           GALGAS_arxmlElementValue inArgument_currentElement,
                                           GALGAS_lstring inArgument_parentPath,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_intParameters_20623 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 641)) ;
  GALGAS_stringlist var_intParametersPath_20660 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 642)) ;
  var_intParametersPath_20660.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 643)) ;
  var_intParametersPath_20660.addAssign_operation (GALGAS_string ("ECUC-INTEGER-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 644)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_intParametersPath_20660, var_intParameters_20623, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 645)) ;
  cEnumerator_arxmlElementValueList enumerator_20877 (var_intParameters_20623, kENUMERATION_UP) ;
  while (enumerator_20877.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_20907 ;
    GALGAS_impType var_type_20925 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_20907, var_type_20925, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 652)), enumerator_20877.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 650)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_20907, var_type_20925, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 655)) ;
    }
    enumerator_20877.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_floatParameters_21489 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 661)) ;
  GALGAS_stringlist var_floatParametersPath_21528 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 662)) ;
  var_floatParametersPath_21528.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 663)) ;
  var_floatParametersPath_21528.addAssign_operation (GALGAS_string ("ECUC-FLOAT-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 664)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_floatParametersPath_21528, var_floatParameters_21489, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 665)) ;
  cEnumerator_arxmlElementValueList enumerator_21753 (var_floatParameters_21489, kENUMERATION_UP) ;
  while (enumerator_21753.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_21783 ;
    GALGAS_impType var_type_21801 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_21783, var_type_21801, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 672)), enumerator_21753.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 670)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_21783, var_type_21801, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 675)) ;
    }
    enumerator_21753.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_stringParameters_22353 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 681)) ;
  GALGAS_stringlist var_stringParametersPath_22393 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 682)) ;
  var_stringParametersPath_22393.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 683)) ;
  var_stringParametersPath_22393.addAssign_operation (GALGAS_string ("ECUC-STRING-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 684)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_stringParametersPath_22393, var_stringParameters_22353, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 685)) ;
  cEnumerator_arxmlElementValueList enumerator_22624 (var_stringParameters_22353, kENUMERATION_UP) ;
  while (enumerator_22624.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_22654 ;
    GALGAS_impType var_type_22672 ;
    {
    routine_arxmlImplementationContainerString (var_attributeName_22654, var_type_22672, GALGAS_dataType::constructor_string (SOURCE_FILE ("arxml_parser.galgas", 692)), enumerator_22624.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 690)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_22654, var_type_22672, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 695)) ;
    }
    enumerator_22624.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_booleanParameters_23221 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 701)) ;
  GALGAS_stringlist var_booleanParametersPath_23262 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 702)) ;
  var_booleanParametersPath_23262.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 703)) ;
  var_booleanParametersPath_23262.addAssign_operation (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 704)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_booleanParametersPath_23262, var_booleanParameters_23221, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 705)) ;
  cEnumerator_arxmlElementValueList enumerator_23499 (var_booleanParameters_23221, kENUMERATION_UP) ;
  while (enumerator_23499.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_23529 ;
    GALGAS_impType var_type_23547 ;
    {
    routine_arxmlImplementationContainerBoolean (var_attributeName_23529, var_type_23547, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("arxml_parser.galgas", 712)), enumerator_23499.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 710)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_23529, var_type_23547, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 715)) ;
    }
    enumerator_23499.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_enumParameters_24096 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 721)) ;
  GALGAS_stringlist var_enumParametersPath_24134 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 722)) ;
  var_enumParametersPath_24134.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 723)) ;
  var_enumParametersPath_24134.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 724)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_enumParametersPath_24134, var_enumParameters_24096, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 725)) ;
  cEnumerator_arxmlElementValueList enumerator_24360 (var_enumParameters_24096, kENUMERATION_UP) ;
  while (enumerator_24360.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_24390 ;
    GALGAS_impType var_type_24408 ;
    {
    routine_arxmlImplementationContainerEnumeration (var_attributeName_24390, var_type_24408, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("arxml_parser.galgas", 732)), enumerator_24360.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 730)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_24390, var_type_24408, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 735)) ;
    }
    enumerator_24360.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_structParameters_24985 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 741)) ;
  GALGAS_stringlist var_structParametersPath_25025 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 742)) ;
  var_structParametersPath_25025.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 743)) ;
  var_structParametersPath_25025.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 744)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_25025, var_structParameters_24985, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 745)) ;
  cEnumerator_arxmlElementValueList enumerator_25268 (var_structParameters_24985, kENUMERATION_UP) ;
  while (enumerator_25268.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_25298 ;
    GALGAS_impType var_type_25316 ;
    {
    routine_arxmlImplementationContainerStructure (var_attributeName_25298, var_type_25316, GALGAS_dataType::constructor_structType (SOURCE_FILE ("arxml_parser.galgas", 752)), enumerator_25268.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 750)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_25298, var_type_25316, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 755)) ;
    }
    enumerator_25268.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_identParameters_25885 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 761)) ;
  GALGAS_stringlist var_identParametersPath_25924 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 762)) ;
  var_identParametersPath_25924.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 763)) ;
  var_identParametersPath_25924.addAssign_operation (GALGAS_string ("TPL-IDENTIFIER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 764)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_identParametersPath_25924, var_identParameters_25885, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 765)) ;
  cEnumerator_arxmlElementValueList enumerator_26147 (var_identParameters_25885, kENUMERATION_UP) ;
  while (enumerator_26147.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_26177 ;
    GALGAS_impType var_type_26195 ;
    {
    routine_arxmlImplementationContainerIdentifier (var_attributeName_26177, var_type_26195, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("arxml_parser.galgas", 772)), enumerator_26147.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 770)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_26177, var_type_26195, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 775)) ;
    }
    enumerator_26147.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_refParameters_26766 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 781)) ;
  GALGAS_stringlist var_refParametersPath_26803 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 782)) ;
  var_refParametersPath_26803.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 783)) ;
  var_refParametersPath_26803.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 784)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_26803, var_refParameters_26766, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 785)) ;
  cEnumerator_arxmlElementValueList enumerator_27016 (var_refParameters_26766, kENUMERATION_UP) ;
  while (enumerator_27016.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_27046 ;
    GALGAS_impType var_type_27064 ;
    {
    routine_arxmlImplementationContainerReference (var_attributeName_27046, var_type_27064, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("arxml_parser.galgas", 792)), enumerator_27016.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 790)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_27046, var_type_27064, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 795)) ;
    }
    enumerator_27016.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Routine 'arxmlImplementationContainerNumber'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerNumber (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_iType,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_dataType var_type_27689 = constinArgument_iType ;
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 811)) ;
  }
  GALGAS_lbool var_multiple_27843 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_27843, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 814)) ;
  }
  GALGAS_bool var_withAuto_27905 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_27905, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 817)) ;
  }
  GALGAS_lstring var_oil_5F_desc_27990 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_27990, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 820)) ;
  }
  GALGAS_attributeRange var_range_28140 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 826)) ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 826)) ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_min_28230 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 827)) ;
      GALGAS_lstring var_max_28287 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 828)) ;
      GALGAS_string var_minSignString_28353 = GALGAS_string::makeEmptyString () ;
      GALGAS_string var_maxSignString_28384 = GALGAS_string::makeEmptyString () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_max_28287.getter_string (SOURCE_FILE ("arxml_parser.galgas", 832)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 832)).objectCompare (GALGAS_string ("INF"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_max_28287.mProperty_string = GALGAS_sint_36__34_::constructor_max (SOURCE_FILE ("arxml_parser.galgas", 833)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 833)) ;
        }
      }
      GALGAS_bool var_minSign_28529 ;
      {
      routine_arxmlPopSign (var_min_28230, var_minSign_28529, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 836)) ;
      }
      GALGAS_bool var_maxSign_28568 ;
      {
      routine_arxmlPopSign (var_max_28287, var_maxSign_28568, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 837)) ;
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = var_minSign_28529.boolEnum () ;
        if (kBoolTrue == test_3) {
          var_minSignString_28353 = GALGAS_string ("-") ;
          var_type_27689 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 842)) ;
        }
      }
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = var_maxSign_28568.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_maxSignString_28384 = GALGAS_string ("-") ;
          var_type_27689 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 846)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27689, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 848)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 848)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 848)) ;
      }
      {
      routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 849)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 849)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 849)) ;
      }
      GALGAS_object_5F_t var_start_28911 ;
      GALGAS_object_5F_t var_stop_28930 ;
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        GALGAS_bool test_6 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 854)))) ;
        if (kBoolTrue != test_6.boolEnum ()) {
          test_6 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 854)))) ;
        }
        test_5 = test_6.boolEnum () ;
        if (kBoolTrue == test_5) {
          GALGAS_luint_36__34_ var_minVal_29030 = GALGAS_luint_36__34_::constructor_new (var_min_28230.getter_string (SOURCE_FILE ("arxml_parser.galgas", 856)).getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 856)), var_min_28230.getter_location (SOURCE_FILE ("arxml_parser.galgas", 857))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 855)) ;
          GALGAS_luint_36__34_ var_maxVal_29208 = GALGAS_luint_36__34_::constructor_new (var_max_28287.getter_string (SOURCE_FILE ("arxml_parser.galgas", 860)).getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)), var_max_28287.getter_location (SOURCE_FILE ("arxml_parser.galgas", 861))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)) ;
          {
          routine_displayOil (GALGAS_string ("[").add_operation (var_minSignString_28353, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)).add_operation (var_minVal_29030.getter_uint_36__34_ (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 863)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)).add_operation (var_maxSignString_28384, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)).add_operation (var_maxVal_29208.getter_uint_36__34_ (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 864)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)) ;
          }
          var_start_28911 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 865)), var_type_27689, var_minVal_29030, var_minSign_28529, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 865)) ;
          var_stop_28930 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 866)), var_type_27689, var_maxVal_29208, var_maxSign_28568, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 866)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 867)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_ldouble var_minVal_29710 = GALGAS_ldouble::constructor_new (var_min_28230.getter_string (SOURCE_FILE ("arxml_parser.galgas", 869)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 869)), var_min_28230.getter_location (SOURCE_FILE ("arxml_parser.galgas", 870))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 868)) ;
            GALGAS_ldouble var_maxVal_29877 = GALGAS_ldouble::constructor_new (var_max_28287.getter_string (SOURCE_FILE ("arxml_parser.galgas", 873)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)), var_max_28287.getter_location (SOURCE_FILE ("arxml_parser.galgas", 874))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)) ;
            {
            routine_displayOil (GALGAS_string ("[").add_operation (var_minVal_29710.getter_double (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 876)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)).add_operation (var_maxVal_29877.getter_double (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 876)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 876)) ;
            }
            var_start_28911 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)), var_type_27689, var_minVal_29710, var_minSign_28529, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)) ;
            var_stop_28930 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 878)), var_type_27689, var_maxVal_29877, var_maxSign_28568, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 878)) ;
          }
        }
        if (kBoolFalse == test_7) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)), GALGAS_string ("Internal error"), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)) ;
          var_start_28911.drop () ; // Release error dropped variable
          var_stop_28930.drop () ; // Release error dropped variable
        }
      }
      var_range_28140 = function_buildRange (var_type_27689, var_start_28911, var_stop_28930, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 882)) ;
    }
  }
  if (kBoolFalse == test_0) {
    {
    routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27689, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 884)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 884)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 884)) ;
    }
    {
    routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 885)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 885)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 885)) ;
    }
    var_range_28140 = GALGAS_noRange::constructor_new (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 886))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 886)) ;
  }
  GALGAS_object_5F_t var_defaultValue_30550 ;
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 891)).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_lstring var_value_30619 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 892)) ;
      GALGAS_bool var_sign_30736 ;
      {
      routine_arxmlPopSign (var_value_30619, var_sign_30736, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 895)) ;
      }
      enumGalgasBool test_10 = kBoolTrue ;
      if (kBoolTrue == test_10) {
        GALGAS_bool test_11 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 898)))) ;
        if (kBoolTrue != test_11.boolEnum ()) {
          test_11 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 898)))) ;
        }
        test_10 = test_11.boolEnum () ;
        if (kBoolTrue == test_10) {
          GALGAS_luint_36__34_ var_integerValue_30914 = GALGAS_luint_36__34_::constructor_new (var_value_30619.getter_string (SOURCE_FILE ("arxml_parser.galgas", 900)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 900)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 900)), var_value_30619.getter_location (SOURCE_FILE ("arxml_parser.galgas", 901))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 899)) ;
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_30914.getter_uint_36__34_ (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 902)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 902)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 902)) ;
          }
          var_defaultValue_30550 = function_checkAndGetIntegerNumber (var_oil_5F_desc_27990, var_type_27689, var_integerValue_30914, var_sign_30736, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 903)) ;
        }
      }
      if (kBoolFalse == test_10) {
        enumGalgasBool test_12 = kBoolTrue ;
        if (kBoolTrue == test_12) {
          test_12 = GALGAS_bool (kIsEqual, var_type_27689.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 907)))).boolEnum () ;
          if (kBoolTrue == test_12) {
            GALGAS_ldouble var_floatValue_31389 = GALGAS_ldouble::constructor_new (var_value_30619.getter_string (SOURCE_FILE ("arxml_parser.galgas", 909)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 909)), var_value_30619.getter_location (SOURCE_FILE ("arxml_parser.galgas", 910))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 908)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_31389.getter_double (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 911)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 911)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 911)) ;
            }
            var_defaultValue_30550 = function_checkAndGetFloatNumber (var_oil_5F_desc_27990, var_type_27689, var_floatValue_31389, var_sign_30736, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)) ;
          }
        }
        if (kBoolFalse == test_12) {
          TC_Array <C_FixItDescription> fixItArray13 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)), GALGAS_string ("Internal error"), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)) ;
          var_defaultValue_30550.drop () ; // Release error dropped variable
        }
      }
    }
  }
  if (kBoolFalse == test_9) {
    enumGalgasBool test_14 = kBoolTrue ;
    if (kBoolTrue == test_14) {
      test_14 = var_withAuto_27905.boolEnum () ;
      if (kBoolTrue == test_14) {
        var_defaultValue_30550 = GALGAS_auto::constructor_new (var_oil_5F_desc_27990, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 920))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 920)) ;
      }
    }
    if (kBoolFalse == test_14) {
      var_defaultValue_30550 = GALGAS_void::constructor_new (var_oil_5F_desc_27990, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 922))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_27990.getter_string (SOURCE_FILE ("arxml_parser.galgas", 924)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 924)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 924)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 924)) ;
  }
  GALGAS_locationList temp_15 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 927)) ;
  temp_15.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 927))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 927)) ;
  GALGAS_lstringlist temp_16 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 931)) ;
  temp_16.addAssign_operation (var_oil_5F_desc_27990  COMMA_SOURCE_FILE ("arxml_parser.galgas", 931)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_15, var_type_27689, outArgument_objectName, var_multiple_27843.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 930)), temp_16, var_withAuto_27905, var_defaultValue_30550, var_range_28140  COMMA_SOURCE_FILE ("arxml_parser.galgas", 927)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Routine 'arxmlImplementationContainerString'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerString (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_type,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 944)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 944)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 944)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 947)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 948)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 948)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 948)) ;
  }
  GALGAS_lbool var_multiple_32814 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_32814, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 951)) ;
  }
  GALGAS_bool var_withAuto_32876 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_32876, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 954)) ;
  }
  GALGAS_lstring var_oil_5F_desc_32961 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_32961, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 957)) ;
  }
  GALGAS_object_5F_t var_defaultValue_33007 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 962)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_33076 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 963)) ;
      {
      routine_displayOil (GALGAS_string (" = \"").add_operation (var_value_33076.getter_string (SOURCE_FILE ("arxml_parser.galgas", 964)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 964)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 964)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 964)) ;
      }
      var_defaultValue_33007 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_32961, var_value_33076.getter_location (SOURCE_FILE ("arxml_parser.galgas", 967)), var_value_33076.getter_string (SOURCE_FILE ("arxml_parser.galgas", 968))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 965)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_32876.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_33007 = GALGAS_auto::constructor_new (var_oil_5F_desc_32961, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 971))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 971)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_33007 = GALGAS_void::constructor_new (var_oil_5F_desc_32961, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 973))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 973)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_32961.getter_string (SOURCE_FILE ("arxml_parser.galgas", 975)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 975)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 975)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 975)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 979)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 979))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 979)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 983)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_32961  COMMA_SOURCE_FILE ("arxml_parser.galgas", 983)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_32814.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 982)), temp_3, var_withAuto_32876, var_defaultValue_33007  COMMA_SOURCE_FILE ("arxml_parser.galgas", 978)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Routine 'arxmlImplementationContainerBoolean'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerBoolean (GALGAS_lstring & outArgument_objectName,
                                                  GALGAS_impType & outArgument_options,
                                                  const GALGAS_dataType constinArgument_type,
                                                  GALGAS_arxmlElementValue inArgument_parameter,
                                                  GALGAS_lstring inArgument_parentPath,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 996)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 996)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 996)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 999)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1000)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1000)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1000)) ;
  }
  GALGAS_bool var_withAuto_34430 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_34430, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1003)) ;
  }
  GALGAS_lbool var_multiple_34520 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_34520, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1006)) ;
  }
  GALGAS_lstring var_oil_5F_desc_34605 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_34605, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1009)) ;
  }
  GALGAS_object_5F_t var_defaultValue_34650 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1013)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_34719 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1014)) ;
      GALGAS_bool var_booleanValue_34792 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_value_34719.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1016)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_value_34719.getter_string (HERE).objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_booleanValue_34792 = GALGAS_bool (true) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          GALGAS_bool test_4 = GALGAS_bool (kIsEqual, var_value_34719.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1019)).objectCompare (GALGAS_string ("FALSE"))) ;
          if (kBoolTrue != test_4.boolEnum ()) {
            test_4 = GALGAS_bool (kIsEqual, var_value_34719.getter_string (HERE).objectCompare (GALGAS_string ("0"))) ;
          }
          test_3 = test_4.boolEnum () ;
          if (kBoolTrue == test_3) {
            var_booleanValue_34792 = GALGAS_bool (false) ;
          }
        }
        if (kBoolFalse == test_3) {
          var_booleanValue_34792 = GALGAS_bool (false) ;
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_value_34719.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1024)), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1024)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_34792.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1026)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026)) ;
      }
      var_defaultValue_34650 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_34605, var_value_34719.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1029)), var_booleanValue_34792, GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1033))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1031))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1027)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_6 = kBoolTrue ;
    if (kBoolTrue == test_6) {
      test_6 = var_withAuto_34430.boolEnum () ;
      if (kBoolTrue == test_6) {
        var_defaultValue_34650 = GALGAS_auto::constructor_new (var_oil_5F_desc_34605, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1037))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1037)) ;
      }
    }
    if (kBoolFalse == test_6) {
      var_defaultValue_34650 = GALGAS_void::constructor_new (var_oil_5F_desc_34605, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1039))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1039)) ;
    }
  }
  GALGAS_implementationObjectMap var_structAttributes_35912 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1045)) ;
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SUB-CONTAINERS"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      routine_displayOil (GALGAS_string ("\n"
        "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1047)) ;
      }
      {
      routine_arxmlImplementationContainer (var_structAttributes_35912, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1048)) ;
      }
      {
      routine_displayOil (GALGAS_string ("\n"
        "    } : \"").add_operation (var_oil_5F_desc_34605.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1049)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1049)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1049)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1049)) ;
      }
    }
  }
  if (kBoolFalse == test_7) {
    {
    routine_displayOil (GALGAS_string (" : \"").add_operation (var_oil_5F_desc_34605.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1051)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
    }
  }
  GALGAS_locationList temp_8 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1056)) ;
  temp_8.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1056))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1056)) ;
  GALGAS_lstringlist temp_9 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1060)) ;
  temp_9.addAssign_operation (var_oil_5F_desc_34605  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1060)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_8, constinArgument_type, outArgument_objectName, var_multiple_34520.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1059)), temp_9, var_withAuto_34430, var_defaultValue_34650, var_structAttributes_35912, var_structAttributes_35912  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Routine 'arxmlImplementationContainerEnumeration'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerEnumeration (GALGAS_lstring & outArgument_objectName,
                                                      GALGAS_impType & outArgument_options,
                                                      const GALGAS_dataType constinArgument_type,
                                                      GALGAS_arxmlElementValue inArgument_parameter,
                                                      GALGAS_lstring /* inArgument_parentPath */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1075)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1075)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1075)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1078)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1079)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1079)).add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1079)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1079)) ;
  }
  GALGAS_bool var_withAuto_37069 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_37069, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1082)) ;
  }
  GALGAS_lbool var_multiple_37159 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_37159, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1085)) ;
  }
  GALGAS_lstring var_oil_5F_desc_37244 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_37244, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1088)) ;
  }
  GALGAS_enumValues var_enumValues_37336 = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1092)) ;
  GALGAS_arxmlElementValueList var_enumElementValues_37404 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1093)) ;
  GALGAS_stringlist var_enumElementValuesPath_37445 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1094)) ;
  var_enumElementValuesPath_37445.addAssign_operation (GALGAS_string ("LITERALS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1095)) ;
  var_enumElementValuesPath_37445.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-LITERAL-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1096)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), var_enumElementValuesPath_37445, var_enumElementValues_37404, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1097)) ;
  cEnumerator_arxmlElementValueList enumerator_37681 (var_enumElementValues_37404, kENUMERATION_UP) ;
  while (enumerator_37681.hasCurrentObject ()) {
    GALGAS_lstring var_enumValueName_37711 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) enumerator_37681.current_value (HERE).ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1099)) ;
    {
    var_enumValues_37336.setter_put (var_enumValueName_37711, GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1100)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1100)) ;
    }
    {
    routine_displayOil (var_enumValueName_37711.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1101)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1101)) ;
    }
    if (enumerator_37681.hasNextObject ()) {
      {
      routine_displayOil (GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1103)) ;
      }
    }
    enumerator_37681.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1105)) ;
  }
  GALGAS_object_5F_t var_defaultValue_37974 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1109)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_38043 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1110)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_value_38043.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1111)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111)) ;
      }
      var_defaultValue_37974 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_37244, var_value_38043.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1114)), var_value_38043.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1115)), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1118))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1116))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1112)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_37069.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_37974 = GALGAS_auto::constructor_new (var_oil_5F_desc_37244, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1122))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_37974 = GALGAS_void::constructor_new (var_oil_5F_desc_37244, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1124))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1124)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    " : \"").add_operation (var_oil_5F_desc_37244.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1127)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1127)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1127)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1127)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1131)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1131))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1131)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1135)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_37244  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1135)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_37159.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1134)), temp_3, var_withAuto_37069, var_defaultValue_37974, var_enumValues_37336  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Routine 'arxmlImplementationContainerStructure'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerStructure (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring inArgument_parentPath,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1153)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1154)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1154)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1154)) ;
  }
  GALGAS_lbool var_multiple_39596 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_39596, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1157)) ;
  }
  GALGAS_lstring var_oil_5F_desc_39681 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_39681, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1160)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1162)) ;
  }
  GALGAS_implementationObjectMap var_structAttributes_39756 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1165)) ;
  {
  routine_arxmlImplementationContainer (var_structAttributes_39756, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1166)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    } : \"").add_operation (var_oil_5F_desc_39681.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1168)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1172)) ;
  temp_0.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1172))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1172)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1176)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_39681  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1176)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_39596.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1175)), temp_1, var_structAttributes_39756  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Routine 'arxmlImplementationContainerIdentifier'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerIdentifier (GALGAS_lstring & outArgument_objectName,
                                                     GALGAS_impType & outArgument_options,
                                                     const GALGAS_dataType constinArgument_type,
                                                     GALGAS_arxmlElementValue inArgument_parameter,
                                                     GALGAS_lstring /* inArgument_parentPath */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1191)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1192)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1192)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1192)) ;
  }
  GALGAS_lbool var_multiple_40679 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_40679, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1195)) ;
  }
  GALGAS_bool var_withAuto_40741 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_40741, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1198)) ;
  }
  GALGAS_lstring var_oil_5F_desc_40826 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_40826, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1201)) ;
  }
  GALGAS_object_5F_t var_defaultValue_40871 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1205)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_40940 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1206)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_value_40940.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1207)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1207)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1207)) ;
      }
      var_defaultValue_40871 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_40826, var_value_40940.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1210)), var_value_40940.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1211))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1208)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_40741.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_40871 = GALGAS_auto::constructor_new (var_oil_5F_desc_40826, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1214))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1214)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_40871 = GALGAS_void::constructor_new (var_oil_5F_desc_40826, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1216))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1216)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_40826.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1218)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1222)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1222))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1222)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1226)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_40826  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1226)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_40679.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1225)), temp_3, var_withAuto_40741, var_defaultValue_40871  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Routine 'arxmlImplementationContainerReference'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerReference (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring /* inArgument_parentPath */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_lstring var_objectType_42134 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DESTINATION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1240)) ;
  var_objectType_42134.mProperty_string = var_objectType_42134.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1242)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1242)) ;
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_objectType_42134.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1243)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1243)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1243)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1246)) ;
  }
  {
  routine_displayOil (GALGAS_string (" ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1247)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1247)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1247)) ;
  }
  GALGAS_lbool var_multiple_42552 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_42552, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)) ;
  }
  GALGAS_lstring var_oil_5F_desc_42637 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_42637, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1253)) ;
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_42637.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1255)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1259)) ;
  temp_0.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1259))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1259)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1263)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_42637  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1263)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_42552.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1262)), temp_1, var_objectType_42134  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'arxmlDefinitionPackage'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionPackage (GALGAS_implementation & ioArgument_imp,
                                     GALGAS_applicationDefinition & ioArgument_application,
                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                     GALGAS_lstring inArgument_parentPath,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_43289 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1279)) ;
  GALGAS_lstring var_currentPath_43398 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1282)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)).add_operation (var_packageName_43289.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)), var_packageName_43289.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1283))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)) ;
  GALGAS_arxmlElementValueList var_definitions_43621 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1286)) ;
  GALGAS_stringlist var_definitionPath_43655 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1287)) ;
  var_definitionPath_43655.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1288)) ;
  var_definitionPath_43655.addAssign_operation (GALGAS_string ("ECUC-MODULE-CONFIGURATION-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1289)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_43655, var_definitions_43621, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1290)) ;
  cEnumerator_arxmlElementValueList enumerator_43867 (var_definitions_43621, kENUMERATION_UP) ;
  while (enumerator_43867.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionRoot (ioArgument_imp, ioArgument_application, enumerator_43867.current_value (HERE), var_currentPath_43398, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1292)) ;
    }
    enumerator_43867.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_44035 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1296)) ;
  GALGAS_stringlist var_packagesPath_44067 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1297)) ;
  var_packagesPath_44067.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1298)) ;
  var_packagesPath_44067.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1299)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_44067, var_packages_44035, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1300)) ;
  cEnumerator_arxmlElementValueList enumerator_44245 (var_packages_44035, kENUMERATION_UP) ;
  while (enumerator_44245.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_44245.current_value (HERE), var_currentPath_43398, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1302)) ;
    }
    enumerator_44245.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Routine 'arxmlDefinitionRoot'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionRoot (GALGAS_implementation & ioArgument_imp,
                                  GALGAS_applicationDefinition & ioArgument_application,
                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring /* inArgument_parentPath */,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_cpuName_44520 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1313)) ;
  GALGAS_lstring var_currentPath_44630 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1316)) ;
  GALGAS_objectsMap var_objects_44745 = ioArgument_application.getter_objects (SOURCE_FILE ("arxml_parser.galgas", 1319)) ;
  GALGAS_lstring var_oil_5F_desc_44858 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_44858, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1322)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_44920 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1325)) ;
  GALGAS_stringlist var_subDefsPath_44951 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1326)) ;
  var_subDefsPath_44951.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1327)) ;
  var_subDefsPath_44951.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1328)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_44951, var_subDefs_44920, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1329)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "CPU ").add_operation (var_cpuName_44520.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1331)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)).add_operation (GALGAS_string ("\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_45185 (var_subDefs_44920, kENUMERATION_UP) ;
  while (enumerator_45185.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionObject (ioArgument_imp, var_objects_44745, enumerator_45185.current_value (HERE), var_currentPath_44630, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1334)) ;
    }
    enumerator_45185.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setName (var_cpuName_44520 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1338)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_44745 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1339)) ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END CPU ").add_operation (var_cpuName_44520.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1341)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)).add_operation (var_oil_5F_desc_44858.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1342)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1342)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1342)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Routine 'arxmlDefinitionObject'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionObject (GALGAS_implementation & ioArgument_imp,
                                    GALGAS_objectsMap & ioArgument_objects,
                                    GALGAS_arxmlElementValue inArgument_currentElement,
                                    GALGAS_lstring inArgument_parentPath,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_currentPath_45657 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1352)) ;
  GALGAS_lstring var_objectKind_45779 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_currentPath_45657, var_objectKind_45779, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1353)) ;
  }
  GALGAS_implementationObject var_impObjOfKind_45840 = callExtensionGetter_impObject ((const cPtr_implementation *) ioArgument_imp.ptr (), var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1356)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1356)) ;
  GALGAS_objectKind var_objectsForKind_45908 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1357))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1357)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objects.getter_hasKey (var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1358)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1358)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_objects.setter_del (var_objectKind_45779, var_objectsForKind_45908, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1359)) ;
      }
    }
  }
  GALGAS_lstring var_objectName_46101 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1363)) ;
  GALGAS_objectAttributes var_object_46213 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1366)) ;
  GALGAS_objectKindMap var_objectsKind_46258 = var_objectsForKind_45908.getter_objects (SOURCE_FILE ("arxml_parser.galgas", 1367)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_impObjOfKind_45840.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1368)).getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1368)).objectCompare (GALGAS_bool (false))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_objectName_46101 = var_objectKind_45779 ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_objectsKind_46258.getter_hasKey (var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1376)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1376)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_objectsKind_46258.setter_del (var_objectName_46101, var_object_46213, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1377)) ;
      }
    }
  }
  GALGAS_lstring var_oil_5F_desc_46820 ;
  {
  routine_arxmlGetDescription (inArgument_currentElement, var_oil_5F_desc_46820, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1381)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (GALGAS_string ("\n"
    "  {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)) ;
  }
  {
  routine_arxmlDefinitionContainer (var_impObjOfKind_45840.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 1386)), var_object_46213, inArgument_currentElement, var_currentPath_45657, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  } : \"").add_operation (var_oil_5F_desc_46820.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1391)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)) ;
  }
  GALGAS_identifierMap var_attributes_47215 = var_object_46213.getter_objectParams (SOURCE_FILE ("arxml_parser.galgas", 1394)) ;
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_attributes_47215.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("arxml_parser.galgas", 1395)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 1395)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      var_attributes_47215.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_46101.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1396))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1396)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_46820, var_objectName_46101.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1398)), var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1399))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1397)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1396)) ;
      }
      {
      var_object_46213.setter_setObjectParams (var_attributes_47215 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1400)) ;
      }
    }
  }
  {
  var_objectsKind_46258.setter_put (var_objectName_46101, var_object_46213, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1402)) ;
  }
  {
  var_objectsForKind_45908.setter_setObjects (var_objectsKind_46258 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1403)) ;
  }
  {
  ioArgument_objects.setter_put (var_objectKind_45779, var_objectsForKind_45908, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1404)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionContainer'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionContainer (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                       GALGAS_lstring inArgument_currentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_textParameters_48011 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1414)) ;
  GALGAS_stringlist var_textParametersPath_48049 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1415)) ;
  var_textParametersPath_48049.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1416)) ;
  var_textParametersPath_48049.addAssign_operation (GALGAS_string ("ECUC-TEXTUAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1417)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_textParametersPath_48049, var_textParameters_48011, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1418)) ;
  GALGAS_arxmlElementValueList var_numParameters_48329 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1421)) ;
  GALGAS_stringlist var_numParametersPath_48366 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1422)) ;
  var_numParametersPath_48366.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1423)) ;
  var_numParametersPath_48366.addAssign_operation (GALGAS_string ("ECUC-NUMERICAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1424)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_numParametersPath_48366, var_numParameters_48329, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1425)) ;
  GALGAS_arxmlElementValueList var_refParameters_48615 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1428)) ;
  GALGAS_stringlist var_refParametersPath_48652 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1429)) ;
  var_refParametersPath_48652.addAssign_operation (GALGAS_string ("REFERENCE-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1430)) ;
  var_refParametersPath_48652.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1431)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_48652, var_refParameters_48615, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1432)) ;
  GALGAS_arxmlElementValueList var_structParameters_48898 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1435)) ;
  GALGAS_stringlist var_structParametersPath_48938 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1436)) ;
  var_structParametersPath_48938.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1437)) ;
  var_structParametersPath_48938.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1438)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_48938, var_structParameters_48898, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1439)) ;
  GALGAS_arxmlElementValueList var_allParameters_49181 = var_numParameters_48329.add_operation (var_textParameters_48011, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1442)).add_operation (var_refParameters_48615, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1443)).add_operation (var_structParameters_48898, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1444)) ;
  cEnumerator_arxmlElementValueList enumerator_49447 (var_allParameters_49181, kENUMERATION_UP) ;
  while (enumerator_49447.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionParameter (constinArgument_types, ioArgument_identifiers, enumerator_49447.current_value (HERE), inArgument_currentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1449)) ;
    }
    enumerator_49447.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionParameter'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionParameter (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_parameter,
                                       GALGAS_lstring inArgument_parentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t var_val_49732 ;
  GALGAS_lstring var_parameterPath_49757 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_lstring var_parameterType_49879 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_parameterPath_49757, var_parameterType_49879, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1462)) ;
  }
  GALGAS_bool var_typeOk_49920 = GALGAS_bool (false) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  GALGAS_impType var_type_49944 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("arxml_parser.galgas", 1468)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1468)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  GALGAS_lstring var_valueType_50216 = callExtensionGetter_getAttributeValueFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), GALGAS_string ("DEST"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1472)) ;
  GALGAS_lstring var_oil_5F_desc_50397 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1477))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1477)) ;
  GALGAS_bool var_isAuto_50553 = GALGAS_bool (false) ;
  GALGAS_lstring var_parameterValue_50587 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1484)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1488)) ;
    }
  }
  if (kBoolFalse == test_1) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1489)).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) ;
        var_parameterValue_50587.mProperty_string = var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1495)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1495)) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1497)).getter_rightSubString (GALGAS_uint ((uint32_t) 3U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1497)).objectCompare (GALGAS_string ("REF"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_parameterType_49879.mProperty_string = var_parameterType_49879.getter_string (HERE).getter_leftSubString (var_parameterType_49879.getter_string (HERE).getter_length (SOURCE_FILE ("arxml_parser.galgas", 1499)).substract_operation (GALGAS_uint ((uint32_t) 3U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1499)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1498)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1500)).getter_rightSubString (GALGAS_uint ((uint32_t) 4U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1500)).objectCompare (GALGAS_string ("REFS"))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_parameterType_49879.mProperty_string = var_parameterType_49879.getter_string (HERE).getter_leftSubString (var_parameterType_49879.getter_string (HERE).getter_length (SOURCE_FILE ("arxml_parser.galgas", 1502)).substract_operation (GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1502)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1501)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1504)), GALGAS_string ("An object reference must end with REF or REFS"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1504)) ;
          }
        }
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_6 = kBoolTrue ;
      if (kBoolTrue == test_6) {
        GALGAS_bool test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("PARAMETER-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1506)) ;
        if (kBoolTrue != test_7.boolEnum ()) {
          test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("REFERENCE-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1507)) ;
        }
        test_6 = test_7.boolEnum () ;
        if (kBoolTrue == test_6) {
          var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1511)) ;
        }
      }
      if (kBoolFalse == test_6) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1512)).boolEnum () ;
          if (kBoolTrue == test_8) {
            var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1516)) ;
            enumGalgasBool test_9 = kBoolTrue ;
            if (kBoolTrue == test_9) {
              GALGAS_bool test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1517)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1517)).objectCompare (GALGAS_string ("TRUE"))) ;
              if (kBoolTrue != test_10.boolEnum ()) {
                test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1518)).objectCompare (GALGAS_string ("1"))) ;
              }
              test_9 = test_10.boolEnum () ;
              if (kBoolTrue == test_9) {
                var_isAuto_50553 = GALGAS_bool (true) ;
              }
            }
          }
        }
        if (kBoolFalse == test_8) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1522)), GALGAS_string ("No value has been found."), fixItArray11  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1522)) ;
          var_parameterValue_50587.drop () ; // Release error dropped variable
        }
      }
    }
  }
  enumGalgasBool test_12 = kBoolTrue ;
  if (kBoolTrue == test_12) {
    test_12 = constinArgument_types.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1526)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1526)).boolEnum () ;
    if (kBoolTrue == test_12) {
      constinArgument_types.method_get (var_parameterType_49879, var_type_49944, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)) ;
      var_typeOk_49920 = GALGAS_bool (true) ;
      {
      routine_testTypeError (var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1530)), var_valueType_50216, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1530)) ;
      }
    }
  }
  if (kBoolFalse == test_12) {
    TC_Array <C_FixItDescription> fixItArray13 ;
    inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1532)), var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1532)).add_operation (GALGAS_string (" is not declared in the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)).add_operation (GALGAS_string ("IMPLEMENTATION."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)) ;
  }
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1536)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1536)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1536)) ;
  }
  GALGAS_implementationObjectMap var_subTypes_53173 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1538)) ;
  GALGAS_objectAttributes var_subAttributes_53246 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1539)) ;
  enumGalgasBool test_14 = kBoolTrue ;
  if (kBoolTrue == test_14) {
    test_14 = var_isAuto_50553.boolEnum () ;
    if (kBoolTrue == test_14) {
      {
      routine_displayOil (GALGAS_string (" = AUTO;"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1548)) ;
      }
      enumGalgasBool test_15 = kBoolTrue ;
      if (kBoolTrue == test_15) {
        test_15 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_49944.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1549)).boolEnum () ;
        if (kBoolTrue == test_15) {
          var_val_49732 = GALGAS_auto::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1550))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1550)) ;
        }
      }
      if (kBoolFalse == test_15) {
        TC_Array <C_FixItDescription> fixItArray16 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1552)), GALGAS_string ("AUTO is not allowed"), fixItArray16  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1552)) ;
        var_val_49732.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_14) {
    enumGalgasBool test_17 = kBoolTrue ;
    if (kBoolTrue == test_17) {
      test_17 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1555)).objectCompare (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF"))).boolEnum () ;
      if (kBoolTrue == test_17) {
        GALGAS_impEnumType temp_18 ;
        if (var_type_49944.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_impEnumType *> (var_type_49944.ptr ())) {
            temp_18 = (cPtr_impEnumType *) var_type_49944.ptr () ;
          }else{
            inCompiler->castError ("impEnumType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)) ;
          }
        }
        GALGAS_impEnumType var_enumType_54049 = temp_18 ;
        enumGalgasBool test_19 = kBoolTrue ;
        if (kBoolTrue == test_19) {
          test_19 = var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1560)).getter_hasKey (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1560)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)).boolEnum () ;
          if (kBoolTrue == test_19) {
            var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1561)).method_get (var_parameterValue_50587, var_subTypes_53173, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1561)) ;
          }
        }
        if (kBoolFalse == test_19) {
          TC_Array <C_FixItDescription> fixItArray20 ;
          inCompiler->emitSemanticError (var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1563)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (GALGAS_string (" ENUM value "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (GALGAS_string ("for "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1564)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (GALGAS_string (" undeclared.\n"
            "One of the following"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (GALGAS_string ("values are expected :\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (function_valueList (var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1565)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)), fixItArray20  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)) ;
        }
        {
        routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1568)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)) ;
        }
        enumGalgasBool test_21 = kBoolTrue ;
        if (kBoolTrue == test_21) {
          test_21 = GALGAS_bool (kIsNotEqual, var_subTypes_53173.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1569)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_21) {
            {
            routine_displayOil (GALGAS_string ("\n"
              "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1570)) ;
            }
            {
            routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1571)) ;
            }
            {
            routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1573)) ;
            }
          }
        }
        {
        routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1575)) ;
        }
        var_val_49732 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1578)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1579)), var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1577)) ;
      }
    }
    if (kBoolFalse == test_17) {
      enumGalgasBool test_22 = kBoolTrue ;
      if (kBoolTrue == test_22) {
        test_22 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1582)).objectCompare (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF"))).boolEnum () ;
        if (kBoolTrue == test_22) {
          GALGAS_impBoolType temp_23 ;
          if (var_type_49944.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_impBoolType *> (var_type_49944.ptr ())) {
              temp_23 = (cPtr_impBoolType *) var_type_49944.ptr () ;
            }else{
              inCompiler->castError ("impBoolType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1586)) ;
            }
          }
          GALGAS_impBoolType var_boolType_55179 = temp_23 ;
          GALGAS_bool var_booleanValue_55225 ;
          enumGalgasBool test_24 = kBoolTrue ;
          if (kBoolTrue == test_24) {
            GALGAS_bool test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1588)).objectCompare (GALGAS_string ("TRUE"))) ;
            if (kBoolTrue != test_25.boolEnum ()) {
              test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).objectCompare (GALGAS_string ("1"))) ;
            }
            test_24 = test_25.boolEnum () ;
            if (kBoolTrue == test_24) {
              var_subTypes_53173 = var_boolType_55179.getter_trueSubAttributes (SOURCE_FILE ("arxml_parser.galgas", 1590)) ;
              var_booleanValue_55225 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_24) {
            enumGalgasBool test_26 = kBoolTrue ;
            if (kBoolTrue == test_26) {
              GALGAS_bool test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1592)).objectCompare (GALGAS_string ("FALSE"))) ;
              if (kBoolTrue != test_27.boolEnum ()) {
                test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).objectCompare (GALGAS_string ("0"))) ;
              }
              test_26 = test_27.boolEnum () ;
              if (kBoolTrue == test_26) {
                var_subTypes_53173 = var_boolType_55179.getter_falseSubAttributes (SOURCE_FILE ("arxml_parser.galgas", 1594)) ;
                var_booleanValue_55225 = GALGAS_bool (false) ;
              }
            }
            if (kBoolFalse == test_26) {
              var_booleanValue_55225 = GALGAS_bool (false) ;
              TC_Array <C_FixItDescription> fixItArray28 ;
              inCompiler->emitSemanticError (var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1598)), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray28  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1598)) ;
            }
          }
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_55225.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1601)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1601)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)) ;
          }
          enumGalgasBool test_29 = kBoolTrue ;
          if (kBoolTrue == test_29) {
            test_29 = GALGAS_bool (kIsNotEqual, var_subTypes_53173.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1602)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_29) {
              {
              routine_displayOil (GALGAS_string ("\n"
                "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1603)) ;
              }
              {
              routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1604)) ;
              }
              {
              routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1606)) ;
              }
            }
          }
          {
          routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1608)) ;
          }
          var_val_49732 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1611)), var_booleanValue_55225, var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1610)) ;
        }
      }
      if (kBoolFalse == test_22) {
        enumGalgasBool test_30 = kBoolTrue ;
        if (kBoolTrue == test_30) {
          test_30 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1615)).objectCompare (GALGAS_string ("ECUC-INTEGER-PARAM-DEF"))).boolEnum () ;
          if (kBoolTrue == test_30) {
            GALGAS_bool var_sign_56460 ;
            {
            routine_arxmlPopSign (var_parameterValue_50587, var_sign_56460, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1619)) ;
            }
            GALGAS_luint_36__34_ var_integerValue_56488 = GALGAS_luint_36__34_::constructor_new (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1622)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1622)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 1622)), var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1623))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1621)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_56488.getter_uint_36__34_ (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)) ;
            }
            var_val_49732 = function_checkAndGetIntegerNumber (var_oil_5F_desc_50397, var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1627)), var_integerValue_56488, var_sign_56460, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1627)) ;
          }
        }
        if (kBoolFalse == test_30) {
          enumGalgasBool test_31 = kBoolTrue ;
          if (kBoolTrue == test_31) {
            test_31 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1629)).objectCompare (GALGAS_string ("ECUC-FLOAT-PARAM-DEF"))).boolEnum () ;
            if (kBoolTrue == test_31) {
              GALGAS_bool var_sign_57047 ;
              {
              routine_arxmlPopSign (var_parameterValue_50587, var_sign_57047, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1633)) ;
              }
              GALGAS_ldouble var_floatValue_57073 = GALGAS_ldouble::constructor_new (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1636)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1636)), var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1637))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1635)) ;
              {
              routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_57073.getter_double (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 1639)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)) ;
              }
              var_val_49732 = function_checkAndGetFloatNumber (var_oil_5F_desc_50397, var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1641)), var_floatValue_57073, var_sign_57047, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1641)) ;
            }
          }
          if (kBoolFalse == test_31) {
            enumGalgasBool test_32 = kBoolTrue ;
            if (kBoolTrue == test_32) {
              test_32 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1643)).objectCompare (GALGAS_string ("ECUC-STRING-PARAM-DEF"))).boolEnum () ;
              if (kBoolTrue == test_32) {
                {
                routine_displayOil (GALGAS_string (" = \"").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1647)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)).add_operation (GALGAS_string ("\";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)) ;
                }
                var_val_49732 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1650)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1651))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1649)) ;
              }
            }
            if (kBoolFalse == test_32) {
              enumGalgasBool test_33 = kBoolTrue ;
              if (kBoolTrue == test_33) {
                test_33 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1653)).objectCompare (GALGAS_string ("ECUC-REFERENCE-DEF"))).boolEnum () ;
                if (kBoolTrue == test_33) {
                  {
                  routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1657)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)) ;
                  }
                  var_val_49732 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1660)), var_parameterValue_50587  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1659)) ;
                }
              }
              if (kBoolFalse == test_33) {
                enumGalgasBool test_34 = kBoolTrue ;
                if (kBoolTrue == test_34) {
                  test_34 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1663)).objectCompare (GALGAS_string ("TPL-IDENTIFIER-DEF"))).boolEnum () ;
                  if (kBoolTrue == test_34) {
                    {
                    routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1667)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)) ;
                    }
                    var_val_49732 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1670)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1671))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1669)) ;
                  }
                }
                if (kBoolFalse == test_34) {
                  enumGalgasBool test_35 = kBoolTrue ;
                  if (kBoolTrue == test_35) {
                    test_35 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1673)).objectCompare (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF"))).boolEnum () ;
                    if (kBoolTrue == test_35) {
                      GALGAS_impStructType temp_36 ;
                      if (var_type_49944.isValid ()) {
                        if (NULL != dynamic_cast <const cPtr_impStructType *> (var_type_49944.ptr ())) {
                          temp_36 = (cPtr_impStructType *) var_type_49944.ptr () ;
                        }else{
                          inCompiler->castError ("impStructType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1677)) ;
                        }
                      }
                      GALGAS_impStructType var_structType_58962 = temp_36 ;
                      var_subTypes_53173 = var_structType_58962.getter_structAttributes (SOURCE_FILE ("arxml_parser.galgas", 1678)) ;
                      {
                      routine_displayOil (GALGAS_string (" ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1680)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)).add_operation (GALGAS_string ("\n"
                        "    {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)) ;
                      }
                      {
                      routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1681)) ;
                      }
                      {
                      routine_displayOil (GALGAS_string ("    };"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1683)) ;
                      }
                      var_val_49732 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1686)), var_parameterValue_50587, var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1685)) ;
                    }
                  }
                  if (kBoolFalse == test_35) {
                    TC_Array <C_FixItDescription> fixItArray37 ;
                    inCompiler->emitSemanticError (var_valueType_50216.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1693)), GALGAS_string ("Undefined valueType ").add_operation (var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1693)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1693)), fixItArray37  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1693)) ;
                    var_val_49732.drop () ; // Release error dropped variable
                    var_typeOk_49920 = GALGAS_bool (false) ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {
  routine_displayOil (GALGAS_string ("      /* ARXML Type :").add_operation (var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1697)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)).add_operation (GALGAS_string (" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)) ;
  }
  GALGAS_identifierMap var_idfs_59897 = ioArgument_identifiers.getter_objectParams (SOURCE_FILE ("arxml_parser.galgas", 1702)) ;
  enumGalgasBool test_38 = kBoolTrue ;
  if (kBoolTrue == test_38) {
    test_38 = var_type_49944.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1703)).boolEnum () ;
    if (kBoolTrue == test_38) {
      enumGalgasBool test_39 = kBoolTrue ;
      if (kBoolTrue == test_39) {
        test_39 = var_idfs_59897.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1704)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1704)).boolEnum () ;
        if (kBoolTrue == test_39) {
          GALGAS_object_5F_t var_attributeList_60031 ;
          {
          var_idfs_59897.setter_del (var_parameterType_49879, var_attributeList_60031, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)) ;
          }
          if (var_attributeList_60031.isValid ()) {
            if (var_attributeList_60031.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
              GALGAS_multipleAttribute cast_60235_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_60031.ptr ()) ;
              GALGAS_identifierList var_aList_60267 = cast_60235_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1711)) ;
              var_aList_60267.addAssign_operation (var_val_49732  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1712)) ;
              var_val_49732 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1713)), cast_60235_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1714)), var_aList_60267  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1713)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_39) {
        GALGAS_identifierList var_aList_60537 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1718)) ;
        GALGAS_object_5F_t var_defaultValue_60616 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_49944.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1720)) ;
        if (var_defaultValue_60616.isValid ()) {
          if (var_defaultValue_60616.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_60745_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_60616.ptr ()) ;
            var_aList_60537 = cast_60745_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1725)) ;
          }
        }
        var_aList_60537.addAssign_operation (var_val_49732  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1730)) ;
        var_val_49732 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1732)), var_val_49732.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1732)), var_aList_60537  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1732)) ;
      }
      enumGalgasBool test_40 = kBoolTrue ;
      if (kBoolTrue == test_40) {
        test_40 = var_idfs_59897.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1734)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1734)).boolEnum () ;
        if (kBoolTrue == test_40) {
          GALGAS_object_5F_t var_existingObject_61232 ;
          {
          var_idfs_59897.setter_del (var_parameterType_49879, var_existingObject_61232, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1738)) ;
          }
          {
          var_val_49732.insulate (HERE) ;
          cPtr_object_5F_t * ptr_61299 = (cPtr_object_5F_t *) var_val_49732.ptr () ;
          callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_61299, var_existingObject_61232, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1739)) ;
          }
        }
      }
    }
  }
  enumGalgasBool test_41 = kBoolTrue ;
  if (kBoolTrue == test_41) {
    test_41 = var_typeOk_49920.boolEnum () ;
    if (kBoolTrue == test_41) {
      {
      var_idfs_59897.setter_put (var_parameterType_49879, var_val_49732, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1745)) ;
      }
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_59897 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1747)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'testTypeError'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_testTypeError (GALGAS_dataType inArgument_type,
                            GALGAS_lstring inArgument_valueType,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1758)).objectCompare (inArgument_valueType.getter_string (HERE))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (inArgument_valueType.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1759)), GALGAS_string ("Expected oil type ").add_operation (extensionGetter_oilType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (inArgument_valueType.getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (GALGAS_string (".\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (GALGAS_string (" Fix : Replace it with "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1761)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1761)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'oilEquivalentName'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_oilEquivalentName (GALGAS_lstring inArgument_parentPath,
                                GALGAS_lstring inArgument_currentPath,
                                GALGAS_lstring & outArgument_outName,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1770)).objectCompare (inArgument_currentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1770)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      inArgument_parentPath.mProperty_string = inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1771)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1771)) ;
    }
  }
  GALGAS_lstring var_objectKind_62165 = GALGAS_lstring::constructor_new (inArgument_currentPath.getter_string (HERE).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1774)), inArgument_currentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1775))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1774)) ;
  GALGAS_string var_lastParent_62458 = inArgument_parentPath.getter_string (HERE).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1779)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1779)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_lastParent_62458.objectCompare (GALGAS_string ("OSOS"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_lastParent_62458 = GALGAS_string ("OS") ;
    }
  }
  GALGAS_uint var_lastParentLength_62702 = var_lastParent_62458.getter_length (SOURCE_FILE ("arxml_parser.galgas", 1787)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_objectKind_62165.getter_string (HERE).getter_leftSubString (var_lastParentLength_62702 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1788)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1788)).objectCompare (var_lastParent_62458)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_objectKind_62165.mProperty_string = var_objectKind_62165.getter_string (HERE).getter_subStringFromIndex (var_lastParentLength_62702 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1790)) ;
      var_objectKind_62165.mProperty_string = var_objectKind_62165.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1791)) ;
      outArgument_outName = var_objectKind_62165 ;
    }
  }
  if (kBoolFalse == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (var_objectKind_62165.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1794)), GALGAS_string ("An object must be named by its Parent.\n"
      " ").add_operation (GALGAS_string ("Ex : If Task object has Os parent, then the DEFINITION-REF must be "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1794)).add_operation (GALGAS_string ("(...)/Os/OsTask.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1795)).add_operation (GALGAS_string ("Fix : Add \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1796)).add_operation (var_lastParent_62458, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1797)).add_operation (GALGAS_string ("\" to the name of your property."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1797)), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1794)) ;
    outArgument_outName.drop () ; // Release error dropped variable
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Routine 'arxmlGetDescription'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetDescription (GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring & outArgument_description,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_description.drop () ; // Release 'out' argument
  outArgument_description = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1806))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1806)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1809)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementValue var_desc_63571 ;
      callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), var_desc_63571, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1810)) ;
      callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) var_desc_63571.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1811)) ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1813)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_arxmlElementValue var_desc_63752 ;
      callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), var_desc_63752, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) ;
      callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) var_desc_63752.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1815)) ;
    }
  }
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1819)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1819)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1822)).getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1822)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1825)).getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1825)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1828)).getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1828)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'displayOil'                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_displayOil (GALGAS_string inArgument_string,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_arxmlDisplayOil.getter_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (inArgument_string  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1837)) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Routine 'arxmlGetMultiplicity'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetMultiplicity (GALGAS_arxmlElementValue inArgument_element,
                                   GALGAS_lstring inArgument_objectName,
                                   GALGAS_lbool & outArgument_multiple,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_multiple.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1846)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_smultiple_64795 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1847)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_smultiple_64795.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1849)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1849)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_smultiple_64795.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1850)).objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (true), var_smultiple_64795.getter_location (HERE)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1851)) ;
          {
          routine_displayOil (GALGAS_string ("[]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1852)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), var_smultiple_64795.getter_location (HERE)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1854)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), inArgument_objectName.getter_location (HERE)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1857)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'arxmlPopSign'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlPopSign (GALGAS_lstring & ioArgument_value,
                           GALGAS_bool & outArgument_sign,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_sign.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, ioArgument_value.getter_string (HERE).getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)).objectCompare (GALGAS_char (TO_UNICODE (45)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_sign = GALGAS_bool (true) ;
      ioArgument_value.mProperty_string = ioArgument_value.getter_string (HERE).getter_subStringFromIndex (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1868)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, ioArgument_value.getter_string (HERE).getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1869)).objectCompare (GALGAS_char (TO_UNICODE (43)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_sign = GALGAS_bool (false) ;
        ioArgument_value.mProperty_string = ioArgument_value.getter_string (HERE).getter_subStringFromIndex (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1871)) ;
      }
    }
    if (kBoolFalse == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'arxmlGetWithAuto'                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetWithAuto (GALGAS_arxmlElementValue inArgument_parameter,
                               GALGAS_bool & outArgument_withAuto,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  outArgument_withAuto = GALGAS_bool (false) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1882)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_autoString_65700 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1883)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_autoString_65700.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1884)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1884)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_autoString_65700.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1885)).objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_withAuto = GALGAS_bool (true) ;
          {
          routine_displayOil (GALGAS_string (" WITH_AUTO"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1887)) ;
          }
        }
      }
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'arxmlGetName'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetName (GALGAS_arxmlElementValue inArgument_parameter,
                           GALGAS_lstring & outArgument_objectName,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_objectName = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1897)) ;
  outArgument_objectName.mProperty_string = outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1898)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1898)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        Routine 'arxmlInsertObjectAttribute'                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlInsertObjectAttribute (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                         GALGAS_lstring inArgument_attributeName,
                                         GALGAS_impType inArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objectAttributes.getter_hasKey (inArgument_attributeName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1906)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1906)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_previousType_66335 ;
      ioArgument_objectAttributes.method_get (inArgument_attributeName, var_previousType_66335, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1908)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_previousType_66335.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1911)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_object_5F_t var_previousDefaultValue_66673 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_66335.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1914)) ;
          GALGAS_object_5F_t var_defaultValue_66735 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) inArgument_type.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1915)) ;
          GALGAS_bool var_oneIsMultiple_66786 = GALGAS_bool (false) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (var_previousDefaultValue_66673.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_oneIsMultiple_66786 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_2) {
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = GALGAS_bool (var_defaultValue_66735.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_oneIsMultiple_66786 = GALGAS_bool (true) ;
              }
            }
          }
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = var_oneIsMultiple_66786.boolEnum () ;
            if (kBoolTrue == test_4) {
              GALGAS_identifierList var_aList_67189 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1926)) ;
              GALGAS_lstring var_desc_67224 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1927)) ;
              GALGAS_location var_location_67268 = GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1928)) ;
              if (var_previousDefaultValue_66673.isValid ()) {
                if (var_previousDefaultValue_66673.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67394_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_66673.ptr ()) ;
                  var_aList_67189 = cast_67394_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1933)) ;
                  var_desc_67224 = cast_67394_multiAttribute.getter_oil_5F_desc (SOURCE_FILE ("arxml_parser.galgas", 1934)) ;
                  var_location_67268 = cast_67394_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1935)) ;
                }
              }
              if (var_defaultValue_66735.isValid ()) {
                if (var_defaultValue_66735.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67654_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_66735.ptr ()) ;
                  var_aList_67189.plusAssign_operation(cast_67654_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1941)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1941)) ;
                  enumGalgasBool test_5 = kBoolTrue ;
                  if (kBoolTrue == test_5) {
                    test_5 = GALGAS_bool (kIsEqual, var_desc_67224.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1942)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                    if (kBoolTrue == test_5) {
                      var_desc_67224 = cast_67654_multiAttribute.getter_oil_5F_desc (SOURCE_FILE ("arxml_parser.galgas", 1943)) ;
                    }
                  }
                  enumGalgasBool test_6 = kBoolTrue ;
                  if (kBoolTrue == test_6) {
                    test_6 = GALGAS_bool (kIsEqual, var_location_67268.objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1945)))).boolEnum () ;
                    if (kBoolTrue == test_6) {
                      var_location_67268 = cast_67654_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1946)) ;
                    }
                  }
                }
              }
              GALGAS_object_5F_t var_newDefault_67983 = GALGAS_multipleAttribute::constructor_new (var_desc_67224, var_location_67268, var_aList_67189  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1951)) ;
              {
              inArgument_type.insulate (HERE) ;
              cPtr_impType * ptr_68085 = (cPtr_impType *) inArgument_type.ptr () ;
              callExtensionSetter_setDefaultValue ((cPtr_impType *) ptr_68085, var_newDefault_67983, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1954)) ;
              }
              {
              GALGAS_impType joker_68164 ; // Joker input parameter
              ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68164, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1956)) ;
              }
              {
              ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1957)) ;
              }
            }
          }
        }
      }
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        test_7 = function_checkNewTypeWithinPreviousType (inArgument_attributeName, var_previousType_66335, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1961)).boolEnum () ;
        if (kBoolTrue == test_7) {
          {
          GALGAS_impType joker_68448 ; // Joker input parameter
          ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68448, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1964)) ;
          }
          {
          ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1965)) ;
          }
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    {
    ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1968)) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension method '@arxmlElementNode print'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_print (const cPtr_arxmlNode * inObject,
                                                    const GALGAS_uint constinArgument_indentation,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  GALGAS_string var_indent_3618 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 172)) ;
  inCompiler->printMessage (var_indent_3618  COMMA_SOURCE_FILE ("arxml_types.galgas", 173)) ;
  inCompiler->printMessage (GALGAS_string ("NODE \"").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 174)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174)).add_operation (GALGAS_string ("\" "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174))  COMMA_SOURCE_FILE ("arxml_types.galgas", 174)) ;
  extensionMethod_print (object->mProperty_attributes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 175)) ;
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("arxml_types.galgas", 176)) ;
  extensionMethod_print (object->mProperty_enclosedNodes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 177)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                              extensionMethod_arxmlElementNode_print) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_print (defineExtensionMethod_arxmlElementNode_print, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@arxmlElementNode getElementsFromName'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_getElementsFromName (const cPtr_arxmlNode * inObject,
                                                                  const GALGAS_string constinArgument_nodeName,
                                                                  GALGAS_arxmlElementList & ioArgument_nodeList,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 184)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementNode temp_1 = object ;
      ioArgument_nodeList.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 185)) ;
    }
  }
  extensionMethod_getElementsFromName (object->mProperty_enclosedNodes, constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 188)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                            extensionMethod_arxmlElementNode_getElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_getElementsFromName (defineExtensionMethod_arxmlElementNode_getElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@arxmlElementNode getSubElementsFromName'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_getSubElementsFromName (const cPtr_arxmlNode * inObject,
                                                                     const GALGAS_string constinArgument_nodeName,
                                                                     GALGAS_arxmlElementList & ioArgument_nodeList,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  cEnumerator_arxmlNodeList enumerator_4206 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4206.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (enumerator_4206.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlElementNode temp_1 ;
        if (enumerator_4206.current_node (HERE).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4206.current_node (HERE).ptr ())) {
            temp_1 = (cPtr_arxmlElementNode *) enumerator_4206.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlElementNode", enumerator_4206.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 197)) ;
          }
        }
        GALGAS_arxmlElementNode var_currentElement_4296 = temp_1 ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_currentElement_4296.getter_name (SOURCE_FILE ("arxml_types.galgas", 198)).getter_string (HERE).objectCompare (constinArgument_nodeName)).boolEnum () ;
          if (kBoolTrue == test_2) {
            ioArgument_nodeList.addAssign_operation (var_currentElement_4296  COMMA_SOURCE_FILE ("arxml_types.galgas", 199)) ;
          }
        }
      }
    }
    enumerator_4206.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                               extensionMethod_arxmlElementNode_getSubElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_getSubElementsFromName (defineExtensionMethod_arxmlElementNode_getSubElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                             Overriding extension method '@arxmlElementNode getProperty'                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_getProperty (const cPtr_arxmlNode * inObject,
                                                          const GALGAS_string constinArgument_nodeName,
                                                          GALGAS_lstring & ioArgument_value,
                                                          GALGAS_bool & ioArgument_found,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 223)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementNode temp_1 = object ;
      callExtensionMethod_getText ((const cPtr_arxmlElementNode *) temp_1.ptr (), ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 224)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 227)).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlNodeList enumerator_4993 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
      bool bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
      if (enumerator_4993.hasCurrentObject () && bool_3) {
        while (enumerator_4993.hasCurrentObject () && bool_3) {
          callExtensionMethod_getProperty ((const cPtr_arxmlNode *) enumerator_4993.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 231)) ;
          enumerator_4993.gotoNextObject () ;
          if (enumerator_4993.hasCurrentObject ()) {
            bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
          }
        }
      }
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                    extensionMethod_arxmlElementNode_getProperty) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_getProperty (defineExtensionMethod_arxmlElementNode_getProperty, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension method '@arxmlCommentNode print'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_print (const cPtr_arxmlNode * inObject,
                                                    const GALGAS_uint constinArgument_indentation,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlCommentNode * object = (const cPtr_arxmlCommentNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlCommentNode) ;
  GALGAS_string var_indent_5992 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 281)) ;
  inCompiler->printMessage (var_indent_5992  COMMA_SOURCE_FILE ("arxml_types.galgas", 282)) ;
  inCompiler->printMessage (GALGAS_string ("COMMENT \"").add_operation (object->mProperty_comment.getter_string (SOURCE_FILE ("arxml_types.galgas", 283)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283))  COMMA_SOURCE_FILE ("arxml_types.galgas", 283)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                              extensionMethod_arxmlCommentNode_print) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_print (defineExtensionMethod_arxmlCommentNode_print, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@arxmlCommentNode getElementsFromName'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_getElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                  const GALGAS_string /* constinArgument_nodeName */,
                                                                  GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                            extensionMethod_arxmlCommentNode_getElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_getElementsFromName (defineExtensionMethod_arxmlCommentNode_getElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@arxmlCommentNode getSubElementsFromName'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_getSubElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                     const GALGAS_string /* constinArgument_nodeName */,
                                                                     GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                     C_Compiler * /* inCompiler */
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                               extensionMethod_arxmlCommentNode_getSubElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_getSubElementsFromName (defineExtensionMethod_arxmlCommentNode_getSubElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                             Overriding extension method '@arxmlCommentNode getProperty'                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_getProperty (const cPtr_arxmlNode * /* inObject */,
                                                          const GALGAS_string /* constinArgument_nodeName */,
                                                          GALGAS_lstring & /* ioArgument_value */,
                                                          GALGAS_bool & /* ioArgument_found */,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                    extensionMethod_arxmlCommentNode_getProperty) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_getProperty (defineExtensionMethod_arxmlCommentNode_getProperty, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension method '@arxmlTextNode print'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_print (const cPtr_arxmlNode * inObject,
                                                 const GALGAS_uint constinArgument_indentation,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlTextNode * object = (const cPtr_arxmlTextNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlTextNode) ;
  GALGAS_string var_indent_6749 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 316)) ;
  inCompiler->printMessage (var_indent_6749  COMMA_SOURCE_FILE ("arxml_types.galgas", 317)) ;
  inCompiler->printMessage (GALGAS_string ("TEXT \"").add_operation (object->mProperty_text.getter_string (SOURCE_FILE ("arxml_types.galgas", 318)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318))  COMMA_SOURCE_FILE ("arxml_types.galgas", 318)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                              extensionMethod_arxmlTextNode_print) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_print (defineExtensionMethod_arxmlTextNode_print, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                          Overriding extension method '@arxmlTextNode getElementsFromName'                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_getElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                               const GALGAS_string /* constinArgument_nodeName */,
                                                               GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                            extensionMethod_arxmlTextNode_getElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_getElementsFromName (defineExtensionMethod_arxmlTextNode_getElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@arxmlTextNode getSubElementsFromName'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_getSubElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                  const GALGAS_string /* constinArgument_nodeName */,
                                                                  GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                               extensionMethod_arxmlTextNode_getSubElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_getSubElementsFromName (defineExtensionMethod_arxmlTextNode_getSubElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              Overriding extension method '@arxmlTextNode getProperty'                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_getProperty (const cPtr_arxmlNode * /* inObject */,
                                                       const GALGAS_string /* constinArgument_nodeName */,
                                                       GALGAS_lstring & /* ioArgument_value */,
                                                       GALGAS_bool & /* ioArgument_found */,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                    extensionMethod_arxmlTextNode_getProperty) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_getProperty (defineExtensionMethod_arxmlTextNode_getProperty, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'lstringhere'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_lstringhere (GALGAS_lstring & outArgument_string,
                          GALGAS_string inArgument_value,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_string.drop () ; // Release 'out' argument
  outArgument_string = GALGAS_lstring::constructor_new (inArgument_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1193))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1193)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'fillLegacy'                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_fillLegacy (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                         GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist var_sortedInfoList_33628 = ioArgument_classGraph.getter_keyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1200)) ;
  cEnumerator_stringlist enumerator_33697 (var_sortedInfoList_33628, kENUMERATION_UP) ;
  while (enumerator_33697.hasCurrentObject ()) {
    GALGAS_lstring var_lClassName_33737 ;
    {
    routine_lstringhere (var_lClassName_33737, enumerator_33697.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1203)) ;
    }
    GALGAS_arxmlMetaClass var_lClass_33777 ;
    ioArgument_classMap.method_searchKey (var_lClassName_33737, var_lClass_33777, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1205)) ;
    GALGAS_lstringlist var_fromList_33870 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1208)) ;
    {
    var_fromList_33870.setter_insertAtIndex (var_lClass_33777.getter_name (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1209)), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1209)) ;
    }
    GALGAS_stringset var_empty_33945 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1210)) ;
    GALGAS_lstringlist var_successorList_33988 = ioArgument_classGraph.getter_accessibleNodesFrom (var_fromList_33870, var_empty_33945, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1211)) ;
    {
    var_lClass_33777.insulate (HERE) ;
    cPtr_arxmlMetaClass * ptr_34134 = (cPtr_arxmlMetaClass *) var_lClass_33777.ptr () ;
    callExtensionSetter_legacyAddParameters ((cPtr_arxmlMetaClass *) ptr_34134, ioArgument_classMap, var_successorList_33988, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1214)) ;
    }
    enumerator_33697.gotoNextObject () ;
  }
}


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"
#include "command_line_interface/C_builtin_CLI_Options.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  "arxml",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  "an AUTOSAR arxml configuration file",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * projectVersionString (void) {
  return "3.1.11" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_1'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_2'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_3'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__33_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 48)) ;
  }
  GALGAS_arxmlNode var_root_1353 ;
  var_root_1353.drop () ;
  cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_root_1353, GALGAS_bool (true), GALGAS_bool (true)  COMMA_SOURCE_FILE ("goil_program.galgas", 49)) ;
  callExtensionMethod_print ((const cPtr_arxmlNode *) var_root_1353.ptr (), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_program.galgas", 53)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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
    C_Compiler * commonCompiler = NULL ;
    macroMyNew (commonCompiler, C_Compiler (NULL COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonCompiler->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "oil") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "OIL") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__31_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "goilTemplate") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__32_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "arxml") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__33_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
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
      routine_after (commonCompiler COMMA_HERE) ;
    //--- Emit JSON issue file ?
      if (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue != "") {
        commonCompiler->writeIssueJSONFile (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue) ;
      }
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
    macroDetachSharedObject (commonCompiler) ;
  }
  return returnCode ;
}


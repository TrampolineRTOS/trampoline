#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-7.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlContext fullPrefix'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_fullPrefix> gExtensionGetterTable_gtlContext_fullPrefix ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fullPrefix (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlContext_fullPrefix inGetter) {
  gExtensionGetterTable_gtlContext_fullPrefix.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_fullPrefix (const cPtr_gtlContext * inObject,
                                               const GALGAS_gtlData & in_vars,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_fullPrefix f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_fullPrefix.count ()) {
      f = gExtensionGetterTable_gtlContext_fullPrefix (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_fullPrefix.count ()) {
           f = gExtensionGetterTable_gtlContext_fullPrefix (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_fullPrefix.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_vars, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlContext_fullPrefix (const cPtr_gtlContext * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_vars */,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_full ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_full = object->mAttribute_prefix ;
//---
  return result_full ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_fullPrefix (void) {
  enterExtensionGetter_fullPrefix (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                   extensionGetter_gtlContext_fullPrefix) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_fullPrefix (void) {
  gExtensionGetterTable_gtlContext_fullPrefix.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_fullPrefix (defineExtensionGetter_gtlContext_fullPrefix,
                                                  freeExtensionGetter_gtlContext_fullPrefix) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension getter '@gtlContext fullTemplateFileName'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_fullTemplateFileName> gExtensionGetterTable_gtlContext_fullTemplateFileName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fullTemplateFileName (const int32_t inClassIndex,
                                                enterExtensionGetter_gtlContext_fullTemplateFileName inGetter) {
  gExtensionGetterTable_gtlContext_fullTemplateFileName.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                         GALGAS_gtlContext in_context,
                                                         GALGAS_gtlData in_vars,
                                                         GALGAS_lstring in_simpleName,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_fullTemplateFileName f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_fullTemplateFileName.count ()) {
      f = gExtensionGetterTable_gtlContext_fullTemplateFileName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_fullTemplateFileName.count ()) {
           f = gExtensionGetterTable_gtlContext_fullTemplateFileName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_fullTemplateFileName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_context, in_vars, in_simpleName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlContext_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                                       GALGAS_gtlContext inArgument_context,
                                                                       GALGAS_gtlData inArgument_vars,
                                                                       GALGAS_lstring inArgument_simpleName,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_fullName ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  const GALGAS_gtlContext temp_0 = object ;
  GALGAS_gtlContext var_copy_2448 = temp_0 ;
  const GALGAS_gtlContext temp_1 = object ;
  GALGAS_lstring var_fullPref_2475 = callExtensionGetter_fullPrefix ((const cPtr_gtlContext *) temp_1.ptr (), inArgument_vars, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 106)) ;
  GALGAS_string var_prefixedTemplatePath_2532 = extensionGetter_stringByAppendingPath (object->mAttribute_templateDirectory, var_fullPref_2475.getter_string (SOURCE_FILE ("gtl_types.galgas", 108)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 108)) ;
  GALGAS_string var_hierarchicalPath_2620 = object->mAttribute_path ;
  GALGAS_string var_rootPath_2646 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2532, inArgument_simpleName.getter_string (SOURCE_FILE ("gtl_types.galgas", 112)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 112)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 110)) ;
  GALGAS_bool var_found_2772 = GALGAS_bool (false) ;
  if (var_hierarchicalPath_2620.getter_length (SOURCE_FILE ("gtl_types.galgas", 117)).isValid ()) {
    uint32_t variant_2788 = var_hierarchicalPath_2620.getter_length (SOURCE_FILE ("gtl_types.galgas", 117)).uintValue () ;
    bool loop_2788 = true ;
    while (loop_2788) {
      GALGAS_bool test_2 = var_found_2772.operator_not (SOURCE_FILE ("gtl_types.galgas", 118)) ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = GALGAS_bool (kIsStrictSup, var_hierarchicalPath_2620.getter_length (SOURCE_FILE ("gtl_types.galgas", 118)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
      }
      loop_2788 = test_2.isValid () ;
      if (loop_2788) {
        loop_2788 = test_2.boolValue () ;
      }
      if (loop_2788 && (0 == variant_2788)) {
        loop_2788 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_types.galgas", 117)) ;
      }
      if (loop_2788) {
        variant_2788 -- ;
        GALGAS_string var_fullPath_2893 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2532, var_hierarchicalPath_2620, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 121)), inArgument_simpleName.getter_string (SOURCE_FILE ("gtl_types.galgas", 122)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 121)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 119)) ;
        const enumGalgasBool test_3 = var_fullPath_2893.getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 126)).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_rootPath_2646 = var_fullPath_2893 ;
          var_found_2772 = GALGAS_bool (true) ;
        }
        var_hierarchicalPath_2620 = var_hierarchicalPath_2620.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("gtl_types.galgas", 133)) ;
      }
    }
  }
  result_fullName = GALGAS_lstring::constructor_new (var_rootPath_2646, inArgument_simpleName.getter_location (SOURCE_FILE ("gtl_types.galgas", 138))  COMMA_SOURCE_FILE ("gtl_types.galgas", 136)) ;
//---
  return result_fullName ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_fullTemplateFileName (void) {
  enterExtensionGetter_fullTemplateFileName (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                             extensionGetter_gtlContext_fullTemplateFileName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_fullTemplateFileName (void) {
  gExtensionGetterTable_gtlContext_fullTemplateFileName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_fullTemplateFileName (defineExtensionGetter_gtlContext_fullTemplateFileName,
                                                            freeExtensionGetter_gtlContext_fullTemplateFileName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlContext setDebugger'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setDebugger> gExtensionModifierTable_gtlContext_setDebugger ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setDebugger (const int32_t inClassIndex,
                                       extensionSetterSignature_gtlContext_setDebugger inModifier) {
  gExtensionModifierTable_gtlContext_setDebugger.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setDebugger (cPtr_gtlContext * inObject,
                                      GALGAS_bool in_debugOn,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setDebugger f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setDebugger.count ()) {
      f = gExtensionModifierTable_gtlContext_setDebugger (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setDebugger.count ()) {
           f = gExtensionModifierTable_gtlContext_setDebugger (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setDebugger.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_debugOn, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setDebugger (cPtr_gtlContext * inObject,
                                                    GALGAS_bool inArgument_debugOn,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.setter_setDebugActive (inArgument_debugOn COMMA_SOURCE_FILE ("gtl_debugger.galgas", 287)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setDebugger (void) {
  enterExtensionSetter_setDebugger (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionSetter_gtlContext_setDebugger) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setDebugger (void) {
  gExtensionModifierTable_gtlContext_setDebugger.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setDebugger (defineExtensionSetter_gtlContext_setDebugger,
                                                   freeExtensionModifier_gtlContext_setDebugger) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext setBreakOnNext'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setBreakOnNext> gExtensionModifierTable_gtlContext_setBreakOnNext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setBreakOnNext (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlContext_setBreakOnNext inModifier) {
  gExtensionModifierTable_gtlContext_setBreakOnNext.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setBreakOnNext (cPtr_gtlContext * inObject,
                                         GALGAS_bool in_break,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setBreakOnNext f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setBreakOnNext.count ()) {
      f = gExtensionModifierTable_gtlContext_setBreakOnNext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setBreakOnNext.count ()) {
           f = gExtensionModifierTable_gtlContext_setBreakOnNext (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setBreakOnNext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_break, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setBreakOnNext (cPtr_gtlContext * inObject,
                                                       GALGAS_bool inArgument_break,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.setter_setBreakOnNext (inArgument_break COMMA_SOURCE_FILE ("gtl_debugger.galgas", 294)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setBreakOnNext (void) {
  enterExtensionSetter_setBreakOnNext (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                       extensionSetter_gtlContext_setBreakOnNext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setBreakOnNext (void) {
  gExtensionModifierTable_gtlContext_setBreakOnNext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setBreakOnNext (defineExtensionSetter_gtlContext_setBreakOnNext,
                                                      freeExtensionModifier_gtlContext_setBreakOnNext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext debugActive'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_debugActive> gExtensionGetterTable_gtlContext_debugActive ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_debugActive (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_debugActive inGetter) {
  gExtensionGetterTable_gtlContext_debugActive.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_debugActive (const cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_debugActive f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_debugActive.count ()) {
      f = gExtensionGetterTable_gtlContext_debugActive (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_debugActive.count ()) {
           f = gExtensionGetterTable_gtlContext_debugActive (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_debugActive.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_debugActive (const cPtr_gtlContext * inObject,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_debugOn ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_debugOn = object->mAttribute_debuggerContext.getter_debugActive (SOURCE_FILE ("gtl_debugger.galgas", 301)) ;
//---
  return result_debugOn ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_debugActive (void) {
  enterExtensionGetter_debugActive (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_debugActive) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_debugActive (void) {
  gExtensionGetterTable_gtlContext_debugActive.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_debugActive (defineExtensionGetter_gtlContext_debugActive,
                                                   freeExtensionGetter_gtlContext_debugActive) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext breakOnNext'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_breakOnNext> gExtensionGetterTable_gtlContext_breakOnNext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_breakOnNext (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_breakOnNext inGetter) {
  gExtensionGetterTable_gtlContext_breakOnNext.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_breakOnNext (const cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_breakOnNext f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_breakOnNext.count ()) {
      f = gExtensionGetterTable_gtlContext_breakOnNext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_breakOnNext.count ()) {
           f = gExtensionGetterTable_gtlContext_breakOnNext (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_breakOnNext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_breakOnNext (const cPtr_gtlContext * inObject,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_breakOnNext ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_breakOnNext = object->mAttribute_debuggerContext.getter_breakOnNext (SOURCE_FILE ("gtl_debugger.galgas", 308)) ;
//---
  return result_breakOnNext ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_breakOnNext (void) {
  enterExtensionGetter_breakOnNext (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_breakOnNext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_breakOnNext (void) {
  gExtensionGetterTable_gtlContext_breakOnNext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_breakOnNext (defineExtensionGetter_gtlContext_breakOnNext,
                                                   freeExtensionGetter_gtlContext_breakOnNext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlContext breakOn'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_breakOn> gExtensionGetterTable_gtlContext_breakOn ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_breakOn (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlContext_breakOn inGetter) {
  gExtensionGetterTable_gtlContext_breakOn.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_breakOn (const cPtr_gtlContext * inObject,
                                         GALGAS_gtlInstruction in_instruction,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_breakOn f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_breakOn.count ()) {
      f = gExtensionGetterTable_gtlContext_breakOn (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_breakOn.count ()) {
           f = gExtensionGetterTable_gtlContext_breakOn (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_breakOn.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_instruction, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_breakOn (const cPtr_gtlContext * inObject,
                                                       GALGAS_gtlInstruction inArgument_instruction,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_breakOn ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_breakOn = callExtensionGetter_breakOn ((const cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr (), inArgument_instruction, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 316)) ;
//---
  return result_breakOn ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_breakOn (void) {
  enterExtensionGetter_breakOn (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                extensionGetter_gtlContext_breakOn) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_breakOn (void) {
  gExtensionGetterTable_gtlContext_breakOn.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_breakOn (defineExtensionGetter_gtlContext_breakOn,
                                               freeExtensionGetter_gtlContext_breakOn) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext promptStyle'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_promptStyle> gExtensionGetterTable_gtlContext_promptStyle ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_promptStyle (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_promptStyle inGetter) {
  gExtensionGetterTable_gtlContext_promptStyle.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_promptStyle (const cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_promptStyle f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_promptStyle.count ()) {
      f = gExtensionGetterTable_gtlContext_promptStyle (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_promptStyle.count ()) {
           f = gExtensionGetterTable_gtlContext_promptStyle (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_promptStyle.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlContext_promptStyle (const cPtr_gtlContext * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_result = object->mAttribute_debuggerContext.getter_promptColor (SOURCE_FILE ("gtl_debugger.galgas", 323)).add_operation (object->mAttribute_debuggerContext.getter_promptFace (SOURCE_FILE ("gtl_debugger.galgas", 323)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 323)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_promptStyle (void) {
  enterExtensionGetter_promptStyle (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_promptStyle) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_promptStyle (void) {
  gExtensionGetterTable_gtlContext_promptStyle.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_promptStyle (defineExtensionGetter_gtlContext_promptStyle,
                                                   freeExtensionGetter_gtlContext_promptStyle) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext outputStyle'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_outputStyle> gExtensionGetterTable_gtlContext_outputStyle ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_outputStyle (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_outputStyle inGetter) {
  gExtensionGetterTable_gtlContext_outputStyle.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_outputStyle (const cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_outputStyle f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_outputStyle.count ()) {
      f = gExtensionGetterTable_gtlContext_outputStyle (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_outputStyle.count ()) {
           f = gExtensionGetterTable_gtlContext_outputStyle (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_outputStyle.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlContext_outputStyle (const cPtr_gtlContext * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_result = object->mAttribute_debuggerContext.getter_outputColor (SOURCE_FILE ("gtl_debugger.galgas", 330)).add_operation (object->mAttribute_debuggerContext.getter_outputFace (SOURCE_FILE ("gtl_debugger.galgas", 330)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 330)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_outputStyle (void) {
  enterExtensionGetter_outputStyle (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_outputStyle) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_outputStyle (void) {
  gExtensionGetterTable_gtlContext_outputStyle.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_outputStyle (defineExtensionGetter_gtlContext_outputStyle,
                                                   freeExtensionGetter_gtlContext_outputStyle) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension setter '@gtlContext appendInstructionToStepDo'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_appendInstructionToStepDo> gExtensionModifierTable_gtlContext_appendInstructionToStepDo ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_appendInstructionToStepDo (const int32_t inClassIndex,
                                                     extensionSetterSignature_gtlContext_appendInstructionToStepDo inModifier) {
  gExtensionModifierTable_gtlContext_appendInstructionToStepDo.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_appendInstructionToStepDo (cPtr_gtlContext * inObject,
                                                    GALGAS_gtlInstruction in_instruction,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_appendInstructionToStepDo f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_appendInstructionToStepDo.count ()) {
      f = gExtensionModifierTable_gtlContext_appendInstructionToStepDo (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_appendInstructionToStepDo.count ()) {
           f = gExtensionModifierTable_gtlContext_appendInstructionToStepDo (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_appendInstructionToStepDo.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_instruction, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_appendInstructionToStepDo (cPtr_gtlContext * inObject,
                                                                  GALGAS_gtlInstruction inArgument_instruction,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_10742 = (cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr () ;
  callExtensionSetter_appendInstructionToStepDo ((cPtr_debuggerContext *) ptr_10742, inArgument_instruction, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 337)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_appendInstructionToStepDo (void) {
  enterExtensionSetter_appendInstructionToStepDo (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                  extensionSetter_gtlContext_appendInstructionToStepDo) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_appendInstructionToStepDo (void) {
  gExtensionModifierTable_gtlContext_appendInstructionToStepDo.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_appendInstructionToStepDo (defineExtensionSetter_gtlContext_appendInstructionToStepDo,
                                                                 freeExtensionModifier_gtlContext_appendInstructionToStepDo) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@gtlContext deleteStepDoInstruction'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteStepDoInstruction> gExtensionModifierTable_gtlContext_deleteStepDoInstruction ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteStepDoInstruction (const int32_t inClassIndex,
                                                   extensionSetterSignature_gtlContext_deleteStepDoInstruction inModifier) {
  gExtensionModifierTable_gtlContext_deleteStepDoInstruction.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteStepDoInstruction (cPtr_gtlContext * inObject,
                                                  const GALGAS_lbigint constin_numToDelete,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteStepDoInstruction f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteStepDoInstruction.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteStepDoInstruction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteStepDoInstruction.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteStepDoInstruction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteStepDoInstruction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteStepDoInstruction (cPtr_gtlContext * inObject,
                                                                const GALGAS_lbigint constinArgument_numToDelete,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_10959 = (cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr () ;
  callExtensionSetter_deleteStepDoInstruction ((cPtr_debuggerContext *) ptr_10959, constinArgument_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 344)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteStepDoInstruction (void) {
  enterExtensionSetter_deleteStepDoInstruction (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                extensionSetter_gtlContext_deleteStepDoInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteStepDoInstruction (void) {
  gExtensionModifierTable_gtlContext_deleteStepDoInstruction.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteStepDoInstruction (defineExtensionSetter_gtlContext_deleteStepDoInstruction,
                                                               freeExtensionModifier_gtlContext_deleteStepDoInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@gtlContext listStepDoInstructions'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_listStepDoInstructions> gExtensionMethodTable_gtlContext_listStepDoInstructions ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listStepDoInstructions (const int32_t inClassIndex,
                                                  extensionMethodSignature_gtlContext_listStepDoInstructions inMethod) {
  gExtensionMethodTable_gtlContext_listStepDoInstructions.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listStepDoInstructions (const cPtr_gtlContext * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_listStepDoInstructions f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_listStepDoInstructions.count ()) {
      f = gExtensionMethodTable_gtlContext_listStepDoInstructions (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_listStepDoInstructions.count ()) {
           f = gExtensionMethodTable_gtlContext_listStepDoInstructions (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_listStepDoInstructions.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_listStepDoInstructions (const cPtr_gtlContext * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_listStepDoInstructions ((const cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 350)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_listStepDoInstructions (void) {
  enterExtensionMethod_listStepDoInstructions (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                               extensionMethod_gtlContext_listStepDoInstructions) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_listStepDoInstructions (void) {
  gExtensionMethodTable_gtlContext_listStepDoInstructions.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_listStepDoInstructions (defineExtensionMethod_gtlContext_listStepDoInstructions,
                                                              freeExtensionMethod_gtlContext_listStepDoInstructions) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@gtlContext executeStepDoList'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_executeStepDoList> gExtensionMethodTable_gtlContext_executeStepDoList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_executeStepDoList (const int32_t inClassIndex,
                                             extensionMethodSignature_gtlContext_executeStepDoList inMethod) {
  gExtensionMethodTable_gtlContext_executeStepDoList.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_executeStepDoList (const cPtr_gtlContext * inObject,
                                            GALGAS_gtlContext & io_context,
                                            GALGAS_gtlData & io_vars,
                                            GALGAS_library & io_lib,
                                            GALGAS_string & io_outputString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_executeStepDoList f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_executeStepDoList.count ()) {
      f = gExtensionMethodTable_gtlContext_executeStepDoList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_executeStepDoList.count ()) {
           f = gExtensionMethodTable_gtlContext_executeStepDoList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_executeStepDoList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_vars, io_lib, io_outputString, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_executeStepDoList (const cPtr_gtlContext * inObject,
                                                          GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & ioArgument_outputString,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  inCompiler->printMessage (callExtensionGetter_outputStyle ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 360))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 360)) ;
  cEnumerator_gtlInstructionList enumerator_11463 (object->mAttribute_debuggerContext.getter_doList (SOURCE_FILE ("gtl_debugger.galgas", 361)), kEnumeration_up) ;
  while (enumerator_11463.hasCurrentObject ()) {
    callExtensionMethod_execute ((const cPtr_gtlInstruction *) enumerator_11463.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 362)) ;
    enumerator_11463.gotoNextObject () ;
  }
  inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 364))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 364)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_executeStepDoList (void) {
  enterExtensionMethod_executeStepDoList (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                          extensionMethod_gtlContext_executeStepDoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_executeStepDoList (void) {
  gExtensionMethodTable_gtlContext_executeStepDoList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_executeStepDoList (defineExtensionMethod_gtlContext_executeStepDoList,
                                                         freeExtensionMethod_gtlContext_executeStepDoList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext setBreakpoint'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setBreakpoint> gExtensionModifierTable_gtlContext_setBreakpoint ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setBreakpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_setBreakpoint inModifier) {
  gExtensionModifierTable_gtlContext_setBreakpoint.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setBreakpoint (cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_fileName,
                                        const GALGAS_uint constin_lineNum,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setBreakpoint f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setBreakpoint.count ()) {
      f = gExtensionModifierTable_gtlContext_setBreakpoint (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setBreakpoint.count ()) {
           f = gExtensionModifierTable_gtlContext_setBreakpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setBreakpoint.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_fileName, constin_lineNum, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setBreakpoint (cPtr_gtlContext * inObject,
                                                      const GALGAS_string constinArgument_fileName,
                                                      const GALGAS_uint constinArgument_lineNum,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_11740 = (cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr () ;
  callExtensionSetter_setBreakpoint ((cPtr_debuggerContext *) ptr_11740, constinArgument_fileName, constinArgument_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 372)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setBreakpoint (void) {
  enterExtensionSetter_setBreakpoint (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionSetter_gtlContext_setBreakpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setBreakpoint (void) {
  gExtensionModifierTable_gtlContext_setBreakpoint.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setBreakpoint (defineExtensionSetter_gtlContext_setBreakpoint,
                                                     freeExtensionModifier_gtlContext_setBreakpoint) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@gtlContext listBreakpoints'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_listBreakpoints> gExtensionMethodTable_gtlContext_listBreakpoints ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listBreakpoints (const int32_t inClassIndex,
                                           extensionMethodSignature_gtlContext_listBreakpoints inMethod) {
  gExtensionMethodTable_gtlContext_listBreakpoints.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listBreakpoints (const cPtr_gtlContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_listBreakpoints f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_listBreakpoints.count ()) {
      f = gExtensionMethodTable_gtlContext_listBreakpoints (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_listBreakpoints.count ()) {
           f = gExtensionMethodTable_gtlContext_listBreakpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_listBreakpoints.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_listBreakpoints (const cPtr_gtlContext * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_listBreakpoints ((const cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 378)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_listBreakpoints (void) {
  enterExtensionMethod_listBreakpoints (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                        extensionMethod_gtlContext_listBreakpoints) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_listBreakpoints (void) {
  gExtensionMethodTable_gtlContext_listBreakpoints.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_listBreakpoints (defineExtensionMethod_gtlContext_listBreakpoints,
                                                       freeExtensionMethod_gtlContext_listBreakpoints) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext deleteBreakpoint'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteBreakpoint> gExtensionModifierTable_gtlContext_deleteBreakpoint ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteBreakpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_deleteBreakpoint inModifier) {
  gExtensionModifierTable_gtlContext_deleteBreakpoint.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteBreakpoint (cPtr_gtlContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteBreakpoint f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteBreakpoint.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteBreakpoint (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteBreakpoint.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteBreakpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteBreakpoint.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteBreakpoint (cPtr_gtlContext * inObject,
                                                         const GALGAS_lbigint constinArgument_numToDelete,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_12101 = (cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr () ;
  callExtensionSetter_deleteBreakpoint ((cPtr_debuggerContext *) ptr_12101, constinArgument_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 385)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteBreakpoint (void) {
  enterExtensionSetter_deleteBreakpoint (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_deleteBreakpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteBreakpoint (void) {
  gExtensionModifierTable_gtlContext_deleteBreakpoint.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteBreakpoint (defineExtensionSetter_gtlContext_deleteBreakpoint,
                                                        freeExtensionModifier_gtlContext_deleteBreakpoint) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext setLoopOnCommand'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setLoopOnCommand> gExtensionModifierTable_gtlContext_setLoopOnCommand ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setLoopOnCommand (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_setLoopOnCommand inModifier) {
  gExtensionModifierTable_gtlContext_setLoopOnCommand.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setLoopOnCommand (cPtr_gtlContext * inObject,
                                           GALGAS_bool in_loopOnCommand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setLoopOnCommand f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setLoopOnCommand.count ()) {
      f = gExtensionModifierTable_gtlContext_setLoopOnCommand (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setLoopOnCommand.count ()) {
           f = gExtensionModifierTable_gtlContext_setLoopOnCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setLoopOnCommand.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_loopOnCommand, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setLoopOnCommand (cPtr_gtlContext * inObject,
                                                         GALGAS_bool inArgument_loopOnCommand,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.setter_setLoopOnCommand (inArgument_loopOnCommand COMMA_SOURCE_FILE ("gtl_debugger.galgas", 392)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setLoopOnCommand (void) {
  enterExtensionSetter_setLoopOnCommand (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_setLoopOnCommand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setLoopOnCommand (void) {
  gExtensionModifierTable_gtlContext_setLoopOnCommand.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setLoopOnCommand (defineExtensionSetter_gtlContext_setLoopOnCommand,
                                                        freeExtensionModifier_gtlContext_setLoopOnCommand) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension getter '@gtlContext loopOnCommand'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_loopOnCommand> gExtensionGetterTable_gtlContext_loopOnCommand ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_loopOnCommand (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlContext_loopOnCommand inGetter) {
  gExtensionGetterTable_gtlContext_loopOnCommand.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_loopOnCommand (const cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_loopOnCommand f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_loopOnCommand.count ()) {
      f = gExtensionGetterTable_gtlContext_loopOnCommand (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_loopOnCommand.count ()) {
           f = gExtensionGetterTable_gtlContext_loopOnCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_loopOnCommand.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_loopOnCommand (const cPtr_gtlContext * inObject,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_loopOnCommand ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_loopOnCommand = object->mAttribute_debuggerContext.getter_loopOnCommand (SOURCE_FILE ("gtl_debugger.galgas", 399)) ;
//---
  return result_loopOnCommand ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_loopOnCommand (void) {
  enterExtensionGetter_loopOnCommand (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionGetter_gtlContext_loopOnCommand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_loopOnCommand (void) {
  gExtensionGetterTable_gtlContext_loopOnCommand.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_loopOnCommand (defineExtensionGetter_gtlContext_loopOnCommand,
                                                     freeExtensionGetter_gtlContext_loopOnCommand) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension method '@gtlContext hereWeAre'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_hereWeAre> gExtensionMethodTable_gtlContext_hereWeAre ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_hereWeAre (const int32_t inClassIndex,
                                     extensionMethodSignature_gtlContext_hereWeAre inMethod) {
  gExtensionMethodTable_gtlContext_hereWeAre.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_hereWeAre (const cPtr_gtlContext * inObject,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_hereWeAre f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_hereWeAre.count ()) {
      f = gExtensionMethodTable_gtlContext_hereWeAre (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_hereWeAre.count ()) {
           f = gExtensionMethodTable_gtlContext_hereWeAre (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_hereWeAre.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_hereWeAre (const cPtr_gtlContext * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_hereWeAre ((const cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 405)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_hereWeAre (void) {
  enterExtensionMethod_hereWeAre (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                  extensionMethod_gtlContext_hereWeAre) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_hereWeAre (void) {
  gExtensionMethodTable_gtlContext_hereWeAre.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_hereWeAre (defineExtensionMethod_gtlContext_hereWeAre,
                                                 freeExtensionMethod_gtlContext_hereWeAre) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension setter '@gtlContext pushInstructionList'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_pushInstructionList> gExtensionModifierTable_gtlContext_pushInstructionList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_pushInstructionList (const int32_t inClassIndex,
                                               extensionSetterSignature_gtlContext_pushInstructionList inModifier) {
  gExtensionModifierTable_gtlContext_pushInstructionList.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_pushInstructionList (cPtr_gtlContext * inObject,
                                              const GALGAS_gtlInstructionList constin_instructionList,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_pushInstructionList f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_pushInstructionList.count ()) {
      f = gExtensionModifierTable_gtlContext_pushInstructionList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_pushInstructionList.count ()) {
           f = gExtensionModifierTable_gtlContext_pushInstructionList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_pushInstructionList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_instructionList, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_pushInstructionList (cPtr_gtlContext * inObject,
                                                            const GALGAS_gtlInstructionList constinArgument_instructionList,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_12854 = (cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr () ;
  callExtensionSetter_pushInstructionList ((cPtr_debuggerContext *) ptr_12854, constinArgument_instructionList, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 412)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_pushInstructionList (void) {
  enterExtensionSetter_pushInstructionList (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                            extensionSetter_gtlContext_pushInstructionList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_pushInstructionList (void) {
  gExtensionModifierTable_gtlContext_pushInstructionList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_pushInstructionList (defineExtensionSetter_gtlContext_pushInstructionList,
                                                           freeExtensionModifier_gtlContext_pushInstructionList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@gtlContext popInstructionList'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_popInstructionList> gExtensionModifierTable_gtlContext_popInstructionList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_popInstructionList (const int32_t inClassIndex,
                                              extensionSetterSignature_gtlContext_popInstructionList inModifier) {
  gExtensionModifierTable_gtlContext_popInstructionList.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_popInstructionList (cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_popInstructionList f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_popInstructionList.count ()) {
      f = gExtensionModifierTable_gtlContext_popInstructionList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_popInstructionList.count ()) {
           f = gExtensionModifierTable_gtlContext_popInstructionList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_popInstructionList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_popInstructionList (cPtr_gtlContext * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_13036 = (cPtr_debuggerContext *) object->mAttribute_debuggerContext.ptr () ;
  callExtensionSetter_popInstructionList ((cPtr_debuggerContext *) ptr_13036, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 418)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_popInstructionList (void) {
  enterExtensionSetter_popInstructionList (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                           extensionSetter_gtlContext_popInstructionList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_popInstructionList (void) {
  gExtensionModifierTable_gtlContext_popInstructionList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_popInstructionList (defineExtensionSetter_gtlContext_popInstructionList,
                                                          freeExtensionModifier_gtlContext_popInstructionList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@gtlContext setNextInstructionIndex'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setNextInstructionIndex> gExtensionModifierTable_gtlContext_setNextInstructionIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setNextInstructionIndex (const int32_t inClassIndex,
                                                   extensionSetterSignature_gtlContext_setNextInstructionIndex inModifier) {
  gExtensionModifierTable_gtlContext_setNextInstructionIndex.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setNextInstructionIndex (cPtr_gtlContext * inObject,
                                                  GALGAS_uint in_index,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setNextInstructionIndex f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setNextInstructionIndex.count ()) {
      f = gExtensionModifierTable_gtlContext_setNextInstructionIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setNextInstructionIndex.count ()) {
           f = gExtensionModifierTable_gtlContext_setNextInstructionIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setNextInstructionIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_index, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setNextInstructionIndex (cPtr_gtlContext * inObject,
                                                                GALGAS_uint inArgument_index,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mAttribute_debuggerContext.setter_setNextInstructionIndex (inArgument_index COMMA_SOURCE_FILE ("gtl_debugger.galgas", 425)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setNextInstructionIndex (void) {
  enterExtensionSetter_setNextInstructionIndex (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                extensionSetter_gtlContext_setNextInstructionIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setNextInstructionIndex (void) {
  gExtensionModifierTable_gtlContext_setNextInstructionIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setNextInstructionIndex (defineExtensionSetter_gtlContext_setNextInstructionIndex,
                                                               freeExtensionModifier_gtlContext_setNextInstructionIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension getter '@applicationDefinition templateData'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_applicationDefinition_templateData> gExtensionGetterTable_applicationDefinition_templateData ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_templateData (const int32_t inClassIndex,
                                        enterExtensionGetter_applicationDefinition_templateData inGetter) {
  gExtensionGetterTable_applicationDefinition_templateData.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_templateData (const cPtr_applicationDefinition * inObject,
                                                 const GALGAS_implementation & in_imp,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_applicationDefinition_templateData f = NULL ;
    if (classIndex < gExtensionGetterTable_applicationDefinition_templateData.count ()) {
      f = gExtensionGetterTable_applicationDefinition_templateData (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_applicationDefinition_templateData.count ()) {
           f = gExtensionGetterTable_applicationDefinition_templateData (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_applicationDefinition_templateData.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_imp, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_applicationDefinition_templateData (const cPtr_applicationDefinition * inObject,
                                                                          const GALGAS_implementation & constinArgument_imp,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_cfg ; // Returned variable
  const cPtr_applicationDefinition * object = inObject ;
  macroValidSharedObject (object, cPtr_applicationDefinition) ;
  result_cfg = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 190)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 190)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 190))  COMMA_SOURCE_FILE ("systemConfig.galgas", 190)) ;
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_5806 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5806, GALGAS_lstring::constructor_new (GALGAS_string ("OILFILENAME"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 196))  COMMA_SOURCE_FILE ("systemConfig.galgas", 196)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 198)), function_lstring (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 199)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 199)), GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 200)).getter_lastPathComponent (SOURCE_FILE ("systemConfig.galgas", 200))  COMMA_SOURCE_FILE ("systemConfig.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 195)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_6031 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6031, GALGAS_lstring::constructor_new (GALGAS_string ("CPUNAME"), object->mAttribute_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 205))  COMMA_SOURCE_FILE ("systemConfig.galgas", 205)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 206)), function_lstring (GALGAS_string ("name of the CPU object"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 206)), object->mAttribute_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 206))  COMMA_SOURCE_FILE ("systemConfig.galgas", 206)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 204)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_6185 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6185, GALGAS_lstring::constructor_new (GALGAS_string ("CPUDESCRIPTION"), object->mAttribute_cpuDescription.getter_location (SOURCE_FILE ("systemConfig.galgas", 210))  COMMA_SOURCE_FILE ("systemConfig.galgas", 210)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 211)), function_lstring (GALGAS_string ("description of the CPU object"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 211)), object->mAttribute_cpuDescription.getter_string (SOURCE_FILE ("systemConfig.galgas", 211))  COMMA_SOURCE_FILE ("systemConfig.galgas", 211)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 209)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_6373 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6373, GALGAS_lstring::constructor_new (GALGAS_string ("OILVERSION"), object->mAttribute_version.getter_location (SOURCE_FILE ("systemConfig.galgas", 215))  COMMA_SOURCE_FILE ("systemConfig.galgas", 215)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 216)), object->mAttribute_versionDescription, object->mAttribute_version.getter_string (SOURCE_FILE ("systemConfig.galgas", 216))  COMMA_SOURCE_FILE ("systemConfig.galgas", 216)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 214)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_6519 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6519, GALGAS_lstring::constructor_new (GALGAS_string ("OILDESCRIPTION"), object->mAttribute_versionDescription.getter_location (SOURCE_FILE ("systemConfig.galgas", 220))  COMMA_SOURCE_FILE ("systemConfig.galgas", 220)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 221)), object->mAttribute_versionDescription, object->mAttribute_versionDescription.getter_string (SOURCE_FILE ("systemConfig.galgas", 221))  COMMA_SOURCE_FILE ("systemConfig.galgas", 221)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 219)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_6691 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6691, GALGAS_lstring::constructor_new (GALGAS_string ("TIMESTAMP"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 225))  COMMA_SOURCE_FILE ("systemConfig.galgas", 225)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 227)), function_lstring (GALGAS_string ("timestamp of OIL compiling"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 228)), GALGAS_string::constructor_stringWithCurrentDateTime (SOURCE_FILE ("systemConfig.galgas", 229))  COMMA_SOURCE_FILE ("systemConfig.galgas", 226)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 224)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_6896 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6896, GALGAS_lstring::constructor_new (GALGAS_string ("PROJECT"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 234))  COMMA_SOURCE_FILE ("systemConfig.galgas", 234)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 236)), function_lstring (GALGAS_string ("project name"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 237)), function_projectName (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 238)).getter_lastPathComponent (SOURCE_FILE ("systemConfig.galgas", 238))  COMMA_SOURCE_FILE ("systemConfig.galgas", 235)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 233)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_7086 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7086, GALGAS_lstring::constructor_new (GALGAS_string ("TARGET"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 243))  COMMA_SOURCE_FILE ("systemConfig.galgas", 243)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 245)), function_lstring (GALGAS_string ("target architecture/chip/board"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 246)), GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ())  COMMA_SOURCE_FILE ("systemConfig.galgas", 244)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 242)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_7300 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7300, GALGAS_lstring::constructor_new (GALGAS_string ("TEMPLATEPATH"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 252))  COMMA_SOURCE_FILE ("systemConfig.galgas", 252)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 254)), function_lstring (GALGAS_string ("path of the templates used"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 255)), GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ())  COMMA_SOURCE_FILE ("systemConfig.galgas", 253)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 251)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_7515 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7515, GALGAS_lstring::constructor_new (GALGAS_string ("ARCH"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 261))  COMMA_SOURCE_FILE ("systemConfig.galgas", 261)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 262)), function_lstring (GALGAS_string ("target architecture"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 262)), function_arch (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 262))  COMMA_SOURCE_FILE ("systemConfig.galgas", 262)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 260)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_7656 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7656, GALGAS_lstring::constructor_new (GALGAS_string ("CHIP"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 266))  COMMA_SOURCE_FILE ("systemConfig.galgas", 266)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 267)), function_lstring (GALGAS_string ("target chip"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 267)), function_chip (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 267))  COMMA_SOURCE_FILE ("systemConfig.galgas", 267)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 265)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_7788 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7788, GALGAS_lstring::constructor_new (GALGAS_string ("BOARD"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 271))  COMMA_SOURCE_FILE ("systemConfig.galgas", 271)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 272)), function_lstring (GALGAS_string ("target board"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 272)), function_board (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 272))  COMMA_SOURCE_FILE ("systemConfig.galgas", 272)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 270)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_7923 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7923, GALGAS_lstring::constructor_new (GALGAS_string ("TARGETPATHLIST"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 276))  COMMA_SOURCE_FILE ("systemConfig.galgas", 276)), GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 277)), function_lstring (GALGAS_string ("target path list"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 277)), function_targetPathList (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 277))  COMMA_SOURCE_FILE ("systemConfig.galgas", 277)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 275)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_8079 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_8079, GALGAS_lstring::constructor_new (GALGAS_string ("LOGFILE"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 281))  COMMA_SOURCE_FILE ("systemConfig.galgas", 281)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 283)), function_lstring (GALGAS_string ("Generated a logfile"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 284)), GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ())  COMMA_SOURCE_FILE ("systemConfig.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 280)) ;
  }
  GALGAS_gtlData var_opts_8311 = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 291)), function_lstring (GALGAS_string ("Passed options"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 292)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 293))  COMMA_SOURCE_FILE ("systemConfig.galgas", 290)) ;
  GALGAS_string var_optionString_8416 = extensionGetter_trimRight (extensionGetter_trimLeft (GALGAS_string (gOption_goil_5F_options_passOption.getter_value ()), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 295)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 295)) ;
  GALGAS_bool test_0 = GALGAS_bool (kIsStrictSup, var_optionString_8416.getter_length (SOURCE_FILE ("systemConfig.galgas", 296)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_pierreOption.getter_value ()) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    var_opts_8311.drop () ;
    cGrammar_options_5F_grammar::_performSourceStringParsing_ (inCompiler, GALGAS_string (gOption_goil_5F_options_passOption.getter_value ()), GALGAS_string ("Passed options"), var_opts_8311  COMMA_SOURCE_FILE ("systemConfig.galgas", 297)) ;
  }
  {
  result_cfg.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_8673 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_8673, GALGAS_lstring::constructor_new (GALGAS_string ("PASSEDOPTIONS"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 301))  COMMA_SOURCE_FILE ("systemConfig.galgas", 301)), var_opts_8311, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 300)) ;
  }
  cEnumerator_objectsMap enumerator_8770 (object->mAttribute_objects, kEnumeration_up) ;
  while (enumerator_8770.hasCurrentObject ()) {
    GALGAS_implementationObject var_implementationObject_9010 ;
    constinArgument_imp.getter_imp (SOURCE_FILE ("systemConfig.galgas", 309)).method_get (enumerator_8770.current_lkey (HERE), var_implementationObject_9010, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 309)) ;
    const enumGalgasBool test_2 = var_implementationObject_9010.getter_multiple (SOURCE_FILE ("systemConfig.galgas", 310)).getter_bool (SOURCE_FILE ("systemConfig.galgas", 310)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_gtlList var_objs_9082 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 311)), enumerator_8770.current_lkey (HERE), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 311))  COMMA_SOURCE_FILE ("systemConfig.galgas", 311)) ;
      cEnumerator_objectKindMap enumerator_9159 (enumerator_8770.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 312)), kEnumeration_up) ;
      while (enumerator_9159.hasCurrentObject ()) {
        GALGAS_gtlData var_attrs_9185 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) enumerator_9159.current_attributes (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 313)) ;
        {
        var_objs_9082.insulate (HERE) ;
        cPtr_gtlList * ptr_9225 = (cPtr_gtlList *) var_objs_9082.ptr () ;
        callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_9225, var_attrs_9185, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 314)) ;
        }
        enumerator_9159.gotoNextObject () ;
      }
      {
      result_cfg.insulate (HERE) ; // §ABSTRACT
      cPtr_gtlData * ptr_9267 = (cPtr_gtlData *) result_cfg.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9267, enumerator_8770.current_lkey (HERE), var_objs_9082, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 316)) ;
      }
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, enumerator_8770.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 322)).getter_count (SOURCE_FILE ("systemConfig.galgas", 322)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_gtlData var_attrs_9432 = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 323)), enumerator_8770.current_lkey (HERE), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 323))  COMMA_SOURCE_FILE ("systemConfig.galgas", 323)) ;
        cEnumerator_objectKindMap enumerator_9520 (enumerator_8770.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 324)), kEnumeration_up) ;
        while (enumerator_9520.hasCurrentObject ()) {
          var_attrs_9432 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) enumerator_9520.current_attributes (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 325)) ;
          enumerator_9520.gotoNextObject () ;
        }
        {
        result_cfg.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_9590 = (cPtr_gtlData *) result_cfg.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9590, enumerator_8770.current_lkey (HERE), var_attrs_9432, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 327)) ;
        }
      }
    }
    enumerator_8770.gotoNextObject () ;
  }
//---
  return result_cfg ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_applicationDefinition_templateData (void) {
  enterExtensionGetter_templateData (kTypeDescriptor_GALGAS_applicationDefinition.mSlotID,
                                     extensionGetter_applicationDefinition_templateData) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_applicationDefinition_templateData (void) {
  gExtensionGetterTable_applicationDefinition_templateData.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_applicationDefinition_templateData (defineExtensionGetter_applicationDefinition_templateData,
                                                               freeExtensionGetter_applicationDefinition_templateData) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@objectKind verifyCrossReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_objectKind_verifyCrossReferences> gExtensionMethodTable_objectKind_verifyCrossReferences ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_objectKind_verifyCrossReferences inMethod) {
  gExtensionMethodTable_objectKind_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyCrossReferences (const cPtr_objectKind * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObject constin_obj,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectKind) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_objectKind_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_objectKind_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_objectKind_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_objectKind_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_objectKind_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_objectKind_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_allObjects, constin_obj, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectKind_verifyCrossReferences (const cPtr_objectKind * inObject,
                                                              const GALGAS_objectsMap constinArgument_allObjects,
                                                              const GALGAS_implementationObject constinArgument_obj,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectKind * object = inObject ;
  macroValidSharedObject (object, cPtr_objectKind) ;
  cEnumerator_objectKindMap enumerator_18395 (object->mAttribute_objects, kEnumeration_up) ;
  while (enumerator_18395.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) enumerator_18395.current_attributes (HERE).ptr (), constinArgument_allObjects, constinArgument_obj.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 590)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 590)) ;
    enumerator_18395.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectKind_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectKind.mSlotID,
                                              extensionMethod_objectKind_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_objectKind_verifyCrossReferences (void) {
  gExtensionMethodTable_objectKind_verifyCrossReferences.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectKind_verifyCrossReferences (defineExtensionMethod_objectKind_verifyCrossReferences,
                                                             freeExtensionMethod_objectKind_verifyCrossReferences) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlStruct overrideMap'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlStruct extensionGetter_gtlStruct_overrideMap (const cPtr_gtlData * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlStruct result_mapOverriden ; // Returned variable
  const cPtr_gtlStruct * object = (const cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  result_mapOverriden = GALGAS_gtlStruct::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 35)), GALGAS_gtlVarMap::constructor_mapWithMapToOverride (object->mAttribute_value  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 36))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 33)) ;
//---
  return result_mapOverriden ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlStruct_overrideMap (void) {
  enterExtensionGetter_overrideMap (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                    extensionGetter_gtlStruct_overrideMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlStruct_overrideMap (defineExtensionGetter_gtlStruct_overrideMap, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlStruct overriddenMap'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlStruct extensionGetter_gtlStruct_overriddenMap (const cPtr_gtlData * inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlStruct result_overriddenMap ; // Returned variable
  const cPtr_gtlStruct * object = (const cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  result_overriddenMap = GALGAS_gtlStruct::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44)), object->mAttribute_value.getter_overriddenMap (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44)) ;
//---
  return result_overriddenMap ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlStruct_overriddenMap (void) {
  enterExtensionGetter_overriddenMap (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                      extensionGetter_gtlStruct_overriddenMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlStruct_overriddenMap (defineExtensionGetter_gtlStruct_overriddenMap, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlVarItemField location'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_gtlVarItemField_location (const cPtr_gtlVarItem * inObject,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_loc ; // Returned variable
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  result_loc = object->mAttribute_field.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 150)) ;
//---
  return result_loc ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                 extensionGetter_gtlVarItemField_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_location (defineExtensionGetter_gtlVarItemField_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@gtlVarItemField stringPath'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarItemField_stringPath (const cPtr_gtlVarItem * inObject,
                                                                 const GALGAS_gtlData & /* constinArgument_vars */,
                                                                 const GALGAS_library & /* constinArgument_lib */,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  result_result = object->mAttribute_field.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 158)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_stringPath (void) {
  enterExtensionGetter_stringPath (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                   extensionGetter_gtlVarItemField_stringPath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_stringPath (defineExtensionGetter_gtlVarItemField_stringPath, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlVarItemField setInContext'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVarItemField_setInContext (const cPtr_gtlVarItem * inObject,
                                                          GALGAS_gtlData & ioArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          const GALGAS_gtlVarPath constinArgument_path,
                                                          const GALGAS_gtlData constinArgument_newData,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 177)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 178)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_context.insulate (HERE) ; // §ABSTRACT
    cPtr_gtlData * ptr_5370 = (cPtr_gtlData *) ioArgument_context.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5370, object->mAttribute_field, constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 179)) ;
    }
  }else if (kBoolFalse == test_0) {
    GALGAS_gtlData var_data_5456 ;
    callExtensionMethod_structField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, var_data_5456, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 181)) ;
    callExtensionMethod_setInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 182)).ptr (), var_data_5456, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 186)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 182)) ;
    {
    ioArgument_context.insulate (HERE) ; // §ABSTRACT
    cPtr_gtlData * ptr_5603 = (cPtr_gtlData *) ioArgument_context.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5603, object->mAttribute_field, var_data_5456, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 189)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVarItemField_setInContext (void) {
  enterExtensionMethod_setInContext (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                     extensionMethod_gtlVarItemField_setInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItemField_setInContext (defineExtensionMethod_gtlVarItemField_setInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlVarItemField getInContext'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlVarItemField_getInContext (const cPtr_gtlVarItem * inObject,
                                                                    const GALGAS_gtlData & constinArgument_context,
                                                                    const GALGAS_gtlData & constinArgument_vars,
                                                                    const GALGAS_library & constinArgument_lib,
                                                                    const GALGAS_gtlVarPath & constinArgument_path,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  GALGAS_gtlData var_data_6064 ;
  callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_context.ptr (), object->mAttribute_field, var_data_6064, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 203)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 204)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = var_data_6064 ;
  }else if (kBoolFalse == test_0) {
    result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 207)).ptr (), var_data_6064, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 211)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 207)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_getInContext (void) {
  enterExtensionGetter_getInContext (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                     extensionGetter_gtlVarItemField_getInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_getInContext (defineExtensionGetter_gtlVarItemField_getInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlVarItemField existsInContext'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlVarItemField_existsInContext (const cPtr_gtlVarItem * inObject,
                                                                    const GALGAS_gtlData & constinArgument_context,
                                                                    const GALGAS_gtlData & constinArgument_vars,
                                                                    const GALGAS_library & constinArgument_lib,
                                                                    const GALGAS_gtlVarPath & constinArgument_path,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) constinArgument_context.ptr (), object->mAttribute_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 226)).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 227)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_result = GALGAS_bool (true) ;
    }else if (kBoolFalse == test_1) {
      GALGAS_gtlData var_subContext_6783 ;
      callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_context.ptr (), object->mAttribute_field, var_subContext_6783, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 230)) ;
      result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 231)).ptr (), var_subContext_6783, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 235)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 231)) ;
    }
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_bool (false) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_existsInContext (void) {
  enterExtensionGetter_existsInContext (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                        extensionGetter_gtlVarItemField_existsInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_existsInContext (defineExtensionGetter_gtlVarItemField_existsInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@gtlVarItemField deleteInContext'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVarItemField_deleteInContext (const cPtr_gtlVarItem * inObject,
                                                             GALGAS_gtlData & ioArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             const GALGAS_gtlVarPath constinArgument_path,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVarItemField * object = (const cPtr_gtlVarItemField *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 252)).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 253)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_1) {
      {
      ioArgument_context.insulate (HERE) ; // §ABSTRACT
      cPtr_gtlData * ptr_7422 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_deleteStructField ((cPtr_gtlData *) ptr_7422, object->mAttribute_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 254)) ;
      }
    }else if (kBoolFalse == test_1) {
      GALGAS_gtlData var_data_7506 ;
      callExtensionMethod_structField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, var_data_7506, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 256)) ;
      callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 257)).ptr (), var_data_7506, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 257)) ;
      {
      ioArgument_context.insulate (HERE) ; // §ABSTRACT
      cPtr_gtlData * ptr_7655 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7655, object->mAttribute_field, var_data_7506, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 263)) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVarItemField_deleteInContext (void) {
  enterExtensionMethod_deleteInContext (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                        extensionMethod_gtlVarItemField_deleteInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItemField_deleteInContext (defineExtensionMethod_gtlVarItemField_deleteInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlVarItemCollection stringPath'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarItemCollection_stringPath (const cPtr_gtlVarItem * inObject,
                                                                      const GALGAS_gtlData & constinArgument_vars,
                                                                      const GALGAS_library & constinArgument_lib,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarItemCollection * object = (const cPtr_gtlVarItemCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemCollection) ;
  result_result = object->mAttribute_field.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 278)).add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 278)) ;
  GALGAS_gtlData var_keyValue_8153 = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 279)) ;
  if (var_keyValue_8153.isValid ()) {
    if (var_keyValue_8153.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_8224_keyString ((cPtr_gtlString *) var_keyValue_8153.ptr ()) ;
      result_result.plusAssign_operation(GALGAS_string ("\"").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) cast_8224_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 282)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 282)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 282)) ;
    }else if (var_keyValue_8153.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_8288_keyInt ((cPtr_gtlInt *) var_keyValue_8153.ptr ()) ;
      result_result.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlInt *) cast_8288_keyInt.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 284)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 284)) ;
    }
  }
  result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 286)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemCollection_stringPath (void) {
  enterExtensionGetter_stringPath (kTypeDescriptor_GALGAS_gtlVarItemCollection.mSlotID,
                                   extensionGetter_gtlVarItemCollection_stringPath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemCollection_stringPath (defineExtensionGetter_gtlVarItemCollection_stringPath, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@gtlVarItemCollection setInContext'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVarItemCollection_setInContext (const cPtr_gtlVarItem * inObject,
                                                               GALGAS_gtlData & ioArgument_context,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               const GALGAS_gtlVarPath constinArgument_path,
                                                               const GALGAS_gtlData constinArgument_newData,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVarItemCollection * object = (const cPtr_gtlVarItemCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemCollection) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 299)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 299)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_8787_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 299)).ptr ()) ;
      ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)) ;
      GALGAS_gtlData var_data_8873 ;
      callExtensionMethod_structField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, var_data_8873, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 302)) ;
      var_data_8873 = function_wantGtlMap (var_data_8873, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 303)) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 304)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        var_data_8873.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_8948 = (cPtr_gtlData *) var_data_8873.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_8948, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_8787_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 305)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 305)) ;
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_9041 ;
        callExtensionMethod_mapItem ((const cPtr_gtlData *) var_data_8873.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_8787_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 307)), var_subContext_9041, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 307)) ;
        callExtensionMethod_setInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 308)).ptr (), var_subContext_9041, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 312)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 308)) ;
        {
        var_data_8873.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_9207 = (cPtr_gtlData *) var_data_8873.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_9207, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_8787_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 315)), var_subContext_9041, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 315)) ;
        }
      }
      {
      ioArgument_context.insulate (HERE) ; // §ABSTRACT
      cPtr_gtlData * ptr_9265 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9265, object->mAttribute_field, var_data_8873, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 317)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 299)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_9319_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 299)).ptr ()) ;
      ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)) ;
      GALGAS_gtlData var_data_9405 ;
      callExtensionMethod_structField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, var_data_9405, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 320)) ;
      var_data_9405 = function_wantGtlList (var_data_9405, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 321)) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 322)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        var_data_9405.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_9481 = (cPtr_gtlData *) var_data_9405.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_9481, constinArgument_newData, cast_9319_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 323)) ;
        }
      }else if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_9568 ;
        callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) var_data_9405.ptr (), var_subContext_9568, cast_9319_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 325)) ;
        callExtensionMethod_setInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 326)).ptr (), var_subContext_9568, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 330)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 326)) ;
        {
        var_data_9405.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_9742 = (cPtr_gtlData *) var_data_9405.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_9742, var_subContext_9568, cast_9319_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 333)) ;
        }
      }
      {
      ioArgument_context.insulate (HERE) ; // §ABSTRACT
      cPtr_gtlData * ptr_9801 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9801, object->mAttribute_field, var_data_9405, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 335)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 337)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 337)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVarItemCollection_setInContext (void) {
  enterExtensionMethod_setInContext (kTypeDescriptor_GALGAS_gtlVarItemCollection.mSlotID,
                                     extensionMethod_gtlVarItemCollection_setInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItemCollection_setInContext (defineExtensionMethod_gtlVarItemCollection_setInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension getter '@gtlVarItemCollection getInContext'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlVarItemCollection_getInContext (const cPtr_gtlVarItem * inObject,
                                                                         const GALGAS_gtlData & constinArgument_context,
                                                                         const GALGAS_gtlData & constinArgument_vars,
                                                                         const GALGAS_library & constinArgument_lib,
                                                                         const GALGAS_gtlVarPath & constinArgument_path,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlVarItemCollection * object = (const cPtr_gtlVarItemCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemCollection) ;
  GALGAS_gtlData var_collection_10322 ;
  callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_context.ptr (), object->mAttribute_field, var_collection_10322, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 351)) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_10383_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)).ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 354)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_0) {
        callExtensionMethod_mapItem ((const cPtr_gtlData *) var_collection_10322.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_10383_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 355)), result_result, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 355)) ;
      }else if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_10528 ;
        callExtensionMethod_mapItem ((const cPtr_gtlData *) var_collection_10322.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_10383_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 357)), var_subContext_10528, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 357)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 358)).ptr (), var_subContext_10528, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 362)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 358)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_10704_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)).ptr ()) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 366)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_1) {
        callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) var_collection_10322.ptr (), result_result, cast_10704_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 367)) ;
      }else if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_10843 ;
        callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) var_collection_10322.ptr (), var_subContext_10843, cast_10704_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 369)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 370)).ptr (), var_subContext_10843, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 374)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 370)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 378)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 378)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemCollection_getInContext (void) {
  enterExtensionGetter_getInContext (kTypeDescriptor_GALGAS_gtlVarItemCollection.mSlotID,
                                     extensionGetter_gtlVarItemCollection_getInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemCollection_getInContext (defineExtensionGetter_gtlVarItemCollection_getInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension getter '@gtlVarItemCollection existsInContext'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlVarItemCollection_existsInContext (const cPtr_gtlVarItem * inObject,
                                                                         const GALGAS_gtlData & constinArgument_context,
                                                                         const GALGAS_gtlData & constinArgument_vars,
                                                                         const GALGAS_library & constinArgument_lib,
                                                                         const GALGAS_gtlVarPath & constinArgument_path,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlVarItemCollection * object = (const cPtr_gtlVarItemCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemCollection) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) constinArgument_context.ptr (), object->mAttribute_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 393)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlData var_collection_11565 ;
    callExtensionMethod_structField ((const cPtr_gtlData *) constinArgument_context.ptr (), object->mAttribute_field, var_collection_11565, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 394)) ;
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 395)).isValid ()) {
      if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 395)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
        GALGAS_gtlString cast_11630_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 395)).ptr ()) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 397)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_collection_11565.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11630_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 398)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 398)) ;
        }else if (kBoolFalse == test_1) {
          const enumGalgasBool test_2 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_collection_11565.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11630_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 400)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 400)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_gtlData var_subContext_11840 ;
            callExtensionMethod_mapItem ((const cPtr_gtlData *) var_collection_11565.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11630_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 401)), var_subContext_11840, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 401)) ;
            result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 402)).ptr (), var_subContext_11840, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 406)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 402)) ;
          }else if (kBoolFalse == test_2) {
            result_result = GALGAS_bool (false) ;
          }
        }
      }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 395)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
        GALGAS_gtlInt cast_12097_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 395)).ptr ()) ;
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 413)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_result = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_collection_11565.ptr (), cast_12097_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 414)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_collection_11565.ptr (), cast_12097_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 416)).boolEnum () ;
          if (kBoolTrue == test_4) {
            GALGAS_gtlData var_subContext_12302 ;
            callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) var_collection_11565.ptr (), var_subContext_12302, cast_12097_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 417)) ;
            result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 418)).ptr (), var_subContext_12302, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 422)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 418)) ;
          }else if (kBoolFalse == test_4) {
            result_result = GALGAS_bool (false) ;
          }
        }
      }else{
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 429)), GALGAS_string ("string ot int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 429)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_bool (false) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemCollection_existsInContext (void) {
  enterExtensionGetter_existsInContext (kTypeDescriptor_GALGAS_gtlVarItemCollection.mSlotID,
                                        extensionGetter_gtlVarItemCollection_existsInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemCollection_existsInContext (defineExtensionGetter_gtlVarItemCollection_existsInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlVarItemCollection deleteInContext'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVarItemCollection_deleteInContext (const cPtr_gtlVarItem * inObject,
                                                                  GALGAS_gtlData & ioArgument_context,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  const GALGAS_library constinArgument_lib,
                                                                  const GALGAS_gtlVarPath constinArgument_path,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVarItemCollection * object = (const cPtr_gtlVarItemCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemCollection) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_13071_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).ptr ()) ;
      const enumGalgasBool test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 447)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_gtlData var_data_13165 ;
        callExtensionMethod_structField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, var_data_13165, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 448)) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 449)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          const enumGalgasBool test_2 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_data_13165.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13071_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 450)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 450)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_data_13165.insulate (HERE) ; // §ABSTRACT
            cPtr_gtlData * ptr_13262 = (cPtr_gtlData *) var_data_13165.ptr () ;
            callExtensionSetter_deleteMapItem ((cPtr_gtlData *) ptr_13262, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13071_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 451)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 451)) ;
            }
          }
        }else if (kBoolFalse == test_1) {
          GALGAS_gtlData var_subContext_13365 ;
          callExtensionMethod_mapItem ((const cPtr_gtlData *) var_data_13165.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13071_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 454)), var_subContext_13365, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 454)) ;
          callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 455)).ptr (), var_subContext_13365, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 459)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 455)) ;
          {
          var_data_13165.insulate (HERE) ; // §ABSTRACT
          cPtr_gtlData * ptr_13531 = (cPtr_gtlData *) var_data_13165.ptr () ;
          callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_13531, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13071_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 461)), var_subContext_13365, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 461)) ;
          }
        }
        {
        ioArgument_context.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_13593 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_13593, object->mAttribute_field, var_data_13165, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 463)) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_13655_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).ptr ()) ;
      const enumGalgasBool test_3 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 466)).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_gtlData var_data_13749 ;
        callExtensionMethod_structField ((const cPtr_gtlData *) ioArgument_context.ptr (), object->mAttribute_field, var_data_13749, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 467)) ;
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 468)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_4) {
          const enumGalgasBool test_5 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_data_13749.ptr (), cast_13655_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 469)).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            var_data_13749.insulate (HERE) ; // §ABSTRACT
            cPtr_gtlData * ptr_13847 = (cPtr_gtlData *) var_data_13749.ptr () ;
            callExtensionSetter_deleteItemAtIndex ((cPtr_gtlData *) ptr_13847, cast_13655_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 470)) ;
            }
          }
        }else if (kBoolFalse == test_4) {
          GALGAS_gtlData var_subContext_13944 ;
          callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) var_data_13749.ptr (), var_subContext_13944, cast_13655_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 473)) ;
          callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).ptr (), var_subContext_13944, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 478)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)) ;
          {
          var_data_13749.insulate (HERE) ; // §ABSTRACT
          cPtr_gtlData * ptr_14118 = (cPtr_gtlData *) var_data_13749.ptr () ;
          callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_14118, var_subContext_13944, cast_13655_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 480)) ;
          }
        }
        {
        ioArgument_context.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_14181 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_14181, object->mAttribute_field, var_data_13749, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 482)) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 485)), GALGAS_string ("string ot int expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 485)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVarItemCollection_deleteInContext (void) {
  enterExtensionMethod_deleteInContext (kTypeDescriptor_GALGAS_gtlVarItemCollection.mSlotID,
                                        extensionMethod_gtlVarItemCollection_deleteInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItemCollection_deleteInContext (defineExtensionMethod_gtlVarItemCollection_deleteInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlVarItemSubCollection location'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_gtlVarItemSubCollection_location (const cPtr_gtlVarItem * inObject,
                                                                         C_Compiler * /* inCompiler */
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_loc ; // Returned variable
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  result_loc = object->mAttribute_subCollectionlocation ;
//---
  return result_loc ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemSubCollection_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                 extensionGetter_gtlVarItemSubCollection_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemSubCollection_location (defineExtensionGetter_gtlVarItemSubCollection_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension getter '@gtlVarItemSubCollection stringPath'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlVarItemSubCollection_stringPath (const cPtr_gtlVarItem * inObject,
                                                                         const GALGAS_gtlData & constinArgument_vars,
                                                                         const GALGAS_library & constinArgument_lib,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  result_result = GALGAS_string ("[") ;
  GALGAS_gtlData var_keyValue_14910 = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 512)) ;
  if (var_keyValue_14910.isValid ()) {
    if (var_keyValue_14910.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_14981_keyString ((cPtr_gtlString *) var_keyValue_14910.ptr ()) ;
      result_result.plusAssign_operation(GALGAS_string ("\"").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) cast_14981_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 515)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 515)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 515)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 515)) ;
    }else if (var_keyValue_14910.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_15045_keyInt ((cPtr_gtlInt *) var_keyValue_14910.ptr ()) ;
      result_result.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlInt *) cast_15045_keyInt.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 517)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 517)) ;
    }
  }
  result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 519)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemSubCollection_stringPath (void) {
  enterExtensionGetter_stringPath (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                   extensionGetter_gtlVarItemSubCollection_stringPath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemSubCollection_stringPath (defineExtensionGetter_gtlVarItemSubCollection_stringPath, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@gtlVarItemSubCollection setInContext'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVarItemSubCollection_setInContext (const cPtr_gtlVarItem * inObject,
                                                                  GALGAS_gtlData & ioArgument_context,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  const GALGAS_library constinArgument_lib,
                                                                  const GALGAS_gtlVarPath constinArgument_path,
                                                                  const GALGAS_gtlData constinArgument_newData,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 532)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 532)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_15550_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 532)).ptr ()) ;
      ioArgument_context = function_wantGtlMap (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 534)) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 535)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        ioArgument_context.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_15634 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_15634, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_15550_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 536)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 536)) ;
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_15730 ;
        callExtensionMethod_mapItem ((const cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_15550_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 538)), var_subContext_15730, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 538)) ;
        callExtensionMethod_setInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 539)).ptr (), var_subContext_15730, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 543)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 539)) ;
        {
        ioArgument_context.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_15899 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_15899, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_15550_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 546)), var_subContext_15730, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 546)) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 532)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_15967_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 532)).ptr ()) ;
      ioArgument_context = function_wantGtlList (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 549)) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 550)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        ioArgument_context.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_16052 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_16052, constinArgument_newData, cast_15967_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 551)) ;
        }
      }else if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_16142 ;
        callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) ioArgument_context.ptr (), var_subContext_16142, cast_15967_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 553)) ;
        callExtensionMethod_setInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 554)).ptr (), var_subContext_16142, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 558)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 554)) ;
        {
        ioArgument_context.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_16319 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_16319, var_subContext_16142, cast_15967_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 561)) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 564)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 564)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVarItemSubCollection_setInContext (void) {
  enterExtensionMethod_setInContext (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                     extensionMethod_gtlVarItemSubCollection_setInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItemSubCollection_setInContext (defineExtensionMethod_gtlVarItemSubCollection_setInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension getter '@gtlVarItemSubCollection getInContext'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlVarItemSubCollection_getInContext (const cPtr_gtlVarItem * inObject,
                                                                            const GALGAS_gtlData & constinArgument_context,
                                                                            const GALGAS_gtlData & constinArgument_vars,
                                                                            const GALGAS_library & constinArgument_lib,
                                                                            const GALGAS_gtlVarPath & constinArgument_path,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 578)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 578)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_16867_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 578)).ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 580)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_0) {
        callExtensionMethod_mapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16867_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 581)), result_result, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 581)) ;
      }else if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_17006 ;
        callExtensionMethod_mapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16867_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 583)), var_subContext_17006, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 583)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 584)).ptr (), var_subContext_17006, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 588)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 584)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 578)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_17182_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 578)).ptr ()) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 592)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_1) {
        callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), result_result, cast_17182_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 593)) ;
      }else if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_17315 ;
        callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), var_subContext_17315, cast_17182_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 595)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 596)).ptr (), var_subContext_17315, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 600)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 596)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 604)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 604)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemSubCollection_getInContext (void) {
  enterExtensionGetter_getInContext (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                     extensionGetter_gtlVarItemSubCollection_getInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemSubCollection_getInContext (defineExtensionGetter_gtlVarItemSubCollection_getInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension getter '@gtlVarItemSubCollection existsInContext'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlVarItemSubCollection_existsInContext (const cPtr_gtlVarItem * inObject,
                                                                            const GALGAS_gtlData & constinArgument_context,
                                                                            const GALGAS_gtlData & constinArgument_vars,
                                                                            const GALGAS_library & constinArgument_lib,
                                                                            const GALGAS_gtlVarPath & constinArgument_path,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 618)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 618)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_18007_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 618)).ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 620)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_result = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_18007_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 621)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 621)) ;
      }else if (kBoolFalse == test_0) {
        const enumGalgasBool test_1 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_18007_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 623)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 623)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlData var_subContext_18198 ;
          callExtensionMethod_mapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_18007_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 624)), var_subContext_18198, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 624)) ;
          result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 625)).ptr (), var_subContext_18198, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 629)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 625)) ;
        }else if (kBoolFalse == test_1) {
          result_result = GALGAS_bool (false) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 618)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_18433_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 618)).ptr ()) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 636)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_result = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), cast_18433_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 637)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), cast_18433_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 639)).boolEnum () ;
        if (kBoolTrue == test_3) {
          GALGAS_gtlData var_subContext_18619 ;
          callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), var_subContext_18619, cast_18433_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 640)) ;
          result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 641)).ptr (), var_subContext_18619, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 645)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 641)) ;
        }else if (kBoolFalse == test_3) {
          result_result = GALGAS_bool (false) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 652)), GALGAS_string ("string ot int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 652)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemSubCollection_existsInContext (void) {
  enterExtensionGetter_existsInContext (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                        extensionGetter_gtlVarItemSubCollection_existsInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemSubCollection_existsInContext (defineExtensionGetter_gtlVarItemSubCollection_existsInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@gtlVarItemSubCollection deleteInContext'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlVarItemSubCollection_deleteInContext (const cPtr_gtlVarItem * inObject,
                                                                     GALGAS_gtlData & ioArgument_context,
                                                                     const GALGAS_gtlData constinArgument_vars,
                                                                     const GALGAS_library constinArgument_lib,
                                                                     const GALGAS_gtlVarPath constinArgument_path,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlVarItemSubCollection * object = (const cPtr_gtlVarItemSubCollection *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemSubCollection) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 665)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 665)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_19336_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 665)).ptr ()) ;
      const enumGalgasBool test_0 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19336_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 667)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 667)).boolEnum () ;
      if (kBoolTrue == test_0) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 668)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          ioArgument_context.insulate (HERE) ; // §ABSTRACT
          cPtr_gtlData * ptr_19433 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_deleteMapItem ((cPtr_gtlData *) ptr_19433, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19336_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 669)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 669)) ;
          }
        }else if (kBoolFalse == test_1) {
          GALGAS_gtlData var_subContext_19527 ;
          callExtensionMethod_mapItem ((const cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19336_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 671)), var_subContext_19527, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 671)) ;
          callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 672)).ptr (), var_subContext_19527, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 676)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 672)) ;
          {
          ioArgument_context.insulate (HERE) ; // §ABSTRACT
          cPtr_gtlData * ptr_19696 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_19696, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19336_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 678)), var_subContext_19527, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 678)) ;
          }
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 665)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_19774_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 665)).ptr ()) ;
      const enumGalgasBool test_2 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) ioArgument_context.ptr (), cast_19774_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 682)).boolEnum () ;
      if (kBoolTrue == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_path.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 683)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          ioArgument_context.insulate (HERE) ; // §ABSTRACT
          cPtr_gtlData * ptr_19872 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_deleteItemAtIndex ((cPtr_gtlData *) ptr_19872, cast_19774_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 684)) ;
          }
        }else if (kBoolFalse == test_3) {
          GALGAS_gtlData var_subContext_19960 ;
          callExtensionMethod_itemAtIndex ((const cPtr_gtlData *) ioArgument_context.ptr (), var_subContext_19960, cast_19774_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 686)) ;
          callExtensionMethod_deleteInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 687)).ptr (), var_subContext_19960, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 691)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 687)) ;
          {
          ioArgument_context.insulate (HERE) ; // §ABSTRACT
          cPtr_gtlData * ptr_20137 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_20137, var_subContext_19960, cast_19774_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 693)) ;
          }
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) object->mAttribute_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 697)), GALGAS_string ("string ot int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 697)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlVarItemSubCollection_deleteInContext (void) {
  enterExtensionMethod_deleteInContext (kTypeDescriptor_GALGAS_gtlVarItemSubCollection.mSlotID,
                                        extensionMethod_gtlVarItemSubCollection_deleteInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlVarItemSubCollection_deleteInContext (defineExtensionMethod_gtlVarItemSubCollection_deleteInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlTerminal eval'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlTerminal_eval (const cPtr_gtlExpression * inObject,
                                                        const GALGAS_gtlData & /* constinArgument_vars */,
                                                        const GALGAS_library & /* constinArgument_lib */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlTerminal * object = (const cPtr_gtlTerminal *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTerminal) ;
  result_result = object->mAttribute_value ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlTerminal_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlTerminal.mSlotID,
                             extensionGetter_gtlTerminal_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlTerminal_eval (defineExtensionGetter_gtlTerminal_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlVarRef eval'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlVarRef_eval (const cPtr_gtlExpression * inObject,
                                                      const GALGAS_gtlData & constinArgument_vars,
                                                      const GALGAS_library & constinArgument_lib,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlVarRef * object = (const cPtr_gtlVarRef *) inObject ;
  macroValidSharedObject (object, cPtr_gtlVarRef) ;
  result_result = extensionGetter_get (object->mAttribute_variableName, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 877)) ;
  {
  result_result.setter_setWhere (object->mAttribute_where COMMA_SOURCE_FILE ("gtl_expressions.galgas", 878)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarRef_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlVarRef.mSlotID,
                             extensionGetter_gtlVarRef_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarRef_eval (defineExtensionGetter_gtlVarRef_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlParenthesizedExpression eval'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlParenthesizedExpression_eval (const cPtr_gtlExpression * inObject,
                                                                       const GALGAS_gtlData & constinArgument_vars,
                                                                       const GALGAS_library & constinArgument_lib,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlParenthesizedExpression * object = (const cPtr_gtlParenthesizedExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlParenthesizedExpression) ;
  result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 893)) ;
  {
  result_result.setter_setWhere (object->mAttribute_where COMMA_SOURCE_FILE ("gtl_expressions.galgas", 894)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlParenthesizedExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlParenthesizedExpression.mSlotID,
                             extensionGetter_gtlParenthesizedExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlParenthesizedExpression_eval (defineExtensionGetter_gtlParenthesizedExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlMinusExpression eval'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlMinusExpression_eval (const cPtr_gtlExpression * inObject,
                                                               const GALGAS_gtlData & constinArgument_vars,
                                                               const GALGAS_library & constinArgument_lib,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlMinusExpression * object = (const cPtr_gtlMinusExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMinusExpression) ;
  result_result = callExtensionGetter_minusOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 907)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 907)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMinusExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlMinusExpression.mSlotID,
                             extensionGetter_gtlMinusExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMinusExpression_eval (defineExtensionGetter_gtlMinusExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlPlusExpression eval'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlPlusExpression_eval (const cPtr_gtlExpression * inObject,
                                                              const GALGAS_gtlData & constinArgument_vars,
                                                              const GALGAS_library & constinArgument_lib,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlPlusExpression * object = (const cPtr_gtlPlusExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlPlusExpression) ;
  result_result = callExtensionGetter_plusOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 920)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 920)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlPlusExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlPlusExpression.mSlotID,
                             extensionGetter_gtlPlusExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlPlusExpression_eval (defineExtensionGetter_gtlPlusExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlNotExpression eval'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlNotExpression_eval (const cPtr_gtlExpression * inObject,
                                                             const GALGAS_gtlData & constinArgument_vars,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlNotExpression * object = (const cPtr_gtlNotExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlNotExpression) ;
  result_result = callExtensionGetter_notOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_son.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 933)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 933)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlNotExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlNotExpression.mSlotID,
                             extensionGetter_gtlNotExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlNotExpression_eval (defineExtensionGetter_gtlNotExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlAddExpression eval'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlAddExpression_eval (const cPtr_gtlExpression * inObject,
                                                             const GALGAS_gtlData & constinArgument_vars,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlAddExpression * object = (const cPtr_gtlAddExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlAddExpression) ;
  result_result = callExtensionGetter_addOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 948)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 949)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 948)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlAddExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlAddExpression.mSlotID,
                             extensionGetter_gtlAddExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlAddExpression_eval (defineExtensionGetter_gtlAddExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlSubstractExpression eval'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlSubstractExpression_eval (const cPtr_gtlExpression * inObject,
                                                                   const GALGAS_gtlData & constinArgument_vars,
                                                                   const GALGAS_library & constinArgument_lib,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSubstractExpression * object = (const cPtr_gtlSubstractExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSubstractExpression) ;
  result_result = callExtensionGetter_subOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 962)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 963)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 962)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlSubstractExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlSubstractExpression.mSlotID,
                             extensionGetter_gtlSubstractExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlSubstractExpression_eval (defineExtensionGetter_gtlSubstractExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@gtlMultiplyExpression eval'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlMultiplyExpression_eval (const cPtr_gtlExpression * inObject,
                                                                  const GALGAS_gtlData & constinArgument_vars,
                                                                  const GALGAS_library & constinArgument_lib,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlMultiplyExpression * object = (const cPtr_gtlMultiplyExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMultiplyExpression) ;
  result_result = callExtensionGetter_mulOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 976)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 977)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 976)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMultiplyExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlMultiplyExpression.mSlotID,
                             extensionGetter_gtlMultiplyExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMultiplyExpression_eval (defineExtensionGetter_gtlMultiplyExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlDivideExpression eval'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlDivideExpression_eval (const cPtr_gtlExpression * inObject,
                                                                const GALGAS_gtlData & constinArgument_vars,
                                                                const GALGAS_library & constinArgument_lib,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlDivideExpression * object = (const cPtr_gtlDivideExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlDivideExpression) ;
  result_result = callExtensionGetter_divOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 990)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 991)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 990)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlDivideExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlDivideExpression.mSlotID,
                             extensionGetter_gtlDivideExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlDivideExpression_eval (defineExtensionGetter_gtlDivideExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@gtlModulusExpression eval'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlModulusExpression_eval (const cPtr_gtlExpression * inObject,
                                                                 const GALGAS_gtlData & constinArgument_vars,
                                                                 const GALGAS_library & constinArgument_lib,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlModulusExpression * object = (const cPtr_gtlModulusExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlModulusExpression) ;
  result_result = callExtensionGetter_modOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1004)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1005)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1004)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlModulusExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlModulusExpression.mSlotID,
                             extensionGetter_gtlModulusExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlModulusExpression_eval (defineExtensionGetter_gtlModulusExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlAndExpression eval'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlAndExpression_eval (const cPtr_gtlExpression * inObject,
                                                             const GALGAS_gtlData & constinArgument_vars,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlAndExpression * object = (const cPtr_gtlAndExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlAndExpression) ;
  result_result = callExtensionGetter_andOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1018)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1019)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1018)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlAndExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlAndExpression.mSlotID,
                             extensionGetter_gtlAndExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlAndExpression_eval (defineExtensionGetter_gtlAndExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlOrExpression eval'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlOrExpression_eval (const cPtr_gtlExpression * inObject,
                                                            const GALGAS_gtlData & constinArgument_vars,
                                                            const GALGAS_library & constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlOrExpression * object = (const cPtr_gtlOrExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlOrExpression) ;
  result_result = callExtensionGetter_orOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1032)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1033)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1032)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlOrExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlOrExpression.mSlotID,
                             extensionGetter_gtlOrExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlOrExpression_eval (defineExtensionGetter_gtlOrExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlXorExpression eval'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlXorExpression_eval (const cPtr_gtlExpression * inObject,
                                                             const GALGAS_gtlData & constinArgument_vars,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlXorExpression * object = (const cPtr_gtlXorExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlXorExpression) ;
  result_result = callExtensionGetter_xorOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1046)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1047)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1046)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlXorExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlXorExpression.mSlotID,
                             extensionGetter_gtlXorExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlXorExpression_eval (defineExtensionGetter_gtlXorExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlShiftLeftExpression eval'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlShiftLeftExpression_eval (const cPtr_gtlExpression * inObject,
                                                                   const GALGAS_gtlData & constinArgument_vars,
                                                                   const GALGAS_library & constinArgument_lib,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlShiftLeftExpression * object = (const cPtr_gtlShiftLeftExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlShiftLeftExpression) ;
  result_result = callExtensionGetter_slOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1060)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1061)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1060)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlShiftLeftExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlShiftLeftExpression.mSlotID,
                             extensionGetter_gtlShiftLeftExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlShiftLeftExpression_eval (defineExtensionGetter_gtlShiftLeftExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlShiftRightExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlShiftRightExpression_eval (const cPtr_gtlExpression * inObject,
                                                                    const GALGAS_gtlData & constinArgument_vars,
                                                                    const GALGAS_library & constinArgument_lib,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlShiftRightExpression * object = (const cPtr_gtlShiftRightExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlShiftRightExpression) ;
  result_result = callExtensionGetter_srOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1074)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1075)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1074)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlShiftRightExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlShiftRightExpression.mSlotID,
                             extensionGetter_gtlShiftRightExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlShiftRightExpression_eval (defineExtensionGetter_gtlShiftRightExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@gtlNotEqualExpression eval'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlNotEqualExpression_eval (const cPtr_gtlExpression * inObject,
                                                                  const GALGAS_gtlData & constinArgument_vars,
                                                                  const GALGAS_library & constinArgument_lib,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlNotEqualExpression * object = (const cPtr_gtlNotEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlNotEqualExpression) ;
  result_result = callExtensionGetter_neqOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1088)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1089)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1088)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlNotEqualExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlNotEqualExpression.mSlotID,
                             extensionGetter_gtlNotEqualExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlNotEqualExpression_eval (defineExtensionGetter_gtlNotEqualExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlEqualExpression eval'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEqualExpression_eval (const cPtr_gtlExpression * inObject,
                                                               const GALGAS_gtlData & constinArgument_vars,
                                                               const GALGAS_library & constinArgument_lib,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEqualExpression * object = (const cPtr_gtlEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEqualExpression) ;
  result_result = callExtensionGetter_eqOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1102)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1103)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1102)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEqualExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlEqualExpression.mSlotID,
                             extensionGetter_gtlEqualExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEqualExpression_eval (defineExtensionGetter_gtlEqualExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlLowerThanExpression eval'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlLowerThanExpression_eval (const cPtr_gtlExpression * inObject,
                                                                   const GALGAS_gtlData & constinArgument_vars,
                                                                   const GALGAS_library & constinArgument_lib,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlLowerThanExpression * object = (const cPtr_gtlLowerThanExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLowerThanExpression) ;
  result_result = callExtensionGetter_ltOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1116)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1117)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1116)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLowerThanExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlLowerThanExpression.mSlotID,
                             extensionGetter_gtlLowerThanExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLowerThanExpression_eval (defineExtensionGetter_gtlLowerThanExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlLowerOrEqualExpression eval'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlLowerOrEqualExpression_eval (const cPtr_gtlExpression * inObject,
                                                                      const GALGAS_gtlData & constinArgument_vars,
                                                                      const GALGAS_library & constinArgument_lib,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlLowerOrEqualExpression * object = (const cPtr_gtlLowerOrEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLowerOrEqualExpression) ;
  result_result = callExtensionGetter_leOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1130)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1131)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1130)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLowerOrEqualExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression.mSlotID,
                             extensionGetter_gtlLowerOrEqualExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLowerOrEqualExpression_eval (defineExtensionGetter_gtlLowerOrEqualExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlGreaterThanExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlGreaterThanExpression_eval (const cPtr_gtlExpression * inObject,
                                                                     const GALGAS_gtlData & constinArgument_vars,
                                                                     const GALGAS_library & constinArgument_lib,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlGreaterThanExpression * object = (const cPtr_gtlGreaterThanExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGreaterThanExpression) ;
  result_result = callExtensionGetter_gtOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1144)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1145)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1144)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGreaterThanExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlGreaterThanExpression.mSlotID,
                             extensionGetter_gtlGreaterThanExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGreaterThanExpression_eval (defineExtensionGetter_gtlGreaterThanExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlGreaterOrEqualExpression eval'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlGreaterOrEqualExpression_eval (const cPtr_gtlExpression * inObject,
                                                                        const GALGAS_gtlData & constinArgument_vars,
                                                                        const GALGAS_library & constinArgument_lib,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlGreaterOrEqualExpression * object = (const cPtr_gtlGreaterOrEqualExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGreaterOrEqualExpression) ;
  result_result = callExtensionGetter_geOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_lSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1158)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_rSon.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1159)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1158)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGreaterOrEqualExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression.mSlotID,
                             extensionGetter_gtlGreaterOrEqualExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGreaterOrEqualExpression_eval (defineExtensionGetter_gtlGreaterOrEqualExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlGetterCallExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlGetterCallExpression_eval (const cPtr_gtlExpression * inObject,
                                                                    const GALGAS_gtlData & constinArgument_vars,
                                                                    const GALGAS_library & constinArgument_lib,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlGetterCallExpression * object = (const cPtr_gtlGetterCallExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlGetterCallExpression) ;
  GALGAS_gtlDataList var_dataArguments_35472 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1176)) ;
  cEnumerator_gtlExpressionList enumerator_35507 (object->mAttribute_arguments, kEnumeration_up) ;
  while (enumerator_35507.hasCurrentObject ()) {
    var_dataArguments_35472.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_35507.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1178))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1178)) ;
    enumerator_35507.gotoNextObject () ;
  }
  GALGAS_gtlData var_targetData_35589 = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_target.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1180)) ;
  result_result = callExtensionGetter_performGetter ((const cPtr_gtlData *) var_targetData_35589.ptr (), object->mAttribute_getterName, var_dataArguments_35472, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1181)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGetterCallExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlGetterCallExpression.mSlotID,
                             extensionGetter_gtlGetterCallExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGetterCallExpression_eval (defineExtensionGetter_gtlGetterCallExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlFunctionCallExpression eval'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFunctionCallExpression_eval (const cPtr_gtlExpression * inObject,
                                                                      const GALGAS_gtlData & constinArgument_vars,
                                                                      const GALGAS_library & constinArgument_lib,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFunctionCallExpression * object = (const cPtr_gtlFunctionCallExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFunctionCallExpression) ;
  GALGAS_uint var_currentErrorCount_37421 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_expressions.galgas", 1234)) ;
  const enumGalgasBool test_0 = GALGAS_function::constructor_isFunctionDefined (object->mAttribute_functionName.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1236))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1236)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_objectlist var_arguments_37558 = GALGAS_objectlist::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1238)) ;
    GALGAS_gtlDataList var_dataArguments_37602 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1239)) ;
    cEnumerator_gtlExpressionList enumerator_37648 (object->mAttribute_functionArguments, kEnumeration_up) ;
    while (enumerator_37648.hasCurrentObject ()) {
      GALGAS_gtlData var_arg_37670 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_37648.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1242)) ;
      var_dataArguments_37602.addAssign_operation (var_arg_37670  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1243)) ;
      callExtensionMethod_addMyValue ((const cPtr_gtlData *) var_arg_37670.ptr (), var_arguments_37558, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1244)) ;
      enumerator_37648.gotoNextObject () ;
    }
    GALGAS_function var_function_37800 = GALGAS_function::constructor_functionWithName (object->mAttribute_functionName.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1247))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1247)) ;
    GALGAS_typelist var_formalParameterList_37886 = var_function_37800.getter_formalParameterTypeList (SOURCE_FILE ("gtl_expressions.galgas", 1249)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_formalParameterList_37886.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1250)).objectCompare (var_arguments_37558.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1250)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string temp_2 ;
      const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, var_arguments_37558.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1253)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
      if (kBoolTrue == test_3) {
        temp_2 = GALGAS_string ("s") ;
      }else if (kBoolFalse == test_3) {
        temp_2 = GALGAS_string::makeEmptyString () ;
      }
      GALGAS_string temp_4 ;
      const enumGalgasBool test_5 = GALGAS_bool (kIsStrictSup, var_formalParameterList_37886.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1255)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
      if (kBoolTrue == test_5) {
        temp_4 = GALGAS_string ("s") ;
      }else if (kBoolFalse == test_5) {
        temp_4 = GALGAS_string::makeEmptyString () ;
      }
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (object->mAttribute_functionName.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1251)), GALGAS_string ("this function is invoked with ").add_operation (var_arguments_37558.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1252)).getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1251)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1251)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1252)).add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1252)).add_operation (GALGAS_string (", but requires "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1253)).add_operation (var_formalParameterList_37886.getter_length (SOURCE_FILE ("gtl_expressions.galgas", 1254)).getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1254)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1254)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1254)).add_operation (temp_4, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1254)), fixItArray6  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1251)) ;
      result_result.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_1) {
      cEnumerator_typelist enumerator_38353 (var_formalParameterList_37886, kEnumeration_up) ;
      cEnumerator_gtlDataList enumerator_38380 (var_dataArguments_37602, kEnumeration_up) ;
      GALGAS_uint index_38321 ((uint32_t) 0) ;
      while (enumerator_38353.hasCurrentObject () && enumerator_38380.hasCurrentObject ()) {
        {
        routine_checkArgumentError (object->mAttribute_functionName, enumerator_38353.current_mValue (HERE), enumerator_38380.current_data (HERE), index_38321, inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1259)) ;
        }
        enumerator_38353.gotoNextObject () ;
        enumerator_38380.gotoNextObject () ;
        index_38321.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1258)) ;
      }
      const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_currentErrorCount_37421.objectCompare (GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_expressions.galgas", 1261)))).boolEnum () ;
      if (kBoolTrue == test_7) {
        GALGAS_object var_returnedValue_38552 = var_function_37800.getter_invoke (var_arguments_37558, object->mAttribute_functionName.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1263)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1263)) ;
        result_result = function_validateReturnValue (object->mAttribute_functionName, var_returnedValue_38552, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1264)) ;
      }else if (kBoolFalse == test_7) {
        result_result = GALGAS_gtlUnconstructed::constructor_new (object->mAttribute_functionName.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1267)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1268))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1266)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    GALGAS_gtlFunction var_function_38860 = callExtensionGetter_getFunction ((const cPtr_library *) constinArgument_lib.ptr (), object->mAttribute_functionName, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1273)) ;
    GALGAS_gtlDataList var_arguments_38921 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1274)) ;
    cEnumerator_gtlExpressionList enumerator_38966 (object->mAttribute_functionArguments, kEnumeration_up) ;
    while (enumerator_38966.hasCurrentObject ()) {
      var_arguments_38921.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_38966.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1276))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1276)) ;
      enumerator_38966.gotoNextObject () ;
    }
    result_result = callExtensionGetter_call ((const cPtr_gtlFunction *) var_function_38860.ptr (), object->mAttribute_functionName.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1278)), constinArgument_lib, var_arguments_38921, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1278)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFunctionCallExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlFunctionCallExpression.mSlotID,
                             extensionGetter_gtlFunctionCallExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFunctionCallExpression_eval (defineExtensionGetter_gtlFunctionCallExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlExistsExpression eval'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlExistsExpression_eval (const cPtr_gtlExpression * inObject,
                                                                const GALGAS_gtlData & constinArgument_vars,
                                                                const GALGAS_library & constinArgument_lib,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlExistsExpression * object = (const cPtr_gtlExistsExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlExistsExpression) ;
  result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295)), extensionGetter_exists (object->mAttribute_variable, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1294)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlExistsExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlExistsExpression.mSlotID,
                             extensionGetter_gtlExistsExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExistsExpression_eval (defineExtensionGetter_gtlExistsExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlExistsDefaultExpression eval'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlExistsDefaultExpression_eval (const cPtr_gtlExpression * inObject,
                                                                       const GALGAS_gtlData & constinArgument_vars,
                                                                       const GALGAS_library & constinArgument_lib,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlExistsDefaultExpression * object = (const cPtr_gtlExistsDefaultExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlExistsDefaultExpression) ;
  const enumGalgasBool test_0 = extensionGetter_exists (object->mAttribute_variable, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1312)).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = extensionGetter_get (object->mAttribute_variable, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1313)) ;
  }else if (kBoolFalse == test_0) {
    result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_defaultValue.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1315)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlExistsDefaultExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlExistsDefaultExpression.mSlotID,
                             extensionGetter_gtlExistsDefaultExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExistsDefaultExpression_eval (defineExtensionGetter_gtlExistsDefaultExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlTypeOfExpression eval'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlTypeOfExpression_eval (const cPtr_gtlExpression * inObject,
                                                                const GALGAS_gtlData & constinArgument_vars,
                                                                const GALGAS_library & constinArgument_lib,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlTypeOfExpression * object = (const cPtr_gtlTypeOfExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlTypeOfExpression) ;
  GALGAS_gtlData var_variableValue_40670 = extensionGetter_get (object->mAttribute_variable, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1331)) ;
  result_result = GALGAS_gtlType::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1332)), var_variableValue_40670.getter_dynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1332))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1332)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlTypeOfExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlTypeOfExpression.mSlotID,
                             extensionGetter_gtlTypeOfExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlTypeOfExpression_eval (defineExtensionGetter_gtlTypeOfExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlMapOfStructExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlMapOfStructExpression_eval (const cPtr_gtlExpression * inObject,
                                                                     const GALGAS_gtlData & constinArgument_vars,
                                                                     const GALGAS_library & constinArgument_lib,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlMapOfStructExpression * object = (const cPtr_gtlMapOfStructExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMapOfStructExpression) ;
  GALGAS_gtlData var_expressionValue_41222 = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_expression.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1347)) ;
  if (var_expressionValue_41222.isValid ()) {
    if (var_expressionValue_41222.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_41319_expressionValueStruct ((cPtr_gtlStruct *) var_expressionValue_41222.ptr ()) ;
      result_result = GALGAS_gtlMap::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1352)), cast_41319_expressionValueStruct.getter_value (SOURCE_FILE ("gtl_expressions.galgas", 1353))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1350)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("struct expected"), fixItArray0  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1356)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMapOfStructExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlMapOfStructExpression.mSlotID,
                             extensionGetter_gtlMapOfStructExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMapOfStructExpression_eval (defineExtensionGetter_gtlMapOfStructExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlMapOfListExpression eval'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlMapOfListExpression_eval (const cPtr_gtlExpression * inObject,
                                                                   const GALGAS_gtlData & constinArgument_vars,
                                                                   const GALGAS_library & constinArgument_lib,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlMapOfListExpression * object = (const cPtr_gtlMapOfListExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMapOfListExpression) ;
  GALGAS_gtlData var_expressionValue_41928 = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_expression.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1372)) ;
  if (var_expressionValue_41928.isValid ()) {
    if (var_expressionValue_41928.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_42021_expressionValueList ((cPtr_gtlList *) var_expressionValue_41928.ptr ()) ;
      GALGAS_gtlVarMap var_resultMap_42047 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1375)) ;
      cEnumerator_list enumerator_42105 (cast_42021_expressionValueList.getter_value (SOURCE_FILE ("gtl_expressions.galgas", 1376)), kEnumeration_up) ;
      GALGAS_uint index_42067 ((uint32_t) 0) ;
      while (enumerator_42105.hasCurrentObject ()) {
        if (enumerator_42105.current_value (HERE).isValid ()) {
          if (enumerator_42105.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
            GALGAS_gtlStruct cast_42168_itemStruct ((cPtr_gtlStruct *) enumerator_42105.current_value (HERE).ptr ()) ;
            const enumGalgasBool test_0 = cast_42168_itemStruct.getter_value (SOURCE_FILE ("gtl_expressions.galgas", 1379)).getter_hasKey (object->mAttribute_key.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1379)) COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1379)).boolEnum () ;
            if (kBoolTrue == test_0) {
              GALGAS_gtlData var_keyValue_42285 ;
              cast_42168_itemStruct.getter_value (SOURCE_FILE ("gtl_expressions.galgas", 1380)).method_get (object->mAttribute_key, var_keyValue_42285, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1380)) ;
              {
              var_resultMap_42047.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_42285.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1382)), enumerator_42105.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1381)) ;
              }
            }else if (kBoolFalse == test_0) {
              TC_Array <C_FixItDescription> fixItArray1 ;
              inCompiler->emitSemanticError (var_expressionValue_41928.getter_where (SOURCE_FILE ("gtl_expressions.galgas", 1386)), GALGAS_string ("item at index ").add_operation (index_42067.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1386)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386)).add_operation (object->mAttribute_key.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1387)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1387)), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386)) ;
            }
          }else{
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (var_expressionValue_41928.getter_where (SOURCE_FILE ("gtl_expressions.galgas", 1390)), GALGAS_string ("list of struct expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1390)) ;
          }
        }
        enumerator_42105.gotoNextObject () ;
        index_42067.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1376)) ;
      }
      result_result = GALGAS_gtlMap::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1393)), var_resultMap_42047  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1393)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (var_expressionValue_41928.getter_where (SOURCE_FILE ("gtl_expressions.galgas", 1395)), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1395)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlMapOfListExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlMapOfListExpression.mSlotID,
                             extensionGetter_gtlMapOfListExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlMapOfListExpression_eval (defineExtensionGetter_gtlMapOfListExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlListOfExpression eval'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlListOfExpression_eval (const cPtr_gtlExpression * inObject,
                                                                const GALGAS_gtlData & constinArgument_vars,
                                                                const GALGAS_library & constinArgument_lib,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlListOfExpression * object = (const cPtr_gtlListOfExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlListOfExpression) ;
  GALGAS_gtlData var_expressionValue_43173 = callExtensionGetter_eval ((const cPtr_gtlExpression *) object->mAttribute_expression.ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1411)) ;
  if (var_expressionValue_43173.isValid ()) {
    if (var_expressionValue_43173.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_43264_expressionValueMap ((cPtr_gtlMap *) var_expressionValue_43173.ptr ()) ;
      GALGAS_list var_resultList_43286 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1414)) ;
      cEnumerator_gtlVarMap enumerator_43348 (cast_43264_expressionValueMap.getter_value (SOURCE_FILE ("gtl_expressions.galgas", 1415)), kEnumeration_up) ;
      while (enumerator_43348.hasCurrentObject ()) {
        var_resultList_43286.addAssign_operation (enumerator_43348.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1416)) ;
        enumerator_43348.gotoNextObject () ;
      }
      result_result = GALGAS_gtlList::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1418)), var_resultList_43286  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1418)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("map expected"), fixItArray0  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1420)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlListOfExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlListOfExpression.mSlotID,
                             extensionGetter_gtlListOfExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlListOfExpression_eval (defineExtensionGetter_gtlListOfExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@gtlLiteralStructExpression eval'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlLiteralStructExpression_eval (const cPtr_gtlExpression * inObject,
                                                                       const GALGAS_gtlData & constinArgument_vars,
                                                                       const GALGAS_library & constinArgument_lib,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlLiteralStructExpression * object = (const cPtr_gtlLiteralStructExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralStructExpression) ;
  GALGAS_gtlVarMap var_resultStruct_43921 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1436)) ;
  cEnumerator_gtlExpressionMap enumerator_43959 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_43959.hasCurrentObject ()) {
    {
    var_resultStruct_43921.setter_put (enumerator_43959.current_lkey (HERE), callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_43959.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1438)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1438)) ;
    }
    enumerator_43959.gotoNextObject () ;
  }
  result_result = GALGAS_gtlStruct::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1440)), var_resultStruct_43921  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1440)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralStructExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlLiteralStructExpression.mSlotID,
                             extensionGetter_gtlLiteralStructExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralStructExpression_eval (defineExtensionGetter_gtlLiteralStructExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlLiteralMapExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlLiteralMapExpression_eval (const cPtr_gtlExpression * inObject,
                                                                    const GALGAS_gtlData & constinArgument_vars,
                                                                    const GALGAS_library & constinArgument_lib,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlLiteralMapExpression * object = (const cPtr_gtlLiteralMapExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralMapExpression) ;
  GALGAS_gtlVarMap var_resultStruct_44496 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1455)) ;
  cEnumerator_gtlExpressionMap enumerator_44534 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_44534.hasCurrentObject ()) {
    {
    var_resultStruct_44496.setter_put (enumerator_44534.current_lkey (HERE), callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_44534.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1457)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1457)) ;
    }
    enumerator_44534.gotoNextObject () ;
  }
  result_result = GALGAS_gtlMap::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1459)), var_resultStruct_44496  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1459)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralMapExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlLiteralMapExpression.mSlotID,
                             extensionGetter_gtlLiteralMapExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralMapExpression_eval (defineExtensionGetter_gtlLiteralMapExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlLiteralListExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlLiteralListExpression_eval (const cPtr_gtlExpression * inObject,
                                                                     const GALGAS_gtlData & constinArgument_vars,
                                                                     const GALGAS_library & constinArgument_lib,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlLiteralListExpression * object = (const cPtr_gtlLiteralListExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralListExpression) ;
  GALGAS_list var_resultList_45065 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1474)) ;
  cEnumerator_gtlExpressionList enumerator_45100 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_45100.hasCurrentObject ()) {
    var_resultList_45065.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_45100.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1476))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1476)) ;
    enumerator_45100.gotoNextObject () ;
  }
  result_result = GALGAS_gtlList::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1478)), var_resultList_45065  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1478)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralListExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlLiteralListExpression.mSlotID,
                             extensionGetter_gtlLiteralListExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralListExpression_eval (defineExtensionGetter_gtlLiteralListExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@gtlLiteralSetExpression eval'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlLiteralSetExpression_eval (const cPtr_gtlExpression * inObject,
                                                                    const GALGAS_gtlData & constinArgument_vars,
                                                                    const GALGAS_library & constinArgument_lib,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlLiteralSetExpression * object = (const cPtr_gtlLiteralSetExpression *) inObject ;
  macroValidSharedObject (object, cPtr_gtlLiteralSetExpression) ;
  GALGAS_stringset var_resultSet_45619 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("gtl_expressions.galgas", 1493)) ;
  cEnumerator_gtlExpressionList enumerator_45653 (object->mAttribute_value, kEnumeration_up) ;
  while (enumerator_45653.hasCurrentObject ()) {
    var_resultSet_45619.addAssign_operation (callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_45653.current_expression (HERE).ptr (), constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1495)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1495))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1495)) ;
    enumerator_45653.gotoNextObject () ;
  }
  result_result = GALGAS_gtlSet::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1497)), var_resultSet_45619  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1497)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlLiteralSetExpression_eval (void) {
  enterExtensionGetter_eval (kTypeDescriptor_GALGAS_gtlLiteralSetExpression.mSlotID,
                             extensionGetter_gtlLiteralSetExpression_eval) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlLiteralSetExpression_eval (defineExtensionGetter_gtlLiteralSetExpression_eval, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed desc'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlUnconstructed_desc (const cPtr_gtlData * /* inObject */,
                                                            const GALGAS_uint & constinArgument_tab,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 359)).add_operation (GALGAS_string ("unconstructed\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 359)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_desc) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_desc (defineExtensionGetter_gtlUnconstructed_desc, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlUnconstructed string'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlUnconstructed_string (const cPtr_gtlData * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an unconstructed to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 364)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                               extensionGetter_gtlUnconstructed_string) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_string (defineExtensionGetter_gtlUnconstructed_string, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlUnconstructed lstring'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlUnconstructed_lstring (const cPtr_gtlData * inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an unconstructed to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 368)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                extensionGetter_gtlUnconstructed_lstring) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_lstring (defineExtensionGetter_gtlUnconstructed_lstring, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed bool'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlUnconstructed_bool (const cPtr_gtlData * inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an unconstructed to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 372)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_bool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_bool (defineExtensionGetter_gtlUnconstructed_bool, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlUnconstructed int'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bigint extensionGetter_gtlUnconstructed_int (const cPtr_gtlData * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an unconstructed to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 376)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                            extensionGetter_gtlUnconstructed_int) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_int (defineExtensionGetter_gtlUnconstructed_int, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed float'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_double extensionGetter_gtlUnconstructed_float (const cPtr_gtlData * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an unconstructed to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 380)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_float) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_float (defineExtensionGetter_gtlUnconstructed_float, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlUnconstructed plusOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_plusOp (const cPtr_gtlData * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 384)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                               extensionGetter_gtlUnconstructed_plusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_plusOp (defineExtensionGetter_gtlUnconstructed_plusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension getter '@gtlUnconstructed minusOp'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_minusOp (const cPtr_gtlData * inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 387)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                extensionGetter_gtlUnconstructed_minusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_minusOp (defineExtensionGetter_gtlUnconstructed_minusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed notOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_notOp (const cPtr_gtlData * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 390)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_notOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_notOp (defineExtensionGetter_gtlUnconstructed_notOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed addOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_addOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 393)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_addOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_addOp (defineExtensionGetter_gtlUnconstructed_addOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed subOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_subOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 396)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_subOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_subOp (defineExtensionGetter_gtlUnconstructed_subOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed mulOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_mulOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 399)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_mulOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_mulOp (defineExtensionGetter_gtlUnconstructed_mulOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed divOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_divOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 402)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_divOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_divOp (defineExtensionGetter_gtlUnconstructed_divOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed modOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_modOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 405)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_modOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_modOp (defineExtensionGetter_gtlUnconstructed_modOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed andOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_andOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 408)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_andOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_andOp (defineExtensionGetter_gtlUnconstructed_andOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed orOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_orOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 411)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_orOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_orOp (defineExtensionGetter_gtlUnconstructed_orOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed xorOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_xorOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 414)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_xorOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_xorOp (defineExtensionGetter_gtlUnconstructed_xorOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed slOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_slOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 417)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_slOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_slOp (defineExtensionGetter_gtlUnconstructed_slOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed srOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_srOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 420)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_srOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_srOp (defineExtensionGetter_gtlUnconstructed_srOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed neqOp'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_neqOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData & /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 423)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_neqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_neqOp (defineExtensionGetter_gtlUnconstructed_neqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed eqOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_eqOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 426)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_eqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_eqOp (defineExtensionGetter_gtlUnconstructed_eqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed gtOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_gtOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 429)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_gtOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_gtOp (defineExtensionGetter_gtlUnconstructed_gtOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed geOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_geOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 432)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_geOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_geOp (defineExtensionGetter_gtlUnconstructed_geOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed ltOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_ltOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 435)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_ltOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_ltOp (defineExtensionGetter_gtlUnconstructed_ltOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed leOp'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_leOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData & /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 438)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_leOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_leOp (defineExtensionGetter_gtlUnconstructed_leOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlUnconstructed embeddedType'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_type extensionGetter_gtlUnconstructed_embeddedType (const cPtr_gtlData * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("unconstructed data provided as argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 443)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                     extensionGetter_gtlUnconstructed_embeddedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_embeddedType (defineExtensionGetter_gtlUnconstructed_embeddedType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@gtlUnconstructed addMyValue'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlUnconstructed_addMyValue (const cPtr_gtlData * inObject,
                                                         GALGAS_objectlist & /* ioArgument_objectList */,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("Attempting to pass an unconstructed data to a function"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 448)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlUnconstructed_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                   extensionMethod_gtlUnconstructed_addMyValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlUnconstructed_addMyValue (defineExtensionMethod_gtlUnconstructed_addMyValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@gtlUnconstructed performGetter'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_performGetter (const cPtr_gtlData * inObject,
                                                                      const GALGAS_lstring & constinArgument_methodName,
                                                                      const GALGAS_gtlDataList & constinArgument_arguments,
                                                                      const GALGAS_library & constinArgument_lib,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 460)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 461)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 461)) ;
    }
    const GALGAS_gtlUnconstructed temp_1 = object ;
    result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 463)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 463)), temp_1.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 463))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 462)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 465)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 466)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 466)) ;
      }
      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 468)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 468)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 467)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 470)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 471)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 471)) ;
        }
        result_result = GALGAS_gtlString::constructor_new (object->mAttribute_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 473)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 473)), object->mAttribute_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 473))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 472)) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 475)).boolEnum () ;
        if (kBoolTrue == test_4) {
          const GALGAS_gtlUnconstructed temp_5 = object ;
          result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 476)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 477)), constinArgument_lib, temp_5, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 476)) ;
        }else if (kBoolFalse == test_4) {
          TC_Array <C_FixItDescription> fixItArray6 ;
          inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 483)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 483)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 483)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 483)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 483)) ;
          result_result.drop () ; // Release error dropped variable
        }
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlUnconstructed_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                      extensionGetter_gtlUnconstructed_performGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlUnconstructed_performGetter (defineExtensionGetter_gtlUnconstructed_performGetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension setter '@gtlUnconstructed performSetter'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlUnconstructed_performSetter (cPtr_gtlData * inObject,
                                                            const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlUnconstructed * object = (cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 495)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 496)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 496)) ;
    }
    GALGAS_gtlString temp_1 ;
    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)).ptr ())) {
        temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)).ptr () ;
      }else{
        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)) ;
      }
    }
    GALGAS_gtlString var_descriptionToSet_15591 = temp_1 ;
    {
    object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_15591.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 498)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 498)) ;
    }
    object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 499)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 500)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 501)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 501)) ;
      }
      object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 502)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 503)).boolEnum () ;
      if (kBoolTrue == test_3) {
        const GALGAS_gtlUnconstructed temp_4 = object ;
        GALGAS_gtlData var_copy_15896 = temp_4 ;
        callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 505)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 506)), constinArgument_lib, var_copy_15896, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 505)) ;
        object->mAttribute_where = var_copy_15896.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 511)) ;
        object->mAttribute_meta = var_copy_15896.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 512)) ;
      }else if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 514)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 514)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 514)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 514)), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 514)) ;
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlUnconstructed_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                      extensionSetter_gtlUnconstructed_performSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlUnconstructed_performSetter (defineExtensionSetter_gtlUnconstructed_performSetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType desc'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlType_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint & constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 528)).add_operation (GALGAS_string ("type: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 528)).add_operation (extensionGetter_typeName (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 529)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 529)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 529)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_desc) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_desc (defineExtensionGetter_gtlType_desc, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType string'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlType_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  result_result = extensionGetter_typeName (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 532)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                               extensionGetter_gtlType_string) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_string (defineExtensionGetter_gtlType_string, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlType lstring'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlType_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 535)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 535)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                extensionGetter_gtlType_lstring) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_lstring (defineExtensionGetter_gtlType_lstring, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType bool'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlType_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast a type to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 539)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_bool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_bool (defineExtensionGetter_gtlType_bool, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType int'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bigint extensionGetter_gtlType_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast a type to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 543)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                            extensionGetter_gtlType_int) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_int (defineExtensionGetter_gtlType_int, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType float'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_double extensionGetter_gtlType_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast a type to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 547)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_float) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_float (defineExtensionGetter_gtlType_float, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType plusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 551)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                               extensionGetter_gtlType_plusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_plusOp (defineExtensionGetter_gtlType_plusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlType minusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 554)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                extensionGetter_gtlType_minusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_minusOp (defineExtensionGetter_gtlType_minusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType notOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 557)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_notOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_notOp (defineExtensionGetter_gtlType_notOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType addOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 560)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_addOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_addOp (defineExtensionGetter_gtlType_addOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType subOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 563)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_subOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_subOp (defineExtensionGetter_gtlType_subOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType mulOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 566)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_mulOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_mulOp (defineExtensionGetter_gtlType_mulOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType divOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 569)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_divOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_divOp (defineExtensionGetter_gtlType_divOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType modOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 572)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_modOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_modOp (defineExtensionGetter_gtlType_modOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType andOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 575)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_andOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_andOp (defineExtensionGetter_gtlType_andOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType orOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 578)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_orOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_orOp (defineExtensionGetter_gtlType_orOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType xorOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 581)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_xorOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_xorOp (defineExtensionGetter_gtlType_xorOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType slOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 584)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_slOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_slOp (defineExtensionGetter_gtlType_slOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType srOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 587)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_srOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_srOp (defineExtensionGetter_gtlType_srOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType neqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlType temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 591)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 591)), GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (temp_1.getter_type (SOURCE_FILE ("gtl_data_types.galgas", 591))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 591)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 593)), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 593)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_neqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_neqOp (defineExtensionGetter_gtlType_neqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType eqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlType temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 598)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 598)), GALGAS_bool (kIsEqual, object->mAttribute_type.objectCompare (temp_1.getter_type (SOURCE_FILE ("gtl_data_types.galgas", 598))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 598)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 600)), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 600)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_eqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_eqOp (defineExtensionGetter_gtlType_eqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType gtOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 604)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_gtOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_gtOp (defineExtensionGetter_gtlType_gtOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType geOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 607)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_geOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_geOp (defineExtensionGetter_gtlType_geOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType ltOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 610)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_ltOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_ltOp (defineExtensionGetter_gtlType_ltOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType leOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 613)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_leOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_leOp (defineExtensionGetter_gtlType_leOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlType embeddedType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_type extensionGetter_gtlType_embeddedType (const cPtr_gtlData * /* inObject */,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_type) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                     extensionGetter_gtlType_embeddedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_embeddedType (defineExtensionGetter_gtlType_embeddedType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@gtlType addMyValue'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlType_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & ioArgument_objectList,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  ioArgument_objectList.addAssign_operation (object->mAttribute_type.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 623))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 623)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlType_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                   extensionMethod_gtlType_addMyValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlType_addMyValue (defineExtensionMethod_gtlType_addMyValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlType performGetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlType_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring & constinArgument_methodName,
                                                             const GALGAS_gtlDataList & constinArgument_arguments,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 635)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 636)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 636)) ;
    }
    const GALGAS_gtlType temp_1 = object ;
    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 638)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 638)), callExtensionGetter_string ((const cPtr_gtlType *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 638))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 637)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 640)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 641)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 641)) ;
      }
      const GALGAS_gtlType temp_3 = object ;
      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 643)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 643)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 643))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 642)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 645)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 646)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 646)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 648)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 648)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 647)) ;
      }else if (kBoolFalse == test_4) {
        const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 650)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 651)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 651)) ;
          }
          result_result = GALGAS_gtlString::constructor_new (object->mAttribute_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 653)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 653)), object->mAttribute_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 653))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 652)) ;
        }else if (kBoolFalse == test_5) {
          const enumGalgasBool test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 655)).boolEnum () ;
          if (kBoolTrue == test_6) {
            const GALGAS_gtlType temp_7 = object ;
            result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 656)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 657)), constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 656)) ;
          }else if (kBoolFalse == test_6) {
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 663)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 663)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 663)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 663)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 663)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlType_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                      extensionGetter_gtlType_performGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlType_performGetter (defineExtensionGetter_gtlType_performGetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension setter '@gtlType performSetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlType_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlType * object = (cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 675)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 676)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 676)) ;
    }
    GALGAS_gtlString temp_1 ;
    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 677)).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 677)).ptr ())) {
        temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 677)).ptr () ;
      }else{
        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 677)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 677)) ;
      }
    }
    GALGAS_gtlString var_descriptionToSet_21675 = temp_1 ;
    {
    object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_21675.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 678)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 678)) ;
    }
    object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 679)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 680)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 681)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 681)) ;
      }
      object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 682)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 683)).boolEnum () ;
      if (kBoolTrue == test_3) {
        const GALGAS_gtlType temp_4 = object ;
        GALGAS_gtlData var_copy_21971 = temp_4 ;
        callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 685)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 686)), constinArgument_lib, var_copy_21971, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 685)) ;
        GALGAS_gtlType temp_5 ;
        if (var_copy_21971.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlType *> (var_copy_21971.ptr ())) {
            temp_5 = (cPtr_gtlType *) var_copy_21971.ptr () ;
          }else{
            inCompiler->castError ("gtlType", var_copy_21971.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 691)) ;
          }
        }
        object->mAttribute_type = temp_5.getter_type (SOURCE_FILE ("gtl_data_types.galgas", 691)) ;
        object->mAttribute_where = var_copy_21971.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 692)) ;
        object->mAttribute_meta = var_copy_21971.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 693)) ;
      }else if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 695)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 695)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 695)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 695)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 695)) ;
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlType_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                      extensionSetter_gtlType_performSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlType_performSetter (defineExtensionSetter_gtlType_performSetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum desc'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlEnum_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint & constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 708)).add_operation (GALGAS_string ("enum: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 708)).add_operation (object->mAttribute_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 709)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 709)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_desc) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_desc (defineExtensionGetter_gtlEnum_desc, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum string'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlEnum_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  result_result = object->mAttribute_value ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                               extensionGetter_gtlEnum_string) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_string (defineExtensionGetter_gtlEnum_string, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlEnum lstring'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlEnum_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  result_result = GALGAS_lstring::constructor_new (object->mAttribute_value, object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 715)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                extensionGetter_gtlEnum_lstring) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_lstring (defineExtensionGetter_gtlEnum_lstring, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum bool'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlEnum_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an enum to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 719)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_bool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_bool (defineExtensionGetter_gtlEnum_bool, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum int'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bigint extensionGetter_gtlEnum_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an enum to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 723)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                            extensionGetter_gtlEnum_int) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_int (defineExtensionGetter_gtlEnum_int, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum float'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_double extensionGetter_gtlEnum_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an enum to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 727)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_float) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_float (defineExtensionGetter_gtlEnum_float, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum plusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                               extensionGetter_gtlEnum_plusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_plusOp (defineExtensionGetter_gtlEnum_plusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlEnum minusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 734)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                extensionGetter_gtlEnum_minusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_minusOp (defineExtensionGetter_gtlEnum_minusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum notOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 737)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_notOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_notOp (defineExtensionGetter_gtlEnum_notOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum addOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 740)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_addOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_addOp (defineExtensionGetter_gtlEnum_addOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum subOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 743)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_subOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_subOp (defineExtensionGetter_gtlEnum_subOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum mulOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 746)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_mulOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_mulOp (defineExtensionGetter_gtlEnum_mulOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum divOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 749)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_divOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_divOp (defineExtensionGetter_gtlEnum_divOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum modOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 752)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_modOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_modOp (defineExtensionGetter_gtlEnum_modOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum andOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 755)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_andOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_andOp (defineExtensionGetter_gtlEnum_andOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum orOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 758)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_orOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_orOp (defineExtensionGetter_gtlEnum_orOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum xorOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 761)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_xorOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_xorOp (defineExtensionGetter_gtlEnum_xorOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum slOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 764)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_slOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_slOp (defineExtensionGetter_gtlEnum_slOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum srOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 767)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_srOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_srOp (defineExtensionGetter_gtlEnum_srOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum neqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlEnum temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 774)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 773)), GALGAS_bool (kIsNotEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 774))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 771)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 777)), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 777)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_neqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_neqOp (defineExtensionGetter_gtlEnum_neqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum eqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlEnum temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 785)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 784)), GALGAS_bool (kIsEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 785))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 782)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 788)), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 788)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_eqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_eqOp (defineExtensionGetter_gtlEnum_eqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum gtOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 792)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_gtOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_gtOp (defineExtensionGetter_gtlEnum_gtOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum geOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 795)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_geOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_geOp (defineExtensionGetter_gtlEnum_geOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum ltOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 798)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_ltOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_ltOp (defineExtensionGetter_gtlEnum_ltOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum leOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 801)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_leOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_leOp (defineExtensionGetter_gtlEnum_leOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlEnum embeddedType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_type extensionGetter_gtlEnum_embeddedType (const cPtr_gtlData * inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 806)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                     extensionGetter_gtlEnum_embeddedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_embeddedType (defineExtensionGetter_gtlEnum_embeddedType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@gtlEnum addMyValue'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlEnum_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & /* ioArgument_objectList */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 811)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlEnum_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                   extensionMethod_gtlEnum_addMyValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlEnum_addMyValue (defineExtensionMethod_gtlEnum_addMyValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlEnum performGetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlEnum_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring & constinArgument_methodName,
                                                             const GALGAS_gtlDataList & constinArgument_arguments,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 823)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 824)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 824)) ;
    }
    const GALGAS_gtlEnum temp_1 = object ;
    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 826)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 826)), callExtensionGetter_string ((const cPtr_gtlEnum *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 826))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 825)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 828)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 829)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 829)) ;
      }
      const GALGAS_gtlEnum temp_3 = object ;
      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 831)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 831)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 831))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 830)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 833)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 834)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 834)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 836)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 836)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 835)) ;
      }else if (kBoolFalse == test_4) {
        const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 838)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 839)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 839)) ;
          }
          result_result = GALGAS_gtlString::constructor_new (object->mAttribute_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 841)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 841)), object->mAttribute_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 841))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 840)) ;
        }else if (kBoolFalse == test_5) {
          const enumGalgasBool test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 843)).boolEnum () ;
          if (kBoolTrue == test_6) {
            const GALGAS_gtlEnum temp_7 = object ;
            result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 844)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 845)), constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 844)) ;
          }else if (kBoolFalse == test_6) {
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 851)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 851)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 851)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 851)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 851)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlEnum_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionGetter_gtlEnum_performGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlEnum_performGetter (defineExtensionGetter_gtlEnum_performGetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension setter '@gtlEnum performSetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlEnum_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlEnum * object = (cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 863)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 864)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 864)) ;
    }
    GALGAS_gtlString temp_1 ;
    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 865)).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 865)).ptr ())) {
        temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 865)).ptr () ;
      }else{
        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 865)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 865)) ;
      }
    }
    GALGAS_gtlString var_descriptionToSet_27868 = temp_1 ;
    {
    object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_27868.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)) ;
    }
    object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 867)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 868)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 869)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 869)) ;
      }
      object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 870)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)).boolEnum () ;
      if (kBoolTrue == test_3) {
        const GALGAS_gtlEnum temp_4 = object ;
        GALGAS_gtlData var_copy_28164 = temp_4 ;
        callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 873)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 874)), constinArgument_lib, var_copy_28164, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 873)) ;
        GALGAS_gtlEnum temp_5 ;
        if (var_copy_28164.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlEnum *> (var_copy_28164.ptr ())) {
            temp_5 = (cPtr_gtlEnum *) var_copy_28164.ptr () ;
          }else{
            inCompiler->castError ("gtlEnum", var_copy_28164.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 879)) ;
          }
        }
        object->mAttribute_value = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 879)) ;
        object->mAttribute_where = var_copy_28164.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 880)) ;
        object->mAttribute_meta = var_copy_28164.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 881)) ;
      }else if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 883)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 883)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 883)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 883)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 883)) ;
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlEnum_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionSetter_gtlEnum_performSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlEnum_performSetter (defineExtensionSetter_gtlEnum_performSetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar desc'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlChar_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint & constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 896)).add_operation (GALGAS_string ("char: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 896)).add_operation (object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 897)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 897)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 897)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_desc) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_desc (defineExtensionGetter_gtlChar_desc, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar string'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlChar_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 900)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                               extensionGetter_gtlChar_string) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_string (defineExtensionGetter_gtlChar_string, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlChar lstring'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlChar_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = GALGAS_lstring::constructor_new (object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 903)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 903)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                extensionGetter_gtlChar_lstring) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_lstring (defineExtensionGetter_gtlChar_lstring, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar bool'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlChar_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast a char to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 907)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_bool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_bool (defineExtensionGetter_gtlChar_bool, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar int'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bigint extensionGetter_gtlChar_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = object->mAttribute_value.getter_uint (SOURCE_FILE ("gtl_data_types.galgas", 911)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 911)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                            extensionGetter_gtlChar_int) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_int (defineExtensionGetter_gtlChar_int, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar float'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_double extensionGetter_gtlChar_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast a char to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 915)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_float) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_float (defineExtensionGetter_gtlChar_float, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar plusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 919)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                               extensionGetter_gtlChar_plusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_plusOp (defineExtensionGetter_gtlChar_plusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlChar minusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 923)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                extensionGetter_gtlChar_minusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_minusOp (defineExtensionGetter_gtlChar_minusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar notOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 927)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_notOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_notOp (defineExtensionGetter_gtlChar_notOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar addOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 931)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_addOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_addOp (defineExtensionGetter_gtlChar_addOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar subOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 935)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_subOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_subOp (defineExtensionGetter_gtlChar_subOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar mulOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 939)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_mulOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_mulOp (defineExtensionGetter_gtlChar_mulOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar divOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 943)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_divOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_divOp (defineExtensionGetter_gtlChar_divOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar modOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 947)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_modOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_modOp (defineExtensionGetter_gtlChar_modOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar andOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 951)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_andOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_andOp (defineExtensionGetter_gtlChar_andOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar orOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 955)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_orOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_orOp (defineExtensionGetter_gtlChar_orOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar xorOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 959)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_xorOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_xorOp (defineExtensionGetter_gtlChar_xorOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar slOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 963)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_slOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_slOp (defineExtensionGetter_gtlChar_slOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar srOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 967)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_srOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_srOp (defineExtensionGetter_gtlChar_srOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar neqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlChar temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 975)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 974)), GALGAS_bool (kIsNotEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 975))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 972)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 978)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 978)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_neqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_neqOp (defineExtensionGetter_gtlChar_neqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar eqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlChar temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 987)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 986)), GALGAS_bool (kIsEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 987))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 984)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 990)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 990)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_eqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_eqOp (defineExtensionGetter_gtlChar_eqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar gtOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlChar temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 999)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 998)), GALGAS_bool (kIsStrictSup, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 999))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 996)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1002)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1002)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_gtOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_gtOp (defineExtensionGetter_gtlChar_gtOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar geOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlChar temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1011)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1010)), GALGAS_bool (kIsSupOrEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1011))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1008)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1014)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1014)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_geOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_geOp (defineExtensionGetter_gtlChar_geOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar ltOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlChar temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1022)), GALGAS_bool (kIsStrictInf, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1023))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1020)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1026)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1026)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_ltOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_ltOp (defineExtensionGetter_gtlChar_ltOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar leOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlChar temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1034)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1035))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1032)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1038)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1038)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_leOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_leOp (defineExtensionGetter_gtlChar_leOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlChar embeddedType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_type extensionGetter_gtlChar_embeddedType (const cPtr_gtlData * /* inObject */,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_char) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                     extensionGetter_gtlChar_embeddedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_embeddedType (defineExtensionGetter_gtlChar_embeddedType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@gtlChar addMyValue'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlChar_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & ioArgument_objectList,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  ioArgument_objectList.addAssign_operation (object->mAttribute_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1049))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1049)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlChar_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                   extensionMethod_gtlChar_addMyValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlChar_addMyValue (defineExtensionMethod_gtlChar_addMyValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlChar performGetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlChar_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring & constinArgument_methodName,
                                                             const GALGAS_gtlDataList & constinArgument_arguments,
                                                             const GALGAS_library & constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1061)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1062)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1062)) ;
    }
    const GALGAS_gtlChar temp_1 = object ;
    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1064)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1064)), callExtensionGetter_string ((const cPtr_gtlChar *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1064))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1063)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlnum").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1066)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1067)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1067)) ;
      }
      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1069)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1069)), object->mAttribute_value.getter_isalnum (SOURCE_FILE ("gtl_data_types.galgas", 1069))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1068)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isCntrl").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1071)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1072)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1072)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1074)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1074)), object->mAttribute_value.getter_iscntrl (SOURCE_FILE ("gtl_data_types.galgas", 1074))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1073)) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isDigit").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1076)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1077)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1077)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1079)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1079)), object->mAttribute_value.getter_isdigit (SOURCE_FILE ("gtl_data_types.galgas", 1079))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1078)) ;
        }else if (kBoolFalse == test_4) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlpha").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1081)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1082)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1082)) ;
            }
            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1084)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1084)), object->mAttribute_value.getter_isalpha (SOURCE_FILE ("gtl_data_types.galgas", 1084))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1083)) ;
          }else if (kBoolFalse == test_5) {
            const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("isLower").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1086)))).boolEnum () ;
            if (kBoolTrue == test_6) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1087)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1087)) ;
              }
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1089)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1089)), object->mAttribute_value.getter_islower (SOURCE_FILE ("gtl_data_types.galgas", 1089))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1088)) ;
            }else if (kBoolFalse == test_6) {
              const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("isUpper").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1091)))).boolEnum () ;
              if (kBoolTrue == test_7) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1092)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1092)) ;
                }
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1094)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1094)), object->mAttribute_value.getter_isupper (SOURCE_FILE ("gtl_data_types.galgas", 1094))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1093)) ;
              }else if (kBoolFalse == test_7) {
                const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("isXDigit").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1096)))).boolEnum () ;
                if (kBoolTrue == test_8) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1097)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1097)) ;
                  }
                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1099)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1099)), object->mAttribute_value.getter_isxdigit (SOURCE_FILE ("gtl_data_types.galgas", 1099))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1098)) ;
                }else if (kBoolFalse == test_8) {
                  const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1101)))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1102)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1102)) ;
                    }
                    const GALGAS_gtlChar temp_10 = object ;
                    result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1104)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1104)), temp_10.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1104))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1103)) ;
                  }else if (kBoolFalse == test_9) {
                    const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1106)))).boolEnum () ;
                    if (kBoolTrue == test_11) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1107)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1107)) ;
                      }
                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1109)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1109)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)) ;
                    }else if (kBoolFalse == test_11) {
                      const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1111)))).boolEnum () ;
                      if (kBoolTrue == test_12) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1112)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1112)) ;
                        }
                        result_result = GALGAS_gtlString::constructor_new (object->mAttribute_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1114)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1114)), object->mAttribute_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1114))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)) ;
                      }else if (kBoolFalse == test_12) {
                        const enumGalgasBool test_13 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1116)).boolEnum () ;
                        if (kBoolTrue == test_13) {
                          const GALGAS_gtlChar temp_14 = object ;
                          result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1117)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1118)), constinArgument_lib, temp_14, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1117)) ;
                        }else if (kBoolFalse == test_13) {
                          TC_Array <C_FixItDescription> fixItArray15 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1124)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1124)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)), fixItArray15  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)) ;
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
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlChar_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionGetter_gtlChar_performGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlChar_performGetter (defineExtensionGetter_gtlChar_performGetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension setter '@gtlChar performSetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlChar_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlChar * object = (cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1136)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1137)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1137)) ;
    }
    GALGAS_gtlString temp_1 ;
    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)).ptr ())) {
        temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)).ptr () ;
      }else{
        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)) ;
      }
    }
    GALGAS_gtlString var_descriptionToSet_36052 = temp_1 ;
    {
    object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_36052.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1139)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1139)) ;
    }
    object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1140)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1141)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1142)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1142)) ;
      }
      object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1143)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1144)).boolEnum () ;
      if (kBoolTrue == test_3) {
        const GALGAS_gtlChar temp_4 = object ;
        GALGAS_gtlData var_copy_36348 = temp_4 ;
        callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1146)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1147)), constinArgument_lib, var_copy_36348, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1146)) ;
        GALGAS_gtlChar temp_5 ;
        if (var_copy_36348.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlChar *> (var_copy_36348.ptr ())) {
            temp_5 = (cPtr_gtlChar *) var_copy_36348.ptr () ;
          }else{
            inCompiler->castError ("gtlChar", var_copy_36348.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1152)) ;
          }
        }
        object->mAttribute_value = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1152)) ;
        object->mAttribute_where = var_copy_36348.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1153)) ;
        object->mAttribute_meta = var_copy_36348.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 1154)) ;
      }else if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1156)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1156)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1156)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1156)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1156)) ;
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlChar_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionSetter_gtlChar_performSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlChar_performSetter (defineExtensionSetter_gtlChar_performSetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt desc'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlInt_desc (const cPtr_gtlData * inObject,
                                                  const GALGAS_uint & constinArgument_tab,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1169)).add_operation (GALGAS_string ("integer: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1169)).add_operation (object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1170)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1170)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1170)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_desc) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_desc (defineExtensionGetter_gtlInt_desc, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt string'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlInt_string (const cPtr_gtlData * inObject,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1173)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                               extensionGetter_gtlInt_string) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_string (defineExtensionGetter_gtlInt_string, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt lstring'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlInt_lstring (const cPtr_gtlData * inObject,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_lstring::constructor_new (object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1176)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                extensionGetter_gtlInt_lstring) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_lstring (defineExtensionGetter_gtlInt_lstring, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt bool'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlInt_bool (const cPtr_gtlData * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast an int to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1180)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_bool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_bool (defineExtensionGetter_gtlInt_bool, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Overriding extension getter '@gtlInt int'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bigint extensionGetter_gtlInt_int (const cPtr_gtlData * inObject,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = object->mAttribute_value ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                            extensionGetter_gtlInt_int) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_int (defineExtensionGetter_gtlInt_int, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt float'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_double extensionGetter_gtlInt_float (const cPtr_gtlData * inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = object->mAttribute_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1188)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 1188)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_float) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_float (defineExtensionGetter_gtlInt_float, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt plusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_plusOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const GALGAS_gtlInt temp_0 = object ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                               extensionGetter_gtlInt_plusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_plusOp (defineExtensionGetter_gtlInt_plusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt minusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_minusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1194)), object->mAttribute_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1194))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1194)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                extensionGetter_gtlInt_minusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_minusOp (defineExtensionGetter_gtlInt_minusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt notOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_notOp (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1198)), object->mAttribute_value.operator_tilde (SOURCE_FILE ("gtl_data_types.galgas", 1198))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1198)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_notOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_notOp (defineExtensionGetter_gtlInt_notOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt addOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_addOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1206)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1205)), object->mAttribute_value.add_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1206)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1206))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1203)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1209)), GALGAS_string ("*int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1209)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_addOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_addOp (defineExtensionGetter_gtlInt_addOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt subOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_subOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1218)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1217)), object->mAttribute_value.substract_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1218)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1218))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1215)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1221)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1221)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_subOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_subOp (defineExtensionGetter_gtlInt_subOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt mulOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_mulOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1230)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1229)), object->mAttribute_value.multiply_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1230)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1230))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1227)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1233)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1233)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_mulOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_mulOp (defineExtensionGetter_gtlInt_mulOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt divOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_divOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1242)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1241)), object->mAttribute_value.divide_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1242)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1242))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1239)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1245)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1245)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_divOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_divOp (defineExtensionGetter_gtlInt_divOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt modOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_modOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1254)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1253)), object->mAttribute_value.modulo_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1254)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1254))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1251)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1257)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1257)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_modOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_modOp (defineExtensionGetter_gtlInt_modOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt andOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_andOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1266)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1265)), object->mAttribute_value.operator_and (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1266)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1266))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1263)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1269)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1269)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_andOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_andOp (defineExtensionGetter_gtlInt_andOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt orOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_orOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1278)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1277)), object->mAttribute_value.operator_or (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1278)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1278))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1275)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1281)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1281)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_orOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_orOp (defineExtensionGetter_gtlInt_orOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt xorOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_xorOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1290)) ;
      }
    }
    result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1289)), object->mAttribute_value.operator_xor (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1290)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1290))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1287)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1293)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1293)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_xorOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_xorOp (defineExtensionGetter_gtlInt_xorOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt slOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_slOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1299)) ;
      }
    }
    GALGAS_bigint var_r_40173 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1299)) ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsSupOrEqual, var_r_40173.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1300)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_gtlInt temp_3 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_3 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1304)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1303)), object->mAttribute_value.left_shift_operation (temp_3.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1304)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1304)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1304))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1301)) ;
    }else if (kBoolFalse == test_2) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1307)), GALGAS_string ("positive int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1307)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1310)), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1310)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_slOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_slOp (defineExtensionGetter_gtlInt_slOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt srOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_srOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1316)) ;
      }
    }
    GALGAS_bigint var_r_40607 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1316)) ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsSupOrEqual, var_r_40607.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1317)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      result_result = GALGAS_gtlInt::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1318)), object->mAttribute_value.right_shift_operation (var_r_40607.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1318)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1318))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1318)) ;
    }else if (kBoolFalse == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1320)), GALGAS_string ("positive int expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1323)), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1323)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_srOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_srOp (defineExtensionGetter_gtlInt_srOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt neqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_neqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData & constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1331)), GALGAS_bool (kIsNotEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1332))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1329)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1335)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1335)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_neqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_neqOp (defineExtensionGetter_gtlInt_neqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt eqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_eqOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1343)), GALGAS_bool (kIsEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1344))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1341)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1347)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1347)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_eqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_eqOp (defineExtensionGetter_gtlInt_eqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt gtOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_gtOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1356)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1355)), GALGAS_bool (kIsStrictSup, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1356))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1359)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1359)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_gtOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_gtOp (defineExtensionGetter_gtlInt_gtOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt geOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_geOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1368)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1367)), GALGAS_bool (kIsSupOrEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1368))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1365)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1371)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1371)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_geOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_geOp (defineExtensionGetter_gtlInt_geOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt ltOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_ltOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1380)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1379)), GALGAS_bool (kIsStrictInf, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1380))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1377)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1383)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1383)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_ltOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_ltOp (defineExtensionGetter_gtlInt_ltOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt leOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_leOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData & constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlInt temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1392)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1391)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1392))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1389)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1395)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1395)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_leOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_leOp (defineExtensionGetter_gtlInt_leOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlInt embeddedType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_type extensionGetter_gtlInt_embeddedType (const cPtr_gtlData * /* inObject */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bigint) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                     extensionGetter_gtlInt_embeddedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_embeddedType (defineExtensionGetter_gtlInt_embeddedType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@gtlInt addMyValue'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlInt_addMyValue (const cPtr_gtlData * inObject,
                                               GALGAS_objectlist & ioArgument_objectList,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  ioArgument_objectList.addAssign_operation (object->mAttribute_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1406))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1406)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlInt_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                   extensionMethod_gtlInt_addMyValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlInt_addMyValue (defineExtensionMethod_gtlInt_addMyValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlInt performGetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlInt_performGetter (const cPtr_gtlData * inObject,
                                                            const GALGAS_lstring & constinArgument_methodName,
                                                            const GALGAS_gtlDataList & constinArgument_arguments,
                                                            const GALGAS_library & constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1418)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1419)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1419)) ;
    }
    const GALGAS_gtlInt temp_1 = object ;
    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1421)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1421)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1421))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1420)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("padded").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1423)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1424)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1424)) ;
      }
      GALGAS_gtlInt temp_3 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)).ptr ())) {
          temp_3 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)).ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)) ;
        }
      }
      GALGAS_uint var_fieldSize_43401 = temp_3.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1425)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)) ;
      const GALGAS_gtlInt temp_4 = object ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1427)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1428)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1429)).getter_stringByLeftAndRightPadding (var_fieldSize_43401, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1429))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1426)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("leftPadded").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1431)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1432)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1432)) ;
        }
        GALGAS_gtlInt temp_6 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)).ptr ())) {
            temp_6 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)) ;
          }
        }
        GALGAS_uint var_fieldSize_43742 = temp_6.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1433)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)) ;
        const GALGAS_gtlInt temp_7 = object ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1435)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1436)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_7.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1437)).getter_stringByLeftPadding (var_fieldSize_43742, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1437))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1434)) ;
      }else if (kBoolFalse == test_5) {
        const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("rightPadded").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1439)))).boolEnum () ;
        if (kBoolTrue == test_8) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1440)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1440)) ;
          }
          GALGAS_gtlInt temp_9 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)).ptr ())) {
              temp_9 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)) ;
            }
          }
          GALGAS_uint var_fieldSize_44077 = temp_9.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1441)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)) ;
          const GALGAS_gtlInt temp_10 = object ;
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1443)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1444)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_10.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1445)).getter_stringByRightPadding (var_fieldSize_44077, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1445))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1442)) ;
        }else if (kBoolFalse == test_8) {
          const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("hexString").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1447)))).boolEnum () ;
          if (kBoolTrue == test_11) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1448)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1448)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1450)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1450)), object->mAttribute_value.getter_hexString (SOURCE_FILE ("gtl_data_types.galgas", 1450))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1449)) ;
          }else if (kBoolFalse == test_11) {
            const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("xString").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1452)))).boolEnum () ;
            if (kBoolTrue == test_12) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1453)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1453)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1455)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1455)), object->mAttribute_value.getter_xString (SOURCE_FILE ("gtl_data_types.galgas", 1455))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1454)) ;
            }else if (kBoolFalse == test_12) {
              const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBytes").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1457)))).boolEnum () ;
              if (kBoolTrue == test_13) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1458)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1458)) ;
                }
                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1460)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1461)), object->mAttribute_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1462)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1462)).substract_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1462)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1462)).divide_operation (GALGAS_uint ((uint32_t) 8U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1462)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1462)).add_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1462)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1462))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1459)) ;
              }else if (kBoolFalse == test_13) {
                const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBytes").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1464)))).boolEnum () ;
                if (kBoolTrue == test_14) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1465)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1465)) ;
                  }
                  result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1467)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1468)), object->mAttribute_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1469)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1469)).substract_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1469)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1469)).divide_operation (GALGAS_uint ((uint32_t) 8U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1469)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1469)).add_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1469)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1469))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1466)) ;
                }else if (kBoolFalse == test_14) {
                  const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBits").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1471)))).boolEnum () ;
                  if (kBoolTrue == test_15) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1472)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1472)) ;
                    }
                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1474)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)), object->mAttribute_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1476)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1476))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1473)) ;
                  }else if (kBoolFalse == test_15) {
                    const enumGalgasBool test_16 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBits").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1478)))).boolEnum () ;
                    if (kBoolTrue == test_16) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)) ;
                      }
                      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1481)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1482)), object->mAttribute_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1483)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1483))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
                    }else if (kBoolFalse == test_16) {
                      const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("sign").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1485)))).boolEnum () ;
                      if (kBoolTrue == test_17) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1486)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1486)) ;
                        }
                        result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1488)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1489)), object->mAttribute_value.getter_sign (SOURCE_FILE ("gtl_data_types.galgas", 1490)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1490))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)) ;
                      }else if (kBoolFalse == test_17) {
                        const enumGalgasBool test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInByte").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1492)))).boolEnum () ;
                        if (kBoolTrue == test_18) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1493)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1493)) ;
                          }
                          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1495)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1497)).objectCompare (GALGAS_uint ((uint32_t) 8U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1494)) ;
                        }else if (kBoolFalse == test_18) {
                          const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInByte").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1499)))).boolEnum () ;
                          if (kBoolTrue == test_19) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500)) ;
                            }
                            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1502)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1504)).objectCompare (GALGAS_uint ((uint32_t) 8U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1501)) ;
                          }else if (kBoolFalse == test_19) {
                            const enumGalgasBool test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInShort").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1506)))).boolEnum () ;
                            if (kBoolTrue == test_20) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1507)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1507)) ;
                              }
                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1509)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1510)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1511)).objectCompare (GALGAS_uint ((uint32_t) 16U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)) ;
                            }else if (kBoolFalse == test_20) {
                              const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInShort").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1513)))).boolEnum () ;
                              if (kBoolTrue == test_21) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1514)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1514)) ;
                                }
                                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1516)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1518)).objectCompare (GALGAS_uint ((uint32_t) 16U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1515)) ;
                              }else if (kBoolFalse == test_21) {
                                const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1520)))).boolEnum () ;
                                if (kBoolTrue == test_22) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1521)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1521)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1523)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1525)).objectCompare (GALGAS_uint ((uint32_t) 32U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1522)) ;
                                }else if (kBoolFalse == test_22) {
                                  const enumGalgasBool test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1527)))).boolEnum () ;
                                  if (kBoolTrue == test_23) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1528)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1528)) ;
                                    }
                                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1530)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1531)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1532)).objectCompare (GALGAS_uint ((uint32_t) 32U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1529)) ;
                                  }else if (kBoolFalse == test_23) {
                                    const enumGalgasBool test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLongLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1534)))).boolEnum () ;
                                    if (kBoolTrue == test_24) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1535)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1535)) ;
                                      }
                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1537)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1538)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1539)).objectCompare (GALGAS_uint ((uint32_t) 64U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1536)) ;
                                    }else if (kBoolFalse == test_24) {
                                      const enumGalgasBool test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLongLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1541)))).boolEnum () ;
                                      if (kBoolTrue == test_25) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1542)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1542)) ;
                                        }
                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1544)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1545)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1546)).objectCompare (GALGAS_uint ((uint32_t) 64U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1543)) ;
                                      }else if (kBoolFalse == test_25) {
                                        const enumGalgasBool test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("abs").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1548)))).boolEnum () ;
                                        if (kBoolTrue == test_26) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1549)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1549)) ;
                                          }
                                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1551)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1552)), object->mAttribute_value.getter_abs (SOURCE_FILE ("gtl_data_types.galgas", 1553))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1550)) ;
                                        }else if (kBoolFalse == test_26) {
                                          const enumGalgasBool test_27 = GALGAS_bool (kIsEqual, GALGAS_string ("bitAtIndex").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1555)))).boolEnum () ;
                                          if (kBoolTrue == test_27) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1556)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1556)) ;
                                            }
                                            GALGAS_gtlInt temp_28 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)).isValid ()) {
                                              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)).ptr ())) {
                                                temp_28 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)) ;
                                              }
                                            }
                                            GALGAS_uint var_index_48273 = temp_28.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1557)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)) ;
                                            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1559)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1560)), object->mAttribute_value.getter_bitAtIndex (var_index_48273 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1561))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1558)) ;
                                          }else if (kBoolFalse == test_27) {
                                            const enumGalgasBool test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1563)))).boolEnum () ;
                                            if (kBoolTrue == test_29) {
                                              {
                                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1564)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1564)) ;
                                              }
                                              const GALGAS_gtlInt temp_30 = object ;
                                              result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1566)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1566)), temp_30.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1566))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1565)) ;
                                            }else if (kBoolFalse == test_29) {
                                              const enumGalgasBool test_31 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1568)))).boolEnum () ;
                                              if (kBoolTrue == test_31) {
                                                {
                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)) ;
                                                }
                                                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1571)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1571)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1570)) ;
                                              }else if (kBoolFalse == test_31) {
                                                const enumGalgasBool test_32 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1573)))).boolEnum () ;
                                                if (kBoolTrue == test_32) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1574)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1574)) ;
                                                  }
                                                  result_result = GALGAS_gtlString::constructor_new (object->mAttribute_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1576)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)), object->mAttribute_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1576))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1575)) ;
                                                }else if (kBoolFalse == test_32) {
                                                  const enumGalgasBool test_33 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1578)).boolEnum () ;
                                                  if (kBoolTrue == test_33) {
                                                    const GALGAS_gtlInt temp_34 = object ;
                                                    result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1579)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1580)), constinArgument_lib, temp_34, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1579)) ;
                                                  }else if (kBoolFalse == test_33) {
                                                    TC_Array <C_FixItDescription> fixItArray35 ;
                                                    inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1586)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1586)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)), fixItArray35  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)) ;
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
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlInt_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionGetter_gtlInt_performGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlInt_performGetter (defineExtensionGetter_gtlInt_performGetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension setter '@gtlInt performSetter'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlInt_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlInt * object = (cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1598)).objectCompare (GALGAS_string ("setBitAtIndex"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_boolIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1599)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1599)) ;
    }
    GALGAS_gtlBool temp_1 ;
    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)).ptr ())) {
        temp_1 = (cPtr_gtlBool *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)).ptr () ;
      }else{
        inCompiler->castError ("gtlBool", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)) ;
      }
    }
    GALGAS_bool var_bit_49736 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1600)) ;
    GALGAS_gtlInt temp_2 ;
    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1601)).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1601)).ptr ())) {
        temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1601)).ptr () ;
      }else{
        inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1601)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1601)) ;
      }
    }
    GALGAS_uint var_index_49801 = temp_2.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1601)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1601)) ;
    {
    object->mAttribute_value.setter_setBitAtIndex (var_bit_49736, var_index_49801 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1602)) ;
    }
    object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1603)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1604)).objectCompare (GALGAS_string ("complementBitAtIndex"))).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1605)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1605)) ;
      }
      GALGAS_gtlInt temp_4 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)).ptr ())) {
          temp_4 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)).ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)) ;
        }
      }
      GALGAS_uint var_index_50052 = temp_4.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1606)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)) ;
      {
      object->mAttribute_value.setter_complementBitAtIndex (var_index_50052 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)) ;
      }
      object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1608)) ;
    }else if (kBoolFalse == test_3) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1609)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1610)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1610)) ;
        }
        GALGAS_gtlString temp_6 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)).ptr ())) {
            temp_6 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)).ptr () ;
          }else{
            inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)) ;
          }
        }
        GALGAS_gtlString var_descriptionToSet_50309 = temp_6 ;
        {
        object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_50309.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
        }
        object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1613)) ;
      }else if (kBoolFalse == test_5) {
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1614)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1615)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1615)) ;
          }
          object->mAttribute_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1616)) ;
        }else if (kBoolFalse == test_7) {
          const enumGalgasBool test_8 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1617)).boolEnum () ;
          if (kBoolTrue == test_8) {
            const GALGAS_gtlInt temp_9 = object ;
            GALGAS_gtlData var_copy_50604 = temp_9 ;
            callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1620)), constinArgument_lib, var_copy_50604, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)) ;
            GALGAS_gtlInt temp_10 ;
            if (var_copy_50604.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_copy_50604.ptr ())) {
                temp_10 = (cPtr_gtlInt *) var_copy_50604.ptr () ;
              }else{
                inCompiler->castError ("gtlInt", var_copy_50604.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1625)) ;
              }
            }
            object->mAttribute_value = temp_10.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1625)) ;
            object->mAttribute_where = var_copy_50604.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1626)) ;
            object->mAttribute_meta = var_copy_50604.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 1627)) ;
          }else if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray11 ;
            inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1629)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1629)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)), fixItArray11  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)) ;
          }
        }
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlInt_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionSetter_gtlInt_performSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlInt_performSetter (defineExtensionSetter_gtlInt_performSetter, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat desc'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlFloat_desc (const cPtr_gtlData * inObject,
                                                    const GALGAS_uint & constinArgument_tab,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)).add_operation (GALGAS_string ("float: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)).add_operation (object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1643)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1643)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1643)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_desc) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_desc (defineExtensionGetter_gtlFloat_desc, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat string'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlFloat_string (const cPtr_gtlData * inObject,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1646)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                               extensionGetter_gtlFloat_string) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_string (defineExtensionGetter_gtlFloat_string, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat lstring'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlFloat_lstring (const cPtr_gtlData * inObject,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = GALGAS_lstring::constructor_new (object->mAttribute_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1649)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1649)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                extensionGetter_gtlFloat_lstring) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_lstring (defineExtensionGetter_gtlFloat_lstring, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat bool'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlFloat_bool (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("cannot cast a float to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1653)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_bool) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_bool (defineExtensionGetter_gtlFloat_bool, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlFloat int'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bigint extensionGetter_gtlFloat_int (const cPtr_gtlData * inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = object->mAttribute_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1657)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1657)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                            extensionGetter_gtlFloat_int) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_int (defineExtensionGetter_gtlFloat_int, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat float'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_double extensionGetter_gtlFloat_float (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = object->mAttribute_value ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_float) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_float (defineExtensionGetter_gtlFloat_float, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat plusOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_plusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const GALGAS_gtlFloat temp_0 = object ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                               extensionGetter_gtlFloat_plusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_plusOp (defineExtensionGetter_gtlFloat_plusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat minusOp'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_minusOp (const cPtr_gtlData * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = GALGAS_gtlFloat::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)), object->mAttribute_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                extensionGetter_gtlFloat_minusOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_minusOp (defineExtensionGetter_gtlFloat_minusOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat notOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_notOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1671)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_notOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_notOp (defineExtensionGetter_gtlFloat_notOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat addOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_addOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1679)) ;
      }
    }
    result_result = GALGAS_gtlFloat::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1678)), object->mAttribute_value.add_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1679)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1679))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1676)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1682)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1682)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_addOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_addOp (defineExtensionGetter_gtlFloat_addOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat subOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_subOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1691)) ;
      }
    }
    result_result = GALGAS_gtlFloat::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1690)), object->mAttribute_value.substract_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1691)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1691))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1688)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1694)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1694)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_subOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_subOp (defineExtensionGetter_gtlFloat_subOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat mulOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_mulOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1703)) ;
      }
    }
    result_result = GALGAS_gtlFloat::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1702)), object->mAttribute_value.multiply_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1703)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1703))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1700)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1706)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_mulOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_mulOp (defineExtensionGetter_gtlFloat_mulOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat divOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_divOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1715)) ;
      }
    }
    result_result = GALGAS_gtlFloat::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1714)), object->mAttribute_value.divide_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1715)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1715))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1712)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1718)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1718)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_divOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_divOp (defineExtensionGetter_gtlFloat_divOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat modOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_modOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1723)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_modOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_modOp (defineExtensionGetter_gtlFloat_modOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat andOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_andOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1727)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_andOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_andOp (defineExtensionGetter_gtlFloat_andOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat orOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_orOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1731)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_orOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_orOp (defineExtensionGetter_gtlFloat_orOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat xorOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_xorOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1735)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_xorOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_xorOp (defineExtensionGetter_gtlFloat_xorOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat slOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_slOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1739)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_slOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_slOp (defineExtensionGetter_gtlFloat_slOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat srOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_srOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mAttribute_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1743)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_srOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_srOp (defineExtensionGetter_gtlFloat_srOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat neqOp'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_neqOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData & constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1751)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1750)), GALGAS_bool (kIsNotEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1751))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1748)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1754)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_neqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_neqOp (defineExtensionGetter_gtlFloat_neqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat eqOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_eqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1763)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1762)), GALGAS_bool (kIsEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1763))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1760)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1766)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_eqOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_eqOp (defineExtensionGetter_gtlFloat_eqOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat gtOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_gtOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1775)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1774)), GALGAS_bool (kIsStrictSup, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1775))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1772)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1778)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_gtOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_gtOp (defineExtensionGetter_gtlFloat_gtOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat geOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_geOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1787)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1786)), GALGAS_bool (kIsSupOrEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1787))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1784)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1790)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1790)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_geOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_geOp (defineExtensionGetter_gtlFloat_geOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat ltOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_ltOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1799)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1798)), GALGAS_bool (kIsStrictInf, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1799))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1796)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1802)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1802)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_ltOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_ltOp (defineExtensionGetter_gtlFloat_ltOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat leOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_leOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData & constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_gtlFloat temp_1 ;
    if (constinArgument_right.isValid ()) {
      if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
        temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
      }else{
        inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1811)) ;
      }
    }
    result_result = GALGAS_gtlBool::constructor_new (object->mAttribute_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1810)), GALGAS_bool (kIsInfOrEqual, object->mAttribute_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1811))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1808)) ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1814)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1814)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_leOp) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_leOp (defineExtensionGetter_gtlFloat_leOp, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlFloat embeddedType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_type extensionGetter_gtlFloat_embeddedType (const cPtr_gtlData * /* inObject */,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_double) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                     extensionGetter_gtlFloat_embeddedType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_embeddedType (defineExtensionGetter_gtlFloat_embeddedType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@gtlFloat addMyValue'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlFloat_addMyValue (const cPtr_gtlData * inObject,
                                                 GALGAS_objectlist & ioArgument_objectList,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  ioArgument_objectList.addAssign_operation (object->mAttribute_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1825))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1825)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlFloat_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                   extensionMethod_gtlFloat_addMyValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlFloat_addMyValue (defineExtensionMethod_gtlFloat_addMyValue, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@gtlFloat performGetter'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFloat_performGetter (const cPtr_gtlData * inObject,
                                                              const GALGAS_lstring & constinArgument_methodName,
                                                              const GALGAS_gtlDataList & constinArgument_arguments,
                                                              const GALGAS_library & constinArgument_lib,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1837)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1838)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1838)) ;
    }
    const GALGAS_gtlFloat temp_1 = object ;
    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1840)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1840)), callExtensionGetter_string ((const cPtr_gtlFloat *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1840))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1839)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("cos").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1842)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1843)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1843)) ;
      }
      result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1845)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1845)), object->mAttribute_value.getter_cos (SOURCE_FILE ("gtl_data_types.galgas", 1845))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1844)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("sin").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1847)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1848)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1848)) ;
        }
        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1850)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1850)), object->mAttribute_value.getter_sin (SOURCE_FILE ("gtl_data_types.galgas", 1850))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1849)) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("tan").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1852)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1853)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1853)) ;
          }
          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1855)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1855)), object->mAttribute_value.getter_tan (SOURCE_FILE ("gtl_data_types.galgas", 1855))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1854)) ;
        }else if (kBoolFalse == test_4) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("cosDegree").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1857)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1858)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1858)) ;
            }
            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1860)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1860)), object->mAttribute_value.getter_cosDegree (SOURCE_FILE ("gtl_data_types.galgas", 1860))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1859)) ;
          }else if (kBoolFalse == test_5) {
            const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("sinDegree").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1862)))).boolEnum () ;
            if (kBoolTrue == test_6) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1863)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1863)) ;
              }
              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1865)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1865)), object->mAttribute_value.getter_sinDegree (SOURCE_FILE ("gtl_data_types.galgas", 1865))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1864)) ;
            }else if (kBoolFalse == test_6) {
              const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("tanDegree").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1867)))).boolEnum () ;
              if (kBoolTrue == test_7) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1868)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1868)) ;
                }
                result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1870)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1870)), object->mAttribute_value.getter_tanDegree (SOURCE_FILE ("gtl_data_types.galgas", 1870))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1869)) ;
              }else if (kBoolFalse == test_7) {
                const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("exp").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1872)))).boolEnum () ;
                if (kBoolTrue == test_8) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1873)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1873)) ;
                  }
                  result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1875)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1875)), object->mAttribute_value.getter_exp (SOURCE_FILE ("gtl_data_types.galgas", 1875))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1874)) ;
                }else if (kBoolFalse == test_8) {
                  const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("logn").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1877)))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1878)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1878)) ;
                    }
                    result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1880)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1880)), object->mAttribute_value.getter_logn (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1880))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1879)) ;
                  }else if (kBoolFalse == test_9) {
                    const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, GALGAS_string ("log2").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1882)))).boolEnum () ;
                    if (kBoolTrue == test_10) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1883)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1883)) ;
                      }
                      result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1885)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1885)), object->mAttribute_value.getter_log_32_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1885))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1884)) ;
                    }else if (kBoolFalse == test_10) {
                      const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("log10").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1887)))).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1888)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1888)) ;
                        }
                        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1890)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1890)), object->mAttribute_value.getter_log_31__30_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1890))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1889)) ;
                      }else if (kBoolFalse == test_11) {
                        const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("sqrt").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1892)))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1893)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1893)) ;
                          }
                          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1895)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1895)), object->mAttribute_value.getter_sqrt (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1895))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1894)) ;
                        }else if (kBoolFalse == test_12) {
                          const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("power").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1897)))).boolEnum () ;
                          if (kBoolTrue == test_13) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_floatArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1898)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1898)) ;
                            }
                            GALGAS_gtlFloat temp_14 ;
                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899)).isValid ()) {
                              if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899)).ptr ())) {
                                temp_14 = (cPtr_gtlFloat *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899)).ptr () ;
                              }else{
                                inCompiler->castError ("gtlFloat", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899)) ;
                              }
                            }
                            GALGAS_double var_power_58807 = temp_14.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1899)) ;
                            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1901)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1901)), object->mAttribute_value.getter_power (var_power_58807, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1901))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1900)) ;
                          }else if (kBoolFalse == test_13) {
                            const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1903)))).boolEnum () ;
                            if (kBoolTrue == test_15) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904)) ;
                              }
                              const GALGAS_gtlFloat temp_16 = object ;
                              result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1906)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1906)), temp_16.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1906))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1905)) ;
                            }else if (kBoolFalse == test_15) {
                              const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1908)))).boolEnum () ;
                              if (kBoolTrue == test_17) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1909)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1909)) ;
                                }
                                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1911)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1911)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1910)) ;
                              }else if (kBoolFalse == test_17) {
                                const enumGalgasBool test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("int").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1913)))).boolEnum () ;
                                if (kBoolTrue == test_18) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1914)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1914)) ;
                                  }
                                  result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1916)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1916)), object->mAttribute_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1916)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1916))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1915)) ;
                                }else if (kBoolFalse == test_18) {
                                  const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1918)))).boolEnum () ;
                                  if (kBoolTrue == test_19) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1919)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1919)) ;
                                    }
                                    result_result = GALGAS_gtlString::constructor_new (object->mAttribute_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1921)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1921)), object->mAttribute_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1921))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1920)) ;
                                  }else if (kBoolFalse == test_19) {
                                    const enumGalgasBool test_20 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1923)).boolEnum () ;
                                    if (kBoolTrue == test_20) {
                                      const GALGAS_gtlFloat temp_21 = object ;
                                      result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1924)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1925)), constinArgument_lib, temp_21, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1924)) ;
                                    }else if (kBoolFalse == test_20) {
                                      TC_Array <C_FixItDescription> fixItArray22 ;
                                      inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1931)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1931)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1931)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1931)), fixItArray22  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1931)) ;
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
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFloat_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                      extensionGetter_gtlFloat_performGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFloat_performGetter (defineExtensionGetter_gtlFloat_performGetter, NULL) ;


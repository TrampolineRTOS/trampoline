#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-3.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@library functionExists'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_functionExists> gExtensionGetterTable_library_functionExists ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_functionExists (const int32_t inClassIndex,
                                          enterExtensionGetter_library_functionExists inGetter) {
  gExtensionGetterTable_library_functionExists.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_functionExists (const cPtr_library * inObject,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_functionExists f = NULL ;
    if (classIndex < gExtensionGetterTable_library_functionExists.count ()) {
      f = gExtensionGetterTable_library_functionExists (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_functionExists.count ()) {
           f = gExtensionGetterTable_library_functionExists (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_functionExists.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_functionExists (const cPtr_library * inObject,
                                                           const GALGAS_lstring constinArgument_name,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_exists ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_exists = object->mAttribute_funcMap.getter_hasKey (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 286)) COMMA_SOURCE_FILE ("gtl_types.galgas", 286)) ;
//---
  return result_exists ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_functionExists (void) {
  enterExtensionGetter_functionExists (kTypeDescriptor_GALGAS_library.mSlotID,
                                       extensionGetter_library_functionExists) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_functionExists (void) {
  gExtensionGetterTable_library_functionExists.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_functionExists (defineExtensionGetter_library_functionExists,
                                                   freeExtensionGetter_library_functionExists) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@library getFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getFunction> gExtensionGetterTable_library_getFunction ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getFunction (const int32_t inClassIndex,
                                       enterExtensionGetter_library_getFunction inGetter) {
  gExtensionGetterTable_library_getFunction.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction callExtensionGetter_getFunction (const cPtr_library * inObject,
                                                    const GALGAS_lstring in_name,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunction result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getFunction f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getFunction.count ()) {
      f = gExtensionGetterTable_library_getFunction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getFunction.count ()) {
           f = gExtensionGetterTable_library_getFunction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getFunction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlFunction extensionGetter_library_getFunction (const cPtr_library * inObject,
                                                               const GALGAS_lstring constinArgument_name,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlFunction result_aFunction ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_funcMap.method_get (constinArgument_name, result_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 293)) ;
//---
  return result_aFunction ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getFunction (void) {
  enterExtensionGetter_getFunction (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionGetter_library_getFunction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getFunction (void) {
  gExtensionGetterTable_library_getFunction.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getFunction (defineExtensionGetter_library_getFunction,
                                                freeExtensionGetter_library_getFunction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library putFunction'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_putFunction> gExtensionModifierTable_library_putFunction ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) {
  gExtensionModifierTable_library_putFunction.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putFunction (cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putFunction f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putFunction.count ()) {
      f = gExtensionModifierTable_library_putFunction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putFunction.count ()) {
           f = gExtensionModifierTable_library_putFunction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putFunction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aFunction, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_putFunction (cPtr_library * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 const GALGAS_gtlFunction constinArgument_aFunction,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mAttribute_funcMap.setter_put (constinArgument_name, constinArgument_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 300)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_putFunction (void) {
  enterExtensionSetter_putFunction (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionSetter_library_putFunction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_putFunction (void) {
  gExtensionModifierTable_library_putFunction.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_putFunction (defineExtensionSetter_library_putFunction,
                                                freeExtensionModifier_library_putFunction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@library getterExists'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getterExists> gExtensionGetterTable_library_getterExists ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getterExists (const int32_t inClassIndex,
                                        enterExtensionGetter_library_getterExists inGetter) {
  gExtensionGetterTable_library_getterExists.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_getterExists (const cPtr_library * inObject,
                                              const GALGAS_string in_type,
                                              const GALGAS_lstring in_name,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getterExists f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getterExists.count ()) {
      f = gExtensionGetterTable_library_getterExists (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getterExists.count ()) {
           f = gExtensionGetterTable_library_getterExists (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getterExists.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_getterExists (const cPtr_library * inObject,
                                                         const GALGAS_string constinArgument_type,
                                                         const GALGAS_lstring constinArgument_name,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_exists ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_exists = object->mAttribute_getterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 308)) COMMA_SOURCE_FILE ("gtl_types.galgas", 308)) ;
//---
  return result_exists ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getterExists (void) {
  enterExtensionGetter_getterExists (kTypeDescriptor_GALGAS_library.mSlotID,
                                     extensionGetter_library_getterExists) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getterExists (void) {
  gExtensionGetterTable_library_getterExists.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getterExists (defineExtensionGetter_library_getterExists,
                                                 freeExtensionGetter_library_getterExists) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library getGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getGetter> gExtensionGetterTable_library_getGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getGetter (const int32_t inClassIndex,
                                     enterExtensionGetter_library_getGetter inGetter) {
  gExtensionGetterTable_library_getGetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter callExtensionGetter_getGetter (const cPtr_library * inObject,
                                                const GALGAS_string in_type,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetter result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getGetter f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getGetter.count ()) {
      f = gExtensionGetterTable_library_getGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getGetter.count ()) {
           f = gExtensionGetterTable_library_getGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlGetter extensionGetter_library_getGetter (const cPtr_library * inObject,
                                                           const GALGAS_string constinArgument_type,
                                                           const GALGAS_lstring constinArgument_name,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlGetter result_aGetter ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_getterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 316)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 316)), constinArgument_name.getter_location (SOURCE_FILE ("gtl_types.galgas", 316))  COMMA_SOURCE_FILE ("gtl_types.galgas", 316)), result_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 316)) ;
//---
  return result_aGetter ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getGetter (void) {
  enterExtensionGetter_getGetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionGetter_library_getGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getGetter (void) {
  gExtensionGetterTable_library_getGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getGetter (defineExtensionGetter_library_getGetter,
                                              freeExtensionGetter_library_getGetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putGetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_putGetter> gExtensionModifierTable_library_putGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) {
  gExtensionModifierTable_library_putGetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putGetter (cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putGetter f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putGetter.count ()) {
      f = gExtensionModifierTable_library_putGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putGetter.count ()) {
           f = gExtensionModifierTable_library_putGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aGetter, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_putGetter (cPtr_library * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlGetter constinArgument_aGetter,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mAttribute_getterMap.setter_put (constinArgument_name, constinArgument_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 323)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_putGetter (void) {
  enterExtensionSetter_putGetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionSetter_library_putGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_putGetter (void) {
  gExtensionModifierTable_library_putGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_putGetter (defineExtensionSetter_library_putGetter,
                                              freeExtensionModifier_library_putGetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@library setterExists'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_setterExists> gExtensionGetterTable_library_setterExists ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_setterExists (const int32_t inClassIndex,
                                        enterExtensionGetter_library_setterExists inGetter) {
  gExtensionGetterTable_library_setterExists.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_setterExists (const cPtr_library * inObject,
                                              const GALGAS_string in_type,
                                              const GALGAS_lstring in_name,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_setterExists f = NULL ;
    if (classIndex < gExtensionGetterTable_library_setterExists.count ()) {
      f = gExtensionGetterTable_library_setterExists (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_setterExists.count ()) {
           f = gExtensionGetterTable_library_setterExists (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_setterExists.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_setterExists (const cPtr_library * inObject,
                                                         const GALGAS_string constinArgument_type,
                                                         const GALGAS_lstring constinArgument_name,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_exists ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_exists = object->mAttribute_setterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 331)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 331)) COMMA_SOURCE_FILE ("gtl_types.galgas", 331)) ;
//---
  return result_exists ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_setterExists (void) {
  enterExtensionGetter_setterExists (kTypeDescriptor_GALGAS_library.mSlotID,
                                     extensionGetter_library_setterExists) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_setterExists (void) {
  gExtensionGetterTable_library_setterExists.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_setterExists (defineExtensionGetter_library_setterExists,
                                                 freeExtensionGetter_library_setterExists) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library getSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_getSetter> gExtensionGetterTable_library_getSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getSetter (const int32_t inClassIndex,
                                     enterExtensionGetter_library_getSetter inGetter) {
  gExtensionGetterTable_library_getSetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter callExtensionGetter_getSetter (const cPtr_library * inObject,
                                                const GALGAS_string in_type,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetter result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_getSetter f = NULL ;
    if (classIndex < gExtensionGetterTable_library_getSetter.count ()) {
      f = gExtensionGetterTable_library_getSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_getSetter.count ()) {
           f = gExtensionGetterTable_library_getSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_getSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_type, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlSetter extensionGetter_library_getSetter (const cPtr_library * inObject,
                                                           const GALGAS_string constinArgument_type,
                                                           const GALGAS_lstring constinArgument_name,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlSetter result_aSetter ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_setterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.getter_string (SOURCE_FILE ("gtl_types.galgas", 339)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 339)), constinArgument_name.getter_location (SOURCE_FILE ("gtl_types.galgas", 339))  COMMA_SOURCE_FILE ("gtl_types.galgas", 339)), result_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 339)) ;
//---
  return result_aSetter ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_getSetter (void) {
  enterExtensionGetter_getSetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionGetter_library_getSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_getSetter (void) {
  gExtensionGetterTable_library_getSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_getSetter (defineExtensionGetter_library_getSetter,
                                              freeExtensionGetter_library_getSetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library putSetter'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_putSetter> gExtensionModifierTable_library_putSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) {
  gExtensionModifierTable_library_putSetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_putSetter (cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putSetter f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putSetter.count ()) {
      f = gExtensionModifierTable_library_putSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putSetter.count ()) {
           f = gExtensionModifierTable_library_putSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aSetter, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_putSetter (cPtr_library * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlSetter constinArgument_aSetter,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mAttribute_setterMap.setter_put (constinArgument_name, constinArgument_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 346)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_putSetter (void) {
  enterExtensionSetter_putSetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionSetter_library_putSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_putSetter (void) {
  gExtensionModifierTable_library_putSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_putSetter (defineExtensionSetter_library_putSetter,
                                              freeExtensionModifier_library_putSetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@library hasImport'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_library_hasImport> gExtensionGetterTable_library_hasImport ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasImport (const int32_t inClassIndex,
                                     enterExtensionGetter_library_hasImport inGetter) {
  gExtensionGetterTable_library_hasImport.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                           const GALGAS_string in_importPath,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_library_hasImport f = NULL ;
    if (classIndex < gExtensionGetterTable_library_hasImport.count ()) {
      f = gExtensionGetterTable_library_hasImport (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_library_hasImport.count ()) {
           f = gExtensionGetterTable_library_hasImport (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_library_hasImport.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_importPath, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_library_hasImport (const cPtr_library * inObject,
                                                      const GALGAS_string constinArgument_importPath,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  result_result = object->mAttribute_doneImports.getter_hasKey (constinArgument_importPath COMMA_SOURCE_FILE ("gtl_types.galgas", 353)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_library_hasImport (void) {
  enterExtensionGetter_hasImport (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionGetter_library_hasImport) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_library_hasImport (void) {
  gExtensionGetterTable_library_hasImport.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_library_hasImport (defineExtensionGetter_library_hasImport,
                                              freeExtensionGetter_library_hasImport) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension setter '@library doImport'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_doImport> gExtensionModifierTable_library_doImport ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) {
  gExtensionModifierTable_library_doImport.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_doImport (cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_doImport f = NULL ;
    if (classIndex < gExtensionModifierTable_library_doImport.count ()) {
      f = gExtensionModifierTable_library_doImport (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_doImport.count ()) {
           f = gExtensionModifierTable_library_doImport (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_doImport.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_importPath, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_doImport (cPtr_library * inObject,
                                              const GALGAS_string constinArgument_importPath,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mAttribute_doneImports.addAssign_operation (constinArgument_importPath  COMMA_SOURCE_FILE ("gtl_types.galgas", 359)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_doImport (void) {
  enterExtensionSetter_doImport (kTypeDescriptor_GALGAS_library.mSlotID,
                                 extensionSetter_library_doImport) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_doImport (void) {
  gExtensionModifierTable_library_doImport.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_doImport (defineExtensionSetter_library_doImport,
                                             freeExtensionModifier_library_doImport) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@library getTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_library_getTemplate> gExtensionModifierTable_library_getTemplate ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_getTemplate (const int32_t inClassIndex,
                                       extensionSetterSignature_library_getTemplate inModifier) {
  gExtensionModifierTable_library_getTemplate.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_getTemplate (cPtr_library * inObject,
                                      const GALGAS_gtlContext constin_context,
                                      GALGAS_lstring in_path,
                                      GALGAS_bool in_ifExists,
                                      GALGAS_library & io_lib,
                                      GALGAS_bool & out_found,
                                      GALGAS_gtlTemplate & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_found.drop () ;
  out_result.drop () ;
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_getTemplate f = NULL ;
    if (classIndex < gExtensionModifierTable_library_getTemplate.count ()) {
      f = gExtensionModifierTable_library_getTemplate (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_getTemplate.count ()) {
           f = gExtensionModifierTable_library_getTemplate (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_getTemplate.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_context, in_path, in_ifExists, io_lib, out_found, out_result, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_library_getTemplate (cPtr_library * inObject,
                                                 const GALGAS_gtlContext constinArgument_context,
                                                 GALGAS_lstring inArgument_path,
                                                 GALGAS_bool inArgument_ifExists,
                                                 GALGAS_library & ioArgument_lib,
                                                 GALGAS_bool & outArgument_found,
                                                 GALGAS_gtlTemplate & outArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  extensionSetter_getTemplate (object->mAttribute_templateMap, constinArgument_context, inArgument_path, inArgument_ifExists, ioArgument_lib, outArgument_found, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 371)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_library_getTemplate (void) {
  enterExtensionSetter_getTemplate (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionSetter_library_getTemplate) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_library_getTemplate (void) {
  gExtensionModifierTable_library_getTemplate.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_library_getTemplate (defineExtensionSetter_library_getTemplate,
                                                freeExtensionModifier_library_getTemplate) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlVarItemField::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarItemField * p = (const cPtr_gtlVarItemField *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarItemField) ;
  if (kOperandEqual == result) {
    result = mAttribute_field.objectCompare (p->mAttribute_field) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlVarItemField::objectCompare (const GALGAS_gtlVarItemField & inOperand) const {
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

GALGAS_gtlVarItemField::GALGAS_gtlVarItemField (void) :
GALGAS_gtlVarItem () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemField GALGAS_gtlVarItemField::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlVarItemField::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemField::GALGAS_gtlVarItemField (const cPtr_gtlVarItemField * inSourcePtr) :
GALGAS_gtlVarItem (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItemField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemField GALGAS_gtlVarItemField::constructor_new (const GALGAS_lstring & inAttribute_field
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemField result ;
  if (inAttribute_field.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarItemField (inAttribute_field COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlVarItemField::getter_field (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlVarItemField * p = (const cPtr_gtlVarItemField *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemField) ;
    result = p->mAttribute_field ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlVarItemField::getter_field (UNUSED_LOCATION_ARGS) const {
  return mAttribute_field ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @gtlVarItemField class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlVarItemField::cPtr_gtlVarItemField (const GALGAS_lstring & in_field
                                            COMMA_LOCATION_ARGS) :
cPtr_gtlVarItem (THERE),
mAttribute_field (in_field) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlVarItemField::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemField ;
}

void cPtr_gtlVarItemField::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@gtlVarItemField:" ;
  mAttribute_field.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlVarItemField::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarItemField (mAttribute_field COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlVarItemField type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItemField ("gtlVarItemField",
                                        & kTypeDescriptor_GALGAS_gtlVarItem) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarItemField::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemField ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarItemField::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItemField (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemField GALGAS_gtlVarItemField::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemField result ;
  const GALGAS_gtlVarItemField * p = (const GALGAS_gtlVarItemField *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItemField *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItemField", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension getter '@gtlVarItemField lstringPath'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlVarItemField_lstringPath> gExtensionGetterTable_gtlVarItemField_lstringPath ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_lstringPath (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlVarItemField_lstringPath inGetter) {
  gExtensionGetterTable_gtlVarItemField_lstringPath.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItemField) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlVarItemField_lstringPath f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlVarItemField_lstringPath.count ()) {
      f = gExtensionGetterTable_gtlVarItemField_lstringPath (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlVarItemField_lstringPath.count ()) {
           f = gExtensionGetterTable_gtlVarItemField_lstringPath (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlVarItemField_lstringPath.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_lstring extensionGetter_gtlVarItemField_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlVarItemField * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlVarItemField) ;
  result_result = object->mAttribute_field ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlVarItemField_lstringPath (void) {
  enterExtensionGetter_lstringPath (kTypeDescriptor_GALGAS_gtlVarItemField.mSlotID,
                                    extensionGetter_gtlVarItemField_lstringPath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlVarItemField_lstringPath (void) {
  gExtensionGetterTable_gtlVarItemField_lstringPath.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlVarItemField_lstringPath (defineExtensionGetter_gtlVarItemField_lstringPath,
                                                        freeExtensionGetter_gtlVarItemField_lstringPath) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlVarItemCollection::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarItemCollection * p = (const cPtr_gtlVarItemCollection *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarItemCollection) ;
  if (kOperandEqual == result) {
    result = mAttribute_field.objectCompare (p->mAttribute_field) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_key.objectCompare (p->mAttribute_key) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlVarItemCollection::objectCompare (const GALGAS_gtlVarItemCollection & inOperand) const {
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

GALGAS_gtlVarItemCollection::GALGAS_gtlVarItemCollection (void) :
GALGAS_gtlVarItemField () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemCollection::GALGAS_gtlVarItemCollection (const cPtr_gtlVarItemCollection * inSourcePtr) :
GALGAS_gtlVarItemField (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItemCollection) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemCollection GALGAS_gtlVarItemCollection::constructor_new (const GALGAS_lstring & inAttribute_field,
                                                                          const GALGAS_gtlExpression & inAttribute_key
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemCollection result ;
  if (inAttribute_field.isValid () && inAttribute_key.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarItemCollection (inAttribute_field, inAttribute_key COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlVarItemCollection::getter_key (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlVarItemCollection * p = (const cPtr_gtlVarItemCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemCollection) ;
    result = p->mAttribute_key ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlVarItemCollection::getter_key (UNUSED_LOCATION_ARGS) const {
  return mAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlVarItemCollection class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlVarItemCollection::cPtr_gtlVarItemCollection (const GALGAS_lstring & in_field,
                                                      const GALGAS_gtlExpression & in_key
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlVarItemField (in_field COMMA_THERE),
mAttribute_key (in_key) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlVarItemCollection::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemCollection ;
}

void cPtr_gtlVarItemCollection::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlVarItemCollection:" ;
  mAttribute_field.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_key.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlVarItemCollection::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarItemCollection (mAttribute_field, mAttribute_key COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlVarItemCollection type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItemCollection ("gtlVarItemCollection",
                                             & kTypeDescriptor_GALGAS_gtlVarItemField) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarItemCollection::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemCollection ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarItemCollection::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItemCollection (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemCollection GALGAS_gtlVarItemCollection::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemCollection result ;
  const GALGAS_gtlVarItemCollection * p = (const GALGAS_gtlVarItemCollection *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItemCollection *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItemCollection", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlVarItemSubCollection::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarItemSubCollection * p = (const cPtr_gtlVarItemSubCollection *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
  if (kOperandEqual == result) {
    result = mAttribute_subCollectionlocation.objectCompare (p->mAttribute_subCollectionlocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_key.objectCompare (p->mAttribute_key) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlVarItemSubCollection::objectCompare (const GALGAS_gtlVarItemSubCollection & inOperand) const {
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

GALGAS_gtlVarItemSubCollection::GALGAS_gtlVarItemSubCollection (void) :
GALGAS_gtlVarItem () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemSubCollection::GALGAS_gtlVarItemSubCollection (const cPtr_gtlVarItemSubCollection * inSourcePtr) :
GALGAS_gtlVarItem (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItemSubCollection) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemSubCollection GALGAS_gtlVarItemSubCollection::constructor_new (const GALGAS_location & inAttribute_subCollectionlocation,
                                                                                const GALGAS_gtlExpression & inAttribute_key
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemSubCollection result ;
  if (inAttribute_subCollectionlocation.isValid () && inAttribute_key.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarItemSubCollection (inAttribute_subCollectionlocation, inAttribute_key COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_gtlVarItemSubCollection::getter_subCollectionlocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlVarItemSubCollection * p = (const cPtr_gtlVarItemSubCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
    result = p->mAttribute_subCollectionlocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_gtlVarItemSubCollection::getter_subCollectionlocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_subCollectionlocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlVarItemSubCollection::getter_key (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlVarItemSubCollection * p = (const cPtr_gtlVarItemSubCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
    result = p->mAttribute_key ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlVarItemSubCollection::getter_key (UNUSED_LOCATION_ARGS) const {
  return mAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlVarItemSubCollection class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlVarItemSubCollection::cPtr_gtlVarItemSubCollection (const GALGAS_location & in_subCollectionlocation,
                                                            const GALGAS_gtlExpression & in_key
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlVarItem (THERE),
mAttribute_subCollectionlocation (in_subCollectionlocation),
mAttribute_key (in_key) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlVarItemSubCollection::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemSubCollection ;
}

void cPtr_gtlVarItemSubCollection::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlVarItemSubCollection:" ;
  mAttribute_subCollectionlocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_key.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlVarItemSubCollection::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarItemSubCollection (mAttribute_subCollectionlocation, mAttribute_key COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlVarItemSubCollection type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItemSubCollection ("gtlVarItemSubCollection",
                                                & kTypeDescriptor_GALGAS_gtlVarItem) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarItemSubCollection::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemSubCollection ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarItemSubCollection::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItemSubCollection (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItemSubCollection GALGAS_gtlVarItemSubCollection::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemSubCollection result ;
  const GALGAS_gtlVarItemSubCollection * p = (const GALGAS_gtlVarItemSubCollection *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItemSubCollection *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItemSubCollection", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlExpression location'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlExpression_location> gExtensionGetterTable_gtlExpression_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlExpression_location inGetter) {
  gExtensionGetterTable_gtlExpression_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_gtlExpression * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlExpression) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlExpression_location f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlExpression_location.count ()) {
      f = gExtensionGetterTable_gtlExpression_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlExpression_location.count ()) {
           f = gExtensionGetterTable_gtlExpression_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlExpression_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_location extensionGetter_gtlExpression_location (const cPtr_gtlExpression * inObject,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_result ; // Returned variable
  const cPtr_gtlExpression * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlExpression) ;
  result_result = object->mAttribute_where ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlExpression_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlExpression.mSlotID,
                                 extensionGetter_gtlExpression_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlExpression_location (void) {
  gExtensionGetterTable_gtlExpression_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExpression_location (defineExtensionGetter_gtlExpression_location,
                                                   freeExtensionGetter_gtlExpression_location) ;

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
//                                                                                                                     *
//                                   Abstract extension getter '@gtlExpression eval'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlExpression_eval> gExtensionGetterTable_gtlExpression_eval ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_eval (const int32_t inClassIndex,
                                enterExtensionGetter_gtlExpression_eval inGetter) {
  gExtensionGetterTable_gtlExpression_eval.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlExpression_eval (void) {
  gExtensionGetterTable_gtlExpression_eval.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlExpression_eval (NULL,
                                               freeExtensionGetter_gtlExpression_eval) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_eval (const cPtr_gtlExpression * inObject,
                                         const GALGAS_gtlContext in_context,
                                         const GALGAS_gtlData in_vars,
                                         const GALGAS_library in_lib,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlExpression) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlExpression_eval f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlExpression_eval.count ()) {
      f = gExtensionGetterTable_gtlExpression_eval (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlExpression_eval.count ()) {
           f = gExtensionGetterTable_gtlExpression_eval (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlExpression_eval.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_context, in_vars, in_lib, inCompiler COMMA_THERE) ;
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
//                                                                                                                     *
//                                          Extension Getter '@type typeName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_typeName (const GALGAS_type & inObject,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_typeName ; // Returned variable
  const GALGAS_type temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt))).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_typeName = GALGAS_string ("int") ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_type temp_2 = inObject ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_2.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_typeName = GALGAS_string ("char") ;
    }else if (kBoolFalse == test_3) {
      const GALGAS_type temp_4 = inObject ;
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, temp_4.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_typeName = GALGAS_string ("float") ;
      }else if (kBoolFalse == test_5) {
        const GALGAS_type temp_6 = inObject ;
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, temp_6.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
        if (kBoolTrue == test_7) {
          result_typeName = GALGAS_string ("string") ;
        }else if (kBoolFalse == test_7) {
          const GALGAS_type temp_8 = inObject ;
          const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, temp_8.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool))).boolEnum () ;
          if (kBoolTrue == test_9) {
            result_typeName = GALGAS_string ("bool") ;
          }else if (kBoolFalse == test_9) {
            const GALGAS_type temp_10 = inObject ;
            const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, temp_10.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
            if (kBoolTrue == test_11) {
              result_typeName = GALGAS_string ("struct") ;
            }else if (kBoolFalse == test_11) {
              const GALGAS_type temp_12 = inObject ;
              const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, temp_12.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlList))).boolEnum () ;
              if (kBoolTrue == test_13) {
                result_typeName = GALGAS_string ("list") ;
              }else if (kBoolFalse == test_13) {
                const GALGAS_type temp_14 = inObject ;
                const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, temp_14.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap))).boolEnum () ;
                if (kBoolTrue == test_15) {
                  result_typeName = GALGAS_string ("map") ;
                }else if (kBoolFalse == test_15) {
                  const GALGAS_type temp_16 = inObject ;
                  const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, temp_16.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlType))).boolEnum () ;
                  if (kBoolTrue == test_17) {
                    result_typeName = GALGAS_string ("type") ;
                  }else if (kBoolFalse == test_17) {
                    const GALGAS_type temp_18 = inObject ;
                    const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, temp_18.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum))).boolEnum () ;
                    if (kBoolTrue == test_19) {
                      result_typeName = GALGAS_string ("enum") ;
                    }else if (kBoolFalse == test_19) {
                      const GALGAS_type temp_20 = inObject ;
                      const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, temp_20.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet))).boolEnum () ;
                      if (kBoolTrue == test_21) {
                        result_typeName = GALGAS_string ("set") ;
                      }else if (kBoolFalse == test_21) {
                        const GALGAS_type temp_22 = inObject ;
                        const enumGalgasBool test_23 = GALGAS_bool (kIsEqual, temp_22.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed))).boolEnum () ;
                        if (kBoolTrue == test_23) {
                          result_typeName = GALGAS_string ("unconstructed") ;
                        }else if (kBoolFalse == test_23) {
                          result_typeName = GALGAS_string ("-unknown-") ;
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
  return result_typeName ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension Getter '@lstring gtlType'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type extensionGetter_gtlType (const GALGAS_lstring & inObject,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_type ; // Returned variable
  const GALGAS_lstring temp_0 = inObject ;
  GALGAS_string var_typeName_2294 = temp_0.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 67)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("int"))).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt) ;
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("char"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("float"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_4) {
          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlString) ;
        }else if (kBoolFalse == test_4) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
          if (kBoolTrue == test_5) {
            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool) ;
          }else if (kBoolFalse == test_5) {
            const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
            if (kBoolTrue == test_6) {
              result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct) ;
            }else if (kBoolFalse == test_6) {
              const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("list"))).boolEnum () ;
              if (kBoolTrue == test_7) {
                result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlList) ;
              }else if (kBoolFalse == test_7) {
                const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                if (kBoolTrue == test_8) {
                  result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap) ;
                }else if (kBoolFalse == test_8) {
                  const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlType) ;
                  }else if (kBoolFalse == test_9) {
                    const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                    if (kBoolTrue == test_10) {
                      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum) ;
                    }else if (kBoolFalse == test_10) {
                      const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet) ;
                      }else if (kBoolFalse == test_11) {
                        const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, var_typeName_2294.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed) ;
                        }else if (kBoolFalse == test_12) {
                          TC_Array <C_FixItDescription> fixItArray13 ;
                          inCompiler->emitSemanticError (inObject.mAttribute_location, GALGAS_string ("unknown type"), fixItArray13  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 80)) ;
                          result_type.drop () ; // Release error dropped variable
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
  return result_type ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension getter '@gtlData location'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_location> gExtensionGetterTable_gtlData_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_gtlData_location inGetter) {
  gExtensionGetterTable_gtlData_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_gtlData * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_location f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_location.count ()) {
      f = gExtensionGetterTable_gtlData_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_location.count ()) {
           f = gExtensionGetterTable_gtlData_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_location extensionGetter_gtlData_location (const cPtr_gtlData * inObject,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_result ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  result_result = object->mAttribute_where ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                 extensionGetter_gtlData_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_location (void) {
  gExtensionGetterTable_gtlData_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_location (defineExtensionGetter_gtlData_location,
                                             freeExtensionGetter_gtlData_location) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData desc'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_desc> gExtensionGetterTable_gtlData_desc ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_desc (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_desc inGetter) {
  gExtensionGetterTable_gtlData_desc.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_desc (void) {
  gExtensionGetterTable_gtlData_desc.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_desc (NULL,
                                         freeExtensionGetter_gtlData_desc) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_desc (const cPtr_gtlData * inObject,
                                        const GALGAS_uint in_tab,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_desc f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_desc.count ()) {
      f = gExtensionGetterTable_gtlData_desc (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_desc.count ()) {
           f = gExtensionGetterTable_gtlData_desc (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_desc.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_tab, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData string'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_string> gExtensionGetterTable_gtlData_string ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_string (const int32_t inClassIndex,
                                  enterExtensionGetter_gtlData_string inGetter) {
  gExtensionGetterTable_gtlData_string.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_string (void) {
  gExtensionGetterTable_gtlData_string.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_string (NULL,
                                           freeExtensionGetter_gtlData_string) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_string (const cPtr_gtlData * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_string f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_string.count ()) {
      f = gExtensionGetterTable_gtlData_string (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_string.count ()) {
           f = gExtensionGetterTable_gtlData_string (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_string.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                    Abstract extension getter '@gtlData lstring'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_lstring> gExtensionGetterTable_gtlData_lstring ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_lstring (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlData_lstring inGetter) {
  gExtensionGetterTable_gtlData_lstring.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_lstring (void) {
  gExtensionGetterTable_gtlData_lstring.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_lstring (NULL,
                                            freeExtensionGetter_gtlData_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_lstring (const cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_lstring f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_lstring.count ()) {
      f = gExtensionGetterTable_gtlData_lstring (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_lstring.count ()) {
           f = gExtensionGetterTable_gtlData_lstring (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_lstring.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData bool'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_bool> gExtensionGetterTable_gtlData_bool ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_bool (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_bool inGetter) {
  gExtensionGetterTable_gtlData_bool.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_bool (void) {
  gExtensionGetterTable_gtlData_bool.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_bool (NULL,
                                         freeExtensionGetter_gtlData_bool) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_bool (const cPtr_gtlData * inObject,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_bool f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_bool.count ()) {
      f = gExtensionGetterTable_gtlData_bool (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_bool.count ()) {
           f = gExtensionGetterTable_gtlData_bool (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_bool.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData int'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_int> gExtensionGetterTable_gtlData_int ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_int (const int32_t inClassIndex,
                               enterExtensionGetter_gtlData_int inGetter) {
  gExtensionGetterTable_gtlData_int.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_int (void) {
  gExtensionGetterTable_gtlData_int.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_int (NULL,
                                        freeExtensionGetter_gtlData_int) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint callExtensionGetter_int (const cPtr_gtlData * inObject,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  GALGAS_bigint result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_int f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_int.count ()) {
      f = gExtensionGetterTable_gtlData_int (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_int.count ()) {
           f = gExtensionGetterTable_gtlData_int (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_int.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData float'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_float> gExtensionGetterTable_gtlData_float ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_float (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_float inGetter) {
  gExtensionGetterTable_gtlData_float.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_float (void) {
  gExtensionGetterTable_gtlData_float.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_float (NULL,
                                          freeExtensionGetter_gtlData_float) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double callExtensionGetter_float (const cPtr_gtlData * inObject,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_double result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_float f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_float.count ()) {
      f = gExtensionGetterTable_gtlData_float (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_float.count ()) {
           f = gExtensionGetterTable_gtlData_float (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_float.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData plusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_plusOp> gExtensionGetterTable_gtlData_plusOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_plusOp (const int32_t inClassIndex,
                                  enterExtensionGetter_gtlData_plusOp inGetter) {
  gExtensionGetterTable_gtlData_plusOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_plusOp (void) {
  gExtensionGetterTable_gtlData_plusOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_plusOp (NULL,
                                           freeExtensionGetter_gtlData_plusOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_plusOp (const cPtr_gtlData * inObject,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_plusOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_plusOp.count ()) {
      f = gExtensionGetterTable_gtlData_plusOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_plusOp.count ()) {
           f = gExtensionGetterTable_gtlData_plusOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_plusOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                    Abstract extension getter '@gtlData minusOp'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_minusOp> gExtensionGetterTable_gtlData_minusOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_minusOp (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlData_minusOp inGetter) {
  gExtensionGetterTable_gtlData_minusOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_minusOp (void) {
  gExtensionGetterTable_gtlData_minusOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_minusOp (NULL,
                                            freeExtensionGetter_gtlData_minusOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_minusOp (const cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_minusOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_minusOp.count ()) {
      f = gExtensionGetterTable_gtlData_minusOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_minusOp.count ()) {
           f = gExtensionGetterTable_gtlData_minusOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_minusOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData notOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_notOp> gExtensionGetterTable_gtlData_notOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_notOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_notOp inGetter) {
  gExtensionGetterTable_gtlData_notOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_notOp (void) {
  gExtensionGetterTable_gtlData_notOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_notOp (NULL,
                                          freeExtensionGetter_gtlData_notOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_notOp (const cPtr_gtlData * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_notOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_notOp.count ()) {
      f = gExtensionGetterTable_gtlData_notOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_notOp.count ()) {
           f = gExtensionGetterTable_gtlData_notOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_notOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData addOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_addOp> gExtensionGetterTable_gtlData_addOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_addOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_addOp inGetter) {
  gExtensionGetterTable_gtlData_addOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_addOp (void) {
  gExtensionGetterTable_gtlData_addOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_addOp (NULL,
                                          freeExtensionGetter_gtlData_addOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_addOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_addOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_addOp.count ()) {
      f = gExtensionGetterTable_gtlData_addOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_addOp.count ()) {
           f = gExtensionGetterTable_gtlData_addOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_addOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData subOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_subOp> gExtensionGetterTable_gtlData_subOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_subOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_subOp inGetter) {
  gExtensionGetterTable_gtlData_subOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_subOp (void) {
  gExtensionGetterTable_gtlData_subOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_subOp (NULL,
                                          freeExtensionGetter_gtlData_subOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_subOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_subOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_subOp.count ()) {
      f = gExtensionGetterTable_gtlData_subOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_subOp.count ()) {
           f = gExtensionGetterTable_gtlData_subOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_subOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData mulOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_mulOp> gExtensionGetterTable_gtlData_mulOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_mulOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_mulOp inGetter) {
  gExtensionGetterTable_gtlData_mulOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_mulOp (void) {
  gExtensionGetterTable_gtlData_mulOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_mulOp (NULL,
                                          freeExtensionGetter_gtlData_mulOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_mulOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_mulOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_mulOp.count ()) {
      f = gExtensionGetterTable_gtlData_mulOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_mulOp.count ()) {
           f = gExtensionGetterTable_gtlData_mulOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_mulOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData divOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_divOp> gExtensionGetterTable_gtlData_divOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_divOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_divOp inGetter) {
  gExtensionGetterTable_gtlData_divOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_divOp (void) {
  gExtensionGetterTable_gtlData_divOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_divOp (NULL,
                                          freeExtensionGetter_gtlData_divOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_divOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_divOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_divOp.count ()) {
      f = gExtensionGetterTable_gtlData_divOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_divOp.count ()) {
           f = gExtensionGetterTable_gtlData_divOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_divOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData modOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_modOp> gExtensionGetterTable_gtlData_modOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_modOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_modOp inGetter) {
  gExtensionGetterTable_gtlData_modOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_modOp (void) {
  gExtensionGetterTable_gtlData_modOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_modOp (NULL,
                                          freeExtensionGetter_gtlData_modOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_modOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_modOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_modOp.count ()) {
      f = gExtensionGetterTable_gtlData_modOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_modOp.count ()) {
           f = gExtensionGetterTable_gtlData_modOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_modOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData andOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_andOp> gExtensionGetterTable_gtlData_andOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_andOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_andOp inGetter) {
  gExtensionGetterTable_gtlData_andOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_andOp (void) {
  gExtensionGetterTable_gtlData_andOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_andOp (NULL,
                                          freeExtensionGetter_gtlData_andOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_andOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_andOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_andOp.count ()) {
      f = gExtensionGetterTable_gtlData_andOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_andOp.count ()) {
           f = gExtensionGetterTable_gtlData_andOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_andOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData orOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_orOp> gExtensionGetterTable_gtlData_orOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_orOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_orOp inGetter) {
  gExtensionGetterTable_gtlData_orOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_orOp (void) {
  gExtensionGetterTable_gtlData_orOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_orOp (NULL,
                                         freeExtensionGetter_gtlData_orOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_orOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_orOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_orOp.count ()) {
      f = gExtensionGetterTable_gtlData_orOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_orOp.count ()) {
           f = gExtensionGetterTable_gtlData_orOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_orOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData xorOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_xorOp> gExtensionGetterTable_gtlData_xorOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_xorOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_xorOp inGetter) {
  gExtensionGetterTable_gtlData_xorOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_xorOp (void) {
  gExtensionGetterTable_gtlData_xorOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_xorOp (NULL,
                                          freeExtensionGetter_gtlData_xorOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_xorOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_xorOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_xorOp.count ()) {
      f = gExtensionGetterTable_gtlData_xorOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_xorOp.count ()) {
           f = gExtensionGetterTable_gtlData_xorOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_xorOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData slOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_slOp> gExtensionGetterTable_gtlData_slOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_slOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_slOp inGetter) {
  gExtensionGetterTable_gtlData_slOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_slOp (void) {
  gExtensionGetterTable_gtlData_slOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_slOp (NULL,
                                         freeExtensionGetter_gtlData_slOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_slOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_slOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_slOp.count ()) {
      f = gExtensionGetterTable_gtlData_slOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_slOp.count ()) {
           f = gExtensionGetterTable_gtlData_slOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_slOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData srOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_srOp> gExtensionGetterTable_gtlData_srOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_srOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_srOp inGetter) {
  gExtensionGetterTable_gtlData_srOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_srOp (void) {
  gExtensionGetterTable_gtlData_srOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_srOp (NULL,
                                         freeExtensionGetter_gtlData_srOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_srOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_srOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_srOp.count ()) {
      f = gExtensionGetterTable_gtlData_srOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_srOp.count ()) {
           f = gExtensionGetterTable_gtlData_srOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_srOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Abstract extension getter '@gtlData neqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_neqOp> gExtensionGetterTable_gtlData_neqOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_neqOp (const int32_t inClassIndex,
                                 enterExtensionGetter_gtlData_neqOp inGetter) {
  gExtensionGetterTable_gtlData_neqOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_neqOp (void) {
  gExtensionGetterTable_gtlData_neqOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_neqOp (NULL,
                                          freeExtensionGetter_gtlData_neqOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_neqOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_neqOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_neqOp.count ()) {
      f = gExtensionGetterTable_gtlData_neqOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_neqOp.count ()) {
           f = gExtensionGetterTable_gtlData_neqOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_neqOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData eqOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_eqOp> gExtensionGetterTable_gtlData_eqOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_eqOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_eqOp inGetter) {
  gExtensionGetterTable_gtlData_eqOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_eqOp (void) {
  gExtensionGetterTable_gtlData_eqOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_eqOp (NULL,
                                         freeExtensionGetter_gtlData_eqOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_eqOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_eqOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_eqOp.count ()) {
      f = gExtensionGetterTable_gtlData_eqOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_eqOp.count ()) {
           f = gExtensionGetterTable_gtlData_eqOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_eqOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData ltOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_ltOp> gExtensionGetterTable_gtlData_ltOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_ltOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_ltOp inGetter) {
  gExtensionGetterTable_gtlData_ltOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_ltOp (void) {
  gExtensionGetterTable_gtlData_ltOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_ltOp (NULL,
                                         freeExtensionGetter_gtlData_ltOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_ltOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_ltOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_ltOp.count ()) {
      f = gExtensionGetterTable_gtlData_ltOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_ltOp.count ()) {
           f = gExtensionGetterTable_gtlData_ltOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_ltOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData leOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_leOp> gExtensionGetterTable_gtlData_leOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_leOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_leOp inGetter) {
  gExtensionGetterTable_gtlData_leOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_leOp (void) {
  gExtensionGetterTable_gtlData_leOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_leOp (NULL,
                                         freeExtensionGetter_gtlData_leOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_leOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_leOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_leOp.count ()) {
      f = gExtensionGetterTable_gtlData_leOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_leOp.count ()) {
           f = gExtensionGetterTable_gtlData_leOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_leOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData gtOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_gtOp> gExtensionGetterTable_gtlData_gtOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_gtOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_gtOp inGetter) {
  gExtensionGetterTable_gtlData_gtOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_gtOp (void) {
  gExtensionGetterTable_gtlData_gtOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_gtOp (NULL,
                                         freeExtensionGetter_gtlData_gtOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_gtOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_gtOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_gtOp.count ()) {
      f = gExtensionGetterTable_gtlData_gtOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_gtOp.count ()) {
           f = gExtensionGetterTable_gtlData_gtOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_gtOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Abstract extension getter '@gtlData geOp'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_geOp> gExtensionGetterTable_gtlData_geOp ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_geOp (const int32_t inClassIndex,
                                enterExtensionGetter_gtlData_geOp inGetter) {
  gExtensionGetterTable_gtlData_geOp.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_geOp (void) {
  gExtensionGetterTable_gtlData_geOp.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_geOp (NULL,
                                         freeExtensionGetter_gtlData_geOp) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_geOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_geOp f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_geOp.count ()) {
      f = gExtensionGetterTable_gtlData_geOp (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_geOp.count ()) {
           f = gExtensionGetterTable_gtlData_geOp (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_geOp.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_right, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Abstract extension getter '@gtlData embeddedType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_embeddedType> gExtensionGetterTable_gtlData_embeddedType ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_embeddedType (const int32_t inClassIndex,
                                        enterExtensionGetter_gtlData_embeddedType inGetter) {
  gExtensionGetterTable_gtlData_embeddedType.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_embeddedType (void) {
  gExtensionGetterTable_gtlData_embeddedType.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_embeddedType (NULL,
                                                 freeExtensionGetter_gtlData_embeddedType) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type callExtensionGetter_embeddedType (const cPtr_gtlData * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_type result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_embeddedType f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_embeddedType.count ()) {
      f = gExtensionGetterTable_gtlData_embeddedType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_embeddedType.count ()) {
           f = gExtensionGetterTable_gtlData_embeddedType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_embeddedType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                                                                                                                     *
//                                   Abstract extension method '@gtlData addMyValue'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_addMyValue> gExtensionMethodTable_gtlData_addMyValue ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_addMyValue (const int32_t inClassIndex,
                                      extensionMethodSignature_gtlData_addMyValue inMethod) {
  gExtensionMethodTable_gtlData_addMyValue.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_addMyValue (void) {
  gExtensionMethodTable_gtlData_addMyValue.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_addMyValue (NULL,
                                               freeExtensionMethod_gtlData_addMyValue) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_addMyValue (const cPtr_gtlData * inObject,
                                     GALGAS_objectlist & io_objectList,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_addMyValue f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_addMyValue.count ()) {
      f = gExtensionMethodTable_gtlData_addMyValue (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_gtlData_addMyValue.count ()) {
          f = gExtensionMethodTable_gtlData_addMyValue (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_gtlData_addMyValue.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_objectList, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension getter '@gtlData performGetter'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_performGetter> gExtensionGetterTable_gtlData_performGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_performGetter (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlData_performGetter inGetter) {
  gExtensionGetterTable_gtlData_performGetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_performGetter (void) {
  gExtensionGetterTable_gtlData_performGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_performGetter (NULL,
                                                  freeExtensionGetter_gtlData_performGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_performGetter (const cPtr_gtlData * inObject,
                                                  const GALGAS_lstring in_methodName,
                                                  const GALGAS_gtlDataList in_arguments,
                                                  const GALGAS_gtlContext in_context,
                                                  const GALGAS_library in_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_performGetter f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_performGetter.count ()) {
      f = gExtensionGetterTable_gtlData_performGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_performGetter.count ()) {
           f = gExtensionGetterTable_gtlData_performGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_performGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_methodName, in_arguments, in_context, in_lib, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension setter '@gtlData performSetter'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_performSetter> gExtensionModifierTable_gtlData_performSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_performSetter (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_performSetter inModifier) {
  gExtensionModifierTable_gtlData_performSetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_performSetter (void) {
  gExtensionModifierTable_gtlData_performSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_performSetter (NULL,
                                                  freeExtensionModifier_gtlData_performSetter) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_performSetter (cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_methodName,
                                        const GALGAS_gtlDataList constin_arguments,
                                        const GALGAS_gtlContext constin_context,
                                        const GALGAS_library constin_lib,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_performSetter f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_performSetter.count ()) {
      f = gExtensionModifierTable_gtlData_performSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_performSetter.count ()) {
           f = gExtensionModifierTable_gtlData_performSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_performSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_methodName, constin_arguments, constin_context, constin_lib, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlData structField'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_structField> gExtensionMethodTable_gtlData_structField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_structField (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlData_structField inMethod) {
  gExtensionMethodTable_gtlData_structField.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_structField (const cPtr_gtlData * inObject,
                                      const GALGAS_lstring constin_name,
                                      GALGAS_gtlData & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_structField f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_structField.count ()) {
      f = gExtensionMethodTable_gtlData_structField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_structField.count ()) {
           f = gExtensionMethodTable_gtlData_structField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_structField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_name, out_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlData_structField (const cPtr_gtlData * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & outArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 240)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 240)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 240)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 240)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 240)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 240)) ;
  outArgument_result.drop () ; // Release error dropped variable
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlData_structField (void) {
  enterExtensionMethod_structField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionMethod_gtlData_structField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_structField (void) {
  gExtensionMethodTable_gtlData_structField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_structField (defineExtensionMethod_gtlData_structField,
                                                freeExtensionMethod_gtlData_structField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData resultField'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_resultField> gExtensionGetterTable_gtlData_resultField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_resultField (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlData_resultField inGetter) {
  gExtensionGetterTable_gtlData_resultField.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_resultField (const cPtr_gtlData * inObject,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_resultField f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_resultField.count ()) {
      f = gExtensionGetterTable_gtlData_resultField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_resultField.count ()) {
           f = gExtensionGetterTable_gtlData_resultField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_resultField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlData_resultField (const cPtr_gtlData * inObject,
                                                           const GALGAS_lstring constinArgument_name,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 247)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 247)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 247)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 247)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 247)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 247)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_resultField (void) {
  enterExtensionGetter_resultField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionGetter_gtlData_resultField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_resultField (void) {
  gExtensionGetterTable_gtlData_resultField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_resultField (defineExtensionGetter_gtlData_resultField,
                                                freeExtensionGetter_gtlData_resultField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlData setStructField'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setStructField> gExtensionModifierTable_gtlData_setStructField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setStructField (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setStructField inModifier) {
  gExtensionModifierTable_gtlData_setStructField.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setStructField (cPtr_gtlData * inObject,
                                         const GALGAS_lstring constin_name,
                                         const GALGAS_gtlData constin_data,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setStructField f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setStructField.count ()) {
      f = gExtensionModifierTable_gtlData_setStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setStructField.count ()) {
           f = gExtensionModifierTable_gtlData_setStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setStructField (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    const GALGAS_gtlData /* constinArgument_data */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 255)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 255)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 255)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 255)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setStructField (void) {
  enterExtensionSetter_setStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionSetter_gtlData_setStructField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setStructField (void) {
  gExtensionModifierTable_gtlData_setStructField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setStructField (defineExtensionSetter_gtlData_setStructField,
                                                   freeExtensionModifier_gtlData_setStructField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@gtlData setStructFieldAtLevel'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setStructFieldAtLevel> gExtensionModifierTable_gtlData_setStructFieldAtLevel ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setStructFieldAtLevel (const int32_t inClassIndex,
                                                 extensionSetterSignature_gtlData_setStructFieldAtLevel inModifier) {
  gExtensionModifierTable_gtlData_setStructFieldAtLevel.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                const GALGAS_lstring constin_name,
                                                const GALGAS_gtlData constin_data,
                                                const GALGAS_uint constin_level,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setStructFieldAtLevel f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setStructFieldAtLevel.count ()) {
      f = gExtensionModifierTable_gtlData_setStructFieldAtLevel (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setStructFieldAtLevel.count ()) {
           f = gExtensionModifierTable_gtlData_setStructFieldAtLevel (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setStructFieldAtLevel.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, constin_level, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                           const GALGAS_lstring constinArgument_name,
                                                           const GALGAS_gtlData /* constinArgument_data */,
                                                           const GALGAS_uint /* constinArgument_level */,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 264)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 264)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 264)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 264)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 264)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 264)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setStructFieldAtLevel (void) {
  enterExtensionSetter_setStructFieldAtLevel (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                              extensionSetter_gtlData_setStructFieldAtLevel) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setStructFieldAtLevel (void) {
  gExtensionModifierTable_gtlData_setStructFieldAtLevel.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setStructFieldAtLevel (defineExtensionSetter_gtlData_setStructFieldAtLevel,
                                                          freeExtensionModifier_gtlData_setStructFieldAtLevel) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlData deleteStructField'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteStructField> gExtensionModifierTable_gtlData_deleteStructField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteStructField (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteStructField inModifier) {
  gExtensionModifierTable_gtlData_deleteStructField.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteStructField (cPtr_gtlData * inObject,
                                            const GALGAS_lstring constin_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteStructField f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteStructField.count ()) {
      f = gExtensionModifierTable_gtlData_deleteStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteStructField.count ()) {
           f = gExtensionModifierTable_gtlData_deleteStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_deleteStructField (cPtr_gtlData * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 270)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 270)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 270)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 270)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 270)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 270)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_deleteStructField (void) {
  enterExtensionSetter_deleteStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                          extensionSetter_gtlData_deleteStructField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_deleteStructField (void) {
  gExtensionModifierTable_gtlData_deleteStructField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_deleteStructField (defineExtensionSetter_gtlData_deleteStructField,
                                                      freeExtensionModifier_gtlData_deleteStructField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlData hasStructField'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_hasStructField> gExtensionGetterTable_gtlData_hasStructField ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasStructField (const int32_t inClassIndex,
                                          enterExtensionGetter_gtlData_hasStructField inGetter) {
  gExtensionGetterTable_gtlData_hasStructField.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasStructField (const cPtr_gtlData * inObject,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_hasStructField f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_hasStructField.count ()) {
      f = gExtensionGetterTable_gtlData_hasStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_hasStructField.count ()) {
           f = gExtensionGetterTable_gtlData_hasStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_hasStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlData_hasStructField (const cPtr_gtlData * /* inObject */,
                                                           const GALGAS_lstring /* constinArgument_name */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_hasStructField (void) {
  enterExtensionGetter_hasStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionGetter_gtlData_hasStructField) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_hasStructField (void) {
  gExtensionGetterTable_gtlData_hasStructField.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_hasStructField (defineExtensionGetter_gtlData_hasStructField,
                                                   freeExtensionGetter_gtlData_hasStructField) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData overrideMap'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_overrideMap> gExtensionGetterTable_gtlData_overrideMap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_overrideMap (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlData_overrideMap inGetter) {
  gExtensionGetterTable_gtlData_overrideMap.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct callExtensionGetter_overrideMap (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_overrideMap f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_overrideMap.count ()) {
      f = gExtensionGetterTable_gtlData_overrideMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_overrideMap.count ()) {
           f = gExtensionGetterTable_gtlData_overrideMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_overrideMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_gtlStruct extensionGetter_gtlData_overrideMap (const cPtr_gtlData * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlStruct result_mapOverriden ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 283)), GALGAS_string ("INTERNAL ERROR : a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 283)) ;
  result_mapOverriden.drop () ; // Release error dropped variable
//---
  return result_mapOverriden ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_overrideMap (void) {
  enterExtensionGetter_overrideMap (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionGetter_gtlData_overrideMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_overrideMap (void) {
  gExtensionGetterTable_gtlData_overrideMap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_overrideMap (defineExtensionGetter_gtlData_overrideMap,
                                                freeExtensionGetter_gtlData_overrideMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlData overriddenMap'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_overriddenMap> gExtensionGetterTable_gtlData_overriddenMap ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_overriddenMap (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlData_overriddenMap inGetter) {
  gExtensionGetterTable_gtlData_overriddenMap.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlStruct callExtensionGetter_overriddenMap (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_overriddenMap f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_overriddenMap.count ()) {
      f = gExtensionGetterTable_gtlData_overriddenMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_overriddenMap.count ()) {
           f = gExtensionGetterTable_gtlData_overriddenMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_overriddenMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_gtlStruct extensionGetter_gtlData_overriddenMap (const cPtr_gtlData * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlStruct result_overriddenMap ; // Returned variable
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 289)), GALGAS_string ("INTERNAL ERROR : a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 289)) ;
  result_overriddenMap.drop () ; // Release error dropped variable
//---
  return result_overriddenMap ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_overriddenMap (void) {
  enterExtensionGetter_overriddenMap (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                      extensionGetter_gtlData_overriddenMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_overriddenMap (void) {
  gExtensionGetterTable_gtlData_overriddenMap.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_overriddenMap (defineExtensionGetter_gtlData_overriddenMap,
                                                  freeExtensionGetter_gtlData_overriddenMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Extension method '@gtlData mapItem'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_mapItem> gExtensionMethodTable_gtlData_mapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_mapItem (const int32_t inClassIndex,
                                   extensionMethodSignature_gtlData_mapItem inMethod) {
  gExtensionMethodTable_gtlData_mapItem.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_mapItem (const cPtr_gtlData * inObject,
                                  const GALGAS_lstring constin_name,
                                  GALGAS_gtlData & out_result,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_mapItem f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_mapItem.count ()) {
      f = gExtensionMethodTable_gtlData_mapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_mapItem.count ()) {
           f = gExtensionMethodTable_gtlData_mapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_mapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_name, out_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlData_mapItem (const cPtr_gtlData * inObject,
                                             const GALGAS_lstring constinArgument_name,
                                             GALGAS_gtlData & outArgument_result,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 296)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 296)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 296)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 296)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 296)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 296)) ;
  outArgument_result.drop () ; // Release error dropped variable
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlData_mapItem (void) {
  enterExtensionMethod_mapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                extensionMethod_gtlData_mapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_mapItem (void) {
  gExtensionMethodTable_gtlData_mapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_mapItem (defineExtensionMethod_gtlData_mapItem,
                                            freeExtensionMethod_gtlData_mapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlData hasMapItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_hasMapItem> gExtensionGetterTable_gtlData_hasMapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasMapItem (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlData_hasMapItem inGetter) {
  gExtensionGetterTable_gtlData_hasMapItem.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasMapItem (const cPtr_gtlData * inObject,
                                            const GALGAS_lstring in_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_hasMapItem f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_hasMapItem.count ()) {
      f = gExtensionGetterTable_gtlData_hasMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_hasMapItem.count ()) {
           f = gExtensionGetterTable_gtlData_hasMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_hasMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_name, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlData_hasMapItem (const cPtr_gtlData * /* inObject */,
                                                       const GALGAS_lstring /* constinArgument_name */,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_hasMapItem (void) {
  enterExtensionGetter_hasMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionGetter_gtlData_hasMapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_hasMapItem (void) {
  gExtensionGetterTable_gtlData_hasMapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_hasMapItem (defineExtensionGetter_gtlData_hasMapItem,
                                               freeExtensionGetter_gtlData_hasMapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@gtlData setMapItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setMapItem> gExtensionModifierTable_gtlData_setMapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setMapItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_setMapItem inModifier) {
  gExtensionModifierTable_gtlData_setMapItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setMapItem (cPtr_gtlData * inObject,
                                     const GALGAS_lstring constin_name,
                                     const GALGAS_gtlData constin_data,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setMapItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setMapItem.count ()) {
      f = gExtensionModifierTable_gtlData_setMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setMapItem.count ()) {
           f = gExtensionModifierTable_gtlData_setMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setMapItem (cPtr_gtlData * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                const GALGAS_gtlData /* constinArgument_data */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 310)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 310)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 310)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 310)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 310)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 310)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setMapItem (void) {
  enterExtensionSetter_setMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionSetter_gtlData_setMapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setMapItem (void) {
  gExtensionModifierTable_gtlData_setMapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setMapItem (defineExtensionSetter_gtlData_setMapItem,
                                               freeExtensionModifier_gtlData_setMapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension setter '@gtlData deleteMapItem'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteMapItem> gExtensionModifierTable_gtlData_deleteMapItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteMapItem (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_deleteMapItem inModifier) {
  gExtensionModifierTable_gtlData_deleteMapItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteMapItem (cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_name,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteMapItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteMapItem.count ()) {
      f = gExtensionModifierTable_gtlData_deleteMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteMapItem.count ()) {
           f = gExtensionModifierTable_gtlData_deleteMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_deleteMapItem (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_name,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 316)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 316)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 316)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 316)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 316)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 316)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_deleteMapItem (void) {
  enterExtensionSetter_deleteMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                      extensionSetter_gtlData_deleteMapItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_deleteMapItem (void) {
  gExtensionModifierTable_gtlData_deleteMapItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_deleteMapItem (defineExtensionSetter_gtlData_deleteMapItem,
                                                  freeExtensionModifier_gtlData_deleteMapItem) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension method '@gtlData itemAtIndex'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlData_itemAtIndex> gExtensionMethodTable_gtlData_itemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_itemAtIndex (const int32_t inClassIndex,
                                       extensionMethodSignature_gtlData_itemAtIndex inMethod) {
  gExtensionMethodTable_gtlData_itemAtIndex.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_itemAtIndex (const cPtr_gtlData * inObject,
                                      GALGAS_gtlData & out_result,
                                      const GALGAS_gtlInt constin_index,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlData_itemAtIndex f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlData_itemAtIndex.count ()) {
      f = gExtensionMethodTable_gtlData_itemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlData_itemAtIndex.count ()) {
           f = gExtensionMethodTable_gtlData_itemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlData_itemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_result, constin_index, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlData_itemAtIndex (const cPtr_gtlData * inObject,
                                                 GALGAS_gtlData & outArgument_result,
                                                 const GALGAS_gtlInt constinArgument_index,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInt *) constinArgument_index.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 323)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 323)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 323)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 323)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 323)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 323)) ;
  outArgument_result.drop () ; // Release error dropped variable
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlData_itemAtIndex (void) {
  enterExtensionMethod_itemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                    extensionMethod_gtlData_itemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlData_itemAtIndex (void) {
  gExtensionMethodTable_gtlData_itemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlData_itemAtIndex (defineExtensionMethod_gtlData_itemAtIndex,
                                                freeExtensionMethod_gtlData_itemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlData hasItemAtIndex'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlData_hasItemAtIndex> gExtensionGetterTable_gtlData_hasItemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasItemAtIndex (const int32_t inClassIndex,
                                          enterExtensionGetter_gtlData_hasItemAtIndex inGetter) {
  gExtensionGetterTable_gtlData_hasItemAtIndex.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasItemAtIndex (const cPtr_gtlData * inObject,
                                                const GALGAS_gtlInt in_index,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlData_hasItemAtIndex f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlData_hasItemAtIndex.count ()) {
      f = gExtensionGetterTable_gtlData_hasItemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlData_hasItemAtIndex.count ()) {
           f = gExtensionGetterTable_gtlData_hasItemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlData_hasItemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_index, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlData_hasItemAtIndex (const cPtr_gtlData * /* inObject */,
                                                           const GALGAS_gtlInt /* constinArgument_index */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlData_hasItemAtIndex (void) {
  enterExtensionGetter_hasItemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionGetter_gtlData_hasItemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlData_hasItemAtIndex (void) {
  gExtensionGetterTable_gtlData_hasItemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlData_hasItemAtIndex (defineExtensionGetter_gtlData_hasItemAtIndex,
                                                   freeExtensionGetter_gtlData_hasItemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlData setItemAtIndex'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_setItemAtIndex> gExtensionModifierTable_gtlData_setItemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setItemAtIndex (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setItemAtIndex inModifier) {
  gExtensionModifierTable_gtlData_setItemAtIndex.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setItemAtIndex (cPtr_gtlData * inObject,
                                         const GALGAS_gtlData constin_data,
                                         const GALGAS_gtlInt constin_index,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setItemAtIndex f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setItemAtIndex.count ()) {
      f = gExtensionModifierTable_gtlData_setItemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setItemAtIndex.count ()) {
           f = gExtensionModifierTable_gtlData_setItemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setItemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_data, constin_index, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_setItemAtIndex (cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_data */,
                                                    const GALGAS_gtlInt constinArgument_index,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInt *) constinArgument_index.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 337)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 337)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 337)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 337)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_setItemAtIndex (void) {
  enterExtensionSetter_setItemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionSetter_gtlData_setItemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_setItemAtIndex (void) {
  gExtensionModifierTable_gtlData_setItemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_setItemAtIndex (defineExtensionSetter_gtlData_setItemAtIndex,
                                                   freeExtensionModifier_gtlData_setItemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlData deleteItemAtIndex'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteItemAtIndex> gExtensionModifierTable_gtlData_deleteItemAtIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteItemAtIndex (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteItemAtIndex inModifier) {
  gExtensionModifierTable_gtlData_deleteItemAtIndex.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteItemAtIndex (cPtr_gtlData * inObject,
                                            const GALGAS_gtlInt constin_index,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteItemAtIndex f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteItemAtIndex.count ()) {
      f = gExtensionModifierTable_gtlData_deleteItemAtIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteItemAtIndex.count ()) {
           f = gExtensionModifierTable_gtlData_deleteItemAtIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteItemAtIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_index, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_deleteItemAtIndex (cPtr_gtlData * inObject,
                                                       const GALGAS_gtlInt constinArgument_index,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInt *) constinArgument_index.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 343)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 343)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 343)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 343)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 343)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 343)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_deleteItemAtIndex (void) {
  enterExtensionSetter_deleteItemAtIndex (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                          extensionSetter_gtlData_deleteItemAtIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_deleteItemAtIndex (void) {
  gExtensionModifierTable_gtlData_deleteItemAtIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_deleteItemAtIndex (defineExtensionSetter_gtlData_deleteItemAtIndex,
                                                      freeExtensionModifier_gtlData_deleteItemAtIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension setter '@gtlData appendItem'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlData_appendItem> gExtensionModifierTable_gtlData_appendItem ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_appendItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_appendItem inModifier) {
  gExtensionModifierTable_gtlData_appendItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_appendItem (cPtr_gtlData * inObject,
                                     const GALGAS_gtlData constin_item,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_appendItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_appendItem.count ()) {
      f = gExtensionModifierTable_gtlData_appendItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_appendItem.count ()) {
           f = gExtensionModifierTable_gtlData_appendItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_appendItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_item, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlData_appendItem (cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constinArgument_item,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_item.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 349)), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 349)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 349)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 349)).add_operation (GALGAS_string (" is not a list"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 349)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 349)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlData_appendItem (void) {
  enterExtensionSetter_appendItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionSetter_gtlData_appendItem) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlData_appendItem (void) {
  gExtensionModifierTable_gtlData_appendItem.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlData_appendItem (defineExtensionSetter_gtlData_appendItem,
                                               freeExtensionModifier_gtlData_appendItem) ;

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
//                                                                                                                     *
//                               Extension method '@gtlExecutableEntity checkArguments'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlExecutableEntity_checkArguments> gExtensionMethodTable_gtlExecutableEntity_checkArguments ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_checkArguments (const int32_t inClassIndex,
                                          extensionMethodSignature_gtlExecutableEntity_checkArguments inMethod) {
  gExtensionMethodTable_gtlExecutableEntity_checkArguments.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_checkArguments (const cPtr_gtlExecutableEntity * inObject,
                                         const GALGAS_location constin_fromLocation,
                                         const GALGAS_gtlDataList constin_actualArguments,
                                         GALGAS_gtlData & out_entityVariableMap,
                                         GALGAS_bool & out_result,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  out_entityVariableMap.drop () ;
  out_result.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlExecutableEntity) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlExecutableEntity_checkArguments f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlExecutableEntity_checkArguments.count ()) {
      f = gExtensionMethodTable_gtlExecutableEntity_checkArguments (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlExecutableEntity_checkArguments.count ()) {
           f = gExtensionMethodTable_gtlExecutableEntity_checkArguments (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlExecutableEntity_checkArguments.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_fromLocation, constin_actualArguments, out_entityVariableMap, out_result, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlExecutableEntity_checkArguments (const cPtr_gtlExecutableEntity * inObject,
                                                                const GALGAS_location constinArgument_fromLocation,
                                                                const GALGAS_gtlDataList constinArgument_actualArguments,
                                                                GALGAS_gtlData & outArgument_entityVariableMap,
                                                                GALGAS_bool & outArgument_result,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlExecutableEntity * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlExecutableEntity) ;
  outArgument_result = GALGAS_bool (true) ;
  outArgument_entityVariableMap = GALGAS_gtlStruct::constructor_new (constinArgument_fromLocation, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 52)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_module.galgas", 53))  COMMA_SOURCE_FILE ("gtl_module.galgas", 50)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_formalArguments.getter_length (SOURCE_FILE ("gtl_module.galgas", 56)).objectCompare (constinArgument_actualArguments.getter_length (SOURCE_FILE ("gtl_module.galgas", 56)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlExecutableEntity temp_1 = object ;
    GALGAS_string temp_2 ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, temp_1.getter_dynamicType (SOURCE_FILE ("gtl_module.galgas", 58)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlProcedure))).boolEnum () ;
    if (kBoolTrue == test_3) {
      temp_2 = GALGAS_string ("procedure '") ;
    }else if (kBoolFalse == test_3) {
      temp_2 = GALGAS_string ("function '") ;
    }
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("calling ").add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 57)).add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("gtl_module.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 62)).add_operation (GALGAS_string ("' needs "), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 63)).add_operation (object->mAttribute_formalArguments.getter_length (SOURCE_FILE ("gtl_module.galgas", 63)).getter_string (SOURCE_FILE ("gtl_module.galgas", 63)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 63)).add_operation (GALGAS_string (" arguments"), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 63)), fixItArray4  COMMA_SOURCE_FILE ("gtl_module.galgas", 57)) ;
  }else if (kBoolFalse == test_0) {
    cEnumerator_gtlArgumentList enumerator_1631 (object->mAttribute_formalArguments, kEnumeration_up) ;
    cEnumerator_gtlDataList enumerator_1654 (constinArgument_actualArguments, kEnumeration_up) ;
    while (enumerator_1631.hasCurrentObject () && enumerator_1654.hasCurrentObject ()) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, enumerator_1654.current_data (HERE).getter_dynamicType (SOURCE_FILE ("gtl_module.galgas", 67)).objectCompare (enumerator_1631.current_type (HERE))).operator_and (enumerator_1631.current_typed (HERE) COMMA_SOURCE_FILE ("gtl_module.galgas", 67)).boolEnum () ;
      if (kBoolTrue == test_5) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) enumerator_1654.current_data (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)), extensionGetter_typeName (enumerator_1631.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)).add_operation (GALGAS_string (" expected for "), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)).add_operation (enumerator_1631.current_name (HERE).getter_string (SOURCE_FILE ("gtl_module.galgas", 68)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 68)), fixItArray6  COMMA_SOURCE_FILE ("gtl_module.galgas", 68)) ;
        outArgument_result = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_5) {
        {
        outArgument_entityVariableMap.insulate (HERE) ;
        cPtr_gtlData * ptr_1843 = (cPtr_gtlData *) outArgument_entityVariableMap.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1843, enumerator_1631.current_name (HERE), enumerator_1654.current_data (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 71)) ;
        }
      }
      enumerator_1631.gotoNextObject () ;
      enumerator_1654.gotoNextObject () ;
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlExecutableEntity_checkArguments (void) {
  enterExtensionMethod_checkArguments (kTypeDescriptor_GALGAS_gtlExecutableEntity.mSlotID,
                                       extensionMethod_gtlExecutableEntity_checkArguments) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlExecutableEntity_checkArguments (void) {
  gExtensionMethodTable_gtlExecutableEntity_checkArguments.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlExecutableEntity_checkArguments (defineExtensionMethod_gtlExecutableEntity_checkArguments,
                                                               freeExtensionMethod_gtlExecutableEntity_checkArguments) ;

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
//                                                                                                                     *
//                                        Extension method '@gtlProcedure call'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlProcedure_call> gExtensionMethodTable_gtlProcedure_call ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_call (const int32_t inClassIndex,
                                extensionMethodSignature_gtlProcedure_call inMethod) {
  gExtensionMethodTable_gtlProcedure_call.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_call (const cPtr_gtlProcedure * inObject,
                               GALGAS_gtlContext & io_context,
                               GALGAS_library & io_lib,
                               GALGAS_string & io_outputString,
                               const GALGAS_location constin_fromLocation,
                               const GALGAS_gtlDataList constin_actualArguments,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlProcedure) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlProcedure_call f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlProcedure_call.count ()) {
      f = gExtensionMethodTable_gtlProcedure_call (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlProcedure_call.count ()) {
           f = gExtensionMethodTable_gtlProcedure_call (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlProcedure_call.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_context, io_lib, io_outputString, constin_fromLocation, constin_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlProcedure_call (const cPtr_gtlProcedure * inObject,
                                               GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_library & ioArgument_lib,
                                               GALGAS_string & ioArgument_outputString,
                                               const GALGAS_location constinArgument_fromLocation,
                                               const GALGAS_gtlDataList constinArgument_actualArguments,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlProcedure * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlProcedure) ;
  GALGAS_gtlData var_vars_2288 ;
  GALGAS_bool var_ok_2298 ;
  const GALGAS_gtlProcedure temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlProcedure *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_vars_2288, var_ok_2298, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 89)) ;
  const enumGalgasBool test_1 = var_ok_2298.boolEnum () ;
  if (kBoolTrue == test_1) {
    extensionMethod_execute (object->mAttribute_instructions, ioArgument_context, var_vars_2288, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 92)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("procedure call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 94)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlProcedure_call (void) {
  enterExtensionMethod_call (kTypeDescriptor_GALGAS_gtlProcedure.mSlotID,
                             extensionMethod_gtlProcedure_call) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlProcedure_call (void) {
  gExtensionMethodTable_gtlProcedure_call.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlProcedure_call (defineExtensionMethod_gtlProcedure_call,
                                              freeExtensionMethod_gtlProcedure_call) ;

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
//                                                                                                                     *
//                                        Extension getter '@gtlFunction call'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlFunction_call> gExtensionGetterTable_gtlFunction_call ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_call (const int32_t inClassIndex,
                                enterExtensionGetter_gtlFunction_call inGetter) {
  gExtensionGetterTable_gtlFunction_call.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_call (const cPtr_gtlFunction * inObject,
                                         const GALGAS_location in_fromLocation,
                                         GALGAS_gtlContext in_context,
                                         GALGAS_library in_lib,
                                         const GALGAS_gtlDataList in_actualArguments,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlFunction) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlFunction_call f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlFunction_call.count ()) {
      f = gExtensionGetterTable_gtlFunction_call (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlFunction_call.count ()) {
           f = gExtensionGetterTable_gtlFunction_call (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlFunction_call.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_fromLocation, in_context, in_lib, in_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlFunction_call (const cPtr_gtlFunction * inObject,
                                                        const GALGAS_location constinArgument_fromLocation,
                                                        GALGAS_gtlContext inArgument_context,
                                                        GALGAS_library inArgument_lib,
                                                        const GALGAS_gtlDataList constinArgument_actualArguments,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFunction * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlFunction) ;
  GALGAS_gtlData var_funcVariableMap_2854 ;
  GALGAS_bool var_ok_2864 ;
  const GALGAS_gtlFunction temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlFunction *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_funcVariableMap_2854, var_ok_2864, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 111)) ;
  {
  var_funcVariableMap_2854.insulate (HERE) ;
  cPtr_gtlData * ptr_2886 = (cPtr_gtlData *) var_funcVariableMap_2854.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2886, object->mAttribute_returnVariable, GALGAS_gtlUnconstructed::constructor_new (object->mAttribute_returnVariable.getter_location (SOURCE_FILE ("gtl_module.galgas", 115)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 115))  COMMA_SOURCE_FILE ("gtl_module.galgas", 115)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 113)) ;
  }
  const enumGalgasBool test_1 = var_ok_2864.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_string var_outputString_3036 = GALGAS_string::makeEmptyString () ;
    extensionMethod_execute (object->mAttribute_instructions, inArgument_context, var_funcVariableMap_2854, inArgument_lib, var_outputString_3036, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 119)) ;
    result_result = callExtensionGetter_resultField ((const cPtr_gtlData *) var_funcVariableMap_2854.ptr (), object->mAttribute_returnVariable, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 120)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("function call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 122)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlFunction_call (void) {
  enterExtensionGetter_call (kTypeDescriptor_GALGAS_gtlFunction.mSlotID,
                             extensionGetter_gtlFunction_call) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlFunction_call (void) {
  gExtensionGetterTable_gtlFunction_call.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlFunction_call (defineExtensionGetter_gtlFunction_call,
                                             freeExtensionGetter_gtlFunction_call) ;

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
//                                                                                                                     *
//                                      Extension getter '@gtlGetter callGetter'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlGetter_callGetter> gExtensionGetterTable_gtlGetter_callGetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_callGetter (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlGetter_callGetter inGetter) {
  gExtensionGetterTable_gtlGetter_callGetter.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_callGetter (const cPtr_gtlGetter * inObject,
                                               const GALGAS_location in_fromLocation,
                                               GALGAS_gtlContext in_context,
                                               GALGAS_library in_lib,
                                               const GALGAS_gtlData in_target,
                                               const GALGAS_gtlDataList in_actualArguments,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlGetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlGetter_callGetter f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlGetter_callGetter.count ()) {
      f = gExtensionGetterTable_gtlGetter_callGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlGetter_callGetter.count ()) {
           f = gExtensionGetterTable_gtlGetter_callGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlGetter_callGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_fromLocation, in_context, in_lib, in_target, in_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_gtlGetter_callGetter (const cPtr_gtlGetter * inObject,
                                                            const GALGAS_location constinArgument_fromLocation,
                                                            GALGAS_gtlContext inArgument_context,
                                                            GALGAS_library inArgument_lib,
                                                            const GALGAS_gtlData constinArgument_target,
                                                            const GALGAS_gtlDataList constinArgument_actualArguments,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlGetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlGetter) ;
  GALGAS_gtlData var_getterVariableMap_3682 ;
  GALGAS_bool var_ok_3692 ;
  const GALGAS_gtlGetter temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlGetter *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_getterVariableMap_3682, var_ok_3692, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 140)) ;
  {
  var_getterVariableMap_3682.insulate (HERE) ;
  cPtr_gtlData * ptr_3716 = (cPtr_gtlData *) var_getterVariableMap_3682.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3716, object->mAttribute_returnVariable, GALGAS_gtlUnconstructed::constructor_new (object->mAttribute_returnVariable.getter_location (SOURCE_FILE ("gtl_module.galgas", 144)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 144))  COMMA_SOURCE_FILE ("gtl_module.galgas", 144)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 142)) ;
  }
  const enumGalgasBool test_1 = var_ok_3692.boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    var_getterVariableMap_3682.insulate (HERE) ;
    cPtr_gtlData * ptr_3866 = (cPtr_gtlData *) var_getterVariableMap_3682.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3866, GALGAS_lstring::constructor_new (GALGAS_string ("self"), constinArgument_fromLocation  COMMA_SOURCE_FILE ("gtl_module.galgas", 148)), constinArgument_target, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 147)) ;
    }
    GALGAS_string var_outputString_3964 = GALGAS_string::makeEmptyString () ;
    extensionMethod_execute (object->mAttribute_instructions, inArgument_context, var_getterVariableMap_3682, inArgument_lib, var_outputString_3964, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 152)) ;
    result_result = callExtensionGetter_resultField ((const cPtr_gtlData *) var_getterVariableMap_3682.ptr (), object->mAttribute_returnVariable, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 153)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("getter call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 155)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGetter_callGetter (void) {
  enterExtensionGetter_callGetter (kTypeDescriptor_GALGAS_gtlGetter.mSlotID,
                                   extensionGetter_gtlGetter_callGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlGetter_callGetter (void) {
  gExtensionGetterTable_gtlGetter_callGetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGetter_callGetter (defineExtensionGetter_gtlGetter_callGetter,
                                                 freeExtensionGetter_gtlGetter_callGetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlGetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlGetter_typedName> gExtensionGetterTable_gtlGetter_typedName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlGetter_typedName inGetter) {
  gExtensionGetterTable_gtlGetter_typedName.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlGetter * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlGetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlGetter_typedName f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlGetter_typedName.count ()) {
      f = gExtensionGetterTable_gtlGetter_typedName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlGetter_typedName.count ()) {
           f = gExtensionGetterTable_gtlGetter_typedName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlGetter_typedName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_lstring extensionGetter_gtlGetter_typedName (const cPtr_gtlGetter * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlGetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlGetter) ;
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (object->mAttribute_targetType, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 162)).add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("gtl_module.galgas", 162)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 162)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_module.galgas", 162)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlGetter_typedName (void) {
  enterExtensionGetter_typedName (kTypeDescriptor_GALGAS_gtlGetter.mSlotID,
                                  extensionGetter_gtlGetter_typedName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlGetter_typedName (void) {
  gExtensionGetterTable_gtlGetter_typedName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlGetter_typedName (defineExtensionGetter_gtlGetter_typedName,
                                                freeExtensionGetter_gtlGetter_typedName) ;

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
//                                                                                                                     *
//                                      Extension method '@gtlSetter callSetter'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlSetter_callSetter> gExtensionMethodTable_gtlSetter_callSetter ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_callSetter (const int32_t inClassIndex,
                                      extensionMethodSignature_gtlSetter_callSetter inMethod) {
  gExtensionMethodTable_gtlSetter_callSetter.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_callSetter (const cPtr_gtlSetter * inObject,
                                     const GALGAS_location constin_fromLocation,
                                     GALGAS_gtlContext in_context,
                                     GALGAS_library in_lib,
                                     GALGAS_gtlData & io_target,
                                     const GALGAS_gtlDataList constin_actualArguments,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlSetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlSetter_callSetter f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlSetter_callSetter.count ()) {
      f = gExtensionMethodTable_gtlSetter_callSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlSetter_callSetter.count ()) {
           f = gExtensionMethodTable_gtlSetter_callSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlSetter_callSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_fromLocation, in_context, in_lib, io_target, constin_actualArguments, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlSetter_callSetter (const cPtr_gtlSetter * inObject,
                                                  const GALGAS_location constinArgument_fromLocation,
                                                  GALGAS_gtlContext inArgument_context,
                                                  GALGAS_library inArgument_lib,
                                                  GALGAS_gtlData & ioArgument_target,
                                                  const GALGAS_gtlDataList constinArgument_actualArguments,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlSetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlSetter) ;
  GALGAS_gtlData var_setterVariableMap_4709 ;
  GALGAS_bool var_ok_4719 ;
  const GALGAS_gtlSetter temp_0 = object ;
  callExtensionMethod_checkArguments ((const cPtr_gtlSetter *) temp_0.ptr (), constinArgument_fromLocation, constinArgument_actualArguments, var_setterVariableMap_4709, var_ok_4719, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 178)) ;
  const enumGalgasBool test_1 = var_ok_4719.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_selfName_4759 = GALGAS_lstring::constructor_new (GALGAS_string ("self"), constinArgument_fromLocation  COMMA_SOURCE_FILE ("gtl_module.galgas", 181)) ;
    {
    var_setterVariableMap_4709.insulate (HERE) ;
    cPtr_gtlData * ptr_4817 = (cPtr_gtlData *) var_setterVariableMap_4709.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4817, var_selfName_4759, ioArgument_target, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 182)) ;
    }
    GALGAS_string var_outputString_4893 = GALGAS_string::makeEmptyString () ;
    extensionMethod_execute (object->mAttribute_instructions, inArgument_context, var_setterVariableMap_4709, inArgument_lib, var_outputString_4893, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 187)) ;
    callExtensionMethod_structField ((const cPtr_gtlData *) var_setterVariableMap_4709.ptr (), var_selfName_4759, ioArgument_target, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 188)) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_fromLocation, GALGAS_string ("setter call failed"), fixItArray2  COMMA_SOURCE_FILE ("gtl_module.galgas", 190)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlSetter_callSetter (void) {
  enterExtensionMethod_callSetter (kTypeDescriptor_GALGAS_gtlSetter.mSlotID,
                                   extensionMethod_gtlSetter_callSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlSetter_callSetter (void) {
  gExtensionMethodTable_gtlSetter_callSetter.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlSetter_callSetter (defineExtensionMethod_gtlSetter_callSetter,
                                                 freeExtensionMethod_gtlSetter_callSetter) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlSetter typedName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlSetter_typedName> gExtensionGetterTable_gtlSetter_typedName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_typedName (const int32_t inClassIndex,
                                     enterExtensionGetter_gtlSetter_typedName inGetter) {
  gExtensionGetterTable_gtlSetter_typedName.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_typedName (const cPtr_gtlSetter * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlSetter) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlSetter_typedName f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlSetter_typedName.count ()) {
      f = gExtensionGetterTable_gtlSetter_typedName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlSetter_typedName.count ()) {
           f = gExtensionGetterTable_gtlSetter_typedName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlSetter_typedName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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

static GALGAS_lstring extensionGetter_gtlSetter_typedName (const cPtr_gtlSetter * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlSetter * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlSetter) ;
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (object->mAttribute_targetType, inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 197)).add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("gtl_module.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("gtl_module.galgas", 197)), object->mAttribute_where  COMMA_SOURCE_FILE ("gtl_module.galgas", 197)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlSetter_typedName (void) {
  enterExtensionGetter_typedName (kTypeDescriptor_GALGAS_gtlSetter.mSlotID,
                                  extensionGetter_gtlSetter_typedName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlSetter_typedName (void) {
  gExtensionGetterTable_gtlSetter_typedName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlSetter_typedName (defineExtensionGetter_gtlSetter_typedName,
                                                freeExtensionGetter_gtlSetter_typedName) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlModule::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlModule * p = (const cPtr_gtlModule *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlModule) ;
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_procedures.objectCompare (p->mAttribute_procedures) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_functions.objectCompare (p->mAttribute_functions) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlModule::objectCompare (const GALGAS_gtlModule & inOperand) const {
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

GALGAS_gtlModule::GALGAS_gtlModule (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModule GALGAS_gtlModule::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlModule::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_gtlProcMap::constructor_emptyMap (HERE),
                                            GALGAS_gtlFuncMap::constructor_emptyMap (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModule::GALGAS_gtlModule (const cPtr_gtlModule * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlModule) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModule GALGAS_gtlModule::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                    const GALGAS_gtlProcMap & inAttribute_procedures,
                                                    const GALGAS_gtlFuncMap & inAttribute_functions
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlModule result ;
  if (inAttribute_name.isValid () && inAttribute_procedures.isValid () && inAttribute_functions.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlModule (inAttribute_name, inAttribute_procedures, inAttribute_functions COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlModule::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlModule * p = (const cPtr_gtlModule *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlModule) ;
    result = p->mAttribute_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlModule::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlModule::getter_procedures (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlProcMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlModule * p = (const cPtr_gtlModule *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlModule) ;
    result = p->mAttribute_procedures ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap cPtr_gtlModule::getter_procedures (UNUSED_LOCATION_ARGS) const {
  return mAttribute_procedures ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlModule::getter_functions (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlFuncMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlModule * p = (const cPtr_gtlModule *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlModule) ;
    result = p->mAttribute_functions ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap cPtr_gtlModule::getter_functions (UNUSED_LOCATION_ARGS) const {
  return mAttribute_functions ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlModule class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlModule::cPtr_gtlModule (const GALGAS_lstring & in_name,
                                const GALGAS_gtlProcMap & in_procedures,
                                const GALGAS_gtlFuncMap & in_functions
                                COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_name (in_name),
mAttribute_procedures (in_procedures),
mAttribute_functions (in_functions) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlModule::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlModule ;
}

void cPtr_gtlModule::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlModule:" ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_procedures.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_functions.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlModule::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlModule (mAttribute_name, mAttribute_procedures, mAttribute_functions COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlModule type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlModule ("gtlModule",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlModule::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlModule ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlModule::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlModule (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlModule GALGAS_gtlModule::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlModule result ;
  const GALGAS_gtlModule * p = (const GALGAS_gtlModule *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlModule *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlModule", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_gtlAssignInstruction::objectCompare (const GALGAS_gtlAssignInstruction & inOperand) const {
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

GALGAS_gtlAssignInstruction::GALGAS_gtlAssignInstruction (void) :
GALGAS_gtlLetUnconstructedInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAssignInstruction::GALGAS_gtlAssignInstruction (const cPtr_gtlAssignInstruction * inSourcePtr) :
GALGAS_gtlLetUnconstructedInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAssignInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlAssignInstruction::getter_rValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlAssignInstruction * p = (const cPtr_gtlAssignInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlAssignInstruction) ;
    result = p->mAttribute_rValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cPtr_gtlAssignInstruction::getter_rValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_rValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlAssignInstruction class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlAssignInstruction::cPtr_gtlAssignInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlVarPath & in_lValue,
                                                      const GALGAS_gtlExpression & in_rValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlLetUnconstructedInstruction (in_where, in_signature, in_lValue COMMA_THERE),
mAttribute_rValue (in_rValue) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlAssignInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAssignInstruction ("gtlAssignInstruction",
                                             & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlAssignInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAssignInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlAssignInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAssignInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlAssignInstruction GALGAS_gtlAssignInstruction::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlAssignInstruction result ;
  const GALGAS_gtlAssignInstruction * p = (const GALGAS_gtlAssignInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAssignInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAssignInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetInstruction * p = (const cPtr_gtlLetInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetInstruction::objectCompare (const GALGAS_gtlLetInstruction & inOperand) const {
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

GALGAS_gtlLetInstruction::GALGAS_gtlLetInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetInstruction::GALGAS_gtlLetInstruction (const cPtr_gtlLetInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetInstruction GALGAS_gtlLetInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                    const GALGAS_string & inAttribute_signature,
                                                                    const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                    const GALGAS_gtlExpression & inAttribute_rValue
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @gtlLetInstruction class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetInstruction::cPtr_gtlLetInstruction (const GALGAS_location & in_where,
                                                const GALGAS_string & in_signature,
                                                const GALGAS_gtlVarPath & in_lValue,
                                                const GALGAS_gtlExpression & in_rValue
                                                COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetInstruction ;
}

void cPtr_gtlLetInstruction::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@gtlLetInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlLetInstruction type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetInstruction ("gtlLetInstruction",
                                          & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetInstruction GALGAS_gtlLetInstruction::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetInstruction result ;
  const GALGAS_gtlLetInstruction * p = (const GALGAS_gtlLetInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetAddInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetAddInstruction * p = (const cPtr_gtlLetAddInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetAddInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetAddInstruction::objectCompare (const GALGAS_gtlLetAddInstruction & inOperand) const {
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

GALGAS_gtlLetAddInstruction::GALGAS_gtlLetAddInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetAddInstruction::GALGAS_gtlLetAddInstruction (const cPtr_gtlLetAddInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetAddInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetAddInstruction GALGAS_gtlLetAddInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_string & inAttribute_signature,
                                                                          const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                          const GALGAS_gtlExpression & inAttribute_rValue
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetAddInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetAddInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @gtlLetAddInstruction class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetAddInstruction::cPtr_gtlLetAddInstruction (const GALGAS_location & in_where,
                                                      const GALGAS_string & in_signature,
                                                      const GALGAS_gtlVarPath & in_lValue,
                                                      const GALGAS_gtlExpression & in_rValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetAddInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetAddInstruction ;
}

void cPtr_gtlLetAddInstruction::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlLetAddInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetAddInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetAddInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlLetAddInstruction type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetAddInstruction ("gtlLetAddInstruction",
                                             & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetAddInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetAddInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetAddInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetAddInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetAddInstruction GALGAS_gtlLetAddInstruction::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetAddInstruction result ;
  const GALGAS_gtlLetAddInstruction * p = (const GALGAS_gtlLetAddInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetAddInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetAddInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetSubstractInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetSubstractInstruction * p = (const cPtr_gtlLetSubstractInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetSubstractInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetSubstractInstruction::objectCompare (const GALGAS_gtlLetSubstractInstruction & inOperand) const {
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

GALGAS_gtlLetSubstractInstruction::GALGAS_gtlLetSubstractInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetSubstractInstruction::GALGAS_gtlLetSubstractInstruction (const cPtr_gtlLetSubstractInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetSubstractInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetSubstractInstruction GALGAS_gtlLetSubstractInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_string & inAttribute_signature,
                                                                                      const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                                      const GALGAS_gtlExpression & inAttribute_rValue
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetSubstractInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetSubstractInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlLetSubstractInstruction class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetSubstractInstruction::cPtr_gtlLetSubstractInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlVarPath & in_lValue,
                                                                  const GALGAS_gtlExpression & in_rValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetSubstractInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetSubstractInstruction ;
}

void cPtr_gtlLetSubstractInstruction::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlLetSubstractInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetSubstractInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetSubstractInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @gtlLetSubstractInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetSubstractInstruction ("gtlLetSubstractInstruction",
                                                   & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetSubstractInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetSubstractInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetSubstractInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetSubstractInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetSubstractInstruction GALGAS_gtlLetSubstractInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetSubstractInstruction result ;
  const GALGAS_gtlLetSubstractInstruction * p = (const GALGAS_gtlLetSubstractInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetSubstractInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetSubstractInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetMultiplyInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetMultiplyInstruction * p = (const cPtr_gtlLetMultiplyInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetMultiplyInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetMultiplyInstruction::objectCompare (const GALGAS_gtlLetMultiplyInstruction & inOperand) const {
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

GALGAS_gtlLetMultiplyInstruction::GALGAS_gtlLetMultiplyInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetMultiplyInstruction::GALGAS_gtlLetMultiplyInstruction (const cPtr_gtlLetMultiplyInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetMultiplyInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetMultiplyInstruction GALGAS_gtlLetMultiplyInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                    const GALGAS_string & inAttribute_signature,
                                                                                    const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                                    const GALGAS_gtlExpression & inAttribute_rValue
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetMultiplyInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetMultiplyInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @gtlLetMultiplyInstruction class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetMultiplyInstruction::cPtr_gtlLetMultiplyInstruction (const GALGAS_location & in_where,
                                                                const GALGAS_string & in_signature,
                                                                const GALGAS_gtlVarPath & in_lValue,
                                                                const GALGAS_gtlExpression & in_rValue
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetMultiplyInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction ;
}

void cPtr_gtlLetMultiplyInstruction::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlLetMultiplyInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetMultiplyInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetMultiplyInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlLetMultiplyInstruction type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction ("gtlLetMultiplyInstruction",
                                                  & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetMultiplyInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetMultiplyInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetMultiplyInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetMultiplyInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetMultiplyInstruction GALGAS_gtlLetMultiplyInstruction::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetMultiplyInstruction result ;
  const GALGAS_gtlLetMultiplyInstruction * p = (const GALGAS_gtlLetMultiplyInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetMultiplyInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetMultiplyInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetDivideInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetDivideInstruction * p = (const cPtr_gtlLetDivideInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetDivideInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetDivideInstruction::objectCompare (const GALGAS_gtlLetDivideInstruction & inOperand) const {
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

GALGAS_gtlLetDivideInstruction::GALGAS_gtlLetDivideInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetDivideInstruction::GALGAS_gtlLetDivideInstruction (const cPtr_gtlLetDivideInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetDivideInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetDivideInstruction GALGAS_gtlLetDivideInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_string & inAttribute_signature,
                                                                                const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                                const GALGAS_gtlExpression & inAttribute_rValue
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetDivideInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetDivideInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlLetDivideInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetDivideInstruction::cPtr_gtlLetDivideInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_gtlVarPath & in_lValue,
                                                            const GALGAS_gtlExpression & in_rValue
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetDivideInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetDivideInstruction ;
}

void cPtr_gtlLetDivideInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLetDivideInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetDivideInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetDivideInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlLetDivideInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetDivideInstruction ("gtlLetDivideInstruction",
                                                & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetDivideInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetDivideInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetDivideInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetDivideInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetDivideInstruction GALGAS_gtlLetDivideInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetDivideInstruction result ;
  const GALGAS_gtlLetDivideInstruction * p = (const GALGAS_gtlLetDivideInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetDivideInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetDivideInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlLetModuloInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetModuloInstruction * p = (const cPtr_gtlLetModuloInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetModuloInstruction) ;
  if (kOperandEqual == result) {
    result = mAttribute_where.objectCompare (p->mAttribute_where) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_signature.objectCompare (p->mAttribute_signature) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_lValue.objectCompare (p->mAttribute_lValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_rValue.objectCompare (p->mAttribute_rValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlLetModuloInstruction::objectCompare (const GALGAS_gtlLetModuloInstruction & inOperand) const {
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

GALGAS_gtlLetModuloInstruction::GALGAS_gtlLetModuloInstruction (void) :
GALGAS_gtlAssignInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetModuloInstruction::GALGAS_gtlLetModuloInstruction (const cPtr_gtlLetModuloInstruction * inSourcePtr) :
GALGAS_gtlAssignInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetModuloInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetModuloInstruction GALGAS_gtlLetModuloInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_string & inAttribute_signature,
                                                                                const GALGAS_gtlVarPath & inAttribute_lValue,
                                                                                const GALGAS_gtlExpression & inAttribute_rValue
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetModuloInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_lValue.isValid () && inAttribute_rValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLetModuloInstruction (inAttribute_where, inAttribute_signature, inAttribute_lValue, inAttribute_rValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @gtlLetModuloInstruction class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlLetModuloInstruction::cPtr_gtlLetModuloInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_gtlVarPath & in_lValue,
                                                            const GALGAS_gtlExpression & in_rValue
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlAssignInstruction (in_where, in_signature, in_lValue, in_rValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlLetModuloInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetModuloInstruction ;
}

void cPtr_gtlLetModuloInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLetModuloInstruction:" ;
  mAttribute_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_lValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_rValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlLetModuloInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLetModuloInstruction (mAttribute_where, mAttribute_signature, mAttribute_lValue, mAttribute_rValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlLetModuloInstruction type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetModuloInstruction ("gtlLetModuloInstruction",
                                                & kTypeDescriptor_GALGAS_gtlAssignInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlLetModuloInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetModuloInstruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlLetModuloInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetModuloInstruction (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlLetModuloInstruction GALGAS_gtlLetModuloInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetModuloInstruction result ;
  const GALGAS_gtlLetModuloInstruction * p = (const GALGAS_gtlLetModuloInstruction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLetModuloInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetModuloInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}


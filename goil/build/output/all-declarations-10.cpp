#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-10.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@impAutoDefaultType verifyType'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impAutoDefaultType_verifyType (const cPtr_impType * inObject,
                                                           const GALGAS_object_5F_t constinArgument_attr,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_string (SOURCE_FILE ("semantic_verification.galgas", 167)))).operator_and (GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 167)))) COMMA_SOURCE_FILE ("semantic_verification.galgas", 167)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 168)), GALGAS_string ("string of identifier expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 168)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 171)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 172)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("*** @impAutoDefaultType ***\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 176)) ;
      constinArgument_attr.log ("attr"  COMMA_SOURCE_FILE ("semantic_verification.galgas", 177)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 178)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impAutoDefaultType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                   extensionMethod_impAutoDefaultType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impAutoDefaultType_verifyType (defineExtensionMethod_impAutoDefaultType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@impRangedType verifyType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impRangedType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 188)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 189)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 192)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 193)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 196)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 197)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)), fixItArray5  COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      const enumGalgasBool test_6 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 200)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 201)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)), fixItArray7  COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("semantic_verification.galgas", 204)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 205)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)), fixItArray9  COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
      const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, object->mAttribute_withAuto.objectCompare (GALGAS_bool (false))).boolEnum () ;
      if (kBoolTrue == test_10) {
        TC_Array <C_FixItDescription> fixItArray11 ;
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 209)), GALGAS_string ("AUTO is not allowed for ").add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("semantic_verification.galgas", 209)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)), fixItArray11  COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray12 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 213)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)), fixItArray12  COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impRangedType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                   extensionMethod_impRangedType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impRangedType_verifyType (defineExtensionMethod_impRangedType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'attributeAllowsAuto'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_allowsAuto ; // Returned variable
  result_allowsAuto = GALGAS_bool (true) ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6562_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      const enumGalgasBool test_0 = cast_6562_autoType.getter_withAuto (SOURCE_FILE ("semantic_verification.galgas", 225)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_allowsAuto = GALGAS_bool (false) ;
      }
    }else{
      result_allowsAuto = GALGAS_bool (false) ;
    }
  }
//---
  return result_allowsAuto ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeAllowsAuto (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_impType operand0 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_attributeAllowsAuto (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'verifyAllAttributes'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAllAttributes (const GALGAS_implementation constinArgument_imp,
                                  const GALGAS_objectsMap constinArgument_objects,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectsMap enumerator_6874 (constinArgument_objects, kEnumeration_up) ;
  while (enumerator_6874.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj_6910 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 242)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7042 (enumerator_6874.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("semantic_verification.galgas", 244)), kEnumeration_up) ;
    while (enumerator_7042.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7087 (var_impObj_6910.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 245)), kEnumeration_up) ;
      while (enumerator_7087.hasCurrentObject ()) {
        const enumGalgasBool test_0 = enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 246)).getter_hasKey (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 246)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_value_7288 ;
          enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 250)).method_get (enumerator_7087.current_lkey (HERE), var_value_7288, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
          if (var_value_7288.isValid ()) {
            if (var_value_7288.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
              const enumGalgasBool test_1 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
              if (kBoolTrue == test_1) {
                TC_Array <C_FixItDescription> fixItArray2 ;
                inCompiler->emitSemanticError (var_value_7288.getter_location (SOURCE_FILE ("semantic_verification.galgas", 255)), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
              }
            }
          }
        }else if (kBoolFalse == test_0) {
          const enumGalgasBool test_3 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7087.current_type (HERE).getter_multiple (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_7042.current_lkey (HERE).getter_location (SOURCE_FILE ("semantic_verification.galgas", 261)), GALGAS_string ("In ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7042.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
          }
        }
        if (enumerator_7087.current_type (HERE).isValid ()) {
          if (enumerator_7087.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7087.gotoNextObject () ;
      }
      enumerator_7042.gotoNextObject () ;
    }
    enumerator_6874.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@multipleAttribute verifyCrossReferences'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_multipleAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                     const GALGAS_objectsMap constinArgument_allObjects,
                                                                     const GALGAS_impType constinArgument_type,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  cEnumerator_identifierList enumerator_19027 (object->mAttribute_items, kEnumeration_up) ;
  while (enumerator_19027.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_object_5F_t *) enumerator_19027.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19027.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_multipleAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                              extensionMethod_multipleAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_multipleAttribute_verifyCrossReferences (defineExtensionMethod_multipleAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@boolAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_boolAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  GALGAS_impBoolType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impBoolType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 625)) ;
    }
  }
  GALGAS_impBoolType var_boolType_19222 = temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_trueSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 627)) ;
  }else if (kBoolFalse == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_falseSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 629)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 629)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_boolAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                              extensionMethod_boolAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_boolAttribute_verifyCrossReferences (defineExtensionMethod_boolAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@enumAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  GALGAS_impEnumType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impEnumType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 637)) ;
    }
  }
  GALGAS_impEnumType var_enumType_19578 = temp_0 ;
  GALGAS_lstring var_key_19620 = GALGAS_lstring::constructor_new (object->mAttribute_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19729 ;
  var_enumType_19578.getter_valuesMap (SOURCE_FILE ("semantic_verification.galgas", 639)).method_get (var_key_19620, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                              extensionMethod_enumAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumAttribute_verifyCrossReferences (defineExtensionMethod_enumAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@structAttribute verifyCrossReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                   const GALGAS_objectsMap constinArgument_allObjects,
                                                                   const GALGAS_impType constinArgument_type,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_impStructType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impStructType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impStructType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 647)) ;
    }
  }
  GALGAS_impStructType var_structType_19943 = temp_0 ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_structType_19943.getter_structAttributes (SOURCE_FILE ("semantic_verification.galgas", 648)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 648)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                              extensionMethod_structAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structAttribute_verifyCrossReferences (defineExtensionMethod_structAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@objectRefAttribute verifyCrossReferences'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectRefAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                      const GALGAS_objectsMap constinArgument_allObjects,
                                                                      const GALGAS_impType constinArgument_type,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  GALGAS_refType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_refType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("refType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 655)) ;
    }
  }
  GALGAS_refType var_refType_20190 = temp_0 ;
  GALGAS_objectKind var_kindMap_20313 ;
  constinArgument_allObjects.method_get (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 657)), var_kindMap_20313, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 657)) ;
  const enumGalgasBool test_1 = var_kindMap_20313.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 658)).getter_hasKey (object->mAttribute_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 658)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 658)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 658)).boolEnum () ;
  if (kBoolTrue == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (object->mAttribute_value.getter_location (SOURCE_FILE ("semantic_verification.galgas", 659)), GALGAS_string ("Referenced ").add_operation (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 659)).getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (object->mAttribute_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectRefAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                                              extensionMethod_objectRefAttribute_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectRefAttribute_verifyCrossReferences (defineExtensionMethod_objectRefAttribute_verifyCrossReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'verifyAll'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAll (const GALGAS_implementation constinArgument_imp,
                        const GALGAS_applicationDefinition constinArgument_application,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes (constinArgument_imp, constinArgument_application.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 681)), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callExtensionMethod_verifyApplication ((const cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'emptyApplicationDefinition'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition function_emptyApplicationDefinition (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'osObject'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_os ; // Returned variable
  GALGAS_objectKind var_objectsForKind_1623 ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind_1623, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names_1696 = var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 68)).getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name_1749 ;
  var_names_1696.method_first (var_name_1749, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 71)).method_get (var_name_1749, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_osObject (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_osObject (operand0,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'objectForKindAndName'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_object ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 79)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_objectKind var_kindObj_1998 ;
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj_1998, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
    const enumGalgasBool test_1 = var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 82)).getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 83)).method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
    }else if (kBoolFalse == test_1) {
      result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
    }
  }else if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectForKindAndName (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectForKindAndName (operand0,
                                        operand1,
                                        operand2,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'setObjectForKindAndName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setObjectForKindAndName (GALGAS_objectsMap & ioArgument_objects,
                                      const GALGAS_string constinArgument_kind,
                                      const GALGAS_string constinArgument_name,
                                      const GALGAS_objectAttributes constinArgument_object,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind_2457 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2495 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2538 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.setter_del (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
    }
  }
  GALGAS_objectKindMap var_kindMap_2686 = var_kindObj_2538.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 103)) ;
  const enumGalgasBool test_1 = var_kindMap_2686.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_objectAttributes joker_2767 ; // Joker input parameter
    var_kindMap_2686.setter_del (var_lname_2495, joker_2767, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
    }
  }
  {
  var_kindMap_2686.setter_put (var_lname_2495, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj_2538.setter_setObjects (var_kindMap_2686 COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.setter_put (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
  }
}


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
      GALGAS_gtlContext var_context_24214 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 758)) ;
      {
      var_context_24214.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 759)) ;
      }
      {
      var_context_24214.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 762)) ;
      }
      {
      var_context_24214.insulate (HERE) ;
      cPtr_gtlContext * ptr_24430 = (cPtr_gtlContext *) var_context_24214.ptr () ;
      callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_24430, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 766)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 765)) ;
      }
      {
      var_context_24214.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 769)) ;
      }
      GALGAS_library var_lib_24658 = function_emptyLib (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 773)) ;
      GALGAS_string var_goilLog_24701 = function_invokeGTL (GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 776)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 777)), GALGAS_string (gOption_goil_5F_options_root.getter_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 775)), var_context_24214, inArgument_cfg, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 774)) ;
      const enumGalgasBool test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_goilLog_24701.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 792)) ;
      }
    }else if (kBoolFalse == test_1) {
      inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 812)) ;
    }
  }else if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 815)) ;
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
  return "3.0.6" ;
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


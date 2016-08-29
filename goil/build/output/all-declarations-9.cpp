#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-9.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@noRange enclose'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_noRange_enclose (const cPtr_attributeRange * /* inObject */,
                                             GALGAS_bool & outArgument_isWithin,
                                             const GALGAS_attributeRange /* constinArgument_value */,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_noRange_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_noRange.mSlotID,
                                extensionMethod_noRange_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_noRange_enclose (defineExtensionMethod_noRange_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@uint32AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeSet * object = (const cPtr_uint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_4277_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_33__32_List enumerator_4315 (cast_4277_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 155)), kEnumeration_up) ;
      while (enumerator_4315.hasCurrentObject ()) {
        GALGAS_bool var_ok_4333 = GALGAS_bool (false) ;
        cEnumerator_uint_33__32_List enumerator_4374 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_4374.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4315.current_value (HERE).objectCompare (enumerator_4374.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_4333 = GALGAS_bool (true) ;
          }
          enumerator_4374.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_4333 COMMA_SOURCE_FILE ("implementation_types.galgas", 162)) ;
        enumerator_4315.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 165)), GALGAS_string ("Incompatible set. Should be a UINT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 165)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 166)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeSet.mSlotID,
                                extensionMethod_uint_33__32_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32_AttributeSet_enclose (defineExtensionMethod_uint_33__32_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@uint64AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeSet * object = (const cPtr_uint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_4888_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_36__34_List enumerator_4926 (cast_4888_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 179)), kEnumeration_up) ;
      while (enumerator_4926.hasCurrentObject ()) {
        GALGAS_bool var_ok_4944 = GALGAS_bool (false) ;
        cEnumerator_uint_36__34_List enumerator_4985 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_4985.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4926.current_value (HERE).objectCompare (enumerator_4985.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_4944 = GALGAS_bool (true) ;
          }
          enumerator_4985.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_4944 COMMA_SOURCE_FILE ("implementation_types.galgas", 186)) ;
        enumerator_4926.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 189)), GALGAS_string ("Incompatible set. Should be a UINT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 189)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 190)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeSet.mSlotID,
                                extensionMethod_uint_36__34_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34_AttributeSet_enclose (defineExtensionMethod_uint_36__34_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@sint32AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeSet * object = (const cPtr_sint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_5499_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_33__32_List enumerator_5537 (cast_5499_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 203)), kEnumeration_up) ;
      while (enumerator_5537.hasCurrentObject ()) {
        GALGAS_bool var_ok_5555 = GALGAS_bool (false) ;
        cEnumerator_sint_33__32_List enumerator_5596 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_5596.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_5537.current_value (HERE).objectCompare (enumerator_5596.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_5555 = GALGAS_bool (true) ;
          }
          enumerator_5596.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5555 COMMA_SOURCE_FILE ("implementation_types.galgas", 210)) ;
        enumerator_5537.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 213)), GALGAS_string ("Incompatible set. Should be a INT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 213)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 214)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeSet.mSlotID,
                                extensionMethod_sint_33__32_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32_AttributeSet_enclose (defineExtensionMethod_sint_33__32_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@sint64AttributeSet enclose'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeSet * object = (const cPtr_sint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_6109_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_36__34_List enumerator_6147 (cast_6109_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 227)), kEnumeration_up) ;
      while (enumerator_6147.hasCurrentObject ()) {
        GALGAS_bool var_ok_6165 = GALGAS_bool (false) ;
        cEnumerator_sint_36__34_List enumerator_6206 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_6206.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6147.current_value (HERE).objectCompare (enumerator_6206.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6165 = GALGAS_bool (true) ;
          }
          enumerator_6206.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6165 COMMA_SOURCE_FILE ("implementation_types.galgas", 234)) ;
        enumerator_6147.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 237)), GALGAS_string ("Incompatible set. Should be a INT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 237)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 238)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeSet.mSlotID,
                                extensionMethod_sint_36__34_AttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34_AttributeSet_enclose (defineExtensionMethod_sint_36__34_AttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension method '@floatAttributeSet enclose'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_floatAttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                       GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeSet * object = (const cPtr_floatAttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_6717_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_floatList enumerator_6755 (cast_6717_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 251)), kEnumeration_up) ;
      while (enumerator_6755.hasCurrentObject ()) {
        GALGAS_bool var_ok_6773 = GALGAS_bool (false) ;
        cEnumerator_floatList enumerator_6814 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_6814.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6755.current_value (HERE).objectCompare (enumerator_6814.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6773 = GALGAS_bool (true) ;
          }
          enumerator_6814.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6773 COMMA_SOURCE_FILE ("implementation_types.galgas", 258)) ;
        enumerator_6755.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 261)), GALGAS_string ("Incompatible set. Should be a FLOAT set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 261)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 262)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_floatAttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeSet.mSlotID,
                                extensionMethod_floatAttributeSet_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_floatAttributeSet_enclose (defineExtensionMethod_floatAttributeSet_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@uint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeMinMax * object = (const cPtr_uint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax) {
      GALGAS_uint_33__32_AttributeMinMax cast_7340_minmax ((cPtr_uint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_7340_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 276)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_7340_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 276)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 276)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_7460_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_33__32_List enumerator_7513 (cast_7460_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 281)), kEnumeration_up) ;
      while (enumerator_7513.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_7513.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_7513.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 282)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_7513.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 287)), GALGAS_string ("Incompatible set. Should be a UINT32 range or UINT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 287)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 288)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_uint_33__32_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32_AttributeMinMax_enclose (defineExtensionMethod_uint_33__32_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@uint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeMinMax * object = (const cPtr_uint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax) {
      GALGAS_uint_36__34_AttributeMinMax cast_7999_minmax ((cPtr_uint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_7999_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 301)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_7999_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 301)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 301)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_8119_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_8172 (cast_8119_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 306)), kEnumeration_up) ;
      while (enumerator_8172.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8172.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8172.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 307)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8172.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 312)), GALGAS_string ("Incompatible set. Should be a UINT64 range or UINT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 312)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 313)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_uint_36__34_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34_AttributeMinMax_enclose (defineExtensionMethod_uint_36__34_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@sint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeMinMax * object = (const cPtr_sint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax) {
      GALGAS_sint_33__32_AttributeMinMax cast_8654_minmax ((cPtr_sint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_8654_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 326)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8654_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 326)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 326)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_8774_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_8827 (cast_8774_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 331)), kEnumeration_up) ;
      while (enumerator_8827.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8827.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8827.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 332)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8827.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 337)), GALGAS_string ("Incompatible set. Should be a INT32 range or INT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 337)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 338)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_sint_33__32_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32_AttributeMinMax_enclose (defineExtensionMethod_sint_33__32_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension method '@sint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeMinMax * object = (const cPtr_sint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax) {
      GALGAS_sint_36__34_AttributeMinMax cast_9311_minmax ((cPtr_sint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9311_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 351)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9311_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 351)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 351)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_9431_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_9484 (cast_9431_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 356)), kEnumeration_up) ;
      while (enumerator_9484.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_9484.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_9484.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 357)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_9484.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 362)), GALGAS_string ("Incompatible set. Should be a INT64 range or INT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 362)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 363)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_sint_36__34_AttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34_AttributeMinMax_enclose (defineExtensionMethod_sint_36__34_AttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension method '@floatAttributeMinMax enclose'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_floatAttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                          GALGAS_bool & outArgument_isWithin,
                                                          const GALGAS_attributeRange constinArgument_value,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeMinMax * object = (const cPtr_floatAttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeMinMax) {
      GALGAS_floatAttributeMinMax cast_9966_minmax ((cPtr_floatAttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9966_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 376)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9966_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 376)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 376)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_10085_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_10138 (cast_10085_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 381)), kEnumeration_up) ;
      while (enumerator_10138.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_10138.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10138.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 382)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_10138.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 387)), GALGAS_string ("Incompatible set. Should be a FLOAT range or FLOAT set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 387)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 388)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_floatAttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeMinMax.mSlotID,
                                extensionMethod_floatAttributeMinMax_enclose) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_floatAttributeMinMax_enclose (defineExtensionMethod_floatAttributeMinMax_enclose, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@impStructType mergeWithType'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impStructType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  GALGAS_impStructType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impStructType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impStructType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 441)) ;
    }
  }
  GALGAS_impStructType var_castTypeToMerge_12022 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedAttributes_12098 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 442)) ;
  cEnumerator_implementationObjectMap enumerator_12139 (object->mAttribute_structAttributes, kEnumeration_up) ;
  while (enumerator_12139.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_12166 = enumerator_12139.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_12022.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 445)).getter_hasKey (enumerator_12139.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 445)) COMMA_SOURCE_FILE ("implementation_types.galgas", 445)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_12321 ;
      var_castTypeToMerge_12022.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 446)).method_get (enumerator_12139.current_lkey (HERE), var_subTypeToMerge_12321, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 446)) ;
      var_mergedAttr_12166 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_12139.current_type (HERE).ptr (), var_subTypeToMerge_12321, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 447)) ;
    }
    {
    var_mergedAttributes_12098.setter_put (enumerator_12139.current_lkey (HERE), var_mergedAttr_12166, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 449)) ;
    }
    enumerator_12139.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impStructType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 452)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 452)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 456)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 456)), var_mergedAttributes_12098  COMMA_SOURCE_FILE ("implementation_types.galgas", 451)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impStructType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                      extensionGetter_impStructType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impStructType_mergeWithType (defineExtensionGetter_impStructType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@impVoid mergeWithType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impVoid_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType /* inArgument_typeToMerge */,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impVoid * object = (const cPtr_impVoid *) inObject ;
  macroValidSharedObject (object, cPtr_impVoid) ;
  const GALGAS_impVoid temp_0 = object ;
  result_mergedType = temp_0 ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impVoid_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impVoid.mSlotID,
                                      extensionGetter_impVoid_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impVoid_mergeWithType (defineExtensionGetter_impVoid_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@impAutoDefaultType mergeWithType'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impAutoDefaultType_mergeWithType (const cPtr_impType * inObject,
                                                                        GALGAS_impType /* inArgument_typeToMerge */,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  const GALGAS_impAutoDefaultType temp_0 = object ;
  result_mergedType = temp_0 ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                      extensionGetter_impAutoDefaultType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_mergeWithType (defineExtensionGetter_impAutoDefaultType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@impAutoDefaultType autoAllowed'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_impAutoDefaultType_autoAllowed (const cPtr_impType * inObject,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  result_result = object->mAttribute_withAuto ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impAutoDefaultType_autoAllowed (void) {
  enterExtensionGetter_autoAllowed (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                    extensionGetter_impAutoDefaultType_autoAllowed) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impAutoDefaultType_autoAllowed (defineExtensionGetter_impAutoDefaultType_autoAllowed, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension getter '@refType mergeWithType'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_refType_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType inArgument_typeToMerge,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  GALGAS_refType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_refType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("refType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 520)) ;
    }
  }
  GALGAS_refType var_castTypeToMerge_13962 = temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 521)).objectCompare (var_castTypeToMerge_13962.getter_ref (SOURCE_FILE ("implementation_types.galgas", 521)).getter_string (SOURCE_FILE ("implementation_types.galgas", 521)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    object->mAttribute_ref.log ("ref"  COMMA_SOURCE_FILE ("implementation_types.galgas", 522)) ;
    GALGAS_lstring var_csatRef_14078 = var_castTypeToMerge_13962.getter_ref (SOURCE_FILE ("implementation_types.galgas", 523)) ;
    var_csatRef_14078.log ("csatRef"  COMMA_SOURCE_FILE ("implementation_types.galgas", 524)) ;
    {
    routine_multiError (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 525)), GALGAS_string ("Redefinition of ").add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 525)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 525)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 525)) ;
    }
    {
    routine_multiError (object->mAttribute_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 526)) ;
    }
  }
  result_mergedType = GALGAS_refType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 529)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 529)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 533)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 533)), object->mAttribute_ref  COMMA_SOURCE_FILE ("implementation_types.galgas", 528)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_refType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                      extensionGetter_refType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_refType_mergeWithType (defineExtensionGetter_refType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@impRangedType mergeWithType'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impRangedType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  GALGAS_impRangedType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impRangedType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impRangedType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impRangedType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 576)) ;
    }
  }
  GALGAS_impRangedType var_castTypeToMerge_15328 = temp_0 ;
  const GALGAS_impRangedType temp_1 = object ;
  const enumGalgasBool test_2 = function_checkRanged (temp_1, var_castTypeToMerge_15328, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 577)).boolEnum () ;
  if (kBoolTrue == test_2) {
    result_mergedType = inArgument_typeToMerge ;
  }else if (kBoolFalse == test_2) {
    const GALGAS_impRangedType temp_3 = object ;
    result_mergedType = temp_3 ;
  }
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impRangedType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                      extensionGetter_impRangedType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impRangedType_mergeWithType (defineExtensionGetter_impRangedType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@impBoolType mergeWithType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impBoolType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  GALGAS_impBoolType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impBoolType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 593)) ;
    }
  }
  GALGAS_impBoolType var_castTypeToMerge_15734 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedTrueAttributes_15812 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 594)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_15873 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 595)) ;
  cEnumerator_implementationObjectMap enumerator_15915 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
  while (enumerator_15915.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_15942 = enumerator_15915.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_15734.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 598)).getter_hasKey (enumerator_15915.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 598)) COMMA_SOURCE_FILE ("implementation_types.galgas", 598)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_16099 ;
      var_castTypeToMerge_15734.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 599)).method_get (enumerator_15915.current_lkey (HERE), var_subTypeToMerge_16099, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 599)) ;
      var_mergedAttr_15942 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_15915.current_type (HERE).ptr (), var_subTypeToMerge_16099, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 600)) ;
    }
    {
    var_mergedTrueAttributes_15812.setter_put (enumerator_15915.current_lkey (HERE), var_mergedAttr_15942, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 602)) ;
    }
    enumerator_15915.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16308 (var_castTypeToMerge_15734.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 605)), kEnumeration_up) ;
  while (enumerator_16308.hasCurrentObject ()) {
    const enumGalgasBool test_2 = object->mAttribute_trueSubAttributes.getter_hasKey (enumerator_16308.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 606)) COMMA_SOURCE_FILE ("implementation_types.galgas", 606)).operator_not (SOURCE_FILE ("implementation_types.galgas", 606)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_mergedTrueAttributes_15812.setter_put (enumerator_16308.current_lkey (HERE), enumerator_16308.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 607)) ;
      }
    }
    enumerator_16308.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16464 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
  while (enumerator_16464.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_16491 = enumerator_16464.current_type (HERE) ;
    const enumGalgasBool test_3 = var_castTypeToMerge_15734.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 613)).getter_hasKey (enumerator_16464.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 613)) COMMA_SOURCE_FILE ("implementation_types.galgas", 613)).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_impType var_subTypeToMerge_16650 ;
      var_castTypeToMerge_15734.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 614)).method_get (enumerator_16464.current_lkey (HERE), var_subTypeToMerge_16650, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 614)) ;
      var_mergedAttr_16491 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_16464.current_type (HERE).ptr (), var_subTypeToMerge_16650, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 615)) ;
    }
    {
    var_mergedFalseAttributes_15873.setter_put (enumerator_16464.current_lkey (HERE), var_mergedAttr_16491, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 617)) ;
    }
    enumerator_16464.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16861 (var_castTypeToMerge_15734.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 620)), kEnumeration_up) ;
  while (enumerator_16861.hasCurrentObject ()) {
    const enumGalgasBool test_4 = object->mAttribute_falseSubAttributes.getter_hasKey (enumerator_16861.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 621)) COMMA_SOURCE_FILE ("implementation_types.galgas", 621)).operator_not (SOURCE_FILE ("implementation_types.galgas", 621)).boolEnum () ;
    if (kBoolTrue == test_4) {
      {
      var_mergedTrueAttributes_15812.setter_put (enumerator_16861.current_lkey (HERE), enumerator_16861.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 622)) ;
      }
    }
    enumerator_16861.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impBoolType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 627)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 631)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 631)), object->mAttribute_withAuto, object->mAttribute_defaultValue, var_mergedTrueAttributes_15812, var_mergedFalseAttributes_15873  COMMA_SOURCE_FILE ("implementation_types.galgas", 626)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impBoolType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                      extensionGetter_impBoolType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impBoolType_mergeWithType (defineExtensionGetter_impBoolType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impBoolType setDefault'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_setDefault (const cPtr_impAutoDefaultType * inObject,
                                                    GALGAS_objectAttributes & ioArgument_attributes,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (object->mAttribute_defaultValue.isValid ()) {
    if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
    }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_17451_b ((cPtr_boolAttribute *) object->mAttribute_defaultValue.ptr ()) ;
      const enumGalgasBool test_0 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 647)).getter_hasKey (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 647)) COMMA_SOURCE_FILE ("implementation_types.galgas", 647)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_identifierMap var_userAttributes_17727 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 650)) ;
        GALGAS_object_5F_t var_value_17779 ;
        var_userAttributes_17727.method_get (object->mAttribute_name, var_value_17779, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 652)) ;
        if (var_value_17779.isValid ()) {
          if (var_value_17779.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
            GALGAS_boolAttribute cast_17881_boolValue ((cPtr_boolAttribute *) var_value_17779.ptr ()) ;
            GALGAS_implementationObjectMap var_subImpAttributes_17935 ;
            const enumGalgasBool test_1 = cast_17881_boolValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 656)).boolEnum () ;
            if (kBoolTrue == test_1) {
              var_subImpAttributes_17935 = object->mAttribute_trueSubAttributes ;
            }else if (kBoolFalse == test_1) {
              var_subImpAttributes_17935 = object->mAttribute_falseSubAttributes ;
            }
            GALGAS_objectAttributes var_subAttributes_18141 = cast_17881_boolValue.getter_subAttributes (SOURCE_FILE ("implementation_types.galgas", 661)) ;
            {
            routine_setDefaultsForType (var_subImpAttributes_17935, var_subAttributes_18141, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 662)) ;
            }
            GALGAS_boolAttribute var_bv_18296 = cast_17881_boolValue ;
            {
            var_bv_18296.setter_setSubAttributes (var_subAttributes_18141 COMMA_SOURCE_FILE ("implementation_types.galgas", 665)) ;
            }
            {
            var_userAttributes_17727.setter_setValueForKey (var_bv_18296, object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 666)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 666)) ;
            }
            {
            ioArgument_attributes.setter_setObjectParams (var_userAttributes_17727 COMMA_SOURCE_FILE ("implementation_types.galgas", 667)) ;
            }
          }
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_implementationObjectMap var_subImpAttributes_18555 ;
        const enumGalgasBool test_2 = cast_17451_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 671)).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_subImpAttributes_18555 = object->mAttribute_trueSubAttributes ;
        }else if (kBoolFalse == test_2) {
          var_subImpAttributes_18555 = object->mAttribute_falseSubAttributes ;
        }
        GALGAS_objectAttributes var_subAttributes_18741 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 676)) ;
        {
        routine_setDefaultsForType (var_subImpAttributes_18555, var_subAttributes_18741, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 677)) ;
        }
        GALGAS_boolAttribute var_defaults_18853 = GALGAS_boolAttribute::constructor_new (cast_17451_b.getter_oil_5F_desc (SOURCE_FILE ("implementation_types.galgas", 678)), cast_17451_b.getter_location (SOURCE_FILE ("implementation_types.galgas", 678)), cast_17451_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 678)), var_subAttributes_18741  COMMA_SOURCE_FILE ("implementation_types.galgas", 678)) ;
        GALGAS_identifierMap var_attr_18960 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 679)) ;
        {
        var_attr_18960.setter_put (object->mAttribute_name, var_defaults_18853, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 680)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_18960 COMMA_SOURCE_FILE ("implementation_types.galgas", 681)) ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_setDefault (void) {
  enterExtensionMethod_setDefault (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_setDefault) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_setDefault (defineExtensionMethod_impBoolType_setDefault, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Overriding extension getter '@impEnumType mergeWithType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_impType extensionGetter_impEnumType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  GALGAS_impEnumType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impEnumType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
    }
  }
  GALGAS_impEnumType var_castTypeToMerge_19902 = temp_0 ;
  result_mergedType = GALGAS_impEnumType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 718)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 718)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 722)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 722)), object->mAttribute_withAuto, object->mAttribute_defaultValue, extensionGetter_mergeWithEnum (object->mAttribute_valuesMap, var_castTypeToMerge_19902.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 725)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 725))  COMMA_SOURCE_FILE ("implementation_types.galgas", 717)) ;
//---
  return result_mergedType ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_impEnumType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                      extensionGetter_impEnumType_mergeWithType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_impEnumType_mergeWithType (defineExtensionGetter_impEnumType_mergeWithType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@refType checkAttributeReferences'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_refType_checkAttributeReferences (const cPtr_impType * inObject,
                                                              const GALGAS_implementation constinArgument_imp,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) constinArgument_imp.ptr (), object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 943)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 943)).operator_not (SOURCE_FILE ("implementation_types.galgas", 943)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mAttribute_ref.getter_location (SOURCE_FILE ("implementation_types.galgas", 944)), object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 944)).add_operation (GALGAS_string (" object kind does not exist"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 944)), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 944)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_refType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_refType.mSlotID,
                                                 extensionMethod_refType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_refType_checkAttributeReferences (defineExtensionMethod_refType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@impBoolType checkAttributeReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  cEnumerator_implementationObjectMap enumerator_27488 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
  while (enumerator_27488.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27488.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
    enumerator_27488.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_27571 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
  while (enumerator_27571.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27571.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
    enumerator_27571.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                                 extensionMethod_impBoolType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_checkAttributeReferences (defineExtensionMethod_impBoolType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@impEnumType checkAttributeReferences'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impEnumType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  cEnumerator_enumValues enumerator_27731 (object->mAttribute_valuesMap, kEnumeration_up) ;
  while (enumerator_27731.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_27763 (enumerator_27731.current_subAttributes (HERE), kEnumeration_up) ;
    while (enumerator_27763.hasCurrentObject ()) {
      callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27763.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
      enumerator_27763.gotoNextObject () ;
    }
    enumerator_27731.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impEnumType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                                 extensionMethod_impEnumType_checkAttributeReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impEnumType_checkAttributeReferences (defineExtensionMethod_impEnumType_checkAttributeReferences, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@structAttribute set'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_gtlData var_subAttrs_935 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  var_subAttrs_935.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_976 = (cPtr_gtlData *) var_subAttrs_935.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_976, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), object->mAttribute_structName.getter_location (SOURCE_FILE ("systemConfig.galgas", 35))  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)), GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_structName.getter_string (SOURCE_FILE ("systemConfig.galgas", 36))  COMMA_SOURCE_FILE ("systemConfig.galgas", 36)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
  }
  {
  var_subAttrs_935.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 38)) ;
  }
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_1129 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1129, constinArgument_name, var_subAttrs_935, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 39)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                            extensionMethod_structAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structAttribute_set (defineExtensionMethod_structAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@boolAttribute set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_boolAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_gtlData & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_1575 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1575, constinArgument_name, GALGAS_gtlBool::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
  }
  GALGAS_gtlData var_subAttrs_1662 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 53)) ;
  GALGAS_gtlStruct temp_0 ;
  if (var_subAttrs_1662.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_1662.ptr ())) {
      temp_0 = (cPtr_gtlStruct *) var_subAttrs_1662.ptr () ;
    }else{
      inCompiler->castError ("gtlStruct", var_subAttrs_1662.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 54)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 54)).getter_count (SOURCE_FILE ("systemConfig.galgas", 54)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_structName_1766 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 55)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 55)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 55))  COMMA_SOURCE_FILE ("systemConfig.galgas", 55)) ;
    {
    var_subAttrs_1662.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 56)) ;
    }
    {
    ioArgument_result.insulate (HERE) ; // §ABSTRACT
    cPtr_gtlData * ptr_1872 = (cPtr_gtlData *) ioArgument_result.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1872, var_structName_1766, var_subAttrs_1662, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 57)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_boolAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                            extensionMethod_boolAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_boolAttribute_set (defineExtensionMethod_boolAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@enumAttribute set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_gtlData & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_2191 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2191, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 66)) ;
  }
  GALGAS_gtlData var_subAttrs_2280 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 67)) ;
  GALGAS_gtlStruct temp_0 ;
  if (var_subAttrs_2280.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_2280.ptr ())) {
      temp_0 = (cPtr_gtlStruct *) var_subAttrs_2280.ptr () ;
    }else{
      inCompiler->castError ("gtlStruct", var_subAttrs_2280.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 68)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 68)).getter_count (SOURCE_FILE ("systemConfig.galgas", 68)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_lstring var_structName_2384 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 69)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 69)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 69))  COMMA_SOURCE_FILE ("systemConfig.galgas", 69)) ;
    {
    var_subAttrs_2280.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 70)) ;
    }
    {
    ioArgument_result.insulate (HERE) ; // §ABSTRACT
    cPtr_gtlData * ptr_2490 = (cPtr_gtlData *) ioArgument_result.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2490, var_structName_2384, var_subAttrs_2280, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 71)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                            extensionMethod_enumAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumAttribute_set (defineExtensionMethod_enumAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Overriding extension method '@stringAttribute set'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_stringAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_stringAttribute * object = (const cPtr_stringAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_stringAttribute) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_2625 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2625, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 76)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_stringAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_stringAttribute.mSlotID,
                            extensionMethod_stringAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_stringAttribute_set (defineExtensionMethod_stringAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@string_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_string_5F_class_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_gtlData & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_string_5F_class * object = (const cPtr_string_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_string_5F_class) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_2782 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2782, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 80)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_string_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_string_5F_class.mSlotID,
                            extensionMethod_string_5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_string_5F_class_set (defineExtensionMethod_string_5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@objectRefAttribute set'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectRefAttribute_set (const cPtr_object_5F_t * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    GALGAS_gtlData & ioArgument_result,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_2945 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_2945, constinArgument_name, GALGAS_gtlString::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_string (SOURCE_FILE ("systemConfig.galgas", 84))  COMMA_SOURCE_FILE ("systemConfig.galgas", 84)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 84)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectRefAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                            extensionMethod_objectRefAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectRefAttribute_set (defineExtensionMethod_objectRefAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@multipleAttribute set'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_multipleAttribute_set (const cPtr_object_5F_t * inObject,
                                                   const GALGAS_lstring constinArgument_name,
                                                   GALGAS_gtlData & ioArgument_result,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  GALGAS_gtlList var_multiple_3115 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 88))  COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
  cEnumerator_identifierList enumerator_3180 (object->mAttribute_items, kEnumeration_up) ;
  while (enumerator_3180.hasCurrentObject ()) {
    GALGAS_gtlData var_multipleItem_3209 = GALGAS_gtlStruct::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 90))  COMMA_SOURCE_FILE ("systemConfig.galgas", 90)) ;
    if (enumerator_3180.current_item (HERE).isValid ()) {
      if (enumerator_3180.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_3312_aStruct ((cPtr_structAttribute *) enumerator_3180.current_item (HERE).ptr ()) ;
        {
        var_multipleItem_3209.insulate (HERE) ; // §ABSTRACT
        cPtr_gtlData * ptr_3336 = (cPtr_gtlData *) var_multipleItem_3209.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3336, GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), cast_3312_aStruct.getter_location (SOURCE_FILE ("systemConfig.galgas", 94))  COMMA_SOURCE_FILE ("systemConfig.galgas", 94)), GALGAS_gtlString::constructor_new (cast_3312_aStruct.getter_location (SOURCE_FILE ("systemConfig.galgas", 96)), cast_3312_aStruct.getter_oil_5F_desc (SOURCE_FILE ("systemConfig.galgas", 97)), cast_3312_aStruct.getter_structName (SOURCE_FILE ("systemConfig.galgas", 98)).getter_string (SOURCE_FILE ("systemConfig.galgas", 98))  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 93)) ;
        }
        GALGAS_gtlData var_subAttrs_3566 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) cast_3312_aStruct.getter_subAttributes (SOURCE_FILE ("systemConfig.galgas", 101)).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 101)) ;
        GALGAS_gtlStruct temp_0 ;
        if (var_subAttrs_3566.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3566.ptr ())) {
            temp_0 = (cPtr_gtlStruct *) var_subAttrs_3566.ptr () ;
          }else{
            inCompiler->castError ("gtlStruct", var_subAttrs_3566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 102)) ;
          }
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, temp_0.getter_value (SOURCE_FILE ("systemConfig.galgas", 102)).getter_count (SOURCE_FILE ("systemConfig.galgas", 102)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlStruct temp_2 ;
          if (var_subAttrs_3566.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_subAttrs_3566.ptr ())) {
              temp_2 = (cPtr_gtlStruct *) var_subAttrs_3566.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_subAttrs_3566.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("systemConfig.galgas", 103)) ;
            }
          }
          cEnumerator_gtlVarMap enumerator_3710 (temp_2.getter_value (SOURCE_FILE ("systemConfig.galgas", 103)), kEnumeration_up) ;
          while (enumerator_3710.hasCurrentObject ()) {
            {
            var_multipleItem_3209.insulate (HERE) ; // §ABSTRACT
            cPtr_gtlData * ptr_3739 = (cPtr_gtlData *) var_multipleItem_3209.ptr () ;
            callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3739, enumerator_3710.current_lkey (HERE), enumerator_3710.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 104)) ;
            }
            enumerator_3710.gotoNextObject () ;
          }
        }
      }else{
        callExtensionMethod_set ((const cPtr_object_5F_t *) enumerator_3180.current_item (HERE).ptr (), GALGAS_lstring::constructor_new (GALGAS_string ("VALUE"), enumerator_3180.current_item (HERE).getter_location (SOURCE_FILE ("systemConfig.galgas", 108))  COMMA_SOURCE_FILE ("systemConfig.galgas", 108)), var_multipleItem_3209, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 108)) ;
      }
    }
    {
    var_multiple_3115.insulate (HERE) ;
    cPtr_gtlList * ptr_3899 = (cPtr_gtlList *) var_multiple_3115.ptr () ;
    callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_3899, var_multipleItem_3209, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 110)) ;
    }
    enumerator_3180.gotoNextObject () ;
  }
  {
  var_multiple_3115.setter_setMeta (object->mAttribute_oil_5F_desc COMMA_SOURCE_FILE ("systemConfig.galgas", 112)) ;
  }
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_3976 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_3976, constinArgument_name, var_multiple_3115, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 113)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_multipleAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                            extensionMethod_multipleAttribute_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_multipleAttribute_set (defineExtensionMethod_multipleAttribute_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@uint32_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32__5F_class * object = (const cPtr_uint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_4096 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4096, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 119))  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 117)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_33__32__5F_class.mSlotID,
                            extensionMethod_uint_33__32__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_33__32__5F_class_set (defineExtensionMethod_uint_33__32__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@sint32_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32__5F_class * object = (const cPtr_sint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_4270 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4270, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 126))  COMMA_SOURCE_FILE ("systemConfig.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 124)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_33__32__5F_class.mSlotID,
                            extensionMethod_sint_33__32__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_33__32__5F_class_set (defineExtensionMethod_sint_33__32__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@uint64_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_uint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34__5F_class * object = (const cPtr_uint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_4444 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4444, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 133))  COMMA_SOURCE_FILE ("systemConfig.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 131)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_uint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_36__34__5F_class.mSlotID,
                            extensionMethod_uint_36__34__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_uint_36__34__5F_class_set (defineExtensionMethod_uint_36__34__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@sint64_class set'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_sint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_gtlData & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34__5F_class * object = (const cPtr_sint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34__5F_class) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_4618 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4618, constinArgument_name, GALGAS_gtlInt::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 140))  COMMA_SOURCE_FILE ("systemConfig.galgas", 140)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_sint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_36__34__5F_class.mSlotID,
                            extensionMethod_sint_36__34__5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_sint_36__34__5F_class_set (defineExtensionMethod_sint_36__34__5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Overriding extension method '@float_class set'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_float_5F_class_set (const cPtr_object_5F_t * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                GALGAS_gtlData & ioArgument_result,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_float_5F_class * object = (const cPtr_float_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_float_5F_class) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_4791 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4791, constinArgument_name, GALGAS_gtlFloat::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, object->mAttribute_value  COMMA_SOURCE_FILE ("systemConfig.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 145)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_float_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_float_5F_class.mSlotID,
                            extensionMethod_float_5F_class_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_float_5F_class_set (defineExtensionMethod_float_5F_class_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Overriding extension method '@auto set'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_auto_set (const cPtr_object_5F_t * inObject,
                                      const GALGAS_lstring constinArgument_name,
                                      GALGAS_gtlData & ioArgument_result,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_auto * object = (const cPtr_auto *) inObject ;
  macroValidSharedObject (object, cPtr_auto) ;
  {
  ioArgument_result.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_4950 = (cPtr_gtlData *) ioArgument_result.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_4950, constinArgument_name, GALGAS_gtlEnum::constructor_new (object->mAttribute_location, object->mAttribute_oil_5F_desc, GALGAS_string ("auto")  COMMA_SOURCE_FILE ("systemConfig.galgas", 154)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 152)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_auto_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_auto.mSlotID,
                            extensionMethod_auto_set) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_auto_set (defineExtensionMethod_auto_set, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Overriding extension method '@impStructType verifyType'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impStructType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_2379_sa ((cPtr_structAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_implementationObjectMap enumerator_2413 (object->mAttribute_structAttributes, kEnumeration_up) ;
      while (enumerator_2413.hasCurrentObject ()) {
        const enumGalgasBool test_0 = cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_hasKey (enumerator_2413.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 88)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 88)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_subAttr_2514 ;
          cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 90)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 90)).method_get (enumerator_2413.current_lkey (HERE), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 90)) ;
          callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_2413.current_type (HERE).ptr (), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 91)) ;
        }
        enumerator_2413.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 95)), GALGAS_string ("STRUCT expected"), fixItArray1  COMMA_SOURCE_FILE ("semantic_verification.galgas", 95)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impStructType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                   extensionMethod_impStructType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impStructType_verifyType (defineExtensionMethod_impStructType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Overriding extension method '@refType verifyType'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_refType_verifyType (const cPtr_impType * /* inObject */,
                                                const GALGAS_object_5F_t constinArgument_attr,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_objectRefAttribute) {
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 105)), GALGAS_string ("object reference expected"), fixItArray0  COMMA_SOURCE_FILE ("semantic_verification.galgas", 105)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_refType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                   extensionMethod_refType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_refType_verifyType (defineExtensionMethod_refType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impBoolType verifyType'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impBoolType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3136_b ((cPtr_boolAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = cast_3136_b.getter_value (SOURCE_FILE ("semantic_verification.galgas", 114)).boolEnum () ;
      if (kBoolTrue == test_0) {
        cEnumerator_implementationObjectMap enumerator_3195 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
        while (enumerator_3195.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_hasKey (enumerator_3195.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 116)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 116)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_3300 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 118)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 118)).method_get (enumerator_3195.current_lkey (HERE), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 118)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3195.current_type (HERE).ptr (), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 119)) ;
          }
          enumerator_3195.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        cEnumerator_implementationObjectMap enumerator_3478 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
        while (enumerator_3478.hasCurrentObject ()) {
          const enumGalgasBool test_2 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_hasKey (enumerator_3478.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 124)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 124)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_object_5F_t var_subAttrs_3583 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 126)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 126)).method_get (enumerator_3478.current_lkey (HERE), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 126)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3478.current_type (HERE).ptr (), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 127)) ;
          }
          enumerator_3478.gotoNextObject () ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 132)), GALGAS_string ("BOOLEAN expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 132)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impBoolType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impBoolType_verifyType (defineExtensionMethod_impBoolType_verifyType, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Overriding extension method '@impEnumType verifyType'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_impEnumType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3969_e ((cPtr_enumAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = object->mAttribute_valuesMap.getter_hasKey (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 141)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_implementationObjectMap var_validVal_4053 ;
        object->mAttribute_valuesMap.method_get (function_lstringWith (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)), var_validVal_4053, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)) ;
        cEnumerator_implementationObjectMap enumerator_4136 (var_validVal_4053, kEnumeration_up) ;
        while (enumerator_4136.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_hasKey (enumerator_4136.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 145)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 145)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_4241 ;
            cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 147)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 147)).method_get (enumerator_4136.current_lkey (HERE), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 147)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_4136.current_type (HERE).ptr (), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 148)) ;
          }
          enumerator_4136.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (cast_3969_e.getter_location (SOURCE_FILE ("semantic_verification.galgas", 152)), cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 152)).add_operation (GALGAS_string (" is not a valid enum value"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("**** @impEnumType ****\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 156)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 157)), GALGAS_string ("ENUM expected"), fixItArray3  COMMA_SOURCE_FILE ("semantic_verification.galgas", 157)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_impEnumType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                   extensionMethod_impEnumType_verifyType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_impEnumType_verifyType (defineExtensionMethod_impEnumType_verifyType, NULL) ;

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


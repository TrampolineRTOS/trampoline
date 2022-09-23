#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-9.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_bool var_included_96131 = GALGAS_bool (true) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3070)) ;
        }
      }
      cEnumerator_lstringset enumerator_96151 (temp_1.readProperty_value (), kENUMERATION_UP) ;
      bool bool_2 = var_included_96131.isValidAndTrue () ;
      if (enumerator_96151.hasCurrentObject () && bool_2) {
        while (enumerator_96151.hasCurrentObject () && bool_2) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = this->mProperty_value.getter_hasKey (enumerator_96151.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3071)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3071)).boolEnum () ;
            if (kBoolTrue == test_3) {
              var_included_96131 = GALGAS_bool (false) ;
            }
          }
          enumerator_96151.gotoNextObject () ;
          if (enumerator_96151.hasCurrentObject ()) {
            bool_2 = var_included_96131.isValidAndTrue () ;
          }
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3073)), var_included_96131  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3073)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3075)), GALGAS_string ("set expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3075)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_ltOp (const GALGAS_gtlData constinArgument_right,
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
            inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3081)) ;
          }
        }
        test_1 = GALGAS_bool (kIsEqual, temp_2.readProperty_value ().objectCompare (this->mProperty_value)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3082)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3082)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_bool var_included_96624 = GALGAS_bool (true) ;
        cEnumerator_lstringset enumerator_96646 (this->mProperty_value, kENUMERATION_UP) ;
        bool bool_3 = var_included_96624.isValidAndTrue () ;
        if (enumerator_96646.hasCurrentObject () && bool_3) {
          while (enumerator_96646.hasCurrentObject () && bool_3) {
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              GALGAS_gtlSet temp_5 ;
              if (constinArgument_right.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
                  temp_5 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
                }else{
                  inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3086)) ;
                }
              }
              test_4 = temp_5.readProperty_value ().getter_hasKey (enumerator_96646.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3086)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3086)).boolEnum () ;
              if (kBoolTrue == test_4) {
                var_included_96624 = GALGAS_bool (false) ;
              }
            }
            enumerator_96646.gotoNextObject () ;
            if (enumerator_96646.hasCurrentObject ()) {
              bool_3 = var_included_96624.isValidAndTrue () ;
            }
          }
        }
        result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3088)), var_included_96624  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3088)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3091)), GALGAS_string ("set expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3091)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_bool var_included_97014 = GALGAS_bool (true) ;
      cEnumerator_lstringset enumerator_97034 (this->mProperty_value, kENUMERATION_UP) ;
      bool bool_1 = var_included_97014.isValidAndTrue () ;
      if (enumerator_97034.hasCurrentObject () && bool_1) {
        while (enumerator_97034.hasCurrentObject () && bool_1) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            GALGAS_gtlSet temp_3 ;
            if (constinArgument_right.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
                temp_3 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
              }else{
                inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3099)) ;
              }
            }
            test_2 = temp_3.readProperty_value ().getter_hasKey (enumerator_97034.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3099)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3099)).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_included_97014 = GALGAS_bool (false) ;
            }
          }
          enumerator_97034.gotoNextObject () ;
          if (enumerator_97034.hasCurrentObject ()) {
            bool_1 = var_included_97014.isValidAndTrue () ;
          }
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3101)), var_included_97014  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3101)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3103)), GALGAS_string ("set expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3103)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlSet::getter_embeddedType (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3109)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSet addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlSet::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     C_Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3114))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3114)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSet::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("length").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3128)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3128)) ;
      }
      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3131)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3132)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 3132))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3129)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("list").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3135)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3135)) ;
        }
        result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3137)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3137))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3136)) ;
        cEnumerator_lstringset enumerator_98305 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_98305.hasCurrentObject ()) {
          {
          result_result.insulate (HERE) ;
          cPtr_gtlData * ptr_98333 = (cPtr_gtlData *) result_result.ptr () ;
          callExtensionSetter_appendItem ((cPtr_gtlData *) ptr_98333, GALGAS_gtlString::constructor_new (enumerator_98305.current_lkey (HERE).readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3140)), enumerator_98305.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3140)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3140)) ;
          }
          enumerator_98305.gotoNextObject () ;
        }
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("contains").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3143)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3143)) ;
          }
          GALGAS_string var_key_98531 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3144)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3144)) ;
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3146)), this->mProperty_value.getter_hasKey (var_key_98531 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3146))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3145)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("elementNamed").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3149)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3149)) ;
            }
            GALGAS_string var_key_98799 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3150)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3150)) ;
            GALGAS_location var_loc_98859 = this->mProperty_value.getter_locationForKey (var_key_98799, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3151)) ;
            result_result = GALGAS_gtlString::constructor_new (var_loc_98859, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3153)), var_key_98799  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3152)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3156)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3156)) ;
              }
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3158)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3157)) ;
            }
          }
          if (kBoolFalse == test_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_5) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3161)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3163)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3162)) ;
              }
            }
            if (kBoolFalse == test_5) {
              enumGalgasBool test_6 = kBoolTrue ;
              if (kBoolTrue == test_6) {
                test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3165)).boolEnum () ;
                if (kBoolTrue == test_6) {
                  const GALGAS_gtlSet temp_7 = this ;
                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3166)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3166)) ;
                }
              }
              if (kBoolFalse == test_6) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3174)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3174)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3176)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3176))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3175)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  TC_Array <C_FixItDescription> fixItArray9 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3179)).add_operation (GALGAS_string ("' for set target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3179)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3179)) ;
                  result_result.drop () ; // Release error dropped variable
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
//Overriding extension setter '@gtlSet performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlSet_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlSet * object = (cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3194)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3194)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3195)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_100301 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_100301.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3196)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3196)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3199)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3199)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("add").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3202)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3202)) ;
          }
          GALGAS_lstring var_key_100647 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3203)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3203)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = object->mProperty_value.getter_hasKey (var_key_100647.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3204)).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              object->mProperty_value.setter_del (var_key_100647, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3205)) ;
              }
            }
          }
          {
          object->mProperty_value.setter_put (var_key_100647, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3207)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("remove").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3210)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3210)) ;
            }
            GALGAS_lstring var_key_100917 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3211)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3211)) ;
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = object->mProperty_value.getter_hasKey (var_key_100917.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3212)).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                object->mProperty_value.setter_del (var_key_100917, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3213)) ;
                }
              }
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_7 = kBoolTrue ;
          if (kBoolTrue == test_7) {
            test_7 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3216)).boolEnum () ;
            if (kBoolTrue == test_7) {
              const GALGAS_gtlSet temp_8 = object ;
              GALGAS_gtlData var_copy_101113 = temp_8 ;
              callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("set"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3218)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_101113, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3218)) ;
              GALGAS_gtlSet temp_9 ;
              if (var_copy_101113.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlSet *> (var_copy_101113.ptr ())) {
                  temp_9 = (cPtr_gtlSet *) var_copy_101113.ptr () ;
                }else{
                  inCompiler->castError ("gtlSet", var_copy_101113.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3225)) ;
                }
              }
              object->mProperty_value = temp_9.readProperty_value () ;
              object->mProperty_where = var_copy_101113.readProperty_where () ;
              object->mProperty_meta = var_copy_101113.readProperty_meta () ;
            }
          }
          if (kBoolFalse == test_7) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3229)).add_operation (GALGAS_string ("' for set target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3229)), fixItArray10  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3229)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlSet_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                                      extensionSetter_gtlSet_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlSet_performSetter (defineExtensionSetter_gtlSet_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_desc (const GALGAS_uint constinArgument_tab,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3242)).add_operation (GALGAS_string ("struct: @{\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3242)) ;
  cEnumerator_gtlVarMap enumerator_101851 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_101851.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3245))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3245)).add_operation (enumerator_101851.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3245)).add_operation (GALGAS_string (" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3246)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_101851.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3247)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3247)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3246)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3245)) ;
    enumerator_101851.gotoNextObject () ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3249)).add_operation (GALGAS_string ("}\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3249)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3249)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_string (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3253)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlStruct::getter_lstring (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3257)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlStruct::getter_bool (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3261)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlStruct::getter_int (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3265)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlStruct::getter_float (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a struct to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3269)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_plusOp (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3273)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_minusOp (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3277)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_notOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3281)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3285)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3289)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3293)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3297)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3301)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3305)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3309)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3313)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3317)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3321)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlStruct temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlStruct *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlStruct", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3326)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_104336 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_104382 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3328)).objectCompare (var_rValue_104336.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3328)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_104382 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_104382 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_104497 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_104497.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_104336.getter_hasKey (enumerator_104497.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3333)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_104596 ;
              var_rValue_104336.method_get (enumerator_104497.current_lkey (HERE), var_rData_104596, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3334)) ;
              var_equal_104382 = var_equal_104382.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_104497.current_value (HERE).ptr (), var_rData_104596, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3335)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3335)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3335)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_104382 = GALGAS_bool (false) ;
          }
          enumerator_104497.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3341)), var_equal_104382.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3341))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3341)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3343)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlStruct temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlStruct *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlStruct", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3349)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_104976 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_105022 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3351)).objectCompare (var_rValue_104976.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 3351)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_105022 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_105022 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_105137 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_105137.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_104976.getter_hasKey (enumerator_105137.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3356)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_105236 ;
              var_rValue_104976.method_get (enumerator_105137.current_lkey (HERE), var_rData_105236, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3357)) ;
              var_equal_105022 = var_equal_105022.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_105137.current_value (HERE).ptr (), var_rData_105236, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3358)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3358)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3358)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_105022 = GALGAS_bool (false) ;
          }
          enumerator_105137.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3364)), var_equal_105022  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3364)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3366)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3371)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3374)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3377)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3380)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlStruct::getter_embeddedType (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3385)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStruct addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlStruct::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3390))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3390)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("map").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3404)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3404)) ;
      }
      result_result = GALGAS_gtlMap::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3407)), this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3405)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3411)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3411)) ;
        }
        const GALGAS_gtlStruct temp_2 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3413)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3413))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3412)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3416)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3416)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3418)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3417)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3421)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3421)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3423)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3422)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3425)).boolEnum () ;
            if (kBoolTrue == test_5) {
              const GALGAS_gtlStruct temp_6 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3426)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_6, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3426)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_7 = kBoolTrue ;
            if (kBoolTrue == test_7) {
              test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_7) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3434)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3434)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3436)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3436))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3435)) ;
              }
            }
            if (kBoolFalse == test_7) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3439)).add_operation (GALGAS_string ("' for struct target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3439)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3439)) ;
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
//Overriding extension setter '@gtlStruct performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_performSetter (cPtr_gtlData * inObject,
                                                     const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3454)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3454)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3455)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_108369 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_108369.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3456)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3456)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3459)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3459)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3461)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlStruct temp_4 = object ;
          GALGAS_gtlData var_copy_108667 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("struct"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3463)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_108667, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3463)) ;
          GALGAS_gtlStruct temp_5 ;
          if (var_copy_108667.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlStruct *> (var_copy_108667.ptr ())) {
              temp_5 = (cPtr_gtlStruct *) var_copy_108667.ptr () ;
            }else{
              inCompiler->castError ("gtlStruct", var_copy_108667.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3470)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_108667.readProperty_where () ;
          object->mProperty_meta = var_copy_108667.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3474)).add_operation (GALGAS_string ("' for struct target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3474)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3474)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                      extensionSetter_gtlStruct_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlStruct_performSetter (defineExtensionSetter_gtlStruct_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStruct structField'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlStruct::method_structField (const GALGAS_lstring constinArgument_name,
                                         GALGAS_gtlData & outArgument_result,
                                         GALGAS_bool & outArgument_found,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3486)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3487)) ;
      outArgument_found = GALGAS_bool (true) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_result = GALGAS_gtlUnconstructed::constructor_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3490))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3490)) ;
    outArgument_found = GALGAS_bool (false) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct resultField'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlStruct::getter_resultField (const GALGAS_lstring constinArgument_name,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3499)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3500)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_gtlUnconstructed::constructor_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3502))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3502)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct hasStructField'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlStruct::getter_hasStructField (const GALGAS_lstring constinArgument_name,
                                                   C_Compiler */* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3513)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct setStructField'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_setStructField (cPtr_gtlData * inObject,
                                                      const GALGAS_lstring constinArgument_name,
                                                      const GALGAS_gtlData constinArgument_data,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  {
  extensionSetter_replaceOrCreate (object->mProperty_value, constinArgument_name, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3523)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_setStructField (void) {
  enterExtensionSetter_setStructField (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                       extensionSetter_gtlStruct_setStructField) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlStruct_setStructField (defineExtensionSetter_gtlStruct_setStructField, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct setStructFieldAtLevel'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                             const GALGAS_lstring constinArgument_name,
                                                             const GALGAS_gtlData constinArgument_data,
                                                             const GALGAS_uint constinArgument_level,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  {
  extensionSetter_replaceOrCreateAtLevel (object->mProperty_value, constinArgument_name, constinArgument_data, constinArgument_level, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3534)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_setStructFieldAtLevel (void) {
  enterExtensionSetter_setStructFieldAtLevel (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                              extensionSetter_gtlStruct_setStructFieldAtLevel) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlStruct_setStructFieldAtLevel (defineExtensionSetter_gtlStruct_setStructFieldAtLevel, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlStruct deleteStructField'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlStruct_deleteStructField (cPtr_gtlData * inObject,
                                                         const GALGAS_lstring constinArgument_name,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlStruct * object = (cPtr_gtlStruct *) inObject ;
  macroValidSharedObject (object, cPtr_gtlStruct) ;
  {
  GALGAS_gtlData joker_110976 ; // Joker input parameter
  object->mProperty_value.setter_del (constinArgument_name, joker_110976, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3543)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlStruct_deleteStructField (void) {
  enterExtensionSetter_deleteStructField (kTypeDescriptor_GALGAS_gtlStruct.mSlotID,
                                          extensionSetter_gtlStruct_deleteStructField) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlStruct_deleteStructField (defineExtensionSetter_gtlStruct_deleteStructField, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlList::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3555)).add_operation (GALGAS_string ("list: @(\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3555)) ;
  cEnumerator_list enumerator_111381 (this->mProperty_value, kENUMERATION_UP) ;
  GALGAS_uint index_111378 ((uint32_t) 0) ;
  while (enumerator_111381.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3558))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3558)).add_operation (index_111378.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3559)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3558)).add_operation (GALGAS_string (" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3559)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_111381.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3560)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3560)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3559)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3558)) ;
    enumerator_111381.gotoNextObject () ;
    index_111378.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3557)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3562)).add_operation (GALGAS_string (")\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3562)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3562)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlList::getter_string (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3566)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlList::getter_lstring (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3570)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlList::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3574)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlList::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3578)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlList::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a list to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3582)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_plusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3586)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3590)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3594)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_list var_res_112509 = this->mProperty_value ;
  var_res_112509.addAssign_operation (constinArgument_right  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3599)) ;
  result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3600)), var_res_112509  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3600)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3604)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3608)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3612)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3616)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3620)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlList temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlList *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlList *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3628)) ;
        }
      }
      result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3627)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3628))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3625)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3631)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3636)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3640)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3644)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlList temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlList *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlList *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3649)) ;
        }
      }
      GALGAS_list var_rValue_113991 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_114035 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3651)).objectCompare (var_rValue_113991.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3651)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_114035 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_114035 = GALGAS_bool (true) ;
        cEnumerator_list enumerator_114145 (this->mProperty_value, kENUMERATION_UP) ;
        cEnumerator_list enumerator_114163 (var_rValue_113991, kENUMERATION_UP) ;
        while (enumerator_114145.hasCurrentObject () && enumerator_114163.hasCurrentObject ()) {
          var_equal_114035 = var_equal_114035.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_114145.current_value (HERE).ptr (), enumerator_114163.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3656)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3656)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3656)) ;
          enumerator_114145.gotoNextObject () ;
          enumerator_114163.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3659)), var_equal_114035.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 3659))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3659)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3661)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlList temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlList *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlList *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlList", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3667)) ;
        }
      }
      GALGAS_list var_rValue_114492 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_114536 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3669)).objectCompare (var_rValue_114492.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3669)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_114536 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_114536 = GALGAS_bool (true) ;
        cEnumerator_list enumerator_114646 (this->mProperty_value, kENUMERATION_UP) ;
        cEnumerator_list enumerator_114664 (var_rValue_114492, kENUMERATION_UP) ;
        while (enumerator_114646.hasCurrentObject () && enumerator_114664.hasCurrentObject ()) {
          var_equal_114536 = var_equal_114536.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_114646.current_value (HERE).ptr (), enumerator_114664.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3674)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3674)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3674)) ;
          enumerator_114646.gotoNextObject () ;
          enumerator_114664.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3677)), var_equal_114536  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3677)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3679)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the > operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3684)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the >= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3688)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the < operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3692)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a list does not support the <= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3696)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlList::getter_embeddedType (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("list forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3701)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlList addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlList::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 3706))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3706)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlList::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("length").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3720)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3720)) ;
      }
      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3723)), this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3724)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 3724))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3721)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("first").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3727)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3727)) ;
        }
        this->mProperty_value.method_first (result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3728)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("last").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3730)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3730)) ;
          }
          this->mProperty_value.method_last (result_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3731)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("elementAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3733)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3733)) ;
            }
            GALGAS_uint var_index_116688 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3734)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3734)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3734)) ;
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              test_4 = GALGAS_bool (kIsStrictInf, var_index_116688.objectCompare (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3735)))).boolEnum () ;
              if (kBoolTrue == test_4) {
                result_result = this->mProperty_value.getter_valueAtIndex (var_index_116688, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3736)) ;
              }
            }
            if (kBoolFalse == test_4) {
              TC_Array <C_FixItDescription> fixItArray5 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("index out of bounds"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3738)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("subListTo").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_6) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3741)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3741)) ;
              }
              GALGAS_uint var_index_117004 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3742)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3742)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3742)) ;
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsStrictInf, var_index_117004.objectCompare (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3743)))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3746)), this->mProperty_value.getter_subListToIndex (var_index_117004, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3747))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3744)) ;
                }
              }
              if (kBoolFalse == test_7) {
                const GALGAS_gtlList temp_8 = this ;
                result_result = temp_8 ;
              }
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_9 = kBoolTrue ;
            if (kBoolTrue == test_9) {
              test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("subListFrom").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_9) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3753)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3753)) ;
                }
                GALGAS_uint var_index_117362 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3754)) ;
                enumGalgasBool test_10 = kBoolTrue ;
                if (kBoolTrue == test_10) {
                  test_10 = GALGAS_bool (kIsStrictInf, var_index_117362.objectCompare (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3755)))).boolEnum () ;
                  if (kBoolTrue == test_10) {
                    result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3758)), this->mProperty_value.getter_subListFromIndex (var_index_117362, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3759))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3756)) ;
                  }
                }
                if (kBoolFalse == test_10) {
                  result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3764)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3765))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3762)) ;
                }
              }
            }
            if (kBoolFalse == test_9) {
              enumGalgasBool test_11 = kBoolTrue ;
              if (kBoolTrue == test_11) {
                test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("subList").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_11) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3769)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3769)) ;
                  }
                  GALGAS_uint var_start_117808 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3770)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3770)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3770)) ;
                  GALGAS_uint var_length_117861 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3771)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3771)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3771)) ;
                  enumGalgasBool test_12 = kBoolTrue ;
                  if (kBoolTrue == test_12) {
                    test_12 = GALGAS_bool (kIsStrictInf, var_start_117808.objectCompare (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3772)))).boolEnum () ;
                    if (kBoolTrue == test_12) {
                      enumGalgasBool test_13 = kBoolTrue ;
                      if (kBoolTrue == test_13) {
                        test_13 = GALGAS_bool (kIsStrictSup, var_start_117808.add_operation (var_length_117861, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3773)).objectCompare (this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3773)))).boolEnum () ;
                        if (kBoolTrue == test_13) {
                          var_length_117861 = this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3774)).substract_operation (var_start_117808, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3774)) ;
                        }
                      }
                      result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3778)), this->mProperty_value.getter_subListWithRange (GALGAS_range::constructor_new (var_start_117808, var_length_117861  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3779)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3779))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3776)) ;
                    }
                  }
                  if (kBoolFalse == test_12) {
                    result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3784)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3785))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3782)) ;
                  }
                }
              }
              if (kBoolFalse == test_11) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("mapBy").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_anyArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3789)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3789)) ;
                    }
                    GALGAS_lstring var_key_118424 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3790)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3790)) ;
                    GALGAS_gtlVarMap var_resultMap_118488 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3791)) ;
                    const GALGAS_gtlList temp_15 = this ;
                    cEnumerator_list enumerator_118514 (temp_15.readProperty_value (), kENUMERATION_UP) ;
                    GALGAS_uint index_118508 ((uint32_t) 0) ;
                    while (enumerator_118514.hasCurrentObject ()) {
                      if (enumerator_118514.current_value (HERE).isValid ()) {
                        if (enumerator_118514.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
                          GALGAS_gtlStruct cast_118594_itemStruct ((cPtr_gtlStruct *) enumerator_118514.current_value (HERE).ptr ()) ;
                          enumGalgasBool test_16 = kBoolTrue ;
                          if (kBoolTrue == test_16) {
                            test_16 = cast_118594_itemStruct.readProperty_value ().getter_hasKey (var_key_118424.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3795)).boolEnum () ;
                            if (kBoolTrue == test_16) {
                              GALGAS_gtlData var_keyValue_118715 ;
                              cast_118594_itemStruct.readProperty_value ().method_get (var_key_118424, var_keyValue_118715, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3796)) ;
                              {
                              var_resultMap_118488.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_118715.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3798)), enumerator_118514.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3797)) ;
                              }
                            }
                          }
                          if (kBoolFalse == test_16) {
                            TC_Array <C_FixItDescription> fixItArray17 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("item at index ").add_operation (index_118508.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3802)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3802)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3802)).add_operation (var_key_118424.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3803)), fixItArray17  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3802)) ;
                          }
                        }else if (enumerator_118514.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
                          GALGAS_gtlMap cast_118964_itemMap ((cPtr_gtlMap *) enumerator_118514.current_value (HERE).ptr ()) ;
                          enumGalgasBool test_18 = kBoolTrue ;
                          if (kBoolTrue == test_18) {
                            test_18 = cast_118964_itemMap.readProperty_value ().getter_hasKey (var_key_118424.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3806)).boolEnum () ;
                            if (kBoolTrue == test_18) {
                              GALGAS_gtlData var_keyValue_119079 ;
                              cast_118964_itemMap.readProperty_value ().method_get (var_key_118424, var_keyValue_119079, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3807)) ;
                              {
                              var_resultMap_118488.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_119079.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3809)), enumerator_118514.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3808)) ;
                              }
                            }
                          }
                          if (kBoolFalse == test_18) {
                            TC_Array <C_FixItDescription> fixItArray19 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("item at index ").add_operation (index_118508.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3813)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3813)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3813)).add_operation (var_key_118424.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3814)), fixItArray19  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3813)) ;
                          }
                        }else{
                          TC_Array <C_FixItDescription> fixItArray20 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("list of struct expected"), fixItArray20  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3817)) ;
                        }
                      }
                      enumerator_118514.gotoNextObject () ;
                      index_118508.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3792)) ;
                    }
                    result_result = GALGAS_gtlMap::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3820)), var_resultMap_118488  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3820)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("set").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3822)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3822)) ;
                      }
                      GALGAS_lstringset var_resultSet_119578 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3823)) ;
                      cEnumerator_list enumerator_119604 (this->mProperty_value, kENUMERATION_UP) ;
                      while (enumerator_119604.hasCurrentObject ()) {
                        GALGAS_lstring var_itemKey_119644 = callExtensionGetter_lstring ((const cPtr_gtlData *) enumerator_119604.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3825)) ;
                        enumGalgasBool test_22 = kBoolTrue ;
                        if (kBoolTrue == test_22) {
                          test_22 = var_resultSet_119578.getter_hasKey (var_itemKey_119644.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3826)).boolEnum () ;
                          if (kBoolTrue == test_22) {
                            {
                            var_resultSet_119578.setter_del (var_itemKey_119644, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3827)) ;
                            }
                          }
                        }
                        {
                        var_resultSet_119578.setter_put (var_itemKey_119644, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3829)) ;
                        }
                        enumerator_119604.gotoNextObject () ;
                      }
                      result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3832)), var_resultSet_119578  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3831)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_23 = kBoolTrue ;
                    if (kBoolTrue == test_23) {
                      test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("setBy").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_23) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3835)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3835)) ;
                        }
                        GALGAS_lstring var_key_120003 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3836)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3836)) ;
                        GALGAS_lstringset var_resultSet_120068 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3837)) ;
                        cEnumerator_list enumerator_120094 (this->mProperty_value, kENUMERATION_UP) ;
                        while (enumerator_120094.hasCurrentObject ()) {
                          GALGAS_gtlData var_field_120156 ;
                          GALGAS_bool joker_120158 ; // Joker input parameter
                          callExtensionMethod_structField ((cPtr_gtlData *) enumerator_120094.current_value (HERE).ptr (), var_key_120003, var_field_120156, joker_120158, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3839)) ;
                          GALGAS_lstring var_resKey_120186 = callExtensionGetter_lstring ((const cPtr_gtlData *) var_field_120156.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3840)) ;
                          enumGalgasBool test_24 = kBoolTrue ;
                          if (kBoolTrue == test_24) {
                            test_24 = var_resultSet_120068.getter_hasKey (var_resKey_120186.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3841)).boolEnum () ;
                            if (kBoolTrue == test_24) {
                              {
                              var_resultSet_120068.setter_del (var_resKey_120186, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3842)) ;
                              }
                            }
                          }
                          {
                          var_resultSet_120068.setter_put (var_resKey_120186, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3844)) ;
                          }
                          enumerator_120094.gotoNextObject () ;
                        }
                        result_result = GALGAS_gtlSet::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3847)), var_resultSet_120068  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3846)) ;
                      }
                    }
                    if (kBoolFalse == test_23) {
                      enumGalgasBool test_25 = kBoolTrue ;
                      if (kBoolTrue == test_25) {
                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("componentsJoinedByString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_25) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3850)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3850)) ;
                          }
                          GALGAS_string var_joiner_120545 = callExtensionGetter_string ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3851)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3851)) ;
                          GALGAS_string var_stringResult_120608 = GALGAS_string::makeEmptyString () ;
                          cEnumerator_list enumerator_120627 (this->mProperty_value, kENUMERATION_UP) ;
                          while (enumerator_120627.hasCurrentObject ()) {
                            var_stringResult_120608 = var_stringResult_120608.add_operation (callExtensionGetter_string ((const cPtr_gtlData *) enumerator_120627.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3855)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3855)) ;
                            if (enumerator_120627.hasNextObject ()) {
                              var_stringResult_120608 = var_stringResult_120608.add_operation (var_joiner_120545, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3857)) ;
                            }
                            enumerator_120627.gotoNextObject () ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3860)), var_stringResult_120608  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3859)) ;
                        }
                      }
                      if (kBoolFalse == test_25) {
                        enumGalgasBool test_26 = kBoolTrue ;
                        if (kBoolTrue == test_26) {
                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_26) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3863)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3863)) ;
                            }
                            const GALGAS_gtlList temp_27 = this ;
                            result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3865)), temp_27.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3865))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3864)) ;
                          }
                        }
                        if (kBoolFalse == test_26) {
                          enumGalgasBool test_28 = kBoolTrue ;
                          if (kBoolTrue == test_28) {
                            test_28 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_28) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3868)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3868)) ;
                              }
                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3870)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3869)) ;
                            }
                          }
                          if (kBoolFalse == test_28) {
                            enumGalgasBool test_29 = kBoolTrue ;
                            if (kBoolTrue == test_29) {
                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_29) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3873)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3873)) ;
                                }
                                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3875)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3874)) ;
                              }
                            }
                            if (kBoolFalse == test_29) {
                              enumGalgasBool test_30 = kBoolTrue ;
                              if (kBoolTrue == test_30) {
                                test_30 = GALGAS_bool (kIsEqual, GALGAS_string ("where").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_30) {
                                  enumGalgasBool test_31 = kBoolTrue ;
                                  if (kBoolTrue == test_31) {
                                    test_31 = GALGAS_bool (kIsStrictInf, constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3878)).objectCompare (GALGAS_uint (uint32_t (1U)))).operator_or (GALGAS_bool (kIsStrictSup, constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3878)).objectCompare (GALGAS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3878)).boolEnum () ;
                                    if (kBoolTrue == test_31) {
                                      TC_Array <C_FixItDescription> fixItArray32 ;
                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("where expects 1 ou 2 arguments. ").add_operation (constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3880)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 3879)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3879)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3880)), fixItArray32  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3879)) ;
                                      result_result.drop () ; // Release error dropped variable
                                    }
                                  }
                                  if (kBoolFalse == test_31) {
                                    enumGalgasBool test_33 = kBoolTrue ;
                                    if (kBoolTrue == test_33) {
                                      test_33 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3882)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3882)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr))).boolEnum () ;
                                      if (kBoolTrue == test_33) {
                                        TC_Array <C_FixItDescription> fixItArray34 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("expression expected for argument 1"), fixItArray34  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3883)) ;
                                        result_result.drop () ; // Release error dropped variable
                                      }
                                    }
                                    if (kBoolFalse == test_33) {
                                      GALGAS_gtlStruct var_vars_121830 ;
                                      enumGalgasBool test_35 = kBoolTrue ;
                                      if (kBoolTrue == test_35) {
                                        test_35 = GALGAS_bool (kIsEqual, constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3886)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
                                        if (kBoolTrue == test_35) {
                                          enumGalgasBool test_36 = kBoolTrue ;
                                          if (kBoolTrue == test_36) {
                                            test_36 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3887)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 3887)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
                                            if (kBoolTrue == test_36) {
                                              TC_Array <C_FixItDescription> fixItArray37 ;
                                              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("struct expected for argument 1"), fixItArray37  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3888)) ;
                                              var_vars_121830.drop () ; // Release error dropped variable
                                            }
                                          }
                                          if (kBoolFalse == test_36) {
                                            GALGAS_gtlStruct temp_38 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)).isValid ()) {
                                              if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)).ptr ())) {
                                                temp_38 = (cPtr_gtlStruct *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlStruct", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3890)) ;
                                              }
                                            }
                                            var_vars_121830 = temp_38 ;
                                          }
                                        }
                                      }
                                      if (kBoolFalse == test_35) {
                                        var_vars_121830 = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3893)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 3893))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3893)) ;
                                      }
                                      GALGAS_gtlExpr temp_39 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)).isValid ()) {
                                        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)).ptr ())) {
                                          temp_39 = (cPtr_gtlExpr *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlExpr", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3895)) ;
                                        }
                                      }
                                      GALGAS_gtlExpression var_expr_122221 = temp_39.readProperty_value () ;
                                      GALGAS_list var_resultList_122295 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 3896)) ;
                                      cEnumerator_list enumerator_122326 (this->mProperty_value, kENUMERATION_UP) ;
                                      while (enumerator_122326.hasCurrentObject ()) {
                                        {
                                        var_vars_121830.insulate (HERE) ;
                                        cPtr_gtlStruct * ptr_122365 = (cPtr_gtlStruct *) var_vars_121830.ptr () ;
                                        callExtensionSetter_setStructField ((cPtr_gtlStruct *) ptr_122365, GALGAS_lstring::constructor_new (GALGAS_string ("__item__"), enumerator_122326.current_value (HERE).readProperty_where ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3899)), enumerator_122326.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3899)) ;
                                        }
                                        GALGAS_gtlData var_evalResult_122463 = callExtensionGetter_eval ((const cPtr_gtlExpression *) var_expr_122221.ptr (), constinArgument_context, var_vars_121830, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3900)) ;
                                        enumGalgasBool test_40 = kBoolTrue ;
                                        if (kBoolTrue == test_40) {
                                          test_40 = callExtensionGetter_bool ((const cPtr_gtlData *) var_evalResult_122463.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3901)).boolEnum () ;
                                          if (kBoolTrue == test_40) {
                                            var_resultList_122295.addAssign_operation (enumerator_122326.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3902)) ;
                                          }
                                        }
                                        enumerator_122326.gotoNextObject () ;
                                      }
                                      result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3907)), var_resultList_122295  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3905)) ;
                                    }
                                  }
                                }
                              }
                              if (kBoolFalse == test_30) {
                                enumGalgasBool test_41 = kBoolTrue ;
                                if (kBoolTrue == test_41) {
                                  test_41 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3912)).boolEnum () ;
                                  if (kBoolTrue == test_41) {
                                    const GALGAS_gtlList temp_42 = this ;
                                    result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3913)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_42, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3913)) ;
                                  }
                                }
                                if (kBoolFalse == test_41) {
                                  enumGalgasBool test_43 = kBoolTrue ;
                                  if (kBoolTrue == test_43) {
                                    test_43 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_43) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3921)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3921)) ;
                                      }
                                      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3923)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3923))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3922)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_43) {
                                    TC_Array <C_FixItDescription> fixItArray44 ;
                                    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3926)).add_operation (GALGAS_string ("' for list target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3926)), fixItArray44  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3926)) ;
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
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3941)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3941)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3942)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_123717 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_123717.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3943)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3943)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3946)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3946)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("insert").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_intAnyArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3949)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3949)) ;
          }
          GALGAS_uint var_insertIndex_124072 = callExtensionGetter_int ((const cPtr_gtlData *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3950)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3950)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3950)) ;
          GALGAS_gtlData var_node_124129 = constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3951)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsStrictInf, var_insertIndex_124072.objectCompare (object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3952)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              {
              object->mProperty_value.setter_insertAtIndex (var_node_124129, var_insertIndex_124072, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3953)) ;
              }
            }
          }
          if (kBoolFalse == test_4) {
            object->mProperty_value.addAssign_operation (var_node_124129  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3955)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3958)).boolEnum () ;
          if (kBoolTrue == test_5) {
            const GALGAS_gtlList temp_6 = object ;
            GALGAS_gtlData var_copy_124379 = temp_6 ;
            callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("list"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3960)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_124379, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3960)) ;
            GALGAS_gtlList temp_7 ;
            if (var_copy_124379.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlList *> (var_copy_124379.ptr ())) {
                temp_7 = (cPtr_gtlList *) var_copy_124379.ptr () ;
              }else{
                inCompiler->castError ("gtlList", var_copy_124379.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3967)) ;
              }
            }
            object->mProperty_value = temp_7.readProperty_value () ;
            object->mProperty_where = var_copy_124379.readProperty_where () ;
            object->mProperty_meta = var_copy_124379.readProperty_meta () ;
          }
        }
        if (kBoolFalse == test_5) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3971)).add_operation (GALGAS_string ("' for list target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3971)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3971)) ;
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                      extensionSetter_gtlList_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlList_performSetter (defineExtensionSetter_gtlList_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList setItemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_setItemAtIndex (cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_data,
                                                    const GALGAS_gtlInt constinArgument_index,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  {
  object->mProperty_value.setter_setValueAtIndex (constinArgument_data, constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3979)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3979)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_setItemAtIndex (void) {
  enterExtensionSetter_setItemAtIndex (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                       extensionSetter_gtlList_setItemAtIndex) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlList_setItemAtIndex (defineExtensionSetter_gtlList_setItemAtIndex, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList deleteItemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_deleteItemAtIndex (cPtr_gtlData * inObject,
                                                       const GALGAS_gtlInt constinArgument_index,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  GALGAS_uint var_indexUint_124940 = constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3985)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, var_indexUint_124940.objectCompare (object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3986)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, var_indexUint_124940.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          object->mProperty_value = object->mProperty_value.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3988)) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_indexUint_124940.objectCompare (object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 3989)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3989)))).boolEnum () ;
          if (kBoolTrue == test_2) {
            object->mProperty_value = object->mProperty_value.getter_subListToIndex (var_indexUint_124940.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3990)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3990)) ;
          }
        }
        if (kBoolFalse == test_2) {
          object->mProperty_value = object->mProperty_value.getter_subListToIndex (var_indexUint_124940.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3992)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3992)).add_operation (object->mProperty_value.getter_subListFromIndex (var_indexUint_124940.add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3993)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3993)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3992)) ;
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_deleteItemAtIndex (void) {
  enterExtensionSetter_deleteItemAtIndex (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                          extensionSetter_gtlList_deleteItemAtIndex) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlList_deleteItemAtIndex (defineExtensionSetter_gtlList_deleteItemAtIndex, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlList itemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlList::method_itemAtIndex (GALGAS_gtlData & outArgument_data,
                                       const GALGAS_gtlInt constinArgument_index,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_data = this->mProperty_value.getter_valueAtIndex (constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4002)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4002)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList hasItemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlList::getter_hasItemAtIndex (const GALGAS_gtlInt constinArgument_index,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (kIsStrictSup, this->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 4009)).objectCompare (constinArgument_index.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4009)))) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlList appendItem'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlList_appendItem (cPtr_gtlData * inObject,
                                                const GALGAS_gtlData constinArgument_item,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlList * object = (cPtr_gtlList *) inObject ;
  macroValidSharedObject (object, cPtr_gtlList) ;
  object->mProperty_value.addAssign_operation (constinArgument_item  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4015)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlList_appendItem (void) {
  enterExtensionSetter_appendItem (kTypeDescriptor_GALGAS_gtlList.mSlotID,
                                   extensionSetter_gtlList_appendItem) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlList_appendItem (defineExtensionSetter_gtlList_appendItem, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_desc (const GALGAS_uint constinArgument_tab,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4027)).add_operation (GALGAS_string ("map: @[\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4027)) ;
  cEnumerator_gtlVarMap enumerator_126050 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_126050.hasCurrentObject ()) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4030))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4030)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4030)).add_operation (enumerator_126050.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4031)).add_operation (GALGAS_string ("\" :>\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4031)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_126050.current_value (HERE).ptr (), constinArgument_tab.add_operation (GALGAS_uint (uint32_t (8U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4032)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4032)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4031)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4030)) ;
    enumerator_126050.gotoNextObject () ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4034)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4034)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4034)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_string (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4038)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlMap::getter_lstring (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4042)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlMap::getter_bool (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4046)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlMap::getter_int (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4050)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlMap::getter_float (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a map to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4054)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_plusOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4058)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_minusOp (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4062)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_notOp (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4066)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4070)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4074)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4078)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4082)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4086)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4090)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4094)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4098)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4102)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4106)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlMap temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlMap *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlMap *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlMap", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4111)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_128432 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_128475 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4113)).objectCompare (var_rValue_128432.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4113)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_128475 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_128475 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_128590 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_128590.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_128432.getter_hasKey (enumerator_128590.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4118)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_128689 ;
              var_rValue_128432.method_get (enumerator_128590.current_lkey (HERE), var_rData_128689, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4119)) ;
              var_equal_128475 = var_equal_128475.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_128590.current_value (HERE).ptr (), var_rData_128689, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4120)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4120)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4120)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_128475 = GALGAS_bool (false) ;
          }
          enumerator_128590.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4126)), var_equal_128475.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 4126))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4126)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4128)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlMap temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlMap *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlMap *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlMap", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4134)) ;
        }
      }
      GALGAS_gtlVarMap var_rValue_129063 = temp_1.readProperty_value () ;
      GALGAS_bool var_equal_129106 ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4136)).objectCompare (var_rValue_129063.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4136)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_equal_129106 = GALGAS_bool (false) ;
        }
      }
      if (kBoolFalse == test_2) {
        var_equal_129106 = GALGAS_bool (true) ;
        cEnumerator_gtlVarMap enumerator_129221 (this->mProperty_value, kENUMERATION_UP) ;
        while (enumerator_129221.hasCurrentObject ()) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_rValue_129063.getter_hasKey (enumerator_129221.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4141)).boolEnum () ;
            if (kBoolTrue == test_3) {
              GALGAS_gtlData var_rData_129320 ;
              var_rValue_129063.method_get (enumerator_129221.current_lkey (HERE), var_rData_129320, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4142)) ;
              var_equal_129106 = var_equal_129106.operator_and (callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_eqOp ((const cPtr_gtlData *) enumerator_129221.current_value (HERE).ptr (), var_rData_129320, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4143)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4143)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4143)) ;
            }
          }
          if (kBoolFalse == test_3) {
            var_equal_129106 = GALGAS_bool (false) ;
          }
          enumerator_129221.gotoNextObject () ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4149)), var_equal_129106  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4149)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("struct expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4151)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the > operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4156)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the >= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4160)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the < operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4164)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("a map does not support the <= operator"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4168)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlMap::getter_embeddedType (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4173)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlMap addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlMap::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     C_Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 4178))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4178)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMap::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("length").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4192)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4192)) ;
      }
      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4195)), this->mProperty_value.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 4196)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 4196))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4193)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4199)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4199)) ;
        }
        const GALGAS_gtlMap temp_2 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4201)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4201))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4200)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4204)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4204)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4206)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4205)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("list").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4209)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4209)) ;
            }
            GALGAS_list var_resultList_131489 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 4210)) ;
            const GALGAS_gtlMap temp_5 = this ;
            cEnumerator_gtlVarMap enumerator_131527 (temp_5.readProperty_value (), kENUMERATION_UP) ;
            while (enumerator_131527.hasCurrentObject ()) {
              var_resultList_131489.addAssign_operation (enumerator_131527.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4212)) ;
              enumerator_131527.gotoNextObject () ;
            }
            result_result = GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4214)), var_resultList_131489  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4214)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("where").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsStrictInf, constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 4216)).objectCompare (GALGAS_uint (uint32_t (1U)))).operator_or (GALGAS_bool (kIsStrictSup, constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 4216)).objectCompare (GALGAS_uint (uint32_t (2U)))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4216)).boolEnum () ;
                if (kBoolTrue == test_7) {
                  TC_Array <C_FixItDescription> fixItArray8 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("where expects 1 ou 2 arguments. ").add_operation (constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 4218)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 4217)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4217)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4218)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4217)) ;
                  result_result.drop () ; // Release error dropped variable
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_9 = kBoolTrue ;
                if (kBoolTrue == test_9) {
                  test_9 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4220)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4220)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr))).boolEnum () ;
                  if (kBoolTrue == test_9) {
                    TC_Array <C_FixItDescription> fixItArray10 ;
                    inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("expression expected for argument 1"), fixItArray10  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4221)) ;
                    result_result.drop () ; // Release error dropped variable
                  }
                }
                if (kBoolFalse == test_9) {
                  GALGAS_gtlStruct var_vars_132066 ;
                  enumGalgasBool test_11 = kBoolTrue ;
                  if (kBoolTrue == test_11) {
                    test_11 = GALGAS_bool (kIsEqual, constinArgument_arguments.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 4224)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
                    if (kBoolTrue == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsNotEqual, constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4225)).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4225)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          TC_Array <C_FixItDescription> fixItArray13 ;
                          inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("struct expected for argument 1"), fixItArray13  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4226)) ;
                          var_vars_132066.drop () ; // Release error dropped variable
                        }
                      }
                      if (kBoolFalse == test_12) {
                        GALGAS_gtlStruct temp_14 ;
                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4228)).isValid ()) {
                          if (NULL != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4228)).ptr ())) {
                            temp_14 = (cPtr_gtlStruct *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4228)).ptr () ;
                          }else{
                            inCompiler->castError ("gtlStruct", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4228)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4228)) ;
                          }
                        }
                        var_vars_132066 = temp_14 ;
                      }
                    }
                  }
                  if (kBoolFalse == test_11) {
                    var_vars_132066 = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4231)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 4231))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4231)) ;
                  }
                  GALGAS_gtlExpr temp_15 ;
                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)).isValid ()) {
                    if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)).ptr ())) {
                      temp_15 = (cPtr_gtlExpr *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)).ptr () ;
                    }else{
                      inCompiler->castError ("gtlExpr", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4233)) ;
                    }
                  }
                  GALGAS_gtlExpression var_expr_132457 = temp_15.readProperty_value () ;
                  GALGAS_gtlVarMap var_resultMap_132535 = GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 4234)) ;
                  cEnumerator_gtlVarMap enumerator_132569 (this->mProperty_value, kENUMERATION_UP) ;
                  while (enumerator_132569.hasCurrentObject ()) {
                    {
                    var_vars_132066.insulate (HERE) ;
                    cPtr_gtlStruct * ptr_132608 = (cPtr_gtlStruct *) var_vars_132066.ptr () ;
                    callExtensionSetter_setStructField ((cPtr_gtlStruct *) ptr_132608, GALGAS_lstring::constructor_new (GALGAS_string ("__item__"), enumerator_132569.current_value (HERE).readProperty_where ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4237)), enumerator_132569.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4237)) ;
                    }
                    GALGAS_gtlData var_evalResult_132706 = callExtensionGetter_eval ((const cPtr_gtlExpression *) var_expr_132457.ptr (), constinArgument_context, var_vars_132066, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4238)) ;
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = callExtensionGetter_bool ((const cPtr_gtlData *) var_evalResult_132706.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4239)).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        var_resultMap_132535.setter_put (enumerator_132569.current_lkey (HERE), enumerator_132569.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4240)) ;
                        }
                      }
                    }
                    enumerator_132569.gotoNextObject () ;
                  }
                  result_result = GALGAS_gtlMap::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4245)), var_resultMap_132535  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4243)) ;
                }
              }
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_17 = kBoolTrue ;
            if (kBoolTrue == test_17) {
              test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_17) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4251)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4251)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4253)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4252)) ;
              }
            }
            if (kBoolFalse == test_17) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4255)).boolEnum () ;
                if (kBoolTrue == test_18) {
                  const GALGAS_gtlMap temp_19 = this ;
                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4256)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_19, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4256)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4264)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4264)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4266)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4266))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4265)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  TC_Array <C_FixItDescription> fixItArray21 ;
                  inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4269)).add_operation (GALGAS_string ("' for map target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4269)), fixItArray21  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4269)) ;
                  result_result.drop () ; // Release error dropped variable
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
//Overriding extension setter '@gtlMap performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlMap_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlMap * object = (cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4284)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4284)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4285)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_134130 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_134130.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4286)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4286)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4289)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4289)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4291)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlMap temp_4 = object ;
          GALGAS_gtlData var_copy_134425 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("map"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4293)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_134425, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4293)) ;
          GALGAS_gtlMap temp_5 ;
          if (var_copy_134425.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlMap *> (var_copy_134425.ptr ())) {
              temp_5 = (cPtr_gtlMap *) var_copy_134425.ptr () ;
            }else{
              inCompiler->castError ("gtlMap", var_copy_134425.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4300)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_134425.readProperty_where () ;
          object->mProperty_meta = var_copy_134425.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4304)).add_operation (GALGAS_string ("' for map target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4304)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4304)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlMap_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                      extensionSetter_gtlMap_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlMap_performSetter (defineExtensionSetter_gtlMap_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlMap setMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlMap_setMapItem (cPtr_gtlData * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlData constinArgument_data,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlMap * object = (cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  {
  extensionSetter_replaceOrCreate (object->mProperty_value, constinArgument_name, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4315)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlMap_setMapItem (void) {
  enterExtensionSetter_setMapItem (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                   extensionSetter_gtlMap_setMapItem) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlMap_setMapItem (defineExtensionSetter_gtlMap_setMapItem, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlMap deleteMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlMap_deleteMapItem (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_name,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlMap * object = (cPtr_gtlMap *) inObject ;
  macroValidSharedObject (object, cPtr_gtlMap) ;
  {
  GALGAS_gtlData joker_135142 ; // Joker input parameter
  object->mProperty_value.setter_del (constinArgument_name, joker_135142, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4321)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlMap_deleteMapItem (void) {
  enterExtensionSetter_deleteMapItem (kTypeDescriptor_GALGAS_gtlMap.mSlotID,
                                      extensionSetter_gtlMap_deleteMapItem) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlMap_deleteMapItem (defineExtensionSetter_gtlMap_deleteMapItem, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlMap mapItem'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlMap::method_mapItem (const GALGAS_lstring constinArgument_name,
                                  GALGAS_gtlData & outArgument_result,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4328)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_value.method_get (constinArgument_name, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4329)) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_result = GALGAS_gtlUnconstructed::constructor_new (constinArgument_name.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4331))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4331)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap hasMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlMap::getter_hasMapItem (const GALGAS_lstring constinArgument_name,
                                            C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_value.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4339)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExpr::getter_desc (const GALGAS_uint constinArgument_tab,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4351)).add_operation (GALGAS_string ("expression: @\? "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4351)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4352)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4352)).add_operation (GALGAS_string (" \?\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4352)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExpr::getter_string (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4356)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlExpr::getter_lstring (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4360)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlExpr::getter_bool (C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4364)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlExpr::getter_int (C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4368)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlExpr::getter_float (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an expression to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4372)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_plusOp (C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlExpr temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_minusOp (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4382)), GALGAS_gtlMinusExpression::constructor_new (this->mProperty_where, this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4383))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4380)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_notOp (C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4390)), GALGAS_gtlNotExpression::constructor_new (this->mProperty_where, this->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4391))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4388)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4400)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4399)), GALGAS_gtlAddExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4400))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4397)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4403)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4412)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4411)), GALGAS_gtlSubstractExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4412))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4409)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4415)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4424)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4423)), GALGAS_gtlMultiplyExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4424))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4421)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4427)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4436)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4435)), GALGAS_gtlDivideExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4436))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4433)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4439)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_modOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4448)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4447)), GALGAS_gtlModulusExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4448))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4445)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4451)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4460)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4459)), GALGAS_gtlAndExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4460))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4457)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4463)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4472)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4471)), GALGAS_gtlOrExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4472))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4469)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4475)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4484)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4483)), GALGAS_gtlXorExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4484))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4481)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4487)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_slOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4496)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4495)), GALGAS_gtlShiftLeftExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4496))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4493)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4499)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_srOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4508)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4507)), GALGAS_gtlShiftRightExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4508))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4505)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4511)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4520)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4519)), GALGAS_gtlNotEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4520))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4517)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4523)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4532)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4531)), GALGAS_gtlEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4532))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4529)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4535)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4544)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4543)), GALGAS_gtlGreaterThanExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4544))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4541)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4547)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4556)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4555)), GALGAS_gtlGreaterOrEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4556))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4553)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4559)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4568)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4567)), GALGAS_gtlLowerThanExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4568))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4565)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4571)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlExpr).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlExpr temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlExpr *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlExpr *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlExpr", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4580)) ;
        }
      }
      result_result = GALGAS_gtlExpr::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4579)), GALGAS_gtlLowerOrEqualExpression::constructor_new (this->mProperty_where, this->mProperty_value, temp_1.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4580))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4577)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("Expression expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4583)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlExpr::getter_embeddedType (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("expression forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4589)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlExpr addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlExpr::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 4594))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4594)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExpr::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("eval"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_structArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4608)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4608)) ;
      }
      GALGAS_gtlData var_vars_142793 = constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4609)) ;
      result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), constinArgument_context, var_vars_142793, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4610)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4612)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4612)) ;
        }
        const GALGAS_gtlExpr temp_2 = this ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4614)), temp_2.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 4614))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4613)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4617)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4617)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4619)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4618)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4622)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4622)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4624)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4623)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4627)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4627)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4629)), this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4629))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4628)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4631)).boolEnum () ;
              if (kBoolTrue == test_6) {
                const GALGAS_gtlExpr temp_7 = this ;
                result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4632)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4632)) ;
              }
            }
            if (kBoolFalse == test_6) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4640)).add_operation (GALGAS_string ("' for expression target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4640)), fixItArray8  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4640)) ;
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
//Overriding extension setter '@gtlExpr performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlExpr_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlExpr * object = (cPtr_gtlExpr *) inObject ;
  macroValidSharedObject (object, cPtr_gtlExpr) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4655)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4655)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4656)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4656)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4656)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4656)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4656)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_144441 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_144441.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4657)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4657)) ;
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
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4660)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4660)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4662)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlExpr temp_4 = object ;
          GALGAS_gtlData var_copy_144743 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("expression"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4664)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_144743, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4664)) ;
          GALGAS_gtlExpr temp_5 ;
          if (var_copy_144743.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlExpr *> (var_copy_144743.ptr ())) {
              temp_5 = (cPtr_gtlExpr *) var_copy_144743.ptr () ;
            }else{
              inCompiler->castError ("gtlExpr", var_copy_144743.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4671)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_144743.readProperty_where () ;
          object->mProperty_meta = var_copy_144743.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4675)).add_operation (GALGAS_string ("' for expression target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4675)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 4675)) ;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlExpr_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlExpr.mSlotID,
                                      extensionSetter_gtlExpr_performSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlExpr_performSetter (defineExtensionSetter_gtlExpr_performSetter, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetUnconstructedInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetUnconstructedInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlUnconstructed::constructor_new (callExtensionGetter_location ((const cPtr_gtlVarItem *) this->mProperty_lValue.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 126)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 126)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 126))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 125)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 125)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                             GALGAS_gtlData & ioArgument_vars,
                                             GALGAS_library & ioArgument_lib,
                                             GALGAS_string & /* ioArgument_outputString */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 149)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 149)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAddInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetAddInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & ioArgument_vars,
                                                GALGAS_library & ioArgument_lib,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_addOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 167)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 168)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 167)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 163)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetSubstractInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetSubstractInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_subOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 187)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 188)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 187)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 183)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetMultiplyInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetMultiplyInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                     GALGAS_gtlData & ioArgument_vars,
                                                     GALGAS_library & ioArgument_lib,
                                                     GALGAS_string & /* ioArgument_outputString */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_mulOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 207)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 208)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 207)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 203)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetDivideInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetDivideInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_divOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 227)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 228)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 227)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 223)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetModuloInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetModuloInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_divOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 247)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 248)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 247)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 243)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftLeftInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftLeftInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_slOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 267)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 268)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 267)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 263)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftRightInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftRightInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                       GALGAS_gtlData & ioArgument_vars,
                                                       GALGAS_library & ioArgument_lib,
                                                       GALGAS_string & /* ioArgument_outputString */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_srOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 287)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 288)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 287)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 283)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAndInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetAndInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & ioArgument_vars,
                                                GALGAS_library & ioArgument_lib,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_andOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 307)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 308)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 307)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 303)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetOrInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetOrInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_gtlData & ioArgument_vars,
                                               GALGAS_library & ioArgument_lib,
                                               GALGAS_string & /* ioArgument_outputString */,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_orOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 327)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 328)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 327)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 323)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetXorInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetXorInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & ioArgument_vars,
                                                GALGAS_library & ioArgument_lib,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_set (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, callExtensionGetter_xorOp ((const cPtr_gtlData *) extensionGetter_get (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 347)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 348)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 347)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 343)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlUnletInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlUnletInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_gtlData & ioArgument_vars,
                                               GALGAS_library & ioArgument_lib,
                                               GALGAS_string & /* ioArgument_outputString */,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_delete (this->mProperty_lValue, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 363)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateStringInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateStringInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & ioArgument_outputString,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_outputString.plusAssign_operation(this->mProperty_value, inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 383)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEmitInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlEmitInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & ioArgument_vars,
                                              GALGAS_library & ioArgument_lib,
                                              GALGAS_string & ioArgument_outputString,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_outputString.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 399)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 399)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 399)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWriteToInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                 GALGAS_gtlData & ioArgument_vars,
                                                 GALGAS_library & ioArgument_lib,
                                                 GALGAS_string & /* ioArgument_outputString */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_currentErrorCount_12242 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 418)) ;
  GALGAS_string var_fullFileName_12288 = callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileNameExpression.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 419)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 419)) ;
  GALGAS_gtlString var_fileName_12371 = GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 422)), var_fullFileName_12288.getter_lastPathComponent (SOURCE_FILE ("gtl_instructions.galgas", 423))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 420)) ;
  GALGAS_gtlString var_filePath_12478 = GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 427)), var_fullFileName_12288.getter_nativePathWithUnixPath (SOURCE_FILE ("gtl_instructions.galgas", 428))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 425)) ;
  GALGAS_string var_result_12583 = GALGAS_string::makeEmptyString () ;
  GALGAS_gtlData var_varsCopy_12608 = ioArgument_vars ;
  {
  var_varsCopy_12608.insulate (HERE) ;
  cPtr_gtlData * ptr_12710 = (cPtr_gtlData *) var_varsCopy_12608.ptr () ;
  callExtensionSetter_setStructFieldAtLevel ((cPtr_gtlData *) ptr_12710, GALGAS_lstring::constructor_new (GALGAS_string ("FILENAME"), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 435)), var_fileName_12371, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 434)) ;
  }
  {
  var_varsCopy_12608.insulate (HERE) ;
  cPtr_gtlData * ptr_12809 = (cPtr_gtlData *) var_varsCopy_12608.ptr () ;
  callExtensionSetter_setStructFieldAtLevel ((cPtr_gtlData *) ptr_12809, GALGAS_lstring::constructor_new (GALGAS_string ("FILEPATH"), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 440)), var_filePath_12478, GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 439)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_currentErrorCount_12242.objectCompare (GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 445)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      extensionMethod_execute (this->mProperty_instructions, ioArgument_context, var_varsCopy_12608, ioArgument_lib, var_result_12583, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 446)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, var_currentErrorCount_12242.objectCompare (GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 447)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = this->mProperty_isExecutable.boolEnum () ;
            if (kBoolTrue == test_2) {
              GALGAS_string var_directory_13119 = var_fullFileName_12288.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("gtl_instructions.galgas", 449)) ;
              enumGalgasBool test_3 = kBoolTrue ;
              if (kBoolTrue == test_3) {
                test_3 = GALGAS_bool (kIsNotEqual, var_directory_13119.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                if (kBoolTrue == test_3) {
                  var_directory_13119.method_makeDirectory (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 450)) ;
                }
              }
              var_result_12583.method_writeToExecutableFile (var_fullFileName_12288, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 451)) ;
            }
          }
          if (kBoolFalse == test_2) {
            var_result_12583.method_makeDirectoryAndWriteToFile (var_fullFileName_12288, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 453)) ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                  GALGAS_gtlData & ioArgument_vars,
                                                  GALGAS_library & ioArgument_lib,
                                                  GALGAS_string & ioArgument_outputString,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlContext var_newContext_14009 = ioArgument_context ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_prefix.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_newContext_14009.setter_setPrefix (this->mProperty_prefix COMMA_SOURCE_FILE ("gtl_instructions.galgas", 480)) ;
      }
    }
  }
  GALGAS_gtlString temp_1 ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).isValid ()) {
    if (NULL != dynamic_cast <const cPtr_gtlString *> (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr ())) {
      temp_1 = (cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr () ;
    }else{
      inCompiler->castError ("gtlString", callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)) ;
    }
  }
  GALGAS_lstring var_templateFileName_14119 = callExtensionGetter_fullTemplateFileName ((const cPtr_gtlContext *) var_newContext_14009.ptr (), ioArgument_context, ioArgument_vars, callExtensionGetter_lstring ((const cPtr_gtlString *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 486)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 483)) ;
  GALGAS_gtlData var_localVars_14270 ;
  {
  var_newContext_14009.setter_setInputVars (GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_instructions.galgas", 490)) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 490)) ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = this->mProperty_isGlobal.operator_not (SOURCE_FILE ("gtl_instructions.galgas", 491)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_localVars_14270 = GALGAS_gtlStruct::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 493)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_instructions.galgas", 493))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 493)) ;
      cEnumerator_gtlExpressionList enumerator_14478 (this->mProperty_arguments, kENUMERATION_UP) ;
      while (enumerator_14478.hasCurrentObject ()) {
        GALGAS_gtlData var_evaluedArg_14525 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_14478.current_expression (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 495)) ;
        {
        var_newContext_14009.insulate (HERE) ;
        cPtr_gtlContext * ptr_14593 = (cPtr_gtlContext *) var_newContext_14009.ptr () ;
        callExtensionSetter_addInputVariable ((cPtr_gtlContext *) ptr_14593, var_evaluedArg_14525, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 496)) ;
        }
        enumerator_14478.gotoNextObject () ;
      }
    }
  }
  if (kBoolFalse == test_2) {
    var_localVars_14270 = ioArgument_vars ;
  }
  GALGAS_bool var_found_14779 ;
  GALGAS_gtlTemplate var_result_14808 ;
  {
  ioArgument_lib.insulate (HERE) ;
  cPtr_library * ptr_14677 = (cPtr_library *) ioArgument_lib.ptr () ;
  callExtensionSetter_getTemplate ((cPtr_library *) ptr_14677, var_newContext_14009, var_templateFileName_14119, this->mProperty_ifExists, ioArgument_lib, var_found_14779, var_result_14808, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 502)) ;
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_found_14779.boolEnum () ;
    if (kBoolTrue == test_3) {
      callExtensionMethod_execute ((cPtr_gtlTemplate *) var_result_14808.ptr (), var_newContext_14009, var_localVars_14270, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 512)) ;
    }
  }
  if (kBoolFalse == test_3) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      test_4 = this->mProperty_ifExists.boolEnum () ;
      if (kBoolTrue == test_4) {
        GALGAS_gtlData var_localMap_14950 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 515)) ;
        extensionMethod_execute (this->mProperty_instructionsIfNotFound, ioArgument_context, var_localMap_14950, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 516)) ;
        ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_14950.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 517)) ;
      }
    }
  }
  {
  ioArgument_context.setter_setDebuggerContext (var_newContext_14009.readProperty_debuggerContext () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 521)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlGetColumnInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlGetColumnInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & ioArgument_outputString,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_value_15717 = GALGAS_string::makeEmptyString () ;
  GALGAS_bool var_searchEndOfLine_15746 = GALGAS_bool (true) ;
  GALGAS_uint var_index_15767 = ioArgument_outputString.getter_length (SOURCE_FILE ("gtl_instructions.galgas", 540)) ;
  if (ioArgument_outputString.getter_length (SOURCE_FILE ("gtl_instructions.galgas", 541)).isValid ()) {
    uint32_t variant_15798 = ioArgument_outputString.getter_length (SOURCE_FILE ("gtl_instructions.galgas", 541)).uintValue () ;
    bool loop_15798 = true ;
    while (loop_15798) {
      loop_15798 = GALGAS_bool (kIsStrictSup, var_index_15767.objectCompare (GALGAS_uint (uint32_t (0U)))).operator_and (var_searchEndOfLine_15746 COMMA_SOURCE_FILE ("gtl_instructions.galgas", 541)).isValid () ;
      if (loop_15798) {
        loop_15798 = GALGAS_bool (kIsStrictSup, var_index_15767.objectCompare (GALGAS_uint (uint32_t (0U)))).operator_and (var_searchEndOfLine_15746 COMMA_SOURCE_FILE ("gtl_instructions.galgas", 541)).boolValue () ;
      }
      if (loop_15798 && (0 == variant_15798)) {
        loop_15798 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 541)) ;
      }
      if (loop_15798) {
        variant_15798 -- ;
        var_searchEndOfLine_15746 = GALGAS_bool (kIsNotEqual, ioArgument_outputString.getter_characterAtIndex (var_index_15767.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 542)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 542)).objectCompare (GALGAS_char (TO_UNICODE (10)))) ;
        var_index_15767.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 543)) ;
        enumGalgasBool test_0 = kBoolTrue ;
        if (kBoolTrue == test_0) {
          test_0 = var_searchEndOfLine_15746.boolEnum () ;
          if (kBoolTrue == test_0) {
            var_value_15717.plusAssign_operation(GALGAS_string (" "), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 545)) ;
          }
        }
      }
    }
  }
  extensionMethod_set (this->mProperty_destVariable, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlString::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 552)), var_value_15717  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 552)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 548)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlIfStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlIfStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                     GALGAS_gtlData & ioArgument_vars,
                                                     GALGAS_library & ioArgument_lib,
                                                     GALGAS_string & ioArgument_outputString,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_16728 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 576)) ;
  GALGAS_bool var_noConditionMatching_16780 = GALGAS_bool (true) ;
  cEnumerator_gtlThenElsifStatementList enumerator_16796 (this->mProperty_thenElsifList, kENUMERATION_UP) ;
  bool bool_0 = var_noConditionMatching_16780.isValidAndTrue () ;
  if (enumerator_16796.hasCurrentObject () && bool_0) {
    while (enumerator_16796.hasCurrentObject () && bool_0) {
      GALGAS_gtlData var_dataCondition_16873 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_16796.current_condition (HERE).ptr (), ioArgument_context, var_localMap_16728, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 580)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (var_dataCondition_16873.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlBool temp_2 ;
          if (var_dataCondition_16873.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlBool *> (var_dataCondition_16873.ptr ())) {
              temp_2 = (cPtr_gtlBool *) var_dataCondition_16873.ptr () ;
            }else{
              inCompiler->castError ("gtlBool", var_dataCondition_16873.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 582)) ;
            }
          }
          GALGAS_bool var_boolCondition_16987 = temp_2.readProperty_value () ;
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = var_boolCondition_16987.boolEnum () ;
            if (kBoolTrue == test_3) {
              extensionMethod_execute (enumerator_16796.current_instructionList (HERE), ioArgument_context, var_localMap_16728, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 584)) ;
              var_noConditionMatching_16780 = GALGAS_bool (false) ;
            }
          }
        }
      }
      if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_dataCondition_16873.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 588)), GALGAS_string ("bool expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 588)) ;
      }
      enumerator_16796.gotoNextObject () ;
      if (enumerator_16796.hasCurrentObject ()) {
        bool_0 = var_noConditionMatching_16780.isValidAndTrue () ;
      }
    }
  }
  enumGalgasBool test_5 = kBoolTrue ;
  if (kBoolTrue == test_5) {
    test_5 = var_noConditionMatching_16780.boolEnum () ;
    if (kBoolTrue == test_5) {
      extensionMethod_execute (this->mProperty_elseList, ioArgument_context, var_localMap_16728, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 592)) ;
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_16728.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 595)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForeachStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & ioArgument_outputString,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_20565 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 706)) ;
  GALGAS_gtlData var_iterableData_20614 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_iterable.ptr (), ioArgument_context, var_localMap_20565, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 707)) ;
  if (var_iterableData_20614.isValid ()) {
    if (var_iterableData_20614.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_20707_iterableMap ((cPtr_gtlMap *) var_iterableData_20614.ptr ()) ;
      const GALGAS_gtlForeachStatementInstruction temp_0 = this ;
      callExtensionMethod_iterateOnMap ((cPtr_gtlForeachStatementInstruction *) temp_0.ptr (), ioArgument_context, var_localMap_20565, ioArgument_lib, ioArgument_outputString, cast_20707_iterableMap, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 710)) ;
    }else if (var_iterableData_20614.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_20819_iterableList ((cPtr_gtlList *) var_iterableData_20614.ptr ()) ;
      const GALGAS_gtlForeachStatementInstruction temp_1 = this ;
      callExtensionMethod_iterateOnList ((cPtr_gtlForeachStatementInstruction *) temp_1.ptr (), ioArgument_context, var_localMap_20565, ioArgument_lib, ioArgument_outputString, cast_20819_iterableList, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 712)) ;
    }else if (var_iterableData_20614.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet) {
      GALGAS_gtlSet cast_20932_iterableSet ((cPtr_gtlSet *) var_iterableData_20614.ptr ()) ;
      const GALGAS_gtlForeachStatementInstruction temp_2 = this ;
      callExtensionMethod_iterateOnSet ((cPtr_gtlForeachStatementInstruction *) temp_2.ptr (), ioArgument_context, var_localMap_20565, ioArgument_lib, ioArgument_outputString, cast_20932_iterableSet, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 714)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_iterable.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 716)), GALGAS_string ("Map, list or set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 716)) ;
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_20565.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 718)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & ioArgument_outputString,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_indexName_21680 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), this->mProperty_where  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 737)) ;
  GALGAS_gtlData var_localMap_21724 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 738)) ;
  cEnumerator_gtlExpressionList enumerator_21754 (this->mProperty_iterable, kENUMERATION_UP) ;
  GALGAS_uint index_21751 ((uint32_t) 0) ;
  while (enumerator_21754.hasCurrentObject ()) {
    GALGAS_gtlData var_value_21802 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_21754.current_expression (HERE).ptr (), ioArgument_context, var_localMap_21724, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 741)) ;
    {
    var_localMap_21724.insulate (HERE) ;
    cPtr_gtlData * ptr_21862 = (cPtr_gtlData *) var_localMap_21724.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_21862, this->mProperty_identifier, var_value_21802, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 742)) ;
    }
    {
    var_localMap_21724.insulate (HERE) ;
    cPtr_gtlData * ptr_21913 = (cPtr_gtlData *) var_localMap_21724.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_21913, var_indexName_21680, GALGAS_gtlInt::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 745)), index_21751.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 745))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 745)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 743)) ;
    }
    extensionMethod_execute (this->mProperty_doList, ioArgument_context, var_localMap_21724, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 747)) ;
    if (enumerator_21754.hasNextObject ()) {
      extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, var_localMap_21724, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 749)) ;
    }
    enumerator_21754.gotoNextObject () ;
    index_21751.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 739)) ;
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_21724.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 751)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoopStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                       GALGAS_gtlData & ioArgument_vars,
                                                       GALGAS_library & ioArgument_lib,
                                                       GALGAS_string & ioArgument_outputString,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_22898 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 775)) ;
  GALGAS_gtlData var_startData_22944 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_start.ptr (), ioArgument_context, var_localMap_22898, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 776)) ;
  GALGAS_gtlData var_stopData_23007 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_stop.ptr (), ioArgument_context, var_localMap_22898, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 777)) ;
  GALGAS_gtlData var_stepData_23071 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_step.ptr (), ioArgument_context, var_localMap_22898, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 778)) ;
  GALGAS_bigint var_startVal_23130 ;
  GALGAS_bigint var_stopVal_23152 ;
  GALGAS_bigint var_stepVal_23174 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (var_startData_22944.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (var_startData_22944.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_startData_22944.ptr ())) {
          temp_1 = (cPtr_gtlInt *) var_startData_22944.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_startData_22944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 783)) ;
        }
      }
      var_startVal_23130 = temp_1.readProperty_value () ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_start.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 785)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 785)) ;
    var_startVal_23130.drop () ; // Release error dropped variable
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = GALGAS_bool (var_stopData_23007.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_gtlInt temp_4 ;
      if (var_stopData_23007.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_stopData_23007.ptr ())) {
          temp_4 = (cPtr_gtlInt *) var_stopData_23007.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_stopData_23007.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 788)) ;
        }
      }
      var_stopVal_23152 = temp_4.readProperty_value () ;
    }
  }
  if (kBoolFalse == test_3) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_stop.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 790)), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 790)) ;
    var_stopVal_23152.drop () ; // Release error dropped variable
  }
  enumGalgasBool test_6 = kBoolTrue ;
  if (kBoolTrue == test_6) {
    test_6 = GALGAS_bool (var_stepData_23071.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_6) {
      GALGAS_gtlInt temp_7 ;
      if (var_stepData_23071.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_stepData_23071.ptr ())) {
          temp_7 = (cPtr_gtlInt *) var_stepData_23071.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_stepData_23071.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 793)) ;
        }
      }
      var_stepVal_23174 = temp_7.readProperty_value ().multiply_operation (this->mProperty_upDown.getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 793)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 793)) ;
    }
  }
  if (kBoolFalse == test_6) {
    TC_Array <C_FixItDescription> fixItArray8 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_step.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 795)), GALGAS_string ("int expected"), fixItArray8  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 795)) ;
    var_stepVal_23174.drop () ; // Release error dropped variable
  }
  GALGAS_bigint var_direction_23636 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 797)) ;
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = GALGAS_bool (kIsStrictInf, var_stepVal_23174.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 798)))).boolEnum () ;
    if (kBoolTrue == test_9) {
      var_direction_23636 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 798)) ;
    }
  }
  enumGalgasBool test_10 = kBoolTrue ;
  if (kBoolTrue == test_10) {
    test_10 = GALGAS_bool (kIsSupOrEqual, var_stopVal_23152.substract_operation (var_startVal_23130, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 799)).multiply_operation (var_direction_23636, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 799)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 799)))).boolEnum () ;
    if (kBoolTrue == test_10) {
      extensionMethod_execute (this->mProperty_beforeList, ioArgument_context, var_localMap_22898, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 800)) ;
      GALGAS_uint var_count_23816 = var_stopVal_23152.substract_operation (var_startVal_23130, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)).multiply_operation (var_direction_23636, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 801)) ;
      if (var_count_23816.isValid ()) {
        uint32_t variant_23871 = var_count_23816.uintValue () ;
        bool loop_23871 = true ;
        while (loop_23871) {
            {
            var_localMap_22898.insulate (HERE) ;
            cPtr_gtlData * ptr_23897 = (cPtr_gtlData *) var_localMap_22898.ptr () ;
            callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_23897, this->mProperty_identifier, GALGAS_gtlInt::constructor_new (this->mProperty_identifier.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 805)), var_startVal_23130  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 805)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 803)) ;
            }
            extensionMethod_execute (this->mProperty_doList, ioArgument_context, var_localMap_22898, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 807)) ;
            var_startVal_23130 = var_startVal_23130.add_operation (var_stepVal_23174, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 808)) ;
          loop_23871 = GALGAS_bool (kIsSupOrEqual, var_stopVal_23152.substract_operation (var_startVal_23130, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).multiply_operation (var_direction_23636, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)))).isValid () ;
          if (loop_23871) {
            loop_23871 = GALGAS_bool (kIsSupOrEqual, var_stopVal_23152.substract_operation (var_startVal_23130, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).multiply_operation (var_direction_23636, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 809)))).boolValue () ;
          }
          if (loop_23871 && (0 == variant_23871)) {
            loop_23871 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 802)) ;
          }
          if (loop_23871) {
            variant_23871 -- ;
            extensionMethod_execute (this->mProperty_betweenList, ioArgument_context, var_localMap_22898, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 810)) ;
          }
        }
      }
      extensionMethod_execute (this->mProperty_afterList, ioArgument_context, var_localMap_22898, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 812)) ;
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_22898.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 814)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlRepeatStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                         GALGAS_gtlData & ioArgument_vars,
                                                         GALGAS_library & ioArgument_lib,
                                                         GALGAS_string & ioArgument_outputString,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_localMap_24908 = callExtensionGetter_overrideMap ((const cPtr_gtlData *) ioArgument_vars.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 833)) ;
  GALGAS_bool var_boolCondition_24951 = GALGAS_bool (false) ;
  GALGAS_gtlData var_limitData_24984 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_limit.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 835)) ;
  GALGAS_uint var_limitVal_25040 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (var_limitData_24984.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (var_limitData_24984.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_limitData_24984.ptr ())) {
          temp_1 = (cPtr_gtlInt *) var_limitData_24984.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_limitData_24984.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 839)) ;
        }
      }
      var_limitVal_25040 = temp_1.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 839)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_limit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 841)), GALGAS_string ("int exprected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 841)) ;
    var_limitVal_25040.drop () ; // Release error dropped variable
  }
  if (var_limitVal_25040.isValid ()) {
    uint32_t variant_25196 = var_limitVal_25040.uintValue () ;
    bool loop_25196 = true ;
    while (loop_25196) {
        extensionMethod_execute (this->mProperty_continueList, ioArgument_context, var_localMap_24908, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 845)) ;
        GALGAS_gtlData var_conditionData_25307 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_condition.ptr (), ioArgument_context, var_localMap_24908, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 846)) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_conditionData_25307.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 847)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool))).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_gtlBool temp_4 ;
            if (var_conditionData_25307.isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlBool *> (var_conditionData_25307.ptr ())) {
                temp_4 = (cPtr_gtlBool *) var_conditionData_25307.ptr () ;
              }else{
                inCompiler->castError ("gtlBool", var_conditionData_25307.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 848)) ;
              }
            }
            var_boolCondition_24951 = temp_4.readProperty_value () ;
          }
        }
        if (kBoolFalse == test_3) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_conditionData_25307.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 850)), GALGAS_string ("bool expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 850)) ;
        }
      loop_25196 = var_boolCondition_24951.isValid () ;
      if (loop_25196) {
        loop_25196 = var_boolCondition_24951.boolValue () ;
      }
      if (loop_25196 && (0 == variant_25196)) {
        loop_25196 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 844)) ;
      }
      if (loop_25196) {
        variant_25196 -- ;
        extensionMethod_execute (this->mProperty_doList, ioArgument_context, var_localMap_24908, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 853)) ;
      }
    }
  }
  ioArgument_vars = callExtensionGetter_overriddenMap ((const cPtr_gtlData *) var_localMap_24908.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 855)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlErrorStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & ioArgument_lib,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location var_errorLocation_26192 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_hereInstead.boolEnum () ;
    if (kBoolTrue == test_0) {
      var_errorLocation_26192 = this->mProperty_where ;
    }
  }
  if (kBoolFalse == test_0) {
    var_errorLocation_26192 = extensionGetter_get (this->mProperty_identifier, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 877)).readProperty_where () ;
  }
  GALGAS_gtlData var_errorMessageData_26351 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_errorMessage.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 879)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_errorMessageData_26351.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 880)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_gtlString temp_2 ;
      if (var_errorMessageData_26351.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (var_errorMessageData_26351.ptr ())) {
          temp_2 = (cPtr_gtlString *) var_errorMessageData_26351.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_errorMessageData_26351.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 881)) ;
        }
      }
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (var_errorLocation_26192, temp_2.readProperty_value (), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 881)) ;
      {
      ioArgument_context.setter_setPropagateError (GALGAS_bool (false) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 882)) ;
      }
    }
  }
  if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_errorMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 884)), GALGAS_string ("string expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 884)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWarningStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location var_warningLocation_27176 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_hereInstead.boolEnum () ;
    if (kBoolTrue == test_0) {
      var_warningLocation_27176 = this->mProperty_where ;
    }
  }
  if (kBoolFalse == test_0) {
    var_warningLocation_27176 = extensionGetter_get (this->mProperty_identifier, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 907)).readProperty_where () ;
  }
  GALGAS_gtlData var_warningMessageData_27341 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_warningMessage.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 909)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_warningMessageData_27341.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 910)).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_gtlString temp_2 ;
      if (var_warningMessageData_27341.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (var_warningMessageData_27341.ptr ())) {
          temp_2 = (cPtr_gtlString *) var_warningMessageData_27341.ptr () ;
        }else{
          inCompiler->castError ("gtlString", var_warningMessageData_27341.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 911)) ;
        }
      }
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticWarning (var_warningLocation_27176, temp_2.readProperty_value (), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 911)) ;
    }
  }
  if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_warningMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 913)), GALGAS_string ("string expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 913)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlPrintStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlPrintStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & ioArgument_lib,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_messageToPrintString_28108 = callExtensionGetter_string ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_messageToPrint.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 932)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 932)) ;
  inCompiler->printMessage (var_messageToPrintString_28108  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 933)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_carriageReturn.boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 934)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDisplayStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDisplayStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_variable_28721 = extensionGetter_get (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 950)) ;
  inCompiler->printMessage (extensionGetter_stringPath (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)).add_operation (GALGAS_string (" from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)).add_operation (this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952)).add_operation (callExtensionGetter_desc ((const cPtr_gtlData *) var_variable_28721.ptr (), GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 953)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 952))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 951)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlAbstractSortInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlAbstractSortInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & /* ioArgument_outputString */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_variable_30657 = extensionGetter_get (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1024)) ;
  if (var_variable_30657.isValid ()) {
    if (var_variable_30657.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_30746_variableList ((cPtr_gtlList *) var_variable_30657.ptr ()) ;
      GALGAS_list var_listToSort_30768 = cast_30746_variableList.readProperty_value () ;
      GALGAS_uint var_length_30812 = var_listToSort_30768.getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1028)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsStrictSup, var_length_30812.objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          const GALGAS_gtlAbstractSortInstruction temp_1 = this ;
          callExtensionMethod_sort ((cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), var_listToSort_30768, GALGAS_uint (uint32_t (0U)), var_length_30812.substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1030)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1030)) ;
        }
      }
      extensionMethod_set (this->mProperty_variablePath, ioArgument_context, ioArgument_vars, ioArgument_lib, GALGAS_gtlList::constructor_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1036)), var_listToSort_30768  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1036)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1032)) ;
    }else{
      GALGAS_gtlVarItem var_lastComponent_31101 ;
      this->mProperty_variablePath.method_last (var_lastComponent_31101, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1039)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_lastComponent_31101.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1040)), GALGAS_string ("list expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1040)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSortStatementStructInstruction compare'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_gtlSortStatementStructInstruction::getter_compare (const GALGAS_gtlData constinArgument_s_31_,
                                                                    const GALGAS_gtlData constinArgument_s_32_,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result_result ; // Returned variable
  const GALGAS_gtlSortStatementStructInstruction temp_0 = this ;
  result_result = callExtensionGetter_compareElements ((const cPtr_gtlSortStatementStructInstruction *) temp_0.ptr (), constinArgument_s_31_, constinArgument_s_32_, this->mProperty_sortingKey, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1054)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSortStatementInstruction compare'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_gtlSortStatementInstruction::getter_compare (const GALGAS_gtlData constinArgument_s_31_,
                                                              const GALGAS_gtlData constinArgument_s_32_,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_ltOp ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), constinArgument_s_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1101)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1108)).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1102)).multiply_operation (this->mProperty_order.readProperty_sint ().getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 1102)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1102)).getter_sint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1102)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_gtOp ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), constinArgument_s_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1104)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1107)).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_result = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1105)).multiply_operation (this->mProperty_order.readProperty_sint ().getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 1105)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1105)).getter_sint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1105)) ;
      }
    }
    if (kBoolFalse == test_1) {
      result_result = GALGAS_sint (int32_t (0L)) ;
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTabStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTabStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                      GALGAS_gtlData & ioArgument_vars,
                                                      GALGAS_library & ioArgument_lib,
                                                      GALGAS_string & ioArgument_outputString,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_tabValueData_33433 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_tabValue.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1125)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (var_tabValueData_33433.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (var_tabValueData_33433.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_tabValueData_33433.ptr ())) {
          temp_1 = (cPtr_gtlInt *) var_tabValueData_33433.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", var_tabValueData_33433.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1127)) ;
        }
      }
      GALGAS_gtlInt var_tabValueInt_33536 = temp_1 ;
      GALGAS_uint var_currentColumn_33590 = ioArgument_outputString.getter_currentColumn (SOURCE_FILE ("gtl_instructions.galgas", 1128)) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_tabValueInt_33536.readProperty_value ().objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1129)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_uint var_tabColumn_33684 = var_tabValueInt_33536.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1130)) ;
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = GALGAS_bool (kIsStrictSup, var_tabColumn_33684.objectCompare (var_currentColumn_33590)).boolEnum () ;
            if (kBoolTrue == test_3) {
              ioArgument_outputString.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_tabColumn_33684.substract_operation (var_currentColumn_33590, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1134)).substract_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1134))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1132)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1132)) ;
            }
          }
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_tabValueData_33433.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1140)), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1140)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVariablesInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                                   GALGAS_gtlData & ioArgument_vars,
                                                   GALGAS_library & /* ioArgument_lib */,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_shortDisplay.boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_gtlVariablesInstruction temp_1 = this ;
      callExtensionMethod_displayShort ((cPtr_gtlVariablesInstruction *) temp_1.ptr (), ioArgument_vars, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1198)) ;
    }
  }
  if (kBoolFalse == test_0) {
    const GALGAS_gtlVariablesInstruction temp_2 = this ;
    callExtensionMethod_displayLong ((cPtr_gtlVariablesInstruction *) temp_2.ptr (), ioArgument_vars, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1200)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLibrariesInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLibrariesInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                                   GALGAS_gtlData & /* ioArgument_vars */,
                                                   GALGAS_library & ioArgument_lib,
                                                   GALGAS_string & /* ioArgument_outputString */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_delimitor_36082 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1215)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1215)) ;
  GALGAS_string var_varDelim_36164 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (45)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1216)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1216)) ;
  GALGAS_string var_separator_36248 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (17U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1217)) ;
  inCompiler->printMessage (var_separator_36248.add_operation (GALGAS_string (" Libraries "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1218)).add_operation (var_separator_36248, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1218)).add_operation (GALGAS_string ("= Displayed from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1219)).add_operation (var_separator_36248, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1219)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1220))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1218)) ;
  inCompiler->printMessage (this->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1221)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1221))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1221)) ;
  inCompiler->printMessage (var_delimitor_36082  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1222)) ;
  inCompiler->printMessage (GALGAS_string (" Functions \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1223)) ;
  inCompiler->printMessage (var_varDelim_36164  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1224)) ;
  GALGAS_uint var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlFuncMap enumerator_36545 (ioArgument_lib.readProperty_funcMap (), kENUMERATION_UP) ;
  const bool bool_0 = true ;
  if (enumerator_36545.hasCurrentObject () && bool_0) {
    while (enumerator_36545.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsStrictSup, var_lineSize_36527.add_operation (enumerator_36545.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1227)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1227)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1229)) ;
        }
      }
      inCompiler->printMessage (enumerator_36545.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1231)) ;
      var_lineSize_36527.plusAssign_operation(enumerator_36545.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1232)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1232)) ;
      enumerator_36545.gotoNextObject () ;
      if (enumerator_36545.hasCurrentObject () && bool_0) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1234)) ;
        var_lineSize_36527.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1235)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1237)) ;
  }
  inCompiler->printMessage (var_delimitor_36082  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1239)) ;
  inCompiler->printMessage (GALGAS_string (" Getters \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1240)) ;
  inCompiler->printMessage (var_varDelim_36164  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1241)) ;
  var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlGetterMap enumerator_36896 (ioArgument_lib.readProperty_getterMap (), kENUMERATION_UP) ;
  const bool bool_2 = true ;
  if (enumerator_36896.hasCurrentObject () && bool_2) {
    while (enumerator_36896.hasCurrentObject () && bool_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsStrictSup, var_lineSize_36527.add_operation (enumerator_36896.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1244)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1244)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1246)) ;
        }
      }
      inCompiler->printMessage (enumerator_36896.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1248)) ;
      var_lineSize_36527.plusAssign_operation(enumerator_36896.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1249)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1249)) ;
      enumerator_36896.gotoNextObject () ;
      if (enumerator_36896.hasCurrentObject () && bool_2) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1251)) ;
        var_lineSize_36527.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1252)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1254)) ;
  }
  inCompiler->printMessage (var_delimitor_36082  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1256)) ;
  inCompiler->printMessage (GALGAS_string (" Setters \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1257)) ;
  inCompiler->printMessage (var_varDelim_36164  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1258)) ;
  var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlSetterMap enumerator_37249 (ioArgument_lib.readProperty_setterMap (), kENUMERATION_UP) ;
  const bool bool_4 = true ;
  if (enumerator_37249.hasCurrentObject () && bool_4) {
    while (enumerator_37249.hasCurrentObject () && bool_4) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsStrictSup, var_lineSize_36527.add_operation (enumerator_37249.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1261)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1261)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1263)) ;
        }
      }
      inCompiler->printMessage (enumerator_37249.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1265)) ;
      var_lineSize_36527.plusAssign_operation(enumerator_37249.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1266)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1266)) ;
      enumerator_37249.gotoNextObject () ;
      if (enumerator_37249.hasCurrentObject () && bool_4) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1268)) ;
        var_lineSize_36527.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1269)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1271)) ;
  }
  inCompiler->printMessage (var_delimitor_36082  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1273)) ;
  inCompiler->printMessage (GALGAS_string (" Templates \n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1274)) ;
  inCompiler->printMessage (var_varDelim_36164  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1275)) ;
  var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
  cEnumerator_gtlTemplateMap enumerator_37604 (ioArgument_lib.readProperty_templateMap (), kENUMERATION_UP) ;
  const bool bool_6 = true ;
  if (enumerator_37604.hasCurrentObject () && bool_6) {
    while (enumerator_37604.hasCurrentObject () && bool_6) {
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        test_7 = GALGAS_bool (kIsStrictSup, var_lineSize_36527.add_operation (enumerator_37604.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1278)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1278)).objectCompare (GALGAS_uint (uint32_t (75U)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          var_lineSize_36527 = GALGAS_uint (uint32_t (0U)) ;
          inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1280)) ;
        }
      }
      inCompiler->printMessage (enumerator_37604.current_lkey (HERE).readProperty_string ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1282)) ;
      var_lineSize_36527.plusAssign_operation(enumerator_37604.current_lkey (HERE).readProperty_string ().getter_length (SOURCE_FILE ("gtl_instructions.galgas", 1283)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1283)) ;
      enumerator_37604.gotoNextObject () ;
      if (enumerator_37604.hasCurrentObject () && bool_6) {
        inCompiler->printMessage (GALGAS_string (", ")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1285)) ;
        var_lineSize_36527.plusAssign_operation(GALGAS_uint (uint32_t (2U)), inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1286)) ;
      }
    }
    inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1288)) ;
  }
  inCompiler->printMessage (var_delimitor_36082  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1290)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSetterCallInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                    GALGAS_gtlData & ioArgument_vars,
                                                    GALGAS_library & ioArgument_lib,
                                                    GALGAS_string & /* ioArgument_outputString */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlDataList var_dataArguments_38444 = GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_instructions.galgas", 1308)) ;
  cEnumerator_gtlExpressionList enumerator_38466 (this->mProperty_arguments, kENUMERATION_UP) ;
  while (enumerator_38466.hasCurrentObject ()) {
    var_dataArguments_38444.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_38466.current_expression (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1310))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1310)) ;
    enumerator_38466.gotoNextObject () ;
  }
  GALGAS_gtlData var_targetData_38570 = extensionGetter_get (this->mProperty_target, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1312)) ;
  {
  var_targetData_38570.insulate (HERE) ;
  cPtr_gtlData * ptr_38621 = (cPtr_gtlData *) var_targetData_38570.ptr () ;
  callExtensionSetter_performSetter ((cPtr_gtlData *) ptr_38621, this->mProperty_setterName, var_dataArguments_38444, ioArgument_context, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1313)) ;
  }
  extensionMethod_set (this->mProperty_target, ioArgument_context, ioArgument_vars, ioArgument_lib, var_targetData_38570, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1314)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInputStatementInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInputStatementInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & ioArgument_vars,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_gtlArgumentList enumerator_39219 (this->mProperty_formalArguments, kENUMERATION_UP) ;
  while (enumerator_39219.hasCurrentObject ()) {
    GALGAS_gtlData var_arg_39298 ;
    {
    ioArgument_context.insulate (HERE) ;
    cPtr_gtlContext * ptr_39257 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
    callExtensionSetter_popFirstInputArg ((cPtr_gtlContext *) ptr_39257, enumerator_39219.current_name (HERE).readProperty_location (), var_arg_39298, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1331)) ;
    }
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = enumerator_39219.current_typed (HERE).boolEnum () ;
      if (kBoolTrue == test_0) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsNotEqual, enumerator_39219.current_type (HERE).objectCompare (var_arg_39298.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 1333)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_arg_39298.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)), GALGAS_string ("mistyped argument, ").add_operation (extensionGetter_typeName (var_arg_39298.getter_dynamicType (SOURCE_FILE ("gtl_instructions.galgas", 1334)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)).add_operation (GALGAS_string (" provided"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)), fixItArray2  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1334)) ;
            TC_Array <C_FixItDescription> fixItArray3 ;
            inCompiler->emitSemanticError (enumerator_39219.current_name (HERE).readProperty_location (), extensionGetter_typeName (enumerator_39219.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1335)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1335)), fixItArray3  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1335)) ;
          }
        }
      }
    }
    {
    ioArgument_vars.insulate (HERE) ;
    cPtr_gtlData * ptr_39525 = (cPtr_gtlData *) ioArgument_vars.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_39525, enumerator_39219.current_name (HERE), var_arg_39298, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1338)) ;
    }
    enumerator_39219.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Function 'trueFalse'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_trueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler *
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_inBool.boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_string ("true") ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("false") ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_trueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_trueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_trueFalse (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_trueFalse ("trueFalse",
                                                           functionWithGenericHeader_trueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_trueFalse) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'TrueFalse'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_TrueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler *
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_inBool.boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_string ("True") ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("False") ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_TrueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_TrueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_TrueFalse (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_TrueFalse ("TrueFalse",
                                                           functionWithGenericHeader_TrueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TrueFalse) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'yesNo'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_yesNo (const GALGAS_bool & constinArgument_inBool,
                              C_Compiler *
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_inBool.boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_string ("YES") ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("NO") ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_yesNo [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_yesNo (C_Compiler * inCompiler,
                                                      const cObjectArray & inEffectiveParameterArray,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_yesNo (operand0,
                         inCompiler
                         COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_yesNo ("yesNo",
                                                       functionWithGenericHeader_yesNo,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       1,
                                                       functionArgs_yesNo) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'TRUEFALSE'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_TRUEFALSE (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler *
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_inBool.boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_string ("TRUE") ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_TRUEFALSE [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_TRUEFALSE (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_TRUEFALSE (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_TRUEFALSE ("TRUEFALSE",
                                                           functionWithGenericHeader_TRUEFALSE,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TRUEFALSE) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'listOfSize'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_list function_listOfSize (GALGAS_bigint inArgument_inSize,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_result ; // Returned variable
  result_result = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_functions.galgas", 84)) ;
  if (inArgument_inSize.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 85)).isValid ()) {
    uint32_t variant_2587 = inArgument_inSize.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 85)).uintValue () ;
    bool loop_2587 = true ;
    while (loop_2587) {
      loop_2587 = GALGAS_bool (kIsStrictSup, inArgument_inSize.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 86)))).isValid () ;
      if (loop_2587) {
        loop_2587 = GALGAS_bool (kIsStrictSup, inArgument_inSize.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 86)))).boolValue () ;
      }
      if (loop_2587 && (0 == variant_2587)) {
        loop_2587 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_functions.galgas", 85)) ;
      }
      if (loop_2587) {
        variant_2587 -- ;
        result_result.addAssign_operation (GALGAS_gtlUnconstructed::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 87))  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87))  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87)) ;
        inArgument_inSize.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 88)) ;
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_listOfSize [2] = {
  & kTypeDescriptor_GALGAS_bigint,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_listOfSize (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_bigint operand0 = GALGAS_bigint::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_listOfSize (operand0,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_listOfSize ("listOfSize",
                                                            functionWithGenericHeader_listOfSize,
                                                            & kTypeDescriptor_GALGAS_list,
                                                            1,
                                                            functionArgs_listOfSize) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'version'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_version (C_Compiler *
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 97)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_version [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_version (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_version (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_version ("version",
                                                         functionWithGenericHeader_version,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_version) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'majorVersion'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_majorVersion (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_3238 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 105)) ;
  GALGAS_stringlist var_versionComponents_3310 = var_version_3238.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 106)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_3310.getter_length (SOURCE_FILE ("gtl_functions.galgas", 107)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = var_versionComponents_3310.getter_mValueAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 109)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 109)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 109)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 111)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_majorVersion [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_majorVersion (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_majorVersion (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_majorVersion ("majorVersion",
                                                              functionWithGenericHeader_majorVersion,
                                                              & kTypeDescriptor_GALGAS_bigint,
                                                              0,
                                                              functionArgs_majorVersion) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'minorVersion'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_minorVersion (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_3772 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 120)) ;
  GALGAS_stringlist var_versionComponents_3844 = var_version_3772.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 121)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_3844.getter_length (SOURCE_FILE ("gtl_functions.galgas", 122)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = var_versionComponents_3844.getter_mValueAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 124)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 124)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 124)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 126)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_minorVersion [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_minorVersion (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_minorVersion (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_minorVersion ("minorVersion",
                                                              functionWithGenericHeader_minorVersion,
                                                              & kTypeDescriptor_GALGAS_bigint,
                                                              0,
                                                              functionArgs_minorVersion) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'revision'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_revision (C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_4297 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 135)) ;
  GALGAS_stringlist var_versionComponents_4369 = var_version_4297.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 136)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_4369.getter_length (SOURCE_FILE ("gtl_functions.galgas", 137)).objectCompare (GALGAS_uint (uint32_t (2U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = var_versionComponents_4369.getter_mValueAtIndex (GALGAS_uint (uint32_t (2U)), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 139)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 139)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 139)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 141)) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_revision [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_revision (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_revision (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_revision ("revision",
                                                          functionWithGenericHeader_revision,
                                                          & kTypeDescriptor_GALGAS_bigint,
                                                          0,
                                                          functionArgs_revision) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'currentDir'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_currentDir (C_Compiler *
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("gtl_functions.galgas", 150)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_currentDir [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_currentDir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_currentDir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_currentDir ("currentDir",
                                                            functionWithGenericHeader_currentDir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_currentDir) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'homeDir'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_homeDir (C_Compiler *
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_homeDirectory (SOURCE_FILE ("gtl_functions.galgas", 158)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_homeDir [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_homeDir (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_homeDir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_homeDir ("homeDir",
                                                         functionWithGenericHeader_homeDir,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_homeDir) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'currentDateTime'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_currentDateTime (C_Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithCurrentDateTime (SOURCE_FILE ("gtl_functions.galgas", 166)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_currentDateTime [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_currentDateTime (C_Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_currentDateTime (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_currentDateTime ("currentDateTime",
                                                                 functionWithGenericHeader_currentDateTime,
                                                                 & kTypeDescriptor_GALGAS_string,
                                                                 0,
                                                                 functionArgs_currentDateTime) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max8bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_38_bitsUnsignedInt (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("255", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 174)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_38_bitsUnsignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_38_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_max_38_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_38_bitsUnsignedInt ("max8bitsUnsignedInt",
                                                                        functionWithGenericHeader_max_38_bitsUnsignedInt,
                                                                        & kTypeDescriptor_GALGAS_bigint,
                                                                        0,
                                                                        functionArgs_max_38_bitsUnsignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max8bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_38_bitsSignedInt (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("127", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 182)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_38_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_38_bitsSignedInt (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_max_38_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_38_bitsSignedInt ("max8bitsSignedInt",
                                                                      functionWithGenericHeader_max_38_bitsSignedInt,
                                                                      & kTypeDescriptor_GALGAS_bigint,
                                                                      0,
                                                                      functionArgs_max_38_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min8bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_38_bitsSignedInt (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("-128", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 190)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_38_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_38_bitsSignedInt (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_min_38_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_38_bitsSignedInt ("min8bitsSignedInt",
                                                                      functionWithGenericHeader_min_38_bitsSignedInt,
                                                                      & kTypeDescriptor_GALGAS_bigint,
                                                                      0,
                                                                      functionArgs_min_38_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max16bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_31__36_bitsUnsignedInt (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("65535", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 198)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_31__36_bitsUnsignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_31__36_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_31__36_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_31__36_bitsUnsignedInt ("max16bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_31__36_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_31__36_bitsUnsignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max16bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_31__36_bitsSignedInt (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("32767", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 206)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_31__36_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_31__36_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_31__36_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_31__36_bitsSignedInt ("max16bitsSignedInt",
                                                                          functionWithGenericHeader_max_31__36_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_31__36_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min16bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_31__36_bitsSignedInt (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_bigint ("-32768", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 214)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_31__36_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_31__36_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_31__36_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_31__36_bitsSignedInt ("min16bitsSignedInt",
                                                                          functionWithGenericHeader_min_31__36_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_31__36_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max32bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_33__32_bitsUnsignedInt (C_Compiler *
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 222)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 222)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_33__32_bitsUnsignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_33__32_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_33__32_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_33__32_bitsUnsignedInt ("max32bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_33__32_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_33__32_bitsUnsignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max32bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_33__32_bitsSignedInt (C_Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 230)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 230)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_33__32_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_33__32_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_33__32_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_33__32_bitsSignedInt ("max32bitsSignedInt",
                                                                          functionWithGenericHeader_max_33__32_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_33__32_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min32bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_33__32_bitsSignedInt (C_Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint::constructor_min (SOURCE_FILE ("gtl_functions.galgas", 238)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 238)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_33__32_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_33__32_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_33__32_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_33__32_bitsSignedInt ("min32bitsSignedInt",
                                                                          functionWithGenericHeader_min_33__32_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_33__32_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max64bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_36__34_bitsUnsignedInt (C_Compiler *
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 246)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 246)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_36__34_bitsUnsignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_36__34_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_36__34_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_36__34_bitsUnsignedInt ("max64bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_36__34_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_36__34_bitsUnsignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max64bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_max_36__34_bitsSignedInt (C_Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 254)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 254)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_max_36__34_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_max_36__34_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_36__34_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_max_36__34_bitsSignedInt ("max64bitsSignedInt",
                                                                          functionWithGenericHeader_max_36__34_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_36__34_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min64bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint function_min_36__34_bitsSignedInt (C_Compiler *
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_::constructor_min (SOURCE_FILE ("gtl_functions.galgas", 262)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 262)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_min_36__34_bitsSignedInt [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_min_36__34_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_36__34_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_min_36__34_bitsSignedInt ("min64bitsSignedInt",
                                                                          functionWithGenericHeader_min_36__34_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_36__34_bitsSignedInt) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'pi'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double function_pi (C_Compiler *
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  result_result = GALGAS_double::constructor_pi (SOURCE_FILE ("gtl_functions.galgas", 270)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_pi [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_pi (C_Compiler * inCompiler,
                                                   const cObjectArray & /* inEffectiveParameterArray */,
                                                   const GALGAS_location & /* inErrorLocation */
                                                   COMMA_LOCATION_ARGS) {
  return function_pi (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_pi ("pi",
                                                    functionWithGenericHeader_pi,
                                                    & kTypeDescriptor_GALGAS_double,
                                                    0,
                                                    functionArgs_pi) ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

C_BoolCommandLineOption gOption_gtl_5F_options_debug ("gtl_options",
                                         "debug",
                                         0,
                                         "debug",
                                         "Execute the GTL templates in debug mode") ;

C_BoolCommandLineOption gOption_gtl_5F_options_warnDeprecated ("gtl_options",
                                         "warnDeprecated",
                                         0,
                                         "warn-deprecated",
                                         "Warns about deprecated constructs in the GTL template language") ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'signature'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_signature (GALGAS_location inArgument_loc,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_signatureString_793 = inArgument_loc.getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (inArgument_loc.getter_line (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 35)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 34)) ;
      result_result = var_signatureString_793.getter_md_35_ (SOURCE_FILE ("gtl_debugger.galgas", 36)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_signature [2] = {
  & kTypeDescriptor_GALGAS_location,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_signature (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_location operand0 = GALGAS_location::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_signature (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_signature ("signature",
                                                           functionWithGenericHeader_signature,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_signature) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'bold'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_bold (C_Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_bold ; // Returned variable
  result_bold = GALGAS_string ("\x1B""[1m") ;
//---
  return result_bold ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_bold = false ;
static GALGAS_string gOnceFunctionResult_bold ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_bold (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_bold) {
    gOnceFunctionResult_bold = onceFunction_bold (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_bold = true ;
  }
  return gOnceFunctionResult_bold ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_bold (void) {
  gOnceFunctionResult_bold.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_bold (NULL,
                                                  releaseOnceFunctionResult_bold) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_bold [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_bold (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_bold (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_bold ("bold",
                                                      functionWithGenericHeader_bold,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_bold) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'underline'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_underline (C_Compiler *
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_underline ; // Returned variable
  result_underline = GALGAS_string ("\x1B""[4m") ;
//---
  return result_underline ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_underline = false ;
static GALGAS_string gOnceFunctionResult_underline ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_underline (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_underline) {
    gOnceFunctionResult_underline = onceFunction_underline (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_underline = true ;
  }
  return gOnceFunctionResult_underline ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_underline (void) {
  gOnceFunctionResult_underline.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_underline (NULL,
                                                       releaseOnceFunctionResult_underline) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_underline [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_underline (C_Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_underline (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_underline ("underline",
                                                           functionWithGenericHeader_underline,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_underline) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'blink'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_blink (C_Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blink ; // Returned variable
  result_blink = GALGAS_string ("\x1B""[5m") ;
//---
  return result_blink ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_blink = false ;
static GALGAS_string gOnceFunctionResult_blink ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_blink (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blink) {
    gOnceFunctionResult_blink = onceFunction_blink (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blink = true ;
  }
  return gOnceFunctionResult_blink ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_blink (void) {
  gOnceFunctionResult_blink.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_blink (NULL,
                                                   releaseOnceFunctionResult_blink) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_blink [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_blink (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_blink (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_blink ("blink",
                                                       functionWithGenericHeader_blink,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_blink) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'black'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_black (C_Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_black ; // Returned variable
  result_black = GALGAS_string ("\x1B""[90m") ;
//---
  return result_black ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_black = false ;
static GALGAS_string gOnceFunctionResult_black ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_black (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_black) {
    gOnceFunctionResult_black = onceFunction_black (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_black = true ;
  }
  return gOnceFunctionResult_black ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_black (void) {
  gOnceFunctionResult_black.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_black (NULL,
                                                   releaseOnceFunctionResult_black) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_black [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_black (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_black (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_black ("black",
                                                       functionWithGenericHeader_black,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_black) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'red'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_red (C_Compiler *
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("\x1B""[91m") ;
//---
  return result_red ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_red = false ;
static GALGAS_string gOnceFunctionResult_red ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_red (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_red) {
    gOnceFunctionResult_red = onceFunction_red (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_red = true ;
  }
  return gOnceFunctionResult_red ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_red (void) {
  gOnceFunctionResult_red.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_red (NULL,
                                                 releaseOnceFunctionResult_red) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_red [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_red (C_Compiler * inCompiler,
                                                    const cObjectArray & /* inEffectiveParameterArray */,
                                                    const GALGAS_location & /* inErrorLocation */
                                                    COMMA_LOCATION_ARGS) {
  return function_red (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_red ("red",
                                                     functionWithGenericHeader_red,
                                                     & kTypeDescriptor_GALGAS_string,
                                                     0,
                                                     functionArgs_red) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'green'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_green (C_Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("\x1B""[92m") ;
//---
  return result_green ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_green = false ;
static GALGAS_string gOnceFunctionResult_green ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_green (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_green) {
    gOnceFunctionResult_green = onceFunction_green (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_green = true ;
  }
  return gOnceFunctionResult_green ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_green (void) {
  gOnceFunctionResult_green.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_green (NULL,
                                                   releaseOnceFunctionResult_green) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_green [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_green (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_green (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_green ("green",
                                                       functionWithGenericHeader_green,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_green) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'yellow'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_yellow (C_Compiler *
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("\x1B""[93m") ;
//---
  return result_yellow ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_yellow = false ;
static GALGAS_string gOnceFunctionResult_yellow ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_yellow (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_yellow) {
    gOnceFunctionResult_yellow = onceFunction_yellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_yellow = true ;
  }
  return gOnceFunctionResult_yellow ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_yellow (void) {
  gOnceFunctionResult_yellow.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_yellow (NULL,
                                                    releaseOnceFunctionResult_yellow) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_yellow [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_yellow (C_Compiler * inCompiler,
                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                       const GALGAS_location & /* inErrorLocation */
                                                       COMMA_LOCATION_ARGS) {
  return function_yellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_yellow ("yellow",
                                                        functionWithGenericHeader_yellow,
                                                        & kTypeDescriptor_GALGAS_string,
                                                        0,
                                                        functionArgs_yellow) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'blue'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_blue (C_Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("\x1B""[94m") ;
//---
  return result_blue ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_blue = false ;
static GALGAS_string gOnceFunctionResult_blue ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_blue (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blue) {
    gOnceFunctionResult_blue = onceFunction_blue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blue = true ;
  }
  return gOnceFunctionResult_blue ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_blue (void) {
  gOnceFunctionResult_blue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_blue (NULL,
                                                  releaseOnceFunctionResult_blue) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_blue [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_blue (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_blue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_blue ("blue",
                                                      functionWithGenericHeader_blue,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_blue) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'magenta'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_magenta (C_Compiler *
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("\x1B""[95m") ;
//---
  return result_magenta ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_magenta = false ;
static GALGAS_string gOnceFunctionResult_magenta ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_magenta (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_magenta) {
    gOnceFunctionResult_magenta = onceFunction_magenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_magenta = true ;
  }
  return gOnceFunctionResult_magenta ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_magenta (void) {
  gOnceFunctionResult_magenta.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_magenta (NULL,
                                                     releaseOnceFunctionResult_magenta) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_magenta [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_magenta (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_magenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_magenta ("magenta",
                                                         functionWithGenericHeader_magenta,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_magenta) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'cyan'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_cyan (C_Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("\x1B""[96m") ;
//---
  return result_cyan ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_cyan = false ;
static GALGAS_string gOnceFunctionResult_cyan ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_cyan (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_cyan) {
    gOnceFunctionResult_cyan = onceFunction_cyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_cyan = true ;
  }
  return gOnceFunctionResult_cyan ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_cyan (void) {
  gOnceFunctionResult_cyan.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_cyan (NULL,
                                                  releaseOnceFunctionResult_cyan) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_cyan [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_cyan (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_cyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_cyan ("cyan",
                                                      functionWithGenericHeader_cyan,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_cyan) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'darkred'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkred (C_Compiler *
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("\x1B""[31m") ;
//---
  return result_red ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkred = false ;
static GALGAS_string gOnceFunctionResult_darkred ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_darkred (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkred) {
    gOnceFunctionResult_darkred = onceFunction_darkred (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkred = true ;
  }
  return gOnceFunctionResult_darkred ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkred (void) {
  gOnceFunctionResult_darkred.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_darkred (NULL,
                                                     releaseOnceFunctionResult_darkred) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkred [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkred (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_darkred (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkred ("darkred",
                                                         functionWithGenericHeader_darkred,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_darkred) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'darkgreen'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkgreen (C_Compiler *
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("\x1B""[32m") ;
//---
  return result_green ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkgreen = false ;
static GALGAS_string gOnceFunctionResult_darkgreen ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_darkgreen (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkgreen) {
    gOnceFunctionResult_darkgreen = onceFunction_darkgreen (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkgreen = true ;
  }
  return gOnceFunctionResult_darkgreen ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkgreen (void) {
  gOnceFunctionResult_darkgreen.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_darkgreen (NULL,
                                                       releaseOnceFunctionResult_darkgreen) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkgreen [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkgreen (C_Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_darkgreen (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkgreen ("darkgreen",
                                                           functionWithGenericHeader_darkgreen,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_darkgreen) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'darkyellow'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkyellow (C_Compiler *
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("\x1B""[33m") ;
//---
  return result_yellow ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkyellow = false ;
static GALGAS_string gOnceFunctionResult_darkyellow ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_darkyellow (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkyellow) {
    gOnceFunctionResult_darkyellow = onceFunction_darkyellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkyellow = true ;
  }
  return gOnceFunctionResult_darkyellow ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkyellow (void) {
  gOnceFunctionResult_darkyellow.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_darkyellow (NULL,
                                                        releaseOnceFunctionResult_darkyellow) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkyellow [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkyellow (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_darkyellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkyellow ("darkyellow",
                                                            functionWithGenericHeader_darkyellow,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_darkyellow) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'darkblue'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkblue (C_Compiler *
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("\x1B""[34m") ;
//---
  return result_blue ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkblue = false ;
static GALGAS_string gOnceFunctionResult_darkblue ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_darkblue (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkblue) {
    gOnceFunctionResult_darkblue = onceFunction_darkblue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkblue = true ;
  }
  return gOnceFunctionResult_darkblue ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkblue (void) {
  gOnceFunctionResult_darkblue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_darkblue (NULL,
                                                      releaseOnceFunctionResult_darkblue) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkblue [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkblue (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkblue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkblue ("darkblue",
                                                          functionWithGenericHeader_darkblue,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkblue) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'darkmagenta'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkmagenta (C_Compiler *
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("\x1B""[35m") ;
//---
  return result_magenta ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkmagenta = false ;
static GALGAS_string gOnceFunctionResult_darkmagenta ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_darkmagenta (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkmagenta) {
    gOnceFunctionResult_darkmagenta = onceFunction_darkmagenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkmagenta = true ;
  }
  return gOnceFunctionResult_darkmagenta ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkmagenta (void) {
  gOnceFunctionResult_darkmagenta.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_darkmagenta (NULL,
                                                         releaseOnceFunctionResult_darkmagenta) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkmagenta [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkmagenta (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_darkmagenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkmagenta ("darkmagenta",
                                                             functionWithGenericHeader_darkmagenta,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_darkmagenta) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'darkcyan'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_darkcyan (C_Compiler *
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("\x1B""[36m") ;
//---
  return result_cyan ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_darkcyan = false ;
static GALGAS_string gOnceFunctionResult_darkcyan ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_darkcyan (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkcyan) {
    gOnceFunctionResult_darkcyan = onceFunction_darkcyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkcyan = true ;
  }
  return gOnceFunctionResult_darkcyan ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_darkcyan (void) {
  gOnceFunctionResult_darkcyan.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_darkcyan (NULL,
                                                      releaseOnceFunctionResult_darkcyan) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_darkcyan [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_darkcyan (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkcyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_darkcyan ("darkcyan",
                                                          functionWithGenericHeader_darkcyan,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkcyan) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'white'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_white (C_Compiler *
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_white ; // Returned variable
  result_white = GALGAS_string ("\x1B""[97m") ;
//---
  return result_white ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_white = false ;
static GALGAS_string gOnceFunctionResult_white ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_white (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_white) {
    gOnceFunctionResult_white = onceFunction_white (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_white = true ;
  }
  return gOnceFunctionResult_white ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_white (void) {
  gOnceFunctionResult_white.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_white (NULL,
                                                   releaseOnceFunctionResult_white) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_white [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_white (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_white (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_white ("white",
                                                       functionWithGenericHeader_white,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_white) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Once function 'endc'
//
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_string onceFunction_endc (C_Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_endc ; // Returned variable
  result_endc = GALGAS_string ("\x1B""[0m") ;
//---
  return result_endc ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_endc = false ;
static GALGAS_string gOnceFunctionResult_endc ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_endc (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_endc) {
    gOnceFunctionResult_endc = onceFunction_endc (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_endc = true ;
  }
  return gOnceFunctionResult_endc ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_endc (void) {
  gOnceFunctionResult_endc.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_endc (NULL,
                                                  releaseOnceFunctionResult_endc) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_endc [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_endc (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_endc (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_endc ("endc",
                                                      functionWithGenericHeader_endc,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_endc) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'defaultDebugSettings'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext function_defaultDebugSettings (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_debuggerContext result_debugSettings ; // Returned variable
  result_debugSettings = GALGAS_debuggerContext::constructor_new (GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()), GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()), GALGAS_bool (false), function_red (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 404)), GALGAS_string::makeEmptyString (), function_blue (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 406)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 407)), function_darkgreen (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 408)), GALGAS_string::makeEmptyString (), function_darkyellow (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 410)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 411)), GALGAS_bool (false), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 413)), GALGAS_gtlBreakpointList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 414)), GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 415)), GALGAS_uint (uint32_t (0U)), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 417)), GALGAS_gtlInstructionListContextStack::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 418)), GALGAS_debugCommandInput::constructor_new (GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 419))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 419))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 400)) ;
//---
  return result_debugSettings ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_defaultDebugSettings [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_defaultDebugSettings (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_defaultDebugSettings (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_defaultDebugSettings ("defaultDebugSettings",
                                                                      functionWithGenericHeader_defaultDebugSettings,
                                                                      & kTypeDescriptor_GALGAS_debuggerContext,
                                                                      0,
                                                                      functionArgs_defaultDebugSettings) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemField::getter_stringRepresentation (const GALGAS_string constinArgument_concatString,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = constinArgument_concatString.add_operation (this->mProperty_field.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 669)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemSubCollection::getter_stringRepresentation (const GALGAS_string /* constinArgument_concatString */,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("[").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 677)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemCollection::getter_stringRepresentation (const GALGAS_string constinArgument_concatString,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = constinArgument_concatString.add_operation (this->mProperty_field.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)).add_operation (GALGAS_char (TO_UNICODE (91)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 685)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)).add_operation (GALGAS_char (TO_UNICODE (93)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 685)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 685)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAddExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlAddExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)).add_operation (GALGAS_string (" + "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 696)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAndExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlAndExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)).add_operation (GALGAS_string (" & "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 703)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlDivideExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlDivideExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)).add_operation (GALGAS_string (" / "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 710)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEqualExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEqualExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)).add_operation (GALGAS_string (" == "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 717)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterOrEqualExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlGreaterOrEqualExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)).add_operation (GALGAS_string (" >= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 724)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterThanExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlGreaterThanExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)).add_operation (GALGAS_string (" > "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 731)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerOrEqualExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLowerOrEqualExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)).add_operation (GALGAS_string (" <= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 738)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerThanExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLowerThanExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)).add_operation (GALGAS_string (" < "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 745)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlModulusExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlModulusExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)).add_operation (GALGAS_string (" mod "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 752)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMultiplyExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMultiplyExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 759)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotEqualExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlNotEqualExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)).add_operation (GALGAS_string (" != "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 766)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlOrExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlOrExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 773)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftLeftExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlShiftLeftExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)).add_operation (GALGAS_string (" << "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 780)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftRightExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlShiftRightExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)).add_operation (GALGAS_string (" >> "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 787)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSubstractExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSubstractExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)).add_operation (GALGAS_string (" - "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 794)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlXorExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlXorExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)).add_operation (GALGAS_string (" ^ "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 801)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExistsExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("exists ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 808)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 808)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsDefaultExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExistsDefaultExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("exists ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 816)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 815)).add_operation (GALGAS_string (" default ( "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 816)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_defaultValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 818)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 817)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 818)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFunctionCallExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFunctionCallExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_functionName.readProperty_string ().add_operation (GALGAS_string ("("), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)).add_operation (extensionGetter_stringRepresentation (this->mProperty_functionArguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 826)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGetterCallExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlGetterCallExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("[").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_target.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)).add_operation (this->mProperty_getterName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 833)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, this->mProperty_arguments.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 834)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = result_result.add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 835)).add_operation (extensionGetter_stringRepresentation (this->mProperty_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 835)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 835)) ;
    }
  }
  result_result = result_result.add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 837)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlListOfExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlListOfExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("listof ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 844)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 844)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralListExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralListExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@( ").add_operation (extensionGetter_stringRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 851)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 851)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 851)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralMapExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralMapExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@[ ").add_operation (extensionGetter_mapRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 858)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 858)).add_operation (GALGAS_string (" ]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 858)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralSetExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralSetExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@! ").add_operation (extensionGetter_stringRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 865)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 865)).add_operation (GALGAS_string (" !"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 865)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralStructExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlLiteralStructExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@{ ").add_operation (extensionGetter_structRepresentation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 872)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 872)).add_operation (GALGAS_string (" }"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 872)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMapOfStructExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMapOfStructExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("mapof ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 879)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 879)).add_operation (GALGAS_string (" end"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 879)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTerminal stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlTerminal::getter_stringRepresentation (C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 886)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTypeOfExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlTypeOfExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("typeof ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 893)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 893)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMinusExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMinusExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("-").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 900)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 900)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlNotExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("not ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 907)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 907)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlParenthesizedExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlParenthesizedExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("(").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 914)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 914)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 914)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlPlusExpression stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlPlusExpression::getter_stringRepresentation (C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("+").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 921)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 921)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarRef stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarRef::getter_stringRepresentation (C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = extensionGetter_stringRepresentation (this->mProperty_variableName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 928)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAllVarsRef stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlAllVarsRef::getter_stringRepresentation (C_Compiler */* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("__VARS__") ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlBool stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlBool::getter_stringRepresentation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlBool temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlBool *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 946)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_stringRepresentation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlChar temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlChar *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 953)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_stringRepresentation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlEnum temp_0 = this ;
  result_result = GALGAS_string ("$").add_operation (callExtensionGetter_string ((const cPtr_gtlEnum *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 960)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 960)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_stringRepresentation (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlFloat temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlFloat *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 967)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_stringRepresentation (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlInt temp_0 = this ;
  result_result = callExtensionGetter_string ((const cPtr_gtlInt *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 974)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_stringRepresentation (C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlString temp_0 = this ;
  GALGAS_string var_literalString_30174 = callExtensionGetter_string ((const cPtr_gtlString *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 981)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 982)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\t"), GALGAS_string ("\\t"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 983)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\f"), GALGAS_string ("\\f"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 984)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string ("\\r"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 985)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\v"), GALGAS_string ("\\v"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 986)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 987)) ;
  var_literalString_30174 = var_literalString_30174.getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 988)) ;
  result_result = GALGAS_string ("\"").add_operation (var_literalString_30174, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 989)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 989)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlUnconstructed::getter_stringRepresentation (C_Compiler */* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("*UNCONSTRUCTED*") ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlType::getter_stringRepresentation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_gtlType temp_0 = this ;
  result_result = GALGAS_string ("@").add_operation (callExtensionGetter_string ((const cPtr_gtlType *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1003)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1003)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlList stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlList::getter_stringRepresentation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@( ") ;
  cEnumerator_list enumerator_31345 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_31345.hasCurrentObject ()) {
    result_result = result_result.add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_31345.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1012)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1012)) ;
    if (enumerator_31345.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1014)) ;
    }
    enumerator_31345.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1016)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMap stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlMap::getter_stringRepresentation (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@[ ") ;
  cEnumerator_gtlVarMap enumerator_31658 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_31658.hasCurrentObject ()) {
    result_result = result_result.add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)).add_operation (enumerator_31658.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)).add_operation (GALGAS_string ("\": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_31658.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1025)) ;
    if (enumerator_31658.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1027)) ;
    }
    enumerator_31658.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" ]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1029)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlStruct::getter_stringRepresentation (C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@{ ") ;
  cEnumerator_gtlVarMap enumerator_31998 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_31998.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_31998.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlData *) enumerator_31998.current_value (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1038)) ;
    if (enumerator_31998.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1040)) ;
    }
    enumerator_31998.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" }"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1042)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSet stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlSet::getter_stringRepresentation (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@! ") ;
  cEnumerator_lstringset enumerator_32322 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_32322.hasCurrentObject ()) {
    result_result = result_result.add_operation (enumerator_32322.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1051)) ;
    if (enumerator_32322.hasNextObject ()) {
      result_result = result_result.add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1053)) ;
    }
    enumerator_32322.gotoNextObject () ;
  }
  result_result = result_result.add_operation (GALGAS_string (" !"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1055)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExpr stringRepresentation'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlExpr::getter_stringRepresentation (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("@\? ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_value.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1062)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1062)).add_operation (GALGAS_string (" \?"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1062)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetUnconstructedInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetUnconstructedInstruction::method_display (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1161)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetInstruction::method_display (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1168)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1167)).add_operation (GALGAS_string (" := "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1168)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1170)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1169))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1167)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAddInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetAddInstruction::method_display (C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1177)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1176)).add_operation (GALGAS_string (" += "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1177)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1179)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1178))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1176)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetSubstractInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetSubstractInstruction::method_display (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1186)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1185)).add_operation (GALGAS_string (" -= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1186)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1188)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1187))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1185)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetMultiplyInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetMultiplyInstruction::method_display (C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1195)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1194)).add_operation (GALGAS_string (" *= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1195)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1197)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1196))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1194)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetDivideInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetDivideInstruction::method_display (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1204)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1203)).add_operation (GALGAS_string (" /= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1204)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1206)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1205))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1203)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetModuloInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetModuloInstruction::method_display (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1213)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1212)).add_operation (GALGAS_string (" mod= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1213)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1215)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1214))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1212)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftLeftInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftLeftInstruction::method_display (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1222)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1221)).add_operation (GALGAS_string (" <<= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1222)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1223))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1221)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetShiftRightInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetShiftRightInstruction::method_display (C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1231)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)).add_operation (GALGAS_string (" >>= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1231)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1233)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1232))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1230)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetAndInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetAndInstruction::method_display (C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1240)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1239)).add_operation (GALGAS_string (" &= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1240)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1242)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1241))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1239)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetOrInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetOrInstruction::method_display (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1249)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1248)).add_operation (GALGAS_string (" |= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1249)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1251)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1250))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1248)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLetXorInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetXorInstruction::method_display (C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("let ").add_operation (extensionGetter_stringRepresentation (this->mProperty_lValue, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1257)).add_operation (GALGAS_string (" ^= "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1258)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1260)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1259))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1257)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoopStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLoopStatementInstruction::method_display (C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, this->mProperty_upDown.objectCompare (GALGAS_sint_36__34_ (int64_t (-1LL)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string (" down") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }
  inCompiler->printMessage (GALGAS_string ("loop ").add_operation (this->mProperty_identifier.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1266)).add_operation (GALGAS_string (" from "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1267)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_start.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1269)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1268)).add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1269)).add_operation (GALGAS_string (" to "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1270)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_stop.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1272)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1271)).add_operation (GALGAS_string (" step "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1272)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_step.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1274)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1273)).add_operation (GALGAS_string (" do"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1274))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1266)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWarningStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWarningStatementInstruction::method_display (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_hereInstead.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("here") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = extensionGetter_stringRepresentation (this->mProperty_identifier, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1282)) ;
  }
  inCompiler->printMessage (GALGAS_string ("warning ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1281)).add_operation (GALGAS_string (" : "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1282)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_warningMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1284)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1283))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1281)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlErrorStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlErrorStatementInstruction::method_display (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_hereInstead.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("here") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = extensionGetter_stringRepresentation (this->mProperty_identifier, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1291)) ;
  }
  inCompiler->printMessage (GALGAS_string ("error ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1290)).add_operation (GALGAS_string (" : "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1291)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_errorMessage.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1293)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1292))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1290)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDisplayStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDisplayStatementInstruction::method_display (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("display ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1299)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1299))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1299)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlPrintStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlPrintStatementInstruction::method_display (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_carriageReturn.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("ln ") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string (" ") ;
  }
  inCompiler->printMessage (GALGAS_string ("print").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1305)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_messageToPrint.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1307)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1306))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1305)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateStringInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateStringInstruction::method_display (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("%").add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1313)).add_operation (GALGAS_string ("%"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1313))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1313)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInputStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInputStatementInstruction::method_display (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("input ( ").add_operation (extensionGetter_stringRepresentation (this->mProperty_formalArguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1319)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSortStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlSortStatementInstruction::method_display (C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("sort ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1326)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1325)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1326)).add_operation (extensionGetter_stringRepresentation (this->mProperty_order, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1328)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1327))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1325)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSortStatementStructInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlSortStatementStructInstruction::method_display (C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("sort ").add_operation (extensionGetter_stringRepresentation (this->mProperty_variablePath, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1335)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1334)).add_operation (GALGAS_string (" by "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1335)).add_operation (extensionGetter_stringRepresentation (this->mProperty_sortingKey, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1337)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1336))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1334)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTemplateInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateInstruction::method_display (C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_isGlobal.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string ("( ").add_operation (extensionGetter_stringRepresentation (this->mProperty_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1344)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1344)).add_operation (GALGAS_string (" ) "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1344)) ;
  }
  GALGAS_string temp_2 ;
  const enumGalgasBool test_3 = this->mProperty_ifExists.boolEnum () ;
  if (kBoolTrue == test_3) {
    temp_2 = GALGAS_string ("if exists ") ;
  }else if (kBoolFalse == test_3) {
    temp_2 = GALGAS_string::makeEmptyString () ;
  }
  GALGAS_string temp_4 ;
  const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_prefix.readProperty_string ())).boolEnum () ;
  if (kBoolTrue == test_5) {
    temp_4 = GALGAS_string (" ") ;
  }else if (kBoolFalse == test_5) {
    temp_4 = GALGAS_string (" in ").add_operation (this->mProperty_prefix.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1347)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1347)) ;
  }
  GALGAS_string temp_6 ;
  const enumGalgasBool test_7 = this->mProperty_ifExists.operator_and (GALGAS_bool (kIsStrictSup, this->mProperty_instructionsIfNotFound.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 1348)).objectCompare (GALGAS_uint (uint32_t (0U)))) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1348)).boolEnum () ;
  if (kBoolTrue == test_7) {
    temp_6 = GALGAS_string ("or ...") ;
  }else if (kBoolFalse == test_7) {
    temp_6 = GALGAS_string::makeEmptyString () ;
  }
  inCompiler->printMessage (GALGAS_string ("template ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1343)).add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1344)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_fileName.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1346)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1345)).add_operation (temp_4, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1346)).add_operation (temp_6, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1347))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1343)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEmitInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlEmitInstruction::method_display (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("! ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_rValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1354)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1354))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1354)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlIfStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlIfStatementInstruction::method_display (C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("if ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_thenElsifList.getter_conditionAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1361)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1361)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1360)).add_operation (GALGAS_string (" then"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1361))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1360)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlForStatementInstruction::method_display (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("for ").add_operation (this->mProperty_identifier.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1368)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1369)).add_operation (extensionGetter_stringRepresentation (this->mProperty_iterable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1371)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1370)).add_operation (GALGAS_string (" do"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1371))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1368)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlForeachStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlForeachStatementInstruction::method_display (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string::makeEmptyString ().objectCompare (this->mProperty_keyName.readProperty_string ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }else if (kBoolFalse == test_1) {
    temp_0 = this->mProperty_keyName.readProperty_string ().add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1379)) ;
  }
  inCompiler->printMessage (GALGAS_string ("foreach ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1378)).add_operation (this->mProperty_variableName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1379)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1380)).add_operation (this->mProperty_indexName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1381)).add_operation (GALGAS_string (") "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1381)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1381)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_iterable.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1382))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1378)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlGetColumnInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlGetColumnInstruction::method_display (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("\? ").add_operation (extensionGetter_stringRepresentation (this->mProperty_destVariable, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1389)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1389))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1389)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLibrariesInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLibrariesInstruction::method_display (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("libraries")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1395)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlRepeatStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlRepeatStatementInstruction::method_display (C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("repeat ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1401)) ;
  if (this->mProperty_limit.isValid ()) {
    if (this->mProperty_limit.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlTerminal) {
      GALGAS_gtlTerminal cast_42108_term ((cPtr_gtlTerminal *) this->mProperty_limit.ptr ()) ;
      if (cast_42108_term.readProperty_value ().isValid ()) {
        if (cast_42108_term.readProperty_value ().dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
          GALGAS_gtlInt cast_42160_intLimit ((cPtr_gtlInt *) cast_42108_term.readProperty_value ().ptr ()) ;
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsNotEqual, cast_42160_intLimit.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1406)).objectCompare (GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_debugger.galgas", 1406)))).boolEnum () ;
            if (kBoolTrue == test_0) {
              inCompiler->printMessage (GALGAS_string (" (").add_operation (callExtensionGetter_string ((const cPtr_gtlInt *) cast_42160_intLimit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1407)) ;
            }
          }
        }
      }
    }else{
      inCompiler->printMessage (GALGAS_string (" (").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_limit.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1411)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1411)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1411))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1411)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlSetterCallInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlSetterCallInstruction::method_display (C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, this->mProperty_arguments.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 1421)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string (": ").add_operation (extensionGetter_stringRepresentation (this->mProperty_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1422)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1422)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1422)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string ("]") ;
  }
  inCompiler->printMessage (GALGAS_string ("[!").add_operation (extensionGetter_stringRepresentation (this->mProperty_target, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1419)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1418)).add_operation (this->mProperty_setterName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1419)).add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1420))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1418)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVariablesInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::method_display (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("variables")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1431)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWriteToInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWriteToInstruction::method_display (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = this->mProperty_isExecutable.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("executable ") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }
  inCompiler->printMessage (GALGAS_string ("write to ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1437)).add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_fileNameExpression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1439)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1438)).add_operation (GALGAS_string (" :"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1439))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1437)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlTabStatementInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTabStatementInstruction::method_display (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("tab ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_tabValue.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1447)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1447))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1447)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlDisplayStatementInstruction mayExecuteWithoutError'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlDisplayStatementInstruction::getter_mayExecuteWithoutError (const GALGAS_gtlContext constinArgument_exeContext,
                                                                                const GALGAS_gtlData constinArgument_context,
                                                                                const GALGAS_library constinArgument_lib,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_may ; // Returned variable
  result_may = extensionGetter_exists (this->mProperty_variablePath, constinArgument_exeContext, constinArgument_context, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1468)) ;
//---
  return result_may ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStepInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlStepInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & /* ioArgument_vars */,
                                              GALGAS_library & /* ioArgument_lib */,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_44272 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_44272, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1482)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlStepInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlStepInstruction::method_display (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("step")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1487)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                GALGAS_gtlData & /* ioArgument_vars */,
                                                GALGAS_library & /* ioArgument_lib */,
                                                GALGAS_string & /* ioArgument_outputString */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_44836 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_appendInstructionToStepDo ((cPtr_gtlContext *) ptr_44836, this->mProperty_instructionToDo, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1504)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstInstruction::method_display (C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do ")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1509)) ;
  callExtensionMethod_display ((cPtr_gtlInstruction *) this->mProperty_instructionToDo.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1510)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                               GALGAS_gtlData & /* ioArgument_vars */,
                                               GALGAS_library & /* ioArgument_lib */,
                                               GALGAS_string & /* ioArgument_outputString */,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_45431 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteStepDoInstruction ((cPtr_gtlContext *) ptr_45431, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1527)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotInstruction::method_display (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do not ").add_operation (this->mProperty_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1532)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1532))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1532)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotAllInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotAllInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                  GALGAS_library & /* ioArgument_lib */,
                                                  GALGAS_string & /* ioArgument_outputString */,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_45999 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllStepDoInstructions ((cPtr_gtlContext *) ptr_45999, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1548)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoNotAllInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoNotAllInstruction::method_display (C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1553)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                            GALGAS_gtlData & /* ioArgument_vars */,
                                            GALGAS_library & /* ioArgument_lib */,
                                            GALGAS_string & /* ioArgument_outputString */,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listStepDoInstructions ((cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1569)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlDoInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDoInstruction::method_display (C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("do")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1574)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlContinueInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContinueInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                  GALGAS_gtlData & /* ioArgument_vars */,
                                                  GALGAS_library & /* ioArgument_lib */,
                                                  GALGAS_string & /* ioArgument_outputString */,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_47040 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setBreakOnNext ((cPtr_gtlContext *) ptr_47040, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1590)) ;
  }
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_47076 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_47076, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1591)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlContinueInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContinueInstruction::method_display (C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("cont")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1596)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                    GALGAS_library & /* ioArgument_lib */,
                                                    GALGAS_string & /* ioArgument_outputString */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlInstructionList var_instructionList_47664 = ioArgument_context.readProperty_debuggerContext ().readProperty_instructionList () ;
  GALGAS_string var_localFileName_47734 = GALGAS_string::makeEmptyString () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_instructionList_47664.getter_length (SOURCE_FILE ("gtl_debugger.galgas", 1616)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_localFileName_47734 = callExtensionGetter_location ((const cPtr_gtlInstruction *) var_instructionList_47664.getter_instructionAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1618)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1618)).getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1618)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 1619)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, this->mProperty_fileName.objectCompare (var_localFileName_47734)).operator_or (GALGAS_bool (kIsEqual, this->mProperty_fileName.objectCompare (GALGAS_string::makeEmptyString ())) COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1621)).boolEnum () ;
        if (kBoolTrue == test_1) {
          inCompiler->printMessage (GALGAS_string ("Setting breakpoint at ").add_operation (var_localFileName_47734, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)).add_operation (this->mProperty_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1622)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1622)) ;
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlContext * ptr_48044 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
          callExtensionSetter_setBreakpoint ((cPtr_gtlContext *) ptr_48044, var_localFileName_47734, this->mProperty_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1623)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (GALGAS_string ("Setting breakpoint at ").add_operation (this->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)).add_operation (this->mProperty_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1625)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlContext * ptr_48187 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
        callExtensionSetter_setBreakpoint ((cPtr_gtlContext *) ptr_48187, this->mProperty_fileName, this->mProperty_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1626)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("Unable to set a breakpoint in an empty file\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1629)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointInstruction::method_display (C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break ").add_operation (this->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)).add_operation (this->mProperty_lineNum.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1635)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1635)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointListInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointListInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listBreakpoints ((cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1651)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointListInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointListInstruction::method_display (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1656)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & /* ioArgument_vars */,
                                                          GALGAS_library & /* ioArgument_lib */,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_49433 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteBreakpoint ((cPtr_gtlContext *) ptr_49433, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1673)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteInstruction::method_display (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break not ").add_operation (this->mProperty_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1678)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1678))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1678)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteAllInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteAllInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                             GALGAS_gtlData & /* ioArgument_vars */,
                                                             GALGAS_library & /* ioArgument_lib */,
                                                             GALGAS_string & /* ioArgument_outputString */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_50041 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllBreakpoints ((cPtr_gtlContext *) ptr_50041, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1694)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlBreakpointDeleteAllInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBreakpointDeleteAllInstruction::method_display (C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("break not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1699)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                    GALGAS_gtlData & /* ioArgument_vars */,
                                                    GALGAS_library & /* ioArgument_lib */,
                                                    GALGAS_string & /* ioArgument_outputString */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_50633 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_setWatchpoint ((cPtr_gtlContext *) ptr_50633, this->mProperty_watchExpression, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1716)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointInstruction::method_display (C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch ( ").add_operation (callExtensionGetter_stringRepresentation ((const cPtr_gtlExpression *) this->mProperty_watchExpression.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721)).add_operation (GALGAS_string (" )"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1721)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointListInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointListInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                        GALGAS_gtlData & /* ioArgument_vars */,
                                                        GALGAS_library & /* ioArgument_lib */,
                                                        GALGAS_string & /* ioArgument_outputString */,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listWatchpoints ((cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1737)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointListInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointListInstruction::method_display (C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1742)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & /* ioArgument_vars */,
                                                          GALGAS_library & /* ioArgument_lib */,
                                                          GALGAS_string & /* ioArgument_outputString */,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_51819 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteWatchpoint ((cPtr_gtlContext *) ptr_51819, this->mProperty_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1759)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteInstruction::method_display (C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch not ").add_operation (this->mProperty_numToDelete.readProperty_bigint ().getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1764)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1764))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1764)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteAllInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteAllInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                             GALGAS_gtlData & /* ioArgument_vars */,
                                                             GALGAS_library & /* ioArgument_lib */,
                                                             GALGAS_string & /* ioArgument_outputString */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_context.insulate (HERE) ;
  cPtr_gtlContext * ptr_52428 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
  callExtensionSetter_deleteAllWatchpoints ((cPtr_gtlContext *) ptr_52428, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1780)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlWatchpointDeleteAllInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlWatchpointDeleteAllInstruction::method_display (C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("watch not all")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1785)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlListInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlListInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & /* ioArgument_vars */,
                                              GALGAS_library & /* ioArgument_lib */,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_hereWeAre ((cPtr_gtlContext *) ioArgument_context.ptr (), this->mProperty_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1802)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlListInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlListInstruction::method_display (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("list ").add_operation (this->mProperty_window.getter_string (SOURCE_FILE ("gtl_debugger.galgas", 1807)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1807))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1807)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHistoryInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlHistoryInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                                 GALGAS_gtlData & /* ioArgument_vars */,
                                                 GALGAS_library & /* ioArgument_lib */,
                                                 GALGAS_string & /* ioArgument_outputString */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  callExtensionMethod_listHistory ((cPtr_debugCommandInput *) ioArgument_context.readProperty_debuggerContext ().readProperty_commandInput ().ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1823)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHistoryInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlHistoryInstruction::method_display (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("hist")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1828)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoadInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLoadInstruction::method_execute (GALGAS_gtlContext & ioArgument_context,
                                              GALGAS_gtlData & ioArgument_vars,
                                              GALGAS_library & ioArgument_lib,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_loadCommandFile (this->mProperty_fileName, ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1845)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlLoadInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLoadInstruction::method_display (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("load \"").add_operation (this->mProperty_fileName, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1850)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1850))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1850)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHelpInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlHelpInstruction::method_execute (GALGAS_gtlContext & /* ioArgument_context */,
                                              GALGAS_gtlData & /* ioArgument_vars */,
                                              GALGAS_library & /* ioArgument_lib */,
                                              GALGAS_string & /* ioArgument_outputString */,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("Available commands:\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1866)) ;
  inCompiler->printMessage (GALGAS_string ("  break <filename>:<line>        : set a breakpoint at <line> in file <filename>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1867)) ;
  inCompiler->printMessage (GALGAS_string ("  break <line>                   : set a breakpoint at <line> in the current file\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1868)) ;
  inCompiler->printMessage (GALGAS_string ("  break                          : lists the breakpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1869)) ;
  inCompiler->printMessage (GALGAS_string ("  break not <num>                : delete breakpoint at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1870)) ;
  inCompiler->printMessage (GALGAS_string ("  break not all                  : delete all breakpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1871)) ;
  inCompiler->printMessage (GALGAS_string ("  cont                           : continue execution until the next breakpoint or the end\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1872)) ;
  inCompiler->printMessage (GALGAS_string ("  display <variable>             : display variable <variable>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1873)) ;
  inCompiler->printMessage (GALGAS_string ("  do <command>                   : do a command each time a step is done\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1874)) ;
  inCompiler->printMessage (GALGAS_string ("  do                             : list the do commands\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1875)) ;
  inCompiler->printMessage (GALGAS_string ("  do not <num>                   : delete the do command at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1876)) ;
  inCompiler->printMessage (GALGAS_string ("  do not all                     : delete all the do commands\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1877)) ;
  inCompiler->printMessage (GALGAS_string ("  hist                           : display the command history\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1878)) ;
  inCompiler->printMessage (GALGAS_string ("  if <expression> then ...       : same as GTL if instruction. Must be on one line though\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1879)) ;
  inCompiler->printMessage (GALGAS_string ("  list                           : lists instructions +/- 5 around current one\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1880)) ;
  inCompiler->printMessage (GALGAS_string ("  list <num>                     : lists instructions +/- <num> around current one\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1881)) ;
  inCompiler->printMessage (GALGAS_string ("  let <variable> := <expression> : compute <expression> and set <variable> to the result\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1882)) ;
  inCompiler->printMessage (GALGAS_string ("  load <filename>                : load commands from file <filename>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1883)) ;
  inCompiler->printMessage (GALGAS_string ("  print <expression>             : prints the <expression>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1884)) ;
  inCompiler->printMessage (GALGAS_string ("  step                           : step one instruction\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1885)) ;
  inCompiler->printMessage (GALGAS_string ("  unlet <variable>               : delete <variable>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1886)) ;
  inCompiler->printMessage (GALGAS_string ("  variables                      : display all variables in scope\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1887)) ;
  inCompiler->printMessage (GALGAS_string ("  watch (<expression>)           : set a watchpoint matching the boolean <expression>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1888)) ;
  inCompiler->printMessage (GALGAS_string ("  watch                          : lists the watchpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1889)) ;
  inCompiler->printMessage (GALGAS_string ("  watch not <num>                : delete watchpoint at index <num>\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1890)) ;
  inCompiler->printMessage (GALGAS_string ("  watch not all                  : delete all watchpoints\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1891)) ;
  inCompiler->printMessage (GALGAS_string ("  <return>                       : step one instruction\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1892)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlHelpInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlHelpInstruction::method_display (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string ("help")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 1897)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

C_BoolCommandLineOption gOption_goil_5F_options_arxmlDisplayOil ("goil_options",
                                         "arxmlDisplayOil",
                                         0,
                                         "arxmlPrintOil",
                                         "Display an Oil version while parsing an arxml file") ;

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

C_BoolCommandLineOption gOption_goil_5F_options_pierreOption ("goil_options",
                                         "pierreOption",
                                         0,
                                         "pierre",
                                         "Special option to pass a galgas bug to Pierre") ;

C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ("goil_options",
                                         "warnMultiple",
                                         0,
                                         "warn-multiple",
                                         "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition") ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//----------------------------------------------------------------------------------------------------------------------

C_StringCommandLineOption gOption_goil_5F_options_config ("goil_options",
                                         "config",
                                         99,
                                         "config",
                                         "Specifies the OIL config file used by goil",
                                         "config") ;

C_StringCommandLineOption gOption_goil_5F_options_passOption ("goil_options",
                                         "passOption",
                                         111,
                                         "option",
                                         "Pass options to the template root script",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ("goil_options",
                                         "project_dir",
                                         112,
                                         "project",
                                         "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_root ("goil_options",
                                         "root",
                                         114,
                                         "root",
                                         "Specifies the root template file to use to generate the output files",
                                         "root") ;

C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ("goil_options",
                                         "target_platform",
                                         116,
                                         "target",
                                         "Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino.",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ("goil_options",
                                         "template_dir",
                                         0,
                                         "templates",
                                         "Specifies template directory (used by goil for code generation)",
                                         "") ;

//----------------------------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkEnums'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool function_checkEnums (const GALGAS_impEnumType & constinArgument_previousEnum,
                                 const GALGAS_impEnumType & constinArgument_newEnum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  GALGAS_stringset var_newValues_16709 = constinArgument_newEnum.readProperty_valuesMap ().getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 614)) ;
  GALGAS_stringset var_previousValues_16772 = constinArgument_previousEnum.readProperty_valuesMap ().getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 615)) ;
  result_inside = GALGAS_bool (kIsEqual, var_newValues_16709.operator_and (var_previousValues_16772 COMMA_SOURCE_FILE ("implementation_parser.galgas", 616)).objectCompare (var_newValues_16709)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 617)).boolEnum () ;
    if (kBoolTrue == test_0) {
      cEnumerator_locationList enumerator_16893 (constinArgument_newEnum.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_16893.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_16893.current_location (HERE), GALGAS_string ("ENUM is not within previous enum declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 619)) ;
        enumerator_16893.gotoNextObject () ;
      }
      cEnumerator_locationList enumerator_17007 (constinArgument_previousEnum.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17007.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_17007.current_location (HERE), GALGAS_string ("previous ENUM declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 622)) ;
        enumerator_17007.gotoNextObject () ;
      }
    }
  }
//---
  return result_inside ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkEnums [3] = {
  & kTypeDescriptor_GALGAS_impEnumType,
  & kTypeDescriptor_GALGAS_impEnumType,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkEnums (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_impEnumType operand0 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_impEnumType operand1 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_checkEnums (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkEnums ("checkEnums",
                                                            functionWithGenericHeader_checkEnums,
                                                            & kTypeDescriptor_GALGAS_bool,
                                                            2,
                                                            functionArgs_checkEnums) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkRanged'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool function_checkRanged (const GALGAS_impRangedType & constinArgument_previousRanged,
                                  const GALGAS_impRangedType & constinArgument_newRanged,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  callExtensionMethod_enclose ((cPtr_attributeRange *) constinArgument_previousRanged.readProperty_setOrRange ().ptr (), result_inside, constinArgument_newRanged.readProperty_setOrRange (), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 635)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 636)).boolEnum () ;
    if (kBoolTrue == test_0) {
      cEnumerator_locationList enumerator_17373 (constinArgument_newRanged.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17373.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_17373.current_location (HERE), GALGAS_string ("new range or set is not within previous range or set declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 638)) ;
        enumerator_17373.gotoNextObject () ;
      }
      cEnumerator_locationList enumerator_17509 (constinArgument_previousRanged.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17509.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_17509.current_location (HERE), GALGAS_string ("previous range or set declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 641)) ;
        enumerator_17509.gotoNextObject () ;
      }
    }
  }
//---
  return result_inside ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkRanged [3] = {
  & kTypeDescriptor_GALGAS_impRangedType,
  & kTypeDescriptor_GALGAS_impRangedType,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkRanged (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_impRangedType operand0 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_impRangedType operand1 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  return function_checkRanged (operand0,
                               operand1,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkRanged ("checkRanged",
                                                             functionWithGenericHeader_checkRanged,
                                                             & kTypeDescriptor_GALGAS_bool,
                                                             2,
                                                             functionArgs_checkRanged) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkNewTypeWithinPreviousType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool function_checkNewTypeWithinPreviousType (const GALGAS_lstring & constinArgument_name,
                                                     const GALGAS_impType & constinArgument_previousType,
                                                     const GALGAS_impType & constinArgument_newType,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, constinArgument_newType.readProperty_type ().objectCompare (constinArgument_previousType.readProperty_type ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      cEnumerator_locationList enumerator_17831 (constinArgument_newType.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17831.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_17831.current_location (HERE), constinArgument_name.readProperty_string ().add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)).add_operation (extensionGetter_oilType (constinArgument_previousType.readProperty_type (), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 654)) ;
        enumerator_17831.gotoNextObject () ;
      }
      cEnumerator_locationList enumerator_17958 (constinArgument_previousType.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_17958.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_17958.current_location (HERE), constinArgument_name.readProperty_string ().add_operation (GALGAS_string (" was previouly defined here"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 657)), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 657)) ;
        enumerator_17958.gotoNextObject () ;
      }
      result_result = GALGAS_bool (false) ;
    }
  }
  if (kBoolFalse == test_0) {
    if (constinArgument_previousType.isValid ()) {
      if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_18149_previousEnum ((cPtr_impEnumType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
            GALGAS_impEnumType cast_18205_newEnum ((cPtr_impEnumType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkEnums (cast_18149_previousEnum, cast_18205_newEnum, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 665)) ;
          }
        }
      }else if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
        GALGAS_impRangedType cast_18316_previousRanged ((cPtr_impRangedType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_18376_newRanged ((cPtr_impRangedType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkRanged (cast_18316_previousRanged, cast_18376_newRanged, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)) ;
          }
        }
      }else{
        result_result = GALGAS_bool (true) ;
      }
    }
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_checkNewTypeWithinPreviousType [4] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_impType,
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_checkNewTypeWithinPreviousType (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand1 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand2 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_checkNewTypeWithinPreviousType (operand0,
                                                  operand1,
                                                  operand2,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_checkNewTypeWithinPreviousType ("checkNewTypeWithinPreviousType",
                                                                                functionWithGenericHeader_checkNewTypeWithinPreviousType,
                                                                                & kTypeDescriptor_GALGAS_bool,
                                                                                3,
                                                                                functionArgs_checkNewTypeWithinPreviousType) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'buildRange'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_attributeRange function_buildRange (const GALGAS_dataType & constinArgument_type,
                                           const GALGAS_object_5F_t & constinArgument_start,
                                           const GALGAS_object_5F_t & constinArgument_stop,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 683)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_range = GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 684)), function_uint_33__32_OrError (constinArgument_start, GALGAS_string ("UINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 684)), function_uint_33__32_OrError (constinArgument_stop, GALGAS_string ("UINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 684))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 684)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 685)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_range = GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)), function_sint_33__32_OrError (constinArgument_start, GALGAS_string ("SINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)), function_sint_33__32_OrError (constinArgument_stop, GALGAS_string ("SINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 686))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 686)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 687)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_range = GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 688)), function_uint_36__34_OrError (constinArgument_start, GALGAS_string ("UINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 688)), function_uint_36__34_OrError (constinArgument_stop, GALGAS_string ("UINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 688))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 688)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 689)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            result_range = GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 690)), function_sint_36__34_OrError (constinArgument_start, GALGAS_string ("SINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 690)), function_sint_36__34_OrError (constinArgument_stop, GALGAS_string ("SINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 690))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 690)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 691)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              result_range = GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)), function_floatOrError (constinArgument_start, GALGAS_string ("FLOAT Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)), function_floatOrError (constinArgument_stop, GALGAS_string ("FLOAT Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 692))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 692)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 694)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_parser.galgas", 694)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_buildRange [4] = {
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_object_5F_t,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_buildRange (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_dataType operand0 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_object_5F_t operand1 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_object_5F_t operand2 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_buildRange (operand0,
                              operand1,
                              operand2,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_buildRange ("buildRange",
                                                            functionWithGenericHeader_buildRange,
                                                            & kTypeDescriptor_GALGAS_attributeRange,
                                                            3,
                                                            functionArgs_buildRange) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithUInt32List'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithUInt_33__32_List (const GALGAS_uint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_33__32_List enumerator_2572 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2572.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2572.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 85)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 85)) ;
    if (enumerator_2572.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 85)) ;
    }
    enumerator_2572.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithUInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_33__32_List operand0 = GALGAS_uint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithUInt_33__32_List ("stringWithUInt32List",
                                                                            functionWithGenericHeader_stringWithUInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_33__32_List) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithUInt64List'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithUInt_36__34_List (const GALGAS_uint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_36__34_List enumerator_2734 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2734.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2734.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 90)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 90)) ;
    if (enumerator_2734.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 90)) ;
    }
    enumerator_2734.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithUInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34_List operand0 = GALGAS_uint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithUInt_36__34_List ("stringWithUInt64List",
                                                                            functionWithGenericHeader_stringWithUInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_36__34_List) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithSInt32List'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithSInt_33__32_List (const GALGAS_sint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_33__32_List enumerator_2896 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_2896.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2896.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 95)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 95)) ;
    if (enumerator_2896.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 95)) ;
    }
    enumerator_2896.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithSInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_33__32_List operand0 = GALGAS_sint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithSInt_33__32_List ("stringWithSInt32List",
                                                                            functionWithGenericHeader_stringWithSInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_33__32_List) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithSInt64List'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithSInt_36__34_List (const GALGAS_sint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_36__34_List enumerator_3058 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_3058.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_3058.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 100)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 100)) ;
    if (enumerator_3058.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 100)) ;
    }
    enumerator_3058.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithSInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_36__34_List operand0 = GALGAS_sint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithSInt_36__34_List ("stringWithSInt64List",
                                                                            functionWithGenericHeader_stringWithSInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_36__34_List) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithFloatList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_stringWithFloatList (const GALGAS_floatList & constinArgument_values,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_floatList enumerator_3218 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_3218.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_3218.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 105)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 105)) ;
    if (enumerator_3218.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 105)) ;
    }
    enumerator_3218.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringWithFloatList (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_floatList operand0 = GALGAS_floatList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  return function_stringWithFloatList (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringWithFloatList ("stringWithFloatList",
                                                                     functionWithGenericHeader_stringWithFloatList,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     1,
                                                                     functionArgs_stringWithFloatList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint32ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_uint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 109)) ;
  cEnumerator_numberList enumerator_3409 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3409.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3409.current_location (HERE), function_uint_33__32_OrError (enumerator_3409.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 111))  COMMA_SOURCE_FILE ("implementation_types.galgas", 111)) ;
    enumerator_3409.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_33__32_ListWithNumberList ("uint32ListWithNumberList",
                                                                                functionWithGenericHeader_uint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_33__32_List,
                                                                                1,
                                                                                functionArgs_uint_33__32_ListWithNumberList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint32ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_sint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 116)) ;
  cEnumerator_numberList enumerator_3607 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3607.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3607.current_location (HERE), function_sint_33__32_OrError (enumerator_3607.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 118))  COMMA_SOURCE_FILE ("implementation_types.galgas", 118)) ;
    enumerator_3607.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_33__32_ListWithNumberList ("sint32ListWithNumberList",
                                                                                functionWithGenericHeader_sint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_33__32_List,
                                                                                1,
                                                                                functionArgs_sint_33__32_ListWithNumberList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint64ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 123)) ;
  cEnumerator_numberList enumerator_3805 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_3805.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3805.current_location (HERE), function_uint_36__34_OrError (enumerator_3805.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 125))  COMMA_SOURCE_FILE ("implementation_types.galgas", 125)) ;
    enumerator_3805.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_uint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_uint_36__34_ListWithNumberList ("uint64ListWithNumberList",
                                                                                functionWithGenericHeader_uint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_36__34_List,
                                                                                1,
                                                                                functionArgs_uint_36__34_ListWithNumberList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint64ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 130)) ;
  cEnumerator_numberList enumerator_4003 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4003.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4003.current_location (HERE), function_sint_36__34_OrError (enumerator_4003.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 132))  COMMA_SOURCE_FILE ("implementation_types.galgas", 132)) ;
    enumerator_4003.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_sint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_sint_36__34_ListWithNumberList ("sint64ListWithNumberList",
                                                                                functionWithGenericHeader_sint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_36__34_List,
                                                                                1,
                                                                                functionArgs_sint_36__34_ListWithNumberList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'floatListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList function_floatListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList result_result ; // Returned variable
  result_result = GALGAS_floatList::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 137)) ;
  cEnumerator_numberList enumerator_4198 (constinArgument_numbers, kENUMERATION_UP) ;
  while (enumerator_4198.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_4198.current_location (HERE), function_floatOrError (enumerator_4198.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 139))  COMMA_SOURCE_FILE ("implementation_types.galgas", 139)) ;
    enumerator_4198.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_floatListWithNumberList (C_Compiler * inCompiler,
                                                                        const cObjectArray & inEffectiveParameterArray,
                                                                        const GALGAS_location & /* inErrorLocation */
                                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_floatListWithNumberList (operand0,
                                           inCompiler
                                           COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_floatListWithNumberList ("floatListWithNumberList",
                                                                         functionWithGenericHeader_floatListWithNumberList,
                                                                         & kTypeDescriptor_GALGAS_floatList,
                                                                         1,
                                                                         functionArgs_floatListWithNumberList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@noRange enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_noRange::method_enclose (GALGAS_bool & outArgument_isWithin,
                                   const GALGAS_attributeRange /* constinArgument_value */,
                                   C_Compiler * /* inCompiler */
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint32AttributeSet enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_4957_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_33__32_List enumerator_4975 (cast_4957_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_4975.hasCurrentObject ()) {
        GALGAS_bool var_ok_5013 = GALGAS_bool (false) ;
        cEnumerator_uint_33__32_List enumerator_5040 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_5040.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_4975.current_value (HERE).objectCompare (enumerator_5040.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_5013 = GALGAS_bool (true) ;
            }
          }
          enumerator_5040.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5013 COMMA_SOURCE_FILE ("implementation_types.galgas", 177)) ;
        enumerator_4975.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a UINT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 180)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 181)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint64AttributeSet enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_5568_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_36__34_List enumerator_5586 (cast_5568_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_5586.hasCurrentObject ()) {
        GALGAS_bool var_ok_5624 = GALGAS_bool (false) ;
        cEnumerator_uint_36__34_List enumerator_5651 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_5651.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_5586.current_value (HERE).objectCompare (enumerator_5651.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_5624 = GALGAS_bool (true) ;
            }
          }
          enumerator_5651.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5624 COMMA_SOURCE_FILE ("implementation_types.galgas", 201)) ;
        enumerator_5586.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a UINT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 204)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 205)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint32AttributeSet enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_6179_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_33__32_List enumerator_6197 (cast_6179_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_6197.hasCurrentObject ()) {
        GALGAS_bool var_ok_6235 = GALGAS_bool (false) ;
        cEnumerator_sint_33__32_List enumerator_6262 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_6262.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_6197.current_value (HERE).objectCompare (enumerator_6262.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_6235 = GALGAS_bool (true) ;
            }
          }
          enumerator_6262.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6235 COMMA_SOURCE_FILE ("implementation_types.galgas", 225)) ;
        enumerator_6197.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a INT32 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 228)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 229)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint64AttributeSet enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                    const GALGAS_attributeRange constinArgument_value,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_6789_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_36__34_List enumerator_6807 (cast_6789_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_6807.hasCurrentObject ()) {
        GALGAS_bool var_ok_6845 = GALGAS_bool (false) ;
        cEnumerator_sint_36__34_List enumerator_6872 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_6872.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_6807.current_value (HERE).objectCompare (enumerator_6872.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_6845 = GALGAS_bool (true) ;
            }
          }
          enumerator_6872.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6845 COMMA_SOURCE_FILE ("implementation_types.galgas", 249)) ;
        enumerator_6807.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a INT64 set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 252)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 253)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@floatAttributeSet enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_floatAttributeSet::method_enclose (GALGAS_bool & outArgument_isWithin,
                                             const GALGAS_attributeRange constinArgument_value,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_7397_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_floatList enumerator_7415 (cast_7397_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_7415.hasCurrentObject ()) {
        GALGAS_bool var_ok_7453 = GALGAS_bool (false) ;
        cEnumerator_floatList enumerator_7480 (this->mProperty_valueList, kENUMERATION_UP) ;
        while (enumerator_7480.hasCurrentObject ()) {
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = GALGAS_bool (kIsEqual, enumerator_7415.current_value (HERE).objectCompare (enumerator_7480.current_value (HERE))).boolEnum () ;
            if (kBoolTrue == test_0) {
              var_ok_7453 = GALGAS_bool (true) ;
            }
          }
          enumerator_7480.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_7453 COMMA_SOURCE_FILE ("implementation_types.galgas", 273)) ;
        enumerator_7415.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a FLOAT set"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 276)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 277)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint32AttributeMinMax enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_33__32_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax) {
      GALGAS_uint_33__32_AttributeMinMax cast_8020_minmax ((cPtr_uint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_8020_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8020_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 291)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_8140_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_33__32_List enumerator_8173 (cast_8140_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_8173.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_8173.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8173.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 297)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_8173.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a UINT32 range or UINT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 302)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 303)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@uint64AttributeMinMax enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_uint_36__34_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax) {
      GALGAS_uint_36__34_AttributeMinMax cast_8679_minmax ((cPtr_uint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_8679_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8679_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 316)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_8799_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_8832 (cast_8799_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_8832.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_8832.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8832.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 322)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_8832.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a UINT64 range or UINT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 327)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 328)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint32AttributeMinMax enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_33__32_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax) {
      GALGAS_sint_33__32_AttributeMinMax cast_9334_minmax ((cPtr_sint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_9334_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9334_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 341)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_9454_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_9487 (cast_9454_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_9487.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_9487.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_9487.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 347)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_9487.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a INT32 range or INT32 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 352)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 353)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@sint64AttributeMinMax enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_sint_36__34_AttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax) {
      GALGAS_sint_36__34_AttributeMinMax cast_9991_minmax ((cPtr_sint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_9991_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9991_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 366)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_10111_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_10144 (cast_10111_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_10144.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_10144.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10144.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 372)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_10144.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a INT64 range or INT64 set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 377)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 378)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@floatAttributeMinMax enclose'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_floatAttributeMinMax::method_enclose (GALGAS_bool & outArgument_isWithin,
                                                const GALGAS_attributeRange constinArgument_value,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeMinMax) {
      GALGAS_floatAttributeMinMax cast_10646_minmax ((cPtr_floatAttributeMinMax *) constinArgument_value.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsSupOrEqual, cast_10646_minmax.readProperty_min ().objectCompare (this->mProperty_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_10646_minmax.readProperty_max ().objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 391)).boolEnum () ;
        if (kBoolTrue == test_0) {
          outArgument_isWithin = GALGAS_bool (true) ;
        }
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_10765_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_10798 (cast_10765_set.readProperty_valueList (), kENUMERATION_UP) ;
      while (enumerator_10798.hasCurrentObject ()) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = GALGAS_bool (kIsStrictInf, enumerator_10798.current_value (HERE).objectCompare (this->mProperty_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10798.current_value (HERE).objectCompare (this->mProperty_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 397)).boolEnum () ;
          if (kBoolTrue == test_1) {
            outArgument_isWithin = GALGAS_bool (false) ;
          }
        }
        enumerator_10798.gotoNextObject () ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_value.readProperty_location (), GALGAS_string ("Incompatible set. Should be a FLOAT range or FLOAT set"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)) ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (this->mProperty_location, GALGAS_string ("Previous set was declared here"), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 403)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Function 'attributeRangeWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_attributeRange function_attributeRangeWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                             const GALGAS_dataType & constinArgument_type,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 412)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_range = GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 413)), function_uint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 413))  COMMA_SOURCE_FILE ("implementation_types.galgas", 413)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 414)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        result_range = GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 415)), function_sint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 415))  COMMA_SOURCE_FILE ("implementation_types.galgas", 415)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 416)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_range = GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 417)), function_uint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 417))  COMMA_SOURCE_FILE ("implementation_types.galgas", 417)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 418)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            result_range = GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 419)), function_sint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 419))  COMMA_SOURCE_FILE ("implementation_types.galgas", 419)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 420)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              result_range = GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 421)), function_floatListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 421))  COMMA_SOURCE_FILE ("implementation_types.galgas", 421)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 423)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_types.galgas", 423)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_attributeRangeWithNumberList [3] = {
  & kTypeDescriptor_GALGAS_numberList,
  & kTypeDescriptor_GALGAS_dataType,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_attributeRangeWithNumberList (C_Compiler * inCompiler,
                                                                             const cObjectArray & inEffectiveParameterArray,
                                                                             const GALGAS_location & /* inErrorLocation */
                                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_attributeRangeWithNumberList (operand0,
                                                operand1,
                                                inCompiler
                                                COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_attributeRangeWithNumberList ("attributeRangeWithNumberList",
                                                                              functionWithGenericHeader_attributeRangeWithNumberList,
                                                                              & kTypeDescriptor_GALGAS_attributeRange,
                                                                              2,
                                                                              functionArgs_attributeRangeWithNumberList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impStructType mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impStructType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  GALGAS_impStructType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impStructType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impStructType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 467)) ;
    }
  }
  GALGAS_impStructType var_castTypeToMerge_12898 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedAttributes_12974 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 468)) ;
  cEnumerator_implementationObjectMap enumerator_12995 (this->mProperty_structAttributes, kENUMERATION_UP) ;
  while (enumerator_12995.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_13042 = enumerator_12995.current_type (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_castTypeToMerge_12898.readProperty_structAttributes ().getter_hasKey (enumerator_12995.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 471)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_subTypeToMerge_13201 ;
        var_castTypeToMerge_12898.readProperty_structAttributes ().method_get (enumerator_12995.current_lkey (HERE), var_subTypeToMerge_13201, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 472)) ;
        var_mergedAttr_13042 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_12995.current_type (HERE).ptr (), var_subTypeToMerge_13201, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 473)) ;
      }
    }
    {
    var_mergedAttributes_12974.setter_put (enumerator_12995.current_lkey (HERE), var_mergedAttr_13042, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 475)) ;
    }
    enumerator_12995.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impStructType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 478)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 482)), var_mergedAttributes_12974  COMMA_SOURCE_FILE ("implementation_types.galgas", 477)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impVoid mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impVoid::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                   C_Compiler */* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  result_mergedType = inArgument_typeToMerge ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impAutoDefaultType getDefaultValue'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t cPtr_impAutoDefaultType::getter_getDefaultValue (C_Compiler */* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_object_5F_t result_outDefaultValue ; // Returned variable
  result_outDefaultValue = this->mProperty_defaultValue ;
//---
  return result_outDefaultValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@impAutoDefaultType setDefValue'
//
//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_impAutoDefaultType_setDefValue (cPtr_impType * inObject,
                                                            GALGAS_object_5F_t inArgument_inDefaultValue,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_impAutoDefaultType * object = (cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  object->mProperty_defaultValue = inArgument_inDefaultValue ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_impAutoDefaultType_setDefValue (void) {
  enterExtensionSetter_setDefValue (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                    extensionSetter_impAutoDefaultType_setDefValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_impAutoDefaultType_setDefValue (defineExtensionSetter_impAutoDefaultType_setDefValue, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impAutoDefaultType mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impAutoDefaultType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                              C_Compiler */* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  result_mergedType = inArgument_typeToMerge ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impAutoDefaultType autoAllowed'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_impAutoDefaultType::getter_autoAllowed (C_Compiler */* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_withAuto ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'multiError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_multiError (GALGAS_locationList inArgument_locations,
                         GALGAS_string inArgument_errorMessage,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_locationList enumerator_14830 (inArgument_locations, kENUMERATION_UP) ;
  while (enumerator_14830.hasCurrentObject ()) {
    TC_Array <C_FixItDescription> fixItArray0 ;
    inCompiler->emitSemanticError (enumerator_14830.current_location (HERE), inArgument_errorMessage, fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 546)) ;
    enumerator_14830.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@refType mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_refType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  GALGAS_refType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_refType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("refType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 558)) ;
    }
  }
  GALGAS_refType var_castTypeToMerge_15080 = temp_0 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsNotEqual, this->mProperty_ref.readProperty_string ().objectCompare (var_castTypeToMerge_15080.readProperty_ref ().readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      this->mProperty_ref.log ("ref"  COMMA_SOURCE_FILE ("implementation_types.galgas", 560)) ;
      GALGAS_lstring var_csatRef_15200 = var_castTypeToMerge_15080.readProperty_ref () ;
      var_csatRef_15200.log ("csatRef"  COMMA_SOURCE_FILE ("implementation_types.galgas", 562)) ;
      {
      routine_multiError (inArgument_typeToMerge.readProperty_locations (), GALGAS_string ("Redefinition of ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 563)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 563)) ;
      }
      {
      routine_multiError (this->mProperty_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
      }
    }
  }
  result_mergedType = GALGAS_refType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 567)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 571)), var_castTypeToMerge_15080.readProperty_ref ()  COMMA_SOURCE_FILE ("implementation_types.galgas", 566)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Function 'valueList'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_valueList (const GALGAS_enumValues & constinArgument_values,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_enumValues enumerator_16169 (constinArgument_values, kENUMERATION_UP) ;
  while (enumerator_16169.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_16169.current_lkey (HERE).readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 600)) ;
    if (enumerator_16169.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 602)) ;
    }
    enumerator_16169.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueList (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_enumValues operand0 = GALGAS_enumValues::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_valueList (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueList ("valueList",
                                                           functionWithGenericHeader_valueList,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_valueList) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impRangedType mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impRangedType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  GALGAS_impRangedType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impRangedType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impRangedType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impRangedType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 614)) ;
    }
  }
  GALGAS_impRangedType var_castTypeToMerge_16458 = temp_0 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    const GALGAS_impRangedType temp_2 = this ;
    test_1 = function_checkRanged (temp_2, var_castTypeToMerge_16458, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 615)).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_mergedType = inArgument_typeToMerge ;
    }
  }
  if (kBoolFalse == test_1) {
    const GALGAS_impRangedType temp_3 = this ;
    result_mergedType = temp_3 ;
  }
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impBoolType mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impBoolType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  GALGAS_impBoolType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impBoolType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 631)) ;
    }
  }
  GALGAS_impBoolType var_castTypeToMerge_16868 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedTrueAttributes_16946 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 632)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_17007 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 633)) ;
  cEnumerator_implementationObjectMap enumerator_17028 (this->mProperty_trueSubAttributes, kENUMERATION_UP) ;
  while (enumerator_17028.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_17076 = enumerator_17028.current_type (HERE) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_castTypeToMerge_16868.readProperty_trueSubAttributes ().getter_hasKey (enumerator_17028.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 636)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_subTypeToMerge_17237 ;
        var_castTypeToMerge_16868.readProperty_trueSubAttributes ().method_get (enumerator_17028.current_lkey (HERE), var_subTypeToMerge_17237, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 637)) ;
        var_mergedAttr_17076 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_17028.current_type (HERE).ptr (), var_subTypeToMerge_17237, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 638)) ;
      }
    }
    {
    var_mergedTrueAttributes_16946.setter_put (enumerator_17028.current_lkey (HERE), var_mergedAttr_17076, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 640)) ;
    }
    enumerator_17028.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17407 (var_castTypeToMerge_16868.readProperty_trueSubAttributes (), kENUMERATION_UP) ;
  while (enumerator_17407.hasCurrentObject ()) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = this->mProperty_trueSubAttributes.getter_hasKey (enumerator_17407.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 644)).operator_not (SOURCE_FILE ("implementation_types.galgas", 644)).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        var_mergedTrueAttributes_16946.setter_put (enumerator_17407.current_lkey (HERE), enumerator_17407.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 645)) ;
        }
      }
    }
    enumerator_17407.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17580 (this->mProperty_falseSubAttributes, kENUMERATION_UP) ;
  while (enumerator_17580.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_17629 = enumerator_17580.current_type (HERE) ;
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = var_castTypeToMerge_16868.readProperty_falseSubAttributes ().getter_hasKey (enumerator_17580.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 651)).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_impType var_subTypeToMerge_17792 ;
        var_castTypeToMerge_16868.readProperty_falseSubAttributes ().method_get (enumerator_17580.current_lkey (HERE), var_subTypeToMerge_17792, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 652)) ;
        var_mergedAttr_17629 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_17580.current_type (HERE).ptr (), var_subTypeToMerge_17792, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 653)) ;
      }
    }
    {
    var_mergedFalseAttributes_17007.setter_put (enumerator_17580.current_lkey (HERE), var_mergedAttr_17629, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 655)) ;
    }
    enumerator_17580.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_17963 (var_castTypeToMerge_16868.readProperty_falseSubAttributes (), kENUMERATION_UP) ;
  while (enumerator_17963.hasCurrentObject ()) {
    enumGalgasBool test_4 = kBoolTrue ;
    if (kBoolTrue == test_4) {
      test_4 = this->mProperty_falseSubAttributes.getter_hasKey (enumerator_17963.current_lkey (HERE).readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 659)).operator_not (SOURCE_FILE ("implementation_types.galgas", 659)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        var_mergedTrueAttributes_16946.setter_put (enumerator_17963.current_lkey (HERE), enumerator_17963.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 660)) ;
        }
      }
    }
    enumerator_17963.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impBoolType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 665)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 669)), this->mProperty_withAuto, var_castTypeToMerge_16868.readProperty_defaultValue (), var_mergedTrueAttributes_16946, var_mergedFalseAttributes_17007  COMMA_SOURCE_FILE ("implementation_types.galgas", 664)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@impBoolType setDefault'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_impBoolType::method_setDefault (GALGAS_objectAttributes & ioArgument_attributes,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (this->mProperty_defaultValue.isValid ()) {
    if (this->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
    }else if (this->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else if (this->mProperty_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_18611_b ((cPtr_boolAttribute *) this->mProperty_defaultValue.ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = ioArgument_attributes.readProperty_objectParams ().getter_hasKey (this->mProperty_name.readProperty_string () COMMA_SOURCE_FILE ("implementation_types.galgas", 685)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_identifierMap var_userAttributes_18887 = ioArgument_attributes.readProperty_objectParams () ;
          GALGAS_object_5F_t var_value_18943 ;
          var_userAttributes_18887.method_get (this->mProperty_name, var_value_18943, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 690)) ;
          if (var_value_18943.isValid ()) {
            if (var_value_18943.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
              GALGAS_boolAttribute cast_19045_boolValue ((cPtr_boolAttribute *) var_value_18943.ptr ()) ;
              GALGAS_implementationObjectMap var_subImpAttributes_19103 ;
              enumGalgasBool test_1 = kBoolTrue ;
              if (kBoolTrue == test_1) {
                test_1 = cast_19045_boolValue.readProperty_value ().boolEnum () ;
                if (kBoolTrue == test_1) {
                  var_subImpAttributes_19103 = this->mProperty_trueSubAttributes ;
                }
              }
              if (kBoolFalse == test_1) {
                var_subImpAttributes_19103 = this->mProperty_falseSubAttributes ;
              }
              GALGAS_objectAttributes var_subAttributes_19309 = cast_19045_boolValue.readProperty_subAttributes () ;
              {
              routine_setDefaultsForType (var_subImpAttributes_19103, var_subAttributes_19309, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 700)) ;
              }
              GALGAS_boolAttribute var_bv_19464 = cast_19045_boolValue ;
              {
              var_bv_19464.setter_setSubAttributes (var_subAttributes_19309 COMMA_SOURCE_FILE ("implementation_types.galgas", 703)) ;
              }
              {
              var_userAttributes_18887.setter_setValueForKey (var_bv_19464, this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 704)) ;
              }
              {
              ioArgument_attributes.setter_setObjectParams (var_userAttributes_18887 COMMA_SOURCE_FILE ("implementation_types.galgas", 705)) ;
              }
            }
          }
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_implementationObjectMap var_subImpAttributes_19727 ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = cast_18611_b.readProperty_value ().boolEnum () ;
          if (kBoolTrue == test_2) {
            var_subImpAttributes_19727 = this->mProperty_trueSubAttributes ;
          }
        }
        if (kBoolFalse == test_2) {
          var_subImpAttributes_19727 = this->mProperty_falseSubAttributes ;
        }
        GALGAS_objectAttributes var_subAttributes_19913 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 714)) ;
        {
        routine_setDefaultsForType (var_subImpAttributes_19727, var_subAttributes_19913, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 715)) ;
        }
        GALGAS_boolAttribute var_defaults_20029 = GALGAS_boolAttribute::constructor_new (cast_18611_b.readProperty_oil_5F_desc (), cast_18611_b.readProperty_location (), cast_18611_b.readProperty_value (), var_subAttributes_19913  COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
        GALGAS_identifierMap var_attr_20136 = ioArgument_attributes.readProperty_objectParams () ;
        {
        var_attr_20136.setter_put (this->mProperty_name, var_defaults_20029, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 718)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_20136 COMMA_SOURCE_FILE ("implementation_types.galgas", 719)) ;
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@impEnumType mergeWithType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType cPtr_impEnumType::getter_mergeWithType (GALGAS_impType inArgument_typeToMerge,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_impType result_mergedType ; // Returned variable
  GALGAS_impEnumType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impEnumType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 754)) ;
    }
  }
  GALGAS_impEnumType var_castTypeToMerge_21086 = temp_0 ;
  result_mergedType = GALGAS_impEnumType::constructor_new (this->mProperty_locations.add_operation (inArgument_typeToMerge.readProperty_locations (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 756)), this->mProperty_type, this->mProperty_name, this->mProperty_multiple, this->mProperty_descs.add_operation (inArgument_typeToMerge.readProperty_descs (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 760)), this->mProperty_withAuto, var_castTypeToMerge_21086.readProperty_defaultValue (), extensionGetter_mergeWithEnum (this->mProperty_valuesMap, var_castTypeToMerge_21086.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 763))  COMMA_SOURCE_FILE ("implementation_types.galgas", 755)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'verifyEnum'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_verifyEnum (const GALGAS_impType constinArgument_anEnum,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_anEnum.isValid ()) {
    if (constinArgument_anEnum.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
      GALGAS_impEnumType cast_21552_realEnum ((cPtr_impEnumType *) constinArgument_anEnum.ptr ()) ;
      if (cast_21552_realEnum.readProperty_defaultValue ().isValid ()) {
        if (cast_21552_realEnum.readProperty_defaultValue ().dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
          GALGAS_string_5F_class cast_21626_defaultValue ((cPtr_string_5F_class *) cast_21552_realEnum.readProperty_defaultValue ().ptr ()) ;
          enumGalgasBool test_0 = kBoolTrue ;
          if (kBoolTrue == test_0) {
            test_0 = cast_21552_realEnum.readProperty_valuesMap ().getter_hasKey (cast_21626_defaultValue.readProperty_value () COMMA_SOURCE_FILE ("implementation_types.galgas", 777)).operator_not (SOURCE_FILE ("implementation_types.galgas", 777)).boolEnum () ;
            if (kBoolTrue == test_0) {
              TC_Array <C_FixItDescription> fixItArray1 ;
              inCompiler->emitSemanticError (cast_21626_defaultValue.readProperty_location (), GALGAS_string ("Default enum value does not match any enum value"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 778)) ;
            }
          }
        }
      }
    }else{
      cEnumerator_locationList enumerator_21829 (constinArgument_anEnum.readProperty_locations (), kENUMERATION_UP) ;
      while (enumerator_21829.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_21829.current_location (HERE), GALGAS_string ("Internal, not an @impEnumType"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 783)) ;
        enumerator_21829.gotoNextObject () ;
      }
    }
  }
}


